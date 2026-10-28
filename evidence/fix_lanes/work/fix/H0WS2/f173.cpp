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
// IDX 173  001093b0  FUN_001093b0
// ------------------------------------------------------------------
void rea_FUN_001093b0(undefined8 * param_1, undefined8 * param_2, undefined8 * param_3)
{
  allocator *paVar1;
  int *piVar2;
  ulong *puVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long long *plVar9;
  ulong *puVar10;
  ulong *puVar11;
  void *pvVar12;
  long long lVar13;
  long long lVar14;
  code *pcVar15;
  int iVar16;
  ulong *puVar17;
  _List_node_base *p_Var18;
  ulong uVar19;
  long long lVar20;
  ulong uVar21;
  allocator *paVar22;
  ulong uVar23;
  allocator local_cb [3];
  ulong *local_c8 [2];
  undefined4 local_b8;
  allocator *local_b0;
  undefined4 local_a8 [2];
  long long local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  code *local_68;
  undefined8 uStack_60;
  undefined8 *local_58 [2];
  code *local_48;
  undefined *local_40;
  
  puVar5 = (undefined8 *)*param_3;
  uVar6 = *param_2;
  *param_3 = 0;
  uVar7 = param_2[1];
  *param_2 = local_98;
  local_88 = (code *)param_2[2];
  param_2[1] = local_90;
  param_2[2] = 0;
  uVar8 = param_2[3];
  param_2[3] = uStack_80;
  plVar9 = (long long *)*param_1;
  local_98 = uVar6;
  local_90 = uVar7;
  uStack_80 = uVar8;
  if (puVar5 == 0x0) {
    rea_WSConn__exit(*(WSConn **)(*plVar9 + 0x68));
  }
  else {
    puVar10 = (ulong *)puVar5[1];
    puVar11 = (ulong *)*puVar5;
    if (puVar10 == puVar11) {
      local_c8[0] = (ulong *)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
      paVar22 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
    }
    else {
      uVar23 = (long long)puVar10 - (long long)puVar11;
      puVar17 = (ulong *)rea_std__string___Rep___S_create(uVar23,0,local_cb);
      local_c8[0] = puVar17 + 3;
      if ((uVar23 < 0x10) || (local_c8[0] < puVar11 + 2 && puVar11 < puVar17 + 5)) {
        lVar20 = 0;
        do {
          *(undefined1 *)((long long)local_c8[0] + lVar20) = *(undefined1 *)((long long)puVar11 + lVar20);
          lVar20 = lVar20 + 1;
        } while (lVar20 != (long long)puVar10 - (long long)puVar11);
      }
      else {
        lVar20 = 0;
        uVar21 = 0;
        uVar19 = uVar23 >> 4;
        do {
          uVar6 = ((undefined8 *)((long long)puVar11 + lVar20))[1];
          uVar21 = uVar21 + 1;
          *(undefined8 *)((long long)local_c8[0] + lVar20) = *(undefined8 *)((long long)puVar11 + lVar20);
          ((undefined8 *)((long long)local_c8[0] + lVar20))[1] = uVar6;
          lVar20 = lVar20 + 0x10;
        } while (uVar21 < uVar19);
        puVar11 = puVar11 + uVar19 * 2;
        puVar3 = local_c8[0] + uVar19 * 2;
        if (((((((uVar19 * 0x10 != uVar23) &&
                (*(char *)puVar3 = (char)*puVar11, puVar10 != (ulong *)((long long)puVar11 + 1))) &&
               (*(undefined1 *)((long long)puVar3 + 1) = *(undefined1 *)((long long)puVar11 + 1),
               puVar10 != (ulong *)((long long)puVar11 + 2))) &&
              ((*(undefined1 *)((long long)puVar3 + 2) = *(undefined1 *)((long long)puVar11 + 2),
               puVar10 != (ulong *)((long long)puVar11 + 3) &&
               (*(undefined1 *)((long long)puVar3 + 3) = *(undefined1 *)((long long)puVar11 + 3),
               puVar10 != (ulong *)((long long)puVar11 + 4))))) &&
             ((*(undefined1 *)((long long)puVar3 + 4) = *(undefined1 *)((long long)puVar11 + 4),
              puVar10 != (ulong *)((long long)puVar11 + 5) &&
              ((*(undefined1 *)((long long)puVar3 + 5) = *(undefined1 *)((long long)puVar11 + 5),
               puVar10 != (ulong *)((long long)puVar11 + 6) &&
               (*(undefined1 *)((long long)puVar3 + 6) = *(undefined1 *)((long long)puVar11 + 6),
               puVar10 != (ulong *)((long long)puVar11 + 7))))))) &&
            (*(undefined1 *)((long long)puVar3 + 7) = *(undefined1 *)((long long)puVar11 + 7),
            puVar10 != puVar11 + 1)) &&
           ((((*(char *)(puVar3 + 1) = (char)puVar11[1], puVar10 != (ulong *)((long long)puVar11 + 9) &&
              (*(undefined1 *)((long long)puVar3 + 9) = *(undefined1 *)((long long)puVar11 + 9),
              puVar10 != (ulong *)((long long)puVar11 + 10))) &&
             (*(undefined1 *)((long long)puVar3 + 10) = *(undefined1 *)((long long)puVar11 + 10),
             puVar10 != (ulong *)((long long)puVar11 + 0xb))) &&
            (((*(undefined1 *)((long long)puVar3 + 0xb) = *(undefined1 *)((long long)puVar11 + 0xb),
              puVar10 != (ulong *)((long long)puVar11 + 0xc) &&
              (*(undefined1 *)((long long)puVar3 + 0xc) = *(undefined1 *)((long long)puVar11 + 0xc),
              puVar10 != (ulong *)((long long)puVar11 + 0xd))) &&
             (*(undefined1 *)((long long)puVar3 + 0xd) = *(undefined1 *)((long long)puVar11 + 0xd),
             puVar10 != (ulong *)((long long)puVar11 + 0xe))))))) {
          *(undefined1 *)((long long)puVar3 + 0xe) = *(undefined1 *)((long long)puVar11 + 0xe);
        }
      }
      paVar22 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
      if (puVar17 != (ulong *)PTR__S_empty_rep_storage_00324fa0) {
        *(undefined4 *)(puVar17 + 2) = 0;
        *puVar17 = uVar23;
        *(undefined1 *)((long long)puVar17 + uVar23 + 0x18) = 0;
      }
    }
    local_b8 = 0;
    rea_std__string__string((string *)&local_b0,(string *)local_c8);
    lVar20 = *plVar9;
    p_Var18 = rea_operator_new(0x20);
    if (p_Var18 != 0x0) {
      *(undefined8 *)p_Var18 = 0;
      *(undefined8 *)(p_Var18 + 8) = 0;
      *(undefined4 *)(p_Var18 + 0x10) = local_b8;
      *(allocator **)(p_Var18 + 0x18) = local_b0;
      local_b0 = paVar22 + 0x18;
    }
    rea_std____detail___List_node_base___M_hook(p_Var18);
    if ((*(char *)(lVar20 + 0xb8) != '\0') &&
       (pvVar12 = *(void **)(lVar20 + 0xa8), (void *)(lVar20 + 0xa8) != pvVar12)) {
      uVar4 = *(undefined4 *)((long long)pvVar12 + 0x10);
      lVar13 = *(long long *)((long long)pvVar12 + 0x18);
      *(allocator **)((long long)pvVar12 + 0x18) = paVar22 + 0x18;
      rea_std____detail___List_node_base___M_unhook();
      lVar14 = *(long long *)((long long)pvVar12 + 0x18);
      if ((allocator *)(lVar14 + -0x18) != paVar22) {
        piVar2 = (int *)(lVar14 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar16 = *(int *)(lVar14 + -8);
          *(int *)(lVar14 + -8) = iVar16 + -1;
        }
        else {
          LOCK();
          iVar16 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar16 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar14 + -0x18));
        }
      }
      rea_operator_delete(pvVar12);
      *(undefined1 *)(lVar20 + 0xb8) = 0;
      if (*(long long *)(lVar20 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_a8[0] = uVar4;
      local_a0 = lVar13;
      (**(code **)(lVar20 + 0xd8))(lVar20 + 0xc0,local_a8);
      if ((allocator *)(local_a0 + -0x18) != paVar22) {
        piVar2 = (int *)(local_a0 + -8);
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          iVar16 = *(int *)(local_a0 + -8);
          *(int *)(local_a0 + -8) = iVar16 + -1;
        }
        else {
          LOCK();
          iVar16 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar16 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(local_a0 + -0x18));
        }
      }
    }
    if (local_b0 + -0x18 != paVar22) {
      paVar1 = local_b0 + -8;
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar16 = *(int *)(local_b0 + -8);
        *(int *)(local_b0 + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *(int *)paVar1;
        *(int *)paVar1 = *(int *)paVar1 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy(local_b0 + -0x18);
      }
    }
    if ((allocator *)(local_c8[0] + -3) != paVar22) {
      puVar11 = local_c8[0] + -1;
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar16 = (int)local_c8[0][-1];
        *(int *)(local_c8[0] + -1) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = (int)*puVar11;
        *(int *)puVar11 = (int)*puVar11 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_c8[0] + -3));
      }
    }
    local_68 = 0x0;
    if (local_88 != 0x0) {
      (*local_88)(&local_78,&local_98,2);
      local_68 = local_88;
      uStack_60 = uStack_80;
    }
    local_48 = 0x0;
    local_58[0] = (undefined8*)(uintptr_t)(rea_operator_new(0x20));
    pcVar15 = local_68;
    local_58[0][2] = 0;
    uVar6 = *local_58[0];
    uVar7 = local_58[0][1];
    uVar8 = local_58[0][3];
    local_58[0][1] = local_70;
    *local_58[0] = local_78;
    local_68 = 0x0;
    local_58[0][2] = (undefined8)(uintptr_t)(pcVar15);
    local_58[0][3] = uStack_60;
    local_40 = PTR__M_invoke_00324fe0;
    local_48 = (code *)PTR__M_manager_00324f88;
    local_78 = uVar6;
    local_70 = uVar7;
    uStack_60 = uVar8;
    rea_WSConn__recv(*(WSConn **)(*plVar9 + 0x68),(long long int)(uintptr_t)(local_58));
    if (local_48 != 0x0) {
      (*local_48)(local_58,local_58,3);
    }
    if (local_68 != 0x0) {
      (*local_68)(&local_78,&local_78,3);
    }
  }
  if (local_88 != 0x0) {
    (*local_88)(&local_98,&local_98,3);
  }
  if (puVar5 != 0x0) {
    if ((void *)*puVar5 != 0x0) {
      rea_operator_delete((void *)*puVar5);
    }
    rea_operator_delete(puVar5);
  }
  return;
}
