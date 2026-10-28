"""Error-driven type-cast inserter + generic rules for the H0WS* decompiled TUs.

Only type-level edits: casts, identifier renames, opaque-aggregate byte access,
declared local types.  Control flow / offsets / constants are never touched.
"""
import json, os, re, subprocess, sys, collections

FIXDIR = r"D:\tmp\semantic\H0WS\fix"
CPPGEN = r"D:\tmp\cppgen"
GXX = (r"C:\Users\w2345\AppData\Local\Microsoft\WinGet\Packages"
       r"\BrechtSanders.WinLibs.POSIX.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe"
       r"\mingw64\bin\g++.exe")

def load(prefix):
    base = os.path.join(CPPGEN, prefix)
    rep = json.load(open(os.path.join(base, prefix + "_report.json"), encoding="utf-8"))
    strict = json.load(open(os.path.join(base, prefix + "_strict.json"), encoding="utf-8"))
    return base, rep, strict

def tu_path(base, name):
    for c in (os.path.join(base, "H0WS_tu", name),
              os.path.join(base, os.path.basename(base) + "_tu", name)):
        if os.path.exists(c):
            return c
    raise FileNotFoundError(name)

def fail_list(prefix):
    base, rep, strict = load(prefix)
    out, cache = [], {}
    for m in rep["manifest"]:
        if strict.get(str(m["idx"])) != "fail":
            continue
        f = m["file"]
        if f not in cache:
            cache[f] = open(tu_path(base, f), encoding="utf-8", errors="replace").read().split("\n")
        body = "\n".join(cache[f][m["line_start"] - 1:m["line_end"]]).rstrip()
        out.append(dict(idx=m["idx"], name=m["name"], orig=m["orig"], file=f,
                        start=m["line_start"], end=m["line_end"], body=body))
    return out

def gendir(p):
    return os.path.join(FIXDIR, "work", "fix", p)

# --------------------------------------------------------------- rules
PTR_BROKEN = "PTR__M_emplace_back_aux<std__pair<EventHandler*,std__function<void()>>>_00325230"

def rule_renames(t):
    t = re.sub(r"(?<![\w])FUN_([0-9a-f]{8})(?![\w])", r"rea_FUN_\1", t)
    t = re.sub(r"PTR__M_emplace_back_aux<\S*?_[0-9a-f]{8}\b", "PTR__M_emplace_back_aux", t)
    return t

RET_RE = re.compile(r"^([A-Za-z_][\w \t\*]*?)\s+(\**[A-Za-z_]\w*)\s*\(", re.M)

def rule_bare_return(t):
    """`return;` inside a non-void function -> `return 0;` (same 'no value' semantics)."""
    m = RET_RE.search(t)
    if not m:
        return t
    ret = m.group(1).strip()
    if ret == "void":
        return t
    return re.sub(r"(\n[ \t]*)return;", r"\1return 0;", t)

FPTR_LOCAL = re.compile(r"^(\s*)undefined8 (\w+);$", re.M)

def rule_fptr(t):
    """A local that the body dereferences as a function pointer must be `code *`."""
    names = set(re.findall(r"\(\*(\w+)\)\s*\(", t))
    for n in list(names):
        if not re.search(r"^[ \t]*undefined8 %s;[ \t]*$" % re.escape(n), t, re.M):
            names.discard(n)
    for n in names:
        t = re.sub(r"^(\s*)undefined8 %s;$" % re.escape(n), r"\1code *%s;" % n, t, flags=re.M)
    return t

def is_ptr_type(t):
    return t.strip().endswith("*")

OPCH = set("+-*/%<>&|^?:=")

def looks_like_type(s):
    s = s.strip()
    if not s:
        return False
    if s.endswith("*") or s.endswith("&"):
        return True
    words = set(re.findall(r"[A-Za-z_]\w*", s))
    kw = {"void", "char", "int", "long", "short", "unsigned", "signed", "float",
          "double", "const", "struct", "bool"}
    return bool(words) and words <= kw

def expr_end(line, start):
    i, n = start, len(line)
    depth = 0
    prev = None
    stack = []           # text of open groups, to detect casts
    while i < n:
        c = line[i]
        if c in " \t":
            i += 1
            continue
        if c == '"' or c == "'":
            q = c
            i += 1
            while i < n and line[i] != q:
                if line[i] == "\\":
                    i += 1
                i += 1
            i += 1
            prev = "val"
            continue
        if c in "([{":
            depth += 1
            stack.append(i)
            i += 1
            prev = "op"
            continue
        if c in ")]}":
            if depth == 0:
                return i
            depth -= 1
            op = stack.pop()
            prev = "op" if (c == ")" and looks_like_type(line[op + 1:i])) else "val"
            i += 1
            continue
        if depth == 0:
            if c in ",;":
                return i
            if c == "-" and i + 1 < n and line[i + 1] == ">":
                i += 2
                prev = "op"
                continue
            if c == ":" and i + 1 < n and line[i + 1] == ":":
                i += 2
                prev = "op"
                continue
            if c in OPCH:
                if prev == "val":
                    return i
                i += 1
                prev = "op"
                continue
            if c.isalnum() or c == "_":
                j = i
                while j < n and (line[j].isalnum() or line[j] == "_"):
                    j += 1
                i = j
                prev = "val"
                continue
            i += 1
            if c == ".":
                prev = "op"
            continue
        i += 1
    return n

def expand_callee(line, start):
    """`name(...)` : if start is the call's '(', move left to the callee start."""
    if start >= len(line) or line[start] != "(":
        return start
    j = start
    while j > 0 and line[j - 1] in " \t":
        j -= 1
    k = j
    while k > 0 and (line[k - 1].isalnum() or line[k - 1] == "_"):
        k -= 1
    if k == j:
        return start
    while True:
        m = k
        if k >= 2 and line[k - 2:k] in ("->", "::"):
            m = k - 2
        elif k >= 1 and line[k - 1] == ".":
            m = k - 1
        else:
            return k
        e = m
        while e > 0 and (line[e - 1].isalnum() or line[e - 1] == "_"):
            e -= 1
        if e == m:
            return k
        k = e

def wrap_cast(line, col, to_type):
    if to_type is None:
        return None
    to_type = to_type.strip()
    if not to_type or "[" in to_type or to_type == "void":
        return None
    start = col - 1
    if start >= len(line):
        return None
    end = expr_end(line, start)
    while end > start and line[end - 1] in " \t":
        end -= 1
    if end <= start:
        return None
    expr = line[start:end]
    if expr.startswith("(") and expr.endswith(")") and expr[1:2] == "(":
        pass
    bridge = ""
    if "float" not in to_type and "double" not in to_type:
        bridge = "(uintptr_t)"
    return line[:start] + "(" + to_type + ")" + bridge + "(" + expr + ")" + line[end:]

def split_types(msg):
    m = re.search(r"from '([^']*)'(?:\s*\{aka '[^']*'\})?\s+to '([^']*)'(?:\s*\{aka '[^']*'\})?", msg)
    if m:
        return m.group(1).strip(), m.group(2).strip()
    m = re.search(r"convert '([^']*)'(?:\s*\{aka '[^']*'\})?\s+to '([^']*)'(?:\s*\{aka '[^']*'\})?", msg)
    if m:
        return m.group(1).strip(), m.group(2).strip()
    return None, None

def compile_unit(path, prefix):
    cmd = [GXX, "-std=gnu++17", "-fsyntax-only", "-fdiagnostics-color=never",
           "-I", os.path.join(CPPGEN, prefix), path]
    p = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    return p.returncode, re.sub(r"\x1b\[[0-9;]*m", "", p.stderr)

DIAG_RE = re.compile(r":(\d+):(\d+): (?:fatal )?error: (.*)$")

def parse_diags(err):
    out = []
    for l in err.split("\n"):
        m = DIAG_RE.search(l)
        if m:
            out.append((int(m.group(1)), int(m.group(2)),
                        re.sub(r"\[-fpermissive\]", "", m.group(3)).strip()))
    return out

def find_assign(line):
    depth = 0
    for i, c in enumerate(line):
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
        elif c == "=" and depth == 0:
            p = line[i - 1] if i else ""
            nx = line[i + 1] if i + 1 < len(line) else ""
            if p not in "=!<>+-*/%&|^" and nx != "=":
                return i
    return -1

def left_operand_start(line, pos):
    """Start index of the operand that ends just before `pos`."""
    i = pos
    while True:
        while i > 0 and line[i - 1] in " \t":
            i -= 1
        if i == 0:
            return 0
        c = line[i - 1]
        if c in ")]":
            open_c = "(" if c == ")" else "["
            d = 0
            j = i - 1
            while j >= 0:
                if line[j] == c:
                    d += 1
                elif line[j] == open_c:
                    d -= 1
                    if d == 0:
                        break
                j -= 1
            i = max(j, 0)
            continue
        if c.isalnum() or c == "_":
            j = i
            while j > 0 and (line[j - 1].isalnum() or line[j - 1] == "_"):
                j -= 1
            i = j
            continue
        if c in "&*":
            i -= 1
            continue
        return i

def is_unary_pos(line, i):
    """True if the operator at index i sits where a unary operator is expected."""
    j = i - 1
    while j >= 0 and line[j] in " \t":
        j -= 1
    if j < 0:
        return True
    return line[j] in "(,=+-*/%&|^!?<>:{["

def patch_round(body, diags):
    """Apply cast insertions for one round of diagnostics. Returns (body, n_patched)."""
    lines = body.split("\n")
    patched = 0
    for ul, col, msg in sorted(diags, key=lambda d: (-d[0], -d[1])):
        li = ul - 1                      # diags carry body-relative line numbers
        if li < 0 or li >= len(lines):
            continue
        line = lines[li]
        src, dst = split_types(msg)
        if not (("invalid conversion" in msg) or ("cannot convert" in msg) or
                ("loses precision" in msg)):
            continue
        if "loses precision" in msg:
            m = re.search(r"to '([^']*)'", msg)
            dst = m.group(1).strip() if m else None
        if dst is None:
            continue
        # where does the offending expression start?
        start = col - 1
        if "in assignment" in msg or "initializing" in msg:
            ai = find_assign(line)
            if ai >= 0:
                start = ai + 1
        while start < len(line) and line[start] in " \t":
            start += 1
        if start >= len(line):
            continue
        start = expand_callee(line, start)
        if "loses precision" in msg:
            m = re.match(r"\(([^()]*)\)", line[start:])
            if not m:
                continue
            ins = start + m.end()
            new = line[:ins] + "(uintptr_t)" + line[ins:]
        elif line[start] in "+-*/%|&^":
            start = left_operand_start(line, start)
            new = wrap_cast(line, start + 1, dst)
        elif line.startswith("(" + dst + ")", start):        # already patched
            continue
        else:
            new = wrap_cast(line, start + 1, dst)
        if new is not None and new != line:
            lines[li] = new
            patched += 1
    return "\n".join(lines), patched

def build_combined(prefix, bodies, path):
    import structural as S
    head = '#include "%s_shim.hpp"\n' % prefix + S.PRELUDE + "\n"
    parts = [head]
    linemap = {}          # unit line -> (idx, body line no)
    ln = head.count("\n")
    for idx in sorted(bodies):
        for bl, text in enumerate(bodies[idx].split("\n"), 1):
            parts.append(text + "\n")
            ln += 1
            linemap[ln] = (idx, bl)
    open(path, "w", encoding="utf-8", newline="\n").write("".join(parts))
    return linemap

def run(prefix, rounds=10, verbose=True):
    d = gendir(prefix)
    os.makedirs(d, exist_ok=True)
    fl = fail_list(prefix)
    bodies = {}
    import structural as S
    for f in fl:
        # keep the 3-line banner (IDX / address / original symbol name) verbatim
        lines = f["body"].split("\n")
        banner, rest = "\n".join(lines[:3]), "\n".join(lines[3:])
        t = rule_renames(rest)
        t = S.rule_opaque(t)
        t = S.rule_wide(t)
        t = S.rule_misc(t)
        t = S.rule_unique(t)
        t = S.rule_func_edits(t, f["name"])
        t = rule_fptr(t)
        t = rule_bare_return(t)
        bodies[f["idx"]] = banner + "\n" + t
    comb = os.path.join(d, "_combined.cpp")
    best_err = None
    best_bodies = None
    for r in range(rounds):
        linemap = build_combined(prefix, bodies, comb)
        rc, err = compile_unit(comb, prefix)
        if rc == 0:
            if verbose:
                print("round %d: all %d clean" % (r, len(fl)))
            best_err, best_bodies = 0, dict(bodies)
            break
        diags = parse_diags(err)
        if best_err is None or len(diags) < best_err:
            best_err, best_bodies = len(diags), dict(bodies)
        byf = collections.defaultdict(list)
        for ul, col, msg in diags:
            if ul in linemap:
                byf[linemap[ul][0]].append((linemap[ul][1], col, msg))
        patched = 0
        for idx, ds in byf.items():
            nb, n = patch_round(bodies[idx], ds)
            if n:
                bodies[idx] = nb
                patched += n
        if verbose:
            print("round %d: %d errors, %d patched, %d funcs affected"
                  % (r, len(diags), patched, len(byf)))
        if patched == 0:
            break
    if best_bodies is not None:
        bodies = best_bodies
    for idx, b in bodies.items():
        open(os.path.join(d, "f%03d.cpp" % idx), "w", encoding="utf-8", newline="\n").write(
            '#include "%s_shim.hpp"\n' % prefix + S.PRELUDE + "\n" + b + "\n")
    return fl

def report(prefix):
    d = gendir(prefix)
    fl = fail_list(prefix)
    bad = []
    for f in fl:
        p = os.path.join(d, "f%03d.cpp" % f["idx"])
        rc, err = compile_unit(p, prefix)
        if rc:
            bad.append((f, parse_diags(err)))
    print("%s: %d/%d clean" % (prefix, len(fl) - len(bad), len(fl)))
    keys = collections.Counter()
    for f, ds in bad:
        for ul, col, msg in ds:
            keys[msg] += 1
    for k, v in keys.most_common():
        print("%4d %s" % (v, k))
    return bad

if __name__ == "__main__":
    cmd = sys.argv[1]
    pref = sys.argv[2]
    if cmd == "gen":
        run(pref)
    report(pref)
