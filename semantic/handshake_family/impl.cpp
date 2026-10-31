#include "impl.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>

namespace h0ws {

const char* const kUpgradeRequestFmt =
    "GET / HTTP/1.1\r\n"
    "Upgrade: websocket\r\n"
    "Connection: Upgrade\r\n"
    "Sec-WebSocket-Key: %s\r\n"
    "Sec-WebSocket-Extensions: permessage-deflate\r\n"
    "Sec-WebSocket-Version: 13\r\n\r\n";           // M01, py3 0x1123f4..0x1124a0

const char* const kBase64Alphabet =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

const char* const kDeflateNeedle = "permessage-deflate";
const char* const kHeadNeedle = "\r\n\r\n";
const char* const kWsGuid = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

// ------------------------------------------------------------------ M01 base64
// Inlined encoder: '=' is part of the alphabet string and is written for the two
// short-final-group cases; it never reads past the 16-byte nonce.
std::string base64_encode(const std::uint8_t* data, std::size_t n) {
  std::string out;
  out.reserve(((n + 2) / 3) * 4);
  std::size_t i = 0;
  while (i + 3 <= n) {
    std::uint32_t v = (std::uint32_t(data[i]) << 16) | (std::uint32_t(data[i + 1]) << 8) |
                      std::uint32_t(data[i + 2]);
    out.push_back(kBase64Alphabet[(v >> 18) & 0x3f]);
    out.push_back(kBase64Alphabet[(v >> 12) & 0x3f]);
    out.push_back(kBase64Alphabet[(v >> 6) & 0x3f]);
    out.push_back(kBase64Alphabet[v & 0x3f]);
    i += 3;
  }
  std::size_t rem = n - i;
  if (rem == 1) {
    std::uint32_t v = std::uint32_t(data[i]) << 16;
    out.push_back(kBase64Alphabet[(v >> 18) & 0x3f]);
    out.push_back(kBase64Alphabet[(v >> 12) & 0x3f]);
    out.push_back('=');
    out.push_back('=');
  } else if (rem == 2) {
    std::uint32_t v = (std::uint32_t(data[i]) << 16) | (std::uint32_t(data[i + 1]) << 8);
    out.push_back(kBase64Alphabet[(v >> 18) & 0x3f]);
    out.push_back(kBase64Alphabet[(v >> 12) & 0x3f]);
    out.push_back(kBase64Alphabet[(v >> 6) & 0x3f]);
    out.push_back('=');
  }
  return out;
}

std::string client_key() {
  std::uint8_t nonce[kNonceBytes];
  std::memset(nonce, 0, sizeof(nonce));  // local_f8[0..0xf] = 0, one store each
  return base64_encode(nonce, sizeof(nonce));
}

std::string upgrade_request(const std::string& key) {
  std::string out;
  buffer_appendf(out, kUpgradeRequestFmt, key);
  return out;
}

// ------------------------------------------------------------------ M03 response scan
RespScan scan_upgrade_response(const char* data, std::size_t n) {
  RespScan r{false, n};
  if (data == nullptr) return r;
  // memmem(data, n, "permessage-deflate", 18) over the whole buffer,
  // before the head is consumed (py3 L? -> 0x10dce0).
  const std::size_t nl = std::strlen(kDeflateNeedle);
  if (n >= nl) {
    for (std::size_t i = 0; i + nl <= n; ++i) {
      if (std::memcmp(data + i, kDeflateNeedle, nl) == 0) {
        r.deflate = true;
        break;
      }
    }
  }
  // recv_pat("\r\n\r\n") hands back the index of the match; the closure then moves
  // data by idx + 4 and memmoves the remainder down (0x10dd9e..0x10ddd0).
  for (std::size_t i = 0; i + kHeadLen <= n; ++i) {
    if (std::memcmp(data + i, kHeadNeedle, kHeadLen) == 0) {
      r.head_end = i + kHeadLen;
      break;
    }
  }
  return r;
}

DeflateSetup establish_deflate(bool response_mentions_deflate) {
  DeflateSetup s{0, 0, 0, 0, 0, 0, 0, false};
  if (!response_mentions_deflate) return s;  // flag 0x58 stays 0
  // inflateInit2_(strm, 0xfffffff1 /* -15 */, "1.2.7", 0x70)
  // deflateInit2_(strm, 0xffffffff /* -1 */, 8, 0xfffffff1, 8, 0, "1.2.7", 0x70)
  s.inflate_window_bits = -15;
  s.deflate_level = -1;
  s.deflate_method = 8;
  s.deflate_window_bits = -15;
  s.deflate_mem_level = 8;
  s.deflate_strategy = 0;
  s.version_len = 5;  // strlen("1.2.7")
  s.ok = true;
  return s;
}

// ------------------------------------------------------------------ M04 SHA-1
static inline std::uint32_t rotl32(std::uint32_t x, int n) {
  return (x << n) | (x >> (32 - n));
}

void sha1_block(std::uint32_t state[5], const std::uint8_t block[64]) {
  std::uint32_t w[80];
  for (int i = 0; i < 16; ++i) {
    w[i] = (std::uint32_t(block[i * 4]) << 24) | (std::uint32_t(block[i * 4 + 1]) << 16) |
           (std::uint32_t(block[i * 4 + 2]) << 8) | std::uint32_t(block[i * 4 + 3]);
  }
  for (int i = 16; i < 80; ++i) w[i] = rotl32(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);

  std::uint32_t a = state[0], b = state[1], c = state[2], d = state[3], e = state[4];
  for (int i = 0; i < 80; ++i) {
    std::uint32_t f, k;
    if (i < 20) {
      f = (b & c) | ((~b) & d);
      k = 0x5a827999u;
    } else if (i < 40) {
      f = b ^ c ^ d;
      k = 0x6ed9eba1u;
    } else if (i < 60) {
      f = (b & c) | (b & d) | (c & d);
      k = 0x8f1bbcdcu;
    } else {
      f = b ^ c ^ d;
      k = 0xca62c1d6u;
    }
    std::uint32_t tmp = rotl32(a, 5) + f + e + k + w[i];
    e = d;
    d = c;
    c = rotl32(b, 30);
    b = a;
    a = tmp;
  }
  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;
  state[4] += e;
}

std::array<std::uint8_t, kSha1DigestBytes> sha1(const void* data, std::size_t n) {
  std::uint32_t h[5] = {0x67452301u, 0xefcdab89u, 0x98badcfeu, 0x10325476u, 0xc3d2e1f0u};
  const std::uint8_t* p = static_cast<const std::uint8_t*>(data);
  std::size_t full = n / 64;
  for (std::size_t i = 0; i < full; ++i) sha1_block(h, p + i * 64);

  std::uint8_t tail[128];
  std::memset(tail, 0, sizeof(tail));
  std::size_t rem = n - full * 64;
  if (rem) std::memcpy(tail, p + full * 64, rem);
  tail[rem] = 0x80;
  std::size_t tail_len = (rem < 56) ? 64 : 128;
  std::uint64_t bits = static_cast<std::uint64_t>(n) * 8u;
  for (int i = 0; i < 8; ++i) tail[tail_len - 1 - i] = std::uint8_t(bits >> (8 * i));
  sha1_block(h, tail);
  if (tail_len == 128) sha1_block(h, tail + 64);

  std::array<std::uint8_t, kSha1DigestBytes> out{};
  for (int i = 0; i < 5; ++i) {
    out[i * 4 + 0] = std::uint8_t(h[i] >> 24);
    out[i * 4 + 1] = std::uint8_t(h[i] >> 16);
    out[i * 4 + 2] = std::uint8_t(h[i] >> 8);
    out[i * 4 + 3] = std::uint8_t(h[i]);
  }
  return out;
}

std::string accept_key(const std::string& key) {
  // accept = base64(SHA1(key || GUID)); the update/final bytes are inlined in key_parse.
  std::string seed = key + kWsGuid;
  auto d = sha1(seed.data(), seed.size());
  return base64_encode(d.data(), d.size());
}

// ------------------------------------------------------------------ M05 Buffer::appendf
static void appendf_v(std::string& buf, const char* fmt, va_list ap) {
  va_list ap2;
  va_copy(ap2, ap);
  int n = std::vsnprintf(nullptr, 0, fmt, ap);
  std::size_t len = buf.size();
  if (n < 0) {
    va_end(ap2);
    return;
  }
  buf.resize(len + std::size_t(n) + 1);  // +1 for the NUL that is written then trimmed
  std::vsnprintf(&buf[len], std::size_t(n) + 1, fmt, ap2);
  va_end(ap2);
  buf.resize(len + std::size_t(n));
}

static void appendf(std::string& buf, const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  appendf_v(buf, fmt, ap);
  va_end(ap);
}

void buffer_appendf(std::string& buf, const char* fmt, const std::string& arg) {
  appendf(buf, fmt, arg.c_str());
}

// ------------------------------------------------------------------ M06 connect plan
ClientPlan plan_tcp_client() {
  ClientPlan p{};
  p.family = kAfInet;         // socket(2, 1, 0)
  p.type = kSockStream;
  p.proto = 0;
  p.sockopt_level = kIpprotoTcp;
  p.sockopt_opt = kTcpNodelay;
  p.sockopt_val = 1;
  p.nonblock = true;          // setnonblock()
  p.cloexec = true;           // setcloexec()
  p.connect_mask = 0x10;      // sizeof(sockaddr_in)
  p.async_on_einprogress = true;
  p.fail_state = 2;
  return p;
}

ConnectOutcome classify_connect(int rc, int err) {
  if (rc == 0) return ConnectOutcome::kConnectedNow;
  if (err == kEinprogress) return ConnectOutcome::kInProgress;
  return ConnectOutcome::kFailed;
}

// ------------------------------------------------------------------ M08 ctor flags
FdClientPlan fd_client_plan() {
  FdClientPlan p{};
  p.opens_socket = false;     // no socket() call in this ctor
  p.probes_connect = false;   // no connect() either
  p.state_connected = true;   // this+0x98 = 1
  p.empty_host = true;        // std::string("")
  p.empty_name = true;        // std::string("")
  p.calls_on_conn_sync = true;
  return p;
}

ConnFlags conn_ctor_flags() {
  ConnFlags f{};
  f.recv_open = true;   // +0x58 = 1
  f.send_open = true;   // +0x59 = 1
  f.send_armed = false; // +0x5a = 0
  f.read_armed = false; // +0x88 = 0
  return f;
}

// ------------------------------------------------------------------ M12 client poll
ClientPoll client_poll(ClientState st, int events, int so_error, bool fd_matches,
                       const ConnFlags& f) {
  ClientPoll r{st, false, false, false, 0, false};
  if (st == ClientState::Connected) {
    if (fd_matches) {
      if (events & kBitOut) r.call_send = true;  // param_2 & 2 -> send_proc  (first)
      if (events & kBitIn) r.call_recv = true;   // param_2 & 1 -> recv_proc  (second)
    }
    // return (0x58 != 0) ? 0 : (0x59 ^ 1)
    r.reap = (!f.recv_open && !f.send_open);
    return r;
  }
  if (st == ClientState::Failed) {
    r.reap = true;  // return 1
    return r;
  }
  // Connecting: only EPOLLOUT wakes it, and the fd must match the one in the conn.
  if (!fd_matches || !(events & kBitOut)) return r;
  r.call_getsockopt = true;  // getsockopt(1 /*SOL_SOCKET*/, 4 /*SO_ERROR*/)
  if (so_error == 0) {
    r.next = ClientState::Connected;
    r.cb = 1;  // on_conn(conn) at +0xb8/+0xc0
  } else {
    r.next = ClientState::Failed;
    r.cb = 2;  // on_err(errno value) at +0xd8/+0xe0
  }
  return r;
}

// ------------------------------------------------------------------ M10 recv_proc
RecvStep recv_step(const ConnFlags& f, long n, int err) {
  RecvStep r{RecvKind::kAgain, false, false, false, false};
  if (!f.read_armed) {
    // fprintf(stderr, "TcpConn: bogus recv: fd=%d\n", fd) then kill both directions.
    r.kind = RecvKind::kBogus;
    r.clear_recv_open = true;
    r.clear_send_open = true;
    return r;
  }
  if (n < 0) {
    if (err == kEagain) {
      r.kind = RecvKind::kAgain;  // no state change at all
      return r;
    }
    r.kind = RecvKind::kFatal;  // perror("tcp recv")
    r.clear_recv_open = true;
    r.clear_send_open = true;
    r.clear_read_armed = true;
    return r;
  }
  if (n == 0) {
    r.kind = RecvKind::kEof;  // peer half-close: no callback, send side stays open
    r.clear_recv_open = true;
    r.clear_read_armed = true;
    return r;
  }
  r.kind = RecvKind::kDelivered;
  r.clear_read_armed = true;
  r.fire_on_read = true;
  return r;
}

// ------------------------------------------------------------------ M11 send_proc
SendStep send_step(bool send_armed, bool has_pending, std::size_t queued, long n, int err) {
  SendStep r{SendKind::kAgain, false, false, false, false, queued};
  if (!send_armed) {
    r.kind = SendKind::kBogus;  // fprintf(stderr, "TcpConn: bogus send: fd=%d\n", fd)
    return r;
  }
  if (!has_pending) {
    // Nothing queued: close the write direction and fire the write-completion callback.
    r.kind = SendKind::kDrainAndShutdown;
    r.clear_send_open = true;
    r.clear_send_armed = true;
    r.shutdown_wr = true;
    r.fire_write_cb = true;
    r.unsent = 0;
    return r;
  }
  if (n < 0) {
    if (err == kEagain) {
      r.kind = SendKind::kAgain;
      return r;
    }
    // Any other errno falls through to the "completed" branch: the queue is dropped.
    r.kind = SendKind::kComplete;
    r.clear_send_armed = true;
    r.fire_write_cb = true;
    r.unsent = 0;
    return r;
  }
  if (std::size_t(n) < queued) {
    r.kind = SendKind::kPartial;  // memmove the tail to the front, stay armed
    r.unsent = queued - std::size_t(n);
    return r;
  }
  r.kind = SendKind::kComplete;
  r.clear_send_armed = true;
  r.fire_write_cb = true;
  r.unsent = 0;
  return r;
}

// ------------------------------------------------------------------ M13 server poll
bool server_should_reap(const ConnFlags& f) {
  // if (conn[0x58] == 0 && conn[0x59] == 0) erase + delete
  return !f.recv_open && !f.send_open;
}

ServerDispatch server_dispatch(int events) {
  ServerDispatch d{};
  d.call_send = (events & kBitOut) != 0;
  d.call_recv = (events & kBitIn) != 0;
  d.send_before_recv = true;  // send_proc() then recv_proc()
  return d;
}

// ------------------------------------------------------------------ M09 / M15 dtors
DtorPlan tcpconn_dtor_plan() {
  DtorPlan p{};
  p.end_zlib = false;
  p.buffers_freed = 1;  // unique_ptr<Buffer> at +0x60
  p.close_fd = true;    // close(fd)
  p.listener_trees_erased = 3;
  return p;
}

DtorPlan wsconn_dtor_plan(bool deflate_negotiated) {
  DtorPlan p{};
  p.end_zlib = deflate_negotiated;  // inflateEnd(+0x60) + deflateEnd(+0x68)
  p.buffers_freed = 3;              // +0x50, +0x48, +0x40
  p.close_fd = false;
  p.listener_trees_erased = 1;
  return p;
}

// ------------------------------------------------------------------ M14 exit
ExitPlan wsconn_exit_plan(bool recv_flag_already, bool send_flag_already) {
  ExitPlan p{};
  p.warn_recv_flag = recv_flag_already;  // "recv(): recv_flag != false\n" (27 bytes)
  p.set_recv_flag = true;
  p.warn_send_flag = send_flag_already;  // "close(): send_flag != false\n" (28 bytes)
  p.set_send_flag = true;
  p.drop_pending = true;                 // +0x60 = 0
  p.callbacks_replaced = 3;              // +0x90, +0x68, +0xb0
  return p;
}

// ------------------------------------------------------------------ M16 loop
int loop_interest_word(bool in, bool out) {
  // uVar8 = 0x11; if (out) { events = 4; uVar8 = 0x15; } if (in) events = uVar8;
  if (in) return out ? (kEpollIn | kEpollOut | kEpollHup) : (kEpollIn | kEpollHup);
  if (out) return kEpollOut;
  return 0;
}

int loop_timeout_ms(long timeout_us) { return int(timeout_us / 1000); }

// ------------------------------------------------------------------ M17 / M18 API
ApiConnectPlan api_connect_plan(const std::string& addr) {
  ApiConnectPlan p{};
  p.is_unix = !addr.empty() && addr[0] == '/';
  p.run_loop_inline = true;             // EventLoop2::run() before PyLong_FromVoidPtr
  p.return_handle_zero_on_loop_ok = true;
  return p;
}

ApiDisconnectPlan api_disconnect_plan(bool handle_valid, bool wsconn_valid) {
  ApiDisconnectPlan p{};
  p.closes_wsconn = handle_valid && wsconn_valid;
  p.runs_loop = handle_valid;
  p.destroys_loop = handle_valid;
  p.returns = 0;  // Py_BuildValue(<DAT_0011f3d1>, 0) -> integer 0
  return p;
}

StrArgKind str_arg_kind(bool type_flags_bytes_bit) {
  // py3 branch: (*(byte*)(ob_type + 0xab) & 8) == 0 -> PyUnicode_AsUTF8, else bytes
  return type_flags_bytes_bit ? StrArgKind::kBytes : StrArgKind::kUnicode;
}

bool loop_starts_running() { return true; }  // this[0x54] = 1 in EventLoop2::EventLoop2

long recv_budget_ms(double timeout_s, double ms_per_s) {
  return static_cast<long>(timeout_s * ms_per_s);  // (long)(param_1 * _DAT_0011f730)
}

}  // namespace h0ws
