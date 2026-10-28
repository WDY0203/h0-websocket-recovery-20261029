#include "H0WS2_shim.hpp"

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

// ------------------------------------------------------------------
// IDX 286  0011c830  __gnu_cxx____to_xstring_std__string_char
// ------------------------------------------------------------------
code * rea___gnu_cxx____to_xstring_std__string_char__dup2(code * param_1, ulong param_2, char * param_3, undefined8 param_x3)
{
  undefined8 stack0x00000008;
  undefined1 *__src;
  long long lVar1;
  char in_AL;
  int iVar2;
  ulong *puVar3;
  ulong *__dest;
  undefined8 in_RCX;
  undefined8 in_R8;
  undefined8 in_R9;
  ulong __n;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  undefined8 uStack_100;
  allocator local_f1;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 *local_e8;
  undefined1 *local_e0;
  undefined1 local_d8 [32];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  
  if (in_AL != '\0') {
    local_a8 = in_XMM0_Qa;
    local_98 = in_XMM1_Qa;
    local_88 = in_XMM2_Qa;
    local_78 = in_XMM3_Qa;
    local_68 = in_XMM4_Qa;
    local_58 = in_XMM5_Qa;
    local_48 = in_XMM6_Qa;
    local_38 = in_XMM7_Qa;
  }
  local_e8 = (undefined1*)(uintptr_t)((void *)&stack0x00000008);
  lVar1 = -((ulong)(param_3 + 0x1e) & 0xfffffffffffffff0);
  local_e0 = local_d8;
  __src = (undefined1 *)((long long)&local_f0 + lVar1);
  local_f0 = 0x20;
  local_ec = 0x30;
  local_b8 = in_R8;
  local_b0 = in_R9;
  *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x11c8d4;
  iVar2 = (*(code *)param_2)(__src,param_3,in_RCX,&local_f0);
  if (__src == __src + iVar2) {
    __dest = (ulong *)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  }
  else {
    __n = (long long)(__src + iVar2) - (long long)__src;
    *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x11c8f3;
    puVar3 = (ulong *)rea_std__string___Rep___S_create(__n,0,&local_f1);
    __dest = puVar3 + 3;
    if (__n == 1) {
      *(undefined1 *)(puVar3 + 3) = *__src;
    }
    else {
      *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x11c90e;
      __dest = (ulong*)(uintptr_t)(rea_memcpy(__dest,__src,__n));
    }
    if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00324fa0) {
      *(undefined4 *)(puVar3 + 2) = 0;
      *puVar3 = __n;
      *(undefined1 *)((long long)puVar3 + __n + 0x18) = 0;
    }
  }
  *(ulong **)param_1 = __dest;
  return param_1;
}
