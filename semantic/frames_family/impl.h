// impl.h -- H0WS (bbwebsocket 1.2.7) WebSocket frame layer + HTTP handshake.
//
// Semantics transcribed from the py3 build (H0WS3_all_decompiled.txt) and
// byte-verified against the py2 build (H0WS2_all_decompiled.txt): every member
// of this family is identical in both builds modulo address/symbol renumbering.
//
// No original binary is executed by this suite. Everything here is a static
// re-derivation; see README.md for the pseudocode line references.

#ifndef H0WS_IMPL_H
#define H0WS_IMPL_H

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace h0ws {

// "not found" result of recv_pat / memmem miss.
constexpr size_t kNpos = static_cast<size_t>(-1);

// ---------------------------------------------------------------------------
// zlib-compatible status codes, only the values the inflate gate looks at.
// ---------------------------------------------------------------------------
enum ZStatus {
  Z_OK = 0,
  Z_STREAM_END = 1,
  Z_NEED_DICT = 2,
  Z_ERRNO = -1,
  Z_STREAM_ERROR = -2,
  Z_DATA_ERROR = -3,
  Z_MEM_ERROR = -4,
  Z_BUF_ERROR = -5
};

// Reproduces the binary's error predicate verbatim:
//   (iVar3 + 4U < 7) && ((1 << ((iVar3 + 4U) & 0x3f)) & 0x47U)
// which is exactly {Z_MEM_ERROR, Z_DATA_ERROR, Z_STREAM_ERROR, Z_NEED_DICT}.
bool zlib_fatal(int status);

// ---------------------------------------------------------------------------
// Handshake crypto / encoding.
// ---------------------------------------------------------------------------
extern const char kWsGuid[];  // "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"

std::vector<uint8_t> sha1(const std::vector<uint8_t> &in);      // FIPS 180-1
std::string base64(const std::vector<uint8_t> &in);
std::string sec_accept(const std::string &key);                 // base64(sha1(key+GUID))

// ---------------------------------------------------------------------------
// Raw DEFLATE (RFC 1951), i.e. what inflateInit2_(-15) / flate2 accept.
// ---------------------------------------------------------------------------
int inflate_raw(const uint8_t *in, size_t n, std::vector<uint8_t> &out);
std::vector<uint8_t> deflate_raw_stored(const uint8_t *in, size_t n, bool final_block);

// ---------------------------------------------------------------------------
// Frame header (WSConn::read_head -> FUN_001115a0 / FUN_00110a20 / FUN_00111b50)
// ---------------------------------------------------------------------------
struct FrameHeader {
  bool fin;      // b0 bit 7
  bool rsv1;     // b0 bit 6  (sticky at this+0x59)
  uint8_t opcode;  // b0 & 0x0f  (RSV2/RSV3 bits are never inspected)
  bool masked;   // b1 bit 7
  uint8_t len7;  // b1 & 0x7f
};
FrameHeader parse_frame_header(const uint8_t *h);   // requires >= 2 bytes

uint16_t decode_len16(const uint8_t *h);            // big-endian h[2],h[3]
int64_t decode_len64(const uint8_t *h, bool *protocol_exit);  // sign-extended

// ---------------------------------------------------------------------------
// Buffer helpers (WSConn::recv_pat / WSConn::recv_more)
// ---------------------------------------------------------------------------
size_t recv_pat(const std::vector<uint8_t> &hay, const std::vector<uint8_t> &needle);
bool recv_more_ready(uint64_t need, uint64_t have);

// In-place unmask as performed by FUN_00110e50:
//   dst[old + i] = masked[i] ^ mask[i & 3]      (i restarts at 0 every frame)
void unmask_into(std::vector<uint8_t> &dst, const uint8_t *masked, size_t n,
                 const uint8_t mask[4]);

// ---------------------------------------------------------------------------
// Server handshake (WSConn::accept + FUN_00112c60)
// ---------------------------------------------------------------------------
enum class HsKind { NeedMore, Reject, Switching101, Http200 };

struct Handshake {
  HsKind kind = HsKind::NeedMore;
  std::vector<uint8_t> bytes;   // bytes the library would enqueue
  std::string path;             // Http200 only
  std::string key;              // extracted Sec-WebSocket-Key
  bool neg_deflate = false;     // "permessage-deflate" found
  size_t header_end = std::string::npos;
};

Handshake server_handshake(const std::vector<uint8_t> &req);

// ---------------------------------------------------------------------------
// WSConn: the frame state machine.
//
// The original has no explicit state object -- it is a chain of recv_more()
// continuations.  This class collapses that chain into a synchronous pump()
// with identical observable behaviour: at most one delivered message per
// recv()/feed() cycle, and the parser stops (without consuming the next
// frame) as soon as a FIN=1 frame has been handled.
// ---------------------------------------------------------------------------
class Conn {
public:
  std::vector<uint8_t> recvbuf;   // this+0x40
  std::vector<uint8_t> msg;       // this+0x48
  bool neg_deflate = false;       // this+0x58 (from handshake)
  bool rsv1 = false;              // this+0x59 (sticky, cleared by recv())
  bool exited = false;            // WSConn::exit() was reached
  bool ub_guard = false;          // see OUTLIERS.md (unreachable UB corner)

  bool last_finalize_compressed = false;
  bool last_finalize_ok = true;
  int last_opcode = -1;

  std::vector<std::vector<uint8_t>> delivered;  // opcode 1 payloads
  int delivered_null = 0;                       // opcode 8 -> callback(nullptr)

  void recv();                                   // WSConn::recv
  void feed(const uint8_t *p, size_t n);         // FUN_00112080 (on_data)
  void feed(const std::vector<uint8_t> &v) { feed(v.data(), v.size()); }
  void feed_null();                              // on_data with a null Buffer -> exit()

  std::vector<uint8_t> send(const std::vector<uint8_t> &payload);  // WSConn::send

  bool pending() const { return in_body_ || !recvbuf.empty(); }

private:
  bool in_body_ = false;
  FrameHeader cur_{};
  int64_t cur_len_ = 0;

  void pump();
  void append_plain();
  void append_masked();
  bool finalize(bool compressed);
  void finish_message();
};

}  // namespace h0ws

#endif  // H0WS_IMPL_H
