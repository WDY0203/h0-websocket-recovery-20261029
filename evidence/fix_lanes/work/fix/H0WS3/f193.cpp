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
// IDX 193  0010be40  std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root___________
// ------------------------------------------------------------------
arr_undefined1_16 rea_std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root__dup2(_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root * this_ptr, WSConn * * param_1, unique_ptr * param_2)
{
  _Rb_tree_node_base *p_Var1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  bool bVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  (*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = (undefined8)(uintptr_t)(rea_operator_new(0x30));
  if ((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) != 0x0) {
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 8) = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x10) = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x18) = 0;
    *(undefined4 *)(*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = 0;
    *(WSConn **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) = *param_1;
    uVar2 = *(undefined8 *)param_2;
    *(undefined8 *)param_2 = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) = uVar2;
  }
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 8);
  p_Var6 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == 0x0) {
LAB_0010bf18:
    p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
    if (p_Var5 == p_Var6) goto LAB_0010bf50;
    p_Var5 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var6);
    if (*(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) <= *(ulong *)(p_Var5 + 0x20)) goto LAB_0010bee1;
  }
  else {
    uVar3 = *(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20);
    p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
    do {
      p_Var6 = p_Var5;
      uVar4 = *(ulong *)(p_Var6 + 0x20);
      if (uVar3 < uVar4) {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
      }
      else {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
    } while (p_Var5 != 0x0);
    if (uVar3 < uVar4) goto LAB_0010bf18;
    p_Var5 = p_Var6;
    if (uVar3 <= uVar4) goto LAB_0010bee1;
  }
  p_Var5 = p_Var6;
  if (p_Var6 == 0x0) {
    p_Var5 = 0x0;
LAB_0010bee1:
    if (*(long long **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) != 0x0) {
      (**(code **)(**(long long **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) + 8))();
    }
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) = 0;
    rea_operator_delete((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)));
    (*(undefined8 *)((uint8_t *)&auVar8 + 0x8)) = 0;
    (*(undefined8 *)((uint8_t *)&auVar8 + 0x0)) = (undefined8)(uintptr_t)(p_Var5);
    return rea_arr_from<arr_undefined1_16>(auVar8);
  }
LAB_0010bf50:
  if (p_Var1 == p_Var5) {
    bVar7 = true;
  }
  else {
    bVar7 = *(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) < *(ulong *)(p_Var5 + 0x20);
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar7,((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar9 + 0x0))),p_Var5,p_Var1);
  *(long long *)(this_ptr + 0x28) = *(long long *)(this_ptr + 0x28) + 1;
  (*(undefined8 *)((uint8_t *)&auVar9 + 0x8)) = 1;
  return rea_arr_from<arr_undefined1_16>(auVar9);
}
