import re, sys

P = r'D:\tmp\H0WS2_all_decompiled.txt'
S = open(P, encoding='utf-8', errors='replace').read()
PARTS = re.split(r'(?m)^===== IDX (\d+) ([0-9a-f]+) (.*?) =====$', S)
# build blocks with global line numbers
BLOCKS = []
line = 1
pos = 0
for i in range(1, len(PARTS), 4):
    idx = int(PARTS[i]); addr = PARTS[i+1]; name = PARTS[i+2]; body = PARTS[i+3]
    start_line = line
    nlines = body.count('\n')
    BLOCKS.append((idx, addr, name, start_line, body))
    line += nlines + 1

BYIDX = {b[0]: b for b in BLOCKS}
BYADDR = {int(b[1], 16): b for b in BLOCKS}


def show(key, lo=None, hi=None):
    if isinstance(key, int) and key in BYIDX:
        b = BYIDX[key]
    else:
        b = BYADDR[int(key, 16)] if isinstance(key, str) else None
    if b is None:
        print("not found"); return
    idx, addr, name, sl, body = b
    lines = body.split('\n')
    if lo is None:
        lo, hi = 1, len(lines)
    print("### IDX %d 0x%s %s  (global lines %d..%d)" % (idx, addr, name, sl, sl+len(lines)-1))
    for n in range(lo, min(hi, len(lines)) + 1):
        print("%5d: %s" % (sl + n - 1, lines[n-1]))


if __name__ == '__main__':
    a = sys.argv[1]
    lo = int(sys.argv[2]) if len(sys.argv) > 2 else None
    hi = int(sys.argv[3]) if len(sys.argv) > 3 else None
    key = int(a) if a.isdigit() else a
    show(key, lo, hi)
