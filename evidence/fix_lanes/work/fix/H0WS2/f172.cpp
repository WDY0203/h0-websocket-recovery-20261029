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
// IDX 172  00109140  FUN_00109140
// ------------------------------------------------------------------
void rea_FUN_00109140(undefined8 * param_1, long long param_2)
{
  long long *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined *puVar4;
  long long lVar5;
  WSConn *pWVar6;
  undefined8 *puVar7;
  long long lVar8;
  long long lVar9;
  WSConn *local_58 [2];
  WSConn *local_48 [2];
  code *local_38;
  code *local_30;
  
  param_1 = (undefined8 *)*param_1;
  pWVar6 = rea_operator_new(0x70);
  *(undefined4 *)(pWVar6 + 0x10) = 0;
  *(long long *)(pWVar6 + 0x18) = 0;
  *(long long *)(pWVar6 + 0x30) = 0;
  *(long long *)(pWVar6 + 0x38) = param_2;
  *(long long *)(pWVar6 + 0x40) = 0;
  *(long long *)(pWVar6 + 0x48) = 0;
  *(WSConn **)(pWVar6 + 0x20) = pWVar6 + 0x10;
  *(WSConn **)(pWVar6 + 0x28) = pWVar6 + 0x10;
  puVar4 = PTR_vtable_00324f30;
  *(long long *)(pWVar6 + 0x50) = 0;
  pWVar6[0x58] = (WSConn)0x0;
  *(undefined **)pWVar6 = puVar4 + 0x10;
  puVar7 = (undefined8*)(uintptr_t)(rea_operator_new(0x18));
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar2 = *(undefined8 **)(pWVar6 + 0x40);
  *(undefined8 **)(pWVar6 + 0x40) = puVar7;
  if (puVar2 != 0x0) {
    if ((void *)*puVar2 != 0x0) {
      rea_operator_delete((void *)*puVar2);
    }
    rea_operator_delete(puVar2);
  }
  lVar8 = param_2 + 0x10;
  lVar5 = *(long long *)(param_2 + 0x18);
  local_58[0] = pWVar6;
  if (*(long long *)(param_2 + 0x18) != 0) {
    do {
      while (lVar9 = lVar5, pWVar6 <= *(WSConn **)(lVar9 + 0x20)) {
        lVar8 = lVar9;
        lVar5 = *(long long *)(lVar9 + 0x10);
        if (*(long long *)(lVar9 + 0x10) == 0) goto LAB_0010922b;
      }
      plVar1 = (long long *)(lVar9 + 0x18);
      lVar9 = lVar8;
      lVar5 = *plVar1;
    } while (*plVar1 != 0);
LAB_0010922b:
    if ((param_2 + 0x10 != lVar9) && (*(WSConn **)(lVar9 + 0x20) <= pWVar6)) goto LAB_00109236;
  }
  local_48[0] = pWVar6;
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root_____________((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(param_2 + 8),local_58,(unique_ptr *)local_48);
  if (local_48[0] != 0x0) {
    (**(code **)(*(long long *)local_48[0] + 8))();
  }
LAB_00109236:
  pWVar6 = local_58[0];
  uVar3 = *param_1;
  local_38 = 0x0;
  local_48[0] = rea_operator_new(0x10);
  *(undefined8 *)local_48[0] = uVar3;
  *(WSConn **)(local_48[0] + 8) = pWVar6;
  local_30 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00108c70);
  local_38 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107b90);
  rea_WSConn__connect(pWVar6,(long long int)(uintptr_t)(local_48));
  if (local_38 != 0x0) {
    (*local_38)(local_48,local_48,3);
  }
  return;
}
