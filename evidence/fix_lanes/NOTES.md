# H0WS2 / H0WS3 — 类型层可编译性修复说明

对 `bbwebsocket.so` / `bbwebsocket3.so` 的 Ghidra 反编译重建 (H0WS2 / H0WS3) 中
**113 个在严格语法检查下失败的函数**做类型层修复，产出可直接替换原定义的 `fixes.cpp`。

- 编译判定：`g++ -std=gnu++17 -fsyntax-only`（MinGW-W64 UCRT g++ 16.2.0），**无 `-fpermissive`**
- 未修改 `D:\tmp\cppgen\H0WS2` / `H0WS3`（含 shim）；未执行 ELF；未联网
- 可复现：`tools/` 下的脚本 + `work/fix/<prefix>/fNNN.cpp`（逐函数修复后的成品）

---

## 1. 结果

| | WS2 | WS3 |
|---|---|---|
| `strict.json` 记录的 fail | 113 | 113 |
| 本次替换并修好的函数 | **113 / 113** | **113 / 113** |
| `fixes.cpp` 单 TU 编译 | **0 error**（48 warning） | **0 error**（48 warning） |
| `remove.txt` 条目 | 113 | 113 |

warning 全部来自原重建代码，不是修复引入的：

- 43 × `-Wwrite-strings`（字面量传给 `char*` 形参，C++11 起的合法但不推荐）
- 4 × `-Wshift-count-overflow`（`ZEXT112(x) << 0x40`，生成器原本就有的 64 位移位，未改动）
- 1 × `-Wint-to-pointer-cast`（`*(long long *)*param_1`，`param_1` 是 `long*`；**这是 Windows/MinGW 的 ABI 现象**：目标 ELF 是 LP64 Linux，`long` 为 64 位。在本机 `long` 是 32 位才报此警告）

逐函数编译（每函数单独一个 TU：`shim + prelude + 函数体`）同样 113/113 clean。
`tools/consistency.py` 校验 `remove.txt` 与 manifest 的 `file/line_start/line_end` 逐条一致、
与 `fixes.cpp` 的 `// IDX n addr name` 横幅一一对应、无重名、无多余定义。

---

## 2. 方法

1. `H0WS*_report.json` 的 `manifest`（`idx/name/file/line_start/line_end`）定位每个失败函数在 TU 中的行区间。
2. 抽取函数体 → 应用**类型层重写规则**（`tools/structural.py`）→ 用编译器诊断驱动**插入转换**（`tools/autofix.py`）→ 迭代到 0 error。
3. 用 `H0WS*_all_decompiled.txt`（`===== IDX n ADDR NAME =====` 块）核对参数表、`auVarN` 槽位、`stat/sockaddr/epoll_event` 布局。
4. 修复后的函数按原 `idx` 顺序写进 `fixes.cpp`，**函数名与返回类型不变**；参数表除 3 个被生成器漏掉的形参外亦不变（见 §4.1）。`remove.txt` 给出要删除的旧定义（行号取自当前 manifest）。

`fixes.cpp` 结构：`#include "<prefix>_shim.hpp"` + 类型修复 prelude + 113 个函数体（每个前面保留 `// IDX n addr name` 横幅，便于对账）。

---

## 3. 施加的规则（只改类型，不改控制流/偏移/常量）

### 3.1 指针 ↔ 整数
shim 把 Ghidra 的类型当“不透明字节”处理（`WSConn`、`_Rb_tree_node_base`、`EventLoop2` … 全是 `typedef uint8_t`），因此 `*puVar = ptr` / `p = (*(undefined8*)&slot)` 之类全部非法。

- 统一用 `(T)(uintptr_t)(expr)` / `(T *)(uintptr_t)(expr)` 桥接；x86-64 上 `uintptr_t` 与 `undefined8` 同宽，**不丢位**。
- 共 575 处桥接（两库相同）。

### 3.2 `operator_new` / `memmove` / 库函数返回值
`rea_operator_new` 声明返回 `_Rb_tree_node_base *`，但被赋给 `undefined8*`、`long long*`、`code*` 等 → 显式转换到目标指针类型。

### 3.3 函数指针
- `undefined8 local_XXX;` 若在函数体内被 `(*local_XXX)(...)` 调用，则声明改为 `code *local_XXX;`（138 处/库）。
- `FUN_xxxx` → `rea_FUN_xxxx`（补声明名）。
- 被生成器截断的 `PTR__M_emplace_back_aux<std__pair<...>>>_00325230`（WS3 为 `_00325220`）→ `PTR__M_emplace_back_aux`：生成器在 `<` 处截断了符号名，裸名就是同一符号。

### 3.4 16 字节 `auVarN` 槽的 `<<` / `>>` / `|`
Ghidra 对 16 字节返回值做 128 位运算。C++ 原始数组没有运算符，所以：

- 参与 `<<`/`>>`/`|` 的 `undefined1 name [N];` 声明改为 shim 已有的 `arr_undefined1_N name;`；
- 在 prelude 里给这些聚合类型补一组**模板运算符**（按 `sizeof(T)` 决定有效字节数，返回 16 字节 `rea_wide`）；
- 补上 shim 缺失的 `arr_undefined1_4 / _8 / _15`。

所有出现的移位量都是 8 的整数倍（`0x10 0x18 0x20 0x28 0x30 0x38 0x40`，共 250 处），因此按字节搬移的实现是**精确**的，没有位级截断；`|` 按字节或。

### 3.5 不透明聚合体：字节数组 + 显式偏移
按 SysV x86-64 布局改写（偏移取自 `H0WS*_all_decompiled.txt` 里 Ghidra 打印的字段偏移）：

| 类型 | 局部声明 | 字段 → 偏移 |
|---|---|---|
| `epoll_event`（packed） | `undefined1 x[0xc]` | `events` @0x0（u32）, `data` @0x4（u64）, `data.fd` @0x4（int） |
| `sockaddr` | `undefined1 x[0x10]` | `sa_family` @0x0（u16）, `sa_data` @0x2；`sa_data._2_4_`→+0x4, `sa_data._0_2_`→+0x2 |
| `stat` | `undefined1 x[0x90]` | `st_mode` @0x18（u32）, `__unused` @0x78 |
| `sigaction` / `_union_1457` | `undefined1 x[0x98]` | `sa_handler` @0x0 |

数组形式（`sockaddr local_a8[2]`）同样改写为 `undefined1 local_a8[2][0x10]`。
生成器已经炸开但丢了基址的表达式 `local_48.(*(undefined4 *)((uint8_t *)&sa_data + 0x2))` 也按上表还原为 `local_48 + 0x4`。

### 3.6 `_4_4_` 半字提取
`slot._4_4_`（Ghidra “偏移 4、宽 4”）→ `(undefined4)((uint64_t)(uintptr_t)slot >> 32)`。

### 3.7 `__sighandler_t`
shim 里 `__sighandler_t` 是**变量**不是类型（`extern uint8_t *__sighandler_t;`），所以 `(__sighandler_t)` 形式全部改成 `(code *)`。

### 3.8 缺失的标量类型
shim 缺 `int3 / uint3 / int5 / unkuint10`。用最接近的原生整型补：

```cpp
typedef uint32_t uint3;             // 3 字节 → 4
typedef int32_t  int3;              // 3 字节 → 4
typedef int64_t  int5;              // 5 字节 → 8
typedef unsigned __int128 unkuint10; // 10 字节 → 16，保住 << 0x38 / << 0x40
```

这些只出现在 `(int3)(...)` / `(unkuint10)CONCAT11(...) << 0x38` 这类**立即被丢弃**的铸型里（右侧要么进 `arr_undefined1_N` 的模板构造，要么是 `code*` 槽），宽度差异不改变控制流。见 §5 简化清单。

### 3.9 `unique0x...` 伪寄存器
Ghidra 的 `unique0x00008e00` 等 7 个伪寄存器在生成代码里被当作普通语句赋值，但没有声明。按 `uintptr_t` 局部变量补声明（只写不读，语义上是死存储）。

---

## 4. 需要人工确认的“非机械”改动（共 8 函数）

### 4.1 补回被生成器截断的参数（3 个）

| 函数 | 生成签名 | 修复后 | 依据 |
|---|---|---|---|
| `rea__Function_handler_void` | `(undefined8 *param_2)` | `(long *param_1, undefined8 *param_2)` | IDX 185 伪代码 `_M_invoke(long *param_1,undefined8 *param_2)` |
| `rea__Function_handler_void__dup2` | `(undefined8 <mangled>, undefined8 *param_3)` | `(undefined8 *param_1, undefined8 *param_2, undefined8 *param_3)` | IDX 186 伪代码三个 `undefined8*` |
| `rea__Function_handler_void__dup3` | `(undefined8 *param_2)` | `(long *param_1, undefined8 *param_2)` | IDX 241 同上 |

### 4.2 `this` 指针拼写不一致（1 个）

`rea_vector_std__pair_EventHandler__std__function_void__dup4`：签名首参叫 `param_x0`，函数体里却用 `this_ptr` → 统一为 `param_x0`。

### 4.3 被彻底揉烂的被调方名字（1 个）

`rea_EventLoop2__del` 里一处调用被生成器写成跨 5 行的 `std::\nvector<std__pair<...>>\n::_M_emplace_back_aux<...>`，这些模板实参名不是合法 C++。改写为 shim 里已声明的同一 `_M_emplace_back_aux` 家族成员：

```cpp
rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_...___M_emplace_back_aux_std__unique_ptr_EventHandler_...((vector_... *)(this_ptr + 0x38),(unique_ptr *)&local_48);
```

两个实参（`vector*`、`pair*`）与形参（`vector*`、`unique_ptr*`）都是 `uint8_t` 派生的不透明类型，调用形态与原伪代码一致。**但这是本批次里唯一一处“换了符号”的改动**，语义上应对照原 ELF 的 PLT 目标确认。

### 4.4 其它两处需要复核的类型假设

- IDX 232：`*(undefined1 (*)[8])(lVar24 + 0x80) = auStack_120;`（数组赋值非法）→ `*(undefined8 *)(lVar24 + 0x80) = *(undefined8 *)(auStack_120);`（按 8 字节搬移）。
- IDX 248：`stat.__unused` 偏移取 **0x78**（glibc x86-64 `struct stat` 尾部 `__unused[3]`，紧随 `st_ctim` 之后）。伪代码把它当数组基址做 `+ __n + 0x17`，本身已是反编译噪声。

---

## 5. 简化 / 偏差清单（均为通过编译所必需，未删任何分支、循环、常量）

1. **`return;` → `return 0;`**（8 个函数，11 处）：伪代码里返回类型被推成 `undefined8` 但函数体是裸 `return;`。改返回类型会波及调用方，故取最小改动（返回值本就无意义）。
   涉及：IDX 38/69/145/185/186/241/260/262（WS2 编号）。
2. **`(T *)0x0` → `0x0`**：指针空常量改成整数 0。语义完全相同（都是空指针常量），目的是消掉 `pointer vs integer` / `distinct pointer types` 两类噪声。**这是唯一一处会触及“本来就编译通过”的行的规则**，如需零噪声可回退（不影响可编译性）。
3. **`int3/uint3/int5` 宽度近似**（见 §3.8）；`unkuint10` 已用 128 位，`<< 0x38 / 0x40` 不失真。
4. **128 位运算按字节实现**：只在 8 的整数倍位移下精确；本语料全部满足。且 `arr_undefined1_N`（N<16）参与运算时只读取 N 字节，其余补 0 —— 与 Ghidra 的窄化视图一致。
5. **`(uintptr_t)` 桥接**假定 `sizeof(void*) == sizeof(undefined8) == 8`（x86-64 成立）。
6. **`unique0x...` 定为 `uintptr_t`**：只写不读。
7. `arr_undefined1_8` 比较写成 `*(undefined8 *)(slot) != 0`（原来是 `slot != arr_undefined1_8{}`，数组 vs 聚合无法比较）。
8. **平台 ABI 差异**：修复在 Windows/MinGW 上验证，目标却是 LP64 Linux。`long` 在本机 32 位、目标 64 位，
   仅影响 `long` 参与的指针转换（1 处 warning），不影响语法结论。若要完全对齐，应把这类 `long` 换成 `long long`。

---

## 6. 校验

`tools/verify.py` 逐函数比对“原始体”与“修复体”的：

- `if / while / for / do / goto / switch / case / else / return` 计数
- `LAB_xxxx` 标签集合
- 数值字面量多重集（扣除 §3.5 引入的字段偏移、`return 0`、`_4_4_` 的 `32`）

结果：

```
H0WS2: 113 functions checked, 2 with differences
  IDX 232  lost literals {'8': 1}     # (*)[8] → undefined8 存储，见 §4.4
  IDX 248  added literals {'0x18': 1} # st_mode 偏移，见 §3.5
H0WS3: 113 functions checked, 2 with differences   （同上两处）
```

即：**226 个函数里，控制流、标签、以及除上述两处外的全部常量都逐一对齐**。

原始状态（`tools/baseline.py`，只把 `FUN_` 改名为 `rea_FUN_`、未加任何类型修复）：

```
H0WS2: 113/113 still failing, 803 diagnostics
H0WS3: 113/113 still failing, 803 diagnostics
```

---

## 7. 同构性

`tools/modes.py`（对原始体做归一化统计）：

| 指标 | WS2 | WS3 |
|---|---|---|
| 失败函数 | 113 | 113 |
| 原始诊断条数 | 803 | 803 |
| 归一化后 (函数, 失败模式) 对 | 368 | 368 |
| 不同失败模式种类 | 110 | 110 |
| 两库共有的失败模式 | **110 / 110（100%）**，且每种模式的计数逐一相同 | |
| 失败函数名交集 | **70 / 113** | |

修复后的 `fixes.cpp` 在把 `IDX 编号 / 地址 / FUN_ 地址` 归一化后**逐行同构**
（18920 vs 18932 行，差分只剩编号与符号地址；`(uintptr_t)` 桥接数、`code*` 局部数、
`&slot` 区域转换数、`return 0` 数在两库中完全相同：575 / 138 / 353 / 130）。

因此规则集是同一套；两份 `fixes.cpp` 只是各自把本库的符号地址写实。若后续要合并为单一源文件，只需抽出地址表。

---

## 8. 仍需人工处理的清单

1. **§4.3 的被调方重定向**（`EventLoop2__del`）—— 需要对着原 ELF 的调用目标确认是否就是 `_M_emplace_back_aux` 那个实例化。
2. **§4.1 三个 `_M_invoke` 的参数表**——伪代码支持，但生成器当初为何丢参数未查（可能上游 `demangled_symbols` 解析差异）。
3. **§4.4 `stat.__unused` 偏移 0x78**、IDX 232 的 8 字节存储 —— 语义已在反编译噪声层面，建议结合 `__xstat` 调用点复核。
4. **`int3/int5/uint3` 宽度**：如需位精确，应在 shim 之外定义 3/5 字节 POD + 转换运算符（`unkuint10` 已用 `unsigned __int128`，无此问题）。
5. **§5.2 的 `(T*)0x0 → 0x0` 全局归一化**：若要求“只动报错行”，可关掉该规则重新生成（其余规则独立）。
6. 两个 `arr_undefined1_8{}` 比较已按“槽位非零”解释；如原意是逐字节比较，需另加 `operator==`。

---

## 9. 复现

```powershell
# 一条命令自检（本目录下）
pwsh -File selfcheck.ps1

# 重新生成两个库的逐函数修复体 + 汇总
python tools\autofix.py gen H0WS2
python tools\autofix.py gen H0WS3
python tools\assemble.py H0WS2 D:\tmp\semantic\H0WS\fix\H0WS2
python tools\assemble.py H0WS3 D:\tmp\semantic\H0WS\fix\H0WS3

$g = Get-ChildItem "$env:LOCALAPPDATA\Microsoft\WinGet\Packages" -Recurse -Filter g++.exe |
     Select-Object -First 1 -ExpandProperty FullName
& $g -std=gnu++17 -fsyntax-only -I D:\tmp\cppgen\H0WS2 H0WS2\fixes.cpp
& $g -std=gnu++17 -fsyntax-only -I D:\tmp\cppgen\H0WS3 H0WS3\fixes.cpp

python tools\verify.py H0WS2 H0WS3   # 控制流 / 常量不变性校验
python tools\baseline.py H0WS2 H0WS3 # 修复前的基线
python tools\modes.py                # 失败模式统计
```

| 文件 | 说明 |
|---|---|
| `selfcheck.ps1` | 一条命令跑两库的 `-fsyntax-only` 自检 |
| `H0WS2/fixes.cpp` | 113 个替换实现 |
| `H0WS2/remove.txt` | `file<TAB>start<TAB>end<TAB>addr<TAB>name` |
| `H0WS3/fixes.cpp`, `H0WS3/remove.txt` | 同上 |
| `tools/autofix.py` | 诊断驱动的转换插入 + 迭代 |
| `tools/structural.py` | 类型层重写规则与 prelude |
| `tools/assemble.py` / `verify.py` / `modes.py` | 汇总 / 校验 / 统计 |
| `work/fix/<prefix>/fNNN.cpp` | 逐函数修复后的独立 TU（可单独编译） |
