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
// IDX 258  00116de0  EventLoop2__run
// ------------------------------------------------------------------
undefined4 rea_EventLoop2__run__dup2(EventLoop2 * this_ptr, long long param_2)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  epoll_data_t *peVar3;
  uint uVar4;
  undefined8 uVar5;
  long long lVar6;
  char cVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  int *piVar13;
  long long *plVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  bool bVar18;
  long long lVar19;
  _Rb_tree_node_base *p_Var20;
  _Rb_tree_node_base *p_Var21;
  undefined8 *puVar22;
  long long *plVar23;
  long long *plVar24;
  byte bVar25;
  undefined1 auVar26 [16];
  long long *local_c8;
  _Rb_tree_node_base *local_c0;
  int local_b0;
  int local_ac;
  long long *local_a0;
  undefined1 local_78[0xc];
  undefined1 local_68[0xc];
  code *local_50;
  code *local_48;
  
  if (this_ptr[0x54] != (EventLoop2)0x0) {
    peVar3 = ((uint8_t *)&local_68 + 0x4);
    do {
      local_a0 = *(long long **)(this_ptr + 0x10);
      local_c8 = *(long long **)(this_ptr + 8);
      if (local_a0 == local_c8) {
        if (*(long long *)(this_ptr + 0x28) == *(long long *)(this_ptr + 0x20)) break;
      }
      else if (*(long long *)(this_ptr + 0x28) == *(long long *)(this_ptr + 0x20)) goto LAB_00116ec6;
      std_________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_________________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_________________(this_ptr + 8);
      plVar24 = *(long long **)(this_ptr + 0x28);
      plVar23 = *(long long **)(this_ptr + 0x20);
      for (plVar14 = plVar23; plVar14 != plVar24; plVar14 = plVar14 + 1) {
        if ((long long *)*plVar14 != 0x0) {
          (**(code **)(*(long long *)*plVar14 + 0x18))();
        }
        *plVar14 = 0;
      }
      local_c8 = *(long long **)(this_ptr + 8);
      *(long long **)(this_ptr + 0x28) = plVar23;
      local_a0 = *(long long **)(this_ptr + 0x10);
      if (local_c8 != local_a0) {
LAB_00116ec6:
        local_ac = 0;
        local_b0 = 1;
        do {
          lVar19 = ((long long)local_ac + 1) * 0x30 + *local_c8;
          p_Var12 = *(_Rb_tree_node_base **)(lVar19 + 0x20);
          local_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          if (p_Var12 != local_c0) {
            do {
              uVar4 = *(uint *)(p_Var12 + 0x24);
              iVar10 = *(int *)(p_Var12 + 0x20);
              uVar8 = 0x11;
              (*(uint32_t *)((uint8_t *)&local_68 + 0x0)) = 0;
              (*(int *)((uint8_t *)&local_68 + 0x4)) = 0;
              if ((uVar4 & 2) != 0) {
                (*(uint32_t *)((uint8_t *)&local_68 + 0x0)) = 4;
                uVar8 = 0x15;
              }
              if ((uVar4 & 1) != 0) {
                (*(uint32_t *)((uint8_t *)&local_68 + 0x0)) = uVar8;
              }
              (*(undefined4 *)((uint8_t *)&local_68 + 0x4)) = iVar10;
              iVar9 = rea_epoll_ctl(*(int *)(this_ptr + 0x50),local_b0,iVar10,(epoll_event*)(uintptr_t)(&local_68));
              if (iVar9 != 0) {
                rea_perror("epoll_ctl");
              }
              lVar19 = *local_c8;
              p_Var1 = (_Rb_tree_node_base *)(lVar19 + 0x10);
              p_Var11 = *(_Rb_tree_node_base **)(lVar19 + 0x18);
              p_Var20 = p_Var1;
              p_Var21 = p_Var1;
              if (*(_Rb_tree_node_base **)(lVar19 + 0x18) == 0x0) {
LAB_00116fcb:
                p_Var11 = rea_operator_new(0x28);
                if (p_Var11 != 0x0) {
                  *(undefined4 *)p_Var11 = 0;
                  *(undefined8 *)(p_Var11 + 8) = 0;
                  *(undefined8 *)(p_Var11 + 0x10) = 0;
                  *(undefined8 *)(p_Var11 + 0x18) = 0;
                  *(int *)(p_Var11 + 0x20) = iVar10;
                  *(undefined4 *)(p_Var11 + 0x24) = 0;
                }
                { auto &&__rea_tmp = (std______________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________________M_get_insert_hint_unique_pos_____________________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                      *)(lVar19 + 8),p_Var21,p_Var11 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
                p_Var20 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x8)));
                p_Var21 = ((_Rb_tree_node_base*)(uintptr_t)(*(undefined8 *)((uint8_t *)&auVar26 + 0x0)));
                if (p_Var20 == 0x0) {
                  rea_operator_delete(p_Var11);
                }
                else {
                  bVar18 = true;
                  if ((p_Var21 == 0x0) && (p_Var1 != p_Var20)) {
                    bVar18 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var20 + 0x20);
                  }
                  rea_std___Rb_tree_insert_and_rebalance(bVar18,p_Var11,p_Var20,p_Var1);
                  *(long long *)(lVar19 + 0x30) = *(long long *)(lVar19 + 0x30) + 1;
                  p_Var21 = p_Var11;
                }
              }
              else {
                do {
                  while (p_Var21 = p_Var11, iVar10 <= *(int *)(p_Var21 + 0x20)) {
                    p_Var11 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
                    p_Var20 = p_Var21;
                    if (*(_Rb_tree_node_base **)(p_Var21 + 0x10) == 0x0)
                    goto LAB_00116fbb;
                  }
                  p_Var2 = p_Var21 + 0x18;
                  p_Var11 = *(_Rb_tree_node_base **)p_Var2;
                  p_Var21 = p_Var20;
                } while (*(_Rb_tree_node_base **)p_Var2 != 0x0);
LAB_00116fbb:
                if ((p_Var21 == p_Var1) || (iVar10 < *(int *)(p_Var21 + 0x20))) goto LAB_00116fcb;
              }
              *(uint *)(p_Var21 + 0x24) = uVar4;
              p_Var12 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var12);
            } while (local_c0 != p_Var12);
            lVar19 = ((long long)local_ac + 1) * 0x30 + *local_c8;
            local_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          }
          std______________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                      *)(lVar19 + 8),*(_Rb_tree_node **)(lVar19 + 0x18));
          *(undefined8 *)(lVar19 + 0x18) = 0;
          *(undefined8 *)(lVar19 + 0x30) = 0;
          *(_Rb_tree_node_base **)(lVar19 + 0x20) = local_c0;
          *(_Rb_tree_node_base **)(lVar19 + 0x28) = local_c0;
          if (local_ac == 1) goto code_r0x001170c4;
          local_b0 = 3;
          local_ac = 1;
        } while( true );
      }
LAB_001170da:
      iVar10 = rea_epoll_wait(*(int *)(this_ptr + 0x50),(epoll_event*)(uintptr_t)(&local_78),1,(int)(*(long long *)(this_ptr + 0x60) / 1000));
      if (iVar10 == -1) {
        piVar13 = rea___errno_location();
        if (*piVar13 != 4) {
          rea_perror("epoll_wait");
          rea_print_stack_abort();
        }
      }
      else if (iVar10 == 0) {
        puVar17 = *(undefined8 **)(this_ptr + 0x38);
        puVar15 = *(undefined8 **)(this_ptr + 0x40);
        if (puVar17 != puVar15) {
          do {
            local_50 = 0x0;
            (*(uint32_t *)((uint8_t *)&local_68 + 0x0)) = (uint32_t)*puVar17;
            (*(undefined4 *)((uint8_t *)&local_68 + 0x4)) = SUB84((ulong)*puVar17 >> 0x20,0);
            if ((code *)puVar17[3] != 0x0) {
              (*(code *)puVar17[3])(peVar3,puVar17 + 1,2);
              local_48 = (code *)puVar17[4];
              local_50 = (code *)puVar17[3];
            }
            plVar23 = *(long long **)(this_ptr + 8);
            plVar24 = *(long long **)(this_ptr + 0x10);
            if (plVar23 != plVar24) {
              lVar19 = *plVar23;
              while (CONCAT44((*(undefined4 *)((uint8_t *)&local_68 + 0x4)),(*(uint32_t *)((uint8_t *)&local_68 + 0x0))) != lVar19) {
                plVar23 = plVar23 + 1;
                if (plVar23 == plVar24) goto joined_r0x00117359;
                lVar19 = *plVar23;
              }
              plVar23 = plVar23 + 1;
              if ((plVar23 != plVar24) && (lVar19 = (long long)plVar24 - (long long)plVar23 >> 3, 0 < lVar19))
              {
                do {
                  plVar24 = (long long *)plVar23[-1];
                  lVar6 = *plVar23;
                  *plVar23 = 0;
                  plVar23[-1] = lVar6;
                  if (plVar24 != 0x0) {
                    (**(code **)(*plVar24 + 0x18))();
                  }
                  plVar23 = plVar23 + 1;
                  lVar19 = lVar19 + -1;
                } while (lVar19 != 0);
                plVar24 = *(long long **)(this_ptr + 0x10);
              }
              *(long long **)(this_ptr + 0x10) = plVar24 + -1;
              if ((long long *)plVar24[-1] != 0x0) {
                (**(code **)(*(long long *)plVar24[-1] + 0x18))();
              }
              plVar24[-1] = 0;
            }
joined_r0x00117359:
            if (local_50 == 0x0) {
                    /* WARNING: Subroutine does not return */
              rea_std____throw_bad_function_call();
            }
            (*local_48)(peVar3);
            if (local_50 != 0x0) {
              (*local_50)(peVar3,peVar3,3);
            }
            puVar17 = puVar17 + 5;
          } while (puVar15 != puVar17);
          puVar16 = *(undefined8 **)(this_ptr + 0x40);
          puVar15 = *(undefined8 **)(this_ptr + 0x38);
          puVar17 = puVar16;
          for (puVar22 = puVar15; puVar16 != puVar22; puVar22 = puVar22 + 5) {
            if ((code *)puVar22[3] != 0x0) {
              (*(code *)puVar22[3])(puVar22 + 1,puVar22 + 1,3);
            }
            puVar17 = puVar15;
          }
        }
        puVar15 = *(undefined8 **)(this_ptr + 8);
        *(undefined8 **)(this_ptr + 0x40) = puVar17;
        while (puVar15 != *(undefined8 **)(this_ptr + 0x10)) {
          cVar7 = (**(code **)(*(long long *)*puVar15 + 8))();
          while (cVar7 == '\0') {
            puVar15 = puVar15 + 1;
            if (puVar15 == *(undefined8 **)(this_ptr + 0x10)) goto LAB_0011724d;
            cVar7 = (**(code **)(*(long long *)*puVar15 + 8))();
          }
          puVar16 = *(undefined8 **)(this_ptr + 0x10);
          puVar17 = puVar15 + 1;
          if ((puVar16 != puVar17) && (lVar19 = (long long)puVar16 - (long long)puVar17 >> 3, 0 < lVar19)) {
            do {
              plVar23 = (long long *)puVar17[-1];
              uVar5 = *puVar17;
              *puVar17 = 0;
              puVar17[-1] = uVar5;
              if (plVar23 != 0x0) {
                (**(code **)(*plVar23 + 0x18))();
              }
              puVar17 = puVar17 + 1;
              lVar19 = lVar19 + -1;
            } while (lVar19 != 0);
            puVar16 = *(undefined8 **)(this_ptr + 0x10);
          }
          *(undefined8 **)(this_ptr + 0x10) = puVar16 + -1;
          if ((long long *)puVar16[-1] != 0x0) {
            (**(code **)(*(long long *)puVar16[-1] + 0x18))();
          }
          puVar16[-1] = 0;
        }
      }
      else {
        puVar17 = *(undefined8 **)(this_ptr + 8);
        while (puVar17 != *(undefined8 **)(this_ptr + 0x10)) {
          bVar25 = ((*(uint32_t *)((uint8_t *)&local_78 + 0x0)) & 0x11) != 0;
          if (((*(uint32_t *)((uint8_t *)&local_78 + 0x0)) & 4) != 0) {
            bVar25 = bVar25 | 2;
          }
          cVar7 = (*(code *)**(undefined8 **)*puVar17)((undefined8 *)*puVar17,(*(undefined4 *)((uint8_t *)&local_78 + 0x4)),bVar25)
          ;
          if ((cVar7 == '\0') && (cVar7 = (**(code **)(*(long long *)*puVar17 + 8))(), cVar7 == '\0')) {
            puVar17 = puVar17 + 1;
          }
          else {
            puVar16 = *(undefined8 **)(this_ptr + 0x10);
            puVar15 = puVar17 + 1;
            if ((puVar16 != puVar15) && (lVar19 = (long long)puVar16 - (long long)puVar15 >> 3, 0 < lVar19)) {
              do {
                plVar23 = (long long *)puVar15[-1];
                uVar5 = *puVar15;
                *puVar15 = 0;
                puVar15[-1] = uVar5;
                if (plVar23 != 0x0) {
                  (**(code **)(*plVar23 + 0x18))();
                }
                puVar15 = puVar15 + 1;
                lVar19 = lVar19 + -1;
              } while (lVar19 != 0);
              puVar16 = *(undefined8 **)(this_ptr + 0x10);
            }
            *(undefined8 **)(this_ptr + 0x10) = puVar16 + -1;
            if ((long long *)puVar16[-1] != 0x0) {
              (**(code **)(*(long long *)puVar16[-1] + 0x18))();
            }
            puVar16[-1] = 0;
          }
        }
      }
LAB_0011724d:
      if (*(long long *)(param_2 + 0x10) != 0) {
        (**(code **)(param_2 + 0x18))(param_2);
      }
    } while (this_ptr[0x54] != (EventLoop2)0x0);
  }
  this_ptr[0x54] = (EventLoop2)0x1;
  return *(undefined4 *)(this_ptr + 0x58);
code_r0x001170c4:
  local_c8 = local_c8 + 1;
  if (local_a0 == local_c8) goto LAB_001170da;
  goto LAB_00116ec6;
}
