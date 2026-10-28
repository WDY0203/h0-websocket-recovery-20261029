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
// IDX 25  00106ff0  WSConn__exit
// ------------------------------------------------------------------
void rea_WSConn__exit(WSConn * this_ptr)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  _Rb_tree_node_base *p_Var2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 *puVar10;
  long long lVar11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  undefined *puVar14;
  long long lVar15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  bool bVar19;
  code *pcVar20;
  uint uVar21;
  uint uVar22;
  undefined1 auVar23 [16];
  int aiStack_a8 [4];
  undefined8 *apuStack_98 [2];
  code *pcStack_88;
  undefined *puStack_80;
  void *pvStack_78;
  undefined8 uStack_70;
  code *pcStack_68;
  undefined *puStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined *puStack_40;
  
  pcStack_88 = 0x0;
  apuStack_98[0] = (undefined8*)(uintptr_t)(rea_operator_new(8));
  lVar15 = *(long long *)(this_ptr + 0x38);
  *apuStack_98[0] = (undefined8)(uintptr_t)(this_ptr);
  puStack_80 = PTR__M_invoke_00324f38;
  pcStack_88 = (code *)PTR__M_manager_00324ec0;
  if (*(char *)(lVar15 + 0x88) != '\0') {
    rea_fwrite((void*)(uintptr_t)("recv(): recv_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar15 + 0x88) = 1;
  pcStack_68 = 0x0;
  if (pcStack_88 != 0x0) {
    (*pcStack_88)(&pvStack_78,apuStack_98,2);
    pcStack_68 = pcStack_88;
    puStack_60 = puStack_80;
  }
  pcStack_48 = 0x0;
  puVar10 = (undefined8*)(uintptr_t)(rea_operator_new(0x20));
  pcVar20 = pcStack_68;
  puVar10[2] = 0;
  pvVar5 = (void *)*puVar10;
  uVar6 = puVar10[1];
  *puVar10 = (undefined8)(uintptr_t)(pvStack_78);
  puVar10[1] = uStack_70;
  pcStack_68 = 0x0;
  uVar7 = puVar10[3];
  puVar10[2] = (undefined8)(uintptr_t)(pcVar20);
  puVar10[3] = (undefined8)(uintptr_t)(puStack_60);
  puVar14 = (undefined*)(uintptr_t)(PTR__M_manager_00324f88);
  uStack_58 = *(undefined8 *)(lVar15 + 0x90);
  uVar8 = *(undefined8 *)(lVar15 + 0x98);
  pcStack_48 = *(code **)(lVar15 + 0xa0);
  *(undefined8 **)(lVar15 + 0x90) = puVar10;
  *(undefined8 *)(lVar15 + 0x98) = uStack_50;
  *(undefined **)(lVar15 + 0xa0) = puVar14;
  puStack_40 = *(undefined **)(lVar15 + 0xa8);
  *(undefined **)(lVar15 + 0xa8) = PTR__M_invoke_00324fe0;
  pvStack_78 = pvVar5;
  uStack_70 = uVar6;
  puStack_60 = (undefined *)uVar7;
  uStack_50 = uVar8;
  if (pcStack_48 != 0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  if (pcStack_68 != 0x0) {
    (*pcStack_68)(&pvStack_78,&pvStack_78,3);
  }
  aiStack_a8[0] = *(int *)(lVar15 + 0x40);
  cVar3 = *(char *)(lVar15 + 0x88);
  lVar15 = *(long long *)(lVar15 + 0x38);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == 0x0) {
LAB_0010cb60:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, aiStack_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == 0x0)
        goto LAB_0010c2da;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != 0x0);
LAB_0010c2da:
    if ((p_Var12 == p_Var18) || (p_Var13 = p_Var12, aiStack_a8[0] < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cb60;
    do {
      while (p_Var16 = p_Var17, aiStack_a8[0] <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == 0x0)
        goto LAB_0010c30a;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != 0x0);
LAB_0010c30a:
    if ((p_Var12 == p_Var16) || (aiStack_a8[0] < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = rea_operator_new(0x28);
      if (p_Var17 != 0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = aiStack_a8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x8)));
      p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x0)));
      if (p_Var13 == 0x0) {
        rea_operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == 0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long long *)(lVar15 + 0x30) = *(long long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var17 = p_Var12;
  p_Var13 = p_Var16;
  uVar9 = uVar21;
  if (p_Var12 != 0x0) {
    do {
      while (p_Var18 = p_Var17, aiStack_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var13 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == 0x0)
        goto LAB_0010c37a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var2 != 0x0);
LAB_0010c37a:
    if ((p_Var16 != p_Var18) && (p_Var17 = p_Var16, *(int *)(p_Var18 + 0x20) <= aiStack_a8[0])) {
      do {
        while (p_Var13 = p_Var12, aiStack_a8[0] <= *(int *)(p_Var13 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
          p_Var17 = p_Var13;
          if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == 0x0)
          goto LAB_0010c3aa;
        }
        p_Var18 = p_Var13 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var13 = p_Var17;
      } while (*(_Rb_tree_node_base **)p_Var18 != 0x0);
LAB_0010c3aa:
      if ((p_Var16 == p_Var13) || (aiStack_a8[0] < *(int *)(p_Var13 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != 0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = aiStack_a8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var13,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
        p_Var17 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x8)));
        p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x0)));
        if (p_Var17 == 0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var13 == 0x0) && (p_Var16 != p_Var17)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var17 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var17,p_Var16);
          *(long long *)(lVar15 + 0x30) = *(long long *)(lVar15 + 0x30) + 1;
          p_Var13 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var13 + 0x24);
    }
  }
  uVar22 = uVar9 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffe;
  }
  if (uVar21 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,aiStack_a8);
  }
  else {
    p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var13 = p_Var16;
    p_Var17 = p_Var16;
    if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == 0x0) {
LAB_0010ca20:
      p_Var12 = rea_operator_new(0x28);
      if (p_Var12 != 0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = aiStack_a8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var1,p_Var17,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x8)));
      p_Var17 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x0)));
      if (p_Var13 == 0x0) {
        rea_operator_delete(p_Var12);
      }
      else {
        bVar19 = true;
        if ((p_Var17 == 0x0) && (p_Var16 != p_Var13)) {
          bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var16);
        *(long long *)(lVar15 + 0x30) = *(long long *)(lVar15 + 0x30) + 1;
        p_Var17 = p_Var12;
      }
    }
    else {
      do {
        while (p_Var17 = p_Var12, aiStack_a8[0] <= *(int *)(p_Var17 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var13 = p_Var17;
          if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == 0x0)
          goto LAB_0010c412;
        }
        p_Var18 = p_Var17 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var17 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != 0x0);
LAB_0010c412:
      if ((p_Var16 == p_Var17) || (aiStack_a8[0] < *(int *)(p_Var17 + 0x20))) goto LAB_0010ca20;
    }
    *(uint *)(p_Var17 + 0x24) = uVar22;
  }
  if (pcStack_88 != 0x0) {
    (*pcStack_88)(apuStack_98,apuStack_98,3);
  }
  pcStack_68 = 0x0;
  pvStack_78 = rea_operator_new(1);
  lVar15 = *(long long *)(this_ptr + 0x38);
  puStack_60 = PTR__M_invoke_00324fd8;
  pcStack_68 = (code *)PTR__M_manager_00324ef8;
  if (*(char *)(lVar15 + 0x5a) != '\0') {
    rea_fwrite((void*)(uintptr_t)("close(): send_flag != false\n"),1,0x1c,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar10 = *(undefined8 **)(lVar15 + 0x60);
  *(undefined1 *)(lVar15 + 0x5a) = 1;
  *(undefined8 *)(lVar15 + 0x60) = 0;
  if (puVar10 != 0x0) {
    if ((void *)*puVar10 != 0x0) {
      rea_operator_delete((void *)*puVar10);
    }
    rea_operator_delete(puVar10);
  }
  pcStack_48 = 0x0;
  if (pcStack_68 == 0x0) {
    pcVar20 = 0x0;
    puVar14 = puStack_40;
  }
  else {
    (*pcStack_68)(&uStack_58,&pvStack_78,2);
    puVar14 = puStack_60;
    pcVar20 = pcStack_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0x68);
  uVar7 = *(undefined8 *)(lVar15 + 0x70);
  pcStack_48 = *(code **)(lVar15 + 0x78);
  *(undefined8 *)(lVar15 + 0x68) = uStack_58;
  *(undefined8 *)(lVar15 + 0x70) = uStack_50;
  puStack_40 = *(undefined **)(lVar15 + 0x80);
  *(code **)(lVar15 + 0x78) = pcVar20;
  *(undefined **)(lVar15 + 0x80) = puVar14;
  uStack_58 = uVar6;
  uStack_50 = uVar7;
  if (pcStack_48 != 0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  cVar3 = *(char *)(lVar15 + 0x5a);
  iVar4 = *(int *)(lVar15 + 0x40);
  lVar15 = *(long long *)(lVar15 + 0x38);
  apuStack_98[0] = (undefined8 *)CONCAT44((undefined4)((uint64_t)(uintptr_t)apuStack_98[0] >> 32),iVar4);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == 0x0) {
LAB_0010cb40:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, iVar4 <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == 0x0)
        goto LAB_0010c58a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != 0x0);
LAB_0010c58a:
    if ((p_Var18 == p_Var12) || (p_Var13 = p_Var12, iVar4 < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cb40;
    do {
      while (p_Var16 = p_Var17, iVar4 <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == 0x0)
        goto LAB_0010c5ba;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != 0x0);
LAB_0010c5ba:
    if ((p_Var16 == p_Var12) || (iVar4 < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = rea_operator_new(0x28);
      if (p_Var17 != 0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = (int)(uintptr_t)apuStack_98[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x8)));
      p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x0)));
      if (p_Var13 == 0x0) {
        rea_operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == 0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long long *)(lVar15 + 0x30) = *(long long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var17 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  uVar9 = uVar21;
  if (p_Var12 != 0x0) {
    p_Var13 = p_Var12;
    p_Var16 = p_Var17;
    do {
      while (p_Var18 = p_Var13, (int)(uintptr_t)apuStack_98[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == 0x0)
        goto LAB_0010c62a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != 0x0);
LAB_0010c62a:
    if ((p_Var18 != p_Var17) && (p_Var13 = p_Var17, *(int *)(p_Var18 + 0x20) <= (int)(uintptr_t)apuStack_98[0])
       ) {
      do {
        while (p_Var16 = p_Var12, (int)(uintptr_t)apuStack_98[0] <= *(int *)(p_Var16 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
          p_Var13 = p_Var16;
          if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == 0x0)
          goto LAB_0010c65a;
        }
        p_Var18 = p_Var16 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var16 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != 0x0);
LAB_0010c65a:
      if ((p_Var16 == p_Var17) || ((int)(uintptr_t)apuStack_98[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != 0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = (int)(uintptr_t)apuStack_98[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var16,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
        p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x8)));
        p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x0)));
        if (p_Var13 == 0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var16 == 0x0) && (p_Var17 != p_Var13)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var17);
          *(long long *)(lVar15 + 0x30) = *(long long *)(lVar15 + 0x30) + 1;
          p_Var16 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar22 = uVar9 | 2;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffd;
  }
  if (uVar21 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,(int *)apuStack_98);
    goto LAB_0010c6db;
  }
  p_Var12 = p_Var17;
  if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == 0x0) {
LAB_0010cab0:
    p_Var13 = rea_operator_new(0x28);
    if (p_Var13 != 0x0) {
      *(undefined4 *)p_Var13 = 0;
      *(undefined8 *)(p_Var13 + 8) = 0;
      *(undefined8 *)(p_Var13 + 0x10) = 0;
      *(undefined8 *)(p_Var13 + 0x18) = 0;
      *(undefined4 *)(p_Var13 + 0x24) = 0;
      *(int *)(p_Var13 + 0x20) = (int)(uintptr_t)apuStack_98[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var1,p_Var12,p_Var13 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
    p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x8)));
    p_Var12 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar23 + 0x0)));
    if (p_Var16 == 0x0) {
      rea_operator_delete(p_Var13);
    }
    else {
      bVar19 = true;
      if ((p_Var12 == 0x0) && (p_Var17 != p_Var16)) {
        bVar19 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var13,p_Var16,p_Var17);
      *(long long *)(lVar15 + 0x30) = *(long long *)(lVar15 + 0x30) + 1;
      p_Var12 = p_Var13;
    }
  }
  else {
    p_Var13 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var16 = p_Var17;
    do {
      while (p_Var12 = p_Var13, (int)(uintptr_t)apuStack_98[0] <= *(int *)(p_Var12 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
        p_Var16 = p_Var12;
        if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == 0x0)
        goto LAB_0010c6c2;
      }
      p_Var18 = p_Var12 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var18;
      p_Var12 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var18 != 0x0);
LAB_0010c6c2:
    if ((p_Var12 == p_Var17) || ((int)(uintptr_t)apuStack_98[0] < *(int *)(p_Var12 + 0x20))) goto LAB_0010cab0;
  }
  *(uint *)(p_Var12 + 0x24) = uVar22;
LAB_0010c6db:
  if (pcStack_68 != 0x0) {
    (*pcStack_68)(&pvStack_78,&pvStack_78,3);
  }
  pcStack_68 = 0x0;
  pvStack_78 = rea_operator_new(1);
  lVar15 = *(long long *)(this_ptr + 0x38);
  pcStack_48 = 0x0;
  puStack_60 = PTR__M_invoke_00324fd0;
  pcStack_68 = (code *)PTR__M_manager_00324fc0;
  if (PTR__M_manager_00324fc0 == 0x0) {
    pcVar20 = 0x0;
    puVar14 = puStack_40;
  }
  else {
    std___Function_base___Base_manager_WSConn__exit__lambda__3___M_manager_______________(&uStack_58,&pvStack_78,2);
    puVar14 = puStack_60;
    pcVar20 = pcStack_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0xb0);
  uVar7 = *(undefined8 *)(lVar15 + 0xb8);
  pcStack_48 = *(code **)(lVar15 + 0xc0);
  *(undefined8 *)(lVar15 + 0xb0) = uStack_58;
  *(undefined8 *)(lVar15 + 0xb8) = uStack_50;
  puStack_40 = *(undefined **)(lVar15 + 200);
  *(code **)(lVar15 + 0xc0) = pcVar20;
  *(undefined **)(lVar15 + 200) = puVar14;
  uStack_58 = uVar6;
  uStack_50 = uVar7;
  if (pcStack_48 != 0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
    pcVar20 = pcStack_68;
  }
  if (pcVar20 != 0x0) {
    (*pcVar20)(&pvStack_78,&pvStack_78,3);
  }
  return;
}
