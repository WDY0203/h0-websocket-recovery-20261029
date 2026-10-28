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
// IDX 241  00115d50  _Function_handler<void
// ------------------------------------------------------------------
undefined8 rea__Function_handler_void__dup3(long * param_1, undefined8 * param_2)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_ptr;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  uint uVar6;
  long long *plVar7;
  _Rb_tree_node_base *p_Var8;
  long long lVar9;
  _Rb_tree_node_base *p_Var10;
  long long lVar11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  _Rb_tree_node_base *p_Var14;
  bool bVar15;
  uint uVar16;
  uint uVar17;
  undefined1 auVar18 [16];
  int local_68 [4];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  
  puVar3 = (undefined8 *)*param_2;
  *param_2 = 0;
  if (puVar3 == 0x0) {
    return 0;
  }
  lVar11 = *(long long *)*param_1;
  if (*(char *)(lVar11 + 0x88) != '\0') {
    rea_fwrite((void*)(uintptr_t)("recv(): recv_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar11 + 0x88) = 1;
  local_48 = 0x0;
  plVar7 = (long long int*)(uintptr_t)(rea_operator_new(8));
  *plVar7 = lVar11;
  puVar5 = PTR__M_manager_00324f68;
  uVar4 = *(undefined8 *)(lVar11 + 0x98);
  local_58 = *(undefined8 *)(lVar11 + 0x90);
  *(undefined8 *)(lVar11 + 0x98) = local_50;
  local_48 = *(code **)(lVar11 + 0xa0);
  *(undefined **)(lVar11 + 0xa0) = puVar5;
  local_40 = *(undefined8 *)(lVar11 + 0xa8);
  *(long long **)(lVar11 + 0x90) = plVar7;
  *(undefined **)(lVar11 + 0xa8) = PTR__M_invoke_00324f40;
  local_50 = uVar4;
  if (local_48 != 0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  local_68[0] = *(int *)(lVar11 + 0x40);
  cVar2 = *(char *)(lVar11 + 0x88);
  lVar11 = *(long long *)(lVar11 + 0x38);
  p_Var8 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var10 = (_Rb_tree_node_base *)(lVar11 + 0x10);
  p_Var13 = p_Var8;
  p_Var12 = p_Var10;
  if (p_Var8 == 0x0) {
LAB_00115e7b:
    lVar9 = 0;
    uVar16 = 0;
  }
  else {
    do {
      while (p_Var14 = p_Var13, *(int *)(p_Var14 + 0x20) < local_68[0]) {
        p_Var1 = p_Var14 + 0x18;
        p_Var13 = *(_Rb_tree_node_base **)p_Var1;
        p_Var14 = p_Var12;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00115e6a;
      }
      p_Var13 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var12 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != 0x0);
LAB_00115e6a:
    if ((p_Var10 == p_Var14) || (p_Var13 = p_Var10, local_68[0] < *(int *)(p_Var14 + 0x20)))
    goto LAB_00115e7b;
    do {
      while (p_Var12 = p_Var8, *(int *)(p_Var12 + 0x20) < local_68[0]) {
        p_Var14 = p_Var12 + 0x18;
        p_Var8 = *(_Rb_tree_node_base **)p_Var14;
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var14 == 0x0) goto LAB_0011603a;
      }
      p_Var8 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)(p_Var12 + 0x10) != 0x0);
LAB_0011603a:
    if ((p_Var10 == p_Var12) || (local_68[0] < *(int *)(p_Var12 + 0x20))) {
      p_Var8 = rea_operator_new(0x28);
      if (p_Var8 != 0x0) {
        *(undefined4 *)p_Var8 = 0;
        *(undefined8 *)(p_Var8 + 8) = 0;
        *(undefined8 *)(p_Var8 + 0x10) = 0;
        *(undefined8 *)(p_Var8 + 0x18) = 0;
        *(undefined4 *)(p_Var8 + 0x24) = 0;
        *(int *)(p_Var8 + 0x20) = local_68[0];
      }
      { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar11 + 8),p_Var12,p_Var8 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
      p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x8)));
      p_Var12 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x0)));
      if (p_Var13 == 0x0) {
        rea_operator_delete(p_Var8);
      }
      else {
        bVar15 = true;
        if ((p_Var12 == 0x0) && (p_Var10 != p_Var13)) {
          bVar15 = *(int *)(p_Var8 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var8,p_Var13,p_Var10);
        *(long long *)(lVar11 + 0x30) = *(long long *)(lVar11 + 0x30) + 1;
        p_Var12 = p_Var8;
      }
    }
    uVar16 = *(uint *)(p_Var12 + 0x24);
    lVar9 = 1;
  }
  lVar11 = lVar11 + (lVar9 + 1) * 0x30;
  this_ptr = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
          *)(lVar11 + 8);
  p_Var10 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar11 + 0x10);
  p_Var8 = p_Var10;
  p_Var13 = p_Var12;
  uVar6 = uVar16;
  if (p_Var10 != 0x0) {
    do {
      while (p_Var14 = p_Var8, *(int *)(p_Var14 + 0x20) < local_68[0]) {
        p_Var1 = p_Var14 + 0x18;
        p_Var8 = *(_Rb_tree_node_base **)p_Var1;
        p_Var14 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00115eca;
      }
      p_Var8 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var13 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != 0x0);
LAB_00115eca:
    if ((p_Var12 != p_Var14) && (p_Var8 = p_Var12, *(int *)(p_Var14 + 0x20) <= local_68[0])) {
      do {
        while (p_Var13 = p_Var10, *(int *)(p_Var13 + 0x20) < local_68[0]) {
          p_Var14 = p_Var13 + 0x18;
          p_Var10 = *(_Rb_tree_node_base **)p_Var14;
          p_Var13 = p_Var8;
          if (*(_Rb_tree_node_base **)p_Var14 == 0x0) goto LAB_00115efa;
        }
        p_Var10 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var8 = p_Var13;
      } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != 0x0);
LAB_00115efa:
      if ((p_Var12 == p_Var13) || (local_68[0] < *(int *)(p_Var13 + 0x20))) {
        p_Var10 = rea_operator_new(0x28);
        if (p_Var10 != 0x0) {
          *(undefined4 *)p_Var10 = 0;
          *(undefined8 *)(p_Var10 + 8) = 0;
          *(undefined8 *)(p_Var10 + 0x10) = 0;
          *(undefined8 *)(p_Var10 + 0x18) = 0;
          *(undefined4 *)(p_Var10 + 0x24) = 0;
          *(int *)(p_Var10 + 0x20) = local_68[0];
        }
        { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_ptr,p_Var13,p_Var10 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
        p_Var8 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x8)));
        p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x0)));
        if (p_Var8 == 0x0) {
          rea_operator_delete(p_Var10);
        }
        else {
          bVar15 = true;
          if ((p_Var13 == 0x0) && (p_Var12 != p_Var8)) {
            bVar15 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var8 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var8,p_Var12);
          *(long long *)(lVar11 + 0x30) = *(long long *)(lVar11 + 0x30) + 1;
          p_Var13 = p_Var10;
        }
      }
      uVar6 = *(uint *)(p_Var13 + 0x24);
    }
  }
  uVar17 = uVar6 | 1;
  if (cVar2 == '\0') {
    uVar17 = uVar6 & 0xfffffffe;
  }
  if (uVar16 == uVar17) {
    _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_ptr,local_68);
    goto LAB_00115ff3;
  }
  p_Var10 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var13 = p_Var12;
  p_Var8 = p_Var12;
  if (*(_Rb_tree_node_base **)(lVar11 + 0x18) == 0x0) {
LAB_00116100:
    p_Var10 = rea_operator_new(0x28);
    if (p_Var10 != 0x0) {
      *(undefined4 *)p_Var10 = 0;
      *(undefined8 *)(p_Var10 + 8) = 0;
      *(undefined8 *)(p_Var10 + 0x10) = 0;
      *(undefined8 *)(p_Var10 + 0x18) = 0;
      *(undefined4 *)(p_Var10 + 0x24) = 0;
      *(int *)(p_Var10 + 0x20) = local_68[0];
    }
    { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_ptr,p_Var8,p_Var10 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
    p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x8)));
    p_Var8 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x0)));
    if (p_Var13 == 0x0) {
      rea_operator_delete(p_Var10);
    }
    else {
      bVar15 = true;
      if ((p_Var8 == 0x0) && (p_Var12 != p_Var13)) {
        bVar15 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var13 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var13,p_Var12);
      *(long long *)(lVar11 + 0x30) = *(long long *)(lVar11 + 0x30) + 1;
      p_Var8 = p_Var10;
    }
  }
  else {
    do {
      while (p_Var8 = p_Var10, *(int *)(p_Var8 + 0x20) < local_68[0]) {
        p_Var14 = p_Var8 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var14;
        p_Var8 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var14 == 0x0) goto LAB_00115fda;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
      p_Var13 = p_Var8;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x10) != 0x0);
LAB_00115fda:
    if ((p_Var12 == p_Var8) || (local_68[0] < *(int *)(p_Var8 + 0x20))) goto LAB_00116100;
  }
  *(uint *)(p_Var8 + 0x24) = uVar17;
LAB_00115ff3:
  if ((void *)*puVar3 != 0x0) {
    rea_operator_delete((void *)*puVar3);
  }
  rea_operator_delete(puVar3);
  return 0;
}
