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
// IDX 170  00108bd0  FUN_00108bd0
// ------------------------------------------------------------------
long long rea_FUN_00108bd0(undefined8 param_1, undefined8 param_2)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long long lVar5;
  undefined8 uVar6;
  undefined8 local_48 [2];
  undefined8 local_38 [2];
  undefined4 local_28;
  long long local_20;
  
  uVar2 = (uint)local_28 >> 0x10;
  local_28 = CONCAT22((ushort)uVar2 & 0xff00,0x4f4f);
  iVar3 = rea_PyArg_ParseTuple(param_2,&local_28,local_48,local_38);
  if (iVar3 != 0) {
    uVar6 = rea_PyFloat_AsDouble(local_38[0]);
    uVar4 = rea_PyLong_AsVoidPtr(local_48[0]);
    rea_FUN_00108660(uVar6,&local_28,(EventLoop2*)(uintptr_t)(uVar4));
    uVar4 = rea_Py_BuildValue("l",(long long)local_28);
    uVar6 = rea_PyBytes_FromStringAndSize(local_20,*(undefined8 *)(local_20 + -0x18));
    lVar5 = rea_PyTuple_New(2);
    *(undefined8 *)(lVar5 + 0x18) = uVar4;
    *(undefined8 *)(lVar5 + 0x20) = uVar6;
    if ((allocator *)(local_20 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_20 + -8);
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar3 = *(int *)(local_20 + -8);
        *(int *)(local_20 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_20 + -0x18));
      }
    }
    return lVar5;
  }
  return 0;
}
