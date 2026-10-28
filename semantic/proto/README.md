# H0WS2 (`bbwebsocket` 1.2.7) — WebSocket 协议层语义重建

只读分析产物。**不运行原始二进制、不联网**；所有结论来自

* 反编译清单 `D:\tmp\H0WS2_all_decompiled.txt`（下文 `L12345` = 该文件的全局行号）
* `readelf -sW` 动态符号表（本 .so 未 strip，保留 215 个 `FUNC` 符号）
* `.rodata` 原始字节（`0x1f280..0x1fe16`，共 `0xb96` 字节）
* `objdump -d`（`_dis.txt`，下文 `@0x12345` = **镜像地址**）

> **地址约定**：反编译清单的块头地址比 ELF 里的地址大 `0x100000`。
> `===== IDX 232 00112b60 ... =====` ⇒ 镜像地址 `0x12b60`，与 `readelf`/`objdump` 一致。
> 本文所有 `@0x...` 都是镜像地址。

---

## 0. 一句话结论

这是一个**极简、非严格**的 WebSocket 实现：服务端握手只认 `Sec-WebSocket-Key` 一个头（不校验
`Upgrade`/`Connection`/`Version`/请求行），客户端 `Sec-WebSocket-Key` 是**常量**
（`base64(16×0x00)`）且**完全不校验服务器响应**（只看有没有 `\r\n\r\n`），接收端只投递 `opcode=1`，
`ping/pong` 被静默吞掉，**全库不会发出任何 Close/Ping/Pong 帧**，且标准的文本分片
（`0x01` + `0x80`）因末帧 `opcode=0` 而**不会投递**。

---

## 1. `.rodata` 常量表（握手关键）

| 地址 | 长度 | 内容（转义） | 用途 |
|---|---|---|---|
| `0x1f280` | 11 | `bbwebsocket` | 模块名 |
| `0x1f28c` | 27 | `recv(): recv_flag != false\n` | 断言日志 |
| `0x1f2a8` | 28 | `close(): send_flag != false\n` | 断言日志 |
| `0x1f634` | 22 | `\x80\x84\x2eApermessage-deflate` | 前 4 字节是死填充；有效串是 `0x1f638` |
| `0x1f638` | 18 | `permessage-deflate` | **协商用的 memmem 针**（`@0x138d6`/`@0x138dd`, `@0xdbc2`） |
| `0x1f64b` | 5 | `1.2.7` | zlib 版本串（`inflateInit2_` 第 3 参） |
| `0x1f687` | 27 | `send(): send_flag != false\n` | 断言日志 |
| `0x1f6a3` | 19 | `Sec-WebSocket-Key: `（含尾空格） | 服务端 `memmem` 查找 |
| `0x1f6b7` | 5 | `GET /` | 请求行前缀比较（`repz cmps`） |
| `0x1f6bd` | 19 | `HTTP/1.0 200 OK\r\n\r\n` | 非升级请求的回退响应 |
| `0x1f6cc` | 4 | `\r\n\r\n` | 握手等待用的针（链接器把字面量合并进上一条的尾部，`@0xfa66`/`@0xfcf2`） |
| `0x1f6d0` | 1 | ``（空串） | 101 的 `%s` 占位 / `..` 清空路径 |
| `0x1f6d8` | 155 | `GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Key: %s\r\nSec-WebSocket-Extensions: permessage-deflate\r\nSec-WebSocket-Version: 13\r\n\r\n` | **客户端请求模板** |
| `0x1f778` | 46 | `Sec-WebSocket-Extensions: permessage-deflate\r\n` | 101 里的扩展回显行 |
| `0x1f7a8` | 105 | `HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n%sSec-WebSocket-Accept: %s\r\n\r\n` | **101 响应模板** |
| `0x1fc40` | 65 | `A-Za-z0-9+/=` | base64 字母表（index 64 = `=`） |

**GUID 不在 `.rodata`**：`258EAFA5-E914-47DA-95CA-C5AB0DC85B11` 由 `@0x1346c` 起 5 条
`movabs` 立即数拼出（`strings` 在文件偏移 `0x1346e` 看到 `258EAFA5` 正是 `.text` 里的立即数）：

| 立即数 | 字节序 | 字符串 |
|---|---|---|
| `0x3541464145383532` | `32 35 38 45 41 46 41 35` | `258EAFA5` |
| `0x37342d343139452d` | `2d 45 39 31 34 2d 34 37` | `-E914-47` |
| `0x2d414335392d4144` | `44 41 2d 39 35 43 41 2d` | `DA-95CA-` |
| `0x3843443042413543` | `43 35 41 42 30 44 43 38` | `C5AB0DC8` |
| `0x31314235` | `35 42 31 31` | `5B11` |

---

## 2. 握手 —— 服务端

调用链：`WSConn::accept` `@0xf940` → `WSConn::recv_pat("\r\n\r\n", ...)` `@0xf180`
→ 命中后调 `FUN_00112b60 @0x12b60`（1424 行伪码，L15141–L16563），参数 2 = `"\r\n\r\n"` 起始下标。

### 2.1 解析顺序（严格按指令顺序）

| 步 | 动作 | 证据 |
|---|---|---|
| 1 | `recv_pat` 用 `memmem(buf, len, "\r\n\r\n", 4)` 等头部结束，**回调参数 = `ptr - buf`**（下标，不是长度） | L12806–L12810 `@0xf180` |
| 2 | `memmem(buf, len, "Sec-WebSocket-Key: ", 19)`，**全文扫描**，不要求行首、大小写敏感 | `@0x12b62` `lea rdx,[0x1f6a3]`、`@0x12b69` `mov ecx,0x13`、`@0x12b9a call memmem`；L15226 |
| 3 | 取 `p+19` 起、到 `\r` 或 `\n` 为止、**最多 127 字节**、并受 `len-19` 限制 | `@0x12bb9` 存字节、`@0x12bd6 cmp cl,0xd`、`@0x12bc7 cmp rdx,0x7f`；L15229–L15238 |
| 4 | 若 key 非空 → `SHA1(key‖GUID)` → base64(20B) = 28 字符 | 见 §2.2 |
| 5 | 计算完立即**跳过**请求行检查（`goto` 101 分支） | L15413 `if (0x13 < iVar31) goto LAB_001138c0`（`@0x138c0`） |
| 6 | `memmem(buf, len, "permessage-deflate", 18)` 决定是否协商压缩 | `@0x138f3 call memmem`、`@0x13904 mov BYTE [rbx+0x58],1`；L16249–L16251 |
| 7 | 从接收缓冲丢弃 `idx+4` 字节（保留其后的流水线数据） | `@0x139a4 lea ebx,[r13+0x4]`；L16287–L16294 |
| 8 | 拼 101 并排队发送 | `@0x139f6` / `@0x13a02` / `@0x13a0c` / `@0x13a1d call appendf` |

**没有任何 `Upgrade` / `Connection` / `Sec-WebSocket-Version` 校验**（全库 `.rodata` 里也没有
对应的查找串）。也就是说：只要请求里出现 `Sec-WebSocket-Key: `（且值非空），无论请求行是
`GET`、`POST` 还是垃圾，都会回 101。伪码 L15226–L15419 到 L16243–L16327 之间没有任何其它比较。

### 2.2 Accept 计算

```
accept = base64( SHA1( key_bytes ‖ "258EAFA5-E914-47DA-95CA-C5AB0DC85B11" ) )   // 28 字符
```

* `@0x13508 lea rax,[r12+rdx]`（`rdx` = `strlen(key)`）后 `@0x13512 mov [rax],rdi` 把 GUID 写在 key 尾部；
  `@0x1350c add rdx,0x24` ⇒ 消息总长 = `strlen(key) + 36`。
* SHA-1：`FUN_0010d620 @0xd620`（1430 行伪码，80 轮全展开）。
  * IV `0x67452301/0xEFCDAB89/0x98BADCFE/0x10325476/0xC3D2E1F0`：`@0x134a6`–`@0x134e4`（L15255–L15265）
  * 轮常量 `0x5A827999`（`@0xd9ac`）、`0x6ED9EBA1`（`@0xd9f1`）、`0xCA62C1D6`（L11751）
  * 结构：`h[5]@+0x00`、`bitlen(u64,BE)@+0x14`、`block[64]@+0x1c`、`fill@+0x5c`（`@0xd63c` 读 `[rdi+0x1c]`，L11758 `param_1[0x17]=0`）
  * 填充：`0x80` + 0 补齐到 56 mod 64 + 8 字节**大端位长**（L15281–L15307）
  * 即标准 FIPS 180-1，与 RFC 6455 要求一致（测试用 RFC 官方向量验证）。
* base64 用 `@0x1fc40` 表；`@0x123a3` 一组 4 字符，尾部 1 字节写 `=`、`=`（`@0x123d9`）。

### 2.3 三条分支

| 条件 | 行为 | 返回字节 |
|---|---|---|
| 有 `Sec-WebSocket-Key` 且值非空 | 101 Switching Protocols（可带 extensions 行） | 105 或 151 字节 |
| 无该头 / 值为空，且 `n>5`、`buf[0..4]=="GET /"`、`buf[5] != '/'` | 回 200 OK，并把路径交给第二个回调 | 19 字节 |
| 其它（`GET //x`、`POST`、`PUT`…） | **不产生任何字节**，把 recv 处理换成 `TcpConn::discard` | 0 字节 |

* 200 OK 分支的路径提取：`buf[5..]` 到 `' '`/`'\r'`/`'\n'`；若途中出现连续 `..`，
  整个路径被 `assign("")` 清空（`@0x12e75 lea rsi,[0x1f6d0]`，L15462）。
* 边界：`if (5 < len)` 是**严格**比较，所以 `len <= 5`（理论上只有孤立的 `\r\n\r\n`）既不回 200 OK
  也不进入 discard 分支，只是原样返回（0 字节）。正常 HTTP 请求不可能触发。
* 失败路径（第三行）证据：`@0x12d68 lea rdi,[0x1f6b7]`、`@0x12d77 repz cmps`（5 字节）、
  `@0x12d7f cmp BYTE [r8+5],0x2f`、`@0x12d79/0x12d84` 两条 `je/jne 0x12c15`；
  `0x12c15` 处 `@0x12c7c` 取 `_ZNSt14_Function_base13_Base_managerIN7TcpConn7discardEE..._M_manager`
  与 `@0x12cb9 ...N7TcpConn7discardE..._M_invoke`，即把接收回调**替换为丢弃**。
* 200 OK 分支：`@0x12d9d jle 0x12e83`（`buf[5]` 是空格/CR/LF → 空路径），
  `@0x12e8d lea rsi,[0x1f6bd]`，`@0x12eb3 call appendf`。

**失败路径返回值**：库不返回错误码——`accept()` 的失败就是"什么都不做"（0 字节）或者
"降级成 HTTP 200"。真正的协议错误处理只有一处：64 位长度越界时调 `WSConn::exit()`（见 §4.2）。

---

## 3. 握手 —— 客户端

`WSConn::connect @0x122b0`（2212 字节，L14729–L15138）。

```
GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n
Sec-WebSocket-Key: AAAAAAAAAAAAAAAAAAAAAA==\r\n
Sec-WebSocket-Extensions: permessage-deflate\r\nSec-WebSocket-Version: 13\r\n\r\n
```

* **key 是常量**：`@0x122d8 mov QWORD [rsp+0x20],0` + `@0x122e1 mov QWORD [rsp+0x28],0`
  把这 16 字节清零，随后 `@0x122b0..@0x12351` 区间内**唯一的一次 `call` 是 `@0x123fa _Znwm`**
  （无 `rand`/`time`/`gettimeofday`）。所以 key 恒为 `base64(16×0x00)` = `AAAAAAAAAAAAAAAAAAAAAA==`。
* 请求模板 `.rodata 0x1f6d8`（155 字节），`@0x14872 Buffer::appendf("%s"→key)`。

### 3.1 客户端如何消费服务器响应

`connect()` 把 **`FUN_0010fc40 @0xfc40`** 装成 TcpConn 的数据回调（`@0x125cf lea rdi,[0xfc40]`、
`@0x125e3 mov [rbx+0x80],rdi`，L14922–L14923）。这条链是：

```
0xfc40 : recv_pat("\r\n\r\n" @0x1f6cc)          // 等响应头结束（L13282-L13283, @0xfd26）
   └─ 命中回调 0xdbc0 :
        memmem(整缓冲, "permessage-deflate", 18)  // @0xdbf4 → this+0x58=1 + inflateInit2_/deflateInit2_
        丢弃 idx+4 字节                            // L11896/L11900
        调用捕获的 std::function（用户的 on-connect 回调） // L11911
```

**关键：不做任何校验。** `0xfc40` 与 `0xdbc0` 里没有对状态行、`Upgrade`、`Connection`、
`Sec-WebSocket-Accept` 的比较（`0xdbc0` 全函数唯一的字符串操作就是 `@0xdbf4` 的 memmem）。
所以服务器回 `HTTP/1.1 400 Bad Request\r\n\r\n` 或 Accept 值错误，客户端都会当成握手成功：
丢掉头部并触发 on-connect（测试 `test_client_response` 覆盖）。

---

## 4. 帧头

### 4.1 位布局（`FUN_001114a0 @0x114a0`，L14261–L14399）

| 字节 | bit | 含义 | 指令 | 伪码 |
|---|---|---|---|---|
| `b0` | 7 | **FIN** | `@0x114cd shr r13b,7` | L14292 `bVar8 = bVar1 >> 7` |
| `b0` | 6 | **RSV1** → `this+0x59 = 1`（粘性，压缩标记） | `@0x114d9 test al,0x40` / `@0x114dd mov BYTE [rdx+0x59],1` | L14296–L14299 |
| `b0` | 5 | RSV2 —— **完全忽略** | `@0x114d5 and r12d,0xf` | L14294 |
| `b0` | 4 | RSV3 —— **完全忽略** | 同上 | L14294 |
| `b0` | 3..0 | **opcode**（低 4 位） | `@0x114d5 and r12d,0xf` | L14294 `uVar7 = bVar1 & 0xf` |
| `b1` | 7 | **MASK** | `@0x114d1 shr r15b,7` | L14293 `local_70 = bVar2 >> 7` |
| `b1` | 6..0 | **payload-len 7 位** | `@0x114e6 and ebp,0x7f` | L14300 |

因为 opcode 只取 `b0 & 0x0f`，**RSV2/RSV3 从不被检查**（也不因未协商扩展而拒绝连接）。

### 4.2 长度分支

| `len7` | 需要总头长 | 后续字节 | 长度解释 | 证据 |
|---|---|---|---|---|
| `0..125` | 2 | 无 | `len7` | `@0x114fd`（memmove 掉 2） |
| `126` | 4 | `b2,b3` | **大端 16 位** `(b2<<8)|b3` | `@0x1093c movzx ecx,[r8+2]`、`@0x1094a shl ecx,8`、`@0x1094d or ecx,eax`；L13785 |
| `127` | 10 | `b2..b5` = 高 32 位，`b6..b9` = 低 32 位 | 高 32 位**必须全 0**，否则 `WSConn::exit()`；长度 = BE32，然后**按有符号 32 位**解释 | `@0x11a68..@0x11a9c`（四次 `cmp BYTE,0`，`jne 0x11a76` → `call WSConn::exit@plt`）；`@0x11a9e..` 组装；L14425–L14431、L14469 |

细节：

* `recv_more` 的等待量分别是 `2 / 4 / 10`（**累计头长**，不是增量）：
  `@0x114a0` 调 `recv_more(this,2,...)`（L13872）、`0x7e` 走 `recv_more(this,4,...)`（L14324）、
  `0x7f` 走 `recv_more(this,10,...)`（L14355）。
* **出现 64 位长度时用 `(long)(int)` 强转**（L14429–L14431），所以 `len ≥ 0x80000000` 会变成负数，
  再按 `ulong` 传给 `recv_more` ⇒ 等价于要求 ~2^64 字节，帧永远不被交付（不会崩、也不报错）。
* 头部一凑齐就 `memmove` 出缓冲：`@0x11515 add r8,rax; mov [r14+8],r8`（2 字节）、
  L13787–L13792（4 字节）、L14432–L14437（10 字节）。
* **不检查最小长度编码**：`len7=126` 携带 `0x007e` 也接受（126 就是 126）。
* **不检查掩码方向**：带 MASK 与不带 MASK 的帧都接受（服务端/客户端逻辑共用）。

---

## 5. 掩码

`WSConn::read_data_mask @0x105a0`（L13631–L13689）+ 回调 `FUN_00110d50 @0x10d50`（L13929–L14099）。

* **等待量**：`recv_more(this, payload_len + 4, ...)`（L13681 `recv_more(this,param_3 + 4,...)`）；
  非掩码路径 `WSConn::read_data @0x10760` 用 `recv_more(this, payload_len, ...)`（L13751）。
* **掩码位置**：头已被移出缓冲后，缓冲前 4 字节就是 mask key：
  `L13958 local_68[0] = *__dest`（一次 32 位读，拷贝到栈上）。
* **时机**：先把消息缓冲**零扩展** `payload_len` 字节（L14002/L13989 的 `memset` + `plVar1[1] += uVar3`），
  再**逐字节**回填，**不是整块 XOR、也不是就地解密**：

```c
msg[old + i] = recvbuf[4 + i] ^ mask[i & 3];       // L14024–L14026
```
  `old = 追加前的消息长度`（续帧时偏移正确），`i` 每帧从 0 开始 ⇒ **掩码索引每帧复位**。
* 之后 `memmove` 掉 `len+4` 字节（L14037–L14046 `__src = __dest + uVar6 + 4`）。
* 非掩码路径直接 `insert` 载荷（L14134–L14200），不做任何变换。

---

## 6. 控制帧

`FUN_00110d50` / `FUN_00111100` 的分发段完全相同（`@0x10e1b`–`@0x10e54`）：

| opcode | FIN=1 时行为 | 证据 |
|---|---|---|
| `0x1` text | 取走消息缓冲，回调 `unique_ptr<Buffer>` | `@0x10e48 cmp eax,1`、`@0x10ff0` 区段（L14068、L14223） |
| `0x8` close | 回调**空** `unique_ptr`（`[rsp+0x20]=0`） | `@0x10e51 cmp eax,8`、`@0x10e56..@0x10e73`（L14079–L14087） |
| `0x9` ping | **什么都不做**：载荷被消费，无 pong、无事件、无回调 | 两条 `cmp` 都不匹配 → `jne 0x10e98` 直接返回 |
| `0xA` pong | 同上 | 同上 |
| `0x2` binary / `0x0` cont / 其它 | 同上（静默丢弃） | 同上 |

补充（都是可断言的字节级行为）：

* **Close 帧的 code/reason 不被解析**：`close` 的 payload 会正常进入消息累积缓冲（L14024 起同一循环），
  但回调收到的是空指针，payload 从未被交给用户。
* **全库不存在 Close/Ping/Pong 帧的构造**：唯一的帧构造器是 `WSConn::send @0x14d00`，
  首字节只有 `0x81`（`@0x15249`，L16621）与 `0xC1`（`@0x14e30`，L16748）两种；
  对全 `.text` 做立即数扫描也**找不到任何** `mov BYTE PTR [...],0x88/0x89/0x8a`
  或 `,0x88/0x89/0x8a` 形式的立即数。
* `WSConn::exit @0xc110` 只做：清发送队列（`*(lVar15+0x60) = 0`，L9806–L9814）→ 登记 eventloop 回调，
  **不发 Close 帧**。
* **不校验控制帧约束**：不检查"control 帧必须 FIN=1、长度 ≤ 125"。`0x09 (FIN=0) + 1 字节载荷`
  会被当作分片的第一片（测试已覆盖）。

---

## 7. 分片

* `FIN=0` ⇒ 消费本帧载荷后**继续 `read_head()`**：`@0x10e1b cmp BYTE [rbx+0x10],0` +
  `@0x10e1f je 0x10eb0`（`0x10eb0` 处重新调 `WSConn::read_head`，L14054/L14209）。
  载荷追加进 `this+0x48`（消息缓冲），追加顺序 = 到达顺序。
* `FIN=1` ⇒ **用"最后这一帧"的 opcode 分发**（`@0x10e45 mov eax,[rbx+0x14]`，即 `read_data` 的
  lambda 里保存的 opcode，L14068 `*(int *)((long)param_1 + 0x14) == 1`）。
* ⇒ **标准文本分片 `0x01`(FIN=0) + `0x80`(FIN=1, opcode=0) 不会投递**：末帧 opcode=0，
  既不是 1 也不是 8，函数直接返回。数据仍留在消息缓冲里（下一条 `recv()` 会清掉）。
  只有"末帧 opcode=1"的非规范序列才会投递拼接结果。
* RSV1（压缩）是**连接级粘性位**：任一头带 RSV1 就置 `this+0x59=1`，只在 `WSConn::recv`
  里清零（L13910 `this[0x59] = 0`）。所以首帧带 RSV1、续帧不带，仍会对整条消息做一次解压。

### 压缩边界（permessage-deflate）

* 入方向 `FUN_0010ee80 @0xee80`：消息尾部**追加 `00 00 FF FF`**（L12643–L12653 四次
  `emplace_back(0,0,0xff,0xff)`），再 `inflate(strm, Z_NO_FLUSH=0)`（L12662），输出块 0x4000；
  `inflateInit2_(strm, -15, "1.2.7", 0x70)`（L16264）。
  错误判定：`(iVar3+4U < 7) && (bit(iVar3+4) & 0x47)` ⇒ `iVar3 ∈ {-4,-3,-2,2}`
  （`Z_MEM_ERROR/Z_DATA_ERROR/Z_STREAM_ERROR/Z_NEED_DICT`）视为失败，`return 0` ⇒ 不投递。
* 出方向：`deflate(strm, 2 /*Z_FINISH*/)`（`@0x14ddd mov esi,0x2`、`@0x14de9 call deflate`），
  随后**长度减 4**（L16686 `uVar12 = -avail_out - 4`，即去掉 `00 00 FF FF`），首字节改 `0xC1`。

---

## 8. 缓冲区（粘包 / 半包）

| 对象 | 位置 | 说明 |
|---|---|---|
| 接收缓冲 | `this+0x40`（`vector<uint8_t>`，元素是 `{begin,end}` 指针对） | 所有收到的字节先追加到这里 |
| 消息缓冲 | `this+0x48` | 分片累积；`recv()` 每次重新分配；投递时指针被取走并置 0 |
| 发送缓冲 | `this+0x50` | `send()` 组帧 |

* `WSConn::recv_more(n, cb) @0xfe70`：
  ```
  @0xfe87  rdx = this->buf
  @0xfe8b  rax = end - begin
  @0xfe92  cmp rsi, rax        ; rsi = 需要的字节数 n
  @0xfe95  jbe 0x10228         ; 已有 >= n -> 立即 invoke(cb)
  ...     否则把 "等 n 字节" 的 lambda 存进 eventloop，来数据后重跑
  ```
  `@0x10228` 处 `call QWORD PTR [rbx+0x18]`（`std::function::operator()`）。
* 数据到达 `FUN_00111f80 @0x11f80`：把新块 `insert` 到接收缓冲尾部（L14633–L14687），
  再调 `recv_pat` 重跑（L14695）。收到空 Buffer ⇒ `WSConn::exit()`（L14628–L14631）。
* **没有显式状态机**：每次数据到达都从缓冲头重新解析，"状态"就是"缓冲里够不够 n 字节"。
  所以半包时缓冲一个字节都不动；凑齐后整帧消费。
* 消费用 `memmove` 压缩（`@0x11515`、L13787、L14432、L14037、L14195），剩余字节保留 ⇒
  天然支持粘包 / 流水线（握手后紧跟的帧数据在丢弃头部时被保留，见 §2 表 step 7）。

---

## 9. 协议状态表

```
                 ┌──────────────── 客户端 ────────────────┐
  INIT ──connect()──> SEND_HTTP_REQUEST（固定 key）
                          │
                          └──> WAIT_HEADER_END (memmem "\r\n\r\n", 0xfc40)
                                   ├─ 未找到：等待更多数据
                                   └─ 找到 ─> 协商 permessage-deflate ─> DROP_HEADER ─> cb()（不校验状态码/Accept）
                                                                              └──> FRAME_HEADER

                 ┌──────────────── 服务端 ────────────────┐
  INIT ──accept()──> WAIT_HEADER_END  (memmem "\r\n\r\n")
                          │ 未找到：原地等待（数据追加后重试）
                          ├─ 找到 ─> PARSE_KEY (memmem "Sec-WebSocket-Key: ")
                          │            ├─ 有非空 key ─> SHA1+BASE64 ─> SEND_101 ─> DROP_HEADER ─> FRAME_HEADER
                          │            └─ 无/空 key  ─> CHECK_REQUEST_LINE
                          │                              ├─ "GET /x" ─> SEND_200 ─> cb(path) ─>（用户处理）
                          │                              └─ 其它     ─> DISCARD（吞掉之后所有输入）
```

帧层（两端共用）：

```
  FRAME_HEADER(需 2/4/10B)
     ├─ 不足 ────────────────> 等待（缓冲不动）
     ├─ len7=0x7f 且高 32 位≠0 ─> WSConn::exit()        [唯一的"协议错误"]
     └─ 头齐 ─> 移出头部 ─> PAYLOAD(需 len，或 len+4)
                     ├─ 不足 ─> 等待
                     └─ 齐 ─> 掩码? XOR(i&3) : 直拷 ─> 追加到 message
                                ├─ FIN=0 ─────────────> 回到 FRAME_HEADER
                                └─ FIN=1 ─> (RSV1&&协商)? inflate
                                             ├─ opcode=1 ─> 回调(message)   [消息缓冲置空]
                                             ├─ opcode=8 ─> 回调(nullptr)
                                             └─ 其它 ────> 丢弃，等待下一次 recv()
```

---

## 10. 与实现（`impl.cpp`）的对应与差异

| 语义 | 二进制 | `impl.cpp` |
|---|---|---|
| 握手 | `0xf940` + `0x12b60` | `server_handshake()` / `parse_server_handshake()` |
| 客户端响应 | `0xfc40` + `0xdbc0` | `client_handshake_response()` |
| Accept | `0xd620` + `0x12b60` 内联 | `sha1()` / `base64()` / `sec_accept()` |
| 客户端请求 | `0x122b0` | `build_client_request()` |
| 帧头 | `0x114a0` / `0x10920` / `0x11a50` | `parse_frame_header()` |
| 掩码 | `0x10d50` | `Connection::pump()` 掩码分支 |
| 分片/控制 | `0x10d50` / `0x11100` 尾部 | `Connection::pump()` 分发 |
| 缓冲 | `0xfe70` / `0x11f80` | `feed()` + `pending_active` 两段式 |

差异（**只是内部时序，不影响外部可见行为**）：二进制把"头已移除、等载荷"的状态藏在
`recv_more` 的 lambda 里；实现用 `pending` 字段表达同一状态。缓冲区中间态因此一致（头先被消费）。

---

## 11. claims 统计

* `claims.json` 共 **42** 条 confirmed + **1** 条 unknown（`unknowns` 段，U1）。
* `test.cpp` 断言 **188** 条，全部通过，末行 `all claims passed`。

```
$ g++ -std=gnu++17 -O2 -Wall -Wextra -o test.exe test.cpp
$ ./test.exe
claims: 188 passed, 0 failed
all claims passed
```

## 12. 已知缺口（unknown）

* **U1**：`WSConn::exit @0xc110` 的最终收敛点。函数尾部只把 lambda 装进 eventloop
  （`PTR__M_invoke_00324fd0`，L10042–L10061），未继续追进 `TcpConn` 的 `shutdown/close` 路径，
  因此"收到 Close 之后 TCP 何时真正 FIN"未定论。
* （原先的 U2——"客户端响应无人消费"——已在复核中解决：`connect()` 通过 `@0x125cf` 把
  `0xfc40` 装成数据回调，见 §3.1，现为 claim C03/C04。）

附注：`.rodata 0x1f634` 的前 4 字节 `80 84 2e 41` 是死填充，真正的
`permessage-deflate` 串从 `0x1f638` 开始并被 `@0x138d6`（服务端内联副本）与
`@0xdbc2`（客户端独立副本）引用。全 `.text` 的 `memmem` 针只有 3 类：
`recv_pat` 由调用者传入的针、`Sec-WebSocket-Key: `（`@0x12b62`）、
`permessage-deflate`（`@0x138d6` / `@0xdbc2`）；另外 `GET /` 用 `repz cmps` 比较（`@0x12d77`）。

---

## 13. 复现

```powershell
# 符号 / 常量
readelf.exe -sW D:\tmp\H0WS2.so
readelf.exe -x .rodata D:\tmp\H0WS2.so
objdump.exe -d --no-show-raw-insn -M intel D:\tmp\H0WS2.so > _dis.txt

# 构建与测试（工作目录 D:\tmp\semantic\H0WS\proto）
$g = (Get-ChildItem "$env:LOCALAPPDATA\Microsoft\WinGet\Packages" -Recurse -Filter g++.exe |
      Select-Object -First 1 -ExpandProperty FullName)
& $g -std=gnu++17 -O2 -Wall -Wextra -o test.exe test.cpp
.\test.exe
```

辅助脚本（可选）：`_get.py`（按 IDX/地址打印伪码块，带全局行号）、`_dis.py`（按地址范围 /
指令模式打印反汇编）、`_sym.txt`、`_dis.txt`、`_idx.txt`、`_blocks.json`。
