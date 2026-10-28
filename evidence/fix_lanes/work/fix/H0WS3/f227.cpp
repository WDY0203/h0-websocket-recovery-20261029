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
// IDX 227  001115a0  FUN_001115a0
// ------------------------------------------------------------------
void rea_FUN_001115a0(long long * param_1)
{
  byte *__src;
  byte bVar1;
  byte bVar2;
  undefined8 *puVar3;
  code *pcVar4;
  byte *__dest;
  long long lVar5;
  size_t __n;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  long long *local_98 [2];
  code *local_88;
  code *local_80;
  long long local_78;
  byte local_70;
  uint local_6c;
  code *local_68;
  long long alStack_60 [2];
  code *local_50;
  long long local_48;
  
  param_1 = (long long *)*param_1;
  local_78 = *param_1;
  puVar3 = *(undefined8 **)(local_78 + 0x40);
  __dest = (byte *)*puVar3;
  bVar1 = *__dest;
  bVar2 = __dest[1];
  bVar8 = bVar1 >> 7;
  local_70 = bVar2 >> 7;
  uVar7 = bVar1 & 0xf;
  bVar6 = bVar2;
  if ((bVar1 & 0x40) != 0) {
    *(undefined1 *)(local_78 + 0x59) = 1;
    bVar6 = __dest[1];
  }
  bVar6 = bVar6 & 0x7f;
  local_6c = uVar7;
  if (bVar6 == 0x7e) {
    local_68 = (code *)CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_68 + 0x1)),bVar8);
    local_50 = 0x0;
    if ((code *)param_1[3] != 0x0) {
      (*(code *)param_1[3])(alStack_60,param_1 + 1,2);
      local_48 = param_1[4];
      local_50 = (code *)param_1[3];
    }
    local_88 = 0x0;
    local_98[0] = (long long int*)(uintptr_t)(rea_operator_new(0x38));
    *local_98[0] = local_78;
    *(byte *)(local_98[0] + 1) = local_70;
    *(uint *)((long long)local_98[0] + 0xc) = local_6c;
    local_98[0][5] = 0;
    *(undefined1 *)(local_98[0] + 2) = (*(undefined1 *)((uint8_t *)&local_68 + 0x0));
    if (local_50 != 0x0) {
      (*local_50)(local_98[0] + 3,alStack_60,2);
      local_98[0][6] = local_48;
      local_98[0][5] = (long long)local_50;
    }
    local_80 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00110a20);
    local_88 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010ebd0);
    rea_WSConn__recv_more((WSConn *)*param_1,4,(long long int)(uintptr_t)(local_98));
    if (local_88 != 0x0) {
      (*local_88)(local_98,local_98,3);
    }
    if (local_50 != 0x0) {
      (*local_50)(alStack_60,alStack_60,3);
      return;
    }
  }
  else if (bVar6 == 0x7f) {
    local_68 = (code *)CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_68 + 0x1)),bVar8);
    local_50 = 0x0;
    if ((code *)param_1[3] != 0x0) {
      (*(code *)param_1[3])(alStack_60,param_1 + 1,2);
      local_48 = param_1[4];
      local_50 = (code *)param_1[3];
    }
    local_88 = 0x0;
    local_98[0] = (long long int*)(uintptr_t)(rea_operator_new(0x38));
    *local_98[0] = local_78;
    *(byte *)(local_98[0] + 1) = local_70;
    *(uint *)((long long)local_98[0] + 0xc) = local_6c;
    local_98[0][5] = 0;
    *(undefined1 *)(local_98[0] + 2) = (*(undefined1 *)((uint8_t *)&local_68 + 0x0));
    if (local_50 != 0x0) {
      (*local_50)(local_98[0] + 3,alStack_60,2);
      local_98[0][6] = local_48;
      local_98[0][5] = (long long)local_50;
    }
    local_80 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00111b50);
    local_88 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010e930);
    rea_WSConn__recv_more((WSConn *)*param_1,10,(long long int)(uintptr_t)(local_98));
    if (local_88 != 0x0) {
      (*local_88)(local_98,local_98,3);
    }
    if (local_50 != 0x0) {
      (*local_50)(alStack_60,alStack_60,3);
      return;
    }
  }
  else {
    __src = __dest + 2;
    lVar5 = 0;
    if ((__src != (byte *)puVar3[1]) && (__n = (long long)puVar3[1] - (long long)__src, __n != 0)) {
      __dest = (byte*)(uintptr_t)(rea_memmove(__dest,__src,__n));
      lVar5 = puVar3[1] - (long long)__src;
    }
    puVar3[1] =(undefined8)(uintptr_t)( __dest) + lVar5;
    local_68 = 0x0;
    pcVar4 = (code *)param_1[3];
    if ((char)bVar2 < '\0') {
      if (pcVar4 != 0x0) {
        (*pcVar4)(&local_78,param_1 + 1,2);
        local_68 = (code *)param_1[3];
        alStack_60[0] = param_1[4];
      }
      rea_WSConn__read_data_mask((WSConn *)*param_1,uVar7,bVar8,bVar6,(long long int)(uintptr_t)(&local_78));
      if (local_68 != 0x0) {
        (*local_68)(&local_78,&local_78,3);
        return;
      }
    }
    else {
      if (pcVar4 != 0x0) {
        (*pcVar4)(&local_78,param_1 + 1,2);
        local_68 = (code *)param_1[3];
        alStack_60[0] = param_1[4];
      }
      rea_WSConn__read_data((WSConn *)*param_1,uVar7,bVar8,bVar6,(long long int)(uintptr_t)(&local_78));
      if (local_68 != 0x0) {
        (*local_68)(&local_78,&local_78,3);
      }
    }
  }
  return;
}
