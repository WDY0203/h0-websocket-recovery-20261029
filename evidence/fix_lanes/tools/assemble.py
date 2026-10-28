import os, re, sys, json
FIXDIR = r"D:\tmp\semantic\H0WS\fix"
sys.path.insert(0, os.path.join(FIXDIR, "tools"))
import autofix as A
import structural as S

def assemble(prefix, outdir):
    fl = A.fail_list(prefix)
    d = A.gendir(prefix)
    bodies = []
    rows = []
    for f in fl:
        txt = open(os.path.join(d, "f%03d.cpp" % f["idx"]), encoding="utf-8").read()
        body = txt.split("\n")
        # drop include + prelude: the body starts at the first "// ---" marker
        start = next(i for i, l in enumerate(body) if l.startswith("// ---"))
        body = "\n".join(body[start:]).rstrip() + "\n"
        # address out of the banner:  // IDX 95  00107450  WSConn__recv
        m = re.search(r"^// IDX \d+\s+([0-9a-fA-F]+)", body, re.M)
        addr = m.group(1) if m else ""
        bodies.append(body)
        rows.append((f["file"], f["start"], f["end"], addr, f["name"]))
    os.makedirs(outdir, exist_ok=True)
    with open(os.path.join(outdir, "fixes.cpp"), "w", encoding="utf-8", newline="\n") as fh:
        fh.write('// Type-level repairs for the %s reconstruction.\n' % prefix)
        fh.write('// Originals are listed in remove.txt and must be deleted from the TUs.\n')
        fh.write('#include "%s_shim.hpp"\n' % prefix)
        fh.write(S.PRELUDE)
        fh.write("\n")
        fh.write("\n".join(bodies))
    with open(os.path.join(outdir, "remove.txt"), "w", encoding="utf-8", newline="\n") as fh:
        for r in rows:
            fh.write("%s\t%d\t%d\t%s\t%s\n" % r)
    print("%s: wrote %d functions" % (prefix, len(bodies)))

if __name__ == "__main__":
    assemble(sys.argv[1], sys.argv[2])
