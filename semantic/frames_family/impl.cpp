// impl.cpp -- H0WS (bbwebsocket 1.2.7) frame layer + HTTP handshake.
//
// This is a static re-derivation from the decompiled pseudocode.  The original
// binary is never executed.  Addresses in comments are py3-build addresses;
// the py2 build is identical after symbol renumbering (see members.tsv).

#include "impl.h"

#include <cstring>

namespace h0ws {

const char kWsGuid[] = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

// ---------------------------------------------------------------------------
// zlib error predicate (FUN_0010ef80, pseudocode line 48):
//   (iVar3 + 4U < 7) && ((1 << ((iVar3 + 4U) & 0x3f)) & 0x47U)
// ---------------------------------------------------------------------------
bool zlib_fatal(int status) {
  const unsigned off = static_cast<unsigned>(status + 4);
  if (off >= 7u) return false;
  return (0x47u & (1u << (off & 0x1fu))) != 0u;
}

// ---------------------------------------------------------------------------
// SHA-1, FIPS 180-1 (FUN_0010d620, 80 rounds fully unrolled in the binary)
// ---------------------------------------------------------------------------
namespace {

inline uint32_t rotl32(uint32_t x, int n) {
  return (x << n) | (x >> (32 - n));
}

}  // namespace

std::vector<uint8_t> sha1(const std::vector<uint8_t> &in) {
  const uint64_t bitlen = static_cast<uint64_t>(in.size()) * 8u;

  std::vector<uint8_t> m = in;
  m.push_back(0x80);
  while (m.size() % 64 != 56) m.push_back(0x00);
  for (int i = 7; i >= 0; --i) m.push_back(static_cast<uint8_t>(bitlen >> (8 * i)));

  uint32_t h[5] = {0x67452301u, 0xEFCDAB89u, 0x98BADCFEu, 0x10325476u, 0xC3D2E1F0u};

  for (size_t off = 0; off < m.size(); off += 64) {
    uint32_t w[80];
    for (int i = 0; i < 16; ++i) {
      w[i] = (static_cast<uint32_t>(m[off + 4 * i]) << 24) |
             (static_cast<uint32_t>(m[off + 4 * i + 1]) << 16) |
             (static_cast<uint32_t>(m[off + 4 * i + 2]) << 8) |
             static_cast<uint32_t>(m[off + 4 * i + 3]);
    }
    for (int i = 16; i < 80; ++i)
      w[i] = rotl32(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);

    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];
    for (int i = 0; i < 80; ++i) {
      uint32_t f, k;
      if (i < 20) {
        f = (b & c) | ((~b) & d);
        k = 0x5A827999u;
      } else if (i < 40) {
        f = b ^ c ^ d;
        k = 0x6ED9EBA1u;
      } else if (i < 60) {
        f = (b & c) | (b & d) | (c & d);
        k = 0x8F1BBCDCu;
      } else {
        f = b ^ c ^ d;
        k = 0xCA62C1D6u;
      }
      const uint32_t t = rotl32(a, 5) + f + e + k + w[i];
      e = d;
      d = c;
      c = rotl32(b, 30);
      b = a;
      a = t;
    }
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
  }

  std::vector<uint8_t> out(20);
  for (int i = 0; i < 5; ++i) {
    out[4 * i + 0] = static_cast<uint8_t>(h[i] >> 24);
    out[4 * i + 1] = static_cast<uint8_t>(h[i] >> 16);
    out[4 * i + 2] = static_cast<uint8_t>(h[i] >> 8);
    out[4 * i + 3] = static_cast<uint8_t>(h[i]);
  }
  return out;
}

std::string base64(const std::vector<uint8_t> &in) {
  static const char *T =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::string out;
  size_t i = 0;
  while (i + 3 <= in.size()) {
    const uint32_t v = (static_cast<uint32_t>(in[i]) << 16) |
                       (static_cast<uint32_t>(in[i + 1]) << 8) |
                       static_cast<uint32_t>(in[i + 2]);
    out.push_back(T[(v >> 18) & 0x3f]);
    out.push_back(T[(v >> 12) & 0x3f]);
    out.push_back(T[(v >> 6) & 0x3f]);
    out.push_back(T[v & 0x3f]);
    i += 3;
  }
  const size_t rem = in.size() - i;
  if (rem == 1) {
    const uint32_t v = static_cast<uint32_t>(in[i]) << 16;
    out.push_back(T[(v >> 18) & 0x3f]);
    out.push_back(T[(v >> 12) & 0x3f]);
    out += "==";
  } else if (rem == 2) {
    const uint32_t v = (static_cast<uint32_t>(in[i]) << 16) |
                       (static_cast<uint32_t>(in[i + 1]) << 8);
    out.push_back(T[(v >> 18) & 0x3f]);
    out.push_back(T[(v >> 12) & 0x3f]);
    out.push_back(T[(v >> 6) & 0x3f]);
    out += "=";
  }
  return out;
}

std::string sec_accept(const std::string &key) {
  std::vector<uint8_t> in(key.begin(), key.end());
  const char *g = kWsGuid;
  in.insert(in.end(), g, g + 36);
  return base64(sha1(in));
}

// ---------------------------------------------------------------------------
// Raw DEFLATE decoder (RFC 1951), canonical-Huffman form.
// ---------------------------------------------------------------------------
namespace {

struct BitState {
  const uint8_t *in = nullptr;
  size_t n = 0;
  size_t incnt = 0;
  uint32_t bitbuf = 0;
  int bitcnt = 0;
  bool err = false;

  int byte() {
    if (incnt >= n) {
      err = true;
      return 0;
    }
    return in[incnt++];
  }
  int bits(int need) {
    if (need <= 0) return 0;
    uint32_t val = bitbuf;
    while (bitcnt < need) {
      if (incnt >= n) {
        err = true;
        return 0;
      }
      val |= static_cast<uint32_t>(in[incnt++]) << bitcnt;
      bitcnt += 8;
    }
    bitbuf = val >> need;
    bitcnt -= need;
    return static_cast<int>(val & ((1u << need) - 1u));
  }
  // Discard the padding bits of the current byte (bitcnt is always < 8 here).
  void align() {
    bitbuf = 0;
    bitcnt = 0;
  }
};

struct Huff {
  uint16_t count[16];
  uint16_t symbol[288];
};

void huff_build(Huff &h, const uint8_t *lens, int n) {
  for (int i = 0; i < 16; ++i) h.count[i] = 0;
  for (int i = 0; i < n; ++i) h.count[lens[i]]++;
  h.count[0] = 0;
  uint16_t offs[16];
  offs[0] = 0;
  offs[1] = 0;
  for (int l = 1; l < 15; ++l) offs[l + 1] = static_cast<uint16_t>(offs[l] + h.count[l]);
  for (int i = 0; i < n; ++i)
    if (lens[i]) h.symbol[offs[lens[i]]++] = static_cast<uint16_t>(i);
}

int huff_decode(BitState &s, const Huff &h) {
  int code = 0, first = 0, index = 0;
  for (int len = 1; len <= 15; ++len) {
    code |= s.bits(1);
    if (s.err) return -1;
    const int count = h.count[len];
    if (code - first < count) return h.symbol[index + (code - first)];
    index += count;
    first = (first + count) << 1;
    code <<= 1;
  }
  return -1;
}

const int kLenBase[29] = {3,  4,  5,  6,  7,  8,  9,  10, 11,  13,  15,  17,  19,  23, 27,
                          31, 35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
const int kLenExtra[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2,
                           2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
const int kDistBase[30] = {1,    2,    3,    4,    5,    7,     9,     13,    17,   25,
                           33,   49,   65,   97,   129,  193,   257,   385,   513,  769,
                           1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577};
const int kDistExtra[30] = {0, 0, 0, 0, 1, 1, 2, 2,  3,  3,  4,  4,  5,  5,  6,
                            6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

int inflate_block(BitState &s, std::vector<uint8_t> &out, const Huff &lit, const Huff &dist) {
  for (;;) {
    const int sym = huff_decode(s, lit);
    if (sym < 0) return Z_DATA_ERROR;
    if (sym < 256) {
      out.push_back(static_cast<uint8_t>(sym));
      continue;
    }
    if (sym == 256) return Z_OK;  // end of block
    const int li = sym - 257;
    if (li >= 29) return Z_DATA_ERROR;
    int length = kLenBase[li] + s.bits(kLenExtra[li]);
    if (s.err) return Z_DATA_ERROR;
    const int dsym = huff_decode(s, dist);
    if (dsym < 0 || dsym >= 30) return Z_DATA_ERROR;
    const unsigned d = static_cast<unsigned>(kDistBase[dsym] + s.bits(kDistExtra[dsym]));
    if (s.err) return Z_DATA_ERROR;
    if (d == 0 || d > out.size()) return Z_DATA_ERROR;
    size_t from = out.size() - d;
    for (int i = 0; i < length; ++i) {
      const uint8_t v = out[from + static_cast<size_t>(i)];
      out.push_back(v);
    }
  }
}

int inflate_stored(BitState &s, std::vector<uint8_t> &out) {
  s.align();
  const int l0 = s.byte(), l1 = s.byte(), n0 = s.byte(), n1 = s.byte();
  if (s.err) return Z_DATA_ERROR;
  const unsigned len = static_cast<unsigned>(l0) | (static_cast<unsigned>(l1) << 8);
  const unsigned nlen = static_cast<unsigned>(n0) | (static_cast<unsigned>(n1) << 8);
  if ((len ^ 0xffffu) != nlen) return Z_DATA_ERROR;
  for (unsigned i = 0; i < len; ++i) {
    const int b = s.byte();
    if (s.err) return Z_DATA_ERROR;
    out.push_back(static_cast<uint8_t>(b));
  }
  return Z_OK;
}

void fixed_tables(Huff &lit, Huff &dist) {
  uint8_t l[288];
  for (int i = 0; i < 144; ++i) l[i] = 8;
  for (int i = 144; i < 256; ++i) l[i] = 9;
  for (int i = 256; i < 280; ++i) l[i] = 7;
  for (int i = 280; i < 288; ++i) l[i] = 8;
  huff_build(lit, l, 288);
  uint8_t d[30];
  for (int i = 0; i < 30; ++i) d[i] = 5;
  huff_build(dist, d, 30);
}

int inflate_dynamic(BitState &s, std::vector<uint8_t> &out) {
  static const int order[19] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
  const int nlen = s.bits(5) + 257;
  const int ndist = s.bits(5) + 1;
  const int ncode = s.bits(4) + 4;
  if (s.err) return Z_DATA_ERROR;
  if (nlen > 286 || ndist > 30) return Z_DATA_ERROR;

  uint8_t lens[320];
  std::memset(lens, 0, sizeof(lens));
  for (int i = 0; i < ncode; ++i) {
    const int v = s.bits(3);
    if (s.err) return Z_DATA_ERROR;
    lens[order[i]] = static_cast<uint8_t>(v);
  }
  Huff lencode;
  huff_build(lencode, lens, 19);

  int idx = 0;
  const int total = nlen + ndist;
  while (idx < total) {
    const int sym = huff_decode(s, lencode);
    if (sym < 0) return Z_DATA_ERROR;
    if (sym < 16) {
      lens[idx++] = static_cast<uint8_t>(sym);
    } else if (sym == 16) {
      if (idx == 0) return Z_DATA_ERROR;
      const uint8_t prev = lens[idx - 1];
      int rep = 3 + s.bits(2);
      if (s.err) return Z_DATA_ERROR;
      while (rep-- > 0 && idx < total) lens[idx++] = prev;
    } else if (sym == 17) {
      int rep = 3 + s.bits(3);
      if (s.err) return Z_DATA_ERROR;
      while (rep-- > 0 && idx < total) lens[idx++] = 0;
    } else {
      int rep = 11 + s.bits(7);
      if (s.err) return Z_DATA_ERROR;
      while (rep-- > 0 && idx < total) lens[idx++] = 0;
    }
  }

  Huff lit, dist;
  huff_build(lit, lens, nlen);
  huff_build(dist, lens + nlen, ndist);
  return inflate_block(s, out, lit, dist);
}

}  // namespace

int inflate_raw(const uint8_t *in, size_t n, std::vector<uint8_t> &out) {
  out.clear();
  BitState s;
  s.in = in;
  s.n = n;

  for (;;) {
    // zlib's inflate() returns Z_OK when it runs out of input mid-stream.
    if (s.incnt >= s.n) return Z_OK;
    const int last = s.bits(1);
    if (s.err) return Z_DATA_ERROR;
    const int type = s.bits(2);
    if (s.err) return Z_DATA_ERROR;

    int rc;
    if (type == 0) {
      rc = inflate_stored(s, out);
    } else if (type == 1) {
      Huff lit, dist;
      fixed_tables(lit, dist);
      rc = inflate_block(s, out, lit, dist);
    } else if (type == 2) {
      rc = inflate_dynamic(s, out);
    } else {
      return Z_DATA_ERROR;  // BTYPE == 3
    }
    if (rc != Z_OK) return rc;
    if (last) return Z_STREAM_END;
  }
}

std::vector<uint8_t> deflate_raw_stored(const uint8_t *in, size_t n, bool final_block) {
  std::vector<uint8_t> out;
  if (n == 0) {
    out.push_back(final_block ? 0x01 : 0x00);
    out.push_back(0x00);
    out.push_back(0x00);
    out.push_back(0xff);
    out.push_back(0xff);
    return out;
  }
  size_t off = 0;
  while (off < n) {
    size_t chunk = n - off;
    if (chunk > 65535) chunk = 65535;
    const bool last = final_block && (off + chunk == n);
    out.push_back(static_cast<uint8_t>(last ? 0x01 : 0x00));
    out.push_back(static_cast<uint8_t>(chunk & 0xff));
    out.push_back(static_cast<uint8_t>((chunk >> 8) & 0xff));
    const uint16_t nl = static_cast<uint16_t>(~static_cast<uint16_t>(chunk));
    out.push_back(static_cast<uint8_t>(nl & 0xff));
    out.push_back(static_cast<uint8_t>(nl >> 8));
    out.insert(out.end(), in + off, in + off + chunk);
    off += chunk;
  }
  return out;
}

// ---------------------------------------------------------------------------
// Frame header
// ---------------------------------------------------------------------------
FrameHeader parse_frame_header(const uint8_t *h) {
  const uint8_t b0 = h[0];
  const uint8_t b1 = h[1];
  FrameHeader f;
  f.fin = ((b0 >> 7) & 1u) != 0u;
  f.rsv1 = (b0 & 0x40u) != 0u;
  f.opcode = static_cast<uint8_t>(b0 & 0x0fu);
  f.masked = ((b1 >> 7) & 1u) != 0u;
  f.len7 = static_cast<uint8_t>(b1 & 0x7fu);
  return f;
}

uint16_t decode_len16(const uint8_t *h) {
  return static_cast<uint16_t>((static_cast<uint16_t>(h[2]) << 8) | h[3]);
}

int64_t decode_len64(const uint8_t *h, bool *protocol_exit) {
  *protocol_exit = false;
  if (h[2] || h[3] || h[4] || h[5]) {
    *protocol_exit = true;  // high 32 bits must be zero, else WSConn::exit()
    return 0;
  }
  const uint32_t v = (static_cast<uint32_t>(h[6]) << 24) | (static_cast<uint32_t>(h[7]) << 16) |
                     (static_cast<uint32_t>(h[8]) << 8) | static_cast<uint32_t>(h[9]);
  return static_cast<int64_t>(static_cast<int32_t>(v));  // (long)(int)  -> sign extends
}

// ---------------------------------------------------------------------------
// Buffer helpers
// ---------------------------------------------------------------------------
size_t recv_pat(const std::vector<uint8_t> &hay, const std::vector<uint8_t> &needle) {
  if (needle.empty()) return 0;  // glibc memmem: nlen == 0 returns haystack
  if (needle.size() > hay.size()) return kNpos;
  const uint8_t first = needle[0];
  const size_t limit = hay.size() - needle.size();
  for (size_t i = 0; i <= limit; ++i) {
    if (hay[i] != first) continue;
    if (std::memcmp(hay.data() + i, needle.data(), needle.size()) == 0) return i;
  }
  return kNpos;
}

bool recv_more_ready(uint64_t need, uint64_t have) { return need <= have; }

void unmask_into(std::vector<uint8_t> &dst, const uint8_t *masked, size_t n,
                 const uint8_t mask[4]) {
  const size_t old = dst.size();
  dst.resize(old + n);
  for (size_t i = 0; i < n; ++i)
    dst[old + i] = static_cast<uint8_t>(masked[i] ^ mask[i & 3u]);
}

// ---------------------------------------------------------------------------
// Server handshake (WSConn::accept + FUN_00112c60)
// ---------------------------------------------------------------------------
Handshake server_handshake(const std::vector<uint8_t> &req) {
  Handshake hs;

  const std::vector<uint8_t> term = {'\r', '\n', '\r', '\n'};
  const size_t idx = recv_pat(req, term);
  if (idx == kNpos) {
    hs.kind = HsKind::NeedMore;
    return hs;
  }
  hs.header_end = idx;

  const char *kname = "Sec-WebSocket-Key: ";
  const std::vector<uint8_t> keyhdr(kname, kname + 19);
  const size_t kpos = recv_pat(req, keyhdr);
  if (kpos != kNpos) {
    const int len = static_cast<int>(req.size());
    int i = 0;
    for (;;) {
      if (i + 19 >= len) break;  // iVar12 - 0x13 <= i
      const char c = static_cast<char>(req[kpos + 19 + static_cast<size_t>(i)]);
      if (c == '\r' || c == '\n') break;
      hs.key.push_back(c);
      ++i;
      if (i == 127) break;  // do..while (lVar24 != 0x7f)
    }
  }

  if (!hs.key.empty()) {
    const char *ext = "permessage-deflate";
    const std::vector<uint8_t> extv(ext, ext + 18);
    hs.neg_deflate = (recv_pat(req, extv) != kNpos);

    std::string r;
    r += "HTTP/1.1 101 Switching Protocols\r\n";
    r += "Upgrade: websocket\r\n";
    r += "Connection: Upgrade\r\n";
    if (hs.neg_deflate) r += "Sec-WebSocket-Extensions: permessage-deflate\r\n";
    r += "Sec-WebSocket-Accept: ";
    r += sec_accept(hs.key);
    r += "\r\n\r\n";
    hs.bytes.assign(r.begin(), r.end());
    hs.kind = HsKind::Switching101;
    return hs;
  }

  // No (or empty) key: the request line decides 200-OK vs discard.
  if (req.size() > 5 && std::memcmp(req.data(), "GET /", 5) == 0 && req[5] != '/') {
    std::string path;
    if (req[5] != ' ' && req[5] != '\r' && req[5] != '\n') {
      const int len = static_cast<int>(req.size());
      int u = 0;
      char cur = static_cast<char>(req[5]);
      for (;;) {
        path.push_back(cur);
        if (u == len - 6) break;
        const char nxt = static_cast<char>(req[6 + static_cast<size_t>(u)]);
        if (nxt == '.' && cur == '.') {  // adjacent ".." wipes the whole path
          path.clear();
          break;
        }
        if (nxt == '\r' || nxt == ' ' || nxt == '\n') break;
        ++u;
        cur = nxt;
      }
    }
    hs.path = path;
    const char *ok = "HTTP/1.0 200 OK\r\n\r\n";
    hs.bytes.assign(ok, ok + 19);
    hs.kind = HsKind::Http200;
    return hs;
  }

  hs.kind = HsKind::Reject;
  return hs;
}

// ---------------------------------------------------------------------------
// Conn
// ---------------------------------------------------------------------------
void Conn::recv() {
  msg.clear();
  rsv1 = false;          // this[0x59] = 0
  in_body_ = false;
  pump();
}

void Conn::feed(const uint8_t *p, size_t n) {
  if (n) recvbuf.insert(recvbuf.end(), p, p + n);
  pump();
}

void Conn::feed_null() { exited = true; }  // null Buffer -> WSConn::exit()

void Conn::pump() {
  for (;;) {
    if (exited) return;
    if (!in_body_) {
      if (recvbuf.size() < 2) return;  // read_head waits for 2 bytes
      const FrameHeader h = parse_frame_header(recvbuf.data());
      if (h.rsv1) rsv1 = true;  // sticky, set before the length dispatch

      int64_t len = 0;
      size_t hdr = 2;
      if (h.len7 == 0x7e) {
        if (recvbuf.size() < 4) return;  // recv_more(4)
        len = static_cast<int64_t>(decode_len16(recvbuf.data()));
        hdr = 4;
      } else if (h.len7 == 0x7f) {
        if (recvbuf.size() < 10) return;  // recv_more(10)
        bool pexit = false;
        len = decode_len64(recvbuf.data(), &pexit);
        if (pexit) {
          exited = true;
          return;
        }
        hdr = 10;
      } else {
        len = static_cast<int64_t>(h.len7);
      }
      recvbuf.erase(recvbuf.begin(), recvbuf.begin() + static_cast<std::ptrdiff_t>(hdr));
      cur_ = h;
      cur_len_ = len;
      in_body_ = true;
    }

    // read_data / read_data_mask both funnel through recv_more(n).
    const int64_t need_s = cur_len_ + (cur_.masked ? 4 : 0);
    if (!recv_more_ready(static_cast<uint64_t>(need_s),
                         static_cast<uint64_t>(recvbuf.size())))
      return;

    if (cur_len_ < 0) {  // see OUTLIERS.md: original is UB here
      ub_guard = true;
      return;
    }
    if (cur_.masked) {
      append_masked();
    } else {
      append_plain();
    }
    recvbuf.erase(recvbuf.begin(), recvbuf.begin() + static_cast<std::ptrdiff_t>(need_s));
    in_body_ = false;
    last_opcode = cur_.opcode;

    if (!cur_.fin) continue;  // FIN=0 -> read_head() again
    finish_message();
    return;  // one delivered frame per cycle
  }
}

void Conn::append_plain() {
  msg.insert(msg.end(), recvbuf.begin(),
             recvbuf.begin() + static_cast<std::ptrdiff_t>(cur_len_));
}

void Conn::append_masked() {
  uint8_t mask[4];
  for (int i = 0; i < 4; ++i) mask[i] = recvbuf[static_cast<size_t>(i)];
  unmask_into(msg, recvbuf.data() + 4, static_cast<size_t>(cur_len_), mask);
}

bool Conn::finalize(bool compressed) {
  if (!compressed) return true;  // FUN_0010ef80 returns 1 immediately
  msg.push_back(0x00);           // permessage-deflate tail append
  msg.push_back(0x00);
  msg.push_back(0xff);
  msg.push_back(0xff);
  std::vector<uint8_t> out;
  const int rc = inflate_raw(msg.data(), msg.size(), out);
  if (zlib_fatal(rc)) return false;
  msg.swap(out);
  return true;
}

void Conn::finish_message() {
  const bool compressed = neg_deflate ? rsv1 : false;  // this+0x58 ? this+0x59 : 0
  last_finalize_compressed = compressed;
  const bool ok = finalize(compressed);
  last_finalize_ok = ok;
  if (!ok) return;

  if (cur_.opcode == 1) {
    delivered.push_back(msg);
    msg.clear();  // the buffer is taken away (this+0x48 = 0)
  } else if (cur_.opcode == 8) {
    delivered_null++;  // callback receives a null unique_ptr; payload never parsed
  }
  // every other opcode is silently discarded
}

std::vector<uint8_t> Conn::send(const std::vector<uint8_t> &payload) {
  std::vector<uint8_t> body;
  uint8_t b0;

  if (!neg_deflate) {
    b0 = 0x81;  // FIN=1, opcode=1 (text)
    body = payload;
  } else {
    b0 = 0xc1;  // FIN=1, RSV1=1, opcode=1
    body = deflate_raw_stored(payload.data(), payload.size(), false);
    // zlib Z_SYNC_FLUSH tail: an empty stored block is 5 bytes (00 00 00 FF FF);
    // permessage-deflate strips the last 4, leaving the 0x00 header in the payload.
    body.push_back(0x00);
    body.push_back(0x00);
    body.push_back(0x00);
    body.push_back(0xff);
    body.push_back(0xff);
    body.resize(body.size() - 4);
  }

  std::vector<uint8_t> out;
  out.push_back(b0);
  const size_t n = body.size();
  if (n > 0x7du) {
    if (n < 0xffffu) {
      out.push_back(0x7e);
      out.push_back(static_cast<uint8_t>(n >> 8));
    } else {
      out.push_back(0x7f);
      out.push_back(0x00);
      out.push_back(0x00);
      out.push_back(0x00);
      out.push_back(0x00);
      out.push_back(static_cast<uint8_t>(n >> 24));
      out.push_back(static_cast<uint8_t>(n >> 16));
      out.push_back(static_cast<uint8_t>(n >> 8));
    }
  }
  out.push_back(static_cast<uint8_t>(n & 0xff));
  out.insert(out.end(), body.begin(), body.end());
  return out;
}

}  // namespace h0ws
