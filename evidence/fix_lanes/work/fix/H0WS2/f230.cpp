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
// IDX 230  00111f80  FUN_00111f80
// ------------------------------------------------------------------
void rea_FUN_00111f80(long long * param_1, undefined8 * param_2)
{
  int *piVar1;
  undefined8 *puVar2;
  void *__src;
  long long *plVar3;
  int iVar4;
  ulong uVar5;
  void *__dest;
  undefined8 uVar6;
  size_t sVar7;
  void *__src_00;
  void *pvVar8;
  ulong __n;
  size_t __n_00;
  ulong local_88;
  long long local_68 [2];
  undefined1 local_58 [16];
  code *local_48;
  long long lStack_40;
  
  puVar2 = (undefined8 *)*param_2;
  *param_2 = 0;
  param_1 = (long long *)*param_1;
  if (puVar2 == 0x0) {
    rea_WSConn__exit((WSConn *)*param_1);
    return;
  }
  __src = (void *)*puVar2;
  plVar3 = *(long long **)(*param_1 + 0x40);
  __src_00 = (void *)plVar3[1];
  if (__src != (void *)puVar2[1]) {
    __n = (long long)puVar2[1] - (long long)__src;
    if ((ulong)(plVar3[2] - (long long)__src_00) < __n) {
      pvVar8 = (void *)*plVar3;
      sVar7 = (long long)__src_00 - (long long)pvVar8;
      if (~sVar7 < __n) {
        uVar6 = rea_std____throw_length_error("vector___M_range_insert");
        rea_FUN_00107772(puVar2);
                    /* WARNING: Subroutine does not return */
        rea__Unwind_Resume(uVar6);
      }
      local_88 = 0xffffffffffffffff;
      uVar5 = sVar7;
      if (sVar7 <= __n) {
        uVar5 = __n;
      }
      if ((CARRY8(uVar5,sVar7)) || (local_88 = uVar5 + sVar7, uVar5 + sVar7 != 0)) {
        __dest = rea_operator_new(local_88);
        pvVar8 = (void *)*plVar3;
        sVar7 = (long long)__src_00 - (long long)pvVar8;
      }
      else {
        local_88 = 0;
        __dest = 0x0;
      }
      if (sVar7 != 0) {
        __dest = rea_memmove(__dest,pvVar8,sVar7);
      }
      pvVar8 = (void *)(sVar7 + (long long)__dest);
      if (__n != 0) {
        pvVar8 = rea_memmove(pvVar8,__src,__n);
      }
      __n_00 = plVar3[1] - (long long)__src_00;
      sVar7 = 0;
      if (__n_00 != 0) {
        rea_memmove((void *)(__n + (long long)pvVar8),__src_00,__n_00);
        sVar7 = __n_00;
      }
      if ((void *)*plVar3 != 0x0) {
        rea_operator_delete((void *)*plVar3);
      }
      *plVar3 = (long long)__dest;
      plVar3[1] = (long long)(__n + (long long)pvVar8) + sVar7;
      plVar3[2] = (long long)__dest + local_88;
    }
    else {
      if (__n != 0) {
        rea_memmove(__src_00,__src,__n);
        __src_00 = (void *)plVar3[1];
      }
      plVar3[1] = (long long)__src_00 + __n;
    }
  }
  local_48 = 0x0;
  if ((code *)param_1[4] != 0x0) {
    (*(code *)param_1[4])(local_58,param_1 + 2,2);
    local_48 = (code *)param_1[4];
    lStack_40 = param_1[5];
  }
  rea_std__string__string((string *)local_68,(string *)(param_1 + 1));
  rea_WSConn__recv_pat((WSConn *)*param_1,(string *)local_68,(long long int)(uintptr_t)(local_58));
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == 0x0) {
      iVar4 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
  if (local_48 != 0x0) {
    (*local_48)(local_58,local_58,3);
  }
  if ((void *)*puVar2 != 0x0) {
    rea_operator_delete((void *)*puVar2);
  }
  rea_operator_delete(puVar2);
  return;
}
