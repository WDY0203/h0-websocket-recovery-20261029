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
// IDX 281  0011a290  TcpClient__TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__TcpClient__dup3(TcpClient * this_ptr, string * param_1, undefined4 param_2, long long param_4, long long param_5)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  long long lVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long long *plVar9;
  TcpConn *this_00;
  int *piVar10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  ulong uVar14;
  bool bVar15;
  uint uVar16;
  _Rb_tree_node_base *p_Var17;
  undefined1 auVar18 [16];
  ushort local_b0;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *local_a8;
  int local_88 [4];
  long long local_78 [2];
  ulong local_68 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined1 local_48[0x10];
  
  local_a8 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 0x38);
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
  *(_Rb_tree_node_base **)(this_ptr + 0x28) = p_Var1;
  *(TcpClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(TcpClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(TcpClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(TcpClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar5 = PTR_vtable_00324f98;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 0;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined **)this_ptr = puVar5 + 0x10;
  if (*(code **)(param_4 + 0x10) != 0x0) {
    (**(code **)(param_4 + 0x10))(this_ptr + 0xa8,param_4,2);
    *(undefined8 *)(this_ptr + 0xc0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this_ptr + 0xb8) = *(undefined8 *)(param_4 + 0x10);
  }
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  if (*(code **)(param_5 + 0x10) != 0x0) {
    (**(code **)(param_5 + 0x10))(this_ptr + 200,param_5,2);
    *(undefined8 *)(this_ptr + 0xe0) = *(undefined8 *)(param_5 + 0x18);
    *(undefined8 *)(this_ptr + 0xd8) = *(undefined8 *)(param_5 + 0x10);
  }
  rea_bzero(&local_48,0x10);
  (*(undefined2 *)((uint8_t *)&local_48 + 0x0)) = 2;
  (*(undefined4 *)((uint8_t *)&local_48 + 0x4)) = rea_inet_addr(*(char **)param_1);
  local_b0 = (ushort)param_2;
  (*(undefined2 *)((uint8_t *)&local_48 + 0x2)) = local_b0 >> 8 | local_b0 << 8;
  iVar6 = rea_socket(2,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)(this_ptr + 0x98) = 2;
    rea_perror("socket");
    piVar10 = rea___errno_location();
    iVar8 = *piVar10;
    if (*(long long *)(param_5 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
LAB_0011a8a1:
    (**(code **)(param_5 + 0x18))(param_5,iVar8);
    return;
  }
  rea_setcloexec(iVar6);
  rea_setnonblock(iVar6);
  local_58 = 1;
  rea_setsockopt(iVar6,6,1,&local_58,4);
  iVar7 = rea_connect(iVar6,(sockaddr*)(uintptr_t)(&local_48),0x10);
  if (iVar7 < 0) {
    piVar10 = rea___errno_location();
    iVar8 = *piVar10;
    if (iVar8 != 0x73) {
      *(undefined4 *)(this_ptr + 0x98) = 2;
      rea_perror("connect");
      rea_close(iVar6);
      if (*(long long *)(param_5 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      goto LAB_0011a8a1;
    }
  }
  rea___gnu_cxx____to_xstring_std__string_char
            ((code *)&local_58,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,(void *)&DAT_0011fd61,param_2);
  rea_std__string__string((string *)local_68,param_1);
  rea_std__string__append((char *)local_68,0x11fcf2);
  uVar14 = *(long long *)(local_68[0] - 0x18) + *(long long *)(CONCAT44(uStack_54,local_58) + -0x18);
  if ((*(ulong *)(local_68[0] - 0x10) < uVar14) &&
     (uVar14 <= *(ulong *)(CONCAT44(uStack_54,local_58) + -0x10))) {
    plVar9 = (long long *)rea_std__string__insert((ulong)&local_58,0x0,local_68[0]);
  }
  else {
    plVar9 = (long long *)rea_std__string__append((string *)local_68);
  }
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  local_78[0] = *plVar9;
  *plVar9 = (long long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_68[0] - 0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(local_68[0] - 8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar8 = *(int *)(local_68[0] - 8);
      *(int *)(local_68[0] - 8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] - 0x18));
    }
  }
  lVar3 = CONCAT44(uStack_54,local_58);
  if ((allocator *)(lVar3 + -0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(lVar3 + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar8 = *(int *)(lVar3 + -8);
      *(int *)(lVar3 + -8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar3 + -0x18));
    }
  }
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,iVar6,param_1,(string *)local_78,(EventHandler *)this_ptr);
  plVar9 = *(long long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar9 != 0x0) {
    (**(code **)(*plVar9 + 8))();
  }
  if (iVar7 == 0) {
    *(undefined4 *)(this_ptr + 0x98) = 1;
    if (*(long long *)(param_4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (**(code **)(param_4 + 0x18))(param_4,*(undefined8 *)(this_ptr + 0xa0));
    goto LAB_0011a5a3;
  }
  p_Var11 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  p_Var17 = p_Var11;
  p_Var12 = p_Var1;
  local_88[0] = iVar6;
  if (p_Var11 == 0x0) {
LAB_0011a683:
    uVar16 = 0;
  }
  else {
    do {
      while (p_Var13 = p_Var17, iVar6 <= *(int *)(p_Var13 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == 0x0)
        goto LAB_0011a672;
      }
      p_Var2 = p_Var13 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var2 != 0x0);
LAB_0011a672:
    if ((p_Var1 == p_Var13) || (p_Var17 = p_Var1, iVar6 < *(int *)(p_Var13 + 0x20)))
    goto LAB_0011a683;
    do {
      while (p_Var12 = p_Var11, iVar6 <= *(int *)(p_Var12 + 0x20)) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
        p_Var17 = p_Var12;
        if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == 0x0)
        goto LAB_0011a8ca;
      }
      p_Var13 = p_Var12 + 0x18;
      p_Var11 = *(_Rb_tree_node_base **)p_Var13;
      p_Var12 = p_Var17;
    } while (*(_Rb_tree_node_base **)p_Var13 != 0x0);
LAB_0011a8ca:
    if ((p_Var1 == p_Var12) || (iVar6 < *(int *)(p_Var12 + 0x20))) {
      p_Var11 = rea_operator_new(0x28);
      if (p_Var11 != 0x0) {
        *(undefined4 *)p_Var11 = 0;
        *(undefined8 *)(p_Var11 + 8) = 0;
        *(undefined8 *)(p_Var11 + 0x10) = 0;
        *(undefined8 *)(p_Var11 + 0x18) = 0;
        *(undefined4 *)(p_Var11 + 0x24) = 0;
        *(int *)(p_Var11 + 0x20) = local_88[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var12,p_Var11 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
      p_Var17 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x8)));
      p_Var12 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x0)));
      if (p_Var17 == 0x0) {
        rea_operator_delete(p_Var11);
      }
      else {
        bVar15 = true;
        if ((p_Var12 == 0x0) && (p_Var1 != p_Var17)) {
          bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var17 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var17,p_Var1);
        *(long long *)(this_ptr + 0x30) = *(long long *)(this_ptr + 0x30) + 1;
        p_Var12 = p_Var11;
      }
    }
    local_a8 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                *)(this_ptr + 0x68);
    uVar16 = *(uint *)(p_Var12 + 0x24);
  }
  p_Var11 = *(_Rb_tree_node_base **)(local_a8 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(local_a8 + 8);
  p_Var17 = p_Var11;
  p_Var12 = p_Var1;
  uVar4 = uVar16;
  if (p_Var11 != 0x0) {
    do {
      while (p_Var13 = p_Var17, local_88[0] <= *(int *)(p_Var13 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == 0x0)
        goto LAB_0011a6ca;
      }
      p_Var2 = p_Var13 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var2 != 0x0);
LAB_0011a6ca:
    if ((p_Var1 != p_Var13) && (p_Var17 = p_Var1, *(int *)(p_Var13 + 0x20) <= local_88[0])) {
      do {
        while (p_Var12 = p_Var11, local_88[0] <= *(int *)(p_Var12 + 0x20)) {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var17 = p_Var12;
          if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == 0x0)
          goto LAB_0011a6fa;
        }
        p_Var13 = p_Var12 + 0x18;
        p_Var11 = *(_Rb_tree_node_base **)p_Var13;
        p_Var12 = p_Var17;
      } while (*(_Rb_tree_node_base **)p_Var13 != 0x0);
LAB_0011a6fa:
      if ((p_Var1 == p_Var12) || (local_88[0] < *(int *)(p_Var12 + 0x20))) {
        p_Var11 = rea_operator_new(0x28);
        if (p_Var11 != 0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_88[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(local_a8,p_Var12,p_Var11 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
        p_Var17 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x8)));
        p_Var12 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x0)));
        if (p_Var17 == 0x0) {
          rea_operator_delete(p_Var11);
        }
        else {
          bVar15 = true;
          if ((p_Var12 == 0x0) && (p_Var1 != p_Var17)) {
            bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var17 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var17,p_Var1);
          *(long long *)(local_a8 + 0x28) = *(long long *)(local_a8 + 0x28) + 1;
          p_Var12 = p_Var11;
        }
      }
      uVar4 = *(uint *)(p_Var12 + 0x24);
    }
  }
  if ((uVar4 | 2) == uVar16) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(local_a8,local_88);
    goto LAB_0011a5a3;
  }
  p_Var11 = *(_Rb_tree_node_base **)(local_a8 + 0x10);
  p_Var12 = p_Var1;
  p_Var17 = p_Var1;
  if (*(_Rb_tree_node_base **)(local_a8 + 0x10) == 0x0) {
LAB_0011a7e9:
    p_Var11 = rea_operator_new(0x28);
    if (p_Var11 != 0x0) {
      *(undefined4 *)p_Var11 = 0;
      *(undefined8 *)(p_Var11 + 8) = 0;
      *(undefined8 *)(p_Var11 + 0x10) = 0;
      *(undefined8 *)(p_Var11 + 0x18) = 0;
      *(undefined4 *)(p_Var11 + 0x24) = 0;
      *(int *)(p_Var11 + 0x20) = local_88[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(local_a8,p_Var17,p_Var11 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
    p_Var12 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x8)));
    p_Var17 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar18 + 0x0)));
    if (p_Var12 == 0x0) {
      rea_operator_delete(p_Var11);
    }
    else {
      bVar15 = true;
      if ((p_Var17 == 0x0) && (p_Var1 != p_Var12)) {
        bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var12 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var12,p_Var1);
      *(long long *)(local_a8 + 0x28) = *(long long *)(local_a8 + 0x28) + 1;
      p_Var17 = p_Var11;
    }
  }
  else {
    do {
      while (p_Var17 = p_Var11, local_88[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var12 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == 0x0)
        goto LAB_0011a7da;
      }
      p_Var13 = p_Var17 + 0x18;
      p_Var11 = *(_Rb_tree_node_base **)p_Var13;
      p_Var17 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var13 != 0x0);
LAB_0011a7da:
    if ((p_Var1 == p_Var17) || (local_88[0] < *(int *)(p_Var17 + 0x20))) goto LAB_0011a7e9;
  }
  *(uint *)(p_Var17 + 0x24) = uVar4 | 2;
LAB_0011a5a3:
  if ((allocator *)(local_78[0] + -0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(local_78[0] + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar6 = *(int *)(local_78[0] + -8);
      *(int *)(local_78[0] + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_78[0] + -0x18));
    }
  }
  return;
}
