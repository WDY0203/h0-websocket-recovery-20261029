# H0 WebSocket 库：只读反编译重建

两个 Linux x86-64 共享库的静态重建，**原始二进制与重建产物均未执行**。

| 库 | 文件 | 大小 | 函数 |
|---|---|---|---|
| `bbwebsocket.so` | `H0WS2` | 155,072 B | 400 |
| `bbwebsocket3.so` | `H0WS3` | 155,200 B | 400 |

两个库是**同一份代码的两个版本**：215 个唯一函数名完全一致，152 个共享；
113 个语法失败函数的**失败模式 110 种、逐条一一对应**。

## 当前状态

| 项 | H0WS2 | H0WS3 |
|---|---|---|
| 严格语法（`g++ -std=gnu++17 -fsyntax-only`，无 `-fpermissive`） | **400 / 400** | **400 / 400** |
| 翻译单元 | 3（`part_0001/0002/0003_fixes`） | 3 |
| shim 单独编译 | 0 error | 0 error |
| 协议层 claims | 42 confirmed + 1 unknown | 同（同一份代码） |
| 协议层测试断言 | 188 通过 | 同 |

## 目录

```
reconstructed_cpp/H0WS2/     400 个函数的 C++ 重建 + 反编译原文 + 报告
reconstructed_cpp/H0WS3/     同上
semantic/proto/              WebSocket 协议语义重建（claims + 测试）
evidence/fix_lanes/          113 个失败函数的修复记录与差异说明
```

## 怎么验

见 `VERIFICATION.md`。三个数字要先自己复算：

```bash
cd reconstructed_cpp/H0WS2
g++ -std=gnu++17 -fsyntax-only -I . H0WS2_tu/part_0001.cpp   # 0 error
grep -c "^===== IDX" H0WS2_all_decompiled.txt                 # 400
```

## 最重要的发现（安全相关）

1. **服务端不校验握手**：只找 `Sec-WebSocket-Key: `，有非空值就回 `101`。
   `Upgrade` / `Connection` / `Sec-WebSocket-Version` / 请求行**完全没检查**。
2. **客户端 key 是常量**：`base64(16×0x00)` = `AAAAAAAAAAAAAAAAAAAAAA==`，
   所有连接用同一个 key。
3. **客户端不校验服务端响应**：只要收到 `\r\n\r\n` 就认为握手成功，HTTP 400 也算。
4. **不发控制帧**：全库没有任何构造 Close/Ping/Pong 的代码路径（`0x88/0x89/0x8a`
   立即数在全 `.text` 中不存在）。
5. **分片是坏的**：`FIN=0` 后仍用**本帧** opcode 分发，标准文本分片
   （首帧 `0x01`、末帧 `0x80`）不会被投递。

细节与地址见 `semantic/proto/README.md`。
