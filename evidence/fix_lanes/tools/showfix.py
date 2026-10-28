import sys, os, json, re
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
CPPGEN = r"D:\tmp\cppgen"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A

prefix = sys.argv[1]
idx = int(sys.argv[2])
lo = int(sys.argv[3]) if len(sys.argv) > 3 else 1
hi = int(sys.argv[4]) if len(sys.argv) > 4 else 10 ** 9
p = os.path.join(A.gendir(prefix), "f%03d.cpp" % idx)
lines = open(p, encoding="utf-8").read().split("\n")[1:]
for i, t in enumerate(lines, 1):
    if lo <= i <= hi:
        print("%4d| %s" % (i, t))
