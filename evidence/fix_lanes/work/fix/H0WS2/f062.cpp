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
// IDX 62  00107240  std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_char__std__string________________
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_char__std__string(long long * param_1, undefined1 * param_2, undefined1 * param_3, undefined1 * param_4)
{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  void *__dest;
  undefined1 *puVar4;
  ulong uVar5;
  size_t sVar6;
  long long lVar7;
  size_t sVar8;
  void *__src;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined1 *puVar12;
  ulong uVar13;
  undefined1 *unaff_R14;
  ulong uVar14;
  ulong uStack_48;
  
  if (param_3 == param_4) {
    return;
  }
  puVar12 = (undefined1 *)param_1[1];
  uVar9 = (long long)param_4 - (long long)param_3;
  if (uVar9 <= (ulong)(param_1[2] - (long long)puVar12)) {
    uVar14 = (long long)puVar12 - (long long)param_2;
    if (uVar9 < uVar14) {
      puVar3 = puVar12 + -uVar9;
      puVar4 = puVar12;
      if ((long long)puVar12 - (long long)puVar3 != 0) {
        puVar4 = (undefined1*)(uintptr_t)(rea_memmove(puVar12,puVar3,(long long)puVar12 - (long long)puVar3));
        puVar12 = (undefined1 *)param_1[1];
      }
      sVar8 = (long long)puVar3 - (long long)param_2;
      param_1[1] = (long long)(puVar12 + uVar9);
      if (sVar8 != 0) {
        rea_memmove(puVar4 + -sVar8,param_2,sVar8);
      }
      if ((long long)uVar9 < 1) {
        return;
      }
      if ((param_2 < param_3 + 0x10 && param_3 < param_2 + 0x10) || (uVar9 < 0x10)) {
        uVar14 = 0;
        do {
          param_2[uVar14] = param_3[uVar14];
          uVar14 = uVar14 + 1;
        } while (uVar9 != uVar14);
        return;
      }
      lVar7 = 0;
      uVar10 = 0;
      uVar14 = uVar9 >> 4;
      uVar5 = uVar14 * 0x10;
      do {
        uVar2 = *(undefined8 *)((long long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long long)(param_2 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar14);
      lVar7 = uVar9 + uVar14 * -0x10;
      if (uVar9 == uVar5) {
        return;
      }
    }
    else {
      puVar4 = param_3 + uVar14;
      uVar5 = (long long)param_4 - (long long)puVar4;
      if (0 < (long long)uVar5) {
        if ((puVar12 < puVar4 + 0x10 && puVar4 < puVar12 + 0x10) || (uVar5 < 0x10)) {
          puVar3 = puVar4;
          do {
            uVar1 = *puVar3;
            puVar3 = puVar3 + 1;
            *puVar12 = uVar1;
            puVar12 = puVar12 + 1;
          } while (puVar3 != puVar4 + uVar5);
        }
        else {
          lVar7 = 0;
          uVar13 = 0;
          uVar11 = uVar5 >> 4;
          uVar10 = uVar11 * 0x10;
          do {
            uVar2 = *(undefined8 *)((long long)(puVar4 + lVar7) + 8);
            uVar13 = uVar13 + 1;
            *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(puVar4 + lVar7);
            *(undefined8 *)((long long)(puVar12 + lVar7) + 8) = uVar2;
            lVar7 = lVar7 + 0x10;
          } while (uVar13 < uVar11);
          puVar3 = puVar4 + uVar10;
          puVar12 = puVar12 + uVar10;
          lVar7 = uVar5 + uVar11 * -0x10;
          if (((((uVar5 != uVar10) && (*puVar12 = *puVar3, lVar7 != 1 && -1 < lVar7 + -1)) &&
               (puVar12[1] = puVar3[1], lVar7 != 2)) &&
              (((puVar12[2] = puVar3[2], lVar7 != 3 && (puVar12[3] = puVar3[3], lVar7 != 4)) &&
               ((puVar12[4] = puVar3[4], lVar7 != 5 &&
                ((puVar12[5] = puVar3[5], lVar7 != 6 && (puVar12[6] = puVar3[6], lVar7 != 7))))))))
             && (((puVar12[7] = puVar3[7], lVar7 != 8 &&
                  ((((puVar12[8] = puVar3[8], lVar7 != 9 && (puVar12[9] = puVar3[9], lVar7 != 10))
                    && (puVar12[10] = puVar3[10], lVar7 != 0xb)) &&
                   ((puVar12[0xb] = puVar3[0xb], lVar7 != 0xc &&
                    (puVar12[0xc] = puVar3[0xc], lVar7 != 0xd)))))) &&
                 (puVar12[0xd] = puVar3[0xd], lVar7 != 0xe)))) {
            puVar12[0xe] = puVar3[0xe];
          }
        }
        puVar12 = (undefined1 *)param_1[1];
      }
      puVar12 = puVar12 + (uVar9 - uVar14);
      param_1[1] = (long long)puVar12;
      if (uVar14 != 0) {
        rea_memmove(puVar12,param_2,uVar14);
        puVar12 = (undefined1 *)param_1[1];
      }
      uVar9 = (long long)puVar4 - (long long)param_3;
      param_1[1] = (long long)(puVar12 + uVar14);
      if ((long long)uVar9 < 1) {
        return;
      }
      if ((uVar9 < 0x10) || (param_3 < param_2 + 0x10 && param_2 < param_3 + 0x10)) {
        uVar14 = 0;
        do {
          param_2[uVar14] = param_3[uVar14];
          uVar14 = uVar14 + 1;
        } while (uVar14 != uVar9);
        return;
      }
      lVar7 = 0;
      uVar10 = 0;
      uVar14 = uVar9 >> 4;
      uVar5 = uVar14 * 0x10;
      do {
        uVar2 = *(undefined8 *)((long long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long long)(param_2 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar14);
      lVar7 = uVar9 + uVar14 * -0x10;
      if (uVar9 == uVar5) {
        return;
      }
    }
    param_2 = param_2 + uVar5;
    param_3 = param_3 + uVar5;
    *param_2 = *param_3;
    if ((((lVar7 != 1 && -1 < lVar7 + -1) && (param_2[1] = param_3[1], lVar7 != 2)) &&
        (param_2[2] = param_3[2], lVar7 != 3)) &&
       (((((param_2[3] = param_3[3], lVar7 != 4 && (param_2[4] = param_3[4], lVar7 != 5)) &&
          ((param_2[5] = param_3[5], lVar7 != 6 &&
           ((param_2[6] = param_3[6], lVar7 != 7 && (param_2[7] = param_3[7], lVar7 != 8)))))) &&
         (param_2[8] = param_3[8], lVar7 != 9)) &&
        ((((param_2[9] = param_3[9], lVar7 != 10 && (param_2[10] = param_3[10], lVar7 != 0xb)) &&
          (param_2[0xb] = param_3[0xb], lVar7 != 0xc)) &&
         ((param_2[0xc] = param_3[0xc], lVar7 != 0xd && (param_2[0xd] = param_3[0xd], lVar7 != 0xe))
         )))))) {
      param_2[0xe] = param_3[0xe];
      return;
    }
    return;
  }
  __src = (void *)*param_1;
  uVar14 = (long long)puVar12 - (long long)__src;
  if (~uVar14 < uVar9) {
    rea_std____throw_length_error("vector___M_range_insert");
    uStack_48 = uVar14;
  }
  else {
    uVar5 = uVar9;
    if (uVar9 <= uVar14) {
      uVar5 = uVar14;
    }
    uStack_48 = 0xffffffffffffffff;
    unaff_R14 = param_3;
    if ((!CARRY8(uVar14,uVar5)) && (uStack_48 = uVar14 + uVar5, uVar14 + uVar5 == 0)) {
      uStack_48 = 0;
      __dest = 0x0;
      goto LAB_0010d326;
    }
  }
  __dest = rea_operator_new(uStack_48);
  __src = (void *)*param_1;
LAB_0010d326:
  sVar6 = (long long)param_2 - (long long)__src;
  sVar8 = 0;
  if (sVar6 != 0) {
    rea_memmove(__dest,__src,sVar6);
    sVar8 = sVar6;
  }
  puVar12 = (undefined1 *)(sVar8 + (long long)__dest);
  if (0 < (long long)uVar9) {
    if ((param_3 < puVar12 + 0x10 && puVar12 < param_3 + 0x10) || (uVar9 < 0x10)) {
      puVar4 = puVar12;
      do {
        uVar1 = *unaff_R14;
        unaff_R14 = unaff_R14 + 1;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      } while (unaff_R14 != param_3 + uVar9);
    }
    else {
      lVar7 = 0;
      uVar10 = 0;
      uVar5 = uVar9 >> 4;
      uVar14 = uVar5 * 0x10;
      do {
        uVar2 = *(undefined8 *)((long long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long long)(puVar12 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar5);
      param_3 = param_3 + uVar14;
      puVar4 = puVar12 + uVar14;
      lVar7 = uVar9 + uVar5 * -0x10;
      if ((((((uVar9 != uVar14) && (*puVar4 = *param_3, 0 < lVar7 + -1)) &&
            (puVar4[1] = param_3[1], lVar7 != 2)) &&
           ((puVar4[2] = param_3[2], lVar7 != 3 && (puVar4[3] = param_3[3], lVar7 != 4)))) &&
          (puVar4[4] = param_3[4], lVar7 != 5)) &&
         ((((puVar4[5] = param_3[5], lVar7 != 6 && (puVar4[6] = param_3[6], lVar7 != 7)) &&
           ((puVar4[7] = param_3[7], lVar7 != 8 &&
            (((puVar4[8] = param_3[8], lVar7 != 9 && (puVar4[9] = param_3[9], lVar7 != 10)) &&
             (puVar4[10] = param_3[10], lVar7 != 0xb)))))) &&
          (((puVar4[0xb] = param_3[0xb], lVar7 != 0xc && (puVar4[0xc] = param_3[0xc], lVar7 != 0xd))
           && (puVar4[0xd] = param_3[0xd], lVar7 != 0xe)))))) {
        puVar4[0xe] = param_3[0xe];
      }
    }
    puVar12 = puVar12 + uVar9;
  }
  sVar6 = param_1[1] - (long long)param_2;
  sVar8 = 0;
  if (sVar6 != 0) {
    puVar12 = (undefined1*)(uintptr_t)(rea_memmove(puVar12,param_2,sVar6));
    sVar8 = sVar6;
  }
  if ((void *)*param_1 != 0x0) {
    rea_operator_delete((void *)*param_1);
  }
  *param_1 = (long long)__dest;
  param_1[1] = (long long)(puVar12 + sVar8);
  param_1[2] = (long long)__dest + uStack_48;
  return;
}
