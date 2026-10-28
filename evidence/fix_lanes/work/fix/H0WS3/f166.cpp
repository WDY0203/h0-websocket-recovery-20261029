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
// IDX 166  00108100  FUN_00108100
// ------------------------------------------------------------------
void rea_FUN_00108100(undefined8 * param_1)
{
  int *piVar1;
  undefined4 uVar2;
  long long lVar3;
  void *pvVar4;
  long long lVar5;
  long long lVar6;
  undefined *puVar7;
  int iVar8;
  _List_node_base *p_Var9;
  undefined *local_50;
  undefined4 local_48 [2];
  long long local_40;
  
  *param_1 = (undefined8)(uintptr_t)((void *)&PTR_FUN_00324730);
  if (*(char *)(param_1 + 1) != '\0') {
    rea_std__string__string((string *)&local_50,"",(allocator *)local_48);
    lVar3 = param_1[2];
    p_Var9 = rea_operator_new(0x20);
    puVar7 = PTR__S_empty_rep_storage_00324fa0;
    if (p_Var9 != 0x0) {
      *(undefined8 *)p_Var9 = 0;
      *(undefined8 *)(p_Var9 + 8) = 0;
      *(undefined4 *)(p_Var9 + 0x10) = 0xffffffff;
      *(undefined **)(p_Var9 + 0x18) = local_50;
      local_50 = puVar7 + 0x18;
    }
    rea_std____detail___List_node_base___M_hook(p_Var9);
    if ((*(char *)(lVar3 + 0xb8) != '\0') &&
       (pvVar4 = *(void **)(lVar3 + 0xa8), (void *)(lVar3 + 0xa8) != pvVar4)) {
      uVar2 = *(undefined4 *)((long long)pvVar4 + 0x10);
      lVar5 = *(long long *)((long long)pvVar4 + 0x18);
      *(undefined **)((long long)pvVar4 + 0x18) = puVar7 + 0x18;
      rea_std____detail___List_node_base___M_unhook();
      lVar6 = *(long long *)((long long)pvVar4 + 0x18);
      if ((allocator *)(lVar6 + -0x18) != (allocator *)puVar7) {
        piVar1 = (int *)(lVar6 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar8 = *(int *)(lVar6 + -8);
          *(int *)(lVar6 + -8) = iVar8 + -1;
        }
        else {
          LOCK();
          iVar8 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar8 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar6 + -0x18));
        }
      }
      rea_operator_delete(pvVar4);
      *(undefined1 *)(lVar3 + 0xb8) = 0;
      if (*(long long *)(lVar3 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_48[0] = uVar2;
      local_40 = lVar5;
      (**(code **)(lVar3 + 0xd8))(lVar3 + 0xc0,(allocator *)local_48);
      if ((allocator *)(local_40 + -0x18) != (allocator *)puVar7) {
        piVar1 = (int *)(local_40 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar8 = *(int *)(local_40 + -8);
          *(int *)(local_40 + -8) = iVar8 + -1;
        }
        else {
          LOCK();
          iVar8 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar8 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(local_40 + -0x18));
        }
      }
    }
    if ((allocator *)(local_50 + -0x18) != (allocator *)puVar7) {
      piVar1 = (int *)(local_50 + -8);
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar8 = *(int *)(local_50 + -8);
        *(int *)(local_50 + -8) = iVar8 + -1;
      }
      else {
        LOCK();
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar8 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_50 + -0x18));
      }
    }
    *(undefined8 *)(param_1[2] + 0x68) = 0;
  }
  *param_1 =(undefined8)(uintptr_t)( PTR_vtable_00324ef0) + 0x10;
  rea_operator_delete(param_1);
  return;
}
