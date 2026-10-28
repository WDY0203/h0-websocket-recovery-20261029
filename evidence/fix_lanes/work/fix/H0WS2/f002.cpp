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
// IDX 2  00106e80  WSConn__recv_pat
// ------------------------------------------------------------------
void rea_WSConn__recv_pat(WSConn * this_ptr, string * param_2, long long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  int *piVar2;
  char cVar3;
  void *__haystack;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  void *pvVar12;
  undefined8 *puVar13;
  _Rb_tree_node_base *p_Var14;
  long long lVar15;
  _Rb_tree_node_base *p_Var16;
  long long lVar17;
  _Rb_tree_node_base *p_Var18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  uint uVar22;
  uint uVar23;
  undefined1 auVar24 [16];
  int aiStack_c8 [4];
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  WSConn *pWStack_98;
  long long lStack_90;
  undefined1 auStack_88 [16];
  code *pcStack_78;
  undefined8 uStack_70;
  WSConn *pWStack_68;
  undefined *puStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  __haystack = (void *)**(undefined8 **)(this_ptr + 0x40);
  pvVar12 = rea_memmem(__haystack,(*(undefined8 **)(this_ptr + 0x40))[1] - (long long)__haystack,
                   *(void **)param_2,*(size_t *)((long long)*(void **)param_2 + -0x18));
  if (pvVar12 != 0x0) {
    if (*(long long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3,(long long)pvVar12 - (long long)__haystack);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  pWStack_98 = this_ptr;
  rea_std__string__string((string *)&lStack_90,param_2);
  pcStack_78 = 0x0;
  if (*(code **)(param_3 + 0x10) != 0x0) {
    (**(code **)(param_3 + 0x10))(auStack_88,param_3,2);
    pcStack_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
  }
  lVar17 = *(long long *)(this_ptr + 0x38);
  if (*(char *)(lVar17 + 0x88) != '\0') {
    rea_fwrite((void*)(uintptr_t)("recv(): recv_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar17 + 0x88) = 1;
  pWStack_68 = pWStack_98;
  rea_std__string__string((string *)&puStack_60,(string *)&lStack_90);
  pcStack_48 = 0x0;
  if (pcStack_78 != 0x0) {
    (*pcStack_78)(&uStack_58,auStack_88,2);
    pcStack_48 = pcStack_78;
    uStack_40 = uStack_70;
  }
  pcStack_a8 = 0x0;
  puVar13 = (undefined8*)(uintptr_t)(rea_operator_new(0x30));
  pcVar9 = pcStack_48;
  puVar8 = PTR__S_empty_rep_storage_00324fa0;
  *puVar13 = (undefined8)(uintptr_t)(pWStack_68);
  puVar13[1] = (undefined8)(uintptr_t)(puStack_60);
  puStack_60 = puVar8 + 0x18;
  puVar13[4] = 0;
  uVar4 = puVar13[2];
  uVar5 = puVar13[3];
  puVar13[2] = uStack_58;
  puVar13[3] = uStack_50;
  pcStack_48 = 0x0;
  uVar6 = puVar13[5];
  puVar13[4] = (undefined8)(uintptr_t)(pcVar9);
  puVar13[5] = uStack_40;
  uStack_b8 = *(undefined8 *)(lVar17 + 0x90);
  uVar7 = *(undefined8 *)(lVar17 + 0x98);
  pcStack_a8 = *(code **)(lVar17 + 0xa0);
  *(undefined8 *)(lVar17 + 0x98) = uStack_b0;
  *(undefined8 **)(lVar17 + 0x90) = puVar13;
  *(code **)(lVar17 + 0xa0) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010deb0);
  uStack_a0 = *(undefined8 *)(lVar17 + 0xa8);
  *(code **)(lVar17 + 0xa8) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00111f80);
  uStack_b0 = uVar7;
  uStack_58 = uVar4;
  uStack_50 = uVar5;
  uStack_40 = uVar6;
  if (pcStack_a8 != 0x0) {
    (*pcStack_a8)(&uStack_b8,&uStack_b8,3);
  }
  if (pcStack_48 != 0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  if ((allocator *)(puStack_60 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(puStack_60 + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar11 = *(int *)(puStack_60 + -8);
      *(int *)(puStack_60 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(puStack_60 + -0x18));
    }
  }
  cVar3 = *(char *)(lVar17 + 0x88);
  aiStack_c8[0] = *(int *)(lVar17 + 0x40);
  lVar17 = *(long long *)(lVar17 + 0x38);
  p_Var14 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var19 = p_Var14;
  p_Var18 = p_Var16;
  if (p_Var14 == 0x0) {
LAB_0010f530:
    lVar15 = 0;
    uVar23 = 0;
  }
  else {
    do {
      while (p_Var20 = p_Var19, *(int *)(p_Var20 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var19 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var18;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0010f43a;
      }
      p_Var19 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var18 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != 0x0);
LAB_0010f43a:
    if ((p_Var16 == p_Var20) || (p_Var19 = p_Var16, aiStack_c8[0] < *(int *)(p_Var20 + 0x20)))
    goto LAB_0010f530;
    do {
      while (p_Var18 = p_Var14, *(int *)(p_Var18 + 0x20) < aiStack_c8[0]) {
        p_Var20 = p_Var18 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var20;
        p_Var18 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == 0x0) goto LAB_0010f46a;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
      p_Var19 = p_Var18;
    } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != 0x0);
LAB_0010f46a:
    if ((p_Var16 == p_Var18) || (aiStack_c8[0] < *(int *)(p_Var18 + 0x20))) {
      p_Var14 = rea_operator_new(0x28);
      if (p_Var14 != 0x0) {
        *(undefined4 *)p_Var14 = 0;
        *(undefined8 *)(p_Var14 + 8) = 0;
        *(undefined8 *)(p_Var14 + 0x10) = 0;
        *(undefined8 *)(p_Var14 + 0x18) = 0;
        *(undefined4 *)(p_Var14 + 0x24) = 0;
        *(int *)(p_Var14 + 0x20) = aiStack_c8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar17 + 8),p_Var18,p_Var14 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
      p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar24 + 0x8)));
      p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar24 + 0x0)));
      if (p_Var19 == 0x0) {
        rea_operator_delete(p_Var14);
      }
      else {
        bVar21 = true;
        if ((p_Var18 == 0x0) && (p_Var16 != p_Var19)) {
          bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var19,p_Var16);
        *(long long *)(lVar17 + 0x30) = *(long long *)(lVar17 + 0x30) + 1;
        p_Var18 = p_Var14;
      }
    }
    uVar23 = *(uint *)(p_Var18 + 0x24);
    lVar15 = 1;
  }
  lVar17 = lVar17 + (lVar15 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar17 + 8);
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var18 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var14 = p_Var16;
  p_Var19 = p_Var18;
  uVar10 = uVar23;
  if (p_Var16 != 0x0) {
    do {
      while (p_Var20 = p_Var14, *(int *)(p_Var20 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0010f582;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != 0x0);
LAB_0010f582:
    if ((p_Var18 != p_Var20) && (p_Var14 = p_Var18, *(int *)(p_Var20 + 0x20) <= aiStack_c8[0])) {
      do {
        while (p_Var19 = p_Var16, *(int *)(p_Var19 + 0x20) < aiStack_c8[0]) {
          p_Var20 = p_Var19 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var20;
          p_Var19 = p_Var14;
          if (*(_Rb_tree_node_base **)p_Var20 == 0x0) goto LAB_0010f5ba;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var14 = p_Var19;
      } while (*(_Rb_tree_node_base **)(p_Var19 + 0x10) != 0x0);
LAB_0010f5ba:
      if ((p_Var18 == p_Var19) || (aiStack_c8[0] < *(int *)(p_Var19 + 0x20))) {
        p_Var16 = rea_operator_new(0x28);
        if (p_Var16 != 0x0) {
          *(undefined4 *)p_Var16 = 0;
          *(undefined8 *)(p_Var16 + 8) = 0;
          *(undefined8 *)(p_Var16 + 0x10) = 0;
          *(undefined8 *)(p_Var16 + 0x18) = 0;
          *(undefined4 *)(p_Var16 + 0x24) = 0;
          *(int *)(p_Var16 + 0x20) = aiStack_c8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var19,p_Var16 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
        p_Var14 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar24 + 0x8)));
        p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar24 + 0x0)));
        if (p_Var14 == 0x0) {
          rea_operator_delete(p_Var16);
        }
        else {
          bVar21 = true;
          if ((p_Var19 == 0x0) && (p_Var18 != p_Var14)) {
            bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var14 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var14,p_Var18);
          *(long long *)(lVar17 + 0x30) = *(long long *)(lVar17 + 0x30) + 1;
          p_Var19 = p_Var16;
        }
      }
      uVar10 = *(uint *)(p_Var19 + 0x24);
    }
  }
  uVar22 = uVar10 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar10 & 0xfffffffe;
  }
  if (uVar23 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_c8);
    goto LAB_0010f72d;
  }
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var19 = p_Var18;
  p_Var14 = p_Var18;
  if (*(_Rb_tree_node_base **)(lVar17 + 0x18) == 0x0) {
LAB_0010f6ad:
    p_Var16 = rea_operator_new(0x28);
    if (p_Var16 != 0x0) {
      *(undefined4 *)p_Var16 = 0;
      *(undefined8 *)(p_Var16 + 8) = 0;
      *(undefined8 *)(p_Var16 + 0x10) = 0;
      *(undefined8 *)(p_Var16 + 0x18) = 0;
      *(undefined4 *)(p_Var16 + 0x24) = 0;
      *(int *)(p_Var16 + 0x20) = aiStack_c8[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var14,p_Var16 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
    p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar24 + 0x8)));
    p_Var14 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar24 + 0x0)));
    if (p_Var19 == 0x0) {
      rea_operator_delete(p_Var16);
    }
    else {
      bVar21 = true;
      if ((p_Var14 == 0x0) && (p_Var18 != p_Var19)) {
        bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var19 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var19,p_Var18);
      *(long long *)(lVar17 + 0x30) = *(long long *)(lVar17 + 0x30) + 1;
      p_Var14 = p_Var16;
    }
  }
  else {
    do {
      while (p_Var14 = p_Var16, *(int *)(p_Var14 + 0x20) < aiStack_c8[0]) {
        p_Var20 = p_Var14 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var20;
        p_Var14 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == 0x0) goto LAB_0010f6a2;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var19 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != 0x0);
LAB_0010f6a2:
    if ((p_Var18 == p_Var14) || (aiStack_c8[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0010f6ad;
  }
  *(uint *)(p_Var14 + 0x24) = uVar22;
LAB_0010f72d:
  if (pcStack_78 != 0x0) {
    (*pcStack_78)(auStack_88,auStack_88,3);
  }
  if ((allocator *)(lStack_90 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(lStack_90 + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar11 = *(int *)(lStack_90 + -8);
      *(int *)(lStack_90 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lStack_90 + -0x18));
    }
  }
  return;
}
