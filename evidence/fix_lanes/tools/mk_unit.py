#> -*- coding: utf-8 -*-
"""Extract per-function standalone TUs for the failing functions and compile them."""
import json, os, re, subprocess, sys, collections

FIXDIR = r"D:\tmp\semantic\H0WS\fix"
CPPGEN = r"D:\tmp\cppgen"
GXX = r"C:\Users\w2345\AppData\Local\Microsoft\WinGet\Packages\BrechtSanders.WinLibs.POSIX.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe\mingw64\bin\g++.exe"

def load(prefix):
    base = os.path.join(CPPGEN, prefix)
    rep = json.load(open(os.path.join(base, prefix + "_report.json"), "r", encoding="utf-8"))
    strict = json.load(open(os.path.join(base, prefix + "_strict.json"), "r", encoding="utf-8"))
    return base, rep, strict

def file_lines(base, name):
    for cand in (os.path.join(base, "H0WS_tu", name),
                 os.path.join(base, os.path.basename(base) + "_tu", name),
                 os.path.join(base, name)):
        if os.path.exists(cand):
            return open(cand, "r", encoding="utf-8", errors="replace").read().split("\n")
    raise FileNotFoundError(name)

def funcs(prefix, only_fail=True):
    base, rep, strict = load(prefix)
    out = []
    cache = {}
    for m in rep["manifest"]:
        st = strict.get(str(m["idx"]), "unknown")
        if only_fail and st != "fail":
            continue
        f = m["file"]
        if f not in cache:
            cache[f] = file_lines(base, f)
        lines = cache[f]
        body = "\n".join(lines[m["line_start"] - 1: m["line_end"]])
        out.append(dict(idx=m["idx"], name=m["name"], orig=m["orig"], file=f,
                        start=m["line_start"], end=m["line_end"], body=body, status=st))
    return out

def write_unit(path, prefix, body):
    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write('#include "%s_shim.hpp"\n' % prefix)
        fh.write(body)
        fh.write("\n")

def compile_unit(path, prefix):
    cmd = [GXX, "-std=gnu++17", "-fsyntax-only", "-fno-diagnostics-color",
           "-I", os.path.join(CPPGEN, prefix), path]
    p = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    return p.returncode, p.stderr

def diag_key(line):
    # normalise a diagnostic into a coarse signature
    m = re.match(r"^(.*?):(\d+):(\d+): (error|warning): (.*)$", line)
    if not m:
        return None
    msg = m.group(5)
    msg = re.sub(r"0x[0-9a-fA-F]+", "0xX", msg)
    msg = re.sub(r"'[^']*'", "'T'", msg)
    msg = re.sub(r"\b\d+\b", "N", msg)
    return msg.strip()

if __name__ == "__main__":
    prefix = sys.argv[1]
    tag = sys.argv[2] if len(sys.argv) > 2 else "scan"
    d = os.path.join(FIXDIR, "work", tag, prefix)
    os.makedirs(d, exist_ok=True)
    fl = funcs(prefix)
    results = []
    keys = collections.Counter()
    for f in fl:
        p = os.path.join(d, "f%03d.cpp" % f["idx"])
        write_unit(p, prefix, f["body"])
        rc, err = compile_unit(p, prefix)
        first_line = f["body"].split("\n")[0]
        errs = [l for l in err.split("\n") if re.search(r": (fatal )?error: ", l)]
        errs = [re.sub(r"^.*?f\d+\.cpp:", "", e) for e in errs]
        results.append(dict(idx=f["idx"], name=f["name"], file=f["file"], start=f["start"],
                            end=f["end"], sig=first_line, ok=(rc == 0), nerr=len(errs),
                            errs=errs[:8]))
        if rc != 0:
            for e in errs:
                k = diag_key("x:1:1: " + e) if False else None
                k = re.sub(r"^\d+:\d+: error: ", "", e)
                k = re.sub(r"0x[0-9a-fA-F]{4,}", "0xA", k)
                k = re.sub(r"\[-fpermissive\]", "", k)
                keys[k.strip()] += 1
    json.dump(results, open(os.path.join(FIXDIR, "work", tag, prefix + "_diag.json"), "w",
                            encoding="utf-8"), indent=1, ensure_ascii=False)
    tot = sum(1 for r in results if r["ok"])
    print("%s: %d/%d compile clean individually" % (prefix, tot, len(results)))
    for k, v in keys.most_common(60):
        print("%5d  %s" % (v, k))
