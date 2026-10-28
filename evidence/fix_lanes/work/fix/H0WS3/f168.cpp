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
// IDX 168  00108660  FUN_00108660
// ------------------------------------------------------------------
undefined4 * rea_FUN_00108660(double param_1, undefined4 * param_2, EventLoop2 * param_3)
{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  EventLoop2 *pEVar4;
  long long lVar5;
  long long lVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 local_98 [2];
  undefined8 local_90;
  undefined4 local_88 [2];
  long long local_80;
  undefined8 *local_78 [2];
  code *local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  
  if ((param_3 == 0x0) || (*(long long *)(param_3 + 0x68) == 0)) {
    *param_2 = 0xffffffff;
    rea_std__string__string((string *)(param_2 + 2),"",(allocator *)&local_58);
  }
  else {
    local_98[0] = 0xffffffff;
    rea_std__string__string((string *)&local_90,"",(allocator *)&local_58);
    *(long long *)(param_3 + 0xe8) = (long long)(param_1 * _DAT_0011f730);
    uVar8 = rea_current_time();
    *(undefined8 *)(param_3 + 0xe0) = uVar8;
    local_68 = 0x0;
    local_78[0] = (undefined8*)(uintptr_t)(rea_operator_new(0x10));
    *local_78[0] = (undefined8)(uintptr_t)(param_3);
    local_78[0][1] = (undefined8)(uintptr_t)(local_98);
    local_48 = 0x0;
    local_60 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107dc0);
    local_68 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_001079a0);
    rea_FUN_001079a0((long long int*)(uintptr_t)((allocator *)&local_58),(long long int*)(uintptr_t)(local_78),2);
    uVar8 = *(undefined8 *)(param_3 + 200);
    uVar3 = *(undefined8 *)(param_3 + 0xc0);
    local_48 = *(code **)(param_3 + 0xd0);
    *(undefined8 *)(param_3 + 0xc0) = local_58;
    *(undefined8 *)(param_3 + 200) = local_50;
    *(code **)(param_3 + 0xd0) = local_68;
    local_40 = *(undefined8 *)(param_3 + 0xd8);
    *(code **)(param_3 + 0xd8) = local_60;
    local_58 = uVar3;
    local_50 = uVar8;
    if (local_48 != 0x0) {
      (*local_48)((allocator *)&local_58,(allocator *)&local_58,3);
    }
    pEVar4 = *(EventLoop2 **)(param_3 + 0xa8);
    param_3[0xb8] = (EventLoop2)0x1;
    if (pEVar4 != param_3 + 0xa8) {
      uVar2 = *(undefined4 *)(pEVar4 + 0x10);
      lVar5 = *(long long *)(pEVar4 + 0x18);
      *(undefined **)(pEVar4 + 0x18) = PTR__S_empty_rep_storage_00324fa0 + 0x18;
      rea_std____detail___List_node_base___M_unhook();
      lVar6 = *(long long *)(pEVar4 + 0x18);
      if ((allocator *)(lVar6 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(lVar6 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar7 = *(int *)(lVar6 + -8);
          *(int *)(lVar6 + -8) = iVar7 + -1;
        }
        else {
          LOCK();
          iVar7 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar7 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar6 + -0x18));
        }
      }
      rea_operator_delete(pEVar4);
      param_3[0xb8] = (EventLoop2)0x0;
      if (*(long long *)(param_3 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_88[0] = uVar2;
      local_80 = lVar5;
      (**(code **)(param_3 + 0xd8))(param_3 + 0xc0,local_88);
      if ((allocator *)(local_80 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(local_80 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar7 = *(int *)(local_80 + -8);
          *(int *)(local_80 + -8) = iVar7 + -1;
        }
        else {
          LOCK();
          iVar7 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar7 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(local_80 + -0x18));
        }
      }
    }
    if (local_68 != 0x0) {
      (*local_68)(local_78,local_78,3);
    }
    local_48 = 0x0;
    rea_EventLoop2__run(param_3,(long long int)(uintptr_t)((allocator *)&local_58));
    if (local_48 != 0x0) {
      (*local_48)((allocator *)&local_58,(allocator *)&local_58,3);
    }
    *param_2 = local_98[0];
    *(undefined8 *)(param_2 + 2) = local_90;
  }
  return param_2;
}
