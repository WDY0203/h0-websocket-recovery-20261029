# `bbwebsocket` 的 Python 侧接口（来自 pypinot zipapp 的源码）

`D:\tmp\opt_pyz\pypinot\external\transport\__init__.py` 里有 `bbwebsocket` 的**真实调用方式**。
这是从 zipapp 里直接读到的 Python 源码，不是反编译推断。

## 关键事实

```python
bbws = util.import_so('bbwebsocket')
```

而 `util.import_so` 的实现是：

```python
def import_so(name):
    ...
    if sys.version_info[0] >= 3:
        name = name + '3'
    path = os.path.join(os.path.dirname(__file__), name + '.so')
```

**这解释了为什么有两个库**：`bbwebsocket.so` 是 Python 2 构建，`bbwebsocket3.so` 是 Python 3 构建。
两者的差异是 `PyInit_bbwebsocket` vs `PyInit_bbwebsocket3`，业务代码相同
（这也解释了为什么我们的语法修复在这两个库上 110 种失败模式完全重合）。

## 对外 API（4 个）

| Python 调用 | 语义 |
|---|---|
| `bbws.connect(addr, port)` | 建立连接，返回非 0 句柄；失败返回 0 |
| `bbws.disconnect(conn)` | 关闭连接 |
| `bbws.send(conn, text)` | 发送一个文本帧（调用方自己 `json.dumps`） |
| `bbws.recv_timeout(conn, timeo)` | 带超时收一帧，返回 `(status, data)`；`status == 0` 表示成功 |

## 用法（pypinot 的消息总线）

```python
class Transport:
    def __init__(self, myname, addr="127.0.0.1", port=2433):
        self.conn = bbws.connect(addr, port)
    def send(self, peername, content):
        msg = {'from': self.myname, 'to': peername, 'content': content}
        bbws.send(self.conn, json.dumps(msg))
    def recvall(self, timeo=5, sender=None):
        status, data = bbws.recv_timeout(self.conn, timeo)
        msg = json.loads(data)
        return 0, msg['from'], msg['to'], msg['content']
```

协议是 **JSON over WebSocket**，默认端口 **2433**，消息字段 `from` / `to` / `content`。

## 对我们重建的意义

1. 这两个库**不是通用 WebSocket 库**，而是给 pypinot 做进程间消息总线用的专用绑定。
2. 之前从符号表推断的 `wsc_connect` / `wsc_send` / `wsc_disconnect` / `wsc_recv`
   就是上表 4 个 API 的内部实现。
3. `recv_timeout` 的 `status` 语义（0 = 成功）与我们在 `semantic/proto/` 里恢复的
   `opcode==1 → 投递消息` 一致。

## 与 D0 的关系

D0 的 `WSConn` 与我们重建的 `bbwebsocket` 是**同一份代码**（`semantic/proto/` 已逐条对照）。
所以 D0 通信库很可能也是给同一套系统做消息总线。
