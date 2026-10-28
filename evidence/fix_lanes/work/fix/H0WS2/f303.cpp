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
// IDX 303  0011e940  UnixClient__poll
// ------------------------------------------------------------------
byte rea_UnixClient__poll(UnixClient * this_ptr, int param_1, int param_2)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  long long lVar7;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  bool bVar10;
  TcpConn *this_00;
  _Rb_tree_node_base *p_Var11;
  uint uVar12;
  undefined1 auVar13 [16];
  int local_78 [4];
  socklen_t local_68 [4];
  int local_58 [4];
  int local_48 [6];
  
  if (*(int *)(this_ptr + 0x98) == 1) {
    this_00 = *(TcpConn **)(this_ptr + 0xa0);
    if (*(int *)(this_00 + 0x40) == param_1) {
      if ((param_2 & 2U) != 0) {
        rea_TcpConn__send_proc(this_00);
        this_00 = *(TcpConn **)(this_ptr + 0xa0);
      }
      if ((param_2 & 1U) != 0) {
        rea_TcpConn__recv_proc(this_00);
        this_00 = *(TcpConn **)(this_ptr + 0xa0);
      }
    }
    if (this_00[0x58] != (TcpConn)0x0) {
      return 0;
    }
    return (byte)this_00[0x59] ^ 1;
  }
  if (*(int *)(this_ptr + 0x98) == 2) {
    return 1;
  }
  if (param_1 != *(int *)(*(long long *)(this_ptr + 0xa0) + 0x40)) {
    return 0;
  }
  if ((param_2 & 2U) == 0) {
    return 0;
  }
  local_68[0] = 4;
  rea_getsockopt(param_1,1,4,local_78,local_68);
  iVar2 = local_78[0];
  if (local_78[0] == 0) {
    p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
    *(undefined4 *)(this_ptr + 0x98) = 1;
    p_Var9 = (_Rb_tree_node_base *)(this_ptr + 0x10);
    p_Var5 = p_Var6;
    p_Var11 = p_Var9;
    local_48[0] = param_1;
    if (p_Var6 == 0x0) {
LAB_0011f0bd:
      lVar7 = 0;
      uVar12 = 0;
    }
    else {
      do {
        if (*(int *)(p_Var5 + 0x20) < param_1) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
          p_Var11 = p_Var5;
        }
        p_Var5 = p_Var8;
      } while (p_Var8 != 0x0);
      if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
      goto LAB_0011f0bd;
      do {
        if (*(int *)(p_Var6 + 0x20) < param_1) {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var11;
      } while (p_Var11 != 0x0);
      if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != 0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(this_ptr + 8),p_Var5,p_Var6 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var11 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x8)));
        p_Var5 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x0)));
        if (p_Var11 == 0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var5 == 0x0) && (p_Var9 != p_Var11)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
          *(long long *)(this_ptr + 0x30) = *(long long *)(this_ptr + 0x30) + 1;
          p_Var5 = p_Var6;
        }
      }
      uVar12 = *(uint *)(p_Var5 + 0x24);
      lVar7 = 1;
    }
    lVar7 = lVar7 + 1;
    p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + lVar7 * 0x30 + 8);
    p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
    p_Var11 = (_Rb_tree_node_base *)(this_ptr + lVar7 * 0x30 + 0x10);
    p_Var6 = p_Var9;
    p_Var5 = p_Var11;
    uVar3 = uVar12;
    if (p_Var9 != 0x0) {
      do {
        if (*(int *)(p_Var6 + 0x20) < local_48[0]) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var8;
      } while (p_Var8 != 0x0);
      if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_48[0])) {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != 0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) {
          p_Var9 = rea_operator_new(0x28);
          if (p_Var9 != 0x0) {
            *(undefined4 *)p_Var9 = 0;
            *(undefined8 *)(p_Var9 + 8) = 0;
            *(undefined8 *)(p_Var9 + 0x10) = 0;
            *(undefined8 *)(p_Var9 + 0x18) = 0;
            *(undefined4 *)(p_Var9 + 0x24) = 0;
            *(int *)(p_Var9 + 0x20) = local_48[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
          p_Var5 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x8)));
          p_Var6 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x0)));
          if (p_Var5 == 0x0) {
            rea_operator_delete(p_Var9);
          }
          else {
            bVar10 = true;
            if ((p_Var6 == 0x0) && (p_Var11 != p_Var5)) {
              bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
            *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
            p_Var6 = p_Var9;
          }
        }
        uVar3 = *(uint *)(p_Var6 + 0x24);
      }
    }
    if ((uVar3 & 0xfffffffd) == uVar12) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var1,local_48);
    }
    else {
      p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
      p_Var6 = p_Var11;
      if (p_Var9 == 0x0) {
LAB_0011f018:
        p_Var9 = rea_operator_new(0x28);
        if (p_Var9 != 0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var5 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x8)));
        p_Var6 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x0)));
        if (p_Var5 == 0x0) {
          rea_operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == 0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      else {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != 0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011f018;
      }
      *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
    }
    if (*(long long *)(this_ptr + 0xb8) != 0) {
      (**(code **)(this_ptr + 0xc0))(this_ptr + 0xa8,*(undefined8 *)(this_ptr + 0xa0));
      return 0;
    }
    goto LAB_0011f251;
  }
  *(undefined4 *)(this_ptr + 0x98) = 2;
  p_Var9 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  piVar4 = rea___errno_location();
  *piVar4 = iVar2;
  rea_perror("connect");
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  p_Var5 = p_Var6;
  p_Var11 = p_Var9;
  local_58[0] = param_1;
  if (p_Var6 == 0x0) {
LAB_0011f0c7:
    lVar7 = 0;
    uVar12 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var5 + 0x20) < param_1) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
        p_Var11 = p_Var5;
      }
      p_Var5 = p_Var8;
    } while (p_Var8 != 0x0);
    if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
    goto LAB_0011f0c7;
    do {
      if (*(int *)(p_Var6 + 0x20) < param_1) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var11;
    } while (p_Var11 != 0x0);
    if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != 0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_58[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var5,p_Var6 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
      p_Var11 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x8)));
      p_Var5 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x0)));
      if (p_Var11 == 0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var5 == 0x0) && (p_Var9 != p_Var11)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
        *(long long *)(this_ptr + 0x30) = *(long long *)(this_ptr + 0x30) + 1;
        p_Var5 = p_Var6;
      }
    }
    uVar12 = *(uint *)(p_Var5 + 0x24);
    lVar7 = 1;
  }
  lVar7 = lVar7 + 1;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(this_ptr + lVar7 * 0x30 + 8);
  p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(this_ptr + lVar7 * 0x30 + 0x10);
  p_Var6 = p_Var9;
  p_Var5 = p_Var11;
  uVar3 = uVar12;
  if (p_Var9 != 0x0) {
    do {
      if (*(int *)(p_Var6 + 0x20) < local_58[0]) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var8;
    } while (p_Var8 != 0x0);
    if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_58[0])) {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != 0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) {
        p_Var9 = rea_operator_new(0x28);
        if (p_Var9 != 0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_58[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var5 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x8)));
        p_Var6 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x0)));
        if (p_Var5 == 0x0) {
          rea_operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == 0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      uVar3 = *(uint *)(p_Var6 + 0x24);
    }
  }
  if ((uVar3 & 0xfffffffd) == uVar12) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,local_58);
  }
  else {
    p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
    p_Var6 = p_Var11;
    if (p_Var9 == 0x0) {
LAB_0011ef69:
      p_Var9 = rea_operator_new(0x28);
      if (p_Var9 != 0x0) {
        *(undefined4 *)p_Var9 = 0;
        *(undefined8 *)(p_Var9 + 8) = 0;
        *(undefined8 *)(p_Var9 + 0x10) = 0;
        *(undefined8 *)(p_Var9 + 0x18) = 0;
        *(undefined4 *)(p_Var9 + 0x24) = 0;
        *(int *)(p_Var9 + 0x20) = local_58[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
      p_Var5 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x8)));
      p_Var6 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar13 + 0x0)));
      if (p_Var5 == 0x0) {
        rea_operator_delete(p_Var9);
      }
      else {
        bVar10 = true;
        if ((p_Var6 == 0x0) && (p_Var11 != p_Var5)) {
          bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
        *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
        p_Var6 = p_Var9;
      }
    }
    else {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != 0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011ef69;
    }
    *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
  }
  if (*(long long *)(this_ptr + 0xd8) != 0) {
    (**(code **)(this_ptr + 0xe0))(this_ptr + 200,local_78[0]);
    return 1;
  }
LAB_0011f251:
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}
