# OUTLIERS — H0WS frames family

本文件记录 **6 条例外**：语义上不能/不应进入表驱动套件的东西，或套件特意保留的怪异行为。

编号 `O1..O6` 与 `table.json → meta.exceptions = 6` 对应。

---

## O1 · `FUN_0010fb50` 只存在于 py2 构建（libstdc++ ABI）

**现象**：跨构建按 `名字#序号` 配对后，帧族附近有且只有这一个函数在 py3 里找不到对应体。

**它是什么**：不是帧逻辑，是 **老 ABI 的写时复制 `std::string` 引用计数析构器**：

```c
LOCK(); iVar1 = *param_3; *param_3 = *param_3 + -1; UNLOCK();
if (iVar1 < 1) std::string::_Rep::_M_destroy(param_1);
```

`_Rep` / `PTR__S_empty_rep_storage` 是 gcc 5 之前 `std::string` 的 COW 实现；py3 构建用的是 SSO（`_M_dispose`/`_M_destroy` 直接内联，无独立 `_Rep` 对象）。

**处理**：不入表。它没有任何帧语义，属于 C++ 运行时差异。这是**唯一**一条 py2 独有、且不是 Python C-API 改名造成的差异。

---

## O2 · 带掩码 + 负 64 位长度的帧 = 原实现的内存安全问题，未纳入

`read_data_mask` 要求 `payload_len + 4` 字节（`L13453`）。长度来自 `(long)(int)` 符号扩展（`L14193`），所以 64 位长度 `0xFFFFFFFF` 得到 `-1`，`-1 + 4 = 3`。

于是 `recv_more(3)` 会**通过**（`3 <= buffered`），随后 `FUN_00110e50` 的循环上界是 `uVar3 = (ulong)(-1) = 2^64-1`：

```c
// L13791-L13793
msg[old + i] = recvbuf[4 + i] ^ mask[i & 3];   // i 上界 2^64-1
```

即**堆溢出写**，不是可观测的"协议行为"。

**处理**：`Conn::ub_guard` 标志位保留该分支但立即返回；测试里没有构造这种输入。它和 `len64 = 0x80000000`（`D07`，只等待、不写）是两回事 —— 后者是安全的、已入表。

---

## O3 · `send()` 是"替换"发送缓冲，不是"追加"

`WSConn::send` 一进来就：

```c
puVar10 = operator_new(0x18); *puVar10=0; puVar10[1]=0; puVar10[2]=0;
puVar3 = *(this + 0x50); *(this + 0x50) = puVar10;   // L16367-L16372
```

即**丢弃上一帧**再去组新帧。若在上一个 `send()` 被 socket 排空之前再调一次，先前的帧会无声消失（`this+0x50` 指针被覆盖）。

这与"表驱动单帧断言"无关，且需要运行时/事件循环才能观察，故不入表 —— 但它是 `send` 语义的一部分，记录在此。

---

## O4 · 压缩路径的**字节精确值**不主张（zlib 版本相关）

`send` 的 deflate 分支：组帧前把 deflate 输出**截掉 4 字节**（`L16445`：`uVar12 = -(ulong)avail_out - 4`），对应 permessage-deflate 的 `00 00 FF FF` 约定。

两个未决点：

1. 前序 `proto/README §7` 报告 `deflate(strm, 2 /*Z_FINISH*/)`。但 **Z_FINISH 的输出以 BFINAL=1 的块结尾，本身不带 `00 00 FF FF`**，无条件减 4 会截掉真实数据。要么反汇编读寄存器 `esi` 的结论有误，要么这确实是个 bug。
   伪代码里 `deflate()` 的参数被反编译器丢掉了（`L16439` 只有 `iVar8 = deflate();`），**本轮无法从伪代码判定**，因此不下结论。
2. 即便 flush 模式正确，zlib 的具体输出字节也随版本/压缩级别变化。

**处理**：`impl.cpp` 的 deflate 用合法的 **stored block**（BFINAL=0）+ 5 字节 sync-flush 尾巴再减 4，只主张结构性事实：
`b0 == 0xC1`、MASK 位为 0、以及"我们的 finalize 能接受我们自己发出的帧"。
**不主张**"与原 zlib 逐字节相同"。测试 `S09/S10` 只断言前两条。

---

## O5 · 长度 65535 走 10 字节头（合法但非最小编码）

```c
if (0x7d < uVar12) {          // L16520
  if (uVar12 < 0xffff) { 0x7e ... }   // L16522
  else { 0x7f + 4×0x00 + BE32 }
}
```

边界是**严格小于**：`126..65534` 用 16 位，`>= 65535` 用 64 位。所以长度正好 65535 时发出 10 字节头（`S06` 断言 `81 7f 00 00 00 00 00 00 ff ff`），而 RFC 6455 允许 16 位表示到 65535。

**处理**：入表（`S06`），但"这个 `<` 是不是作者手滑写成 `<=`"列为 **inferred**（claims `F28`），不作为已证事实。

---

## O6 · 任何 FIN=1 帧之后解析器就停下（流水线帧要等下一次 `recv()`）

`FUN_00110e50` / `FUN_00111200` 在 FIN=1 分支派发完就 `return`；`read_head` 只在 FIN=0 分支被重新调用（`L13814-L13822`）。所以同一批字节里跟在后面的帧**不会被立刻解析**，要等用户回调里再调 `recv()`。

这看起来像 bug，但它是原库的真实时序，**必须保留**否则 `D23`（pipelined-frames-one-per-recv）会失败。同类还有 `D12`：一个 ping 帧（opcode 9，FIN=1）会"吃掉"本轮解析，后面的文本帧留在缓冲里。

**处理**：入表并显式断言（`D12`、`D23`），不是例外而是特性 —— 记在这里是因为"顺手修好它"是最容易犯的重建错误。

---

## 附：`impl.cpp` 相对原实现的**已知建模偏差**（均为故意，不影响断言）

| 偏差 | 原因 | 影响 |
|---|---|---|
| `Conn::msg` 用 `std::vector` 清空代替 `this+0x48 = 0` | 原实现置空后在 `recv()` 之前再喂数据会解引用空指针（UB） | 无断言覆盖该 UB |
| `Conn::exited` 布尔代替 `WSConn::exit()` 的副作用 | `exit()` 还会清发送队列、登记 eventloop 回调，这些超出帧族 | 只断言"是否 exit" |
| `pump()` 同步循环代替 `recv_more` 续延链 | 原库靠 eventloop 回调续跑 | 可观测行为一致：每轮最多投递 1 条消息 |
| deflate 用 stored block（见 O4） | 固定命令行 `g++ ... test.cpp impl.cpp` 不能 `-lz` | 只主张结构性事实 |
