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
// IDX 91  001074a0  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
arr_undefined1_16 rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_get_insert_hint_unique_pos(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, _Rb_tree_node_base * param_2, int * param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  int iVar5;
  int iVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  p_Var4 = (_Rb_tree_node_base *)(this_ptr + 8);
  if (p_Var4 != param_2) {
    iVar6 = *param_3;
    if (iVar6 < *(int *)(param_2 + 0x20)) {
      p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
      p_Var3 = p_Var2;
      if (p_Var2 == param_2) goto LAB_0010bfe8;
      p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(param_2);
      if (*(int *)(p_Var1 + 0x20) < iVar6) {
        p_Var3 = 0x0;
        p_Var2 = p_Var1;
        if (*(long long *)(p_Var1 + 0x18) != 0) {
          p_Var3 = param_2;
          p_Var2 = param_2;
        }
        goto LAB_0010bfe8;
      }
      p_Var3 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
      if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == 0x0) {
LAB_0010c110:
        if (p_Var2 == p_Var4) goto LAB_0010c12b;
        p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var4);
        iVar5 = *(int *)(p_Var1 + 0x20);
      }
      else {
        do {
          p_Var4 = p_Var3;
          iVar5 = *(int *)(p_Var4 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x18);
          }
        } while (p_Var3 != 0x0);
        p_Var1 = p_Var4;
        if (iVar6 < iVar5) goto LAB_0010c110;
      }
      p_Var3 = 0x0;
      p_Var2 = p_Var4;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var1;
        p_Var2 = 0x0;
      }
      goto LAB_0010bfe8;
    }
    if (iVar6 <= *(int *)(param_2 + 0x20)) {
      (*(undefined8 *)((uint8_t *)&auVar9 + 0x8)) = 0;
      (*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = (undefined8)(uintptr_t)(param_2);
      return rea_arr_from<arr_undefined1_16>(auVar9);
    }
    p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x20);
    if (p_Var2 == param_2) {
LAB_0010c12b:
      p_Var3 = 0x0;
    }
    else {
      p_Var2 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(param_2);
      if (iVar6 < *(int *)(p_Var2 + 0x20)) {
        p_Var4 = p_Var2;
        if (*(long long *)(param_2 + 0x18) == 0) {
          p_Var2 = param_2;
          p_Var4 = 0x0;
        }
        (*(undefined8 *)((uint8_t *)&auVar8 + 0x8)) = (undefined8)(uintptr_t)(p_Var2);
        (*(undefined8 *)((uint8_t *)&auVar8 + 0x0)) = (undefined8)(uintptr_t)(p_Var4);
        return rea_arr_from<arr_undefined1_16>(auVar8);
      }
      p_Var3 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
      p_Var2 = p_Var4;
      if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == 0x0) {
LAB_0010c1e0:
        if (*(_Rb_tree_node_base **)(this_ptr + 0x18) == p_Var2) goto LAB_0010c12b;
        p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var2);
        iVar5 = *(int *)(p_Var4 + 0x20);
      }
      else {
        do {
          p_Var2 = p_Var3;
          iVar5 = *(int *)(p_Var2 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x18);
          }
        } while (p_Var3 != 0x0);
        p_Var4 = p_Var2;
        if (iVar6 < iVar5) goto LAB_0010c1e0;
      }
      p_Var3 = 0x0;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var4;
        p_Var2 = 0x0;
      }
    }
    goto LAB_0010bfe8;
  }
  if ((*(long long *)(this_ptr + 0x28) != 0) &&
     (*(int *)(*(_Rb_tree_node_base **)(this_ptr + 0x20) + 0x20) < *param_3)) {
    p_Var3 = 0x0;
    p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x20);
    goto LAB_0010bfe8;
  }
  if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == 0x0) {
LAB_0010c1b7:
    if (*(_Rb_tree_node_base **)(this_ptr + 0x18) == p_Var4) {
      p_Var3 = 0x0;
      p_Var2 = p_Var4;
      goto LAB_0010bfe8;
    }
    p_Var3 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var4);
    iVar5 = *(int *)(p_Var3 + 0x20);
    iVar6 = *param_3;
  }
  else {
    iVar6 = *param_3;
    p_Var4 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
    do {
      p_Var3 = p_Var4;
      iVar5 = *(int *)(p_Var3 + 0x20);
      if (iVar6 < iVar5) {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x10);
      }
      else {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x18);
      }
    } while (p_Var4 != 0x0);
    p_Var4 = p_Var3;
    if (iVar6 < iVar5) goto LAB_0010c1b7;
  }
  p_Var2 = 0x0;
  if (iVar5 < iVar6) {
    p_Var3 = p_Var2;
    p_Var2 = p_Var4;
  }
LAB_0010bfe8:
  (*(undefined8 *)((uint8_t *)&auVar7 + 0x8)) = (undefined8)(uintptr_t)(p_Var2);
  (*(undefined8 *)((uint8_t *)&auVar7 + 0x0)) = (undefined8)(uintptr_t)(p_Var3);
  return rea_arr_from<arr_undefined1_16>(auVar7);
}
