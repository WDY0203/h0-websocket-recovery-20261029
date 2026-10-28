import os, re, sys, json, collections
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A

for p in ("H0WS2", "H0WS3"):
    base, rep, strict = A.load(p)
    man = {m["idx"]: m for m in rep["manifest"]}
    rows = [l.split("\t") for l in open(os.path.join(FIXDIR, p, "remove.txt"),
                                        encoding="utf-8").read().splitlines() if l.strip()]
    txt = open(os.path.join(FIXDIR, p, "fixes.cpp"), encoding="utf-8").read()
    defined = re.findall(r"^// IDX (\d+)\s+([0-9a-f]+)\s+(.*)$", txt, re.M)
    ok = True
    if len(rows) != 113:
        print(p, "remove.txt row count", len(rows)); ok = False
    if len(defined) != 113:
        print(p, "fixes.cpp banner count", len(defined)); ok = False
    # every remove.txt row must match the manifest exactly
    for f, s, e, addr, name in rows:
        idx = None
        for i, m in man.items():
            if m["name"] == name:
                idx = i; break
        if idx is None:
            print(p, "name not in manifest:", name); ok = False; continue
        m = man[idx]
        if (m["file"], str(m["line_start"]), str(m["line_end"])) != (f, s, e):
            print(p, "line range mismatch", name, (f, s, e), m["file"], m["line_start"], m["line_end"]); ok = False
        if not re.search(r"^// IDX %d\s+%s\s" % (idx, addr), txt, re.M):
            print(p, "banner missing", idx, name); ok = False
    # duplicate names
    dup = [k for k, v in collections.Counter(r[4] for r in rows).items() if v > 1]
    if dup:
        print(p, "duplicate names in remove.txt:", dup); ok = False
    # every function definition in fixes.cpp must be one of the 113
    orig = {man[i]["orig"] for i in man}
    for idx, addr, nm in defined:
        if nm.strip() not in orig and ("rea_" + nm.strip()) not in orig:
            print(p, "extra definition", idx, nm); ok = False
    print("%s: remove.txt <-> manifest <-> fixes.cpp consistent: %s" % (p, ok))
