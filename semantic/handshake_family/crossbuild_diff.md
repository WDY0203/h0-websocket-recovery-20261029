# 跨构建 diff：py2 构建 vs py3 构建

两个 dump 是同一库的两个构建（`bbwebsocket.so` / `bbwebsocket3.so`），各 400 个函数。
本文先证明**怎么配对**，再给出**哪些逐行相同**，最后列出唯一的语义差异。

---

## 1. 配对方法

直接按 `IDX` 序号比是错的：

- dump 按地址排序，而 py2 在 `0x10fb50` 多出一个函数（`std::string::_Rep::_M_destroy` 的
  COW 析构器，py3 用 SSO 没有），从那里开始**序号整体错位 1**；
- `FUN_xxxxxx` 这类未命名函数的编号两边完全不同（py2 有 58 个、py3 有 57 个），不能按名字配。

所以采用：

1. **命名函数**：同名 + 地址最近（`py3_addr - 0x100` 作先验）。
2. **`FUN_*`**：按归一化后的**内容相似度**贪心最佳匹配（限制行数差 ≤ 40/60 行）。

### 1.1 归一化规则

比对前对每行做 4 步替换（与 `frames_family` 一致，便于横向引用）：

```
@0x<hex>                  -> @A              # 注释里的绝对地址
0x<hex>{5,}               -> 0xADDR          # 立即数形式的地址
(FUN|LAB|DAT|PTR|UNK)_<hex> -> $1_X          # 符号编号
PTR_<name>_<hex>          -> PTR_<name>      # GOT 槽
```

`0x7f`、`0x8000`、`0x11`、`0x73` 这类**语义常量不归一化** —— 它们正是要断言的。

---

## 2. 本族 18 个成员的配对结果

| id | 函数 | py3 | py2 | Δaddr | py3 行 | py2 行 | 归一化 | raw diff |
|---|---|---|---|---|---|---|---|---|
| M01 | `WSConn::connect` | 0x1123b0 | 0x1122b0 | 0x100 | 412 | 412 | **相同** | 40 |
| M02 | `FUN_0010fd40` | 0x10fd40 | 0x10fc40 | 0x100 | 65 | 65 | **相同** | 6 |
| M03 | `FUN_0010dcc0` | 0x10dcc0 | 0x10dbc0 | 0x100 | 76 | 76 | **相同** | 12 |
| M04 | `FUN_0010d720` (SHA-1) | 0x10d720 | 0x10d620 | 0x100 | 1429 | 1429 | **相同** | 2 |
| M05 | `Buffer::appendf` | 0x1159c0 | 0x1158c0 | 0x100 | 179 | 179 | **相同** | 16 |
| M06 | `TcpClient::TcpClient(host,port)` | 0x11a390 | 0x11a290 | 0x100 | 381 | 381 | **相同** | 42 |
| M07 | `TcpClient::TcpClient(fd)` | 0x118320 | 0x118220 | 0x100 | 71 | 71 | **相同** | **0** |
| M08 | `TcpConn::TcpConn` | 0x118190 | 0x118090 | 0x100 | 38 | 38 | **相同** | 4 |
| M09 | `~TcpConn` | 0x118550 | 0x118450 | 0x100 | 90 | 90 | **相同** | **0** |
| M10 | `TcpConn::recv_proc` | 0x119380 | 0x119280 | 0x100 | 758 | 758 | **相同** | 78 |
| M11 | `TcpConn::send_proc` | 0x11ad10 | 0x11ac10 | 0x100 | 680 | 680 | **相同** | 60 |
| M12 | `TcpClient::poll` | 0x11c000 | 0x11bf00 | 0x100 | 436 | 436 | **相同** | 20 |
| M13 | `TcpServer::poll` | 0x11baf0 | 0x11b9f0 | 0x100 | 210 | 210 | **相同** | 22 |
| M14 | `WSConn::exit` | 0x10c210 | 0x10c110 | 0x100 | 569 | 569 | **相同** | 60 |
| M15 | `~WSConn` | 0x10ee70 | 0x10ed70 | 0x100 | 49 | 49 | **相同** | **0** |
| M16 | `EventLoop2::run` | 0x116de0 | 0x116ce0 | 0x100 | 323 | 323 | **相同** | 30 |
| M17 | `FUN_0010a780` (connect) | 0x10a780 | 0x10a6b0 | **0xd0** | 216 | 210 | **不同** | 52 |
| M18 | `FUN_00109f70` (disconnect) | 0x109f70 | 0x109ea0 | **0xd0** | 361 | 361 | **相同** | 40 |

- **17 / 18 逐行相同**；`raw diff` 列剩下的全是"符号编号被重新分配"的行（例如
  `local_48 = FUN_0010e2d0` ↔ `FUN_0010e1d0`），归一化后归零。
- **M07 / M09 / M15 的 raw diff = 0**：它们不引用任何被重新编号的符号，40/83/42 行
  逐字节一致。
- **地址平移不是恒定 0x100**：M01–M16 是 0x100；M17/M18 在 Python 绑定区，是 **0xd0**。
  原因是这两个函数本身在 py2 里短了 0x30 字节（`PyString_*` 分支比 `PyUnicode/PyBytes`
  分支少一次类型判断），其后的函数整体上移。
- **行数完全相同**也是证据：17 个成员两边的伪代码行数逐一相等（M17 除外：216 vs 210）。

---

## 3. 唯一差异：M17（`connect(addr,port)` 的参数提取）

py3 侧（`FUN_0010a780`，L8048–L8263）：

```c
uVar8 = PyLong_AsLong(local_258[0]);                  // port
if ((*(byte *)(*(long *)(local_268[0] + 8) + 0xab) & 8) == 0) {   // 非 bytes 子类
    pcVar9 = (char *)PyUnicode_AsUTF8();              // str -> UTF-8
    std::string::string((string *)local_248, pcVar9, ...);
} else {
    uVar12 = PyBytes_Size();
    pcVar9 = (char *)PyBytes_AsString(local_268[0]);
    std::string::string((string *)local_248, pcVar9, uVar12, ...);
}
```

py2 侧（`FUN_0010a6b0`）：

```c
uVar8 = PyLong_AsLong(local_258[0]);
uVar9 = PyString_Size(local_268[0]);
pcVar10 = (char *)PyString_AsString(local_268[0]);
std::string::string((string *)local_248, pcVar10, uVar9, ...);
```

差异只有两点，**都在解释器适配层**：

1. py2 只有一种字符串类型，直接 `PyString_Size` + `PyString_AsString`；
2. py3 要先判断是不是 bytes 子类（`ob_type` 的 tp_flags 字节 `+0xab` 的 `0x08` 位），
   再决定走 `PyUnicode_AsUTF8`（无长度，`strlen`）还是 `PyBytes_Size/AsString`（带长度）。

**对协议语义无影响**：两条分支最终都构造同一个 `std::string` 地址串。
其余 38 行差异是局部变量重命名（`pUVar10`→`pUVar11`、`uVar11`→`uVar12`）与
`(string *)` 强转的显式/隐式写法，属于反编译噪声。

该差异已记入 `OUTLIERS.md` O1，并在 `test.cpp` 里以
`str_arg_kind()` 的两条断言（unicode / bytes）正面覆盖。

---

## 4. 全库视角（引用 + 本族独立重算）

`frames_family` 对全库 400 函数做过配对：**389 对，385 对归一化相同**，
4 个非相同项全部落在 Python 绑定层与 libstdc++ ABI 层（`PyString_*`→`PyBytes_*`、
`Py_InitModule4_64`→`PyModule_Create2`、新增 `PyUnicode_AsUTF8`、py2 独有的 COW 析构器）。

本文独立重算了本族 18 个成员（不依赖上述结论），得到一致的图景：
**协议逻辑零差异，差异只在绑定层**。因此"以 py3 为准"对本族无损。

---

## 5. 一个必须记录的结构性发现：dump 的低地址段是 PLT 槽位列表

`D:\tmp\H0WS3_all_decompiled.txt` 的 `IDX 0–~145` 段，地址是 `.plt` 槽位
（`0x106ed8` 起，步长 0x10），但其中**本地定义函数**（`recv_pat`、`send`、`connect`、
`exit`、`run`…）打印的却是**真实函数体**。证据：

```
IDX 2  00106f10 recv_pat   348 行     <- 真实函数体，但地址是 PLT 槽
IDX 3  00106f20 append      12 行     <- PLT 桩
```

`0x106f10` 与 `0x106f20` 只差 0x10 字节，不可能容纳 348 行函数 —— 说明该段的
**地址元数据是 PLT 槽**，函数体来自符号表里的真实定义（真实地址见高地址副本
`0x10f280`）。因此：

- 本族所有 claim 一律使用**高地址副本**（`0x10a780` 以上）的地址与行号；
- 低地址段里体量较大的块，按"同一函数的第二次反编译"记为 `alias`（局部变量命名风格
  不同，例如 `pWStack_98` vs `local_98`），`buckets.tsv` 里逐条标注了它对应的目标。

这不是 py2/py3 差异，是两个 dump 共同的结构特征；记录在此以免后人误用其地址。
