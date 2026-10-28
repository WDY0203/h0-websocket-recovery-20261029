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
// IDX 226  00111200  FUN_00111200
// ------------------------------------------------------------------
void rea_FUN_00111200(long long * param_1)
{
  undefined8 *puVar1;
  char cVar2;
  long long lVar3;
  ulong uVar4;
  void *__dest;
  void *pvVar5;
  long long lVar6;
  size_t sVar7;
  void *pvVar8;
  undefined1 uVar9;
  void *pvVar10;
  ulong __n;
  long long *plVar11;
  size_t __n_00;
  ulong local_68;
  undefined8 *local_58 [2];
  code *local_48;
  long long lStack_40;
  
  param_1 = (long long *)*param_1;
  lVar6 = *param_1;
  lVar3 = param_1[1];
  plVar11 = *(long long **)(lVar6 + 0x48);
  pvVar8 = (void *)**(undefined8 **)(lVar6 + 0x40);
  pvVar5 = (void *)plVar11[1];
  if (pvVar8 != (void *)((long long)pvVar8 + lVar3)) {
    __n = ((long long)pvVar8 + lVar3) - (long long)pvVar8;
    if ((ulong)(plVar11[2] - (long long)pvVar5) < __n) {
      pvVar10 = (void *)*plVar11;
      sVar7 = (long long)pvVar5 - (long long)pvVar10;
      if (~sVar7 < __n) {
        rea_std____throw_length_error("vector___M_range_insert");
        goto LAB_00111527;
      }
      local_68 = 0xffffffffffffffff;
      uVar4 = sVar7;
      if (sVar7 <= __n) {
        uVar4 = __n;
      }
      if ((CARRY8(uVar4,sVar7)) || (local_68 = uVar4 + sVar7, uVar4 + sVar7 != 0)) {
        __dest = rea_operator_new(local_68);
        pvVar10 = (void *)*plVar11;
        sVar7 = (long long)pvVar5 - (long long)pvVar10;
      }
      else {
        local_68 = 0;
        __dest = 0x0;
      }
      if (sVar7 != 0) {
        rea_memmove(__dest,pvVar10,sVar7);
      }
      pvVar10 = (void *)(sVar7 + (long long)__dest);
      if (__n != 0) {
        pvVar10 = rea_memmove(pvVar10,pvVar8,__n);
      }
      __n_00 = plVar11[1] - (long long)pvVar5;
      sVar7 = 0;
      if (__n_00 != 0) {
        rea_memmove((void *)(__n + (long long)pvVar10),pvVar5,__n_00);
        sVar7 = __n_00;
      }
      if ((void *)*plVar11 != 0x0) {
        rea_operator_delete((void *)*plVar11);
      }
      *plVar11 = (long long)__dest;
      lVar6 = *param_1;
      plVar11[1] = (long long)(__n + (long long)pvVar10) + sVar7;
      plVar11[2] = (long long)__dest + local_68;
      plVar11 = *(long long **)(lVar6 + 0x40);
      pvVar5 = (void *)*plVar11;
      pvVar8 = (void *)((long long)pvVar5 + param_1[1]);
    }
    else {
      if (__n != 0) {
        rea_memmove(pvVar5,pvVar8,__n);
        pvVar5 = (void *)plVar11[1];
        lVar3 = param_1[1];
        lVar6 = *param_1;
      }
      plVar11[1] = (long long)pvVar5 + __n;
      plVar11 = *(long long **)(lVar6 + 0x40);
      pvVar5 = (void *)*plVar11;
      pvVar8 = (void *)((long long)pvVar5 + lVar3);
    }
    if (pvVar8 != pvVar5) {
      lVar6 = 0;
      if ((pvVar8 != (void *)plVar11[1]) && (sVar7 = plVar11[1] - (long long)pvVar8, sVar7 != 0)) {
        pvVar5 = rea_memmove(pvVar5,pvVar8,sVar7);
        lVar6 = plVar11[1] - (long long)pvVar8;
      }
      plVar11[1] = (long long)pvVar5 + lVar6;
    }
  }
  if ((char)param_1[2] == '\0') {
    local_48 = 0x0;
    if ((code *)param_1[5] != 0x0) {
      (*(code *)param_1[5])(local_58,param_1 + 3,2);
      local_48 = (code *)param_1[5];
      lStack_40 = param_1[6];
    }
    rea_WSConn__read_head((WSConn *)*param_1,(long long int)(uintptr_t)(local_58));
    if (local_48 != 0x0) {
      (*local_48)(local_58,local_58,3);
      return;
    }
  }
  else {
    lVar6 = *param_1;
    uVar9 = 0;
    if (*(char *)(lVar6 + 0x58) != '\0') {
      uVar9 = *(undefined1 *)(lVar6 + 0x59);
    }
    cVar2 = rea_FUN_0010ef80((long long int*)(uintptr_t)(lVar6) + 0x48,uVar9,(undefined8*)(uintptr_t)(*(undefined8 *)(lVar6 + 0x60)));
    if (cVar2 != '\0') {
      if (*(int *)((long long)param_1 + 0x14) == 1) {
        local_58[0] = *(undefined8 **)(*param_1 + 0x48);
        *(undefined8 *)(*param_1 + 0x48) = 0;
        if (param_1[5] == 0) {
LAB_00111527:
                    /* WARNING: Subroutine does not return */
          rea_std____throw_bad_function_call();
        }
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      else {
        if (*(int *)((long long)param_1 + 0x14) != 8) {
          return;
        }
        if (param_1[5] == 0) {
                    /* WARNING: Subroutine does not return */
          rea_std____throw_bad_function_call();
        }
        local_58[0] = 0x0;
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      puVar1 = local_58[0];
      if (local_58[0] != 0x0) {
        if ((void *)*local_58[0] != 0x0) {
          rea_operator_delete((void *)*local_58[0]);
        }
        rea_operator_delete(puVar1);
      }
    }
  }
  return;
}
