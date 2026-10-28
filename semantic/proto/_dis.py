import sys

LINES = open(r'D:\tmp\semantic\H0WS\proto\_dis.txt', encoding='utf-8', errors='replace').read().split('\n')
INS = []
for ln in LINES:
    p = ln.split('\t')
    if len(p) >= 2:
        try:
            a = int(p[0].strip().rstrip(':'), 16)
        except ValueError:
            continue
        INS.append((a, p[1].strip() if len(p) > 1 else ''))


def show(lo, hi):
    for a, t in INS:
        if lo <= a <= hi:
            print('%08x  %s' % (a, t))


def find(pat, ctx=0):
    for i, (a, t) in enumerate(INS):
        if pat in t:
            print('--- %08x ---' % a)
            for j in range(max(0, i - ctx), min(len(INS), i + ctx + 1)):
                print('%08x  %s' % INS[j])


if __name__ == '__main__':
    if sys.argv[1] == 'r':
        show(int(sys.argv[2], 16), int(sys.argv[3], 16))
    else:
        find(sys.argv[2], int(sys.argv[3]) if len(sys.argv) > 3 else 0)
