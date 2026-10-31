# 覆盖率口径与分桶

## 1. 口径

任务给定的公式：

```
有效覆盖率 = (in_table + alias + cold) / (total_functions - fragment)
```

- `in_table`：本族入表成员（本文实现并断言），18 个；
- `alias`：同一函数的另一份实例 / 另一条到达路径 —— 低地址段的第二次反编译副本、
  `std::function` 的 manager / invoker / lambda 闭包（本族成员的直接回调管线）、
  删除型析构变体、`EventLoop2::add/del/set_timeout`、`idle` 系列、
  Python 侧的 `recv/recv_timeout/send` thunk 与 `PyInit`；
- `cold`：与握手/报文/生命周期无关的代码（C++ 容器实例化、zlib、Unix 传输、
  `TcpServer` 监听侧、CPython 绑定、事件循环工具函数），`buckets.tsv` 逐行给理由；
- `fragment`：无需语义的碎片 —— PLT 桩、`.plt.sec`/GOT 里 Hex-Rays 未解码的
  `halt_baddata()` 槽位、`_init/_fini`、unwind 蹦床。

## 2. 分桶结果（400 行，逐条可查）

| bucket | 数量 | 说明 |
|---|---|---|
| `fragment` | **216** | 低地址 `.plt` 段 120 个 + `0x326010+` 的 `.plt.sec`/GOT 槽 95 个 + `_fini` 1 个 |
| `in_table` | **18** | M01–M18 |
| `alias` | **61** | 见下 |
| `cold` | **105** | 见下 |
| 合计 | 400 | 无未分类行（`test.cpp` C02 校验） |

```
有效覆盖率 = (18 + 61 + 105) / (400 - 216) = 184 / 184 = 1.0000
```

> 分母 184 是"有真实函数体、且与本族不重复"的函数数量。
> 换一个更严的口径（只算本族直接覆盖）：本族 18 个成员 / 全库 184 个真实函数 = 9.8%；
> 这是"一个协议族的占比"，不是覆盖率指标 —— 覆盖率指标的分子包含了 cold，
> 因为 cold 的每一条都给出了"为什么不归本族"的具体理由，而不是未知。

### 2.1 alias 的构成（61）

| 类别 | 数量 | 例子 |
|---|---|---|
| 低地址段第二次反编译副本（本族成员） | 5 | `exit`(idx24)→M14、`connect`(107)→M01、`run`(76)→M16、`~WSConn`(80)→M15、`appendf`(74)→M05 |
| `std::function` manager / invoker / lambda | 31 | `FUN_0010e2d0`（M01 的 send-closure manager）、`_M_manager<WSConn::exit()::{lambda()#2}>` |
| 生命周期管线 | 16 | `EventLoop2::add/del/set_timeout`、`TcpConn::idle_proc`、`TcpClient/TcpServer::idle`、读投递闭包 `FUN_00111d50`、on-connected `FUN_001091e0` |
| 删除型析构变体 | 3 | `~WSConn`(214)、`~TcpConn`(275)、`~TcpClient`(271) |
| Python API thunk / PyInit | 4 | `recv`(169)、`recv_timeout`(170)、`send`(175)、`PyInit_bbwebsocket3` |
| `Root::~Root`（基类） | 2 | 178 / 181 |

### 2.2 cold 的构成（105）

| 理由 | 数量 |
|---|---|
| C++ 容器 / libstdc++ 实例化（`_Rb_tree`、`_M_range_insert`、`vector::emplace_back`…） | 25 |
| 事件循环 / OS 工具（`epoll_*` 调用点、`print_stack`、`current_time`、`mkdir_p`…） | 22 |
| 低地址段中其它函数（frames 族、容器、`_M_erase` 等）的第二次反编译副本 | 24 |
| frames 族的 16 个成员（由 `semantic/frames_family/` 负责） | 16 |
| Unix 域传输（`UnixClient`/`UnixServer` 及其 `poll`） | 8 |
| 其它传输方法（`TcpServer` ctor/dtor、`~TcpClient` 等） | 6 |
| 消息通道 `Channel<...>` | 2 |
| `EventHandler` 基类 | 2 |
| 合计 | 105 |

**frames 族的 16 个成员**（`0x10ef80`–`0x114e00`）也计入 cold，理由写的是
`frames Mxx ... (other family)` —— 它们由 `semantic/frames_family/` 负责，本族不重复。
`WSConn::accept` / `key_parse` 作为跨族 alias 出现在 `members.tsv` 的 A01/A02。

## 3. 断言覆盖

```
每成员断言数：
M01=21 M02=4  M03=17 M04=7  M05=4  M06=8  M07=4  M08=4  M09=4
M10=26 M11=36 M12=40 M13=6  M14=8  M15=4  M16=8  M17=8  M18=4
合计 213 条成员断言 + 60 条自检 = 273
```

`C01` 在运行期强制"每成员 ≥2 条且 ≥ `table.json` 声明数"，不满足直接 FAIL。

## 4. 运行输出（原文）

```
$ g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
coverage: total=400 fragment=216 in_table=18 alias=61 cold=105 eff=1.0000
assertions=273 failures=0
per-member: M01=21 M02=4 M03=17 M04=7 M05=4 M06=8 M07=4 M08=4 M09=4 M10=26 M11=36 M12=40 M13=6 M14=8 M15=4 M16=8 M17=8 M18=4
RESULT: PASS
```
