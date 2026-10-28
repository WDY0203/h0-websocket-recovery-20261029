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
// IDX 280  00119380  TcpConn__recv_proc
// ------------------------------------------------------------------
void rea_TcpConn__recv_proc__dup2(TcpConn * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var2;
  undefined8 uVar3;
  code *pcVar4;
  long long *plVar5;
  int iVar6;
  long long *plVar7;
  void *pvVar8;
  size_t sVar9;
  ssize_t sVar10;
  _Rb_tree_node_base *p_Var11;
  long long lVar12;
  _Rb_tree_node_base *p_Var13;
  ulong uVar14;
  int *piVar15;
  ulong uVar16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  undefined8 uVar19;
  ulong __n;
  void *pvVar20;
  bool bVar21;
  long long lVar22;
  _Rb_tree_node_base *p_Var23;
  uint uVar24;
  size_t __n_00;
  ulong uVar25;
  uint uVar26;
  undefined1 auVar27 [16];
  int local_88 [4];
  int local_78 [4];
  long long *local_68 [2];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  
  if (this_ptr[0x88] == (TcpConn)0x0) {
    rea_fprintf(*(FILE **)PTR_stderr_00324fb0,"TcpConn: bogus recv: fd=%d\n",
            (ulong)*(uint *)(this_ptr + 0x40));
    this_ptr[0x58] = (TcpConn)0x0;
    this_ptr[0x59] = (TcpConn)0x0;
    return;
  }
  plVar7 = (long long int*)(uintptr_t)(rea_operator_new(0x18));
  *plVar7 = 0;
  plVar7[1] = 0;
  plVar7[2] = 0;
  pvVar8 = rea_operator_new(0x8000);
  __n_00 = plVar7[1] - *plVar7;
  sVar9 = 0;
  if (__n_00 != 0) {
    rea_memmove(pvVar8,(void *)*plVar7,__n_00);
    sVar9 = __n_00;
  }
  rea_memset((void *)((long long)pvVar8 + sVar9),0,0x8000);
  if ((void *)*plVar7 != 0x0) {
    rea_operator_delete((void *)*plVar7);
  }
  iVar6 = *(int *)(this_ptr + 0x40);
  *plVar7 = (long long)pvVar8;
  plVar7[1] = (long long)((long long)pvVar8 + sVar9) + 0x8000;
  plVar7[2] = (long long)pvVar8 + 0x8000;
  sVar10 = rea_read(iVar6,pvVar8,0x8000);
  iVar6 = (int)sVar10;
  if (iVar6 == -1) {
    piVar15 = rea___errno_location();
    if (*piVar15 == 0xb) goto LAB_001197ee;
  }
  else if (-1 < iVar6) {
    if (iVar6 != 0) {
      pvVar8 = (void *)plVar7[1];
      pvVar20 = (void *)*plVar7;
      uVar14 = (ulong)iVar6;
      __n = (long long)pvVar8 - (long long)pvVar20;
      if (__n < uVar14) {
        uVar14 = uVar14 - __n;
        if (uVar14 != 0) {
          if ((ulong)(plVar7[2] - (long long)pvVar8) < uVar14) {
            if (~__n < uVar14) {
              uVar19 = rea_std____throw_length_error("vector___M_default_append");
              rea_FUN_00107834((undefined8*)(uintptr_t)(plVar7));
              if (local_48 != 0x0) {
                (*local_48)(&local_58,&local_58,3);
              }
                    /* WARNING: Subroutine does not return */
              rea__Unwind_Resume(uVar19);
            }
            uVar16 = __n;
            if (__n <= uVar14) {
              uVar16 = uVar14;
            }
            uVar25 = 0xffffffffffffffff;
            if ((CARRY8(uVar16,__n)) || (uVar25 = uVar16 + __n, uVar16 + __n != 0)) {
              pvVar8 = rea_operator_new(uVar25);
              pvVar20 = (void *)*plVar7;
              __n = plVar7[1] - (long long)pvVar20;
            }
            else {
              uVar25 = 0;
              pvVar8 = 0x0;
            }
            if (__n != 0) {
              rea_memmove(pvVar8,pvVar20,__n);
            }
            pvVar20 = (void *)((long long)pvVar8 + __n);
            rea_memset(pvVar20,0,(uVar14 + (long long)pvVar20) - (long long)pvVar20);
            if ((void *)*plVar7 != 0x0) {
              rea_operator_delete((void *)*plVar7);
            }
            *plVar7 = (long long)pvVar8;
            plVar7[1] = uVar14 + (long long)pvVar20;
            plVar7[2] = uVar25 + (long long)pvVar8;
          }
          else {
            rea_memset(pvVar8,0,uVar14);
            plVar7[1] = plVar7[1] + uVar14;
          }
        }
      }
      else if (uVar14 < __n) {
        plVar7[1] = uVar14 + (long long)pvVar20;
      }
      lVar22 = *(long long *)(this_ptr + 0x38);
      local_78[0] = *(int *)(this_ptr + 0x40);
      this_ptr[0x88] = (TcpConn)0x0;
      p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
      p_Var18 = p_Var11;
      p_Var23 = p_Var13;
      if (p_Var11 == 0x0) {
LAB_00119ce0:
        lVar12 = 0;
        uVar24 = 0;
      }
      else {
        do {
          while (p_Var17 = p_Var18, *(int *)(p_Var17 + 0x20) < local_78[0]) {
            p_Var1 = p_Var17 + 0x18;
            p_Var18 = *(_Rb_tree_node_base **)p_Var1;
            p_Var17 = p_Var23;
            if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_001198da;
          }
          p_Var18 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var23 = p_Var17;
        } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != 0x0);
LAB_001198da:
        if ((p_Var13 == p_Var17) || (p_Var18 = p_Var13, local_78[0] < *(int *)(p_Var17 + 0x20)))
        goto LAB_00119ce0;
        do {
          while (p_Var23 = p_Var11, *(int *)(p_Var23 + 0x20) < local_78[0]) {
            p_Var17 = p_Var23 + 0x18;
            p_Var11 = *(_Rb_tree_node_base **)p_Var17;
            p_Var23 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == 0x0) goto LAB_0011990a;
          }
          p_Var11 = *(_Rb_tree_node_base **)(p_Var23 + 0x10);
          p_Var18 = p_Var23;
        } while (*(_Rb_tree_node_base **)(p_Var23 + 0x10) != 0x0);
LAB_0011990a:
        if ((p_Var13 == p_Var23) || (local_78[0] < *(int *)(p_Var23 + 0x20))) {
          p_Var11 = rea_operator_new(0x28);
          if (p_Var11 != 0x0) {
            *(undefined4 *)p_Var11 = 0;
            *(undefined8 *)(p_Var11 + 8) = 0;
            *(undefined8 *)(p_Var11 + 0x10) = 0;
            *(undefined8 *)(p_Var11 + 0x18) = 0;
            *(undefined4 *)(p_Var11 + 0x24) = 0;
            *(int *)(p_Var11 + 0x20) = local_78[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos_______________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                *)(lVar22 + 8),p_Var23,p_Var11 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
          p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
          p_Var23 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
          if (p_Var18 == 0x0) {
            rea_operator_delete(p_Var11);
          }
          else {
            bVar21 = true;
            if ((p_Var23 == 0x0) && (p_Var13 != p_Var18)) {
              bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var18 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var18,p_Var13);
            *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
            p_Var23 = p_Var11;
          }
        }
        uVar24 = *(uint *)(p_Var23 + 0x24);
        lVar12 = 1;
      }
      lVar22 = lVar22 + (lVar12 + 1) * 0x30;
      p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                *)(lVar22 + 8);
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var23 = (_Rb_tree_node_base *)(lVar22 + 0x10);
      p_Var11 = p_Var13;
      p_Var18 = p_Var23;
      uVar26 = uVar24;
      if (p_Var13 != 0x0) {
        do {
          while (p_Var17 = p_Var11, *(int *)(p_Var17 + 0x20) < local_78[0]) {
            p_Var1 = p_Var17 + 0x18;
            p_Var11 = *(_Rb_tree_node_base **)p_Var1;
            p_Var17 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_001199ea;
          }
          p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var18 = p_Var17;
        } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != 0x0);
LAB_001199ea:
        if ((p_Var23 != p_Var17) && (p_Var11 = p_Var23, *(int *)(p_Var17 + 0x20) <= local_78[0])) {
          do {
            while (p_Var18 = p_Var13, *(int *)(p_Var18 + 0x20) < local_78[0]) {
              p_Var17 = p_Var18 + 0x18;
              p_Var13 = *(_Rb_tree_node_base **)p_Var17;
              p_Var18 = p_Var11;
              if (*(_Rb_tree_node_base **)p_Var17 == 0x0) goto LAB_00119a1a;
            }
            p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
            p_Var11 = p_Var18;
          } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != 0x0);
LAB_00119a1a:
          if ((p_Var23 == p_Var18) || (local_78[0] < *(int *)(p_Var18 + 0x20))) {
            p_Var13 = rea_operator_new(0x28);
            if (p_Var13 != 0x0) {
              *(undefined4 *)p_Var13 = 0;
              *(undefined8 *)(p_Var13 + 8) = 0;
              *(undefined8 *)(p_Var13 + 0x10) = 0;
              *(undefined8 *)(p_Var13 + 0x18) = 0;
              *(undefined4 *)(p_Var13 + 0x24) = 0;
              *(int *)(p_Var13 + 0x20) = local_78[0];
            }
            { auto &&__rea_tmp = (std__________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________________M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
            p_Var11 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
            p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
            if (p_Var11 == 0x0) {
              rea_operator_delete(p_Var13);
            }
            else {
              bVar21 = true;
              if ((p_Var18 == 0x0) && (p_Var23 != p_Var11)) {
                bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var11 + 0x20);
              }
              rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var11,p_Var23);
              *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
              p_Var18 = p_Var13;
            }
          }
          uVar26 = *(uint *)(p_Var18 + 0x24);
        }
      }
      if ((uVar26 & 0xfffffffe) == uVar24) {
        std____________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___________erase(p_Var2,local_78);
        goto LAB_00119b77;
      }
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var18 = p_Var23;
      p_Var11 = p_Var23;
      if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == 0x0) {
LAB_00119af5:
        p_Var13 = rea_operator_new(0x28);
        if (p_Var13 != 0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = local_78[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var11,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
        p_Var11 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
        if (p_Var18 == 0x0) {
          rea_operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var11 == 0x0) && (p_Var23 != p_Var18)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var18,p_Var23);
          *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
          p_Var11 = p_Var13;
        }
      }
      else {
        do {
          while (p_Var11 = p_Var13, *(int *)(p_Var11 + 0x20) < local_78[0]) {
            p_Var17 = p_Var11 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var11 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == 0x0) goto LAB_00119aea;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
          p_Var18 = p_Var11;
        } while (*(_Rb_tree_node_base **)(p_Var11 + 0x10) != 0x0);
LAB_00119aea:
        if ((p_Var23 == p_Var11) || (local_78[0] < *(int *)(p_Var11 + 0x20))) goto LAB_00119af5;
      }
      *(uint *)(p_Var11 + 0x24) = uVar26 & 0xfffffffe;
LAB_00119b77:
      uVar19 = *(undefined8 *)(this_ptr + 0x98);
      uVar3 = *(undefined8 *)(this_ptr + 0x90);
      local_48 = *(code **)(this_ptr + 0xa0);
      pcVar4 = *(code **)(this_ptr + 0xa8);
      *(undefined8 *)(this_ptr + 0x90) = local_58;
      *(undefined8 *)(this_ptr + 0x98) = local_50;
      *(undefined8 *)(this_ptr + 0xa0) = 0;
      *(code **)(this_ptr + 0xa8) = local_40;
      local_58 = uVar3;
      local_50 = uVar19;
      local_40 = pcVar4;
      if (local_48 == 0x0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_68[0] = plVar7;
      (*pcVar4)(&local_58,local_68);
      plVar7 = local_68[0];
      if (local_68[0] != 0x0) {
        if ((void *)*local_68[0] != 0x0) {
          rea_operator_delete((void *)*local_68[0]);
        }
        rea_operator_delete(plVar7);
      }
      if (local_48 == 0x0) {
        return;
      }
      (*local_48)(&local_58,&local_58,3);
      return;
    }
    lVar22 = *(long long *)(this_ptr + 0x38);
    local_88[0] = *(int *)(this_ptr + 0x40);
    this_ptr[0x58] = (TcpConn)0x0;
    this_ptr[0x88] = (TcpConn)0x0;
    p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
    p_Var18 = p_Var11;
    p_Var23 = p_Var13;
    if (p_Var11 == 0x0) {
LAB_00119cd0:
      lVar12 = 0;
      uVar24 = 0;
    }
    else {
      do {
        while (p_Var17 = p_Var18, *(int *)(p_Var17 + 0x20) < local_88[0]) {
          p_Var1 = p_Var17 + 0x18;
          p_Var18 = *(_Rb_tree_node_base **)p_Var1;
          p_Var17 = p_Var23;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011949a;
        }
        p_Var18 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var23 = p_Var17;
      } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != 0x0);
LAB_0011949a:
      if ((p_Var13 == p_Var17) || (p_Var18 = p_Var13, local_88[0] < *(int *)(p_Var17 + 0x20)))
      goto LAB_00119cd0;
      do {
        while (p_Var23 = p_Var11, *(int *)(p_Var23 + 0x20) < local_88[0]) {
          p_Var17 = p_Var23 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var17;
          p_Var23 = p_Var18;
          if (*(_Rb_tree_node_base **)p_Var17 == 0x0) goto LAB_001194ca;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var23 + 0x10);
        p_Var18 = p_Var23;
      } while (*(_Rb_tree_node_base **)(p_Var23 + 0x10) != 0x0);
LAB_001194ca:
      if ((p_Var13 == p_Var23) || (local_88[0] < *(int *)(p_Var23 + 0x20))) {
        p_Var11 = rea_operator_new(0x28);
        if (p_Var11 != 0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_88[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar22 + 8),p_Var23,p_Var11 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
        p_Var23 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
        if (p_Var18 == 0x0) {
          rea_operator_delete(p_Var11);
        }
        else {
          bVar21 = true;
          if ((p_Var23 == 0x0) && (p_Var13 != p_Var18)) {
            bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var18,p_Var13);
          *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
          p_Var23 = p_Var11;
        }
      }
      uVar24 = *(uint *)(p_Var23 + 0x24);
      lVar12 = 1;
    }
    lVar22 = lVar22 + (lVar12 + 1) * 0x30;
    p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar22 + 8);
    p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    p_Var23 = (_Rb_tree_node_base *)(lVar22 + 0x10);
    p_Var11 = p_Var13;
    p_Var18 = p_Var23;
    uVar26 = uVar24;
    if (p_Var13 != 0x0) {
      do {
        while (p_Var17 = p_Var11, *(int *)(p_Var17 + 0x20) < local_88[0]) {
          p_Var1 = p_Var17 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var1;
          p_Var17 = p_Var18;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_001195aa;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var18 = p_Var17;
      } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != 0x0);
LAB_001195aa:
      if ((p_Var23 != p_Var17) && (p_Var11 = p_Var23, *(int *)(p_Var17 + 0x20) <= local_88[0])) {
        do {
          while (p_Var18 = p_Var13, *(int *)(p_Var18 + 0x20) < local_88[0]) {
            p_Var17 = p_Var18 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var18 = p_Var11;
            if (*(_Rb_tree_node_base **)p_Var17 == 0x0) goto LAB_001195da;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
          p_Var11 = p_Var18;
        } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != 0x0);
LAB_001195da:
        if ((p_Var23 == p_Var18) || (local_88[0] < *(int *)(p_Var18 + 0x20))) {
          p_Var13 = rea_operator_new(0x28);
          if (p_Var13 != 0x0) {
            *(undefined4 *)p_Var13 = 0;
            *(undefined8 *)(p_Var13 + 8) = 0;
            *(undefined8 *)(p_Var13 + 0x10) = 0;
            *(undefined8 *)(p_Var13 + 0x18) = 0;
            *(undefined4 *)(p_Var13 + 0x24) = 0;
            *(int *)(p_Var13 + 0x20) = local_88[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
          p_Var11 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
          p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
          if (p_Var11 == 0x0) {
            rea_operator_delete(p_Var13);
          }
          else {
            bVar21 = true;
            if ((p_Var18 == 0x0) && (p_Var23 != p_Var11)) {
              bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var11 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var11,p_Var23);
            *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
            p_Var18 = p_Var13;
          }
        }
        uVar26 = *(uint *)(p_Var18 + 0x24);
      }
    }
    if ((uVar26 & 0xfffffffe) == uVar24) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var2,local_88);
    }
    else {
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var18 = p_Var23;
      p_Var11 = p_Var23;
      if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == 0x0) {
LAB_001196b5:
        p_Var13 = rea_operator_new(0x28);
        if (p_Var13 != 0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = local_88[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var11,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
        p_Var11 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
        if (p_Var18 == 0x0) {
          rea_operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var11 == 0x0) && (p_Var23 != p_Var18)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var18,p_Var23);
          *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
          p_Var11 = p_Var13;
        }
      }
      else {
        do {
          while (p_Var11 = p_Var13, *(int *)(p_Var11 + 0x20) < local_88[0]) {
            p_Var17 = p_Var11 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var11 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == 0x0) goto LAB_001196aa;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
          p_Var18 = p_Var11;
        } while (*(_Rb_tree_node_base **)(p_Var11 + 0x10) != 0x0);
LAB_001196aa:
        if ((p_Var23 == p_Var11) || (local_88[0] < *(int *)(p_Var11 + 0x20))) goto LAB_001196b5;
      }
      *(uint *)(p_Var11 + 0x24) = uVar26 & 0xfffffffe;
    }
    uVar19 = *(undefined8 *)(this_ptr + 0x98);
    uVar3 = *(undefined8 *)(this_ptr + 0x90);
    local_48 = *(code **)(this_ptr + 0xa0);
    pcVar4 = *(code **)(this_ptr + 0xa8);
    *(undefined8 *)(this_ptr + 0x90) = local_58;
    *(undefined8 *)(this_ptr + 0x98) = local_50;
    *(undefined8 *)(this_ptr + 0xa0) = 0;
    *(code **)(this_ptr + 0xa8) = local_40;
    local_58 = uVar3;
    local_50 = uVar19;
    local_40 = pcVar4;
    if (local_48 == 0x0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    local_68[0] = 0x0;
    (*pcVar4)(&local_58,local_68);
    plVar5 = local_68[0];
    if (local_68[0] != 0x0) {
      if ((void *)*local_68[0] != 0x0) {
        rea_operator_delete((void *)*local_68[0]);
      }
      rea_operator_delete(plVar5);
    }
    if (local_48 != 0x0) {
      (*local_48)(&local_58,&local_58,3);
    }
    goto LAB_001197ee;
  }
  rea_perror("tcp recv");
  iVar6 = *(int *)(this_ptr + 0x40);
  this_ptr[0x58] = (TcpConn)0x0;
  this_ptr[0x59] = (TcpConn)0x0;
  this_ptr[0x88] = (TcpConn)0x0;
  lVar22 = *(long long *)(this_ptr + 0x38);
  local_58 = CONCAT44((*(undefined4 *)((uint8_t *)&local_58 + 0x4)),iVar6);
  p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
  p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
  p_Var18 = p_Var11;
  p_Var23 = p_Var13;
  if (p_Var11 == 0x0) {
LAB_0011a090:
    lVar12 = 0;
    uVar24 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var18 + 0x20) < iVar6) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var23 = p_Var18;
      }
      p_Var18 = p_Var17;
    } while (p_Var17 != 0x0);
    if ((p_Var13 == p_Var23) || (p_Var18 = p_Var13, iVar6 < *(int *)(p_Var23 + 0x20)))
    goto LAB_0011a090;
    do {
      if (*(int *)(p_Var11 + 0x20) < iVar6) {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
      }
      else {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
        p_Var18 = p_Var11;
      }
      p_Var11 = p_Var23;
    } while (p_Var23 != 0x0);
    if ((p_Var13 == p_Var18) || (iVar6 < *(int *)(p_Var18 + 0x20))) {
      p_Var11 = rea_operator_new(0x28);
      if (p_Var11 != 0x0) {
        *(undefined4 *)p_Var11 = 0;
        *(undefined8 *)(p_Var11 + 8) = 0;
        *(undefined8 *)(p_Var11 + 0x10) = 0;
        *(undefined8 *)(p_Var11 + 0x18) = 0;
        *(undefined4 *)(p_Var11 + 0x24) = 0;
        *(int *)(p_Var11 + 0x20) = (int)local_58;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar22 + 8),p_Var18,p_Var11 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
      p_Var23 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
      p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
      if (p_Var23 == 0x0) {
        rea_operator_delete(p_Var11);
      }
      else {
        bVar21 = true;
        if ((p_Var18 == 0x0) && (p_Var13 != p_Var23)) {
          bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var23 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var23,p_Var13);
        *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
        p_Var18 = p_Var11;
      }
    }
    uVar24 = *(uint *)(p_Var18 + 0x24);
    lVar12 = 1;
  }
  lVar22 = lVar22 + (lVar12 + 1) * 0x30;
  p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar22 + 8);
  p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(lVar22 + 0x10);
  uVar26 = uVar24;
  if (p_Var13 != 0x0) {
    p_Var18 = p_Var13;
    p_Var23 = p_Var11;
    do {
      if (*(int *)(p_Var18 + 0x20) < (int)local_58) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var23 = p_Var18;
      }
      p_Var18 = p_Var17;
    } while (p_Var17 != 0x0);
    if ((p_Var11 != p_Var23) && (p_Var18 = p_Var11, *(int *)(p_Var23 + 0x20) <= (int)local_58)) {
      do {
        if (*(int *)(p_Var13 + 0x20) < (int)local_58) {
          p_Var23 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
        }
        else {
          p_Var23 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
          p_Var18 = p_Var13;
        }
        p_Var13 = p_Var23;
      } while (p_Var23 != 0x0);
      if ((p_Var11 == p_Var18) || ((int)local_58 < *(int *)(p_Var18 + 0x20))) {
        p_Var13 = rea_operator_new(0x28);
        if (p_Var13 != 0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = (int)local_58;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var23 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
        p_Var18 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
        if (p_Var23 == 0x0) {
          rea_operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var18 == 0x0) && (p_Var11 != p_Var23)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var23 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var23,p_Var11);
          *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
          p_Var18 = p_Var13;
        }
      }
      uVar26 = *(uint *)(p_Var18 + 0x24);
    }
  }
  if ((uVar26 & 0xfffffffe) == uVar24) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var2,(int *)&local_58);
    goto LAB_001197ee;
  }
  p_Var13 = p_Var11;
  if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == 0x0) {
LAB_00119ffb:
    p_Var18 = rea_operator_new(0x28);
    if (p_Var18 != 0x0) {
      *(undefined4 *)p_Var18 = 0;
      *(undefined8 *)(p_Var18 + 8) = 0;
      *(undefined8 *)(p_Var18 + 0x10) = 0;
      *(undefined8 *)(p_Var18 + 0x18) = 0;
      *(undefined4 *)(p_Var18 + 0x24) = 0;
      *(int *)(p_Var18 + 0x20) = (int)local_58;
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var2,p_Var13,p_Var18 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
    p_Var23 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x8)));
    p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar27 + 0x0)));
    if (p_Var23 == 0x0) {
      rea_operator_delete(p_Var18);
    }
    else {
      bVar21 = true;
      if ((p_Var13 == 0x0) && (p_Var11 != p_Var23)) {
        bVar21 = *(int *)(p_Var18 + 0x20) < *(int *)(p_Var23 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var18,p_Var23,p_Var11);
      *(long long *)(lVar22 + 0x30) = *(long long *)(lVar22 + 0x30) + 1;
      p_Var13 = p_Var18;
    }
  }
  else {
    p_Var18 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    do {
      if (*(int *)(p_Var18 + 0x20) < (int)local_58) {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var13 = p_Var18;
      }
      p_Var18 = p_Var23;
    } while (p_Var23 != 0x0);
    if ((p_Var11 == p_Var13) || ((int)local_58 < *(int *)(p_Var13 + 0x20))) goto LAB_00119ffb;
  }
  *(uint *)(p_Var13 + 0x24) = uVar26 & 0xfffffffe;
LAB_001197ee:
  if ((void *)*plVar7 != 0x0) {
    rea_operator_delete((void *)*plVar7);
  }
  rea_operator_delete(plVar7);
  return;
}
