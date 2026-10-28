// test.cpp -- verifies every byte-level claim in claims.json
// build: g++ -std=gnu++17 -O2 -Wall -Wextra -o test.exe test.cpp
#include "impl.cpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

static int g_fail = 0;
static int g_pass = 0;
static const char* g_area = "";

static void area(const char* a) { g_area = a; }

static void ok(bool cond, const char* what) {
    if (cond) { ++g_pass; return; }
    ++g_fail;
    std::printf("FAIL [%s] %s\n", g_area, what);
}

static void eq(const std::string& got, const std::string& want, const char* what) {
    if (got == want) { ++g_pass; return; }
    ++g_fail;
    std::printf("FAIL [%s] %s\n  got  (%zu): ", g_area, what, got.size());
    for (unsigned char c : got) std::printf(c >= 32 && c < 127 ? "%c" : "\\x%02x", c);
    std::printf("\n  want (%zu): ", want.size());
    for (unsigned char c : want) std::printf(c >= 32 && c < 127 ? "%c" : "\\x%02x", c);
    std::printf("\n");
}

static void equ(uint64_t got, uint64_t want, const char* what) {
    if (got == want) { ++g_pass; return; }
    ++g_fail;
    std::printf("FAIL [%s] %s   got=%llu want=%llu\n", g_area, what,
                (unsigned long long)got, (unsigned long long)want);
}

static std::string hex2bin(const std::string& h) {
    std::string out;
    for (size_t i = 0; i + 1 < h.size(); i += 2) {
        auto v = [](char c) -> int {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'a' && c <= 'f') return c - 'a' + 10;
            return c - 'A' + 10;
        };
        out.push_back((char)((v(h[i]) << 4) | v(h[i + 1])));
    }
    return out;
}

using namespace h0ws;

// ===========================================================================
static void test_sha1() {
    area("sha1");
    // public FIPS 180-1 vectors; IV/constants at 0x134a6..0x134e4, 0xd9ac, 0xd9f1, 11751
    ok(sha1("abc") == hex2bin("a9993e364706816aba3e25717850c26c9cd0d89d"), "sha1(\"abc\")");
    ok(sha1("") == hex2bin("da39a3ee5e6b4b0d3255bfef95601890afd80709"), "sha1(\"\")");
    ok(sha1("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq") ==
       hex2bin("84983e441c3bd26ebaae4aa1f95129e5e54670f1"), "sha1(56 byte boundary)");
    ok(sha1(std::string(64, 'a')) ==
       hex2bin("0098ba824b5c16427bd7a1122a5a442a25ec644d"), "sha1(64 bytes, 0x80 needs a new block)");
    equ(sha1("abc").size(), 20, "digest is 20 bytes -> 28 base64 chars");
}

static void test_base64() {
    area("base64");
    eq(base64(""), "", "base64(\"\")");
    eq(base64(std::string(16, '\0')), "AAAAAAAAAAAAAAAAAAAAAA==", "base64(16*0x00)");
    eq(base64("a"), "YQ==", "1-byte tail -> '=='");
    eq(base64("ab"), "YWI=", "2-byte tail -> '='");
    eq(base64("abc"), "YWJj", "no padding");
    ok(std::strcmp(b64_alphabet(),
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=") == 0,
       "alphabet == .rodata 0x1fc40");
}

static void test_accept() {
    area("accept");
    // RFC 6455 1.3 official example
    eq(sec_accept("dGhlIHNhbXBsZSBub25jZQ=="), "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=",
       "RFC6455 sample Accept");
    // client constant key (16 zero bytes, 0x122d8)
    eq(client_key(), "AAAAAAAAAAAAAAAAAAAAAA==", "client key == base64(16*0x00)");
    eq(sec_accept(client_key()), "ICX+Yqv66kxgM0FcWaLWlFLwTAI=", "Accept of the constant key");
    eq(sec_accept("x"), "JVxkmtKFjDcI/Pm/AGPEKSN6wT8=", "single byte key");
    // concatenation order key || GUID (0x13508 / 0x1350c)
    ok(sha1(std::string("k") + ws_guid()) ==
           sha1(std::string("k") + "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"),
       "GUID constant");
    equ(std::strlen(ws_guid()), 36, "GUID is 36 bytes -> len += 0x24");
}

static void test_client_request() {
    area("client-request");
    equ(std::strlen(client_request_template()), 155,
        "request template is 155 bytes (.rodata 0x1f6d8)");
    std::string tmpl = client_request_template();
    size_t pct = 0;
    for (char c : tmpl) if (c == '%') ++pct;
    equ(pct, 1, "exactly one %s placeholder in the template");
    std::string req = build_client_request();
    equ(req.size(), 155 - 2 + client_key().size(), "built request = template with key substituted");
    ok(req.find("GET / HTTP/1.1\r\n") == 0, "request line first");
    ok(req.find("Sec-WebSocket-Key: AAAAAAAAAAAAAAAAAAAAAA==\r\n") != std::string::npos,
       "constant key substituted into %s");
    ok(req.find("Sec-WebSocket-Extensions: permessage-deflate\r\n") != std::string::npos,
       "client always offers permessage-deflate");
    ok(req.find("Sec-WebSocket-Version: 13\r\n") != std::string::npos, "Version: 13");
    ok(req.size() >= 4 && req.compare(req.size() - 4, 4, "\r\n\r\n") == 0, "ends with CRLFCRLF");
}

static void test_server_handshake() {
    area("handshake");

    // 1) no CRLFCRLF yet
    {
        std::string s = "GET / HTTP/1.1\r\nSec-WebSocket-Key: abc";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::NeedMore, "no CRLFCRLF -> NeedMore");
    }

    // 2) standard client request -> 101
    {
        std::string s = build_client_request();
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::Upgrade, "Key present -> Upgrade");
        equ(h.header_len, s.size(), "header_len = idx(CRLFCRLF)+4");
        ok(h.permessage_deflate, "permessage-deflate negotiated");
        eq(h.response, build_101_response(true, sec_accept("AAAAAAAAAAAAAAAAAAAAAA==")),
           "101 = .rodata 0x1f7a8 + ext line 0x1f778");
        eq(h.response.substr(0, 34), "HTTP/1.1 101 Switching Protocols\r\n", "status line");
        ok(h.response.find("Sec-WebSocket-Accept: ICX+Yqv66kxgM0FcWaLWlFLwTAI=\r\n") !=
               std::string::npos, "Accept header");
        ok(h.response.size() >= 4 &&
               h.response.compare(h.response.size() - 4, 4, "\r\n\r\n") == 0,
           "response ends with CRLFCRLF");
    }

    // 3) no extensions header -> no ext line (0x13a0c cmove -> 0x1f6d0 empty)
    {
        std::string s =
            "GET /x HTTP/1.1\r\nHost: h\r\nSec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::Upgrade, "no extensions header still Upgrade");
        ok(!h.permessage_deflate, "compression not negotiated");
        ok(h.response.find("permessage-deflate") == std::string::npos, "no ext line in 101");
        eq(h.response,
           std::string("HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\n"
                       "Connection: Upgrade\r\nSec-WebSocket-Accept: "
                       "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=\r\n\r\n"),
           "exact 101 bytes");
    }

    // 4) parse order: Key header need not be on the first line; even POST works
    {
        std::string s = "POST /whatever HTTP/1.1\r\nX: y\r\nSec-WebSocket-Key: x\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::Upgrade, "whole-buffer memmem -> request line irrelevant");
        eq(h.accept, sec_accept("x"), "accept is still base64(sha1(key|GUID))");
    }

    // 5) empty key -> not an upgrade
    {
        std::string s = "GET /a HTTP/1.1\r\nSec-WebSocket-Key: \r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::PlainHttp, "empty key -> request-line branch");
        eq(h.path, "a", "path");
        eq(h.response, "HTTP/1.0 200 OK\r\n\r\n", "200 response .rodata 0x1f6bd");
    }

    // 6) no Key -> 200 OK + path
    {
        std::string s = "GET /index.html HTTP/1.1\r\nHost: h\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::PlainHttp, "plain GET -> 200 OK");
        eq(h.path, "index.html", "path cut at space");
        equ(h.header_len, s.size(), "whole header dropped as well");
    }

    // 7) ".." in path -> cleared
    {
        std::string s = "GET /a/../../etc/passwd HTTP/1.1\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        eq(h.path, "", "\"..\" -> path cleared");
    }

    // 8) "GET //x" -> 0x12d84 je 0x12c15 -> no response
    {
        std::string s = "GET //x HTTP/1.1\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::NoResponse, "buf[5]=='/' -> NoResponse");
        ok(h.response.empty(), "zero bytes emitted");
    }

    // 9) not GET -> no response
    {
        std::string s = "PUT /x HTTP/1.1\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::NoResponse, "not GET / -> NoResponse");
        ok(h.response.empty(), "zero bytes emitted");
    }

    // 10) key value capped at 127 bytes (0x12bc7 cmp rdx,0x7f)
    {
        std::string longkey(200, 'K');
        std::string s = "GET /a HTTP/1.1\r\nSec-WebSocket-Key: " + longkey + "\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        ok(h.kind == HandshakeKind::Upgrade, "overlong key still Upgrade");
        equ(h.key.size(), 127, "key truncated to 127 bytes");
        eq(h.accept, sec_accept(std::string(127, 'K')), "Accept over the truncated key");
    }

    // 11) sticky packet: a frame right after the header is preserved
    {
        std::string s = build_client_request();
        std::string frame = "\x81\x05hello";
        size_t hdr = s.size();
        std::string all = s + frame;
        Handshake h = server_handshake((const uint8_t*)all.data(), all.size());
        equ(h.header_len, hdr, "header_len covers the header only");
        ok(all.substr(h.header_len) == frame, "pipelined frame preserved");
    }

    // 12) only the first CRLFCRLF counts
    {
        std::string s = "GET /a HTTP/1.1\r\n\r\nGET /b HTTP/1.1\r\n\r\n";
        Handshake h = server_handshake((const uint8_t*)s.data(), s.size());
        equ(h.header_len, 19, "first CRLFCRLF only");
    }
}

static void test_client_response() {
    area("client-response");
    // 0xfc40/0xdbc0: wait for CRLFCRLF, negotiate pmd, drop idx+4, no validation
    {
        std::string s = "HTTP/1.1 101 Switching Protocols\r\n"
                        "Upgrade: websocket\r\nConnection: Upgrade\r\n"
                        "Sec-WebSocket-Accept: s3pPLMBiTxaQ9kYGzzhZRbK+xOo=\r\n\r\n";
        ClientHandshake c = client_handshake_response((const uint8_t*)s.data(), s.size());
        ok(c.kind == ClientHandshake::Ready, "response header ready");
        equ(c.header_len, s.size(), "header_len = idx+4");
        ok(!c.permessage_deflate, "no deflate token -> not negotiated");
    }
    {
        std::string s = "HTTP/1.1 101 Switching Protocols\r\n"
                        "Sec-WebSocket-Extensions: permessage-deflate\r\n\r\n";
        ClientHandshake c = client_handshake_response((const uint8_t*)s.data(), s.size());
        ok(c.permessage_deflate, "deflate token in the response -> negotiated");
    }
    {
        // no status / Accept validation at all
        std::string s = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
        ClientHandshake c = client_handshake_response((const uint8_t*)s.data(), s.size());
        ok(c.kind == ClientHandshake::Ready, "400 response is accepted (no status check)");
        equ(c.header_len, s.size(), "header dropped anyway");
    }
    {
        std::string s = "HTTP/1.1 101 Switching Protocols\r\nSec-WebSocket-Accept: wrong\r\n\r\n";
        ClientHandshake c = client_handshake_response((const uint8_t*)s.data(), s.size());
        ok(c.kind == ClientHandshake::Ready, "wrong Accept value is not verified");
    }
    {
        std::string s = "HTTP/1.1 101 Switching";
        ClientHandshake c = client_handshake_response((const uint8_t*)s.data(), s.size());
        ok(c.kind == ClientHandshake::NeedMore, "incomplete header -> NeedMore");
    }
    {
        // pipelined frame after the response header survives
        std::string hdr = "HTTP/1.1 101 OK\r\n\r\n";
        std::string all = hdr + std::string("\x81\x02hi", 4);
        ClientHandshake c = client_handshake_response((const uint8_t*)all.data(), all.size());
        equ(c.header_len, hdr.size(), "only the header is dropped");
        ok(all.substr(c.header_len) == std::string("\x81\x02hi", 4), "frame preserved");
    }
}

static void test_frame_header() {
    area("frame-header");

    {
        uint8_t b[] = {0x81, 0x05};
        FrameHeader h;
        ok(parse_frame_header(b, 2, h) == HeaderStatus::Ok, "2-byte header parses");
        ok(h.fin, "byte0 bit7 = FIN");
        ok(!h.rsv1, "byte0 bit6 = RSV1");
        ok(!h.mask, "byte1 bit7 = MASK");
        equ(h.opcode, 0x1, "byte0 low nibble = opcode");
        equ(h.header_len, 2, "len<=125 -> 2-byte header");
        equ(h.payload_len, 5, "low 7 bits = length");
    }
    {
        uint8_t b[] = {0x82, 0x7E, 0x01, 0x00};
        FrameHeader h;
        ok(parse_frame_header(b, 4, h) == HeaderStatus::Ok, "0x7E header");
        equ(h.header_len, 4, "0x7E -> 4-byte header");
        equ(h.payload_len, 256, "buf[2]<<8|buf[3] big-endian");
        equ(h.opcode, 0x2, "binary");
    }
    {
        uint8_t b[] = {0x82, 0x7E, 0x00, 0x7E};
        FrameHeader h;
        parse_frame_header(b, 4, h);
        equ(h.payload_len, 126, "126 encoded as extended 16-bit still reads 126");
    }
    {
        uint8_t b[] = {0x88, 0x7F, 0, 0, 0, 0, 0x00, 0x00, 0x01, 0x00};
        FrameHeader h;
        ok(parse_frame_header(b, 10, h) == HeaderStatus::Ok, "0x7F header");
        equ(h.header_len, 10, "0x7F -> 10-byte header");
        equ(h.payload_len, 256, "low 4 bytes big-endian");
        equ(h.opcode, 0x8, "close");
    }
    {
        uint8_t b[] = {0x82, 0x7F, 0, 0, 0, 1, 0, 0, 0, 1};
        FrameHeader h;
        ok(parse_frame_header(b, 10, h) == HeaderStatus::Abort,
           "non-zero high 32 bits -> WSConn::exit()");
    }
    {
        uint8_t b[] = {0x82, 0x7F, 0, 0, 0, 0, 0, 0, 0, 1};
        FrameHeader h;
        ok(parse_frame_header(b, 10, h) == HeaderStatus::Ok, "zero high 32 bits accepted");
    }
    {
        uint8_t b[] = {0x82, 0x7F, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF};
        FrameHeader h;
        parse_frame_header(b, 10, h);
        equ(h.payload_len, 0xFFFFFFFFFFFFFFFFull, "signed 32-bit -> negative as ulong");
    }
    {
        uint8_t b[] = {0xF1, 0x00};   // FIN=1 RSV1=1 RSV2=1 RSV3=1 opcode=1
        FrameHeader h;
        parse_frame_header(b, 2, h);
        ok(h.rsv1, "RSV1 (0x40) detected");
        equ(h.opcode, 0x1, "RSV2/RSV3 do not affect opcode");
        uint8_t c[] = {0x91, 0x00};   // FIN=1 + RSV3 only
        FrameHeader h2;
        parse_frame_header(c, 2, h2);
        ok(!h2.rsv1, "RSV3 alone does not set RSV1");
        equ(h2.opcode, 0x1, "opcode still 1");
        uint8_t d2[] = {0xA1, 0x00};  // FIN=1 + RSV2 only
        FrameHeader h3;
        parse_frame_header(d2, 2, h3);
        ok(!h3.rsv1, "RSV2 alone does not set RSV1");
        equ(h3.opcode, 0x1, "opcode still 1");
    }
    {
        uint8_t b[] = {0x81, 0x85};
        FrameHeader h;
        parse_frame_header(b, 2, h);
        ok(h.mask, "byte1 bit7 = MASK");
        equ(h.payload_len, 5, "MASK bit not part of length");
    }
    {
        uint8_t b[] = {0x81};
        FrameHeader h;
        ok(parse_frame_header(b, 1, h) == HeaderStatus::NeedMore, "1 byte -> NeedMore");
        uint8_t c[] = {0x81, 0x7E, 0x01};
        ok(parse_frame_header(c, 3, h) == HeaderStatus::NeedMore, "0x7E incomplete -> NeedMore");
        uint8_t d[] = {0x81, 0x7F, 0, 0, 0, 0, 0, 0, 0};
        ok(parse_frame_header(d, 9, h) == HeaderStatus::NeedMore, "0x7F incomplete -> NeedMore");
    }
    {
        const uint8_t ops[] = {0x0, 0x1, 0x2, 0x8, 0x9, 0xA, 0x3, 0xB};
        for (uint8_t op : ops) {
            uint8_t b[] = {(uint8_t)(0x80 | op), 0x00};
            FrameHeader h;
            parse_frame_header(b, 2, h);
            equ(h.opcode, op, "opcode taken verbatim from low nibble");
        }
    }
}

static void test_mask() {
    area("mask");
    Connection c;
    std::string maskkey = hex2bin("37fa213d");
    std::string plain = "Hello";
    std::string masked;
    for (size_t i = 0; i < plain.size(); ++i)
        masked.push_back((char)(plain[i] ^ maskkey[i & 3]));
    std::string frame;
    frame.push_back((char)0x81);
    frame.push_back((char)(0x80 | plain.size()));
    frame += maskkey;
    frame += masked;
    c.feed(frame.data(), frame.size());
    ok(c.pump() == Connection::Event::Message, "masked frame -> Message");
    eq(c.last_message, "Hello", "XOR restores payload");

    {
        Connection d;
        std::string p = "ABCDEFGHI";           // 9 bytes
        std::string m;
        for (size_t i = 0; i < p.size(); ++i) m.push_back((char)(p[i] ^ maskkey[i & 3]));
        std::string f;
        f.push_back((char)0x81);
        f.push_back((char)(0x80 | p.size()));
        f += maskkey;
        f += m;
        d.feed(f.data(), f.size());
        d.pump();
        eq(d.last_message, p, "9-byte frame cycles mask index 0,1,2,3,...");
    }

    {
        Connection d;
        std::string k2 = hex2bin("00000000");
        std::string p2 = "world";
        std::string f2;
        f2.push_back((char)0x81);
        f2.push_back((char)(0x80 | p2.size()));
        f2 += k2;
        f2 += p2;
        d.feed(frame.data(), frame.size());
        ok(d.pump() == Connection::Event::Message, "frame 1");
        d.start_message();
        d.feed(f2.data(), f2.size());
        ok(d.pump() == Connection::Event::Message, "frame 2");
        eq(d.last_message, "world", "frame 2 uses its own mask key");
    }

    {
        Connection d;
        std::string f;
        f.push_back((char)0x81);
        f.push_back((char)0x03);
        f += "raw";
        d.feed(f.data(), f.size());
        ok(d.pump() == Connection::Event::Message, "unmasked frame");
        eq(d.last_message, "raw", "payload delivered as-is");
    }
}

static void test_control() {
    area("control");
    {
        Connection c;
        std::string f;
        f.push_back((char)0x89);
        f.push_back((char)0x04);
        f += "ping";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Dropped, "ping -> not delivered");
        ok(c.outbox.empty(), "ping produces no pong (no auto reply)");
        ok(!c.sent_any_close_frame(), "no Close frame");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x8A);
        f.push_back((char)0x00);
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Dropped, "pong -> not delivered");
        ok(c.outbox.empty(), "pong produces zero bytes");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x88);
        f.push_back((char)0x02);
        f += std::string("\x03\xe8", 2);     // 1000
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Close, "close -> Close event (nullptr buffer)");
        ok(c.outbox.empty(), "no automatic Close frame");
        eq(c.message, std::string("\x03\xe8", 2), "close payload consumed but code/reason not parsed");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x09);
        f.push_back((char)0x01);
        f += "A";
        f.push_back((char)0x81);
        f.push_back((char)0x01);
        f += "B";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Message, "FIN=0 ping treated as fragment start");
        eq(c.last_message, "AB", "payload accumulated (no control frame validation)");
    }
    {
        Connection c;
        std::string k = hex2bin("01020304");
        std::string pl = std::string("\x03\xe8", 2);
        std::string m;
        for (size_t i = 0; i < pl.size(); ++i) m.push_back((char)(pl[i] ^ k[i & 3]));
        std::string f;
        f.push_back((char)0x88);
        f.push_back((char)(0x80 | pl.size()));
        f += k;
        f += m;
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Close, "masked close recognised too");
    }
}

static void test_fragmentation() {
    area("frag");
    {
        Connection c;
        std::string f;
        f.push_back((char)0x81);
        f.push_back((char)0x02);
        f += "hi";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Message, "FIN=1 opcode=1 -> Message");
        eq(c.last_message, "hi", "payload");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x01); f.push_back((char)0x03); f += "Hel";
        f.push_back((char)0x80); f.push_back((char)0x02); f += "lo";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Dropped,
           "text fragments (0x01 + 0x80): last frame opcode 0 -> not delivered");
        eq(c.message, "Hello", "bytes still accumulate in the message buffer");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x01); f.push_back((char)0x01); f += "A";
        f.push_back((char)0x00); f.push_back((char)0x01); f += "B";
        f.push_back((char)0x81); f.push_back((char)0x01); f += "C";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Message, "three frames, last one opcode 1 -> Message");
        eq(c.last_message, "ABC", "concatenated in arrival order");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x82); f.push_back((char)0x01); f += "X";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Dropped, "opcode=2 never delivered (only 1 and 8)");
        eq(c.message, "X", "payload consumed");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x01); f.push_back((char)0x02); f += "ab";
        std::string k = hex2bin("ffffffff");
        std::string pl = "cd";
        std::string m;
        for (size_t i = 0; i < pl.size(); ++i) m.push_back((char)(pl[i] ^ k[i & 3]));
        f.push_back((char)0x81);
        f.push_back((char)(0x80 | pl.size()));
        f += k;
        f += m;
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Message, "fragment + masked final frame");
        eq(c.last_message, "abcd", "concatenation correct");
    }
}

static void test_buffer() {
    area("buffer");
    {
        std::string f;
        f.push_back((char)0x81); f.push_back((char)0x03); f += "abc";
        f.push_back((char)0x81); f.push_back((char)0x02); f += "de";
        Connection c;
        int got = 0;
        for (size_t i = 0; i < f.size(); ++i) {
            c.feed(f.data() + i, 1);
            Connection::Event e = c.pump();
            if (i + 1 < 5) ok(e == Connection::Event::NeedMore, "waits while incomplete");
            if (e == Connection::Event::Message) {
                ++got;
                if (got == 1) eq(c.last_message, "abc", "frame 1");
                if (got == 2) eq(c.last_message, "de", "frame 2");
                c.start_message();
            }
        }
        equ(got, 2, "byte-by-byte feeding completes both frames");
        ok(c.recvbuf.empty(), "buffer empty once fully consumed");
    }
    {
        Connection c;
        std::string f;
        f.push_back((char)0x81); f.push_back((char)0x01); f += "A";
        f.push_back((char)0x81); f.push_back((char)0x01); f += "B";
        c.feed(f.data(), f.size() - 1);          // one byte missing
        ok(c.pump() == Connection::Event::Message, "frame 1 complete");
        c.start_message();
        equ(c.recvbuf.size(), 2, "frame 2 header bytes stay in the buffer");
        ok(c.pump() == Connection::Event::NeedMore, "half packet waits");
        equ(c.recvbuf.size(), 0, "header consumed before the payload arrives");
        c.feed(f.data() + f.size() - 1, 1);
        ok(c.pump() == Connection::Event::Message, "completes after the last byte");
        eq(c.last_message, "B", "frame 2");
    }
    {
        Connection c;
        uint8_t b[] = {0x82, 0x7F, 0, 0, 0, 2, 0, 0, 0, 1};
        c.feed(b, sizeof b);
        ok(c.pump() == Connection::Event::Abort, "non-zero high words -> Abort(exit)");
    }
    {
        Connection c;
        uint8_t b[] = {0x82, 0x7F, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF};
        c.feed(b, sizeof b);
        ok(c.pump() == Connection::Event::NeedMore, "negative length -> never satisfied");
    }
    {
        Connection c;
        uint8_t b[] = {0x81, 0x00};
        c.feed(b, sizeof b);
        ok(c.pump() == Connection::Event::Message, "zero-length frame is delivered");
        eq(c.last_message, "", "empty message");
    }
}

static void test_deflate_boundary() {
    area("deflate");
    {
        Connection c;
        std::string f;
        f.push_back((char)0xC1); f.push_back((char)0x03); f += "raw";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::Message, "no negotiation -> no inflate");
        eq(c.last_message, "raw", "delivered as-is");
        Connection s;
        std::string part;
        part.push_back((char)0x41); part.push_back((char)0x01); part += "r";   // RSV1, FIN=0
        s.feed(part.data(), part.size());
        ok(s.pump() == Connection::Event::NeedMore, "FIN=0 waits for continuation");
        ok(s.rsv1, "sticky RSV1 flag set (this+0x59)");
    }
    {
        Connection c;
        c.deflate_negotiated = true;
        std::string f;
        f.push_back((char)0xC1); f.push_back((char)0x02); f += "zz";
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::NeedInflate, "external zlib required");
        eq(c.message, std::string("zz\x00\x00\xff\xff", 6), "00 00 FF FF appended before inflate");
    }
    {
        Connection c;
        c.deflate_negotiated = true;
        std::string f;
        f.push_back((char)0xC1); f.push_back((char)0x02); f += "zz";
        c.feed(f.data(), f.size());
        std::string seen;
        Connection::InflateFn inflate = [&](const std::string& in) {
            seen = in;
            return Connection::InflateResult{true, std::string("decoded")};
        };
        ok(c.pump(&inflate) == Connection::Event::Message, "delivery after successful inflate");
        eq(c.last_message, "decoded", "inflated result delivered");
        eq(seen, std::string("zz\x00\x00\xff\xff", 6), "zlib input carries the 4-byte tail");
    }
    {
        Connection c;
        c.deflate_negotiated = true;
        std::string f;
        f.push_back((char)0xC1); f.push_back((char)0x01); f += "z";
        c.feed(f.data(), f.size());
        Connection::InflateFn bad = [](const std::string&) {
            return Connection::InflateResult{false, std::string()};
        };
        ok(c.pump(&bad) == Connection::Event::Dropped, "inflate error -> no delivery (0xee80 returns 0)");
    }
    {
        Connection c;
        c.deflate_negotiated = true;
        std::string f;
        f.push_back((char)0x41); f.push_back((char)0x01); f += "a";   // RSV1=1 FIN=0
        f.push_back((char)0x80); f.push_back((char)0x01); f += "b";   // no RSV1
        c.feed(f.data(), f.size());
        ok(c.pump() == Connection::Event::NeedInflate, "sticky RSV1 still applies on continuation");
        eq(c.message, std::string("ab\x00\x00\xff\xff", 6), "concatenated, then one inflate");
    }
}

static void test_send() {
    area("send");
    Connection c;
    c.send_text("hello");
    eq(c.outbox, std::string("\x81\x05hello", 7), "0x81 + length + payload");
    ok(!c.sent_any_close_frame(), "library never emits a Close frame");

    c.outbox.clear();
    c.send_text(std::string(125, 'x'));
    equ((uint8_t)c.outbox[0], 0x81, "byte0 = 0x81");
    equ((uint8_t)c.outbox[1], 125, "125 uses the 7-bit length");
    equ(c.outbox.size(), 127, "125 -> 2-byte header");

    c.outbox.clear();
    c.send_text(std::string(126, 'x'));
    equ((uint8_t)c.outbox[1], 0x7E, "126 -> 0x7E");
    equ((uint8_t)c.outbox[2], 0x00, "high byte");
    equ((uint8_t)c.outbox[3], 0x7E, "low byte");

    c.outbox.clear();
    c.send_text(std::string(0xffff - 1, 'x'));
    equ((uint8_t)c.outbox[1], 0x7E, "65534 -> 16-bit");
    equ((uint8_t)c.outbox[2], 0xff, "65534 high byte");
    equ((uint8_t)c.outbox[3], 0xfe, "65534 low byte");

    // quirk: 65535 takes the 64-bit branch (`len < 0xffff`)
    c.outbox.clear();
    c.send_text(std::string(0xffff, 'x'));
    equ((uint8_t)c.outbox[1], 0x7F, "65535 -> 0x7F (64-bit branch)");
    equ((uint8_t)c.outbox[2], 0, "3rd byte 0");
    equ((uint8_t)c.outbox[3], 0, "4th byte 0");
    equ((uint8_t)c.outbox[4], 0, "5th byte 0");
    equ((uint8_t)c.outbox[5], 0, "6th byte 0");
    equ((uint8_t)c.outbox[6], 0, "len >>24");
    equ((uint8_t)c.outbox[7], 0, "len >>16");
    equ((uint8_t)c.outbox[8], 0xff, "len >>8");
    equ((uint8_t)c.outbox[9], 0xff, "len low byte");

    c.outbox.clear();
    c.send_text("abc", true);
    equ((uint8_t)c.outbox[0], 0xC1, "compressed frame byte0 = 0xC1 (RSV1=1,FIN=1,text)");
    equ((uint8_t)c.outbox[1] & 0x80, 0, "MASK always 0 (server does not mask)");

    std::string hdr = Connection::encode_frame_header(300, false);
    FrameHeader h;
    ok(parse_frame_header((const uint8_t*)hdr.data(), hdr.size(), h) == HeaderStatus::Ok,
       "self-produced header parses back");
    equ(h.payload_len, 300, "length round-trips");
    ok(h.fin && !h.mask, "FIN=1 and MASK=0");
}

int main() {
    test_sha1();
    test_base64();
    test_accept();
    test_client_request();
    test_client_response();
    test_server_handshake();
    test_frame_header();
    test_mask();
    test_control();
    test_fragmentation();
    test_buffer();
    test_deflate_boundary();
    test_send();

    std::printf("\nclaims: %d passed, %d failed\n", g_pass, g_fail);
    if (g_fail != 0) {
        std::printf("FAILED\n");
        return 1;
    }
    std::printf("all claims passed\n");
    return 0;
}
