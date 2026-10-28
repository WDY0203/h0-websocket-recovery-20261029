// impl.cpp -- H0WS2 / bbwebsocket 1.2.7 : WebSocket protocol layer reconstruction
// Target: D:\tmp\H0WS2.so  (ELF x86-64, .text 0x7750..0x1f256, .rodata 0x1f280..0x1fe16)
// Self-contained: no zlib, no original binary, no network.
//
// Address convention: every "A:0x1234" below is an IMAGE address
// (= address printed in the decompiler listing - 0x100000).
// Listing block header "===== IDX n 00112b60 ... =====" -> image address 0x12b60.
//
// What is reconstructed byte-exactly:
//   1. Sec-WebSocket-Accept = base64(SHA1(key || GUID))       [SHA1 0xd620, inlined at 0x12b60]
//   2. Server handshake parse order / 3 branches (101|200|silent)   [0x12b60]
//   3. Client handshake request (constant key, fixed template)      [0x122b0]
//   4. Frame header 2/4/10 bytes: FIN/RSV1/opcode/MASK/payload-len  [0x114a0,0x10920,0x11a50]
//   5. Masking: byte-wise XOR, index i&3, reset per frame           [0x10d50]
//   6. Control frames / fragmentation / FIN dispatch                [0x10d50,0x11100]
//   7. Sticky/partial packets: wait until whole frame, then memmove [0xfe70,0x11f80]
//   8. Send side: 0x81 / 0xC1 frame + 7/16/64-bit length quirks     [0x14d00]
//
// Boundary (the binary calls zlib there, the codec itself is not re-implemented):
//   permessage-deflate: inbound appends 00 00 FF FF then inflates with
//   windowBits=-15 (0xee80); outbound deflates with Z_FINISH, trims 4 bytes
//   and sets RSV1 (0x14d00).

#ifndef H0WS_PROTO_IMPL_CPP_
#define H0WS_PROTO_IMPL_CPP_

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>
#include <functional>

namespace h0ws {

// ---------------------------------------------------------------------------
// 0. helpers
// ---------------------------------------------------------------------------

inline size_t find_bytes(const void* hay, size_t haylen, const void* needle, size_t nlen) {
    if (nlen == 0 || nlen > haylen) return std::string::npos;
    const uint8_t* h = static_cast<const uint8_t*>(hay);
    const uint8_t* n = static_cast<const uint8_t*>(needle);
    for (size_t i = 0; i + nlen <= haylen; ++i) {
        if (h[i] == n[0] && std::memcmp(h + i, n, nlen) == 0) return i;
    }
    return std::string::npos;
}

inline uint32_t rotl32(uint32_t v, int n) { return (v << n) | (v >> (32 - n)); }

// ---------------------------------------------------------------------------
// 1. SHA-1 -- 0xd620 (FUN_0010d620, fully unrolled 80 rounds)
//    struct layout seen at 0xd620: h[5] @+0x00, bitlen(64,BE) @+0x14,
//                                  block[64] @+0x1c, fill @+0x5c
//    evidence: 0xd63c loads [rdi+0x1c] (=block); 0x134a6..0x134e4 stores the IV;
//              0xd9ac adds 0x5a827999 / 0xd9f1 adds 0x6ed9eba1; tail uses 0xca62c1d6
//              (pseudocode line 11751) and adds the state back (lines 11759-11763).
// ---------------------------------------------------------------------------
struct Sha1Ctx {
    uint32_t h[5];
    uint64_t bitlen;
    uint8_t  block[64];
    uint32_t fill;
    Sha1Ctx() { reset(); }
    void reset() {
        h[0] = 0x67452301u; h[1] = 0xefcdab89u; h[2] = 0x98badcfeu;
        h[3] = 0x10325476u; h[4] = 0xc3d2e1f0u;
        bitlen = 0; fill = 0; std::memset(block, 0, sizeof block);
    }
};

inline void sha1_block(uint32_t h[5], const uint8_t blk[64]) {
    uint32_t w[80];
    for (int i = 0; i < 16; ++i)
        w[i] = (uint32_t)blk[i * 4] << 24 | (uint32_t)blk[i * 4 + 1] << 16 |
               (uint32_t)blk[i * 4 + 2] << 8 | (uint32_t)blk[i * 4 + 3];
    for (int i = 16; i < 80; ++i) w[i] = rotl32(w[i - 16] ^ w[i - 14] ^ w[i - 8] ^ w[i - 3], 1);
    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];
    for (int i = 0; i < 80; ++i) {
        uint32_t f, k;
        if (i < 20)      { f = (b & c) | (~b & d);            k = 0x5a827999u; }
        else if (i < 40) { f = b ^ c ^ d;                     k = 0x6ed9eba1u; }
        else if (i < 60) { f = (b & c) | (b & d) | (c & d);   k = 0x8f1bbcdcu; }
        else             { f = b ^ c ^ d;                     k = 0xca62c1d6u; }
        uint32_t t = rotl32(a, 5) + f + e + k + w[i];
        e = d; d = c; c = rotl32(b, 30); b = a; a = t;
    }
    h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e;
}

// Same as the inlined copy at 0x12b60: byte-wise feed, 0x80 pad, zero pad,
// 8-byte big-endian bit length at the end.
inline std::string sha1(const std::string& data) {
    uint32_t h[5] = {0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u, 0xc3d2e1f0u};
    size_t n = data.size();
    std::string m = data;
    m.push_back((char)0x80);
    while (m.size() % 64 != 56) m.push_back((char)0x00);
    uint64_t bits = (uint64_t)n * 8;
    for (int i = 7; i >= 0; --i) m.push_back((char)((bits >> (i * 8)) & 0xff));
    for (size_t off = 0; off < m.size(); off += 64)
        sha1_block(h, reinterpret_cast<const uint8_t*>(m.data() + off));
    std::string out(20, '\0');
    for (int i = 0; i < 5; ++i) {
        out[i * 4 + 0] = (char)(h[i] >> 24);
        out[i * 4 + 1] = (char)(h[i] >> 16);
        out[i * 4 + 2] = (char)(h[i] >> 8);
        out[i * 4 + 3] = (char)(h[i]);
    }
    return out;
}

// ---------------------------------------------------------------------------
// 2. Base64 -- alphabet at .rodata 0x1fc40:
//    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
//    0x123a3/0x123ae emit 4 chars per 3 bytes; 0x123d9 emits '=','=' for a
//    1-byte tail (index 64 of the table is '=').
// ---------------------------------------------------------------------------
inline const char* b64_alphabet() {
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
}

inline std::string base64(const std::string& raw) {
    const char* T = b64_alphabet();
    std::string out;
    size_t i = 0;
    const uint8_t* p = reinterpret_cast<const uint8_t*>(raw.data());
    for (; i + 2 < raw.size(); i += 3) {
        uint32_t v = (uint32_t)p[i] << 16 | (uint32_t)p[i + 1] << 8 | p[i + 2];
        out.push_back(T[(v >> 18) & 0x3f]);
        out.push_back(T[(v >> 12) & 0x3f]);
        out.push_back(T[(v >> 6) & 0x3f]);
        out.push_back(T[v & 0x3f]);
    }
    size_t rest = raw.size() - i;
    if (rest == 1) {
        uint32_t v = (uint32_t)p[i] << 16;
        out.push_back(T[(v >> 18) & 0x3f]);
        out.push_back(T[(v >> 12) & 0x3f]);
        out.push_back('=');
        out.push_back('=');          // 0x123d9: T[64] == '='
    } else if (rest == 2) {
        uint32_t v = (uint32_t)p[i] << 16 | (uint32_t)p[i + 1] << 8;
        out.push_back(T[(v >> 18) & 0x3f]);
        out.push_back(T[(v >> 12) & 0x3f]);
        out.push_back(T[(v >> 6) & 0x3f]);
        out.push_back('=');          // 0x123e3: eax=0x40 -> T[64]
    }
    return out;
}

// ---------------------------------------------------------------------------
// 3. Handshake: GUID / Accept
//    The GUID is NOT in .rodata; it is assembled from movabs immediates at
//    0x1346c / 0x13515 / 0x1351f / ... :
//      0x3541464145383532 "258EAFA5"  0x37342d343139452d "-E914-47"
//      0x2d414335392d4144 "DA-95CA-"  0x3843443042413543 "C5AB0DC8"
//      0x31314235         "5B11"
// ---------------------------------------------------------------------------
inline const char* ws_guid() { return "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"; }

// 0x13448..0x1351f: msg = key(strlen) || GUID(36); 0x1350c: len += 0x24
inline std::string sec_accept(const std::string& key) {
    return base64(sha1(key + ws_guid()));
}

// Client key: 0x122d8/0x122e1 zero 16 bytes; between 0x122b0 and 0x12351 the
// only call is operator new (no rand/time), so the key is base64(16*0x00).
inline std::string client_key() { return base64(std::string(16, '\0')); }

// .rodata 0x1f6d8, 155 bytes
inline const char* client_request_template() {
    return "GET / HTTP/1.1\r\n"
           "Upgrade: websocket\r\n"
           "Connection: Upgrade\r\n"
           "Sec-WebSocket-Key: %s\r\n"
           "Sec-WebSocket-Extensions: permessage-deflate\r\n"
           "Sec-WebSocket-Version: 13\r\n"
           "\r\n";
}

inline std::string build_client_request() {
    std::string t = client_request_template();
    std::string key = client_key();
    size_t p = t.find("%s");
    return t.substr(0, p) + key + t.substr(p + 2);
}

// .rodata 0x1f7a8 (105 bytes) / 0x1f778 (46 bytes) / 0x1f6d0 (empty string)
inline std::string build_101_response(bool permessage_deflate, const std::string& accept) {
    std::string ext = permessage_deflate
        ? "Sec-WebSocket-Extensions: permessage-deflate\r\n"   // 0x1f778
        : "";                                                 // 0x1f6d0
    return "HTTP/1.1 101 Switching Protocols\r\n"
           "Upgrade: websocket\r\n"
           "Connection: Upgrade\r\n" + ext +
           "Sec-WebSocket-Accept: " + accept + "\r\n"
           "\r\n";
}

// .rodata 0x1f6bd, 19 bytes
inline const char* http_200_response() { return "HTTP/1.0 200 OK\r\n\r\n"; }

inline const char* key_header_prefix() { return "Sec-WebSocket-Key: "; }   // 0x1f6a3, 19 bytes
inline const char* pmd_token()        { return "permessage-deflate"; }     // 18 bytes
inline const char* get_prefix()       { return "GET /"; }                  // 0x1f6b7, 5 bytes

// ---------------------------------------------------------------------------
// 4. Server handshake -- FUN_00112b60 (0x12b60)
//    Caller WSConn::accept (0xf940) first recv_pat("\r\n\r\n") and passes the
//    index of "\r\n\r\n" as the second argument.
//    Order (exactly as the binary does it):
//      a) memmem(whole_buf, "Sec-WebSocket-Key: ")      [0x12b62]
//      b) key = buf[p+19..] until CR/LF/end/127 bytes   [0x12bd1..0x12bcb]
//      c) non-empty -> SHA1(key||GUID) -> base64 -> accept
//      d) memmem(whole_buf, "permessage-deflate") -> negotiate [0x130xx]
//      e) drop idx+4 bytes from the receive buffer      [0x139a4]
//      f) send 101                                      [0x13a1d]
//    If (a) misses, no WebSocket handling happens and the request-line branch runs.
// ---------------------------------------------------------------------------
enum class HandshakeKind {
    NeedMore,      // no "\r\n\r\n" yet
    Upgrade,       // 101 sent
    PlainHttp,     // "HTTP/1.0 200 OK\r\n\r\n" sent, path handed to 2nd callback
    NoResponse     // not "GET /<non-slash>": zero bytes emitted, conn set to discard
};

struct Handshake {
    HandshakeKind kind = HandshakeKind::NeedMore;
    size_t   header_len = 0;          // bytes to drop from recv buffer = idx+4
    std::string path;                 // PlainHttp branch
    std::string key;                  // raw key value (no trimming)
    std::string accept;
    bool     permessage_deflate = false;
    std::string response;             // bytes to write out
};

// Request-line branch (0x12d68..0x12e83)
//   repz cmps 5 bytes "GET /" and buf[5] != '/' required, otherwise 0x12c15.
//   path = buf[5..] until ' ' / '\r' / '\n'; on consecutive ".." the whole
//   path is cleared (assign "" -> .rodata 0x1f6d0).
inline Handshake parse_server_handshake(const uint8_t* buf, size_t n, size_t idx_crlfcrlf) {
    Handshake hs;
    hs.header_len = idx_crlfcrlf + 4;

    const char* kh = key_header_prefix();
    size_t kp = find_bytes(buf, n, kh, 19);
    if (kp != std::string::npos) {
        std::string key;
        // 0x12ba6: esi = len-19 ; 0x12bc7: at most 0x7f bytes
        for (size_t i = 0; i < 0x7f; ++i) {
            if (kp + 19 + i >= n) break;                 // out of buffer
            if (i >= (size_t)((long)n - 19)) break;      // cmp esi,edx ; jle
            char c = (char)buf[kp + 19 + i];
            if (c == '\r' || c == '\n') break;           // 0x12bd6 / 0x12bb0
            key.push_back(c);
        }
        if (!key.empty()) {                               // 0x12be3: first byte != 0
            hs.kind = HandshakeKind::Upgrade;
            hs.key = key;
            hs.accept = sec_accept(key);
            hs.permessage_deflate =
                find_bytes(buf, n, pmd_token(), 18) != std::string::npos;
            hs.response = build_101_response(hs.permessage_deflate, hs.accept);
            return hs;
        }
    }

    // (a) missed or key empty -> request-line branch
    if (n > 5 && std::memcmp(buf, get_prefix(), 5) == 0 && buf[5] != '/') {
        hs.kind = HandshakeKind::PlainHttp;
        if (buf[5] != ' ' && buf[5] != '\r' && buf[5] != '\n') {
            std::string path;
            size_t i = 5;
            bool dots = false;
            for (;;) {
                char c = (char)buf[i];
                path.push_back(c);
                if (i + 1 >= n) break;                    // uVar29 == len-6
                char nxt = (char)buf[i + 1];
                if (nxt == '.' && c == '.') { dots = true; break; }
                if (nxt == '\r' || nxt == ' ' || nxt == '\n') break;
                ++i;
            }
            hs.path = dots ? std::string() : path;        // ".." -> cleared
        }
        hs.response = http_200_response();
        return hs;
    }

    hs.kind = HandshakeKind::NoResponse;
    return hs;
}

// High level: locate "\r\n\r\n" ourselves (= recv_pat semantics, memmem at 0xf180)
inline Handshake server_handshake(const uint8_t* buf, size_t n) {
    static const char term[4] = {'\r', '\n', '\r', '\n'};
    size_t idx = find_bytes(buf, n, term, 4);
    if (idx == std::string::npos) {
        Handshake hs;
        hs.kind = HandshakeKind::NeedMore;
        return hs;
    }
    return parse_server_handshake(buf, n, idx);
}

// ---------------------------------------------------------------------------
// 4b. Client response handling -- FUN_0010fc40 (0xfc40) + FUN_0010dbc0 (0xdbc0)
//     connect() installs 0xfc40 as the TcpConn data handler (@0x125cf, L14923).
//     0xfc40 waits for "\r\n\r\n" with recv_pat (L13282-L13283) and passes the
//     index to FUN_0010dbc0, which does:
//       0xdbf4 memmem(whole buffer, "permessage-deflate", 0x12) -> this+0x58 = 1
//       then inflateInit2_(-15,"1.2.7") / deflateInit2_(-1,8,-15,8,0,...)
//       L11896/L11900 drop (idx+4) bytes from the receive buffer
//       L11911 invoke the captured std::function (the user's on-connect cb)
//     There is NO comparison of the status line, Upgrade, Connection or
//     Sec-WebSocket-Accept: any response ending in CRLFCRLF is accepted.
// ---------------------------------------------------------------------------
struct ClientHandshake {
    enum Kind { NeedMore, Ready };
    Kind   kind = NeedMore;
    size_t header_len = 0;
    bool   permessage_deflate = false;
};

inline ClientHandshake client_handshake_response(const uint8_t* buf, size_t n) {
    static const char term[4] = {'\r', '\n', '\r', '\n'};
    ClientHandshake ch;
    size_t idx = find_bytes(buf, n, term, 4);
    if (idx == std::string::npos) return ch;          // 0xfc40 waits for the pattern
    ch.kind = ClientHandshake::Ready;
    ch.header_len = idx + 4;                          // 0xdb?? param_2 + 4
    // 0xdbf4: scanned over the whole buffer, before the header is dropped
    ch.permessage_deflate = find_bytes(buf, n, pmd_token(), 18) != std::string::npos;
    return ch;
}

// ---------------------------------------------------------------------------
// 5. Frame header -- FUN_001114a0 (0x114a0), first 40 instructions
//    0x114bb movzx eax,[buf]      0x114bf movzx ebp,[buf+1]
//    0x114cd shr r13b,7   -> FIN   (bit7 of byte0)
//    0x114d1 shr r15b,7   -> MASK  (bit7 of byte1)
//    0x114d5 and r12d,0xf -> opcode (low nibble; RSV2/RSV3 are dropped here)
//    0x114d9 test al,0x40 -> RSV1 -> this+0x59 = 1 (sticky)
//    0x114e6 and ebp,0x7f -> len7
//    0x114e9 / 0x114f3: 0x7e -> recv_more(4)  -> FUN_00110920
//                       0x7f -> recv_more(10) -> FUN_00111a50
//    extended length: 0x1093c 16-bit big-endian; 0x11a68..0x11a9c high 32 bits
//    must be zero, otherwise WSConn::exit().
// ---------------------------------------------------------------------------
enum class Opcode : uint8_t {
    Cont = 0x0, Text = 0x1, Binary = 0x2, Close = 0x8, Ping = 0x9, Pong = 0xA
};

struct FrameHeader {
    bool     fin = false;
    bool     rsv1 = false;
    bool     mask = false;
    uint8_t  opcode = 0;
    size_t   header_len = 0;       // 2 / 4 / 10
    uint64_t payload_len = 0;      // already interpreted like the binary
    uint8_t  mask_key[4] = {0, 0, 0, 0};
};

enum class HeaderStatus { NeedMore, Ok, Abort };

// Header only (mask key not included).
inline HeaderStatus parse_frame_header(const uint8_t* buf, size_t n, FrameHeader& h) {
    if (n < 2) return HeaderStatus::NeedMore;
    h.fin    = (buf[0] & 0x80) != 0;
    h.rsv1   = (buf[0] & 0x40) != 0;
    h.opcode = (uint8_t)(buf[0] & 0x0f);          // RSV2(0x20)/RSV3(0x10) unchecked
    h.mask   = (buf[1] & 0x80) != 0;
    uint32_t len7 = (uint32_t)(buf[1] & 0x7f);

    if (len7 == 0x7e) {
        if (n < 4) return HeaderStatus::NeedMore;
        h.header_len = 4;
        h.payload_len = ((uint32_t)buf[2] << 8) | (uint32_t)buf[3];   // big-endian
    } else if (len7 == 0x7f) {
        if (n < 10) return HeaderStatus::NeedMore;
        // 0x11a68: any of buf[2..5] non-zero -> WSConn::exit()
        if (buf[2] || buf[3] || buf[4] || buf[5]) return HeaderStatus::Abort;
        uint32_t raw = ((uint32_t)buf[6] << 24) | ((uint32_t)buf[7] << 16) |
                       ((uint32_t)buf[8] << 8) | (uint32_t)buf[9];
        h.header_len = 10;
        h.payload_len = (uint64_t)(int64_t)(int32_t)raw;   // signed 32-bit extension
    } else {
        h.header_len = 2;
        h.payload_len = len7;
    }
    return HeaderStatus::Ok;
}

// ---------------------------------------------------------------------------
// 6. Message dispatch -- FUN_00110d50 (masked) / FUN_00111100 (plain)
//    Both tails are identical:
//      0x10e1b cmp BYTE [rbx+0x10],0    ; FIN
//      0x10e1f je  -> read_head()   keep accumulating (fragmentation)
//      0x10e2a/0x10e34: rsv1 AND this+0x58(negotiated) -> FUN_0010ee80 (inflate)
//      0x10e45 mov eax,[rbx+0x14]       ; opcode of THIS frame
//      0x10e48 cmp eax,0x1 -> deliver    0x10e51 cmp eax,0x8 -> deliver nullptr
//      anything else (0/2/9/10) -> plain return (no delivery, no reply)
// ---------------------------------------------------------------------------
class Connection {
public:
    std::string recvbuf;              // this+0x40  (vector<unsigned char>)
    std::string message;              // this+0x48  (message accumulator)
    bool deflate_negotiated = false;  // this+0x58
    bool rsv1 = false;                // this+0x59 (sticky, cleared by recv())

    enum class Event {
        NeedMore,     // not enough data yet
        Message,      // opcode==1 and FIN: message taken out
        Close,        // opcode==8 and FIN: callback receives an empty Buffer
        Dropped,      // FIN but opcode not 1/8, or inflate failure
        NeedInflate,  // external zlib required (message already has 00 00 FF FF)
        Abort         // 64-bit length with non-zero high words -> WSConn::exit()
    };

    struct InflateResult { bool ok; std::string data; };
    using InflateFn = std::function<InflateResult(const std::string&)>;

    // WSConn::recv(): 0x10c60 -- fresh message buffer + clear sticky RSV1
    void start_message() { message.clear(); rsv1 = false; }

    void feed(const void* p, size_t n) { recvbuf.append((const char*)p, n); }

    bool  pending_active = false;   // header removed, waiting for the payload
    FrameHeader pending;

    // Equivalent of 0x11f80 "data arrived -> append -> re-run the parser"
    Event pump(const InflateFn* inflate = nullptr) {
        for (;;) {
            if (!pending_active) {
                FrameHeader h;
                HeaderStatus st = parse_frame_header(
                    reinterpret_cast<const uint8_t*>(recvbuf.data()), recvbuf.size(), h);
                if (st == HeaderStatus::NeedMore) return Event::NeedMore;
                if (st == HeaderStatus::Abort) return Event::Abort;

                if (h.rsv1) rsv1 = true;              // 0x114d9: sticky
                // 0x11515 / 0x10958 / 0x11ae7: header is memmoved out as soon
                // as it is complete, long before the payload arrives.
                pending = h;
                pending_active = true;
                recvbuf.erase(0, h.header_len);
            }

            const FrameHeader& h = pending;
            // read_data_mask(this, len+4) / read_data(this, len); a negative
            // length is reinterpreted as ulong and therefore never satisfied.
            if (h.payload_len > (uint64_t)recvbuf.size()) return Event::NeedMore;
            size_t want = (size_t)h.payload_len + (h.mask ? 4u : 0u);
            if (recvbuf.size() < want) return Event::NeedMore;

            const uint8_t* b = reinterpret_cast<const uint8_t*>(recvbuf.data());
            if (h.mask) {
                // 0x10d50: key = first 4 bytes; message is zero-extended by len
                // and then XOR-filled one byte at a time.
                uint8_t k[4] = { b[0], b[1], b[2], b[3] };
                size_t old = message.size();
                message.resize(old + (size_t)h.payload_len, '\0');
                for (size_t i = 0; i < (size_t)h.payload_len; ++i)
                    message[old + i] = (char)(b[4 + i] ^ k[i & 3]);
                recvbuf.erase(0, want);              // memmove out len+4
            } else {
                // 0x11100: insert payload directly
                message.append((const char*)b, (size_t)h.payload_len);
                recvbuf.erase(0, want);
            }
            pending_active = false;

            if (!h.fin) continue;                    // 0x10e1f -> read_head()

            if (rsv1 && deflate_negotiated) {        // 0x10e2a
                message.append("\x00\x00\xff\xff", 4);   // 0xee80 prefix
                if (!inflate) return Event::NeedInflate;
                InflateResult r = (*inflate)(message);
                if (!r.ok) return Event::Dropped;    // inflate error -> no delivery
                message = r.data;
            }

            if (h.opcode == 0x1) {                   // 0x10e48
                std::string out = message;
                message.clear();                     // 0x10ff7: this+0x48 = 0
                rsv1 = false;
                last_message.swap(out);
                return Event::Message;
            }
            if (h.opcode == 0x8) return Event::Close;  // 0x10e51 -> callback(nullptr)
            return Event::Dropped;                     // 0/2/9/10/others
        }
    }

    std::string last_message;

    // -----------------------------------------------------------------
    // 7. Send side -- WSConn::send (0x14d00)
    //    byte0 = 0x81 (no compression) / 0xC1 (RSV1=1)
    //    byte1 = len7 | 0x00   (MASK always 0)
    //    len > 125 -> 126 + 2 bytes big-endian;
    //    len >= 0xffff -> 127 + four 0x00 + 4 bytes big-endian
    //    (quirk: 0x1526c `cmp r15,0xfffe ; ja` -> 65535 takes the 64-bit branch)
    // -----------------------------------------------------------------
    static std::string encode_frame_header(size_t len, bool rsv1_compressed) {
        std::string out;
        out.push_back((char)(rsv1_compressed ? 0xC1 : 0x81));
        if (len > 0x7d) {                       // 0x15262 `cmp r15,0x7d ; jbe`
            if (len < 0xffff) {                 // strict less-than
                out.push_back((char)0x7E);
                out.push_back((char)((len >> 8) & 0xff));
            } else {
                out.push_back((char)0x7F);
                out.push_back(0); out.push_back(0); out.push_back(0); out.push_back(0);
                out.push_back((char)((len >> 24) & 0xff));
                out.push_back((char)((len >> 16) & 0xff));
                out.push_back((char)((len >> 8) & 0xff));
            }
        }
        out.push_back((char)(len & 0xff));
        return out;
    }

    std::string outbox;    // bytes the library would actually write

    // Plain path; for the compressed path the caller supplies payload that is
    // already deflate(Z_FINISH)-ed with the trailing 4 bytes trimmed.
    void send_text(const std::string& payload, bool compressed = false) {
        outbox += encode_frame_header(payload.size(), compressed);
        outbox += payload;
    }

    // WSConn::exit (0xc110): clears the send queue and schedules teardown,
    // it never emits a Close frame.
    bool sent_any_close_frame() const { return false; }
};

}  // namespace h0ws

#endif  // H0WS_PROTO_IMPL_CPP_
