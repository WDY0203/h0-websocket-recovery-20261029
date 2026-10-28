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
// IDX 262  001177d0  vector<std__pair<EventHandler*,std__function<void
// ------------------------------------------------------------------
undefined8 rea_vector_std__pair_EventHandler__std__function_void__dup4(undefined8 * param_x0, undefined8 * param_1)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  ulong local_48;
  
  lVar5 = *(long long *)(param_x0 + 8) - *(long long *)param_x0 >> 3;
  if (lVar5 * -0x3333333333333333 == 0) {
    local_48 = 1;
  }
  else {
    local_48 = lVar5 * -0x6666666666666666;
    if (local_48 <= (ulong)(lVar5 * -0x3333333333333333) && lVar5 * 0x3333333333333333 != 0) {
      uVar8 = 0xfffffffffffffff0;
      local_48 = 0x666666666666666;
      goto LAB_00117827;
    }
    if (0x666666666666666 < local_48) {
      uVar8 = 0xfffffffffffffff0;
      local_48 = 0x666666666666666;
      goto LAB_00117827;
    }
  }
  uVar8 = local_48 * 0x28;
LAB_00117827:
  puVar6 = (undefined8*)(uintptr_t)(rea_operator_new(uVar8));
  puVar11 = *(undefined8 **)(param_x0 + 8);
  puVar7 = *(undefined8 **)param_x0;
  puVar9 = (undefined8 *)(((long long)puVar11 - (long long)puVar7 & 0xfffffffffffffff8U) + (long long)puVar6);
  if (puVar9 != 0x0) {
    uVar1 = *(undefined8 *)param_1;
    puVar9[3] = 0;
    *puVar9 = uVar1;
    uVar1 = puVar9[1];
    uVar2 = *(undefined8 *)(param_1 + 8);
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(param_1 + 0x10) = puVar9[2];
    *(undefined8 *)(param_1 + 8) = uVar1;
    puVar9[1] = uVar2;
    puVar9[2] = uVar3;
    uVar1 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x18) = puVar9[3];
    puVar9[3] = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = puVar9[4];
    puVar9[4] = uVar1;
    puVar11 = *(undefined8 **)(param_x0 + 8);
    puVar7 = *(undefined8 **)param_x0;
  }
  if (puVar11 == puVar7) {
    puVar9 = puVar6 + 5;
  }
  else {
    puVar10 = puVar6 + 4;
    puVar4 = puVar6;
    do {
      puVar9 = puVar4;
      if (puVar9 != 0x0) {
        *puVar9 = *puVar7;
        puVar10[-1] = 0;
        if ((code *)puVar7[3] != 0x0) {
          (*(code *)puVar7[3])(puVar9 + 1,puVar7 + 1,2);
          *puVar10 = puVar7[4];
          puVar10[-1] = puVar7[3];
        }
      }
      puVar7 = puVar7 + 5;
      puVar10 = puVar10 + 5;
      puVar4 = puVar9 + 5;
    } while (puVar11 != puVar7);
    puVar9 = puVar9 + 10;
    puVar7 = *(undefined8 **)param_x0;
    puVar11 = *(undefined8 **)(param_x0 + 8);
    if (puVar11 != puVar7) {
      do {
        if ((code *)puVar7[3] != 0x0) {
          (*(code *)puVar7[3])(puVar7 + 1,puVar7 + 1,3);
        }
        puVar7 = puVar7 + 5;
      } while (puVar11 != puVar7);
      puVar11 = *(undefined8 **)param_x0;
    }
  }
  if (puVar11 != 0x0) {
    rea_operator_delete(puVar11);
  }
  *(undefined8 **)(param_x0 + 8) = puVar9;
  *(undefined8 **)param_x0 = puVar6;
  *(undefined8 **)(param_x0 + 0x10) = puVar6 + local_48 * 5;
  return 0;
}
