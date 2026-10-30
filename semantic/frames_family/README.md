# H0WS 帧族（HTTP/WebSocket 帧处理）语义重建 · L2 表驱动套件

目标：`bbwebsocket` 1.2.7 的 **握手 + 帧头 + 掩码 + 分片 + close 码** 这一族。
方法：**静态语义重建**。只读分析，不运行原始二进制，不联网。
两个 dump 是同一库的 Python2 / Python3 构建 —— 本文先把它们做**结构化 diff**，再据以产出表驱动套件。

> 覆盖数：**成员 15 / 函数 16 / 入表 93 条断言 / 例外 6 条 / claims 45 条（inferred 4 条 = 8.9%）**

---

## 0. 一句话结论

**帧层在 py2 与 py3 两个构建里逐语句完全相同**（16/16 函数归一化后零残留差异，仅绝对地址整体 +0x100）。
真正的 py2/py3 差异只出现在 **Python C-API 绑定函数**里（`PyString_*`→`PyBytes_*`、`Py_InitModule4_64`→`PyModule_Create2`、新增 `PyUnicode_AsUTF8`），外加 1 个 py2 独有的老 ABI `std::string` COW 析构器。
所以"以 py3 为准、py2 差异入表"的结果是：**帧族成员表里 py2 一栏与 py3 完全相同，唯一的差异项是 0 条语义差异 + 1 条构建级例外（O1）**。

---

## 1. 方法与证据

| 项 | 说明 |
|---|---|
| 主源 | `D:\tmp\H0WS3_all_decompiled.txt`（400 函数，25923 行） |
| 对照 | `D:\tmp\H0WS2_all_decompiled.txt`（400 函数，25932 行） |
| 切分 | 按 `^===== IDX <n> <addr> <name> =====` 切成 400 个块，`blocks\p{2,3}_NNN.c` |
| 行号约定 | `L<n>` = **py3 dump 的 1-based 绝对行号**（`ranges_py3.csv` 给出每块的行区间） |
| 地址约定 | `0x…` = py3 的虚拟地址；py2 同函数地址 = py3 − 0x100（见 §3.3） |
| 伪代码优先 | 与前序 `semantic/proto/README.md` 冲突处，以伪代码为准；冲突已记入 `OUTLIERS.md` |

### 1.1 归一化规则（用于跨构建比对）

比对前对每一行做 4 步替换，目的只是抹掉"同一个东西换了个编号"：

```
@0x<hex>            -> @A          # 注释里的绝对地址
0x<hex>{5,}         -> 0xADDR      # 立即数形式的地址（>0xFFFF）
(FUN|LAB|DAT|PTR|…)_<hex> -> $1_X  # 符号编号
PTR_<name> / DAT_<name>   -> PTR_SYM / DAT_SYM   # GOT 槽名（py3 因 PLT 变长而 +8）
```

**小型立即数（`0x7f`、`0x4000`、`0xf`、`0x47`）一律不归一化** —— 它们是语义常量，正是要断言的东西。

---

## 2. 选族：为什么是这 16 个函数

从地址 0x10f280–0x114e00 这一段连续取"帧处理链"，加上握手入口：

```
accept ──recv_pat("\r\n\r\n")──> [key_parse: 抽 key / SHA1+BASE64 / 101|200|discard]

recv() ─> read_head ─> hdr_parse ─┬─ len7=0x7e ─> len16 ─┐
                                  ├─ len7=0x7f ─> len64 ─┤
                                  └─ 其它 ────────────────┤
                                                          v
                            mask? ─> read_data_mask(len+4) ─> payload_mask ─┐
                                    read_data(len)          ─> payload_plain ┤
                                                                             v
                                              FIN=0 -> read_head
                                              FIN=1 -> finalize(inflate) -> opcode 1/8/其它
on_data：有新字节就塞进 recvbuf，重新跑一遍
send：0x81/0xC1 + 1/3/10 字节长度 + 载荷
```

`members.tsv` 是机器可读版本；下表是摘要（含 py2 地址，可见只差 0x100）：

| id | 函数 | py3 | py2 | 行数 | 归一化后 |
|---|---|---|---|---|---|
| M01 | `WSConn::recv_pat` | 0x10f280 | 0x10f180 | 348 | 相同 |
| M02 | `WSConn::recv_more` | 0x10ff70 | 0x10fe70 | 311 | 相同 |
| M03 | `WSConn::read_head` | 0x110bd0 | 0x110ad0 | 56 | 相同 |
| M04 | `FUN_001115a0` hdr_parse | 0x1115a0 | 0x1114a0 | 143 | 相同 |
| M05 | `FUN_00110a20` len16 | 0x110a20 | 0x110920 | 61 | 相同 |
| M06 | `FUN_00111b50` len64 | 0x111b50 | 0x111a50 | 71 | 相同 |
| M07 | `WSConn::read_data` | 0x110860 | 0x110760 | 68 | 相同 |
| M08 | `WSConn::read_data_mask` | 0x1106a0 | 0x1105a0 | 67 | 相同 |
| M09 | `FUN_00110e50` payload_mask | 0x110e50 | 0x110d50 | 175 | 相同 |
| M10 | `FUN_00111200` payload_plain | 0x111200 | 0x111100 | 153 | 相同 |
| M11 | `FUN_0010ef80` finalize | 0x10ef80 | 0x10ee80 | 137 | 相同 |
| M12 | `WSConn::recv` | 0x110d60 | 0x110c60 | 40 | 相同 |
| M13 | `WSConn::send` | 0x114e00 | 0x114d00 | 477 | 相同 |
| M14 | `WSConn::accept` + `FUN_00112c60` | 0x10fa40 / 0x112c60 | 0x10f940 / 0x112b60 | 107 / 1423 | 相同 |
| M15 | `FUN_00111f80` on_data | 0x112080 | 0x111f80 | 122 | 相同 |

合计 **3759 行** py3 伪代码。

---

## 3. 跨构建 diff（核心章节）

### 3.1 配对方法

按 `IDX` 序号直接比是错的：dump 按地址排序，而 py3 的 PLT/GOT 多出几条，导致**从 idx 5 开始整体错位**（`PyString_AsString` ↔ `memset` …）。
所以按下列顺序配对：

1. **命名函数**：`符号名 # 第几次出现`。注意同名多份（`assign`、`string`、`_M_erase`、`exit`…），必须带序号。
2. **未命名 `FUN_xxxx`**：py2 有 58 个、py3 有 57 个，按**内容相似度贪心最佳匹配**（不用序号，因为序号也会错位）。

### 3.2 结果

| 组 | 对数 | 归一化后相同 | 说明 |
|---|---|---|---|
| 命名函数 | 332 | **332 / 332** | 零残留差异 |
| `FUN_*` | 57（py2 侧共 58 个） | 53 / 57 | 3 个只差 Python C-API 调用；1 个无 py3 对应（`FUN_0010fb50`） |
| 合计 | 389 | 385 / 389 | 4 个非相同项全部集中在绑定层 / C++ 运行时 |

### 3.3 差异清单（全库，按类别）

**A 类 · 纯地址平移（不是差异）**
主 `.text` 区所有函数统一 **+0x100**；PLT 桩区 +0x80…+0xd8。
函数体行数**逐一相同**（帧族 16/16 完全同长）。`PTR_*_0032xxxx` 这类 GOT 槽地址 +8（多了一条 PLT）。

**B 类 · Python C-API 重命名（同一角色）**

| py2 | py3 |
|---|---|
| `PyString_AsString` | `PyBytes_AsString` |
| `PyString_FromStringAndSize` | `PyBytes_FromStringAndSize` |
| `PyString_Size` | `PyBytes_Size` |
| `Py_InitModule4_64` + `initbbwebsocket` | `PyModule_Create2` + `PyInit_bbwebsocket3` |
| — | `PyUnicode_AsUTF8`（py3 新增） |

这些只出现在**绑定层**（3 个 `FUN_*` + 若干 init 函数），例如：
`PyString_FromStringAndSize(...)` ↔ `PyBytes_FromStringAndSize(...)`（p2 idx 168 / p3 idx 169，2 行差异，全是这一处改名）。

**C 类 · libstdc++ ABI（真实差异，与帧无关）**
py2 用 COW `std::string`（`std::string::_Rep`、`PTR__S_empty_rep_storage`），因此多出 `FUN_0010fb50`：

```c
LOCK(); iVar1 = *param_3; *param_3 = *param_3 + -1; UNLOCK();
if (iVar1 < 1) std::string::_Rep::_M_destroy(param_1);
```

py3 用 SSO，没有这个函数。**全库唯一一个"py2 独有且不是 API 改名"的函数**。详见 `OUTLIERS.md` O1。

**D 类 · 帧语义差异：0 条。**

### 3.4 对"帧族"的直接结论

- 16 个函数、3759 行，**归一化后逐行相同**；raw diff 只剩 0–148 行不等的符号编号差（例如 `read_head` 里 `local_50 = FUN_001114a0` ↔ `FUN_001115a0`，正好 4 行 = 2 处引用 × 两侧）。
- `WSConn::recv` 是唯一 **raw diff = 0** 的函数（40 行逐字节一致，因为它不引用任何被重编号的符号）。
- 因此"以 py3 为准"不会丢掉任何 py2 信息；`members.tsv` 里 `addr_delta` 一列全是 `0x100`，即为证。

---

## 4. 帧语义总览（据伪代码确定）

### 4.1 帧头位布局（M04，`L14055-L14065`）

| 位 | 含义 | 源码 |
|---|---|---|
| `b0>>7` | FIN | `bVar8 = bVar1 >> 7` |
| `b0 & 0x40` | RSV1 → `this+0x59 = 1`（**粘性**，在长度分派之前就写入） | `if ((bVar1 & 0x40) != 0)` |
| `b0 & 0x20/0x10` | RSV2 / RSV3 —— **完全不检查** | 无相应指令 |
| `b0 & 0x0f` | opcode | `uVar7 = bVar1 & 0xf`（保留值 3–7、11–15 也放行） |
| `b1>>7` | MASK | `local_70 = bVar2 >> 7` |
| `b1 & 0x7f` | 长度选择子 | `bVar6 = bVar2 & 0x7f` |

### 4.2 长度三路（M05 / M06）

| len7 | 总头长 | 解释 | 备注 |
|---|---|---|---|
| 0–125 | 2 | 原值 | |
| 126 | 4 | **大端 16 位** `b2<<8\|b3` | 不检查最小编码：`0x007e` 携带值 5 也接受 |
| 127 | 10 | 高 32 位 `b2..b5` **必须全 0**，否则 `WSConn::exit()`；长度 = BE32，再 `(long)(int)` | `≥0x80000000` 变负数 → 永远等不满 → 丢帧不报错 |

### 4.3 掩码（M09，`L13791-L13793`）

```c
msg[old + i] = recvbuf[4 + i] ^ mask[i & 3];   // i 每帧从 0 重新开始
```
- 掩码键就是帧头被 memmove 掉之后的缓冲前 4 字节（一次 32 位读入栈）。
- 先对消息缓冲**零扩展** `payload_len` 再回填，`old` = 追加前长度 ⇒ 续帧偏移正确。
- 服务端不检查掩码方向：带 MASK 和不带 MASK 都收。

### 4.4 分片与控制帧（M10/M11）

- `FIN=0` ⇒ 消费本帧载荷后**回到 read_head**；消息缓冲按到达顺序累加。
- `FIN=1` ⇒ **用"最后一帧"的 opcode 分派**：

| 末帧 opcode | 行为 |
|---|---|
| 1 text | 取走消息缓冲，回调 `unique_ptr<Buffer>` |
| 8 close | 回调 **null**；payload（含 close code 1000 等）**从未解析** |
| 9 ping | 什么都不做：无 pong、无事件；**并且本轮解析就此停止** |
| 10 pong / 2 binary / 0 cont / 其它 | 静默丢弃 |

- ⇒ **标准文本分片 `0x01`+`0x80` 永不投递**（末帧 opcode=0）；只有"末帧重复 opcode 1"的非规范序列才会投递。
- ⇒ 全库不存在 Close/Ping/Pong 帧构造器：`send` 首字节只有 `0x81`、`0xC1`。

### 4.5 压缩门（M11）

```
if (compressed) {
  msg += 00 00 FF FF ;                       // permessage-deflate 尾巴
  rc = inflate(strm, Z_NO_FLUSH=0);
  if ((rc+4U < 7) && (1<<((rc+4)&0x3f) & 0x47)) return 0;   // {-4,-3,-2,2}
  msg = out;
}
return 1;
```
`compressed = (this+0x58 != 0) ? this+0x59 : 0` —— 必须**协商过**且**本消息带过 RSV1**（任一分片带过即算）。

### 4.6 发送（M13，`L16379`–`L16567`）

```
b0 = 0x81 (明文) | 0xC1 (deflate 且已截掉 4 字节尾巴)
n = payload_len
n <= 125           -> b0, n
126 <= n <= 65534  -> b0, 0x7e, n>>8, n
n >= 65535         -> b0, 0x7f, 00 00 00 00, n>>24, n>>16, n>>8, n
再拼载荷
```
**MASK 位永远是 0** —— 客户端不发掩码帧，违反 RFC 6455 §5.3。

### 4.7 握手（M14）

```
accept = base64( SHA1( key ‖ "258EAFA5-E914-47DA-95CA-C5AB0DC85B11" ) )   // 恒 28 字符
key    = "Sec-WebSocket-Key: " 之后、到 CR/LF 为止、最多 127 字节（原样使用，不解 base64）
101    = "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n"
       + (协商成功 ? "Sec-WebSocket-Extensions: permessage-deflate\r\n" : "")
       + "Sec-WebSocket-Accept: " + accept + "\r\n\r\n"
```
- **不校验** Upgrade / Connection / Sec-WebSocket-Version / 请求方法 —— 只要有非空 key 就 101。
- 无 key 时：`len>5` 且前 5 字节 `"GET /"` 且 `buf[5] != '/'` ⇒ 回 19 字节 `HTTP/1.0 200 OK\r\n\r\n`，路径交给第二个回调；路径里出现**相邻两个 `'.'`** 就把整条路径清空。
- 其它（`GET //x`、`POST`…）⇒ 0 字节，并把接收回调换成 `TcpConn::discard`。

---

## 5. 套件结构

| 文件 | 内容 |
|---|---|
| `members.tsv` | 16 行 = 15 成员 / 16 函数；py2+py3 地址、行数、归一化结论、角色 |
| `table.json` | 10 张表（T1–T10）+ 成员表 + 覆盖计数，机器可读 |
| `impl.h` / `impl.cpp` | 逐语句转写：帧状态机、SHA-1、base64、RFC1951 inflate、握手 |
| `test.cpp` | 表驱动驱动：读表 → 逐行断言 → 覆盖自检 |
| `claims.json` | 45 条 claim，带 `addr` + `L` 行号 + 状态 + 对应测试 id |
| `OUTLIERS.md` | 6 条例外 + 建模偏差表 |
| `ranges_py3.csv` / `ranges_py2.csv` | 每个 IDX 块在 dump 里的行区间（复核 `L<n>` 用） |

**关键约束**：`impl.cpp` 不是"重写一个 WebSocket 库"，而是把伪代码**逐分支照抄**。凡是原实现怪异的地方（ping 吃掉一轮解析、末帧 opcode 分派、65535 用 10 字节头、不发掩码）都**保留**，并在测试里正面断言 —— 这样测试才有鉴别力。

---

## 6. 覆盖统计

```
members           : 15
functions         : 16
assertions        : 93
per-member        : M01=5 M02=6 M03=3 M04=10 M05=6 M06=9 M07=2 M08=2
                    M09=11 M10=4 M11=4 M12=6 M13=10 M14=12 M15=2
claims            : 45  (confirmed 41 / inferred 4 = 8.9%)
exceptions        : 6   (OUTLIERS.md O1..O6)
```

每个成员 ≥2 条断言由 `test.cpp` 在运行期**自检**（`C01`），不满足直接失败。

| 表 | 成员 | 行数 | 断言 |
|---|---|---|---|
| T1 帧头位布局 | M04 | 9 | 9 |
| T2 16 位长度 | M05 | 5 | 5 |
| T3 64 位长度 + 高位守卫 | M06 | 6 | 6 |
| T4 模式扫描 | M01 | 5 | 5 |
| T5 need-N 门 | M02 | 6 | 6 |
| T6 掩码 | M09 | 5 | 10（双向） |
| T7 组帧 | M13 | 7 | 10 |
| T8 握手 | M14 | 8 | 12 |
| T9 端到端驱动 | M03/M07–M12/M15 | 25 | 25 |
| T10 recv 标志位 | M12 | 4 | 4 |

---

## 7. 手算样例（期望值怎么来的）

**(a) `D02` RFC 6455 §5.7 的掩码帧**
```
81 85 37 fa 21 3d 7f 9f 4d 51 58
b0=0x81 -> FIN=1 opcode=1 ; b1=0x85 -> MASK=1 len7=5
mask = 37 fa 21 3d
0x7f^0x37=0x48 'H' | 0x9f^0xfa=0x65 'e' | 0x4d^0x21=0x6c 'l'
0x51^0x3d=0x6c 'l' | 0x58^0x37=0x6f 'o'   -> "Hello"
```

**(b) `D22` 掩码索引每帧复位**
第 1 帧 3 字节、mask=`11 22 33 44`：`"Hel"` → `59 47 5f`。
第 2 帧 2 字节、**同一** mask：若索引连续应从 `mask[3]=0x44` 起，则 `0x6c^0x44=0x28`；
实际持 `0x6c^0x11=0x7d`、`0x6f^0x22=0x4d` ⇒ 证明 `i` 从 0 重新开始。

**(c) `S06` 长度边界** `n=65535=0xffff` 不满足 `< 0xffff`，走 64 位分支：
`81 | 7f | 00 00 00 00 | 00 00 ff ff` = 10 字节（`n>>24=0, n>>16=0, n>>8=0xff, n=0xff`）。

**(d) 101 响应长度**
`34 (状态行) + 20 (Upgrade) + 21 (Connection) + 22 ("Sec-WebSocket-Accept: ") + 28 (accept) + 4` = **129**；
带扩展行再加 `46` = **175**。与 `A01/A02` 一致（与 key 内容无关，accept 恒 28 字符）。

**(e) `E04` 64 位长度 `0x80000000`**
`decode_len64` 得 `(int32)0x80000000 = -2147483648`；`recv_more` 拿 `(uint64)(-2^31)=0xFFFFFFFF80000000` 去比缓冲长度 ⇒ 恒假 ⇒ 永远等待，不 exit、不投递（`D07` + `G05`）。

---

## 8. 复现

```bash
g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

实际输出（末 5 行）：

```
members           : 15
assertions        : 93
failed            : 0
-----------------------------------------------------------
all claims passed
```

完整输出：

```
H0WS frame family -- table-driven conformance suite
(static re-derivation; original binary not executed)

T1  frame header bit layout        (M04)                                       9 checks
T2  16-bit extended length         (M05)                                       5 checks
T3  64-bit extended length + guard (M06)                                       6 checks
T4  pattern scan                   (M01)                                       5 checks
T5  need-N-bytes gate             (M02)                                        6 checks
T6  payload masking                (M09)                                      10 checks
T7  frame construction             (M13)                                      10 checks
T8  server handshake               (M14)                                      12 checks
T9  end-to-end frame driver  (M03/M04/M05/M06/M07/M08/M09/M10/M11/M12/M15)    25 checks
T10 recv() flag handling           (M12)                                       4 checks

-----------------------------------------------------------
per-member assertion counts:
  M01=5 M02=6 M03=3 M04=10 M05=6 M06=9 M07=2 M08=2
  M09=11 M10=4 M11=4 M12=6 M13=10 M14=12 M15=2
members           : 15
assertions        : 93
failed            : 0
-----------------------------------------------------------
all claims passed
```

---

## 9. 局限

1. **压缩路径的字节精确值不主张**。固定命令行不能 `-lz`，`impl.cpp` 用合法但朴素的 stored-block DEFLATE；只断言 `b0==0xC1`、MASK 位、以及自洽性。原实现用真 zlib，输出随版本变化。见 `OUTLIERS.md` O4。
2. **`deflate()` 的 flush 参数无法从伪代码判定**（反编译器丢了实参）。前序文档说 `Z_FINISH`，但 `Z_FINISH` 输出不带 `00 00 FF FF`，与随后"减 4"矛盾 —— 未下结论。
3. **事件循环时序未建模**。原库用 `recv_more` 续延 + epoll 驱动；本套件把它压成同步 `pump()`，只保证"每轮最多投递 1 条消息"这一可观测契约。
4. **未覆盖**：`WSConn::connect`（客户端握手，512 行）、`recv_proc`/`send_proc`（TcpConn 层）、`EventLoop2`。它们与帧族相邻但属于另一族。
5. 4 条 `inferred` claim（`F15/F21/F29/F45`）是**解释性**结论（如"null unique_ptr 表示已关闭"、"0x58 表示已协商压缩"），已在 `claims.json` 里写明 `inference_basis`。

---

## 10. 与既有 `semantic/proto`（42 条 claim）的关系

本次 45 条与新套件**不重复覆盖**同一组断言，而是把协议层结论落实成可执行表格。两处需要读者注意：

- `proto/README §2.3` 说 101 响应"105 或 151 字节"。**105 是 `.rodata` 里的模板长度**（含两个 `%s` 占位符），实际响应是 **129 / 175** 字节（本文 §7(d) 已核算）。
- `proto/README §7` 的 `deflate(strm, Z_FINISH)` 与"减 4"存在矛盾，本文按 `OUTLIERS.md` O4 处理为**未决**，未写入 claim。
