import sys, os, json, re, collections
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
CPPGEN = r"D:\tmp\cppgen"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A

prefix = sys.argv[1]
fl = A.fail_list(prefix)
d = A.gendir(prefix)
rows = []
for f in fl:
    p = os.path.join(d, "f%03d.cpp" % f["idx"])
    rc, err = A.compile_unit(p, prefix)
    if rc == 0:
        continue
    ds = A.parse_diags(err)
    rows.append((f, ds))
print("%s: %d failing" % (prefix, len(rows)))
for f, ds in rows:
    print("--- IDX %d %s (%s:%d-%d) : %d errors" % (f["idx"], f["name"], f["file"], f["start"], f["end"], len(ds)))
    seen = collections.Counter()
    for ul, col, msg in ds:
        seen[msg] += 1
    for k, v in seen.most_common(8):
        print("    x%-3d %s" % (v, k))
