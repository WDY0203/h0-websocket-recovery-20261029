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
// IDX 215  0010ef80  FUN_0010ef80
// ------------------------------------------------------------------
undefined8 rea_FUN_0010ef80(long long * param_1, char param_2, undefined8 * param_3)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  long long *plVar4;
  ulong uVar5;
  void *__dest;
  size_t sVar6;
  void *__dest_00;
  undefined8 uVar7;
  size_t sVar8;
  void *__src;
  void *__dest_01;
  uchar *puVar9;
  ulong __n;
  ulong local_4050;
  uchar local_4038 [16392];
  
  if (param_2 != '\0') {
    plVar4 = (long long int*)(uintptr_t)(rea_operator_new(0x18));
    *plVar4 = 0;
    plVar4[1] = 0;
    plVar4[2] = 0;
    local_4038[0] = '\0';
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              ((vector_unsigned_char_std__allocator_unsigned_char *)*param_1,local_4038);
    local_4038[0] = '\0';
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              ((vector_unsigned_char_std__allocator_unsigned_char *)*param_1,local_4038);
    local_4038[0] = 0xff;
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              ((vector_unsigned_char_std__allocator_unsigned_char *)*param_1,local_4038);
    local_4038[0] = 0xff;
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              ((vector_unsigned_char_std__allocator_unsigned_char *)*param_1,local_4038);
    uVar7 = *(undefined8 *)*param_1;
    uVar1 = ((undefined8 *)*param_1)[1];
    *param_3 = uVar7;
    *(int *)(param_3 + 1) = (int)uVar1 - (int)uVar7;
    do {
      while( true ) {
        *(undefined4 *)(param_3 + 4) = 0x4000;
        param_3[3] = (undefined8)(uintptr_t)(local_4038);
        iVar3 = rea_inflate(param_3,0);
        if ((iVar3 + 4U < 7) && ((1L << ((byte)(iVar3 + 4U) & 0x3f) & 0x47U) != 0)) {
          if ((void *)*plVar4 != 0x0) {
            rea_operator_delete((void *)*plVar4);
          }
          rea_operator_delete(plVar4);
          return 0;
        }
        iVar3 = *(int *)(param_3 + 4);
        __dest_01 = (void *)plVar4[1];
        puVar9 = local_4038 + (0x4000 - iVar3);
        if (puVar9 != local_4038) break;
LAB_0010f054:
        if (iVar3 != 0) goto LAB_0010f157;
      }
      __n = (long long)puVar9 - (long long)local_4038;
      if (__n <= (ulong)(plVar4[2] - (long long)__dest_01)) {
        if (__n != 0) {
          rea_memmove(__dest_01,local_4038,__n);
          __dest_01 = (void *)plVar4[1];
          iVar3 = *(int *)(param_3 + 4);
        }
        plVar4[1] = (long long)__dest_01 + __n;
        goto LAB_0010f054;
      }
      __src = (void *)*plVar4;
      sVar8 = (long long)__dest_01 - (long long)__src;
      if (~sVar8 < __n) {
        uVar7 = rea_std____throw_length_error("vector___M_range_insert");
        rea_FUN_00107812((undefined8*)(uintptr_t)(plVar4));
                    /* WARNING: Subroutine does not return */
        rea__Unwind_Resume(uVar7);
      }
      local_4050 = 0xffffffffffffffff;
      uVar5 = __n;
      if (__n <= sVar8) {
        uVar5 = sVar8;
      }
      if ((CARRY8(uVar5,sVar8)) || (local_4050 = uVar5 + sVar8, uVar5 + sVar8 != 0)) {
        __dest = rea_operator_new(local_4050);
        __src = (void *)*plVar4;
        sVar8 = (long long)__dest_01 - (long long)__src;
        __dest_00 = __dest;
        if (sVar8 == 0) goto LAB_0010f10c;
LAB_0010f1d1:
        rea_memmove(__dest,__src,sVar8);
        __dest_00 = (void *)(sVar8 + (long long)__dest);
        if (__n != 0) goto LAB_0010f1f2;
LAB_0010f118:
        sVar8 = plVar4[1] - (long long)__dest_01;
      }
      else {
        __dest = 0x0;
        local_4050 = 0;
        __dest_00 = __dest;
        if (sVar8 != 0) goto LAB_0010f1d1;
LAB_0010f10c:
        __dest = __dest_00;
        if (__n == 0) goto LAB_0010f118;
LAB_0010f1f2:
        __dest_00 = rea_memmove(__dest_00,local_4038,__n);
        sVar8 = plVar4[1] - (long long)__dest_01;
      }
      sVar6 = 0;
      if (sVar8 != 0) {
        rea_memmove((void *)(__n + (long long)__dest_00),__dest_01,sVar8);
        sVar6 = sVar8;
      }
      if ((void *)*plVar4 != 0x0) {
        rea_operator_delete((void *)*plVar4);
      }
      *plVar4 = (long long)__dest;
      iVar3 = *(int *)(param_3 + 4);
      plVar4[1] = (long long)(__n + (long long)__dest_00) + sVar6;
      plVar4[2] = (long long)__dest + local_4050;
    } while (iVar3 == 0);
LAB_0010f157:
    puVar2 = (undefined8 *)*param_1;
    *param_1 = (long long)plVar4;
    if (puVar2 != 0x0) {
      if ((void *)*puVar2 != 0x0) {
        rea_operator_delete((void *)*puVar2);
      }
      rea_operator_delete(puVar2);
    }
  }
  return 1;
}
