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
// IDX 263  00117ac0  std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler________________
// ------------------------------------------------------------------
void rea_std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__dup2(undefined8 * param_1, long long * param_2, long long * param_3, long long * param_4)
{
  long long lVar1;
  long long *plVar2;
  long long *plVar3;
  long long *plVar4;
  long long *plVar5;
  long long *plVar6;
  long long *plVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long long lVar12;
  
  if (param_4 == param_3) {
    return;
  }
  plVar4 = (long long *)param_1[1];
  uVar9 = (long long)param_4 - (long long)param_3 >> 3;
  if (uVar9 <= (ulong)(param_1[2] - (long long)plVar4 >> 3)) {
    uVar10 = (long long)plVar4 - (long long)param_2 >> 3;
    if (uVar10 <= uVar9) {
      plVar2 = param_3 + uVar10;
      plVar7 = plVar4;
      plVar3 = plVar2;
      if (param_4 != plVar2) {
        do {
          if (plVar7 != 0x0) {
            lVar12 = *plVar3;
            *plVar3 = 0;
            *plVar7 = lVar12;
          }
          plVar3 = plVar3 + 1;
          plVar7 = plVar7 + 1;
        } while (param_4 != plVar3);
        plVar7 = (long long *)param_1[1];
      }
      plVar7 = plVar7 + (uVar9 - uVar10);
      param_1[1] = (undefined8)(uintptr_t)(plVar7);
      plVar3 = param_2;
      if (plVar4 != param_2) {
        do {
          if (plVar7 != 0x0) {
            lVar12 = *plVar3;
            *plVar3 = 0;
            *plVar7 = lVar12;
          }
          plVar3 = plVar3 + 1;
          plVar7 = plVar7 + 1;
        } while (plVar4 != plVar3);
        plVar7 = (long long *)param_1[1];
      }
      param_1[1] =(undefined8)(uintptr_t)( plVar7) + uVar10;
      lVar12 = (long long)plVar2 - (long long)param_3 >> 3;
      if (lVar12 < 1) {
        return;
      }
      do {
        lVar1 = *param_3;
        *param_3 = 0;
        plVar4 = (long long *)*param_2;
        *param_2 = lVar1;
        if (plVar4 != 0x0) {
          (**(code **)(*plVar4 + 0x18))();
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      return;
    }
    plVar3 = plVar4 + -uVar9;
    plVar2 = plVar4;
    plVar7 = plVar3;
    if (plVar4 != plVar3) {
      do {
        if (plVar2 != 0x0) {
          lVar12 = *plVar7;
          *plVar7 = 0;
          *plVar2 = lVar12;
        }
        plVar7 = plVar7 + 1;
        plVar2 = plVar2 + 1;
      } while (plVar4 != plVar7);
      plVar2 = (long long *)param_1[1];
    }
    param_1[1] =(undefined8)(uintptr_t)( plVar2) + uVar9;
    lVar12 = (long long)plVar3 - (long long)param_2 >> 3;
    if (0 < lVar12) {
      do {
        plVar3 = plVar3 + -1;
        plVar4 = plVar4 + -1;
        lVar1 = *plVar3;
        *plVar3 = 0;
        plVar2 = (long long *)*plVar4;
        *plVar4 = lVar1;
        if (plVar2 != 0x0) {
          (**(code **)(*plVar2 + 0x18))();
        }
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
    }
    if ((long long)uVar9 < 1) {
      return;
    }
    do {
      lVar12 = *param_3;
      *param_3 = 0;
      plVar4 = (long long *)*param_2;
      *param_2 = lVar12;
      if (plVar4 != 0x0) {
        (**(code **)(*plVar4 + 0x18))();
      }
      param_3 = param_3 + 1;
      param_2 = param_2 + 1;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    return;
  }
  plVar2 = (long long *)*param_1;
  uVar10 = (long long)plVar4 - (long long)plVar2 >> 3;
  if (0x1fffffffffffffff - uVar10 < uVar9) {
    rea_std____throw_length_error("vector___M_range_insert");
    return;
  }
  uVar11 = 0xfffffffffffffff8;
  if (uVar9 <= uVar10) {
    uVar9 = uVar10;
  }
  uVar8 = uVar10 + uVar9;
  if ((!CARRY8(uVar10,uVar9)) && (uVar8 < 0x2000000000000000)) {
    if (uVar8 == 0) {
      uVar11 = 0;
      plVar4 = 0x0;
      goto LAB_00117d22;
    }
    uVar11 = uVar8 * 8;
  }
  plVar4 = (long long int*)(uintptr_t)(rea_operator_new(uVar11));
  plVar2 = (long long *)*param_1;
LAB_00117d22:
  plVar6 = param_3;
  plVar5 = plVar2;
  plVar7 = plVar4;
  plVar3 = plVar4;
  if (plVar2 != param_2) {
    do {
      if (plVar7 != 0x0) {
        lVar12 = *plVar5;
        *plVar5 = 0;
        *plVar7 = lVar12;
      }
      plVar5 = plVar5 + 1;
      plVar7 = plVar7 + 1;
    } while (plVar5 != param_2);
    plVar7 = (long long *)((long long)plVar4 + ((long long)param_2 - (long long)(plVar2 + 1) & 0xfffffffffffffff8U) + 8)
    ;
    plVar3 = plVar7;
  }
  do {
    if (plVar7 != 0x0) {
      lVar12 = *plVar6;
      *plVar6 = 0;
      *plVar7 = lVar12;
    }
    plVar6 = plVar6 + 1;
    plVar7 = plVar7 + 1;
  } while (param_4 != plVar6);
  plVar2 = (long long *)param_1[1];
  plVar3 = (long long *)((long long)plVar3 + ((long long)param_4 - (long long)(param_3 + 1) & 0xfffffffffffffff8U) + 8);
  plVar7 = param_2;
  plVar6 = plVar3;
  if (plVar2 != param_2) {
    do {
      if (plVar6 != 0x0) {
        lVar12 = *plVar7;
        *plVar7 = 0;
        *plVar6 = lVar12;
      }
      plVar7 = plVar7 + 1;
      plVar6 = plVar6 + 1;
    } while (plVar2 != plVar7);
    plVar7 = param_2 + 1;
    param_2 = (long long *)param_1[1];
    plVar3 = (long long *)((long long)plVar3 + ((long long)plVar2 - (long long)plVar7 & 0xfffffffffffffff8U) + 8);
  }
  plVar2 = (long long *)*param_1;
  if (plVar2 != param_2) {
    do {
      if ((long long *)*plVar2 != 0x0) {
        (**(code **)(*(long long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (param_2 != plVar2);
    param_2 = (long long *)*param_1;
  }
  if (param_2 != 0x0) {
    rea_operator_delete(param_2);
  }
  *param_1 = (undefined8)(uintptr_t)(plVar4);
  param_1[1] = (undefined8)(uintptr_t)(plVar3);
  param_1[2] = (long long)plVar4 + uVar11;
  return;
}
