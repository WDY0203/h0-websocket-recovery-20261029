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
// IDX 89  001073f0  WSConn__send
// ------------------------------------------------------------------
void rea_WSConn__send(WSConn * this_ptr, long long * param_2, long long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  long long *plVar11;
  ulong uVar12;
  ulong uVar13;
  long long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  void *pvVar17;
  void *pvVar18;
  ulong uVar19;
  undefined8 uVar20;
  _Rb_tree_node_base *p_Var21;
  _Rb_tree_node_base *p_Var22;
  ulong uVar23;
  bool bVar24;
  long long lVar25;
  _Rb_tree_node_base *p_Var26;
  uint uVar27;
  undefined1 auVar28 [16];
  ulong uStack_68;
  void *pvStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  puVar10 = (undefined8*)(uintptr_t)(rea_operator_new(0x18));
  *puVar10 = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar3 = *(undefined8 **)(this_ptr + 0x50);
  *(undefined8 **)(this_ptr + 0x50) = puVar10;
  if (puVar3 != 0x0) {
    if ((void *)*puVar3 != 0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  if (this_ptr[0x58] == (WSConn)0x0) {
    uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),0x81);
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
    plVar11 = (long long *)*param_2;
LAB_0011525a:
    uVar12 = plVar11[1] - *plVar11;
  }
  else {
    puVar3 = *(undefined8 **)(this_ptr + 0x68);
    uVar20 = *(undefined8 *)*param_2;
    uVar4 = ((undefined8 *)*param_2)[1];
    *puVar3 = uVar20;
    *(int *)(puVar3 + 1) = (int)uVar4 - (int)uVar20;
    plVar11 = (long long int*)(uintptr_t)(rea_operator_new(0x18));
    *plVar11 = 0;
    plVar11[1] = 0;
    plVar11[2] = 0;
    uVar12 = rea_deflateBound(*(undefined8 *)(this_ptr + 0x68));
    pvVar17 = (void *)plVar11[1];
    pvVar18 = (void *)*plVar11;
    uVar23 = (long long)pvVar17 - (long long)pvVar18;
    if (uVar23 < uVar12) {
      uVar12 = uVar12 - uVar23;
      if (uVar12 != 0) {
        if ((ulong)(plVar11[2] - (long long)pvVar17) < uVar12) {
          if (uVar12 <= ~uVar23) {
            uVar13 = uVar23;
            if (uVar23 <= uVar12) {
              uVar13 = uVar12;
            }
            uVar19 = 0xffffffffffffffff;
            if (CARRY8(uVar13,uVar23)) goto LAB_00115465;
            uVar19 = uVar13 + uVar23;
            if (uVar13 + uVar23 != 0) goto LAB_00115465;
            pvStack_60 = 0x0;
            uVar19 = 0;
            pvVar17 = pvVar18;
            goto LAB_00115483;
          }
          uVar20 = rea_std____throw_length_error("vector___M_default_append");
          rea_FUN_00107772((undefined8*)(uintptr_t)(plVar11));
                    /* WARNING: Subroutine does not return */
          rea__Unwind_Resume(uVar20);
        }
        rea_memset(pvVar17,0,uVar12);
        lVar14 = plVar11[1];
        pvVar18 = (void *)*plVar11;
        plVar11[1] = uVar12 + lVar14;
        uVar23 = (uVar12 + lVar14) - (long long)pvVar18;
      }
    }
    else if (uVar12 < uVar23) {
      plVar11[1] = (long long)pvVar18 + uVar12;
      uVar23 = ((long long)pvVar18 + uVar12) - (long long)pvVar18;
    }
    while( true ) {
      lVar14 = *(long long *)(this_ptr + 0x68);
      *(int *)(lVar14 + 0x20) = (int)uVar23;
      *(void **)(lVar14 + 0x18) = pvVar18;
      iVar8 = rea_deflate();
      if (iVar8 != 0) break;
      pvVar17 = (void *)plVar11[1];
      pvVar18 = (void *)*plVar11;
      uVar13 = (long long)pvVar17 - (long long)pvVar18;
      uVar12 = -(ulong)*(uint *)(*(long long *)(this_ptr + 0x68) + 0x20) - 4;
      uVar23 = uVar13 + uVar12;
      if (uVar23 <= uVar13) {
        if (uVar23 < uVar13) {
          plVar11[1] = uVar23 + (long long)pvVar18;
        }
        break;
      }
      if (uVar12 <= (ulong)(plVar11[2] - (long long)pvVar17)) {
        rea_memset(pvVar17,0,uVar12);
        plVar11[1] = plVar11[1] + uVar12;
        break;
      }
      if (uVar12 <= ~uVar13) {
        uStack_68 = 0xffffffffffffffff;
        uVar23 = uVar12;
        if (uVar12 <= uVar13) {
          uVar23 = uVar13;
        }
        if ((CARRY8(uVar23,uVar13)) || (uStack_68 = uVar23 + uVar13, uVar23 + uVar13 != 0)) {
          pvVar17 = rea_operator_new(uStack_68);
          pvVar18 = (void *)*plVar11;
          uVar13 = plVar11[1] - (long long)pvVar18;
        }
        else {
          uStack_68 = 0;
          pvVar17 = 0x0;
        }
        if (uVar13 != 0) {
          rea_memmove(pvVar17,pvVar18,uVar13);
        }
        pvVar18 = (void *)((long long)pvVar17 + uVar13);
        rea_memset(pvVar18,0,(uVar12 + (long long)pvVar18) - (long long)pvVar18);
        if ((void *)*plVar11 != 0x0) {
          rea_operator_delete((void *)*plVar11);
        }
        *plVar11 = (long long)pvVar17;
        plVar11[1] = uVar12 + (long long)pvVar18;
        plVar11[2] = (long long)pvVar17 + uStack_68;
        break;
      }
      uVar19 = rea_std____throw_length_error("vector___M_default_append");
LAB_00115465:
      pvStack_60 = rea_operator_new(uVar19);
      uVar23 = plVar11[1] - *plVar11;
      pvVar17 = (void *)*plVar11;
LAB_00115483:
      pvVar18 = pvStack_60;
      if (uVar23 != 0) {
        pvVar18 = rea_memmove(pvStack_60,pvVar17,uVar23);
      }
      pvVar17 = (void *)((long long)pvVar18 + uVar23);
      lVar14 = uVar12 + (long long)pvVar17;
      rea_memset(pvVar17,0,lVar14 - (long long)pvVar17);
      if ((void *)*plVar11 != 0x0) {
        rea_operator_delete((void *)*plVar11);
      }
      *plVar11 = (long long)pvVar18;
      plVar11[1] = lVar14;
      plVar11[2] = uVar19 + (long long)pvVar18;
      uVar23 = lVar14 - (long long)pvStack_60;
    }
    uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),0xc1);
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
    puVar3 = (undefined8 *)*param_2;
    *param_2 = (long long)plVar11;
    if (puVar3 == 0x0) goto LAB_0011525a;
    if ((void *)*puVar3 != 0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
    uVar12 = ((long long *)*param_2)[1] - *(long long *)*param_2;
  }
  if (0x7d < uVar12) {
    (*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)) = (undefined7)((ulong)uStack_58 >> 8);
    if (uVar12 < 0xffff) {
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '~';
    }
    else {
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\x7f';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = (uchar)(uVar12 >> 0x18);
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = (uchar)(uVar12 >> 0x10);
    }
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
    uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),(char)(uVar12 >> 8));
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
  }
  uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),(char)uVar12);
  rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
            (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
             (uchar *)&uStack_58);
  std__vector_unsigned_char_std__allocator_unsigned_char______M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char_____________(*(long long *)(this_ptr + 0x50),*(undefined8 *)(*(long long *)(this_ptr + 0x50) + 8),*(long long *)*param_2,
             *(long long *)*param_2 + uVar12);
  uVar20 = *(undefined8 *)(this_ptr + 0x50);
  *(undefined8 *)(this_ptr + 0x50) = 0;
  lVar14 = *(long long *)(this_ptr + 0x38);
  if (*(char *)(lVar14 + 0x5a) != '\0') {
    rea_fwrite((void*)(uintptr_t)("send(): send_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar3 = *(undefined8 **)(lVar14 + 0x60);
  *(undefined1 *)(lVar14 + 0x5a) = 1;
  *(undefined8 *)(lVar14 + 0x60) = uVar20;
  if (puVar3 != 0x0) {
    if ((void *)*puVar3 != 0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  pcStack_48 = 0x0;
  if (*(code **)(param_3 + 0x10) == 0x0) {
    uVar20 = 0;
  }
  else {
    (**(code **)(param_3 + 0x10))(&uStack_58,param_3,2);
    uStack_40 = *(undefined8 *)(param_3 + 0x18);
    uVar20 = *(undefined8 *)(param_3 + 0x10);
  }
  uVar4 = *(undefined8 *)(lVar14 + 0x68);
  uVar5 = *(undefined8 *)(lVar14 + 0x70);
  pcStack_48 = *(code **)(lVar14 + 0x78);
  *(undefined8 *)(lVar14 + 0x68) = uStack_58;
  *(undefined8 *)(lVar14 + 0x70) = uStack_50;
  uVar6 = *(undefined8 *)(lVar14 + 0x80);
  *(undefined8 *)(lVar14 + 0x78) = uVar20;
  *(undefined8 *)(lVar14 + 0x80) = uStack_40;
  uStack_58 = uVar4;
  uStack_50 = uVar5;
  uStack_40 = uVar6;
  if (pcStack_48 != 0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  lVar25 = *(long long *)(lVar14 + 0x38);
  iVar8 = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x5a);
  p_Var26 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  uStack_58 = CONCAT44((*(undefined4 *)((uint8_t *)&uStack_58 + 0x4)),iVar8);
  p_Var15 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  p_Var16 = p_Var26;
  p_Var21 = p_Var15;
  if (p_Var26 == 0x0) {
LAB_001153b0:
    lVar14 = 0;
    uVar27 = 0;
  }
  else {
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < iVar8) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00114fcb;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != 0x0);
LAB_00114fcb:
    if ((p_Var15 == p_Var22) || (p_Var16 = p_Var15, iVar8 < *(int *)(p_Var22 + 0x20)))
    goto LAB_001153b0;
    do {
      while (p_Var21 = p_Var26, *(int *)(p_Var21 + 0x20) < iVar8) {
        p_Var22 = p_Var21 + 0x18;
        p_Var26 = *(_Rb_tree_node_base **)p_Var22;
        p_Var21 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var22 == 0x0) goto LAB_00115003;
      }
      p_Var26 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
      p_Var16 = p_Var21;
    } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != 0x0);
LAB_00115003:
    if ((p_Var15 == p_Var21) || (iVar8 < *(int *)(p_Var21 + 0x20))) {
      p_Var26 = rea_operator_new(0x28);
      if (p_Var26 != 0x0) {
        *(undefined4 *)p_Var26 = 0;
        *(undefined8 *)(p_Var26 + 8) = 0;
        *(undefined8 *)(p_Var26 + 0x10) = 0;
        *(undefined8 *)(p_Var26 + 0x18) = 0;
        *(undefined4 *)(p_Var26 + 0x24) = 0;
        *(int *)(p_Var26 + 0x20) = (int)uStack_58;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar25 + 8),p_Var21,p_Var26 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
      p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar28 + 0x8)));
      p_Var21 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar28 + 0x0)));
      if (p_Var16 == 0x0) {
        rea_operator_delete(p_Var26);
      }
      else {
        bVar24 = true;
        if ((p_Var21 == 0x0) && (p_Var15 != p_Var16)) {
          bVar24 = *(int *)(p_Var26 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var26,p_Var16,p_Var15);
        *(long long *)(lVar25 + 0x30) = *(long long *)(lVar25 + 0x30) + 1;
        p_Var21 = p_Var26;
      }
    }
    uVar27 = *(uint *)(p_Var21 + 0x24);
    lVar14 = 1;
  }
  lVar25 = lVar25 + (lVar14 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar25 + 8);
  p_Var15 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  p_Var26 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  uVar9 = uVar27;
  if (p_Var15 != 0x0) {
    p_Var16 = p_Var15;
    p_Var21 = p_Var26;
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < (int)uStack_58) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00115073;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != 0x0);
LAB_00115073:
    if ((p_Var26 != p_Var22) && (p_Var16 = p_Var26, *(int *)(p_Var22 + 0x20) <= (int)uStack_58)) {
      do {
        while (p_Var21 = p_Var15, *(int *)(p_Var21 + 0x20) < (int)uStack_58) {
          p_Var22 = p_Var21 + 0x18;
          p_Var15 = *(_Rb_tree_node_base **)p_Var22;
          p_Var21 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var22 == 0x0) goto LAB_001150ab;
        }
        p_Var15 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
        p_Var16 = p_Var21;
      } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != 0x0);
LAB_001150ab:
      if ((p_Var26 == p_Var21) || ((int)uStack_58 < *(int *)(p_Var21 + 0x20))) {
        p_Var15 = rea_operator_new(0x28);
        if (p_Var15 != 0x0) {
          *(undefined4 *)p_Var15 = 0;
          *(undefined8 *)(p_Var15 + 8) = 0;
          *(undefined8 *)(p_Var15 + 0x10) = 0;
          *(undefined8 *)(p_Var15 + 0x18) = 0;
          *(undefined4 *)(p_Var15 + 0x24) = 0;
          *(int *)(p_Var15 + 0x20) = (int)uStack_58;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var21,p_Var15 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
        p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar28 + 0x8)));
        p_Var21 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar28 + 0x0)));
        if (p_Var16 == 0x0) {
          rea_operator_delete(p_Var15);
        }
        else {
          bVar24 = true;
          if ((p_Var21 == 0x0) && (p_Var26 != p_Var16)) {
            bVar24 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var16 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var15,p_Var16,p_Var26);
          *(long long *)(lVar25 + 0x30) = *(long long *)(lVar25 + 0x30) + 1;
          p_Var21 = p_Var15;
        }
      }
      uVar9 = *(uint *)(p_Var21 + 0x24);
    }
  }
  uVar7 = uVar9 | 2;
  if (cVar2 == '\0') {
    uVar7 = uVar9 & 0xfffffffd;
  }
  if (uVar27 == uVar7) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,(int *)&uStack_58);
    return;
  }
  p_Var15 = p_Var26;
  if (*(_Rb_tree_node_base **)(lVar25 + 0x18) != 0x0) {
    p_Var16 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
    p_Var21 = p_Var26;
    do {
      while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < (int)uStack_58) {
        p_Var22 = p_Var15 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var22;
        p_Var15 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var22 == 0x0) goto LAB_00115182;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var21 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != 0x0);
LAB_00115182:
    if ((p_Var26 != p_Var15) && (*(int *)(p_Var15 + 0x20) <= (int)uStack_58)) goto LAB_00115225;
  }
  p_Var16 = rea_operator_new(0x28);
  if (p_Var16 != 0x0) {
    *(undefined4 *)p_Var16 = 0;
    *(undefined8 *)(p_Var16 + 8) = 0;
    *(undefined8 *)(p_Var16 + 0x10) = 0;
    *(undefined8 *)(p_Var16 + 0x18) = 0;
    *(undefined4 *)(p_Var16 + 0x24) = 0;
    *(int *)(p_Var16 + 0x20) = (int)uStack_58;
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var16 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
  p_Var21 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar28 + 0x8)));
  p_Var15 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar28 + 0x0)));
  if (p_Var21 == 0x0) {
    rea_operator_delete(p_Var16);
  }
  else {
    bVar24 = true;
    if ((p_Var15 == 0x0) && (p_Var26 != p_Var21)) {
      bVar24 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var21 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var16,p_Var21,p_Var26);
    *(long long *)(lVar25 + 0x30) = *(long long *)(lVar25 + 0x30) + 1;
    p_Var15 = p_Var16;
  }
LAB_00115225:
  *(uint *)(p_Var15 + 0x24) = uVar7;
  return;
}
