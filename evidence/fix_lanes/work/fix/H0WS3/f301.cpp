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
// IDX 301  0011de60  UnixServer__UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__UnixServer(UnixServer * this_ptr, string * param_1, long long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  bool bVar10;
  uint uVar11;
  undefined1 auVar12 [16];
  int local_b8 [4];
  undefined1 local_a8[7][0x10];
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(this_ptr + 0x38);
  *(UnixServer **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(UnixServer **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
  *(UnixServer **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(UnixServer **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar4 = PTR_vtable_00324ec8;
  *(_Rb_tree_node_base **)(this_ptr + 0x28) = p_Var1;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined **)this_ptr = puVar4 + 0x10;
  *(undefined8 *)(this_ptr + 0xa8) = 0;
  if (*(code **)(param_3 + 0x10) != 0x0) {
    (**(code **)(param_3 + 0x10))(this_ptr + 0x98,param_3,2);
    *(undefined8 *)(this_ptr + 0xb0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this_ptr + 0xa8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(undefined4 *)(this_ptr + 200) = 0;
  *(undefined8 *)(this_ptr + 0xd0) = 0;
  *(undefined8 *)(this_ptr + 0xe8) = 0;
  *(UnixServer **)(this_ptr + 0xd8) = this_ptr + 200;
  *(UnixServer **)(this_ptr + 0xe0) = this_ptr + 200;
  rea_std__string__string((string *)(this_ptr + 0xf0),param_1);
  rea_bzero(local_a8,0x6e);
  (*(undefined2 *)((uint8_t *)&local_a8[0] + 0x0)) = 1;
  rea_strncpy(((char*)(uintptr_t)((uint8_t *)&local_a8[0]) + 0x2),*(char **)param_1,0x6b);
  iVar5 = rea_socket(1,1,0);
  *(int *)(this_ptr + 0xb8) = iVar5;
  if (iVar5 < 0) {
    rea_perror("socket");
LAB_0011e437:
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setcloexec(iVar5);
  iVar5 = rea_bind(*(int *)(this_ptr + 0xb8),(sockaddr*)(uintptr_t)(local_a8),0x6e);
  if (iVar5 < 0) {
    rea_perror("bind");
    goto LAB_0011e437;
  }
  iVar5 = rea_listen(*(int *)(this_ptr + 0xb8),0x1ff);
  if (iVar5 < 0) {
    rea_perror("listen");
    goto LAB_0011e437;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  local_b8[0] = *(int *)(this_ptr + 0xb8);
  p_Var7 = p_Var6;
  p_Var8 = p_Var1;
  if (p_Var6 == 0x0) {
LAB_0011e310:
    uVar11 = 0;
  }
  else {
    do {
      while (p_Var9 = p_Var7, *(int *)(p_Var9 + 0x20) < local_b8[0]) {
        p_Var2 = p_Var9 + 0x18;
        p_Var7 = *(_Rb_tree_node_base **)p_Var2;
        p_Var9 = p_Var8;
        if (*(_Rb_tree_node_base **)p_Var2 == 0x0) goto LAB_0011e042;
      }
      p_Var7 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
      p_Var8 = p_Var9;
    } while (*(_Rb_tree_node_base **)(p_Var9 + 0x10) != 0x0);
LAB_0011e042:
    if ((p_Var1 == p_Var9) || (local_b8[0] < *(int *)(p_Var9 + 0x20))) goto LAB_0011e310;
    iVar5 = *(int *)(p_Var6 + 0x20);
    p_Var7 = p_Var1;
    while( true ) {
      if (iVar5 < local_b8[0]) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var7 = p_Var6;
      }
      p_Var6 = p_Var8;
      if (p_Var6 == 0x0) break;
      iVar5 = *(int *)(p_Var6 + 0x20);
    }
    if ((p_Var1 == p_Var7) || (local_b8[0] < *(int *)(p_Var7 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != 0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_b8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var7,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
      p_Var8 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar12 + 0x8)));
      p_Var7 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar12 + 0x0)));
      if (p_Var8 == 0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var7 == 0x0) && (p_Var1 != p_Var8)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var8 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var8,p_Var1);
        *(long long *)(this_ptr + 0x30) = *(long long *)(this_ptr + 0x30) + 1;
        p_Var7 = p_Var6;
      }
    }
    uVar11 = *(uint *)(p_Var7 + 0x24);
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(this_ptr + 0x68);
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(this_00 + 8);
  p_Var7 = p_Var6;
  p_Var8 = p_Var1;
  uVar3 = uVar11;
  if (p_Var6 != 0x0) {
    do {
      while (p_Var9 = p_Var7, *(int *)(p_Var9 + 0x20) < local_b8[0]) {
        p_Var2 = p_Var9 + 0x18;
        p_Var7 = *(_Rb_tree_node_base **)p_Var2;
        p_Var9 = p_Var8;
        if (*(_Rb_tree_node_base **)p_Var2 == 0x0) goto LAB_0011e0d2;
      }
      p_Var7 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
      p_Var8 = p_Var9;
    } while (*(_Rb_tree_node_base **)(p_Var9 + 0x10) != 0x0);
LAB_0011e0d2:
    if ((p_Var1 != p_Var9) && (p_Var7 = p_Var1, *(int *)(p_Var9 + 0x20) <= local_b8[0])) {
      do {
        while (p_Var8 = p_Var6, *(int *)(p_Var8 + 0x20) < local_b8[0]) {
          p_Var9 = p_Var8 + 0x18;
          p_Var6 = *(_Rb_tree_node_base **)p_Var9;
          p_Var8 = p_Var7;
          if (*(_Rb_tree_node_base **)p_Var9 == 0x0) goto LAB_0011e10a;
        }
        p_Var6 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
      } while (*(_Rb_tree_node_base **)(p_Var8 + 0x10) != 0x0);
LAB_0011e10a:
      if ((p_Var1 == p_Var8) || (local_b8[0] < *(int *)(p_Var8 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != 0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_b8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var8,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
        p_Var7 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar12 + 0x8)));
        p_Var8 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar12 + 0x0)));
        if (p_Var7 == 0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var8 == 0x0) && (p_Var1 != p_Var7)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
          *(long long *)(this_00 + 0x28) = *(long long *)(this_00 + 0x28) + 1;
          p_Var8 = p_Var6;
        }
      }
      uVar3 = *(uint *)(p_Var8 + 0x24);
    }
  }
  if ((uVar3 | 1) == uVar11) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_b8);
    return;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var8 = p_Var1;
  p_Var7 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_00 + 0x10) != 0x0) {
    do {
      while (p_Var7 = p_Var6, *(int *)(p_Var7 + 0x20) < local_b8[0]) {
        p_Var9 = p_Var7 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var9;
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)p_Var9 == 0x0) goto LAB_0011e162;
      }
      p_Var6 = *(_Rb_tree_node_base **)(p_Var7 + 0x10);
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)(p_Var7 + 0x10) != 0x0);
LAB_0011e162:
    if ((p_Var1 != p_Var7) && (*(int *)(p_Var7 + 0x20) <= local_b8[0])) goto LAB_0011e1eb;
  }
  p_Var6 = rea_operator_new(0x28);
  if (p_Var6 != 0x0) {
    *(undefined4 *)p_Var6 = 0;
    *(undefined8 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined4 *)(p_Var6 + 0x24) = 0;
    *(int *)(p_Var6 + 0x20) = local_b8[0];
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(this_00,p_Var7,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
  p_Var8 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar12 + 0x8)));
  p_Var7 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar12 + 0x0)));
  if (p_Var8 == 0x0) {
    rea_operator_delete(p_Var6);
  }
  else {
    bVar10 = true;
    if ((p_Var7 == 0x0) && (p_Var1 != p_Var8)) {
      bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var8 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var8,p_Var1);
    *(long long *)(this_00 + 0x28) = *(long long *)(this_00 + 0x28) + 1;
    p_Var7 = p_Var6;
  }
LAB_0011e1eb:
  *(uint *)(p_Var7 + 0x24) = uVar3 | 1;
  return;
}
