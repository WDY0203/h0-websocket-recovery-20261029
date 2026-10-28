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
// IDX 202  0010e040  FUN_0010e040
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e040(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  int *piVar1;
  long long *plVar2;
  long long lVar3;
  string *psVar4;
  int iVar5;
  string *this_ptr;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (undefined8)(uintptr_t)((void *)&PTR_vtable_003248f0);
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      psVar4 = (string *)*param_2;
      this_ptr = rea_operator_new(0x28);
      rea_std__string__string(this_ptr,psVar4);
      *(undefined8 *)(this_ptr + 0x18) = 0;
      if (*(code **)(psVar4 + 0x18) != 0x0) {
        (**(code **)(psVar4 + 0x18))(this_ptr + 8,psVar4 + 8,2);
        *(undefined8 *)(this_ptr + 0x20) = *(undefined8 *)(psVar4 + 0x20);
        *(undefined8 *)(this_ptr + 0x18) = *(undefined8 *)(psVar4 + 0x18);
      }
      *param_1 = (undefined8)(uintptr_t)(this_ptr);
      return 0;
    }
    if ((param_3 == 3) && (plVar2 = (long long *)*param_1, plVar2 != 0x0)) {
      if ((code *)plVar2[3] != 0x0) {
        (*(code *)plVar2[3])(plVar2 + 1,plVar2 + 1,3);
      }
      lVar3 = *plVar2;
      if ((allocator *)(lVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(lVar3 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar5 = *(int *)(lVar3 + -8);
          *(int *)(lVar3 + -8) = iVar5 + -1;
        }
        else {
          LOCK();
          iVar5 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar5 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar3 + -0x18));
        }
      }
      rea_operator_delete(plVar2);
    }
  }
  return 0;
}
