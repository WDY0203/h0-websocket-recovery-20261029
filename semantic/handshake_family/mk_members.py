import json, os
HERE = r'D:\tmp\semantic\H0WS\handshake_family'
ml = {m['id']: m for m in json.load(open(r'D:\tmp\semantic\H0WS\_work\member_lines.json'))}
P2 = {b['idx']: b for b in json.load(open(r'D:\tmp\semantic\H0WS\_work\p2.json', encoding='utf-8'))}
P3 = {b['idx']: b for b in json.load(open(r'D:\tmp\semantic\H0WS\_work\p3.json', encoding='utf-8'))}
t = json.load(open(os.path.join(HERE, 'table.json'), encoding='utf-8'))

ROLE = {m['id']: m['role'] for m in t['members']}
FUNC = {m['id']: m['func'] for m in t['members']}

rows = []
for m in t['members']:
    mid = m['id']
    L = ml[mid]
    rows.append((mid, FUNC[mid], FUNC[mid], L['i2'], m['py2'], L['i3'], m['py3'],
                 hex(m['delta']), P2[L['i2']]['nlines'], P3[L['i3']]['nlines'],
                 'yes' if L['norm_same'] else 'NO',
                 L['raw_diff'], ROLE[mid]))

with open(os.path.join(HERE, 'members.tsv'), 'w', encoding='utf-8') as f:
    f.write('id\tfun\tfunc\tpy2_idx\tpy2_addr\tpy3_idx\tpy3_addr\taddr_delta\t'
            'py2_lines\tpy3_lines\tnorm_identical\traw_diff_lines\trole\n')
    for r in rows:
        f.write('\t'.join(str(x) for x in r) + '\n')
        if r[0] == 'M18':
            # cross-family aliases: covered by frames_family, not re-implemented here
            f.write('A01\taccept\tWSConn::accept\t216\t0x10f940\t217\t0x10fa40\t0x100\t107\t107\tyes\t4\t'
                    'ALIAS -> frames_family M14 (server-side handshake entry)\n')
            f.write('A02\tkey_parse\tFUN_00112c60\t232\t0x112b60\t232\t0x112c60\t0x100\t1423\t1423\tyes\t148\t'
                    'ALIAS -> frames_family M14 (Sec-WebSocket-Key extraction + SHA1/base64 Accept + 101)\n')
print(open(os.path.join(HERE, 'members.tsv'), encoding='utf-8').read())
