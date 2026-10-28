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
// IDX 232  00112b60  FUN_00112b60
// ------------------------------------------------------------------
void rea_FUN_00112b60(long long * param_1, int param_2)
{
  uintptr_t unique0x00008e00;
  uintptr_t unique0x00023d00;
  uintptr_t unique0x10001b0b;
  uintptr_t unique0x10001b2b;
  uintptr_t unique0x10001b33;
  uintptr_t unique0x10001b3b;
  uintptr_t unique0x10001b43;

  undefined8 stack0xfffffffffffffec8;
  undefined8 stack0xfffffffffffffecc;
  undefined8 stack0xfffffffffffffed0;
  _Rb_tree_node_base *p_Var1;
  ulong uVar2;
  int *piVar3;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var4;
  uint *puVar5;
  char cVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  long long *plVar16;
  char *pcVar17;
  undefined8 *puVar18;
  void *pvVar19;
  long long lVar20;
  _Rb_tree_node_base *p_Var21;
  _Rb_tree_node_base *p_Var22;
  sbyte sVar23;
  long long lVar24;
  _Rb_tree_node_base *p_Var25;
  ulong uVar26;
  uint *puVar27;
  size_t __n;
  char *pcVar28;
  ulong uVar29;
  _Rb_tree_node_base *p_Var30;
  int iVar31;
  char *pcVar32;
  char cVar33;
  uint uVar34;
  long long lVar35;
  _Rb_tree_node_base *p_Var36;
  uint *puVar37;
  bool bVar38;
  byte bVar39;
  undefined1 auVar40 [16];
  int local_218 [4];
  undefined *local_208 [2];
  undefined8 local_1f8;
  undefined8 local_1f0;
  code *local_1e8;
  undefined8 local_1e0;
  char local_1d8 [48];
  string local_1a8;
  byte bStack_1a7;
  byte bStack_1a6;
  byte bStack_1a5;
  undefined4 uStack_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  int local_194;
  code *local_190;
  long long local_188;
  undefined1 local_154;
  undefined1 local_153;
  undefined1 local_152;
  undefined1 local_151;
  undefined1 local_150;
  undefined1 local_14f;
  undefined1 local_14e;
  undefined1 local_14d;
  int local_14c;
  int local_148;
  int local_144;
  undefined1 auStack_13b [8];
  undefined1 auStack_133 [8];
  undefined1 auStack_12b [3];
  undefined1 local_128 [8];
  undefined1 auStack_120 [8];
  undefined8 local_118;
  
  bVar39 = 0;
  param_1 = (long long *)*param_1;
  pvVar15 = (void *)**(undefined8 **)(*param_1 + 0x40);
  iVar12 = (int)(*(undefined8 **)(*param_1 + 0x40))[1] - (int)(uintptr_t)pvVar15;
  pvVar15 = rea_memmem(pvVar15,(long long)iVar12,(void*)(uintptr_t)("Sec-WebSocket-Key: "),0x13);
  if (pvVar15 != 0x0) {
    lVar24 = 0;
    do {
      cVar33 = *(char *)((long long)pvVar15 + lVar24 + 0x13);
      if (((cVar33 == '\r') || (cVar33 == '\n')) || (iVar31 = (int)lVar24, iVar12 + -0x13 <= iVar31)
         ) goto LAB_00112bdb;
      auStack_13b[lVar24 + 3] = cVar33;
      lVar24 = lVar24 + 1;
    } while (lVar24 != 0x7f);
    lVar24 = (long long)(iVar31 + 1);
LAB_00112bdb:
    auStack_13b[lVar24 + 3] = 0;
    if (auStack_13b[3] != '\0') {
      puVar5 = (uint *)(auStack_13b + 3);
      puVar37 = puVar5;
      do {
        puVar27 = puVar37;
        uVar13 = *puVar27 + 0xfefefeff & ~*puVar27;
        uVar14 = uVar13 & 0x80808080;
        puVar37 = puVar27 + 1;
      } while (uVar14 == 0);
      local_194 = 0;
      bVar38 = (uVar13 & 0x8080) == 0;
      local_190 = (code *)((ulong)local_190 & 0xffffffff00000000);
      if (bVar38) {
        uVar14 = uVar14 >> 0x10;
      }
      local_14c = 0;
      local_1a8 = (string)0x1;
      bStack_1a7 = 0x23;
      bStack_1a6 = 0x45;
      bStack_1a5 = 0x67;
      uStack_1a4 = 0xefcdab89;
      if (bVar38) {
        puVar37 = (uint *)((long long)puVar27 + 6);
      }
      local_1a0 = 0x98badcfe;
      local_19c = 0x10325476;
      local_198 = 0xc3d2e1f0;
      lVar24 = (long long)puVar37 + ((-3 - (ulong)CARRY1((byte)uVar14,(byte)uVar14)) - (long long)puVar5);
      local_148 = 0;
      local_144 = 0;
      *(undefined8 *)((long long)puVar5 + lVar24) = 0x3541464145383532;
      *(undefined4 *)(auStack_120 + lVar24 + 8) = 0x31314235;
      *(undefined8 *)(auStack_133 + lVar24 + 3) = 0x37342d343139452d;
      *(undefined1 *)((long long)&local_118 + lVar24 + 4) = 0;
      *(undefined8 *)(auStack_12b + lVar24 + 3) = 0x2d414335392d4144;
      *(undefined8 *)(local_128 + lVar24 + 8) = 0x3843443042413543;
      if ((int)lVar24 == -0x24) {
LAB_001135da:
        iVar31 = local_14c;
        iVar12 = local_14c + 1;
        lVar24 = (long long)local_14c;
        local_14c = iVar12;
        *(undefined1 *)((long long)&local_190 + lVar24 + 4) = 0x80;
        if (iVar31 < 0x38) {
          if (iVar12 != 0x38) {
            rea_memset((void *)((long long)&local_190 + lVar24 + 5),0,(ulong)(0x37 - iVar31));
            local_14c = 0x38;
          }
        }
        else {
          if (iVar12 < 0x40) {
            rea_memset((void *)((long long)&local_190 + lVar24 + 5),0,(ulong)(0x3f - iVar31));
            local_14c = 0x40;
          }
          rea_FUN_0010d620((uint*)(uintptr_t)(&local_1a8));
          if (local_14c < 0x38) {
            rea_memset((void *)((long long)&local_190 + (long long)local_14c + 4),0,(ulong)(0x38 - local_14c));
            local_14c = 0x38;
          }
        }
        local_151 = SUB81(local_190,0);
        local_154 = (undefined1)((ulong)local_190 >> 0x18);
        local_153 = (undefined1)((ulong)local_190 >> 0x10);
        local_152 = (undefined1)((ulong)local_190 >> 8);
        local_14d = (undefined1)local_194;
        local_150 = (undefined1)((uint)local_194 >> 0x18);
        local_14f = (undefined1)((uint)local_194 >> 0x10);
        local_14e = (undefined1)((uint)local_194 >> 8);
        rea_FUN_0010d620((uint*)(uintptr_t)(&local_1a8));
LAB_001136c1:
        uVar14 = (uint)bStack_1a5;
        (*(arr_undefined1_3 *)((uint8_t *)&local_1f8 + 0x0)) = CONCAT12(bStack_1a7,CONCAT11(bStack_1a6,bStack_1a5));
        local_1f8 = CONCAT17((char)uStack_1a4,
                             CONCAT16((char)((uint)uStack_1a4 >> 8),
                                      CONCAT15((char)((uint)uStack_1a4 >> 0x10),
                                               CONCAT14((char)((uint)uStack_1a4 >> 0x18),
                                                        CONCAT13(local_1a8,(undefined3)local_1f8))))
                            );
        (*(arr_undefined1_3 *)((uint8_t *)&local_1f0 + 0x0)) =
             CONCAT12((char)((uint)local_1a0 >> 8),
                      CONCAT11((char)((uint)local_1a0 >> 0x10),(char)((uint)local_1a0 >> 0x18)));
        local_1f0 = CONCAT17((char)local_19c,
                             CONCAT16((char)((uint)local_19c >> 8),
                                      CONCAT15((char)((uint)local_19c >> 0x10),
                                               CONCAT14((char)((uint)local_19c >> 0x18),
                                                        CONCAT13((char)local_1a0,
                                                                 (undefined3)local_1f0)))));
        local_1e8 = (code *)CONCAT53(CONCAT41((*(undefined4 *)((uint8_t *)&local_1e8 + 0x4)),(char)local_198),
                                     CONCAT12((char)((uint)local_198 >> 8),
                                              CONCAT11((char)((uint)local_198 >> 0x10),
                                                       (char)((uint)local_198 >> 0x18))));
      }
      else {
        local_194 = 0;
        lVar35 = 0;
        puVar37 = puVar5;
        while( true ) {
          iVar12 = (int)lVar35 + 1;
          local_14c = iVar12;
          *(char *)((long long)&local_190 + lVar35 + 4) = (char)*puVar37;
          local_194 = local_194 + 8;
          if (local_194 == 0) {
            iVar31 = (int)(uintptr_t)local_190 + 1;
            local_190 = (code *)CONCAT44((*(undefined4 *)((uint8_t *)&local_190 + 0x4)),iVar31);
            if (iVar31 == 0) {
              local_144 = 1;
            }
          }
          if (iVar12 == 0x40) {
            rea_FUN_0010d620((uint*)(uintptr_t)(&local_1a8));
          }
          if (puVar37 == (uint *)((ulong)((int)lVar24 + 0x23) + (long long)puVar5)) break;
          if (local_144 != 0) goto LAB_00113799;
          puVar37 = (uint *)((long long)puVar37 + 1);
          lVar35 = (long long)local_14c;
        }
        if (local_144 == 0) {
          if (local_148 == 0) goto LAB_001135da;
          goto LAB_001136c1;
        }
LAB_00113799:
        local_1f8 = 0;
        local_1f0 = 0;
        uVar14 = 0;
        local_1e8 = (code *)((ulong)(*(undefined4 *)((uint8_t *)&local_1e8 + 0x4)) << 0x20);
      }
      pcVar17 = local_1d8;
      iVar12 = 0;
      do {
        local_1a8 = (string)0x0;
        bStack_1a7 = 0;
        bStack_1a6 = 0;
        bStack_1a5 = 0;
        if (iVar12 + 1 == 0x14) {
          iVar31 = 0x14;
          sVar23 = 0x10;
          iVar12 = 1;
        }
        else {
          iVar31 = iVar12 + 2;
          uVar14 = (uint)*(byte *)((long long)&local_1f8 + (long long)(iVar12 + 1)) | uVar14 << 8;
          if (iVar31 < 0x14) {
            lVar24 = (long long)iVar31;
            iVar31 = iVar12 + 3;
            iVar12 = 3;
            uVar14 = uVar14 << 8 | (uint)*(byte *)((long long)&local_1f8 + lVar24);
            sVar23 = 0;
          }
          else {
            iVar12 = 2;
            sVar23 = 8;
          }
        }
        uVar14 = uVar14 << sVar23;
        local_1a8 = (string)((byte)((int)uVar14 >> 0x12) & 0x3f);
        *pcVar17 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                   [(char)local_1a8];
        bStack_1a7 = (byte)((int)uVar14 >> 0xc) & 0x3f;
        pcVar17[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                     [(char)bStack_1a7];
        if (iVar12 == 1) {
          pcVar17[2] = '=';
LAB_001138ad:
          uVar14 = 0x40;
        }
        else {
          bStack_1a6 = (byte)((int)uVar14 >> 6) & 0x3f;
          pcVar17[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                       [(char)bStack_1a6];
          if (iVar12 != 3) goto LAB_001138ad;
          uVar14 = uVar14 & 0x3f;
        }
        pcVar17[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                     [(int)uVar14];
        if (0x13 < iVar31) goto LAB_001138c0;
        uVar14 = (uint)*(byte *)((long long)&local_1f8 + (long long)iVar31);
        pcVar17 = pcVar17 + 4;
        iVar12 = iVar31;
      } while( true );
    }
  }
  local_1d8[0] = '\0';
LAB_00112bf9:
  puVar11 = PTR__S_empty_rep_storage_00324fa0;
  puVar18 = *(undefined8 **)(*param_1 + 0x40);
  pcVar17 = (char *)*puVar18;
  uVar26 = puVar18[1] - (long long)pcVar17;
  bVar38 = uVar26 == 5;
  if (5 < uVar26) {
    lVar24 = 5;
    pcVar28 = pcVar17;
    pcVar32 = "GET /";
    do {
      if (lVar24 == 0) break;
      lVar24 = lVar24 + -1;
      bVar38 = *pcVar28 == *pcVar32;
      pcVar28 = pcVar28 + (ulong)bVar39 * -2 + 1;
      pcVar32 = pcVar32 + (ulong)bVar39 * -2 + 1;
    } while (bVar38);
    if ((bVar38) && (pcVar17[5] != '/')) {
      local_208[0] = PTR__S_empty_rep_storage_00324fa0 + 0x18;
      if ((5 < (int)uVar26) &&
         (((cVar33 = pcVar17[5], cVar33 != ' ' && (cVar33 != '\r')) && (cVar33 != '\n')))) {
        uVar29 = 0;
        while( true ) {
          lVar24 = *(long long *)(local_208[0] + -0x18);
          uVar2 = lVar24 + 1;
          if ((*(ulong *)(local_208[0] + -0x10) < uVar2) || (0 < *(int *)(local_208[0] + -8))) {
            rea_std__string__reserve((ulong)local_208);
            lVar24 = *(long long *)(local_208[0] + -0x18);
          }
          local_208[0][lVar24] = cVar33;
          if (local_208[0] + -0x18 != puVar11) {
            *(undefined4 *)(local_208[0] + -8) = 0;
            *(ulong *)(local_208[0] + -0x18) = uVar2;
            local_208[0][uVar2] = 0;
          }
          if (uVar29 == (int)uVar26 - 6) goto LAB_00112e83;
          cVar6 = *(char *)(**(long long **)(*param_1 + 0x40) + 6 + uVar29);
          if ((cVar6 == '.') && (cVar33 == '.')) break;
          if (((cVar6 == '\r') || (cVar6 == ' ')) ||
             (uVar29 = uVar29 + 1, cVar33 = cVar6, cVar6 == '\n')) goto LAB_00112e83;
        }
        rea_std__string__assign((char *)local_208,0x11f6d0);
      }
LAB_00112e83:
      pcVar17 = (char*)(uintptr_t)(rea_operator_new(0x18));
      pcVar17[0] = '\0';
      pcVar17[1] = '\0';
      pcVar17[2] = '\0';
      pcVar17[3] = '\0';
      pcVar17[4] = '\0';
      pcVar17[5] = '\0';
      pcVar17[6] = '\0';
      pcVar17[7] = '\0';
      pcVar17[8] = '\0';
      pcVar17[9] = '\0';
      pcVar17[10] = '\0';
      pcVar17[0xb] = '\0';
      pcVar17[0xc] = '\0';
      pcVar17[0xd] = '\0';
      pcVar17[0xe] = '\0';
      pcVar17[0xf] = '\0';
      pcVar17[0x10] = '\0';
      pcVar17[0x11] = '\0';
      pcVar17[0x12] = '\0';
      pcVar17[0x13] = '\0';
      pcVar17[0x14] = '\0';
      pcVar17[0x15] = '\0';
      pcVar17[0x16] = '\0';
      pcVar17[0x17] = '\0';
      rea_Buffer__appendf(pcVar17,"HTTP/1.0 200 OK\r\n\r\n");
      rea_std__string__string(&local_1a8,(string *)local_208);
      local_190 = 0x0;
      if ((code *)param_1[7] != 0x0) {
        (*(code *)param_1[7])(&local_1a0,param_1 + 5,2);
        local_188 = param_1[8];
        local_190 = (code *)param_1[7];
      }
      lVar24 = *(long long *)(*param_1 + 0x38);
      if (*(char *)(lVar24 + 0x5a) != '\0') {
        rea_fwrite((void*)(uintptr_t)("send(): send_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
        rea_print_stack();
      }
      puVar18 = *(undefined8 **)(lVar24 + 0x60);
      *(undefined1 *)(lVar24 + 0x5a) = 1;
      *(char **)(lVar24 + 0x60) = pcVar17;
      if (puVar18 != 0x0) {
        if ((void *)*puVar18 != 0x0) {
          rea_operator_delete((void *)*puVar18);
        }
        rea_operator_delete(puVar18);
      }
      rea_std__string__string((string *)(auStack_13b + 3),&local_1a8);
      memset(auStack_120, 0, sizeof(auStack_120));
      if (local_190 != 0x0) {
        (*local_190)(auStack_133 + 3,&local_1a0,2);
        local_118 = local_188;
        { auto &&__rea_tmp = ((arr_undefined1_8)local_190); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
      }
      local_1e8 = 0x0;
      puVar18 = (undefined8*)(uintptr_t)(rea_operator_new(0x28));
      *puVar18 = stack0xfffffffffffffec8;
      unique0x00008e00 =(uintptr_t)(uintptr_t)( puVar11) + 0x18;
      puVar18[3] = 0;
      if ((*(undefined8 *)(auStack_120) != 0)) {
        (*(code *)auStack_120)(puVar18 + 1,auStack_133 + 3,2);
        puVar18[4] = local_118;
        puVar18[3] = (undefined8)(uintptr_t)(auStack_120);
      }
      local_1f8 = *(undefined8 *)(lVar24 + 0x68);
      uVar7 = *(undefined8 *)(lVar24 + 0x70);
      local_1e8 = *(code **)(lVar24 + 0x78);
      *(undefined8 *)(lVar24 + 0x70) = local_1f0;
      *(undefined8 **)(lVar24 + 0x68) = puVar18;
      local_1e0 = *(undefined8 *)(lVar24 + 0x80);
      *(code **)(lVar24 + 0x78) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010e040);
      *(code **)(lVar24 + 0x80) = (uint64_t (*)(...))(uintptr_t)(rea_FUN_0010dda0);
      local_1f0 = uVar7;
      if (local_1e8 != 0x0) {
        (*local_1e8)(&local_1f8,&local_1f8,3);
      }
      if ((*(undefined8 *)(auStack_120) != 0)) {
        (*(code *)auStack_120)(auStack_133 + 3,auStack_133 + 3,3);
      }
      if ((allocator *)(stack0xfffffffffffffec8 + -0x18) != (allocator *)puVar11) {
        piVar3 = (int *)(stack0xfffffffffffffec8 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar12 = *(int *)(stack0xfffffffffffffec8 + -8);
          *(int *)(stack0xfffffffffffffec8 + -8) = iVar12 + -1;
        }
        else {
          LOCK();
          iVar12 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar12 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(stack0xfffffffffffffec8 + -0x18));
        }
      }
      cVar33 = *(char *)(lVar24 + 0x5a);
      local_218[0] = *(int *)(lVar24 + 0x40);
      lVar24 = *(long long *)(lVar24 + 0x38);
      p_Var36 = *(_Rb_tree_node_base **)(lVar24 + 0x18);
      p_Var21 = (_Rb_tree_node_base *)(lVar24 + 0x10);
      p_Var22 = p_Var36;
      p_Var30 = p_Var21;
      if (p_Var36 == 0x0) {
LAB_00113e70:
        lVar35 = 0;
        uVar14 = 0;
      }
      else {
        do {
          while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < local_218[0]) {
            p_Var1 = p_Var25 + 0x18;
            p_Var22 = *(_Rb_tree_node_base **)p_Var1;
            p_Var25 = p_Var30;
            if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_001130f2;
          }
          p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
          p_Var30 = p_Var25;
        } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_001130f2:
        if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, local_218[0] < *(int *)(p_Var25 + 0x20)))
        goto LAB_00113e70;
        do {
          while (p_Var30 = p_Var36, *(int *)(p_Var30 + 0x20) < local_218[0]) {
            p_Var25 = p_Var30 + 0x18;
            p_Var36 = *(_Rb_tree_node_base **)p_Var25;
            p_Var30 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == 0x0) goto LAB_0011312a;
          }
          p_Var36 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
          p_Var22 = p_Var30;
        } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != 0x0);
LAB_0011312a:
        if ((p_Var21 == p_Var30) || (local_218[0] < *(int *)(p_Var30 + 0x20))) {
          p_Var36 = rea_operator_new(0x28);
          if (p_Var36 != 0x0) {
            *(undefined4 *)p_Var36 = 0;
            *(undefined8 *)(p_Var36 + 8) = 0;
            *(undefined8 *)(p_Var36 + 0x10) = 0;
            *(undefined8 *)(p_Var36 + 0x18) = 0;
            *(undefined4 *)(p_Var36 + 0x24) = 0;
            *(int *)(p_Var36 + 0x20) = local_218[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos_______________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                *)(lVar24 + 8),p_Var30,p_Var36 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
          p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
          p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
          if (p_Var22 == 0x0) {
            rea_operator_delete(p_Var36);
          }
          else {
            bVar38 = true;
            if ((p_Var30 == 0x0) && (p_Var21 != p_Var22)) {
              bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var22 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var22,p_Var21);
            *(long long *)(lVar24 + 0x30) = *(long long *)(lVar24 + 0x30) + 1;
            p_Var30 = p_Var36;
          }
        }
        uVar14 = *(uint *)(p_Var30 + 0x24);
        lVar35 = 1;
      }
      lVar24 = lVar24 + (lVar35 + 1) * 0x30;
      p_Var4 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                *)(lVar24 + 8);
      p_Var21 = *(_Rb_tree_node_base **)(lVar24 + 0x18);
      p_Var30 = (_Rb_tree_node_base *)(lVar24 + 0x10);
      p_Var36 = p_Var21;
      p_Var22 = p_Var30;
      uVar13 = uVar14;
      if (p_Var21 != 0x0) {
        do {
          while (p_Var25 = p_Var36, *(int *)(p_Var25 + 0x20) < local_218[0]) {
            p_Var1 = p_Var25 + 0x18;
            p_Var36 = *(_Rb_tree_node_base **)p_Var1;
            p_Var25 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00113212;
          }
          p_Var36 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
          p_Var22 = p_Var25;
        } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_00113212:
        if ((p_Var30 != p_Var25) && (p_Var36 = p_Var30, *(int *)(p_Var25 + 0x20) <= local_218[0])) {
          do {
            while (p_Var22 = p_Var21, *(int *)(p_Var22 + 0x20) < local_218[0]) {
              p_Var25 = p_Var22 + 0x18;
              p_Var21 = *(_Rb_tree_node_base **)p_Var25;
              p_Var22 = p_Var36;
              if (*(_Rb_tree_node_base **)p_Var25 == 0x0) goto LAB_0011324a;
            }
            p_Var21 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
            p_Var36 = p_Var22;
          } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != 0x0);
LAB_0011324a:
          if ((p_Var30 == p_Var22) || (local_218[0] < *(int *)(p_Var22 + 0x20))) {
            p_Var21 = rea_operator_new(0x28);
            if (p_Var21 != 0x0) {
              *(undefined4 *)p_Var21 = 0;
              *(undefined8 *)(p_Var21 + 8) = 0;
              *(undefined8 *)(p_Var21 + 0x10) = 0;
              *(undefined8 *)(p_Var21 + 0x18) = 0;
              *(undefined4 *)(p_Var21 + 0x24) = 0;
              *(int *)(p_Var21 + 0x20) = local_218[0];
            }
            { auto &&__rea_tmp = (std__________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________________M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
            p_Var36 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
            p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
            if (p_Var36 == 0x0) {
              rea_operator_delete(p_Var21);
            }
            else {
              bVar38 = true;
              if ((p_Var22 == 0x0) && (p_Var30 != p_Var36)) {
                bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var36 + 0x20);
              }
              rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var36,p_Var30);
              *(long long *)(lVar24 + 0x30) = *(long long *)(lVar24 + 0x30) + 1;
              p_Var22 = p_Var21;
            }
          }
          uVar13 = *(uint *)(p_Var22 + 0x24);
        }
      }
      uVar34 = uVar13 | 2;
      if (cVar33 == '\0') {
        uVar34 = uVar13 & 0xfffffffd;
      }
      if (uVar14 == uVar34) {
        std____________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___________erase(p_Var4,local_218);
        goto LAB_001133cf;
      }
      p_Var21 = *(_Rb_tree_node_base **)(lVar24 + 0x18);
      p_Var22 = p_Var30;
      p_Var36 = p_Var30;
      if (*(_Rb_tree_node_base **)(lVar24 + 0x18) == 0x0) {
LAB_00113339:
        p_Var21 = rea_operator_new(0x28);
        if (p_Var21 != 0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(int *)(p_Var21 + 0x20) = local_218[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var4,p_Var36,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
        p_Var36 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
        if (p_Var22 == 0x0) {
          rea_operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var36 == 0x0) && (p_Var30 != p_Var22)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var22 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var22,p_Var30);
          *(long long *)(lVar24 + 0x30) = *(long long *)(lVar24 + 0x30) + 1;
          p_Var36 = p_Var21;
        }
      }
      else {
        do {
          while (p_Var36 = p_Var21, *(int *)(p_Var36 + 0x20) < local_218[0]) {
            p_Var25 = p_Var36 + 0x18;
            p_Var21 = *(_Rb_tree_node_base **)p_Var25;
            p_Var36 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == 0x0) goto LAB_0011332a;
          }
          p_Var21 = *(_Rb_tree_node_base **)(p_Var36 + 0x10);
          p_Var22 = p_Var36;
        } while (*(_Rb_tree_node_base **)(p_Var36 + 0x10) != 0x0);
LAB_0011332a:
        if ((p_Var30 == p_Var36) || (local_218[0] < *(int *)(p_Var36 + 0x20))) goto LAB_00113339;
      }
      *(uint *)(p_Var36 + 0x24) = uVar34;
LAB_001133cf:
      if (local_190 != 0x0) {
        (*local_190)(&local_1a0,&local_1a0,3);
      }
      lVar24 = CONCAT44(uStack_1a4,
                        CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8))));
      if ((allocator *)(lVar24 + -0x18) != (allocator *)puVar11) {
        piVar3 = (int *)(lVar24 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar12 = *(int *)(lVar24 + -8);
          *(int *)(lVar24 + -8) = iVar12 + -1;
        }
        else {
          LOCK();
          iVar12 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar12 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar24 + -0x18));
        }
      }
      if ((allocator *)(local_208[0] + -0x18) == (allocator *)puVar11) {
        return;
      }
      piVar3 = (int *)(local_208[0] + -8);
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar12 = *(int *)(local_208[0] + -8);
        *(int *)(local_208[0] + -8) = iVar12 + -1;
      }
      else {
        LOCK();
        iVar12 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
      }
      if (0 < iVar12) {
        return;
      }
      rea_std__string___Rep___M_destroy((allocator *)(local_208[0] + -0x18));
      return;
    }
  }
  lVar24 = *(long long *)(*param_1 + 0x38);
  if (*(char *)(lVar24 + 0x88) != '\0') {
    rea_fwrite((void*)(uintptr_t)("recv(): recv_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar24 + 0x88) = 1;
  memset(local_128, 0, sizeof(local_128));
  plVar16 = (long long int*)(uintptr_t)(rea_operator_new(8));
  *plVar16 = lVar24;
  puVar11 = PTR__M_manager_00324f68;
  unique0x00023d00 =(uintptr_t)(uintptr_t)( *(undefined **)(lVar24 + 0x90));
  uVar7 = *(undefined8 *)(lVar24 + 0x98);
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0xa0)); memcpy(local_128, &__rea_tmp, sizeof(local_128)); }
  *(long long **)(lVar24 + 0x90) = plVar16;
  *(undefined8 *)(lVar24 + 0x98) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0xa0) = puVar11;
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0xa8)); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
  *(undefined **)(lVar24 + 0xa8) = PTR__M_invoke_00324f40;
  unique0x10001b43 = uVar7;
  if ((*(undefined8 *)(local_128) != 0)) {
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  lVar35 = *(long long *)(lVar24 + 0x38);
  iVar12 = *(int *)(lVar24 + 0x40);
  cVar33 = *(char *)(lVar24 + 0x88);
  p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  local_1f8 = CONCAT44((*(undefined4 *)((uint8_t *)&local_1f8 + 0x4)),iVar12);
  p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  p_Var22 = p_Var36;
  p_Var30 = p_Var21;
  if (p_Var36 == 0x0) {
LAB_00114751:
    lVar20 = 0;
    uVar14 = 0;
  }
  else {
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00112d2b;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_00112d2b:
    if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, iVar12 < *(int *)(p_Var25 + 0x20)))
    goto LAB_00114751;
    do {
      if (*(int *)(p_Var36 + 0x20) < iVar12) {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x18);
      }
      else {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x10);
        p_Var22 = p_Var36;
      }
      p_Var36 = p_Var30;
    } while (p_Var30 != 0x0);
    if ((p_Var21 == p_Var22) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
      p_Var36 = rea_operator_new(0x28);
      if (p_Var36 != 0x0) {
        *(undefined4 *)p_Var36 = 0;
        *(undefined8 *)(p_Var36 + 8) = 0;
        *(undefined8 *)(p_Var36 + 0x10) = 0;
        *(undefined8 *)(p_Var36 + 0x18) = 0;
        *(undefined4 *)(p_Var36 + 0x24) = 0;
        *(int *)(p_Var36 + 0x20) = (int)local_1f8;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar35 + 8),p_Var22,p_Var36 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
      p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
      p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
      if (p_Var30 == 0x0) {
        rea_operator_delete(p_Var36);
      }
      else {
        bVar38 = true;
        if ((p_Var22 == 0x0) && (p_Var21 != p_Var30)) {
          bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var30,p_Var21);
        *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
        p_Var22 = p_Var36;
      }
    }
    uVar14 = *(uint *)(p_Var22 + 0x24);
    lVar20 = 1;
  }
  lVar35 = lVar35 + (lVar20 + 1) * 0x30;
  p_Var4 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar35 + 8);
  p_Var21 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  p_Var36 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  uVar13 = uVar14;
  if (p_Var21 != 0x0) {
    p_Var22 = p_Var21;
    p_Var30 = p_Var36;
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < (int)local_1f8) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_0011402b;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_0011402b:
    if ((p_Var36 != p_Var25) && (p_Var22 = p_Var36, *(int *)(p_Var25 + 0x20) <= (int)local_1f8)) {
      do {
        if (*(int *)(p_Var21 + 0x20) < (int)local_1f8) {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x18);
        }
        else {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
          p_Var22 = p_Var21;
        }
        p_Var21 = p_Var30;
      } while (p_Var30 != 0x0);
      if ((p_Var36 == p_Var22) || ((int)local_1f8 < *(int *)(p_Var22 + 0x20))) {
        p_Var21 = rea_operator_new(0x28);
        if (p_Var21 != 0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(int *)(p_Var21 + 0x20) = (int)local_1f8;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
        p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
        if (p_Var30 == 0x0) {
          rea_operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var22 == 0x0) && (p_Var36 != p_Var30)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var30 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var30,p_Var36);
          *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
          p_Var22 = p_Var21;
        }
      }
      uVar13 = *(uint *)(p_Var22 + 0x24);
    }
  }
  uVar34 = uVar13 | 1;
  if (cVar33 == '\0') {
    uVar34 = uVar13 & 0xfffffffe;
  }
  if (uVar14 == uVar34) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var4,(int *)&local_1f8);
  }
  else {
    p_Var21 = p_Var36;
    if (*(_Rb_tree_node_base **)(lVar35 + 0x18) == 0x0) {
LAB_0011434f:
      p_Var22 = rea_operator_new(0x28);
      if (p_Var22 != 0x0) {
        *(undefined4 *)p_Var22 = 0;
        *(undefined8 *)(p_Var22 + 8) = 0;
        *(undefined8 *)(p_Var22 + 0x10) = 0;
        *(undefined8 *)(p_Var22 + 0x18) = 0;
        *(undefined4 *)(p_Var22 + 0x24) = 0;
        *(int *)(p_Var22 + 0x20) = (int)local_1f8;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
      p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
      p_Var21 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
      if (p_Var30 == 0x0) {
        rea_operator_delete(p_Var22);
      }
      else {
        bVar38 = true;
        if ((p_Var21 == 0x0) && (p_Var36 != p_Var30)) {
          bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
        *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
        p_Var21 = p_Var22;
      }
    }
    else {
      p_Var22 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
      do {
        if (*(int *)(p_Var22 + 0x20) < (int)local_1f8) {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x18);
        }
        else {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
          p_Var21 = p_Var22;
        }
        p_Var22 = p_Var30;
      } while (p_Var30 != 0x0);
      if ((p_Var36 == p_Var21) || ((int)local_1f8 < *(int *)(p_Var21 + 0x20))) goto LAB_0011434f;
    }
    *(uint *)(p_Var21 + 0x24) = uVar34;
  }
  if (*(char *)(lVar24 + 0x5a) != '\0') {
    rea_fwrite((void*)(uintptr_t)("close(): send_flag != false\n"),1,0x1c,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar18 = *(undefined8 **)(lVar24 + 0x60);
  *(undefined1 *)(lVar24 + 0x5a) = 1;
  *(undefined8 *)(lVar24 + 0x60) = 0;
  if (puVar18 != 0x0) {
    if ((void *)*puVar18 != 0x0) {
      rea_operator_delete((void *)*puVar18);
    }
    rea_operator_delete(puVar18);
  }
  memset(local_128, 0, sizeof(local_128));
  pvVar15 = rea_operator_new(1);
  puVar11 = PTR__M_manager_00324f78;
  unique0x00023d00 =(uintptr_t)(uintptr_t)( *(undefined **)(lVar24 + 0x68));
  uVar7 = *(undefined8 *)(lVar24 + 0x70);
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0x78)); memcpy(local_128, &__rea_tmp, sizeof(local_128)); }
  *(void **)(lVar24 + 0x68) = pvVar15;
  *(undefined8 *)(lVar24 + 0x70) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0x78) = puVar11;
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0x80)); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
  *(undefined **)(lVar24 + 0x80) = PTR__M_invoke_00324fe8;
  unique0x10001b3b = uVar7;
  if ((*(undefined8 *)(local_128) != 0)) {
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  lVar35 = *(long long *)(lVar24 + 0x38);
  iVar12 = *(int *)(lVar24 + 0x40);
  cVar33 = *(char *)(lVar24 + 0x5a);
  p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  local_1a8 = SUB41(iVar12,0);
  bStack_1a7 = (byte)((uint)iVar12 >> 8);
  bStack_1a6 = (byte)((uint)iVar12 >> 0x10);
  bStack_1a5 = (byte)((uint)iVar12 >> 0x18);
  p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  p_Var22 = p_Var36;
  p_Var30 = p_Var21;
  if (p_Var36 == 0x0) {
LAB_00114747:
    lVar20 = 0;
    uVar14 = 0;
  }
  else {
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00114313;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_00114313:
    if ((p_Var25 == p_Var21) || (p_Var22 = p_Var21, iVar12 < *(int *)(p_Var25 + 0x20)))
    goto LAB_00114747;
    do {
      if (*(int *)(p_Var36 + 0x20) < iVar12) {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x18);
      }
      else {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x10);
        p_Var22 = p_Var36;
      }
      p_Var36 = p_Var30;
    } while (p_Var30 != 0x0);
    if ((p_Var22 == p_Var21) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
      p_Var36 = rea_operator_new(0x28);
      if (p_Var36 != 0x0) {
        *(undefined4 *)p_Var36 = 0;
        *(undefined8 *)(p_Var36 + 8) = 0;
        *(undefined8 *)(p_Var36 + 0x10) = 0;
        *(undefined8 *)(p_Var36 + 0x18) = 0;
        *(undefined4 *)(p_Var36 + 0x24) = 0;
        *(uint *)(p_Var36 + 0x20) =
             CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar35 + 8),p_Var22,p_Var36 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
      p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
      p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
      if (p_Var30 == 0x0) {
        rea_operator_delete(p_Var36);
      }
      else {
        bVar38 = true;
        if ((p_Var22 == 0x0) && (p_Var21 != p_Var30)) {
          bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var30,p_Var21);
        *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
        p_Var22 = p_Var36;
      }
    }
    uVar14 = *(uint *)(p_Var22 + 0x24);
    lVar20 = 1;
  }
  lVar35 = lVar35 + (lVar20 + 1) * 0x30;
  p_Var4 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar35 + 8);
  p_Var21 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  p_Var36 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  uVar13 = uVar14;
  if (p_Var21 != 0x0) {
    iVar12 = CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    p_Var22 = p_Var21;
    p_Var30 = p_Var36;
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00114443;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_00114443:
    if ((p_Var25 != p_Var36) && (p_Var22 = p_Var36, *(int *)(p_Var25 + 0x20) <= iVar12)) {
      do {
        if (*(int *)(p_Var21 + 0x20) < iVar12) {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x18);
        }
        else {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
          p_Var22 = p_Var21;
        }
        p_Var21 = p_Var30;
      } while (p_Var30 != 0x0);
      if ((p_Var22 == p_Var36) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
        p_Var21 = rea_operator_new(0x28);
        if (p_Var21 != 0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(uint *)(p_Var21 + 0x20) =
               CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
        p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
        if (p_Var30 == 0x0) {
          rea_operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var22 == 0x0) && (p_Var36 != p_Var30)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var30 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var30,p_Var36);
          *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
          p_Var22 = p_Var21;
        }
      }
      uVar13 = *(uint *)(p_Var22 + 0x24);
    }
  }
  uVar34 = uVar13 | 2;
  if (cVar33 == '\0') {
    uVar34 = uVar13 & 0xfffffffd;
  }
  if (uVar14 == uVar34) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var4,(int *)&local_1a8);
    goto LAB_0011460d;
  }
  p_Var21 = p_Var36;
  if (*(_Rb_tree_node_base **)(lVar35 + 0x18) == 0x0) {
LAB_001146c4:
    p_Var22 = rea_operator_new(0x28);
    if (p_Var22 != 0x0) {
      *(undefined4 *)p_Var22 = 0;
      *(undefined8 *)(p_Var22 + 8) = 0;
      *(undefined8 *)(p_Var22 + 0x10) = 0;
      *(undefined8 *)(p_Var22 + 0x18) = 0;
      *(undefined4 *)(p_Var22 + 0x24) = 0;
      *(uint *)(p_Var22 + 0x20) =
           CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
    p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
    p_Var21 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
    if (p_Var30 == 0x0) {
      rea_operator_delete(p_Var22);
    }
    else {
      bVar38 = true;
      if ((p_Var21 == 0x0) && (p_Var36 != p_Var30)) {
        bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
      *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
      p_Var21 = p_Var22;
    }
  }
  else {
    iVar12 = CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    p_Var22 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
    do {
      if (*(int *)(p_Var22 + 0x20) < iVar12) {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x18);
      }
      else {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
        p_Var21 = p_Var22;
      }
      p_Var22 = p_Var30;
    } while (p_Var30 != 0x0);
    if ((p_Var21 == p_Var36) || (iVar12 < *(int *)(p_Var21 + 0x20))) goto LAB_001146c4;
  }
  *(uint *)(p_Var21 + 0x24) = uVar34;
LAB_0011460d:
  memset(local_128, 0, sizeof(local_128));
  pvVar15 = rea_operator_new(1);
  puVar11 = PTR__M_manager_00324f58;
  unique0x00023d00 =(uintptr_t)(uintptr_t)( *(undefined **)(lVar24 + 0xb0));
  uVar7 = *(undefined8 *)(lVar24 + 0xb8);
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0xc0)); memcpy(local_128, &__rea_tmp, sizeof(local_128)); }
  *(void **)(lVar24 + 0xb0) = pvVar15;
  *(undefined8 *)(lVar24 + 0xb8) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0xc0) = puVar11;
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 200)); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
  *(undefined **)(lVar24 + 200) = PTR__M_invoke_00324eb0;
  if ((*(undefined8 *)(local_128) != 0)) {
    unique0x10001b2b = uVar7;
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  return;
LAB_001138c0:
  pcVar17[4] = '\0';
  if (local_1d8[0] != '\0') {
    lVar24 = *param_1;
    puVar18 = *(undefined8 **)(lVar24 + 0x40);
    pvVar15 = (void *)*puVar18;
    pvVar19 = rea_memmem(pvVar15,puVar18[1] - (long long)pvVar15,(void*)(uintptr_t)("permessage-deflate"),0x12);
    if (pvVar19 != 0x0) {
      *(undefined1 *)(lVar24 + 0x58) = 1;
      pvVar15 = rea_operator_new(0x70);
      *(void **)(lVar24 + 0x60) = pvVar15;
      lVar24 = *param_1;
      pvVar15 = rea_operator_new(0x70);
      *(void **)(lVar24 + 0x68) = pvVar15;
      puVar18 = *(undefined8 **)(*param_1 + 0x60);
      puVar8 = *(undefined8 **)(*param_1 + 0x68);
      puVar18[8] = 0;
      puVar18[9] = 0;
      puVar18[10] = 0;
      *(undefined4 *)(puVar18 + 1) = 0;
      *puVar18 = 0;
      iVar12 = inflateInit2_(puVar18,0xfffffff1,"1.2.7",0x70);
      if (iVar12 == 0) {
        puVar8[8] = 0;
        puVar8[9] = 0;
        puVar8[10] = 0;
        *(undefined4 *)(puVar8 + 1) = 0;
        *puVar8 = 0;
        iVar12 = deflateInit2_(puVar8,0xffffffff,8,0xfffffff1,8,0,"1.2.7",0x70);
        if (iVar12 != 0) {
          rea_inflateEnd(puVar18);
          goto LAB_0011397b;
        }
      }
      else {
LAB_0011397b:
        lVar24 = *param_1;
        *(undefined1 *)(lVar24 + 0x58) = 0;
        rea_operator_delete(*(void **)(lVar24 + 0x60));
        rea_operator_delete(*(void **)(*param_1 + 0x68));
      }
      puVar18 = *(undefined8 **)(*param_1 + 0x40);
      pvVar15 = (void *)*puVar18;
    }
    pvVar19 = (void *)((long long)(param_2 + 4) + (long long)pvVar15);
    if (pvVar19 != pvVar15) {
      lVar24 = 0;
      if ((pvVar19 != (void *)puVar18[1]) && (__n = (long long)puVar18[1] - (long long)pvVar19, __n != 0)) {
        pvVar15 = rea_memmove(pvVar15,pvVar19,__n);
        lVar24 = puVar18[1] - (long long)pvVar19;
      }
      puVar18[1] = lVar24 + (long long)pvVar15;
    }
    pcVar17 = (char*)(uintptr_t)(rea_operator_new(0x18));
    pcVar17[0] = '\0';
    pcVar17[1] = '\0';
    pcVar17[2] = '\0';
    pcVar17[3] = '\0';
    pcVar17[4] = '\0';
    pcVar17[5] = '\0';
    pcVar17[6] = '\0';
    pcVar17[7] = '\0';
    pcVar17[8] = '\0';
    pcVar17[9] = '\0';
    pcVar17[10] = '\0';
    pcVar17[0xb] = '\0';
    pcVar17[0xc] = '\0';
    pcVar17[0xd] = '\0';
    pcVar17[0xe] = '\0';
    pcVar17[0xf] = '\0';
    pcVar17[0x10] = '\0';
    pcVar17[0x11] = '\0';
    pcVar17[0x12] = '\0';
    pcVar17[0x13] = '\0';
    pcVar17[0x14] = '\0';
    pcVar17[0x15] = '\0';
    pcVar17[0x16] = '\0';
    pcVar17[0x17] = '\0';
    pcVar28 = "Sec-WebSocket-Extensions: permessage-deflate\r\n";
    if (*(char *)(*param_1 + 0x58) == '\0') {
      pcVar28 = "";
    }
    rea_Buffer__appendf(pcVar17,
                    "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n%sSec-WebSocket-Accept: %s\r\n\r\n"
                    ,pcVar28,local_1d8);
    lVar24 = *(long long *)(*param_1 + 0x38);
    if (*(char *)(lVar24 + 0x5a) != '\0') {
      rea_fwrite((void*)(uintptr_t)("send(): send_flag != false\n"),1,0x1b,*(FILE **)PTR_stderr_00324fb0);
      rea_print_stack();
    }
    puVar18 = *(undefined8 **)(lVar24 + 0x60);
    *(undefined1 *)(lVar24 + 0x5a) = 1;
    *(char **)(lVar24 + 0x60) = pcVar17;
    if (puVar18 != 0x0) {
      if ((void *)*puVar18 != 0x0) {
        rea_operator_delete((void *)*puVar18);
      }
      rea_operator_delete(puVar18);
    }
    memset(local_128, 0, sizeof(local_128));
    if ((code *)param_1[3] == 0x0) {
      lVar35 = 0;
    }
    else {
      (*(code *)param_1[3])(puVar5,param_1 + 1,2);
      { auto &&__rea_tmp = ((arr_undefined1_8)param_1[4]); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
      lVar35 = param_1[3];
    }
    uVar7 = *(undefined8 *)(lVar24 + 0x68);
    uVar9 = *(undefined8 *)(lVar24 + 0x70);
    { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0x78)); memcpy(local_128, &__rea_tmp, sizeof(local_128)); }
    *(undefined **)(lVar24 + 0x68) = (undefined*)(uintptr_t)(stack0xfffffffffffffec8);
    *(undefined8 *)(lVar24 + 0x70) = stack0xfffffffffffffed0;
    uVar10 = *(undefined8 *)(lVar24 + 0x80);
    *(long long *)(lVar24 + 0x78) = lVar35;
    *(undefined8 *)(lVar24 + 0x80) = *(undefined8 *)(auStack_120);
    unique0x10001b0b = (uintptr_t)(uintptr_t)((undefined *)uVar7);
    unique0x10001b33 = uVar9;
    { auto &&__rea_tmp = ((arr_undefined1_8)uVar10); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
    if ((*(undefined8 *)(local_128) != 0)) {
      (*(code *)local_128)(puVar5,puVar5,3);
    }
    lVar35 = *(long long *)(lVar24 + 0x38);
    iVar12 = *(int *)(lVar24 + 0x40);
    cVar33 = *(char *)(lVar24 + 0x5a);
    p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
    stack0xfffffffffffffec8 = (undefined8)(uintptr_t)((undefined *)CONCAT44(stack0xfffffffffffffecc,iVar12));
    p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
    p_Var22 = p_Var36;
    p_Var30 = p_Var21;
    if (p_Var36 == 0x0) {
LAB_00113e40:
      lVar24 = 0;
      uVar14 = 0;
    }
    else {
      do {
        while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
          p_Var1 = p_Var25 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var1;
          p_Var25 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00113b4b;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
        p_Var30 = p_Var25;
      } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_00113b4b:
      if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, iVar12 < *(int *)(p_Var25 + 0x20)))
      goto LAB_00113e40;
      do {
        while (p_Var30 = p_Var36, *(int *)(p_Var30 + 0x20) < iVar12) {
          p_Var25 = p_Var30 + 0x18;
          p_Var36 = *(_Rb_tree_node_base **)p_Var25;
          p_Var30 = p_Var22;
          if (*(_Rb_tree_node_base **)p_Var25 == 0x0) goto LAB_00113b83;
        }
        p_Var36 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
        p_Var22 = p_Var30;
      } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != 0x0);
LAB_00113b83:
      if ((p_Var21 == p_Var30) || (iVar12 < *(int *)(p_Var30 + 0x20))) {
        p_Var36 = rea_operator_new(0x28);
        if (p_Var36 != 0x0) {
          *(undefined4 *)p_Var36 = 0;
          *(undefined8 *)(p_Var36 + 8) = 0;
          *(undefined8 *)(p_Var36 + 0x10) = 0;
          *(undefined8 *)(p_Var36 + 0x18) = 0;
          *(undefined4 *)(p_Var36 + 0x24) = 0;
          *(undefined4 *)(p_Var36 + 0x20) = (*(undefined4 *)((uint8_t *)&auStack_13b + 0x3));
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar35 + 8),p_Var30,p_Var36 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
        p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
        if (p_Var22 == 0x0) {
          rea_operator_delete(p_Var36);
        }
        else {
          bVar38 = true;
          if ((p_Var30 == 0x0) && (p_Var21 != p_Var22)) {
            bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var22 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var22,p_Var21);
          *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
          p_Var30 = p_Var36;
        }
      }
      uVar14 = *(uint *)(p_Var30 + 0x24);
      lVar24 = 1;
    }
    lVar35 = lVar35 + (lVar24 + 1) * 0x30;
    p_Var4 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar35 + 8);
    p_Var21 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
    p_Var36 = (_Rb_tree_node_base *)(lVar35 + 0x10);
    uVar13 = uVar14;
    if (p_Var21 != 0x0) {
      p_Var22 = p_Var21;
      p_Var30 = p_Var36;
      do {
        while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))) {
          p_Var1 = p_Var25 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var1;
          p_Var25 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var1 == 0x0) goto LAB_00113c6b;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
        p_Var30 = p_Var25;
      } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != 0x0);
LAB_00113c6b:
      if ((p_Var36 != p_Var25) &&
         (p_Var22 = p_Var36, *(int *)(p_Var25 + 0x20) <= (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3)))) {
        do {
          while (p_Var30 = p_Var21, *(int *)(p_Var30 + 0x20) < (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))) {
            p_Var25 = p_Var30 + 0x18;
            p_Var21 = *(_Rb_tree_node_base **)p_Var25;
            p_Var30 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == 0x0) goto LAB_00113ca3;
          }
          p_Var21 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
          p_Var22 = p_Var30;
        } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != 0x0);
LAB_00113ca3:
        if ((p_Var36 == p_Var30) || ((int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3)) < *(int *)(p_Var30 + 0x20))) {
          p_Var21 = rea_operator_new(0x28);
          if (p_Var21 != 0x0) {
            *(undefined4 *)p_Var21 = 0;
            *(undefined8 *)(p_Var21 + 8) = 0;
            *(undefined8 *)(p_Var21 + 0x10) = 0;
            *(undefined8 *)(p_Var21 + 0x18) = 0;
            *(undefined4 *)(p_Var21 + 0x24) = 0;
            *(undefined4 *)(p_Var21 + 0x20) = (*(undefined4 *)((uint8_t *)&auStack_13b + 0x3));
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var4,p_Var30,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
          p_Var22 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
          p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
          if (p_Var22 == 0x0) {
            rea_operator_delete(p_Var21);
          }
          else {
            bVar38 = true;
            if ((p_Var30 == 0x0) && (p_Var36 != p_Var22)) {
              bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var22 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var22,p_Var36);
            *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
            p_Var30 = p_Var21;
          }
        }
        uVar13 = *(uint *)(p_Var30 + 0x24);
      }
    }
    uVar34 = uVar13 | 2;
    if (cVar33 == '\0') {
      uVar34 = uVar13 & 0xfffffffd;
    }
    if (uVar14 == uVar34) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var4,(int *)puVar5);
      return;
    }
    p_Var21 = p_Var36;
    if (*(_Rb_tree_node_base **)(lVar35 + 0x18) != 0x0) {
      p_Var22 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
      p_Var30 = p_Var36;
      do {
        while (p_Var21 = p_Var22, *(int *)(p_Var21 + 0x20) < (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))) {
          p_Var25 = p_Var21 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var25;
          p_Var21 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var25 == 0x0) goto LAB_00113d82;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
        p_Var30 = p_Var21;
      } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != 0x0);
LAB_00113d82:
      if ((p_Var36 != p_Var21) && (*(int *)(p_Var21 + 0x20) <= (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))))
      goto LAB_00113e28;
    }
    p_Var22 = rea_operator_new(0x28);
    if (p_Var22 != 0x0) {
      *(undefined4 *)p_Var22 = 0;
      *(undefined8 *)(p_Var22 + 8) = 0;
      *(undefined8 *)(p_Var22 + 0x10) = 0;
      *(undefined8 *)(p_Var22 + 0x18) = 0;
      *(undefined4 *)(p_Var22 + 0x24) = 0;
      *(undefined4 *)(p_Var22 + 0x20) = (*(undefined4 *)((uint8_t *)&auStack_13b + 0x3));
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
    p_Var30 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x8)));
    p_Var21 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar40 + 0x0)));
    if (p_Var30 == 0x0) {
      rea_operator_delete(p_Var22);
    }
    else {
      bVar38 = true;
      if ((p_Var21 == 0x0) && (p_Var36 != p_Var30)) {
        bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
      *(long long *)(lVar35 + 0x30) = *(long long *)(lVar35 + 0x30) + 1;
      p_Var21 = p_Var22;
    }
LAB_00113e28:
    *(uint *)(p_Var21 + 0x24) = uVar34;
    return;
  }
  goto LAB_00112bf9;
}
