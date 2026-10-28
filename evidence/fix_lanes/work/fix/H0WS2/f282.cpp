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
// IDX 282  0011ac10  TcpConn__send_proc
// ------------------------------------------------------------------
void rea_TcpConn__send_proc__dup2(TcpConn * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  void *__src;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var2;
  undefined8 *puVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  ssize_t sVar10;
  long long lVar11;
  _Rb_tree_node_base *p_Var12;
  void *__dest;
  int *piVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  long long lVar18;
  _Rb_tree_node_base *p_Var19;
  uint uVar20;
  undefined1 auVar21 [16];
  int local_78 [4];
  int local_68 [4];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  
  if (this_ptr[0x5a] == (TcpConn)0x0) {
    rea_fprintf(*(FILE **)PTR_stderr_00324fb0,"TcpConn: bogus send: fd=%d\n",
            (ulong)*(uint *)(this_ptr + 0x40));
    return;
  }
  puVar3 = *(undefined8 **)(this_ptr + 0x60);
  if (puVar3 == 0x0) {
    this_ptr[0x59] = (TcpConn)0x0;
    rea_shutdown(*(int *)(this_ptr + 0x40),1);
    lVar18 = *(long long *)(this_ptr + 0x38);
    local_68[0] = *(int *)(this_ptr + 0x40);
    this_ptr[0x5a] = (TcpConn)0x0;
    p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var16 = p_Var14;
    p_Var19 = p_Var12;
    if (p_Var14 == 0x0) {
LAB_0011b430:
      lVar11 = 0;
      uVar20 = 0;
    }
    else {
      do {
        while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < local_68[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var19;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011b17b;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var19 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != 0x0);
LAB_0011b17b:
      if ((p_Var12 == p_Var15) || (p_Var16 = p_Var12, local_68[0] < *(int *)(p_Var15 + 0x20)))
      goto LAB_0011b430;
      do {
        if (*(int *)(p_Var14 + 0x20) < local_68[0]) {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
        }
        else {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
          p_Var16 = p_Var14;
        }
        p_Var14 = p_Var19;
      } while (p_Var19 != 0x0);
      if ((p_Var12 == p_Var16) || (local_68[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var14 = rea_operator_new(0x28);
        if (p_Var14 != 0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_68[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar18 + 8),p_Var16,p_Var14 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
        p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
        p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
        if (p_Var19 == 0x0) {
          rea_operator_delete(p_Var14);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == 0x0) && (p_Var12 != p_Var19)) {
            bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var19,p_Var12);
          *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
          p_Var16 = p_Var14;
        }
      }
      uVar20 = *(uint *)(p_Var16 + 0x24);
      lVar11 = 1;
    }
    lVar18 = lVar18 + (lVar11 + 1) * 0x30;
    p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar18 + 8);
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var14 = p_Var12;
    p_Var16 = p_Var19;
    uVar9 = uVar20;
    if (p_Var12 != 0x0) {
      do {
        while (p_Var15 = p_Var14, *(int *)(p_Var15 + 0x20) < local_68[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011b21b;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var16 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != 0x0);
LAB_0011b21b:
      if ((p_Var19 != p_Var15) && (p_Var14 = p_Var19, *(int *)(p_Var15 + 0x20) <= local_68[0])) {
        do {
          if (*(int *)(p_Var12 + 0x20) < local_68[0]) {
            p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
          }
          else {
            p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
            p_Var14 = p_Var12;
          }
          p_Var12 = p_Var16;
        } while (p_Var16 != 0x0);
        if ((p_Var19 == p_Var14) || (local_68[0] < *(int *)(p_Var14 + 0x20))) {
          p_Var12 = rea_operator_new(0x28);
          if (p_Var12 != 0x0) {
            *(undefined4 *)p_Var12 = 0;
            *(undefined8 *)(p_Var12 + 8) = 0;
            *(undefined8 *)(p_Var12 + 0x10) = 0;
            *(undefined8 *)(p_Var12 + 0x18) = 0;
            *(undefined4 *)(p_Var12 + 0x24) = 0;
            *(int *)(p_Var12 + 0x20) = local_68[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
          p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
          p_Var14 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
          if (p_Var16 == 0x0) {
            rea_operator_delete(p_Var12);
          }
          else {
            bVar17 = true;
            if ((p_Var14 == 0x0) && (p_Var19 != p_Var16)) {
              bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
            *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
            p_Var14 = p_Var12;
          }
        }
        uVar9 = *(uint *)(p_Var14 + 0x24);
      }
    }
    if ((uVar9 & 0xfffffffd) == uVar20) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var2,local_68);
      goto LAB_0011b3a6;
    }
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var14 = p_Var19;
    if (p_Var12 == 0x0) {
LAB_0011b32a:
      p_Var12 = rea_operator_new(0x28);
      if (p_Var12 != 0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_68[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
      p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
      p_Var14 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
      if (p_Var16 == 0x0) {
        rea_operator_delete(p_Var12);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == 0x0) && (p_Var19 != p_Var16)) {
          bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
        *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
        p_Var14 = p_Var12;
      }
    }
    else {
      do {
        if (*(int *)(p_Var12 + 0x20) < local_68[0]) {
          p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
        }
        else {
          p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var14 = p_Var12;
        }
        p_Var12 = p_Var16;
      } while (p_Var16 != 0x0);
      if ((p_Var19 == p_Var14) || (local_68[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0011b32a;
    }
    *(uint *)(p_Var14 + 0x24) = uVar9 & 0xfffffffd;
LAB_0011b3a6:
    uVar5 = *(undefined8 *)(this_ptr + 0x70);
    uVar6 = *(undefined8 *)(this_ptr + 0x68);
    *(undefined8 *)(this_ptr + 0x70) = local_50;
    local_48 = *(code **)(this_ptr + 0x78);
    *(undefined8 *)(this_ptr + 0x68) = local_58;
    pcVar7 = *(code **)(this_ptr + 0x80);
    *(undefined8 *)(this_ptr + 0x78) = 0;
    *(code **)(this_ptr + 0x80) = local_40;
    local_58 = uVar6;
    local_50 = uVar5;
    local_40 = pcVar7;
    if (local_48 == 0x0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (*pcVar7)(&local_58);
    if (local_48 == 0x0) {
      return;
    }
    (*local_48)(&local_58,&local_58,3);
    return;
  }
  sVar10 = rea_write(*(int *)(this_ptr + 0x40),(void *)*puVar3,puVar3[1] - (long long)*puVar3);
  iVar8 = (int)sVar10;
  if (iVar8 == -1) {
    piVar13 = rea___errno_location();
    if (*piVar13 == 0xb) {
      return;
    }
  }
  else if (-1 < iVar8) {
    puVar3 = *(undefined8 **)(this_ptr + 0x60);
    pvVar4 = (void *)puVar3[1];
    __dest = (void *)*puVar3;
    if ((ulong)(long long)iVar8 < (ulong)((long long)pvVar4 - (long long)__dest)) {
      __src = (void *)((long long)__dest + (long long)iVar8);
      if (__dest == __src) {
        return;
      }
      lVar18 = 0;
      if ((pvVar4 != __src) && ((long long)pvVar4 - (long long)__src != 0)) {
        __dest = rea_memmove(__dest,__src,(long long)pvVar4 - (long long)__src);
        lVar18 = puVar3[1] - (long long)__src;
      }
      puVar3[1] = lVar18 + (long long)__dest;
      return;
    }
    lVar18 = *(long long *)(this_ptr + 0x38);
    local_78[0] = *(int *)(this_ptr + 0x40);
    this_ptr[0x5a] = (TcpConn)0x0;
    p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var16 = p_Var14;
    p_Var19 = p_Var12;
    if (p_Var14 == 0x0) {
LAB_0011acc9:
      lVar11 = 0;
      uVar20 = 0;
    }
    else {
      do {
        while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < local_78[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var19;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011acbb;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var19 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != 0x0);
LAB_0011acbb:
      if ((p_Var12 == p_Var15) || (p_Var16 = p_Var12, local_78[0] < *(int *)(p_Var15 + 0x20)))
      goto LAB_0011acc9;
      do {
        while (p_Var19 = p_Var14, *(int *)(p_Var19 + 0x20) < local_78[0]) {
          p_Var15 = p_Var19 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var15;
          p_Var19 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var15 == 0x0) goto LAB_0011aceb;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var16 = p_Var19;
      } while (*(_Rb_tree_node_base **)(p_Var19 + 0x10) != 0x0);
LAB_0011aceb:
      if ((p_Var12 == p_Var19) || (local_78[0] < *(int *)(p_Var19 + 0x20))) {
        p_Var14 = rea_operator_new(0x28);
        if (p_Var14 != 0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_78[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar18 + 8),p_Var19,p_Var14 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
        p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
        p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
        if (p_Var16 == 0x0) {
          rea_operator_delete(p_Var14);
        }
        else {
          bVar17 = true;
          if ((p_Var19 == 0x0) && (p_Var12 != p_Var16)) {
            bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var16 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var16,p_Var12);
          *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
          p_Var19 = p_Var14;
        }
      }
      uVar20 = *(uint *)(p_Var19 + 0x24);
      lVar11 = 1;
    }
    lVar18 = lVar18 + (lVar11 + 1) * 0x30;
    p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar18 + 8);
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var14 = p_Var12;
    p_Var16 = p_Var19;
    uVar9 = uVar20;
    if (p_Var12 != 0x0) {
      do {
        while (p_Var15 = p_Var14, *(int *)(p_Var15 + 0x20) < local_78[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011ad5b;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var16 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != 0x0);
LAB_0011ad5b:
      if ((p_Var19 != p_Var15) && (p_Var14 = p_Var19, *(int *)(p_Var15 + 0x20) <= local_78[0])) {
        do {
          while (p_Var16 = p_Var12, *(int *)(p_Var16 + 0x20) < local_78[0]) {
            p_Var15 = p_Var16 + 0x18;
            p_Var12 = *(_Rb_tree_node_base **)p_Var15;
            p_Var16 = p_Var14;
            if (*(_Rb_tree_node_base **)p_Var15 == 0x0) goto LAB_0011af4b;
          }
          p_Var12 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
          p_Var14 = p_Var16;
        } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != 0x0);
LAB_0011af4b:
        if ((p_Var19 == p_Var16) || (local_78[0] < *(int *)(p_Var16 + 0x20))) {
          p_Var12 = rea_operator_new(0x28);
          if (p_Var12 != 0x0) {
            *(undefined4 *)p_Var12 = 0;
            *(undefined8 *)(p_Var12 + 8) = 0;
            *(undefined8 *)(p_Var12 + 0x10) = 0;
            *(undefined8 *)(p_Var12 + 0x18) = 0;
            *(undefined4 *)(p_Var12 + 0x24) = 0;
            *(int *)(p_Var12 + 0x20) = local_78[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var2,p_Var16,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
          p_Var14 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
          p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
          if (p_Var14 == 0x0) {
            rea_operator_delete(p_Var12);
          }
          else {
            bVar17 = true;
            if ((p_Var16 == 0x0) && (p_Var19 != p_Var14)) {
              bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var14 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var14,p_Var19);
            *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
            p_Var16 = p_Var12;
          }
        }
        uVar9 = *(uint *)(p_Var16 + 0x24);
      }
    }
    if ((uVar9 & 0xfffffffd) == uVar20) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var2,local_78);
      goto LAB_0011ae38;
    }
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var16 = p_Var19;
    p_Var14 = p_Var19;
    if (*(_Rb_tree_node_base **)(lVar18 + 0x18) == 0x0) {
LAB_0011adbc:
      p_Var12 = rea_operator_new(0x28);
      if (p_Var12 != 0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_78[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
      p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
      p_Var14 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
      if (p_Var16 == 0x0) {
        rea_operator_delete(p_Var12);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == 0x0) && (p_Var19 != p_Var16)) {
          bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
        *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
        p_Var14 = p_Var12;
      }
    }
    else {
      do {
        while (p_Var14 = p_Var12, *(int *)(p_Var14 + 0x20) < local_78[0]) {
          p_Var15 = p_Var14 + 0x18;
          p_Var12 = *(_Rb_tree_node_base **)p_Var15;
          p_Var14 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var15 == 0x0) goto LAB_0011adb2;
        }
        p_Var12 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
        p_Var16 = p_Var14;
      } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != 0x0);
LAB_0011adb2:
      if ((p_Var19 == p_Var14) || (local_78[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0011adbc;
    }
    *(uint *)(p_Var14 + 0x24) = uVar9 & 0xfffffffd;
LAB_0011ae38:
    puVar3 = *(undefined8 **)(this_ptr + 0x60);
    *(undefined8 *)(this_ptr + 0x60) = 0;
    if (puVar3 != 0x0) {
      if ((void *)*puVar3 != 0x0) {
        rea_operator_delete((void *)*puVar3);
      }
      rea_operator_delete(puVar3);
    }
    uVar5 = *(undefined8 *)(this_ptr + 0x70);
    uVar6 = *(undefined8 *)(this_ptr + 0x68);
    *(undefined8 *)(this_ptr + 0x70) = local_50;
    local_48 = *(code **)(this_ptr + 0x78);
    *(undefined8 *)(this_ptr + 0x68) = local_58;
    pcVar7 = *(code **)(this_ptr + 0x80);
    *(undefined8 *)(this_ptr + 0x78) = 0;
    *(code **)(this_ptr + 0x80) = local_40;
    local_58 = uVar6;
    local_50 = uVar5;
    local_40 = pcVar7;
    if (local_48 != 0x0) {
      (*pcVar7)(&local_58);
      if (local_48 == 0x0) {
        return;
      }
      (*local_48)(&local_58,&local_58,3);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  rea_perror("tcp send");
  lVar18 = *(long long *)(this_ptr + 0x38);
  iVar8 = *(int *)(this_ptr + 0x40);
  this_ptr[0x58] = (TcpConn)0x0;
  this_ptr[0x59] = (TcpConn)0x0;
  this_ptr[0x5a] = (TcpConn)0x0;
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  local_58 = CONCAT44((*(undefined4 *)((uint8_t *)&local_58 + 0x4)),iVar8);
  p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var16 = p_Var14;
  p_Var19 = p_Var12;
  if (p_Var14 == 0x0) {
LAB_0011b44e:
    lVar11 = 0;
    uVar20 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var16 + 0x20) < iVar8) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var19 = p_Var16;
      }
      p_Var16 = p_Var15;
    } while (p_Var15 != 0x0);
    if ((p_Var12 == p_Var19) || (p_Var16 = p_Var12, iVar8 < *(int *)(p_Var19 + 0x20)))
    goto LAB_0011b44e;
    do {
      if (*(int *)(p_Var14 + 0x20) < iVar8) {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
      }
      else {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
        p_Var16 = p_Var14;
      }
      p_Var14 = p_Var19;
    } while (p_Var19 != 0x0);
    if ((p_Var12 == p_Var16) || (iVar8 < *(int *)(p_Var16 + 0x20))) {
      p_Var14 = rea_operator_new(0x28);
      if (p_Var14 != 0x0) {
        *(undefined4 *)p_Var14 = 0;
        *(undefined8 *)(p_Var14 + 8) = 0;
        *(undefined8 *)(p_Var14 + 0x10) = 0;
        *(undefined8 *)(p_Var14 + 0x18) = 0;
        *(undefined4 *)(p_Var14 + 0x24) = 0;
        *(int *)(p_Var14 + 0x20) = (int)local_58;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar18 + 8),p_Var16,p_Var14 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
      p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
      p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
      if (p_Var19 == 0x0) {
        rea_operator_delete(p_Var14);
      }
      else {
        bVar17 = true;
        if ((p_Var16 == 0x0) && (p_Var12 != p_Var19)) {
          bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var19,p_Var12);
        *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
        p_Var16 = p_Var14;
      }
    }
    uVar20 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar18 = lVar18 + (lVar11 + 1) * 0x30;
  p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar18 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  uVar9 = uVar20;
  if (p_Var12 != 0x0) {
    p_Var16 = p_Var12;
    p_Var19 = p_Var14;
    do {
      if (*(int *)(p_Var16 + 0x20) < (int)local_58) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var19 = p_Var16;
      }
      p_Var16 = p_Var15;
    } while (p_Var15 != 0x0);
    if ((p_Var14 != p_Var19) && (p_Var16 = p_Var14, *(int *)(p_Var19 + 0x20) <= (int)local_58)) {
      do {
        if (*(int *)(p_Var12 + 0x20) < (int)local_58) {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
        }
        else {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var16 = p_Var12;
        }
        p_Var12 = p_Var19;
      } while (p_Var19 != 0x0);
      if ((p_Var14 == p_Var16) || ((int)local_58 < *(int *)(p_Var16 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != 0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = (int)local_58;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var16,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
        p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
        p_Var16 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
        if (p_Var19 == 0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == 0x0) && (p_Var14 != p_Var19)) {
            bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var19 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var19,p_Var14);
          *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
          p_Var16 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var16 + 0x24);
    }
  }
  if ((uVar9 & 0xfffffffd) == uVar20) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var2,(int *)&local_58);
    return;
  }
  p_Var12 = p_Var14;
  if (*(_Rb_tree_node_base **)(lVar18 + 0x18) != 0x0) {
    p_Var16 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    do {
      if (*(int *)(p_Var16 + 0x20) < (int)local_58) {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var12 = p_Var16;
      }
      p_Var16 = p_Var19;
    } while (p_Var19 != 0x0);
    if ((p_Var14 != p_Var12) && (*(int *)(p_Var12 + 0x20) <= (int)local_58)) goto LAB_0011b77d;
  }
  p_Var16 = rea_operator_new(0x28);
  if (p_Var16 != 0x0) {
    *(undefined4 *)p_Var16 = 0;
    *(undefined8 *)(p_Var16 + 8) = 0;
    *(undefined8 *)(p_Var16 + 0x10) = 0;
    *(undefined8 *)(p_Var16 + 0x18) = 0;
    *(undefined4 *)(p_Var16 + 0x24) = 0;
    *(int *)(p_Var16 + 0x20) = (int)local_58;
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(p_Var2,p_Var12,p_Var16 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
  p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x8)));
  p_Var12 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar21 + 0x0)));
  if (p_Var19 == 0x0) {
    rea_operator_delete(p_Var16);
  }
  else {
    bVar17 = true;
    if ((p_Var12 == 0x0) && (p_Var14 != p_Var19)) {
      bVar17 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var19 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var16,p_Var19,p_Var14);
    *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
    p_Var12 = p_Var16;
  }
LAB_0011b77d:
  *(uint *)(p_Var12 + 0x24) = uVar9 & 0xfffffffd;
  return;
}
