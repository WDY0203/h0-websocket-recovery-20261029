"""Structural, type-level rewrites applied before the cast-inserter rounds."""

import re

# ---------------------------------------------------------------- prelude
PRELUDE = r"""
// ===================== type repair prelude (fixes.cpp) =====================
// Missing aggregate types that the generator referenced but did not emit.
struct arr_undefined1_4  { undefined1 v[4];  arr_undefined1_4() = default;  undefined1 &operator[](int i) { return v[i]; }  template<class U> arr_undefined1_4(U)  {} };
struct arr_undefined1_8  { undefined1 v[8];  arr_undefined1_8() = default;  undefined1 &operator[](int i) { return v[i]; }  template<class U> arr_undefined1_8(U)  {} };
struct arr_undefined1_15 { undefined1 v[15]; arr_undefined1_15() = default; undefined1 &operator[](int i) { return v[i]; } template<class U> arr_undefined1_15(U) {} };

// Ghidra integer types that the shim omitted.  Widths are the closest native
// type (3 -> 32 bit, 5 -> 64 bit, 10-byte unsigned -> 128 bit so that the
// `<< 0x40` / `<< 0x38` the pseudocode applies to it stays a legal shift).
// See NOTES.md.
typedef uint32_t uint3;
typedef int32_t  int3;
typedef int64_t  int5;
typedef unsigned __int128 unkuint10;

// 128-bit scratch values.  Ghidra emits `<<`, `>>` and `|` on the 16-byte
// return slots and on the arr_undefined1_N slices of them.  C++ has no
// operators for raw arrays, so those slots are addressed through the shim's
// arr_undefined1_N aggregates and the operators below.
struct rea_wide { uint8_t v[16];
  rea_wide() = default;
  template <class U> rea_wide(U) {}
  operator uint64_t() const { uint64_t x; memcpy(&x, v, 8); return x; }
};

template <class T> struct rea_has_v {
  template <class U> static char probe(decltype(&U::v) *);
  template <class U> static long probe(...);
  enum { value = sizeof(probe<T>(0)) == 1 };
};

static inline rea_wide rea_shift_bytes(const void *p, size_t nbytes, unsigned cnt, int left)
{
  uint8_t out[16] = {0};
  unsigned by = cnt / 8;
  if (cnt % 8 == 0) {
    for (int i = 0; i < 16; ++i) {
      long src = left ? (long)i - (long)by : (long)i + (long)by;
      if (src >= 0 && (size_t)src < nbytes && (size_t)src < 16)
        out[i] = ((const uint8_t *)p)[src];
    }
  }
  rea_wide r; memcpy(r.v, out, 16); return r;
}
static inline rea_wide rea_or_bytes(const void *a, size_t na, const void *b, size_t nb)
{
  uint8_t out[16];
  for (int i = 0; i < 16; ++i) {
    uint8_t x = i < (int)na ? ((const uint8_t *)a)[i] : 0;
    uint8_t y = i < (int)nb ? ((const uint8_t *)b)[i] : 0;
    out[i] = (uint8_t)(x | y);
  }
  rea_wide r; memcpy(r.v, out, 16); return r;
}

template <class A> inline typename std::enable_if<rea_has_v<A>::value || std::is_same<A, rea_wide>::value, rea_wide>::type
operator<<(const A &a, int cnt) { return rea_shift_bytes(&a, sizeof(A), (unsigned)cnt, 1); }

template <class A> inline typename std::enable_if<rea_has_v<A>::value || std::is_same<A, rea_wide>::value, rea_wide>::type
operator>>(const A &a, int cnt) { return rea_shift_bytes(&a, sizeof(A), (unsigned)cnt, 0); }

template <class A, class B> inline typename std::enable_if<(rea_has_v<A>::value || std::is_same<A, rea_wide>::value) &&
                                                           (rea_has_v<B>::value || std::is_same<B, rea_wide>::value), rea_wide>::type
operator|(const A &a, const B &b) { return rea_or_bytes(&a, sizeof(A), &b, sizeof(B)); }
// =================== end type repair prelude ===================
"""

# ------------------------------------------------------- opaque aggregates
# offsets from the x86-64 SysV layouts of the generated headers
OPAQUE = [
    # epoll_event { uint32_t events; epoll_data_t data; }   (packed: data @4)
    (r"&(\w+(?:\[\d+\])?)\.data\b",        r"((uint8_t *)&\1 + 0x4)"),
    (r"(\w+(?:\[\d+\])?)\.data\.fd\b",     r"(*(int *)((uint8_t *)&\1 + 0x4))"),
    (r"(\w+(?:\[\d+\])?)\.data\b",         r"(*(undefined8 *)((uint8_t *)&\1 + 0x4))"),
    (r"(\w+(?:\[\d+\])?)\.events\b",       r"(*(uint32_t *)((uint8_t *)&\1 + 0x0))"),
    # sockaddr { sa_family_t sa_family; char sa_data[14]; }
    (r"(\w+(?:\[\d+\])?)\.sa_family\b",    r"(*(undefined2 *)((uint8_t *)&\1 + 0x0))"),
    (r"(\w+(?:\[\d+\])?)\.sa_data\._2_4_\b", r"(*(undefined4 *)((uint8_t *)&\1 + 0x4))"),
    (r"(\w+(?:\[\d+\])?)\.sa_data\._0_2_\b", r"(*(undefined2 *)((uint8_t *)&\1 + 0x2))"),
    (r"(\w+(?:\[\d+\])?)\.sa_data\._0_4_\b", r"(*(undefined4 *)((uint8_t *)&\1 + 0x2))"),
    (r"(\w+(?:\[\d+\])?)\.sa_data\b",      r"((uint8_t *)&\1 + 0x2)"),
    # generator already exploded sa_data but lost the base expression
    (r"(\w+(?:\[\d+\])?)\.\(\*\(undefined4 \*\)\(\(uint8_t \*\)&sa_data \+ 0x2\)\)",
     r"(*(undefined4 *)((uint8_t *)&\1 + 0x4))"),
    (r"(\w+(?:\[\d+\])?)\.\(\*\(undefined2 \*\)\(\(uint8_t \*\)&sa_data \+ 0x0\)\)",
     r"(*(undefined2 *)((uint8_t *)&\1 + 0x2))"),
    # stat: st_mode @0x18, __unused @0x78
    (r"(\w+(?:\[\d+\])?)\.st_mode\b",      r"(*(uint32_t *)((uint8_t *)&\1 + 0x18))"),
    (r"\(long long\)(\w+)\.__unused\b",    r"((long long)((uint8_t *)&\1 + 0x78))"),
    (r"\(long\)(\w+)\.__unused\b",         r"((long)((uint8_t *)&\1 + 0x78))"),
    # sigaction: sa_handler @0
    (r"(\w+(?:\[\d+\])?)\.sa_handler\b",   r"(*(code **)((uint8_t *)&\1 + 0x0))"),
    (r"\(__sighandler_t\)",                r"(code *)"),
]

DECL_OPAQUE = [
    (r"^(\s*)stat (\w+);",            r"\1undefined1 \2[0x90];"),
    (r"^(\s*)sockaddr (\w+);",        r"\1undefined1 \2[0x10];"),
    (r"^(\s*)epoll_event (\w+);",     r"\1undefined1 \2[0xc];"),
    (r"^(\s*)_union_1457 (\w+);",     r"\1undefined1 \2[0x98];"),
    (r"^(\s*)sockaddr (\w+) \[(\d+)\];",       r"\1undefined1 \2[\3][0x10];"),
    (r"^(\s*)epoll_event (\w+) \[(\d+)\];",    r"\1undefined1 \2[\3][0xc];"),
]

def _apply_lines(text, rules, regex=True):
    out = []
    for line in text.split("\n"):
        for pat, rep in rules:
            if regex:
                line = re.sub(pat, rep, line)
            elif pat in line:
                line = line.replace(pat, rep)
        out.append(line)
    return "\n".join(out)

def rule_opaque(t):
    t = _apply_lines(t, DECL_OPAQUE)
    t = _apply_lines(t, OPAQUE)
    return t

def rule_wide(t):
    """Turn 16-byte raw slots that take part in <<, >>, | into arr_undefined1_N."""
    names = set()
    for pat in (r"(\w+)\s*(?:<<|>>|\|)", r"(?:<<|>>|\|)\s*(\w+)"):
        for m in re.finditer(pat, t):
            names.add(m.group(1))
    decl = {}
    for m in re.finditer(r"^\s*undefined1 (\w+) \[(\d+)\];", t, re.M):
        decl[m.group(1)] = int(m.group(2))
    conv = {n: decl[n] for n in names if n in decl}
    if not conv:
        return t
    out = []
    for line in t.split("\n"):
        m = re.match(r"^(\s*)undefined1 (\w+) \[(\d+)\];$", line)
        if m and m.group(2) in conv:
            line = "%sarr_undefined1_%s %s;" % (m.group(1), m.group(3), m.group(2))
        for n in conv:
            line = re.sub(r"\bmemcpy\(%s," % re.escape(n), "memcpy(&%s," % n, line)
        out.append(line)
    return "\n".join(out)

def rule_unique(t):
    """Ghidra `unique0x...` pseudo-registers are plain local scratch slots here."""
    names = sorted(set(re.findall(r"\bunique0x[0-9a-f]+\b", t)))
    if not names:
        return t
    decl = "".join("  uintptr_t %s;\n" % n for n in names)
    m = re.search(r"^\{\s*$", t, re.M)
    if not m:
        return t
    return t[:m.end()] + "\n" + decl + t[m.end():]

FUNC_EDITS = {
    # --- signatures that the generator truncated (parameters used by the body)
    "rea__Function_handler_void": [
        (r"^undefined8 rea__Function_handler_void\(undefined8 \* param_2\)",
         "undefined8 rea__Function_handler_void(long * param_1, undefined8 * param_2)")],
    "rea__Function_handler_void__dup3": [
        (r"^undefined8 rea__Function_handler_void__dup3\(undefined8 \* param_2\)",
         "undefined8 rea__Function_handler_void__dup3(long * param_1, undefined8 * param_2)")],
    "rea__Function_handler_void__dup2": [
        (r"^undefined8 rea__Function_handler_void__dup2\([^)]*\)",
         "undefined8 rea__Function_handler_void__dup2(undefined8 * param_1, undefined8 * param_2, undefined8 * param_3)")],
    # --- implicit this pointer was emitted under a different spelling
    "rea_vector_std__pair_EventHandler__std__function_void__dup4": [
        (r"\bthis_ptr\b", "param_x0")],
    # --- fully mangled template-id in the callee spelling
    "rea_EventLoop2__del": [
        (r"(?s)\n[ \t]*std::\n.*?&local_48\);",
         "\n    rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler("
         "(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler *)(this_ptr + 0x38),"
         "(unique_ptr *)&local_48);")],
}

def rule_func_edits(t, name):
    for pat, new in FUNC_EDITS.get(name, ()):
        t = re.sub(pat, new, t, flags=re.M)
    return t

def rule_misc(t):
    # 8-byte slot compared against the generator's empty aggregate literal
    t = re.sub(r"\b(\w+)\s*!=\s*arr_undefined1_8\{\}", r"(*(undefined8 *)(\1) != 0)", t)
    t = re.sub(r"\b(\w+)\s*==\s*arr_undefined1_8\{\}", r"(*(undefined8 *)(\1) == 0)", t)
    # store of an 8-byte slot through a pointer-to-array
    t = re.sub(r"\*\(undefined1 \(\*\) \[8\]\)\(([^;]+?)\) = (\w+);",
               r"*(undefined8 *)(\1) = *(undefined8 *)(\2);", t)
    # `slot._4_4_` = high dword of the 8-byte slot
    t = re.sub(r"\b([A-Za-z_]\w*(?:\[\d+\])?)\._4_4_",
               r"(undefined4)((uint64_t)(uintptr_t)\1 >> 32)", t)
    # `(T *)0x0` -> plain 0 (valid for pointer and integer comparands alike)
    t = re.sub(r"\((?:[A-Za-z_]\w*)(?: [A-Za-z_]\w*)*\s*\*\)0x0\b", "0x0", t)
    return t
