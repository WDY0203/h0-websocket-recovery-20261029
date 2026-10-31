// H0WS handshake/HTTP/connection-lifecycle family -- semantic transcription.
// Reconstructed statically from D:\tmp\H0WS3_all_decompiled.txt (py3 build, canonical
// high-address copy) and cross-checked against D:\tmp\H0WS2_all_decompiled.txt (py2 build).
// This is NOT a re-implementation of a WebSocket library: every branch below mirrors the
// decompiled control flow, including the quirks, so that the table-driven tests have
// discriminating power.
#ifndef H0WS_IMPL_H
#define H0WS_IMPL_H

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <vector>

namespace h0ws {

// ---------------------------------------------------------------- wire constants
// M01: the client sends this exact request template (Buffer::appendf, py3 0x1123b0).
extern const char* const kUpgradeRequestFmt;   // contains one %s
extern const char* const kBase64Alphabet;      // "A..Za..z0..9+/="  ('=' is the pad)
extern const char* const kDeflateNeedle;       // "permessage-deflate"
extern const char* const kHeadNeedle;          // "\r\n\r\n"
extern const char* const kWsGuid;              // RFC 6455 magic GUID

constexpr std::size_t kNonceBytes      = 16;   // local_f8[16], zero-filled
constexpr std::size_t kKeyChars        = 24;   // base64 of 16 bytes
constexpr std::size_t kNeedleLen       = 18;   // memmem(..., "permessage-deflate", 0x12)
constexpr std::size_t kHeadLen         = 4;    // "\r\n\r\n"
constexpr std::size_t kRequestLen      = 177;  // template (153) + key (24)
constexpr std::size_t kSha1DigestBytes = 20;

// socket()/setsockopt()/getsockopt()/shutdown() literals seen in M06/M12
constexpr int kAfInet         = 2;
constexpr int kSockStream     = 1;
constexpr int kIpprotoTcp     = 6;
constexpr int kTcpNodelay     = 1;
constexpr int kSolSocket      = 1;
constexpr int kSoError        = 4;
constexpr int kShutWr         = 1;
constexpr int kEagain         = 0x0b;   // 11
constexpr int kEinprogress    = 0x73;   // 115
constexpr int kEintr          = 4;
constexpr int kRecvChunk      = 0x8000; // 32768
constexpr int kEpollCloexec   = 0x80000;
constexpr int kEpollMaxEvents = 1;      // epoll_wait(..., 1, ...)

// M16: epoll interest words are built from two internal bits only.
constexpr int kBitIn          = 1;      // tree value bit 0
constexpr int kBitOut         = 2;      // tree value bit 1
constexpr int kEpollIn        = 0x1;
constexpr int kEpollOut       = 0x4;
constexpr int kEpollHup       = 0x10;

// ---------------------------------------------------------------- handshake (M01-M05)
std::string base64_encode(const std::uint8_t* data, std::size_t n);

// M01: the 16-byte nonce is zero-filled in the decompiled body, so the key is constant.
std::string client_key();
std::string upgrade_request(const std::string& key);

// M03: one pass over the received bytes. `deflate` is memmem() over the WHOLE buffer,
// `head_end` is the index just past the first "\r\n\r\n" (recv_pat's match + 4).
struct RespScan {
  bool deflate;
  std::size_t head_end;
};
RespScan scan_upgrade_response(const char* data, std::size_t n);

// M03: zlib objects are created with these exact literals on a successful negotiation.
struct DeflateSetup {
  int inflate_window_bits;
  int deflate_level;
  int deflate_method;
  int deflate_window_bits;
  int deflate_mem_level;
  int deflate_strategy;
  int version_len;
  bool ok;
};
DeflateSetup establish_deflate(bool response_mentions_deflate);

// M04: SHA-1 block transform. `state` is h0..h4 (a..e); one 64-byte block is absorbed.
void sha1_block(std::uint32_t state[5], const std::uint8_t block[64]);
std::array<std::uint8_t, kSha1DigestBytes> sha1(const void* data, std::size_t n);
// RFC 6455 accept value; the padding/update/final part lives inlined in key_parse.
std::string accept_key(const std::string& key);

// M05: Buffer::appendf -- vsnprintf twice, grow by len+1, then trim the NUL.
void buffer_appendf(std::string& buf, const char* fmt, const std::string& arg);

// ---------------------------------------------------------------- lifecycle (M06-M13)
struct ClientPlan {
  int family;
  int type;
  int proto;
  int sockopt_level;
  int sockopt_opt;
  int sockopt_val;
  bool nonblock;
  bool cloexec;
  int connect_mask;   // htons()'d? no: raw port bytes, see impl
  bool async_on_einprogress;
  int fail_state;     // state written on hard failure
};
ClientPlan plan_tcp_client();

// M06: result of connect(fd, sockaddr, 16).
enum class ConnectOutcome { kConnectedNow, kInProgress, kFailed };
ConnectOutcome classify_connect(int rc, int err);

// M07: TcpClient(int fd, ...) adopts a ready fd.
struct FdClientPlan {
  bool opens_socket;
  bool probes_connect;
  bool state_connected;
  bool empty_host;
  bool empty_name;
  bool calls_on_conn_sync;
};
FdClientPlan fd_client_plan();

// M08: TcpConn::TcpConn initial flags.
struct ConnFlags {
  bool recv_open;   // +0x58
  bool send_open;   // +0x59
  bool send_armed;  // +0x5a
  bool read_armed;  // +0x88
};
ConnFlags conn_ctor_flags();

enum class ClientState { Connecting = 0, Connected = 1, Failed = 2 };

// M12: TcpClient::poll(fd, events) decision table. `cb` names the callback that fires:
// 0 none, 1 on_conn, 2 on_err.
struct ClientPoll {
  ClientState next;
  bool call_send;
  bool call_recv;
  bool call_getsockopt;
  int cb;
  bool reap;
};
ClientPoll client_poll(ClientState st, int events, int so_error, bool fd_matches,
                       const ConnFlags& f);

// M10: TcpConn::recv_proc outcome.
enum class RecvKind { kDelivered, kAgain, kEof, kFatal, kBogus };
struct RecvStep {
  RecvKind kind;
  bool clear_recv_open;
  bool clear_send_open;
  bool clear_read_armed;
  bool fire_on_read;
};
RecvStep recv_step(const ConnFlags& f, long n, int err);

// M11: TcpConn::send_proc outcome.
enum class SendKind { kBogus, kDrainAndShutdown, kAgain, kPartial, kComplete };
struct SendStep {
  SendKind kind;
  bool clear_send_open;
  bool clear_send_armed;
  bool shutdown_wr;
  bool fire_write_cb;
  std::size_t unsent;  // bytes still queued after this call
};
SendStep send_step(bool send_armed, bool has_pending, std::size_t queued, long n, int err);

// M13: TcpServer::poll reap condition, and dispatch order.
bool server_should_reap(const ConnFlags& f);
struct ServerDispatch { bool call_send; bool call_recv; bool send_before_recv; };
ServerDispatch server_dispatch(int events);

// M09/M15: teardown.
struct DtorPlan {
  bool end_zlib;
  int buffers_freed;
  bool close_fd;
  int listener_trees_erased;
};
DtorPlan tcpconn_dtor_plan();
DtorPlan wsconn_dtor_plan(bool deflate_negotiated);

// M14: WSConn::exit() -- three waves, each with its own stderr guard.
struct ExitPlan {
  bool warn_recv_flag;
  bool set_recv_flag;
  bool warn_send_flag;
  bool set_send_flag;
  bool drop_pending;
  int callbacks_replaced;
};
ExitPlan wsconn_exit_plan(bool recv_flag_already, bool send_flag_already);

// ---------------------------------------------------------------- loop / API (M16-M18)
// M16: internal interest bits -> epoll event word.
int loop_interest_word(bool in, bool out);
int loop_timeout_ms(long timeout_us);

struct ApiConnectPlan {
  bool is_unix;          // addr non-empty and addr[0] == '/'
  bool run_loop_inline;  // EventLoop2::run() is called before returning
  bool return_handle_zero_on_loop_ok;
};
ApiConnectPlan api_connect_plan(const std::string& addr);

struct ApiDisconnectPlan {
  bool closes_wsconn;
  bool runs_loop;
  bool destroys_loop;
  int  returns;
};
ApiDisconnectPlan api_disconnect_plan(bool handle_valid, bool wsconn_valid);

// M17: argument extraction branch (py3: unicode vs bytes; py2: always PyString).
enum class StrArgKind { kUnicode, kBytes };
StrArgKind str_arg_kind(bool type_flags_bytes_bit);

// M18/M17 bootstrapping helpers.
bool loop_starts_running();
long recv_budget_ms(double timeout_s, double ms_per_s);

}  // namespace h0ws

#endif
