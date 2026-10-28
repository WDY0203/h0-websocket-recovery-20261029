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
// IDX 228  00111b50  FUN_00111b50
// ------------------------------------------------------------------
void rea_FUN_00111b50(long long * param_1)
{
  void *__src;
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  void *__dest;
  long long lVar5;
  size_t __n;
  long long lVar6;
  undefined1 auStack_48 [16];
  code *local_38;
  undefined8 uStack_30;
  
  puVar2 = (undefined8 *)*param_1;
  puVar3 = *(undefined8 **)((WSConn *)*puVar2 + 0x40);
  __dest = (void *)*puVar3;
  if ((((*(char *)((long long)__dest + 2) == '\0') && (*(char *)((long long)__dest + 3) == '\0')) &&
      (*(char *)((long long)__dest + 4) == '\0')) && (*(char *)((long long)__dest + 5) == '\0')) {
    __src = (void *)((long long)__dest + 10);
    lVar5 = 0;
    lVar6 = (long long)(int)((uint)*(byte *)((long long)__dest + 6) << 0x18 |
                        (uint)*(byte *)((long long)__dest + 7) << 0x10 |
                        (uint)*(byte *)((long long)__dest + 9) | (uint)*(byte *)((long long)__dest + 8) << 8);
    if ((__src != (void *)puVar3[1]) && (__n = (long long)puVar3[1] - (long long)__src, __n != 0)) {
      __dest = rea_memmove(__dest,__src,__n);
      lVar5 = puVar3[1] - (long long)__src;
    }
    cVar1 = *(char *)(puVar2 + 1);
    puVar3[1] = (long long)__dest + lVar5;
    local_38 = 0x0;
    pcVar4 = (code *)puVar2[5];
    if (cVar1 == '\0') {
      if (pcVar4 != 0x0) {
        (*pcVar4)(auStack_48,puVar2 + 3,2);
        local_38 = (code *)puVar2[5];
        uStack_30 = puVar2[6];
      }
      rea_WSConn__read_data((WSConn *)*puVar2,*(undefined4 *)((long long)puVar2 + 0xc),
                        *(undefined1 *)(puVar2 + 2),lVar6,(long long int)(uintptr_t)(auStack_48));
      if (local_38 != 0x0) {
        (*local_38)(auStack_48,auStack_48,3);
        return;
      }
    }
    else {
      if (pcVar4 != 0x0) {
        (*pcVar4)(auStack_48,puVar2 + 3,2);
        local_38 = (code *)puVar2[5];
        uStack_30 = puVar2[6];
      }
      WSConn__read_data_mask_________________((WSConn *)*puVar2,*(undefined4 *)((long long)puVar2 + 0xc),*(undefined1 *)(puVar2 + 2),
                 lVar6,auStack_48);
      if (local_38 != 0x0) {
        (*local_38)(auStack_48,auStack_48,3);
        return;
      }
    }
  }
  else {
    rea_WSConn__exit((WSConn *)*puVar2);
  }
  return;
}
