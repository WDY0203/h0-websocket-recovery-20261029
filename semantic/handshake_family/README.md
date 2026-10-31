# H0WS 握手 / HTTP / 连接生命周期族 · L2 表驱动套件

目标：`bbwebsocket` 1.2.7（py2 构建 `bbwebsocket.so` / py3 构建 `bbwebsocket3.so`）里
**帧族之外**的协议面：客户端握手、HTTP 报文生成与响应扫描、`TcpConn`/`TcpClient` 的状态机与拆除。

方法：**静态语义重建**。只读分析，不运行原始二进制，不联网。
主源 `D:\tmp\H0WS3_all_decompiled.txt`（400 函数），对照 `D:\tmp\H0WS2_all_decompiled.txt`。

> 成员 **18** / 函数 **18** / 入表断言 **273** / claims **56**（inferred 3 = 5.4%）/
> 例外 **12**（O1–O12）/ 有效覆盖率 **100%**（184/184，分母 = 400 − 216 fragment）/
> py2 与 py3 归一化后 **17 个成员逐行相同，1 个只差绑定层分支（M17）**

---

## 0. 一句话结论

**握手只有一个方向是真的**：客户端（M01–M03）自己拼一个 `GET / HTTP/1.1` 升级请求就发出去，
但**key 是 16 个 0 字节的 base64（常量 `AAAAAAAAAAAAAAAAAAAAAA==`）**，
**响应只看有没有 `\r\n\r\n` 和有没有出现 `permessage-deflate` 字样**，
既不看 `101`、也不校验 `Sec-WebSocket-Accept`；服务端方向的 key/SHA1/Accept 逻辑在
`key_parse`（`frames_family` 的 M14，本文以 **alias** 记账，不重复实现）。

**连接生命周期是"两个方向各一个标志位"的极简状态机**：
`+0x58 recv_open`、`+0x59 send_open`、`+0x5a send_armed`、`+0x88 read_armed`；
两个方向都关掉才会被 `poll()` 回收删除。`WSConn::exit()` 并不发 Close 帧，
它只是把 `send_armed` 重新置 1 并把待发缓冲清空，好让下一轮 `send_proc` 走
"无待发 → `shutdown(fd, SHUT_WR)`" 这条路。

---

## 1. 文件

| 文件 | 内容 |
|---|---|
| `members.tsv` | 18 成员 + 2 条跨族 alias（frames M14）机器可读表 |
| `table.json` | T1–T12 共 12 张表 + 成员表 + 覆盖计数（测试的唯一数据源） |
| `impl.h` / `impl.cpp` | 逐语句转写：base64 / 握手请求 / 响应扫描 / SHA-1 / 连接状态机 / 拆除 / epoll 映射 |
| `test.cpp` | 读 `table.json`、`buckets.tsv` 驱动 273 条断言 + 4 类自检 |
| `claims.json` | 56 条 claim，带 `addr` + `L` 行号 + `status` + 对应测试 |
| `buckets.tsv` | 400 个函数逐条分桶（in_table / alias / cold / fragment）+ 理由 |
| `COVERAGE.md` | 覆盖口径与分桶统计 |
| `OUTLIERS.md` | 12 条例外（O1–O12）/ 建模偏差 / RFC 差距 |
| `crossbuild_diff.md` | 跨构建 diff：怎么配对、哪些相同、唯一差异是什么 |
| `gen_table.py` `mkcoverage.py` `mk_members.py` `mk_claims.py` | 生成器（可复现） |

复现：

```
python mkcoverage.py && python gen_table.py && g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

---

## 2. 选族：为什么是这 18 个

帧族（`semantic/frames_family/members.tsv`）已经覆盖了 `accept / key_parse / recv_pat /
read_head / hdr_parse / payload_* / finalize / recv / send / on_data` 共 16 个函数。
本文只取**它没有的**协议面，按三条线：

```
握手（客户端）      M01 WSConn::connect ──> M05 Buffer::appendf（拼请求）
                      └─ M02 等 "\r\n\r\n" ──> M03 扫响应 / 起 zlib / 消费头部
                      └─ M04 SHA-1 变换（服务端 accept 用；客户端不用）

报文与传输          M06 TcpClient(host,port) / M07 TcpClient(fd) / M08 TcpConn ctor
                      └─ M12 TcpClient::poll ─┐
                      └─ M13 TcpServer::poll ─┴─> M10 recv_proc / M11 send_proc

生命周期            M09 ~TcpConn / M14 WSConn::exit / M15 ~WSConn
                      └─ M16 EventLoop2::run（epoll 驱动）
                      └─ M17 connect(addr,port) / M18 disconnect(handle)（Python API）
```

`WSConn::accept` 与 `FUN_00112c60`(key_parse) 在 `members.tsv` 里以 **A01/A02** 出现，
`role` 明确写 `ALIAS -> frames_family M14`：本文**不重复实现**，只在流程叙述里引用。

---

## 3. 语义总览（据伪代码确定）

### 3.1 客户端握手（M01 → M02 → M03）

```
nonce[16] = {0}                                  // L14538 起逐字节清零
key       = base64(nonce)      = "AAAAAAAAAAAAAAAAAAAAAA=="   // 24 字符，恒定
buf       = appendf("GET / HTTP/1.1\r\n"
                    "Upgrade: websocket\r\n"
                    "Connection: Upgrade\r\n"
                    "Sec-WebSocket-Key: %s\r\n"
                    "Sec-WebSocket-Extensions: permessage-deflate\r\n"
                    "Sec-WebSocket-Version: 13\r\n\r\n", key)   // 共 177 字节
send_armed(+0x5a) = 1 ; pending(+0x60) = buf
callbacks: +0x78 = FUN_0010e2d0（manager）, +0x80 = FUN_0010fd40（等响应）
```

| 事实 | 证据 | 与 RFC 6455 |
|---|---|---|
| 请求行恒为 `GET /` | M01 立即数 | 路径不可配 |
| **没有 `Host:`** | 请求串里没有该字面量 | §4.1 要求 Host |
| key 是常量 16×0x00 | M01 先清零再编码 | §4.1 要求 16 随机字节 |
| 总是附带 `permessage-deflate` | 请求串常量 | 服务器可拒绝 |
| 发完就等 `\r\n\r\n`，无超时、无重试 | M02→recv_pat | — |

响应侧（M03）：

```
deflate = memmem(recvbuf, len, "permessage-deflate", 18) != NULL
if (deflate) { +0x58 = 1
   inflateInit2_(z_in , -15, "1.2.7", 0x70)
   deflateInit2_(z_out, -1, 8, -15, 8, 0, "1.2.7", 0x70)
   任一失败 -> +0x58 = 0，释放两个 z_stream
}
memmove(data, data + idx + 4, end - (data + idx + 4))   // idx = recv_pat 的 CRTFT 命中位置
cb()                                                    // 上层"已连接"
```

**没有**状态码比较、**没有** `Sec-WebSocket-Accept` 计算/比对、**没有**大小写折叠。
只要对端回了 `...\r\n\r\n`，握手即"成功"。

### 3.2 服务端握手（alias）

`frames_family` 已确认：`accept = base64(SHA1(key ‖ "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"))`，
回 101（129 字节；带扩展行 175 字节），无 key 时回 19 字节 `HTTP/1.0 200 OK\r\n\r\n` 或丢弃。
本文补上它调用的 **SHA-1 块变换**（M04）：`FUN_0010d720` 里
`0x5a827999 / 0x6ed9eba1 / 0x8f1bbcdc(写作 -0x70e44324) / 0xca62c1d6`
四个 K 常量与 5 字状态 `state[0..4] += a..e` 明确可见；测试用 RFC 3174 向量与
RFC 6455 §1.3 样例（`dGhlIHNhbXBsZSBub25jZQ==` → `s3pPLMBiTxaQ9kYGzzhZRbK+xOo=`）核对。

### 3.3 连接状态机

```
TcpClient 状态 +0x98:  0 = connecting, 1 = connected, 2 = failed
TcpConn   标志:        +0x58 recv_open   +0x59 send_open
                       +0x5a send_armed  +0x88 read_armed
```

| 事件 | 动作 | 结果 |
|---|---|---|
| `connect()` 返回 0 | `+0x98 = 1`，同步回调 `on_conn` | 直连成功 |
| `connect()` 返回 -1 且 errno=115 | 注册 EPOLLOUT，等 `poll` | 异步连接 |
| 其它 errno | `+0x98 = 2`、`perror("connect")`、`close`、`on_err(errno)` | 失败 |
| `poll`(state 0, OUT) | `getsockopt(1,4,SO_ERROR)` | 0 → state 1 + `on_conn`；否则 state 2 + `on_err` |
| `recv_proc` 读到 n>0 | 清 `read_armed`，回调 `Buffer` | 收数据 |
| `recv_proc` 读到 0 (EOF) | 清 `recv_open` + `read_armed` | **不回调**，半关 |
| `recv_proc` `-1/EAGAIN` | 什么都不做 | — |
| `recv_proc` 其它错误 | `perror("tcp recv")`，清 `recv_open/send_open/read_armed` | 整条连接报废 |
| `send_proc` 有待发 | `write`；短写 memmove 剩余到头部 | 保持 armed |
| `send_proc` 无待发 | 清 `send_open`、`shutdown(fd,1)`、清 armed、回调 | 写方向关闭 |
| `poll` 收尾 | `recv_open==0 && send_open==0` → erase + delete | 回收 |

两条"怪"但被断言钉住的行为：

1. **EOF 之后连接不会立刻被回收**：`recv_proc` 只清 `recv_open`，`send_open` 仍为 1，
   于是 `TcpServer::poll` 的 `&&` 条件不成立，连接对象留在表里，直到写方向也关闭。
2. **硬写错误被当成写完成**：`write` 返回 -1 且 errno≠EAGAIN 时，
   代码落到"写满"分支（无符号比较 `(ulong)n < len` 恒假），队列被丢弃、armed 清零。

### 3.4 拆除（M14/M15/M09）

```
WSConn::exit():
  wave1: if (+0x88 already) fprintf("recv(): recv_flag != false\n"); +0x88 = 1; 换 +0x90 回调
  wave2: if (+0x5a already) fprintf("close(): send_flag != false\n"); +0x5a = 1;
         +0x60 = NULL（丢掉待发缓冲）; 换 +0x68 回调
  wave3: 换 +0xb0（idle）回调
```

它**不发 Close 帧**（函数体内没有任何 `WSConn::send` 调用）。把 `send_armed` 重新置 1
并清空待发缓冲，是为了让下一轮 `send_proc` 命中"无待发"分支从而 `shutdown(SHUT_WR)`。
`~WSConn` 只在 `+0x58`（协商过压缩）时 `inflateEnd/deflateEnd`；`~TcpConn` 负责
`close(fd)` 并从 3 张 fd 表里摘除。

### 3.5 事件循环（M16）

```
interest = in ? (out ? 0x15 : 0x11) : (out ? 0x04 : 0x00)   // 0x11=IN|HUP, 0x15=IN|OUT|HUP
epoll_ctl(epfd, ADD|MOD, fd, events)
epoll_wait(epfd, &ev, 1, (this+0x60)/1000)                  // maxevents=1, 0x60=1000000us
EINTR(4) 忽略；其它错误 perror("epoll_wait") + print_stack_abort
```

`maxevents = 1` 意味着每轮只取一个就绪事件，吞吐上限被这个常量钉死。

### 3.6 Python API 层（M17/M18）

| API | 行为 |
|---|---|
| `connect(addr, port)` | 新建 `EventLoop2`；`addr[0]=='/'` → `UnixClient`，否则 `TcpClient`；`EventLoop2::add`；**同步跑 `run()`**；loop 正常返回后销毁 loop 并把 handle 置 0 |
| `disconnect(handle)` | 先按 `close(): send_flag` 路径关 WSConn，再 `run()` 把残留事件排空，最后销毁 loop，返回整数 0 |
| `send` / `recv_timeout` | 通过 `Channel` 投递/取消息，见 `buckets.tsv` 中 alias 行 |

即：**`connect()` 是一次阻塞的"跑到连接结束"调用**，不是常驻后台事件循环。

---

## 4. 跨构建 diff（摘要）

详见 `crossbuild_diff.md`。

| 结论 | 数值 |
|---|---|
| 成员总数 | 18 |
| py2/py3 归一化后**逐行相同** | **17 / 18** |
| 唯一差异 | M17（`connect(addr,port)`）：py3 走 `PyUnicode_AsUTF8` / `PyBytes_AsString`，py2 走 `PyString_AsString` |
| 该差异是否影响协议 | 否：只是字符串取址分支，连字节语义都相同（都带长度构造 `std::string`） |
| 地址平移 | 0x100（M01–M16），**0xd0**（M17/M18，绑定区函数长度不同导致） |

---

## 5. 套件与断言

| 表 | 成员 | 表项 | 内容 |
|---|---|---|---|
| T1 base64 | M01 | 7 | 空/1/2/3 字节/16 零/高位字节 |
| T2 upgrade request | M01 | 2 | 长度 177、前缀、key 偏移 76、尾部 CRLFCRLF |
| T3 response scan | M03 | 7 | deflate 命中/未命中/大小写/头部消费 |
| T4 sha1 | M04 | 4 | 空、abc、64×'a'（两块）、样例 nonce |
| T5 conn ctor flags | M08 | 4 | 0x58/0x59/0x5a/0x88 |
| T6 recv_step | M10 | 5 | bogus/EAGAIN/EOF/fatal/delivered |
| T7 send_step | M11 | 6 | bogus/drain/EAGAIN/partial/complete/硬错误 |
| T8 client_poll | M12 | 8 | 3 个状态 × 事件位 × fd 匹配 × 回收 |
| T9 server reap | M13 | 4 | 两个方向标志的四种组合 |
| T10 loop interest | M16 | 4 | 0x15/0x11/0x04/0x00 |
| T11 api transport | M17 | 4 | `/` 前缀 → Unix，空串 → TCP |
| T12 exit waves | M14 | 2 | 警告位与回调数量 |

自检：`C01` 每成员 ≥2 条且达到 `table.json` 声明数、`C02` 分桶 400 行且
有效覆盖率 ≥90%、`C04` 每个成员的 `py3-py2` 偏移与表一致、17 个相同。

运行结果见 `COVERAGE.md` 末尾（原文粘贴）。
