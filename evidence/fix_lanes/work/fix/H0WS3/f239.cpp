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
// IDX 239  001159c0  Buffer__appendf
// ------------------------------------------------------------------
void rea_Buffer__appendf__dup2(char * param_1, undefined8 param_x1)
{
  undefined8 stack0x00000008;
  int iVar1;
  char in_AL;
  int iVar2;
  void *pvVar3;
  undefined8 in_RCX;
  undefined8 in_RDX;
  ulong uVar4;
  ulong extraout_RDX;
  size_t __n;
  ulong uVar5;
  char *in_RSI;
  void *pvVar6;
  undefined8 in_R8;
  undefined8 in_R9;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  void *local_128;
  ulong local_120;
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 *local_f8;
  undefined1 *local_f0;
  undefined1 local_e8 [16];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  
  if (in_AL != '\0') {
    local_b8 = in_XMM0_Qa;
    local_a8 = in_XMM1_Qa;
    local_98 = in_XMM2_Qa;
    local_88 = in_XMM3_Qa;
    local_78 = in_XMM4_Qa;
    local_68 = in_XMM5_Qa;
    local_58 = in_XMM6_Qa;
    local_48 = in_XMM7_Qa;
  }
  local_f8 = (undefined1*)(uintptr_t)((void *)&stack0x00000008);
  local_f0 = local_e8;
  local_100 = 0x10;
  local_fc = 0x30;
  local_d8 = in_RDX;
  local_d0 = in_RCX;
  local_c8 = in_R8;
  local_c0 = in_R9;
  iVar2 = rea_vsnprintf(0x0,0,in_RSI,(__gnuc_va_list)(uintptr_t)(&local_100));
  pvVar3 = *(void **)(param_1 + 8);
  pvVar6 = *(void **)param_1;
  __n = (long long)pvVar3 - (long long)pvVar6;
  iVar1 = (int)__n;
  uVar7 = iVar2 + iVar1;
  uVar8 = (ulong)uVar7;
  uVar9 = (ulong)(int)(uVar7 + 1);
  if (__n < uVar9) {
    uVar9 = uVar9 - __n;
    if (uVar9 == 0) goto LAB_00115a94;
    if (uVar9 <= (ulong)(*(long long *)(param_1 + 0x10) - (long long)pvVar3)) {
      rea_memset(pvVar3,0,uVar9);
      *(ulong *)(param_1 + 8) = *(long long *)(param_1 + 8) + uVar9;
      goto LAB_00115a94;
    }
    if (uVar9 <= ~__n) {
      local_120 = 0xffffffffffffffff;
      uVar8 = __n;
      if (__n <= uVar9) {
        uVar8 = uVar9;
      }
      if ((CARRY8(uVar8,__n)) || (local_120 = uVar8 + __n, uVar8 + __n != 0)) {
        local_128 = rea_operator_new(local_120);
        pvVar6 = *(void **)param_1;
        __n = *(long long *)(param_1 + 8) - (long long)pvVar6;
      }
      else {
        local_120 = 0;
        local_128 = 0x0;
      }
      if (__n != 0) {
        rea_memmove(local_128,pvVar6,__n);
      }
      pvVar3 = (void *)((long long)local_128 + __n);
      rea_memset(pvVar3,0,(uVar9 + (long long)pvVar3) - (long long)pvVar3);
      if (*(void **)param_1 != 0x0) {
        rea_operator_delete(*(void **)param_1);
      }
      *(ulong *)(param_1 + 8) = uVar9 + (long long)pvVar3;
      *(void **)param_1 = local_128;
      *(ulong *)(param_1 + 0x10) = (long long)local_128 + local_120;
      goto LAB_00115a94;
    }
LAB_00115d22:
    rea_std____throw_length_error("vector___M_default_append");
    uVar5 = extraout_RDX;
  }
  else {
    if (uVar9 < __n) {
      *(ulong *)(param_1 + 8) = uVar9 + (long long)pvVar6;
    }
LAB_00115a94:
    local_f8 = (undefined1*)(uintptr_t)((void *)&stack0x00000008);
    local_100 = 0x10;
    local_f0 = local_e8;
    local_fc = 0x30;
    uVar8 = (ulong)(int)uVar7;
    rea_vsnprintf((char *)((long long)iVar1 + *(long long *)param_1),(long long)(iVar2 + 1),in_RSI,(__gnuc_va_list)(uintptr_t)(&local_100));
    pvVar3 = *(void **)(param_1 + 8);
    pvVar6 = *(void **)param_1;
    uVar9 = (long long)pvVar3 - (long long)pvVar6;
    if (uVar8 <= uVar9) {
      if (uVar9 <= uVar8) {
        return;
      }
      *(ulong *)(param_1 + 8) = uVar8 + (long long)pvVar6;
      return;
    }
    uVar8 = uVar8 - uVar9;
    if (uVar8 == 0) {
      return;
    }
    if (uVar8 <= (ulong)(*(long long *)(param_1 + 0x10) - (long long)pvVar3)) {
      rea_memset(pvVar3,0,uVar8);
      *(ulong *)(param_1 + 8) = *(long long *)(param_1 + 8) + uVar8;
      return;
    }
    if (~uVar9 < uVar8) goto LAB_00115d22;
    uVar4 = uVar9;
    if (uVar9 <= uVar8) {
      uVar4 = uVar8;
    }
    uVar5 = 0xffffffffffffffff;
    if ((!CARRY8(uVar4,uVar9)) && (uVar5 = uVar4 + uVar9, uVar4 + uVar9 == 0)) {
      uVar5 = 0;
      pvVar3 = 0x0;
      goto LAB_00115b5e;
    }
  }
  pvVar3 = rea_operator_new(uVar5);
  pvVar6 = *(void **)param_1;
  uVar9 = *(long long *)(param_1 + 8) - (long long)pvVar6;
LAB_00115b5e:
  if (uVar9 != 0) {
    rea_memmove(pvVar3,pvVar6,uVar9);
  }
  pvVar6 = (void *)((long long)pvVar3 + uVar9);
  rea_memset(pvVar6,0,(uVar8 + (long long)pvVar6) - (long long)pvVar6);
  if (*(void **)param_1 != 0x0) {
    rea_operator_delete(*(void **)param_1);
  }
  *(void **)param_1 = pvVar3;
  *(ulong *)(param_1 + 8) = uVar8 + (long long)pvVar6;
  *(ulong *)(param_1 + 0x10) = uVar5 + (long long)pvVar3;
  return;
}
