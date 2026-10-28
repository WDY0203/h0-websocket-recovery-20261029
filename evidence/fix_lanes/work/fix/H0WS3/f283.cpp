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
// IDX 283  0011baf0  TcpServer__poll
// ------------------------------------------------------------------
undefined8 rea_TcpServer__poll(TcpServer * this_ptr, int param_1, int param_2)
{
  _Rb_tree_node_base *p_Var1;
  TcpServer *pTVar2;
  int *piVar3;
  undefined *puVar4;
  _Rb_tree_node_base *p_Var5;
  TcpServer *pTVar6;
  int iVar7;
  void *pvVar8;
  char *pcVar9;
  long long *plVar10;
  TcpConn *this_00;
  TcpServer *pTVar11;
  ulong uVar12;
  TcpServer *pTVar13;
  TcpServer *pTVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  bool bVar18;
  undefined1 local_b9;
  socklen_t local_b8 [4];
  int local_a8 [4];
  long long local_98 [2];
  long long local_88 [2];
  ulong local_78 [2];
  long long local_68 [2];
  int *local_58 [2];
  undefined1 local_48 [24];
  
  if ((*(int *)(this_ptr + 0xb8) != param_1) || ((param_2 & 1U) == 0)) goto LAB_0011bb1e;
  local_b8[0] = 0x10;
  local_a8[0] = rea_accept(*(int *)(this_ptr + 0xb8),(sockaddr *)local_48,local_b8);
  if (local_a8[0] < 0) {
    rea_perror("accept");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setnonblock(local_a8[0]);
  rea_setcloexec(local_a8[0]);
  local_58[0] = (int *)CONCAT44((undefined4)((uint64_t)(uintptr_t)local_58[0] >> 32),1);
  rea_setsockopt(local_a8[0],6,1,(allocator *)local_58,4);
  pcVar9 = rea_inet_ntoa((in_addr)(*(undefined4 *)((uint8_t *)&local_48 + 0x4)));
  rea_std__string__string((string *)local_98,pcVar9,(allocator *)local_58);
  rea___gnu_cxx____to_xstring_std__string_char
            ((code *)local_68,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,(void *)&DAT_0011fe68,
             (ulong)(ushort)((ushort)(*(undefined2 *)((uint8_t *)&local_48 + 0x2)) >> 8 | (*(undefined2 *)((uint8_t *)&local_48 + 0x2)) << 8));
  rea_std__string__string((string *)local_78,(string *)local_98);
  rea_std__string__append((char *)local_78,0x11fdf2);
  uVar12 = *(long long *)(local_78[0] - 0x18) + *(long long *)(local_68[0] + -0x18);
  if ((*(ulong *)(local_78[0] - 0x10) < uVar12) && (uVar12 <= *(ulong *)(local_68[0] + -0x10))) {
    plVar10 = (long long *)rea_std__string__insert((ulong)local_68,0x0,local_78[0]);
  }
  else {
    plVar10 = (long long *)rea_std__string__append((string *)local_78);
  }
  puVar4 = PTR__S_empty_rep_storage_00324fa0;
  local_88[0] = *plVar10;
  *plVar10 = (long long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_78[0] - 0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_78[0] - 8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar7 = *(int *)(local_78[0] - 8);
      *(int *)(local_78[0] - 8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_78[0] - 0x18));
    }
  }
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar7 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,local_a8[0],(string *)local_98,(string *)local_88,(EventHandler *)this_ptr);
  pTVar14 = this_ptr + 200;
  pTVar6 = *(TcpServer **)(this_ptr + 0xd0);
  pTVar13 = pTVar14;
  if (*(TcpServer **)(this_ptr + 0xd0) == 0x0) {
LAB_0011be19:
    local_58[0] = local_a8;
    pTVar11 = (TcpServer *)
              std__________________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________________________________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple__________________________(this_ptr + 0xc0,pTVar14,(void *)&DAT_0011fecc,(allocator *)local_58,&local_b9);
  }
  else {
    do {
      while (pTVar11 = pTVar6, *(int *)(pTVar11 + 0x20) < local_a8[0]) {
        pTVar2 = pTVar11 + 0x18;
        pTVar6 = *(TcpServer **)pTVar2;
        pTVar11 = pTVar13;
        if (*(TcpServer **)pTVar2 == 0x0) goto LAB_0011bdaa;
      }
      pTVar6 = *(TcpServer **)(pTVar11 + 0x10);
      pTVar13 = pTVar11;
    } while (*(TcpServer **)(pTVar11 + 0x10) != 0x0);
LAB_0011bdaa:
    bVar18 = pTVar14 == pTVar11;
    pTVar14 = pTVar11;
    if ((bVar18) || (local_a8[0] < *(int *)(pTVar11 + 0x20))) goto LAB_0011be19;
  }
  plVar10 = *(long long **)(pTVar11 + 0x28);
  *(TcpConn **)(pTVar11 + 0x28) = this_00;
  if (plVar10 != 0x0) {
    (**(code **)(*plVar10 + 8))();
  }
  if (*(long long *)(this_ptr + 0xa8) == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  (**(code **)(this_ptr + 0xb0))(this_ptr + 0x98,this_00);
  if ((allocator *)(local_88[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_88[0] + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar7 = *(int *)(local_88[0] + -8);
      *(int *)(local_88[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_88[0] + -0x18));
    }
  }
  if ((allocator *)(local_98[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_98[0] + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar7 = *(int *)(local_98[0] + -8);
      *(int *)(local_98[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_98[0] + -0x18));
    }
  }
LAB_0011bb1e:
  p_Var17 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0xd0);
  p_Var15 = p_Var17;
  if (*(_Rb_tree_node_base **)(this_ptr + 0xd0) != 0x0) {
    do {
      while (p_Var16 = p_Var5, *(int *)(p_Var16 + 0x20) < param_1) {
        p_Var1 = p_Var16 + 0x18;
        p_Var5 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011bb4a;
      }
      p_Var5 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var15 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != 0x0);
LAB_0011bb4a:
    if ((p_Var17 != p_Var16) && (*(int *)(p_Var16 + 0x20) <= param_1)) {
      if ((param_2 & 2U) != 0) {
        rea_TcpConn__send_proc(*(TcpConn **)(p_Var16 + 0x28));
      }
      if ((param_2 & 1U) != 0) {
        rea_TcpConn__recv_proc(*(TcpConn **)(p_Var16 + 0x28));
      }
      if ((*(char *)(*(long long *)(p_Var16 + 0x28) + 0x58) == '\0') &&
         (*(char *)(*(long long *)(p_Var16 + 0x28) + 0x59) == '\0')) {
        pvVar8 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var16,p_Var17);
        if (*(long long **)((long long)pvVar8 + 0x28) != 0x0) {
          (**(code **)(**(long long **)((long long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long long)pvVar8 + 0x28) = 0;
        rea_operator_delete(pvVar8);
        *(long long *)(this_ptr + 0xe8) = *(long long *)(this_ptr + 0xe8) + -1;
      }
    }
  }
  return 0;
}
