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
// IDX 225  00110e50  FUN_00110e50
// ------------------------------------------------------------------
void rea_FUN_00110e50(long long * param_1)
{
  undefined4 *__src;
  long long *plVar1;
  char cVar2;
  ulong uVar3;
  undefined4 *__dest;
  void *pvVar4;
  size_t sVar5;
  ulong uVar6;
  undefined1 uVar7;
  void *pvVar8;
  long long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  undefined4 local_68 [4];
  undefined8 *local_58 [2];
  code *local_48;
  long long lStack_40;
  
  param_1 = (long long *)*param_1;
  lVar9 = *param_1;
  uVar3 = param_1[1];
  puVar11 = *(undefined8 **)(lVar9 + 0x40);
  plVar1 = *(long long **)(lVar9 + 0x48);
  __dest = (undefined4 *)*puVar11;
  pvVar4 = (void *)plVar1[1];
  local_68[0] = *__dest;
  pvVar8 = (void *)*plVar1;
  uVar10 = (long long)pvVar4 - (long long)pvVar8;
  uVar6 = uVar10 + uVar3;
  if (uVar10 < uVar6) {
    uVar6 = 0;
    if (uVar3 != 0) {
      if ((ulong)(plVar1[2] - (long long)pvVar4) < uVar3) {
        if (~uVar10 < uVar3) {
          rea_std____throw_length_error("vector___M_default_append");
          goto LAB_001111e1;
        }
        uVar6 = uVar3;
        if (uVar3 <= uVar10) {
          uVar6 = uVar10;
        }
        uVar12 = 0xffffffffffffffff;
        if ((CARRY8(uVar6,uVar10)) || (uVar12 = uVar6 + uVar10, uVar6 + uVar10 != 0)) {
          pvVar4 = rea_operator_new(uVar12);
          pvVar8 = (void *)*plVar1;
          sVar5 = plVar1[1] - (long long)pvVar8;
        }
        else {
          uVar12 = 0;
          pvVar4 = 0x0;
          sVar5 = uVar10;
        }
        if (sVar5 != 0) {
          rea_memmove(pvVar4,pvVar8,sVar5);
        }
        pvVar8 = (void *)((long long)pvVar4 + sVar5);
        rea_memset(pvVar8,0,(uVar3 + (long long)pvVar8) - (long long)pvVar8);
        if ((void *)*plVar1 != 0x0) {
          rea_operator_delete((void *)*plVar1);
        }
        lVar9 = *param_1;
        plVar1[1] = uVar3 + (long long)pvVar8;
        *plVar1 = (long long)pvVar4;
        plVar1[2] = uVar12 + (long long)pvVar4;
        uVar3 = param_1[1];
        puVar11 = *(undefined8 **)(lVar9 + 0x40);
        __dest = (undefined4 *)*puVar11;
      }
      else {
        rea_memset(pvVar4,0,uVar3);
        lVar9 = *param_1;
        plVar1[1] = plVar1[1] + uVar3;
        uVar3 = param_1[1];
        puVar11 = *(undefined8 **)(lVar9 + 0x40);
        __dest = (undefined4 *)*puVar11;
      }
      goto LAB_00110ea8;
    }
  }
  else {
    if (uVar6 < uVar10) {
      plVar1[1] = (long long)pvVar8 + uVar6;
      lVar9 = *param_1;
      puVar11 = *(undefined8 **)(lVar9 + 0x40);
      __dest = (undefined4 *)*puVar11;
    }
LAB_00110ea8:
    uVar6 = 0;
    if (uVar3 != 0) {
      uVar3 = 0;
      while( true ) {
        *(byte *)(uVar10 + **(long long **)(lVar9 + 0x48) + uVar3) =
             *(byte *)((long long)__dest + uVar3 + 4) ^
             *(byte *)((long long)local_68 + (ulong)((uint)uVar3 & 3));
        uVar6 = param_1[1];
        uVar3 = uVar3 + 1;
        if (uVar6 <= uVar3) break;
        lVar9 = *param_1;
        __dest = (undefined4 *)**(undefined8 **)(lVar9 + 0x40);
      }
      puVar11 = *(undefined8 **)(*param_1 + 0x40);
      __dest = (undefined4 *)*puVar11;
    }
  }
  __src = (undefined4 *)((long long)__dest + uVar6 + 4);
  if (__src != __dest) {
    lVar9 = 0;
    if ((__src != (undefined4 *)puVar11[1]) && (sVar5 = (long long)puVar11[1] - (long long)__src, sVar5 != 0))
    {
      __dest = (undefined4*)(uintptr_t)(rea_memmove(__dest,__src,sVar5));
      lVar9 = puVar11[1] - (long long)__src;
    }
    puVar11[1] = lVar9 + (long long)__dest;
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
    lVar9 = *param_1;
    uVar7 = 0;
    if (*(char *)(lVar9 + 0x58) != '\0') {
      uVar7 = *(undefined1 *)(lVar9 + 0x59);
    }
    cVar2 = rea_FUN_0010ef80((long long int*)(uintptr_t)(lVar9) + 0x48,uVar7,(undefined8*)(uintptr_t)(*(undefined8 *)(lVar9 + 0x60)));
    if (cVar2 != '\0') {
      if (*(int *)((long long)param_1 + 0x14) == 1) {
        local_58[0] = *(undefined8 **)(*param_1 + 0x48);
        *(undefined8 *)(*param_1 + 0x48) = 0;
        if (param_1[5] == 0) {
LAB_001111e1:
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
      puVar11 = local_58[0];
      if (local_58[0] != 0x0) {
        if ((void *)*local_58[0] != 0x0) {
          rea_operator_delete((void *)*local_58[0]);
        }
        rea_operator_delete(puVar11);
      }
    }
  }
  return;
}
