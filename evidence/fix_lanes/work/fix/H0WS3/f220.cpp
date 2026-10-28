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
// IDX 220  001106a0  WSConn__read_data_mask
// ------------------------------------------------------------------
void rea_WSConn__read_data_mask__dup2(WSConn * this_ptr, undefined4 param_1, undefined1 param_2, long long param_3, long long param_5)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *local_88 [2];
  code *local_78;
  code *local_70;
  WSConn *local_68;
  long long local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  code *local_40;
  undefined8 local_38;
  
  local_40 = 0x0;
  local_68 = this_ptr;
  local_60 = param_3;
  local_58 = param_2;
  local_54 = param_1;
  if (*(code **)(param_5 + 0x10) != 0x0) {
    (**(code **)(param_5 + 0x10))(&local_50,param_5,2);
    local_38 = *(undefined8 *)(param_5 + 0x18);
    local_40 = *(code **)(param_5 + 0x10);
  }
  local_78 = 0x0;
  local_88[0] = (undefined8*)(uintptr_t)(rea_operator_new(0x38));
  pcVar4 = local_40;
  uVar1 = local_88[0][3];
  uVar2 = local_88[0][4];
  local_88[0][5] = 0;
  uVar3 = local_88[0][6];
  *local_88[0] = (undefined8)(uintptr_t)(local_68);
  local_88[0][1] = local_60;
  *(undefined1 *)(local_88[0] + 2) = local_58;
  *(undefined4 *)((long long)local_88[0] + 0x14) = local_54;
  local_88[0][3] = local_50;
  local_88[0][4] = uStack_48;
  local_40 = 0x0;
  local_88[0][5] = (undefined8)(uintptr_t)(pcVar4);
  local_88[0][6] = local_38;
  local_70 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00110e50);
  local_78 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010ed20);
  local_50 = uVar1;
  uStack_48 = uVar2;
  local_38 = uVar3;
  recv_more(this_ptr,param_3 + 4,local_88);
  if (local_78 != 0x0) {
    (*local_78)(local_88,local_88,3);
  }
  if (local_40 != 0x0) {
    (*local_40)(&local_50,&local_50,3);
  }
  return;
}
