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
// IDX 170  00108c70  FUN_00108c70
// ------------------------------------------------------------------
void rea_FUN_00108c70(long long * param_1)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  long long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  long long *plVar8;
  _Rb_tree_node_base *p_Var9;
  _Rb_tree_node_base *p_Var10;
  ulong uVar11;
  long long lVar12;
  ulong uVar13;
  _Rb_tree_node_base *p_Var14;
  bool bVar15;
  long long *local_78;
  undefined8 local_70;
  code *local_68;
  code *pcStack_60;
  undefined8 *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  
  param_1 = (long long *)*param_1;
  lVar3 = *param_1;
  lVar12 = param_1[1];
  *(undefined8 *)(lVar3 + 0xe0) = 0;
  *(long long *)(lVar3 + 0x68) = lVar12;
  *(undefined8 *)(lVar3 + 0xe8) = 0;
  plVar8 = (long long int*)(uintptr_t)(rea_operator_new(0x18));
  lVar12 = *param_1;
  plVar8[2] = lVar3;
  *(undefined1 *)(plVar8 + 1) = 1;
  *plVar8 = (long long)(void *)&PTR_FUN_00324730;
  lVar3 = *(long long *)(lVar12 + 0x68);
  p_Var2 = (_Rb_tree_node_base *)(lVar3 + 0x10);
  p_Var10 = p_Var2;
  p_Var14 = *(_Rb_tree_node_base **)(lVar3 + 0x18);
  if (*(_Rb_tree_node_base **)(lVar3 + 0x18) != 0x0) {
    do {
      while (p_Var9 = p_Var14, plVar8 <= *(long long **)(p_Var9 + 0x20)) {
        p_Var10 = p_Var9;
        p_Var14 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
        if (*(_Rb_tree_node_base **)(p_Var9 + 0x10) == 0x0) goto LAB_00108d03;
      }
      p_Var1 = p_Var9 + 0x18;
      p_Var9 = p_Var10;
      p_Var14 = *(_Rb_tree_node_base **)p_Var1;
    } while (*(_Rb_tree_node_base **)p_Var1 != 0x0);
LAB_00108d03:
    if ((p_Var2 != p_Var9) && (*(long long **)(p_Var9 + 0x20) <= plVar8)) goto LAB_00108d19;
  }
  p_Var10 = rea_operator_new(0x30);
  if (p_Var10 != 0x0) {
    *(undefined4 *)p_Var10 = 0;
    *(undefined8 *)(p_Var10 + 8) = 0;
    *(undefined8 *)(p_Var10 + 0x10) = 0;
    *(undefined8 *)(p_Var10 + 0x18) = 0;
    *(long long **)(p_Var10 + 0x20) = plVar8;
    *(long long **)(p_Var10 + 0x28) = plVar8;
    plVar8 = 0x0;
  }
  p_Var14 = p_Var2;
  if (*(_Rb_tree_node_base **)(lVar3 + 0x18) == 0x0) {
LAB_00108fe2:
    if (*(_Rb_tree_node_base **)(lVar3 + 0x20) != p_Var14) {
      lVar12 = rea_std___Rb_tree_decrement(p_Var14);
      uVar13 = *(ulong *)(lVar12 + 0x20);
      uVar11 = *(ulong *)(p_Var10 + 0x20);
      goto LAB_00108fa5;
    }
LAB_00108ffb:
    if (p_Var14 == 0x0) goto LAB_00108faa;
    if (p_Var2 == p_Var14) {
      bVar15 = true;
    }
    else {
      bVar15 = *(ulong *)(p_Var10 + 0x20) < *(ulong *)(p_Var14 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var14,p_Var2);
    *(long long *)(lVar3 + 0x30) = *(long long *)(lVar3 + 0x30) + 1;
  }
  else {
    uVar11 = *(ulong *)(p_Var10 + 0x20);
    p_Var9 = *(_Rb_tree_node_base **)(lVar3 + 0x18);
    do {
      p_Var14 = p_Var9;
      uVar13 = *(ulong *)(p_Var14 + 0x20);
      if (uVar11 < uVar13) {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      }
      else {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
      }
    } while (p_Var9 != 0x0);
    if (uVar11 < uVar13) goto LAB_00108fe2;
LAB_00108fa5:
    if (uVar13 < uVar11) goto LAB_00108ffb;
LAB_00108faa:
    if (*(long long **)(p_Var10 + 0x28) != 0x0) {
      (**(code **)(**(long long **)(p_Var10 + 0x28) + 8))();
    }
    *(undefined8 *)(p_Var10 + 0x28) = 0;
    rea_operator_delete(p_Var10);
  }
  if (plVar8 != 0x0) {
    (**(code **)(*plVar8 + 8))(plVar8);
  }
  lVar12 = *param_1;
LAB_00108d19:
  local_68 = 0x0;
  local_78 = (long long int*)(uintptr_t)(rea_operator_new(8));
  *local_78 = lVar12;
  pcStack_60 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00108300);
  local_68 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107c20);
  lVar3 = *(long long *)(*(long long *)(*param_1 + 0x68) + 0x38);
  local_48 = 0x0;
  rea_FUN_00107c20((undefined8*)(uintptr_t)(&local_58),(undefined8*)(uintptr_t)(&local_78),2);
  puVar4 = *(undefined8 **)(lVar3 + 0xb0);
  uVar5 = *(undefined8 *)(lVar3 + 0xb8);
  local_48 = *(code **)(lVar3 + 0xc0);
  *(undefined8 **)(lVar3 + 0xb0) = local_58;
  *(undefined8 *)(lVar3 + 0xb8) = local_50;
  puStack_40 = *(undefined **)(lVar3 + 200);
  *(code **)(lVar3 + 0xc0) = local_68;
  *(code **)(lVar3 + 200) = pcStack_60;
  local_58 = puVar4;
  local_50 = uVar5;
  if (local_48 != 0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != 0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  lVar3 = *param_1;
  local_68 = 0x0;
  local_78 = (long long int*)(uintptr_t)(rea_operator_new(8));
  *local_78 = lVar3;
  local_48 = 0x0;
  pcStack_60 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_001093b0);
  local_68 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107ca0);
  local_58 = (undefined8*)(uintptr_t)(rea_operator_new(0x20));
  pcVar7 = local_68;
  local_58[2] = 0;
  plVar8 = (long long *)*local_58;
  uVar5 = local_58[1];
  *local_58 = (undefined8)(uintptr_t)(local_78);
  local_58[1] = local_70;
  local_68 = 0x0;
  uVar6 = local_58[3];
  local_58[2] = (undefined8)(uintptr_t)(pcVar7);
  local_58[3] = (undefined8)(uintptr_t)(pcStack_60);
  puStack_40 = PTR__M_invoke_00324fe0;
  local_48 = (code *)PTR__M_manager_00324f88;
  local_78 = plVar8;
  local_70 = uVar5;
  pcStack_60 = (code *)uVar6;
  rea_WSConn__recv(*(WSConn **)(*param_1 + 0x68),(long long int)(uintptr_t)(&local_58));
  if (local_48 != 0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != 0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  rea_EventLoop2__exit((EventLoop2 *)*param_1,1);
  return;
}
