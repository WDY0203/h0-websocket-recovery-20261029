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
// IDX 218  0010fd40  FUN_0010fd40
// ------------------------------------------------------------------
void rea_FUN_0010fd40(long long * param_1)
{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  allocator local_79;
  long long local_78 [2];
  undefined8 *local_68 [2];
  code *local_58;
  code *local_50;
  undefined8 local_48;
  undefined1 local_40 [16];
  code *local_30;
  undefined8 local_28;
  
  puVar2 = (undefined8 *)*param_1;
  local_48 = *puVar2;
  local_30 = 0x0;
  if ((code *)puVar2[3] != 0x0) {
    (*(code *)puVar2[3])(local_40,puVar2 + 1,2);
    local_28 = puVar2[4];
    local_30 = (code *)puVar2[3];
  }
  local_58 = 0x0;
  local_68[0] = (undefined8*)(uintptr_t)(rea_operator_new(0x28));
  local_68[0][3] = 0;
  *local_68[0] = local_48;
  if (local_30 != 0x0) {
    (*local_30)(local_68[0] + 1,local_40,2);
    local_68[0][4] = local_28;
    local_68[0][3] = (undefined8)(uintptr_t)(local_30);
  }
  local_50 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010dcc0);
  local_58 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010e400);
  rea_std__string__string((string *)local_78,"\r\n\r\n",&local_79);
  rea_WSConn__recv_pat((WSConn *)*puVar2,(string *)local_78,(long long int)(uintptr_t)(local_68));
  if ((allocator *)(local_78[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_78[0] + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar3 = *(int *)(local_78[0] + -8);
      *(int *)(local_78[0] + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_78[0] + -0x18));
    }
  }
  if (local_58 != 0x0) {
    (*local_58)(local_68,local_68,3);
  }
  if (local_30 != 0x0) {
    (*local_30)(local_40,local_40,3);
  }
  return;
}
