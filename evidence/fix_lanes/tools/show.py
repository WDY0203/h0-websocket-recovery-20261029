import json, os, re, sys
CPPGEN = r"D:\tmp\cppgen"
def load(prefix):
    base = os.path.join(CPPGEN, prefix)
    rep = json.load(open(os.path.join(base, prefix + "_report.json"), "r", encoding="utf-8"))
    strict = json.load(open(os.path.join(base, prefix + "_strict.json"), "r", encoding="utf-8"))
    return base, rep, strict
def tu_path(base, name):
    for c in (os.path.join(base, "H0WS_tu", name), os.path.join(base, os.path.basename(base) + "_tu", name)):
        if os.path.exists(c): return c
    raise FileNotFoundError(name)
def show(prefix, idx, lo=1, hi=10**9):
    base, rep, strict = load(prefix)
    m = [x for x in rep["manifest"] if x["idx"] == idx][0]
    lines = open(tu_path(base, m["file"]), encoding="utf-8", errors="replace").read().split("\n")
    for i in range(m["line_start"], m["line_end"] + 1):
        rel = i - m["line_start"] + 1
        if lo <= rel <= hi:
            print("%4d| %s" % (rel, lines[i-1]))
if __name__ == "__main__":
    show(sys.argv[1], int(sys.argv[2]),
         int(sys.argv[3]) if len(sys.argv) > 3 else 1,
         int(sys.argv[4]) if len(sys.argv) > 4 else 10**9)
