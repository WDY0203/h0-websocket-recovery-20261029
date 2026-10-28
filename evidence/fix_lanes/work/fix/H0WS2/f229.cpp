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
// IDX 229  00111c50  FUN_00111c50
// ------------------------------------------------------------------
void rea_FUN_00111c50(long long * param_1, undefined8 * param_2)
{
  undefined8 *puVar1;
  void *__src;
  ulong uVar2;
  void *__dest;
  undefined8 uVar3;
  WSConn *pWVar4;
  size_t sVar5;
  void *__src_00;
  void *pvVar6;
  long long *plVar7;
  ulong uVar8;
  size_t __n;
  ulong local_68;
  undefined1 local_58 [16];
  code *local_48;
  long long lStack_40;
  
  puVar1 = (undefined8 *)*param_2;
  *param_2 = 0;
  param_1 = (long long *)*param_1;
  if (puVar1 == 0x0) {
    rea_WSConn__exit((WSConn *)*param_1);
    return;
  }
  pWVar4 = (WSConn *)*param_1;
  __src = (void *)*puVar1;
  plVar7 = *(long long **)(pWVar4 + 0x40);
  __src_00 = (void *)plVar7[1];
  if (__src != (void *)puVar1[1]) {
    uVar8 = (long long)puVar1[1] - (long long)__src;
    if ((ulong)(plVar7[2] - (long long)__src_00) < uVar8) {
      pvVar6 = (void *)*plVar7;
      sVar5 = (long long)__src_00 - (long long)pvVar6;
      if (~sVar5 < uVar8) {
        uVar3 = rea_std____throw_length_error("vector___M_range_insert");
        rea_FUN_00107772(puVar1);
                    /* WARNING: Subroutine does not return */
        rea__Unwind_Resume(uVar3);
      }
      local_68 = 0xffffffffffffffff;
      uVar2 = sVar5;
      if (sVar5 <= uVar8) {
        uVar2 = uVar8;
      }
      if ((CARRY8(uVar2,sVar5)) || (local_68 = uVar2 + sVar5, uVar2 + sVar5 != 0)) {
        __dest = rea_operator_new(local_68);
        pvVar6 = (void *)*plVar7;
        sVar5 = (long long)__src_00 - (long long)pvVar6;
      }
      else {
        local_68 = 0;
        __dest = 0x0;
      }
      if (sVar5 != 0) {
        __dest = rea_memmove(__dest,pvVar6,sVar5);
      }
      pvVar6 = (void *)(sVar5 + (long long)__dest);
      if (uVar8 != 0) {
        pvVar6 = rea_memmove(pvVar6,__src,uVar8);
      }
      __n = plVar7[1] - (long long)__src_00;
      sVar5 = 0;
      if (__n != 0) {
        rea_memmove((void *)(uVar8 + (long long)pvVar6),__src_00,__n);
        sVar5 = __n;
      }
      if ((void *)*plVar7 != 0x0) {
        rea_operator_delete((void *)*plVar7);
      }
      *plVar7 = (long long)__dest;
      pWVar4 = (WSConn *)*param_1;
      plVar7[1] = (long long)(uVar8 + (long long)pvVar6) + sVar5;
      plVar7[2] = (long long)__dest + local_68;
      plVar7 = *(long long **)(pWVar4 + 0x40);
      __src_00 = (void *)plVar7[1];
    }
    else {
      if (uVar8 != 0) {
        rea_memmove(__src_00,__src,uVar8);
        __src_00 = (void *)plVar7[1];
        pWVar4 = (WSConn *)*param_1;
      }
      plVar7[1] = (long long)__src_00 + uVar8;
      plVar7 = *(long long **)(pWVar4 + 0x40);
      __src_00 = (void *)plVar7[1];
    }
  }
  uVar8 = param_1[1];
  if ((ulong)((long long)__src_00 - *plVar7) < uVar8) {
    local_48 = 0x0;
    if ((code *)param_1[4] != 0x0) {
      (*(code *)param_1[4])(local_58,param_1 + 2,2);
      local_48 = (code *)param_1[4];
      lStack_40 = param_1[5];
      uVar8 = param_1[1];
      pWVar4 = (WSConn *)*param_1;
    }
    rea_WSConn__recv_more(pWVar4,uVar8,(long long int)(uintptr_t)(local_58));
    if (local_48 != 0x0) {
      (*local_48)(local_58,local_58,3);
    }
  }
  else {
    if (param_1[4] == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (*(code *)param_1[5])(param_1 + 2);
  }
  if ((void *)*puVar1 != 0x0) {
    rea_operator_delete((void *)*puVar1);
  }
  rea_operator_delete(puVar1);
  return;
}
