#!/usr/bin/env python3
# Classifies all 400 decompiled blocks into fragment / in_table / alias / cold and writes
# buckets.tsv + coverage_counts.json. The classification is heuristic for the "cold" mass
# (with a reason string) but explicit for every name that matters to this family.
import json, re, difflib, os, sys

HERE = os.path.dirname(os.path.abspath(__file__))
bs = json.load(open(r'D:\tmp\semantic\H0WS\_work\p3.json', encoding='utf-8'))
D = {b['idx']: b for b in bs}

IN_TABLE = {
    231: 'M01 WSConn::connect', 218: 'M02 client wait-head closure', 200: 'M03 client response',
    197: 'M04 SHA-1 block transform', 239: 'M05 Buffer::appendf',
    281: 'M06 TcpClient(host,port)', 273: 'M07 TcpClient(fd)', 272: 'M08 TcpConn ctor',
    274: 'M09 ~TcpConn', 280: 'M10 recv_proc', 282: 'M11 send_proc', 284: 'M12 TcpClient::poll',
    283: 'M13 TcpServer::poll', 195: 'M14 WSConn::exit', 213: 'M15 ~WSConn',
    258: 'M16 EventLoop2::run', 177: 'M17 api connect', 176: 'M18 api disconnect',
}

# frames_family/members.tsv (py3 addresses) -- owned by that family, cold here.
FRAMES_ADDR = {
    0x10f280: 'frames M01 recv_pat', 0x10ff70: 'frames M02 recv_more',
    0x110bd0: 'frames M03 read_head', 0x1115a0: 'frames M04 hdr_parse',
    0x110a20: 'frames M05 len16', 0x111b50: 'frames M06 len64',
    0x110860: 'frames M07 read_data', 0x1106a0: 'frames M08 read_data_mask',
    0x110e50: 'frames M09 payload_mask', 0x111200: 'frames M10 payload_plain',
    0x10ef80: 'frames M11 finalize', 0x110d60: 'frames M12 recv',
    0x114e00: 'frames M13 send', 0x10fa40: 'frames M14 accept',
    0x112c60: 'frames M14 key_parse', 0x112080: 'frames M15 on_data',
}
FRAGMENT_ADDR = {0x106ed8: '_init', 0x1078d0: '_FINI_0', 0x107910: '_INIT_0'}

# helpers that are literally the callback plumbing of this family -> alias
ALIAS_HELPERS = {
    164: 'M18/M17 recv-completion closure (pops the message channel)',
    165: 'M18 recv-timeout/abort closure',
    166: 'M17 on-error closure',
    167: 'M17/M18 loop-exit closure',
    168: 'recv_with_timeout (called by the py recv/recv_timeout thunks)',
    169: 'py recv() thunk (FUN_00108a30)',
    170: 'py recv_timeout() thunk (FUN_00108bd0)',
    171: 'M18 close path installed by disconnect',
    172: 'PyInit_bbwebsocket3',
    173: 'M17 on-tcp-connected -> WSConn ctor + WSConn::connect',
    175: 'py send() thunk (FUN_00109bb0)',
    174: 'std::function handler that drives WSConn callbacks (FUN_00109450)',
    256: 'EventLoop2::add (registers a handler for M16)',
    257: 'EventLoop2::del (unregisters a handler for M16)',
    266: 'TcpConn::idle_proc (invokes the per-conn idle callback)',
    267: 'TcpClient::idle (M12 reap vote)',
    268: 'TcpServer::idle (M13 reap sweep)',
    229: 'WSConn read-delivery glue: null Buffer -> WSConn::exit(), else append + recv_more',
    214: '~WSConn deleting-destructor variant',
    275: '~TcpConn deleting-destructor variant',
    270: '~TcpClient (owns and destroys the conn)',
    271: '~TcpClient deleting-destructor variant',
    254: 'EventLoop2::set_timeout (feeds the M16 wait timeout / recv deadline)',
    153: 'exit() lambda #1 invoker', 154: 'lambda invoker (destroy)', 155: 'lambda invoker (clone)',
    160: 'std::function manager for M01 closure', 161: 'std::function manager for M17 closure',
    162: 'std::function manager for M01 closure', 163: 'std::function manager for M17 closure',
    264: 'lambda invoker for TcpConn idle cb', 265: 'std::function manager for TcpConn idle cb',
    178: 'Root::~Root', 179: 'lambda invoker for M14 exit#2', 180: 'lambda invoker for M14 exit#3',
    181: 'Root::~Root (2nd)', 182: 'std::function manager for M14 exit#2',
    183: 'std::function manager for M14 exit#3', 184: 'std::function manager for recv cb',
    185: 'std::function manager for recv cb', 186: 'std::function handler (recv)',
    187: 'std::function handler (recv)',
    198: 'manager for M02 closure', 199: 'manager for M03 closure',
    201: 'manager for client resp cb', 202: 'manager for wait-head cb',
    203: 'manager for wait-head cb', 204: 'manager/cloner for M01 send-closure',
    205: 'manager for M02 closure', 206: 'manager for client resp cb',
    207: 'manager for wait-head cb', 208: 'manager for wait-head cb',
    209: 'manager for M01 send-closure', 210: 'manager for M01 send-closure',
    211: 'manager for M14 exit cb', 212: 'manager for M14 exit cb',
}

def norm(t):
    t = re.sub(r'@0x[0-9a-fA-F]+', '@A', t)
    t = re.sub(r'0x[0-9a-fA-F]{5,}', '0xADDR', t)
    t = re.sub(r'\b(FUN|LAB|DAT|PTR|UNK)_[0-9a-fA-F]{6,}', r'\1_X', t)
    return [l.rstrip() for l in t.split('\n') if l.strip()]

def is_plt(b):
    body = b['body']
    if 'halt_baddata' in body:
        return True   # .plt.sec / GOT slot that Hex-Rays could not decode
    if b['name'] in ('_fini', '_init'):
        return True
    if '(*' not in body:
        return False
    if len(re.findall(r'\(\*\(code \*\)PTR_', body)) < 1:
        return False
    # a real body may also deref a vtable slot, so require the thunk shape
    return b['nlines'] <= 17 and 'while' not in body and 'if (' not in body.split('{', 1)[-1][:200]

def reason_bucket(idx, name, body):
    if name.startswith('std::') or name.startswith('_Rb_tree') or '_M_' in name or name.startswith('~vector') \
       or name.startswith('__to_xstring') or name.startswith('emplace_back') or name.startswith('append') \
       or name.startswith('erase') or name.startswith('insert') or name.startswith('reserve'):
        return 'cold', 'C++ container / libstdc++ instantiation'
    if name in ('inflate', 'deflate', 'inflateInit2_', 'deflateInit2_', 'inflateEnd', 'deflateEnd', 'inflateReset'):
        return 'cold', 'zlib'
    if name.startswith('Py') or name == 'bbwebsocket':
        return 'cold', 'CPython binding (not protocol)'
    if 'Unix' in name:
        return 'cold', 'Unix-domain sibling transport'
    if 'Channel' in name:
        return 'cold', 'message channel (send/recv plumbing)'
    if 'EventHandler' in name:
        return 'cold', 'EventHandler base'
    if 'TcpServer' in name or name in ('poll',):
        return 'cold', 'sibling transport method (listen side / other poll)'
    if name in ('EventLoop2', '~EventLoop2', 'run', 'add', 'del', 'idle', 'idle_proc', 'iter', 'exit',
                'current_time', 'setnonblock', 'setcloexec', 'print_stack', 'print_stack_abort',
                'is_myaddr', 'mkdir_p', 'dirname', 'entry'):
        return 'cold', 'event-loop / OS utility (not handshake)'
    return 'cold', 'unattributed helper (no handshake strings or state flags)'

rows = []
dup_map = {}
hi = [b for b in bs if b['idx'] >= 160]
hi_norm = {b['idx']: norm(b['body']) for b in hi}

for b in bs:
    idx = b['idx']
    name = b['name']
    if idx in IN_TABLE:
        rows.append((idx, b['addr'], name, b['nlines'], 'in_table', 'handshake_family ' + IN_TABLE[idx]))
        continue
    if int(b['addr'], 16) in FRAMES_ADDR:
        rows.append((idx, b['addr'], name, b['nlines'], 'cold',
                     FRAMES_ADDR[int(b['addr'], 16)] + ' (other family)'))
        continue
    if int(b['addr'], 16) in FRAGMENT_ADDR:
        rows.append((idx, b['addr'], name, b['nlines'], 'fragment', 'CRT startup stub'))
        continue
    if idx in (146, 147, 148, 149, 150):
        rows.append((idx, b['addr'], name, b['nlines'], 'fragment', 'unwind / CRT trampoline'))
        continue
    if idx in ALIAS_HELPERS:
        rows.append((idx, b['addr'], name, b['nlines'], 'alias', ALIAS_HELPERS[idx]))
        continue
    if is_plt(b):
        rows.append((idx, b['addr'], name, b['nlines'], 'fragment', 'PLT/import thunk'))
        continue
    if idx < 160 and b['nlines'] >= 20:
        # second decompilation pass: locate the equivalent high-address body
        A = norm(b['body'])
        best = None
        # 1) same symbol name, comparable size
        for h in hi:
            if h['name'] == name and abs(len(A) - len(hi_norm[h['idx']])) <= 20:
                best = (1.0, h)
                break
        # 2) content similarity
        if best is None:
            for h in hi:
                B = hi_norm[h['idx']]
                if abs(len(A) - len(B)) > 6:
                    continue
                r = difflib.SequenceMatcher(None, A, B, autojunk=False).ratio()
                if best is None or r > best[0]:
                    best = (r, h)
        if best and best[0] > 0.75:
            target = best[1]
            if target['idx'] in IN_TABLE:
                rows.append((idx, b['addr'], name, b['nlines'], 'alias',
                             'duplicate listing pass of %s (0x%s)' % (IN_TABLE[target['idx']], target['addr'])))
            elif int(target['addr'], 16) in FRAMES_ADDR:
                rows.append((idx, b['addr'], name, b['nlines'], 'cold',
                             'duplicate listing pass of ' + FRAMES_ADDR[int(target['addr'], 16)]))
            else:
                bk, why = reason_bucket(idx, target['name'], target['body'])
                rows.append((idx, b['addr'], name, b['nlines'], bk,
                             'duplicate listing pass of %s (0x%s)' % (target['name'][:40], target['addr'])))
            continue
    bk, why = reason_bucket(idx, name, b['body'])
    rows.append((idx, b['addr'], name, b['nlines'], bk, why))

rows.sort()
with open(os.path.join(HERE, 'buckets.tsv'), 'w', encoding='utf-8') as f:
    f.write('idx\taddr\tname\tlines\tbucket\treason\n')
    for r in rows:
        f.write('%d\t%s\t%s\t%d\t%s\t%s\n' % r)

cnt = {}
for r in rows:
    cnt[r[4]] = cnt.get(r[4], 0) + 1
total = len(rows)
frag = cnt.get('fragment', 0)
cov = {
    'total_functions': total,
    'fragment': frag,
    'in_table': cnt.get('in_table', 0),
    'alias': cnt.get('alias', 0),
    'cold': cnt.get('cold', 0),
    'effective_coverage': round((cnt.get('in_table', 0) + cnt.get('alias', 0) + cnt.get('cold', 0)) / (total - frag), 4),
}
json.dump(cov, open(os.path.join(HERE, 'coverage_counts.json'), 'w'), indent=1)
print(json.dumps(cov, indent=1))
