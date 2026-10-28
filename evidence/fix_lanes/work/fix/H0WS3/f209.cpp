#include "H0WS3_shim.hpp"

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
// IDX 209  0010e930  FUN_0010e930
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e930(long long * param_1, long long * param_2, int param_3)
{
  undefined1 uVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long long)(void *)&PTR_vtable_00324950;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar3 = (undefined8 *)*param_2;
    puVar4 = (undefined8*)(uintptr_t)(rea_operator_new(0x38));
    *puVar4 = *puVar3;
    *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(puVar3 + 1);
    *(undefined4 *)((long long)puVar4 + 0xc) = *(undefined4 *)((long long)puVar3 + 0xc);
    uVar1 = *(undefined1 *)(puVar3 + 2);
    puVar4[5] = 0;
    *(undefined1 *)(puVar4 + 2) = uVar1;
    if ((code *)puVar3[5] != 0x0) {
      (*(code *)puVar3[5])(puVar4 + 3,puVar3 + 3,2);
      puVar4[6] = puVar3[6];
      puVar4[5] = puVar3[5];
    }
    *param_1 = (long long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != 0x0)) {
    if (*(code **)((long long)pvVar2 + 0x28) != 0x0) {
      (**(code **)((long long)pvVar2 + 0x28))((long long)pvVar2 + 0x18,(long long)pvVar2 + 0x18,3);
    }
    rea_operator_delete(pvVar2);
    return 0;
  }
  return 0;
}
