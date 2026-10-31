#!/usr/bin/env python3
# Generates table.json (single source of truth for the table-driven test) from the
# values observed in the decompiled listings. Every row below is a claim that is
# re-checked at test time by test.cpp.
import json, os, hashlib, base64

OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'table.json')

ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
FMT = ("GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n"
       "Sec-WebSocket-Key: %s\r\nSec-WebSocket-Extensions: permessage-deflate\r\n"
       "Sec-WebSocket-Version: 13\r\n\r\n")

def b64(hexs):
    return base64.b64encode(bytes.fromhex(hexs)).decode()

T1 = [
    {"id": "B01", "hex": "",                                 "out": ""},
    {"id": "B02", "hex": "66",                               "out": b64("66")},
    {"id": "B03", "hex": "666f",                             "out": b64("666f")},
    {"id": "B04", "hex": "666f6f",                           "out": b64("666f6f")},
    {"id": "B05", "hex": "00" * 16,                          "out": "AAAAAAAAAAAAAAAAAAAAAA=="},
    {"id": "B06", "hex": "fbff",                             "out": b64("fbff")},
    {"id": "B07", "hex": "00ff10",                           "out": b64("00ff10")},
]

KEY = "AAAAAAAAAAAAAAAAAAAAAA=="
REQ = FMT % KEY
T2 = [
    {"id": "R01", "key": KEY, "len": len(REQ), "prefix": "GET / HTTP/1.1\r\n",
     "head_off": REQ.index(KEY), "tail": "\r\n\r\n"},
    {"id": "R02", "key": "dGhlIHNhbXBsZSBub25jZQ==", "len": len(FMT % "dGhlIHNhbXBsZSBub25jZQ=="),
     "prefix": "GET / HTTP/1.1\r\n", "head_off": 76, "tail": "\r\n\r\n"},
]

T3 = [
    {"id": "S01", "buf": "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\n"
                         "Connection: Upgrade\r\nSec-WebSocket-Accept: x\r\n\r\n",
     "deflate": False, "head_end": None},
    {"id": "S02", "buf": "HTTP/1.1 101 Switching Protocols\r\nSec-WebSocket-Extensions: "
                         "permessage-deflate\r\n\r\n", "deflate": True, "head_end": None},
    {"id": "S03", "buf": "HTTP/1.1 200 OK\r\n\r\n", "deflate": False, "head_end": 19},
    {"id": "S04", "buf": "\r\n\r\nrest", "deflate": False, "head_end": 4},
    {"id": "S05", "buf": "A\r\n\r\nB\r\n\r\n", "deflate": False, "head_end": 5},
    {"id": "S06", "buf": "Sec-WebSocket-Extensions: Permessage-Deflate\r\n\r\n",
     "deflate": False, "head_end": None},
    {"id": "S07", "buf": "x-permessage-deflate-x\r\n\r\n", "deflate": True, "head_end": 26},
]
for r in T3:
    if r["head_end"] is None:
        r["head_end"] = len(r["buf"])  # sentinel: no CRLFCRLF found

T4 = [
    {"id": "H01", "input": "abc", "hex": hashlib.sha1(b"abc").hexdigest()},
    {"id": "H02", "input": "",    "hex": hashlib.sha1(b"").hexdigest()},
    {"id": "H03", "input": "a" * 64, "hex": hashlib.sha1(b"a" * 64).hexdigest()},
    {"id": "H04", "input": "dGhlIHNhbXBsZSBub25jZQ==", "hex": hashlib.sha1(b"dGhlIHNhbXBsZSBub25jZQ==").hexdigest()},
]

T5 = [
    {"id": "F01", "name": "recv_open",  "value": True},
    {"id": "F02", "name": "send_open",  "value": True},
    {"id": "F03", "name": "send_armed", "value": False},
    {"id": "F04", "name": "read_armed", "value": False},
]

T6 = [  # recv_step
    {"id": "V01", "armed": False, "n": 10,  "err": 0,  "kind": "Bogus",
     "clear_recv": True,  "clear_send": True,  "clear_armed": False, "fire": False},
    {"id": "V02", "armed": True,  "n": -1,  "err": 11, "kind": "Again",
     "clear_recv": False, "clear_send": False, "clear_armed": False, "fire": False},
    {"id": "V03", "armed": True,  "n": 0,   "err": 0,  "kind": "Eof",
     "clear_recv": True,  "clear_send": False, "clear_armed": True,  "fire": False},
    {"id": "V04", "armed": True,  "n": -1,  "err": 32, "kind": "Fatal",
     "clear_recv": True,  "clear_send": True,  "clear_armed": True,  "fire": False},
    {"id": "V05", "armed": True,  "n": 5,   "err": 0,  "kind": "Delivered",
     "clear_recv": False, "clear_send": False, "clear_armed": True,  "fire": True},
]

T7 = [  # send_step
    {"id": "W01", "armed": False, "pending": True,  "queued": 10, "n": 10,  "err": 0,
     "kind": "Bogus", "clear_open": False, "clear_armed": False, "shutdown": False,
     "fire": False, "unsent": 10},
    {"id": "W02", "armed": True,  "pending": False, "queued": 0,  "n": 0,   "err": 0,
     "kind": "DrainAndShutdown", "clear_open": True, "clear_armed": True, "shutdown": True,
     "fire": True, "unsent": 0},
    {"id": "W03", "armed": True,  "pending": True,  "queued": 10, "n": -1,  "err": 11,
     "kind": "Again", "clear_open": False, "clear_armed": False, "shutdown": False,
     "fire": False, "unsent": 10},
    {"id": "W04", "armed": True,  "pending": True,  "queued": 10, "n": 4,   "err": 0,
     "kind": "Partial", "clear_open": False, "clear_armed": False, "shutdown": False,
     "fire": False, "unsent": 6},
    {"id": "W05", "armed": True,  "pending": True,  "queued": 10, "n": 10,  "err": 0,
     "kind": "Complete", "clear_open": False, "clear_armed": True, "shutdown": False,
     "fire": True, "unsent": 0},
    {"id": "W06", "armed": True,  "pending": True,  "queued": 10, "n": -1,  "err": 32,
     "kind": "Complete", "clear_open": False, "clear_armed": True, "shutdown": False,
     "fire": True, "unsent": 0},
]

T8 = [  # client_poll
    {"id": "P01", "state": 0, "events": 2, "so_error": 0,   "fd_match": True,
     "recv_open": True,  "send_open": True,  "next": 1, "cb": 1, "reap": False,
     "call_send": False, "call_recv": False},
    {"id": "P02", "state": 0, "events": 2, "so_error": 111, "fd_match": True,
     "recv_open": True,  "send_open": True,  "next": 2, "cb": 2, "reap": False,
     "call_send": False, "call_recv": False},
    {"id": "P03", "state": 0, "events": 1, "so_error": 0,   "fd_match": True,
     "recv_open": True,  "send_open": True,  "next": 0, "cb": 0, "reap": False,
     "call_send": False, "call_recv": False},
    {"id": "P04", "state": 0, "events": 2, "so_error": 0,   "fd_match": False,
     "recv_open": True,  "send_open": True,  "next": 0, "cb": 0, "reap": False,
     "call_send": False, "call_recv": False},
    {"id": "P05", "state": 1, "events": 3, "so_error": 0,   "fd_match": True,
     "recv_open": True,  "send_open": True,  "next": 1, "cb": 0, "reap": False,
     "call_send": True,  "call_recv": True},
    {"id": "P06", "state": 1, "events": 1, "so_error": 0,   "fd_match": True,
     "recv_open": False, "send_open": False, "next": 1, "cb": 0, "reap": True,
     "call_send": False, "call_recv": True},
    {"id": "P07", "state": 1, "events": 2, "so_error": 0,   "fd_match": True,
     "recv_open": False, "send_open": True,  "next": 1, "cb": 0, "reap": False,
     "call_send": True,  "call_recv": False},
    {"id": "P08", "state": 2, "events": 0, "so_error": 0,   "fd_match": True,
     "recv_open": True,  "send_open": True,  "next": 2, "cb": 0, "reap": True,
     "call_send": False, "call_recv": False},
]

T9 = [  # server reap
    {"id": "K01", "recv_open": True,  "send_open": True,  "reap": False},
    {"id": "K02", "recv_open": False, "send_open": True,  "reap": False},
    {"id": "K03", "recv_open": True,  "send_open": False, "reap": False},
    {"id": "K04", "recv_open": False, "send_open": False, "reap": True},
]

T10 = [
    {"id": "L01", "in": True,  "out": True,  "word": 0x15},
    {"id": "L02", "in": True,  "out": False, "word": 0x11},
    {"id": "L03", "in": False, "out": True,  "word": 0x04},
    {"id": "L04", "in": False, "out": False, "word": 0x00},
]

T11 = [
    {"id": "A01", "addr": "/tmp/bb.sock", "unix": True},
    {"id": "A02", "addr": "127.0.0.1",    "unix": False},
    {"id": "A03", "addr": "",             "unix": False},
    {"id": "A04", "addr": "/",            "unix": True},
]

T12 = [
    {"id": "X01", "recv_flag": False, "send_flag": False, "warn_recv": False,
     "warn_send": False, "callbacks": 3},
    {"id": "X02", "recv_flag": True,  "send_flag": True,  "warn_recv": True,
     "warn_send": True,  "callbacks": 3},
]

MEMBERS = [
    {"id": "M01", "func": "WSConn::connect",        "py3": "0x1123b0", "py2": "0x1122b0", "i3": 231, "i2": 231, "lines3": 405, "lines2": 405, "same": True,  "asserts": 8, "role": "client handshake: zero nonce -> base64 key -> GET upgrade, installs callbacks"},
    {"id": "M02", "func": "FUN_0010fd40",           "py3": "0x10fd40", "py2": "0x10fc40", "i3": 218, "i2": 218, "lines3": 59,  "lines2": 59,  "same": True,  "asserts": 4, "role": "after send: wait for CRLFCRLF via recv_pat, then hand over to M03"},
    {"id": "M03", "func": "FUN_0010dcc0",           "py3": "0x10dcc0", "py2": "0x10dbc0", "i3": 200, "i2": 199, "lines3": 70,  "lines2": 70,  "same": True,  "asserts": 6, "role": "client response: memmem permessage-deflate, zlib init, consume head, fire on-connect"},
    {"id": "M04", "func": "FUN_0010d720",           "py3": "0x10d720", "py2": "0x10d620", "i3": 197, "i2": 196, "lines3": 1423,"lines2": 1423,"same": True,  "asserts": 7, "role": "SHA-1 block transform (K constants 5a827999/6ed9eba1/8f1bbcdc/ca62c1d6)"},
    {"id": "M05", "func": "Buffer::appendf",        "py3": "0x1159c0", "py2": "0x1158c0", "i3": 239, "i2": 239, "lines3": 172, "lines2": 172, "same": True,  "asserts": 4, "role": "vsnprintf twice, grow len+1, trim NUL (builds the GET request)"},
    {"id": "M06", "func": "TcpClient::TcpClient(host,port)", "py3": "0x11a390", "py2": "0x11a290", "i3": 281, "i2": 281, "lines3": 374, "lines2": 374, "same": True, "asserts": 7, "role": "AF_INET inet_addr + TCP_NODELAY + nonblock + connect, EINPROGRESS=115 is the async path"},
    {"id": "M07", "func": "TcpClient::TcpClient(fd)", "py3": "0x118320", "py2": "0x118220", "i3": 273, "i2": 273, "lines3": 64, "lines2": 64, "same": True,  "asserts": 4, "role": "adopt an existing fd: state=1 immediately, TcpConn with empty host/name"},
    {"id": "M08", "func": "TcpConn::TcpConn",       "py3": "0x118190", "py2": "0x118090", "i3": 272, "i2": 272, "lines3": 31,  "lines2": 31,  "same": True,  "asserts": 3, "role": "connection flag init 0x58=1 0x59=1 0x5a=0 0x88=0"},
    {"id": "M09", "func": "~TcpConn",               "py3": "0x118550", "py2": "0x118450", "i3": 274, "i2": 274, "lines3": 83,  "lines2": 83,  "same": True,  "asserts": 4, "role": "erase 3 fd trees, close(fd), free pending buffer"},
    {"id": "M10", "func": "TcpConn::recv_proc",     "py3": "0x119380", "py2": "0x119280", "i3": 280, "i2": 280, "lines3": 751, "lines2": 751, "same": True,  "asserts": 6, "role": "read 0x8000; EAGAIN/Eof/Fatal/Bogus; no callback on EOF"},
    {"id": "M11", "func": "TcpConn::send_proc",     "py3": "0x11ad10", "py2": "0x11ac10", "i3": 282, "i2": 282, "lines3": 673, "lines2": 673, "same": True,  "asserts": 6, "role": "write pending buffer; partial keeps tail; drain -> shutdown(SHUT_WR)"},
    {"id": "M12", "func": "TcpClient::poll",        "py3": "0x11c000", "py2": "0x11bf00", "i3": 284, "i2": 284, "lines3": 429, "lines2": 429, "same": True,  "asserts": 8, "role": "state 0/1/2; SO_ERROR probe; reap when both directions closed"},
    {"id": "M13", "func": "TcpServer::poll",        "py3": "0x11baf0", "py2": "0x11b9f0", "i3": 283, "i2": 283, "lines3": 203, "lines2": 203, "same": True,  "asserts": 3, "role": "accept on listen fd, else send_proc then recv_proc then reap"},
    {"id": "M14", "func": "WSConn::exit",           "py3": "0x10c210", "py2": "0x10c110", "i3": 195, "i2": 194, "lines3": 562, "lines2": 562, "same": True,  "asserts": 5, "role": "3 waves: recv_flag(+0x88), send_flag(+0x5a)+drop pending, idle cb; 3 callbacks replaced"},
    {"id": "M15", "func": "~WSConn",                "py3": "0x10ee70", "py2": "0x10ed70", "i3": 213, "i2": 212, "lines3": 42,  "lines2": 42,  "same": True,  "asserts": 3, "role": "inflateEnd/deflateEnd only if 0x58 negotiated; free 3 buffers"},
    {"id": "M16", "func": "EventLoop2::run",        "py3": "0x116de0", "py2": "0x116ce0", "i3": 258, "i2": 258, "lines3": 316, "lines2": 316, "same": True,  "asserts": 7, "role": "epoll_ctl interest 0x11/0x15/0x4, epoll_wait maxevents=1, timeout us/1000"},
    {"id": "M17", "func": "FUN_0010a780",           "py3": "0x10a780", "py2": "0x10a6b0", "i3": 177, "i2": 176, "lines3": 210, "lines2": 204, "same": False, "asserts": 5, "role": "connect(addr,port): EventLoop2 + TcpClient|UnixClient, runs loop inline, returns handle"},
    {"id": "M18", "func": "FUN_00109f70",           "py3": "0x109f70", "py2": "0x109ea0", "i3": 176, "i2": 175, "lines3": 355, "lines2": 355, "same": True,  "asserts": 4, "role": "disconnect(handle): close WSConn, run loop, destroy loop, return 0"},
]

COVERAGE = {
    "total_functions": 400,
    "fragment": 0,          # patched by mkcoverage.py
    "in_table": 18,
    "alias": 0,             # patched
    "cold": 0,              # patched
    "formula": "(in_table + alias + cold) / (total_functions - fragment)",
}

ASSERTS = {
    'M01': 21, 'M02': 4, 'M03': 17, 'M04': 7, 'M05': 4, 'M06': 8, 'M07': 4,
    'M08': 4, 'M09': 4, 'M10': 26, 'M11': 36, 'M12': 40, 'M13': 6, 'M14': 8,
    'M15': 4, 'M16': 8, 'M17': 8, 'M18': 4,
}

def main():
    for m in MEMBERS:
        m['asserts'] = ASSERTS[m['id']]
        m.setdefault('delta', 0xd0 if m['id'] in ('M17', 'M18') else 0x100)
    cov_path = os.path.join(os.path.dirname(OUT), 'coverage_counts.json')
    if os.path.exists(cov_path):
        COVERAGE.update(json.load(open(cov_path)))
    doc = {
        "family": "handshake_family",
        "target": "bbwebsocket (py2 build bbwebsocket.so / py3 build bbwebsocket3.so) 1.2.7",
        "source_py3": "D:\\\\tmp\\\\H0WS3_all_decompiled.txt",
        "source_py2": "D:\\\\tmp\\\\H0WS2_all_decompiled.txt",
        "tables": {
            "T1_base64": T1,
            "T2_request": T2,
            "T3_response_scan": T3,
            "T4_sha1": T4,
            "T5_conn_ctor_flags": T5,
            "T6_recv_step": T6,
            "T7_send_step": T7,
            "T8_client_poll": T8,
            "T9_server_reap": T9,
            "T10_loop_interest": T10,
            "T11_api_transport": T11,
            "T12_exit_waves": T12,
        },
        "members": MEMBERS,
        "coverage": COVERAGE,
    }
    with open(OUT, 'w', encoding='utf-8') as f:
        json.dump(doc, f, indent=1, ensure_ascii=False)
    print('wrote', OUT, os.path.getsize(OUT), 'bytes')

if __name__ == '__main__':
    main()
