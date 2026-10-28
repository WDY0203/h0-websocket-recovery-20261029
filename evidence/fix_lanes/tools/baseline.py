import os, sys, re, collections
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A

for p in sys.argv[1:]:
    fl = A.fail_list(p)
    head = '#include "%s_shim.hpp"\n' % p
    parts = [head]
    lm = {}
    ln = head.count("\n")
    for f in fl:
        body = A.rule_renames(f["body"])
        for bl, t in enumerate(body.split("\n"), 1):
            parts.append(t + "\n")
            ln += 1
            lm[ln] = f["idx"]
    path = os.path.join(A.gendir(p), "_base.cpp")
    open(path, "w", encoding="utf-8", newline="\n").write("".join(parts))
    rc, err = A.compile_unit(path, p)
    ds = A.parse_diags(err)
    bad = {lm[u] for u, c, m in ds if u in lm}
    print("%s: pristine+rename -> %d/%d still failing, %d diagnostics"
          % (p, len(bad), len(fl), len(ds)))
    clean = [f["idx"] for f in fl if f["idx"] not in bad]
    print("   fixed by the FUN_ -> rea_FUN_ rename alone:", clean)
