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
// IDX 175  00109bb0  FUN_00109bb0
// ------------------------------------------------------------------
undefined8 rea_FUN_00109bb0(undefined8 param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4, undefined8 param_5, undefined8 param_6)
{
  int *piVar1;
  long long lVar2;
  int iVar3;
  char *pcVar4;
  EventLoop2 *pEVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  ulong uVar8;
  char local_208 [16];
  undefined2 local_1f8;
  undefined1 local_1f6;
  undefined1 local_1e8;
  undefined1 local_1e7;
  undefined1 local_1e6;
  undefined8 local_1d8 [2];
  long long local_1c8 [2];
  long long local_1b8 [2];
  undefined8 *local_1a8 [2];
  undefined8 *local_198 [2];
  code *local_188;
  code *local_180;
  undefined1 local_178[0x98];
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  (*(code **)((uint8_t *)&local_178 + 0x0)) = 0x0;
  local_f0 = 0;
  rea_sigemptyset(&local_170);
  rea_sigaction(2,(sigaction *)&local_178,&local_d8);
  local_1f8 = 0x4f4f;
  local_1e6 = 0;
  local_1e8 = 0x4f;
  local_1e7 = 0x4f;
  local_1f6 = 0;
  uVar8 = (ulong)local_198[0] >> 0x10;
  local_198[0] = (undefined8 *)CONCAT62((uint6)uVar8 & 0xffffffffff00,0x4f4f);
  iVar3 = rea_PyArg_ParseTuple(param_2,(allocator *)local_198,local_1d8,local_1c8);
  if (iVar3 == 0) {
    uVar7 = 0;
  }
  else {
    if ((*(byte *)(*(long long *)(local_1c8[0] + 8) + 0xab) & 8) == 0) {
      pcVar4 = (char *)rea_PyUnicode_AsUTF8();
      rea_std__string__string((string *)local_1b8,pcVar4,(allocator *)local_198);
    }
    else {
      uVar8 = rea_PyBytes_Size();
      pcVar4 = (char *)rea_PyBytes_AsString(local_1c8[0]);
      rea_std__string__string((string *)local_1b8,pcVar4,uVar8,(allocator *)local_198);
    }
    pEVar5 = (EventLoop2 *)rea_PyLong_AsVoidPtr(local_1d8[0]);
    if ((pEVar5 == 0x0) || (*(long long *)(pEVar5 + 0x68) == 0)) {
      uVar7 = 1;
    }
    else {
      local_208[0] = '\0';
      puVar6 = (undefined8*)(uintptr_t)(rea_operator_new(0x18));
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      uVar7 = 0;
      lVar2 = *(long long *)(local_1b8[0] + -0x18);
      if (-1 < *(int *)(local_1b8[0] + -8)) {
        rea_std__string___M_leak_hard();
        uVar7 = puVar6[1];
      }
      std__vector_unsigned_char_std__allocator_unsigned_char__________M_range_insert___gnu_cxx____normal_iterator_char__std__string_________________(puVar6,uVar7,local_1b8[0],local_1b8[0] + lVar2,param_5,param_6,0);
      local_188 = 0x0;
      local_198[0] = (undefined8*)(uintptr_t)(rea_operator_new(0x10));
      *local_198[0] = (undefined8)(uintptr_t)(pEVar5);
      local_198[0][1] = (undefined8)(uintptr_t)(local_208);
      local_180 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107960);
      local_188 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107a30);
      local_1a8[0] = puVar6;
      rea_WSConn__send(*(WSConn **)(pEVar5 + 0x68),(long long int*)(uintptr_t)(local_1a8),(long long int)(uintptr_t)((allocator *)local_198));
      puVar6 = local_1a8[0];
      if (local_1a8[0] != 0x0) {
        if ((void *)*local_1a8[0] != 0x0) {
          rea_operator_delete((void *)*local_1a8[0]);
        }
        rea_operator_delete(puVar6);
      }
      if (local_188 != 0x0) {
        (*local_188)((allocator *)local_198,(allocator *)local_198,3);
      }
      while (local_208[0] == '\0') {
        while( true ) {
          local_188 = 0x0;
          rea_EventLoop2__run(pEVar5,(long long int)(uintptr_t)((allocator *)local_198));
          if (local_188 == 0x0) break;
          (*local_188)((allocator *)local_198,(allocator *)local_198,3);
          if (local_208[0] != '\0') goto LAB_00109def;
        }
      }
LAB_00109def:
      uVar7 = 0;
    }
    if ((allocator *)(local_1b8[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_1b8[0] + -8);
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar3 = *(int *)(local_1b8[0] + -8);
        *(int *)(local_1b8[0] + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_1b8[0] + -0x18));
      }
    }
    uVar7 = rea_Py_BuildValue("l",uVar7);
  }
  rea_sigaction(2,&local_d8,0x0);
  return uVar7;
}
