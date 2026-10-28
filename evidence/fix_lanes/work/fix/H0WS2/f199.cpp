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
// IDX 199  0010dbc0  FUN_0010dbc0
// ------------------------------------------------------------------
void rea_FUN_0010dbc0(long long * param_1, int param_2)
{
  long long lVar1;
  undefined8 *puVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  long long lVar6;
  size_t __n;
  undefined8 *puVar7;
  
  param_1 = (long long *)*param_1;
  lVar6 = *param_1;
  puVar7 = *(undefined8 **)(lVar6 + 0x40);
  pvVar5 = (void *)*puVar7;
  pvVar4 = rea_memmem(pvVar5,puVar7[1] - (long long)pvVar5,(void*)(uintptr_t)("permessage-deflate"),0x12);
  if (pvVar4 == 0x0) goto LAB_0010dc9e;
  *(undefined1 *)(lVar6 + 0x58) = 1;
  pvVar5 = rea_operator_new(0x70);
  lVar1 = *param_1;
  *(void **)(lVar6 + 0x60) = pvVar5;
  pvVar5 = rea_operator_new(0x70);
  *(void **)(lVar1 + 0x68) = pvVar5;
  puVar7 = *(undefined8 **)(*param_1 + 0x60);
  puVar2 = *(undefined8 **)(*param_1 + 0x68);
  puVar7[8] = 0;
  puVar7[9] = 0;
  puVar7[10] = 0;
  *(undefined4 *)(puVar7 + 1) = 0;
  *puVar7 = 0;
  iVar3 = inflateInit2_(puVar7,0xfffffff1,"1.2.7",0x70);
  if (iVar3 == 0) {
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
    *puVar2 = 0;
    iVar3 = deflateInit2_(puVar2,0xffffffff,8,0xfffffff1,8,0,"1.2.7",0x70);
    if (iVar3 != 0) {
      rea_inflateEnd(puVar7);
      goto LAB_0010dc77;
    }
  }
  else {
LAB_0010dc77:
    lVar6 = *param_1;
    *(undefined1 *)(lVar6 + 0x58) = 0;
    rea_operator_delete(*(void **)(lVar6 + 0x60));
    rea_operator_delete(*(void **)(*param_1 + 0x68));
  }
  puVar7 = *(undefined8 **)(*param_1 + 0x40);
  pvVar5 = (void *)*puVar7;
LAB_0010dc9e:
  pvVar4 = (void *)((long long)(param_2 + 4) + (long long)pvVar5);
  if (pvVar4 != pvVar5) {
    lVar6 = 0;
    if ((pvVar4 != (void *)puVar7[1]) && (__n = (long long)puVar7[1] - (long long)pvVar4, __n != 0)) {
      pvVar5 = rea_memmove(pvVar5,pvVar4,__n);
      lVar6 = puVar7[1] - (long long)pvVar4;
    }
    puVar7[1] = (long long)pvVar5 + lVar6;
  }
  if (param_1[3] == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
                    /* WARNING: Could not recover jumptable at 0x0010dce9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[4])(param_1 + 1);
  return;
}
