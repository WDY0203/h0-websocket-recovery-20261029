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
// IDX 91  00107410  WSConn__recv_more
// ------------------------------------------------------------------
void rea_WSConn__recv_more(WSConn * this_ptr, ulong param_1, long long param_3)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  long long lVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  code *pcVar12;
  _Rb_tree_node_base *p_Var13;
  long long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auVar20 [16];
  int aiStack_c8 [4];
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  WSConn *pWStack_98;
  ulong uStack_90;
  undefined1 auStack_88 [16];
  code *pcStack_78;
  undefined8 uStack_70;
  WSConn *pWStack_68;
  ulong uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  if (param_1 <= (ulong)((*(long long **)(this_ptr + 0x40))[1] - **(long long **)(this_ptr + 0x40))) {
    if (*(long long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  pcStack_78 = 0x0;
  pWStack_98 = this_ptr;
  uStack_90 = param_1;
  if (*(code **)(param_3 + 0x10) == 0x0) {
    pcVar12 = 0x0;
  }
  else {
    (**(code **)(param_3 + 0x10))(auStack_88,param_3,2);
    pcStack_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
    pcVar12 = *(code **)(param_3 + 0x10);
  }
  lVar14 = *(long long *)(this_ptr + 0x38);
  if (*(char *)(lVar14 + 0x88) != '\0') {
    rea_fwrite((void*)(uintptr_t)("recv(): recv_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
    pcVar12 = pcStack_78;
  }
  *(undefined1 *)(lVar14 + 0x88) = 1;
  pcStack_48 = 0x0;
  pWStack_68 = pWStack_98;
  uStack_60 = uStack_90;
  if (pcVar12 != 0x0) {
    (*pcVar12)(&uStack_58,auStack_88,2);
    pcStack_48 = pcStack_78;
    uStack_40 = uStack_70;
  }
  pcStack_a8 = 0x0;
  puVar8 = (undefined8*)(uintptr_t)(rea_operator_new(0x30));
  pcVar12 = pcStack_48;
  puVar8[4] = 0;
  uVar3 = puVar8[2];
  uVar4 = puVar8[3];
  uVar5 = puVar8[5];
  *puVar8 = (undefined8)(uintptr_t)(pWStack_68);
  puVar8[1] = uStack_60;
  puVar8[3] = uStack_50;
  puVar8[2] = uStack_58;
  pcStack_48 = 0x0;
  puVar8[4] = (undefined8)(uintptr_t)(pcVar12);
  puVar8[5] = uStack_40;
  uStack_b8 = *(undefined8 *)(lVar14 + 0x90);
  uVar6 = *(undefined8 *)(lVar14 + 0x98);
  *(undefined8 *)(lVar14 + 0x98) = uStack_b0;
  *(undefined8 **)(lVar14 + 0x90) = puVar8;
  pcStack_a8 = *(code **)(lVar14 + 0xa0);
  uStack_a0 = *(undefined8 *)(lVar14 + 0xa8);
  *(code **)(lVar14 + 0xa0) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010e430);
  *(code **)(lVar14 + 0xa8) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00111c50);
  uStack_b0 = uVar6;
  uStack_58 = uVar3;
  uStack_50 = uVar4;
  uStack_40 = uVar5;
  if (pcStack_a8 != 0x0) {
    (*pcStack_a8)(&uStack_b8,&uStack_b8,3);
  }
  if (pcStack_48 != 0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  aiStack_c8[0] = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x88);
  lVar14 = *(long long *)(lVar14 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var16 = p_Var10;
  p_Var15 = p_Var11;
  if (p_Var10 == 0x0) {
LAB_001103f0:
    lVar9 = 0;
    uVar18 = 0;
  }
  else {
    do {
      while (p_Var13 = p_Var16, *(int *)(p_Var13 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_001100b3;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var15 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != 0x0);
LAB_001100b3:
    if ((p_Var11 == p_Var13) || (p_Var16 = p_Var11, aiStack_c8[0] < *(int *)(p_Var13 + 0x20)))
    goto LAB_001103f0;
    do {
      while (p_Var15 = p_Var10, *(int *)(p_Var15 + 0x20) < aiStack_c8[0]) {
        p_Var13 = p_Var15 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var13;
        p_Var15 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == 0x0) goto LAB_001100eb;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var16 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != 0x0);
LAB_001100eb:
    if ((p_Var11 == p_Var15) || (aiStack_c8[0] < *(int *)(p_Var15 + 0x20))) {
      p_Var10 = rea_operator_new(0x28);
      if (p_Var10 != 0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = aiStack_c8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar14 + 8),p_Var15,p_Var10 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
      p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar20 + 0x8)));
      p_Var15 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar20 + 0x0)));
      if (p_Var16 == 0x0) {
        rea_operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var15 == 0x0) && (p_Var11 != p_Var16)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var16,p_Var11);
        *(long long *)(lVar14 + 0x30) = *(long long *)(lVar14 + 0x30) + 1;
        p_Var15 = p_Var10;
      }
    }
    uVar18 = *(uint *)(p_Var15 + 0x24);
    lVar9 = 1;
  }
  lVar14 = lVar14 + (lVar9 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar14 + 8);
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var15 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var10 = p_Var11;
  p_Var16 = p_Var15;
  uVar7 = uVar18;
  if (p_Var11 != 0x0) {
    do {
      while (p_Var13 = p_Var10, *(int *)(p_Var13 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011015a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != 0x0);
LAB_0011015a:
    if ((p_Var15 != p_Var13) && (p_Var10 = p_Var15, *(int *)(p_Var13 + 0x20) <= aiStack_c8[0])) {
      do {
        while (p_Var16 = p_Var11, *(int *)(p_Var16 + 0x20) < aiStack_c8[0]) {
          p_Var13 = p_Var16 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var13;
          p_Var16 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var13 == 0x0) goto LAB_0011018a;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var10 = p_Var16;
      } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != 0x0);
LAB_0011018a:
      if ((p_Var15 == p_Var16) || (aiStack_c8[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var11 = rea_operator_new(0x28);
        if (p_Var11 != 0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = aiStack_c8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var16,p_Var11 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
        p_Var10 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar20 + 0x8)));
        p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar20 + 0x0)));
        if (p_Var10 == 0x0) {
          rea_operator_delete(p_Var11);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == 0x0) && (p_Var15 != p_Var10)) {
            bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var10,p_Var15);
          *(long long *)(lVar14 + 0x30) = *(long long *)(lVar14 + 0x30) + 1;
          p_Var16 = p_Var11;
        }
      }
      uVar7 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar19 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar19 = uVar7 & 0xfffffffe;
  }
  if (uVar18 == uVar19) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_c8);
    goto LAB_00110208;
  }
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var16 = p_Var15;
  p_Var10 = p_Var15;
  if (*(_Rb_tree_node_base **)(lVar14 + 0x18) == 0x0) {
LAB_00110360:
    p_Var11 = rea_operator_new(0x28);
    if (p_Var11 != 0x0) {
      *(undefined4 *)p_Var11 = 0;
      *(undefined8 *)(p_Var11 + 8) = 0;
      *(undefined8 *)(p_Var11 + 0x10) = 0;
      *(undefined8 *)(p_Var11 + 0x18) = 0;
      *(undefined4 *)(p_Var11 + 0x24) = 0;
      *(int *)(p_Var11 + 0x20) = aiStack_c8[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var11 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
    p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar20 + 0x8)));
    p_Var10 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar20 + 0x0)));
    if (p_Var16 == 0x0) {
      rea_operator_delete(p_Var11);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == 0x0) && (p_Var15 != p_Var16)) {
        bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var16,p_Var15);
      *(long long *)(lVar14 + 0x30) = *(long long *)(lVar14 + 0x30) + 1;
      p_Var10 = p_Var11;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var11, *(int *)(p_Var10 + 0x20) < aiStack_c8[0]) {
        p_Var13 = p_Var10 + 0x18;
        p_Var11 = *(_Rb_tree_node_base **)p_Var13;
        p_Var10 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == 0x0) goto LAB_001101f2;
      }
      p_Var11 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var16 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != 0x0);
LAB_001101f2:
    if ((p_Var15 == p_Var10) || (aiStack_c8[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00110360;
  }
  *(uint *)(p_Var10 + 0x24) = uVar19;
LAB_00110208:
  if (pcStack_78 != 0x0) {
    (*pcStack_78)(auStack_88,auStack_88,3);
  }
  return;
}
