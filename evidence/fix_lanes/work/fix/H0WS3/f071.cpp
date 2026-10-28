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
// IDX 71  00107360  std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char(vector_unsigned_char_std__allocator_unsigned_char * this_ptr, uchar * param_1)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  char cVar2;
  uchar *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  uint uVar7;
  ulong uVar8;
  void *__dest;
  size_t __n;
  long long *plVar9;
  _Rb_tree_node_base *p_Var10;
  long long lVar11;
  _Rb_tree_node_base *p_Var12;
  long long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  void *__src;
  char *pcVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  undefined1 auVar22 [16];
  int aiStack_a0 [4];
  undefined8 uStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined8 uStack_78;
  vector_unsigned_char_std__allocator_unsigned_char *pvStack_68;
  
  puVar3 = *(uchar **)(this_ptr + 8);
  if (puVar3 != *(uchar **)(this_ptr + 0x10)) {
    if (puVar3 == 0x0) {
      lVar13 = 0;
    }
    else {
      *puVar3 = *param_1;
      lVar13 = *(long long *)(this_ptr + 8);
    }
    *(long long *)(this_ptr + 8) = lVar13 + 1;
    return;
  }
  uVar8 = (long long)puVar3 - *(long long *)this_ptr;
  if (uVar8 != 0xffffffffffffffff) {
    uVar19 = 1;
    if (uVar8 != 0) {
      uVar19 = 0xffffffffffffffff;
      if (uVar8 <= uVar8 * 2) {
        uVar19 = uVar8 * 2;
      }
    }
    __dest = rea_operator_new(uVar19);
    __src = *(void **)this_ptr;
    __n = *(long long *)(this_ptr + 8) - (long long)__src;
    if ((uchar *)((long long)__dest + __n) == 0x0) {
      lVar13 = 0;
    }
    else {
      *(uchar *)((long long)__dest + __n) = *param_1;
      __src = *(void **)this_ptr;
      __n = *(long long *)(this_ptr + 8) - (long long)__src;
      lVar13 = (long long)__dest + __n;
    }
    if (__n != 0) {
      rea_memmove(__dest,__src,__n);
      __src = *(void **)this_ptr;
    }
    if (__src != 0x0) {
      rea_operator_delete(__src);
    }
    *(void **)this_ptr = __dest;
    *(long long *)(this_ptr + 8) = lVar13 + 1;
    *(ulong *)(this_ptr + 0x10) = (long long)__dest + uVar19;
    return;
  }
  pcVar18 = "vector___M_emplace_back_aux";
  rea_std____throw_length_error("vector___M_emplace_back_aux");
  puVar4 = *(undefined8 **)param_1;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  if (puVar4 == 0x0) {
    return;
  }
  lVar13 = **(long long **)pcVar18;
  pvStack_68 = this_ptr;
  if (*(char *)(lVar13 + 0x88) != '\0') {
    rea_fwrite((void*)(uintptr_t)("recv(): recv_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar13 + 0x88) = 1;
  pcStack_80 = 0x0;
  plVar9 = (long long int*)(uintptr_t)(rea_operator_new(8));
  *plVar9 = lVar13;
  puVar6 = PTR__M_manager_00324f68;
  uVar5 = *(undefined8 *)(lVar13 + 0x98);
  uStack_90 = *(undefined8 *)(lVar13 + 0x90);
  *(undefined8 *)(lVar13 + 0x98) = uStack_88;
  pcStack_80 = *(code **)(lVar13 + 0xa0);
  *(undefined **)(lVar13 + 0xa0) = puVar6;
  uStack_78 = *(undefined8 *)(lVar13 + 0xa8);
  *(long long **)(lVar13 + 0x90) = plVar9;
  *(undefined **)(lVar13 + 0xa8) = PTR__M_invoke_00324f40;
  uStack_88 = uVar5;
  if (pcStack_80 != 0x0) {
    (*pcStack_80)(&uStack_90,&uStack_90,3);
  }
  aiStack_a0[0] = *(int *)(lVar13 + 0x40);
  cVar2 = *(char *)(lVar13 + 0x88);
  lVar13 = *(long long *)(lVar13 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var15 = p_Var10;
  p_Var14 = p_Var12;
  if (p_Var10 == 0x0) {
LAB_00115f7b:
    lVar11 = 0;
    uVar20 = 0;
  }
  else {
    do {
      while (p_Var16 = p_Var15, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var15 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var14;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00115f6a;
      }
      p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var14 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != 0x0);
LAB_00115f6a:
    if ((p_Var12 == p_Var16) || (p_Var15 = p_Var12, aiStack_a0[0] < *(int *)(p_Var16 + 0x20)))
    goto LAB_00115f7b;
    do {
      while (p_Var14 = p_Var10, *(int *)(p_Var14 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var14 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var16;
        p_Var14 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == 0x0) goto LAB_0011613a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var15 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != 0x0);
LAB_0011613a:
    if ((p_Var12 == p_Var14) || (aiStack_a0[0] < *(int *)(p_Var14 + 0x20))) {
      p_Var10 = rea_operator_new(0x28);
      if (p_Var10 != 0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = aiStack_a0[0];
      }
      { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar13 + 8),p_Var14,p_Var10 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
      p_Var15 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar22 + 0x8)));
      p_Var14 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar22 + 0x0)));
      if (p_Var15 == 0x0) {
        rea_operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == 0x0) && (p_Var12 != p_Var15)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var15 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var15,p_Var12);
        *(long long *)(lVar13 + 0x30) = *(long long *)(lVar13 + 0x30) + 1;
        p_Var14 = p_Var10;
      }
    }
    uVar20 = *(uint *)(p_Var14 + 0x24);
    lVar11 = 1;
  }
  lVar13 = lVar13 + (lVar11 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar13 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var10 = p_Var12;
  p_Var15 = p_Var14;
  uVar7 = uVar20;
  if (p_Var12 != 0x0) {
    do {
      while (p_Var16 = p_Var10, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00115fca;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var15 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != 0x0);
LAB_00115fca:
    if ((p_Var14 != p_Var16) && (p_Var10 = p_Var14, *(int *)(p_Var16 + 0x20) <= aiStack_a0[0])) {
      do {
        while (p_Var15 = p_Var12, *(int *)(p_Var15 + 0x20) < aiStack_a0[0]) {
          p_Var16 = p_Var15 + 0x18;
          p_Var12 = *(_Rb_tree_node_base **)p_Var16;
          p_Var15 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var16 == 0x0) goto LAB_00115ffa;
        }
        p_Var12 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var10 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != 0x0);
LAB_00115ffa:
      if ((p_Var14 == p_Var15) || (aiStack_a0[0] < *(int *)(p_Var15 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != 0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
        }
        { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var12 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
        p_Var10 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar22 + 0x8)));
        p_Var15 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar22 + 0x0)));
        if (p_Var10 == 0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar17 = true;
          if ((p_Var15 == 0x0) && (p_Var14 != p_Var10)) {
            bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var10,p_Var14);
          *(long long *)(lVar13 + 0x30) = *(long long *)(lVar13 + 0x30) + 1;
          p_Var15 = p_Var12;
        }
      }
      uVar7 = *(uint *)(p_Var15 + 0x24);
    }
  }
  uVar21 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar21 = uVar7 & 0xfffffffe;
  }
  if (uVar20 == uVar21) {
    _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_a0);
    goto LAB_001160f3;
  }
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var15 = p_Var14;
  p_Var10 = p_Var14;
  if (*(_Rb_tree_node_base **)(lVar13 + 0x18) == 0x0) {
LAB_00116200:
    p_Var12 = rea_operator_new(0x28);
    if (p_Var12 != 0x0) {
      *(undefined4 *)p_Var12 = 0;
      *(undefined8 *)(p_Var12 + 8) = 0;
      *(undefined8 *)(p_Var12 + 0x10) = 0;
      *(undefined8 *)(p_Var12 + 0x18) = 0;
      *(undefined4 *)(p_Var12 + 0x24) = 0;
      *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
    }
    { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var12 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
    p_Var15 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar22 + 0x8)));
    p_Var10 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar22 + 0x0)));
    if (p_Var15 == 0x0) {
      rea_operator_delete(p_Var12);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == 0x0) && (p_Var14 != p_Var15)) {
        bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var15 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var15,p_Var14);
      *(long long *)(lVar13 + 0x30) = *(long long *)(lVar13 + 0x30) + 1;
      p_Var10 = p_Var12;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var12, *(int *)(p_Var10 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var10 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var16;
        p_Var10 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == 0x0) goto LAB_001160da;
      }
      p_Var12 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var15 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != 0x0);
LAB_001160da:
    if ((p_Var14 == p_Var10) || (aiStack_a0[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00116200;
  }
  *(uint *)(p_Var10 + 0x24) = uVar21;
LAB_001160f3:
  if ((void *)*puVar4 != 0x0) {
    rea_operator_delete((void *)*puVar4);
  }
  rea_operator_delete(puVar4);
  return;
}
