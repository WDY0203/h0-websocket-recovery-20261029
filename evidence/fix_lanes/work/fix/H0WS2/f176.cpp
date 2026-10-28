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
// IDX 176  0010a6b0  FUN_0010a6b0
// ------------------------------------------------------------------
undefined8 rea_FUN_0010a6b0(undefined8 param_1, undefined8 param_2)
{
  allocator *paVar1;
  int *piVar2;
  EventLoop2 *pEVar3;
  long long lVar4;
  EventLoop2 *pEVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 uVar8;
  ulong uVar9;
  char *pcVar10;
  EventLoop2 *this_ptr;
  UnixClient *pUVar11;
  undefined8 uVar12;
  EventLoop2 *pEVar13;
  allocator *paVar14;
  undefined8 local_268 [2];
  undefined8 local_258 [2];
  char *local_248 [2];
  undefined8 *local_238 [2];
  code *local_228;
  code *pcStack_220;
  undefined8 *local_218 [2];
  code *local_208;
  code *pcStack_200;
  undefined1 local_1f8 [16];
  code *local_1e8;
  code *pcStack_1e0;
  undefined1 local_1d8 [16];
  code *local_1c8;
  code *pcStack_1c0;
  undefined1 local_1b8 [16];
  code *local_1a8;
  code *pcStack_1a0;
  undefined2 local_198;
  undefined1 local_196;
  code *local_188;
  code *pcStack_180;
  undefined1 local_178[0x98];
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  (*(code **)((uint8_t *)&local_178 + 0x0)) = 0x0;
  local_f0 = 0;
  rea_sigemptyset(&local_170);
  rea_sigaction(2,(sigaction *)&local_178,&local_d8);
  local_196 = 0;
  local_198 = 0x4f4f;
  iVar7 = rea_PyArg_ParseTuple(param_2,(allocator *)&local_198,local_268,local_258);
  if (iVar7 == 0) {
    uVar12 = 0;
  }
  else {
    uVar8 = rea_PyLong_AsLong(local_258[0]);
    uVar9 = rea_PyString_Size(local_268[0]);
    pcVar10 = (char *)rea_PyString_AsString(local_268[0]);
    rea_std__string__string((string *)local_248,pcVar10,uVar9,(allocator *)&local_198);
    this_ptr = rea_operator_new(0xf0);
    rea_EventLoop2__EventLoop2(this_ptr);
    pEVar3 = this_ptr + 0xa8;
    *(undefined4 *)(this_ptr + 0x80) = 0;
    *(undefined8 *)(this_ptr + 0x88) = 0;
    *(undefined8 *)(this_ptr + 0xa0) = 0;
    *(EventLoop2 **)(this_ptr + 0x90) = this_ptr + 0x80;
    *(EventLoop2 **)(this_ptr + 0x98) = this_ptr + 0x80;
    puVar6 = PTR_vtable_00324f90;
    *(EventLoop2 **)(this_ptr + 0xa8) = pEVar3;
    *(EventLoop2 **)(this_ptr + 0xb0) = pEVar3;
    this_ptr[0xb8] = (EventLoop2)0x0;
    *(undefined8 *)(this_ptr + 0xd0) = 0;
    local_208 = 0x0;
    *(undefined **)(this_ptr + 0x70) = puVar6 + 0x10;
    local_218[0] = (undefined8*)(uintptr_t)(rea_operator_new(8));
    *local_218[0] = (undefined8)(uintptr_t)(this_ptr);
    local_228 = 0x0;
    pcStack_200 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_001078e0);
    local_208 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107a90);
    local_238[0] = (undefined8*)(uintptr_t)(rea_operator_new(8));
    *local_238[0] = (undefined8)(uintptr_t)(this_ptr);
    pcStack_220 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00109140);
    local_228 = (uint64_t (*)(...))(uintptr_t)(rea_FUN_00107b10);
    if ((*(long long *)(local_248[0] + -0x18) == 0) || (*local_248[0] != '/')) {
      local_1c8 = 0x0;
      rea_FUN_00107b10((undefined8*)(uintptr_t)(local_1d8),(undefined8*)(uintptr_t)(local_238),2);
      local_1e8 = 0x0;
      local_1c8 = local_228;
      pcStack_1c0 = pcStack_220;
      if (local_208 != 0x0) {
        (*local_208)(local_1f8,local_218,2);
        local_1e8 = local_208;
        pcStack_1e0 = pcStack_200;
      }
      pUVar11 = rea_operator_new(0xe8);
      rea_TcpClient__TcpClient((TcpClient *)pUVar11,(string *)local_248,uVar8,local_1d8,local_1f8);
      if (local_1e8 != 0x0) {
        (*local_1e8)(local_1f8,local_1f8,3);
      }
      if (local_1c8 != 0x0) {
        (*local_1c8)(local_1d8,local_1d8,3);
      }
    }
    else {
      local_188 = 0x0;
      rea_FUN_00107b10((undefined8*)(uintptr_t)((allocator *)&local_198),(undefined8*)(uintptr_t)(local_238),2);
      local_1a8 = 0x0;
      local_188 = local_228;
      pcStack_180 = pcStack_220;
      if (local_208 != 0x0) {
        (*local_208)(local_1b8,local_218,2);
        local_1a8 = local_208;
        pcStack_1a0 = pcStack_200;
      }
      pUVar11 = rea_operator_new(0xe8);
      rea_UnixClient__UnixClient(pUVar11,(string *)local_248,(allocator *)&local_198);
      if (local_1a8 != 0x0) {
        (*local_1a8)(local_1b8,local_1b8,3);
      }
      if (local_188 != 0x0) {
        (*local_188)((allocator *)&local_198,(allocator *)&local_198,3);
      }
    }
    rea_EventLoop2__add(this_ptr,(EventHandler *)pUVar11);
    if (local_228 != 0x0) {
      (*local_228)(local_238,local_238,3);
    }
    if (local_208 != 0x0) {
      (*local_208)(local_218,local_218,3);
    }
    local_188 = 0x0;
    iVar7 = rea_EventLoop2__run(this_ptr,(long long int)(uintptr_t)((allocator *)&local_198));
    if (local_188 != 0x0) {
      (*local_188)((allocator *)&local_198,(allocator *)&local_198,3);
    }
    paVar14 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
    if (iVar7 == 0) {
      *(undefined **)(this_ptr + 0x70) = PTR_vtable_00324f90 + 0x10;
      if (*(code **)(this_ptr + 0xd0) != 0x0) {
        (**(code **)(this_ptr + 0xd0))(this_ptr + 0xc0,this_ptr + 0xc0,3);
      }
      paVar14 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
      pEVar13 = *(EventLoop2 **)(this_ptr + 0xa8);
      if (pEVar3 != pEVar13) {
        if (PTR___pthread_key_create_00324f80 == 0x0) {
          do {
            lVar4 = *(long long *)(pEVar13 + 0x18);
            pEVar5 = *(EventLoop2 **)pEVar13;
            if (((allocator *)(lVar4 + -0x18) != paVar14) &&
               (iVar7 = *(int *)(lVar4 + -8), *(int *)(lVar4 + -8) = iVar7 + -1, iVar7 < 1)) {
              rea_std__string___Rep___M_destroy((allocator *)(lVar4 + -0x18));
            }
            rea_operator_delete(pEVar13);
            pEVar13 = pEVar5;
          } while (pEVar3 != pEVar5);
        }
        else {
          do {
            pEVar5 = *(EventLoop2 **)pEVar13;
            paVar1 = (allocator *)(*(long long *)(pEVar13 + 0x18) + -0x18);
            if (paVar1 != paVar14) {
              LOCK();
              piVar2 = (int *)(*(long long *)(pEVar13 + 0x18) + -8);
              iVar7 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
              if (iVar7 < 1) {
                rea_std__string___Rep___M_destroy(paVar1);
              }
            }
            rea_operator_delete(pEVar13);
            pEVar13 = pEVar5;
          } while (pEVar3 != pEVar5);
        }
      }
      std__________Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root__________M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
                  *)(this_ptr + 0x78),*(_Rb_tree_node **)(this_ptr + 0x88));
      *(undefined **)(this_ptr + 0x70) = PTR_vtable_00324ef0 + 0x10;
      rea_EventLoop2__dtor_EventLoop2(this_ptr);
      rea_operator_delete(this_ptr);
      this_ptr = 0x0;
    }
    if ((allocator *)(local_248[0] + -0x18) != paVar14) {
      piVar2 = (int *)(local_248[0] + -8);
      if (PTR___pthread_key_create_00324f80 == 0x0) {
        iVar7 = *(int *)(local_248[0] + -8);
        *(int *)(local_248[0] + -8) = iVar7 + -1;
      }
      else {
        LOCK();
        iVar7 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar7 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_248[0] + -0x18));
      }
    }
    uVar12 = rea_PyLong_FromVoidPtr(this_ptr);
  }
  rea_sigaction(2,&local_d8,0x0);
  return uVar12;
}
