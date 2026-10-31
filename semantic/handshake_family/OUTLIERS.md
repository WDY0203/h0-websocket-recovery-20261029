# 例外、建模偏差与 RFC 差距（O1–O12）

「例外」= 本族语义重建里**不能用一条表项直说**的地方：跨构建差异、dump 结构坑、
伪代码没给出的常量、以及原实现与 RFC 6455 的实质差距。
每条都标了影响面：是否影响断言、是否影响 `impl.cpp` 的行为。

---

## O1 · M17 是 py2/py3 唯一的语义差异（绑定层）

- **位置**：`FUN_0010a780`（py3 0x10a780 / py2 0x10a6b0）
- **差异**：py3 先看 `ob_type+0xab` 的 `0x08` 位决定 `PyUnicode_AsUTF8` 还是
  `PyBytes_Size/AsString`；py2 只有 `PyString_Size/AsString`。
- **影响**：协议零影响（都构造同一个 `std::string` 地址）。`test.cpp` 用
  `str_arg_kind()` 两条断言把两条分支都钉住。
- **附带**：py2 版本短 0x30 字节，因此该函数及其后函数的地址差是 **0xd0** 而非 0x100（见 O3）。

## O2 · dump 的低地址段是 PLT 槽位列表，地址元数据不可用

- **现象**：`IDX 0–~145` 的地址是 `.plt` 槽（`0x106ed8` 步长 0x10），但本地定义函数
  （`recv_pat/send/connect/exit/run`…）打印的是**真实函数体**。`IDX 2` 的 `0x106f10`
  与 `IDX 3` 的 `0x106f20` 只差 16 字节，不可能容纳 348 行。
- **处理**：所有 claim 只用高地址副本（`0x10a780` 以上）的地址与 `L` 行号；
  低地址段里体量大的块记为 `alias`（第二次反编译，局部变量命名风格不同）。
- **影响**：不影响语义，但**禁止**用低地址段的地址做 `addr` 断言。

## O3 · 地址平移不是恒定 0x100

- **事实**：M01–M16 为 `0x100`；M17/M18 为 `0xd0`。
- **原因**：Python 绑定区函数在 py2 里短了 0x30 字节（O1），其后整段上移。
- **影响**：`members.tsv` 的 `addr_delta` 列按成员给出；`test.cpp` C04 逐个核对。

## O4 · 客户端 key 是常量，不是随机数

- **证据**：M01 先把 `local_f8[16]` 逐字节清零，再直接 base64 编码；两者之间没有任何
  `RAND_bytes`/`getrandom`/`time` 调用。
- **结果**：每次连接的 `Sec-WebSocket-Key` 都是 `AAAAAAAAAAAAAAAAAAAAAA==`。
- **RFC**：§4.1 要求 16 字节随机 nonce。
- **影响**：已作为 M01 的正面断言（不是"未知"，是"确实如此"）。

## O5 · 客户端不校验握手响应

- **证据**：M03 全文没有状态码比较、没有 `Sec-WebSocket-Accept` 计算/比对、
  没有 `Upgrade`/`Connection` 检查。
- **结果**：任何以 `\r\n\r\n` 结尾的响应都被当成握手成功；`HTTP/1.1 500 ...\r\n\r\n`
  同样会进入已连接状态。
- **影响**：`impl.cpp` 如实实现（`scan_upgrade_response` 只回 deflate 标志与头部长度）。

## O6 · deflate 协商是"整包 substring 搜索 + 区分大小写"

- **证据**：`memmem(recvbuf, len, "permessage-deflate", 18)` 在**消费头部之前**对整个缓冲区搜索。
- **结果**：①响应中任何位置（含无关头部值）出现该字样即开启压缩；
  ②`Permessage-Deflate` 不会命中；③服务器没同意也可能被开启。
- **影响**：T3 的 S06/S07 就是这两条边界。

## O7 · `head_end == n` 是建模哨兵

- **事实**：`recv_pat` 在找不到 `\r\n\r\n` 时**不会**回调，所以真实代码里不存在"没找到头部"的分支。
- **处理**：`scan_upgrade_response` 在未命中时返回 `head_end = n`，仅用于测试表达"没消费"。
- **影响**：仅建模层，不对应任何原实现分支（T3/S01 用到了这个哨兵）。

## O8 · EOF 不回调、也不关写方向 —— 连接会滞留

- **证据**：`recv_proc` 在 `read()==0` 时只清 `recv_open(+0x58)` 与 `read_armed(+0x88)`，
  然后返回；`send_open(+0x59)` 保持 1，回收条件 `!0x58 && !0x59` 不成立。
- **后果**：对端关闭后，`TcpConn` 留在服务器的 fd 表里，直到本端也关闭写方向；
  上层 `WSConn` 收不到任何"对端关闭"事件。
- **连带**：`FUN_00111d50` 里"null Buffer → `WSConn::exit()`"这条路径从 `recv_proc`
  出发**不可达**（后者从不以 null 回调）。

## O9 · 硬写错误被当成"写完成"

- **证据**：`write()` 返回 -1 且 errno ≠ EAGAIN 时，代码继续走
  `if ((ulong)n < (ulong)queued)` —— `(ulong)(-1)` 极大，条件恒假，落入"写满"分支：
  清 `send_armed`、注销 EPOLLOUT、回调。
- **后果**：待发数据被静默丢弃，调用方看到的是"发送完成"。

## O10 · 事件循环的两个常量与 recv 超时的粒度

- `epoll_wait(..., maxevents = 1, ...)`：每轮只处理一个就绪事件。
- 超时 = `*(long*)(this+0x60) / 1000`，ctor 写死 `1000000`（µs）→ 1000 ms。
- `recv_timeout` 的预算存在 `handle+0xe8 = (long)(timeout * _DAT_0011f730)`，
  每 tick 由 `idle` 系列递减 1；`_DAT_0011f730` 是**浮点数据符号**，伪代码未给出值，
  本文**不猜**，只把它建模成参数 `ms_per_s`（`recv_budget_ms()`），不做常量断言。
- **影响**：`loop_timeout_ms(1000000)==1000` 有断言；乘数本身无断言。

## O11 · `exit()` 不发 Close 帧（没有 WS 关闭握手）

- **证据**：`WSConn::exit()` 全文没有 `WSConn::send`，也没有 `0x88`(Close) 帧构造。
- **行为**：只是把 `send_armed` 置 1、丢掉待发缓冲，让下一轮 `send_proc` 命中
  "无待发 → `shutdown(fd, SHUT_WR)`"，随后 TCP 半关。
- **RFC**：§5.5.1 要求先发 Close 帧并等待对端 Close。
- **影响**：`members.tsv` M14 的 role 明确写"3 waves…"，不把它当"正常关闭"。

## O12 · 两处字面量未定：`Py_BuildValue` 格式与提示字符串长度

- `FUN_00109f70` 结尾 `Py_BuildValue(&DAT_0011f3d1, 0)`：格式串是**数据符号**，
  无法从伪代码确定是 `"i"` 还是 `"l"`；本文只断言**返回值为 0**。
- `fwrite("recv(): recv_flag != false\n", 1, 0x1b, stderr)` 的 0x1b=27 与
  `"close(): send_flag != false\n"` 的 0x1c=28 均与字符串长度自洽，已核对，不属例外；
  列在此处仅为说明"哪些数字是**核对过**而不是猜的"。

---

## 建模偏差对照表

| 偏差 | 是否影响断言 | 说明 |
|---|---|---|
| `Buffer` 用 `std::string` 代替 `vector<unsigned char>` | 否 | 只影响容量语义，字符内容一致 |
| `recv_step` 不模拟 0x8000 缓冲的分配/搬移 | 否 | 断言只关心状态迁移与回调 |
| 事件注册用返回值结构体，不模拟真实 `epoll_ctl` | 否 | 断言只关心 interest word 与顺序 |
| `accept_key()` 的 padding 用标准 MD 补位 | 否 | 见 claims C17（inferred）；与 RFC 6455 样例对齐 |
| `TcpConn` 标志用 bool 而非 `char` | 否 | 位宽不影响语义 |
| `client_poll` 把 `getsockopt` 的结果作为入参 | 否 | 真实调用点由 `call_getsockopt` 标志表达 |
