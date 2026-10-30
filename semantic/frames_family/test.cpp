// test.cpp -- table-driven conformance suite for the H0WS frame family.
//
// Every expected value below is hand-computed from RFC 6455 plus the
// decompiled pseudocode (see claims.json / README.md for the derivation of
// each row).  Nothing here executes the original binary.
//
//   g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t

#include "impl.h"

#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

using namespace h0ws;
using Bytes = std::vector<uint8_t>;

// --------------------------------------------------------------------------
// harness
// --------------------------------------------------------------------------
static int g_asserts = 0;
static int g_fails = 0;
static std::map<std::string, int> g_byMember;
static std::map<std::string, int> g_failByMember;
static bool g_verbose = false;

static std::string hex(const Bytes &b) {
  static const char *H = "0123456789abcdef";
  std::string s = "[";
  for (size_t i = 0; i < b.size(); ++i) {
    if (i) s += ' ';
    s += H[b[i] >> 4];
    s += H[b[i] & 0xf];
  }
  s += "]";
  return s;
}

static std::string hex(const std::string &s) { return hex(Bytes(s.begin(), s.end())); }

static void chk(const char *member, const char *id, const char *what, bool ok,
                const std::string &got, const std::string &want) {
  ++g_asserts;
  ++g_byMember[member];
  if (ok) {
    if (g_verbose) std::printf("  ok    %-5s %-42s\n", id, what);
    return;
  }
  ++g_fails;
  ++g_failByMember[member];
  std::printf("  FAIL  %-5s [%s] %s\n        got  = %s\n        want = %s\n", id, member,
              what, got.c_str(), want.c_str());
}

static Bytes B(std::initializer_list<int> xs) {
  Bytes b;
  for (int x : xs) b.push_back(static_cast<uint8_t>(x));
  return b;
}
static Bytes S(const char *s) { return Bytes(s, s + std::strlen(s)); }
static Bytes R(char c, size_t n) { return Bytes(n, static_cast<uint8_t>(c)); }
static Bytes cat(const Bytes &a, const Bytes &b) {
  Bytes r = a;
  r.insert(r.end(), b.begin(), b.end());
  return r;
}

// --------------------------------------------------------------------------
// T1  frame header bit layout  (M04, FUN_001115a0 L31-L41)
//     fin = b0>>7 | rsv1 = b0&0x40 | opcode = b0&0x0f | mask = b1>>7 | len7 = b1&0x7f
// --------------------------------------------------------------------------
struct HdrRow {
  const char *id;
  uint8_t b0, b1;
  bool fin, rsv1;
  uint8_t op;
  bool m;
  uint8_t l7;
};

static const HdrRow kHdr[] = {
    //  id      b0    b1    fin   rsv1  op  mask  len7
    {"H01", 0x81, 0x05, true, false, 1, false, 5},    // text, 5 bytes, unmasked
    {"H02", 0x01, 0x03, false, false, 1, false, 3},   // FIN=0 first fragment
    {"H03", 0x88, 0x00, true, false, 8, false, 0},    // close, empty
    {"H04", 0x89, 0x80, true, false, 9, true, 0},     // ping, masked, len 0
    {"H05", 0xc1, 0x7e, true, true, 1, false, 126},   // RSV1 + 16-bit length
    {"H06", 0xf2, 0xff, true, true, 2, true, 127},    // binary + 64-bit length
    {"H07", 0x8f, 0x00, true, false, 15, false, 0},   // reserved opcode 0xF passes
    {"H08", 0xb1, 0x05, true, false, 1, false, 5},    // RSV2|RSV3 set -> ignored
    {"H09", 0x71, 0x05, false, true, 1, false, 5},    // everything except FIN
};

static void run_header() {
  for (const HdrRow &r : kHdr) {
    const uint8_t h[2] = {r.b0, r.b1};
    const FrameHeader f = parse_frame_header(h);
    const bool ok = f.fin == r.fin && f.rsv1 == r.rsv1 && f.opcode == r.op &&
                    f.masked == r.m && f.len7 == r.l7;
    char want[160];
    std::snprintf(want, sizeof(want), "fin=%d rsv1=%d op=%u mask=%d len7=%u", (int)r.fin,
                  (int)r.rsv1, (unsigned)r.op, (int)r.m, (unsigned)r.l7);
    char got[160];
    std::snprintf(got, sizeof(got), "fin=%d rsv1=%d op=%u mask=%d len7=%u", (int)f.fin,
                  (int)f.rsv1, (unsigned)f.opcode, (int)f.masked, (unsigned)f.len7);
    chk("M04", r.id, "b0/b1 -> fin,rsv1,opcode,mask,len7", ok, ok ? want : got, want);
  }
}

// --------------------------------------------------------------------------
// T2  decode_len16  (M05, FUN_00110a20 L21: CONCAT11(dest[2], dest[3]))
// --------------------------------------------------------------------------
struct Len16Row {
  const char *id;
  uint8_t b2, b3;
  uint16_t want;
};
static const Len16Row kLen16[] = {
    {"L01", 0x00, 0x7e, 126},     // minimal encoding of 126
    {"L02", 0x00, 0x05, 5},       // NON-minimal: value fits in 7 bits, still accepted
    {"L03", 0xff, 0xff, 65535},   // maximum 16-bit value
    {"L04", 0x01, 0x00, 256},     // byte order is big-endian
    {"L05", 0x7e, 0x7e, 32382},   // 126*256 + 126
};

static void run_len16() {
  for (const Len16Row &r : kLen16) {
    const uint8_t h[4] = {0x81, 0x7e, r.b2, r.b3};
    const uint16_t got = decode_len16(h);
    chk("M05", r.id, "16-bit length = (b2<<8)|b3", got == r.want, std::to_string(got),
        std::to_string(r.want));
  }
}

// --------------------------------------------------------------------------
// T3  decode_len64  (M06, FUN_00111b50 L21-L27)
//     high 32 bits non-zero -> WSConn::exit();  value is (long)(int32)
// --------------------------------------------------------------------------
struct Len64Row {
  const char *id;
  uint8_t h[10];
  bool want_exit;
  int64_t want;
};
static const Len64Row kLen64[] = {
    {"E01", {0x81, 0x7f, 0, 0, 0, 0, 0, 0, 0, 5}, false, 5},
    {"E02", {0x81, 0x7f, 0, 0, 0, 1, 0, 0, 0, 5}, true, 0},   // h[5] != 0 -> exit()
    {"E03", {0x81, 0x7f, 1, 0, 0, 0, 0, 0, 0, 5}, true, 0},   // h[2] != 0 -> exit()
    {"E04", {0x81, 0x7f, 0, 0, 0, 0, 0x80, 0, 0, 0}, false, -2147483648LL},
    {"E05", {0x81, 0x7f, 0, 0, 0, 0, 0x00, 0x01, 0x00, 0x00}, false, 65536},
    {"E06", {0x81, 0x7f, 0, 0, 0, 0, 0xff, 0xff, 0xff, 0xff}, false, -1},
};

static void run_len64() {
  for (const Len64Row &r : kLen64) {
    bool ex = false;
    const int64_t got = decode_len64(r.h, &ex);
    const bool ok = (got == r.want) && (ex == r.want_exit);
    char w[96], g[96];
    std::snprintf(w, sizeof(w), "len=%lld exit=%d", (long long)r.want, (int)r.want_exit);
    std::snprintf(g, sizeof(g), "len=%lld exit=%d", (long long)got, (int)ex);
    chk("M06", r.id, "64-bit length + high-32 guard", ok, g, w);
  }
}

// --------------------------------------------------------------------------
// T4  recv_pat  (M01, WSConn::recv_pat L51-L61: memmem, cb(ptr-buf))
// --------------------------------------------------------------------------
struct PatRow {
  const char *id;
  const char *hay;
  const char *needle;
  size_t want;
};
static const PatRow kPat[] = {
    {"R01", "abc\r\n\r\ndef", "\r\n\r\n", 3},
    {"R02", "\r\n\r\nxyz", "\r\n\r\n", 0},
    {"R03", "abcdef", "\r\n\r\n", kNpos},
    {"R04", "aaab", "aab", 1},   // leftmost non-overlapping-start match
    {"R05", "abc", "", 0},       // glibc memmem: nlen==0 -> haystack
};

static void run_pat() {
  for (const PatRow &r : kPat) {
    const size_t got = recv_pat(S(r.hay), S(r.needle));
    const bool ok = got == r.want;
    char w[32], g[32];
    std::snprintf(w, sizeof(w), "%zu", r.want);
    if (r.want == kNpos)
      std::snprintf(w, sizeof(w), "npos");
    else
      std::snprintf(w, sizeof(w), "%zu", r.want);
    if (got == kNpos)
      std::snprintf(g, sizeof(g), "npos");
    else
      std::snprintf(g, sizeof(g), "%zu", got);
    chk("M01", r.id, "memmem index (not length)", ok, g, w);
  }
}

// --------------------------------------------------------------------------
// T5  recv_more  (M02, WSConn::recv_more L46: unsigned n <= size)
// --------------------------------------------------------------------------
struct MoreRow {
  const char *id;
  uint64_t need, have;
  bool want;
};
static const MoreRow kMore[] = {
    {"G01", 10, 10, true},   // exactly enough -> invoke now
    {"G02", 11, 10, false},  // one short -> register continuation
    {"G03", 0, 0, true},     // zero-length frame body
    {"G04", 4, 3, false},
    {"G05", 0xFFFFFFFF80000000ULL, 100, false},  // 64-bit len -2^31 -> wait forever
    {"G06", 3, 3, true},
};

static void run_more() {
  for (const MoreRow &r : kMore) {
    const bool got = recv_more_ready(r.need, r.have);
    char w[64], g[64];
    std::snprintf(w, sizeof(w), "ready=%d (need=%llu have=%llu)", (int)r.want,
                  (unsigned long long)r.need, (unsigned long long)r.have);
    std::snprintf(g, sizeof(g), "ready=%d", (int)got);
    chk("M02", r.id, "unsigned need<=have gate", got == r.want, g, w);
  }
}

// --------------------------------------------------------------------------
// T6  unmask  (M09, FUN_00110e50 L97-L99)
//       msg[old+i] = recvbuf[4+i] ^ mask[i & 3],  i restarts at 0 per frame
// --------------------------------------------------------------------------
struct UnmaskRow {
  const char *id;
  const char *plain;
  uint8_t mask[4];
  Bytes masked;
};
static const UnmaskRow kUnmask[] = {
    // RFC 6455 section 5.7 worked example
    {"U01", "Hello", {0x37, 0xfa, 0x21, 0x3d}, {0x7f, 0x9f, 0x4d, 0x51, 0x58}},
    {"U02", "Hello", {0x00, 0x00, 0x00, 0x00}, {0x48, 0x65, 0x6c, 0x6c, 0x6f}},
    {"U03", "Hello", {0xff, 0xff, 0xff, 0xff}, {0xb7, 0x9a, 0x93, 0x93, 0x90}},
    {"U04", "abcd", {0x01, 0x02, 0x03, 0x04}, {0x60, 0x60, 0x60, 0x60}},
    {"U05", "ab", {0xaa, 0xbb, 0xcc, 0xdd}, {0xcb, 0xd9}},
};

static void run_unmask() {
  for (const UnmaskRow &r : kUnmask) {
    const Bytes plain = S(r.plain);
    Bytes round = plain;  // start with the cleartext, then unmask(cipher) must match
    unmask_into(round, r.masked.data(), r.masked.size(), r.mask);
    // round now holds plain || plain_again; check only the appended tail
    const Bytes tail(round.begin() + plain.size(), round.end());
    chk("M09", r.id, "unmask round-trip (xor i&3)", tail == plain, hex(tail), hex(plain));
  }
  // Independent direction: masking cleartext must reproduce the table's bytes.
  for (const UnmaskRow &r : kUnmask) {
    const Bytes plain = S(r.plain);
    Bytes m(plain.size());
    for (size_t i = 0; i < plain.size(); ++i)
      m[i] = static_cast<uint8_t>(plain[i] ^ r.mask[i & 3]);
    chk("M09", r.id, "mask(cleartext) == table ciphertext", m == r.masked, hex(m),
        hex(r.masked));
  }
}

// --------------------------------------------------------------------------
// T7  WSConn::send frame construction  (M13, send L56-L244)
//     b0 = 0x81 (plain) / 0xC1 (deflate); MASK bit is never set
//     n<=125 -> 1 byte | 126..65534 -> 0x7e + BE16 | >=65535 -> 0x7f + 4x00 + BE32
// --------------------------------------------------------------------------
struct SendRow {
  const char *id;
  size_t n;
  Bytes want_hdr;
};
static const SendRow kSend[] = {
    {"S01", 0, B({0x81, 0x00})},
    {"S02", 1, B({0x81, 0x01})},
    {"S03", 125, B({0x81, 0x7d})},
    {"S04", 126, B({0x81, 0x7e, 0x00, 0x7e})},
    {"S05", 65534, B({0x81, 0x7e, 0xff, 0xfe})},
    {"S06", 65535, B({0x81, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff})},
    {"S07", 65536, B({0x81, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00})},
};

static void run_send() {
  Conn c;  // neg_deflate == false
  bool mask_ever = false;
  for (const SendRow &r : kSend) {
    const Bytes frame = c.send(R('A', r.n));
    const Bytes hdr(frame.begin(), frame.begin() + static_cast<long>(r.want_hdr.size()));
    const bool ok = hdr == r.want_hdr && frame.size() == r.want_hdr.size() + r.n;
    chk("M13", r.id, "header length encoding boundary", ok, hex(hdr), hex(r.want_hdr));
    if (frame.size() > 1 && (frame[1] & 0x80u)) mask_ever = true;
  }
  chk("M13", "S08", "MASK bit never set on outgoing frames", !mask_ever,
      mask_ever ? "mask set" : "mask clear", "mask clear");

  // Deflate path: first byte must be 0xC1 (FIN=1, RSV1=1, opcode=1).
  Conn d;
  d.neg_deflate = true;
  const Bytes cf = d.send(S("Hi"));
  chk("M13", "S09", "deflate path sets FIN|RSV1|text = 0xC1", !cf.empty() && cf[0] == 0xc1,
      hex(Bytes(cf.begin(), cf.begin() + 1)), hex(B({0xc1})));
  chk("M13", "S10", "deflate path still clears the MASK bit", cf.size() > 1 && !(cf[1] & 0x80u),
      hex(Bytes(cf.begin() + 1, cf.begin() + 2)), "no 0x80");
}

// --------------------------------------------------------------------------
// T8  server handshake  (M14, WSConn::accept + FUN_00112c60)
// --------------------------------------------------------------------------
struct HsRow {
  const char *id;
  const char *req;
  HsKind kind;
  size_t nbytes;
  const char *key;
  const char *path;
  bool neg;
};
static const HsRow kHs[] = {
    {"A01",
     "GET /chat HTTP/1.1\r\nHost: x\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n"
     "Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\nSec-WebSocket-Version: 13\r\n\r\n",
     HsKind::Switching101, 129, "dGhlIHNhbXBsZSBub25jZQ==", "", false},
    {"A02",
     "GET /chat HTTP/1.1\r\nSec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\n"
     "Sec-WebSocket-Extensions: permessage-deflate\r\n\r\n",
     HsKind::Switching101, 175, "dGhlIHNhbXBsZSBub25jZQ==", "", true},
    {"A03", "GET /index.html HTTP/1.1\r\n\r\n", HsKind::Http200, 19, "", "index.html", false},
    {"A04", "GET //evil HTTP/1.1\r\n\r\n", HsKind::Reject, 0, "", "", false},
    {"A05", "POST /x HTTP/1.1\r\n\r\n", HsKind::Reject, 0, "", "", false},
    {"A06", "GET /a..b HTTP/1.1\r\n\r\n", HsKind::Http200, 19, "", "", false},
    {"A07", "GET /partial\r\n", HsKind::NeedMore, 0, "", "", false},
    {"A08", "GET / HTTP/1.1\r\nSec-WebSocket-Key: abc\r\n\r\n", HsKind::Switching101, 129,
     "abc", "", false},
};

static const char *kindName(HsKind k) {
  switch (k) {
    case HsKind::NeedMore: return "NeedMore";
    case HsKind::Reject: return "Reject";
    case HsKind::Switching101: return "101";
    case HsKind::Http200: return "200";
  }
  return "?";
}

static void run_handshake() {
  // RFC 6455 section 1.3 canonical accept value.
  chk("M14", "A10", "sec_accept(RFC6455 sample nonce)", sec_accept("dGhlIHNhbXBsZSBub25jZQ==") ==
                                                          "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=",
      sec_accept("dGhlIHNhbXBsZSBub25jZQ=="), "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=");
  // base64(SHA1("")) -- independent check of the encoder and the digest.
  chk("M14", "A11", "base64(sha1(\"\"))", base64(sha1(Bytes{})) == "2jmj7l5rSw0yVb/vlWAYkK/YBwk=",
      base64(sha1(Bytes{})), "2jmj7l5rSw0yVb/vlWAYkK/YBwk=");

  for (const HsRow &r : kHs) {
    const Handshake hs = server_handshake(S(r.req));
    const bool ok = hs.kind == r.kind && hs.bytes.size() == r.nbytes && hs.key == r.key &&
                    hs.path == r.path && hs.neg_deflate == r.neg;
    char w[160], g[160];
    std::snprintf(w, sizeof(w), "%s bytes=%zu key='%s' path='%s' neg=%d", kindName(r.kind),
                  r.nbytes, r.key, r.path, (int)r.neg);
    std::snprintf(g, sizeof(g), "%s bytes=%zu key='%s' path='%s' neg=%d", kindName(hs.kind),
                  hs.bytes.size(), hs.key.c_str(), hs.path.c_str(), (int)hs.neg_deflate);
    chk("M14", r.id, "handshake branch", ok, g, w);
  }

  // The 101 body must contain the RFC accept value verbatim.
  const Handshake hs = server_handshake(S(kHs[0].req));
  const std::string body(hs.bytes.begin(), hs.bytes.end());
  const std::string needle = "Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=\r\n\r\n";
  chk("M14", "A12", "101 carries the RFC accept value + blank line",
      body.find(needle) != std::string::npos, body.substr(0, 40) + "...", needle);

  // Key extraction is capped at 127 bytes (do..while (lVar24 != 0x7f)).
  std::string longreq = "GET / HTTP/1.1\r\nSec-WebSocket-Key: ";
  longreq += std::string(140, 'x');
  longreq += "\r\n\r\n";
  const Handshake lh = server_handshake(S(longreq.c_str()));
  chk("M14", "A13", "key length capped at 127", lh.key.size() == 127,
      std::to_string(lh.key.size()), "127");
}

// --------------------------------------------------------------------------
// T9  end-to-end frame driver  (M03/M07/M08/M09/M10/M11/M12/M15)
// --------------------------------------------------------------------------
struct Step {
  int kind;  // 0 = data, 1 = recv(), 2 = null Buffer
  Bytes data;
};
struct DriveRow {
  const char *id;
  const char *member;
  const char *name;
  bool neg;
  std::vector<Step> steps;
  std::vector<Bytes> want_msgs;
  int want_null;
  bool want_exited;
  bool want_pending;
  int want_comp;  // -1 = don't care
};

static Step d0(Bytes b) { return Step{0, b}; }
static Step d1() { return Step{1, Bytes{}}; }
static Step d2() { return Step{2, Bytes{}}; }

static void run_driver() {
  std::vector<DriveRow> rows;

  // --- M10 plain payload path -------------------------------------------
  rows.push_back({"D01", "M03", "text-unmasked", false,
                  {d0(B({0x81, 0x05, 'H', 'e', 'l', 'l', 'o'}))}, {S("Hello")}, 0, false, false,
                  -1});
  rows.push_back({"D02", "M08", "text-masked", false,
                  {d0(B({0x81, 0x85, 0x37, 0xfa, 0x21, 0x3d, 0x7f, 0x9f, 0x4d, 0x51, 0x58}))},
                  {S("Hello")}, 0, false, false, -1});
  rows.push_back({"D03", "M07", "len16-body", false,
                  {d0(cat(B({0x81, 0x7e, 0x00, 0x7e}), R('A', 126)))}, {R('A', 126)}, 0, false,
                  false, -1});
  rows.push_back({"D04", "M05", "len16-nonminimal", false,
                  {d0(B({0x81, 0x7e, 0x00, 0x05, 'H', 'e', 'l', 'l', 'o'}))}, {S("Hello")}, 0,
                  false, false, -1});
  rows.push_back({"D05", "M06", "len64-ok", false,
                  {d0(B({0x81, 0x7f, 0, 0, 0, 0, 0, 0, 0, 5, 'H', 'e', 'l', 'l', 'o'}))},
                  {S("Hello")}, 0, false, false, -1});
  rows.push_back({"D06", "M06", "len64-high-nonzero-exit", false,
                  {d0(B({0x81, 0x7f, 0, 0, 0, 1, 0, 0, 0, 5}))}, {}, 0, true, true, -1});
  rows.push_back({"D07", "M06", "len64-0x80000000-stalls", false,
                  {d0(B({0x81, 0x7f, 0, 0, 0, 0, 0x80, 0, 0, 0}))}, {}, 0, false, true, -1});
  rows.push_back({"D08", "M10", "frag-standard-not-delivered", false,
                  {d0(B({0x01, 0x03, 'H', 'e', 'l'})), d0(B({0x80, 0x02, 'l', 'o'}))}, {}, 0,
                  false, false, -1});
  rows.push_back({"D09", "M10", "frag-nonstandard-delivered", false,
                  {d0(B({0x01, 0x03, 'H', 'e', 'l'})), d0(B({0x81, 0x02, 'l', 'o'}))},
                  {S("Hello")}, 0, false, false, -1});
  rows.push_back({"D10", "M10", "frag-three-parts", false,
                  {d0(B({0x01, 0x03, 'H', 'e', 'l'})), d0(B({0x00, 0x02, 'l', 'o'})),
                   d0(B({0x81, 0x01, '!'}))},
                  {S("Hello!")}, 0, false, false, -1});
  rows.push_back({"D11", "M09", "close-masked-delivers-null", false,
                  {d0(B({0x88, 0x82, 0xaa, 0xbb, 0xcc, 0xdd, 0xa9, 0x53}))}, {}, 1, false, false,
                  -1});
  rows.push_back({"D12", "M10", "ping-stops-parsing", false,
                  {d0(B({0x89, 0x00, 0x81, 0x05, 'H', 'e', 'l', 'l', 'o'}))}, {}, 0, false,
                  true, -1});
  rows.push_back({"D13", "M04", "rsv2-rsv3-ignored", false,
                  {d0(B({0xb1, 0x05, 'H', 'e', 'l', 'l', 'o'}))}, {S("Hello")}, 0, false, false,
                  -1});
  // --- M15 on_data ------------------------------------------------------
  {
    std::vector<Step> steps;
    const Bytes f = B({0x81, 0x85, 0x37, 0xfa, 0x21, 0x3d, 0x7f, 0x9f, 0x4d, 0x51, 0x58});
    for (uint8_t b : f) steps.push_back(d0(B({b})));
    rows.push_back({"D14", "M15", "byte-at-a-time", false, steps, {S("Hello")}, 0, false, false,
                    -1});
  }
  rows.push_back({"D15", "M03", "half-header-then-body", false,
                  {d0(B({0x81, 0x05, 'H', 'e', 'l'})), d0(B({'l', 'o'}))}, {S("Hello")}, 0,
                  false, false, -1});
  rows.push_back({"D16", "M07", "zero-length-text", false, {d0(B({0x81, 0x00}))},
                  {Bytes{}}, 0, false, false, -1});
  rows.push_back({"D25", "M03", "one-byte-header-then-rest", false,
                  {d0(B({0x81})), d0(B({0x05, 'H', 'e', 'l', 'l', 'o'}))}, {S("Hello")}, 0,
                  false, false, -1});
  rows.push_back({"D17", "M12", "recv-resets-message", false,
                  {d0(B({0x81, 0x05, 'H', 'e', 'l', 'l', 'o'})), d1(),
                   d0(B({0x81, 0x05, 'W', 'o', 'r', 'l', 'd'}))},
                  {S("Hello"), S("World")}, 0, false, false, -1});
  // --- M11 finalize -----------------------------------------------------
  rows.push_back({"D18", "M11", "rsv1-without-negotiation-passthrough", false,
                  {d0(B({0xc1, 0x03, 0x11, 0x22, 0x33}))}, {B({0x11, 0x22, 0x33})}, 0, false,
                  false, 0});
  rows.push_back({"D19", "M11", "deflate-stored-block", true,
                  {d0(B({0xc1, 0x08, 0x00, 0x02, 0x00, 0xfd, 0xff, 'H', 'i', 0x00}))},
                  {S("Hi")}, 0, false, false, 1});
  rows.push_back({"D20", "M11", "deflate-data-error-drops", true,
                  {d0(B({0xc1, 0x03, 0xff, 0xff, 0xff}))}, {}, 0, false, false, 1});
  rows.push_back({"D21", "M11", "rsv1-sticky-across-fragments", true,
                  {d0(B({0x41, 0x04, 0x00, 0x02, 0x00, 0xfd})),
                   d0(B({0x81, 0x04, 0xff, 'H', 'i', 0x00}))},
                  {S("Hi")}, 0, false, false, 1});
  // --- M08 masked fragmentation ----------------------------------------
  rows.push_back({"D22", "M08", "mask-index-resets-each-frame", false,
                  {d0(B({0x01, 0x83, 0x11, 0x22, 0x33, 0x44, 0x59, 0x47, 0x5f})),
                   d0(B({0x81, 0x82, 0x11, 0x22, 0x33, 0x44, 0x7d, 0x4d}))},
                  {S("Hello")}, 0, false, false, -1});
  // --- M12 pipelining ---------------------------------------------------
  rows.push_back({"D23", "M12", "pipelined-frames-one-per-recv", false,
                  {d0(B({0x81, 0x03, 'O', 'n', 'e', 0x81, 0x03, 'T', 'w', 'o'})), d1()},
                  {S("One"), S("Two")}, 0, false, false, -1});
  rows.push_back({"D24", "M15", "null-buffer-calls-exit", false, {d2()}, {}, 0, true, false,
                  -1});

  for (const DriveRow &r : rows) {
    Conn c;
    c.neg_deflate = r.neg;
    for (const Step &s : r.steps) {
      if (s.kind == 0)
        c.feed(s.data);
      else if (s.kind == 1)
        c.recv();
      else
        c.feed_null();
    }
    bool ok = c.delivered.size() == r.want_msgs.size() &&
              c.delivered_null == r.want_null && c.exited == r.want_exited &&
              c.pending() == r.want_pending;
    if (ok)
      for (size_t i = 0; i < r.want_msgs.size(); ++i)
        if (c.delivered[i] != r.want_msgs[i]) ok = false;
    if (ok && r.want_comp >= 0)
      ok = (c.last_finalize_compressed == (r.want_comp != 0));

    std::string got = "msgs=" + std::to_string(c.delivered.size());
    for (const Bytes &m : c.delivered) got += " " + hex(m);
    got += " null=" + std::to_string(c.delivered_null) +
           " exit=" + std::to_string((int)c.exited) +
           " pending=" + std::to_string((int)c.pending()) +
           " comp=" + std::to_string((int)c.last_finalize_compressed);

    std::string want = "msgs=" + std::to_string(r.want_msgs.size());
    for (const Bytes &m : r.want_msgs) want += " " + hex(m);
    want += " null=" + std::to_string(r.want_null) +
            " exit=" + std::to_string((int)r.want_exited) +
            " pending=" + std::to_string((int)r.want_pending);
    if (r.want_comp >= 0) want += " comp=" + std::to_string(r.want_comp);

    chk(r.member, r.id, r.name, ok, got, want);
  }
}

// --------------------------------------------------------------------------
// T10  WSConn::recv flag handling  (M12, recv L13-L32)
// --------------------------------------------------------------------------
static void run_recv_flags() {
  Conn c;
  c.neg_deflate = true;
  // Frame with RSV1 set, no fragmentation, not negotiated as text -> discarded
  // but the sticky flag must be observable.
  c.feed(B({0x89, 0x00}));  // ping, harmless
  chk("M12", "V01", "rsv1 starts clear", !c.rsv1, std::to_string((int)c.rsv1), "0");

  c.feed(B({0xc1, 0x01, 'Z'}));  // RSV1 text
  chk("M12", "V02", "rsv1 set by a header with bit 6", c.rsv1, std::to_string((int)c.rsv1), "1");

  c.recv();
  chk("M12", "V03", "recv() clears rsv1 (this[0x59]=0)", !c.rsv1,
      std::to_string((int)c.rsv1), "0");

  chk("M12", "V04", "recv() leaves neg_deflate untouched", c.neg_deflate,
      std::to_string((int)c.neg_deflate), "1");
}

// --------------------------------------------------------------------------
int main(int argc, char **argv) {
  g_verbose = (argc > 1 && std::strcmp(argv[1], "-v") == 0);

  std::printf("H0WS frame family -- table-driven conformance suite\n");
  std::printf("(static re-derivation; original binary not executed)\n\n");

  struct Section {
    const char *name;
    void (*fn)();
  } sections[] = {
      {"T1  frame header bit layout        (M04)", run_header},
      {"T2  16-bit extended length         (M05)", run_len16},
      {"T3  64-bit extended length + guard (M06)", run_len64},
      {"T4  pattern scan                   (M01)", run_pat},
      {"T5  need-N-bytes gate             (M02)", run_more},
      {"T6  payload masking                (M09)", run_unmask},
      {"T7  frame construction             (M13)", run_send},
      {"T8  server handshake               (M14)", run_handshake},
      {"T9  end-to-end frame driver  (M03/M04/M05/M06/M07/M08/M09/M10/M11/M12/M15)",
       run_driver},
      {"T10 recv() flag handling           (M12)", run_recv_flags},
  };

  for (const Section &s : sections) {
    const int before = g_asserts;
    s.fn();
    std::printf("%-76s %3d checks\n", s.name, g_asserts - before);
  }

  // Coverage requirement: every member needs at least two assertions.
  const char *members[] = {"M01", "M02", "M03", "M04", "M05", "M06", "M07", "M08",
                           "M09", "M10", "M11", "M12", "M13", "M14", "M15"};
  int covered = 0;
  bool cov_ok = true;
  for (const char *m : members) {
    const int n = g_byMember.count(m) ? g_byMember[m] : 0;
    if (n >= 2)
      ++covered;
    else {
      cov_ok = false;
      std::printf("  COVERAGE FAIL %s has only %d assertion(s)\n", m, n);
    }
  }
  chk("COV", "C01", "every member has >= 2 assertions", cov_ok,
      std::to_string(covered) + "/15", "15/15");

  std::printf("\n-----------------------------------------------------------\n");
  std::printf("per-member assertion counts:\n  ");
  for (size_t i = 0; i < sizeof(members) / sizeof(members[0]); ++i) {
    const char *m = members[i];
    std::printf("%s=%d%s", m, g_byMember.count(m) ? g_byMember[m] : 0,
                (i + 1) % 8 == 0 ? "\n  " : " ");
  }
  std::printf("\n");
  std::printf("members           : 15\n");
  std::printf("assertions        : %d\n", g_asserts);
  std::printf("failed            : %d\n", g_fails);
  std::printf("-----------------------------------------------------------\n");

  if (g_fails == 0) {
    std::printf("all claims passed\n");
    return 0;
  }
  std::printf("%d claim(s) FAILED\n", g_fails);
  return 1;
}
