import json, os, re, sys, collections
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
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
prefix = sys.argv[1]
base, rep, strict = load(prefix)
man = {m["idx"]: m for m in rep["manifest"]}
diag = json.load(open(os.path.join(FIXDIR, "work", "scan", prefix + "_diag.json"), encoding="utf-8"))
out = []
for r in diag:
    m = man[r["idx"]]
    lines = open(tu_path(base, m["file"]), encoding="utf-8", errors="replace").read().split("\n")
    for e in r["errs"]:
        mm = re.match(r"^(\d+):(\d+): (?:fatal )?error: (.*)$", e)
        if not mm: continue
        ul = int(mm.group(1)); col = int(mm.group(2)); msg = mm.group(3)
        src = lines[m["line_start"] - 1 + (ul - 2)] if (ul - 2) + m["line_start"] - 1 < len(lines) else "?"
        msg2 = re.sub(r"0x[0-9a-fA-F]{4,}", "0xA", msg)
        msg2 = re.sub(r"\[-fpermissive\]", "", msg2)
        out.append(dict(idx=r["idx"], name=r["name"], ul=ul, col=col, msg=msg2, src=src))
# group by msg2 + crude shape of src
g = collections.Counter()
for o in out:
    g[(o["msg"],)] += 1
for k, v in g.most_common():
    print("%5d  %s" % (v, k[0]))
json.dump(out, open(os.path.join(FIXDIR, "work", "scan", prefix + "_errlines.json"), "w", encoding="utf-8"), indent=1, ensure_ascii=False)
