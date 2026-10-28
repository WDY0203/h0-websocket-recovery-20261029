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
// IDX 168  00108990  FUN_00108990
// ------------------------------------------------------------------
undefined8 rea_FUN_00108990(undefined8 param_1, undefined8 param_2)
{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_198 [2];
  long long local_188 [2];
  undefined2 local_178 [4];
  long long local_170;
  undefined1 local_168[0x98];
  sigset_t local_160;
  undefined4 local_e0;
  sigaction local_c8;
  
  (*(code **)((uint8_t *)&local_168 + 0x0)) = 0x0;
  local_e0 = 0;
  rea_sigemptyset(&local_160);
  rea_sigaction(2,(sigaction *)&local_168,&local_c8);
  local_178[0] = 0x4f;
  iVar3 = rea_PyArg_ParseTuple(param_2,local_178,local_198);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = rea_PyLong_AsVoidPtr(local_198[0]);
    rea_FUN_001085c0(0,(undefined4*)(uintptr_t)(local_178),(EventLoop2*)(uintptr_t)(uVar4));
    rea_std__string__string((string *)local_188,(string *)&local_170);
    puVar2 = PTR__S_empty_rep_storage_00324fa0;
    if ((allocator *)(local_170 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_170 + -8);
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar3 = *(int *)(local_170 + -8);
        *(int *)(local_170 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_170 + -0x18));
      }
    }
    uVar4 = rea_PyString_FromStringAndSize(local_188[0],*(undefined8 *)(local_188[0] + -0x18));
    if ((allocator *)(local_188[0] + -0x18) != (allocator *)puVar2) {
      piVar1 = (int *)(local_188[0] + -8);
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar3 = *(int *)(local_188[0] + -8);
        *(int *)(local_188[0] + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_188[0] + -0x18));
      }
    }
  }
  rea_sigaction(2,&local_c8,0x0);
  return uVar4;
}
