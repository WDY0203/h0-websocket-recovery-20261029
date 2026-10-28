"""Verify that the repairs only changed types: control flow, labels and the
numeric literals of each function must be unchanged (modulo the documented
opaque-aggregate field offsets)."""
import os, re, sys, json, collections
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A

# offsets introduced on purpose by the sockaddr/stat/epoll_event/sigaction rewrites
DOCUMENTED = {"0x2", "0x4", "0x12", "0x78", "0xc", "0x90", "0x98", "0x10", "0x0",
              "32", "0"}
PER_FUNC = {232: {"8"}}

NUM = re.compile(r"\b(0x[0-9a-fA-F]+|\d+)\b")
KW = {"if": r"\bif\s*\(", "while": r"\bwhile\s*\(", "for": r"\bfor\s*\(",
      "do": r"\bdo\s*\{", "goto": r"\bgoto\b", "return": r"\breturn\b",
      "switch": r"\bswitch\s*\(", "case": r"\bcase\b", "else": r"\belse\b"}

def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    t = re.sub(r"//[^\n]*", "", t)
    return t

def strip_decl_sizes(t):
    out = []
    for line in t.split("\n"):
        s = line.strip()
        if s.endswith("];") and "=" not in s and "(" not in s:
            line = re.sub(r"\[\d+\]", "[]", line)
        out.append(line)
    return "\n".join(out)

def stats(t):
    t = strip_decl_sizes(strip_comments(t))
    nums = collections.Counter(NUM.findall(t))
    lbl = set(re.findall(r"\bLAB_[0-9a-f]+\b", t))
    kws = {k: len(re.findall(v, t)) for k, v in KW.items()}
    return nums, lbl, kws

def check(prefix):
    fl = A.fail_list(prefix)
    problems = []
    for f in fl:
        nums0, lbl0, kw0 = stats(f["body"])
        p = os.path.join(FIXDIR, prefix, "fixes.cpp")
    txt = open(p, encoding="utf-8").read()
    # split fixes.cpp back into functions using the IDX banners
    parts = re.split(r"^// IDX (\d+)\s", txt, flags=re.M)
    fixed = {}
    for i in range(1, len(parts) - 1, 2):
        chunk = re.sub(r"^\s*[0-9a-fA-F]{8}[^\n]*\n", "", parts[i + 1], count=1)
        chunk = re.sub(r"^-+\n", "", chunk, count=1)
        fixed[int(parts[i])] = chunk
    for f in fl:
        if f["idx"] not in fixed:
            problems.append((f["idx"], f["name"], "missing from fixes.cpp"))
            continue
        nums0, lbl0, kw0 = stats(f["body"])
        nums1, lbl1, kw1 = stats(fixed[f["idx"]])
        d = []
        if lbl0 != lbl1:
            d.append("labels %s -> %s" % (sorted(lbl0 - lbl1), sorted(lbl1 - lbl0)))
        for k in KW:
            if kw0[k] != kw1[k]:
                d.append("%s %d->%d" % (k, kw0[k], kw1[k]))
        extra = {n: c for n, c in (nums1 - nums0).items()
                 if n not in DOCUMENTED and n not in PER_FUNC.get(f["idx"], ())}
        lost = dict(nums0 - nums1)
        if extra:
            d.append("added literals %s" % extra)
        if lost:
            d.append("lost literals %s" % lost)
        if d:
            problems.append((f["idx"], f["name"], "; ".join(d)))
    print("== %s: %d functions checked, %d with differences" % (prefix, len(fl), len(problems)))
    for p_ in problems:
        print("  IDX %-4d %-55s %s" % (p_[0], p_[1][:55], p_[2]))
    return problems

if __name__ == "__main__":
    for pref in sys.argv[1:]:
        check(pref)
