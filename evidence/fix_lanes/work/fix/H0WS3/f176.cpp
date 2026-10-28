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
// IDX 176  00109f70  FUN_00109f70
// ------------------------------------------------------------------
undefined8 rea_FUN_00109f70(undefined8 param_1, undefined8 param_2)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_ptr;
  allocator *paVar2;
  int *piVar3;
  EventLoop2 *pEVar4;
  char cVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  EventLoop2 *pEVar9;
  undefined *puVar10;
  int iVar11;
  uint uVar12;
  EventLoop2 *this_00;
  _Rb_tree_node_base *p_Var13;
  long long lVar14;
  _Rb_tree_node_base *p_Var15;
  undefined8 uVar16;
  EventLoop2 *pEVar17;
  code *pcVar18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  code *pcVar22;
  long long lVar23;
  _Rb_tree_node_base *p_Var24;
  uint uVar25;
  undefined1 auVar26 [16];
  int local_1d8 [4];
  undefined8 local_1c8 [2];
  void *local_1b8 [2];
  code *local_1a8;
  code *pcStack_1a0;
  undefined8 local_198;
  undefined8 local_190;
  code *local_188;
  code *pcStack_180;
  undefined1 local_178[0x98];
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  (*(code **)((uint8_t *)&local_178 + 0x0)) = 0x0;
  local_f0 = 0;
  rea_sigemptyset(&local_170);
  rea_sigaction(2,(sigaction *)&local_178,&local_d8);
  local_198 = CONCAT62((*(arr_undefined1_6 *)((uint8_t *)&local_198 + 0x2)),0x4f);
  iVar11 = rea_PyArg_ParseTuple(param_2,&local_198,local_1c8);
  if (iVar11 == 0) {
    uVar16 = 0;
    goto LAB_0010a4b6;
  }
  this_00 = (EventLoop2 *)rea_PyLong_AsVoidPtr(local_1c8[0]);
  if (this_00 != 0x0) {
    if (*(long long *)(this_00 + 0x68) != 0) {
      local_1a8 = 0x0;
      local_1b8[0] = rea_operator_new(1);
      pcStack_1a0 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107950);
      local_1a8 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107ac0);
      lVar23 = *(long long *)(*(long long *)(this_00 + 0x68) + 0x38);
      if (*(char *)(lVar23 + 0x5a) != '\0') {
        rea_fwrite((void*)(uintptr_t)("close(): send_flag != false\n"),1,0x1c,*(FILE **)PTR_stderr_00324fb0);
        rea_print_stack();
      }
      puVar7 = *(undefined8 **)(lVar23 + 0x60);
      *(undefined1 *)(lVar23 + 0x5a) = 1;
      *(undefined8 *)(lVar23 + 0x60) = 0;
      if (puVar7 != 0x0) {
        if ((void *)*puVar7 != 0x0) {
          rea_operator_delete((void *)*puVar7);
        }
        rea_operator_delete(puVar7);
      }
      local_188 = 0x0;
      if (local_1a8 == 0x0) {
        pcVar22 = 0x0;
        pcVar18 = pcStack_180;
      }
      else {
        (*local_1a8)(&local_198,local_1b8,2);
        pcVar18 = pcStack_1a0;
        pcVar22 = local_1a8;
      }
      uVar16 = *(undefined8 *)(lVar23 + 0x68);
      uVar8 = *(undefined8 *)(lVar23 + 0x70);
      local_188 = *(code **)(lVar23 + 0x78);
      *(undefined8 *)(lVar23 + 0x68) = local_198;
      *(undefined8 *)(lVar23 + 0x70) = local_190;
      pcStack_180 = *(code **)(lVar23 + 0x80);
      *(code **)(lVar23 + 0x78) = pcVar22;
      *(code **)(lVar23 + 0x80) = pcVar18;
      local_198 = uVar16;
      local_190 = uVar8;
      if (local_188 != 0x0) {
        (*local_188)(&local_198,&local_198,3);
      }
      cVar5 = *(char *)(lVar23 + 0x5a);
      local_1d8[0] = *(int *)(lVar23 + 0x40);
      lVar23 = *(long long *)(lVar23 + 0x38);
      p_Var13 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
      p_Var15 = (_Rb_tree_node_base *)(lVar23 + 0x10);
      p_Var19 = p_Var13;
      p_Var24 = p_Var15;
      if (p_Var13 == 0x0) {
LAB_0010a4f0:
        lVar14 = 0;
        uVar6 = 0;
      }
      else {
        do {
          while (p_Var20 = p_Var19, local_1d8[0] <= *(int *)(p_Var20 + 0x20)) {
            p_Var19 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
            p_Var24 = p_Var20;
            if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == 0x0)
            goto LAB_0010a15a;
          }
          p_Var1 = p_Var20 + 0x18;
          p_Var19 = *(_Rb_tree_node_base **)p_Var1;
          p_Var20 = p_Var24;
        } while (*(_Rb_tree_node_base **)p_Var1 != 0x0);
LAB_0010a15a:
        if ((p_Var15 == p_Var20) || (p_Var19 = p_Var15, local_1d8[0] < *(int *)(p_Var20 + 0x20)))
        goto LAB_0010a4f0;
        do {
          while (p_Var24 = p_Var13, local_1d8[0] <= *(int *)(p_Var24 + 0x20)) {
            p_Var13 = *(_Rb_tree_node_base **)(p_Var24 + 0x10);
            p_Var19 = p_Var24;
            if (*(_Rb_tree_node_base **)(p_Var24 + 0x10) == 0x0)
            goto LAB_0010a18a;
          }
          p_Var20 = p_Var24 + 0x18;
          p_Var13 = *(_Rb_tree_node_base **)p_Var20;
          p_Var24 = p_Var19;
        } while (*(_Rb_tree_node_base **)p_Var20 != 0x0);
LAB_0010a18a:
        if ((p_Var15 == p_Var24) || (local_1d8[0] < *(int *)(p_Var24 + 0x20))) {
          p_Var13 = rea_operator_new(0x28);
          if (p_Var13 != 0x0) {
            *(undefined4 *)p_Var13 = 0;
            *(undefined8 *)(p_Var13 + 8) = 0;
            *(undefined8 *)(p_Var13 + 0x10) = 0;
            *(undefined8 *)(p_Var13 + 0x18) = 0;
            *(undefined4 *)(p_Var13 + 0x24) = 0;
            *(int *)(p_Var13 + 0x20) = local_1d8[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos_______________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                *)(lVar23 + 8),p_Var24,p_Var13 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
          p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x8)));
          p_Var24 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x0)));
          if (p_Var19 == 0x0) {
            rea_operator_delete(p_Var13);
          }
          else {
            bVar21 = true;
            if ((p_Var24 == 0x0) && (p_Var15 != p_Var19)) {
              bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var19 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var19,p_Var15);
            *(long long *)(lVar23 + 0x30) = *(long long *)(lVar23 + 0x30) + 1;
            p_Var24 = p_Var13;
          }
        }
        uVar6 = *(uint *)(p_Var24 + 0x24);
        lVar14 = 1;
      }
      lVar23 = lVar23 + (lVar14 + 1) * 0x30;
      this_ptr = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar23 + 8);
      p_Var15 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
      p_Var24 = (_Rb_tree_node_base *)(lVar23 + 0x10);
      p_Var13 = p_Var15;
      p_Var19 = p_Var24;
      uVar12 = uVar6;
      if (p_Var15 != 0x0) {
        do {
          while (p_Var20 = p_Var13, local_1d8[0] <= *(int *)(p_Var20 + 0x20)) {
            p_Var13 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
            p_Var19 = p_Var20;
            if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == 0x0)
            goto LAB_0010a272;
          }
          p_Var1 = p_Var20 + 0x18;
          p_Var13 = *(_Rb_tree_node_base **)p_Var1;
          p_Var20 = p_Var19;
        } while (*(_Rb_tree_node_base **)p_Var1 != 0x0);
LAB_0010a272:
        if ((p_Var24 != p_Var20) && (p_Var13 = p_Var24, *(int *)(p_Var20 + 0x20) <= local_1d8[0])) {
          do {
            while (p_Var19 = p_Var15, local_1d8[0] <= *(int *)(p_Var19 + 0x20)) {
              p_Var15 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
              p_Var13 = p_Var19;
              if (*(_Rb_tree_node_base **)(p_Var19 + 0x10) == 0x0)
              goto LAB_0010a2aa;
            }
            p_Var20 = p_Var19 + 0x18;
            p_Var15 = *(_Rb_tree_node_base **)p_Var20;
            p_Var19 = p_Var13;
          } while (*(_Rb_tree_node_base **)p_Var20 != 0x0);
LAB_0010a2aa:
          if ((p_Var24 == p_Var19) || (local_1d8[0] < *(int *)(p_Var19 + 0x20))) {
            p_Var15 = rea_operator_new(0x28);
            if (p_Var15 != 0x0) {
              *(undefined4 *)p_Var15 = 0;
              *(undefined8 *)(p_Var15 + 8) = 0;
              *(undefined8 *)(p_Var15 + 0x10) = 0;
              *(undefined8 *)(p_Var15 + 0x18) = 0;
              *(undefined4 *)(p_Var15 + 0x24) = 0;
              *(int *)(p_Var15 + 0x20) = local_1d8[0];
            }
            { auto &&__rea_tmp = (std__________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________________M_get_insert_hint_unique_pos(this_ptr,p_Var19,p_Var15 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
            p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x8)));
            p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x0)));
            if (p_Var13 == 0x0) {
              rea_operator_delete(p_Var15);
            }
            else {
              bVar21 = true;
              if ((p_Var19 == 0x0) && (p_Var24 != p_Var13)) {
                bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var13 + 0x20);
              }
              rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var13,p_Var24);
              *(long long *)(lVar23 + 0x30) = *(long long *)(lVar23 + 0x30) + 1;
              p_Var19 = p_Var15;
            }
          }
          uVar12 = *(uint *)(p_Var19 + 0x24);
        }
      }
      uVar25 = uVar12 | 2;
      if (cVar5 == '\0') {
        uVar25 = uVar12 & 0xfffffffd;
      }
      if (uVar6 == uVar25) {
        std____________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___________erase(this_ptr,local_1d8);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
        p_Var19 = p_Var24;
        p_Var13 = p_Var24;
        if (*(_Rb_tree_node_base **)(lVar23 + 0x18) == 0x0) {
LAB_0010a321:
          p_Var15 = rea_operator_new(0x28);
          if (p_Var15 != 0x0) {
            *(undefined4 *)p_Var15 = 0;
            *(undefined8 *)(p_Var15 + 8) = 0;
            *(undefined8 *)(p_Var15 + 0x10) = 0;
            *(undefined8 *)(p_Var15 + 0x18) = 0;
            *(undefined4 *)(p_Var15 + 0x24) = 0;
            *(int *)(p_Var15 + 0x20) = local_1d8[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(this_ptr,p_Var13,p_Var15 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
          p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x8)));
          p_Var13 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x0)));
          if (p_Var19 == 0x0) {
            rea_operator_delete(p_Var15);
          }
          else {
            bVar21 = true;
            if ((p_Var13 == 0x0) && (p_Var24 != p_Var19)) {
              bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var19 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var19,p_Var24);
            *(long long *)(lVar23 + 0x30) = *(long long *)(lVar23 + 0x30) + 1;
            p_Var13 = p_Var15;
          }
        }
        else {
          do {
            while (p_Var13 = p_Var15, local_1d8[0] <= *(int *)(p_Var13 + 0x20)) {
              p_Var15 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var19 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == 0x0)
              goto LAB_0010a312;
            }
            p_Var20 = p_Var13 + 0x18;
            p_Var15 = *(_Rb_tree_node_base **)p_Var20;
            p_Var13 = p_Var19;
          } while (*(_Rb_tree_node_base **)p_Var20 != 0x0);
LAB_0010a312:
          if ((p_Var24 == p_Var13) || (local_1d8[0] < *(int *)(p_Var13 + 0x20))) goto LAB_0010a321;
        }
        *(uint *)(p_Var13 + 0x24) = uVar25;
      }
      if (local_1a8 != 0x0) {
        (*local_1a8)(local_1b8,local_1b8,3);
      }
      local_188 = 0x0;
      rea_EventLoop2__run(this_00,(long long int)(uintptr_t)(&local_198));
      if (local_188 != 0x0) {
        (*local_188)(&local_198,&local_198,3);
      }
    }
    *(undefined **)(this_00 + 0x70) = PTR_vtable_00324f90 + 0x10;
    if (*(code **)(this_00 + 0xd0) != 0x0) {
      (**(code **)(this_00 + 0xd0))(this_00 + 0xc0,this_00 + 0xc0,3);
    }
    puVar10 = PTR__S_empty_rep_storage_00324fa0;
    pEVar17 = *(EventLoop2 **)(this_00 + 0xa8);
    pEVar4 = this_00 + 0xa8;
    if (pEVar4 != pEVar17) {
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        do {
          lVar23 = *(long long *)(pEVar17 + 0x18);
          pEVar9 = *(EventLoop2 **)pEVar17;
          if (((allocator *)(lVar23 + -0x18) != (allocator *)puVar10) &&
             (iVar11 = *(int *)(lVar23 + -8), *(int *)(lVar23 + -8) = iVar11 + -1, iVar11 < 1)) {
            rea_std__string___Rep___M_destroy((allocator *)(lVar23 + -0x18));
          }
          rea_operator_delete(pEVar17);
          pEVar17 = pEVar9;
        } while (pEVar4 != pEVar9);
      }
      else {
        do {
          pEVar9 = *(EventLoop2 **)pEVar17;
          paVar2 = (allocator *)(*(long long *)(pEVar17 + 0x18) + -0x18);
          if (paVar2 != (allocator *)puVar10) {
            LOCK();
            piVar3 = (int *)(*(long long *)(pEVar17 + 0x18) + -8);
            iVar11 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
            if (iVar11 < 1) {
              rea_std__string___Rep___M_destroy(paVar2);
            }
          }
          rea_operator_delete(pEVar17);
          pEVar17 = pEVar9;
        } while (pEVar4 != pEVar9);
      }
    }
    std________Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root________M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
                *)(this_00 + 0x78),*(_Rb_tree_node **)(this_00 + 0x88));
    *(undefined **)(this_00 + 0x70) = PTR_vtable_00324ef0 + 0x10;
    rea_EventLoop2__dtor_EventLoop2(this_00);
    rea_operator_delete(this_00);
  }
  uVar16 = rea_Py_BuildValue((void *)&DAT_0011f3d1,0);
LAB_0010a4b6:
  rea_sigaction(2,&local_d8,0x0);
  return uVar16;
}
