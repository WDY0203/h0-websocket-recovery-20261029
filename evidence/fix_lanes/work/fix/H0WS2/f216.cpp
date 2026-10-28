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
// IDX 216  0010f940  WSConn__accept
// ------------------------------------------------------------------
void rea_WSConn__accept(WSConn * this_ptr, long long param_2, long long param_3)
{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  code *pcVar9;
  int iVar10;
  allocator local_aa [2];
  long long local_a8 [2];
  undefined8 *local_98 [2];
  code *local_88;
  code *local_80;
  WSConn *local_78;
  undefined8 local_70;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  code *local_40;
  undefined8 local_38;
  
  local_60 = 0x0;
  local_78 = this_ptr;
  if (*(code **)(param_2 + 0x10) != 0x0) {
    (**(code **)(param_2 + 0x10))(&local_70,param_2,2);
    local_58 = *(undefined8 *)(param_2 + 0x18);
    local_60 = *(code **)(param_2 + 0x10);
  }
  local_40 = 0x0;
  if (*(code **)(param_3 + 0x10) != 0x0) {
    (**(code **)(param_3 + 0x10))(&local_50,param_3,2);
    local_38 = *(undefined8 *)(param_3 + 0x18);
    local_40 = *(code **)(param_3 + 0x10);
  }
  local_88 = 0x0;
  local_98[0] = (undefined8*)(uintptr_t)(rea_operator_new(0x48));
  pcVar9 = local_40;
  pcVar8 = local_60;
  local_98[0][3] = 0;
  uVar2 = local_98[0][1];
  uVar3 = local_98[0][2];
  uVar4 = local_98[0][4];
  local_98[0][7] = 0;
  *local_98[0] = (undefined8)(uintptr_t)(local_78);
  uVar5 = local_98[0][6];
  local_98[0][2] = local_68;
  uVar6 = local_98[0][5];
  local_98[0][1] = local_70;
  local_60 = 0x0;
  local_98[0][3] = (undefined8)(uintptr_t)(pcVar8);
  uVar7 = local_98[0][8];
  local_98[0][4] = local_58;
  local_98[0][6] = local_48;
  local_98[0][5] = local_50;
  local_40 = 0x0;
  local_98[0][7] = (undefined8)(uintptr_t)(pcVar9);
  local_98[0][8] = local_38;
  local_80 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00112b60);
  local_88 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010e560);
  local_70 = uVar2;
  local_68 = uVar3;
  local_58 = uVar4;
  local_50 = uVar6;
  local_48 = uVar5;
  local_38 = uVar7;
  rea_std__string__string((string *)local_a8,"\r\n\r\n",local_aa);
  recv_pat(this_ptr,(string *)local_a8,local_98);
  if ((allocator *)(local_a8[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_a8[0] + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar10 = *(int *)(local_a8[0] + -8);
      *(int *)(local_a8[0] + -8) = iVar10 + -1;
    }
    else {
      LOCK();
      iVar10 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar10 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_a8[0] + -0x18));
    }
  }
  if (local_88 != 0x0) {
    (*local_88)(local_98,local_98,3);
  }
  if (local_40 != 0x0) {
    (*local_40)(&local_50,&local_50,3);
  }
  if (local_60 != 0x0) {
    (*local_60)(&local_70,&local_70,3);
  }
  return;
}
