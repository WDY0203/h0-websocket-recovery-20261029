import sys, os, json, re, collections
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
CPPGEN = r"D:\tmp\cppgen"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A

prefix = sys.argv[1]
only = sys.argv[2] if len(sys.argv) > 2 else None
fl = A.fail_list(prefix)
d = A.gendir(prefix)
for f in fl:
    p = os.path.join(d, "f%03d.cpp" % f["idx"])
    rc, err = A.compile_unit(p, prefix)
    if rc == 0:
        continue
    if only and str(f["idx"]) != only:
        continue
    ds = A.parse_diags(err)
    body = open(p, encoding="utf-8").read().split("\n")
    print("=== IDX %d %s" % (f["idx"], f["name"][:60]))
    last = None
    for ul, col, msg in ds:
        src = body[ul - 1] if 0 < ul <= len(body) else "?"
        if (ul, msg) != last:
            print("  L%-5d c%-3d %s" % (ul - 1, col, msg[:110]))
            print("        |%s" % src.strip()[:190])
        last = (ul, msg)
