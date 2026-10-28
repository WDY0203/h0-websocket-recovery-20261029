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
// IDX 261  00117670  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler___________
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler__dup2(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr, unique_ptr * param_1)
{
  undefined8 uVar1;
  long long lVar2;
  ulong uVar3;
  long long *plVar4;
  undefined8 *puVar5;
  long long *plVar6;
  long long *plVar7;
  long long *plVar8;
  long long *plVar9;
  long long *plVar10;
  ulong uVar11;
  long long *plVar12;
  
  uVar11 = 8;
  uVar3 = *(long long *)(this_ptr + 8) - *(long long *)this_ptr >> 3;
  if (uVar3 != 0) {
    if ((uVar3 * 2 < uVar3) || (0x1fffffffffffffff < uVar3 * 2)) {
      uVar11 = 0xfffffffffffffff8;
    }
    else {
      uVar11 = uVar3 << 4;
    }
  }
  plVar4 = (long long int*)(uintptr_t)(rea_operator_new(uVar11));
  plVar9 = *(long long **)(this_ptr + 8);
  plVar8 = *(long long **)this_ptr;
  plVar12 = plVar4 + 1;
  puVar5 = (undefined8 *)(((long long)plVar9 - (long long)plVar8 & 0xfffffffffffffff8U) + (long long)plVar4);
  if (puVar5 != 0x0) {
    uVar1 = *(undefined8 *)param_1;
    *(undefined8 *)param_1 = 0;
    plVar9 = *(long long **)(this_ptr + 8);
    plVar8 = *(long long **)this_ptr;
    *puVar5 = uVar1;
  }
  plVar6 = plVar4;
  plVar7 = plVar8;
  plVar10 = plVar9;
  if (plVar9 != plVar8) {
    do {
      if (plVar6 != 0x0) {
        lVar2 = *plVar7;
        *plVar7 = 0;
        *plVar6 = lVar2;
      }
      plVar7 = plVar7 + 1;
      plVar6 = plVar6 + 1;
    } while (plVar7 != plVar9);
    plVar10 = *(long long **)(this_ptr + 8);
    plVar6 = *(long long **)this_ptr;
    plVar12 = (long long *)((long long)plVar4 +
                      ((long long)plVar9 - (long long)(plVar8 + 1) & 0xfffffffffffffff8U) + 0x10);
    if (plVar10 != plVar6) {
      do {
        if ((long long *)*plVar6 != 0x0) {
          (**(code **)(*(long long *)*plVar6 + 0x18))();
        }
        *plVar6 = 0;
        plVar6 = plVar6 + 1;
      } while (plVar10 != plVar6);
      plVar10 = *(long long **)this_ptr;
    }
  }
  if (plVar10 != 0x0) {
    rea_operator_delete(plVar10);
  }
  *(long long **)this_ptr = plVar4;
  *(long long **)(this_ptr + 8) = plVar12;
  *(ulong *)(this_ptr + 0x10) = (long long)plVar4 + uVar11;
  return;
}
