"""Statistics about the failure modes before the repair."""
import os, re, sys, json, collections
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A

def norm(msg):
    m = re.sub(r"0x[0-9a-fA-F]{4,}", "0xA", msg)
    m = re.sub(r"'(?:[A-Za-z_]\w*)(?:\[\d+\])?'", lambda x: x.group(0), m)
    return m.strip()

def baseline(prefix):
    fl = A.fail_list(prefix)
    head = '#include "%s_shim.hpp"\n' % prefix
    parts = [head]
    lm = {}
    ln = head.count("\n")
    for f in fl:
        body = A.rule_renames(f["body"])
        for bl, t in enumerate(body.split("\n"), 1):
            parts.append(t + "\n")
            ln += 1
            lm[ln] = f["idx"]
    path = os.path.join(A.gendir(prefix), "_baseline.cpp")
    open(path, "w", encoding="utf-8", newline="\n").write("".join(parts))
    rc, err = A.compile_unit(path, prefix)
    out = collections.defaultdict(set)
    for ul, col, msg in A.parse_diags(err):
        if ul in lm:
            out[lm[ul]].add(norm(msg))
    return {f["idx"]: f["name"] for f in fl}, out

if __name__ == "__main__":
    res = {}
    for p in ("H0WS2", "H0WS3"):
        names, errs = baseline(p)
        res[p] = (names, errs)
        print("%s baseline: %d failing funcs, %d distinct messages"
              % (p, len(errs), len({m for s in errs.values() for m in s})))
    n2, e2 = res["H0WS2"]
    n3, e3 = res["H0WS3"]
    s2 = set(n2.values()); s3 = set(n3.values())
    print("shared function names among the failures: %d / %d / %d"
          % (len(s2 & s3), len(s2), len(s3)))
    allmsg2 = collections.Counter(m for s in e2.values() for m in s)
    allmsg3 = collections.Counter(m for s in e3.values() for m in s)
    common = set(allmsg2) & set(allmsg3)
    print("distinct failure modes: WS2=%d WS3=%d common=%d"
          % (len(allmsg2), len(allmsg3), len(common)))
    print("total diagnostics: WS2=%d WS3=%d" % (sum(allmsg2.values()), sum(allmsg3.values())))
    json.dump({"ws2": sorted(allmsg2), "ws3": sorted(allmsg3)},
              open(os.path.join(FIXDIR, "work", "modes.json"), "w", encoding="utf-8"),
              indent=1)
    for m in sorted(common, key=lambda x: -allmsg2[x])[:200]:
        print("  %4d/%-4d %s" % (allmsg2[m], allmsg3[m], m[:110]))
