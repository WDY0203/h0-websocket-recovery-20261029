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
// IDX 231  001122b0  WSConn__connect
// ------------------------------------------------------------------
void rea_WSConn__connect__dup2(WSConn * this_ptr, long long param_2)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  long long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  sbyte sVar16;
  _Rb_tree_node_base *p_Var17;
  long long lVar18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  undefined1 auVar25 [16];
  int local_108 [4];
  byte local_f8 [16];
  undefined8 local_e8;
  undefined8 local_e0;
  code *local_d8;
  undefined8 local_d0;
  char local_c8 [48];
  WSConn *local_98;
  undefined1 local_90 [16];
  code *local_80;
  undefined8 local_78;
  WSConn *local_68;
  undefined8 local_60;
  undefined8 local_58;
  code *local_50;
  undefined8 local_48;
  
  uVar9 = 0;
  local_f8[0] = 0;
  local_f8[1] = 0;
  local_f8[2] = 0;
  local_f8[3] = 0;
  local_f8[4] = 0;
  local_f8[5] = 0;
  local_f8[6] = 0;
  local_f8[7] = 0;
  local_f8[8] = 0;
  local_f8[9] = 0;
  local_f8[10] = 0;
  local_f8[0xb] = 0;
  local_f8[0xc] = 0;
  local_f8[0xd] = 0;
  local_f8[0xe] = 0;
  local_f8[0xf] = 0;
  pcVar11 = local_c8;
  iVar22 = 0;
  do {
    if (iVar22 + 1 == 0x10) {
      iVar23 = 0x10;
      sVar16 = 0x10;
      iVar22 = 1;
    }
    else {
      uVar9 = (uint)local_f8[iVar22 + 1] | uVar9 << 8;
      iVar23 = iVar22 + 2;
      if (iVar23 < 0x10) {
        lVar18 = (long long)iVar23;
        iVar23 = iVar22 + 3;
        sVar16 = 0;
        uVar9 = uVar9 << 8 | (uint)local_f8[lVar18];
        iVar22 = 3;
      }
      else {
        sVar16 = 8;
        iVar22 = 2;
      }
    }
    uVar9 = uVar9 << sVar16;
    bVar7 = (byte)((int)uVar9 >> 0x12);
    local_68 = (WSConn *)(CONCAT71((int7)((ulong)local_68 >> 8),bVar7) & 0xffffffff0000003f);
    *pcVar11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
               [(char)(bVar7 & 0x3f)];
    bVar7 = (byte)((int)uVar9 >> 0xc);
    local_68 = (WSConn *)
               (CONCAT62((*(arr_undefined1_6 *)((uint8_t *)&local_68 + 0x2)),CONCAT11(bVar7,(*(undefined1 *)((uint8_t *)&local_68 + 0x0)))) & 0xffffffffffff3fff);
    pcVar11[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                 [(char)(bVar7 & 0x3f)];
    if (iVar22 == 1) {
      pcVar11[2] = '=';
LAB_001123de:
      uVar9 = 0x40;
    }
    else {
      bVar7 = (byte)((int)uVar9 >> 6);
      local_68 = (WSConn *)
                 (CONCAT53((*(arr_undefined1_5 *)((uint8_t *)&local_68 + 0x3)),CONCAT12(bVar7,(*(undefined2 *)((uint8_t *)&local_68 + 0x0)))) & 0xffffffffff3fffff);
      pcVar11[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                   [(char)(bVar7 & 0x3f)];
      if (iVar22 != 3) goto LAB_001123de;
      uVar9 = uVar9 & 0x3f;
    }
    pcVar11[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="[(int)uVar9];
    if (0xf < iVar23) break;
    uVar9 = (uint)local_f8[iVar23];
    pcVar11 = pcVar11 + 4;
    iVar22 = iVar23;
  } while( true );
  pcVar11[4] = '\0';
  pcVar11 = (char*)(uintptr_t)(rea_operator_new(0x18));
  pcVar11[0] = '\0';
  pcVar11[1] = '\0';
  pcVar11[2] = '\0';
  pcVar11[3] = '\0';
  pcVar11[4] = '\0';
  pcVar11[5] = '\0';
  pcVar11[6] = '\0';
  pcVar11[7] = '\0';
  pcVar11[8] = '\0';
  pcVar11[9] = '\0';
  pcVar11[10] = '\0';
  pcVar11[0xb] = '\0';
  pcVar11[0xc] = '\0';
  pcVar11[0xd] = '\0';
  pcVar11[0xe] = '\0';
  pcVar11[0xf] = '\0';
  pcVar11[0x10] = '\0';
  pcVar11[0x11] = '\0';
  pcVar11[0x12] = '\0';
  pcVar11[0x13] = '\0';
  pcVar11[0x14] = '\0';
  pcVar11[0x15] = '\0';
  pcVar11[0x16] = '\0';
  pcVar11[0x17] = '\0';
  rea_Buffer__appendf(pcVar11,
                  "GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Key: %s\r\nSec-WebSocket-Extensions: permessage-deflate\r\nSec-WebSocket-Version: 13\r\n\r\n"
                  ,local_c8);
  local_80 = 0x0;
  local_98 = this_ptr;
  if (*(code **)(param_2 + 0x10) != 0x0) {
    (**(code **)(param_2 + 0x10))(local_90,param_2,2);
    local_78 = *(undefined8 *)(param_2 + 0x18);
    local_80 = *(code **)(param_2 + 0x10);
  }
  lVar18 = *(long long *)(this_ptr + 0x38);
  if (*(char *)(lVar18 + 0x5a) != '\0') {
    rea_fwrite((void*)(uintptr_t)("send(): send_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar12 = *(undefined8 **)(lVar18 + 0x60);
  *(undefined1 *)(lVar18 + 0x5a) = 1;
  *(char **)(lVar18 + 0x60) = pcVar11;
  if (puVar12 != 0x0) {
    if ((void *)*puVar12 != 0x0) {
      rea_operator_delete((void *)*puVar12);
    }
    rea_operator_delete(puVar12);
  }
  local_50 = 0x0;
  local_68 = local_98;
  if (local_80 != 0x0) {
    (*local_80)(&local_60,local_90,2);
    local_48 = local_78;
    local_50 = local_80;
  }
  local_d8 = 0x0;
  puVar12 = (undefined8*)(uintptr_t)(rea_operator_new(0x28));
  pcVar8 = local_50;
  uVar3 = puVar12[1];
  puVar12[3] = 0;
  uVar4 = puVar12[2];
  *puVar12 = (undefined8)(uintptr_t)(local_68);
  puVar12[1] = local_60;
  puVar12[2] = local_58;
  local_50 = 0x0;
  uVar5 = puVar12[4];
  puVar12[3] = (undefined8)(uintptr_t)(pcVar8);
  puVar12[4] = local_48;
  local_e8 = *(undefined8 *)(lVar18 + 0x68);
  uVar6 = *(undefined8 *)(lVar18 + 0x70);
  *(undefined8 *)(lVar18 + 0x70) = local_e0;
  *(undefined8 **)(lVar18 + 0x68) = puVar12;
  local_d8 = *(code **)(lVar18 + 0x78);
  local_d0 = *(undefined8 *)(lVar18 + 0x80);
  *(code **)(lVar18 + 0x78) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010e1d0);
  *(code **)(lVar18 + 0x80) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010fc40);
  local_e0 = uVar6;
  local_60 = uVar3;
  local_58 = uVar4;
  local_48 = uVar5;
  if (local_d8 != 0x0) {
    (*local_d8)(&local_e8,&local_e8,3);
  }
  if (local_50 != 0x0) {
    (*local_50)(&local_60,&local_60,3);
  }
  local_108[0] = *(int *)(lVar18 + 0x40);
  cVar2 = *(char *)(lVar18 + 0x5a);
  lVar18 = *(long long *)(lVar18 + 0x38);
  p_Var15 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var20 = p_Var15;
  p_Var19 = p_Var14;
  if (p_Var15 == 0x0) {
LAB_00112970:
    lVar13 = 0;
    uVar9 = 0;
  }
  else {
    do {
      while (p_Var17 = p_Var20, local_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var20 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var19 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == 0x0)
        goto LAB_0011265b;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var20 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var19;
    } while (*(_Rb_tree_node_base **)p_Var1 != 0x0);
LAB_0011265b:
    if ((p_Var14 == p_Var17) || (p_Var20 = p_Var14, local_108[0] < *(int *)(p_Var17 + 0x20)))
    goto LAB_00112970;
    do {
      while (p_Var19 = p_Var15, local_108[0] <= *(int *)(p_Var19 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)(p_Var19 + 0x10) == 0x0)
        goto LAB_00112693;
      }
      p_Var17 = p_Var19 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var17;
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != 0x0);
LAB_00112693:
    if ((p_Var14 == p_Var19) || (local_108[0] < *(int *)(p_Var19 + 0x20))) {
      p_Var15 = rea_operator_new(0x28);
      if (p_Var15 != 0x0) {
        *(undefined4 *)p_Var15 = 0;
        *(undefined8 *)(p_Var15 + 8) = 0;
        *(undefined8 *)(p_Var15 + 0x10) = 0;
        *(undefined8 *)(p_Var15 + 0x18) = 0;
        *(undefined4 *)(p_Var15 + 0x24) = 0;
        *(int *)(p_Var15 + 0x20) = local_108[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar18 + 8),p_Var19,p_Var15 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
      p_Var20 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar25 + 0x8)));
      p_Var19 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar25 + 0x0)));
      if (p_Var20 == 0x0) {
        rea_operator_delete(p_Var15);
      }
      else {
        bVar21 = true;
        if ((p_Var19 == 0x0) && (p_Var14 != p_Var20)) {
          bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var20 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var20,p_Var14);
        *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
        p_Var19 = p_Var15;
      }
    }
    uVar9 = *(uint *)(p_Var19 + 0x24);
    lVar13 = 1;
  }
  lVar18 = lVar18 + (lVar13 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar18 + 8);
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var15 = p_Var14;
  p_Var20 = p_Var19;
  uVar10 = uVar9;
  if (p_Var14 != 0x0) {
    do {
      while (p_Var17 = p_Var15, local_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var20 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == 0x0)
        goto LAB_001126fa;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var1 != 0x0);
LAB_001126fa:
    if ((p_Var19 != p_Var17) && (p_Var15 = p_Var19, *(int *)(p_Var17 + 0x20) <= local_108[0])) {
      do {
        while (p_Var20 = p_Var14, local_108[0] <= *(int *)(p_Var20 + 0x20)) {
          p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
          p_Var15 = p_Var20;
          if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == 0x0)
          goto LAB_0011272a;
        }
        p_Var17 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var17;
        p_Var20 = p_Var15;
      } while (*(_Rb_tree_node_base **)p_Var17 != 0x0);
LAB_0011272a:
      if ((p_Var19 == p_Var20) || (local_108[0] < *(int *)(p_Var20 + 0x20))) {
        p_Var14 = rea_operator_new(0x28);
        if (p_Var14 != 0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_108[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var20,p_Var14 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
        p_Var15 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar25 + 0x8)));
        p_Var20 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar25 + 0x0)));
        if (p_Var15 == 0x0) {
          rea_operator_delete(p_Var14);
        }
        else {
          bVar21 = true;
          if ((p_Var20 == 0x0) && (p_Var19 != p_Var15)) {
            bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var15 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var15,p_Var19);
          *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
          p_Var20 = p_Var14;
        }
      }
      uVar10 = *(uint *)(p_Var20 + 0x24);
    }
  }
  uVar24 = uVar10 | 2;
  if (cVar2 == '\0') {
    uVar24 = uVar10 & 0xfffffffd;
  }
  if (uVar9 == uVar24) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_108);
    goto LAB_00112819;
  }
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var20 = p_Var19;
  p_Var15 = p_Var19;
  if (*(_Rb_tree_node_base **)(lVar18 + 0x18) == 0x0) {
LAB_0011279c:
    p_Var14 = rea_operator_new(0x28);
    if (p_Var14 != 0x0) {
      *(undefined4 *)p_Var14 = 0;
      *(undefined8 *)(p_Var14 + 8) = 0;
      *(undefined8 *)(p_Var14 + 0x10) = 0;
      *(undefined8 *)(p_Var14 + 0x18) = 0;
      *(undefined4 *)(p_Var14 + 0x24) = 0;
      *(int *)(p_Var14 + 0x20) = local_108[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var14 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
    p_Var20 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar25 + 0x8)));
    p_Var15 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar25 + 0x0)));
    if (p_Var20 == 0x0) {
      rea_operator_delete(p_Var14);
    }
    else {
      bVar21 = true;
      if ((p_Var15 == 0x0) && (p_Var19 != p_Var20)) {
        bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var20 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var20,p_Var19);
      *(long long *)(lVar18 + 0x30) = *(long long *)(lVar18 + 0x30) + 1;
      p_Var15 = p_Var14;
    }
  }
  else {
    do {
      while (p_Var15 = p_Var14, local_108[0] <= *(int *)(p_Var15 + 0x20)) {
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var20 = p_Var15;
        if (*(_Rb_tree_node_base **)(p_Var15 + 0x10) == 0x0)
        goto LAB_00112792;
      }
      p_Var17 = p_Var15 + 0x18;
      p_Var14 = *(_Rb_tree_node_base **)p_Var17;
      p_Var15 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != 0x0);
LAB_00112792:
    if ((p_Var19 == p_Var15) || (local_108[0] < *(int *)(p_Var15 + 0x20))) goto LAB_0011279c;
  }
  *(uint *)(p_Var15 + 0x24) = uVar24;
LAB_00112819:
  if (local_80 != 0x0) {
    (*local_80)(local_90,local_90,3);
  }
  return;
}
