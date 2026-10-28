# 核实指引（给 Codex / 独立复核者）

## 0. 这是什么

对两个 Linux x86-64 共享库（`bbwebsocket.so`、`bbwebsocket3.so`）的**只读静态重建**。
原始二进制从未执行，重建代码也从未运行。请只做静态核实。

重建方式：Ghidra headless 导出伪代码 → 机械转成可编译 C++ → 4 条修复 lane 消除类型层错误。
伪代码本体逐句保留，只做机械化重写（类型转换、未声明标识符补齐、不透明结构改为字节偏移访问）。

## 1. 构建

```bash
cd reconstructed_cpp/H0WS2
g++ -std=gnu++17 -fsyntax-only -I . H0WS2_tu/part_0001.cpp
g++ -std=gnu++17 -fsyntax-only -I . H0WS2_tu/part_0002.cpp
g++ -std=gnu++17 -fsyntax-only -I . H0WS2_tu/part_0003_fixes.cpp
```

H0WS3 同理。四个 TU（两库各 3 个）都应为 **0 error**。

注意：重建代码引用大量 libc / zlib 符号，没有可链接的 `main`，**不要期望链接成功**。

## 2. 要复算的数字

| 项 | 期望 |
|---|---|
| `grep -c "^===== IDX" H0WS2_all_decompiled.txt` | 400 |
| `grep -c "^===== IDX" H0WS3_all_decompiled.txt` | 400 |
| 唯一函数名（两库各自） | 215 |
| 两库共享的唯一函数名 | 152 |
| 严格语法通过 | 400 / 400（两库） |
| 两库语法失败函数 | 各 113，失败模式 110 种完全相同 |

## 3. 保真性检查（重点）

建议抽查下列函数，确认控制流、偏移、常量与伪代码一致：

| 函数 | WS2 地址 | 为什么看 |
|---|---|---|
| 帧头解析 | `0x114a0` | FIN/RSV/opcode/MASK/长度位布局 |
| 掩码解码 | `0x105a0` 附近（`read_data_mask`） | XOR 时机与索引复位 |
| 服务端握手 | `0xf940` → `0x12b60` | `Sec-WebSocket-Key` 提取与 101 响应 |
| SHA-1 | `0xd620` | 标准 FIPS180-1 四轮 |
| 客户端连接 | `0xfc40` / `0xdbc0` | 不校验服务器响应 |
| 帧发送 | `0x14d00` | 首字节只有 `0x81`/`0xC1` |

对应伪代码在 `reconstructed_cpp/H0WS2/H0WS2_all_decompiled.txt`。

## 4. 已声明的偏差（不要当成 bug 报）

1. **`long` 宽度**：原库 LP64（`long` 64 位），MinGW 是 LLP64（32 位），
   生成后统一改写为 `long long` 以还原原始宽度。
2. **不透明结构**：`epoll_event` / `sockaddr` / `sockaddr_un` / `stat` / `sigaction`
   在 shim 里是字节数组，按显式偏移访问；字段大小是**推断**的。
3. **`int3`/`int5` 宽度近似**：分别按 4/8 字节处理。
4. **`auVarN` 16 字节返回槽**：`<<`/`>>`/`|` 按字节实现（所有移位量都是 8 的倍数）。
5. **`EventLoop2__del` 的被调方重定向**：唯一一处"换了符号"的改动，见
   `evidence/fix_lanes/NOTES.md` §4。

## 5. 不要做的事

- 不要执行原 `.so` 或任何重建产物。
- 不要因为"能编译"就认为语义正确——编译通过只说明类型能对上。
- 协议层的结论请对照 `semantic/proto/README.md` 里的地址逐条核，不要只看结论。

## 6. 回报格式

```
条目：<文件>:<行> 或 <函数> @ <地址>
现象：<与伪代码/协议规范的哪一点不符>
证据：<伪代码行号 / 反汇编片段 / rodata 地址>
影响：<个例还是整个协议层>
```
