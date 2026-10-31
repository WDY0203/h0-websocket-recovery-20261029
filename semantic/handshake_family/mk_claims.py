import json, os
HERE = r'D:\tmp\semantic\H0WS\handshake_family'
P3 = {b['idx']: b for b in json.load(open(r'D:\tmp\semantic\H0WS\_work\p3.json', encoding='utf-8'))}
P2 = {b['idx']: b for b in json.load(open(r'D:\tmp\semantic\H0WS\_work\p2.json', encoding='utf-8'))}
ml = {m['id']: m for m in json.load(open(r'D:\tmp\semantic\H0WS\_work\member_lines.json'))}
t = json.load(open(os.path.join(HERE, 'table.json'), encoding='utf-8'))
IDX = {m['id']: m['i3'] for m in t['members']}
ADDR = {m['id']: m['py3'] for m in t['members']}

def line_of(mid, marker, nth=0):
    b = P3[IDX[mid]]
    lines = b['body'].split('\n')
    seen = 0
    for i, l in enumerate(lines):
        if marker in l:
            if seen == nth:
                return b['start'] + 1 + i
            seen += 1
    return None

# (member, claim_id, status, text, marker, test)
C = [
 ('M01','C01','confirmed','16-byte nonce is zero-filled, so the client key is the constant base64 of 16 zero bytes',"local_f8[0] = 0",'T1/B05, M01 key check'),
 ('M01','C02','confirmed','key is 24 chars with == padding',"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",'T2/R01'),
 ('M01','C03','confirmed','request line is GET / HTTP/1.1 (path is always /)','GET / HTTP/1.1',  'T2/R01 prefix'),
 ('M01','C04','confirmed','request is built by Buffer::appendf with one %s (the key)','Sec-WebSocket-Key: %s','T2/R01'),
 ('M01','C05','confirmed','no Host header is sent (RFC 6455 violation)',None,'M01 no Host'),
 ('M01','C06','confirmed','always offers Sec-WebSocket-Extensions: permessage-deflate','permessage-deflate','M01 extensions'),
 ('M01','C07','confirmed','after queueing the request it arms send_flag(+0x5a)=1 and installs two callbacks at +0x78/+0x80',"*(undefined1 *)(lVar18 + 0x5a) = 1",'impl: request+callbacks'),
 ('M02','C08','confirmed','waits for CRLFCRLF through WSConn::recv_pat (the frames_family M01 scanner)','\\r\\n\\r\\n','T3 head tests'),
 ('M02','C09','confirmed','the callback chain is copied into the heap closure (0x28 bytes) before recv_pat','operator_new(0x28)',None),
 ('M03','C10','confirmed','deflate is detected with memmem over the whole receive buffer, needle length 0x12','memmem','T3'),
 ('M03','C11','confirmed','successful negotiation sets WSConn+0x58 = 1 and creates inflate/deflate z_streams at +0x60/+0x68','inflateInit2_','impl establish_deflate'),
 ('M03','C12','confirmed','zlib windowBits is -15 (0xfffffff1), deflate level -1, memLevel 8, strategy 0','0xfffffff1','impl establish_deflate'),
 ('M03','C13','confirmed','the HTTP head is consumed by memmove(data, data+idx+4, end-(idx+4))','memmove','T3 head_end + keeps tail'),
 ('M03','C14','confirmed','the status line / Accept value / Upgrade header are never parsed: any reply containing CRLFCRLF ends the handshake',None,'T3 S01/S03'),
 ('M04','C15','confirmed','SHA-1 round constants 0x5a827999, 0x6ed9eba1, 0x8f1bbcdc(-0x70e44324), 0xca62c1d6 appear verbatim','0xca62c1d6','T4 all'),
 ('M04','C16','confirmed','five-word state is stored at state[0..4] and incremented a..e in that order','param_1[1] = ',"T4 (digest layout)"),
 ('M04','C17','inferred','Merkle-Damgard padding is the standard one; it is inlined into key_parse (1.4k-line member) rather than a separate function',None,'T4 H01-H03'),
 ('M05','C18','confirmed','appendf calls vsnprintf twice (size probe then write) and grows the vector by len+1','vsnprintf','M05'),
 ('M05','C19','confirmed','the trailing NUL written by vsnprintf is trimmed: size becomes old_len + n','std::__throw_length_error','M05 no NUL'),
 ('M06','C20','confirmed','address is resolved with inet_addr only; there is no getaddrinfo/DNS path',"inet_addr",'M06 plan'),
 ('M06','C21','confirmed','socket(2,1,0) = AF_INET,SOCK_STREAM; setnonblock + setcloexec; setsockopt(6,1,1) = TCP_NODELAY','setsockopt','M06 plan'),
 ('M06','C22','confirmed','connect() returning -1 is tolerated only for errno 0x73 (EINPROGRESS=115)','0x73','T2/M06 EINPROGRESS'),
 ('M06','C23','confirmed','any other connect error sets state 2, perror("connect"), close(fd) and calls the error callback with errno','perror("connect")','M06 ECONNREFUSED'),
 ('M07','C24','confirmed','the fd-adopting ctor sets state(+0x98)=1 with no socket()/connect() call, and builds TcpConn with empty host/name strings','setnonblock','M07'),
 ('M08','C25','confirmed','connection flags start as 0x58=1,0x59=1,0x5a=0,0x88=0 (recv open, send open, send idle, not reading)','this[0x88] = (TcpConn)0x0','T5'),
 ('M09','C26','confirmed','~TcpConn erases the fd from three registries, then close(fd), then frees the pending buffer','close(*(int *)(this + 0x40))','M09'),
 ('M10','C27','confirmed','recv_proc refuses to run unless +0x88 is set, prints "TcpConn: bogus recv: fd=%d" and clears both direction flags','bogus recv','T6/V01'),
 ('M10','C28','confirmed','read() is issued with a 0x8000 (32768) byte scratch buffer','0x8000','M10 chunk'),
 ('M10','C29','confirmed','EAGAIN (11) returns without any state change','0xb','T6/V02'),
 ('M10','C30','confirmed','EOF (read returns 0) clears recv_open and read_armed but leaves send_open set and fires NO callback','this[0x58] = (TcpConn)0x0','T6/V03'),
 ('M10','C31','confirmed','a non-EAGAIN read error prints perror("tcp recv") and clears recv_open, send_open and read_armed','perror("tcp recv")','T6/V04'),
 ('M11','C32','confirmed','send_proc refuses to run unless +0x5a is armed and prints "TcpConn: bogus send: fd=%d"','bogus send','T7/W01'),
 ('M11','C33','confirmed','with no pending buffer it clears send_open, calls shutdown(fd,1)=SHUT_WR, clears the arm flag and fires the write callback','shutdown(','T7/W02'),
 ('M11','C34','confirmed','a partial write memmoves the tail to the front and keeps the arm flag set','memmove','T7/W04'),
 ('M11','C35','confirmed','a hard write error other than EAGAIN falls through to the completed branch: the queue is discarded','__errno_location','T7/W06'),
 ('M12','C36','confirmed','state 0 probes getsockopt(1,4)=SO_ERROR on EPOLLOUT and moves to 1 (connected) or 2 (failed)','getsockopt','T8'),
 ('M12','C37','confirmed','poll returns reap==1 when both 0x58 and 0x59 are clear, or immediately in state 2','this_00[0x58]','T8/P06,P08'),
 ('M12','C38','confirmed','state 1 dispatches send_proc for bit 2 before recv_proc for bit 1','param_2 & 2U','T8/P05'),
 ('M13','C39','confirmed','TcpServer::poll accepts on the listen fd, sets nonblock/cloexec/TCP_NODELAY and calls the new-connection callback','accept(','M13'),
 ('M13','C40','confirmed','a non-listen fd is dispatched send_proc then recv_proc, and erased+deleted when both direction flags are clear','send_proc','T9'),
 ('M14','C41','confirmed','exit() wave 1 sets +0x88=1, warning "recv(): recv_flag != false" if it was already set','recv(): recv_flag != false','T12'),
 ('M14','C42','confirmed','wave 2 sets +0x5a=1, drops the pending buffer at +0x60 and warns "close(): send_flag != false"','close(): send_flag != false','T12'),
 ('M14','C43','confirmed','three callbacks are replaced (+0x90 close, +0x68 write-complete, +0xb0 idle)','0xb0','T12 callbacks=3'),
 ('M14','C44','confirmed','exit() sends no Close frame: no WSConn::send call exists in the body',None,'no send() in members.tsv role'),
 ('M15','C45','confirmed','~WSConn calls inflateEnd/deflateEnd only when +0x58 (negotiated) is set','inflateEnd','M15'),
 ('M15','C46','confirmed','three buffers (+0x50,+0x48,+0x40) are freed; the socket is not closed here',None,'M15'),
 ('M16','C47','confirmed','interest word = 0x11 (IN|HUP) / 0x15 (IN|OUT|HUP) / 0x4 (OUT) / 0',"uVar8 = 0x11",'T10'),
 ('M16','C48','confirmed','epoll_wait is called with maxevents = 1','epoll_wait','M16 maxevents'),
 ('M16','C49','confirmed','epoll timeout = (this+0x60)/1000 with 0x60 initialised to 1000000 (1 s)','1000000','M16 timeout'),
 ('M16','C50','confirmed','epoll_create1(0x80000) = EPOLL_CLOEXEC; failure -> perror + abort','epoll_create1','M16 cloexec'),
 ('M17','C51','confirmed','connect(addr,port) picks the Unix transport iff the address string is non-empty and starts with "/"',None,'T11'),
 ('M17','C52','confirmed','the event loop is run inline: PyLong_FromVoidPtr() is returned only after EventLoop2::run() returns','EventLoop2::run','M17 inline'),
 ('M17','C53','confirmed','py3 extracts the address with PyUnicode_AsUTF8 or PyBytes_AsString/Size depending on the type flags','PyUnicode_AsUTF8','M17 str_arg_kind'),
 ('M17','C54','inferred','the type test is one byte at ob_type+0xab, bit 0x08 -- CPython tp_flags bytes-subclass bit',None,'M17 str_arg_kind'),
 ('M18','C55','confirmed','disconnect(handle) closes the WSConn (send_flag path), runs the loop to drain, destroys it and returns 0','close(): send_flag != false','M18'),
 ('M18','C56','inferred','the Py_BuildValue format is a data byte (DAT_0011f3d1), so only the integer 0 payload is modelled',None,'M18 returns 0'),
]

out = []
for mid, cid, status, text, marker, test in C:
    ln = line_of(mid, marker) if marker else None
    b = P3[IDX[mid]]
    out.append({
        'id': cid,
        'member': mid,
        'addr': ADDR[mid],
        'lines': 'L%d-L%d' % (b['start'] + 1, b['end']),
        'line': ('L%d' % ln) if ln else None,
        'status': status,
        'claim': text,
        'evidence': ('py3 dump marker %r' % marker) if marker else 'structural (whole body re-read)',
        'test': test,
    })

doc = {'family': 'handshake_family', 'claims': out}
json.dump(doc, open(os.path.join(HERE, 'claims.json'), 'w', encoding='utf-8'), indent=1, ensure_ascii=False)
conf = sum(1 for c in out if c['status'] == 'confirmed')
inf = sum(1 for c in out if c['status'] == 'inferred')
print('claims=%d confirmed=%d inferred=%d (%.1f%%)' % (len(out), conf, inf, 100.0 * inf / len(out)))
for c in out[:6]:
    print(c['id'], c['member'], c['line'])
