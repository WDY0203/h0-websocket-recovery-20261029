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
// IDX 186  0010b320  _Function_handler<void
// ------------------------------------------------------------------
undefined8 rea__Function_handler_void__dup2(undefined8 * param_1, undefined8 * param_2, undefined8 * param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 local_78;
  undefined8 local_70;
  code *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 uStack_40;
  undefined8 *local_38 [2];
  code *local_28;
  undefined *local_20;
  
  puVar1 = (undefined8 *)*param_3;
  *param_3 = 0;
  uVar2 = *param_2;
  uVar3 = param_2[1];
  *param_2 = local_78;
  param_2[1] = local_70;
  local_68 = (code *)param_2[2];
  uVar4 = param_2[3];
  param_2[2] = 0;
  param_2[3] = uStack_60;
  param_1 = (undefined8 *)*param_1;
  local_78 = uVar2;
  local_70 = uVar3;
  uStack_60 = uVar4;
  if (puVar1 != 0x0) {
    local_48 = 0x0;
    if (local_68 != 0x0) {
      (*local_68)(&local_58,&local_78,2);
      local_48 = local_68;
      uStack_40 = uStack_60;
    }
    local_28 = 0x0;
    local_38[0] = (undefined8*)(uintptr_t)(rea_operator_new(0x20));
    pcVar5 = local_48;
    local_38[0][2] = 0;
    uVar2 = *local_38[0];
    uVar3 = local_38[0][1];
    uVar4 = local_38[0][3];
    local_38[0][1] = local_50;
    *local_38[0] = local_58;
    local_48 = 0x0;
    local_38[0][2] = (undefined8)(uintptr_t)(pcVar5);
    local_38[0][3] = uStack_40;
    local_20 = PTR__M_invoke_00324fe0;
    local_28 = (code *)PTR__M_manager_00324f88;
    local_58 = uVar2;
    local_50 = uVar3;
    uStack_40 = uVar4;
    rea_WSConn__recv((WSConn *)*param_1,(long long int)(uintptr_t)(local_38));
    if (local_28 != 0x0) {
      (*local_28)(local_38,local_38,3);
    }
    if (local_48 != 0x0) {
      (*local_48)(&local_58,&local_58,3);
    }
  }
  if (local_68 != 0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  if (puVar1 != 0x0) {
    if ((void *)*puVar1 != 0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  return 0;
}
