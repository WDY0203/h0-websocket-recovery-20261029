#include "H0WS2_shim.hpp"

// ------------------------------------------------------------------
// IDX 0  00106e48  _init
// ------------------------------------------------------------------
int rea__init(EVP_PKEY_CTX * ctx)
{
  int iVar1;
  
  iVar1 = 0;
  if (PTR___gmon_start___00324ed0 != (undefined *)0x0) {
    iVar1 = __gmon_start__();
  }
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 1  00106e70  FUN_00106e70
// ------------------------------------------------------------------
void rea_FUN_00106e70(void)
{
  (*(code *)PTR_00325010)();
  return;
}





// ------------------------------------------------------------------
// IDX 2  00106e80  WSConn__recv_pat
// ------------------------------------------------------------------
void rea_WSConn__recv_pat(WSConn * this_ptr, string * param_2, long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  int *piVar2;
  char cVar3;
  void *__haystack;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  void *pvVar12;
  undefined8 *puVar13;
  _Rb_tree_node_base *p_Var14;
  long lVar15;
  _Rb_tree_node_base *p_Var16;
  long lVar17;
  _Rb_tree_node_base *p_Var18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  uint uVar22;
  uint uVar23;
  undefined1 auVar24 [16];
  int aiStack_c8 [4];
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  WSConn *pWStack_98;
  long lStack_90;
  undefined1 auStack_88 [16];
  code *pcStack_78;
  undefined8 uStack_70;
  WSConn *pWStack_68;
  undefined *puStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  __haystack = (void *)**(undefined8 **)(this_ptr + 0x40);
  pvVar12 = rea_memmem(__haystack,(*(undefined8 **)(this_ptr + 0x40))[1] - (long)__haystack,
                   *(void **)param_2,*(size_t *)((long)*(void **)param_2 + -0x18));
  if (pvVar12 != (void *)0x0) {
    if (*(long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3,(long)pvVar12 - (long)__haystack);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  pWStack_98 = this_ptr;
  rea_std__string__string((string *)&lStack_90,param_2);
  pcStack_78 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(auStack_88,param_3,2);
    pcStack_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
  }
  lVar17 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar17 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar17 + 0x88) = 1;
  pWStack_68 = pWStack_98;
  rea_std__string__string((string *)&puStack_60,(string *)&lStack_90);
  pcStack_48 = (code *)0x0;
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(&uStack_58,auStack_88,2);
    pcStack_48 = pcStack_78;
    uStack_40 = uStack_70;
  }
  pcStack_a8 = (code *)0x0;
  puVar13 = rea_operator_new(0x30);
  pcVar9 = pcStack_48;
  puVar8 = PTR__S_empty_rep_storage_00324fa0;
  *puVar13 = pWStack_68;
  puVar13[1] = puStack_60;
  puStack_60 = puVar8 + 0x18;
  puVar13[4] = 0;
  uVar4 = puVar13[2];
  uVar5 = puVar13[3];
  puVar13[2] = uStack_58;
  puVar13[3] = uStack_50;
  pcStack_48 = (code *)0x0;
  uVar6 = puVar13[5];
  puVar13[4] = pcVar9;
  puVar13[5] = uStack_40;
  uStack_b8 = *(undefined8 *)(lVar17 + 0x90);
  uVar7 = *(undefined8 *)(lVar17 + 0x98);
  pcStack_a8 = *(code **)(lVar17 + 0xa0);
  *(undefined8 *)(lVar17 + 0x98) = uStack_b0;
  *(undefined8 **)(lVar17 + 0x90) = puVar13;
  *(code **)(lVar17 + 0xa0) = FUN_0010deb0;
  uStack_a0 = *(undefined8 *)(lVar17 + 0xa8);
  *(code **)(lVar17 + 0xa8) = FUN_00111f80;
  uStack_b0 = uVar7;
  uStack_58 = uVar4;
  uStack_50 = uVar5;
  uStack_40 = uVar6;
  if (pcStack_a8 != (code *)0x0) {
    (*pcStack_a8)(&uStack_b8,&uStack_b8,3);
  }
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  if ((allocator *)(puStack_60 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(puStack_60 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar11 = *(int *)(puStack_60 + -8);
      *(int *)(puStack_60 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(puStack_60 + -0x18));
    }
  }
  cVar3 = *(char *)(lVar17 + 0x88);
  aiStack_c8[0] = *(int *)(lVar17 + 0x40);
  lVar17 = *(long *)(lVar17 + 0x38);
  p_Var14 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var19 = p_Var14;
  p_Var18 = p_Var16;
  if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0010f530:
    lVar15 = 0;
    uVar23 = 0;
  }
  else {
    do {
      while (p_Var20 = p_Var19, *(int *)(p_Var20 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var19 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var18;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0010f43a;
      }
      p_Var19 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var18 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f43a:
    if ((p_Var16 == p_Var20) || (p_Var19 = p_Var16, aiStack_c8[0] < *(int *)(p_Var20 + 0x20)))
    goto LAB_0010f530;
    do {
      while (p_Var18 = p_Var14, *(int *)(p_Var18 + 0x20) < aiStack_c8[0]) {
        p_Var20 = p_Var18 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var20;
        p_Var18 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f46a;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
      p_Var19 = p_Var18;
    } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f46a:
    if ((p_Var16 == p_Var18) || (aiStack_c8[0] < *(int *)(p_Var18 + 0x20))) {
      p_Var14 = rea_operator_new(0x28);
      if (p_Var14 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var14 = 0;
        *(undefined8 *)(p_Var14 + 8) = 0;
        *(undefined8 *)(p_Var14 + 0x10) = 0;
        *(undefined8 *)(p_Var14 + 0x18) = 0;
        *(undefined4 *)(p_Var14 + 0x24) = 0;
        *(int *)(p_Var14 + 0x20) = aiStack_c8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar17 + 8),p_Var18,p_Var14 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
      p_Var19 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x8));
      p_Var18 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x0));
      if (p_Var19 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var14);
      }
      else {
        bVar21 = true;
        if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var19)) {
          bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var19,p_Var16);
        *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
        p_Var18 = p_Var14;
      }
    }
    uVar23 = *(uint *)(p_Var18 + 0x24);
    lVar15 = 1;
  }
  lVar17 = lVar17 + (lVar15 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar17 + 8);
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var18 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var14 = p_Var16;
  p_Var19 = p_Var18;
  uVar10 = uVar23;
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var20 = p_Var14, *(int *)(p_Var20 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0010f582;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f582:
    if ((p_Var18 != p_Var20) && (p_Var14 = p_Var18, *(int *)(p_Var20 + 0x20) <= aiStack_c8[0])) {
      do {
        while (p_Var19 = p_Var16, *(int *)(p_Var19 + 0x20) < aiStack_c8[0]) {
          p_Var20 = p_Var19 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var20;
          p_Var19 = p_Var14;
          if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f5ba;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var14 = p_Var19;
      } while (*(_Rb_tree_node_base **)(p_Var19 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f5ba:
      if ((p_Var18 == p_Var19) || (aiStack_c8[0] < *(int *)(p_Var19 + 0x20))) {
        p_Var16 = rea_operator_new(0x28);
        if (p_Var16 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var16 = 0;
          *(undefined8 *)(p_Var16 + 8) = 0;
          *(undefined8 *)(p_Var16 + 0x10) = 0;
          *(undefined8 *)(p_Var16 + 0x18) = 0;
          *(undefined4 *)(p_Var16 + 0x24) = 0;
          *(int *)(p_Var16 + 0x20) = aiStack_c8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var19,p_Var16 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
        p_Var14 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x8));
        p_Var19 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x0));
        if (p_Var14 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var16);
        }
        else {
          bVar21 = true;
          if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var18 != p_Var14)) {
            bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var14 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var14,p_Var18);
          *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
          p_Var19 = p_Var16;
        }
      }
      uVar10 = *(uint *)(p_Var19 + 0x24);
    }
  }
  uVar22 = uVar10 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar10 & 0xfffffffe;
  }
  if (uVar23 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_c8);
    goto LAB_0010f72d;
  }
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var19 = p_Var18;
  p_Var14 = p_Var18;
  if (*(_Rb_tree_node_base **)(lVar17 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010f6ad:
    p_Var16 = rea_operator_new(0x28);
    if (p_Var16 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var16 = 0;
      *(undefined8 *)(p_Var16 + 8) = 0;
      *(undefined8 *)(p_Var16 + 0x10) = 0;
      *(undefined8 *)(p_Var16 + 0x18) = 0;
      *(undefined4 *)(p_Var16 + 0x24) = 0;
      *(int *)(p_Var16 + 0x20) = aiStack_c8[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var14,p_Var16 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
    p_Var19 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x8));
    p_Var14 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x0));
    if (p_Var19 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var16);
    }
    else {
      bVar21 = true;
      if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var18 != p_Var19)) {
        bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var19 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var19,p_Var18);
      *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
      p_Var14 = p_Var16;
    }
  }
  else {
    do {
      while (p_Var14 = p_Var16, *(int *)(p_Var14 + 0x20) < aiStack_c8[0]) {
        p_Var20 = p_Var14 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var20;
        p_Var14 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f6a2;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var19 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f6a2:
    if ((p_Var18 == p_Var14) || (aiStack_c8[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0010f6ad;
  }
  *(uint *)(p_Var14 + 0x24) = uVar22;
LAB_0010f72d:
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(auStack_88,auStack_88,3);
  }
  if ((allocator *)(lStack_90 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(lStack_90 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar11 = *(int *)(lStack_90 + -8);
      *(int *)(lStack_90 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lStack_90 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 3  00106e90  std__string__append
// ------------------------------------------------------------------
undefined8 rea_std__string__append(char * param_1, ulong param_2)
{
  (*(code *)PTR_append_00325020)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 4  00106ea0  std____throw_length_error
// ------------------------------------------------------------------
undefined8 rea_std____throw_length_error(char * param_1)
{
  (*(code *)PTR___throw_length_error_00325028)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 5  00106eb0  PyString_AsString
// ------------------------------------------------------------------
undefined8 rea_PyString_AsString(...)
{
  (*(code *)PTR_PyString_AsString_00325030)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 6  00106ec0  memset
// ------------------------------------------------------------------
void * rea_memset(void * __s, int __c, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00325038)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 7  00106ed0  shutdown
// ------------------------------------------------------------------
int rea_shutdown(int __fd, int __how)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_shutdown_00325040)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 8  00106ee0  backtrace
// ------------------------------------------------------------------
undefined8 rea_backtrace(...)
{
  (*(code *)PTR_backtrace_00325048)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 9  00106ef0  std____detail___List_node_base___M_unhook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_unhook(void)
{
  (*(code *)PTR__M_unhook_00325050)();
  return;
}





// ------------------------------------------------------------------
// IDX 10  00106f00  close
// ------------------------------------------------------------------
int rea_close(int __fd)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00325058)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 11  00106f10  inflateEnd
// ------------------------------------------------------------------
void rea_inflateEnd(...)
{
  (*(code *)PTR_inflateEnd_00325060)();
  return;
}





// ------------------------------------------------------------------
// IDX 12  00106f20  Py_InitModule4_64
// ------------------------------------------------------------------
void rea_Py_InitModule4_64(...)
{
  (*(code *)PTR_Py_InitModule4_64_00325068)();
  return;
}





// ------------------------------------------------------------------
// IDX 13  00106f30  abort
// ------------------------------------------------------------------
void rea_abort(void)
{
  (*(code *)PTR_abort_00325070)();
  return;
}





// ------------------------------------------------------------------
// IDX 14  00106f40  PyLong_FromVoidPtr
// ------------------------------------------------------------------
undefined8 rea_PyLong_FromVoidPtr(...)
{
  (*(code *)PTR_PyLong_FromVoidPtr_00325078)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 15  00106f50  PyLong_AsVoidPtr
// ------------------------------------------------------------------
undefined8 rea_PyLong_AsVoidPtr(...)
{
  (*(code *)PTR_PyLong_AsVoidPtr_00325080)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 16  00106f60  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string(string * this_ptr, char * param_1, ulong param_2, allocator * param_3)
{
  (*(code *)PTR_string_00325088)();
  return;
}





// ------------------------------------------------------------------
// IDX 17  00106f70  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase
// ------------------------------------------------------------------
long rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, int * param_1)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  int iVar3;
  _Rb_tree_node *p_Var4;
  long lVar5;
  _Rb_tree_node *p_Var6;
  long lVar7;
  _Rb_tree_node_base *p_Var8;
  void *pvVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 8);
  p_Var4 = *(_Rb_tree_node **)(this_ptr + 0x10);
  p_Var11 = p_Var1;
  p_Var13 = p_Var1;
  if (p_Var4 != (_Rb_tree_node *)0x0) {
    iVar3 = *param_1;
    p_Var6 = p_Var4;
    do {
      while (p_Var8 = (_Rb_tree_node_base *)p_Var6, iVar3 <= *(int *)(p_Var8 + 0x20)) {
        if (*(int *)(p_Var8 + 0x20) <= iVar3) {
          p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
          p_Var12 = *(_Rb_tree_node_base **)(p_Var8 + 0x18);
          while (p_Var13 = p_Var11, p_Var12 != (_Rb_tree_node_base *)0x0) {
            while (p_Var13 = p_Var12, iVar3 < *(int *)(p_Var13 + 0x20)) {
              p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var11 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010b800;
            }
            p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
          }
LAB_0010b800:
          do {
            p_Var11 = p_Var8;
            if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
            iVar2 = *(int *)(p_Var10 + 0x20);
            while (p_Var11 = p_Var10, iVar3 <= iVar2) {
              p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
              if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
              iVar2 = *(int *)(p_Var10 + 0x20);
              p_Var8 = p_Var11;
            }
            p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
          } while( true );
        }
        p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var11 = p_Var8;
        p_Var13 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
      }
      p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x18);
      p_Var13 = p_Var11;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x18) != (_Rb_tree_node_base *)0x0);
  }
LAB_0010b763:
  lVar5 = *(long *)(this_ptr + 0x28);
  if ((p_Var11 == *(_Rb_tree_node_base **)(this_ptr + 0x18)) && (p_Var1 == p_Var13)) {
    _M_erase(this_ptr,p_Var4);
    *(_Rb_tree_node_base **)(this_ptr + 0x18) = p_Var1;
    *(undefined8 *)(this_ptr + 0x10) = 0;
    *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
    *(undefined8 *)(this_ptr + 0x28) = 0;
    lVar7 = lVar5;
  }
  else {
    lVar7 = 0;
    if (p_Var11 != p_Var13) {
      do {
        p_Var8 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var11);
        pvVar9 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var11,p_Var1);
        rea_operator_delete(pvVar9);
        lVar7 = *(long *)(this_ptr + 0x28);
        *(long *)(this_ptr + 0x28) = lVar7 + -1;
        p_Var11 = p_Var8;
      } while (p_Var8 != p_Var13);
      lVar7 = lVar5 - (lVar7 + -1);
    }
  }
  return lVar7;
}





// ------------------------------------------------------------------
// IDX 18  00106f80  EventLoop2__dtor_EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__dtor_EventLoop2(EventLoop2 * this_ptr)
{
  void *pvVar1;
  long *plVar2;
  void *pvVar3;
  long *plVar4;
  
  *(undefined **)this_ptr = PTR_vtable_00324f00 + 0x10;
  rea_close(*(int *)(this_ptr + 0x50));
  pvVar3 = *(void **)(this_ptr + 0x40);
  pvVar1 = *(void **)(this_ptr + 0x38);
  if (pvVar3 != pvVar1) {
    do {
      if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
        (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
      }
      pvVar1 = (void *)((long)pvVar1 + 0x28);
    } while (pvVar3 != pvVar1);
    pvVar3 = *(void **)(this_ptr + 0x38);
  }
  if (pvVar3 != (void *)0x0) {
    rea_operator_delete(pvVar3);
  }
  plVar4 = *(long **)(this_ptr + 0x28);
  plVar2 = *(long **)(this_ptr + 0x20);
  if (plVar4 != plVar2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long **)(this_ptr + 0x20);
  }
  if (plVar4 != (long *)0x0) {
    rea_operator_delete(plVar4);
  }
  plVar4 = *(long **)(this_ptr + 0x10);
  plVar2 = *(long **)(this_ptr + 8);
  if (plVar4 != plVar2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long **)(this_ptr + 8);
  }
  if (plVar4 == (long *)0x0) {
    return;
  }
  rea_operator_delete(plVar4);
  return;
}





// ------------------------------------------------------------------
// IDX 19  00106f90  operator_delete
// ------------------------------------------------------------------
void rea_operator__delete(void * param_1)
{
  (*(code *)PTR_operator_delete_003250a0)();
  return;
}





// ------------------------------------------------------------------
// IDX 20  00106fa0  std__string__reserve
// ------------------------------------------------------------------
void rea_std__string__reserve(ulong param_1)
{
  (*(code *)PTR_reserve_003250a8)();
  return;
}





// ------------------------------------------------------------------
// IDX 21  00106fb0  std__string___Rep___M_dispose
// ------------------------------------------------------------------
void rea_std__string___Rep___M_dispose(allocator * param_1)
{
  (*(code *)PTR__M_dispose_003250b0)();
  return;
}





// ------------------------------------------------------------------
// IDX 22  00106fc0  WSConn__read_data_mask
// ------------------------------------------------------------------
void rea_WSConn__read_data_mask(WSConn * this_ptr, undefined4 param_1, undefined1 param_2, long param_3, long param_5)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *apuStack_88 [2];
  code *pcStack_78;
  code *pcStack_70;
  WSConn *pWStack_68;
  long lStack_60;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  code *pcStack_40;
  undefined8 uStack_38;
  
  pcStack_40 = (code *)0x0;
  pWStack_68 = this_ptr;
  lStack_60 = param_3;
  uStack_58 = param_2;
  uStack_54 = param_1;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(&uStack_50,param_5,2);
    uStack_38 = *(undefined8 *)(param_5 + 0x18);
    pcStack_40 = *(code **)(param_5 + 0x10);
  }
  pcStack_78 = (code *)0x0;
  apuStack_88[0] = rea_operator_new(0x38);
  pcVar4 = pcStack_40;
  uVar1 = apuStack_88[0][3];
  uVar2 = apuStack_88[0][4];
  apuStack_88[0][5] = 0;
  uVar3 = apuStack_88[0][6];
  *apuStack_88[0] = pWStack_68;
  apuStack_88[0][1] = lStack_60;
  *(undefined1 *)(apuStack_88[0] + 2) = uStack_58;
  *(undefined4 *)((long)apuStack_88[0] + 0x14) = uStack_54;
  apuStack_88[0][3] = uStack_50;
  apuStack_88[0][4] = uStack_48;
  pcStack_40 = (code *)0x0;
  apuStack_88[0][5] = pcVar4;
  apuStack_88[0][6] = uStack_38;
  pcStack_70 = FUN_00110d50;
  pcStack_78 = FUN_0010ec20;
  uStack_50 = uVar1;
  uStack_48 = uVar2;
  uStack_38 = uVar3;
  recv_more(this_ptr,param_3 + 4,apuStack_88);
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(apuStack_88,apuStack_88,3);
  }
  if (pcStack_40 != (code *)0x0) {
    (*pcStack_40)(&uStack_50,&uStack_50,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 23  00106fd0  gettimeofday
// ------------------------------------------------------------------
int rea_gettimeofday(timeval * __tv, __timezone_ptr_t __tz)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_gettimeofday_003250c0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 24  00106fe0  __cxa_rethrow
// ------------------------------------------------------------------
void rea___cxa_rethrow(void)
{
  (*(code *)PTR___cxa_rethrow_003250c8)();
  return;
}





// ------------------------------------------------------------------
// IDX 25  00106ff0  WSConn__exit
// ------------------------------------------------------------------
void rea_WSConn__exit(WSConn * this_ptr)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  _Rb_tree_node_base *p_Var2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 *puVar10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  undefined *puVar14;
  long lVar15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  bool bVar19;
  code *pcVar20;
  uint uVar21;
  uint uVar22;
  undefined1 auVar23 [16];
  int aiStack_a8 [4];
  undefined8 *apuStack_98 [2];
  code *pcStack_88;
  undefined *puStack_80;
  void *pvStack_78;
  undefined8 uStack_70;
  code *pcStack_68;
  undefined *puStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined *puStack_40;
  
  pcStack_88 = (code *)0x0;
  apuStack_98[0] = rea_operator_new(8);
  lVar15 = *(long *)(this_ptr + 0x38);
  *apuStack_98[0] = this_ptr;
  puStack_80 = PTR__M_invoke_00324f38;
  pcStack_88 = (code *)PTR__M_manager_00324ec0;
  if (*(char *)(lVar15 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar15 + 0x88) = 1;
  pcStack_68 = (code *)0x0;
  if (pcStack_88 != (code *)0x0) {
    (*pcStack_88)(&pvStack_78,apuStack_98,2);
    pcStack_68 = pcStack_88;
    puStack_60 = puStack_80;
  }
  pcStack_48 = (code *)0x0;
  puVar10 = rea_operator_new(0x20);
  pcVar20 = pcStack_68;
  puVar10[2] = 0;
  pvVar5 = (void *)*puVar10;
  uVar6 = puVar10[1];
  *puVar10 = pvStack_78;
  puVar10[1] = uStack_70;
  pcStack_68 = (code *)0x0;
  uVar7 = puVar10[3];
  puVar10[2] = pcVar20;
  puVar10[3] = puStack_60;
  puVar14 = PTR__M_manager_00324f88;
  uStack_58 = *(undefined8 *)(lVar15 + 0x90);
  uVar8 = *(undefined8 *)(lVar15 + 0x98);
  pcStack_48 = *(code **)(lVar15 + 0xa0);
  *(undefined8 **)(lVar15 + 0x90) = puVar10;
  *(undefined8 *)(lVar15 + 0x98) = uStack_50;
  *(undefined **)(lVar15 + 0xa0) = puVar14;
  puStack_40 = *(undefined **)(lVar15 + 0xa8);
  *(undefined **)(lVar15 + 0xa8) = PTR__M_invoke_00324fe0;
  pvStack_78 = pvVar5;
  uStack_70 = uVar6;
  puStack_60 = (undefined *)uVar7;
  uStack_50 = uVar8;
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  if (pcStack_68 != (code *)0x0) {
    (*pcStack_68)(&pvStack_78,&pvStack_78,3);
  }
  aiStack_a8[0] = *(int *)(lVar15 + 0x40);
  cVar3 = *(char *)(lVar15 + 0x88);
  lVar15 = *(long *)(lVar15 + 0x38);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == (_Rb_tree_node_base *)0x0) {
LAB_0010cb60:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, aiStack_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c2da;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c2da:
    if ((p_Var12 == p_Var18) || (p_Var13 = p_Var12, aiStack_a8[0] < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cb60;
    do {
      while (p_Var16 = p_Var17, aiStack_a8[0] <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c30a;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c30a:
    if ((p_Var12 == p_Var16) || (aiStack_a8[0] < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = rea_operator_new(0x28);
      if (p_Var17 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = aiStack_a8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var17 = p_Var12;
  p_Var13 = p_Var16;
  uVar9 = uVar21;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var18 = p_Var17, aiStack_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var13 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c37a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c37a:
    if ((p_Var16 != p_Var18) && (p_Var17 = p_Var16, *(int *)(p_Var18 + 0x20) <= aiStack_a8[0])) {
      do {
        while (p_Var13 = p_Var12, aiStack_a8[0] <= *(int *)(p_Var13 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
          p_Var17 = p_Var13;
          if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c3aa;
        }
        p_Var18 = p_Var13 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var13 = p_Var17;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c3aa:
      if ((p_Var16 == p_Var13) || (aiStack_a8[0] < *(int *)(p_Var13 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = aiStack_a8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var13,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
        p_Var17 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
        p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
        if (p_Var17 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var17)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var17 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var17,p_Var16);
          *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
          p_Var13 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var13 + 0x24);
    }
  }
  uVar22 = uVar9 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffe;
  }
  if (uVar21 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,aiStack_a8);
  }
  else {
    p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var13 = p_Var16;
    p_Var17 = p_Var16;
    if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010ca20:
      p_Var12 = rea_operator_new(0x28);
      if (p_Var12 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = aiStack_a8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var1,p_Var17,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
      p_Var17 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var12);
      }
      else {
        bVar19 = true;
        if ((p_Var17 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var13)) {
          bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var16);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var17 = p_Var12;
      }
    }
    else {
      do {
        while (p_Var17 = p_Var12, aiStack_a8[0] <= *(int *)(p_Var17 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var13 = p_Var17;
          if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c412;
        }
        p_Var18 = p_Var17 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var17 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c412:
      if ((p_Var16 == p_Var17) || (aiStack_a8[0] < *(int *)(p_Var17 + 0x20))) goto LAB_0010ca20;
    }
    *(uint *)(p_Var17 + 0x24) = uVar22;
  }
  if (pcStack_88 != (code *)0x0) {
    (*pcStack_88)(apuStack_98,apuStack_98,3);
  }
  pcStack_68 = (code *)0x0;
  pvStack_78 = rea_operator_new(1);
  lVar15 = *(long *)(this_ptr + 0x38);
  puStack_60 = PTR__M_invoke_00324fd8;
  pcStack_68 = (code *)PTR__M_manager_00324ef8;
  if (*(char *)(lVar15 + 0x5a) != '\0') {
    rea_fwrite("close(): send_flag != false\n",1,0x1c,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar10 = *(undefined8 **)(lVar15 + 0x60);
  *(undefined1 *)(lVar15 + 0x5a) = 1;
  *(undefined8 *)(lVar15 + 0x60) = 0;
  if (puVar10 != (undefined8 *)0x0) {
    if ((void *)*puVar10 != (void *)0x0) {
      rea_operator_delete((void *)*puVar10);
    }
    rea_operator_delete(puVar10);
  }
  pcStack_48 = (code *)0x0;
  if (pcStack_68 == (code *)0x0) {
    pcVar20 = (code *)0x0;
    puVar14 = puStack_40;
  }
  else {
    (*pcStack_68)(&uStack_58,&pvStack_78,2);
    puVar14 = puStack_60;
    pcVar20 = pcStack_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0x68);
  uVar7 = *(undefined8 *)(lVar15 + 0x70);
  pcStack_48 = *(code **)(lVar15 + 0x78);
  *(undefined8 *)(lVar15 + 0x68) = uStack_58;
  *(undefined8 *)(lVar15 + 0x70) = uStack_50;
  puStack_40 = *(undefined **)(lVar15 + 0x80);
  *(code **)(lVar15 + 0x78) = pcVar20;
  *(undefined **)(lVar15 + 0x80) = puVar14;
  uStack_58 = uVar6;
  uStack_50 = uVar7;
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  cVar3 = *(char *)(lVar15 + 0x5a);
  iVar4 = *(int *)(lVar15 + 0x40);
  lVar15 = *(long *)(lVar15 + 0x38);
  apuStack_98[0] = (undefined8 *)CONCAT44(apuStack_98[0]._4_4_,iVar4);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == (_Rb_tree_node_base *)0x0) {
LAB_0010cb40:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, iVar4 <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c58a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c58a:
    if ((p_Var18 == p_Var12) || (p_Var13 = p_Var12, iVar4 < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cb40;
    do {
      while (p_Var16 = p_Var17, iVar4 <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c5ba;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c5ba:
    if ((p_Var16 == p_Var12) || (iVar4 < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = rea_operator_new(0x28);
      if (p_Var17 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = (int)apuStack_98[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var17 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  uVar9 = uVar21;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    p_Var13 = p_Var12;
    p_Var16 = p_Var17;
    do {
      while (p_Var18 = p_Var13, (int)apuStack_98[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c62a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c62a:
    if ((p_Var18 != p_Var17) && (p_Var13 = p_Var17, *(int *)(p_Var18 + 0x20) <= (int)apuStack_98[0])
       ) {
      do {
        while (p_Var16 = p_Var12, (int)apuStack_98[0] <= *(int *)(p_Var16 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
          p_Var13 = p_Var16;
          if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c65a;
        }
        p_Var18 = p_Var16 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var16 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c65a:
      if ((p_Var16 == p_Var17) || ((int)apuStack_98[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = (int)apuStack_98[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var16,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
        p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
        if (p_Var13 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var17 != p_Var13)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var17);
          *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
          p_Var16 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar22 = uVar9 | 2;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffd;
  }
  if (uVar21 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,(int *)apuStack_98);
    goto LAB_0010c6db;
  }
  p_Var12 = p_Var17;
  if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010cab0:
    p_Var13 = rea_operator_new(0x28);
    if (p_Var13 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var13 = 0;
      *(undefined8 *)(p_Var13 + 8) = 0;
      *(undefined8 *)(p_Var13 + 0x10) = 0;
      *(undefined8 *)(p_Var13 + 0x18) = 0;
      *(undefined4 *)(p_Var13 + 0x24) = 0;
      *(int *)(p_Var13 + 0x20) = (int)apuStack_98[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var1,p_Var12,p_Var13 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
    p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
    p_Var12 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
    if (p_Var16 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var13);
    }
    else {
      bVar19 = true;
      if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var17 != p_Var16)) {
        bVar19 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var13,p_Var16,p_Var17);
      *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
      p_Var12 = p_Var13;
    }
  }
  else {
    p_Var13 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var16 = p_Var17;
    do {
      while (p_Var12 = p_Var13, (int)apuStack_98[0] <= *(int *)(p_Var12 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
        p_Var16 = p_Var12;
        if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c6c2;
      }
      p_Var18 = p_Var12 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var18;
      p_Var12 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c6c2:
    if ((p_Var12 == p_Var17) || ((int)apuStack_98[0] < *(int *)(p_Var12 + 0x20))) goto LAB_0010cab0;
  }
  *(uint *)(p_Var12 + 0x24) = uVar22;
LAB_0010c6db:
  if (pcStack_68 != (code *)0x0) {
    (*pcStack_68)(&pvStack_78,&pvStack_78,3);
  }
  pcStack_68 = (code *)0x0;
  pvStack_78 = rea_operator_new(1);
  lVar15 = *(long *)(this_ptr + 0x38);
  pcStack_48 = (code *)0x0;
  puStack_60 = PTR__M_invoke_00324fd0;
  pcStack_68 = (code *)PTR__M_manager_00324fc0;
  if (PTR__M_manager_00324fc0 == (undefined *)0x0) {
    pcVar20 = (code *)0x0;
    puVar14 = puStack_40;
  }
  else {
    std___Function_base___Base_manager_WSConn__exit__lambda__3___M_manager_______________(&uStack_58,&pvStack_78,2);
    puVar14 = puStack_60;
    pcVar20 = pcStack_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0xb0);
  uVar7 = *(undefined8 *)(lVar15 + 0xb8);
  pcStack_48 = *(code **)(lVar15 + 0xc0);
  *(undefined8 *)(lVar15 + 0xb0) = uStack_58;
  *(undefined8 *)(lVar15 + 0xb8) = uStack_50;
  puStack_40 = *(undefined **)(lVar15 + 200);
  *(code **)(lVar15 + 0xc0) = pcVar20;
  *(undefined **)(lVar15 + 200) = puVar14;
  uStack_58 = uVar6;
  uStack_50 = uVar7;
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
    pcVar20 = pcStack_68;
  }
  if (pcVar20 != (code *)0x0) {
    (*pcVar20)(&pvStack_78,&pvStack_78,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 26  00107000  deflate
// ------------------------------------------------------------------
undefined8 rea_deflate(void)
{
  (*(code *)PTR_deflate_003250d8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 27  00107010  read
// ------------------------------------------------------------------
ssize_t rea_read(int __fd, void * __buf, size_t __nbytes)
{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_003250e0)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 28  00107020  TcpClient__dtor_TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__dtor_TcpClient(TcpClient * this_ptr)
{
  (*(code *)PTR__TcpClient_003250e8)();
  return;
}





// ------------------------------------------------------------------
// IDX 29  00107030  EventLoop2__exit
// ------------------------------------------------------------------
void rea_EventLoop2__exit(EventLoop2 * this_ptr, int param_1)
{
  *(int *)(this_ptr + 0x58) = param_1;
  this_ptr[0x54] = (EventLoop2)0x0;
  return;
}





// ------------------------------------------------------------------
// IDX 30  00107040  std___Rb_tree_decrement
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_decrement(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_decrement_003250f8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 31  00107050  std__string___Rep___S_create
// ------------------------------------------------------------------
undefined8 rea_std__string___Rep___S_create(ulong param_1, ulong param_2, allocator * param_3)
{
  (*(code *)PTR__S_create_00325100)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 32  00107060  UnixClient__dtor_UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__dtor_UnixClient(UnixClient * this_ptr)
{
  (*(code *)PTR__UnixClient_00325108)();
  return;
}





// ------------------------------------------------------------------
// IDX 33  00107070  std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char________________
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char(long * param_1, void * param_2, void * param_3, void * param_4)
{
  void *pvVar1;
  size_t sVar2;
  size_t __n;
  void *pvVar3;
  ulong uVar4;
  size_t sVar5;
  ulong uVar6;
  void *__src;
  bool bVar7;
  
  if (param_3 == param_4) {
    return;
  }
  pvVar3 = (void *)param_1[1];
  __n = (long)param_4 - (long)param_3;
  if (__n <= (ulong)(param_1[2] - (long)pvVar3)) {
    uVar6 = (long)pvVar3 - (long)param_2;
    if (__n < uVar6) {
      __src = (void *)((long)pvVar3 - __n);
      pvVar1 = pvVar3;
      if ((long)pvVar3 - (long)__src != 0) {
        pvVar1 = rea_memmove(pvVar3,__src,(long)pvVar3 - (long)__src);
        pvVar3 = (void *)param_1[1];
      }
      sVar2 = (long)__src - (long)param_2;
      param_1[1] = (long)pvVar3 + __n;
      if (sVar2 != 0) {
        rea_memmove((void *)((long)pvVar1 - sVar2),param_2,sVar2);
        if (__n == 0) {
          return;
        }
        goto LAB_00116338;
      }
    }
    else {
      pvVar1 = (void *)((long)param_3 + uVar6);
      if ((long)param_4 - (long)pvVar1 != 0) {
        rea_memmove(pvVar3,pvVar1,(long)param_4 - (long)pvVar1);
        pvVar3 = (void *)param_1[1];
      }
      pvVar3 = (void *)((long)pvVar3 + (__n - uVar6));
      param_1[1] = (long)pvVar3;
      if (uVar6 != 0) {
        rea_memmove(pvVar3,param_2,uVar6);
        pvVar3 = (void *)param_1[1];
      }
      __n = (long)pvVar1 - (long)param_3;
      param_1[1] = (long)pvVar3 + uVar6;
    }
    if (__n == 0) {
      return;
    }
LAB_00116338:
    rea_memmove(param_2,param_3,__n);
    return;
  }
  pvVar1 = (void *)*param_1;
  uVar6 = (long)pvVar3 - (long)pvVar1;
  if (~uVar6 < __n) {
    rea_std____throw_length_error("vector___M_range_insert");
  }
  else {
    uVar4 = __n;
    if (__n <= uVar6) {
      uVar4 = uVar6;
    }
    bVar7 = CARRY8(uVar6,uVar4);
    uVar4 = uVar6 + uVar4;
    uVar6 = 0xffffffffffffffff;
    if ((!bVar7) && (uVar6 = uVar4, uVar4 == 0)) {
      uVar6 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_00116398;
    }
  }
  pvVar3 = rea_operator_new(uVar6);
  pvVar1 = (void *)*param_1;
LAB_00116398:
  sVar5 = (long)param_2 - (long)pvVar1;
  sVar2 = 0;
  if (sVar5 != 0) {
    rea_memmove(pvVar3,pvVar1,sVar5);
    sVar2 = sVar5;
  }
  pvVar1 = (void *)(sVar2 + (long)pvVar3);
  if (__n != 0) {
    pvVar1 = rea_memmove(pvVar1,param_3,__n);
  }
  sVar5 = param_1[1] - (long)param_2;
  sVar2 = 0;
  if (sVar5 != 0) {
    rea_memmove((void *)(__n + (long)pvVar1),param_2,sVar5);
    sVar2 = sVar5;
  }
  if ((void *)*param_1 != (void *)0x0) {
    rea_operator_delete((void *)*param_1);
  }
  *param_1 = (long)pvVar3;
  param_1[1] = (long)(__n + (long)pvVar1) + sVar2;
  param_1[2] = uVar6 + (long)pvVar3;
  return;
}





// ------------------------------------------------------------------
// IDX 34  00107080  print_stack
// ------------------------------------------------------------------
void rea_print_stack(void)
{
  char *__s;
  int iVar1;
  void *__ptr;
  size_t __n;
  long lVar2;
  undefined1 auStack_348 [808];
  
  iVar1 = rea_backtrace(auStack_348,100);
  __ptr = (void *)rea_backtrace_symbols(auStack_348,iVar1);
  rea_write(2,"backtrace:",10);
  rea_write(2,"\n",1);
  rea_write(2,"<<<<<",5);
  rea_write(2,"\n",1);
  if (__ptr != (void *)0x0) {
    lVar2 = 0;
    if (0 < iVar1) {
      do {
        __s = *(char **)((long)__ptr + lVar2 * 8);
        lVar2 = lVar2 + 1;
        __n = rea_strlen(__s);
        rea_write(2,__s,__n);
        rea_write(2,"\n",1);
      } while ((int)lVar2 < iVar1);
    }
    rea_free(__ptr);
  }
  rea_write(2,">>>>>",5);
  rea_write(2,"\n",1);
  return;
}





// ------------------------------------------------------------------
// IDX 35  00107090  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup2(string * this_ptr, string * param_1)
{
  (*(code *)PTR_string_00325120)();
  return;
}





// ------------------------------------------------------------------
// IDX 36  001070a0  setsockopt
// ------------------------------------------------------------------
int rea_setsockopt(int __fd, int __level, int __optname, void * __optval, socklen_t __optlen)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setsockopt_00325128)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 37  001070b0  PyString_FromStringAndSize
// ------------------------------------------------------------------
undefined8 rea_PyString_FromStringAndSize(...)
{
  (*(code *)PTR_PyString_FromStringAndSize_00325130)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 38  001070c0  vector<std__pair<EventHandler*,std__function<void
// ------------------------------------------------------------------
undefined8 rea_vector_std__pair_EventHandler__std__function_void(undefined8 * param_x0, undefined8 * this_ptr)
{
  (*(code *)PTR__vector_00325138)();
  return;
}





// ------------------------------------------------------------------
// IDX 39  001070d0  TcpConn__idle_proc
// ------------------------------------------------------------------
void rea_TcpConn__idle_proc(TcpConn * this_ptr)
{
  (*(code *)PTR_idle_proc_00325140)();
  return;
}





// ------------------------------------------------------------------
// IDX 40  001070e0  PyLong_AsLong
// ------------------------------------------------------------------
undefined8 rea_PyLong_AsLong(...)
{
  (*(code *)PTR_PyLong_AsLong_00325148)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 41  001070f0  TcpConn__send_proc
// ------------------------------------------------------------------
void rea_TcpConn__send_proc(TcpConn * this_ptr)
{
  (*(code *)PTR_send_proc_00325150)();
  return;
}





// ------------------------------------------------------------------
// IDX 42  00107100  PyString_Size
// ------------------------------------------------------------------
undefined8 rea_PyString_Size(...)
{
  (*(code *)PTR_PyString_Size_00325158)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 43  00107110  inflateInit2_
// ------------------------------------------------------------------
void rea_inflateInit2(void)
{
  (*(code *)PTR_inflateInit2__00325160)();
  return;
}





// ------------------------------------------------------------------
// IDX 44  00107120  bzero
// ------------------------------------------------------------------
void rea_bzero(void * __s, size_t __n)
{
  (*(code *)PTR_bzero_00325168)();
  return;
}





// ------------------------------------------------------------------
// IDX 45  00107130  strnlen
// ------------------------------------------------------------------
size_t rea_strnlen(char * __string, size_t __maxlen)
{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strnlen_00325170)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 46  00107140  PyArg_ParseTuple
// ------------------------------------------------------------------
undefined8 rea_PyArg_ParseTuple(...)
{
  (*(code *)PTR_PyArg_ParseTuple_00325178)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 47  00107150  inflate
// ------------------------------------------------------------------
undefined8 rea_inflate(...)
{
  (*(code *)PTR_inflate_00325180)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 48  00107160  backtrace_symbols
// ------------------------------------------------------------------
undefined8 rea_backtrace_symbols(...)
{
  (*(code *)PTR_backtrace_symbols_00325188)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 49  00107170  free
// ------------------------------------------------------------------
void rea_free(void * __ptr)
{
  (*(code *)PTR_free_00325190)();
  return;
}





// ------------------------------------------------------------------
// IDX 50  00107180  strlen
// ------------------------------------------------------------------
size_t rea_strlen(char * __s)
{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00325198)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 51  00107190  std__string___Rep___M_destroy
// ------------------------------------------------------------------
void rea_std__string___Rep___M_destroy(allocator * param_1)
{
  (*(code *)PTR__M_destroy_003251a0)();
  return;
}





// ------------------------------------------------------------------
// IDX 52  001071a0  __xstat
// ------------------------------------------------------------------
int rea___xstat(int __ver, char * __filename, stat * __stat_buf)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR___xstat_003251a8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 53  001071b0  deflateEnd
// ------------------------------------------------------------------
void rea_deflateEnd(...)
{
  (*(code *)PTR_deflateEnd_003251b0)();
  return;
}





// ------------------------------------------------------------------
// IDX 54  001071c0  std_________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple_________________
// ------------------------------------------------------------------
void rea_std_________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple(void)
{
  (*(code *)
    PTR__M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple__003251b8
  )();
  return;
}





// ------------------------------------------------------------------
// IDX 55  001071d0  listen
// ------------------------------------------------------------------
int rea_listen(int __fd, int __n)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_listen_003251c0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 56  001071e0  TcpConn__TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__TcpConn(TcpConn * this_ptr, int param_1, string * param_2, string * param_3, EventHandler * param_4)
{
  (*(code *)PTR_TcpConn_003251c8)();
  return;
}





// ------------------------------------------------------------------
// IDX 57  001071f0  WSConn__read_data
// ------------------------------------------------------------------
void rea_WSConn__read_data(WSConn * this_ptr, undefined4 param_1, undefined1 param_2, undefined8 param_3, long param_5)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *apuStack_88 [2];
  code *pcStack_78;
  code *pcStack_70;
  WSConn *pWStack_68;
  undefined8 uStack_60;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  code *pcStack_40;
  undefined8 uStack_38;
  
  pcStack_40 = (code *)0x0;
  pWStack_68 = this_ptr;
  uStack_60 = param_3;
  uStack_58 = param_2;
  uStack_54 = param_1;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(&uStack_50,param_5,2);
    uStack_38 = *(undefined8 *)(param_5 + 0x18);
    pcStack_40 = *(code **)(param_5 + 0x10);
  }
  pcStack_78 = (code *)0x0;
  apuStack_88[0] = rea_operator_new(0x38);
  pcVar4 = pcStack_40;
  uVar1 = apuStack_88[0][3];
  uVar2 = apuStack_88[0][4];
  apuStack_88[0][5] = 0;
  uVar3 = apuStack_88[0][6];
  *apuStack_88[0] = pWStack_68;
  apuStack_88[0][1] = uStack_60;
  *(undefined1 *)(apuStack_88[0] + 2) = uStack_58;
  *(undefined4 *)((long)apuStack_88[0] + 0x14) = uStack_54;
  apuStack_88[0][3] = uStack_50;
  apuStack_88[0][4] = uStack_48;
  pcStack_40 = (code *)0x0;
  apuStack_88[0][5] = pcVar4;
  apuStack_88[0][6] = uStack_38;
  pcStack_70 = FUN_00111100;
  pcStack_78 = FUN_0010e980;
  uStack_50 = uVar1;
  uStack_48 = uVar2;
  uStack_38 = uVar3;
  recv_more(this_ptr,param_3,apuStack_88);
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(apuStack_88,apuStack_88,3);
  }
  if (pcStack_40 != (code *)0x0) {
    (*pcStack_40)(&uStack_50,&uStack_50,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 58  00107200  strrchr
// ------------------------------------------------------------------
char * rea_strrchr(char * __s, int __c)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strrchr_003251d8)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 59  00107210  std__string__insert
// ------------------------------------------------------------------
undefined8 rea_std__string__insert(ulong param_1, char * param_2, ulong param_3)
{
  (*(code *)PTR_insert_003251e0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 60  00107220  std___Rb_tree_increment
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_increment(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_increment_003251e8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 61  00107230  epoll_create1
// ------------------------------------------------------------------
int rea_epoll_create1(int __flags)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_epoll_create1_003251f0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 62  00107240  std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_char__std__string________________
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_char__std__string(long * param_1, undefined1 * param_2, undefined1 * param_3, undefined1 * param_4)
{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  void *__dest;
  undefined1 *puVar4;
  ulong uVar5;
  size_t sVar6;
  long lVar7;
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
  uVar9 = (long)param_4 - (long)param_3;
  if (uVar9 <= (ulong)(param_1[2] - (long)puVar12)) {
    uVar14 = (long)puVar12 - (long)param_2;
    if (uVar9 < uVar14) {
      puVar3 = puVar12 + -uVar9;
      puVar4 = puVar12;
      if ((long)puVar12 - (long)puVar3 != 0) {
        puVar4 = rea_memmove(puVar12,puVar3,(long)puVar12 - (long)puVar3);
        puVar12 = (undefined1 *)param_1[1];
      }
      sVar8 = (long)puVar3 - (long)param_2;
      param_1[1] = (long)(puVar12 + uVar9);
      if (sVar8 != 0) {
        rea_memmove(puVar4 + -sVar8,param_2,sVar8);
      }
      if ((long)uVar9 < 1) {
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
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(param_2 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar14);
      lVar7 = uVar9 + uVar14 * -0x10;
      if (uVar9 == uVar5) {
        return;
      }
    }
    else {
      puVar4 = param_3 + uVar14;
      uVar5 = (long)param_4 - (long)puVar4;
      if (0 < (long)uVar5) {
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
            uVar2 = *(undefined8 *)((long)(puVar4 + lVar7) + 8);
            uVar13 = uVar13 + 1;
            *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(puVar4 + lVar7);
            *(undefined8 *)((long)(puVar12 + lVar7) + 8) = uVar2;
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
      param_1[1] = (long)puVar12;
      if (uVar14 != 0) {
        rea_memmove(puVar12,param_2,uVar14);
        puVar12 = (undefined1 *)param_1[1];
      }
      uVar9 = (long)puVar4 - (long)param_3;
      param_1[1] = (long)(puVar12 + uVar14);
      if ((long)uVar9 < 1) {
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
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(param_2 + lVar7) + 8) = uVar2;
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
  uVar14 = (long)puVar12 - (long)__src;
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
      __dest = (void *)0x0;
      goto LAB_0010d326;
    }
  }
  __dest = rea_operator_new(uStack_48);
  __src = (void *)*param_1;
LAB_0010d326:
  sVar6 = (long)param_2 - (long)__src;
  sVar8 = 0;
  if (sVar6 != 0) {
    rea_memmove(__dest,__src,sVar6);
    sVar8 = sVar6;
  }
  puVar12 = (undefined1 *)(sVar8 + (long)__dest);
  if (0 < (long)uVar9) {
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
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(puVar12 + lVar7) + 8) = uVar2;
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
  sVar6 = param_1[1] - (long)param_2;
  sVar8 = 0;
  if (sVar6 != 0) {
    puVar12 = rea_memmove(puVar12,param_2,sVar6);
    sVar8 = sVar6;
  }
  if ((void *)*param_1 != (void *)0x0) {
    rea_operator_delete((void *)*param_1);
  }
  *param_1 = (long)__dest;
  param_1[1] = (long)(puVar12 + sVar8);
  param_1[2] = (long)__dest + uStack_48;
  return;
}





// ------------------------------------------------------------------
// IDX 63  00107250  std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root___________
// ------------------------------------------------------------------
arr_undefined1_16 rea_std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root(_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root * this_ptr, WSConn * * param_1, unique_ptr * param_2)
{
  _Rb_tree_node_base *p_Var1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  bool bVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  (*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = rea_operator_new(0x30);
  if ((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) != (_Rb_tree_node_base *)0x0) {
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 8) = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x10) = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x18) = 0;
    *(undefined4 *)(*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = 0;
    *(WSConn **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) = *param_1;
    uVar2 = *(undefined8 *)param_2;
    *(undefined8 *)param_2 = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) = uVar2;
  }
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 8);
  p_Var6 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010be18:
    p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
    if (p_Var5 == p_Var6) goto LAB_0010be50;
    p_Var5 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var6);
    if (*(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) <= *(ulong *)(p_Var5 + 0x20)) goto LAB_0010bde1;
  }
  else {
    uVar3 = *(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20);
    p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
    do {
      p_Var6 = p_Var5;
      uVar4 = *(ulong *)(p_Var6 + 0x20);
      if (uVar3 < uVar4) {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
      }
      else {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
    } while (p_Var5 != (_Rb_tree_node_base *)0x0);
    if (uVar3 < uVar4) goto LAB_0010be18;
    p_Var5 = p_Var6;
    if (uVar3 <= uVar4) goto LAB_0010bde1;
  }
  p_Var5 = p_Var6;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = (_Rb_tree_node_base *)0x0;
LAB_0010bde1:
    if (*(long **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) + 8))();
    }
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) = 0;
    rea_operator_delete((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)));
    (*(undefined8 *)((uint8_t *)&auVar8 + 0x8)) = 0;
    (*(undefined8 *)((uint8_t *)&auVar8 + 0x0)) = p_Var5;
    return rea_arr_from<arr_undefined1_16>(auVar8);
  }
LAB_0010be50:
  if (p_Var1 == p_Var5) {
    bVar7 = true;
  }
  else {
    bVar7 = *(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) < *(ulong *)(p_Var5 + 0x20);
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar7,(*(undefined8 *)((uint8_t *)&auVar9 + 0x0)),p_Var5,p_Var1);
  *(long *)(this_ptr + 0x28) = *(long *)(this_ptr + 0x28) + 1;
  (*(undefined8 *)((uint8_t *)&auVar9 + 0x8)) = 1;
  return rea_arr_from<arr_undefined1_16>(auVar9);
}





// ------------------------------------------------------------------
// IDX 64  00107260  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup3(string * this_ptr, char * param_1, allocator * param_2)
{
  (*(code *)PTR_string_00325208)();
  return;
}





// ------------------------------------------------------------------
// IDX 65  00107270  epoll_ctl
// ------------------------------------------------------------------
int rea_epoll_ctl(int __epfd, int __op, int __fd, epoll_event * __event)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_epoll_ctl_00325210)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 66  00107280  sigaction
// ------------------------------------------------------------------
int rea_sigaction(int __sig, sigaction * __act, sigaction * __oact)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sigaction_00325218)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 67  00107290  getifaddrs
// ------------------------------------------------------------------
void rea_getifaddrs(...)
{
  (*(code *)PTR_getifaddrs_00325220)();
  return;
}





// ------------------------------------------------------------------
// IDX 68  001072a0  std__terminate
// ------------------------------------------------------------------
void rea_std__terminate(void)
{
  (*(code *)PTR_terminate_00325228)();
  return;
}





// ------------------------------------------------------------------
// IDX 69  001072b0  vector<std__pair<EventHandler*,std__function<void
// ------------------------------------------------------------------
undefined8 rea_vector_std__pair_EventHandler__std__function_void__dup2(undefined8 * param_x0, undefined8 * param_1)
{
  (*(code *)PTR__M_emplace_back_aux<std__pair<EventHandler*,std__function<void()>>>_00325230)();
  return;
}





// ------------------------------------------------------------------
// IDX 70  001072c0  getsockopt
// ------------------------------------------------------------------
int rea_getsockopt(int __fd, int __level, int __optname, void * __optval, socklen_t * __optlen)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getsockopt_00325238)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 71  001072d0  UnixServer__dtor_UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__dtor_UnixServer(UnixServer * this_ptr)
{
  (*(code *)PTR__UnixServer_00325240)();
  return;
}





// ------------------------------------------------------------------
// IDX 72  001072e0  connect
// ------------------------------------------------------------------
int rea_connect(int __fd, sockaddr * __addr, socklen_t __len)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_connect_00325248)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 73  001072f0  std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char(vector_unsigned_char_std__allocator_unsigned_char * this_ptr, uchar * param_1)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  char cVar2;
  uchar *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  uint uVar7;
  ulong uVar8;
  void *__dest;
  size_t __n;
  long *plVar9;
  _Rb_tree_node_base *p_Var10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  void *__src;
  char *pcVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  undefined1 auVar22 [16];
  int aiStack_a0 [4];
  undefined8 uStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined8 uStack_78;
  vector_unsigned_char_std__allocator_unsigned_char *pvStack_68;
  
  puVar3 = *(uchar **)(this_ptr + 8);
  if (puVar3 != *(uchar **)(this_ptr + 0x10)) {
    if (puVar3 == (uchar *)0x0) {
      lVar13 = 0;
    }
    else {
      *puVar3 = *param_1;
      lVar13 = *(long *)(this_ptr + 8);
    }
    *(long *)(this_ptr + 8) = lVar13 + 1;
    return;
  }
  uVar8 = (long)puVar3 - *(long *)this_ptr;
  if (uVar8 != 0xffffffffffffffff) {
    uVar19 = 1;
    if (uVar8 != 0) {
      uVar19 = 0xffffffffffffffff;
      if (uVar8 <= uVar8 * 2) {
        uVar19 = uVar8 * 2;
      }
    }
    __dest = rea_operator_new(uVar19);
    __src = *(void **)this_ptr;
    __n = *(long *)(this_ptr + 8) - (long)__src;
    if ((uchar *)((long)__dest + __n) == (uchar *)0x0) {
      lVar13 = 0;
    }
    else {
      *(uchar *)((long)__dest + __n) = *param_1;
      __src = *(void **)this_ptr;
      __n = *(long *)(this_ptr + 8) - (long)__src;
      lVar13 = (long)__dest + __n;
    }
    if (__n != 0) {
      rea_memmove(__dest,__src,__n);
      __src = *(void **)this_ptr;
    }
    if (__src != (void *)0x0) {
      rea_operator_delete(__src);
    }
    *(void **)this_ptr = __dest;
    *(long *)(this_ptr + 8) = lVar13 + 1;
    *(ulong *)(this_ptr + 0x10) = (long)__dest + uVar19;
    return;
  }
  pcVar18 = "vector___M_emplace_back_aux";
  rea_std____throw_length_error("vector___M_emplace_back_aux");
  puVar4 = *(undefined8 **)param_1;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  if (puVar4 == (undefined8 *)0x0) {
    return;
  }
  lVar13 = **(long **)pcVar18;
  pvStack_68 = this_ptr;
  if (*(char *)(lVar13 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar13 + 0x88) = 1;
  pcStack_80 = (code *)0x0;
  plVar9 = rea_operator_new(8);
  *plVar9 = lVar13;
  puVar6 = PTR__M_manager_00324f68;
  uVar5 = *(undefined8 *)(lVar13 + 0x98);
  uStack_90 = *(undefined8 *)(lVar13 + 0x90);
  *(undefined8 *)(lVar13 + 0x98) = uStack_88;
  pcStack_80 = *(code **)(lVar13 + 0xa0);
  *(undefined **)(lVar13 + 0xa0) = puVar6;
  uStack_78 = *(undefined8 *)(lVar13 + 0xa8);
  *(long **)(lVar13 + 0x90) = plVar9;
  *(undefined **)(lVar13 + 0xa8) = PTR__M_invoke_00324f40;
  uStack_88 = uVar5;
  if (pcStack_80 != (code *)0x0) {
    (*pcStack_80)(&uStack_90,&uStack_90,3);
  }
  aiStack_a0[0] = *(int *)(lVar13 + 0x40);
  cVar2 = *(char *)(lVar13 + 0x88);
  lVar13 = *(long *)(lVar13 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var15 = p_Var10;
  p_Var14 = p_Var12;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
LAB_00115e7b:
    lVar11 = 0;
    uVar20 = 0;
  }
  else {
    do {
      while (p_Var16 = p_Var15, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var15 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var14;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115e6a;
      }
      p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var14 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115e6a:
    if ((p_Var12 == p_Var16) || (p_Var15 = p_Var12, aiStack_a0[0] < *(int *)(p_Var16 + 0x20)))
    goto LAB_00115e7b;
    do {
      while (p_Var14 = p_Var10, *(int *)(p_Var14 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var14 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var16;
        p_Var14 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_0011603a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var15 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011603a:
    if ((p_Var12 == p_Var14) || (aiStack_a0[0] < *(int *)(p_Var14 + 0x20))) {
      p_Var10 = rea_operator_new(0x28);
      if (p_Var10 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = aiStack_a0[0];
      }
      { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar13 + 8),p_Var14,p_Var10 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
      p_Var15 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x8));
      p_Var14 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x0));
      if (p_Var15 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var15)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var15 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var15,p_Var12);
        *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
        p_Var14 = p_Var10;
      }
    }
    uVar20 = *(uint *)(p_Var14 + 0x24);
    lVar11 = 1;
  }
  lVar13 = lVar13 + (lVar11 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar13 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var10 = p_Var12;
  p_Var15 = p_Var14;
  uVar7 = uVar20;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var16 = p_Var10, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115eca;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var15 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115eca:
    if ((p_Var14 != p_Var16) && (p_Var10 = p_Var14, *(int *)(p_Var16 + 0x20) <= aiStack_a0[0])) {
      do {
        while (p_Var15 = p_Var12, *(int *)(p_Var15 + 0x20) < aiStack_a0[0]) {
          p_Var16 = p_Var15 + 0x18;
          p_Var12 = *(_Rb_tree_node_base **)p_Var16;
          p_Var15 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_00115efa;
        }
        p_Var12 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var10 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115efa:
      if ((p_Var14 == p_Var15) || (aiStack_a0[0] < *(int *)(p_Var15 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
        }
        { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var12 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
        p_Var10 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x8));
        p_Var15 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x0));
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar17 = true;
          if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var10)) {
            bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var10,p_Var14);
          *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
          p_Var15 = p_Var12;
        }
      }
      uVar7 = *(uint *)(p_Var15 + 0x24);
    }
  }
  uVar21 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar21 = uVar7 & 0xfffffffe;
  }
  if (uVar20 == uVar21) {
    _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_a0);
    goto LAB_00115ff3;
  }
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var15 = p_Var14;
  p_Var10 = p_Var14;
  if (*(_Rb_tree_node_base **)(lVar13 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116100:
    p_Var12 = rea_operator_new(0x28);
    if (p_Var12 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var12 = 0;
      *(undefined8 *)(p_Var12 + 8) = 0;
      *(undefined8 *)(p_Var12 + 0x10) = 0;
      *(undefined8 *)(p_Var12 + 0x18) = 0;
      *(undefined4 *)(p_Var12 + 0x24) = 0;
      *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
    }
    { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var12 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
    p_Var15 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x8));
    p_Var10 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x0));
    if (p_Var15 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var12);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var15)) {
        bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var15 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var15,p_Var14);
      *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
      p_Var10 = p_Var12;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var12, *(int *)(p_Var10 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var10 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var16;
        p_Var10 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_00115fda;
      }
      p_Var12 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var15 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115fda:
    if ((p_Var14 == p_Var10) || (aiStack_a0[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00116100;
  }
  *(uint *)(p_Var10 + 0x24) = uVar21;
LAB_00115ff3:
  if ((void *)*puVar4 != (void *)0x0) {
    rea_operator_delete((void *)*puVar4);
  }
  rea_operator_delete(puVar4);
  return;
}





// ------------------------------------------------------------------
// IDX 74  00107300  TcpConn__dtor_TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__dtor_TcpConn(TcpConn * this_ptr)
{
  (*(code *)PTR__TcpConn_00325258)();
  return;
}





// ------------------------------------------------------------------
// IDX 75  00107310  std____detail___List_node_base___M_hook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_hook(_List_node_base * param_1)
{
  (*(code *)PTR__M_hook_00325260)();
  return;
}





// ------------------------------------------------------------------
// IDX 76  00107320  Buffer__appendf
// ------------------------------------------------------------------
void rea_Buffer__appendf(char * param_1, undefined8 param_x1)
{
  undefined8 stack0x00000008;
  int iVar1;
  char in_AL;
  int iVar2;
  void *pvVar3;
  undefined8 in_RCX;
  undefined8 in_RDX;
  ulong uVar4;
  ulong extraout_RDX;
  size_t __n;
  ulong uVar5;
  char *in_RSI;
  void *pvVar6;
  undefined8 in_R8;
  undefined8 in_R9;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  void *pvStack_128;
  ulong uStack_120;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined1 *puStack_f8;
  undefined1 *puStack_f0;
  undefined1 auStack_e8 [16];
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_a8;
  undefined8 uStack_98;
  undefined8 uStack_88;
  undefined8 uStack_78;
  undefined8 uStack_68;
  undefined8 uStack_58;
  undefined8 uStack_48;
  
  if (in_AL != '\0') {
    uStack_b8 = in_XMM0_Qa;
    uStack_a8 = in_XMM1_Qa;
    uStack_98 = in_XMM2_Qa;
    uStack_88 = in_XMM3_Qa;
    uStack_78 = in_XMM4_Qa;
    uStack_68 = in_XMM5_Qa;
    uStack_58 = in_XMM6_Qa;
    uStack_48 = in_XMM7_Qa;
  }
  puStack_f8 = (void *)&stack0x00000008;
  puStack_f0 = auStack_e8;
  uStack_100 = 0x10;
  uStack_fc = 0x30;
  uStack_d8 = in_RDX;
  uStack_d0 = in_RCX;
  uStack_c8 = in_R8;
  uStack_c0 = in_R9;
  iVar2 = rea_vsnprintf((char *)0x0,0,in_RSI,&uStack_100);
  pvVar3 = *(void **)(param_1 + 8);
  pvVar6 = *(void **)param_1;
  __n = (long)pvVar3 - (long)pvVar6;
  iVar1 = (int)__n;
  uVar7 = iVar2 + iVar1;
  uVar8 = (ulong)uVar7;
  uVar9 = (ulong)(int)(uVar7 + 1);
  if (__n < uVar9) {
    uVar9 = uVar9 - __n;
    if (uVar9 == 0) goto LAB_00115994;
    if (uVar9 <= (ulong)(*(long *)(param_1 + 0x10) - (long)pvVar3)) {
      rea_memset(pvVar3,0,uVar9);
      *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + uVar9;
      goto LAB_00115994;
    }
    if (uVar9 <= ~__n) {
      uStack_120 = 0xffffffffffffffff;
      uVar8 = __n;
      if (__n <= uVar9) {
        uVar8 = uVar9;
      }
      if ((CARRY8(uVar8,__n)) || (uStack_120 = uVar8 + __n, uVar8 + __n != 0)) {
        pvStack_128 = rea_operator_new(uStack_120);
        pvVar6 = *(void **)param_1;
        __n = *(long *)(param_1 + 8) - (long)pvVar6;
      }
      else {
        uStack_120 = 0;
        pvStack_128 = (void *)0x0;
      }
      if (__n != 0) {
        rea_memmove(pvStack_128,pvVar6,__n);
      }
      pvVar3 = (void *)((long)pvStack_128 + __n);
      rea_memset(pvVar3,0,(uVar9 + (long)pvVar3) - (long)pvVar3);
      if (*(void **)param_1 != (void *)0x0) {
        rea_operator_delete(*(void **)param_1);
      }
      *(ulong *)(param_1 + 8) = uVar9 + (long)pvVar3;
      *(void **)param_1 = pvStack_128;
      *(ulong *)(param_1 + 0x10) = (long)pvStack_128 + uStack_120;
      goto LAB_00115994;
    }
LAB_00115c22:
    rea_std____throw_length_error("vector___M_default_append");
    uVar5 = extraout_RDX;
  }
  else {
    if (uVar9 < __n) {
      *(ulong *)(param_1 + 8) = uVar9 + (long)pvVar6;
    }
LAB_00115994:
    puStack_f8 = (void *)&stack0x00000008;
    uStack_100 = 0x10;
    puStack_f0 = auStack_e8;
    uStack_fc = 0x30;
    uVar8 = (ulong)(int)uVar7;
    rea_vsnprintf((char *)((long)iVar1 + *(long *)param_1),(long)(iVar2 + 1),in_RSI,&uStack_100);
    pvVar3 = *(void **)(param_1 + 8);
    pvVar6 = *(void **)param_1;
    uVar9 = (long)pvVar3 - (long)pvVar6;
    if (uVar8 <= uVar9) {
      if (uVar9 <= uVar8) {
        return;
      }
      *(ulong *)(param_1 + 8) = uVar8 + (long)pvVar6;
      return;
    }
    uVar8 = uVar8 - uVar9;
    if (uVar8 == 0) {
      return;
    }
    if (uVar8 <= (ulong)(*(long *)(param_1 + 0x10) - (long)pvVar3)) {
      rea_memset(pvVar3,0,uVar8);
      *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + uVar8;
      return;
    }
    if (~uVar9 < uVar8) goto LAB_00115c22;
    uVar4 = uVar9;
    if (uVar9 <= uVar8) {
      uVar4 = uVar8;
    }
    uVar5 = 0xffffffffffffffff;
    if ((!CARRY8(uVar4,uVar9)) && (uVar5 = uVar4 + uVar9, uVar4 + uVar9 == 0)) {
      uVar5 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_00115a5e;
    }
  }
  pvVar3 = rea_operator_new(uVar5);
  pvVar6 = *(void **)param_1;
  uVar9 = *(long *)(param_1 + 8) - (long)pvVar6;
LAB_00115a5e:
  if (uVar9 != 0) {
    rea_memmove(pvVar3,pvVar6,uVar9);
  }
  pvVar6 = (void *)((long)pvVar3 + uVar9);
  rea_memset(pvVar6,0,(uVar8 + (long)pvVar6) - (long)pvVar6);
  if (*(void **)param_1 != (void *)0x0) {
    rea_operator_delete(*(void **)param_1);
  }
  *(void **)param_1 = pvVar3;
  *(ulong *)(param_1 + 8) = uVar8 + (long)pvVar6;
  *(ulong *)(param_1 + 0x10) = uVar5 + (long)pvVar3;
  return;
}





// ------------------------------------------------------------------
// IDX 77  00107330  setcloexec
// ------------------------------------------------------------------
void rea_setcloexec(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,1);
  if ((int)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_fcntl(param_1,2,(ulong)(uVar1 | 1));
  return;
}





// ------------------------------------------------------------------
// IDX 78  00107340  EventLoop2__run
// ------------------------------------------------------------------
undefined4 rea_EventLoop2__run(EventLoop2 * this_ptr, long param_2)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  epoll_data_t *peVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  char cVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  int *piVar13;
  long *plVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  bool bVar18;
  long lVar19;
  _Rb_tree_node_base *p_Var20;
  _Rb_tree_node_base *p_Var21;
  undefined8 *puVar22;
  long *plVar23;
  long *plVar24;
  byte bVar25;
  undefined1 auVar26 [16];
  long *plStack_c8;
  _Rb_tree_node_base *p_Stack_c0;
  int iStack_b0;
  int iStack_ac;
  long *plStack_a0;
  epoll_event eStack_78;
  epoll_event eStack_68;
  code *pcStack_50;
  code *pcStack_48;
  
  if (this_ptr[0x54] != (EventLoop2)0x0) {
    peVar3 = &eStack_68.data;
    do {
      plStack_a0 = *(long **)(this_ptr + 0x10);
      plStack_c8 = *(long **)(this_ptr + 8);
      if (plStack_a0 == plStack_c8) {
        if (*(long *)(this_ptr + 0x28) == *(long *)(this_ptr + 0x20)) break;
      }
      else if (*(long *)(this_ptr + 0x28) == *(long *)(this_ptr + 0x20)) goto LAB_00116dc6;
      std_________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_________________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_________________(this_ptr + 8);
      plVar24 = *(long **)(this_ptr + 0x28);
      plVar23 = *(long **)(this_ptr + 0x20);
      for (plVar14 = plVar23; plVar14 != plVar24; plVar14 = plVar14 + 1) {
        if ((long *)*plVar14 != (long *)0x0) {
          (**(code **)(*(long *)*plVar14 + 0x18))();
        }
        *plVar14 = 0;
      }
      plStack_c8 = *(long **)(this_ptr + 8);
      *(long **)(this_ptr + 0x28) = plVar23;
      plStack_a0 = *(long **)(this_ptr + 0x10);
      if (plStack_c8 != plStack_a0) {
LAB_00116dc6:
        iStack_ac = 0;
        iStack_b0 = 1;
        do {
          lVar19 = ((long)iStack_ac + 1) * 0x30 + *plStack_c8;
          p_Var12 = *(_Rb_tree_node_base **)(lVar19 + 0x20);
          p_Stack_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          if (p_Var12 != p_Stack_c0) {
            do {
              uVar4 = *(uint *)(p_Var12 + 0x24);
              iVar10 = *(int *)(p_Var12 + 0x20);
              uVar8 = 0x11;
              eStack_68.events = 0;
              eStack_68.data.fd = 0;
              if ((uVar4 & 2) != 0) {
                eStack_68.events = 4;
                uVar8 = 0x15;
              }
              if ((uVar4 & 1) != 0) {
                eStack_68.events = uVar8;
              }
              (*(undefined4 *)((uint8_t *)&eStack_68 + 0x4)) = iVar10;
              iVar9 = rea_epoll_ctl(*(int *)(this_ptr + 0x50),iStack_b0,iVar10,&eStack_68);
              if (iVar9 != 0) {
                rea_perror("epoll_ctl");
              }
              lVar19 = *plStack_c8;
              p_Var1 = (_Rb_tree_node_base *)(lVar19 + 0x10);
              p_Var11 = *(_Rb_tree_node_base **)(lVar19 + 0x18);
              p_Var20 = p_Var1;
              p_Var21 = p_Var1;
              if (*(_Rb_tree_node_base **)(lVar19 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116ecb:
                p_Var11 = rea_operator_new(0x28);
                if (p_Var11 != (_Rb_tree_node_base *)0x0) {
                  *(undefined4 *)p_Var11 = 0;
                  *(undefined8 *)(p_Var11 + 8) = 0;
                  *(undefined8 *)(p_Var11 + 0x10) = 0;
                  *(undefined8 *)(p_Var11 + 0x18) = 0;
                  *(int *)(p_Var11 + 0x20) = iVar10;
                  *(undefined4 *)(p_Var11 + 0x24) = 0;
                }
                { auto &&__rea_tmp = (std______________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________________M_get_insert_hint_unique_pos_____________________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                      *)(lVar19 + 8),p_Var21,p_Var11 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
                p_Var20 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x8));
                p_Var21 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x0));
                if (p_Var20 == (_Rb_tree_node_base *)0x0) {
                  rea_operator_delete(p_Var11);
                }
                else {
                  bVar18 = true;
                  if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var20)) {
                    bVar18 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var20 + 0x20);
                  }
                  rea_std___Rb_tree_insert_and_rebalance(bVar18,p_Var11,p_Var20,p_Var1);
                  *(long *)(lVar19 + 0x30) = *(long *)(lVar19 + 0x30) + 1;
                  p_Var21 = p_Var11;
                }
              }
              else {
                do {
                  while (p_Var21 = p_Var11, iVar10 <= *(int *)(p_Var21 + 0x20)) {
                    p_Var11 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
                    p_Var20 = p_Var21;
                    if (*(_Rb_tree_node_base **)(p_Var21 + 0x10) == (_Rb_tree_node_base *)0x0)
                    goto LAB_00116ebb;
                  }
                  p_Var2 = p_Var21 + 0x18;
                  p_Var11 = *(_Rb_tree_node_base **)p_Var2;
                  p_Var21 = p_Var20;
                } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_00116ebb:
                if ((p_Var21 == p_Var1) || (iVar10 < *(int *)(p_Var21 + 0x20))) goto LAB_00116ecb;
              }
              *(uint *)(p_Var21 + 0x24) = uVar4;
              p_Var12 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var12);
            } while (p_Stack_c0 != p_Var12);
            lVar19 = ((long)iStack_ac + 1) * 0x30 + *plStack_c8;
            p_Stack_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          }
          std______________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                      *)(lVar19 + 8),*(_Rb_tree_node **)(lVar19 + 0x18));
          *(undefined8 *)(lVar19 + 0x18) = 0;
          *(undefined8 *)(lVar19 + 0x30) = 0;
          *(_Rb_tree_node_base **)(lVar19 + 0x20) = p_Stack_c0;
          *(_Rb_tree_node_base **)(lVar19 + 0x28) = p_Stack_c0;
          if (iStack_ac == 1) goto code_r0x00116fc4;
          iStack_b0 = 3;
          iStack_ac = 1;
        } while( true );
      }
LAB_00116fda:
      iVar10 = rea_epoll_wait(*(int *)(this_ptr + 0x50),&eStack_78,1,(int)(*(long *)(this_ptr + 0x60) / 1000));
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
            pcStack_50 = (code *)0x0;
            eStack_68.events = (uint32_t)*puVar17;
            (*(undefined4 *)((uint8_t *)&eStack_68 + 0x4)) = SUB84((ulong)*puVar17 >> 0x20,0);
            if ((code *)puVar17[3] != (code *)0x0) {
              (*(code *)puVar17[3])(peVar3,puVar17 + 1,2);
              pcStack_48 = (code *)puVar17[4];
              pcStack_50 = (code *)puVar17[3];
            }
            plVar23 = *(long **)(this_ptr + 8);
            plVar24 = *(long **)(this_ptr + 0x10);
            if (plVar23 != plVar24) {
              lVar19 = *plVar23;
              while (CONCAT44((*(undefined4 *)((uint8_t *)&eStack_68 + 0x4)),eStack_68.events) != lVar19) {
                plVar23 = plVar23 + 1;
                if (plVar23 == plVar24) goto joined_r0x00117259;
                lVar19 = *plVar23;
              }
              plVar23 = plVar23 + 1;
              if ((plVar23 != plVar24) && (lVar19 = (long)plVar24 - (long)plVar23 >> 3, 0 < lVar19))
              {
                do {
                  plVar24 = (long *)plVar23[-1];
                  lVar6 = *plVar23;
                  *plVar23 = 0;
                  plVar23[-1] = lVar6;
                  if (plVar24 != (long *)0x0) {
                    (**(code **)(*plVar24 + 0x18))();
                  }
                  plVar23 = plVar23 + 1;
                  lVar19 = lVar19 + -1;
                } while (lVar19 != 0);
                plVar24 = *(long **)(this_ptr + 0x10);
              }
              *(long **)(this_ptr + 0x10) = plVar24 + -1;
              if ((long *)plVar24[-1] != (long *)0x0) {
                (**(code **)(*(long *)plVar24[-1] + 0x18))();
              }
              plVar24[-1] = 0;
            }
joined_r0x00117259:
            if (pcStack_50 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
              rea_std____throw_bad_function_call();
            }
            (*pcStack_48)(peVar3);
            if (pcStack_50 != (code *)0x0) {
              (*pcStack_50)(peVar3,peVar3,3);
            }
            puVar17 = puVar17 + 5;
          } while (puVar15 != puVar17);
          puVar16 = *(undefined8 **)(this_ptr + 0x40);
          puVar15 = *(undefined8 **)(this_ptr + 0x38);
          puVar17 = puVar16;
          for (puVar22 = puVar15; puVar16 != puVar22; puVar22 = puVar22 + 5) {
            if ((code *)puVar22[3] != (code *)0x0) {
              (*(code *)puVar22[3])(puVar22 + 1,puVar22 + 1,3);
            }
            puVar17 = puVar15;
          }
        }
        puVar15 = *(undefined8 **)(this_ptr + 8);
        *(undefined8 **)(this_ptr + 0x40) = puVar17;
        while (puVar15 != *(undefined8 **)(this_ptr + 0x10)) {
          cVar7 = (**(code **)(*(long *)*puVar15 + 8))();
          while (cVar7 == '\0') {
            puVar15 = puVar15 + 1;
            if (puVar15 == *(undefined8 **)(this_ptr + 0x10)) goto LAB_0011714d;
            cVar7 = (**(code **)(*(long *)*puVar15 + 8))();
          }
          puVar16 = *(undefined8 **)(this_ptr + 0x10);
          puVar17 = puVar15 + 1;
          if ((puVar16 != puVar17) && (lVar19 = (long)puVar16 - (long)puVar17 >> 3, 0 < lVar19)) {
            do {
              plVar23 = (long *)puVar17[-1];
              uVar5 = *puVar17;
              *puVar17 = 0;
              puVar17[-1] = uVar5;
              if (plVar23 != (long *)0x0) {
                (**(code **)(*plVar23 + 0x18))();
              }
              puVar17 = puVar17 + 1;
              lVar19 = lVar19 + -1;
            } while (lVar19 != 0);
            puVar16 = *(undefined8 **)(this_ptr + 0x10);
          }
          *(undefined8 **)(this_ptr + 0x10) = puVar16 + -1;
          if ((long *)puVar16[-1] != (long *)0x0) {
            (**(code **)(*(long *)puVar16[-1] + 0x18))();
          }
          puVar16[-1] = 0;
        }
      }
      else {
        puVar17 = *(undefined8 **)(this_ptr + 8);
        while (puVar17 != *(undefined8 **)(this_ptr + 0x10)) {
          bVar25 = (eStack_78.events & 0x11) != 0;
          if ((eStack_78.events & 4) != 0) {
            bVar25 = bVar25 | 2;
          }
          cVar7 = (*(code *)**(undefined8 **)*puVar17)
                            ((undefined8 *)*puVar17,(*(undefined4 *)((uint8_t *)&eStack_78 + 0x4)),bVar25);
          if ((cVar7 == '\0') && (cVar7 = (**(code **)(*(long *)*puVar17 + 8))(), cVar7 == '\0')) {
            puVar17 = puVar17 + 1;
          }
          else {
            puVar16 = *(undefined8 **)(this_ptr + 0x10);
            puVar15 = puVar17 + 1;
            if ((puVar16 != puVar15) && (lVar19 = (long)puVar16 - (long)puVar15 >> 3, 0 < lVar19)) {
              do {
                plVar23 = (long *)puVar15[-1];
                uVar5 = *puVar15;
                *puVar15 = 0;
                puVar15[-1] = uVar5;
                if (plVar23 != (long *)0x0) {
                  (**(code **)(*plVar23 + 0x18))();
                }
                puVar15 = puVar15 + 1;
                lVar19 = lVar19 + -1;
              } while (lVar19 != 0);
              puVar16 = *(undefined8 **)(this_ptr + 0x10);
            }
            *(undefined8 **)(this_ptr + 0x10) = puVar16 + -1;
            if ((long *)puVar16[-1] != (long *)0x0) {
              (**(code **)(*(long *)puVar16[-1] + 0x18))();
            }
            puVar16[-1] = 0;
          }
        }
      }
LAB_0011714d:
      if (*(long *)(param_2 + 0x10) != 0) {
        (**(code **)(param_2 + 0x18))(param_2);
      }
    } while (this_ptr[0x54] != (EventLoop2)0x0);
  }
  this_ptr[0x54] = (EventLoop2)0x1;
  return *(undefined4 *)(this_ptr + 0x58);
code_r0x00116fc4:
  plStack_c8 = plStack_c8 + 1;
  if (plStack_a0 == plStack_c8) goto LAB_00116fda;
  goto LAB_00116dc6;
}





// ------------------------------------------------------------------
// IDX 79  00107350  memmove
// ------------------------------------------------------------------
void * rea_memmove(void * __dest, void * __src, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmove_00325280)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 80  00107360  setnonblock
// ------------------------------------------------------------------
void rea_setnonblock(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,3);
  if ((int)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_fcntl(param_1,4,(ulong)(uVar1 | 0x800));
  return;
}





// ------------------------------------------------------------------
// IDX 81  00107370  TcpConn__recv_proc
// ------------------------------------------------------------------
void rea_TcpConn__recv_proc(TcpConn * this_ptr)
{
  (*(code *)PTR_recv_proc_00325290)();
  return;
}





// ------------------------------------------------------------------
// IDX 82  00107380  WSConn__dtor_WSConn
// ------------------------------------------------------------------
void rea_WSConn__dtor_WSConn(WSConn * this_ptr)
{
  undefined8 *puVar1;
  
  *(undefined **)this_ptr = PTR_vtable_00324f30 + 0x10;
  if (this_ptr[0x58] != (WSConn)0x0) {
    rea_inflateEnd(*(undefined8 *)(this_ptr + 0x60));
    rea_deflateEnd(*(undefined8 *)(this_ptr + 0x68));
    rea_operator_delete(*(void **)(this_ptr + 0x60));
    rea_operator_delete(*(void **)(this_ptr + 0x68));
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x50);
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x48);
  *(undefined8 *)(this_ptr + 0x50) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x40);
  *(undefined8 *)(this_ptr + 0x48) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  *(undefined8 *)(this_ptr + 0x40) = 0;
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 83  00107390  PyFloat_AsDouble
// ------------------------------------------------------------------
undefined8 rea_PyFloat_AsDouble(...)
{
  (*(code *)PTR_PyFloat_AsDouble_003252a0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 84  001073a0  socket
// ------------------------------------------------------------------
int rea_socket(int __domain, int __type, int __protocol)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_003252a8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 85  001073b0  inet_ntoa
// ------------------------------------------------------------------
char * rea_inet_ntoa(in_addr __in)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_inet_ntoa_003252b0)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 86  001073c0  print_stack_abort
// ------------------------------------------------------------------
void rea_print_stack_abort(void)
{
  rea_print_stack();
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 87  001073d0  Py_BuildValue
// ------------------------------------------------------------------
undefined8 rea_Py_BuildValue(...)
{
  (*(code *)PTR_Py_BuildValue_003252c0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 88  001073e0  __errno_location
// ------------------------------------------------------------------
int * rea___errno_location(void)
{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR___errno_location_003252c8)();
  return piVar1;
}





// ------------------------------------------------------------------
// IDX 89  001073f0  WSConn__send
// ------------------------------------------------------------------
void rea_WSConn__send(WSConn * this_ptr, long * param_2, long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  void *pvVar17;
  void *pvVar18;
  ulong uVar19;
  undefined8 uVar20;
  _Rb_tree_node_base *p_Var21;
  _Rb_tree_node_base *p_Var22;
  ulong uVar23;
  bool bVar24;
  long lVar25;
  _Rb_tree_node_base *p_Var26;
  uint uVar27;
  undefined1 auVar28 [16];
  ulong uStack_68;
  void *pvStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  puVar10 = rea_operator_new(0x18);
  *puVar10 = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar3 = *(undefined8 **)(this_ptr + 0x50);
  *(undefined8 **)(this_ptr + 0x50) = puVar10;
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  if (this_ptr[0x58] == (WSConn)0x0) {
    uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),0x81);
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
    plVar11 = (long *)*param_2;
LAB_0011525a:
    uVar12 = plVar11[1] - *plVar11;
  }
  else {
    puVar3 = *(undefined8 **)(this_ptr + 0x68);
    uVar20 = *(undefined8 *)*param_2;
    uVar4 = ((undefined8 *)*param_2)[1];
    *puVar3 = uVar20;
    *(int *)(puVar3 + 1) = (int)uVar4 - (int)uVar20;
    plVar11 = rea_operator_new(0x18);
    *plVar11 = 0;
    plVar11[1] = 0;
    plVar11[2] = 0;
    uVar12 = rea_deflateBound(*(undefined8 *)(this_ptr + 0x68));
    pvVar17 = (void *)plVar11[1];
    pvVar18 = (void *)*plVar11;
    uVar23 = (long)pvVar17 - (long)pvVar18;
    if (uVar23 < uVar12) {
      uVar12 = uVar12 - uVar23;
      if (uVar12 != 0) {
        if ((ulong)(plVar11[2] - (long)pvVar17) < uVar12) {
          if (uVar12 <= ~uVar23) {
            uVar13 = uVar23;
            if (uVar23 <= uVar12) {
              uVar13 = uVar12;
            }
            uVar19 = 0xffffffffffffffff;
            if (CARRY8(uVar13,uVar23)) goto LAB_00115465;
            uVar19 = uVar13 + uVar23;
            if (uVar13 + uVar23 != 0) goto LAB_00115465;
            pvStack_60 = (void *)0x0;
            uVar19 = 0;
            pvVar17 = pvVar18;
            goto LAB_00115483;
          }
          uVar20 = rea_std____throw_length_error("vector___M_default_append");
          rea_FUN_00107772(plVar11);
                    /* WARNING: Subroutine does not return */
          rea__Unwind_Resume(uVar20);
        }
        rea_memset(pvVar17,0,uVar12);
        lVar14 = plVar11[1];
        pvVar18 = (void *)*plVar11;
        plVar11[1] = uVar12 + lVar14;
        uVar23 = (uVar12 + lVar14) - (long)pvVar18;
      }
    }
    else if (uVar12 < uVar23) {
      plVar11[1] = (long)pvVar18 + uVar12;
      uVar23 = ((long)pvVar18 + uVar12) - (long)pvVar18;
    }
    while( true ) {
      lVar14 = *(long *)(this_ptr + 0x68);
      *(int *)(lVar14 + 0x20) = (int)uVar23;
      *(void **)(lVar14 + 0x18) = pvVar18;
      iVar8 = rea_deflate();
      if (iVar8 != 0) break;
      pvVar17 = (void *)plVar11[1];
      pvVar18 = (void *)*plVar11;
      uVar13 = (long)pvVar17 - (long)pvVar18;
      uVar12 = -(ulong)*(uint *)(*(long *)(this_ptr + 0x68) + 0x20) - 4;
      uVar23 = uVar13 + uVar12;
      if (uVar23 <= uVar13) {
        if (uVar23 < uVar13) {
          plVar11[1] = uVar23 + (long)pvVar18;
        }
        break;
      }
      if (uVar12 <= (ulong)(plVar11[2] - (long)pvVar17)) {
        rea_memset(pvVar17,0,uVar12);
        plVar11[1] = plVar11[1] + uVar12;
        break;
      }
      if (uVar12 <= ~uVar13) {
        uStack_68 = 0xffffffffffffffff;
        uVar23 = uVar12;
        if (uVar12 <= uVar13) {
          uVar23 = uVar13;
        }
        if ((CARRY8(uVar23,uVar13)) || (uStack_68 = uVar23 + uVar13, uVar23 + uVar13 != 0)) {
          pvVar17 = rea_operator_new(uStack_68);
          pvVar18 = (void *)*plVar11;
          uVar13 = plVar11[1] - (long)pvVar18;
        }
        else {
          uStack_68 = 0;
          pvVar17 = (void *)0x0;
        }
        if (uVar13 != 0) {
          rea_memmove(pvVar17,pvVar18,uVar13);
        }
        pvVar18 = (void *)((long)pvVar17 + uVar13);
        rea_memset(pvVar18,0,(uVar12 + (long)pvVar18) - (long)pvVar18);
        if ((void *)*plVar11 != (void *)0x0) {
          rea_operator_delete((void *)*plVar11);
        }
        *plVar11 = (long)pvVar17;
        plVar11[1] = uVar12 + (long)pvVar18;
        plVar11[2] = (long)pvVar17 + uStack_68;
        break;
      }
      uVar19 = rea_std____throw_length_error("vector___M_default_append");
LAB_00115465:
      pvStack_60 = rea_operator_new(uVar19);
      uVar23 = plVar11[1] - *plVar11;
      pvVar17 = (void *)*plVar11;
LAB_00115483:
      pvVar18 = pvStack_60;
      if (uVar23 != 0) {
        pvVar18 = rea_memmove(pvStack_60,pvVar17,uVar23);
      }
      pvVar17 = (void *)((long)pvVar18 + uVar23);
      lVar14 = uVar12 + (long)pvVar17;
      rea_memset(pvVar17,0,lVar14 - (long)pvVar17);
      if ((void *)*plVar11 != (void *)0x0) {
        rea_operator_delete((void *)*plVar11);
      }
      *plVar11 = (long)pvVar18;
      plVar11[1] = lVar14;
      plVar11[2] = uVar19 + (long)pvVar18;
      uVar23 = lVar14 - (long)pvStack_60;
    }
    uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),0xc1);
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
    puVar3 = (undefined8 *)*param_2;
    *param_2 = (long)plVar11;
    if (puVar3 == (undefined8 *)0x0) goto LAB_0011525a;
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
    uVar12 = ((long *)*param_2)[1] - *(long *)*param_2;
  }
  if (0x7d < uVar12) {
    (*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)) = (undefined7)((ulong)uStack_58 >> 8);
    if (uVar12 < 0xffff) {
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '~';
    }
    else {
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\x7f';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = (uchar)(uVar12 >> 0x18);
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&uStack_58);
      (*(undefined1 *)((uint8_t *)&uStack_58 + 0x0)) = (uchar)(uVar12 >> 0x10);
    }
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
    uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),(char)(uVar12 >> 8));
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&uStack_58);
  }
  uStack_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&uStack_58 + 0x1)),(char)uVar12);
  rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
            (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
             (uchar *)&uStack_58);
  std__vector_unsigned_char_std__allocator_unsigned_char______M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char_____________(*(long *)(this_ptr + 0x50),*(undefined8 *)(*(long *)(this_ptr + 0x50) + 8),*(long *)*param_2,
             *(long *)*param_2 + uVar12);
  uVar20 = *(undefined8 *)(this_ptr + 0x50);
  *(undefined8 *)(this_ptr + 0x50) = 0;
  lVar14 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar14 + 0x5a) != '\0') {
    rea_fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar3 = *(undefined8 **)(lVar14 + 0x60);
  *(undefined1 *)(lVar14 + 0x5a) = 1;
  *(undefined8 *)(lVar14 + 0x60) = uVar20;
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  pcStack_48 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) == (code *)0x0) {
    uVar20 = 0;
  }
  else {
    (**(code **)(param_3 + 0x10))(&uStack_58,param_3,2);
    uStack_40 = *(undefined8 *)(param_3 + 0x18);
    uVar20 = *(undefined8 *)(param_3 + 0x10);
  }
  uVar4 = *(undefined8 *)(lVar14 + 0x68);
  uVar5 = *(undefined8 *)(lVar14 + 0x70);
  pcStack_48 = *(code **)(lVar14 + 0x78);
  *(undefined8 *)(lVar14 + 0x68) = uStack_58;
  *(undefined8 *)(lVar14 + 0x70) = uStack_50;
  uVar6 = *(undefined8 *)(lVar14 + 0x80);
  *(undefined8 *)(lVar14 + 0x78) = uVar20;
  *(undefined8 *)(lVar14 + 0x80) = uStack_40;
  uStack_58 = uVar4;
  uStack_50 = uVar5;
  uStack_40 = uVar6;
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  lVar25 = *(long *)(lVar14 + 0x38);
  iVar8 = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x5a);
  p_Var26 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  uStack_58 = CONCAT44((*(undefined4 *)((uint8_t *)&uStack_58 + 0x4)),iVar8);
  p_Var15 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  p_Var16 = p_Var26;
  p_Var21 = p_Var15;
  if (p_Var26 == (_Rb_tree_node_base *)0x0) {
LAB_001153b0:
    lVar14 = 0;
    uVar27 = 0;
  }
  else {
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < iVar8) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00114fcb;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00114fcb:
    if ((p_Var15 == p_Var22) || (p_Var16 = p_Var15, iVar8 < *(int *)(p_Var22 + 0x20)))
    goto LAB_001153b0;
    do {
      while (p_Var21 = p_Var26, *(int *)(p_Var21 + 0x20) < iVar8) {
        p_Var22 = p_Var21 + 0x18;
        p_Var26 = *(_Rb_tree_node_base **)p_Var22;
        p_Var21 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_00115003;
      }
      p_Var26 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
      p_Var16 = p_Var21;
    } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115003:
    if ((p_Var15 == p_Var21) || (iVar8 < *(int *)(p_Var21 + 0x20))) {
      p_Var26 = rea_operator_new(0x28);
      if (p_Var26 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var26 = 0;
        *(undefined8 *)(p_Var26 + 8) = 0;
        *(undefined8 *)(p_Var26 + 0x10) = 0;
        *(undefined8 *)(p_Var26 + 0x18) = 0;
        *(undefined4 *)(p_Var26 + 0x24) = 0;
        *(int *)(p_Var26 + 0x20) = (int)uStack_58;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar25 + 8),p_Var21,p_Var26 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x8));
      p_Var21 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x0));
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var26);
      }
      else {
        bVar24 = true;
        if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var16)) {
          bVar24 = *(int *)(p_Var26 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var26,p_Var16,p_Var15);
        *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
        p_Var21 = p_Var26;
      }
    }
    uVar27 = *(uint *)(p_Var21 + 0x24);
    lVar14 = 1;
  }
  lVar25 = lVar25 + (lVar14 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar25 + 8);
  p_Var15 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  p_Var26 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  uVar9 = uVar27;
  if (p_Var15 != (_Rb_tree_node_base *)0x0) {
    p_Var16 = p_Var15;
    p_Var21 = p_Var26;
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < (int)uStack_58) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115073;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115073:
    if ((p_Var26 != p_Var22) && (p_Var16 = p_Var26, *(int *)(p_Var22 + 0x20) <= (int)uStack_58)) {
      do {
        while (p_Var21 = p_Var15, *(int *)(p_Var21 + 0x20) < (int)uStack_58) {
          p_Var22 = p_Var21 + 0x18;
          p_Var15 = *(_Rb_tree_node_base **)p_Var22;
          p_Var21 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_001150ab;
        }
        p_Var15 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
        p_Var16 = p_Var21;
      } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001150ab:
      if ((p_Var26 == p_Var21) || ((int)uStack_58 < *(int *)(p_Var21 + 0x20))) {
        p_Var15 = rea_operator_new(0x28);
        if (p_Var15 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var15 = 0;
          *(undefined8 *)(p_Var15 + 8) = 0;
          *(undefined8 *)(p_Var15 + 0x10) = 0;
          *(undefined8 *)(p_Var15 + 0x18) = 0;
          *(undefined4 *)(p_Var15 + 0x24) = 0;
          *(int *)(p_Var15 + 0x20) = (int)uStack_58;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var21,p_Var15 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x8));
        p_Var21 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x0));
        if (p_Var16 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var15);
        }
        else {
          bVar24 = true;
          if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var26 != p_Var16)) {
            bVar24 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var16 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var15,p_Var16,p_Var26);
          *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
          p_Var21 = p_Var15;
        }
      }
      uVar9 = *(uint *)(p_Var21 + 0x24);
    }
  }
  uVar7 = uVar9 | 2;
  if (cVar2 == '\0') {
    uVar7 = uVar9 & 0xfffffffd;
  }
  if (uVar27 == uVar7) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,(int *)&uStack_58);
    return;
  }
  p_Var15 = p_Var26;
  if (*(_Rb_tree_node_base **)(lVar25 + 0x18) != (_Rb_tree_node_base *)0x0) {
    p_Var16 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
    p_Var21 = p_Var26;
    do {
      while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < (int)uStack_58) {
        p_Var22 = p_Var15 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var22;
        p_Var15 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_00115182;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var21 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115182:
    if ((p_Var26 != p_Var15) && (*(int *)(p_Var15 + 0x20) <= (int)uStack_58)) goto LAB_00115225;
  }
  p_Var16 = rea_operator_new(0x28);
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var16 = 0;
    *(undefined8 *)(p_Var16 + 8) = 0;
    *(undefined8 *)(p_Var16 + 0x10) = 0;
    *(undefined8 *)(p_Var16 + 0x18) = 0;
    *(undefined4 *)(p_Var16 + 0x24) = 0;
    *(int *)(p_Var16 + 0x20) = (int)uStack_58;
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var16 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
  p_Var21 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x8));
  p_Var15 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x0));
  if (p_Var21 == (_Rb_tree_node_base *)0x0) {
    rea_operator_delete(p_Var16);
  }
  else {
    bVar24 = true;
    if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var26 != p_Var21)) {
      bVar24 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var21 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var16,p_Var21,p_Var26);
    *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
    p_Var15 = p_Var16;
  }
LAB_00115225:
  *(uint *)(p_Var15 + 0x24) = uVar7;
  return;
}





// ------------------------------------------------------------------
// IDX 90  00107400  std___Rb_tree_insert_and_rebalance________________
// ------------------------------------------------------------------
void rea_std___Rb_tree_insert_and_rebalance(bool param_1, _Rb_tree_node_base * param_2, _Rb_tree_node_base * param_3, _Rb_tree_node_base * param_4)
{
  (*(code *)PTR__Rb_tree_insert_and_rebalance_003252d8)();
  return;
}





// ------------------------------------------------------------------
// IDX 91  00107410  WSConn__recv_more
// ------------------------------------------------------------------
void rea_WSConn__recv_more(WSConn * this_ptr, ulong param_1, long param_3)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  long lVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  code *pcVar12;
  _Rb_tree_node_base *p_Var13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auVar20 [16];
  int aiStack_c8 [4];
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  WSConn *pWStack_98;
  ulong uStack_90;
  undefined1 auStack_88 [16];
  code *pcStack_78;
  undefined8 uStack_70;
  WSConn *pWStack_68;
  ulong uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  if (param_1 <= (ulong)((*(long **)(this_ptr + 0x40))[1] - **(long **)(this_ptr + 0x40))) {
    if (*(long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  pcStack_78 = (code *)0x0;
  pWStack_98 = this_ptr;
  uStack_90 = param_1;
  if (*(code **)(param_3 + 0x10) == (code *)0x0) {
    pcVar12 = (code *)0x0;
  }
  else {
    (**(code **)(param_3 + 0x10))(auStack_88,param_3,2);
    pcStack_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
    pcVar12 = *(code **)(param_3 + 0x10);
  }
  lVar14 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar14 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
    pcVar12 = pcStack_78;
  }
  *(undefined1 *)(lVar14 + 0x88) = 1;
  pcStack_48 = (code *)0x0;
  pWStack_68 = pWStack_98;
  uStack_60 = uStack_90;
  if (pcVar12 != (code *)0x0) {
    (*pcVar12)(&uStack_58,auStack_88,2);
    pcStack_48 = pcStack_78;
    uStack_40 = uStack_70;
  }
  pcStack_a8 = (code *)0x0;
  puVar8 = rea_operator_new(0x30);
  pcVar12 = pcStack_48;
  puVar8[4] = 0;
  uVar3 = puVar8[2];
  uVar4 = puVar8[3];
  uVar5 = puVar8[5];
  *puVar8 = pWStack_68;
  puVar8[1] = uStack_60;
  puVar8[3] = uStack_50;
  puVar8[2] = uStack_58;
  pcStack_48 = (code *)0x0;
  puVar8[4] = pcVar12;
  puVar8[5] = uStack_40;
  uStack_b8 = *(undefined8 *)(lVar14 + 0x90);
  uVar6 = *(undefined8 *)(lVar14 + 0x98);
  *(undefined8 *)(lVar14 + 0x98) = uStack_b0;
  *(undefined8 **)(lVar14 + 0x90) = puVar8;
  pcStack_a8 = *(code **)(lVar14 + 0xa0);
  uStack_a0 = *(undefined8 *)(lVar14 + 0xa8);
  *(code **)(lVar14 + 0xa0) = FUN_0010e430;
  *(code **)(lVar14 + 0xa8) = FUN_00111c50;
  uStack_b0 = uVar6;
  uStack_58 = uVar3;
  uStack_50 = uVar4;
  uStack_40 = uVar5;
  if (pcStack_a8 != (code *)0x0) {
    (*pcStack_a8)(&uStack_b8,&uStack_b8,3);
  }
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  aiStack_c8[0] = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x88);
  lVar14 = *(long *)(lVar14 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var16 = p_Var10;
  p_Var15 = p_Var11;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
LAB_001103f0:
    lVar9 = 0;
    uVar18 = 0;
  }
  else {
    do {
      while (p_Var13 = p_Var16, *(int *)(p_Var13 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001100b3;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var15 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001100b3:
    if ((p_Var11 == p_Var13) || (p_Var16 = p_Var11, aiStack_c8[0] < *(int *)(p_Var13 + 0x20)))
    goto LAB_001103f0;
    do {
      while (p_Var15 = p_Var10, *(int *)(p_Var15 + 0x20) < aiStack_c8[0]) {
        p_Var13 = p_Var15 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var13;
        p_Var15 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_001100eb;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var16 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001100eb:
    if ((p_Var11 == p_Var15) || (aiStack_c8[0] < *(int *)(p_Var15 + 0x20))) {
      p_Var10 = rea_operator_new(0x28);
      if (p_Var10 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = aiStack_c8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar14 + 8),p_Var15,p_Var10 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x8));
      p_Var15 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x0));
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var16)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var16,p_Var11);
        *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
        p_Var15 = p_Var10;
      }
    }
    uVar18 = *(uint *)(p_Var15 + 0x24);
    lVar9 = 1;
  }
  lVar14 = lVar14 + (lVar9 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar14 + 8);
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var15 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var10 = p_Var11;
  p_Var16 = p_Var15;
  uVar7 = uVar18;
  if (p_Var11 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var13 = p_Var10, *(int *)(p_Var13 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011015a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011015a:
    if ((p_Var15 != p_Var13) && (p_Var10 = p_Var15, *(int *)(p_Var13 + 0x20) <= aiStack_c8[0])) {
      do {
        while (p_Var16 = p_Var11, *(int *)(p_Var16 + 0x20) < aiStack_c8[0]) {
          p_Var13 = p_Var16 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var13;
          p_Var16 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_0011018a;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var10 = p_Var16;
      } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011018a:
      if ((p_Var15 == p_Var16) || (aiStack_c8[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var11 = rea_operator_new(0x28);
        if (p_Var11 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = aiStack_c8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var16,p_Var11 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
        p_Var10 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x8));
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x0));
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var11);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var10)) {
            bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var10,p_Var15);
          *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
          p_Var16 = p_Var11;
        }
      }
      uVar7 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar19 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar19 = uVar7 & 0xfffffffe;
  }
  if (uVar18 == uVar19) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_c8);
    goto LAB_00110208;
  }
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var16 = p_Var15;
  p_Var10 = p_Var15;
  if (*(_Rb_tree_node_base **)(lVar14 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00110360:
    p_Var11 = rea_operator_new(0x28);
    if (p_Var11 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var11 = 0;
      *(undefined8 *)(p_Var11 + 8) = 0;
      *(undefined8 *)(p_Var11 + 0x10) = 0;
      *(undefined8 *)(p_Var11 + 0x18) = 0;
      *(undefined4 *)(p_Var11 + 0x24) = 0;
      *(int *)(p_Var11 + 0x20) = aiStack_c8[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var11 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
    p_Var16 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x8));
    p_Var10 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x0));
    if (p_Var16 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var11);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var16)) {
        bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var16,p_Var15);
      *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
      p_Var10 = p_Var11;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var11, *(int *)(p_Var10 + 0x20) < aiStack_c8[0]) {
        p_Var13 = p_Var10 + 0x18;
        p_Var11 = *(_Rb_tree_node_base **)p_Var13;
        p_Var10 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_001101f2;
      }
      p_Var11 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var16 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001101f2:
    if ((p_Var15 == p_Var10) || (aiStack_c8[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00110360;
  }
  *(uint *)(p_Var10 + 0x24) = uVar19;
LAB_00110208:
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(auStack_88,auStack_88,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 92  00107420  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr)
{
  (*(code *)PTR__vector_003252e8)();
  return;
}





// ------------------------------------------------------------------
// IDX 93  00107430  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
arr_undefined1_16 rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_get_insert_hint_unique_pos(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, _Rb_tree_node_base * param_2, int * param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  int iVar5;
  int iVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  p_Var4 = (_Rb_tree_node_base *)(this_ptr + 8);
  if (p_Var4 != param_2) {
    iVar6 = *param_3;
    if (iVar6 < *(int *)(param_2 + 0x20)) {
      p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
      p_Var3 = p_Var2;
      if (p_Var2 == param_2) goto LAB_0010bee8;
      p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(param_2);
      if (*(int *)(p_Var1 + 0x20) < iVar6) {
        p_Var3 = (_Rb_tree_node_base *)0x0;
        p_Var2 = p_Var1;
        if (*(long *)(p_Var1 + 0x18) != 0) {
          p_Var3 = param_2;
          p_Var2 = param_2;
        }
        goto LAB_0010bee8;
      }
      p_Var3 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
      if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c010:
        if (p_Var2 == p_Var4) goto LAB_0010c02b;
        p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var4);
        iVar5 = *(int *)(p_Var1 + 0x20);
      }
      else {
        do {
          p_Var4 = p_Var3;
          iVar5 = *(int *)(p_Var4 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x18);
          }
        } while (p_Var3 != (_Rb_tree_node_base *)0x0);
        p_Var1 = p_Var4;
        if (iVar6 < iVar5) goto LAB_0010c010;
      }
      p_Var3 = (_Rb_tree_node_base *)0x0;
      p_Var2 = p_Var4;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var1;
        p_Var2 = (_Rb_tree_node_base *)0x0;
      }
      goto LAB_0010bee8;
    }
    if (iVar6 <= *(int *)(param_2 + 0x20)) {
      (*(undefined8 *)((uint8_t *)&auVar9 + 0x8)) = 0;
      (*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = param_2;
      return rea_arr_from<arr_undefined1_16>(auVar9);
    }
    p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x20);
    if (p_Var2 == param_2) {
LAB_0010c02b:
      p_Var3 = (_Rb_tree_node_base *)0x0;
    }
    else {
      p_Var2 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(param_2);
      if (iVar6 < *(int *)(p_Var2 + 0x20)) {
        p_Var4 = p_Var2;
        if (*(long *)(param_2 + 0x18) == 0) {
          p_Var2 = param_2;
          p_Var4 = (_Rb_tree_node_base *)0x0;
        }
        (*(undefined8 *)((uint8_t *)&auVar8 + 0x8)) = p_Var2;
        (*(undefined8 *)((uint8_t *)&auVar8 + 0x0)) = p_Var4;
        return rea_arr_from<arr_undefined1_16>(auVar8);
      }
      p_Var3 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
      p_Var2 = p_Var4;
      if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c0e0:
        if (*(_Rb_tree_node_base **)(this_ptr + 0x18) == p_Var2) goto LAB_0010c02b;
        p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var2);
        iVar5 = *(int *)(p_Var4 + 0x20);
      }
      else {
        do {
          p_Var2 = p_Var3;
          iVar5 = *(int *)(p_Var2 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x18);
          }
        } while (p_Var3 != (_Rb_tree_node_base *)0x0);
        p_Var4 = p_Var2;
        if (iVar6 < iVar5) goto LAB_0010c0e0;
      }
      p_Var3 = (_Rb_tree_node_base *)0x0;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var4;
        p_Var2 = (_Rb_tree_node_base *)0x0;
      }
    }
    goto LAB_0010bee8;
  }
  if ((*(long *)(this_ptr + 0x28) != 0) &&
     (*(int *)(*(_Rb_tree_node_base **)(this_ptr + 0x20) + 0x20) < *param_3)) {
    p_Var3 = (_Rb_tree_node_base *)0x0;
    p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x20);
    goto LAB_0010bee8;
  }
  if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c0b7:
    if (*(_Rb_tree_node_base **)(this_ptr + 0x18) == p_Var4) {
      p_Var3 = (_Rb_tree_node_base *)0x0;
      p_Var2 = p_Var4;
      goto LAB_0010bee8;
    }
    p_Var3 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var4);
    iVar5 = *(int *)(p_Var3 + 0x20);
    iVar6 = *param_3;
  }
  else {
    iVar6 = *param_3;
    p_Var4 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
    do {
      p_Var3 = p_Var4;
      iVar5 = *(int *)(p_Var3 + 0x20);
      if (iVar6 < iVar5) {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x10);
      }
      else {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x18);
      }
    } while (p_Var4 != (_Rb_tree_node_base *)0x0);
    p_Var4 = p_Var3;
    if (iVar6 < iVar5) goto LAB_0010c0b7;
  }
  p_Var2 = (_Rb_tree_node_base *)0x0;
  if (iVar5 < iVar6) {
    p_Var3 = p_Var2;
    p_Var2 = p_Var4;
  }
LAB_0010bee8:
  (*(undefined8 *)((uint8_t *)&auVar7 + 0x8)) = p_Var2;
  (*(undefined8 *)((uint8_t *)&auVar7 + 0x0)) = p_Var3;
  return rea_arr_from<arr_undefined1_16>(auVar7);
}





// ------------------------------------------------------------------
// IDX 94  00107440  std____throw_bad_function_call
// ------------------------------------------------------------------
void rea_std____throw_bad_function_call(void)
{
  (*(code *)PTR___throw_bad_function_call_003252f8)();
  return;
}





// ------------------------------------------------------------------
// IDX 95  00107450  WSConn__recv
// ------------------------------------------------------------------
void rea_WSConn__recv(WSConn * this_ptr, long param_2)
{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 auStack_38 [16];
  code *pcStack_28;
  undefined8 uStack_20;
  
  puVar2 = rea_operator_new(0x18);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar1 = *(undefined8 **)(this_ptr + 0x48);
  *(undefined8 **)(this_ptr + 0x48) = puVar2;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  this_ptr[0x59] = (WSConn)0x0;
  pcStack_28 = (code *)0x0;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(auStack_38,param_2,2);
    pcStack_28 = *(code **)(param_2 + 0x10);
    uStack_20 = *(undefined8 *)(param_2 + 0x18);
  }
  read_head(this_ptr,auStack_38);
  if (pcStack_28 != (code *)0x0) {
    (*pcStack_28)(auStack_38,auStack_38,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 96  00107460  UnixClient__UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__UnixClient(...)
{
  (*(code *)PTR_UnixClient_00325308)();
  return;
}





// ------------------------------------------------------------------
// IDX 97  00107470  std___Rb_tree_rebalance_for_erase
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_rebalance_for_erase(_Rb_tree_node_base * param_1, _Rb_tree_node_base * param_2)
{
  (*(code *)PTR__Rb_tree_rebalance_for_erase_00325310)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 98  00107480  strcmp
// ------------------------------------------------------------------
int rea_strcmp(char * __s1, char * __s2)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00325318)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 99  00107490  TcpClient__TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__TcpClient(...)
{
  (*(code *)PTR_TcpClient_00325320)();
  return;
}





// ------------------------------------------------------------------
// IDX 100  001074a0  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, _Rb_tree_node * param_1)
{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  _Rb_tree_node *p_Var9;
  void *pvVar10;
  
  while (param_1 != (_Rb_tree_node *)0x0) {
    pvVar10 = *(void **)(param_1 + 0x18);
    while (pvVar10 != (void *)0x0) {
      pvVar8 = *(void **)((long)pvVar10 + 0x18);
      while (pvVar8 != (void *)0x0) {
        pvVar7 = *(void **)((long)pvVar8 + 0x18);
        while (pvVar7 != (void *)0x0) {
          pvVar6 = *(void **)((long)pvVar7 + 0x18);
          while (pvVar6 != (void *)0x0) {
            pvVar5 = *(void **)((long)pvVar6 + 0x18);
            while (pvVar5 != (void *)0x0) {
              pvVar4 = *(void **)((long)pvVar5 + 0x18);
              while (pvVar4 != (void *)0x0) {
                pvVar3 = *(void **)((long)pvVar4 + 0x18);
                while (pvVar3 != (void *)0x0) {
                  pvVar2 = *(void **)((long)pvVar3 + 0x18);
                  while (pvVar2 != (void *)0x0) {
                    _M_erase(this_ptr,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
                    pvVar1 = *(void **)((long)pvVar2 + 0x10);
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long)pvVar3 + 0x10);
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long)pvVar4 + 0x10);
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long)pvVar5 + 0x10);
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long)pvVar6 + 0x10);
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long)pvVar7 + 0x10);
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long)pvVar8 + 0x10);
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long)pvVar10 + 0x10);
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 101  001074b0  deflateBound
// ------------------------------------------------------------------
undefined8 rea_deflateBound(...)
{
  (*(code *)PTR_deflateBound_00325330)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 102  001074c0  std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase(_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root * this_ptr, _Rb_tree_node * param_1)
{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  _Rb_tree_node *p_Var9;
  void *pvVar10;
  
  while (param_1 != (_Rb_tree_node *)0x0) {
    pvVar10 = *(void **)(param_1 + 0x18);
    while (pvVar10 != (void *)0x0) {
      pvVar8 = *(void **)((long)pvVar10 + 0x18);
      while (pvVar8 != (void *)0x0) {
        pvVar7 = *(void **)((long)pvVar8 + 0x18);
        while (pvVar7 != (void *)0x0) {
          pvVar6 = *(void **)((long)pvVar7 + 0x18);
          while (pvVar6 != (void *)0x0) {
            pvVar5 = *(void **)((long)pvVar6 + 0x18);
            while (pvVar5 != (void *)0x0) {
              pvVar4 = *(void **)((long)pvVar5 + 0x18);
              while (pvVar4 != (void *)0x0) {
                pvVar3 = *(void **)((long)pvVar4 + 0x18);
                while (pvVar3 != (void *)0x0) {
                  pvVar2 = *(void **)((long)pvVar3 + 0x18);
                  while (pvVar2 != (void *)0x0) {
                    _M_erase(this_ptr,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
                    pvVar1 = *(void **)((long)pvVar2 + 0x10);
                    if (*(long **)((long)pvVar2 + 0x28) != (long *)0x0) {
                      (**(code **)(**(long **)((long)pvVar2 + 0x28) + 8))();
                    }
                    *(undefined8 *)((long)pvVar2 + 0x28) = 0;
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long)pvVar3 + 0x10);
                  if (*(long **)((long)pvVar3 + 0x28) != (long *)0x0) {
                    (**(code **)(**(long **)((long)pvVar3 + 0x28) + 8))();
                  }
                  *(undefined8 *)((long)pvVar3 + 0x28) = 0;
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long)pvVar4 + 0x10);
                if (*(long **)((long)pvVar4 + 0x28) != (long *)0x0) {
                  (**(code **)(**(long **)((long)pvVar4 + 0x28) + 8))();
                }
                *(undefined8 *)((long)pvVar4 + 0x28) = 0;
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long)pvVar5 + 0x10);
              if (*(long **)((long)pvVar5 + 0x28) != (long *)0x0) {
                (**(code **)(**(long **)((long)pvVar5 + 0x28) + 8))();
              }
              *(undefined8 *)((long)pvVar5 + 0x28) = 0;
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long)pvVar6 + 0x10);
            if (*(long **)((long)pvVar6 + 0x28) != (long *)0x0) {
              (**(code **)(**(long **)((long)pvVar6 + 0x28) + 8))();
            }
            *(undefined8 *)((long)pvVar6 + 0x28) = 0;
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long)pvVar7 + 0x10);
          if (*(long **)((long)pvVar7 + 0x28) != (long *)0x0) {
            (**(code **)(**(long **)((long)pvVar7 + 0x28) + 8))();
          }
          *(undefined8 *)((long)pvVar7 + 0x28) = 0;
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long)pvVar8 + 0x10);
        if (*(long **)((long)pvVar8 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar8 + 0x28) = 0;
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long)pvVar10 + 0x10);
      if (*(long **)((long)pvVar10 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)((long)pvVar10 + 0x28) + 8))();
      }
      *(undefined8 *)((long)pvVar10 + 0x28) = 0;
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 8))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 103  001074d0  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign(char * param_1, ulong param_2)
{
  (*(code *)PTR_assign_00325340)();
  return;
}





// ------------------------------------------------------------------
// IDX 104  001074e0  TcpServer__dtor_TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__dtor_TcpServer(TcpServer * this_ptr)
{
  (*(code *)PTR__TcpServer_00325348)();
  return;
}





// ------------------------------------------------------------------
// IDX 105  001074f0  epoll_wait
// ------------------------------------------------------------------
int rea_epoll_wait(int __epfd, epoll_event * __events, int __maxevents, int __timeout)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_epoll_wait_00325350)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 106  00107500  freeifaddrs
// ------------------------------------------------------------------
void rea_freeifaddrs(...)
{
  (*(code *)PTR_freeifaddrs_00325358)();
  return;
}





// ------------------------------------------------------------------
// IDX 107  00107510  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign__dup2(string * param_1)
{
  (*(code *)PTR_assign_00325360)();
  return;
}





// ------------------------------------------------------------------
// IDX 108  00107520  WSConn__connect
// ------------------------------------------------------------------
void rea_WSConn__connect(WSConn * this_ptr, long param_2)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  sbyte sVar16;
  _Rb_tree_node_base *p_Var17;
  long lVar18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  undefined1 auVar25 [16];
  int aiStack_108 [4];
  byte abStack_f8 [16];
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  code *pcStack_d8;
  undefined8 uStack_d0;
  char acStack_c8 [48];
  WSConn *pWStack_98;
  undefined1 auStack_90 [16];
  code *pcStack_80;
  undefined8 uStack_78;
  WSConn *pWStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  code *pcStack_50;
  undefined8 uStack_48;
  
  uVar9 = 0;
  abStack_f8[0] = 0;
  abStack_f8[1] = 0;
  abStack_f8[2] = 0;
  abStack_f8[3] = 0;
  abStack_f8[4] = 0;
  abStack_f8[5] = 0;
  abStack_f8[6] = 0;
  abStack_f8[7] = 0;
  abStack_f8[8] = 0;
  abStack_f8[9] = 0;
  abStack_f8[10] = 0;
  abStack_f8[0xb] = 0;
  abStack_f8[0xc] = 0;
  abStack_f8[0xd] = 0;
  abStack_f8[0xe] = 0;
  abStack_f8[0xf] = 0;
  pcVar11 = acStack_c8;
  iVar22 = 0;
  do {
    if (iVar22 + 1 == 0x10) {
      iVar23 = 0x10;
      sVar16 = 0x10;
      iVar22 = 1;
    }
    else {
      uVar9 = (uint)abStack_f8[iVar22 + 1] | uVar9 << 8;
      iVar23 = iVar22 + 2;
      if (iVar23 < 0x10) {
        lVar18 = (long)iVar23;
        iVar23 = iVar22 + 3;
        sVar16 = 0;
        uVar9 = uVar9 << 8 | (uint)abStack_f8[lVar18];
        iVar22 = 3;
      }
      else {
        sVar16 = 8;
        iVar22 = 2;
      }
    }
    uVar9 = uVar9 << sVar16;
    bVar7 = (byte)((int)uVar9 >> 0x12);
    pWStack_68 = (WSConn *)(CONCAT71((int7)((ulong)pWStack_68 >> 8),bVar7) & 0xffffffff0000003f);
    *pcVar11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
               [(char)(bVar7 & 0x3f)];
    bVar7 = (byte)((int)uVar9 >> 0xc);
    pWStack_68 = (WSConn *)
                 (CONCAT62((*(arr_undefined1_6 *)((uint8_t *)&pWStack_68 + 0x2)),CONCAT11(bVar7,(*(undefined1 *)((uint8_t *)&pWStack_68 + 0x0)))) & 0xffffffffffff3fff);
    pcVar11[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                 [(char)(bVar7 & 0x3f)];
    if (iVar22 == 1) {
      pcVar11[2] = '=';
LAB_001123de:
      uVar9 = 0x40;
    }
    else {
      bVar7 = (byte)((int)uVar9 >> 6);
      pWStack_68 = (WSConn *)
                   (CONCAT53((*(arr_undefined1_5 *)((uint8_t *)&pWStack_68 + 0x3)),CONCAT12(bVar7,(*(undefined2 *)((uint8_t *)&pWStack_68 + 0x0)))) & 0xffffffffff3fffff
                   );
      pcVar11[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                   [(char)(bVar7 & 0x3f)];
      if (iVar22 != 3) goto LAB_001123de;
      uVar9 = uVar9 & 0x3f;
    }
    pcVar11[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="[(int)uVar9];
    if (0xf < iVar23) break;
    uVar9 = (uint)abStack_f8[iVar23];
    pcVar11 = pcVar11 + 4;
    iVar22 = iVar23;
  } while( true );
  pcVar11[4] = '\0';
  pcVar11 = rea_operator_new(0x18);
  pcVar11[0] = '\0';
  pcVar11[1] = '\0';
  pcVar11[2] = '\0';
  pcVar11[3] = '\0';
  pcVar11[4] = '\0';
  pcVar11[5] = '\0';
  pcVar11[6] = '\0';
  pcVar11[7] = '\0';
  pcVar11[8] = '\0';
  pcVar11[9] = '\0';
  pcVar11[10] = '\0';
  pcVar11[0xb] = '\0';
  pcVar11[0xc] = '\0';
  pcVar11[0xd] = '\0';
  pcVar11[0xe] = '\0';
  pcVar11[0xf] = '\0';
  pcVar11[0x10] = '\0';
  pcVar11[0x11] = '\0';
  pcVar11[0x12] = '\0';
  pcVar11[0x13] = '\0';
  pcVar11[0x14] = '\0';
  pcVar11[0x15] = '\0';
  pcVar11[0x16] = '\0';
  pcVar11[0x17] = '\0';
  rea_Buffer__appendf(pcVar11,
                  "GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Key: %s\r\nSec-WebSocket-Extensions: permessage-deflate\r\nSec-WebSocket-Version: 13\r\n\r\n"
                  ,acStack_c8);
  pcStack_80 = (code *)0x0;
  pWStack_98 = this_ptr;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(auStack_90,param_2,2);
    uStack_78 = *(undefined8 *)(param_2 + 0x18);
    pcStack_80 = *(code **)(param_2 + 0x10);
  }
  lVar18 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar18 + 0x5a) != '\0') {
    rea_fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar12 = *(undefined8 **)(lVar18 + 0x60);
  *(undefined1 *)(lVar18 + 0x5a) = 1;
  *(char **)(lVar18 + 0x60) = pcVar11;
  if (puVar12 != (undefined8 *)0x0) {
    if ((void *)*puVar12 != (void *)0x0) {
      rea_operator_delete((void *)*puVar12);
    }
    rea_operator_delete(puVar12);
  }
  pcStack_50 = (code *)0x0;
  pWStack_68 = pWStack_98;
  if (pcStack_80 != (code *)0x0) {
    (*pcStack_80)(&uStack_60,auStack_90,2);
    uStack_48 = uStack_78;
    pcStack_50 = pcStack_80;
  }
  pcStack_d8 = (code *)0x0;
  puVar12 = rea_operator_new(0x28);
  pcVar8 = pcStack_50;
  uVar3 = puVar12[1];
  puVar12[3] = 0;
  uVar4 = puVar12[2];
  *puVar12 = pWStack_68;
  puVar12[1] = uStack_60;
  puVar12[2] = uStack_58;
  pcStack_50 = (code *)0x0;
  uVar5 = puVar12[4];
  puVar12[3] = pcVar8;
  puVar12[4] = uStack_48;
  uStack_e8 = *(undefined8 *)(lVar18 + 0x68);
  uVar6 = *(undefined8 *)(lVar18 + 0x70);
  *(undefined8 *)(lVar18 + 0x70) = uStack_e0;
  *(undefined8 **)(lVar18 + 0x68) = puVar12;
  pcStack_d8 = *(code **)(lVar18 + 0x78);
  uStack_d0 = *(undefined8 *)(lVar18 + 0x80);
  *(code **)(lVar18 + 0x78) = FUN_0010e1d0;
  *(code **)(lVar18 + 0x80) = FUN_0010fc40;
  uStack_e0 = uVar6;
  uStack_60 = uVar3;
  uStack_58 = uVar4;
  uStack_48 = uVar5;
  if (pcStack_d8 != (code *)0x0) {
    (*pcStack_d8)(&uStack_e8,&uStack_e8,3);
  }
  if (pcStack_50 != (code *)0x0) {
    (*pcStack_50)(&uStack_60,&uStack_60,3);
  }
  aiStack_108[0] = *(int *)(lVar18 + 0x40);
  cVar2 = *(char *)(lVar18 + 0x5a);
  lVar18 = *(long *)(lVar18 + 0x38);
  p_Var15 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var20 = p_Var15;
  p_Var19 = p_Var14;
  if (p_Var15 == (_Rb_tree_node_base *)0x0) {
LAB_00112970:
    lVar13 = 0;
    uVar9 = 0;
  }
  else {
    do {
      while (p_Var17 = p_Var20, aiStack_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var20 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var19 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011265b;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var20 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var19;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_0011265b:
    if ((p_Var14 == p_Var17) || (p_Var20 = p_Var14, aiStack_108[0] < *(int *)(p_Var17 + 0x20)))
    goto LAB_00112970;
    do {
      while (p_Var19 = p_Var15, aiStack_108[0] <= *(int *)(p_Var19 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)(p_Var19 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00112693;
      }
      p_Var17 = p_Var19 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var17;
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_00112693:
    if ((p_Var14 == p_Var19) || (aiStack_108[0] < *(int *)(p_Var19 + 0x20))) {
      p_Var15 = rea_operator_new(0x28);
      if (p_Var15 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var15 = 0;
        *(undefined8 *)(p_Var15 + 8) = 0;
        *(undefined8 *)(p_Var15 + 0x10) = 0;
        *(undefined8 *)(p_Var15 + 0x18) = 0;
        *(undefined4 *)(p_Var15 + 0x24) = 0;
        *(int *)(p_Var15 + 0x20) = aiStack_108[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar18 + 8),p_Var19,p_Var15 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
      p_Var20 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x8));
      p_Var19 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x0));
      if (p_Var20 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var15);
      }
      else {
        bVar21 = true;
        if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var20)) {
          bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var20 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var20,p_Var14);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var19 = p_Var15;
      }
    }
    uVar9 = *(uint *)(p_Var19 + 0x24);
    lVar13 = 1;
  }
  lVar18 = lVar18 + (lVar13 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar18 + 8);
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var15 = p_Var14;
  p_Var20 = p_Var19;
  uVar10 = uVar9;
  if (p_Var14 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var17 = p_Var15, aiStack_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var20 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_001126fa;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_001126fa:
    if ((p_Var19 != p_Var17) && (p_Var15 = p_Var19, *(int *)(p_Var17 + 0x20) <= aiStack_108[0])) {
      do {
        while (p_Var20 = p_Var14, aiStack_108[0] <= *(int *)(p_Var20 + 0x20)) {
          p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
          p_Var15 = p_Var20;
          if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011272a;
        }
        p_Var17 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var17;
        p_Var20 = p_Var15;
      } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_0011272a:
      if ((p_Var19 == p_Var20) || (aiStack_108[0] < *(int *)(p_Var20 + 0x20))) {
        p_Var14 = rea_operator_new(0x28);
        if (p_Var14 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = aiStack_108[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var20,p_Var14 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
        p_Var15 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x8));
        p_Var20 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x0));
        if (p_Var15 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var14);
        }
        else {
          bVar21 = true;
          if ((p_Var20 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var15)) {
            bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var15 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var15,p_Var19);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var20 = p_Var14;
        }
      }
      uVar10 = *(uint *)(p_Var20 + 0x24);
    }
  }
  uVar24 = uVar10 | 2;
  if (cVar2 == '\0') {
    uVar24 = uVar10 & 0xfffffffd;
  }
  if (uVar9 == uVar24) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_108);
    goto LAB_00112819;
  }
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var20 = p_Var19;
  p_Var15 = p_Var19;
  if (*(_Rb_tree_node_base **)(lVar18 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0011279c:
    p_Var14 = rea_operator_new(0x28);
    if (p_Var14 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var14 = 0;
      *(undefined8 *)(p_Var14 + 8) = 0;
      *(undefined8 *)(p_Var14 + 0x10) = 0;
      *(undefined8 *)(p_Var14 + 0x18) = 0;
      *(undefined4 *)(p_Var14 + 0x24) = 0;
      *(int *)(p_Var14 + 0x20) = aiStack_108[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var14 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
    p_Var20 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x8));
    p_Var15 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x0));
    if (p_Var20 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var14);
    }
    else {
      bVar21 = true;
      if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var20)) {
        bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var20 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var20,p_Var19);
      *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
      p_Var15 = p_Var14;
    }
  }
  else {
    do {
      while (p_Var15 = p_Var14, aiStack_108[0] <= *(int *)(p_Var15 + 0x20)) {
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var20 = p_Var15;
        if (*(_Rb_tree_node_base **)(p_Var15 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00112792;
      }
      p_Var17 = p_Var15 + 0x18;
      p_Var14 = *(_Rb_tree_node_base **)p_Var17;
      p_Var15 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_00112792:
    if ((p_Var19 == p_Var15) || (aiStack_108[0] < *(int *)(p_Var15 + 0x20))) goto LAB_0011279c;
  }
  *(uint *)(p_Var15 + 0x24) = uVar24;
LAB_00112819:
  if (pcStack_80 != (code *)0x0) {
    (*pcStack_80)(auStack_90,auStack_90,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 109  00107530  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler___________
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr, unique_ptr * param_1)
{
  (*(code *)
    PTR__M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler_00325370
  )();
  return;
}





// ------------------------------------------------------------------
// IDX 110  00107540  deflateInit2_
// ------------------------------------------------------------------
void rea_deflateInit2(void)
{
  (*(code *)PTR_deflateInit2__00325378)();
  return;
}





// ------------------------------------------------------------------
// IDX 111  00107550  memmem
// ------------------------------------------------------------------
void * rea_memmem(void * __haystack, size_t __haystacklen, void * __needle, size_t __needlelen)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmem_00325380)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 112  00107560  EventLoop2__EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__EventLoop2(EventLoop2 * this_ptr)
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_vtable_00324f00;
  *(undefined8 *)(this_ptr + 8) = 0;
  *(undefined8 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x20) = 0;
  *(undefined8 *)(this_ptr + 0x28) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined8 *)(this_ptr + 0x38) = 0;
  *(undefined **)this_ptr = puVar1 + 0x10;
  *(undefined8 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  this_ptr[0x54] = (EventLoop2)0x1;
  *(undefined4 *)(this_ptr + 0x58) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 1000000;
  iVar2 = rea_epoll_create1(0x80000);
  *(int *)(this_ptr + 0x50) = iVar2;
  if (iVar2 < 0) {
    rea_perror("epoll_create1");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  return;
}





// ------------------------------------------------------------------
// IDX 113  00107570  remove
// ------------------------------------------------------------------
int rea_remove(char * __filename)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_remove_00325390)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 114  00107580  strncpy
// ------------------------------------------------------------------
char * rea_strncpy(char * __dest, char * __src, size_t __n)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strncpy_00325398)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 115  00107590  PyTuple_New
// ------------------------------------------------------------------
undefined8 rea_PyTuple_New(...)
{
  (*(code *)PTR_PyTuple_New_003253a0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 116  001075a0  std___Rb_tree_increment
// ------------------------------------------------------------------
void rea_std___Rb_tree_increment__dup2(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_increment_003253a8)();
  return;
}





// ------------------------------------------------------------------
// IDX 117  001075b0  __cxa_end_catch
// ------------------------------------------------------------------
void rea___cxa_end_catch(void)
{
  (*(code *)PTR___cxa_end_catch_003253b0)();
  return;
}





// ------------------------------------------------------------------
// IDX 118  001075c0  sigemptyset
// ------------------------------------------------------------------
int rea_sigemptyset(sigset_t * __set)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sigemptyset_003253b8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 119  001075d0  EventHandler__dtor_EventHandler
// ------------------------------------------------------------------
void rea_EventHandler__dtor_EventHandler(EventHandler * this_ptr)
{
  (*(code *)PTR__EventHandler_003253c0)();
  return;
}





// ------------------------------------------------------------------
// IDX 120  001075e0  __cxa_begin_catch
// ------------------------------------------------------------------
void rea___cxa_begin_catch(void)
{
  (*(code *)PTR___cxa_begin_catch_003253c8)();
  return;
}





// ------------------------------------------------------------------
// IDX 121  001075f0  WSConn__read_head
// ------------------------------------------------------------------
void rea_WSConn__read_head(WSConn * this_ptr, long param_2)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *apuStack_68 [2];
  code *pcStack_58;
  code *pcStack_50;
  WSConn *pWStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  code *pcStack_30;
  undefined8 uStack_28;
  
  pcStack_30 = (code *)0x0;
  pWStack_48 = this_ptr;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(&uStack_40,param_2,2);
    uStack_28 = *(undefined8 *)(param_2 + 0x18);
    pcStack_30 = *(code **)(param_2 + 0x10);
  }
  pcStack_58 = (code *)0x0;
  apuStack_68[0] = rea_operator_new(0x28);
  pcVar4 = pcStack_30;
  apuStack_68[0][3] = 0;
  uVar1 = apuStack_68[0][1];
  uVar2 = apuStack_68[0][2];
  uVar3 = apuStack_68[0][4];
  *apuStack_68[0] = pWStack_48;
  apuStack_68[0][2] = uStack_38;
  apuStack_68[0][1] = uStack_40;
  pcStack_30 = (code *)0x0;
  apuStack_68[0][3] = pcVar4;
  apuStack_68[0][4] = uStack_28;
  pcStack_50 = FUN_001114a0;
  pcStack_58 = FUN_0010e700;
  uStack_40 = uVar1;
  uStack_38 = uVar2;
  uStack_28 = uVar3;
  recv_more(this_ptr,2,apuStack_68);
  if (pcStack_58 != (code *)0x0) {
    (*pcStack_58)(apuStack_68,apuStack_68,3);
  }
  if (pcStack_30 != (code *)0x0) {
    (*pcStack_30)(&uStack_40,&uStack_40,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 122  00107600  bind
// ------------------------------------------------------------------
int rea_bind(int __fd, sockaddr * __addr, socklen_t __len)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_bind_003253d8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 123  00107610  fwrite
// ------------------------------------------------------------------
size_t rea_fwrite(void * __ptr, size_t __size, size_t __n, FILE * __s)
{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_003253e0)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 124  00107620  std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler________________
// ------------------------------------------------------------------
void rea_std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler(void)
{
  (*(code *)
    PTR__M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_003253e8
  )();
  return;
}





// ------------------------------------------------------------------
// IDX 125  00107630  perror
// ------------------------------------------------------------------
void rea_perror(char * __s)
{
  (*(code *)PTR_perror_003253f0)();
  return;
}





// ------------------------------------------------------------------
// IDX 126  00107640  fprintf
// ------------------------------------------------------------------
int rea_fprintf(FILE * __stream, char * __format, undefined8 param_x2)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fprintf_003253f8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 127  00107650  write
// ------------------------------------------------------------------
ssize_t rea_write(int __fd, void * __buf, size_t __n)
{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_00325400)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 128  00107660  operator_new
// ------------------------------------------------------------------
void * rea_operator__new(ulong param_1)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new_00325408)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 129  00107670  _Unwind_Resume
// ------------------------------------------------------------------
void rea__Unwind_Resume(...)
{
  (*(code *)PTR__Unwind_Resume_00325410)();
  return;
}





// ------------------------------------------------------------------
// IDX 130  00107680  accept
// ------------------------------------------------------------------
int rea_accept(int __fd, sockaddr * __addr, socklen_t * __addr_len)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_accept_00325418)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 131  00107690  EventLoop2__add
// ------------------------------------------------------------------
void rea_EventLoop2__add(EventLoop2 * this_ptr, EventHandler * param_1)
{
  undefined8 *puVar1;
  EventHandler *apEStack_18 [2];
  
  puVar1 = *(undefined8 **)(this_ptr + 0x28);
  apEStack_18[0] = param_1;
  if (puVar1 == *(undefined8 **)(this_ptr + 0x30)) {
    std_______vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler________M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________((vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler
                *)(this_ptr + 0x20),(unique_ptr *)apEStack_18);
  }
  else {
    if (puVar1 != (undefined8 *)0x0) {
      apEStack_18[0] = (EventHandler *)0x0;
      *puVar1 = param_1;
    }
    *(undefined8 **)(this_ptr + 0x28) = puVar1 + 1;
  }
  if (apEStack_18[0] != (EventHandler *)0x0) {
    (**(code **)(*(long *)apEStack_18[0] + 0x18))();
  }
  return;
}





// ------------------------------------------------------------------
// IDX 132  001076a0  std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase(_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn * this_ptr, _Rb_tree_node * param_1)
{
  (*(code *)PTR__M_erase_00325428)();
  return;
}





// ------------------------------------------------------------------
// IDX 133  001076b0  std__string___M_leak_hard
// ------------------------------------------------------------------
void rea_std__string___M_leak_hard(void)
{
  (*(code *)PTR__M_leak_hard_00325430)();
  return;
}





// ------------------------------------------------------------------
// IDX 134  001076c0  memcpy
// ------------------------------------------------------------------
void * rea_memcpy(void * __dest, void * __src, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00325438)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 135  001076d0  fcntl
// ------------------------------------------------------------------
int rea_fcntl(int __fd, int __cmd, undefined8 param_x2)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fcntl_00325440)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 136  001076e0  std__string__append
// ------------------------------------------------------------------
void rea_std__string__append__dup2(string * param_1)
{
  (*(code *)PTR_append_00325448)();
  return;
}





// ------------------------------------------------------------------
// IDX 137  001076f0  mkdir
// ------------------------------------------------------------------
int rea_mkdir(char * __path, __mode_t __mode)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mkdir_00325450)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 138  00107700  inet_addr
// ------------------------------------------------------------------
in_addr_t rea_inet_addr(char * __cp)
{
  in_addr_t iVar1;
  
  iVar1 = (*(code *)PTR_inet_addr_00325458)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 139  00107710  __gnu_cxx____to_xstring_std__string_char
// ------------------------------------------------------------------
void rea___gnu_cxx____to_xstring_std__string_char(code * param_1, ulong param_2, char * param_3, undefined8 param_x3)
{
  (*(code *)PTR___to_xstring_std__string_char_00325460)();
  return;
}





// ------------------------------------------------------------------
// IDX 140  00107720  current_time
// ------------------------------------------------------------------
long rea_current_time(void)
{
  timeval tStack_18;
  
  rea_gettimeofday(&tStack_18,(__timezone_ptr_t)0x0);
  return tStack_18.tv_sec * 1000000 + tStack_18.tv_usec;
}





// ------------------------------------------------------------------
// IDX 141  00107730  __gmon_start__
// ------------------------------------------------------------------
void rea___gmon_start(void)
{
  (*(code *)PTR___gmon_start___00324ed0)();
  return;
}





// ------------------------------------------------------------------
// IDX 142  00107738  __cxa_finalize
// ------------------------------------------------------------------
void rea___cxa_finalize(...)
{
  (*(code *)PTR___cxa_finalize_00324f28)();
  return;
}





// ------------------------------------------------------------------
// IDX 143  00107740  vsnprintf
// ------------------------------------------------------------------
int rea_vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_vsnprintf_00324f60)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 144  00107748  std___Function_base___Base_manager_WSConn__exit__lambda__3___M_manager___________
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager_WSConn__exit__lambda__3___M_manager(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324f50;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = rea_operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 145  00107750  entry
// ------------------------------------------------------------------
undefined8 rea_entry(void)
{
  undefined8 *in_RDI;
  
  if (in_RDI != (undefined8 *)0x0) {
    if ((void *)*in_RDI != (void *)0x0) {
      rea_operator_delete((void *)*in_RDI);
    }
    rea_operator_delete(in_RDI);
    return;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 146  00107772  FUN_00107772
// ------------------------------------------------------------------
void rea_FUN_00107772(undefined8 * param_1)
{
  if (param_1 != (undefined8 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      rea_operator_delete((void *)*param_1);
    }
    rea_operator_delete(param_1);
    return;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 147  00107794  FUN_00107794
// ------------------------------------------------------------------
void rea_FUN_00107794(undefined8 * param_1)
{
  if (param_1 != (undefined8 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      rea_operator_delete((void *)*param_1);
    }
    rea_operator_delete(param_1);
    return;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 148  001077c0  FUN_001077c0
// ------------------------------------------------------------------
void rea_FUN_001077c0(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 149  001077f0  FUN_001077f0
// ------------------------------------------------------------------
void rea_FUN_001077f0(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 150  00107830  _FINI_0
// ------------------------------------------------------------------
void rea__FINI_0(void)
{
  if (__bss_start == '\0') {
    if (PTR___cxa_finalize_00324f28 != (undefined *)0x0) {
      rea___cxa_finalize((void *)&PTR_LOOP_00324740);
    }
    rea_FUN_001077c0();
    __bss_start = '\x01';
  }
  return;
}





// ------------------------------------------------------------------
// IDX 151  00107870  _INIT_0
// ------------------------------------------------------------------
void rea__INIT_0(void)
{
  if ((DAT_00324718 != 0) && (PTR__Jv_RegisterClasses_00324ed8 != (undefined *)0x0)) {
    (*(code *)PTR__Jv_RegisterClasses_00324ed8)((void *)&DAT_00324718);
    rea_FUN_001077f0();
    return;
  }
  rea_FUN_001077f0();
  return;
}





// ------------------------------------------------------------------
// IDX 152  001078b0  FUN_001078b0
// ------------------------------------------------------------------
void rea_FUN_001078b0(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 153  001078c0  FUN_001078c0
// ------------------------------------------------------------------
void rea_FUN_001078c0(long * param_1)
{
  EventLoop2 *this_ptr;
  
  this_ptr = *(EventLoop2 **)*param_1;
  *(undefined1 *)((undefined8 *)*param_1)[1] = 1;
  rea_EventLoop2__exit(this_ptr,0);
  return;
}





// ------------------------------------------------------------------
// IDX 154  001078e0  FUN_001078e0
// ------------------------------------------------------------------
void rea_FUN_001078e0(undefined8 * param_1)
{
  EventLoop2 *this_ptr;
  
  this_ptr = *(EventLoop2 **)*param_1;
  *(undefined8 *)(this_ptr + 0x68) = 0;
  rea_EventLoop2__exit(this_ptr,0);
  return;
}





// ------------------------------------------------------------------
// IDX 155  00107900  FUN_00107900
// ------------------------------------------------------------------
undefined8 rea_FUN_00107900(long * param_1, long * param_2, int param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324770;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar1 = (undefined8 *)*param_2;
      puVar3 = rea_operator_new(0x10);
      uVar2 = puVar1[1];
      *puVar3 = *puVar1;
      puVar3[1] = uVar2;
      *param_1 = (long)puVar3;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 156  00107990  FUN_00107990
// ------------------------------------------------------------------
undefined8 rea_FUN_00107990(long * param_1, long * param_2, int param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324780;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar1 = (undefined8 *)*param_2;
      puVar3 = rea_operator_new(0x10);
      uVar2 = puVar1[1];
      *puVar3 = *puVar1;
      puVar3[1] = uVar2;
      *param_1 = (long)puVar3;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 157  00107a20  FUN_00107a20
// ------------------------------------------------------------------
undefined8 rea_FUN_00107a20(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (void *)&PTR_vtable_00324790;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = rea_operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 158  00107a90  FUN_00107a90
// ------------------------------------------------------------------
undefined8 rea_FUN_00107a90(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (void *)&PTR_vtable_003247a0;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = rea_operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 159  00107b10  FUN_00107b10
// ------------------------------------------------------------------
undefined8 rea_FUN_00107b10(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (void *)&PTR_vtable_003247b0;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = rea_operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 160  00107b90  FUN_00107b90
// ------------------------------------------------------------------
undefined8 rea_FUN_00107b90(long * param_1, long * param_2, int param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_003247c0;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar1 = (undefined8 *)*param_2;
      puVar3 = rea_operator_new(0x10);
      uVar2 = puVar1[1];
      *puVar3 = *puVar1;
      puVar3[1] = uVar2;
      *param_1 = (long)puVar3;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 161  00107c20  FUN_00107c20
// ------------------------------------------------------------------
undefined8 rea_FUN_00107c20(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (void *)&PTR_vtable_003247d0;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = rea_operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 162  00107ca0  FUN_00107ca0
// ------------------------------------------------------------------
undefined8 rea_FUN_00107ca0(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (void *)&PTR_vtable_00324760;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = rea_operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 163  00107d20  FUN_00107d20
// ------------------------------------------------------------------
void rea_FUN_00107d20(long * param_1, undefined4 * param_2)
{
  int *piVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  lVar2 = *(long *)(param_2 + 2);
  *(undefined **)(param_2 + 2) = PTR__S_empty_rep_storage_00324fa0 + 0x18;
  puVar3 = (undefined8 *)*param_1;
  puVar4 = (undefined4 *)puVar3[1];
  *puVar4 = *param_2;
  rea_std__string__assign((string *)(puVar4 + 2));
  rea_EventLoop2__exit((EventLoop2 *)*puVar3,0);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar5) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar6 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 164  00107dd0  FUN_00107dd0
// ------------------------------------------------------------------
void rea_FUN_00107dd0(undefined8 * param_1)
{
  int *piVar1;
  undefined4 uVar2;
  long lVar3;
  void *pvVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  int iVar8;
  _List_node_base *p_Var9;
  undefined *local_50;
  undefined4 local_48 [2];
  long local_40;
  
  *param_1 = (void *)&PTR_FUN_00324730;
  if (*(char *)(param_1 + 1) != '\0') {
    rea_std__string__string((string *)&local_50,"",(allocator *)local_48);
    lVar3 = param_1[2];
    p_Var9 = rea_operator_new(0x20);
    puVar7 = PTR__S_empty_rep_storage_00324fa0;
    if (p_Var9 != (_List_node_base *)0x0) {
      *(undefined8 *)p_Var9 = 0;
      *(undefined8 *)(p_Var9 + 8) = 0;
      *(undefined4 *)(p_Var9 + 0x10) = 0xffffffff;
      *(undefined **)(p_Var9 + 0x18) = local_50;
      local_50 = puVar7 + 0x18;
    }
    rea_std____detail___List_node_base___M_hook(p_Var9);
    if ((*(char *)(lVar3 + 0xb8) != '\0') &&
       (pvVar4 = *(void **)(lVar3 + 0xa8), (void *)(lVar3 + 0xa8) != pvVar4)) {
      uVar2 = *(undefined4 *)((long)pvVar4 + 0x10);
      lVar5 = *(long *)((long)pvVar4 + 0x18);
      *(undefined **)((long)pvVar4 + 0x18) = puVar7 + 0x18;
      rea_std____detail___List_node_base___M_unhook();
      lVar6 = *(long *)((long)pvVar4 + 0x18);
      if ((allocator *)(lVar6 + -0x18) != (allocator *)puVar7) {
        piVar1 = (int *)(lVar6 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (*(long *)(lVar3 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_48[0] = uVar2;
      local_40 = lVar5;
      (**(code **)(lVar3 + 0xd8))(lVar3 + 0xc0,(allocator *)local_48);
      if ((allocator *)(local_40 + -0x18) != (allocator *)puVar7) {
        piVar1 = (int *)(local_40 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
  *param_1 = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 165  00108060  FUN_00108060
// ------------------------------------------------------------------
void rea_FUN_00108060(undefined8 * param_1)
{
  int *piVar1;
  undefined4 uVar2;
  long lVar3;
  void *pvVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  int iVar8;
  _List_node_base *p_Var9;
  undefined *local_50;
  undefined4 local_48 [2];
  long local_40;
  
  *param_1 = (void *)&PTR_FUN_00324730;
  if (*(char *)(param_1 + 1) != '\0') {
    rea_std__string__string((string *)&local_50,"",(allocator *)local_48);
    lVar3 = param_1[2];
    p_Var9 = rea_operator_new(0x20);
    puVar7 = PTR__S_empty_rep_storage_00324fa0;
    if (p_Var9 != (_List_node_base *)0x0) {
      *(undefined8 *)p_Var9 = 0;
      *(undefined8 *)(p_Var9 + 8) = 0;
      *(undefined4 *)(p_Var9 + 0x10) = 0xffffffff;
      *(undefined **)(p_Var9 + 0x18) = local_50;
      local_50 = puVar7 + 0x18;
    }
    rea_std____detail___List_node_base___M_hook(p_Var9);
    if ((*(char *)(lVar3 + 0xb8) != '\0') &&
       (pvVar4 = *(void **)(lVar3 + 0xa8), (void *)(lVar3 + 0xa8) != pvVar4)) {
      uVar2 = *(undefined4 *)((long)pvVar4 + 0x10);
      lVar5 = *(long *)((long)pvVar4 + 0x18);
      *(undefined **)((long)pvVar4 + 0x18) = puVar7 + 0x18;
      rea_std____detail___List_node_base___M_unhook();
      lVar6 = *(long *)((long)pvVar4 + 0x18);
      if ((allocator *)(lVar6 + -0x18) != (allocator *)puVar7) {
        piVar1 = (int *)(lVar6 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (*(long *)(lVar3 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_48[0] = uVar2;
      local_40 = lVar5;
      (**(code **)(lVar3 + 0xd8))(lVar3 + 0xc0,(allocator *)local_48);
      if ((allocator *)(local_40 + -0x18) != (allocator *)puVar7) {
        piVar1 = (int *)(local_40 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
  *param_1 = PTR_vtable_00324ef0 + 0x10;
  rea_operator_delete(param_1);
  return;
}





// ------------------------------------------------------------------
// IDX 166  00108300  FUN_00108300
// ------------------------------------------------------------------
void rea_FUN_00108300(undefined8 * param_1)
{
  int *piVar1;
  undefined4 uVar2;
  long *plVar3;
  long lVar4;
  void *pvVar5;
  long lVar6;
  long lVar7;
  undefined *puVar8;
  int iVar9;
  long lVar10;
  _List_node_base *p_Var11;
  undefined *local_50;
  undefined4 local_48 [2];
  long local_40;
  
  plVar3 = (long *)*param_1;
  if ((*(long *)(*plVar3 + 0xe8) == 0) ||
     (lVar10 = rea_current_time(), lVar10 - *(long *)(*plVar3 + 0xe0) <= *(long *)(*plVar3 + 0xe8))) {
    return;
  }
  rea_std__string__string((string *)&local_50,"",(allocator *)local_48);
  lVar4 = *plVar3;
  p_Var11 = rea_operator_new(0x20);
  puVar8 = PTR__S_empty_rep_storage_00324fa0;
  if (p_Var11 != (_List_node_base *)0x0) {
    *(undefined8 *)p_Var11 = 0;
    *(undefined8 *)(p_Var11 + 8) = 0;
    *(undefined4 *)(p_Var11 + 0x10) = 1;
    *(undefined **)(p_Var11 + 0x18) = local_50;
    local_50 = puVar8 + 0x18;
  }
  rea_std____detail___List_node_base___M_hook(p_Var11);
  if ((*(char *)(lVar4 + 0xb8) != '\0') &&
     (pvVar5 = *(void **)(lVar4 + 0xa8), (void *)(lVar4 + 0xa8) != pvVar5)) {
    uVar2 = *(undefined4 *)((long)pvVar5 + 0x10);
    lVar6 = *(long *)((long)pvVar5 + 0x18);
    *(undefined **)((long)pvVar5 + 0x18) = puVar8 + 0x18;
    rea_std____detail___List_node_base___M_unhook();
    lVar7 = *(long *)((long)pvVar5 + 0x18);
    if ((allocator *)(lVar7 + -0x18) != (allocator *)puVar8) {
      piVar1 = (int *)(lVar7 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar9 = *(int *)(lVar7 + -8);
        *(int *)(lVar7 + -8) = iVar9 + -1;
      }
      else {
        LOCK();
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar9 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar7 + -0x18));
      }
    }
    rea_operator_delete(pvVar5);
    *(undefined1 *)(lVar4 + 0xb8) = 0;
    if (*(long *)(lVar4 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    local_48[0] = uVar2;
    local_40 = lVar6;
    (**(code **)(lVar4 + 0xd8))(lVar4 + 0xc0,(allocator *)local_48);
    if ((allocator *)(local_40 + -0x18) != (allocator *)puVar8) {
      piVar1 = (int *)(local_40 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar9 = *(int *)(local_40 + -8);
        *(int *)(local_40 + -8) = iVar9 + -1;
      }
      else {
        LOCK();
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar9 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_40 + -0x18));
      }
    }
  }
  if ((allocator *)(local_50 + -0x18) != (allocator *)puVar8) {
    piVar1 = (int *)(local_50 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar9 = *(int *)(local_50 + -8);
      *(int *)(local_50 + -8) = iVar9 + -1;
    }
    else {
      LOCK();
      iVar9 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar9 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_50 + -0x18));
    }
  }
  *(long *)(*plVar3 + 0xe0) = lVar10;
  return;
}





// ------------------------------------------------------------------
// IDX 167  001085c0  FUN_001085c0
// ------------------------------------------------------------------
undefined4 * rea_FUN_001085c0(double param_1, undefined4 * param_2, EventLoop2 * param_3)
{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  EventLoop2 *pEVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 local_98 [2];
  undefined8 local_90;
  undefined4 local_88 [2];
  long local_80;
  undefined8 *local_78 [2];
  code *local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  
  if ((param_3 == (EventLoop2 *)0x0) || (*(long *)(param_3 + 0x68) == 0)) {
    *param_2 = 0xffffffff;
    rea_std__string__string((string *)(param_2 + 2),"",(allocator *)&local_58);
  }
  else {
    local_98[0] = 0xffffffff;
    rea_std__string__string((string *)&local_90,"",(allocator *)&local_58);
    *(long *)(param_3 + 0xe8) = (long)(param_1 * _DAT_0011f630);
    uVar8 = rea_current_time();
    *(undefined8 *)(param_3 + 0xe0) = uVar8;
    local_68 = (code *)0x0;
    local_78[0] = rea_operator_new(0x10);
    *local_78[0] = param_3;
    local_78[0][1] = local_98;
    local_48 = (code *)0x0;
    local_60 = FUN_00107d20;
    local_68 = FUN_00107900;
    rea_FUN_00107900((allocator *)&local_58,local_78,2);
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
    if (local_48 != (code *)0x0) {
      (*local_48)((allocator *)&local_58,(allocator *)&local_58,3);
    }
    pEVar4 = *(EventLoop2 **)(param_3 + 0xa8);
    param_3[0xb8] = (EventLoop2)0x1;
    if (pEVar4 != param_3 + 0xa8) {
      uVar2 = *(undefined4 *)(pEVar4 + 0x10);
      lVar5 = *(long *)(pEVar4 + 0x18);
      *(undefined **)(pEVar4 + 0x18) = PTR__S_empty_rep_storage_00324fa0 + 0x18;
      rea_std____detail___List_node_base___M_unhook();
      lVar6 = *(long *)(pEVar4 + 0x18);
      if ((allocator *)(lVar6 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(lVar6 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (*(long *)(param_3 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_88[0] = uVar2;
      local_80 = lVar5;
      (**(code **)(param_3 + 0xd8))(param_3 + 0xc0,local_88);
      if ((allocator *)(local_80 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(local_80 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
    if (local_68 != (code *)0x0) {
      (*local_68)(local_78,local_78,3);
    }
    local_48 = (code *)0x0;
    rea_EventLoop2__run(param_3,(allocator *)&local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)((allocator *)&local_58,(allocator *)&local_58,3);
    }
    *param_2 = local_98[0];
    *(undefined8 *)(param_2 + 2) = local_90;
  }
  return param_2;
}





// ------------------------------------------------------------------
// IDX 168  00108990  FUN_00108990
// ------------------------------------------------------------------
undefined8 rea_FUN_00108990(undefined8 param_1, undefined8 param_2)
{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_198 [2];
  long local_188 [2];
  undefined2 local_178 [4];
  long local_170;
  _union_1457 local_168;
  sigset_t local_160;
  undefined4 local_e0;
  sigaction local_c8;
  
  local_168.sa_handler = (__sighandler_t)0x0;
  local_e0 = 0;
  rea_sigemptyset(&local_160);
  rea_sigaction(2,(sigaction *)&local_168,&local_c8);
  local_178[0] = 0x4f;
  iVar3 = rea_PyArg_ParseTuple(param_2,local_178,local_198);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = rea_PyLong_AsVoidPtr(local_198[0]);
    rea_FUN_001085c0(0,local_178,uVar4);
    rea_std__string__string((string *)local_188,(string *)&local_170);
    puVar2 = PTR__S_empty_rep_storage_00324fa0;
    if ((allocator *)(local_170 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_170 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar3 = *(int *)(local_170 + -8);
        *(int *)(local_170 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_170 + -0x18));
      }
    }
    uVar4 = rea_PyString_FromStringAndSize(local_188[0],*(undefined8 *)(local_188[0] + -0x18));
    if ((allocator *)(local_188[0] + -0x18) != (allocator *)puVar2) {
      piVar1 = (int *)(local_188[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar3 = *(int *)(local_188[0] + -8);
        *(int *)(local_188[0] + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_188[0] + -0x18));
      }
    }
  }
  rea_sigaction(2,&local_c8,(sigaction *)0x0);
  return uVar4;
}





// ------------------------------------------------------------------
// IDX 169  00108b30  FUN_00108b30
// ------------------------------------------------------------------
long rea_FUN_00108b30(undefined8 param_1, undefined8 param_2)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 local_48 [2];
  undefined8 local_38 [2];
  undefined4 local_28;
  long local_20;
  
  uVar2 = (uint)local_28 >> 0x10;
  local_28 = CONCAT22((ushort)uVar2 & 0xff00,0x4f4f);
  iVar3 = rea_PyArg_ParseTuple(param_2,&local_28,local_48,local_38);
  if (iVar3 != 0) {
    uVar6 = rea_PyFloat_AsDouble(local_38[0]);
    uVar4 = rea_PyLong_AsVoidPtr(local_48[0]);
    rea_FUN_001085c0(uVar6,&local_28,uVar4);
    uVar4 = rea_Py_BuildValue("l",(long)local_28);
    uVar6 = rea_PyString_FromStringAndSize(local_20,*(undefined8 *)(local_20 + -0x18));
    lVar5 = rea_PyTuple_New(2);
    *(undefined8 *)(lVar5 + 0x18) = uVar4;
    *(undefined8 *)(lVar5 + 0x20) = uVar6;
    if ((allocator *)(local_20 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_20 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar3 = *(int *)(local_20 + -8);
        *(int *)(local_20 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_20 + -0x18));
      }
    }
    return lVar5;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 170  00108c70  FUN_00108c70
// ------------------------------------------------------------------
void rea_FUN_00108c70(long * param_1)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  long *plVar8;
  _Rb_tree_node_base *p_Var9;
  _Rb_tree_node_base *p_Var10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  _Rb_tree_node_base *p_Var14;
  bool bVar15;
  long *local_78;
  undefined8 local_70;
  code *local_68;
  code *pcStack_60;
  undefined8 *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  
  param_1 = (long *)*param_1;
  lVar3 = *param_1;
  lVar12 = param_1[1];
  *(undefined8 *)(lVar3 + 0xe0) = 0;
  *(long *)(lVar3 + 0x68) = lVar12;
  *(undefined8 *)(lVar3 + 0xe8) = 0;
  plVar8 = rea_operator_new(0x18);
  lVar12 = *param_1;
  plVar8[2] = lVar3;
  *(undefined1 *)(plVar8 + 1) = 1;
  *plVar8 = (long)(void *)&PTR_FUN_00324730;
  lVar3 = *(long *)(lVar12 + 0x68);
  p_Var2 = (_Rb_tree_node_base *)(lVar3 + 0x10);
  p_Var10 = p_Var2;
  p_Var14 = *(_Rb_tree_node_base **)(lVar3 + 0x18);
  if (*(_Rb_tree_node_base **)(lVar3 + 0x18) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var9 = p_Var14, plVar8 <= *(long **)(p_Var9 + 0x20)) {
        p_Var10 = p_Var9;
        p_Var14 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
        if (*(_Rb_tree_node_base **)(p_Var9 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_00108d03;
      }
      p_Var1 = p_Var9 + 0x18;
      p_Var9 = p_Var10;
      p_Var14 = *(_Rb_tree_node_base **)p_Var1;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_00108d03:
    if ((p_Var2 != p_Var9) && (*(long **)(p_Var9 + 0x20) <= plVar8)) goto LAB_00108d19;
  }
  p_Var10 = rea_operator_new(0x30);
  if (p_Var10 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var10 = 0;
    *(undefined8 *)(p_Var10 + 8) = 0;
    *(undefined8 *)(p_Var10 + 0x10) = 0;
    *(undefined8 *)(p_Var10 + 0x18) = 0;
    *(long **)(p_Var10 + 0x20) = plVar8;
    *(long **)(p_Var10 + 0x28) = plVar8;
    plVar8 = (long *)0x0;
  }
  p_Var14 = p_Var2;
  if (*(_Rb_tree_node_base **)(lVar3 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00108fe2:
    if (*(_Rb_tree_node_base **)(lVar3 + 0x20) != p_Var14) {
      lVar12 = rea_std___Rb_tree_decrement(p_Var14);
      uVar13 = *(ulong *)(lVar12 + 0x20);
      uVar11 = *(ulong *)(p_Var10 + 0x20);
      goto LAB_00108fa5;
    }
LAB_00108ffb:
    if (p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_00108faa;
    if (p_Var2 == p_Var14) {
      bVar15 = true;
    }
    else {
      bVar15 = *(ulong *)(p_Var10 + 0x20) < *(ulong *)(p_Var14 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var14,p_Var2);
    *(long *)(lVar3 + 0x30) = *(long *)(lVar3 + 0x30) + 1;
  }
  else {
    uVar11 = *(ulong *)(p_Var10 + 0x20);
    p_Var9 = *(_Rb_tree_node_base **)(lVar3 + 0x18);
    do {
      p_Var14 = p_Var9;
      uVar13 = *(ulong *)(p_Var14 + 0x20);
      if (uVar11 < uVar13) {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      }
      else {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
      }
    } while (p_Var9 != (_Rb_tree_node_base *)0x0);
    if (uVar11 < uVar13) goto LAB_00108fe2;
LAB_00108fa5:
    if (uVar13 < uVar11) goto LAB_00108ffb;
LAB_00108faa:
    if (*(long **)(p_Var10 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(p_Var10 + 0x28) + 8))();
    }
    *(undefined8 *)(p_Var10 + 0x28) = 0;
    rea_operator_delete(p_Var10);
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 8))(plVar8);
  }
  lVar12 = *param_1;
LAB_00108d19:
  local_68 = (code *)0x0;
  local_78 = rea_operator_new(8);
  *local_78 = lVar12;
  pcStack_60 = FUN_00108300;
  local_68 = FUN_00107c20;
  lVar3 = *(long *)(*(long *)(*param_1 + 0x68) + 0x38);
  local_48 = (code *)0x0;
  rea_FUN_00107c20(&local_58,&local_78,2);
  puVar4 = *(undefined8 **)(lVar3 + 0xb0);
  uVar5 = *(undefined8 *)(lVar3 + 0xb8);
  local_48 = *(code **)(lVar3 + 0xc0);
  *(undefined8 **)(lVar3 + 0xb0) = local_58;
  *(undefined8 *)(lVar3 + 0xb8) = local_50;
  puStack_40 = *(undefined **)(lVar3 + 200);
  *(code **)(lVar3 + 0xc0) = local_68;
  *(code **)(lVar3 + 200) = pcStack_60;
  local_58 = puVar4;
  local_50 = uVar5;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  lVar3 = *param_1;
  local_68 = (code *)0x0;
  local_78 = rea_operator_new(8);
  *local_78 = lVar3;
  local_48 = (code *)0x0;
  pcStack_60 = FUN_001093b0;
  local_68 = FUN_00107ca0;
  local_58 = rea_operator_new(0x20);
  pcVar7 = local_68;
  local_58[2] = 0;
  plVar8 = (long *)*local_58;
  uVar5 = local_58[1];
  *local_58 = local_78;
  local_58[1] = local_70;
  local_68 = (code *)0x0;
  uVar6 = local_58[3];
  local_58[2] = pcVar7;
  local_58[3] = pcStack_60;
  puStack_40 = PTR__M_invoke_00324fe0;
  local_48 = (code *)PTR__M_manager_00324f88;
  local_78 = plVar8;
  local_70 = uVar5;
  pcStack_60 = (code *)uVar6;
  rea_WSConn__recv(*(WSConn **)(*param_1 + 0x68),&local_58);
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  rea_EventLoop2__exit((EventLoop2 *)*param_1,1);
  return;
}





// ------------------------------------------------------------------
// IDX 171  00109120  initbbwebsocket
// ------------------------------------------------------------------
void rea_initbbwebsocket(void)
{
  rea_Py_InitModule4_64("bbwebsocket",(void *)&PTR_s_connect_0011f2df_3_00325480,0,0,0x3f5);
  return;
}





// ------------------------------------------------------------------
// IDX 172  00109140  FUN_00109140
// ------------------------------------------------------------------
void rea_FUN_00109140(undefined8 * param_1, long param_2)
{
  long *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined *puVar4;
  long lVar5;
  WSConn *pWVar6;
  undefined8 *puVar7;
  long lVar8;
  long lVar9;
  WSConn *local_58 [2];
  WSConn *local_48 [2];
  code *local_38;
  code *local_30;
  
  param_1 = (undefined8 *)*param_1;
  pWVar6 = rea_operator_new(0x70);
  *(undefined4 *)(pWVar6 + 0x10) = 0;
  *(long *)(pWVar6 + 0x18) = 0;
  *(long *)(pWVar6 + 0x30) = 0;
  *(long *)(pWVar6 + 0x38) = param_2;
  *(long *)(pWVar6 + 0x40) = 0;
  *(long *)(pWVar6 + 0x48) = 0;
  *(WSConn **)(pWVar6 + 0x20) = pWVar6 + 0x10;
  *(WSConn **)(pWVar6 + 0x28) = pWVar6 + 0x10;
  puVar4 = PTR_vtable_00324f30;
  *(long *)(pWVar6 + 0x50) = 0;
  pWVar6[0x58] = (WSConn)0x0;
  *(undefined **)pWVar6 = puVar4 + 0x10;
  puVar7 = rea_operator_new(0x18);
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar2 = *(undefined8 **)(pWVar6 + 0x40);
  *(undefined8 **)(pWVar6 + 0x40) = puVar7;
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      rea_operator_delete((void *)*puVar2);
    }
    rea_operator_delete(puVar2);
  }
  lVar8 = param_2 + 0x10;
  lVar5 = *(long *)(param_2 + 0x18);
  local_58[0] = pWVar6;
  if (*(long *)(param_2 + 0x18) != 0) {
    do {
      while (lVar9 = lVar5, pWVar6 <= *(WSConn **)(lVar9 + 0x20)) {
        lVar8 = lVar9;
        lVar5 = *(long *)(lVar9 + 0x10);
        if (*(long *)(lVar9 + 0x10) == 0) goto LAB_0010922b;
      }
      plVar1 = (long *)(lVar9 + 0x18);
      lVar9 = lVar8;
      lVar5 = *plVar1;
    } while (*plVar1 != 0);
LAB_0010922b:
    if ((param_2 + 0x10 != lVar9) && (*(WSConn **)(lVar9 + 0x20) <= pWVar6)) goto LAB_00109236;
  }
  local_48[0] = pWVar6;
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root_____________((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(param_2 + 8),local_58,(unique_ptr *)local_48);
  if (local_48[0] != (WSConn *)0x0) {
    (**(code **)(*(long *)local_48[0] + 8))();
  }
LAB_00109236:
  pWVar6 = local_58[0];
  uVar3 = *param_1;
  local_38 = (code *)0x0;
  local_48[0] = rea_operator_new(0x10);
  *(undefined8 *)local_48[0] = uVar3;
  *(WSConn **)(local_48[0] + 8) = pWVar6;
  local_30 = FUN_00108c70;
  local_38 = FUN_00107b90;
  rea_WSConn__connect(pWVar6,local_48);
  if (local_38 != (code *)0x0) {
    (*local_38)(local_48,local_48,3);
  }
  return;
}





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
  long *plVar9;
  ulong *puVar10;
  ulong *puVar11;
  void *pvVar12;
  long lVar13;
  long lVar14;
  code *pcVar15;
  int iVar16;
  ulong *puVar17;
  _List_node_base *p_Var18;
  ulong uVar19;
  long lVar20;
  ulong uVar21;
  allocator *paVar22;
  ulong uVar23;
  allocator local_cb [3];
  ulong *local_c8 [2];
  undefined4 local_b8;
  allocator *local_b0;
  undefined4 local_a8 [2];
  long local_a0;
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
  plVar9 = (long *)*param_1;
  local_98 = uVar6;
  local_90 = uVar7;
  uStack_80 = uVar8;
  if (puVar5 == (undefined8 *)0x0) {
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
      uVar23 = (long)puVar10 - (long)puVar11;
      puVar17 = (ulong *)rea_std__string___Rep___S_create(uVar23,0,local_cb);
      local_c8[0] = puVar17 + 3;
      if ((uVar23 < 0x10) || (local_c8[0] < puVar11 + 2 && puVar11 < puVar17 + 5)) {
        lVar20 = 0;
        do {
          *(undefined1 *)((long)local_c8[0] + lVar20) = *(undefined1 *)((long)puVar11 + lVar20);
          lVar20 = lVar20 + 1;
        } while (lVar20 != (long)puVar10 - (long)puVar11);
      }
      else {
        lVar20 = 0;
        uVar21 = 0;
        uVar19 = uVar23 >> 4;
        do {
          uVar6 = ((undefined8 *)((long)puVar11 + lVar20))[1];
          uVar21 = uVar21 + 1;
          *(undefined8 *)((long)local_c8[0] + lVar20) = *(undefined8 *)((long)puVar11 + lVar20);
          ((undefined8 *)((long)local_c8[0] + lVar20))[1] = uVar6;
          lVar20 = lVar20 + 0x10;
        } while (uVar21 < uVar19);
        puVar11 = puVar11 + uVar19 * 2;
        puVar3 = local_c8[0] + uVar19 * 2;
        if (((((((uVar19 * 0x10 != uVar23) &&
                (*(char *)puVar3 = (char)*puVar11, puVar10 != (ulong *)((long)puVar11 + 1))) &&
               (*(undefined1 *)((long)puVar3 + 1) = *(undefined1 *)((long)puVar11 + 1),
               puVar10 != (ulong *)((long)puVar11 + 2))) &&
              ((*(undefined1 *)((long)puVar3 + 2) = *(undefined1 *)((long)puVar11 + 2),
               puVar10 != (ulong *)((long)puVar11 + 3) &&
               (*(undefined1 *)((long)puVar3 + 3) = *(undefined1 *)((long)puVar11 + 3),
               puVar10 != (ulong *)((long)puVar11 + 4))))) &&
             ((*(undefined1 *)((long)puVar3 + 4) = *(undefined1 *)((long)puVar11 + 4),
              puVar10 != (ulong *)((long)puVar11 + 5) &&
              ((*(undefined1 *)((long)puVar3 + 5) = *(undefined1 *)((long)puVar11 + 5),
               puVar10 != (ulong *)((long)puVar11 + 6) &&
               (*(undefined1 *)((long)puVar3 + 6) = *(undefined1 *)((long)puVar11 + 6),
               puVar10 != (ulong *)((long)puVar11 + 7))))))) &&
            (*(undefined1 *)((long)puVar3 + 7) = *(undefined1 *)((long)puVar11 + 7),
            puVar10 != puVar11 + 1)) &&
           ((((*(char *)(puVar3 + 1) = (char)puVar11[1], puVar10 != (ulong *)((long)puVar11 + 9) &&
              (*(undefined1 *)((long)puVar3 + 9) = *(undefined1 *)((long)puVar11 + 9),
              puVar10 != (ulong *)((long)puVar11 + 10))) &&
             (*(undefined1 *)((long)puVar3 + 10) = *(undefined1 *)((long)puVar11 + 10),
             puVar10 != (ulong *)((long)puVar11 + 0xb))) &&
            (((*(undefined1 *)((long)puVar3 + 0xb) = *(undefined1 *)((long)puVar11 + 0xb),
              puVar10 != (ulong *)((long)puVar11 + 0xc) &&
              (*(undefined1 *)((long)puVar3 + 0xc) = *(undefined1 *)((long)puVar11 + 0xc),
              puVar10 != (ulong *)((long)puVar11 + 0xd))) &&
             (*(undefined1 *)((long)puVar3 + 0xd) = *(undefined1 *)((long)puVar11 + 0xd),
             puVar10 != (ulong *)((long)puVar11 + 0xe))))))) {
          *(undefined1 *)((long)puVar3 + 0xe) = *(undefined1 *)((long)puVar11 + 0xe);
        }
      }
      paVar22 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
      if (puVar17 != (ulong *)PTR__S_empty_rep_storage_00324fa0) {
        *(undefined4 *)(puVar17 + 2) = 0;
        *puVar17 = uVar23;
        *(undefined1 *)((long)puVar17 + uVar23 + 0x18) = 0;
      }
    }
    local_b8 = 0;
    rea_std__string__string((string *)&local_b0,(string *)local_c8);
    lVar20 = *plVar9;
    p_Var18 = rea_operator_new(0x20);
    if (p_Var18 != (_List_node_base *)0x0) {
      *(undefined8 *)p_Var18 = 0;
      *(undefined8 *)(p_Var18 + 8) = 0;
      *(undefined4 *)(p_Var18 + 0x10) = local_b8;
      *(allocator **)(p_Var18 + 0x18) = local_b0;
      local_b0 = paVar22 + 0x18;
    }
    rea_std____detail___List_node_base___M_hook(p_Var18);
    if ((*(char *)(lVar20 + 0xb8) != '\0') &&
       (pvVar12 = *(void **)(lVar20 + 0xa8), (void *)(lVar20 + 0xa8) != pvVar12)) {
      uVar4 = *(undefined4 *)((long)pvVar12 + 0x10);
      lVar13 = *(long *)((long)pvVar12 + 0x18);
      *(allocator **)((long)pvVar12 + 0x18) = paVar22 + 0x18;
      rea_std____detail___List_node_base___M_unhook();
      lVar14 = *(long *)((long)pvVar12 + 0x18);
      if ((allocator *)(lVar14 + -0x18) != paVar22) {
        piVar2 = (int *)(lVar14 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (*(long *)(lVar20 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_a8[0] = uVar4;
      local_a0 = lVar13;
      (**(code **)(lVar20 + 0xd8))(lVar20 + 0xc0,local_a8);
      if ((allocator *)(local_a0 + -0x18) != paVar22) {
        piVar2 = (int *)(local_a0 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
    local_68 = (code *)0x0;
    if (local_88 != (code *)0x0) {
      (*local_88)(&local_78,&local_98,2);
      local_68 = local_88;
      uStack_60 = uStack_80;
    }
    local_48 = (code *)0x0;
    local_58[0] = rea_operator_new(0x20);
    pcVar15 = local_68;
    local_58[0][2] = 0;
    uVar6 = *local_58[0];
    uVar7 = local_58[0][1];
    uVar8 = local_58[0][3];
    local_58[0][1] = local_70;
    *local_58[0] = local_78;
    local_68 = (code *)0x0;
    local_58[0][2] = pcVar15;
    local_58[0][3] = uStack_60;
    local_40 = PTR__M_invoke_00324fe0;
    local_48 = (code *)PTR__M_manager_00324f88;
    local_78 = uVar6;
    local_70 = uVar7;
    uStack_60 = uVar8;
    rea_WSConn__recv(*(WSConn **)(*plVar9 + 0x68),local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)(local_58,local_58,3);
    }
    if (local_68 != (code *)0x0) {
      (*local_68)(&local_78,&local_78,3);
    }
  }
  if (local_88 != (code *)0x0) {
    (*local_88)(&local_98,&local_98,3);
  }
  if (puVar5 != (undefined8 *)0x0) {
    if ((void *)*puVar5 != (void *)0x0) {
      rea_operator_delete((void *)*puVar5);
    }
    rea_operator_delete(puVar5);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 174  00109b10  FUN_00109b10
// ------------------------------------------------------------------
undefined8 rea_FUN_00109b10(undefined8 param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4, undefined8 param_5, undefined8 param_6)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  char *pcVar5;
  EventLoop2 *pEVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  char local_208 [16];
  undefined2 local_1f8;
  undefined1 local_1f6;
  undefined1 local_1e8;
  undefined1 local_1e7;
  undefined1 local_1e6;
  undefined8 local_1d8 [2];
  undefined8 local_1c8 [2];
  long local_1b8 [2];
  undefined8 *local_1a8 [2];
  undefined8 *local_198 [2];
  code *local_188;
  code *local_180;
  _union_1457 local_178;
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  local_178.sa_handler = (__sighandler_t)0x0;
  local_f0 = 0;
  rea_sigemptyset(&local_170);
  rea_sigaction(2,(sigaction *)&local_178,&local_d8);
  local_1f8 = 0x4f4f;
  local_1e6 = 0;
  local_1e8 = 0x4f;
  local_1e7 = 0x4f;
  local_1f6 = 0;
  uVar4 = (ulong)local_198[0] >> 0x10;
  local_198[0] = (undefined8 *)CONCAT62((uint6)uVar4 & 0xffffffffff00,0x4f4f);
  iVar3 = rea_PyArg_ParseTuple(param_2,(allocator *)local_198,local_1d8,local_1c8);
  if (iVar3 == 0) {
    uVar8 = 0;
  }
  else {
    uVar4 = rea_PyString_Size(local_1c8[0]);
    pcVar5 = (char *)rea_PyString_AsString(local_1c8[0]);
    rea_std__string__string((string *)local_1b8,pcVar5,uVar4,(allocator *)local_198);
    pEVar6 = (EventLoop2 *)rea_PyLong_AsVoidPtr(local_1d8[0]);
    if ((pEVar6 == (EventLoop2 *)0x0) || (*(long *)(pEVar6 + 0x68) == 0)) {
      uVar8 = 1;
    }
    else {
      local_208[0] = '\0';
      puVar7 = rea_operator_new(0x18);
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      uVar8 = 0;
      lVar2 = *(long *)(local_1b8[0] + -0x18);
      if (-1 < *(int *)(local_1b8[0] + -8)) {
        rea_std__string___M_leak_hard();
        uVar8 = puVar7[1];
      }
      std__vector_unsigned_char_std__allocator_unsigned_char__________M_range_insert___gnu_cxx____normal_iterator_char__std__string_________________(puVar7,uVar8,local_1b8[0],local_1b8[0] + lVar2,param_5,param_6,0);
      local_188 = (code *)0x0;
      local_198[0] = rea_operator_new(0x10);
      *local_198[0] = pEVar6;
      local_198[0][1] = local_208;
      local_180 = FUN_001078c0;
      local_188 = FUN_00107990;
      local_1a8[0] = puVar7;
      rea_WSConn__send(*(WSConn **)(pEVar6 + 0x68),local_1a8,(allocator *)local_198);
      puVar7 = local_1a8[0];
      if (local_1a8[0] != (undefined8 *)0x0) {
        if ((void *)*local_1a8[0] != (void *)0x0) {
          rea_operator_delete((void *)*local_1a8[0]);
        }
        rea_operator_delete(puVar7);
      }
      if (local_188 != (code *)0x0) {
        (*local_188)((allocator *)local_198,(allocator *)local_198,3);
      }
      while (local_208[0] == '\0') {
        while( true ) {
          local_188 = (code *)0x0;
          rea_EventLoop2__run(pEVar6,(allocator *)local_198);
          if (local_188 == (code *)0x0) break;
          (*local_188)((allocator *)local_198,(allocator *)local_198,3);
          if (local_208[0] != '\0') goto LAB_00109d4f;
        }
      }
LAB_00109d4f:
      uVar8 = 0;
    }
    if ((allocator *)(local_1b8[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_1b8[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
    uVar8 = rea_Py_BuildValue("l",uVar8);
  }
  rea_sigaction(2,&local_d8,(sigaction *)0x0);
  return uVar8;
}





// ------------------------------------------------------------------
// IDX 175  00109ea0  FUN_00109ea0
// ------------------------------------------------------------------
undefined8 rea_FUN_00109ea0(undefined8 param_1, undefined8 param_2)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_ptr;
  allocator *paVar2;
  int *piVar3;
  EventLoop2 *pEVar4;
  char cVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  EventLoop2 *pEVar9;
  undefined *puVar10;
  int iVar11;
  uint uVar12;
  EventLoop2 *this_00;
  _Rb_tree_node_base *p_Var13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  undefined8 uVar16;
  EventLoop2 *pEVar17;
  code *pcVar18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  code *pcVar22;
  long lVar23;
  _Rb_tree_node_base *p_Var24;
  uint uVar25;
  undefined1 auVar26 [16];
  int local_1d8 [4];
  undefined8 local_1c8 [2];
  void *local_1b8 [2];
  code *local_1a8;
  code *pcStack_1a0;
  undefined8 local_198;
  undefined8 local_190;
  code *local_188;
  code *pcStack_180;
  _union_1457 local_178;
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  local_178.sa_handler = (__sighandler_t)0x0;
  local_f0 = 0;
  rea_sigemptyset(&local_170);
  rea_sigaction(2,(sigaction *)&local_178,&local_d8);
  local_198 = CONCAT62((*(arr_undefined1_6 *)((uint8_t *)&local_198 + 0x2)),0x4f);
  iVar11 = rea_PyArg_ParseTuple(param_2,&local_198,local_1c8);
  if (iVar11 == 0) {
    uVar16 = 0;
    goto LAB_0010a3e6;
  }
  this_00 = (EventLoop2 *)rea_PyLong_AsVoidPtr(local_1c8[0]);
  if (this_00 != (EventLoop2 *)0x0) {
    if (*(long *)(this_00 + 0x68) != 0) {
      local_1a8 = (code *)0x0;
      local_1b8[0] = rea_operator_new(1);
      pcStack_1a0 = FUN_001078b0;
      local_1a8 = FUN_00107a20;
      lVar23 = *(long *)(*(long *)(this_00 + 0x68) + 0x38);
      if (*(char *)(lVar23 + 0x5a) != '\0') {
        rea_fwrite("close(): send_flag != false\n",1,0x1c,*(FILE **)PTR_stderr_00324fb0);
        rea_print_stack();
      }
      puVar7 = *(undefined8 **)(lVar23 + 0x60);
      *(undefined1 *)(lVar23 + 0x5a) = 1;
      *(undefined8 *)(lVar23 + 0x60) = 0;
      if (puVar7 != (undefined8 *)0x0) {
        if ((void *)*puVar7 != (void *)0x0) {
          rea_operator_delete((void *)*puVar7);
        }
        rea_operator_delete(puVar7);
      }
      local_188 = (code *)0x0;
      if (local_1a8 == (code *)0x0) {
        pcVar22 = (code *)0x0;
        pcVar18 = pcStack_180;
      }
      else {
        (*local_1a8)(&local_198,local_1b8,2);
        pcVar18 = pcStack_1a0;
        pcVar22 = local_1a8;
      }
      uVar16 = *(undefined8 *)(lVar23 + 0x68);
      uVar8 = *(undefined8 *)(lVar23 + 0x70);
      local_188 = *(code **)(lVar23 + 0x78);
      *(undefined8 *)(lVar23 + 0x68) = local_198;
      *(undefined8 *)(lVar23 + 0x70) = local_190;
      pcStack_180 = *(code **)(lVar23 + 0x80);
      *(code **)(lVar23 + 0x78) = pcVar22;
      *(code **)(lVar23 + 0x80) = pcVar18;
      local_198 = uVar16;
      local_190 = uVar8;
      if (local_188 != (code *)0x0) {
        (*local_188)(&local_198,&local_198,3);
      }
      cVar5 = *(char *)(lVar23 + 0x5a);
      local_1d8[0] = *(int *)(lVar23 + 0x40);
      lVar23 = *(long *)(lVar23 + 0x38);
      p_Var13 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
      p_Var15 = (_Rb_tree_node_base *)(lVar23 + 0x10);
      p_Var19 = p_Var13;
      p_Var24 = p_Var15;
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
LAB_0010a420:
        lVar14 = 0;
        uVar6 = 0;
      }
      else {
        do {
          while (p_Var20 = p_Var19, local_1d8[0] <= *(int *)(p_Var20 + 0x20)) {
            p_Var19 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
            p_Var24 = p_Var20;
            if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == (_Rb_tree_node_base *)0x0)
            goto LAB_0010a08a;
          }
          p_Var1 = p_Var20 + 0x18;
          p_Var19 = *(_Rb_tree_node_base **)p_Var1;
          p_Var20 = p_Var24;
        } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_0010a08a:
        if ((p_Var15 == p_Var20) || (p_Var19 = p_Var15, local_1d8[0] < *(int *)(p_Var20 + 0x20)))
        goto LAB_0010a420;
        do {
          while (p_Var24 = p_Var13, local_1d8[0] <= *(int *)(p_Var24 + 0x20)) {
            p_Var13 = *(_Rb_tree_node_base **)(p_Var24 + 0x10);
            p_Var19 = p_Var24;
            if (*(_Rb_tree_node_base **)(p_Var24 + 0x10) == (_Rb_tree_node_base *)0x0)
            goto LAB_0010a0ba;
          }
          p_Var20 = p_Var24 + 0x18;
          p_Var13 = *(_Rb_tree_node_base **)p_Var20;
          p_Var24 = p_Var19;
        } while (*(_Rb_tree_node_base **)p_Var20 != (_Rb_tree_node_base *)0x0);
LAB_0010a0ba:
        if ((p_Var15 == p_Var24) || (local_1d8[0] < *(int *)(p_Var24 + 0x20))) {
          p_Var13 = rea_operator_new(0x28);
          if (p_Var13 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var13 = 0;
            *(undefined8 *)(p_Var13 + 8) = 0;
            *(undefined8 *)(p_Var13 + 0x10) = 0;
            *(undefined8 *)(p_Var13 + 0x18) = 0;
            *(undefined4 *)(p_Var13 + 0x24) = 0;
            *(int *)(p_Var13 + 0x20) = local_1d8[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos_______________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                *)(lVar23 + 8),p_Var24,p_Var13 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
          p_Var19 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x8));
          p_Var24 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x0));
          if (p_Var19 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var13);
          }
          else {
            bVar21 = true;
            if ((p_Var24 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var19)) {
              bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var19 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var19,p_Var15);
            *(long *)(lVar23 + 0x30) = *(long *)(lVar23 + 0x30) + 1;
            p_Var24 = p_Var13;
          }
        }
        uVar6 = *(uint *)(p_Var24 + 0x24);
        lVar14 = 1;
      }
      lVar23 = lVar23 + (lVar14 + 1) * 0x30;
      this_ptr = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar23 + 8);
      p_Var15 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
      p_Var24 = (_Rb_tree_node_base *)(lVar23 + 0x10);
      p_Var13 = p_Var15;
      p_Var19 = p_Var24;
      uVar12 = uVar6;
      if (p_Var15 != (_Rb_tree_node_base *)0x0) {
        do {
          while (p_Var20 = p_Var13, local_1d8[0] <= *(int *)(p_Var20 + 0x20)) {
            p_Var13 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
            p_Var19 = p_Var20;
            if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == (_Rb_tree_node_base *)0x0)
            goto LAB_0010a1a2;
          }
          p_Var1 = p_Var20 + 0x18;
          p_Var13 = *(_Rb_tree_node_base **)p_Var1;
          p_Var20 = p_Var19;
        } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_0010a1a2:
        if ((p_Var24 != p_Var20) && (p_Var13 = p_Var24, *(int *)(p_Var20 + 0x20) <= local_1d8[0])) {
          do {
            while (p_Var19 = p_Var15, local_1d8[0] <= *(int *)(p_Var19 + 0x20)) {
              p_Var15 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
              p_Var13 = p_Var19;
              if (*(_Rb_tree_node_base **)(p_Var19 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010a1da;
            }
            p_Var20 = p_Var19 + 0x18;
            p_Var15 = *(_Rb_tree_node_base **)p_Var20;
            p_Var19 = p_Var13;
          } while (*(_Rb_tree_node_base **)p_Var20 != (_Rb_tree_node_base *)0x0);
LAB_0010a1da:
          if ((p_Var24 == p_Var19) || (local_1d8[0] < *(int *)(p_Var19 + 0x20))) {
            p_Var15 = rea_operator_new(0x28);
            if (p_Var15 != (_Rb_tree_node_base *)0x0) {
              *(undefined4 *)p_Var15 = 0;
              *(undefined8 *)(p_Var15 + 8) = 0;
              *(undefined8 *)(p_Var15 + 0x10) = 0;
              *(undefined8 *)(p_Var15 + 0x18) = 0;
              *(undefined4 *)(p_Var15 + 0x24) = 0;
              *(int *)(p_Var15 + 0x20) = local_1d8[0];
            }
            { auto &&__rea_tmp = (std__________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________________M_get_insert_hint_unique_pos(this_ptr,p_Var19,p_Var15 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
            p_Var13 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x8));
            p_Var19 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x0));
            if (p_Var13 == (_Rb_tree_node_base *)0x0) {
              rea_operator_delete(p_Var15);
            }
            else {
              bVar21 = true;
              if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var24 != p_Var13)) {
                bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var13 + 0x20);
              }
              rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var13,p_Var24);
              *(long *)(lVar23 + 0x30) = *(long *)(lVar23 + 0x30) + 1;
              p_Var19 = p_Var15;
            }
          }
          uVar12 = *(uint *)(p_Var19 + 0x24);
        }
      }
      uVar25 = uVar12 | 2;
      if (cVar5 == '\0') {
        uVar25 = uVar12 & 0xfffffffd;
      }
      if (uVar6 == uVar25) {
        std____________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___________erase(this_ptr,local_1d8);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
        p_Var19 = p_Var24;
        p_Var13 = p_Var24;
        if (*(_Rb_tree_node_base **)(lVar23 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010a251:
          p_Var15 = rea_operator_new(0x28);
          if (p_Var15 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var15 = 0;
            *(undefined8 *)(p_Var15 + 8) = 0;
            *(undefined8 *)(p_Var15 + 0x10) = 0;
            *(undefined8 *)(p_Var15 + 0x18) = 0;
            *(undefined4 *)(p_Var15 + 0x24) = 0;
            *(int *)(p_Var15 + 0x20) = local_1d8[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(this_ptr,p_Var13,p_Var15 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
          p_Var19 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x8));
          p_Var13 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x0));
          if (p_Var19 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var15);
          }
          else {
            bVar21 = true;
            if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var24 != p_Var19)) {
              bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var19 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var19,p_Var24);
            *(long *)(lVar23 + 0x30) = *(long *)(lVar23 + 0x30) + 1;
            p_Var13 = p_Var15;
          }
        }
        else {
          do {
            while (p_Var13 = p_Var15, local_1d8[0] <= *(int *)(p_Var13 + 0x20)) {
              p_Var15 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var19 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010a242;
            }
            p_Var20 = p_Var13 + 0x18;
            p_Var15 = *(_Rb_tree_node_base **)p_Var20;
            p_Var13 = p_Var19;
          } while (*(_Rb_tree_node_base **)p_Var20 != (_Rb_tree_node_base *)0x0);
LAB_0010a242:
          if ((p_Var24 == p_Var13) || (local_1d8[0] < *(int *)(p_Var13 + 0x20))) goto LAB_0010a251;
        }
        *(uint *)(p_Var13 + 0x24) = uVar25;
      }
      if (local_1a8 != (code *)0x0) {
        (*local_1a8)(local_1b8,local_1b8,3);
      }
      local_188 = (code *)0x0;
      rea_EventLoop2__run(this_00,&local_198);
      if (local_188 != (code *)0x0) {
        (*local_188)(&local_198,&local_198,3);
      }
    }
    *(undefined **)(this_00 + 0x70) = PTR_vtable_00324f90 + 0x10;
    if (*(code **)(this_00 + 0xd0) != (code *)0x0) {
      (**(code **)(this_00 + 0xd0))(this_00 + 0xc0,this_00 + 0xc0,3);
    }
    puVar10 = PTR__S_empty_rep_storage_00324fa0;
    pEVar17 = *(EventLoop2 **)(this_00 + 0xa8);
    pEVar4 = this_00 + 0xa8;
    if (pEVar4 != pEVar17) {
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        do {
          lVar23 = *(long *)(pEVar17 + 0x18);
          pEVar9 = *(EventLoop2 **)pEVar17;
          if (((allocator *)(lVar23 + -0x18) != (allocator *)puVar10) &&
             (iVar11 = *(int *)(lVar23 + -8), *(int *)(lVar23 + -8) = iVar11 + -1, iVar11 < 1)) {
            rea_std__string___Rep___M_destroy((allocator *)(lVar23 + -0x18));
          }
          rea_operator_delete(pEVar17);
          pEVar17 = pEVar9;
        } while (pEVar4 != pEVar9);
      }
      else {
        do {
          pEVar9 = *(EventLoop2 **)pEVar17;
          paVar2 = (allocator *)(*(long *)(pEVar17 + 0x18) + -0x18);
          if (paVar2 != (allocator *)puVar10) {
            LOCK();
            piVar3 = (int *)(*(long *)(pEVar17 + 0x18) + -8);
            iVar11 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
            if (iVar11 < 1) {
              rea_std__string___Rep___M_destroy(paVar2);
            }
          }
          rea_operator_delete(pEVar17);
          pEVar17 = pEVar9;
        } while (pEVar4 != pEVar9);
      }
    }
    std________Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root________M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
                *)(this_00 + 0x78),*(_Rb_tree_node **)(this_00 + 0x88));
    *(undefined **)(this_00 + 0x70) = PTR_vtable_00324ef0 + 0x10;
    rea_EventLoop2__dtor_EventLoop2(this_00);
    rea_operator_delete(this_00);
  }
  uVar16 = rea_Py_BuildValue((void *)&DAT_0011f2dd,0);
LAB_0010a3e6:
  rea_sigaction(2,&local_d8,(sigaction *)0x0);
  return uVar16;
}





// ------------------------------------------------------------------
// IDX 176  0010a6b0  FUN_0010a6b0
// ------------------------------------------------------------------
undefined8 rea_FUN_0010a6b0(undefined8 param_1, undefined8 param_2)
{
  allocator *paVar1;
  int *piVar2;
  EventLoop2 *pEVar3;
  long lVar4;
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
  _union_1457 local_178;
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  local_178.sa_handler = (__sighandler_t)0x0;
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
    local_208 = (code *)0x0;
    *(undefined **)(this_ptr + 0x70) = puVar6 + 0x10;
    local_218[0] = rea_operator_new(8);
    *local_218[0] = this_ptr;
    local_228 = (code *)0x0;
    pcStack_200 = FUN_001078e0;
    local_208 = FUN_00107a90;
    local_238[0] = rea_operator_new(8);
    *local_238[0] = this_ptr;
    pcStack_220 = FUN_00109140;
    local_228 = FUN_00107b10;
    if ((*(long *)(local_248[0] + -0x18) == 0) || (*local_248[0] != '/')) {
      local_1c8 = (code *)0x0;
      rea_FUN_00107b10(local_1d8,local_238,2);
      local_1e8 = (code *)0x0;
      local_1c8 = local_228;
      pcStack_1c0 = pcStack_220;
      if (local_208 != (code *)0x0) {
        (*local_208)(local_1f8,local_218,2);
        local_1e8 = local_208;
        pcStack_1e0 = pcStack_200;
      }
      pUVar11 = rea_operator_new(0xe8);
      rea_TcpClient__TcpClient((TcpClient *)pUVar11,(string *)local_248,uVar8,local_1d8,local_1f8);
      if (local_1e8 != (code *)0x0) {
        (*local_1e8)(local_1f8,local_1f8,3);
      }
      if (local_1c8 != (code *)0x0) {
        (*local_1c8)(local_1d8,local_1d8,3);
      }
    }
    else {
      local_188 = (code *)0x0;
      rea_FUN_00107b10((allocator *)&local_198,local_238,2);
      local_1a8 = (code *)0x0;
      local_188 = local_228;
      pcStack_180 = pcStack_220;
      if (local_208 != (code *)0x0) {
        (*local_208)(local_1b8,local_218,2);
        local_1a8 = local_208;
        pcStack_1a0 = pcStack_200;
      }
      pUVar11 = rea_operator_new(0xe8);
      rea_UnixClient__UnixClient(pUVar11,(string *)local_248,(allocator *)&local_198);
      if (local_1a8 != (code *)0x0) {
        (*local_1a8)(local_1b8,local_1b8,3);
      }
      if (local_188 != (code *)0x0) {
        (*local_188)((allocator *)&local_198,(allocator *)&local_198,3);
      }
    }
    rea_EventLoop2__add(this_ptr,(EventHandler *)pUVar11);
    if (local_228 != (code *)0x0) {
      (*local_228)(local_238,local_238,3);
    }
    if (local_208 != (code *)0x0) {
      (*local_208)(local_218,local_218,3);
    }
    local_188 = (code *)0x0;
    iVar7 = rea_EventLoop2__run(this_ptr,(allocator *)&local_198);
    if (local_188 != (code *)0x0) {
      (*local_188)((allocator *)&local_198,(allocator *)&local_198,3);
    }
    paVar14 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
    if (iVar7 == 0) {
      *(undefined **)(this_ptr + 0x70) = PTR_vtable_00324f90 + 0x10;
      if (*(code **)(this_ptr + 0xd0) != (code *)0x0) {
        (**(code **)(this_ptr + 0xd0))(this_ptr + 0xc0,this_ptr + 0xc0,3);
      }
      paVar14 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
      pEVar13 = *(EventLoop2 **)(this_ptr + 0xa8);
      if (pEVar3 != pEVar13) {
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          do {
            lVar4 = *(long *)(pEVar13 + 0x18);
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
            paVar1 = (allocator *)(*(long *)(pEVar13 + 0x18) + -0x18);
            if (paVar1 != paVar14) {
              LOCK();
              piVar2 = (int *)(*(long *)(pEVar13 + 0x18) + -8);
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
      this_ptr = (EventLoop2 *)0x0;
    }
    if ((allocator *)(local_248[0] + -0x18) != paVar14) {
      piVar2 = (int *)(local_248[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
  rea_sigaction(2,&local_d8,(sigaction *)0x0);
  return uVar12;
}





// ------------------------------------------------------------------
// IDX 177  0010aef0  Root__dtor_Root
// ------------------------------------------------------------------
void rea_Root__dtor_Root(Root * this_ptr)
{
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 178  0010af00  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 179  0010af10  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void__dup2(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 180  0010af20  Root__dtor_Root
// ------------------------------------------------------------------
void rea_Root__dtor_Root__dup2(Root * this_ptr)
{
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 181  0010af40  std___Function_base___Base_manager_WSConn__exit__lambda__2___M_manager___________
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager_WSConn__exit__lambda__2___M_manager(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324f10;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = rea_operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 182  0010afb0  std___Function_base___Base_manager_WSConn__exit__lambda__3___M_manager___________
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager_WSConn__exit__lambda__3___M_manager__dup2(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324f50;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = rea_operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 183  0010b020  std___Function_base____Base_manager_WSConn__exit__lambda___void_std__unique_ptr_Buffer_std__default_delete_Buffer____std__unique_ptr_Buffer_std__default_delete_Buffer___1____M_manager
// ------------------------------------------------------------------
undefined8 rea_std___Function_base____Base_manager_WSConn__exit__lambda___void_std__unique_ptr_Buffer_std__default_delete_Buffer____std__unique_ptr_Buffer_std__default_delete_Buffer___1____M_manager(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324fa8;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = rea_operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 184  0010b0a0  std___Function_base___Base_manager___void_std__unique_ptr_Buffer_std__default_delete_Buffer____M_manager
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager___void_std__unique_ptr_Buffer_std__default_delete_Buffer____M_manager(long * param_1, long * param_2, int param_3)
{
  long lVar1;
  void *pvVar2;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)PTR_typeinfo_00324ee0;
      return 0;
    }
  }
  else if (param_3 == 2) {
    lVar1 = *param_2;
    pvVar2 = rea_operator_new(0x20);
    *(undefined8 *)((long)pvVar2 + 0x10) = 0;
    if (*(code **)(lVar1 + 0x10) != (code *)0x0) {
      (**(code **)(lVar1 + 0x10))(pvVar2,lVar1,2);
      *(undefined8 *)((long)pvVar2 + 0x18) = *(undefined8 *)(lVar1 + 0x18);
      *(undefined8 *)((long)pvVar2 + 0x10) = *(undefined8 *)(lVar1 + 0x10);
    }
    *param_1 = (long)pvVar2;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
    if (*(code **)((long)pvVar2 + 0x10) != (code *)0x0) {
      (**(code **)((long)pvVar2 + 0x10))(pvVar2,pvVar2,3);
    }
    rea_operator_delete(pvVar2);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 185  0010b190  _Function_handler<void
// ------------------------------------------------------------------
undefined8 rea__Function_handler_void(undefined8 * param_2)
{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *local_68 [2];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  code *local_28;
  undefined8 local_20;
  
  lVar1 = *param_1;
  puVar2 = (undefined8 *)*param_2;
  local_48 = (code *)0x0;
  *param_2 = 0;
  if (*(code **)(lVar1 + 0x10) != (code *)0x0) {
    (**(code **)(lVar1 + 0x10))(&local_58,lVar1,2);
    uVar4 = local_50;
    uVar3 = local_58;
    local_28 = *(code **)(lVar1 + 0x10);
    local_48 = local_28;
    local_40 = *(undefined8 *)(lVar1 + 0x18);
    if (*(long *)(lVar1 + 0x10) != 0) {
      local_58 = local_38;
      local_50 = local_30;
      local_38 = uVar3;
      local_30 = uVar4;
      local_48 = (code *)0x0;
      local_40 = local_20;
      local_68[0] = puVar2;
      local_20 = *(undefined8 *)(lVar1 + 0x18);
      (**(code **)(lVar1 + 0x18))(lVar1,&local_38,local_68);
      if (local_28 != (code *)0x0) {
        (*local_28)(&local_38,&local_38,3);
      }
      puVar2 = local_68[0];
      if (local_68[0] != (undefined8 *)0x0) {
        if ((void *)*local_68[0] != (void *)0x0) {
          rea_operator_delete((void *)*local_68[0]);
        }
        rea_operator_delete(puVar2);
      }
      if (local_48 != (code *)0x0) {
        (*local_48)(&local_58,&local_58,3);
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 186  0010b320  _Function_handler<void
// ------------------------------------------------------------------
undefined8 rea__Function_handler_void__dup2(undefined8 __void_std__unique_ptr_Buffer_std__default_delete_Buffer, undefined8 * param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 local_78;
  undefined8 local_70;
  code *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 uStack_40;
  undefined8 *local_38 [2];
  code *local_28;
  undefined *local_20;
  
  puVar1 = (undefined8 *)*param_3;
  *param_3 = 0;
  uVar2 = *param_2;
  uVar3 = param_2[1];
  *param_2 = local_78;
  param_2[1] = local_70;
  local_68 = (code *)param_2[2];
  uVar4 = param_2[3];
  param_2[2] = 0;
  param_2[3] = uStack_60;
  param_1 = (undefined8 *)*param_1;
  local_78 = uVar2;
  local_70 = uVar3;
  uStack_60 = uVar4;
  if (puVar1 != (undefined8 *)0x0) {
    local_48 = (code *)0x0;
    if (local_68 != (code *)0x0) {
      (*local_68)(&local_58,&local_78,2);
      local_48 = local_68;
      uStack_40 = uStack_60;
    }
    local_28 = (code *)0x0;
    local_38[0] = rea_operator_new(0x20);
    pcVar5 = local_48;
    local_38[0][2] = 0;
    uVar2 = *local_38[0];
    uVar3 = local_38[0][1];
    uVar4 = local_38[0][3];
    local_38[0][1] = local_50;
    *local_38[0] = local_58;
    local_48 = (code *)0x0;
    local_38[0][2] = pcVar5;
    local_38[0][3] = uStack_40;
    local_20 = PTR__M_invoke_00324fe0;
    local_28 = (code *)PTR__M_manager_00324f88;
    local_58 = uVar2;
    local_50 = uVar3;
    uStack_40 = uVar4;
    rea_WSConn__recv((WSConn *)*param_1,local_38);
    if (local_28 != (code *)0x0) {
      (*local_28)(local_38,local_38,3);
    }
    if (local_48 != (code *)0x0) {
      (*local_48)(&local_58,&local_58,3);
    }
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 187  0010b540  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase__dup2(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, _Rb_tree_node * param_1)
{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  _Rb_tree_node *p_Var9;
  void *pvVar10;
  
  while (param_1 != (_Rb_tree_node *)0x0) {
    pvVar10 = *(void **)(param_1 + 0x18);
    while (pvVar10 != (void *)0x0) {
      pvVar8 = *(void **)((long)pvVar10 + 0x18);
      while (pvVar8 != (void *)0x0) {
        pvVar7 = *(void **)((long)pvVar8 + 0x18);
        while (pvVar7 != (void *)0x0) {
          pvVar6 = *(void **)((long)pvVar7 + 0x18);
          while (pvVar6 != (void *)0x0) {
            pvVar5 = *(void **)((long)pvVar6 + 0x18);
            while (pvVar5 != (void *)0x0) {
              pvVar4 = *(void **)((long)pvVar5 + 0x18);
              while (pvVar4 != (void *)0x0) {
                pvVar3 = *(void **)((long)pvVar4 + 0x18);
                while (pvVar3 != (void *)0x0) {
                  pvVar2 = *(void **)((long)pvVar3 + 0x18);
                  while (pvVar2 != (void *)0x0) {
                    _M_erase(this_ptr,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
                    pvVar1 = *(void **)((long)pvVar2 + 0x10);
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long)pvVar3 + 0x10);
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long)pvVar4 + 0x10);
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long)pvVar5 + 0x10);
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long)pvVar6 + 0x10);
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long)pvVar7 + 0x10);
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long)pvVar8 + 0x10);
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long)pvVar10 + 0x10);
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 188  0010b710  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase
// ------------------------------------------------------------------
long rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase__dup2(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, int * param_1)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  int iVar3;
  _Rb_tree_node *p_Var4;
  long lVar5;
  _Rb_tree_node *p_Var6;
  long lVar7;
  _Rb_tree_node_base *p_Var8;
  void *pvVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 8);
  p_Var4 = *(_Rb_tree_node **)(this_ptr + 0x10);
  p_Var11 = p_Var1;
  p_Var13 = p_Var1;
  if (p_Var4 != (_Rb_tree_node *)0x0) {
    iVar3 = *param_1;
    p_Var6 = p_Var4;
    do {
      while (p_Var8 = (_Rb_tree_node_base *)p_Var6, iVar3 <= *(int *)(p_Var8 + 0x20)) {
        if (*(int *)(p_Var8 + 0x20) <= iVar3) {
          p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
          p_Var12 = *(_Rb_tree_node_base **)(p_Var8 + 0x18);
          while (p_Var13 = p_Var11, p_Var12 != (_Rb_tree_node_base *)0x0) {
            while (p_Var13 = p_Var12, iVar3 < *(int *)(p_Var13 + 0x20)) {
              p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var11 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010b800;
            }
            p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
          }
LAB_0010b800:
          do {
            p_Var11 = p_Var8;
            if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
            iVar2 = *(int *)(p_Var10 + 0x20);
            while (p_Var11 = p_Var10, iVar3 <= iVar2) {
              p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
              if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
              iVar2 = *(int *)(p_Var10 + 0x20);
              p_Var8 = p_Var11;
            }
            p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
          } while( true );
        }
        p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var11 = p_Var8;
        p_Var13 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
      }
      p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x18);
      p_Var13 = p_Var11;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x18) != (_Rb_tree_node_base *)0x0);
  }
LAB_0010b763:
  lVar5 = *(long *)(this_ptr + 0x28);
  if ((p_Var11 == *(_Rb_tree_node_base **)(this_ptr + 0x18)) && (p_Var1 == p_Var13)) {
    _M_erase(this_ptr,p_Var4);
    *(_Rb_tree_node_base **)(this_ptr + 0x18) = p_Var1;
    *(undefined8 *)(this_ptr + 0x10) = 0;
    *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
    *(undefined8 *)(this_ptr + 0x28) = 0;
    lVar7 = lVar5;
  }
  else {
    lVar7 = 0;
    if (p_Var11 != p_Var13) {
      do {
        p_Var8 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var11);
        pvVar9 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var11,p_Var1);
        rea_operator_delete(pvVar9);
        lVar7 = *(long *)(this_ptr + 0x28);
        *(long *)(this_ptr + 0x28) = lVar7 + -1;
        p_Var11 = p_Var8;
      } while (p_Var8 != p_Var13);
      lVar7 = lVar5 - (lVar7 + -1);
    }
  }
  return lVar7;
}





// ------------------------------------------------------------------
// IDX 189  0010b880  std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase__dup2(_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root * this_ptr, _Rb_tree_node * param_1)
{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  _Rb_tree_node *p_Var9;
  void *pvVar10;
  
  while (param_1 != (_Rb_tree_node *)0x0) {
    pvVar10 = *(void **)(param_1 + 0x18);
    while (pvVar10 != (void *)0x0) {
      pvVar8 = *(void **)((long)pvVar10 + 0x18);
      while (pvVar8 != (void *)0x0) {
        pvVar7 = *(void **)((long)pvVar8 + 0x18);
        while (pvVar7 != (void *)0x0) {
          pvVar6 = *(void **)((long)pvVar7 + 0x18);
          while (pvVar6 != (void *)0x0) {
            pvVar5 = *(void **)((long)pvVar6 + 0x18);
            while (pvVar5 != (void *)0x0) {
              pvVar4 = *(void **)((long)pvVar5 + 0x18);
              while (pvVar4 != (void *)0x0) {
                pvVar3 = *(void **)((long)pvVar4 + 0x18);
                while (pvVar3 != (void *)0x0) {
                  pvVar2 = *(void **)((long)pvVar3 + 0x18);
                  while (pvVar2 != (void *)0x0) {
                    _M_erase(this_ptr,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
                    pvVar1 = *(void **)((long)pvVar2 + 0x10);
                    if (*(long **)((long)pvVar2 + 0x28) != (long *)0x0) {
                      (**(code **)(**(long **)((long)pvVar2 + 0x28) + 8))();
                    }
                    *(undefined8 *)((long)pvVar2 + 0x28) = 0;
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long)pvVar3 + 0x10);
                  if (*(long **)((long)pvVar3 + 0x28) != (long *)0x0) {
                    (**(code **)(**(long **)((long)pvVar3 + 0x28) + 8))();
                  }
                  *(undefined8 *)((long)pvVar3 + 0x28) = 0;
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long)pvVar4 + 0x10);
                if (*(long **)((long)pvVar4 + 0x28) != (long *)0x0) {
                  (**(code **)(**(long **)((long)pvVar4 + 0x28) + 8))();
                }
                *(undefined8 *)((long)pvVar4 + 0x28) = 0;
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long)pvVar5 + 0x10);
              if (*(long **)((long)pvVar5 + 0x28) != (long *)0x0) {
                (**(code **)(**(long **)((long)pvVar5 + 0x28) + 8))();
              }
              *(undefined8 *)((long)pvVar5 + 0x28) = 0;
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long)pvVar6 + 0x10);
            if (*(long **)((long)pvVar6 + 0x28) != (long *)0x0) {
              (**(code **)(**(long **)((long)pvVar6 + 0x28) + 8))();
            }
            *(undefined8 *)((long)pvVar6 + 0x28) = 0;
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long)pvVar7 + 0x10);
          if (*(long **)((long)pvVar7 + 0x28) != (long *)0x0) {
            (**(code **)(**(long **)((long)pvVar7 + 0x28) + 8))();
          }
          *(undefined8 *)((long)pvVar7 + 0x28) = 0;
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long)pvVar8 + 0x10);
        if (*(long **)((long)pvVar8 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar8 + 0x28) = 0;
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long)pvVar10 + 0x10);
      if (*(long **)((long)pvVar10 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)((long)pvVar10 + 0x28) + 8))();
      }
      *(undefined8 *)((long)pvVar10 + 0x28) = 0;
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 8))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 190  0010bb30  Channel_std__pair_int_std__string___Channel
// ------------------------------------------------------------------
void rea_Channel_std__pair_int_std__string___Channel(Channel_std__pair_int_std__string * this_ptr)
{
  Channel_std__pair_int_std__string *pCVar1;
  allocator *paVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  Channel_std__pair_int_std__string *pCVar6;
  undefined *puVar7;
  Channel_std__pair_int_std__string *pCVar8;
  
  *(undefined **)this_ptr = PTR_vtable_00324f90 + 0x10;
  if (*(code **)(this_ptr + 0x60) != (code *)0x0) {
    (**(code **)(this_ptr + 0x60))(this_ptr + 0x50,this_ptr + 0x50,3);
  }
  puVar7 = PTR__S_empty_rep_storage_00324fa0;
  pCVar8 = *(Channel_std__pair_int_std__string **)(this_ptr + 0x38);
  pCVar1 = this_ptr + 0x38;
  if (pCVar8 != pCVar1) {
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      do {
        lVar5 = *(long *)(pCVar8 + 0x18);
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        if (((allocator *)(lVar5 + -0x18) != (allocator *)puVar7) &&
           (iVar4 = *(int *)(lVar5 + -8), *(int *)(lVar5 + -8) = iVar4 + -1, iVar4 < 1)) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar5 + -0x18));
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
    else {
      do {
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        paVar2 = (allocator *)(*(long *)(pCVar8 + 0x18) + -0x18);
        if (paVar2 != (allocator *)puVar7) {
          LOCK();
          piVar3 = (int *)(*(long *)(pCVar8 + 0x18) + -8);
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 < 1) {
            rea_std__string___Rep___M_destroy(paVar2);
          }
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
  }
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 191  0010bc30  Channel_std__pair_int_std__string___Channel
// ------------------------------------------------------------------
void rea_Channel_std__pair_int_std__string___Channel__dup2(Channel_std__pair_int_std__string * this_ptr)
{
  Channel_std__pair_int_std__string *pCVar1;
  allocator *paVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  Channel_std__pair_int_std__string *pCVar6;
  undefined *puVar7;
  Channel_std__pair_int_std__string *pCVar8;
  
  *(undefined **)this_ptr = PTR_vtable_00324f90 + 0x10;
  if (*(code **)(this_ptr + 0x60) != (code *)0x0) {
    (**(code **)(this_ptr + 0x60))(this_ptr + 0x50,this_ptr + 0x50,3);
  }
  puVar7 = PTR__S_empty_rep_storage_00324fa0;
  pCVar8 = *(Channel_std__pair_int_std__string **)(this_ptr + 0x38);
  pCVar1 = this_ptr + 0x38;
  if (pCVar8 != pCVar1) {
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      do {
        lVar5 = *(long *)(pCVar8 + 0x18);
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        if (((allocator *)(lVar5 + -0x18) != (allocator *)puVar7) &&
           (iVar4 = *(int *)(lVar5 + -8), *(int *)(lVar5 + -8) = iVar4 + -1, iVar4 < 1)) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar5 + -0x18));
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
    else {
      do {
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        paVar2 = (allocator *)(*(long *)(pCVar8 + 0x18) + -0x18);
        if (paVar2 != (allocator *)puVar7) {
          LOCK();
          piVar3 = (int *)(*(long *)(pCVar8 + 0x18) + -8);
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 < 1) {
            rea_std__string___Rep___M_destroy(paVar2);
          }
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
  }
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 192  0010bd40  std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root___________
// ------------------------------------------------------------------
arr_undefined1_16 rea_std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_emplace_unique_WSConn___std__unique_ptr_Root_std__default_delete_Root__dup2(_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root * this_ptr, WSConn * * param_1, unique_ptr * param_2)
{
  _Rb_tree_node_base *p_Var1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  bool bVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  (*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = rea_operator_new(0x30);
  if ((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) != (_Rb_tree_node_base *)0x0) {
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 8) = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x10) = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x18) = 0;
    *(undefined4 *)(*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = 0;
    *(WSConn **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) = *param_1;
    uVar2 = *(undefined8 *)param_2;
    *(undefined8 *)param_2 = 0;
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) = uVar2;
  }
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 8);
  p_Var6 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010be18:
    p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
    if (p_Var5 == p_Var6) goto LAB_0010be50;
    p_Var5 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var6);
    if (*(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) <= *(ulong *)(p_Var5 + 0x20)) goto LAB_0010bde1;
  }
  else {
    uVar3 = *(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20);
    p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
    do {
      p_Var6 = p_Var5;
      uVar4 = *(ulong *)(p_Var6 + 0x20);
      if (uVar3 < uVar4) {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
      }
      else {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
    } while (p_Var5 != (_Rb_tree_node_base *)0x0);
    if (uVar3 < uVar4) goto LAB_0010be18;
    p_Var5 = p_Var6;
    if (uVar3 <= uVar4) goto LAB_0010bde1;
  }
  p_Var5 = p_Var6;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = (_Rb_tree_node_base *)0x0;
LAB_0010bde1:
    if (*(long **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) + 8))();
    }
    *(undefined8 *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x28) = 0;
    rea_operator_delete((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)));
    (*(undefined8 *)((uint8_t *)&auVar8 + 0x8)) = 0;
    (*(undefined8 *)((uint8_t *)&auVar8 + 0x0)) = p_Var5;
    return rea_arr_from<arr_undefined1_16>(auVar8);
  }
LAB_0010be50:
  if (p_Var1 == p_Var5) {
    bVar7 = true;
  }
  else {
    bVar7 = *(ulong *)((*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) + 0x20) < *(ulong *)(p_Var5 + 0x20);
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar7,(*(undefined8 *)((uint8_t *)&auVar9 + 0x0)),p_Var5,p_Var1);
  *(long *)(this_ptr + 0x28) = *(long *)(this_ptr + 0x28) + 1;
  (*(undefined8 *)((uint8_t *)&auVar9 + 0x8)) = 1;
  return rea_arr_from<arr_undefined1_16>(auVar9);
}





// ------------------------------------------------------------------
// IDX 193  0010be90  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
arr_undefined1_16 rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_get_insert_hint_unique_pos__dup2(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, _Rb_tree_node_base * param_2, int * param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  int iVar5;
  int iVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  p_Var4 = (_Rb_tree_node_base *)(this_ptr + 8);
  if (p_Var4 != param_2) {
    iVar6 = *param_3;
    if (iVar6 < *(int *)(param_2 + 0x20)) {
      p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
      p_Var3 = p_Var2;
      if (p_Var2 == param_2) goto LAB_0010bee8;
      p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(param_2);
      if (*(int *)(p_Var1 + 0x20) < iVar6) {
        p_Var3 = (_Rb_tree_node_base *)0x0;
        p_Var2 = p_Var1;
        if (*(long *)(p_Var1 + 0x18) != 0) {
          p_Var3 = param_2;
          p_Var2 = param_2;
        }
        goto LAB_0010bee8;
      }
      p_Var3 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
      if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c010:
        if (p_Var2 == p_Var4) goto LAB_0010c02b;
        p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var4);
        iVar5 = *(int *)(p_Var1 + 0x20);
      }
      else {
        do {
          p_Var4 = p_Var3;
          iVar5 = *(int *)(p_Var4 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x18);
          }
        } while (p_Var3 != (_Rb_tree_node_base *)0x0);
        p_Var1 = p_Var4;
        if (iVar6 < iVar5) goto LAB_0010c010;
      }
      p_Var3 = (_Rb_tree_node_base *)0x0;
      p_Var2 = p_Var4;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var1;
        p_Var2 = (_Rb_tree_node_base *)0x0;
      }
      goto LAB_0010bee8;
    }
    if (iVar6 <= *(int *)(param_2 + 0x20)) {
      (*(undefined8 *)((uint8_t *)&auVar9 + 0x8)) = 0;
      (*(undefined8 *)((uint8_t *)&auVar9 + 0x0)) = param_2;
      return rea_arr_from<arr_undefined1_16>(auVar9);
    }
    p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x20);
    if (p_Var2 == param_2) {
LAB_0010c02b:
      p_Var3 = (_Rb_tree_node_base *)0x0;
    }
    else {
      p_Var2 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(param_2);
      if (iVar6 < *(int *)(p_Var2 + 0x20)) {
        p_Var4 = p_Var2;
        if (*(long *)(param_2 + 0x18) == 0) {
          p_Var2 = param_2;
          p_Var4 = (_Rb_tree_node_base *)0x0;
        }
        (*(undefined8 *)((uint8_t *)&auVar8 + 0x8)) = p_Var2;
        (*(undefined8 *)((uint8_t *)&auVar8 + 0x0)) = p_Var4;
        return rea_arr_from<arr_undefined1_16>(auVar8);
      }
      p_Var3 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
      p_Var2 = p_Var4;
      if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c0e0:
        if (*(_Rb_tree_node_base **)(this_ptr + 0x18) == p_Var2) goto LAB_0010c02b;
        p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var2);
        iVar5 = *(int *)(p_Var4 + 0x20);
      }
      else {
        do {
          p_Var2 = p_Var3;
          iVar5 = *(int *)(p_Var2 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x18);
          }
        } while (p_Var3 != (_Rb_tree_node_base *)0x0);
        p_Var4 = p_Var2;
        if (iVar6 < iVar5) goto LAB_0010c0e0;
      }
      p_Var3 = (_Rb_tree_node_base *)0x0;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var4;
        p_Var2 = (_Rb_tree_node_base *)0x0;
      }
    }
    goto LAB_0010bee8;
  }
  if ((*(long *)(this_ptr + 0x28) != 0) &&
     (*(int *)(*(_Rb_tree_node_base **)(this_ptr + 0x20) + 0x20) < *param_3)) {
    p_Var3 = (_Rb_tree_node_base *)0x0;
    p_Var2 = *(_Rb_tree_node_base **)(this_ptr + 0x20);
    goto LAB_0010bee8;
  }
  if (*(_Rb_tree_node_base **)(this_ptr + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c0b7:
    if (*(_Rb_tree_node_base **)(this_ptr + 0x18) == p_Var4) {
      p_Var3 = (_Rb_tree_node_base *)0x0;
      p_Var2 = p_Var4;
      goto LAB_0010bee8;
    }
    p_Var3 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var4);
    iVar5 = *(int *)(p_Var3 + 0x20);
    iVar6 = *param_3;
  }
  else {
    iVar6 = *param_3;
    p_Var4 = *(_Rb_tree_node_base **)(this_ptr + 0x10);
    do {
      p_Var3 = p_Var4;
      iVar5 = *(int *)(p_Var3 + 0x20);
      if (iVar6 < iVar5) {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x10);
      }
      else {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x18);
      }
    } while (p_Var4 != (_Rb_tree_node_base *)0x0);
    p_Var4 = p_Var3;
    if (iVar6 < iVar5) goto LAB_0010c0b7;
  }
  p_Var2 = (_Rb_tree_node_base *)0x0;
  if (iVar5 < iVar6) {
    p_Var3 = p_Var2;
    p_Var2 = p_Var4;
  }
LAB_0010bee8:
  (*(undefined8 *)((uint8_t *)&auVar7 + 0x8)) = p_Var2;
  (*(undefined8 *)((uint8_t *)&auVar7 + 0x0)) = p_Var3;
  return rea_arr_from<arr_undefined1_16>(auVar7);
}





// ------------------------------------------------------------------
// IDX 194  0010c110  WSConn__exit
// ------------------------------------------------------------------
void rea_WSConn__exit__dup2(WSConn * this_ptr)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  _Rb_tree_node_base *p_Var2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 *puVar10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  undefined *puVar14;
  long lVar15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  bool bVar19;
  code *pcVar20;
  uint uVar21;
  uint uVar22;
  undefined1 auVar23 [16];
  int local_a8 [4];
  undefined8 *local_98 [2];
  code *local_88;
  undefined *puStack_80;
  void *local_78;
  undefined8 local_70;
  code *local_68;
  undefined *puStack_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  
  local_88 = (code *)0x0;
  local_98[0] = rea_operator_new(8);
  lVar15 = *(long *)(this_ptr + 0x38);
  *local_98[0] = this_ptr;
  puStack_80 = PTR__M_invoke_00324f38;
  local_88 = (code *)PTR__M_manager_00324ec0;
  if (*(char *)(lVar15 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar15 + 0x88) = 1;
  local_68 = (code *)0x0;
  if (local_88 != (code *)0x0) {
    (*local_88)(&local_78,local_98,2);
    local_68 = local_88;
    puStack_60 = puStack_80;
  }
  local_48 = (code *)0x0;
  puVar10 = rea_operator_new(0x20);
  pcVar20 = local_68;
  puVar10[2] = 0;
  pvVar5 = (void *)*puVar10;
  uVar6 = puVar10[1];
  *puVar10 = local_78;
  puVar10[1] = local_70;
  local_68 = (code *)0x0;
  uVar7 = puVar10[3];
  puVar10[2] = pcVar20;
  puVar10[3] = puStack_60;
  puVar14 = PTR__M_manager_00324f88;
  local_58 = *(undefined8 *)(lVar15 + 0x90);
  uVar8 = *(undefined8 *)(lVar15 + 0x98);
  local_48 = *(code **)(lVar15 + 0xa0);
  *(undefined8 **)(lVar15 + 0x90) = puVar10;
  *(undefined8 *)(lVar15 + 0x98) = local_50;
  *(undefined **)(lVar15 + 0xa0) = puVar14;
  puStack_40 = *(undefined **)(lVar15 + 0xa8);
  *(undefined **)(lVar15 + 0xa8) = PTR__M_invoke_00324fe0;
  local_78 = pvVar5;
  local_70 = uVar6;
  puStack_60 = (undefined *)uVar7;
  local_50 = uVar8;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  local_a8[0] = *(int *)(lVar15 + 0x40);
  cVar3 = *(char *)(lVar15 + 0x88);
  lVar15 = *(long *)(lVar15 + 0x38);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == (_Rb_tree_node_base *)0x0) {
LAB_0010cb60:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, local_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c2da;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c2da:
    if ((p_Var12 == p_Var18) || (p_Var13 = p_Var12, local_a8[0] < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cb60;
    do {
      while (p_Var16 = p_Var17, local_a8[0] <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c30a;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c30a:
    if ((p_Var12 == p_Var16) || (local_a8[0] < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = rea_operator_new(0x28);
      if (p_Var17 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = local_a8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var17 = p_Var12;
  p_Var13 = p_Var16;
  uVar9 = uVar21;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var18 = p_Var17, local_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var13 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c37a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c37a:
    if ((p_Var16 != p_Var18) && (p_Var17 = p_Var16, *(int *)(p_Var18 + 0x20) <= local_a8[0])) {
      do {
        while (p_Var13 = p_Var12, local_a8[0] <= *(int *)(p_Var13 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
          p_Var17 = p_Var13;
          if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c3aa;
        }
        p_Var18 = p_Var13 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var13 = p_Var17;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c3aa:
      if ((p_Var16 == p_Var13) || (local_a8[0] < *(int *)(p_Var13 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = local_a8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var13,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
        p_Var17 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
        p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
        if (p_Var17 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var17)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var17 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var17,p_Var16);
          *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
          p_Var13 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var13 + 0x24);
    }
  }
  uVar22 = uVar9 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffe;
  }
  if (uVar21 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,local_a8);
  }
  else {
    p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var13 = p_Var16;
    p_Var17 = p_Var16;
    if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010ca20:
      p_Var12 = rea_operator_new(0x28);
      if (p_Var12 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_a8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var1,p_Var17,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
      p_Var17 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var12);
      }
      else {
        bVar19 = true;
        if ((p_Var17 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var13)) {
          bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var16);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var17 = p_Var12;
      }
    }
    else {
      do {
        while (p_Var17 = p_Var12, local_a8[0] <= *(int *)(p_Var17 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var13 = p_Var17;
          if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c412;
        }
        p_Var18 = p_Var17 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var17 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c412:
      if ((p_Var16 == p_Var17) || (local_a8[0] < *(int *)(p_Var17 + 0x20))) goto LAB_0010ca20;
    }
    *(uint *)(p_Var17 + 0x24) = uVar22;
  }
  if (local_88 != (code *)0x0) {
    (*local_88)(local_98,local_98,3);
  }
  local_68 = (code *)0x0;
  local_78 = rea_operator_new(1);
  lVar15 = *(long *)(this_ptr + 0x38);
  puStack_60 = PTR__M_invoke_00324fd8;
  local_68 = (code *)PTR__M_manager_00324ef8;
  if (*(char *)(lVar15 + 0x5a) != '\0') {
    rea_fwrite("close(): send_flag != false\n",1,0x1c,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar10 = *(undefined8 **)(lVar15 + 0x60);
  *(undefined1 *)(lVar15 + 0x5a) = 1;
  *(undefined8 *)(lVar15 + 0x60) = 0;
  if (puVar10 != (undefined8 *)0x0) {
    if ((void *)*puVar10 != (void *)0x0) {
      rea_operator_delete((void *)*puVar10);
    }
    rea_operator_delete(puVar10);
  }
  local_48 = (code *)0x0;
  if (local_68 == (code *)0x0) {
    pcVar20 = (code *)0x0;
    puVar14 = puStack_40;
  }
  else {
    (*local_68)(&local_58,&local_78,2);
    puVar14 = puStack_60;
    pcVar20 = local_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0x68);
  uVar7 = *(undefined8 *)(lVar15 + 0x70);
  local_48 = *(code **)(lVar15 + 0x78);
  *(undefined8 *)(lVar15 + 0x68) = local_58;
  *(undefined8 *)(lVar15 + 0x70) = local_50;
  puStack_40 = *(undefined **)(lVar15 + 0x80);
  *(code **)(lVar15 + 0x78) = pcVar20;
  *(undefined **)(lVar15 + 0x80) = puVar14;
  local_58 = uVar6;
  local_50 = uVar7;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  cVar3 = *(char *)(lVar15 + 0x5a);
  iVar4 = *(int *)(lVar15 + 0x40);
  lVar15 = *(long *)(lVar15 + 0x38);
  local_98[0] = (undefined8 *)CONCAT44(local_98[0]._4_4_,iVar4);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == (_Rb_tree_node_base *)0x0) {
LAB_0010cb40:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, iVar4 <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c58a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c58a:
    if ((p_Var18 == p_Var12) || (p_Var13 = p_Var12, iVar4 < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cb40;
    do {
      while (p_Var16 = p_Var17, iVar4 <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c5ba;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c5ba:
    if ((p_Var16 == p_Var12) || (iVar4 < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = rea_operator_new(0x28);
      if (p_Var17 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = (int)local_98[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
      p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var17 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  uVar9 = uVar21;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    p_Var13 = p_Var12;
    p_Var16 = p_Var17;
    do {
      while (p_Var18 = p_Var13, (int)local_98[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c62a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c62a:
    if ((p_Var18 != p_Var17) && (p_Var13 = p_Var17, *(int *)(p_Var18 + 0x20) <= (int)local_98[0])) {
      do {
        while (p_Var16 = p_Var12, (int)local_98[0] <= *(int *)(p_Var16 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
          p_Var13 = p_Var16;
          if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c65a;
        }
        p_Var18 = p_Var16 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var16 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c65a:
      if ((p_Var16 == p_Var17) || ((int)local_98[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = (int)local_98[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var16,p_Var12 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
        p_Var13 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
        if (p_Var13 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var17 != p_Var13)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var17);
          *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
          p_Var16 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar22 = uVar9 | 2;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffd;
  }
  if (uVar21 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,(int *)local_98);
    goto LAB_0010c6db;
  }
  p_Var12 = p_Var17;
  if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010cab0:
    p_Var13 = rea_operator_new(0x28);
    if (p_Var13 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var13 = 0;
      *(undefined8 *)(p_Var13 + 8) = 0;
      *(undefined8 *)(p_Var13 + 0x10) = 0;
      *(undefined8 *)(p_Var13 + 0x18) = 0;
      *(undefined4 *)(p_Var13 + 0x24) = 0;
      *(int *)(p_Var13 + 0x20) = (int)local_98[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var1,p_Var12,p_Var13 + 0x20)); memcpy(auVar23, &__rea_tmp, sizeof(auVar23)); }
    p_Var16 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x8));
    p_Var12 = (*(undefined8 *)((uint8_t *)&auVar23 + 0x0));
    if (p_Var16 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var13);
    }
    else {
      bVar19 = true;
      if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var17 != p_Var16)) {
        bVar19 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar19,p_Var13,p_Var16,p_Var17);
      *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
      p_Var12 = p_Var13;
    }
  }
  else {
    p_Var13 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var16 = p_Var17;
    do {
      while (p_Var12 = p_Var13, (int)local_98[0] <= *(int *)(p_Var12 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
        p_Var16 = p_Var12;
        if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c6c2;
      }
      p_Var18 = p_Var12 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var18;
      p_Var12 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c6c2:
    if ((p_Var12 == p_Var17) || ((int)local_98[0] < *(int *)(p_Var12 + 0x20))) goto LAB_0010cab0;
  }
  *(uint *)(p_Var12 + 0x24) = uVar22;
LAB_0010c6db:
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  local_68 = (code *)0x0;
  local_78 = rea_operator_new(1);
  lVar15 = *(long *)(this_ptr + 0x38);
  local_48 = (code *)0x0;
  puStack_60 = PTR__M_invoke_00324fd0;
  local_68 = (code *)PTR__M_manager_00324fc0;
  if (PTR__M_manager_00324fc0 == (undefined *)0x0) {
    pcVar20 = (code *)0x0;
    puVar14 = puStack_40;
  }
  else {
    std___Function_base___Base_manager_WSConn__exit__lambda__3___M_manager_______________(&local_58,&local_78,2);
    puVar14 = puStack_60;
    pcVar20 = local_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0xb0);
  uVar7 = *(undefined8 *)(lVar15 + 0xb8);
  local_48 = *(code **)(lVar15 + 0xc0);
  *(undefined8 *)(lVar15 + 0xb0) = local_58;
  *(undefined8 *)(lVar15 + 0xb8) = local_50;
  puStack_40 = *(undefined **)(lVar15 + 200);
  *(code **)(lVar15 + 0xc0) = pcVar20;
  *(undefined **)(lVar15 + 200) = puVar14;
  local_58 = uVar6;
  local_50 = uVar7;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
    pcVar20 = local_68;
  }
  if (pcVar20 != (code *)0x0) {
    (*pcVar20)(&local_78,&local_78,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 195  0010ced0  std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_char__std__string________________
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_char__std__string__dup2(long * param_1, undefined1 * param_2, undefined1 * param_3, undefined1 * param_4)
{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  void *__dest;
  undefined1 *puVar4;
  ulong uVar5;
  size_t sVar6;
  long lVar7;
  size_t sVar8;
  void *__src;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined1 *puVar12;
  ulong uVar13;
  undefined1 *unaff_R14;
  ulong uVar14;
  ulong local_48;
  
  if (param_3 == param_4) {
    return;
  }
  puVar12 = (undefined1 *)param_1[1];
  uVar9 = (long)param_4 - (long)param_3;
  if (uVar9 <= (ulong)(param_1[2] - (long)puVar12)) {
    uVar14 = (long)puVar12 - (long)param_2;
    if (uVar9 < uVar14) {
      puVar3 = puVar12 + -uVar9;
      puVar4 = puVar12;
      if ((long)puVar12 - (long)puVar3 != 0) {
        puVar4 = rea_memmove(puVar12,puVar3,(long)puVar12 - (long)puVar3);
        puVar12 = (undefined1 *)param_1[1];
      }
      sVar8 = (long)puVar3 - (long)param_2;
      param_1[1] = (long)(puVar12 + uVar9);
      if (sVar8 != 0) {
        rea_memmove(puVar4 + -sVar8,param_2,sVar8);
      }
      if ((long)uVar9 < 1) {
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
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(param_2 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar14);
      lVar7 = uVar9 + uVar14 * -0x10;
      if (uVar9 == uVar5) {
        return;
      }
    }
    else {
      puVar4 = param_3 + uVar14;
      uVar5 = (long)param_4 - (long)puVar4;
      if (0 < (long)uVar5) {
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
            uVar2 = *(undefined8 *)((long)(puVar4 + lVar7) + 8);
            uVar13 = uVar13 + 1;
            *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(puVar4 + lVar7);
            *(undefined8 *)((long)(puVar12 + lVar7) + 8) = uVar2;
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
      param_1[1] = (long)puVar12;
      if (uVar14 != 0) {
        rea_memmove(puVar12,param_2,uVar14);
        puVar12 = (undefined1 *)param_1[1];
      }
      uVar9 = (long)puVar4 - (long)param_3;
      param_1[1] = (long)(puVar12 + uVar14);
      if ((long)uVar9 < 1) {
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
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(param_2 + lVar7) + 8) = uVar2;
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
  uVar14 = (long)puVar12 - (long)__src;
  if (~uVar14 < uVar9) {
    rea_std____throw_length_error("vector___M_range_insert");
    local_48 = uVar14;
  }
  else {
    uVar5 = uVar9;
    if (uVar9 <= uVar14) {
      uVar5 = uVar14;
    }
    local_48 = 0xffffffffffffffff;
    unaff_R14 = param_3;
    if ((!CARRY8(uVar14,uVar5)) && (local_48 = uVar14 + uVar5, uVar14 + uVar5 == 0)) {
      local_48 = 0;
      __dest = (void *)0x0;
      goto LAB_0010d326;
    }
  }
  __dest = rea_operator_new(local_48);
  __src = (void *)*param_1;
LAB_0010d326:
  sVar6 = (long)param_2 - (long)__src;
  sVar8 = 0;
  if (sVar6 != 0) {
    rea_memmove(__dest,__src,sVar6);
    sVar8 = sVar6;
  }
  puVar12 = (undefined1 *)(sVar8 + (long)__dest);
  if (0 < (long)uVar9) {
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
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(puVar12 + lVar7) + 8) = uVar2;
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
  sVar6 = param_1[1] - (long)param_2;
  sVar8 = 0;
  if (sVar6 != 0) {
    puVar12 = rea_memmove(puVar12,param_2,sVar6);
    sVar8 = sVar6;
  }
  if ((void *)*param_1 != (void *)0x0) {
    rea_operator_delete((void *)*param_1);
  }
  *param_1 = (long)__dest;
  param_1[1] = (long)(puVar12 + sVar8);
  param_1[2] = (long)__dest + local_48;
  return;
}





// ------------------------------------------------------------------
// IDX 196  0010d620  FUN_0010d620
// ------------------------------------------------------------------
void rea_FUN_0010d620(uint * param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [14];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [15];
  undefined1 auVar11 [15];
  undefined1 auVar12 [15];
  undefined1 auVar13 [15];
  undefined1 auVar14 [14];
  undefined1 auVar15 [14];
  undefined1 auVar16 [14];
  undefined1 auVar17 [14];
  undefined1 auVar18 [15];
  undefined1 auVar19 [15];
  undefined1 auVar20 [15];
  undefined1 auVar21 [15];
  undefined1 auVar22 [15];
  undefined1 auVar23 [15];
  undefined1 auVar24 [15];
  undefined1 auVar25 [15];
  undefined1 auVar26 [14];
  undefined1 auVar27 [14];
  undefined1 auVar28 [14];
  undefined1 auVar29 [14];
  undefined1 auVar30 [13];
  undefined1 auVar31 [13];
  undefined1 auVar32 [13];
  undefined1 auVar33 [13];
  undefined1 auVar34 [13];
  undefined1 auVar35 [13];
  undefined1 auVar36 [13];
  undefined1 auVar37 [13];
  undefined1 auVar38 [13];
  undefined1 auVar39 [13];
  undefined1 auVar40 [13];
  undefined1 auVar41 [13];
  undefined1 auVar42 [15];
  undefined1 auVar43 [15];
  undefined1 auVar44 [15];
  undefined1 auVar45 [15];
  undefined1 auVar46 [15];
  undefined1 auVar47 [15];
  undefined1 auVar48 [15];
  undefined1 auVar49 [15];
  undefined1 auVar50 [15];
  undefined1 auVar51 [15];
  undefined1 uVar52;
  undefined1 uVar53;
  undefined1 uVar54;
  undefined1 uVar55;
  undefined1 uVar56;
  undefined1 uVar57;
  undefined1 uVar58;
  undefined1 uVar59;
  undefined1 uVar60;
  undefined1 uVar61;
  undefined1 uVar62;
  undefined1 uVar63;
  undefined1 uVar64;
  byte bVar65;
  byte bVar66;
  byte bVar67;
  byte bVar68;
  undefined1 uVar69;
  undefined1 uVar70;
  undefined1 uVar71;
  undefined1 uVar72;
  undefined1 uVar73;
  undefined1 uVar74;
  undefined1 uVar75;
  undefined1 uVar76;
  undefined1 uVar77;
  undefined1 auVar78 [16];
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  undefined1 auVar81 [16];
  undefined1 auVar82 [16];
  undefined1 auVar83 [16];
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  undefined1 auVar93 [16];
  undefined1 auVar94 [16];
  undefined1 auVar95 [16];
  undefined1 auVar96 [16];
  undefined1 auVar97 [16];
  undefined1 auVar98 [16];
  undefined1 auVar99 [16];
  undefined1 auVar100 [16];
  undefined1 auVar101 [16];
  undefined1 auVar102 [16];
  undefined1 auVar103 [16];
  undefined1 auVar104 [16];
  undefined1 auVar105 [16];
  undefined1 auVar106 [16];
  undefined1 auVar107 [16];
  undefined1 auVar108 [16];
  undefined1 auVar109 [16];
  undefined1 auVar110 [16];
  undefined1 auVar111 [16];
  undefined1 auVar112 [16];
  undefined1 auVar113 [16];
  undefined1 auVar114 [16];
  undefined1 auVar115 [16];
  undefined1 auVar116 [16];
  undefined1 auVar117 [16];
  undefined1 auVar118 [16];
  undefined1 auVar119 [16];
  undefined1 auVar120 [16];
  undefined1 auVar121 [16];
  undefined1 auVar122 [16];
  undefined1 auVar123 [16];
  undefined1 auVar124 [16];
  undefined1 auVar125 [16];
  undefined1 auVar126 [16];
  undefined1 auVar127 [16];
  undefined1 auVar128 [16];
  undefined1 auVar129 [16];
  undefined1 auVar130 [16];
  undefined1 auVar131 [16];
  undefined1 auVar132 [16];
  undefined1 auVar133 [16];
  undefined1 auVar134 [16];
  undefined1 auVar135 [16];
  undefined1 auVar136 [16];
  undefined1 auVar137 [16];
  undefined1 auVar138 [16];
  undefined1 auVar139 [16];
  undefined1 auVar140 [16];
  undefined1 auVar141 [16];
  undefined1 auVar142 [16];
  undefined1 auVar143 [16];
  undefined1 auVar144 [16];
  undefined1 auVar145 [16];
  undefined1 auVar146 [16];
  undefined1 auVar147 [16];
  undefined1 auVar148 [16];
  undefined1 auVar149 [16];
  undefined1 auVar150 [16];
  undefined1 auVar151 [16];
  undefined1 auVar152 [16];
  undefined1 auVar153 [16];
  undefined1 auVar154 [16];
  undefined1 auVar155 [16];
  undefined1 auVar156 [16];
  undefined1 auVar157 [16];
  undefined1 auVar158 [16];
  undefined1 auVar159 [15];
  unkuint9 Var160;
  undefined1 auVar161 [11];
  undefined1 auVar162 [15];
  undefined1 auVar163 [13];
  undefined1 auVar164 [15];
  unkuint9 Var165;
  undefined1 auVar166 [11];
  undefined1 auVar167 [13];
  undefined1 auVar168 [15];
  unkuint9 Var169;
  undefined1 auVar170 [11];
  undefined1 auVar171 [13];
  undefined1 auVar172 [15];
  unkuint9 Var173;
  undefined1 auVar174 [11];
  undefined1 auVar175 [13];
  undefined1 auVar176 [14];
  undefined1 auVar177 [14];
  undefined1 auVar178 [14];
  undefined1 auVar179 [14];
  undefined1 auVar180 [13];
  undefined1 auVar181 [13];
  undefined1 auVar182 [13];
  undefined1 auVar183 [13];
  undefined3 uVar184;
  undefined3 uVar185;
  undefined1 auVar186 [15];
  undefined1 auVar187 [15];
  undefined1 auVar188 [15];
  undefined8 uVar189;
  undefined1 auVar190 [15];
  undefined1 auVar191 [15];
  undefined8 uVar192;
  undefined1 auVar193 [15];
  undefined1 auVar194 [15];
  undefined5 uVar195;
  undefined5 uVar196;
  undefined1 auVar197 [12];
  undefined8 uVar198;
  undefined1 auVar199 [12];
  undefined8 uVar200;
  undefined1 auVar201 [14];
  undefined1 auVar202 [14];
  undefined8 uVar203;
  uint6 uVar204;
  uint6 uVar205;
  uint uVar206;
  uint uVar207;
  uint *puVar208;
  uint uVar209;
  long lVar210;
  int iVar211;
  uint uVar212;
  uint uVar213;
  int *piVar214;
  int *piVar215;
  uint *puVar216;
  undefined1 auVar217 [16];
  undefined1 auVar225 [16];
  undefined1 auVar233 [16];
  undefined1 auVar241 [16];
  undefined1 auVar244 [16];
  undefined1 auVar245 [16];
  undefined1 auVar253 [16];
  undefined1 auVar261 [16];
  uint uVar269;
  undefined1 auVar270 [16];
  undefined1 auVar278 [16];
  undefined1 auVar286 [16];
  undefined1 auVar294 [16];
  undefined1 auVar302 [16];
  undefined1 auVar309 [16];
  undefined1 auVar316 [16];
  undefined1 auVar319 [16];
  uint uVar320;
  undefined1 uVar353;
  undefined1 uVar354;
  undefined1 uVar355;
  undefined1 uVar356;
  undefined1 auVar321 [16];
  undefined1 auVar329 [16];
  undefined1 auVar337 [16];
  undefined1 auVar345 [16];
  byte bVar360;
  byte bVar361;
  byte bVar362;
  undefined1 uVar363;
  undefined1 uVar364;
  undefined1 uVar365;
  undefined1 uVar366;
  undefined1 auVar357 [16];
  undefined1 auVar358 [16];
  undefined1 auVar359 [16];
  byte bVar369;
  byte bVar370;
  uint uVar367;
  undefined1 uVar371;
  undefined1 uVar372;
  undefined1 uVar373;
  undefined1 uVar374;
  undefined1 auVar368 [16];
  byte bVar376;
  byte bVar377;
  byte bVar378;
  byte bVar379;
  undefined1 uVar380;
  undefined1 uVar381;
  undefined1 uVar382;
  undefined1 uVar383;
  undefined1 auVar375 [16];
  undefined1 auVar384 [16];
  undefined1 auVar385 [16];
  undefined1 auVar386 [16];
  undefined1 auVar387 [16];
  undefined1 auVar388 [16];
  undefined1 local_198 [16];
  uint local_178 [4];
  undefined1 local_168 [16];
  undefined1 local_158 [16];
  undefined1 local_148 [16];
  uint local_128 [20];
  uint local_d8 [20];
  int local_88 [20];
  int aiStack_38 [2];
  undefined1 auVar218 [16];
  undefined1 auVar226 [16];
  undefined1 auVar234 [16];
  undefined1 auVar246 [16];
  undefined1 auVar254 [16];
  undefined1 auVar262 [16];
  undefined1 auVar219 [16];
  undefined1 auVar227 [16];
  undefined1 auVar235 [16];
  undefined1 auVar247 [16];
  undefined1 auVar255 [16];
  undefined1 auVar263 [16];
  undefined1 auVar220 [16];
  undefined1 auVar228 [16];
  undefined1 auVar236 [16];
  undefined1 auVar248 [16];
  undefined1 auVar256 [16];
  undefined1 auVar264 [16];
  undefined1 auVar221 [16];
  undefined1 auVar229 [16];
  undefined1 auVar237 [16];
  undefined1 auVar249 [16];
  undefined1 auVar257 [16];
  undefined1 auVar265 [16];
  undefined1 auVar222 [16];
  undefined1 auVar230 [16];
  undefined1 auVar238 [16];
  undefined1 auVar250 [16];
  undefined1 auVar258 [16];
  undefined1 auVar266 [16];
  undefined1 auVar223 [16];
  undefined1 auVar231 [16];
  undefined1 auVar239 [16];
  undefined1 auVar242 [16];
  undefined1 auVar251 [16];
  undefined1 auVar259 [16];
  undefined1 auVar267 [16];
  undefined1 auVar224 [16];
  undefined1 auVar232 [16];
  undefined1 auVar240 [16];
  undefined1 auVar243 [16];
  undefined1 auVar252 [16];
  undefined1 auVar260 [16];
  undefined1 auVar268 [16];
  undefined1 auVar271 [16];
  undefined1 auVar279 [16];
  undefined1 auVar287 [16];
  undefined1 auVar295 [16];
  undefined1 auVar272 [16];
  undefined1 auVar280 [16];
  undefined1 auVar288 [16];
  undefined1 auVar296 [16];
  undefined1 auVar303 [16];
  undefined1 auVar310 [16];
  undefined1 auVar273 [16];
  undefined1 auVar281 [16];
  undefined1 auVar289 [16];
  undefined1 auVar297 [16];
  undefined1 auVar304 [16];
  undefined1 auVar311 [16];
  undefined1 auVar274 [16];
  undefined1 auVar282 [16];
  undefined1 auVar290 [16];
  undefined1 auVar298 [16];
  undefined1 auVar305 [16];
  undefined1 auVar312 [16];
  undefined1 auVar275 [16];
  undefined1 auVar283 [16];
  undefined1 auVar291 [16];
  undefined1 auVar299 [16];
  undefined1 auVar306 [16];
  undefined1 auVar313 [16];
  undefined1 auVar276 [16];
  undefined1 auVar284 [16];
  undefined1 auVar292 [16];
  undefined1 auVar300 [16];
  undefined1 auVar307 [16];
  undefined1 auVar314 [16];
  undefined1 auVar317 [16];
  undefined1 auVar277 [16];
  undefined1 auVar285 [16];
  undefined1 auVar293 [16];
  undefined1 auVar301 [16];
  undefined1 auVar315 [16];
  undefined1 auVar308 [16];
  undefined1 auVar318 [16];
  undefined1 auVar322 [16];
  undefined1 auVar330 [16];
  undefined1 auVar338 [16];
  undefined1 auVar346 [16];
  undefined1 auVar323 [16];
  undefined1 auVar331 [16];
  undefined1 auVar339 [16];
  undefined1 auVar347 [16];
  undefined1 auVar324 [16];
  undefined1 auVar332 [16];
  undefined1 auVar340 [16];
  undefined1 auVar348 [16];
  undefined1 auVar325 [16];
  undefined1 auVar333 [16];
  undefined1 auVar341 [16];
  undefined1 auVar349 [16];
  undefined1 auVar326 [16];
  undefined1 auVar334 [16];
  undefined1 auVar342 [16];
  undefined1 auVar350 [16];
  undefined1 auVar327 [16];
  undefined1 auVar335 [16];
  undefined1 auVar343 [16];
  undefined1 auVar351 [16];
  undefined1 auVar328 [16];
  undefined1 auVar336 [16];
  undefined1 auVar344 [16];
  undefined1 auVar352 [16];
  
  iVar211 = 0x10;
  { auto &&__rea_tmp = (*(undefined1 (*) [16])(param_1 + 7)); memcpy(auVar5, &__rea_tmp, sizeof(auVar5)); }
  puVar216 = local_178;
  uVar52 = *(undefined1 *)((long)param_1 + 0x2e);
  uVar53 = *(undefined1 *)((long)param_1 + 0x2f);
  uVar54 = (undefined1)param_1[0xc];
  uVar55 = *(undefined1 *)((long)param_1 + 0x31);
  uVar56 = *(undefined1 *)((long)param_1 + 0x32);
  uVar57 = *(undefined1 *)((long)param_1 + 0x33);
  uVar58 = *(undefined1 *)((long)param_1 + 0x35);
  uVar59 = *(undefined1 *)((long)param_1 + 0x36);
  uVar60 = *(undefined1 *)((long)param_1 + 0x37);
  uVar61 = (undefined1)param_1[0xe];
  uVar62 = *(undefined1 *)((long)param_1 + 0x39);
  uVar63 = *(undefined1 *)((long)param_1 + 0x3a);
  uVar64 = *(undefined1 *)((long)param_1 + 0x3b);
  uVar374 = auVar5[7];
  uVar373 = auVar5[6];
  uVar372 = auVar5[5];
  uVar371 = auVar5[4];
  bVar370 = auVar5[3];
  bVar369 = auVar5[2];
  auVar322[8] = auVar5[8];
  uVar353 = auVar5[9];
  auVar324[10] = auVar5[10];
  uVar354 = auVar5[0xb];
  auVar326[0xc] = auVar5[0xc];
  uVar355 = auVar5[0xd];
  auVar328[0xe] = auVar5[0xe];
  uVar356 = auVar5[0xf];
  auVar277[0xe] = uVar374;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar277 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar5 + 0x0));
  auVar277[0xf] = uVar57;
  (*(undefined2 *)((uint8_t *)&auVar276 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar277 + 0x14));
  auVar276[0xd] = uVar56;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar276 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar5 + 0x0));
  (*(arr_undefined1_3 *)((uint8_t *)&auVar275 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar276 + 0x13));
  auVar275[0xc] = uVar373;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar275 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar5 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar274 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar275 + 0x12));
  auVar274[0xb] = uVar55;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar274 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar5 + 0x0));
  (*(arr_undefined1_5 *)((uint8_t *)&auVar273 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar274 + 0x11));
  auVar273[10] = uVar372;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar273 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar5 + 0x0));
  (*(arr_undefined1_6 *)((uint8_t *)&auVar272 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar273 + 0x10));
  auVar272[9] = uVar54;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar272 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar5 + 0x0));
  (*(arr_undefined1_7 *)((uint8_t *)&auVar271 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar272 + 0x9));
  auVar271[8] = uVar371;
  (*(undefined8 *)((uint8_t *)&auVar271 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar5 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar82 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar271 + 0x8));
  auVar82[0] = uVar53;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar82 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar81 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar81 + 0x0)) = SUB1610(auVar82 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar80 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar80 + 0x0)) = SUB1611(auVar81 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar79 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar79 + 0x0)) = SUB1612(auVar80 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar78 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar78 + 0x0)) = SUB1613(auVar79 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar270 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar270 + 0x0)) = SUB1614(auVar78 << 0x18,2);
  { auto &&__rea_tmp = (auVar270 << 0x10); memcpy(auVar270, &__rea_tmp, sizeof(auVar270)); }
  { auto &&__rea_tmp = (*(undefined1 (*) [16])(param_1 + 0xf)); memcpy(auVar6, &__rea_tmp, sizeof(auVar6)); }
  (*(arr_undefined1_14 *)((uint8_t *)&auVar285 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar270 + 0x0));
  auVar285[0xe] = uVar53;
  auVar285[0xf] = uVar60;
  (*(undefined2 *)((uint8_t *)&auVar284 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar285 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar284 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar270 + 0x0));
  auVar284[0xd] = uVar354;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar283 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar284 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar283 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar270 + 0x0));
  auVar283[0xc] = bVar370;
  (*(undefined4 *)((uint8_t *)&auVar282 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar283 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar282 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar270 + 0x0));
  auVar282[0xb] = uVar59;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar281 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar282 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar281 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar270 + 0x0));
  auVar281[10] = uVar52;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar280 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar281 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar280 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar270 + 0x0));
  auVar280[9] = auVar324[10];
  (*(arr_undefined1_7 *)((uint8_t *)&auVar279 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar280 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar279 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar270 + 0x0));
  auVar279[8] = bVar369;
  (*(undefined8 *)((uint8_t *)&auVar87 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar279 + 0x8));
  auVar87[0] = uVar58;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar87 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar86 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar86 + 0x0)) = SUB1610(auVar87 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar85 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar85 + 0x0)) = SUB1611(auVar86 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar84 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar84 + 0x0)) = SUB1612(auVar85 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar83 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar83 + 0x0)) = SUB1613(auVar84 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar278 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar278 + 0x0)) = SUB1614(auVar83 << 0x18,2);
  { auto &&__rea_tmp = (auVar278 << 0x10); memcpy(auVar278, &__rea_tmp, sizeof(auVar278)); }
  bVar65 = (byte)param_1[0x13];
  bVar66 = *(byte *)((long)param_1 + 0x4d);
  bVar67 = *(byte *)((long)param_1 + 0x4e);
  bVar68 = *(byte *)((long)param_1 + 0x4f);
  uVar69 = (undefined1)param_1[0x14];
  uVar70 = *(undefined1 *)((long)param_1 + 0x51);
  uVar71 = *(undefined1 *)((long)param_1 + 0x52);
  uVar72 = *(undefined1 *)((long)param_1 + 0x53);
  uVar73 = (undefined1)param_1[0x15];
  uVar74 = *(undefined1 *)((long)param_1 + 0x55);
  uVar75 = *(undefined1 *)((long)param_1 + 0x56);
  uVar76 = *(undefined1 *)((long)param_1 + 0x57);
  uVar77 = (undefined1)param_1[0x16];
  bVar376 = auVar6[8];
  bVar377 = auVar6[9];
  bVar378 = auVar6[10];
  bVar379 = auVar6[0xb];
  uVar380 = auVar6[0xc];
  uVar381 = auVar6[0xd];
  uVar382 = auVar6[0xe];
  uVar383 = auVar6[0xf];
  (*(arr_undefined1_14 *)((uint8_t *)&auVar293 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar278 + 0x0));
  auVar293[0xe] = uVar58;
  auVar293[0xf] = uVar62;
  (*(undefined2 *)((uint8_t *)&auVar292 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar293 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar292 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar278 + 0x0));
  auVar292[0xd] = uVar55;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar291 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar292 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar291 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar278 + 0x0));
  auVar291[0xc] = *(undefined1 *)((long)param_1 + 0x2d);
  (*(undefined4 *)((uint8_t *)&auVar290 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar291 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar290 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar278 + 0x0));
  auVar290[0xb] = uVar355;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar289 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar290 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar289 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar278 + 0x0));
  auVar289[10] = uVar353;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar288 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar289 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar288 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar278 + 0x0));
  auVar288[9] = uVar372;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar287 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar288 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar287 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar278 + 0x0));
  auVar287[8] = auVar5[1];
  (*(undefined8 *)((uint8_t *)&auVar92 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar287 + 0x8));
  auVar92[0] = uVar61;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar92 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar91 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar91 + 0x0)) = SUB1610(auVar92 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar90 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar90 + 0x0)) = SUB1611(auVar91 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar89 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar89 + 0x0)) = SUB1612(auVar90 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar88 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar88 + 0x0)) = SUB1613(auVar89 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar286 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar286 + 0x0)) = SUB1614(auVar88 << 0x18,2);
  { auto &&__rea_tmp = (auVar286 << 0x10); memcpy(auVar286, &__rea_tmp, sizeof(auVar286)); }
  uVar366 = auVar6[7];
  uVar365 = auVar6[6];
  uVar364 = auVar6[5];
  uVar363 = auVar6[4];
  bVar362 = auVar6[3];
  bVar361 = auVar6[2];
  bVar360 = auVar6[1];
  auVar224[0xe] = uVar366;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar224 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar6 + 0x0));
  auVar224[0xf] = uVar72;
  (*(undefined2 *)((uint8_t *)&auVar223 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar224 + 0x14));
  auVar223[0xd] = uVar71;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar223 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar6 + 0x0));
  (*(arr_undefined1_3 *)((uint8_t *)&auVar222 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar223 + 0x13));
  auVar222[0xc] = uVar365;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar222 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar6 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar221 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar222 + 0x12));
  auVar221[0xb] = uVar70;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar221 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar6 + 0x0));
  (*(arr_undefined1_5 *)((uint8_t *)&auVar220 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar221 + 0x11));
  auVar220[10] = uVar364;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar220 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar6 + 0x0));
  (*(arr_undefined1_6 *)((uint8_t *)&auVar219 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar220 + 0x10));
  auVar219[9] = uVar69;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar219 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar6 + 0x0));
  (*(arr_undefined1_7 *)((uint8_t *)&auVar218 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar219 + 0x9));
  auVar218[8] = uVar363;
  (*(undefined8 *)((uint8_t *)&auVar218 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar6 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar97 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar218 + 0x8));
  auVar97[0] = bVar68;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar97 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar96 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar96 + 0x0)) = SUB1610(auVar97 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar95 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar95 + 0x0)) = SUB1611(auVar96 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar94 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar94 + 0x0)) = SUB1612(auVar95 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar93 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar93 + 0x0)) = SUB1613(auVar94 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar217 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar217 + 0x0)) = SUB1614(auVar93 << 0x18,2);
  { auto &&__rea_tmp = (auVar217 << 0x10); memcpy(auVar217, &__rea_tmp, sizeof(auVar217)); }
  (*(arr_undefined1_14 *)((uint8_t *)&auVar301 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar286 + 0x0));
  auVar301[0xe] = uVar61;
  auVar301[0xf] = uVar63;
  (*(undefined2 *)((uint8_t *)&auVar300 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar301 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar300 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar286 + 0x0));
  auVar300[0xd] = uVar59;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar299 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar300 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar299 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar286 + 0x0));
  auVar299[0xc] = (char)param_1[0xd];
  (*(undefined4 *)((uint8_t *)&auVar298 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar299 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar298 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar286 + 0x0));
  auVar298[0xb] = uVar56;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar297 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar298 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar297 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar286 + 0x0));
  auVar297[10] = uVar54;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar296 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar297 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar296 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar286 + 0x0));
  auVar296[9] = uVar52;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar295 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar296 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar295 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar286 + 0x0));
  auVar295[8] = (char)param_1[0xb];
  (*(undefined8 *)((uint8_t *)&auVar102 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar295 + 0x8));
  auVar102[0] = auVar328[0xe];
  (*(arr_undefined1_7 *)((uint8_t *)&auVar102 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar101 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar101 + 0x0)) = SUB1610(auVar102 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar100 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar100 + 0x0)) = SUB1611(auVar101 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar99 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar99 + 0x0)) = SUB1612(auVar100 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar98 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar98 + 0x0)) = SUB1613(auVar99 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar294 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar294 + 0x0)) = SUB1614(auVar98 << 0x18,2);
  { auto &&__rea_tmp = (auVar294 << 0x10); memcpy(auVar294, &__rea_tmp, sizeof(auVar294)); }
  (*(arr_undefined1_14 *)((uint8_t *)&auVar232 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar217 + 0x0));
  auVar232[0xe] = bVar68;
  auVar232[0xf] = uVar76;
  (*(undefined2 *)((uint8_t *)&auVar231 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar232 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar231 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar217 + 0x0));
  auVar231[0xd] = bVar379;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar230 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar231 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar230 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar217 + 0x0));
  auVar230[0xc] = bVar362;
  (*(undefined4 *)((uint8_t *)&auVar229 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar230 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar229 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar217 + 0x0));
  auVar229[0xb] = uVar75;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar228 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar229 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar228 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar217 + 0x0));
  auVar228[10] = bVar67;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar227 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar228 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar227 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar217 + 0x0));
  auVar227[9] = bVar378;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar226 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar227 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar226 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar217 + 0x0));
  auVar226[8] = bVar361;
  (*(undefined8 *)((uint8_t *)&auVar107 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar226 + 0x8));
  auVar107[0] = uVar74;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar107 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar106 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar106 + 0x0)) = SUB1610(auVar107 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar105 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar105 + 0x0)) = SUB1611(auVar106 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar104 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar104 + 0x0)) = SUB1612(auVar105 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar103 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar103 + 0x0)) = SUB1613(auVar104 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar225 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar225 + 0x0)) = SUB1614(auVar103 << 0x18,2);
  { auto &&__rea_tmp = (auVar225 << 0x10); memcpy(auVar225, &__rea_tmp, sizeof(auVar225)); }
  (*(arr_undefined1_14 *)((uint8_t *)&auVar240 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar225 + 0x0));
  auVar240[0xe] = uVar74;
  auVar240[0xf] = *(undefined1 *)((long)param_1 + 0x59);
  (*(undefined2 *)((uint8_t *)&auVar239 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar240 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar239 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar225 + 0x0));
  auVar239[0xd] = uVar70;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar238 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar239 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar238 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar225 + 0x0));
  auVar238[0xc] = bVar66;
  (*(undefined4 *)((uint8_t *)&auVar237 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar238 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar237 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar225 + 0x0));
  auVar237[0xb] = uVar381;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar236 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar237 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar236 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar225 + 0x0));
  auVar236[10] = bVar377;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar235 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar236 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar235 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar225 + 0x0));
  auVar235[9] = uVar364;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar234 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar235 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar234 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar225 + 0x0));
  auVar234[8] = bVar360;
  (*(undefined8 *)((uint8_t *)&auVar112 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar234 + 0x8));
  auVar112[0] = uVar77;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar112 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar111 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar111 + 0x0)) = SUB1610(auVar112 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar110 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar110 + 0x0)) = SUB1611(auVar111 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar109 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar109 + 0x0)) = SUB1612(auVar110 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar108 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar108 + 0x0)) = SUB1613(auVar109 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar233 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar233 + 0x0)) = SUB1614(auVar108 << 0x18,2);
  { auto &&__rea_tmp = (auVar233 << 0x10); memcpy(auVar233, &__rea_tmp, sizeof(auVar233)); }
  (*(arr_undefined1_14 *)((uint8_t *)&auVar243 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar233 + 0x0));
  auVar243[0xe] = uVar77;
  auVar243[0xf] = *(undefined1 *)((long)param_1 + 0x5a);
  (*(undefined2 *)((uint8_t *)&auVar242 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar243 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar242 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar233 + 0x0));
  auVar242[0xd] = uVar75;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar241 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar242 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar241 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar233 + 0x0));
  auVar241[0xc] = uVar73;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar328 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar294 + 0x0));
  auVar328[0xf] = uVar382;
  (*(undefined2 *)((uint8_t *)&auVar327 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar328 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar327 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar294 + 0x0));
  auVar327[0xd] = uVar380;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar326 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar327 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar326 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar294 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar325 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar326 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar325 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar294 + 0x0));
  auVar325[0xb] = bVar378;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar324 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar325 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar324 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar294 + 0x0));
  (*(arr_undefined1_6 *)((uint8_t *)&auVar323 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar324 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar323 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar294 + 0x0));
  auVar323[9] = bVar376;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar322 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar323 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar322 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar294 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar117 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar322 + 0x8));
  auVar117[0] = uVar365;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar117 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar116 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar116 + 0x0)) = SUB1610(auVar117 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar115 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar115 + 0x0)) = SUB1611(auVar116 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar114 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar114 + 0x0)) = SUB1612(auVar115 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar113 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar113 + 0x0)) = SUB1613(auVar114 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar321 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar321 + 0x0)) = SUB1614(auVar113 << 0x18,2);
  { auto &&__rea_tmp = (auVar321 << 0x10); memcpy(auVar321, &__rea_tmp, sizeof(auVar321)); }
  auVar308[0xe] = auVar328[0xe];
  (*(arr_undefined1_14 *)((uint8_t *)&auVar308 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar328 + 0x0));
  auVar308[0xf] = uVar382;
  (*(undefined2 *)((uint8_t *)&auVar307 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar308 + 0x14));
  auVar307[0xd] = uVar380;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar307 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar327 + 0x0));
  (*(arr_undefined1_3 *)((uint8_t *)&auVar306 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar307 + 0x13));
  auVar306[0xc] = auVar326[0xc];
  (*(arr_undefined1_12 *)((uint8_t *)&auVar306 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar326 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar305 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar306 + 0x12));
  auVar305[0xb] = bVar378;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar305 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar325 + 0x0));
  (*(arr_undefined1_5 *)((uint8_t *)&auVar304 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar305 + 0x11));
  auVar304[10] = auVar324[10];
  (*(arr_undefined1_10 *)((uint8_t *)&auVar304 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar324 + 0x0));
  (*(arr_undefined1_6 *)((uint8_t *)&auVar303 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar304 + 0x10));
  auVar303[9] = bVar376;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar303 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar323 + 0x0));
  (*(arr_undefined1_7 *)((uint8_t *)&auVar302 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar303 + 0x9));
  auVar302[8] = auVar322[8];
  (*(undefined8 *)((uint8_t *)&auVar302 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar322 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar121 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar302 + 0x8));
  auVar121[0] = uVar365;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar121 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar120 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar120 + 0x0)) = SUB1610(auVar121 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar119 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar119 + 0x0)) = SUB1611(auVar120 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar118 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar118 + 0x0)) = SUB1612(auVar119 << 0x28,4);
  (*(arr_undefined1_13 *)((uint8_t *)&auVar7 + 0x1)) = SUB1613(auVar118 << 0x20,3);
  auVar7[0] = bVar369;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar315 + 0x0)) = auVar7 << 0x10;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar336 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar321 + 0x0));
  auVar336[0xe] = uVar365;
  auVar336[0xf] = uVar71;
  (*(undefined2 *)((uint8_t *)&auVar335 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar336 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar335 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar321 + 0x0));
  auVar335[0xd] = uVar56;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar334 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar335 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar334 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar321 + 0x0));
  auVar334[0xc] = uVar373;
  (*(undefined4 *)((uint8_t *)&auVar333 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar334 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar333 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar321 + 0x0));
  auVar333[0xb] = uVar69;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar332 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar333 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar332 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar321 + 0x0));
  auVar332[10] = uVar363;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar331 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar332 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar331 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar321 + 0x0));
  auVar331[9] = uVar54;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar330 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar331 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar330 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar321 + 0x0));
  auVar330[8] = uVar371;
  (*(undefined8 *)((uint8_t *)&auVar126 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar330 + 0x8));
  auVar126[0] = bVar67;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar126 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar125 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar125 + 0x0)) = SUB1610(auVar126 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar124 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar124 + 0x0)) = SUB1611(auVar125 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar123 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar123 + 0x0)) = SUB1612(auVar124 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar122 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar122 + 0x0)) = SUB1613(auVar123 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar329 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar329 + 0x0)) = SUB1614(auVar122 << 0x18,2);
  { auto &&__rea_tmp = (auVar329 << 0x10); memcpy(auVar329, &__rea_tmp, sizeof(auVar329)); }
  auVar315[0xe] = uVar365;
  auVar315[0xf] = uVar71;
  (*(undefined2 *)((uint8_t *)&auVar314 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar315 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar314 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar315 + 0x0));
  auVar314[0xd] = uVar56;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar313 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar314 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar313 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar315 + 0x0));
  auVar313[0xc] = uVar373;
  (*(undefined4 *)((uint8_t *)&auVar312 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar313 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar312 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar315 + 0x0));
  auVar312[0xb] = uVar69;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar311 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar312 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar311 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar315 + 0x0));
  auVar311[10] = uVar363;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar310 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar311 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar310 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar315 + 0x0));
  auVar310[9] = uVar54;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar309 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar310 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar309 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar315 + 0x0));
  auVar309[8] = uVar371;
  (*(undefined8 *)((uint8_t *)&auVar128 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar309 + 0x8));
  auVar128[0] = bVar67;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar128 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar127 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar127 + 0x0)) = SUB1610(auVar128 << 0x38,6);
  (*(arr_undefined1_11 *)((uint8_t *)&auVar9 + 0x1)) = SUB1611(auVar127 << 0x30,5);
  auVar9[0] = bVar369;
  (*(undefined4 *)((uint8_t *)&auVar9 + 0x12)) = 0;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar8 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar8 + 0x0)) = SUB1613(auVar9 << 0x20,3);
  (*(arr_undefined1_14 *)((uint8_t *)&auVar318 + 0x0)) = SUB1614(auVar8 << 0x18,2) << 0x10;
  (*(undefined8 *)((uint8_t *)&auVar133 + 0x1)) =
       (long)(CONCAT72(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(uVar383,uVar356),
                                                                    uVar381),uVar355),bVar379),
                                         uVar354),bVar377),CONCAT11(uVar353,uVar356)) >> 8);
  auVar133[0] = uVar366;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar133 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar132 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar132 + 0x0)) = SUB1610(auVar133 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar131 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar131 + 0x0)) = SUB1611(auVar132 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar130 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar130 + 0x0)) = SUB1612(auVar131 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar129 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar129 + 0x0)) = SUB1613(auVar130 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar244 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar244 + 0x0)) = SUB1614(auVar129 << 0x18,2);
  { auto &&__rea_tmp = (auVar244 << 0x10); memcpy(auVar244, &__rea_tmp, sizeof(auVar244)); }
  (*(arr_undefined1_14 *)((uint8_t *)&auVar344 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar329 + 0x0));
  auVar344[0xe] = bVar67;
  auVar344[0xf] = uVar75;
  (*(undefined2 *)((uint8_t *)&auVar343 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar344 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar343 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar329 + 0x0));
  auVar343[0xd] = bVar378;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar342 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar343 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar342 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar329 + 0x0));
  auVar342[0xc] = bVar361;
  (*(undefined4 *)((uint8_t *)&auVar341 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar342 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar341 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar329 + 0x0));
  auVar341[0xb] = uVar59;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar340 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar341 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar340 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar329 + 0x0));
  auVar340[10] = uVar52;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar339 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar340 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar339 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar329 + 0x0));
  auVar339[9] = auVar324[10];
  (*(arr_undefined1_7 *)((uint8_t *)&auVar338 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar339 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar338 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar329 + 0x0));
  auVar338[8] = bVar369;
  (*(undefined8 *)((uint8_t *)&auVar138 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar338 + 0x8));
  auVar138[0] = uVar73;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar138 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar137 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar137 + 0x0)) = SUB1610(auVar138 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar136 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar136 + 0x0)) = SUB1611(auVar137 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar135 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar135 + 0x0)) = SUB1612(auVar136 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar134 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar134 + 0x0)) = SUB1613(auVar135 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar337 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar337 + 0x0)) = SUB1614(auVar134 << 0x18,2);
  { auto &&__rea_tmp = (auVar337 << 0x10); memcpy(auVar337, &__rea_tmp, sizeof(auVar337)); }
  auVar318[0xe] = bVar67;
  auVar318[0xf] = uVar75;
  (*(undefined2 *)((uint8_t *)&auVar317 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar318 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar317 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar318 + 0x0));
  auVar317[0xd] = bVar378;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar316 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar317 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar316 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar318 + 0x0));
  auVar316[0xc] = bVar361;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar252 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar244 + 0x0));
  auVar252[0xe] = uVar366;
  auVar252[0xf] = uVar72;
  (*(undefined2 *)((uint8_t *)&auVar251 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar252 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar251 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar244 + 0x0));
  auVar251[0xd] = uVar57;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar250 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar251 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar250 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar244 + 0x0));
  auVar250[0xc] = uVar374;
  (*(undefined4 *)((uint8_t *)&auVar249 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar250 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar249 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar244 + 0x0));
  auVar249[0xb] = uVar70;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar248 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar249 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar248 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar244 + 0x0));
  auVar248[10] = uVar364;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar247 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar248 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar247 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar244 + 0x0));
  auVar247[9] = uVar55;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar246 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar247 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar246 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar244 + 0x0));
  auVar246[8] = uVar372;
  (*(undefined8 *)((uint8_t *)&auVar143 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar246 + 0x8));
  auVar143[0] = bVar68;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar143 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar142 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar142 + 0x0)) = SUB1610(auVar143 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar141 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar141 + 0x0)) = SUB1611(auVar142 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar140 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar140 + 0x0)) = SUB1612(auVar141 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar139 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar139 + 0x0)) = SUB1613(auVar140 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar245 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar245 + 0x0)) = SUB1614(auVar139 << 0x18,2);
  { auto &&__rea_tmp = (auVar245 << 0x10); memcpy(auVar245, &__rea_tmp, sizeof(auVar245)); }
  (*(arr_undefined1_14 *)((uint8_t *)&auVar352 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar337 + 0x0));
  auVar352[0xe] = uVar73;
  auVar352[0xf] = uVar77;
  (*(undefined2 *)((uint8_t *)&auVar351 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar352 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar351 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar337 + 0x0));
  auVar351[0xd] = uVar69;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar350 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar351 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar350 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar337 + 0x0));
  auVar350[0xc] = bVar65;
  (*(undefined4 *)((uint8_t *)&auVar349 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar350 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar349 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar337 + 0x0));
  auVar349[0xb] = uVar380;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar348 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar349 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar348 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar337 + 0x0));
  auVar348[10] = bVar376;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar347 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar348 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar347 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar337 + 0x0));
  auVar347[9] = uVar363;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar346 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar347 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar346 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar337 + 0x0));
  auVar346[8] = auVar6[0];
  (*(undefined8 *)((uint8_t *)&auVar148 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar346 + 0x8));
  auVar148[0] = uVar61;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar148 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar147 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar147 + 0x0)) = SUB1610(auVar148 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar146 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar146 + 0x0)) = SUB1611(auVar147 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar145 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar145 + 0x0)) = SUB1612(auVar146 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar144 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar144 + 0x0)) = SUB1613(auVar145 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar345 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar345 + 0x0)) = SUB1614(auVar144 << 0x18,2);
  { auto &&__rea_tmp = (auVar345 << 0x10); memcpy(auVar345, &__rea_tmp, sizeof(auVar345)); }
  uVar184 = CONCAT12(uVar365,CONCAT11(bVar361,uVar63));
  uVar213 = CONCAT13(bVar378,uVar184);
  uVar195 = CONCAT14(uVar382,uVar213);
  auVar201[5] = bVar67;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar201 + 0x0)) = uVar195;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar260 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar245 + 0x0));
  auVar260[0xe] = bVar68;
  auVar260[0xf] = uVar76;
  (*(undefined2 *)((uint8_t *)&auVar259 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar260 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar259 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar245 + 0x0));
  auVar259[0xd] = bVar379;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar258 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar259 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar258 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar245 + 0x0));
  auVar258[0xc] = bVar362;
  (*(undefined4 *)((uint8_t *)&auVar257 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar258 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar257 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar245 + 0x0));
  auVar257[0xb] = uVar60;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar256 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar257 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar256 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar245 + 0x0));
  auVar256[10] = uVar53;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar255 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar256 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar255 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar245 + 0x0));
  auVar255[9] = uVar354;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar254 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar255 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar254 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar245 + 0x0));
  auVar254[8] = bVar370;
  (*(undefined8 *)((uint8_t *)&auVar153 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar254 + 0x8));
  auVar153[0] = uVar74;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar153 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar152 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar152 + 0x0)) = SUB1610(auVar153 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar151 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar151 + 0x0)) = SUB1611(auVar152 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar150 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar150 + 0x0)) = SUB1612(auVar151 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar149 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar149 + 0x0)) = SUB1613(auVar150 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar253 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar253 + 0x0)) = SUB1614(auVar149 << 0x18,2);
  { auto &&__rea_tmp = (auVar253 << 0x10); memcpy(auVar253, &__rea_tmp, sizeof(auVar253)); }
  uVar185 = CONCAT12(uVar366,CONCAT11(bVar362,uVar64));
  uVar206 = CONCAT13(bVar379,uVar185);
  uVar196 = CONCAT14(uVar383,uVar206);
  auVar202[5] = bVar68;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar202 + 0x0)) = uVar196;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar268 + 0x0)) = (*(arr_undefined1_14 *)((uint8_t *)&auVar253 + 0x0));
  auVar268[0xe] = uVar74;
  auVar268[0xf] = *(undefined1 *)((long)param_1 + 0x59);
  (*(undefined2 *)((uint8_t *)&auVar267 + 0x14)) = (*(undefined2 *)((uint8_t *)&auVar268 + 0x14));
  (*(arr_undefined1_13 *)((uint8_t *)&auVar267 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar253 + 0x0));
  auVar267[0xd] = uVar70;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar266 + 0x13)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar267 + 0x13));
  (*(arr_undefined1_12 *)((uint8_t *)&auVar266 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar253 + 0x0));
  auVar266[0xc] = bVar66;
  (*(undefined4 *)((uint8_t *)&auVar265 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar266 + 0x12));
  (*(arr_undefined1_11 *)((uint8_t *)&auVar265 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar253 + 0x0));
  auVar265[0xb] = uVar381;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar264 + 0x11)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar265 + 0x11));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar264 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar253 + 0x0));
  auVar264[10] = bVar377;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar263 + 0x10)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar264 + 0x10));
  (*(arr_undefined1_9 *)((uint8_t *)&auVar263 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar253 + 0x0));
  auVar263[9] = uVar364;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar262 + 0x9)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar263 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar262 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar253 + 0x0));
  auVar262[8] = bVar360;
  (*(undefined8 *)((uint8_t *)&auVar158 + 0x1)) = (*(undefined8 *)((uint8_t *)&auVar262 + 0x8));
  auVar158[0] = uVar62;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar158 + 0x9)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar157 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar157 + 0x0)) = SUB1610(auVar158 << 0x38,6);
  (*(arr_undefined1_5 *)((uint8_t *)&auVar156 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar156 + 0x0)) = SUB1611(auVar157 << 0x30,5);
  (*(undefined4 *)((uint8_t *)&auVar155 + 0x12)) = 0;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar155 + 0x0)) = SUB1612(auVar156 << 0x28,4);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar154 + 0x13)) = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar154 + 0x0)) = SUB1613(auVar155 << 0x20,3);
  (*(undefined2 *)((uint8_t *)&auVar261 + 0x14)) = 0;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar261 + 0x0)) = SUB1614(auVar154 << 0x18,2);
  { auto &&__rea_tmp = (auVar261 << 0x10); memcpy(auVar261, &__rea_tmp, sizeof(auVar261)); }
  uVar320 = CONCAT13(0,CONCAT12(uVar363,(ushort)auVar6[0]));
  auVar10[0xd] = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar10 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar345 + 0x0));
  auVar10[0xe] = uVar61;
  auVar18[0xc] = (char)param_1[0xd];
  (*(arr_undefined1_12 *)((uint8_t *)&auVar18 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar345 + 0x0));
  (*(undefined2 *)((uint8_t *)&auVar18 + 0x13)) = (*(undefined2 *)((uint8_t *)&auVar10 + 0x13));
  auVar20[0xb] = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar20 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar345 + 0x0));
  (*(arr_undefined1_3 *)((uint8_t *)&auVar20 + 0x12)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar18 + 0x12));
  uVar209 = (*(undefined4 *)((uint8_t *)&auVar20 + 0x11));
  auVar24[10] = uVar54;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar24 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar345 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar24 + 0x11)) = uVar209;
  auVar42[9] = 0;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar42 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar345 + 0x0));
  (*(arr_undefined1_5 *)((uint8_t *)&auVar42 + 0x10)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar24 + 0x10));
  auVar46[8] = (char)param_1[0xb];
  (*(undefined8 *)((uint8_t *)&auVar46 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar345 + 0x0));
  (*(arr_undefined1_6 *)((uint8_t *)&auVar46 + 0x9)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar42 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar159 + 0x7)) = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar159 + 0x0)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar46 + 0x8));
  Var160 = CONCAT81(SUB158(auVar159 << 0x40,7),auVar326[0xc]);
  (*(arr_undefined1_6 *)((uint8_t *)&auVar186 + 0x9)) = 0;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar186 + 0x0)) = Var160;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar161 + 0x1)) = SUB1510(auVar186 << 0x30,5);
  auVar161[0] = auVar322[8];
  (*(undefined4 *)((uint8_t *)&auVar162 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar162 + 0x0)) = auVar161;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar163 + 0x1)) = SUB1512(auVar162 << 0x20,3);
  auVar163[0] = uVar371;
  auVar48[1] = 0;
  auVar48[0] = auVar5[0];
  (*(arr_undefined1_13 *)((uint8_t *)&auVar48 + 0x2)) = auVar163;
  uVar207 = CONCAT13(0,CONCAT12(uVar364,(ushort)bVar360));
  auVar11[0xd] = 0;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar11 + 0x0)) = (*(arr_undefined1_13 *)((uint8_t *)&auVar261 + 0x0));
  auVar11[0xe] = uVar62;
  auVar19[0xc] = uVar58;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar19 + 0x0)) = (*(arr_undefined1_12 *)((uint8_t *)&auVar261 + 0x0));
  (*(undefined2 *)((uint8_t *)&auVar19 + 0x13)) = (*(undefined2 *)((uint8_t *)&auVar11 + 0x13));
  auVar21[0xb] = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar21 + 0x0)) = (*(arr_undefined1_11 *)((uint8_t *)&auVar261 + 0x0));
  (*(arr_undefined1_3 *)((uint8_t *)&auVar21 + 0x12)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar19 + 0x12));
  uVar212 = (*(undefined4 *)((uint8_t *)&auVar21 + 0x11));
  auVar25[10] = uVar55;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar25 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar261 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar25 + 0x11)) = uVar212;
  auVar43[9] = 0;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar43 + 0x0)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar261 + 0x0));
  (*(arr_undefined1_5 *)((uint8_t *)&auVar43 + 0x10)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar25 + 0x10));
  auVar47[8] = *(undefined1 *)((long)param_1 + 0x2d);
  (*(undefined8 *)((uint8_t *)&auVar47 + 0x0)) = (*(undefined8 *)((uint8_t *)&auVar261 + 0x0));
  (*(arr_undefined1_6 *)((uint8_t *)&auVar47 + 0x9)) = (*(arr_undefined1_6 *)((uint8_t *)&auVar43 + 0x9));
  (*(undefined8 *)((uint8_t *)&auVar164 + 0x7)) = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar164 + 0x0)) = (*(arr_undefined1_7 *)((uint8_t *)&auVar47 + 0x8));
  Var165 = CONCAT81(SUB158(auVar164 << 0x40,7),uVar355);
  (*(arr_undefined1_6 *)((uint8_t *)&auVar187 + 0x9)) = 0;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar187 + 0x0)) = Var165;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar166 + 0x1)) = SUB1510(auVar187 << 0x30,5);
  auVar166[0] = uVar353;
  (*(undefined4 *)((uint8_t *)&auVar188 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar188 + 0x0)) = auVar166;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar167 + 0x1)) = SUB1512(auVar188 << 0x20,3);
  auVar167[0] = uVar372;
  auVar49[1] = 0;
  auVar49[0] = auVar5[1];
  (*(arr_undefined1_13 *)((uint8_t *)&auVar49 + 0x2)) = auVar167;
  uVar269 = CONCAT13(0,CONCAT12(uVar365,(ushort)bVar361));
  (*(undefined8 *)((uint8_t *)&auVar201 + 0x6)) = 0;
  auVar12[0xe] = uVar63;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar12 + 0x0)) = auVar201 << 0x38;
  (*(undefined8 *)((uint8_t *)&auVar197 + 0x4)) = 0;
  (*(undefined4 *)((uint8_t *)&auVar197 + 0x0)) = uVar213;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar22 + 0x12)) = (int3)(CONCAT26((*(undefined2 *)((uint8_t *)&auVar12 + 0x13)),CONCAT15(uVar59,uVar195)) >> 0x28);
  (*(arr_undefined1_12 *)((uint8_t *)&auVar22 + 0x0)) = auVar197 << 0x38;
  uVar213 = (*(undefined4 *)((uint8_t *)&auVar22 + 0x11));
  uVar198 = CONCAT44(uVar213,CONCAT13(uVar56,uVar184));
  (*(arr_undefined1_5 *)((uint8_t *)&auVar44 + 0x10)) = (int5)((ulong)uVar198 >> 0x18);
  (*(arr_undefined1_10 *)((uint8_t *)&auVar44 + 0x0)) = (unkuint10)CONCAT11(bVar361,uVar63) << 0x38;
  uVar189 = CONCAT62((*(arr_undefined1_6 *)((uint8_t *)&auVar44 + 0x9)),CONCAT11(uVar52,uVar63));
  (*(undefined8 *)((uint8_t *)&auVar168 + 0x7)) = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar168 + 0x0)) = (uint7)((ulong)uVar189 >> 8);
  Var169 = CONCAT81(SUB158(auVar168 << 0x40,7),auVar328[0xe]);
  (*(arr_undefined1_6 *)((uint8_t *)&auVar190 + 0x9)) = 0;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar190 + 0x0)) = Var169;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar170 + 0x1)) = SUB1510(auVar190 << 0x30,5);
  auVar170[0] = auVar324[10];
  (*(undefined4 *)((uint8_t *)&auVar191 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar191 + 0x0)) = auVar170;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar171 + 0x1)) = SUB1512(auVar191 << 0x20,3);
  auVar171[0] = uVar373;
  auVar50[1] = 0;
  auVar50[0] = bVar369;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar50 + 0x2)) = auVar171;
  uVar367 = CONCAT13(0,CONCAT12(uVar366,(ushort)bVar362));
  (*(undefined8 *)((uint8_t *)&auVar202 + 0x6)) = 0;
  auVar13[0xe] = uVar64;
  (*(arr_undefined1_14 *)((uint8_t *)&auVar13 + 0x0)) = auVar202 << 0x38;
  uVar203 = CONCAT26((*(undefined2 *)((uint8_t *)&auVar13 + 0x13)),CONCAT15(uVar60,uVar196));
  (*(undefined8 *)((uint8_t *)&auVar199 + 0x4)) = 0;
  (*(undefined4 *)((uint8_t *)&auVar199 + 0x0)) = uVar206;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar23 + 0x12)) = (int3)((ulong)uVar203 >> 0x28);
  (*(arr_undefined1_12 *)((uint8_t *)&auVar23 + 0x0)) = auVar199 << 0x38;
  uVar200 = CONCAT44((*(undefined4 *)((uint8_t *)&auVar23 + 0x11)),CONCAT13(uVar57,uVar185));
  (*(arr_undefined1_5 *)((uint8_t *)&auVar45 + 0x10)) = (int5)((ulong)uVar200 >> 0x18);
  (*(arr_undefined1_10 *)((uint8_t *)&auVar45 + 0x0)) = (unkuint10)CONCAT11(bVar362,uVar64) << 0x38;
  uVar192 = CONCAT62((*(arr_undefined1_6 *)((uint8_t *)&auVar45 + 0x9)),CONCAT11(uVar53,uVar64));
  (*(undefined8 *)((uint8_t *)&auVar172 + 0x7)) = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar172 + 0x0)) = (uint7)((ulong)uVar192 >> 8);
  Var173 = CONCAT81(SUB158(auVar172 << 0x40,7),uVar356);
  (*(arr_undefined1_6 *)((uint8_t *)&auVar193 + 0x9)) = 0;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar193 + 0x0)) = Var173;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar174 + 0x1)) = SUB1510(auVar193 << 0x30,5);
  auVar174[0] = uVar354;
  (*(undefined4 *)((uint8_t *)&auVar194 + 0x11)) = 0;
  (*(arr_undefined1_11 *)((uint8_t *)&auVar194 + 0x0)) = auVar174;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar175 + 0x1)) = SUB1512(auVar194 << 0x20,3);
  auVar175[0] = uVar374;
  auVar51[1] = 0;
  auVar51[0] = bVar370;
  (*(arr_undefined1_13 *)((uint8_t *)&auVar51 + 0x2)) = auVar175;
  (*(undefined2 *)((uint8_t *)&auVar14 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar14 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar50 + 0x0));
  (*(undefined2 *)((uint8_t *)&auVar14 + 0x12)) = (short)Var169;
  uVar204 = CONCAT42((*(undefined4 *)((uint8_t *)&auVar14 + 0x10)),(*(undefined2 *)((uint8_t *)&auVar170 + 0x0)));
  (*(undefined8 *)((uint8_t *)&auVar176 + 0x6)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar176 + 0x0)) = uVar204;
  (*(undefined2 *)((uint8_t *)&auVar26 + 0x4)) = (*(undefined2 *)((uint8_t *)&auVar171 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar26 + 0x0)) = (*(undefined4 *)((uint8_t *)&auVar50 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar26 + 0x6)) = SUB148(auVar176 << 0x40,6);
  (*(undefined2 *)((uint8_t *)&auVar15 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar15 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar49 + 0x0));
  (*(undefined2 *)((uint8_t *)&auVar15 + 0x12)) = (short)Var165;
  uVar205 = CONCAT42((*(undefined4 *)((uint8_t *)&auVar15 + 0x10)),(*(undefined2 *)((uint8_t *)&auVar166 + 0x0)));
  (*(undefined8 *)((uint8_t *)&auVar177 + 0x6)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar177 + 0x0)) = uVar205;
  (*(undefined2 *)((uint8_t *)&auVar27 + 0x4)) = (*(undefined2 *)((uint8_t *)&auVar167 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar27 + 0x0)) = (*(undefined4 *)((uint8_t *)&auVar49 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar27 + 0x6)) = SUB148(auVar177 << 0x40,6);
  (*(undefined4 *)((uint8_t *)&auVar5 + 0x2)) = (uint)(*(undefined2 *)((uint8_t *)&auVar25 + 0x10)) << 0x10;
  (*(undefined2 *)((uint8_t *)&auVar5 + 0x0)) = (*(undefined2 *)((uint8_t *)&auVar47 + 0x8));
  (*(undefined4 *)((uint8_t *)&auVar5 + 0x6)) = (uVar212 >> 8) << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar5 + 0x10)) = (uVar212 >> 0x18) << 0x10;
  (*(undefined2 *)((uint8_t *)&auVar5 + 0x14)) = 0;
  (*(undefined4 *)((uint8_t *)&local_198 + 0x4)) = (*(undefined4 *)((uint8_t *)&auVar27 + 0x4)) << 0x10 | (*(undefined4 *)((uint8_t *)&auVar26 + 0x4)) << 8;
  (*(undefined4 *)((uint8_t *)&local_198 + 0x0)) = (*(undefined4 *)((uint8_t *)&auVar49 + 0x0)) << 0x10 | ((*(undefined4 *)((uint8_t *)&auVar50 + 0x0)) & 0xffff) << 8;
  (*(undefined4 *)((uint8_t *)&local_198 + 0x8)) = (int)uVar205 << 0x10 | (int)uVar204 << 8;
  (*(undefined4 *)((uint8_t *)&local_198 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar15 + 0x10)) & 0xffff0000 | ((*(undefined4 *)((uint8_t *)&auVar14 + 0x10)) >> 0x10) << 8;
  (*(undefined2 *)((uint8_t *)&auVar387 + 0x2)) = 0;
  (*(undefined2 *)((uint8_t *)&auVar387 + 0x0)) = (ushort)((ulong)uVar192 >> 8);
  (*(undefined2 *)((uint8_t *)&auVar387 + 0x4)) = (short)((ulong)uVar200 >> 0x18);
  (*(undefined2 *)((uint8_t *)&auVar387 + 0x6)) = 0;
  (*(undefined2 *)((uint8_t *)&auVar387 + 0x8)) = (short)((ulong)uVar203 >> 0x28);
  (*(undefined2 *)((uint8_t *)&auVar387 + 0x10)) = 0;
  auVar387[0xc] = uVar64;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar387 + 0x13)) = 0;
  (*(undefined2 *)((uint8_t *)&auVar16 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar16 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar51 + 0x0));
  (*(undefined2 *)((uint8_t *)&auVar16 + 0x12)) = (short)Var173;
  (*(undefined4 *)((uint8_t *)&auVar178 + 0x2)) = (*(undefined4 *)((uint8_t *)&auVar16 + 0x10));
  (*(undefined2 *)((uint8_t *)&auVar178 + 0x0)) = (*(undefined2 *)((uint8_t *)&auVar174 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar178 + 0x6)) = 0;
  (*(undefined2 *)((uint8_t *)&auVar28 + 0x4)) = (*(undefined2 *)((uint8_t *)&auVar175 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar28 + 0x0)) = (*(undefined4 *)((uint8_t *)&auVar51 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar28 + 0x6)) = SUB148(auVar178 << 0x40,6);
  (*(undefined4 *)((uint8_t *)&auVar357 + 0x0)) = (*(undefined4 *)((uint8_t *)&auVar51 + 0x0)) & 0xffff;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar357 + 0x4)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar28 + 0x4));
  (*(undefined2 *)((uint8_t *)&auVar357 + 0x14)) = 0;
  { auto &&__rea_tmp = (auVar357 | local_198); memcpy(auVar357, &__rea_tmp, sizeof(auVar357)); }
  (*(undefined2 *)((uint8_t *)&auVar17 + 0x10)) = 0;
  (*(arr_undefined1_10 *)((uint8_t *)&auVar17 + 0x0)) = (*(arr_undefined1_10 *)((uint8_t *)&auVar48 + 0x0));
  (*(undefined2 *)((uint8_t *)&auVar17 + 0x12)) = (short)Var160;
  uVar204 = CONCAT42((*(undefined4 *)((uint8_t *)&auVar17 + 0x10)),(*(undefined2 *)((uint8_t *)&auVar161 + 0x0)));
  (*(undefined8 *)((uint8_t *)&auVar179 + 0x6)) = 0;
  (*(arr_undefined1_6 *)((uint8_t *)&auVar179 + 0x0)) = uVar204;
  (*(undefined2 *)((uint8_t *)&auVar29 + 0x4)) = (*(undefined2 *)((uint8_t *)&auVar163 + 0x0));
  (*(undefined4 *)((uint8_t *)&auVar29 + 0x0)) = (*(undefined4 *)((uint8_t *)&auVar48 + 0x0));
  (*(undefined8 *)((uint8_t *)&auVar29 + 0x6)) = SUB148(auVar179 << 0x40,6);
  (*(undefined4 *)((uint8_t *)&auVar384 + 0x0)) = (uint)(*(undefined2 *)((uint8_t *)&auVar46 + 0x8)) << 0x18;
  (*(undefined4 *)((uint8_t *)&auVar384 + 0x4)) = (uint)(*(undefined2 *)((uint8_t *)&auVar24 + 0x10)) << 0x18;
  (*(undefined4 *)((uint8_t *)&auVar384 + 0x8)) = (uVar209 >> 8) << 0x18;
  (*(undefined4 *)((uint8_t *)&auVar384 + 0x12)) = uVar209 & 0xff000000;
  (*(undefined4 *)((uint8_t *)&local_198 + 0x0)) = (*(undefined4 *)((uint8_t *)&auVar357 + 0x0));
  (*(undefined4 *)((uint8_t *)&local_198 + 0x4)) = (*(undefined4 *)((uint8_t *)&auVar357 + 0x4));
  (*(undefined4 *)((uint8_t *)&local_198 + 0x8)) = (*(undefined4 *)((uint8_t *)&auVar357 + 0x8));
  (*(undefined4 *)((uint8_t *)&local_198 + 0x12)) = (*(undefined4 *)((uint8_t *)&auVar357 + 0x12));
  local_178[0] = (*(undefined4 *)((uint8_t *)&auVar48 + 0x0)) << 0x18 | (*(undefined4 *)((uint8_t *)&local_198 + 0x0));
  local_178[1] = (*(undefined4 *)((uint8_t *)&auVar29 + 0x4)) << 0x18 | (*(undefined4 *)((uint8_t *)&local_198 + 0x4));
  local_178[2] = (int)uVar204 << 0x18 | (*(undefined4 *)((uint8_t *)&local_198 + 0x8));
  local_178[3] = ((*(undefined4 *)((uint8_t *)&auVar17 + 0x10)) >> 0x10) << 0x18 | (*(undefined4 *)((uint8_t *)&local_198 + 0x12));
  (*(undefined4 *)((uint8_t *)&auVar358 + 0x0)) = (uint)(ushort)((ulong)uVar189 >> 8) << 8;
  (*(undefined4 *)((uint8_t *)&auVar358 + 0x4)) = (uint)(ushort)((ulong)uVar198 >> 0x18) << 8;
  (*(undefined4 *)((uint8_t *)&auVar358 + 0x8)) = (uVar213 >> 8 & 0xffff) << 8;
  (*(undefined4 *)((uint8_t *)&auVar358 + 0x12)) = (uVar213 >> 0x18) << 8;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar368 + 0x1)) = 0;
  auVar368[0] = bVar68;
  auVar368[4] = uVar72;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar368 + 0x5)) = 0;
  auVar368[8] = uVar76;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar368 + 0x9)) = 0;
  auVar368[0xc] = *(undefined1 *)((long)param_1 + 0x5b);
  (*(arr_undefined1_3 *)((uint8_t *)&auVar368 + 0x13)) = 0;
  auVar30[0xc] = uVar383;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar30 + 0x0)) = ZEXT112(bVar68) << 0x40;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar31 + 0x10)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar30 + 0x10));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar31 + 0x0)) = (unkuint10)bVar379 << 0x40;
  (*(undefined8 *)((uint8_t *)&auVar180 + 0x5)) = 0;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar180 + 0x0)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar31 + 0x8));
  auVar32[4] = uVar366;
  (*(undefined4 *)((uint8_t *)&auVar32 + 0x0)) = uVar367;
  auVar32[5] = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar32 + 0x6)) = SUB137(auVar180 << 0x40,6);
  (*(undefined4 *)((uint8_t *)&auVar388 + 0x0)) = uVar367 & 0xffff;
  (*(arr_undefined1_9 *)((uint8_t *)&auVar388 + 0x4)) = (*(arr_undefined1_9 *)((uint8_t *)&auVar32 + 0x4));
  (*(arr_undefined1_3 *)((uint8_t *)&auVar388 + 0x13)) = 0;
  auVar33[0xc] = uVar382;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar33 + 0x0)) = ZEXT112(bVar67) << 0x40;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar34 + 0x10)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar33 + 0x10));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar34 + 0x0)) = (unkuint10)bVar378 << 0x40;
  (*(undefined8 *)((uint8_t *)&auVar181 + 0x5)) = 0;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar181 + 0x0)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar34 + 0x8));
  auVar35[4] = uVar365;
  (*(undefined4 *)((uint8_t *)&auVar35 + 0x0)) = uVar269;
  auVar35[5] = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar35 + 0x6)) = SUB137(auVar181 << 0x40,6);
  { auto &&__rea_tmp = (auVar358 | auVar5 << 0x10 | auVar387 | auVar384); memcpy(local_168, &__rea_tmp, sizeof(local_168)); }
  (*(undefined4 *)((uint8_t *)&auVar319 + 0x0)) = (uint)bVar67 << 8;
  (*(undefined4 *)((uint8_t *)&auVar319 + 0x4)) = ((*(undefined4 *)((uint8_t *)&auVar333 + 0x12)) >> 0x18) << 8;
  (*(undefined4 *)((uint8_t *)&auVar319 + 0x8)) = ((*(undefined4 *)((uint8_t *)&auVar316 + 0x12)) >> 0x18) << 8;
  (*(undefined4 *)((uint8_t *)&auVar319 + 0x12)) = ((*(undefined4 *)((uint8_t *)&auVar241 + 0x12)) >> 0x18) << 8;
  (*(undefined4 *)((uint8_t *)&auVar359 + 0x0)) = (uVar269 & 0xffff) << 8;
  (*(undefined4 *)((uint8_t *)&auVar359 + 0x4)) = (*(undefined4 *)((uint8_t *)&auVar35 + 0x4)) << 8;
  (*(undefined4 *)((uint8_t *)&auVar359 + 0x8)) = (*(undefined4 *)((uint8_t *)&auVar34 + 0x8)) << 8;
  (*(undefined4 *)((uint8_t *)&auVar359 + 0x12)) = (uint)(uint3)((*(arr_undefined1_3 *)((uint8_t *)&auVar33 + 0x10)) >> 0x10) << 8;
  auVar36[0xc] = uVar381;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar36 + 0x0)) = ZEXT112(bVar66) << 0x40;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar37 + 0x10)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar36 + 0x10));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar37 + 0x0)) = (unkuint10)bVar377 << 0x40;
  (*(undefined8 *)((uint8_t *)&auVar182 + 0x5)) = 0;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar182 + 0x0)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar37 + 0x8));
  auVar38[4] = uVar364;
  (*(undefined4 *)((uint8_t *)&auVar38 + 0x0)) = uVar207;
  auVar38[5] = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar38 + 0x6)) = SUB137(auVar182 << 0x40,6);
  (*(undefined4 *)((uint8_t *)&auVar375 + 0x0)) = ((*(undefined4 *)((uint8_t *)&auVar265 + 0x12)) & 0xff) << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar375 + 0x4)) = ((*(undefined4 *)((uint8_t *)&auVar265 + 0x12)) >> 8 & 0xff) << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar375 + 0x8)) = ((*(undefined4 *)((uint8_t *)&auVar265 + 0x12)) >> 0x10 & 0xff) << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar375 + 0x12)) = ((*(undefined4 *)((uint8_t *)&auVar265 + 0x12)) >> 0x18) << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar385 + 0x0)) = uVar207 << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar385 + 0x4)) = (*(undefined4 *)((uint8_t *)&auVar38 + 0x4)) << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar385 + 0x8)) = (*(undefined4 *)((uint8_t *)&auVar37 + 0x8)) << 0x10;
  (*(undefined4 *)((uint8_t *)&auVar385 + 0x12)) = (uint)(uint3)((*(arr_undefined1_3 *)((uint8_t *)&auVar36 + 0x10)) >> 0x10) << 0x10;
  auVar39[0xc] = uVar380;
  (*(arr_undefined1_12 *)((uint8_t *)&auVar39 + 0x0)) = ZEXT112(bVar65) << 0x40;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar40 + 0x10)) = (*(arr_undefined1_3 *)((uint8_t *)&auVar39 + 0x10));
  (*(arr_undefined1_10 *)((uint8_t *)&auVar40 + 0x0)) = (unkuint10)bVar376 << 0x40;
  (*(undefined8 *)((uint8_t *)&auVar183 + 0x5)) = 0;
  (*(arr_undefined1_5 *)((uint8_t *)&auVar183 + 0x0)) = (*(arr_undefined1_5 *)((uint8_t *)&auVar40 + 0x8));
  auVar41[4] = uVar363;
  (*(undefined4 *)((uint8_t *)&auVar41 + 0x0)) = uVar320;
  auVar41[5] = 0;
  (*(arr_undefined1_7 *)((uint8_t *)&auVar41 + 0x6)) = SUB137(auVar183 << 0x40,6);
  (*(undefined4 *)((uint8_t *)&auVar6 + 0x1)) = ((*(undefined4 *)((uint8_t *)&auVar349 + 0x12)) >> 8) << 0x18;
  auVar6[0] = bVar65;
  (*(undefined4 *)((uint8_t *)&auVar6 + 0x5)) = ((*(undefined4 *)((uint8_t *)&auVar349 + 0x12)) >> 0x10) << 0x18;
  (*(undefined4 *)((uint8_t *)&auVar6 + 0x9)) = (*(undefined4 *)((uint8_t *)&auVar349 + 0x12)) & 0xff000000;
  (*(arr_undefined1_3 *)((uint8_t *)&auVar6 + 0x13)) = 0;
  { auto &&__rea_tmp = (auVar319 | auVar375 | auVar368 | auVar6 << 0x18); memcpy(local_148, &__rea_tmp, sizeof(local_148)); }
  (*(undefined4 *)((uint8_t *)&auVar386 + 0x0)) = uVar320 << 0x18;
  (*(undefined4 *)((uint8_t *)&auVar386 + 0x4)) = (*(undefined4 *)((uint8_t *)&auVar41 + 0x4)) << 0x18;
  (*(undefined4 *)((uint8_t *)&auVar386 + 0x8)) = (*(undefined4 *)((uint8_t *)&auVar40 + 0x8)) << 0x18;
  (*(undefined4 *)((uint8_t *)&auVar386 + 0x12)) = (uint)(uint3)((*(arr_undefined1_3 *)((uint8_t *)&auVar39 + 0x10)) >> 0x10) << 0x18;
  { auto &&__rea_tmp = (auVar359 | auVar385 | auVar388 | auVar386); memcpy(local_158, &__rea_tmp, sizeof(local_158)); }
  puVar208 = (uint *)local_158;
  do {
    (*(undefined4 *)((uint8_t *)&local_148 + 0x4)) = (*(undefined4 *)((uint8_t *)&local_148 + 0x4)) ^ local_178[0];
    local_178[0] = puVar208[-5];
    (*(undefined4 *)((uint8_t *)&local_148 + 0x8)) = (*(undefined4 *)((uint8_t *)&local_148 + 0x8)) ^ local_178[1];
    local_178[1] = puVar208[-4];
    iVar211 = iVar211 + 3;
    uVar212 = (*(undefined4 *)((uint8_t *)&local_148 + 0x8)) ^ local_178[0] ^ puVar208[1];
    uVar213 = (*(undefined4 *)((uint8_t *)&local_148 + 0x4)) ^ *puVar208 ^ puVar208[-6];
    uVar209 = puVar208[2] ^ local_178[1] ^ (*(undefined4 *)((uint8_t *)&local_148 + 0x12)) ^ puVar208[-6];
    (*(undefined4 *)((uint8_t *)&local_148 + 0x4)) = uVar213 >> 0x1f | uVar213 << 1;
    (*(undefined4 *)((uint8_t *)&local_148 + 0x8)) = uVar212 >> 0x1f | uVar212 << 1;
    (*(undefined4 *)((uint8_t *)&local_148 + 0x12)) = uVar209 >> 0x1f | uVar209 << 1;
    puVar208[8] = (*(undefined4 *)((uint8_t *)&local_148 + 0x4));
    puVar208[9] = (*(undefined4 *)((uint8_t *)&local_148 + 0x8));
    puVar208[10] = (*(undefined4 *)((uint8_t *)&local_148 + 0x12));
    puVar208 = puVar208 + 3;
  } while (iVar211 != 0x4f);
  iVar211 = 0x4f;
  do {
    iVar1 = iVar211 + -8;
    iVar2 = iVar211 + -3;
    lVar210 = (long)iVar211;
    iVar3 = iVar211 + -0xe;
    iVar4 = iVar211 + -0x10;
    iVar211 = iVar211 + 1;
    uVar209 = local_178[iVar1] ^ local_178[iVar2] ^ local_178[iVar3] ^ local_178[iVar4];
    local_178[lVar210] = uVar209 >> 0x1f | uVar209 << 1;
  } while (iVar211 != 0x50);
  uVar209 = param_1[4];
  uVar212 = param_1[3];
  uVar213 = *param_1;
  uVar206 = param_1[1];
  uVar207 = param_1[2];
  do {
    uVar367 = uVar207;
    uVar320 = uVar213;
    uVar269 = uVar212;
    uVar212 = *puVar216;
    puVar216 = puVar216 + 1;
    uVar207 = uVar206 >> 2 | uVar206 << 0x1e;
    uVar213 = (uVar320 >> 0x1b | uVar320 << 5) + uVar212 + 0x5a827999 +
              (~uVar206 & uVar269 | uVar367 & uVar206) + uVar209;
    uVar209 = uVar269;
    uVar212 = uVar367;
    uVar206 = uVar320;
  } while (puVar216 != local_128);
  puVar216 = local_128;
  do {
    uVar206 = uVar213;
    uVar212 = uVar207;
    uVar209 = uVar367;
    puVar208 = puVar216 + 1;
    uVar207 = uVar320 >> 2 | uVar320 << 0x1e;
    uVar213 = (uVar206 >> 0x1b | uVar206 << 5) + 0x6ed9eba1 + (uVar212 ^ uVar320 ^ uVar209) +
              *puVar216 + uVar269;
    puVar216 = puVar208;
    uVar269 = uVar209;
    uVar320 = uVar206;
    uVar367 = uVar212;
  } while (puVar208 != local_d8);
  puVar216 = local_d8;
  do {
    uVar367 = uVar207;
    uVar320 = uVar213;
    uVar269 = uVar212;
    uVar212 = *puVar216;
    puVar216 = puVar216 + 1;
    uVar207 = uVar206 >> 2 | uVar206 << 0x1e;
    uVar213 = (uVar320 >> 0x1b | uVar320 << 5) + uVar212 + -0x70e44324 +
              ((uVar269 | uVar367) & uVar206 | uVar269 & uVar367) + uVar209;
    uVar209 = uVar269;
    uVar212 = uVar367;
    uVar206 = uVar320;
  } while (puVar216 != (uint *)local_88);
  piVar214 = local_88;
  do {
    uVar212 = uVar207;
    uVar209 = uVar367;
    uVar206 = uVar213;
    piVar215 = piVar214 + 1;
    uVar207 = uVar320 >> 2 | uVar320 << 0x1e;
    uVar213 = (uVar206 >> 0x1b | uVar206 << 5) + 0xca62c1d6 + (uVar212 ^ uVar320 ^ uVar209) +
              *piVar214 + uVar269;
    piVar214 = piVar215;
    uVar269 = uVar209;
    uVar320 = uVar206;
    uVar367 = uVar212;
  } while (piVar215 != aiStack_38);
  param_1[0x17] = 0;
  param_1[1] = uVar206 + param_1[1];
  param_1[2] = uVar207 + param_1[2];
  *param_1 = uVar213 + *param_1;
  param_1[3] = uVar212 + param_1[3];
  param_1[4] = uVar209 + param_1[4];
  return;
}





// ------------------------------------------------------------------
// IDX 197  0010dae0  FUN_0010dae0
// ------------------------------------------------------------------
void rea_FUN_0010dae0(long param_1)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    (**(code **)(param_1 + 0x20))(param_1 + 0x10,param_1 + 0x10,3);
  }
  lVar2 = *(long *)(param_1 + 8);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar3 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 198  0010db50  FUN_0010db50
// ------------------------------------------------------------------
void rea_FUN_0010db50(long * param_1)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  
  if ((code *)param_1[3] != (code *)0x0) {
    (*(code *)param_1[3])(param_1 + 1,param_1 + 1,3);
  }
  lVar2 = *param_1;
  if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar3 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 199  0010dbc0  FUN_0010dbc0
// ------------------------------------------------------------------
void rea_FUN_0010dbc0(long * param_1, int param_2)
{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  long lVar6;
  size_t __n;
  undefined8 *puVar7;
  
  param_1 = (long *)*param_1;
  lVar6 = *param_1;
  puVar7 = *(undefined8 **)(lVar6 + 0x40);
  pvVar5 = (void *)*puVar7;
  pvVar4 = rea_memmem(pvVar5,puVar7[1] - (long)pvVar5,"permessage-deflate",0x12);
  if (pvVar4 == (void *)0x0) goto LAB_0010dc9e;
  *(undefined1 *)(lVar6 + 0x58) = 1;
  pvVar5 = rea_operator_new(0x70);
  lVar1 = *param_1;
  *(void **)(lVar6 + 0x60) = pvVar5;
  pvVar5 = rea_operator_new(0x70);
  *(void **)(lVar1 + 0x68) = pvVar5;
  puVar7 = *(undefined8 **)(*param_1 + 0x60);
  puVar2 = *(undefined8 **)(*param_1 + 0x68);
  puVar7[8] = 0;
  puVar7[9] = 0;
  puVar7[10] = 0;
  *(undefined4 *)(puVar7 + 1) = 0;
  *puVar7 = 0;
  iVar3 = inflateInit2_(puVar7,0xfffffff1,"1.2.7",0x70);
  if (iVar3 == 0) {
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
    *puVar2 = 0;
    iVar3 = deflateInit2_(puVar2,0xffffffff,8,0xfffffff1,8,0,"1.2.7",0x70);
    if (iVar3 != 0) {
      rea_inflateEnd(puVar7);
      goto LAB_0010dc77;
    }
  }
  else {
LAB_0010dc77:
    lVar6 = *param_1;
    *(undefined1 *)(lVar6 + 0x58) = 0;
    rea_operator_delete(*(void **)(lVar6 + 0x60));
    rea_operator_delete(*(void **)(*param_1 + 0x68));
  }
  puVar7 = *(undefined8 **)(*param_1 + 0x40);
  pvVar5 = (void *)*puVar7;
LAB_0010dc9e:
  pvVar4 = (void *)((long)(param_2 + 4) + (long)pvVar5);
  if (pvVar4 != pvVar5) {
    lVar6 = 0;
    if ((pvVar4 != (void *)puVar7[1]) && (__n = (long)puVar7[1] - (long)pvVar4, __n != 0)) {
      pvVar5 = rea_memmove(pvVar5,pvVar4,__n);
      lVar6 = puVar7[1] - (long)pvVar4;
    }
    puVar7[1] = (long)pvVar5 + lVar6;
  }
  if (param_1[3] == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
                    /* WARNING: Could not recover jumptable at 0x0010dce9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[4])(param_1 + 1);
  return;
}





// ------------------------------------------------------------------
// IDX 200  0010dda0  FUN_0010dda0
// ------------------------------------------------------------------
void rea_FUN_0010dda0(undefined8 * param_1)
{
  int *piVar1;
  string *psVar2;
  undefined *puVar3;
  int iVar4;
  undefined *local_38 [2];
  long local_28 [2];
  
  psVar2 = (string *)*param_1;
  rea_std__string__string((string *)local_38,psVar2);
  puVar3 = PTR__S_empty_rep_storage_00324fa0;
  if (*(long *)(psVar2 + 0x18) != 0) {
    local_28[0] = (long)local_38[0];
    local_38[0] = PTR__S_empty_rep_storage_00324fa0 + 0x18;
    (**(code **)(psVar2 + 0x20))(psVar2 + 8,local_28);
    if ((allocator *)(local_28[0] + -0x18) != (allocator *)puVar3) {
      piVar1 = (int *)(local_28[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar4 = *(int *)(local_28[0] + -8);
        *(int *)(local_28[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_28[0] + -0x18));
      }
    }
    if ((allocator *)(local_38[0] + -0x18) != (allocator *)puVar3) {
      piVar1 = (int *)(local_38[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar4 = *(int *)(local_38[0] + -8);
        *(int *)(local_38[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_38[0] + -0x18));
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 201  0010deb0  FUN_0010deb0
// ------------------------------------------------------------------
undefined8 rea_FUN_0010deb0(long * param_1, long * param_2, int param_3)
{
  int *piVar1;
  void *pvVar2;
  long lVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined8 *puVar6;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324900;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar4 = (undefined8 *)*param_2;
      puVar6 = rea_operator_new(0x30);
      *puVar6 = *puVar4;
      rea_std__string__string((string *)(puVar6 + 1),(string *)(puVar4 + 1));
      puVar6[4] = 0;
      if ((code *)puVar4[4] != (code *)0x0) {
        (*(code *)puVar4[4])(puVar6 + 2,puVar4 + 2,2);
        puVar6[5] = puVar4[5];
        puVar6[4] = puVar4[4];
      }
      *param_1 = (long)puVar6;
      return 0;
    }
    if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
      if (*(code **)((long)pvVar2 + 0x20) != (code *)0x0) {
        (**(code **)((long)pvVar2 + 0x20))((long)pvVar2 + 0x10,(long)pvVar2 + 0x10,3);
      }
      lVar3 = *(long *)((long)pvVar2 + 8);
      if ((allocator *)(lVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(lVar3 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar5 = *(int *)(lVar3 + -8);
          *(int *)(lVar3 + -8) = iVar5 + -1;
        }
        else {
          LOCK();
          iVar5 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar5 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar3 + -0x18));
        }
      }
      rea_operator_delete(pvVar2);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 202  0010e040  FUN_0010e040
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e040(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  int *piVar1;
  long *plVar2;
  long lVar3;
  string *psVar4;
  int iVar5;
  string *this_ptr;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (void *)&PTR_vtable_003248f0;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      psVar4 = (string *)*param_2;
      this_ptr = rea_operator_new(0x28);
      rea_std__string__string(this_ptr,psVar4);
      *(undefined8 *)(this_ptr + 0x18) = 0;
      if (*(code **)(psVar4 + 0x18) != (code *)0x0) {
        (**(code **)(psVar4 + 0x18))(this_ptr + 8,psVar4 + 8,2);
        *(undefined8 *)(this_ptr + 0x20) = *(undefined8 *)(psVar4 + 0x20);
        *(undefined8 *)(this_ptr + 0x18) = *(undefined8 *)(psVar4 + 0x18);
      }
      *param_1 = this_ptr;
      return 0;
    }
    if ((param_3 == 3) && (plVar2 = (long *)*param_1, plVar2 != (long *)0x0)) {
      if ((code *)plVar2[3] != (code *)0x0) {
        (*(code *)plVar2[3])(plVar2 + 1,plVar2 + 1,3);
      }
      lVar3 = *plVar2;
      if ((allocator *)(lVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(lVar3 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar5 = *(int *)(lVar3 + -8);
          *(int *)(lVar3 + -8) = iVar5 + -1;
        }
        else {
          LOCK();
          iVar5 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar5 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar3 + -0x18));
        }
      }
      rea_operator_delete(plVar2);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 203  0010e1d0  FUN_0010e1d0
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e1d0(long * param_1, long * param_2, int param_3)
{
  void *pvVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_003248e0;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar2 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x28);
    uVar3 = *puVar2;
    puVar4[3] = 0;
    *puVar4 = uVar3;
    if ((code *)puVar2[3] != (code *)0x0) {
      (*(code *)puVar2[3])(puVar4 + 1,puVar2 + 1,2);
      puVar4[4] = puVar2[4];
      puVar4[3] = puVar2[3];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar1 = (void *)*param_1, pvVar1 != (void *)0x0)) {
    if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
      (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
    }
    rea_operator_delete(pvVar1);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 204  0010e300  FUN_0010e300
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e300(long * param_1, long * param_2, int param_3)
{
  void *pvVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324920;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar2 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x28);
    uVar3 = *puVar2;
    puVar4[3] = 0;
    *puVar4 = uVar3;
    if ((code *)puVar2[3] != (code *)0x0) {
      (*(code *)puVar2[3])(puVar4 + 1,puVar2 + 1,2);
      puVar4[4] = puVar2[4];
      puVar4[3] = puVar2[3];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar1 = (void *)*param_1, pvVar1 != (void *)0x0)) {
    if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
      (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
    }
    rea_operator_delete(pvVar1);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 205  0010e430  FUN_0010e430
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e430(long * param_1, long * param_2, int param_3)
{
  void *pvVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324910;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar2 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x30);
    *puVar4 = *puVar2;
    uVar3 = puVar2[1];
    puVar4[4] = 0;
    puVar4[1] = uVar3;
    if ((code *)puVar2[4] != (code *)0x0) {
      (*(code *)puVar2[4])(puVar4 + 2,puVar2 + 2,2);
      puVar4[5] = puVar2[5];
      puVar4[4] = puVar2[4];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar1 = (void *)*param_1, pvVar1 != (void *)0x0)) {
    if (*(code **)((long)pvVar1 + 0x20) != (code *)0x0) {
      (**(code **)((long)pvVar1 + 0x20))((long)pvVar1 + 0x10,(long)pvVar1 + 0x10,3);
    }
    rea_operator_delete(pvVar1);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 206  0010e560  FUN_0010e560
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e560(long * param_1, long * param_2, int param_3)
{
  void *pvVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324930;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar2 = (undefined8 *)*param_2;
      puVar4 = rea_operator_new(0x48);
      uVar3 = *puVar2;
      puVar4[3] = 0;
      *puVar4 = uVar3;
      if ((code *)puVar2[3] != (code *)0x0) {
        (*(code *)puVar2[3])(puVar4 + 1,puVar2 + 1,2);
        puVar4[4] = puVar2[4];
        puVar4[3] = puVar2[3];
      }
      puVar4[7] = 0;
      if ((code *)puVar2[7] != (code *)0x0) {
        (*(code *)puVar2[7])(puVar4 + 5,puVar2 + 5,2);
        puVar4[8] = puVar2[8];
        puVar4[7] = puVar2[7];
      }
      *param_1 = (long)puVar4;
      return 0;
    }
    if ((param_3 == 3) && (pvVar1 = (void *)*param_1, pvVar1 != (void *)0x0)) {
      if (*(code **)((long)pvVar1 + 0x38) != (code *)0x0) {
        (**(code **)((long)pvVar1 + 0x38))((long)pvVar1 + 0x28,(long)pvVar1 + 0x28,3);
      }
      if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
        (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
      }
      rea_operator_delete(pvVar1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 207  0010e700  FUN_0010e700
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e700(long * param_1, long * param_2, int param_3)
{
  void *pvVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324940;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar2 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x28);
    uVar3 = *puVar2;
    puVar4[3] = 0;
    *puVar4 = uVar3;
    if ((code *)puVar2[3] != (code *)0x0) {
      (*(code *)puVar2[3])(puVar4 + 1,puVar2 + 1,2);
      puVar4[4] = puVar2[4];
      puVar4[3] = puVar2[3];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar1 = (void *)*param_1, pvVar1 != (void *)0x0)) {
    if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
      (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
    }
    rea_operator_delete(pvVar1);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 208  0010e830  FUN_0010e830
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e830(long * param_1, long * param_2, int param_3)
{
  undefined1 uVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324950;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar3 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x38);
    *puVar4 = *puVar3;
    *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(puVar3 + 1);
    *(undefined4 *)((long)puVar4 + 0xc) = *(undefined4 *)((long)puVar3 + 0xc);
    uVar1 = *(undefined1 *)(puVar3 + 2);
    puVar4[5] = 0;
    *(undefined1 *)(puVar4 + 2) = uVar1;
    if ((code *)puVar3[5] != (code *)0x0) {
      (*(code *)puVar3[5])(puVar4 + 3,puVar3 + 3,2);
      puVar4[6] = puVar3[6];
      puVar4[5] = puVar3[5];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
    if (*(code **)((long)pvVar2 + 0x28) != (code *)0x0) {
      (**(code **)((long)pvVar2 + 0x28))((long)pvVar2 + 0x18,(long)pvVar2 + 0x18,3);
    }
    rea_operator_delete(pvVar2);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 209  0010e980  FUN_0010e980
// ------------------------------------------------------------------
undefined8 rea_FUN_0010e980(long * param_1, long * param_2, int param_3)
{
  undefined4 uVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324970;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar3 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x38);
    *puVar4 = *puVar3;
    puVar4[1] = puVar3[1];
    *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(puVar3 + 2);
    uVar1 = *(undefined4 *)((long)puVar3 + 0x14);
    puVar4[5] = 0;
    *(undefined4 *)((long)puVar4 + 0x14) = uVar1;
    if ((code *)puVar3[5] != (code *)0x0) {
      (*(code *)puVar3[5])(puVar4 + 3,puVar3 + 3,2);
      puVar4[6] = puVar3[6];
      puVar4[5] = puVar3[5];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
    if (*(code **)((long)pvVar2 + 0x28) != (code *)0x0) {
      (**(code **)((long)pvVar2 + 0x28))((long)pvVar2 + 0x18,(long)pvVar2 + 0x18,3);
    }
    rea_operator_delete(pvVar2);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 210  0010ead0  FUN_0010ead0
// ------------------------------------------------------------------
undefined8 rea_FUN_0010ead0(long * param_1, long * param_2, int param_3)
{
  undefined1 uVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324960;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar3 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x38);
    *puVar4 = *puVar3;
    *(undefined1 *)(puVar4 + 1) = *(undefined1 *)(puVar3 + 1);
    *(undefined4 *)((long)puVar4 + 0xc) = *(undefined4 *)((long)puVar3 + 0xc);
    uVar1 = *(undefined1 *)(puVar3 + 2);
    puVar4[5] = 0;
    *(undefined1 *)(puVar4 + 2) = uVar1;
    if ((code *)puVar3[5] != (code *)0x0) {
      (*(code *)puVar3[5])(puVar4 + 3,puVar3 + 3,2);
      puVar4[6] = puVar3[6];
      puVar4[5] = puVar3[5];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
    if (*(code **)((long)pvVar2 + 0x28) != (code *)0x0) {
      (**(code **)((long)pvVar2 + 0x28))((long)pvVar2 + 0x18,(long)pvVar2 + 0x18,3);
    }
    rea_operator_delete(pvVar2);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 211  0010ec20  FUN_0010ec20
// ------------------------------------------------------------------
undefined8 rea_FUN_0010ec20(long * param_1, long * param_2, int param_3)
{
  undefined4 uVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)(void *)&PTR_vtable_00324980;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar3 = (undefined8 *)*param_2;
    puVar4 = rea_operator_new(0x38);
    *puVar4 = *puVar3;
    puVar4[1] = puVar3[1];
    *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(puVar3 + 2);
    uVar1 = *(undefined4 *)((long)puVar3 + 0x14);
    puVar4[5] = 0;
    *(undefined4 *)((long)puVar4 + 0x14) = uVar1;
    if ((code *)puVar3[5] != (code *)0x0) {
      (*(code *)puVar3[5])(puVar4 + 3,puVar3 + 3,2);
      puVar4[6] = puVar3[6];
      puVar4[5] = puVar3[5];
    }
    *param_1 = (long)puVar4;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
    if (*(code **)((long)pvVar2 + 0x28) != (code *)0x0) {
      (**(code **)((long)pvVar2 + 0x28))((long)pvVar2 + 0x18,(long)pvVar2 + 0x18,3);
    }
    rea_operator_delete(pvVar2);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 212  0010ed70  WSConn__dtor_WSConn
// ------------------------------------------------------------------
void rea_WSConn__dtor_WSConn__dup2(WSConn * this_ptr)
{
  undefined8 *puVar1;
  
  *(undefined **)this_ptr = PTR_vtable_00324f30 + 0x10;
  if (this_ptr[0x58] != (WSConn)0x0) {
    rea_inflateEnd(*(undefined8 *)(this_ptr + 0x60));
    rea_deflateEnd(*(undefined8 *)(this_ptr + 0x68));
    rea_operator_delete(*(void **)(this_ptr + 0x60));
    rea_operator_delete(*(void **)(this_ptr + 0x68));
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x50);
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x48);
  *(undefined8 *)(this_ptr + 0x50) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x40);
  *(undefined8 *)(this_ptr + 0x48) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  *(undefined8 *)(this_ptr + 0x40) = 0;
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 213  0010ee60  WSConn__dtor_WSConn
// ------------------------------------------------------------------
void rea_WSConn__dtor_WSConn__dup3(WSConn * this_ptr)
{
  dtor_WSConn(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 214  0010ee80  FUN_0010ee80
// ------------------------------------------------------------------
undefined8 rea_FUN_0010ee80(long * param_1, char param_2, undefined8 * param_3)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  long *plVar4;
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
    plVar4 = rea_operator_new(0x18);
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
        param_3[3] = local_4038;
        iVar3 = rea_inflate(param_3,0);
        if ((iVar3 + 4U < 7) && ((1L << ((byte)(iVar3 + 4U) & 0x3f) & 0x47U) != 0)) {
          if ((void *)*plVar4 != (void *)0x0) {
            rea_operator_delete((void *)*plVar4);
          }
          rea_operator_delete(plVar4);
          return 0;
        }
        iVar3 = *(int *)(param_3 + 4);
        __dest_01 = (void *)plVar4[1];
        puVar9 = local_4038 + (0x4000 - iVar3);
        if (puVar9 != local_4038) break;
LAB_0010ef54:
        if (iVar3 != 0) goto LAB_0010f057;
      }
      __n = (long)puVar9 - (long)local_4038;
      if (__n <= (ulong)(plVar4[2] - (long)__dest_01)) {
        if (__n != 0) {
          rea_memmove(__dest_01,local_4038,__n);
          __dest_01 = (void *)plVar4[1];
          iVar3 = *(int *)(param_3 + 4);
        }
        plVar4[1] = (long)__dest_01 + __n;
        goto LAB_0010ef54;
      }
      __src = (void *)*plVar4;
      sVar8 = (long)__dest_01 - (long)__src;
      if (~sVar8 < __n) {
        uVar7 = rea_std____throw_length_error("vector___M_range_insert");
        rea_FUN_00107772(plVar4);
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
        sVar8 = (long)__dest_01 - (long)__src;
        __dest_00 = __dest;
        if (sVar8 == 0) goto LAB_0010f00c;
LAB_0010f0d1:
        rea_memmove(__dest,__src,sVar8);
        __dest_00 = (void *)(sVar8 + (long)__dest);
        if (__n != 0) goto LAB_0010f0f2;
LAB_0010f018:
        sVar8 = plVar4[1] - (long)__dest_01;
      }
      else {
        __dest = (void *)0x0;
        local_4050 = 0;
        __dest_00 = __dest;
        if (sVar8 != 0) goto LAB_0010f0d1;
LAB_0010f00c:
        __dest = __dest_00;
        if (__n == 0) goto LAB_0010f018;
LAB_0010f0f2:
        __dest_00 = rea_memmove(__dest_00,local_4038,__n);
        sVar8 = plVar4[1] - (long)__dest_01;
      }
      sVar6 = 0;
      if (sVar8 != 0) {
        rea_memmove((void *)(__n + (long)__dest_00),__dest_01,sVar8);
        sVar6 = sVar8;
      }
      if ((void *)*plVar4 != (void *)0x0) {
        rea_operator_delete((void *)*plVar4);
      }
      *plVar4 = (long)__dest;
      iVar3 = *(int *)(param_3 + 4);
      plVar4[1] = (long)(__n + (long)__dest_00) + sVar6;
      plVar4[2] = (long)__dest + local_4050;
    } while (iVar3 == 0);
LAB_0010f057:
    puVar2 = (undefined8 *)*param_1;
    *param_1 = (long)plVar4;
    if (puVar2 != (undefined8 *)0x0) {
      if ((void *)*puVar2 != (void *)0x0) {
        rea_operator_delete((void *)*puVar2);
      }
      rea_operator_delete(puVar2);
    }
  }
  return 1;
}





// ------------------------------------------------------------------
// IDX 215  0010f180  WSConn__recv_pat
// ------------------------------------------------------------------
void rea_WSConn__recv_pat__dup2(WSConn * this_ptr, string * param_2, long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  int *piVar2;
  char cVar3;
  void *__haystack;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  void *pvVar12;
  undefined8 *puVar13;
  _Rb_tree_node_base *p_Var14;
  long lVar15;
  _Rb_tree_node_base *p_Var16;
  long lVar17;
  _Rb_tree_node_base *p_Var18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  uint uVar22;
  uint uVar23;
  undefined1 auVar24 [16];
  int local_c8 [4];
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  WSConn *local_98;
  long local_90;
  undefined1 local_88 [16];
  code *local_78;
  undefined8 uStack_70;
  WSConn *local_68;
  undefined *local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 uStack_40;
  
  __haystack = (void *)**(undefined8 **)(this_ptr + 0x40);
  pvVar12 = rea_memmem(__haystack,(*(undefined8 **)(this_ptr + 0x40))[1] - (long)__haystack,
                   *(void **)param_2,*(size_t *)((long)*(void **)param_2 + -0x18));
  if (pvVar12 != (void *)0x0) {
    if (*(long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3,(long)pvVar12 - (long)__haystack);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  local_98 = this_ptr;
  rea_std__string__string((string *)&local_90,param_2);
  local_78 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(local_88,param_3,2);
    local_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
  }
  lVar17 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar17 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar17 + 0x88) = 1;
  local_68 = local_98;
  rea_std__string__string((string *)&local_60,(string *)&local_90);
  local_48 = (code *)0x0;
  if (local_78 != (code *)0x0) {
    (*local_78)(&local_58,local_88,2);
    local_48 = local_78;
    uStack_40 = uStack_70;
  }
  local_a8 = (code *)0x0;
  puVar13 = rea_operator_new(0x30);
  pcVar9 = local_48;
  puVar8 = PTR__S_empty_rep_storage_00324fa0;
  *puVar13 = local_68;
  puVar13[1] = local_60;
  local_60 = puVar8 + 0x18;
  puVar13[4] = 0;
  uVar4 = puVar13[2];
  uVar5 = puVar13[3];
  puVar13[2] = local_58;
  puVar13[3] = local_50;
  local_48 = (code *)0x0;
  uVar6 = puVar13[5];
  puVar13[4] = pcVar9;
  puVar13[5] = uStack_40;
  local_b8 = *(undefined8 *)(lVar17 + 0x90);
  uVar7 = *(undefined8 *)(lVar17 + 0x98);
  local_a8 = *(code **)(lVar17 + 0xa0);
  *(undefined8 *)(lVar17 + 0x98) = local_b0;
  *(undefined8 **)(lVar17 + 0x90) = puVar13;
  *(code **)(lVar17 + 0xa0) = FUN_0010deb0;
  local_a0 = *(undefined8 *)(lVar17 + 0xa8);
  *(code **)(lVar17 + 0xa8) = FUN_00111f80;
  local_b0 = uVar7;
  local_58 = uVar4;
  local_50 = uVar5;
  uStack_40 = uVar6;
  if (local_a8 != (code *)0x0) {
    (*local_a8)(&local_b8,&local_b8,3);
  }
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if ((allocator *)(local_60 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(local_60 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar11 = *(int *)(local_60 + -8);
      *(int *)(local_60 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_60 + -0x18));
    }
  }
  cVar3 = *(char *)(lVar17 + 0x88);
  local_c8[0] = *(int *)(lVar17 + 0x40);
  lVar17 = *(long *)(lVar17 + 0x38);
  p_Var14 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var19 = p_Var14;
  p_Var18 = p_Var16;
  if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0010f530:
    lVar15 = 0;
    uVar23 = 0;
  }
  else {
    do {
      while (p_Var20 = p_Var19, *(int *)(p_Var20 + 0x20) < local_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var19 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var18;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0010f43a;
      }
      p_Var19 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var18 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f43a:
    if ((p_Var16 == p_Var20) || (p_Var19 = p_Var16, local_c8[0] < *(int *)(p_Var20 + 0x20)))
    goto LAB_0010f530;
    do {
      while (p_Var18 = p_Var14, *(int *)(p_Var18 + 0x20) < local_c8[0]) {
        p_Var20 = p_Var18 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var20;
        p_Var18 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f46a;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
      p_Var19 = p_Var18;
    } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f46a:
    if ((p_Var16 == p_Var18) || (local_c8[0] < *(int *)(p_Var18 + 0x20))) {
      p_Var14 = rea_operator_new(0x28);
      if (p_Var14 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var14 = 0;
        *(undefined8 *)(p_Var14 + 8) = 0;
        *(undefined8 *)(p_Var14 + 0x10) = 0;
        *(undefined8 *)(p_Var14 + 0x18) = 0;
        *(undefined4 *)(p_Var14 + 0x24) = 0;
        *(int *)(p_Var14 + 0x20) = local_c8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar17 + 8),p_Var18,p_Var14 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
      p_Var19 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x8));
      p_Var18 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x0));
      if (p_Var19 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var14);
      }
      else {
        bVar21 = true;
        if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var19)) {
          bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var19,p_Var16);
        *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
        p_Var18 = p_Var14;
      }
    }
    uVar23 = *(uint *)(p_Var18 + 0x24);
    lVar15 = 1;
  }
  lVar17 = lVar17 + (lVar15 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar17 + 8);
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var18 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var14 = p_Var16;
  p_Var19 = p_Var18;
  uVar10 = uVar23;
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var20 = p_Var14, *(int *)(p_Var20 + 0x20) < local_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0010f582;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f582:
    if ((p_Var18 != p_Var20) && (p_Var14 = p_Var18, *(int *)(p_Var20 + 0x20) <= local_c8[0])) {
      do {
        while (p_Var19 = p_Var16, *(int *)(p_Var19 + 0x20) < local_c8[0]) {
          p_Var20 = p_Var19 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var20;
          p_Var19 = p_Var14;
          if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f5ba;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var14 = p_Var19;
      } while (*(_Rb_tree_node_base **)(p_Var19 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f5ba:
      if ((p_Var18 == p_Var19) || (local_c8[0] < *(int *)(p_Var19 + 0x20))) {
        p_Var16 = rea_operator_new(0x28);
        if (p_Var16 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var16 = 0;
          *(undefined8 *)(p_Var16 + 8) = 0;
          *(undefined8 *)(p_Var16 + 0x10) = 0;
          *(undefined8 *)(p_Var16 + 0x18) = 0;
          *(undefined4 *)(p_Var16 + 0x24) = 0;
          *(int *)(p_Var16 + 0x20) = local_c8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var19,p_Var16 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
        p_Var14 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x8));
        p_Var19 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x0));
        if (p_Var14 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var16);
        }
        else {
          bVar21 = true;
          if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var18 != p_Var14)) {
            bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var14 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var14,p_Var18);
          *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
          p_Var19 = p_Var16;
        }
      }
      uVar10 = *(uint *)(p_Var19 + 0x24);
    }
  }
  uVar22 = uVar10 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar10 & 0xfffffffe;
  }
  if (uVar23 == uVar22) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_c8);
    goto LAB_0010f72d;
  }
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var19 = p_Var18;
  p_Var14 = p_Var18;
  if (*(_Rb_tree_node_base **)(lVar17 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010f6ad:
    p_Var16 = rea_operator_new(0x28);
    if (p_Var16 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var16 = 0;
      *(undefined8 *)(p_Var16 + 8) = 0;
      *(undefined8 *)(p_Var16 + 0x10) = 0;
      *(undefined8 *)(p_Var16 + 0x18) = 0;
      *(undefined4 *)(p_Var16 + 0x24) = 0;
      *(int *)(p_Var16 + 0x20) = local_c8[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var14,p_Var16 + 0x20)); memcpy(auVar24, &__rea_tmp, sizeof(auVar24)); }
    p_Var19 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x8));
    p_Var14 = (*(undefined8 *)((uint8_t *)&auVar24 + 0x0));
    if (p_Var19 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var16);
    }
    else {
      bVar21 = true;
      if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var18 != p_Var19)) {
        bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var19 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var19,p_Var18);
      *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
      p_Var14 = p_Var16;
    }
  }
  else {
    do {
      while (p_Var14 = p_Var16, *(int *)(p_Var14 + 0x20) < local_c8[0]) {
        p_Var20 = p_Var14 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var20;
        p_Var14 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f6a2;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var19 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f6a2:
    if ((p_Var18 == p_Var14) || (local_c8[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0010f6ad;
  }
  *(uint *)(p_Var14 + 0x24) = uVar22;
LAB_0010f72d:
  if (local_78 != (code *)0x0) {
    (*local_78)(local_88,local_88,3);
  }
  if ((allocator *)(local_90 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(local_90 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar11 = *(int *)(local_90 + -8);
      *(int *)(local_90 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_90 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 216  0010f940  WSConn__accept
// ------------------------------------------------------------------
void rea_WSConn__accept(WSConn * this_ptr, long param_2, long param_3)
{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  code *pcVar9;
  int iVar10;
  allocator local_aa [2];
  long local_a8 [2];
  undefined8 *local_98 [2];
  code *local_88;
  code *local_80;
  WSConn *local_78;
  undefined8 local_70;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  code *local_40;
  undefined8 local_38;
  
  local_60 = (code *)0x0;
  local_78 = this_ptr;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(&local_70,param_2,2);
    local_58 = *(undefined8 *)(param_2 + 0x18);
    local_60 = *(code **)(param_2 + 0x10);
  }
  local_40 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(&local_50,param_3,2);
    local_38 = *(undefined8 *)(param_3 + 0x18);
    local_40 = *(code **)(param_3 + 0x10);
  }
  local_88 = (code *)0x0;
  local_98[0] = rea_operator_new(0x48);
  pcVar9 = local_40;
  pcVar8 = local_60;
  local_98[0][3] = 0;
  uVar2 = local_98[0][1];
  uVar3 = local_98[0][2];
  uVar4 = local_98[0][4];
  local_98[0][7] = 0;
  *local_98[0] = local_78;
  uVar5 = local_98[0][6];
  local_98[0][2] = local_68;
  uVar6 = local_98[0][5];
  local_98[0][1] = local_70;
  local_60 = (code *)0x0;
  local_98[0][3] = pcVar8;
  uVar7 = local_98[0][8];
  local_98[0][4] = local_58;
  local_98[0][6] = local_48;
  local_98[0][5] = local_50;
  local_40 = (code *)0x0;
  local_98[0][7] = pcVar9;
  local_98[0][8] = local_38;
  local_80 = FUN_00112b60;
  local_88 = FUN_0010e560;
  local_70 = uVar2;
  local_68 = uVar3;
  local_58 = uVar4;
  local_50 = uVar6;
  local_48 = uVar5;
  local_38 = uVar7;
  rea_std__string__string((string *)local_a8,"\r\n\r\n",local_aa);
  recv_pat(this_ptr,(string *)local_a8,local_98);
  if ((allocator *)(local_a8[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_a8[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar10 = *(int *)(local_a8[0] + -8);
      *(int *)(local_a8[0] + -8) = iVar10 + -1;
    }
    else {
      LOCK();
      iVar10 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar10 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_a8[0] + -0x18));
    }
  }
  if (local_88 != (code *)0x0) {
    (*local_88)(local_98,local_98,3);
  }
  if (local_40 != (code *)0x0) {
    (*local_40)(&local_50,&local_50,3);
  }
  if (local_60 != (code *)0x0) {
    (*local_60)(&local_70,&local_70,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 217  0010fb50  FUN_0010fb50
// ------------------------------------------------------------------
void rea_FUN_0010fb50(allocator * param_1, undefined8 param_2, int * param_3)
{
  undefined8 stack0x00000048;
  undefined8 stack0x00000068;
  int iVar1;
  code *in_stack_00000030;
  code *in_stack_00000058;
  code *in_stack_00000078;
  
  LOCK();
  iVar1 = *param_3;
  *param_3 = *param_3 + -1;
  UNLOCK();
  if (iVar1 < 1) {
    rea_std__string___Rep___M_destroy(param_1);
  }
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
  if (in_stack_00000078 != (code *)0x0) {
    (*in_stack_00000078)((void *)&stack0x00000068,(void *)&stack0x00000068,3);
  }
  if (in_stack_00000058 != (code *)0x0) {
    (*in_stack_00000058)((void *)&stack0x00000048,(void *)&stack0x00000048,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 218  0010fc40  FUN_0010fc40
// ------------------------------------------------------------------
void rea_FUN_0010fc40(long * param_1)
{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  allocator local_79;
  long local_78 [2];
  undefined8 *local_68 [2];
  code *local_58;
  code *local_50;
  undefined8 local_48;
  undefined1 local_40 [16];
  code *local_30;
  undefined8 local_28;
  
  puVar2 = (undefined8 *)*param_1;
  local_48 = *puVar2;
  local_30 = (code *)0x0;
  if ((code *)puVar2[3] != (code *)0x0) {
    (*(code *)puVar2[3])(local_40,puVar2 + 1,2);
    local_28 = puVar2[4];
    local_30 = (code *)puVar2[3];
  }
  local_58 = (code *)0x0;
  local_68[0] = rea_operator_new(0x28);
  local_68[0][3] = 0;
  *local_68[0] = local_48;
  if (local_30 != (code *)0x0) {
    (*local_30)(local_68[0] + 1,local_40,2);
    local_68[0][4] = local_28;
    local_68[0][3] = local_30;
  }
  local_50 = FUN_0010dbc0;
  local_58 = FUN_0010e300;
  rea_std__string__string((string *)local_78,"\r\n\r\n",&local_79);
  rea_WSConn__recv_pat((WSConn *)*puVar2,(string *)local_78,local_68);
  if ((allocator *)(local_78[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_78[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar3 = *(int *)(local_78[0] + -8);
      *(int *)(local_78[0] + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_78[0] + -0x18));
    }
  }
  if (local_58 != (code *)0x0) {
    (*local_58)(local_68,local_68,3);
  }
  if (local_30 != (code *)0x0) {
    (*local_30)(local_40,local_40,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 219  0010fe70  WSConn__recv_more
// ------------------------------------------------------------------
void rea_WSConn__recv_more__dup2(WSConn * this_ptr, ulong param_1, long param_3)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  long lVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  code *pcVar12;
  _Rb_tree_node_base *p_Var13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auVar20 [16];
  int local_c8 [4];
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  WSConn *local_98;
  ulong local_90;
  undefined1 local_88 [16];
  code *local_78;
  undefined8 uStack_70;
  WSConn *local_68;
  ulong local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 uStack_40;
  
  if (param_1 <= (ulong)((*(long **)(this_ptr + 0x40))[1] - **(long **)(this_ptr + 0x40))) {
    if (*(long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  local_78 = (code *)0x0;
  local_98 = this_ptr;
  local_90 = param_1;
  if (*(code **)(param_3 + 0x10) == (code *)0x0) {
    pcVar12 = (code *)0x0;
  }
  else {
    (**(code **)(param_3 + 0x10))(local_88,param_3,2);
    local_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
    pcVar12 = *(code **)(param_3 + 0x10);
  }
  lVar14 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar14 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
    pcVar12 = local_78;
  }
  *(undefined1 *)(lVar14 + 0x88) = 1;
  local_48 = (code *)0x0;
  local_68 = local_98;
  local_60 = local_90;
  if (pcVar12 != (code *)0x0) {
    (*pcVar12)(&local_58,local_88,2);
    local_48 = local_78;
    uStack_40 = uStack_70;
  }
  local_a8 = (code *)0x0;
  puVar8 = rea_operator_new(0x30);
  pcVar12 = local_48;
  puVar8[4] = 0;
  uVar3 = puVar8[2];
  uVar4 = puVar8[3];
  uVar5 = puVar8[5];
  *puVar8 = local_68;
  puVar8[1] = local_60;
  puVar8[3] = local_50;
  puVar8[2] = local_58;
  local_48 = (code *)0x0;
  puVar8[4] = pcVar12;
  puVar8[5] = uStack_40;
  local_b8 = *(undefined8 *)(lVar14 + 0x90);
  uVar6 = *(undefined8 *)(lVar14 + 0x98);
  *(undefined8 *)(lVar14 + 0x98) = local_b0;
  *(undefined8 **)(lVar14 + 0x90) = puVar8;
  local_a8 = *(code **)(lVar14 + 0xa0);
  local_a0 = *(undefined8 *)(lVar14 + 0xa8);
  *(code **)(lVar14 + 0xa0) = FUN_0010e430;
  *(code **)(lVar14 + 0xa8) = FUN_00111c50;
  local_b0 = uVar6;
  local_58 = uVar3;
  local_50 = uVar4;
  uStack_40 = uVar5;
  if (local_a8 != (code *)0x0) {
    (*local_a8)(&local_b8,&local_b8,3);
  }
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  local_c8[0] = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x88);
  lVar14 = *(long *)(lVar14 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var16 = p_Var10;
  p_Var15 = p_Var11;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
LAB_001103f0:
    lVar9 = 0;
    uVar18 = 0;
  }
  else {
    do {
      while (p_Var13 = p_Var16, *(int *)(p_Var13 + 0x20) < local_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001100b3;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var15 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001100b3:
    if ((p_Var11 == p_Var13) || (p_Var16 = p_Var11, local_c8[0] < *(int *)(p_Var13 + 0x20)))
    goto LAB_001103f0;
    do {
      while (p_Var15 = p_Var10, *(int *)(p_Var15 + 0x20) < local_c8[0]) {
        p_Var13 = p_Var15 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var13;
        p_Var15 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_001100eb;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var16 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001100eb:
    if ((p_Var11 == p_Var15) || (local_c8[0] < *(int *)(p_Var15 + 0x20))) {
      p_Var10 = rea_operator_new(0x28);
      if (p_Var10 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = local_c8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar14 + 8),p_Var15,p_Var10 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x8));
      p_Var15 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x0));
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var16)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var16,p_Var11);
        *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
        p_Var15 = p_Var10;
      }
    }
    uVar18 = *(uint *)(p_Var15 + 0x24);
    lVar9 = 1;
  }
  lVar14 = lVar14 + (lVar9 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar14 + 8);
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var15 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var10 = p_Var11;
  p_Var16 = p_Var15;
  uVar7 = uVar18;
  if (p_Var11 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var13 = p_Var10, *(int *)(p_Var13 + 0x20) < local_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011015a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011015a:
    if ((p_Var15 != p_Var13) && (p_Var10 = p_Var15, *(int *)(p_Var13 + 0x20) <= local_c8[0])) {
      do {
        while (p_Var16 = p_Var11, *(int *)(p_Var16 + 0x20) < local_c8[0]) {
          p_Var13 = p_Var16 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var13;
          p_Var16 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_0011018a;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var10 = p_Var16;
      } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011018a:
      if ((p_Var15 == p_Var16) || (local_c8[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var11 = rea_operator_new(0x28);
        if (p_Var11 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_c8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var16,p_Var11 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
        p_Var10 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x8));
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x0));
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var11);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var10)) {
            bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var10,p_Var15);
          *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
          p_Var16 = p_Var11;
        }
      }
      uVar7 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar19 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar19 = uVar7 & 0xfffffffe;
  }
  if (uVar18 == uVar19) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_c8);
    goto LAB_00110208;
  }
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var16 = p_Var15;
  p_Var10 = p_Var15;
  if (*(_Rb_tree_node_base **)(lVar14 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00110360:
    p_Var11 = rea_operator_new(0x28);
    if (p_Var11 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var11 = 0;
      *(undefined8 *)(p_Var11 + 8) = 0;
      *(undefined8 *)(p_Var11 + 0x10) = 0;
      *(undefined8 *)(p_Var11 + 0x18) = 0;
      *(undefined4 *)(p_Var11 + 0x24) = 0;
      *(int *)(p_Var11 + 0x20) = local_c8[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var11 + 0x20)); memcpy(auVar20, &__rea_tmp, sizeof(auVar20)); }
    p_Var16 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x8));
    p_Var10 = (*(undefined8 *)((uint8_t *)&auVar20 + 0x0));
    if (p_Var16 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var11);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var16)) {
        bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var16,p_Var15);
      *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
      p_Var10 = p_Var11;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var11, *(int *)(p_Var10 + 0x20) < local_c8[0]) {
        p_Var13 = p_Var10 + 0x18;
        p_Var11 = *(_Rb_tree_node_base **)p_Var13;
        p_Var10 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_001101f2;
      }
      p_Var11 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var16 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001101f2:
    if ((p_Var15 == p_Var10) || (local_c8[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00110360;
  }
  *(uint *)(p_Var10 + 0x24) = uVar19;
LAB_00110208:
  if (local_78 != (code *)0x0) {
    (*local_78)(local_88,local_88,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 220  001105a0  WSConn__read_data_mask
// ------------------------------------------------------------------
void rea_WSConn__read_data_mask__dup2(WSConn * this_ptr, undefined4 param_1, undefined1 param_2, long param_3, long param_5)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *local_88 [2];
  code *local_78;
  code *local_70;
  WSConn *local_68;
  long local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  code *local_40;
  undefined8 local_38;
  
  local_40 = (code *)0x0;
  local_68 = this_ptr;
  local_60 = param_3;
  local_58 = param_2;
  local_54 = param_1;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(&local_50,param_5,2);
    local_38 = *(undefined8 *)(param_5 + 0x18);
    local_40 = *(code **)(param_5 + 0x10);
  }
  local_78 = (code *)0x0;
  local_88[0] = rea_operator_new(0x38);
  pcVar4 = local_40;
  uVar1 = local_88[0][3];
  uVar2 = local_88[0][4];
  local_88[0][5] = 0;
  uVar3 = local_88[0][6];
  *local_88[0] = local_68;
  local_88[0][1] = local_60;
  *(undefined1 *)(local_88[0] + 2) = local_58;
  *(undefined4 *)((long)local_88[0] + 0x14) = local_54;
  local_88[0][3] = local_50;
  local_88[0][4] = uStack_48;
  local_40 = (code *)0x0;
  local_88[0][5] = pcVar4;
  local_88[0][6] = local_38;
  local_70 = FUN_00110d50;
  local_78 = FUN_0010ec20;
  local_50 = uVar1;
  uStack_48 = uVar2;
  local_38 = uVar3;
  recv_more(this_ptr,param_3 + 4,local_88);
  if (local_78 != (code *)0x0) {
    (*local_78)(local_88,local_88,3);
  }
  if (local_40 != (code *)0x0) {
    (*local_40)(&local_50,&local_50,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 221  00110760  WSConn__read_data
// ------------------------------------------------------------------
void rea_WSConn__read_data__dup2(WSConn * this_ptr, undefined4 param_1, undefined1 param_2, undefined8 param_3, long param_5)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *local_88 [2];
  code *local_78;
  code *local_70;
  WSConn *local_68;
  undefined8 local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  code *local_40;
  undefined8 local_38;
  
  local_40 = (code *)0x0;
  local_68 = this_ptr;
  local_60 = param_3;
  local_58 = param_2;
  local_54 = param_1;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(&local_50,param_5,2);
    local_38 = *(undefined8 *)(param_5 + 0x18);
    local_40 = *(code **)(param_5 + 0x10);
  }
  local_78 = (code *)0x0;
  local_88[0] = rea_operator_new(0x38);
  pcVar4 = local_40;
  uVar1 = local_88[0][3];
  uVar2 = local_88[0][4];
  local_88[0][5] = 0;
  uVar3 = local_88[0][6];
  *local_88[0] = local_68;
  local_88[0][1] = local_60;
  *(undefined1 *)(local_88[0] + 2) = local_58;
  *(undefined4 *)((long)local_88[0] + 0x14) = local_54;
  local_88[0][3] = local_50;
  local_88[0][4] = uStack_48;
  local_40 = (code *)0x0;
  local_88[0][5] = pcVar4;
  local_88[0][6] = local_38;
  local_70 = FUN_00111100;
  local_78 = FUN_0010e980;
  local_50 = uVar1;
  uStack_48 = uVar2;
  local_38 = uVar3;
  recv_more(this_ptr,param_3,local_88);
  if (local_78 != (code *)0x0) {
    (*local_78)(local_88,local_88,3);
  }
  if (local_40 != (code *)0x0) {
    (*local_40)(&local_50,&local_50,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 222  00110920  FUN_00110920
// ------------------------------------------------------------------
void rea_FUN_00110920(long * param_1)
{
  void *__src;
  undefined8 *puVar1;
  code *pcVar2;
  undefined2 uVar3;
  long lVar4;
  void *__dest;
  long lVar5;
  size_t __n;
  undefined1 auStack_48 [16];
  code *local_38;
  long lStack_30;
  
  param_1 = (long *)*param_1;
  puVar1 = *(undefined8 **)(*param_1 + 0x40);
  __dest = (void *)*puVar1;
  __src = (void *)((long)__dest + 4);
  uVar3 = CONCAT11(*(undefined1 *)((long)__dest + 2),*(undefined1 *)((long)__dest + 3));
  lVar5 = 0;
  if ((__src != (void *)puVar1[1]) && (__n = (long)puVar1[1] - (long)__src, __n != 0)) {
    __dest = rea_memmove(__dest,__src,__n);
    lVar5 = puVar1[1] - (long)__src;
  }
  lVar4 = param_1[1];
  puVar1[1] = (long)__dest + lVar5;
  local_38 = (code *)0x0;
  pcVar2 = (code *)param_1[5];
  if ((char)lVar4 == '\0') {
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(auStack_48,param_1 + 3,2);
      local_38 = (code *)param_1[5];
      lStack_30 = param_1[6];
    }
    rea_WSConn__read_data((WSConn *)*param_1,*(undefined4 *)((long)param_1 + 0xc),(char)param_1[2],uVar3
                      ,auStack_48);
    if (local_38 != (code *)0x0) {
      (*local_38)(auStack_48,auStack_48,3);
      return;
    }
  }
  else {
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(auStack_48,param_1 + 3,2);
      local_38 = (code *)param_1[5];
      lStack_30 = param_1[6];
    }
    WSConn__read_data_mask_______________((WSConn *)*param_1,*(undefined4 *)((long)param_1 + 0xc),(char)param_1[2],uVar3,
               auStack_48);
    if (local_38 != (code *)0x0) {
      (*local_38)(auStack_48,auStack_48,3);
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 223  00110ad0  WSConn__read_head
// ------------------------------------------------------------------
void rea_WSConn__read_head__dup2(WSConn * this_ptr, long param_2)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *local_68 [2];
  code *local_58;
  code *local_50;
  WSConn *local_48;
  undefined8 local_40;
  undefined8 local_38;
  code *local_30;
  undefined8 local_28;
  
  local_30 = (code *)0x0;
  local_48 = this_ptr;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(&local_40,param_2,2);
    local_28 = *(undefined8 *)(param_2 + 0x18);
    local_30 = *(code **)(param_2 + 0x10);
  }
  local_58 = (code *)0x0;
  local_68[0] = rea_operator_new(0x28);
  pcVar4 = local_30;
  local_68[0][3] = 0;
  uVar1 = local_68[0][1];
  uVar2 = local_68[0][2];
  uVar3 = local_68[0][4];
  *local_68[0] = local_48;
  local_68[0][2] = local_38;
  local_68[0][1] = local_40;
  local_30 = (code *)0x0;
  local_68[0][3] = pcVar4;
  local_68[0][4] = local_28;
  local_50 = FUN_001114a0;
  local_58 = FUN_0010e700;
  local_40 = uVar1;
  local_38 = uVar2;
  local_28 = uVar3;
  recv_more(this_ptr,2,local_68);
  if (local_58 != (code *)0x0) {
    (*local_58)(local_68,local_68,3);
  }
  if (local_30 != (code *)0x0) {
    (*local_30)(&local_40,&local_40,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 224  00110c60  WSConn__recv
// ------------------------------------------------------------------
void rea_WSConn__recv__dup2(WSConn * this_ptr, long param_2)
{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 auStack_38 [16];
  code *local_28;
  undefined8 uStack_20;
  
  puVar2 = rea_operator_new(0x18);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar1 = *(undefined8 **)(this_ptr + 0x48);
  *(undefined8 **)(this_ptr + 0x48) = puVar2;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  this_ptr[0x59] = (WSConn)0x0;
  local_28 = (code *)0x0;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(auStack_38,param_2,2);
    local_28 = *(code **)(param_2 + 0x10);
    uStack_20 = *(undefined8 *)(param_2 + 0x18);
  }
  read_head(this_ptr,auStack_38);
  if (local_28 != (code *)0x0) {
    (*local_28)(auStack_38,auStack_38,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 225  00110d50  FUN_00110d50
// ------------------------------------------------------------------
void rea_FUN_00110d50(long * param_1)
{
  undefined4 *__src;
  long *plVar1;
  char cVar2;
  ulong uVar3;
  undefined4 *__dest;
  void *pvVar4;
  size_t sVar5;
  ulong uVar6;
  undefined1 uVar7;
  void *pvVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  undefined4 local_68 [4];
  undefined8 *local_58 [2];
  code *local_48;
  long lStack_40;
  
  param_1 = (long *)*param_1;
  lVar9 = *param_1;
  uVar3 = param_1[1];
  puVar11 = *(undefined8 **)(lVar9 + 0x40);
  plVar1 = *(long **)(lVar9 + 0x48);
  __dest = (undefined4 *)*puVar11;
  pvVar4 = (void *)plVar1[1];
  local_68[0] = *__dest;
  pvVar8 = (void *)*plVar1;
  uVar10 = (long)pvVar4 - (long)pvVar8;
  uVar6 = uVar10 + uVar3;
  if (uVar10 < uVar6) {
    uVar6 = 0;
    if (uVar3 != 0) {
      if ((ulong)(plVar1[2] - (long)pvVar4) < uVar3) {
        if (~uVar10 < uVar3) {
          rea_std____throw_length_error("vector___M_default_append");
          goto LAB_001110e1;
        }
        uVar6 = uVar3;
        if (uVar3 <= uVar10) {
          uVar6 = uVar10;
        }
        uVar12 = 0xffffffffffffffff;
        if ((CARRY8(uVar6,uVar10)) || (uVar12 = uVar6 + uVar10, uVar6 + uVar10 != 0)) {
          pvVar4 = rea_operator_new(uVar12);
          pvVar8 = (void *)*plVar1;
          sVar5 = plVar1[1] - (long)pvVar8;
        }
        else {
          uVar12 = 0;
          pvVar4 = (void *)0x0;
          sVar5 = uVar10;
        }
        if (sVar5 != 0) {
          rea_memmove(pvVar4,pvVar8,sVar5);
        }
        pvVar8 = (void *)((long)pvVar4 + sVar5);
        rea_memset(pvVar8,0,(uVar3 + (long)pvVar8) - (long)pvVar8);
        if ((void *)*plVar1 != (void *)0x0) {
          rea_operator_delete((void *)*plVar1);
        }
        lVar9 = *param_1;
        plVar1[1] = uVar3 + (long)pvVar8;
        *plVar1 = (long)pvVar4;
        plVar1[2] = uVar12 + (long)pvVar4;
        uVar3 = param_1[1];
        puVar11 = *(undefined8 **)(lVar9 + 0x40);
        __dest = (undefined4 *)*puVar11;
      }
      else {
        rea_memset(pvVar4,0,uVar3);
        lVar9 = *param_1;
        plVar1[1] = plVar1[1] + uVar3;
        uVar3 = param_1[1];
        puVar11 = *(undefined8 **)(lVar9 + 0x40);
        __dest = (undefined4 *)*puVar11;
      }
      goto LAB_00110da8;
    }
  }
  else {
    if (uVar6 < uVar10) {
      plVar1[1] = (long)pvVar8 + uVar6;
      lVar9 = *param_1;
      puVar11 = *(undefined8 **)(lVar9 + 0x40);
      __dest = (undefined4 *)*puVar11;
    }
LAB_00110da8:
    uVar6 = 0;
    if (uVar3 != 0) {
      uVar3 = 0;
      while( true ) {
        *(byte *)(uVar10 + **(long **)(lVar9 + 0x48) + uVar3) =
             *(byte *)((long)__dest + uVar3 + 4) ^
             *(byte *)((long)local_68 + (ulong)((uint)uVar3 & 3));
        uVar6 = param_1[1];
        uVar3 = uVar3 + 1;
        if (uVar6 <= uVar3) break;
        lVar9 = *param_1;
        __dest = (undefined4 *)**(undefined8 **)(lVar9 + 0x40);
      }
      puVar11 = *(undefined8 **)(*param_1 + 0x40);
      __dest = (undefined4 *)*puVar11;
    }
  }
  __src = (undefined4 *)((long)__dest + uVar6 + 4);
  if (__src != __dest) {
    lVar9 = 0;
    if ((__src != (undefined4 *)puVar11[1]) && (sVar5 = (long)puVar11[1] - (long)__src, sVar5 != 0))
    {
      __dest = rea_memmove(__dest,__src,sVar5);
      lVar9 = puVar11[1] - (long)__src;
    }
    puVar11[1] = lVar9 + (long)__dest;
  }
  if ((char)param_1[2] == '\0') {
    local_48 = (code *)0x0;
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(local_58,param_1 + 3,2);
      local_48 = (code *)param_1[5];
      lStack_40 = param_1[6];
    }
    rea_WSConn__read_head((WSConn *)*param_1,local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)(local_58,local_58,3);
      return;
    }
  }
  else {
    lVar9 = *param_1;
    uVar7 = 0;
    if (*(char *)(lVar9 + 0x58) != '\0') {
      uVar7 = *(undefined1 *)(lVar9 + 0x59);
    }
    cVar2 = rea_FUN_0010ee80(lVar9 + 0x48,uVar7,*(undefined8 *)(lVar9 + 0x60));
    if (cVar2 != '\0') {
      if (*(int *)((long)param_1 + 0x14) == 1) {
        local_58[0] = *(undefined8 **)(*param_1 + 0x48);
        *(undefined8 *)(*param_1 + 0x48) = 0;
        if (param_1[5] == 0) {
LAB_001110e1:
                    /* WARNING: Subroutine does not return */
          rea_std____throw_bad_function_call();
        }
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      else {
        if (*(int *)((long)param_1 + 0x14) != 8) {
          return;
        }
        if (param_1[5] == 0) {
                    /* WARNING: Subroutine does not return */
          rea_std____throw_bad_function_call();
        }
        local_58[0] = (undefined8 *)0x0;
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      puVar11 = local_58[0];
      if (local_58[0] != (undefined8 *)0x0) {
        if ((void *)*local_58[0] != (void *)0x0) {
          rea_operator_delete((void *)*local_58[0]);
        }
        rea_operator_delete(puVar11);
      }
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 226  00111100  FUN_00111100
// ------------------------------------------------------------------
void rea_FUN_00111100(long * param_1)
{
  undefined8 *puVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  void *__dest;
  void *pvVar5;
  long lVar6;
  size_t sVar7;
  void *pvVar8;
  undefined1 uVar9;
  void *pvVar10;
  ulong __n;
  long *plVar11;
  size_t __n_00;
  ulong local_68;
  undefined8 *local_58 [2];
  code *local_48;
  long lStack_40;
  
  param_1 = (long *)*param_1;
  lVar6 = *param_1;
  lVar3 = param_1[1];
  plVar11 = *(long **)(lVar6 + 0x48);
  pvVar8 = (void *)**(undefined8 **)(lVar6 + 0x40);
  pvVar5 = (void *)plVar11[1];
  if (pvVar8 != (void *)((long)pvVar8 + lVar3)) {
    __n = ((long)pvVar8 + lVar3) - (long)pvVar8;
    if ((ulong)(plVar11[2] - (long)pvVar5) < __n) {
      pvVar10 = (void *)*plVar11;
      sVar7 = (long)pvVar5 - (long)pvVar10;
      if (~sVar7 < __n) {
        rea_std____throw_length_error("vector___M_range_insert");
        goto LAB_00111427;
      }
      local_68 = 0xffffffffffffffff;
      uVar4 = sVar7;
      if (sVar7 <= __n) {
        uVar4 = __n;
      }
      if ((CARRY8(uVar4,sVar7)) || (local_68 = uVar4 + sVar7, uVar4 + sVar7 != 0)) {
        __dest = rea_operator_new(local_68);
        pvVar10 = (void *)*plVar11;
        sVar7 = (long)pvVar5 - (long)pvVar10;
      }
      else {
        local_68 = 0;
        __dest = (void *)0x0;
      }
      if (sVar7 != 0) {
        rea_memmove(__dest,pvVar10,sVar7);
      }
      pvVar10 = (void *)(sVar7 + (long)__dest);
      if (__n != 0) {
        pvVar10 = rea_memmove(pvVar10,pvVar8,__n);
      }
      __n_00 = plVar11[1] - (long)pvVar5;
      sVar7 = 0;
      if (__n_00 != 0) {
        rea_memmove((void *)(__n + (long)pvVar10),pvVar5,__n_00);
        sVar7 = __n_00;
      }
      if ((void *)*plVar11 != (void *)0x0) {
        rea_operator_delete((void *)*plVar11);
      }
      *plVar11 = (long)__dest;
      lVar6 = *param_1;
      plVar11[1] = (long)(__n + (long)pvVar10) + sVar7;
      plVar11[2] = (long)__dest + local_68;
      plVar11 = *(long **)(lVar6 + 0x40);
      pvVar5 = (void *)*plVar11;
      pvVar8 = (void *)((long)pvVar5 + param_1[1]);
    }
    else {
      if (__n != 0) {
        rea_memmove(pvVar5,pvVar8,__n);
        pvVar5 = (void *)plVar11[1];
        lVar3 = param_1[1];
        lVar6 = *param_1;
      }
      plVar11[1] = (long)pvVar5 + __n;
      plVar11 = *(long **)(lVar6 + 0x40);
      pvVar5 = (void *)*plVar11;
      pvVar8 = (void *)((long)pvVar5 + lVar3);
    }
    if (pvVar8 != pvVar5) {
      lVar6 = 0;
      if ((pvVar8 != (void *)plVar11[1]) && (sVar7 = plVar11[1] - (long)pvVar8, sVar7 != 0)) {
        pvVar5 = rea_memmove(pvVar5,pvVar8,sVar7);
        lVar6 = plVar11[1] - (long)pvVar8;
      }
      plVar11[1] = (long)pvVar5 + lVar6;
    }
  }
  if ((char)param_1[2] == '\0') {
    local_48 = (code *)0x0;
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(local_58,param_1 + 3,2);
      local_48 = (code *)param_1[5];
      lStack_40 = param_1[6];
    }
    rea_WSConn__read_head((WSConn *)*param_1,local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)(local_58,local_58,3);
      return;
    }
  }
  else {
    lVar6 = *param_1;
    uVar9 = 0;
    if (*(char *)(lVar6 + 0x58) != '\0') {
      uVar9 = *(undefined1 *)(lVar6 + 0x59);
    }
    cVar2 = rea_FUN_0010ee80(lVar6 + 0x48,uVar9,*(undefined8 *)(lVar6 + 0x60));
    if (cVar2 != '\0') {
      if (*(int *)((long)param_1 + 0x14) == 1) {
        local_58[0] = *(undefined8 **)(*param_1 + 0x48);
        *(undefined8 *)(*param_1 + 0x48) = 0;
        if (param_1[5] == 0) {
LAB_00111427:
                    /* WARNING: Subroutine does not return */
          rea_std____throw_bad_function_call();
        }
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      else {
        if (*(int *)((long)param_1 + 0x14) != 8) {
          return;
        }
        if (param_1[5] == 0) {
                    /* WARNING: Subroutine does not return */
          rea_std____throw_bad_function_call();
        }
        local_58[0] = (undefined8 *)0x0;
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      puVar1 = local_58[0];
      if (local_58[0] != (undefined8 *)0x0) {
        if ((void *)*local_58[0] != (void *)0x0) {
          rea_operator_delete((void *)*local_58[0]);
        }
        rea_operator_delete(puVar1);
      }
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 227  001114a0  FUN_001114a0
// ------------------------------------------------------------------
void rea_FUN_001114a0(long * param_1)
{
  byte *__src;
  byte bVar1;
  byte bVar2;
  undefined8 *puVar3;
  code *pcVar4;
  byte *__dest;
  long lVar5;
  size_t __n;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  long *local_98 [2];
  code *local_88;
  code *local_80;
  long local_78;
  byte local_70;
  uint local_6c;
  code *local_68;
  long alStack_60 [2];
  code *local_50;
  long local_48;
  
  param_1 = (long *)*param_1;
  local_78 = *param_1;
  puVar3 = *(undefined8 **)(local_78 + 0x40);
  __dest = (byte *)*puVar3;
  bVar1 = *__dest;
  bVar2 = __dest[1];
  bVar8 = bVar1 >> 7;
  local_70 = bVar2 >> 7;
  uVar7 = bVar1 & 0xf;
  bVar6 = bVar2;
  if ((bVar1 & 0x40) != 0) {
    *(undefined1 *)(local_78 + 0x59) = 1;
    bVar6 = __dest[1];
  }
  bVar6 = bVar6 & 0x7f;
  local_6c = uVar7;
  if (bVar6 == 0x7e) {
    local_68 = (code *)CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_68 + 0x1)),bVar8);
    local_50 = (code *)0x0;
    if ((code *)param_1[3] != (code *)0x0) {
      (*(code *)param_1[3])(alStack_60,param_1 + 1,2);
      local_48 = param_1[4];
      local_50 = (code *)param_1[3];
    }
    local_88 = (code *)0x0;
    local_98[0] = rea_operator_new(0x38);
    *local_98[0] = local_78;
    *(byte *)(local_98[0] + 1) = local_70;
    *(uint *)((long)local_98[0] + 0xc) = local_6c;
    local_98[0][5] = 0;
    *(undefined1 *)(local_98[0] + 2) = (*(undefined1 *)((uint8_t *)&local_68 + 0x0));
    if (local_50 != (code *)0x0) {
      (*local_50)(local_98[0] + 3,alStack_60,2);
      local_98[0][6] = local_48;
      local_98[0][5] = (long)local_50;
    }
    local_80 = FUN_00110920;
    local_88 = FUN_0010ead0;
    rea_WSConn__recv_more((WSConn *)*param_1,4,local_98);
    if (local_88 != (code *)0x0) {
      (*local_88)(local_98,local_98,3);
    }
    if (local_50 != (code *)0x0) {
      (*local_50)(alStack_60,alStack_60,3);
      return;
    }
  }
  else if (bVar6 == 0x7f) {
    local_68 = (code *)CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_68 + 0x1)),bVar8);
    local_50 = (code *)0x0;
    if ((code *)param_1[3] != (code *)0x0) {
      (*(code *)param_1[3])(alStack_60,param_1 + 1,2);
      local_48 = param_1[4];
      local_50 = (code *)param_1[3];
    }
    local_88 = (code *)0x0;
    local_98[0] = rea_operator_new(0x38);
    *local_98[0] = local_78;
    *(byte *)(local_98[0] + 1) = local_70;
    *(uint *)((long)local_98[0] + 0xc) = local_6c;
    local_98[0][5] = 0;
    *(undefined1 *)(local_98[0] + 2) = (*(undefined1 *)((uint8_t *)&local_68 + 0x0));
    if (local_50 != (code *)0x0) {
      (*local_50)(local_98[0] + 3,alStack_60,2);
      local_98[0][6] = local_48;
      local_98[0][5] = (long)local_50;
    }
    local_80 = FUN_00111a50;
    local_88 = FUN_0010e830;
    rea_WSConn__recv_more((WSConn *)*param_1,10,local_98);
    if (local_88 != (code *)0x0) {
      (*local_88)(local_98,local_98,3);
    }
    if (local_50 != (code *)0x0) {
      (*local_50)(alStack_60,alStack_60,3);
      return;
    }
  }
  else {
    __src = __dest + 2;
    lVar5 = 0;
    if ((__src != (byte *)puVar3[1]) && (__n = (long)puVar3[1] - (long)__src, __n != 0)) {
      __dest = rea_memmove(__dest,__src,__n);
      lVar5 = puVar3[1] - (long)__src;
    }
    puVar3[1] = __dest + lVar5;
    local_68 = (code *)0x0;
    pcVar4 = (code *)param_1[3];
    if ((char)bVar2 < '\0') {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(&local_78,param_1 + 1,2);
        local_68 = (code *)param_1[3];
        alStack_60[0] = param_1[4];
      }
      rea_WSConn__read_data_mask((WSConn *)*param_1,uVar7,bVar8,bVar6,&local_78);
      if (local_68 != (code *)0x0) {
        (*local_68)(&local_78,&local_78,3);
        return;
      }
    }
    else {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(&local_78,param_1 + 1,2);
        local_68 = (code *)param_1[3];
        alStack_60[0] = param_1[4];
      }
      rea_WSConn__read_data((WSConn *)*param_1,uVar7,bVar8,bVar6,&local_78);
      if (local_68 != (code *)0x0) {
        (*local_68)(&local_78,&local_78,3);
      }
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 228  00111a50  FUN_00111a50
// ------------------------------------------------------------------
void rea_FUN_00111a50(long * param_1)
{
  void *__src;
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  void *__dest;
  long lVar5;
  size_t __n;
  long lVar6;
  undefined1 auStack_48 [16];
  code *local_38;
  undefined8 uStack_30;
  
  puVar2 = (undefined8 *)*param_1;
  puVar3 = *(undefined8 **)((WSConn *)*puVar2 + 0x40);
  __dest = (void *)*puVar3;
  if ((((*(char *)((long)__dest + 2) == '\0') && (*(char *)((long)__dest + 3) == '\0')) &&
      (*(char *)((long)__dest + 4) == '\0')) && (*(char *)((long)__dest + 5) == '\0')) {
    __src = (void *)((long)__dest + 10);
    lVar5 = 0;
    lVar6 = (long)(int)((uint)*(byte *)((long)__dest + 6) << 0x18 |
                        (uint)*(byte *)((long)__dest + 7) << 0x10 |
                        (uint)*(byte *)((long)__dest + 9) | (uint)*(byte *)((long)__dest + 8) << 8);
    if ((__src != (void *)puVar3[1]) && (__n = (long)puVar3[1] - (long)__src, __n != 0)) {
      __dest = rea_memmove(__dest,__src,__n);
      lVar5 = puVar3[1] - (long)__src;
    }
    cVar1 = *(char *)(puVar2 + 1);
    puVar3[1] = (long)__dest + lVar5;
    local_38 = (code *)0x0;
    pcVar4 = (code *)puVar2[5];
    if (cVar1 == '\0') {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(auStack_48,puVar2 + 3,2);
        local_38 = (code *)puVar2[5];
        uStack_30 = puVar2[6];
      }
      rea_WSConn__read_data((WSConn *)*puVar2,*(undefined4 *)((long)puVar2 + 0xc),
                        *(undefined1 *)(puVar2 + 2),lVar6,auStack_48);
      if (local_38 != (code *)0x0) {
        (*local_38)(auStack_48,auStack_48,3);
        return;
      }
    }
    else {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(auStack_48,puVar2 + 3,2);
        local_38 = (code *)puVar2[5];
        uStack_30 = puVar2[6];
      }
      WSConn__read_data_mask_________________((WSConn *)*puVar2,*(undefined4 *)((long)puVar2 + 0xc),*(undefined1 *)(puVar2 + 2),
                 lVar6,auStack_48);
      if (local_38 != (code *)0x0) {
        (*local_38)(auStack_48,auStack_48,3);
        return;
      }
    }
  }
  else {
    rea_WSConn__exit((WSConn *)*puVar2);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 229  00111c50  FUN_00111c50
// ------------------------------------------------------------------
void rea_FUN_00111c50(long * param_1, undefined8 * param_2)
{
  undefined8 *puVar1;
  void *__src;
  ulong uVar2;
  void *__dest;
  undefined8 uVar3;
  WSConn *pWVar4;
  size_t sVar5;
  void *__src_00;
  void *pvVar6;
  long *plVar7;
  ulong uVar8;
  size_t __n;
  ulong local_68;
  undefined1 local_58 [16];
  code *local_48;
  long lStack_40;
  
  puVar1 = (undefined8 *)*param_2;
  *param_2 = 0;
  param_1 = (long *)*param_1;
  if (puVar1 == (undefined8 *)0x0) {
    rea_WSConn__exit((WSConn *)*param_1);
    return;
  }
  pWVar4 = (WSConn *)*param_1;
  __src = (void *)*puVar1;
  plVar7 = *(long **)(pWVar4 + 0x40);
  __src_00 = (void *)plVar7[1];
  if (__src != (void *)puVar1[1]) {
    uVar8 = (long)puVar1[1] - (long)__src;
    if ((ulong)(plVar7[2] - (long)__src_00) < uVar8) {
      pvVar6 = (void *)*plVar7;
      sVar5 = (long)__src_00 - (long)pvVar6;
      if (~sVar5 < uVar8) {
        uVar3 = rea_std____throw_length_error("vector___M_range_insert");
        rea_FUN_00107772(puVar1);
                    /* WARNING: Subroutine does not return */
        rea__Unwind_Resume(uVar3);
      }
      local_68 = 0xffffffffffffffff;
      uVar2 = sVar5;
      if (sVar5 <= uVar8) {
        uVar2 = uVar8;
      }
      if ((CARRY8(uVar2,sVar5)) || (local_68 = uVar2 + sVar5, uVar2 + sVar5 != 0)) {
        __dest = rea_operator_new(local_68);
        pvVar6 = (void *)*plVar7;
        sVar5 = (long)__src_00 - (long)pvVar6;
      }
      else {
        local_68 = 0;
        __dest = (void *)0x0;
      }
      if (sVar5 != 0) {
        __dest = rea_memmove(__dest,pvVar6,sVar5);
      }
      pvVar6 = (void *)(sVar5 + (long)__dest);
      if (uVar8 != 0) {
        pvVar6 = rea_memmove(pvVar6,__src,uVar8);
      }
      __n = plVar7[1] - (long)__src_00;
      sVar5 = 0;
      if (__n != 0) {
        rea_memmove((void *)(uVar8 + (long)pvVar6),__src_00,__n);
        sVar5 = __n;
      }
      if ((void *)*plVar7 != (void *)0x0) {
        rea_operator_delete((void *)*plVar7);
      }
      *plVar7 = (long)__dest;
      pWVar4 = (WSConn *)*param_1;
      plVar7[1] = (long)(uVar8 + (long)pvVar6) + sVar5;
      plVar7[2] = (long)__dest + local_68;
      plVar7 = *(long **)(pWVar4 + 0x40);
      __src_00 = (void *)plVar7[1];
    }
    else {
      if (uVar8 != 0) {
        rea_memmove(__src_00,__src,uVar8);
        __src_00 = (void *)plVar7[1];
        pWVar4 = (WSConn *)*param_1;
      }
      plVar7[1] = (long)__src_00 + uVar8;
      plVar7 = *(long **)(pWVar4 + 0x40);
      __src_00 = (void *)plVar7[1];
    }
  }
  uVar8 = param_1[1];
  if ((ulong)((long)__src_00 - *plVar7) < uVar8) {
    local_48 = (code *)0x0;
    if ((code *)param_1[4] != (code *)0x0) {
      (*(code *)param_1[4])(local_58,param_1 + 2,2);
      local_48 = (code *)param_1[4];
      lStack_40 = param_1[5];
      uVar8 = param_1[1];
      pWVar4 = (WSConn *)*param_1;
    }
    rea_WSConn__recv_more(pWVar4,uVar8,local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)(local_58,local_58,3);
    }
  }
  else {
    if (param_1[4] == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (*(code *)param_1[5])(param_1 + 2);
  }
  if ((void *)*puVar1 != (void *)0x0) {
    rea_operator_delete((void *)*puVar1);
  }
  rea_operator_delete(puVar1);
  return;
}





// ------------------------------------------------------------------
// IDX 230  00111f80  FUN_00111f80
// ------------------------------------------------------------------
void rea_FUN_00111f80(long * param_1, undefined8 * param_2)
{
  int *piVar1;
  undefined8 *puVar2;
  void *__src;
  long *plVar3;
  int iVar4;
  ulong uVar5;
  void *__dest;
  undefined8 uVar6;
  size_t sVar7;
  void *__src_00;
  void *pvVar8;
  ulong __n;
  size_t __n_00;
  ulong local_88;
  long local_68 [2];
  undefined1 local_58 [16];
  code *local_48;
  long lStack_40;
  
  puVar2 = (undefined8 *)*param_2;
  *param_2 = 0;
  param_1 = (long *)*param_1;
  if (puVar2 == (undefined8 *)0x0) {
    rea_WSConn__exit((WSConn *)*param_1);
    return;
  }
  __src = (void *)*puVar2;
  plVar3 = *(long **)(*param_1 + 0x40);
  __src_00 = (void *)plVar3[1];
  if (__src != (void *)puVar2[1]) {
    __n = (long)puVar2[1] - (long)__src;
    if ((ulong)(plVar3[2] - (long)__src_00) < __n) {
      pvVar8 = (void *)*plVar3;
      sVar7 = (long)__src_00 - (long)pvVar8;
      if (~sVar7 < __n) {
        uVar6 = rea_std____throw_length_error("vector___M_range_insert");
        rea_FUN_00107772(puVar2);
                    /* WARNING: Subroutine does not return */
        rea__Unwind_Resume(uVar6);
      }
      local_88 = 0xffffffffffffffff;
      uVar5 = sVar7;
      if (sVar7 <= __n) {
        uVar5 = __n;
      }
      if ((CARRY8(uVar5,sVar7)) || (local_88 = uVar5 + sVar7, uVar5 + sVar7 != 0)) {
        __dest = rea_operator_new(local_88);
        pvVar8 = (void *)*plVar3;
        sVar7 = (long)__src_00 - (long)pvVar8;
      }
      else {
        local_88 = 0;
        __dest = (void *)0x0;
      }
      if (sVar7 != 0) {
        __dest = rea_memmove(__dest,pvVar8,sVar7);
      }
      pvVar8 = (void *)(sVar7 + (long)__dest);
      if (__n != 0) {
        pvVar8 = rea_memmove(pvVar8,__src,__n);
      }
      __n_00 = plVar3[1] - (long)__src_00;
      sVar7 = 0;
      if (__n_00 != 0) {
        rea_memmove((void *)(__n + (long)pvVar8),__src_00,__n_00);
        sVar7 = __n_00;
      }
      if ((void *)*plVar3 != (void *)0x0) {
        rea_operator_delete((void *)*plVar3);
      }
      *plVar3 = (long)__dest;
      plVar3[1] = (long)(__n + (long)pvVar8) + sVar7;
      plVar3[2] = (long)__dest + local_88;
    }
    else {
      if (__n != 0) {
        rea_memmove(__src_00,__src,__n);
        __src_00 = (void *)plVar3[1];
      }
      plVar3[1] = (long)__src_00 + __n;
    }
  }
  local_48 = (code *)0x0;
  if ((code *)param_1[4] != (code *)0x0) {
    (*(code *)param_1[4])(local_58,param_1 + 2,2);
    local_48 = (code *)param_1[4];
    lStack_40 = param_1[5];
  }
  rea_std__string__string((string *)local_68,(string *)(param_1 + 1));
  rea_WSConn__recv_pat((WSConn *)*param_1,(string *)local_68,local_58);
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
  if (local_48 != (code *)0x0) {
    (*local_48)(local_58,local_58,3);
  }
  if ((void *)*puVar2 != (void *)0x0) {
    rea_operator_delete((void *)*puVar2);
  }
  rea_operator_delete(puVar2);
  return;
}





// ------------------------------------------------------------------
// IDX 231  001122b0  WSConn__connect
// ------------------------------------------------------------------
void rea_WSConn__connect__dup2(WSConn * this_ptr, long param_2)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  sbyte sVar16;
  _Rb_tree_node_base *p_Var17;
  long lVar18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  undefined1 auVar25 [16];
  int local_108 [4];
  byte local_f8 [16];
  undefined8 local_e8;
  undefined8 local_e0;
  code *local_d8;
  undefined8 local_d0;
  char local_c8 [48];
  WSConn *local_98;
  undefined1 local_90 [16];
  code *local_80;
  undefined8 local_78;
  WSConn *local_68;
  undefined8 local_60;
  undefined8 local_58;
  code *local_50;
  undefined8 local_48;
  
  uVar9 = 0;
  local_f8[0] = 0;
  local_f8[1] = 0;
  local_f8[2] = 0;
  local_f8[3] = 0;
  local_f8[4] = 0;
  local_f8[5] = 0;
  local_f8[6] = 0;
  local_f8[7] = 0;
  local_f8[8] = 0;
  local_f8[9] = 0;
  local_f8[10] = 0;
  local_f8[0xb] = 0;
  local_f8[0xc] = 0;
  local_f8[0xd] = 0;
  local_f8[0xe] = 0;
  local_f8[0xf] = 0;
  pcVar11 = local_c8;
  iVar22 = 0;
  do {
    if (iVar22 + 1 == 0x10) {
      iVar23 = 0x10;
      sVar16 = 0x10;
      iVar22 = 1;
    }
    else {
      uVar9 = (uint)local_f8[iVar22 + 1] | uVar9 << 8;
      iVar23 = iVar22 + 2;
      if (iVar23 < 0x10) {
        lVar18 = (long)iVar23;
        iVar23 = iVar22 + 3;
        sVar16 = 0;
        uVar9 = uVar9 << 8 | (uint)local_f8[lVar18];
        iVar22 = 3;
      }
      else {
        sVar16 = 8;
        iVar22 = 2;
      }
    }
    uVar9 = uVar9 << sVar16;
    bVar7 = (byte)((int)uVar9 >> 0x12);
    local_68 = (WSConn *)(CONCAT71((int7)((ulong)local_68 >> 8),bVar7) & 0xffffffff0000003f);
    *pcVar11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
               [(char)(bVar7 & 0x3f)];
    bVar7 = (byte)((int)uVar9 >> 0xc);
    local_68 = (WSConn *)
               (CONCAT62((*(arr_undefined1_6 *)((uint8_t *)&local_68 + 0x2)),CONCAT11(bVar7,(*(undefined1 *)((uint8_t *)&local_68 + 0x0)))) & 0xffffffffffff3fff);
    pcVar11[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                 [(char)(bVar7 & 0x3f)];
    if (iVar22 == 1) {
      pcVar11[2] = '=';
LAB_001123de:
      uVar9 = 0x40;
    }
    else {
      bVar7 = (byte)((int)uVar9 >> 6);
      local_68 = (WSConn *)
                 (CONCAT53((*(arr_undefined1_5 *)((uint8_t *)&local_68 + 0x3)),CONCAT12(bVar7,(*(undefined2 *)((uint8_t *)&local_68 + 0x0)))) & 0xffffffffff3fffff);
      pcVar11[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                   [(char)(bVar7 & 0x3f)];
      if (iVar22 != 3) goto LAB_001123de;
      uVar9 = uVar9 & 0x3f;
    }
    pcVar11[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="[(int)uVar9];
    if (0xf < iVar23) break;
    uVar9 = (uint)local_f8[iVar23];
    pcVar11 = pcVar11 + 4;
    iVar22 = iVar23;
  } while( true );
  pcVar11[4] = '\0';
  pcVar11 = rea_operator_new(0x18);
  pcVar11[0] = '\0';
  pcVar11[1] = '\0';
  pcVar11[2] = '\0';
  pcVar11[3] = '\0';
  pcVar11[4] = '\0';
  pcVar11[5] = '\0';
  pcVar11[6] = '\0';
  pcVar11[7] = '\0';
  pcVar11[8] = '\0';
  pcVar11[9] = '\0';
  pcVar11[10] = '\0';
  pcVar11[0xb] = '\0';
  pcVar11[0xc] = '\0';
  pcVar11[0xd] = '\0';
  pcVar11[0xe] = '\0';
  pcVar11[0xf] = '\0';
  pcVar11[0x10] = '\0';
  pcVar11[0x11] = '\0';
  pcVar11[0x12] = '\0';
  pcVar11[0x13] = '\0';
  pcVar11[0x14] = '\0';
  pcVar11[0x15] = '\0';
  pcVar11[0x16] = '\0';
  pcVar11[0x17] = '\0';
  rea_Buffer__appendf(pcVar11,
                  "GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Key: %s\r\nSec-WebSocket-Extensions: permessage-deflate\r\nSec-WebSocket-Version: 13\r\n\r\n"
                  ,local_c8);
  local_80 = (code *)0x0;
  local_98 = this_ptr;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(local_90,param_2,2);
    local_78 = *(undefined8 *)(param_2 + 0x18);
    local_80 = *(code **)(param_2 + 0x10);
  }
  lVar18 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar18 + 0x5a) != '\0') {
    rea_fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar12 = *(undefined8 **)(lVar18 + 0x60);
  *(undefined1 *)(lVar18 + 0x5a) = 1;
  *(char **)(lVar18 + 0x60) = pcVar11;
  if (puVar12 != (undefined8 *)0x0) {
    if ((void *)*puVar12 != (void *)0x0) {
      rea_operator_delete((void *)*puVar12);
    }
    rea_operator_delete(puVar12);
  }
  local_50 = (code *)0x0;
  local_68 = local_98;
  if (local_80 != (code *)0x0) {
    (*local_80)(&local_60,local_90,2);
    local_48 = local_78;
    local_50 = local_80;
  }
  local_d8 = (code *)0x0;
  puVar12 = rea_operator_new(0x28);
  pcVar8 = local_50;
  uVar3 = puVar12[1];
  puVar12[3] = 0;
  uVar4 = puVar12[2];
  *puVar12 = local_68;
  puVar12[1] = local_60;
  puVar12[2] = local_58;
  local_50 = (code *)0x0;
  uVar5 = puVar12[4];
  puVar12[3] = pcVar8;
  puVar12[4] = local_48;
  local_e8 = *(undefined8 *)(lVar18 + 0x68);
  uVar6 = *(undefined8 *)(lVar18 + 0x70);
  *(undefined8 *)(lVar18 + 0x70) = local_e0;
  *(undefined8 **)(lVar18 + 0x68) = puVar12;
  local_d8 = *(code **)(lVar18 + 0x78);
  local_d0 = *(undefined8 *)(lVar18 + 0x80);
  *(code **)(lVar18 + 0x78) = FUN_0010e1d0;
  *(code **)(lVar18 + 0x80) = FUN_0010fc40;
  local_e0 = uVar6;
  local_60 = uVar3;
  local_58 = uVar4;
  local_48 = uVar5;
  if (local_d8 != (code *)0x0) {
    (*local_d8)(&local_e8,&local_e8,3);
  }
  if (local_50 != (code *)0x0) {
    (*local_50)(&local_60,&local_60,3);
  }
  local_108[0] = *(int *)(lVar18 + 0x40);
  cVar2 = *(char *)(lVar18 + 0x5a);
  lVar18 = *(long *)(lVar18 + 0x38);
  p_Var15 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var20 = p_Var15;
  p_Var19 = p_Var14;
  if (p_Var15 == (_Rb_tree_node_base *)0x0) {
LAB_00112970:
    lVar13 = 0;
    uVar9 = 0;
  }
  else {
    do {
      while (p_Var17 = p_Var20, local_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var20 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var19 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011265b;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var20 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var19;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_0011265b:
    if ((p_Var14 == p_Var17) || (p_Var20 = p_Var14, local_108[0] < *(int *)(p_Var17 + 0x20)))
    goto LAB_00112970;
    do {
      while (p_Var19 = p_Var15, local_108[0] <= *(int *)(p_Var19 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)(p_Var19 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00112693;
      }
      p_Var17 = p_Var19 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var17;
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_00112693:
    if ((p_Var14 == p_Var19) || (local_108[0] < *(int *)(p_Var19 + 0x20))) {
      p_Var15 = rea_operator_new(0x28);
      if (p_Var15 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var15 = 0;
        *(undefined8 *)(p_Var15 + 8) = 0;
        *(undefined8 *)(p_Var15 + 0x10) = 0;
        *(undefined8 *)(p_Var15 + 0x18) = 0;
        *(undefined4 *)(p_Var15 + 0x24) = 0;
        *(int *)(p_Var15 + 0x20) = local_108[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar18 + 8),p_Var19,p_Var15 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
      p_Var20 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x8));
      p_Var19 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x0));
      if (p_Var20 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var15);
      }
      else {
        bVar21 = true;
        if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var20)) {
          bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var20 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var20,p_Var14);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var19 = p_Var15;
      }
    }
    uVar9 = *(uint *)(p_Var19 + 0x24);
    lVar13 = 1;
  }
  lVar18 = lVar18 + (lVar13 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar18 + 8);
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var15 = p_Var14;
  p_Var20 = p_Var19;
  uVar10 = uVar9;
  if (p_Var14 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var17 = p_Var15, local_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var20 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_001126fa;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_001126fa:
    if ((p_Var19 != p_Var17) && (p_Var15 = p_Var19, *(int *)(p_Var17 + 0x20) <= local_108[0])) {
      do {
        while (p_Var20 = p_Var14, local_108[0] <= *(int *)(p_Var20 + 0x20)) {
          p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
          p_Var15 = p_Var20;
          if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011272a;
        }
        p_Var17 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var17;
        p_Var20 = p_Var15;
      } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_0011272a:
      if ((p_Var19 == p_Var20) || (local_108[0] < *(int *)(p_Var20 + 0x20))) {
        p_Var14 = rea_operator_new(0x28);
        if (p_Var14 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_108[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var20,p_Var14 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
        p_Var15 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x8));
        p_Var20 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x0));
        if (p_Var15 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var14);
        }
        else {
          bVar21 = true;
          if ((p_Var20 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var15)) {
            bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var15 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var15,p_Var19);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var20 = p_Var14;
        }
      }
      uVar10 = *(uint *)(p_Var20 + 0x24);
    }
  }
  uVar24 = uVar10 | 2;
  if (cVar2 == '\0') {
    uVar24 = uVar10 & 0xfffffffd;
  }
  if (uVar9 == uVar24) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_108);
    goto LAB_00112819;
  }
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var20 = p_Var19;
  p_Var15 = p_Var19;
  if (*(_Rb_tree_node_base **)(lVar18 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0011279c:
    p_Var14 = rea_operator_new(0x28);
    if (p_Var14 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var14 = 0;
      *(undefined8 *)(p_Var14 + 8) = 0;
      *(undefined8 *)(p_Var14 + 0x10) = 0;
      *(undefined8 *)(p_Var14 + 0x18) = 0;
      *(undefined4 *)(p_Var14 + 0x24) = 0;
      *(int *)(p_Var14 + 0x20) = local_108[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var14 + 0x20)); memcpy(auVar25, &__rea_tmp, sizeof(auVar25)); }
    p_Var20 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x8));
    p_Var15 = (*(undefined8 *)((uint8_t *)&auVar25 + 0x0));
    if (p_Var20 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var14);
    }
    else {
      bVar21 = true;
      if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var20)) {
        bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var20 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var20,p_Var19);
      *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
      p_Var15 = p_Var14;
    }
  }
  else {
    do {
      while (p_Var15 = p_Var14, local_108[0] <= *(int *)(p_Var15 + 0x20)) {
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var20 = p_Var15;
        if (*(_Rb_tree_node_base **)(p_Var15 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00112792;
      }
      p_Var17 = p_Var15 + 0x18;
      p_Var14 = *(_Rb_tree_node_base **)p_Var17;
      p_Var15 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_00112792:
    if ((p_Var19 == p_Var15) || (local_108[0] < *(int *)(p_Var15 + 0x20))) goto LAB_0011279c;
  }
  *(uint *)(p_Var15 + 0x24) = uVar24;
LAB_00112819:
  if (local_80 != (code *)0x0) {
    (*local_80)(local_90,local_90,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 232  00112b60  FUN_00112b60
// ------------------------------------------------------------------
void rea_FUN_00112b60(long * param_1, int param_2)
{
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
  long *plVar16;
  char *pcVar17;
  undefined8 *puVar18;
  void *pvVar19;
  long lVar20;
  _Rb_tree_node_base *p_Var21;
  _Rb_tree_node_base *p_Var22;
  sbyte sVar23;
  long lVar24;
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
  long lVar35;
  _Rb_tree_node_base *p_Var36;
  uint *puVar37;
  bool bVar38;
  byte bVar39;
  undefined1 auVar40 [16];
  int local_218 [4];
  undefined *local_208 [2];
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
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
  undefined8 local_190;
  long local_188;
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
  param_1 = (long *)*param_1;
  pvVar15 = (void *)**(undefined8 **)(*param_1 + 0x40);
  iVar12 = (int)(*(undefined8 **)(*param_1 + 0x40))[1] - (int)pvVar15;
  pvVar15 = rea_memmem(pvVar15,(long)iVar12,"Sec-WebSocket-Key: ",0x13);
  if (pvVar15 != (void *)0x0) {
    lVar24 = 0;
    do {
      cVar33 = *(char *)((long)pvVar15 + lVar24 + 0x13);
      if (((cVar33 == '\r') || (cVar33 == '\n')) || (iVar31 = (int)lVar24, iVar12 + -0x13 <= iVar31)
         ) goto LAB_00112bdb;
      auStack_13b[lVar24 + 3] = cVar33;
      lVar24 = lVar24 + 1;
    } while (lVar24 != 0x7f);
    lVar24 = (long)(iVar31 + 1);
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
        puVar37 = (uint *)((long)puVar27 + 6);
      }
      local_1a0 = 0x98badcfe;
      local_19c = 0x10325476;
      local_198 = 0xc3d2e1f0;
      lVar24 = (long)puVar37 + ((-3 - (ulong)CARRY1((byte)uVar14,(byte)uVar14)) - (long)puVar5);
      local_148 = 0;
      local_144 = 0;
      *(undefined8 *)((long)puVar5 + lVar24) = 0x3541464145383532;
      *(undefined4 *)(auStack_120 + lVar24 + 8) = 0x31314235;
      *(undefined8 *)(auStack_133 + lVar24 + 3) = 0x37342d343139452d;
      *(undefined1 *)((long)&local_118 + lVar24 + 4) = 0;
      *(undefined8 *)(auStack_12b + lVar24 + 3) = 0x2d414335392d4144;
      *(undefined8 *)(local_128 + lVar24 + 8) = 0x3843443042413543;
      if ((int)lVar24 == -0x24) {
LAB_001135da:
        iVar31 = local_14c;
        iVar12 = local_14c + 1;
        lVar24 = (long)local_14c;
        local_14c = iVar12;
        *(undefined1 *)((long)&local_190 + lVar24 + 4) = 0x80;
        if (iVar31 < 0x38) {
          if (iVar12 != 0x38) {
            rea_memset((void *)((long)&local_190 + lVar24 + 5),0,(ulong)(0x37 - iVar31));
            local_14c = 0x38;
          }
        }
        else {
          if (iVar12 < 0x40) {
            rea_memset((void *)((long)&local_190 + lVar24 + 5),0,(ulong)(0x3f - iVar31));
            local_14c = 0x40;
          }
          rea_FUN_0010d620(&local_1a8);
          if (local_14c < 0x38) {
            rea_memset((void *)((long)&local_190 + (long)local_14c + 4),0,(ulong)(0x38 - local_14c));
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
        rea_FUN_0010d620(&local_1a8);
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
          *(char *)((long)&local_190 + lVar35 + 4) = (char)*puVar37;
          local_194 = local_194 + 8;
          if (local_194 == 0) {
            iVar31 = (int)local_190 + 1;
            local_190 = (code *)CONCAT44((*(undefined4 *)((uint8_t *)&local_190 + 0x4)),iVar31);
            if (iVar31 == 0) {
              local_144 = 1;
            }
          }
          if (iVar12 == 0x40) {
            rea_FUN_0010d620(&local_1a8);
          }
          if (puVar37 == (uint *)((ulong)((int)lVar24 + 0x23) + (long)puVar5)) break;
          if (local_144 != 0) goto LAB_00113799;
          puVar37 = (uint *)((long)puVar37 + 1);
          lVar35 = (long)local_14c;
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
          uVar14 = (uint)*(byte *)((long)&local_1f8 + (long)(iVar12 + 1)) | uVar14 << 8;
          if (iVar31 < 0x14) {
            lVar24 = (long)iVar31;
            iVar31 = iVar12 + 3;
            iVar12 = 3;
            uVar14 = uVar14 << 8 | (uint)*(byte *)((long)&local_1f8 + lVar24);
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
        uVar14 = (uint)*(byte *)((long)&local_1f8 + (long)iVar31);
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
  uVar26 = puVar18[1] - (long)pcVar17;
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
          lVar24 = *(long *)(local_208[0] + -0x18);
          uVar2 = lVar24 + 1;
          if ((*(ulong *)(local_208[0] + -0x10) < uVar2) || (0 < *(int *)(local_208[0] + -8))) {
            rea_std__string__reserve((ulong)local_208);
            lVar24 = *(long *)(local_208[0] + -0x18);
          }
          local_208[0][lVar24] = cVar33;
          if (local_208[0] + -0x18 != puVar11) {
            *(undefined4 *)(local_208[0] + -8) = 0;
            *(ulong *)(local_208[0] + -0x18) = uVar2;
            local_208[0][uVar2] = 0;
          }
          if (uVar29 == (int)uVar26 - 6) goto LAB_00112e83;
          cVar6 = *(char *)(**(long **)(*param_1 + 0x40) + 6 + uVar29);
          if ((cVar6 == '.') && (cVar33 == '.')) break;
          if (((cVar6 == '\r') || (cVar6 == ' ')) ||
             (uVar29 = uVar29 + 1, cVar33 = cVar6, cVar6 == '\n')) goto LAB_00112e83;
        }
        rea_std__string__assign((char *)local_208,0x11f6d0);
      }
LAB_00112e83:
      pcVar17 = rea_operator_new(0x18);
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
      local_190 = (code *)0x0;
      if ((code *)param_1[7] != (code *)0x0) {
        (*(code *)param_1[7])(&local_1a0,param_1 + 5,2);
        local_188 = param_1[8];
        local_190 = (code *)param_1[7];
      }
      lVar24 = *(long *)(*param_1 + 0x38);
      if (*(char *)(lVar24 + 0x5a) != '\0') {
        rea_fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
        rea_print_stack();
      }
      puVar18 = *(undefined8 **)(lVar24 + 0x60);
      *(undefined1 *)(lVar24 + 0x5a) = 1;
      *(char **)(lVar24 + 0x60) = pcVar17;
      if (puVar18 != (undefined8 *)0x0) {
        if ((void *)*puVar18 != (void *)0x0) {
          rea_operator_delete((void *)*puVar18);
        }
        rea_operator_delete(puVar18);
      }
      rea_std__string__string((string *)(auStack_13b + 3),&local_1a8);
      memset(auStack_120, 0, sizeof(auStack_120));
      if (local_190 != (code *)0x0) {
        (*local_190)(auStack_133 + 3,&local_1a0,2);
        local_118 = local_188;
        { auto &&__rea_tmp = ((arr_undefined1_8)local_190); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
      }
      local_1e8 = (code *)0x0;
      puVar18 = rea_operator_new(0x28);
      *puVar18 = stack0xfffffffffffffec8;
      unique0x00008e00 = puVar11 + 0x18;
      puVar18[3] = 0;
      if (auStack_120 != arr_undefined1_8{}) {
        (*(code *)auStack_120)(puVar18 + 1,auStack_133 + 3,2);
        puVar18[4] = local_118;
        puVar18[3] = auStack_120;
      }
      local_1f8 = *(undefined8 *)(lVar24 + 0x68);
      uVar7 = *(undefined8 *)(lVar24 + 0x70);
      local_1e8 = *(code **)(lVar24 + 0x78);
      *(undefined8 *)(lVar24 + 0x70) = local_1f0;
      *(undefined8 **)(lVar24 + 0x68) = puVar18;
      local_1e0 = *(undefined8 *)(lVar24 + 0x80);
      *(code **)(lVar24 + 0x78) = FUN_0010e040;
      *(code **)(lVar24 + 0x80) = FUN_0010dda0;
      local_1f0 = uVar7;
      if (local_1e8 != (code *)0x0) {
        (*local_1e8)(&local_1f8,&local_1f8,3);
      }
      if (auStack_120 != arr_undefined1_8{}) {
        (*(code *)auStack_120)(auStack_133 + 3,auStack_133 + 3,3);
      }
      if ((allocator *)(stack0xfffffffffffffec8 + -0x18) != (allocator *)puVar11) {
        piVar3 = (int *)(stack0xfffffffffffffec8 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      lVar24 = *(long *)(lVar24 + 0x38);
      p_Var36 = *(_Rb_tree_node_base **)(lVar24 + 0x18);
      p_Var21 = (_Rb_tree_node_base *)(lVar24 + 0x10);
      p_Var22 = p_Var36;
      p_Var30 = p_Var21;
      if (p_Var36 == (_Rb_tree_node_base *)0x0) {
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
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001130f2;
          }
          p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
          p_Var30 = p_Var25;
        } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001130f2:
        if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, local_218[0] < *(int *)(p_Var25 + 0x20)))
        goto LAB_00113e70;
        do {
          while (p_Var30 = p_Var36, *(int *)(p_Var30 + 0x20) < local_218[0]) {
            p_Var25 = p_Var30 + 0x18;
            p_Var36 = *(_Rb_tree_node_base **)p_Var25;
            p_Var30 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_0011312a;
          }
          p_Var36 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
          p_Var22 = p_Var30;
        } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011312a:
        if ((p_Var21 == p_Var30) || (local_218[0] < *(int *)(p_Var30 + 0x20))) {
          p_Var36 = rea_operator_new(0x28);
          if (p_Var36 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var36 = 0;
            *(undefined8 *)(p_Var36 + 8) = 0;
            *(undefined8 *)(p_Var36 + 0x10) = 0;
            *(undefined8 *)(p_Var36 + 0x18) = 0;
            *(undefined4 *)(p_Var36 + 0x24) = 0;
            *(int *)(p_Var36 + 0x20) = local_218[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos_______________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                *)(lVar24 + 8),p_Var30,p_Var36 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
          p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
          p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
          if (p_Var22 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var36);
          }
          else {
            bVar38 = true;
            if ((p_Var30 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var22)) {
              bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var22 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var22,p_Var21);
            *(long *)(lVar24 + 0x30) = *(long *)(lVar24 + 0x30) + 1;
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
      if (p_Var21 != (_Rb_tree_node_base *)0x0) {
        do {
          while (p_Var25 = p_Var36, *(int *)(p_Var25 + 0x20) < local_218[0]) {
            p_Var1 = p_Var25 + 0x18;
            p_Var36 = *(_Rb_tree_node_base **)p_Var1;
            p_Var25 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00113212;
          }
          p_Var36 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
          p_Var22 = p_Var25;
        } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113212:
        if ((p_Var30 != p_Var25) && (p_Var36 = p_Var30, *(int *)(p_Var25 + 0x20) <= local_218[0])) {
          do {
            while (p_Var22 = p_Var21, *(int *)(p_Var22 + 0x20) < local_218[0]) {
              p_Var25 = p_Var22 + 0x18;
              p_Var21 = *(_Rb_tree_node_base **)p_Var25;
              p_Var22 = p_Var36;
              if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_0011324a;
            }
            p_Var21 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
            p_Var36 = p_Var22;
          } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011324a:
          if ((p_Var30 == p_Var22) || (local_218[0] < *(int *)(p_Var22 + 0x20))) {
            p_Var21 = rea_operator_new(0x28);
            if (p_Var21 != (_Rb_tree_node_base *)0x0) {
              *(undefined4 *)p_Var21 = 0;
              *(undefined8 *)(p_Var21 + 8) = 0;
              *(undefined8 *)(p_Var21 + 0x10) = 0;
              *(undefined8 *)(p_Var21 + 0x18) = 0;
              *(undefined4 *)(p_Var21 + 0x24) = 0;
              *(int *)(p_Var21 + 0x20) = local_218[0];
            }
            { auto &&__rea_tmp = (std__________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________________M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
            p_Var36 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
            p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
            if (p_Var36 == (_Rb_tree_node_base *)0x0) {
              rea_operator_delete(p_Var21);
            }
            else {
              bVar38 = true;
              if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var30 != p_Var36)) {
                bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var36 + 0x20);
              }
              rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var36,p_Var30);
              *(long *)(lVar24 + 0x30) = *(long *)(lVar24 + 0x30) + 1;
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
      if (*(_Rb_tree_node_base **)(lVar24 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00113339:
        p_Var21 = rea_operator_new(0x28);
        if (p_Var21 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(int *)(p_Var21 + 0x20) = local_218[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var4,p_Var36,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
        p_Var36 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
        if (p_Var22 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var36 == (_Rb_tree_node_base *)0x0) && (p_Var30 != p_Var22)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var22 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var22,p_Var30);
          *(long *)(lVar24 + 0x30) = *(long *)(lVar24 + 0x30) + 1;
          p_Var36 = p_Var21;
        }
      }
      else {
        do {
          while (p_Var36 = p_Var21, *(int *)(p_Var36 + 0x20) < local_218[0]) {
            p_Var25 = p_Var36 + 0x18;
            p_Var21 = *(_Rb_tree_node_base **)p_Var25;
            p_Var36 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_0011332a;
          }
          p_Var21 = *(_Rb_tree_node_base **)(p_Var36 + 0x10);
          p_Var22 = p_Var36;
        } while (*(_Rb_tree_node_base **)(p_Var36 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011332a:
        if ((p_Var30 == p_Var36) || (local_218[0] < *(int *)(p_Var36 + 0x20))) goto LAB_00113339;
      }
      *(uint *)(p_Var36 + 0x24) = uVar34;
LAB_001133cf:
      if (local_190 != (code *)0x0) {
        (*local_190)(&local_1a0,&local_1a0,3);
      }
      lVar24 = CONCAT44(uStack_1a4,
                        CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8))));
      if ((allocator *)(lVar24 + -0x18) != (allocator *)puVar11) {
        piVar3 = (int *)(lVar24 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
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
  lVar24 = *(long *)(*param_1 + 0x38);
  if (*(char *)(lVar24 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar24 + 0x88) = 1;
  memset(local_128, 0, sizeof(local_128));
  plVar16 = rea_operator_new(8);
  *plVar16 = lVar24;
  puVar11 = PTR__M_manager_00324f68;
  unique0x00023d00 = *(undefined **)(lVar24 + 0x90);
  uVar7 = *(undefined8 *)(lVar24 + 0x98);
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0xa0)); memcpy(local_128, &__rea_tmp, sizeof(local_128)); }
  *(long **)(lVar24 + 0x90) = plVar16;
  *(undefined8 *)(lVar24 + 0x98) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0xa0) = puVar11;
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0xa8)); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
  *(undefined **)(lVar24 + 0xa8) = PTR__M_invoke_00324f40;
  unique0x10001b43 = uVar7;
  if (local_128 != arr_undefined1_8{}) {
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  lVar35 = *(long *)(lVar24 + 0x38);
  iVar12 = *(int *)(lVar24 + 0x40);
  cVar33 = *(char *)(lVar24 + 0x88);
  p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  local_1f8 = CONCAT44((*(undefined4 *)((uint8_t *)&local_1f8 + 0x4)),iVar12);
  p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  p_Var22 = p_Var36;
  p_Var30 = p_Var21;
  if (p_Var36 == (_Rb_tree_node_base *)0x0) {
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
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00112d2b;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
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
    } while (p_Var30 != (_Rb_tree_node_base *)0x0);
    if ((p_Var21 == p_Var22) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
      p_Var36 = rea_operator_new(0x28);
      if (p_Var36 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var36 = 0;
        *(undefined8 *)(p_Var36 + 8) = 0;
        *(undefined8 *)(p_Var36 + 0x10) = 0;
        *(undefined8 *)(p_Var36 + 0x18) = 0;
        *(undefined4 *)(p_Var36 + 0x24) = 0;
        *(int *)(p_Var36 + 0x20) = (int)local_1f8;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar35 + 8),p_Var22,p_Var36 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
      p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
      p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
      if (p_Var30 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var36);
      }
      else {
        bVar38 = true;
        if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var30)) {
          bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var30,p_Var21);
        *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
  if (p_Var21 != (_Rb_tree_node_base *)0x0) {
    p_Var22 = p_Var21;
    p_Var30 = p_Var36;
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < (int)local_1f8) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011402b;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
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
      } while (p_Var30 != (_Rb_tree_node_base *)0x0);
      if ((p_Var36 == p_Var22) || ((int)local_1f8 < *(int *)(p_Var22 + 0x20))) {
        p_Var21 = rea_operator_new(0x28);
        if (p_Var21 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(int *)(p_Var21 + 0x20) = (int)local_1f8;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
        p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
        if (p_Var30 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var30 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var30,p_Var36);
          *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
    if (*(_Rb_tree_node_base **)(lVar35 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0011434f:
      p_Var22 = rea_operator_new(0x28);
      if (p_Var22 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var22 = 0;
        *(undefined8 *)(p_Var22 + 8) = 0;
        *(undefined8 *)(p_Var22 + 0x10) = 0;
        *(undefined8 *)(p_Var22 + 0x18) = 0;
        *(undefined4 *)(p_Var22 + 0x24) = 0;
        *(int *)(p_Var22 + 0x20) = (int)local_1f8;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
      p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
      p_Var21 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
      if (p_Var30 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var22);
      }
      else {
        bVar38 = true;
        if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
          bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
        *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
      } while (p_Var30 != (_Rb_tree_node_base *)0x0);
      if ((p_Var36 == p_Var21) || ((int)local_1f8 < *(int *)(p_Var21 + 0x20))) goto LAB_0011434f;
    }
    *(uint *)(p_Var21 + 0x24) = uVar34;
  }
  if (*(char *)(lVar24 + 0x5a) != '\0') {
    rea_fwrite("close(): send_flag != false\n",1,0x1c,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar18 = *(undefined8 **)(lVar24 + 0x60);
  *(undefined1 *)(lVar24 + 0x5a) = 1;
  *(undefined8 *)(lVar24 + 0x60) = 0;
  if (puVar18 != (undefined8 *)0x0) {
    if ((void *)*puVar18 != (void *)0x0) {
      rea_operator_delete((void *)*puVar18);
    }
    rea_operator_delete(puVar18);
  }
  memset(local_128, 0, sizeof(local_128));
  pvVar15 = rea_operator_new(1);
  puVar11 = PTR__M_manager_00324f78;
  unique0x00023d00 = *(undefined **)(lVar24 + 0x68);
  uVar7 = *(undefined8 *)(lVar24 + 0x70);
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0x78)); memcpy(local_128, &__rea_tmp, sizeof(local_128)); }
  *(void **)(lVar24 + 0x68) = pvVar15;
  *(undefined8 *)(lVar24 + 0x70) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0x78) = puVar11;
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0x80)); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
  *(undefined **)(lVar24 + 0x80) = PTR__M_invoke_00324fe8;
  unique0x10001b3b = uVar7;
  if (local_128 != arr_undefined1_8{}) {
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  lVar35 = *(long *)(lVar24 + 0x38);
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
  if (p_Var36 == (_Rb_tree_node_base *)0x0) {
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
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00114313;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
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
    } while (p_Var30 != (_Rb_tree_node_base *)0x0);
    if ((p_Var22 == p_Var21) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
      p_Var36 = rea_operator_new(0x28);
      if (p_Var36 != (_Rb_tree_node_base *)0x0) {
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
      p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
      p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
      if (p_Var30 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var36);
      }
      else {
        bVar38 = true;
        if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var30)) {
          bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var30,p_Var21);
        *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
  if (p_Var21 != (_Rb_tree_node_base *)0x0) {
    iVar12 = CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    p_Var22 = p_Var21;
    p_Var30 = p_Var36;
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00114443;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
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
      } while (p_Var30 != (_Rb_tree_node_base *)0x0);
      if ((p_Var22 == p_Var36) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
        p_Var21 = rea_operator_new(0x28);
        if (p_Var21 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(uint *)(p_Var21 + 0x20) =
               CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
        p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
        if (p_Var30 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var30 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var30,p_Var36);
          *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
  if (*(_Rb_tree_node_base **)(lVar35 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_001146c4:
    p_Var22 = rea_operator_new(0x28);
    if (p_Var22 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var22 = 0;
      *(undefined8 *)(p_Var22 + 8) = 0;
      *(undefined8 *)(p_Var22 + 0x10) = 0;
      *(undefined8 *)(p_Var22 + 0x18) = 0;
      *(undefined4 *)(p_Var22 + 0x24) = 0;
      *(uint *)(p_Var22 + 0x20) =
           CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
    p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
    p_Var21 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
    if (p_Var30 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var22);
    }
    else {
      bVar38 = true;
      if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
        bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
      *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
    } while (p_Var30 != (_Rb_tree_node_base *)0x0);
    if ((p_Var21 == p_Var36) || (iVar12 < *(int *)(p_Var21 + 0x20))) goto LAB_001146c4;
  }
  *(uint *)(p_Var21 + 0x24) = uVar34;
LAB_0011460d:
  memset(local_128, 0, sizeof(local_128));
  pvVar15 = rea_operator_new(1);
  puVar11 = PTR__M_manager_00324f58;
  unique0x00023d00 = *(undefined **)(lVar24 + 0xb0);
  uVar7 = *(undefined8 *)(lVar24 + 0xb8);
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 0xc0)); memcpy(local_128, &__rea_tmp, sizeof(local_128)); }
  *(void **)(lVar24 + 0xb0) = pvVar15;
  *(undefined8 *)(lVar24 + 0xb8) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0xc0) = puVar11;
  { auto &&__rea_tmp = (*(undefined1 (*) [8])(lVar24 + 200)); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
  *(undefined **)(lVar24 + 200) = PTR__M_invoke_00324eb0;
  if (local_128 != arr_undefined1_8{}) {
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
    pvVar19 = rea_memmem(pvVar15,puVar18[1] - (long)pvVar15,"permessage-deflate",0x12);
    if (pvVar19 != (void *)0x0) {
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
    pvVar19 = (void *)((long)(param_2 + 4) + (long)pvVar15);
    if (pvVar19 != pvVar15) {
      lVar24 = 0;
      if ((pvVar19 != (void *)puVar18[1]) && (__n = (long)puVar18[1] - (long)pvVar19, __n != 0)) {
        pvVar15 = rea_memmove(pvVar15,pvVar19,__n);
        lVar24 = puVar18[1] - (long)pvVar19;
      }
      puVar18[1] = lVar24 + (long)pvVar15;
    }
    pcVar17 = rea_operator_new(0x18);
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
    lVar24 = *(long *)(*param_1 + 0x38);
    if (*(char *)(lVar24 + 0x5a) != '\0') {
      rea_fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
      rea_print_stack();
    }
    puVar18 = *(undefined8 **)(lVar24 + 0x60);
    *(undefined1 *)(lVar24 + 0x5a) = 1;
    *(char **)(lVar24 + 0x60) = pcVar17;
    if (puVar18 != (undefined8 *)0x0) {
      if ((void *)*puVar18 != (void *)0x0) {
        rea_operator_delete((void *)*puVar18);
      }
      rea_operator_delete(puVar18);
    }
    memset(local_128, 0, sizeof(local_128));
    if ((code *)param_1[3] == (code *)0x0) {
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
    *(undefined **)(lVar24 + 0x68) = stack0xfffffffffffffec8;
    *(undefined8 *)(lVar24 + 0x70) = stack0xfffffffffffffed0;
    uVar10 = *(undefined8 *)(lVar24 + 0x80);
    *(long *)(lVar24 + 0x78) = lVar35;
    *(undefined1 (*) [8])(lVar24 + 0x80) = auStack_120;
    unique0x10001b0b = (undefined *)uVar7;
    unique0x10001b33 = uVar9;
    { auto &&__rea_tmp = ((arr_undefined1_8)uVar10); memcpy(auStack_120, &__rea_tmp, sizeof(auStack_120)); }
    if (local_128 != arr_undefined1_8{}) {
      (*(code *)local_128)(puVar5,puVar5,3);
    }
    lVar35 = *(long *)(lVar24 + 0x38);
    iVar12 = *(int *)(lVar24 + 0x40);
    cVar33 = *(char *)(lVar24 + 0x5a);
    p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
    stack0xfffffffffffffec8 = (undefined *)CONCAT44(stack0xfffffffffffffecc,iVar12);
    p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
    p_Var22 = p_Var36;
    p_Var30 = p_Var21;
    if (p_Var36 == (_Rb_tree_node_base *)0x0) {
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
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00113b4b;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
        p_Var30 = p_Var25;
      } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113b4b:
      if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, iVar12 < *(int *)(p_Var25 + 0x20)))
      goto LAB_00113e40;
      do {
        while (p_Var30 = p_Var36, *(int *)(p_Var30 + 0x20) < iVar12) {
          p_Var25 = p_Var30 + 0x18;
          p_Var36 = *(_Rb_tree_node_base **)p_Var25;
          p_Var30 = p_Var22;
          if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_00113b83;
        }
        p_Var36 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
        p_Var22 = p_Var30;
      } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113b83:
      if ((p_Var21 == p_Var30) || (iVar12 < *(int *)(p_Var30 + 0x20))) {
        p_Var36 = rea_operator_new(0x28);
        if (p_Var36 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var36 = 0;
          *(undefined8 *)(p_Var36 + 8) = 0;
          *(undefined8 *)(p_Var36 + 0x10) = 0;
          *(undefined8 *)(p_Var36 + 0x18) = 0;
          *(undefined4 *)(p_Var36 + 0x24) = 0;
          *(undefined4 *)(p_Var36 + 0x20) = (*(undefined4 *)((uint8_t *)&auStack_13b + 0x3));
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar35 + 8),p_Var30,p_Var36 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
        p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
        p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
        if (p_Var22 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var36);
        }
        else {
          bVar38 = true;
          if ((p_Var30 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var22)) {
            bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var22 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var22,p_Var21);
          *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
    if (p_Var21 != (_Rb_tree_node_base *)0x0) {
      p_Var22 = p_Var21;
      p_Var30 = p_Var36;
      do {
        while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))) {
          p_Var1 = p_Var25 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var1;
          p_Var25 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00113c6b;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
        p_Var30 = p_Var25;
      } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113c6b:
      if ((p_Var36 != p_Var25) &&
         (p_Var22 = p_Var36, *(int *)(p_Var25 + 0x20) <= (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3)))) {
        do {
          while (p_Var30 = p_Var21, *(int *)(p_Var30 + 0x20) < (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))) {
            p_Var25 = p_Var30 + 0x18;
            p_Var21 = *(_Rb_tree_node_base **)p_Var25;
            p_Var30 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_00113ca3;
          }
          p_Var21 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
          p_Var22 = p_Var30;
        } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113ca3:
        if ((p_Var36 == p_Var30) || ((int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3)) < *(int *)(p_Var30 + 0x20))) {
          p_Var21 = rea_operator_new(0x28);
          if (p_Var21 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var21 = 0;
            *(undefined8 *)(p_Var21 + 8) = 0;
            *(undefined8 *)(p_Var21 + 0x10) = 0;
            *(undefined8 *)(p_Var21 + 0x18) = 0;
            *(undefined4 *)(p_Var21 + 0x24) = 0;
            *(undefined4 *)(p_Var21 + 0x20) = (*(undefined4 *)((uint8_t *)&auStack_13b + 0x3));
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var4,p_Var30,p_Var21 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
          p_Var22 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
          p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
          if (p_Var22 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var21);
          }
          else {
            bVar38 = true;
            if ((p_Var30 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var22)) {
              bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var22 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var22,p_Var36);
            *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
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
    if (*(_Rb_tree_node_base **)(lVar35 + 0x18) != (_Rb_tree_node_base *)0x0) {
      p_Var22 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
      p_Var30 = p_Var36;
      do {
        while (p_Var21 = p_Var22, *(int *)(p_Var21 + 0x20) < (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))) {
          p_Var25 = p_Var21 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var25;
          p_Var21 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_00113d82;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
        p_Var30 = p_Var21;
      } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113d82:
      if ((p_Var36 != p_Var21) && (*(int *)(p_Var21 + 0x20) <= (int)(*(undefined4 *)((uint8_t *)&auStack_13b + 0x3))))
      goto LAB_00113e28;
    }
    p_Var22 = rea_operator_new(0x28);
    if (p_Var22 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var22 = 0;
      *(undefined8 *)(p_Var22 + 8) = 0;
      *(undefined8 *)(p_Var22 + 0x10) = 0;
      *(undefined8 *)(p_Var22 + 0x18) = 0;
      *(undefined4 *)(p_Var22 + 0x24) = 0;
      *(undefined4 *)(p_Var22 + 0x20) = (*(undefined4 *)((uint8_t *)&auStack_13b + 0x3));
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20)); memcpy(auVar40, &__rea_tmp, sizeof(auVar40)); }
    p_Var30 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x8));
    p_Var21 = (*(undefined8 *)((uint8_t *)&auVar40 + 0x0));
    if (p_Var30 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var22);
    }
    else {
      bVar38 = true;
      if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
        bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
      *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
      p_Var21 = p_Var22;
    }
LAB_00113e28:
    *(uint *)(p_Var21 + 0x24) = uVar34;
    return;
  }
  goto LAB_00112bf9;
}





// ------------------------------------------------------------------
// IDX 233  00114d00  WSConn__send
// ------------------------------------------------------------------
void rea_WSConn__send__dup2(WSConn * this_ptr, long * param_2, long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  void *pvVar17;
  void *pvVar18;
  ulong uVar19;
  undefined8 uVar20;
  _Rb_tree_node_base *p_Var21;
  _Rb_tree_node_base *p_Var22;
  ulong uVar23;
  bool bVar24;
  long lVar25;
  _Rb_tree_node_base *p_Var26;
  uint uVar27;
  undefined1 auVar28 [16];
  ulong local_68;
  void *local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 uStack_40;
  
  puVar10 = rea_operator_new(0x18);
  *puVar10 = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar3 = *(undefined8 **)(this_ptr + 0x50);
  *(undefined8 **)(this_ptr + 0x50) = puVar10;
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  if (this_ptr[0x58] == (WSConn)0x0) {
    local_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_58 + 0x1)),0x81);
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&local_58);
    plVar11 = (long *)*param_2;
LAB_0011525a:
    uVar12 = plVar11[1] - *plVar11;
  }
  else {
    puVar3 = *(undefined8 **)(this_ptr + 0x68);
    uVar20 = *(undefined8 *)*param_2;
    uVar4 = ((undefined8 *)*param_2)[1];
    *puVar3 = uVar20;
    *(int *)(puVar3 + 1) = (int)uVar4 - (int)uVar20;
    plVar11 = rea_operator_new(0x18);
    *plVar11 = 0;
    plVar11[1] = 0;
    plVar11[2] = 0;
    uVar12 = rea_deflateBound(*(undefined8 *)(this_ptr + 0x68));
    pvVar17 = (void *)plVar11[1];
    pvVar18 = (void *)*plVar11;
    uVar23 = (long)pvVar17 - (long)pvVar18;
    if (uVar23 < uVar12) {
      uVar12 = uVar12 - uVar23;
      if (uVar12 != 0) {
        if ((ulong)(plVar11[2] - (long)pvVar17) < uVar12) {
          if (uVar12 <= ~uVar23) {
            uVar13 = uVar23;
            if (uVar23 <= uVar12) {
              uVar13 = uVar12;
            }
            uVar19 = 0xffffffffffffffff;
            if (CARRY8(uVar13,uVar23)) goto LAB_00115465;
            uVar19 = uVar13 + uVar23;
            if (uVar13 + uVar23 != 0) goto LAB_00115465;
            local_60 = (void *)0x0;
            uVar19 = 0;
            pvVar17 = pvVar18;
            goto LAB_00115483;
          }
          uVar20 = rea_std____throw_length_error("vector___M_default_append");
          rea_FUN_00107772(plVar11);
                    /* WARNING: Subroutine does not return */
          rea__Unwind_Resume(uVar20);
        }
        rea_memset(pvVar17,0,uVar12);
        lVar14 = plVar11[1];
        pvVar18 = (void *)*plVar11;
        plVar11[1] = uVar12 + lVar14;
        uVar23 = (uVar12 + lVar14) - (long)pvVar18;
      }
    }
    else if (uVar12 < uVar23) {
      plVar11[1] = (long)pvVar18 + uVar12;
      uVar23 = ((long)pvVar18 + uVar12) - (long)pvVar18;
    }
    while( true ) {
      lVar14 = *(long *)(this_ptr + 0x68);
      *(int *)(lVar14 + 0x20) = (int)uVar23;
      *(void **)(lVar14 + 0x18) = pvVar18;
      iVar8 = rea_deflate();
      if (iVar8 != 0) break;
      pvVar17 = (void *)plVar11[1];
      pvVar18 = (void *)*plVar11;
      uVar13 = (long)pvVar17 - (long)pvVar18;
      uVar12 = -(ulong)*(uint *)(*(long *)(this_ptr + 0x68) + 0x20) - 4;
      uVar23 = uVar13 + uVar12;
      if (uVar23 <= uVar13) {
        if (uVar23 < uVar13) {
          plVar11[1] = uVar23 + (long)pvVar18;
        }
        break;
      }
      if (uVar12 <= (ulong)(plVar11[2] - (long)pvVar17)) {
        rea_memset(pvVar17,0,uVar12);
        plVar11[1] = plVar11[1] + uVar12;
        break;
      }
      if (uVar12 <= ~uVar13) {
        local_68 = 0xffffffffffffffff;
        uVar23 = uVar12;
        if (uVar12 <= uVar13) {
          uVar23 = uVar13;
        }
        if ((CARRY8(uVar23,uVar13)) || (local_68 = uVar23 + uVar13, uVar23 + uVar13 != 0)) {
          pvVar17 = rea_operator_new(local_68);
          pvVar18 = (void *)*plVar11;
          uVar13 = plVar11[1] - (long)pvVar18;
        }
        else {
          local_68 = 0;
          pvVar17 = (void *)0x0;
        }
        if (uVar13 != 0) {
          rea_memmove(pvVar17,pvVar18,uVar13);
        }
        pvVar18 = (void *)((long)pvVar17 + uVar13);
        rea_memset(pvVar18,0,(uVar12 + (long)pvVar18) - (long)pvVar18);
        if ((void *)*plVar11 != (void *)0x0) {
          rea_operator_delete((void *)*plVar11);
        }
        *plVar11 = (long)pvVar17;
        plVar11[1] = uVar12 + (long)pvVar18;
        plVar11[2] = (long)pvVar17 + local_68;
        break;
      }
      uVar19 = rea_std____throw_length_error("vector___M_default_append");
LAB_00115465:
      local_60 = rea_operator_new(uVar19);
      uVar23 = plVar11[1] - *plVar11;
      pvVar17 = (void *)*plVar11;
LAB_00115483:
      pvVar18 = local_60;
      if (uVar23 != 0) {
        pvVar18 = rea_memmove(local_60,pvVar17,uVar23);
      }
      pvVar17 = (void *)((long)pvVar18 + uVar23);
      lVar14 = uVar12 + (long)pvVar17;
      rea_memset(pvVar17,0,lVar14 - (long)pvVar17);
      if ((void *)*plVar11 != (void *)0x0) {
        rea_operator_delete((void *)*plVar11);
      }
      *plVar11 = (long)pvVar18;
      plVar11[1] = lVar14;
      plVar11[2] = uVar19 + (long)pvVar18;
      uVar23 = lVar14 - (long)local_60;
    }
    local_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_58 + 0x1)),0xc1);
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&local_58);
    puVar3 = (undefined8 *)*param_2;
    *param_2 = (long)plVar11;
    if (puVar3 == (undefined8 *)0x0) goto LAB_0011525a;
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
    uVar12 = ((long *)*param_2)[1] - *(long *)*param_2;
  }
  if (0x7d < uVar12) {
    (*(arr_undefined1_7 *)((uint8_t *)&local_58 + 0x1)) = (undefined7)((ulong)local_58 >> 8);
    if (uVar12 < 0xffff) {
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = '~';
    }
    else {
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = '\x7f';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&local_58);
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&local_58);
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&local_58);
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&local_58);
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = '\0';
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&local_58);
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = (uchar)(uVar12 >> 0x18);
      rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
                (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
                 (uchar *)&local_58);
      (*(undefined1 *)((uint8_t *)&local_58 + 0x0)) = (uchar)(uVar12 >> 0x10);
    }
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&local_58);
    local_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_58 + 0x1)),(char)(uVar12 >> 8));
    rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
              (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
               (uchar *)&local_58);
  }
  local_58 = CONCAT71((*(arr_undefined1_7 *)((uint8_t *)&local_58 + 0x1)),(char)uVar12);
  rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
            (*(vector_unsigned_char_std__allocator_unsigned_char **)(this_ptr + 0x50),
             (uchar *)&local_58);
  std__vector_unsigned_char_std__allocator_unsigned_char______M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char_____________(*(long *)(this_ptr + 0x50),*(undefined8 *)(*(long *)(this_ptr + 0x50) + 8),*(long *)*param_2,
             *(long *)*param_2 + uVar12);
  uVar20 = *(undefined8 *)(this_ptr + 0x50);
  *(undefined8 *)(this_ptr + 0x50) = 0;
  lVar14 = *(long *)(this_ptr + 0x38);
  if (*(char *)(lVar14 + 0x5a) != '\0') {
    rea_fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  puVar3 = *(undefined8 **)(lVar14 + 0x60);
  *(undefined1 *)(lVar14 + 0x5a) = 1;
  *(undefined8 *)(lVar14 + 0x60) = uVar20;
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  local_48 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) == (code *)0x0) {
    uVar20 = 0;
  }
  else {
    (**(code **)(param_3 + 0x10))(&local_58,param_3,2);
    uStack_40 = *(undefined8 *)(param_3 + 0x18);
    uVar20 = *(undefined8 *)(param_3 + 0x10);
  }
  uVar4 = *(undefined8 *)(lVar14 + 0x68);
  uVar5 = *(undefined8 *)(lVar14 + 0x70);
  local_48 = *(code **)(lVar14 + 0x78);
  *(undefined8 *)(lVar14 + 0x68) = local_58;
  *(undefined8 *)(lVar14 + 0x70) = local_50;
  uVar6 = *(undefined8 *)(lVar14 + 0x80);
  *(undefined8 *)(lVar14 + 0x78) = uVar20;
  *(undefined8 *)(lVar14 + 0x80) = uStack_40;
  local_58 = uVar4;
  local_50 = uVar5;
  uStack_40 = uVar6;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  lVar25 = *(long *)(lVar14 + 0x38);
  iVar8 = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x5a);
  p_Var26 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  local_58 = CONCAT44((*(undefined4 *)((uint8_t *)&local_58 + 0x4)),iVar8);
  p_Var15 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  p_Var16 = p_Var26;
  p_Var21 = p_Var15;
  if (p_Var26 == (_Rb_tree_node_base *)0x0) {
LAB_001153b0:
    lVar14 = 0;
    uVar27 = 0;
  }
  else {
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < iVar8) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00114fcb;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00114fcb:
    if ((p_Var15 == p_Var22) || (p_Var16 = p_Var15, iVar8 < *(int *)(p_Var22 + 0x20)))
    goto LAB_001153b0;
    do {
      while (p_Var21 = p_Var26, *(int *)(p_Var21 + 0x20) < iVar8) {
        p_Var22 = p_Var21 + 0x18;
        p_Var26 = *(_Rb_tree_node_base **)p_Var22;
        p_Var21 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_00115003;
      }
      p_Var26 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
      p_Var16 = p_Var21;
    } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115003:
    if ((p_Var15 == p_Var21) || (iVar8 < *(int *)(p_Var21 + 0x20))) {
      p_Var26 = rea_operator_new(0x28);
      if (p_Var26 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var26 = 0;
        *(undefined8 *)(p_Var26 + 8) = 0;
        *(undefined8 *)(p_Var26 + 0x10) = 0;
        *(undefined8 *)(p_Var26 + 0x18) = 0;
        *(undefined4 *)(p_Var26 + 0x24) = 0;
        *(int *)(p_Var26 + 0x20) = (int)local_58;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar25 + 8),p_Var21,p_Var26 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x8));
      p_Var21 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x0));
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var26);
      }
      else {
        bVar24 = true;
        if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var16)) {
          bVar24 = *(int *)(p_Var26 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var26,p_Var16,p_Var15);
        *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
        p_Var21 = p_Var26;
      }
    }
    uVar27 = *(uint *)(p_Var21 + 0x24);
    lVar14 = 1;
  }
  lVar25 = lVar25 + (lVar14 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar25 + 8);
  p_Var15 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  p_Var26 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  uVar9 = uVar27;
  if (p_Var15 != (_Rb_tree_node_base *)0x0) {
    p_Var16 = p_Var15;
    p_Var21 = p_Var26;
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < (int)local_58) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115073;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115073:
    if ((p_Var26 != p_Var22) && (p_Var16 = p_Var26, *(int *)(p_Var22 + 0x20) <= (int)local_58)) {
      do {
        while (p_Var21 = p_Var15, *(int *)(p_Var21 + 0x20) < (int)local_58) {
          p_Var22 = p_Var21 + 0x18;
          p_Var15 = *(_Rb_tree_node_base **)p_Var22;
          p_Var21 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_001150ab;
        }
        p_Var15 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
        p_Var16 = p_Var21;
      } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001150ab:
      if ((p_Var26 == p_Var21) || ((int)local_58 < *(int *)(p_Var21 + 0x20))) {
        p_Var15 = rea_operator_new(0x28);
        if (p_Var15 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var15 = 0;
          *(undefined8 *)(p_Var15 + 8) = 0;
          *(undefined8 *)(p_Var15 + 0x10) = 0;
          *(undefined8 *)(p_Var15 + 0x18) = 0;
          *(undefined4 *)(p_Var15 + 0x24) = 0;
          *(int *)(p_Var15 + 0x20) = (int)local_58;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var21,p_Var15 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x8));
        p_Var21 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x0));
        if (p_Var16 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var15);
        }
        else {
          bVar24 = true;
          if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var26 != p_Var16)) {
            bVar24 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var16 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var15,p_Var16,p_Var26);
          *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
          p_Var21 = p_Var15;
        }
      }
      uVar9 = *(uint *)(p_Var21 + 0x24);
    }
  }
  uVar7 = uVar9 | 2;
  if (cVar2 == '\0') {
    uVar7 = uVar9 & 0xfffffffd;
  }
  if (uVar27 == uVar7) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,(int *)&local_58);
    return;
  }
  p_Var15 = p_Var26;
  if (*(_Rb_tree_node_base **)(lVar25 + 0x18) != (_Rb_tree_node_base *)0x0) {
    p_Var16 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
    p_Var21 = p_Var26;
    do {
      while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < (int)local_58) {
        p_Var22 = p_Var15 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var22;
        p_Var15 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_00115182;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var21 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115182:
    if ((p_Var26 != p_Var15) && (*(int *)(p_Var15 + 0x20) <= (int)local_58)) goto LAB_00115225;
  }
  p_Var16 = rea_operator_new(0x28);
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var16 = 0;
    *(undefined8 *)(p_Var16 + 8) = 0;
    *(undefined8 *)(p_Var16 + 0x10) = 0;
    *(undefined8 *)(p_Var16 + 0x18) = 0;
    *(undefined4 *)(p_Var16 + 0x24) = 0;
    *(int *)(p_Var16 + 0x20) = (int)local_58;
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var16 + 0x20)); memcpy(auVar28, &__rea_tmp, sizeof(auVar28)); }
  p_Var21 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x8));
  p_Var15 = (*(undefined8 *)((uint8_t *)&auVar28 + 0x0));
  if (p_Var21 == (_Rb_tree_node_base *)0x0) {
    rea_operator_delete(p_Var16);
  }
  else {
    bVar24 = true;
    if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var26 != p_Var21)) {
      bVar24 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var21 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar24,p_Var16,p_Var21,p_Var26);
    *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
    p_Var15 = p_Var16;
  }
LAB_00115225:
  *(uint *)(p_Var15 + 0x24) = uVar7;
  return;
}





// ------------------------------------------------------------------
// IDX 234  00115740  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void__dup3(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 235  00115750  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void__dup4(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 236  00115760  std___Function_base___Base_manager_TcpConn__discard___M_manager___________
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager_TcpConn__discard___M_manager(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324eb8;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = rea_operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 237  001157e0  std___Function_base___Base_manager_TcpConn__exit__lambda__1___M_manager___________
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager_TcpConn__exit__lambda__1___M_manager(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324ee8;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = rea_operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 238  00115850  std___Function_base___Base_manager_TcpConn__exit__lambda__2___M_manager___________
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager_TcpConn__exit__lambda__2___M_manager(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324fc8;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = rea_operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 239  001158c0  Buffer__appendf
// ------------------------------------------------------------------
void rea_Buffer__appendf__dup2(char * param_1, undefined8 param_x1)
{
  undefined8 stack0x00000008;
  int iVar1;
  char in_AL;
  int iVar2;
  void *pvVar3;
  undefined8 in_RCX;
  undefined8 in_RDX;
  ulong uVar4;
  ulong extraout_RDX;
  size_t __n;
  ulong uVar5;
  char *in_RSI;
  void *pvVar6;
  undefined8 in_R8;
  undefined8 in_R9;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  void *local_128;
  ulong local_120;
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 *local_f8;
  undefined1 *local_f0;
  undefined1 local_e8 [16];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  
  if (in_AL != '\0') {
    local_b8 = in_XMM0_Qa;
    local_a8 = in_XMM1_Qa;
    local_98 = in_XMM2_Qa;
    local_88 = in_XMM3_Qa;
    local_78 = in_XMM4_Qa;
    local_68 = in_XMM5_Qa;
    local_58 = in_XMM6_Qa;
    local_48 = in_XMM7_Qa;
  }
  local_f8 = (void *)&stack0x00000008;
  local_f0 = local_e8;
  local_100 = 0x10;
  local_fc = 0x30;
  local_d8 = in_RDX;
  local_d0 = in_RCX;
  local_c8 = in_R8;
  local_c0 = in_R9;
  iVar2 = rea_vsnprintf((char *)0x0,0,in_RSI,&local_100);
  pvVar3 = *(void **)(param_1 + 8);
  pvVar6 = *(void **)param_1;
  __n = (long)pvVar3 - (long)pvVar6;
  iVar1 = (int)__n;
  uVar7 = iVar2 + iVar1;
  uVar8 = (ulong)uVar7;
  uVar9 = (ulong)(int)(uVar7 + 1);
  if (__n < uVar9) {
    uVar9 = uVar9 - __n;
    if (uVar9 == 0) goto LAB_00115994;
    if (uVar9 <= (ulong)(*(long *)(param_1 + 0x10) - (long)pvVar3)) {
      rea_memset(pvVar3,0,uVar9);
      *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + uVar9;
      goto LAB_00115994;
    }
    if (uVar9 <= ~__n) {
      local_120 = 0xffffffffffffffff;
      uVar8 = __n;
      if (__n <= uVar9) {
        uVar8 = uVar9;
      }
      if ((CARRY8(uVar8,__n)) || (local_120 = uVar8 + __n, uVar8 + __n != 0)) {
        local_128 = rea_operator_new(local_120);
        pvVar6 = *(void **)param_1;
        __n = *(long *)(param_1 + 8) - (long)pvVar6;
      }
      else {
        local_120 = 0;
        local_128 = (void *)0x0;
      }
      if (__n != 0) {
        rea_memmove(local_128,pvVar6,__n);
      }
      pvVar3 = (void *)((long)local_128 + __n);
      rea_memset(pvVar3,0,(uVar9 + (long)pvVar3) - (long)pvVar3);
      if (*(void **)param_1 != (void *)0x0) {
        rea_operator_delete(*(void **)param_1);
      }
      *(ulong *)(param_1 + 8) = uVar9 + (long)pvVar3;
      *(void **)param_1 = local_128;
      *(ulong *)(param_1 + 0x10) = (long)local_128 + local_120;
      goto LAB_00115994;
    }
LAB_00115c22:
    rea_std____throw_length_error("vector___M_default_append");
    uVar5 = extraout_RDX;
  }
  else {
    if (uVar9 < __n) {
      *(ulong *)(param_1 + 8) = uVar9 + (long)pvVar6;
    }
LAB_00115994:
    local_f8 = (void *)&stack0x00000008;
    local_100 = 0x10;
    local_f0 = local_e8;
    local_fc = 0x30;
    uVar8 = (ulong)(int)uVar7;
    rea_vsnprintf((char *)((long)iVar1 + *(long *)param_1),(long)(iVar2 + 1),in_RSI,&local_100);
    pvVar3 = *(void **)(param_1 + 8);
    pvVar6 = *(void **)param_1;
    uVar9 = (long)pvVar3 - (long)pvVar6;
    if (uVar8 <= uVar9) {
      if (uVar9 <= uVar8) {
        return;
      }
      *(ulong *)(param_1 + 8) = uVar8 + (long)pvVar6;
      return;
    }
    uVar8 = uVar8 - uVar9;
    if (uVar8 == 0) {
      return;
    }
    if (uVar8 <= (ulong)(*(long *)(param_1 + 0x10) - (long)pvVar3)) {
      rea_memset(pvVar3,0,uVar8);
      *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + uVar8;
      return;
    }
    if (~uVar9 < uVar8) goto LAB_00115c22;
    uVar4 = uVar9;
    if (uVar9 <= uVar8) {
      uVar4 = uVar8;
    }
    uVar5 = 0xffffffffffffffff;
    if ((!CARRY8(uVar4,uVar9)) && (uVar5 = uVar4 + uVar9, uVar4 + uVar9 == 0)) {
      uVar5 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_00115a5e;
    }
  }
  pvVar3 = rea_operator_new(uVar5);
  pvVar6 = *(void **)param_1;
  uVar9 = *(long *)(param_1 + 8) - (long)pvVar6;
LAB_00115a5e:
  if (uVar9 != 0) {
    rea_memmove(pvVar3,pvVar6,uVar9);
  }
  pvVar6 = (void *)((long)pvVar3 + uVar9);
  rea_memset(pvVar6,0,(uVar8 + (long)pvVar6) - (long)pvVar6);
  if (*(void **)param_1 != (void *)0x0) {
    rea_operator_delete(*(void **)param_1);
  }
  *(void **)param_1 = pvVar3;
  *(ulong *)(param_1 + 8) = uVar8 + (long)pvVar6;
  *(ulong *)(param_1 + 0x10) = uVar5 + (long)pvVar3;
  return;
}





// ------------------------------------------------------------------
// IDX 240  00115c40  std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char__emplace_back_unsigned_char__dup2(vector_unsigned_char_std__allocator_unsigned_char * this_ptr, uchar * param_1)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  char cVar2;
  uchar *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  uint uVar7;
  ulong uVar8;
  void *__dest;
  size_t __n;
  long *plVar9;
  _Rb_tree_node_base *p_Var10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  void *__src;
  char *pcVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  undefined1 auVar22 [16];
  int aiStack_a0 [4];
  undefined8 uStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined8 uStack_78;
  vector_unsigned_char_std__allocator_unsigned_char *pvStack_68;
  
  puVar3 = *(uchar **)(this_ptr + 8);
  if (puVar3 != *(uchar **)(this_ptr + 0x10)) {
    if (puVar3 == (uchar *)0x0) {
      lVar13 = 0;
    }
    else {
      *puVar3 = *param_1;
      lVar13 = *(long *)(this_ptr + 8);
    }
    *(long *)(this_ptr + 8) = lVar13 + 1;
    return;
  }
  uVar8 = (long)puVar3 - *(long *)this_ptr;
  if (uVar8 != 0xffffffffffffffff) {
    uVar19 = 1;
    if (uVar8 != 0) {
      uVar19 = 0xffffffffffffffff;
      if (uVar8 <= uVar8 * 2) {
        uVar19 = uVar8 * 2;
      }
    }
    __dest = rea_operator_new(uVar19);
    __src = *(void **)this_ptr;
    __n = *(long *)(this_ptr + 8) - (long)__src;
    if ((uchar *)((long)__dest + __n) == (uchar *)0x0) {
      lVar13 = 0;
    }
    else {
      *(uchar *)((long)__dest + __n) = *param_1;
      __src = *(void **)this_ptr;
      __n = *(long *)(this_ptr + 8) - (long)__src;
      lVar13 = (long)__dest + __n;
    }
    if (__n != 0) {
      rea_memmove(__dest,__src,__n);
      __src = *(void **)this_ptr;
    }
    if (__src != (void *)0x0) {
      rea_operator_delete(__src);
    }
    *(void **)this_ptr = __dest;
    *(long *)(this_ptr + 8) = lVar13 + 1;
    *(ulong *)(this_ptr + 0x10) = (long)__dest + uVar19;
    return;
  }
  pcVar18 = "vector___M_emplace_back_aux";
  rea_std____throw_length_error("vector___M_emplace_back_aux");
  puVar4 = *(undefined8 **)param_1;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  if (puVar4 == (undefined8 *)0x0) {
    return;
  }
  lVar13 = **(long **)pcVar18;
  pvStack_68 = this_ptr;
  if (*(char *)(lVar13 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar13 + 0x88) = 1;
  pcStack_80 = (code *)0x0;
  plVar9 = rea_operator_new(8);
  *plVar9 = lVar13;
  puVar6 = PTR__M_manager_00324f68;
  uVar5 = *(undefined8 *)(lVar13 + 0x98);
  uStack_90 = *(undefined8 *)(lVar13 + 0x90);
  *(undefined8 *)(lVar13 + 0x98) = uStack_88;
  pcStack_80 = *(code **)(lVar13 + 0xa0);
  *(undefined **)(lVar13 + 0xa0) = puVar6;
  uStack_78 = *(undefined8 *)(lVar13 + 0xa8);
  *(long **)(lVar13 + 0x90) = plVar9;
  *(undefined **)(lVar13 + 0xa8) = PTR__M_invoke_00324f40;
  uStack_88 = uVar5;
  if (pcStack_80 != (code *)0x0) {
    (*pcStack_80)(&uStack_90,&uStack_90,3);
  }
  aiStack_a0[0] = *(int *)(lVar13 + 0x40);
  cVar2 = *(char *)(lVar13 + 0x88);
  lVar13 = *(long *)(lVar13 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var15 = p_Var10;
  p_Var14 = p_Var12;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
LAB_00115e7b:
    lVar11 = 0;
    uVar20 = 0;
  }
  else {
    do {
      while (p_Var16 = p_Var15, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var15 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var14;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115e6a;
      }
      p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var14 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115e6a:
    if ((p_Var12 == p_Var16) || (p_Var15 = p_Var12, aiStack_a0[0] < *(int *)(p_Var16 + 0x20)))
    goto LAB_00115e7b;
    do {
      while (p_Var14 = p_Var10, *(int *)(p_Var14 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var14 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var16;
        p_Var14 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_0011603a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var15 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011603a:
    if ((p_Var12 == p_Var14) || (aiStack_a0[0] < *(int *)(p_Var14 + 0x20))) {
      p_Var10 = rea_operator_new(0x28);
      if (p_Var10 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = aiStack_a0[0];
      }
      { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar13 + 8),p_Var14,p_Var10 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
      p_Var15 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x8));
      p_Var14 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x0));
      if (p_Var15 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var15)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var15 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var15,p_Var12);
        *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
        p_Var14 = p_Var10;
      }
    }
    uVar20 = *(uint *)(p_Var14 + 0x24);
    lVar11 = 1;
  }
  lVar13 = lVar13 + (lVar11 + 1) * 0x30;
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(lVar13 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var10 = p_Var12;
  p_Var15 = p_Var14;
  uVar7 = uVar20;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var16 = p_Var10, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115eca;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var15 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115eca:
    if ((p_Var14 != p_Var16) && (p_Var10 = p_Var14, *(int *)(p_Var16 + 0x20) <= aiStack_a0[0])) {
      do {
        while (p_Var15 = p_Var12, *(int *)(p_Var15 + 0x20) < aiStack_a0[0]) {
          p_Var16 = p_Var15 + 0x18;
          p_Var12 = *(_Rb_tree_node_base **)p_Var16;
          p_Var15 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_00115efa;
        }
        p_Var12 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var10 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115efa:
      if ((p_Var14 == p_Var15) || (aiStack_a0[0] < *(int *)(p_Var15 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
        }
        { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var12 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
        p_Var10 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x8));
        p_Var15 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x0));
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar17 = true;
          if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var10)) {
            bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var10,p_Var14);
          *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
          p_Var15 = p_Var12;
        }
      }
      uVar7 = *(uint *)(p_Var15 + 0x24);
    }
  }
  uVar21 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar21 = uVar7 & 0xfffffffe;
  }
  if (uVar20 == uVar21) {
    _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,aiStack_a0);
    goto LAB_00115ff3;
  }
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var15 = p_Var14;
  p_Var10 = p_Var14;
  if (*(_Rb_tree_node_base **)(lVar13 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116100:
    p_Var12 = rea_operator_new(0x28);
    if (p_Var12 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var12 = 0;
      *(undefined8 *)(p_Var12 + 8) = 0;
      *(undefined8 *)(p_Var12 + 0x10) = 0;
      *(undefined8 *)(p_Var12 + 0x18) = 0;
      *(undefined4 *)(p_Var12 + 0x24) = 0;
      *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
    }
    { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var12 + 0x20)); memcpy(auVar22, &__rea_tmp, sizeof(auVar22)); }
    p_Var15 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x8));
    p_Var10 = (*(undefined8 *)((uint8_t *)&auVar22 + 0x0));
    if (p_Var15 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var12);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var15)) {
        bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var15 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var15,p_Var14);
      *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
      p_Var10 = p_Var12;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var12, *(int *)(p_Var10 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var10 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var16;
        p_Var10 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_00115fda;
      }
      p_Var12 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var15 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115fda:
    if ((p_Var14 == p_Var10) || (aiStack_a0[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00116100;
  }
  *(uint *)(p_Var10 + 0x24) = uVar21;
LAB_00115ff3:
  if ((void *)*puVar4 != (void *)0x0) {
    rea_operator_delete((void *)*puVar4);
  }
  rea_operator_delete(puVar4);
  return;
}





// ------------------------------------------------------------------
// IDX 241  00115d50  _Function_handler<void
// ------------------------------------------------------------------
undefined8 rea__Function_handler_void__dup3(undefined8 * param_2)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_ptr;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  uint uVar6;
  long *plVar7;
  _Rb_tree_node_base *p_Var8;
  long lVar9;
  _Rb_tree_node_base *p_Var10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  _Rb_tree_node_base *p_Var14;
  bool bVar15;
  uint uVar16;
  uint uVar17;
  undefined1 auVar18 [16];
  int local_68 [4];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  
  puVar3 = (undefined8 *)*param_2;
  *param_2 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    return;
  }
  lVar11 = *(long *)*param_1;
  if (*(char *)(lVar11 + 0x88) != '\0') {
    rea_fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    rea_print_stack();
  }
  *(undefined1 *)(lVar11 + 0x88) = 1;
  local_48 = (code *)0x0;
  plVar7 = rea_operator_new(8);
  *plVar7 = lVar11;
  puVar5 = PTR__M_manager_00324f68;
  uVar4 = *(undefined8 *)(lVar11 + 0x98);
  local_58 = *(undefined8 *)(lVar11 + 0x90);
  *(undefined8 *)(lVar11 + 0x98) = local_50;
  local_48 = *(code **)(lVar11 + 0xa0);
  *(undefined **)(lVar11 + 0xa0) = puVar5;
  local_40 = *(undefined8 *)(lVar11 + 0xa8);
  *(long **)(lVar11 + 0x90) = plVar7;
  *(undefined **)(lVar11 + 0xa8) = PTR__M_invoke_00324f40;
  local_50 = uVar4;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  local_68[0] = *(int *)(lVar11 + 0x40);
  cVar2 = *(char *)(lVar11 + 0x88);
  lVar11 = *(long *)(lVar11 + 0x38);
  p_Var8 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var10 = (_Rb_tree_node_base *)(lVar11 + 0x10);
  p_Var13 = p_Var8;
  p_Var12 = p_Var10;
  if (p_Var8 == (_Rb_tree_node_base *)0x0) {
LAB_00115e7b:
    lVar9 = 0;
    uVar16 = 0;
  }
  else {
    do {
      while (p_Var14 = p_Var13, *(int *)(p_Var14 + 0x20) < local_68[0]) {
        p_Var1 = p_Var14 + 0x18;
        p_Var13 = *(_Rb_tree_node_base **)p_Var1;
        p_Var14 = p_Var12;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115e6a;
      }
      p_Var13 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var12 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115e6a:
    if ((p_Var10 == p_Var14) || (p_Var13 = p_Var10, local_68[0] < *(int *)(p_Var14 + 0x20)))
    goto LAB_00115e7b;
    do {
      while (p_Var12 = p_Var8, *(int *)(p_Var12 + 0x20) < local_68[0]) {
        p_Var14 = p_Var12 + 0x18;
        p_Var8 = *(_Rb_tree_node_base **)p_Var14;
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_0011603a;
      }
      p_Var8 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)(p_Var12 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011603a:
    if ((p_Var10 == p_Var12) || (local_68[0] < *(int *)(p_Var12 + 0x20))) {
      p_Var8 = rea_operator_new(0x28);
      if (p_Var8 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var8 = 0;
        *(undefined8 *)(p_Var8 + 8) = 0;
        *(undefined8 *)(p_Var8 + 0x10) = 0;
        *(undefined8 *)(p_Var8 + 0x18) = 0;
        *(undefined4 *)(p_Var8 + 0x24) = 0;
        *(int *)(p_Var8 + 0x20) = local_68[0];
      }
      { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar11 + 8),p_Var12,p_Var8 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
      p_Var13 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x8));
      p_Var12 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x0));
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var8);
      }
      else {
        bVar15 = true;
        if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var10 != p_Var13)) {
          bVar15 = *(int *)(p_Var8 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var8,p_Var13,p_Var10);
        *(long *)(lVar11 + 0x30) = *(long *)(lVar11 + 0x30) + 1;
        p_Var12 = p_Var8;
      }
    }
    uVar16 = *(uint *)(p_Var12 + 0x24);
    lVar9 = 1;
  }
  lVar11 = lVar11 + (lVar9 + 1) * 0x30;
  this_ptr = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
          *)(lVar11 + 8);
  p_Var10 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar11 + 0x10);
  p_Var8 = p_Var10;
  p_Var13 = p_Var12;
  uVar6 = uVar16;
  if (p_Var10 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var14 = p_Var8, *(int *)(p_Var14 + 0x20) < local_68[0]) {
        p_Var1 = p_Var14 + 0x18;
        p_Var8 = *(_Rb_tree_node_base **)p_Var1;
        p_Var14 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115eca;
      }
      p_Var8 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var13 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115eca:
    if ((p_Var12 != p_Var14) && (p_Var8 = p_Var12, *(int *)(p_Var14 + 0x20) <= local_68[0])) {
      do {
        while (p_Var13 = p_Var10, *(int *)(p_Var13 + 0x20) < local_68[0]) {
          p_Var14 = p_Var13 + 0x18;
          p_Var10 = *(_Rb_tree_node_base **)p_Var14;
          p_Var13 = p_Var8;
          if (*(_Rb_tree_node_base **)p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_00115efa;
        }
        p_Var10 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var8 = p_Var13;
      } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115efa:
      if ((p_Var12 == p_Var13) || (local_68[0] < *(int *)(p_Var13 + 0x20))) {
        p_Var10 = rea_operator_new(0x28);
        if (p_Var10 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var10 = 0;
          *(undefined8 *)(p_Var10 + 8) = 0;
          *(undefined8 *)(p_Var10 + 0x10) = 0;
          *(undefined8 *)(p_Var10 + 0x18) = 0;
          *(undefined4 *)(p_Var10 + 0x24) = 0;
          *(int *)(p_Var10 + 0x20) = local_68[0];
        }
        { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_ptr,p_Var13,p_Var10 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
        p_Var8 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x8));
        p_Var13 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x0));
        if (p_Var8 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var10);
        }
        else {
          bVar15 = true;
          if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var8)) {
            bVar15 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var8 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var8,p_Var12);
          *(long *)(lVar11 + 0x30) = *(long *)(lVar11 + 0x30) + 1;
          p_Var13 = p_Var10;
        }
      }
      uVar6 = *(uint *)(p_Var13 + 0x24);
    }
  }
  uVar17 = uVar6 | 1;
  if (cVar2 == '\0') {
    uVar17 = uVar6 & 0xfffffffe;
  }
  if (uVar16 == uVar17) {
    _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_ptr,local_68);
    goto LAB_00115ff3;
  }
  p_Var10 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var13 = p_Var12;
  p_Var8 = p_Var12;
  if (*(_Rb_tree_node_base **)(lVar11 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116100:
    p_Var10 = rea_operator_new(0x28);
    if (p_Var10 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var10 = 0;
      *(undefined8 *)(p_Var10 + 8) = 0;
      *(undefined8 *)(p_Var10 + 0x10) = 0;
      *(undefined8 *)(p_Var10 + 0x18) = 0;
      *(undefined4 *)(p_Var10 + 0x24) = 0;
      *(int *)(p_Var10 + 0x20) = local_68[0];
    }
    { auto &&__rea_tmp = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(this_ptr,p_Var8,p_Var10 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
    p_Var13 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x8));
    p_Var8 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x0));
    if (p_Var13 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var10);
    }
    else {
      bVar15 = true;
      if ((p_Var8 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
        bVar15 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var13 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var13,p_Var12);
      *(long *)(lVar11 + 0x30) = *(long *)(lVar11 + 0x30) + 1;
      p_Var8 = p_Var10;
    }
  }
  else {
    do {
      while (p_Var8 = p_Var10, *(int *)(p_Var8 + 0x20) < local_68[0]) {
        p_Var14 = p_Var8 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var14;
        p_Var8 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_00115fda;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
      p_Var13 = p_Var8;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115fda:
    if ((p_Var12 == p_Var8) || (local_68[0] < *(int *)(p_Var8 + 0x20))) goto LAB_00116100;
  }
  *(uint *)(p_Var8 + 0x24) = uVar17;
LAB_00115ff3:
  if ((void *)*puVar3 != (void *)0x0) {
    rea_operator_delete((void *)*puVar3);
  }
  rea_operator_delete(puVar3);
  return;
}





// ------------------------------------------------------------------
// IDX 242  00116280  std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char________________
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char__dup2(long * param_1, void * param_2, void * param_3, void * param_4)
{
  void *pvVar1;
  size_t sVar2;
  size_t __n;
  void *pvVar3;
  ulong uVar4;
  size_t sVar5;
  ulong uVar6;
  void *__src;
  bool bVar7;
  
  if (param_3 == param_4) {
    return;
  }
  pvVar3 = (void *)param_1[1];
  __n = (long)param_4 - (long)param_3;
  if (__n <= (ulong)(param_1[2] - (long)pvVar3)) {
    uVar6 = (long)pvVar3 - (long)param_2;
    if (__n < uVar6) {
      __src = (void *)((long)pvVar3 - __n);
      pvVar1 = pvVar3;
      if ((long)pvVar3 - (long)__src != 0) {
        pvVar1 = rea_memmove(pvVar3,__src,(long)pvVar3 - (long)__src);
        pvVar3 = (void *)param_1[1];
      }
      sVar2 = (long)__src - (long)param_2;
      param_1[1] = (long)pvVar3 + __n;
      if (sVar2 != 0) {
        rea_memmove((void *)((long)pvVar1 - sVar2),param_2,sVar2);
        if (__n == 0) {
          return;
        }
        goto LAB_00116338;
      }
    }
    else {
      pvVar1 = (void *)((long)param_3 + uVar6);
      if ((long)param_4 - (long)pvVar1 != 0) {
        rea_memmove(pvVar3,pvVar1,(long)param_4 - (long)pvVar1);
        pvVar3 = (void *)param_1[1];
      }
      pvVar3 = (void *)((long)pvVar3 + (__n - uVar6));
      param_1[1] = (long)pvVar3;
      if (uVar6 != 0) {
        rea_memmove(pvVar3,param_2,uVar6);
        pvVar3 = (void *)param_1[1];
      }
      __n = (long)pvVar1 - (long)param_3;
      param_1[1] = (long)pvVar3 + uVar6;
    }
    if (__n == 0) {
      return;
    }
LAB_00116338:
    rea_memmove(param_2,param_3,__n);
    return;
  }
  pvVar1 = (void *)*param_1;
  uVar6 = (long)pvVar3 - (long)pvVar1;
  if (~uVar6 < __n) {
    rea_std____throw_length_error("vector___M_range_insert");
  }
  else {
    uVar4 = __n;
    if (__n <= uVar6) {
      uVar4 = uVar6;
    }
    bVar7 = CARRY8(uVar6,uVar4);
    uVar4 = uVar6 + uVar4;
    uVar6 = 0xffffffffffffffff;
    if ((!bVar7) && (uVar6 = uVar4, uVar4 == 0)) {
      uVar6 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_00116398;
    }
  }
  pvVar3 = rea_operator_new(uVar6);
  pvVar1 = (void *)*param_1;
LAB_00116398:
  sVar5 = (long)param_2 - (long)pvVar1;
  sVar2 = 0;
  if (sVar5 != 0) {
    rea_memmove(pvVar3,pvVar1,sVar5);
    sVar2 = sVar5;
  }
  pvVar1 = (void *)(sVar2 + (long)pvVar3);
  if (__n != 0) {
    pvVar1 = rea_memmove(pvVar1,param_3,__n);
  }
  sVar5 = param_1[1] - (long)param_2;
  sVar2 = 0;
  if (sVar5 != 0) {
    rea_memmove((void *)(__n + (long)pvVar1),param_2,sVar5);
    sVar2 = sVar5;
  }
  if ((void *)*param_1 != (void *)0x0) {
    rea_operator_delete((void *)*param_1);
  }
  *param_1 = (long)pvVar3;
  param_1[1] = (long)(__n + (long)pvVar1) + sVar2;
  param_1[2] = uVar6 + (long)pvVar3;
  return;
}





// ------------------------------------------------------------------
// IDX 243  00116500  setnonblock
// ------------------------------------------------------------------
void rea_setnonblock__dup2(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,3);
  if (-1 < (int)uVar1) {
    rea_fcntl(param_1,4,(ulong)(uVar1 | 0x800));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 244  00116530  setcloexec
// ------------------------------------------------------------------
void rea_setcloexec__dup2(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,1);
  if (-1 < (int)uVar1) {
    rea_fcntl(param_1,2,(ulong)(uVar1 | 1));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 245  00116560  print_stack
// ------------------------------------------------------------------
void rea_print_stack__dup2(void)
{
  char *__s;
  int iVar1;
  void *__ptr;
  size_t __n;
  long lVar2;
  undefined1 auStack_348 [808];
  
  iVar1 = rea_backtrace(auStack_348,100);
  __ptr = (void *)rea_backtrace_symbols(auStack_348,iVar1);
  rea_write(2,"backtrace:",10);
  rea_write(2,"\n",1);
  rea_write(2,"<<<<<",5);
  rea_write(2,"\n",1);
  if (__ptr != (void *)0x0) {
    lVar2 = 0;
    if (0 < iVar1) {
      do {
        __s = *(char **)((long)__ptr + lVar2 * 8);
        lVar2 = lVar2 + 1;
        __n = rea_strlen(__s);
        rea_write(2,__s,__n);
        rea_write(2,"\n",1);
      } while ((int)lVar2 < iVar1);
    }
    rea_free(__ptr);
  }
  rea_write(2,">>>>>",5);
  rea_write(2,"\n",1);
  return;
}





// ------------------------------------------------------------------
// IDX 246  00116670  print_stack_abort
// ------------------------------------------------------------------
void rea_print_stack_abort__dup2(void)
{
  rea_print_stack();
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 247  00116680  is_myaddr
// ------------------------------------------------------------------
undefined8 rea_is_myaddr(char * param_1)
{
  short *psVar1;
  int iVar2;
  char *__s2;
  long *plVar3;
  long *local_28 [3];
  
  rea_getifaddrs(local_28);
  plVar3 = local_28[0];
  if (local_28[0] == (long *)0x0) {
    local_28[0] = (long *)0x0;
  }
  else {
    do {
      psVar1 = (short *)plVar3[3];
      if ((psVar1 != (short *)0x0) && (*psVar1 == 2)) {
        __s2 = rea_inet_ntoa((in_addr)*(in_addr_t *)(psVar1 + 2));
        iVar2 = rea_strcmp(param_1,__s2);
        if (iVar2 == 0) {
          rea_freeifaddrs(local_28[0]);
          return 1;
        }
      }
      plVar3 = (long *)*plVar3;
    } while (plVar3 != (long *)0x0);
  }
  rea_freeifaddrs(local_28[0]);
  return 0;
}





// ------------------------------------------------------------------
// IDX 248  00116700  mkdir_p
// ------------------------------------------------------------------
undefined4 rea_mkdir_p(char * param_1, int param_2)
{
  int iVar1;
  undefined4 uVar2;
  size_t __n;
  char *pcVar3;
  stat sStack_10b8;
  char local_1028 [4104];
  
  __n = rea_strnlen(param_1,0x1000);
  uVar2 = 0xffffffff;
  if ((__n & 0xffffffffffffefff) != 0) {
    rea_memcpy(local_1028,param_1,__n);
    local_1028[__n] = '\0';
    if (*(char *)((long)sStack_10b8.__unused + __n + 0x17) == '/') {
      *(undefined1 *)((long)sStack_10b8.__unused + __n + 0x17) = 0;
    }
    iVar1 = rea___xstat(1,local_1028,&sStack_10b8);
    if ((iVar1 == 0) && ((sStack_10b8.st_mode & 0xf000) == 0x4000)) {
      uVar2 = 0;
    }
    else {
      pcVar3 = local_1028 + 1;
      while (local_1028[1] != '\0') {
        while (local_1028[1] != '/') {
          pcVar3 = pcVar3 + 1;
          local_1028[1] = *pcVar3;
          if (local_1028[1] == '\0') goto LAB_001167c0;
        }
        *pcVar3 = '\0';
        rea_mkdir(local_1028,param_2);
        *pcVar3 = '/';
        local_1028[1] = pcVar3[1];
        pcVar3 = pcVar3 + 1;
      }
LAB_001167c0:
      rea_mkdir(local_1028,param_2);
      uVar2 = 0;
    }
  }
  return uVar2;
}





// ------------------------------------------------------------------
// IDX 249  00116810  dirname
// ------------------------------------------------------------------
string * rea_dirname(string * param_1)
{
  char *__s;
  char *pcVar1;
  undefined8 *in_RSI;
  allocator local_19 [9];
  
  __s = (char *)*in_RSI;
  pcVar1 = rea_strrchr(__s,0x2f);
  if (pcVar1 == (char *)0x0) {
    *(undefined **)param_1 = PTR__S_empty_rep_storage_00324fa0 + 0x18;
    return param_1;
  }
  if (__s < pcVar1) {
    do {
      if (pcVar1[-1] != '/') break;
      pcVar1 = pcVar1 + -1;
    } while (pcVar1 != __s);
  }
  rea_std__string__string(param_1,__s,(long)pcVar1 - (long)__s,local_19);
  return param_1;
}





// ------------------------------------------------------------------
// IDX 250  00116890  current_time
// ------------------------------------------------------------------
long rea_current_time__dup2(void)
{
  timeval local_18;
  
  rea_gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  return local_18.tv_sec * 1000000 + local_18.tv_usec;
}





// ------------------------------------------------------------------
// IDX 251  001168c0  EventLoop2__dtor_EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__dtor_EventLoop2__dup2(EventLoop2 * this_ptr)
{
  void *pvVar1;
  long *plVar2;
  void *pvVar3;
  long *plVar4;
  
  *(undefined **)this_ptr = PTR_vtable_00324f00 + 0x10;
  rea_close(*(int *)(this_ptr + 0x50));
  pvVar3 = *(void **)(this_ptr + 0x40);
  pvVar1 = *(void **)(this_ptr + 0x38);
  if (pvVar3 != pvVar1) {
    do {
      if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
        (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
      }
      pvVar1 = (void *)((long)pvVar1 + 0x28);
    } while (pvVar3 != pvVar1);
    pvVar3 = *(void **)(this_ptr + 0x38);
  }
  if (pvVar3 != (void *)0x0) {
    rea_operator_delete(pvVar3);
  }
  plVar4 = *(long **)(this_ptr + 0x28);
  plVar2 = *(long **)(this_ptr + 0x20);
  if (plVar4 != plVar2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long **)(this_ptr + 0x20);
  }
  if (plVar4 != (long *)0x0) {
    rea_operator_delete(plVar4);
  }
  plVar4 = *(long **)(this_ptr + 0x10);
  plVar2 = *(long **)(this_ptr + 8);
  if (plVar4 != plVar2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long **)(this_ptr + 8);
  }
  if (plVar4 == (long *)0x0) {
    return;
  }
  rea_operator_delete(plVar4);
  return;
}





// ------------------------------------------------------------------
// IDX 252  001169f0  EventLoop2__dtor_EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__dtor_EventLoop2__dup3(EventLoop2 * this_ptr)
{
  dtor_EventLoop2(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 253  00116a10  EventLoop2__exit
// ------------------------------------------------------------------
void rea_EventLoop2__exit__dup2(EventLoop2 * this_ptr, int param_1)
{
  *(int *)(this_ptr + 0x58) = param_1;
  this_ptr[0x54] = (EventLoop2)0x0;
  return;
}





// ------------------------------------------------------------------
// IDX 254  00116a20  EventLoop2__set_timeout
// ------------------------------------------------------------------
void rea_EventLoop2__set_timeout(EventLoop2 * this_ptr, long param_1)
{
  *(long *)(this_ptr + 0x60) = param_1;
  return;
}





// ------------------------------------------------------------------
// IDX 255  00116a30  EventLoop2__EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__EventLoop2__dup2(EventLoop2 * this_ptr)
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_vtable_00324f00;
  *(undefined8 *)(this_ptr + 8) = 0;
  *(undefined8 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x20) = 0;
  *(undefined8 *)(this_ptr + 0x28) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined8 *)(this_ptr + 0x38) = 0;
  *(undefined **)this_ptr = puVar1 + 0x10;
  *(undefined8 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  this_ptr[0x54] = (EventLoop2)0x1;
  *(undefined4 *)(this_ptr + 0x58) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 1000000;
  iVar2 = rea_epoll_create1(0x80000);
  *(int *)(this_ptr + 0x50) = iVar2;
  if (-1 < iVar2) {
    return;
  }
  rea_perror("epoll_create1");
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 256  00116b00  EventLoop2__add
// ------------------------------------------------------------------
void rea_EventLoop2__add__dup2(EventLoop2 * this_ptr, EventHandler * param_1)
{
  undefined8 *puVar1;
  EventHandler *local_18 [2];
  
  puVar1 = *(undefined8 **)(this_ptr + 0x28);
  local_18[0] = param_1;
  if (puVar1 == *(undefined8 **)(this_ptr + 0x30)) {
    std_______vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler________M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________((vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler
                *)(this_ptr + 0x20),(unique_ptr *)local_18);
  }
  else {
    if (puVar1 != (undefined8 *)0x0) {
      local_18[0] = (EventHandler *)0x0;
      *puVar1 = param_1;
    }
    *(undefined8 **)(this_ptr + 0x28) = puVar1 + 1;
  }
  if (local_18[0] != (EventHandler *)0x0) {
    (**(code **)(*(long *)local_18[0] + 0x18))();
  }
  return;
}





// ------------------------------------------------------------------
// IDX 257  00116b80  EventLoop2__del
// ------------------------------------------------------------------
void rea_EventLoop2__del(EventLoop2 * this_ptr, undefined8 param_1, long param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  code *local_30;
  undefined8 local_28;
  
  local_30 = (code *)0x0;
  local_48 = param_1;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(&local_40,param_3,2);
    local_28 = *(undefined8 *)(param_3 + 0x18);
    local_30 = *(code **)(param_3 + 0x10);
  }
  pcVar5 = local_30;
  puVar1 = *(undefined8 **)(this_ptr + 0x40);
  if (puVar1 == *(undefined8 **)(this_ptr + 0x48)) {
    std::
    vector<std__pair<EventHandler*,std__function<void()>>,std__allocator<std__pair<EventHandler*,std__function<void()>>>>
    ::_M_emplace_back_aux<std__pair<EventHandler*,std__function<void()>>>
              ((vector<std__pair<EventHandler*,std__function<void()>>,std__allocator<std__pair<EventHandler*,std__function<void()>>>>
                *)(this_ptr + 0x38),(pair *)&local_48);
  }
  else {
    lVar6 = 0;
    if (puVar1 != (undefined8 *)0x0) {
      puVar1[3] = 0;
      uVar2 = puVar1[2];
      *puVar1 = local_48;
      uVar3 = puVar1[1];
      uVar4 = puVar1[4];
      puVar1[1] = local_40;
      puVar1[2] = local_38;
      local_30 = (code *)0x0;
      puVar1[3] = pcVar5;
      puVar1[4] = local_28;
      lVar6 = *(long *)(this_ptr + 0x40);
      local_40 = uVar3;
      local_38 = uVar2;
      local_28 = uVar4;
    }
    *(long *)(this_ptr + 0x40) = lVar6 + 0x28;
  }
  if (local_30 != (code *)0x0) {
    (*local_30)(&local_40,&local_40,3);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 258  00116ce0  EventLoop2__run
// ------------------------------------------------------------------
undefined4 rea_EventLoop2__run__dup2(EventLoop2 * this_ptr, long param_2)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  epoll_data_t *peVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  char cVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  int *piVar13;
  long *plVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  bool bVar18;
  long lVar19;
  _Rb_tree_node_base *p_Var20;
  _Rb_tree_node_base *p_Var21;
  undefined8 *puVar22;
  long *plVar23;
  long *plVar24;
  byte bVar25;
  undefined1 auVar26 [16];
  long *local_c8;
  _Rb_tree_node_base *local_c0;
  int local_b0;
  int local_ac;
  long *local_a0;
  epoll_event local_78;
  epoll_event local_68;
  code *local_50;
  code *local_48;
  
  if (this_ptr[0x54] != (EventLoop2)0x0) {
    peVar3 = &local_68.data;
    do {
      local_a0 = *(long **)(this_ptr + 0x10);
      local_c8 = *(long **)(this_ptr + 8);
      if (local_a0 == local_c8) {
        if (*(long *)(this_ptr + 0x28) == *(long *)(this_ptr + 0x20)) break;
      }
      else if (*(long *)(this_ptr + 0x28) == *(long *)(this_ptr + 0x20)) goto LAB_00116dc6;
      std_________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_________________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_________________(this_ptr + 8);
      plVar24 = *(long **)(this_ptr + 0x28);
      plVar23 = *(long **)(this_ptr + 0x20);
      for (plVar14 = plVar23; plVar14 != plVar24; plVar14 = plVar14 + 1) {
        if ((long *)*plVar14 != (long *)0x0) {
          (**(code **)(*(long *)*plVar14 + 0x18))();
        }
        *plVar14 = 0;
      }
      local_c8 = *(long **)(this_ptr + 8);
      *(long **)(this_ptr + 0x28) = plVar23;
      local_a0 = *(long **)(this_ptr + 0x10);
      if (local_c8 != local_a0) {
LAB_00116dc6:
        local_ac = 0;
        local_b0 = 1;
        do {
          lVar19 = ((long)local_ac + 1) * 0x30 + *local_c8;
          p_Var12 = *(_Rb_tree_node_base **)(lVar19 + 0x20);
          local_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          if (p_Var12 != local_c0) {
            do {
              uVar4 = *(uint *)(p_Var12 + 0x24);
              iVar10 = *(int *)(p_Var12 + 0x20);
              uVar8 = 0x11;
              local_68.events = 0;
              local_68.data.fd = 0;
              if ((uVar4 & 2) != 0) {
                local_68.events = 4;
                uVar8 = 0x15;
              }
              if ((uVar4 & 1) != 0) {
                local_68.events = uVar8;
              }
              (*(undefined4 *)((uint8_t *)&local_68 + 0x4)) = iVar10;
              iVar9 = rea_epoll_ctl(*(int *)(this_ptr + 0x50),local_b0,iVar10,&local_68);
              if (iVar9 != 0) {
                rea_perror("epoll_ctl");
              }
              lVar19 = *local_c8;
              p_Var1 = (_Rb_tree_node_base *)(lVar19 + 0x10);
              p_Var11 = *(_Rb_tree_node_base **)(lVar19 + 0x18);
              p_Var20 = p_Var1;
              p_Var21 = p_Var1;
              if (*(_Rb_tree_node_base **)(lVar19 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116ecb:
                p_Var11 = rea_operator_new(0x28);
                if (p_Var11 != (_Rb_tree_node_base *)0x0) {
                  *(undefined4 *)p_Var11 = 0;
                  *(undefined8 *)(p_Var11 + 8) = 0;
                  *(undefined8 *)(p_Var11 + 0x10) = 0;
                  *(undefined8 *)(p_Var11 + 0x18) = 0;
                  *(int *)(p_Var11 + 0x20) = iVar10;
                  *(undefined4 *)(p_Var11 + 0x24) = 0;
                }
                { auto &&__rea_tmp = (std______________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________________M_get_insert_hint_unique_pos_____________________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                      *)(lVar19 + 8),p_Var21,p_Var11 + 0x20)); memcpy(auVar26, &__rea_tmp, sizeof(auVar26)); }
                p_Var20 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x8));
                p_Var21 = (*(undefined8 *)((uint8_t *)&auVar26 + 0x0));
                if (p_Var20 == (_Rb_tree_node_base *)0x0) {
                  rea_operator_delete(p_Var11);
                }
                else {
                  bVar18 = true;
                  if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var20)) {
                    bVar18 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var20 + 0x20);
                  }
                  rea_std___Rb_tree_insert_and_rebalance(bVar18,p_Var11,p_Var20,p_Var1);
                  *(long *)(lVar19 + 0x30) = *(long *)(lVar19 + 0x30) + 1;
                  p_Var21 = p_Var11;
                }
              }
              else {
                do {
                  while (p_Var21 = p_Var11, iVar10 <= *(int *)(p_Var21 + 0x20)) {
                    p_Var11 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
                    p_Var20 = p_Var21;
                    if (*(_Rb_tree_node_base **)(p_Var21 + 0x10) == (_Rb_tree_node_base *)0x0)
                    goto LAB_00116ebb;
                  }
                  p_Var2 = p_Var21 + 0x18;
                  p_Var11 = *(_Rb_tree_node_base **)p_Var2;
                  p_Var21 = p_Var20;
                } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_00116ebb:
                if ((p_Var21 == p_Var1) || (iVar10 < *(int *)(p_Var21 + 0x20))) goto LAB_00116ecb;
              }
              *(uint *)(p_Var21 + 0x24) = uVar4;
              p_Var12 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var12);
            } while (local_c0 != p_Var12);
            lVar19 = ((long)local_ac + 1) * 0x30 + *local_c8;
            local_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          }
          std______________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                      *)(lVar19 + 8),*(_Rb_tree_node **)(lVar19 + 0x18));
          *(undefined8 *)(lVar19 + 0x18) = 0;
          *(undefined8 *)(lVar19 + 0x30) = 0;
          *(_Rb_tree_node_base **)(lVar19 + 0x20) = local_c0;
          *(_Rb_tree_node_base **)(lVar19 + 0x28) = local_c0;
          if (local_ac == 1) goto code_r0x00116fc4;
          local_b0 = 3;
          local_ac = 1;
        } while( true );
      }
LAB_00116fda:
      iVar10 = rea_epoll_wait(*(int *)(this_ptr + 0x50),&local_78,1,(int)(*(long *)(this_ptr + 0x60) / 1000));
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
            local_50 = (code *)0x0;
            local_68.events = (uint32_t)*puVar17;
            (*(undefined4 *)((uint8_t *)&local_68 + 0x4)) = SUB84((ulong)*puVar17 >> 0x20,0);
            if ((code *)puVar17[3] != (code *)0x0) {
              (*(code *)puVar17[3])(peVar3,puVar17 + 1,2);
              local_48 = (code *)puVar17[4];
              local_50 = (code *)puVar17[3];
            }
            plVar23 = *(long **)(this_ptr + 8);
            plVar24 = *(long **)(this_ptr + 0x10);
            if (plVar23 != plVar24) {
              lVar19 = *plVar23;
              while (CONCAT44((*(undefined4 *)((uint8_t *)&local_68 + 0x4)),local_68.events) != lVar19) {
                plVar23 = plVar23 + 1;
                if (plVar23 == plVar24) goto joined_r0x00117259;
                lVar19 = *plVar23;
              }
              plVar23 = plVar23 + 1;
              if ((plVar23 != plVar24) && (lVar19 = (long)plVar24 - (long)plVar23 >> 3, 0 < lVar19))
              {
                do {
                  plVar24 = (long *)plVar23[-1];
                  lVar6 = *plVar23;
                  *plVar23 = 0;
                  plVar23[-1] = lVar6;
                  if (plVar24 != (long *)0x0) {
                    (**(code **)(*plVar24 + 0x18))();
                  }
                  plVar23 = plVar23 + 1;
                  lVar19 = lVar19 + -1;
                } while (lVar19 != 0);
                plVar24 = *(long **)(this_ptr + 0x10);
              }
              *(long **)(this_ptr + 0x10) = plVar24 + -1;
              if ((long *)plVar24[-1] != (long *)0x0) {
                (**(code **)(*(long *)plVar24[-1] + 0x18))();
              }
              plVar24[-1] = 0;
            }
joined_r0x00117259:
            if (local_50 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
              rea_std____throw_bad_function_call();
            }
            (*local_48)(peVar3);
            if (local_50 != (code *)0x0) {
              (*local_50)(peVar3,peVar3,3);
            }
            puVar17 = puVar17 + 5;
          } while (puVar15 != puVar17);
          puVar16 = *(undefined8 **)(this_ptr + 0x40);
          puVar15 = *(undefined8 **)(this_ptr + 0x38);
          puVar17 = puVar16;
          for (puVar22 = puVar15; puVar16 != puVar22; puVar22 = puVar22 + 5) {
            if ((code *)puVar22[3] != (code *)0x0) {
              (*(code *)puVar22[3])(puVar22 + 1,puVar22 + 1,3);
            }
            puVar17 = puVar15;
          }
        }
        puVar15 = *(undefined8 **)(this_ptr + 8);
        *(undefined8 **)(this_ptr + 0x40) = puVar17;
        while (puVar15 != *(undefined8 **)(this_ptr + 0x10)) {
          cVar7 = (**(code **)(*(long *)*puVar15 + 8))();
          while (cVar7 == '\0') {
            puVar15 = puVar15 + 1;
            if (puVar15 == *(undefined8 **)(this_ptr + 0x10)) goto LAB_0011714d;
            cVar7 = (**(code **)(*(long *)*puVar15 + 8))();
          }
          puVar16 = *(undefined8 **)(this_ptr + 0x10);
          puVar17 = puVar15 + 1;
          if ((puVar16 != puVar17) && (lVar19 = (long)puVar16 - (long)puVar17 >> 3, 0 < lVar19)) {
            do {
              plVar23 = (long *)puVar17[-1];
              uVar5 = *puVar17;
              *puVar17 = 0;
              puVar17[-1] = uVar5;
              if (plVar23 != (long *)0x0) {
                (**(code **)(*plVar23 + 0x18))();
              }
              puVar17 = puVar17 + 1;
              lVar19 = lVar19 + -1;
            } while (lVar19 != 0);
            puVar16 = *(undefined8 **)(this_ptr + 0x10);
          }
          *(undefined8 **)(this_ptr + 0x10) = puVar16 + -1;
          if ((long *)puVar16[-1] != (long *)0x0) {
            (**(code **)(*(long *)puVar16[-1] + 0x18))();
          }
          puVar16[-1] = 0;
        }
      }
      else {
        puVar17 = *(undefined8 **)(this_ptr + 8);
        while (puVar17 != *(undefined8 **)(this_ptr + 0x10)) {
          bVar25 = (local_78.events & 0x11) != 0;
          if ((local_78.events & 4) != 0) {
            bVar25 = bVar25 | 2;
          }
          cVar7 = (*(code *)**(undefined8 **)*puVar17)((undefined8 *)*puVar17,(*(undefined4 *)((uint8_t *)&local_78 + 0x4)),bVar25)
          ;
          if ((cVar7 == '\0') && (cVar7 = (**(code **)(*(long *)*puVar17 + 8))(), cVar7 == '\0')) {
            puVar17 = puVar17 + 1;
          }
          else {
            puVar16 = *(undefined8 **)(this_ptr + 0x10);
            puVar15 = puVar17 + 1;
            if ((puVar16 != puVar15) && (lVar19 = (long)puVar16 - (long)puVar15 >> 3, 0 < lVar19)) {
              do {
                plVar23 = (long *)puVar15[-1];
                uVar5 = *puVar15;
                *puVar15 = 0;
                puVar15[-1] = uVar5;
                if (plVar23 != (long *)0x0) {
                  (**(code **)(*plVar23 + 0x18))();
                }
                puVar15 = puVar15 + 1;
                lVar19 = lVar19 + -1;
              } while (lVar19 != 0);
              puVar16 = *(undefined8 **)(this_ptr + 0x10);
            }
            *(undefined8 **)(this_ptr + 0x10) = puVar16 + -1;
            if ((long *)puVar16[-1] != (long *)0x0) {
              (**(code **)(*(long *)puVar16[-1] + 0x18))();
            }
            puVar16[-1] = 0;
          }
        }
      }
LAB_0011714d:
      if (*(long *)(param_2 + 0x10) != 0) {
        (**(code **)(param_2 + 0x18))(param_2);
      }
    } while (this_ptr[0x54] != (EventLoop2)0x0);
  }
  this_ptr[0x54] = (EventLoop2)0x1;
  return *(undefined4 *)(this_ptr + 0x58);
code_r0x00116fc4:
  local_c8 = local_c8 + 1;
  if (local_a0 == local_c8) goto LAB_00116fda;
  goto LAB_00116dc6;
}





// ------------------------------------------------------------------
// IDX 259  001174a0  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector__dup2(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr)
{
  long *plVar1;
  long *plVar2;
  
  plVar2 = *(long **)(this_ptr + 8);
  plVar1 = *(long **)this_ptr;
  if (plVar2 != plVar1) {
    do {
      if ((long *)*plVar1 != (long *)0x0) {
        (**(code **)(*(long *)*plVar1 + 0x18))();
      }
      *plVar1 = 0;
      plVar1 = plVar1 + 1;
    } while (plVar2 != plVar1);
    plVar2 = *(long **)this_ptr;
  }
  if (plVar2 == (long *)0x0) {
    return;
  }
  rea_operator_delete(plVar2);
  return;
}





// ------------------------------------------------------------------
// IDX 260  00117500  vector<std__pair<EventHandler*,std__function<void
// ------------------------------------------------------------------
undefined8 rea_vector_std__pair_EventHandler__std__function_void__dup3(undefined8 * param_x0, undefined8 * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)(this_ptr + 8);
  pvVar1 = *(void **)this_ptr;
  if (pvVar2 != pvVar1) {
    do {
      if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
        (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
      }
      pvVar1 = (void *)((long)pvVar1 + 0x28);
    } while (pvVar2 != pvVar1);
    pvVar2 = *(void **)this_ptr;
  }
  if (pvVar2 == (void *)0x0) {
    return;
  }
  rea_operator_delete(pvVar2);
  return;
}





// ------------------------------------------------------------------
// IDX 261  00117570  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler___________
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler__dup2(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr, unique_ptr * param_1)
{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  undefined8 *puVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  long *plVar12;
  
  uVar11 = 8;
  uVar3 = *(long *)(this_ptr + 8) - *(long *)this_ptr >> 3;
  if (uVar3 != 0) {
    if ((uVar3 * 2 < uVar3) || (0x1fffffffffffffff < uVar3 * 2)) {
      uVar11 = 0xfffffffffffffff8;
    }
    else {
      uVar11 = uVar3 << 4;
    }
  }
  plVar4 = rea_operator_new(uVar11);
  plVar9 = *(long **)(this_ptr + 8);
  plVar8 = *(long **)this_ptr;
  plVar12 = plVar4 + 1;
  puVar5 = (undefined8 *)(((long)plVar9 - (long)plVar8 & 0xfffffffffffffff8U) + (long)plVar4);
  if (puVar5 != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)param_1;
    *(undefined8 *)param_1 = 0;
    plVar9 = *(long **)(this_ptr + 8);
    plVar8 = *(long **)this_ptr;
    *puVar5 = uVar1;
  }
  plVar6 = plVar4;
  plVar7 = plVar8;
  plVar10 = plVar9;
  if (plVar9 != plVar8) {
    do {
      if (plVar6 != (long *)0x0) {
        lVar2 = *plVar7;
        *plVar7 = 0;
        *plVar6 = lVar2;
      }
      plVar7 = plVar7 + 1;
      plVar6 = plVar6 + 1;
    } while (plVar7 != plVar9);
    plVar10 = *(long **)(this_ptr + 8);
    plVar6 = *(long **)this_ptr;
    plVar12 = (long *)((long)plVar4 +
                      ((long)plVar9 - (long)(plVar8 + 1) & 0xfffffffffffffff8U) + 0x10);
    if (plVar10 != plVar6) {
      do {
        if ((long *)*plVar6 != (long *)0x0) {
          (**(code **)(*(long *)*plVar6 + 0x18))();
        }
        *plVar6 = 0;
        plVar6 = plVar6 + 1;
      } while (plVar10 != plVar6);
      plVar10 = *(long **)this_ptr;
    }
  }
  if (plVar10 != (long *)0x0) {
    rea_operator_delete(plVar10);
  }
  *(long **)this_ptr = plVar4;
  *(long **)(this_ptr + 8) = plVar12;
  *(ulong *)(this_ptr + 0x10) = (long)plVar4 + uVar11;
  return;
}





// ------------------------------------------------------------------
// IDX 262  001176d0  vector<std__pair<EventHandler*,std__function<void
// ------------------------------------------------------------------
undefined8 rea_vector_std__pair_EventHandler__std__function_void__dup4(undefined8 * param_x0, undefined8 * param_1)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  ulong local_48;
  
  lVar5 = *(long *)(this_ptr + 8) - *(long *)this_ptr >> 3;
  if (lVar5 * -0x3333333333333333 == 0) {
    local_48 = 1;
  }
  else {
    local_48 = lVar5 * -0x6666666666666666;
    if (local_48 <= (ulong)(lVar5 * -0x3333333333333333) && lVar5 * 0x3333333333333333 != 0) {
      uVar8 = 0xfffffffffffffff0;
      local_48 = 0x666666666666666;
      goto LAB_00117727;
    }
    if (0x666666666666666 < local_48) {
      uVar8 = 0xfffffffffffffff0;
      local_48 = 0x666666666666666;
      goto LAB_00117727;
    }
  }
  uVar8 = local_48 * 0x28;
LAB_00117727:
  puVar6 = rea_operator_new(uVar8);
  puVar11 = *(undefined8 **)(this_ptr + 8);
  puVar7 = *(undefined8 **)this_ptr;
  puVar9 = (undefined8 *)(((long)puVar11 - (long)puVar7 & 0xfffffffffffffff8U) + (long)puVar6);
  if (puVar9 != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)param_1;
    puVar9[3] = 0;
    *puVar9 = uVar1;
    uVar1 = puVar9[1];
    uVar2 = *(undefined8 *)(param_1 + 8);
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(param_1 + 0x10) = puVar9[2];
    *(undefined8 *)(param_1 + 8) = uVar1;
    puVar9[1] = uVar2;
    puVar9[2] = uVar3;
    uVar1 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x18) = puVar9[3];
    puVar9[3] = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = puVar9[4];
    puVar9[4] = uVar1;
    puVar11 = *(undefined8 **)(this_ptr + 8);
    puVar7 = *(undefined8 **)this_ptr;
  }
  if (puVar11 == puVar7) {
    puVar9 = puVar6 + 5;
  }
  else {
    puVar10 = puVar6 + 4;
    puVar4 = puVar6;
    do {
      puVar9 = puVar4;
      if (puVar9 != (undefined8 *)0x0) {
        *puVar9 = *puVar7;
        puVar10[-1] = 0;
        if ((code *)puVar7[3] != (code *)0x0) {
          (*(code *)puVar7[3])(puVar9 + 1,puVar7 + 1,2);
          *puVar10 = puVar7[4];
          puVar10[-1] = puVar7[3];
        }
      }
      puVar7 = puVar7 + 5;
      puVar10 = puVar10 + 5;
      puVar4 = puVar9 + 5;
    } while (puVar11 != puVar7);
    puVar9 = puVar9 + 10;
    puVar7 = *(undefined8 **)this_ptr;
    puVar11 = *(undefined8 **)(this_ptr + 8);
    if (puVar11 != puVar7) {
      do {
        if ((code *)puVar7[3] != (code *)0x0) {
          (*(code *)puVar7[3])(puVar7 + 1,puVar7 + 1,3);
        }
        puVar7 = puVar7 + 5;
      } while (puVar11 != puVar7);
      puVar11 = *(undefined8 **)this_ptr;
    }
  }
  if (puVar11 != (undefined8 *)0x0) {
    rea_operator_delete(puVar11);
  }
  *(undefined8 **)(this_ptr + 8) = puVar9;
  *(undefined8 **)this_ptr = puVar6;
  *(undefined8 **)(this_ptr + 0x10) = puVar6 + local_48 * 5;
  return;
}





// ------------------------------------------------------------------
// IDX 263  001179c0  std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler________________
// ------------------------------------------------------------------
void rea_std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__dup2(undefined8 * param_1, long * param_2, long * param_3, long * param_4)
{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  
  if (param_4 == param_3) {
    return;
  }
  plVar4 = (long *)param_1[1];
  uVar9 = (long)param_4 - (long)param_3 >> 3;
  if (uVar9 <= (ulong)(param_1[2] - (long)plVar4 >> 3)) {
    uVar10 = (long)plVar4 - (long)param_2 >> 3;
    if (uVar10 <= uVar9) {
      plVar2 = param_3 + uVar10;
      plVar7 = plVar4;
      plVar3 = plVar2;
      if (param_4 != plVar2) {
        do {
          if (plVar7 != (long *)0x0) {
            lVar12 = *plVar3;
            *plVar3 = 0;
            *plVar7 = lVar12;
          }
          plVar3 = plVar3 + 1;
          plVar7 = plVar7 + 1;
        } while (param_4 != plVar3);
        plVar7 = (long *)param_1[1];
      }
      plVar7 = plVar7 + (uVar9 - uVar10);
      param_1[1] = plVar7;
      plVar3 = param_2;
      if (plVar4 != param_2) {
        do {
          if (plVar7 != (long *)0x0) {
            lVar12 = *plVar3;
            *plVar3 = 0;
            *plVar7 = lVar12;
          }
          plVar3 = plVar3 + 1;
          plVar7 = plVar7 + 1;
        } while (plVar4 != plVar3);
        plVar7 = (long *)param_1[1];
      }
      param_1[1] = plVar7 + uVar10;
      lVar12 = (long)plVar2 - (long)param_3 >> 3;
      if (lVar12 < 1) {
        return;
      }
      do {
        lVar1 = *param_3;
        *param_3 = 0;
        plVar4 = (long *)*param_2;
        *param_2 = lVar1;
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 0x18))();
        }
        param_2 = param_2 + 1;
        param_3 = param_3 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      return;
    }
    plVar3 = plVar4 + -uVar9;
    plVar2 = plVar4;
    plVar7 = plVar3;
    if (plVar4 != plVar3) {
      do {
        if (plVar2 != (long *)0x0) {
          lVar12 = *plVar7;
          *plVar7 = 0;
          *plVar2 = lVar12;
        }
        plVar7 = plVar7 + 1;
        plVar2 = plVar2 + 1;
      } while (plVar4 != plVar7);
      plVar2 = (long *)param_1[1];
    }
    param_1[1] = plVar2 + uVar9;
    lVar12 = (long)plVar3 - (long)param_2 >> 3;
    if (0 < lVar12) {
      do {
        plVar3 = plVar3 + -1;
        plVar4 = plVar4 + -1;
        lVar1 = *plVar3;
        *plVar3 = 0;
        plVar2 = (long *)*plVar4;
        *plVar4 = lVar1;
        if (plVar2 != (long *)0x0) {
          (**(code **)(*plVar2 + 0x18))();
        }
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
    }
    if ((long)uVar9 < 1) {
      return;
    }
    do {
      lVar12 = *param_3;
      *param_3 = 0;
      plVar4 = (long *)*param_2;
      *param_2 = lVar12;
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x18))();
      }
      param_3 = param_3 + 1;
      param_2 = param_2 + 1;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    return;
  }
  plVar2 = (long *)*param_1;
  uVar10 = (long)plVar4 - (long)plVar2 >> 3;
  if (0x1fffffffffffffff - uVar10 < uVar9) {
    rea_std____throw_length_error("vector___M_range_insert");
    return;
  }
  uVar11 = 0xfffffffffffffff8;
  if (uVar9 <= uVar10) {
    uVar9 = uVar10;
  }
  uVar8 = uVar10 + uVar9;
  if ((!CARRY8(uVar10,uVar9)) && (uVar8 < 0x2000000000000000)) {
    if (uVar8 == 0) {
      uVar11 = 0;
      plVar4 = (long *)0x0;
      goto LAB_00117c22;
    }
    uVar11 = uVar8 * 8;
  }
  plVar4 = rea_operator_new(uVar11);
  plVar2 = (long *)*param_1;
LAB_00117c22:
  plVar6 = param_3;
  plVar5 = plVar2;
  plVar7 = plVar4;
  plVar3 = plVar4;
  if (plVar2 != param_2) {
    do {
      if (plVar7 != (long *)0x0) {
        lVar12 = *plVar5;
        *plVar5 = 0;
        *plVar7 = lVar12;
      }
      plVar5 = plVar5 + 1;
      plVar7 = plVar7 + 1;
    } while (plVar5 != param_2);
    plVar7 = (long *)((long)plVar4 + ((long)param_2 - (long)(plVar2 + 1) & 0xfffffffffffffff8U) + 8)
    ;
    plVar3 = plVar7;
  }
  do {
    if (plVar7 != (long *)0x0) {
      lVar12 = *plVar6;
      *plVar6 = 0;
      *plVar7 = lVar12;
    }
    plVar6 = plVar6 + 1;
    plVar7 = plVar7 + 1;
  } while (param_4 != plVar6);
  plVar2 = (long *)param_1[1];
  plVar3 = (long *)((long)plVar3 + ((long)param_4 - (long)(param_3 + 1) & 0xfffffffffffffff8U) + 8);
  plVar7 = param_2;
  plVar6 = plVar3;
  if (plVar2 != param_2) {
    do {
      if (plVar6 != (long *)0x0) {
        lVar12 = *plVar7;
        *plVar7 = 0;
        *plVar6 = lVar12;
      }
      plVar7 = plVar7 + 1;
      plVar6 = plVar6 + 1;
    } while (plVar2 != plVar7);
    plVar7 = param_2 + 1;
    param_2 = (long *)param_1[1];
    plVar3 = (long *)((long)plVar3 + ((long)plVar2 - (long)plVar7 & 0xfffffffffffffff8U) + 8);
  }
  plVar2 = (long *)*param_1;
  if (plVar2 != param_2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (param_2 != plVar2);
    param_2 = (long *)*param_1;
  }
  if (param_2 != (long *)0x0) {
    rea_operator_delete(param_2);
  }
  *param_1 = plVar4;
  param_1[1] = plVar3;
  param_1[2] = (long)plVar4 + uVar11;
  return;
}





// ------------------------------------------------------------------
// IDX 264  00117d90  FUN_00117d90
// ------------------------------------------------------------------
void rea_FUN_00117d90(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 265  00117da0  FUN_00117da0
// ------------------------------------------------------------------
undefined8 rea_FUN_00117da0(undefined8 * param_1, undefined8 * param_2, int param_3)
{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (void *)&PTR_vtable_00324a80;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = rea_operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      rea_operator_delete((void *)*param_1);
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 266  00117e10  TcpConn__idle_proc
// ------------------------------------------------------------------
void rea_TcpConn__idle_proc__dup2(TcpConn * this_ptr)
{
  if (*(long *)(this_ptr + 0xc0) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00117e2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(this_ptr + 200))(this_ptr + 0xb0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 267  00117e40  TcpClient__idle
// ------------------------------------------------------------------
uint rea_TcpClient__idle(TcpClient * this_ptr)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this_ptr + 0x98);
  if (iVar1 == 1) {
    rea_TcpConn__idle_proc(*(TcpConn **)(this_ptr + 0xa0));
    uVar2 = 0;
    if (*(char *)(*(long *)(this_ptr + 0xa0) + 0x58) == '\0') {
      return *(byte *)(*(long *)(this_ptr + 0xa0) + 0x59) ^ 1;
    }
  }
  else {
    uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 2);
  }
  return uVar2;
}





// ------------------------------------------------------------------
// IDX 268  00117e90  TcpServer__idle
// ------------------------------------------------------------------
undefined8 rea_TcpServer__idle(TcpServer * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  void *pvVar3;
  _Rb_tree_node_base *p_Var4;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var4 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  do {
    if (p_Var4 == p_Var1) {
      return 0;
    }
    while( true ) {
      rea_TcpConn__idle_proc(*(TcpConn **)(p_Var4 + 0x28));
      if ((*(char *)(*(long *)(p_Var4 + 0x28) + 0x58) != '\0') ||
         (*(char *)(*(long *)(p_Var4 + 0x28) + 0x59) != '\0')) break;
      p_Var2 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
      pvVar3 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var4,p_Var1);
      if (*(long **)((long)pvVar3 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)((long)pvVar3 + 0x28) + 8))();
      }
      *(undefined8 *)((long)pvVar3 + 0x28) = 0;
      rea_operator_delete(pvVar3);
      *(long *)(this_ptr + 0xe8) = *(long *)(this_ptr + 0xe8) + -1;
      p_Var4 = p_Var2;
      if (p_Var2 == p_Var1) {
        return 0;
      }
    }
    p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
  } while( true );
}





// ------------------------------------------------------------------
// IDX 269  00117f40  TcpServer__iter
// ------------------------------------------------------------------
void rea_TcpServer__iter(TcpServer * this_ptr, long param_2)
{
  _Rb_tree_node_base *p_Var1;
  
  p_Var1 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  while( true ) {
    if (p_Var1 == (_Rb_tree_node_base *)(this_ptr + 200)) {
      return;
    }
    if (*(long *)(param_2 + 0x10) == 0) break;
    (**(code **)(param_2 + 0x18))
              (param_2,*(undefined4 *)(p_Var1 + 0x20),*(undefined8 *)(p_Var1 + 0x28));
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var1);
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 270  00117f90  TcpClient__dtor_TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__dtor_TcpClient__dup2(TcpClient * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  undefined *puVar3;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  TcpClient *pTVar4;
  
  *(undefined **)this_ptr = PTR_vtable_00324f98 + 0x10;
  if (*(code **)(this_ptr + 0xd8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xd8))(this_ptr + 200,this_ptr + 200,3);
  }
  if (*(code **)(this_ptr + 0xb8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xb8))(this_ptr + 0xa8,this_ptr + 0xa8,3);
  }
  if (*(long **)(this_ptr + 0xa0) != (long *)0x0) {
    (**(code **)(**(long **)(this_ptr + 0xa0) + 8))();
  }
  puVar3 = PTR_vtable_00324fb8;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  pTVar4 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pTVar4 + -0x30);
    pvVar2 = *(void **)(pTVar4 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pTVar4 = (TcpClient *)this_00;
  } while (this_ptr + 0x38 != (TcpClient *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 271  00118070  TcpClient__dtor_TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__dtor_TcpClient__dup3(TcpClient * this_ptr)
{
  dtor_TcpClient(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 272  00118090  TcpConn__TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__TcpConn__dup2(TcpConn * this_ptr, int param_1, string * param_2, string * param_3, EventHandler * param_4)
{
  undefined *puVar1;
  void *pvVar2;
  
  *(TcpConn **)(this_ptr + 0x20) = this_ptr + 0x10;
  *(TcpConn **)(this_ptr + 0x28) = this_ptr + 0x10;
  puVar1 = PTR_vtable_00324f08;
  *(int *)(this_ptr + 0x40) = param_1;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(EventHandler **)(this_ptr + 0x38) = param_4;
  *(undefined **)this_ptr = puVar1 + 0x10;
  rea_std__string__string((string *)(this_ptr + 0x48),param_2);
  rea_std__string__string((string *)(this_ptr + 0x50),param_3);
  this_ptr[0x58] = (TcpConn)0x1;
  this_ptr[0x59] = (TcpConn)0x1;
  this_ptr[0x5a] = (TcpConn)0x0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  this_ptr[0x88] = (TcpConn)0x0;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xc0) = 0;
  pvVar2 = rea_operator_new(1);
  *(void **)(this_ptr + 0xb0) = pvVar2;
  *(code **)(this_ptr + 200) = FUN_00117d90;
  *(code **)(this_ptr + 0xc0) = FUN_00117da0;
  return;
}





// ------------------------------------------------------------------
// IDX 273  00118220  TcpClient__TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__TcpClient__dup2(TcpClient * this_ptr, int param_1, long param_3)
{
  int *piVar1;
  long *plVar2;
  undefined *puVar3;
  int iVar4;
  TcpConn *this_00;
  allocator local_3a [2];
  long local_38 [2];
  
  *(TcpClient **)(this_ptr + 0x20) = this_ptr + 0x10;
  *(TcpClient **)(this_ptr + 0x28) = this_ptr + 0x10;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(TcpClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(TcpClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(TcpClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(TcpClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar3 = PTR_vtable_00324f98;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 1;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  rea_setcloexec(param_1);
  rea_setnonblock(param_1);
  rea_std__string__string((string *)local_38,"",local_3a);
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,param_1,(string *)local_38,(string *)local_38,(EventHandler *)this_ptr);
  plVar2 = *(long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 8))();
  }
  if ((allocator *)(local_38[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_38[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(local_38[0] + -8);
      *(int *)(local_38[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_38[0] + -0x18));
    }
  }
  if (*(long *)(param_3 + 0x10) != 0) {
    (**(code **)(param_3 + 0x18))(param_3,*(undefined8 *)(this_ptr + 0xa0));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 274  00118450  TcpConn__dtor_TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__dtor_TcpConn__dup2(TcpConn * this_ptr)
{
  int *piVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  int iVar5;
  int local_28 [4];
  
  lVar2 = *(long *)(this_ptr + 0x38);
  *(undefined **)this_ptr = PTR_vtable_00324f08 + 0x10;
  local_28[0] = *(int *)(this_ptr + 0x40);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(lVar2 + 8),local_28);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(lVar2 + 0x38),local_28);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(lVar2 + 0x68),local_28);
  rea_close(*(int *)(this_ptr + 0x40));
  if (*(code **)(this_ptr + 0xc0) != (code *)0x0) {
    (**(code **)(this_ptr + 0xc0))(this_ptr + 0xb0,this_ptr + 0xb0,3);
  }
  if (*(code **)(this_ptr + 0xa0) != (code *)0x0) {
    (**(code **)(this_ptr + 0xa0))(this_ptr + 0x90,this_ptr + 0x90,3);
  }
  if (*(code **)(this_ptr + 0x78) != (code *)0x0) {
    (**(code **)(this_ptr + 0x78))(this_ptr + 0x68,this_ptr + 0x68,3);
  }
  puVar3 = *(undefined8 **)(this_ptr + 0x60);
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  puVar4 = PTR__S_empty_rep_storage_00324fa0;
  lVar2 = *(long *)(this_ptr + 0x50);
  *(undefined8 *)(this_ptr + 0x60) = 0;
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar4) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar5 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  lVar2 = *(long *)(this_ptr + 0x48);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar4) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar5 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 275  001185c0  TcpConn__dtor_TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__dtor_TcpConn__dup3(TcpConn * this_ptr)
{
  dtor_TcpConn(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 276  001185e0  TcpServer__dtor_TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__dtor_TcpServer__dup2(TcpServer * this_ptr)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  int local_38 [6];
  
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(this_ptr + 0x98);
  *(undefined **)this_ptr = PTR_vtable_00324f48 + 0x10;
  local_38[0] = *(int *)(this_ptr + 0xb8);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 8),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x38),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x68),local_38);
  rea_close(*(int *)(this_ptr + 0xb8));
  std______Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn______M_erase((_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn
              *)(this_ptr + 0xc0),*(_Rb_tree_node **)(this_ptr + 0xd0));
  if (*(code **)(this_ptr + 0xa8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xa8))(p_Var1,p_Var1,3);
  }
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  while ((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
          *)(this_ptr + 0x38) != p_Var1) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________M_erase(p_Var1 + -0x30,*(_Rb_tree_node **)(p_Var1 + -0x20));
    p_Var1 = p_Var1 + -0x30;
  }
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 277  001186b0  TcpServer__dtor_TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__dtor_TcpServer__dup3(TcpServer * this_ptr)
{
  dtor_TcpServer(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 278  001186d0  TcpServer__TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__TcpServer(TcpServer * this_ptr, int param_1, long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  bool bVar10;
  uint uVar11;
  undefined1 auVar12 [16];
  int local_48 [6];
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(this_ptr + 0x38);
  *(TcpServer **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(TcpServer **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
  *(TcpServer **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(TcpServer **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar5 = PTR_vtable_00324f48;
  *(_Rb_tree_node_base **)(this_ptr + 0x28) = p_Var1;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined **)this_ptr = puVar5 + 0x10;
  *(undefined8 *)(this_ptr + 0xa8) = 0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(this_ptr + 0x98,param_3,2);
    *(undefined8 *)(this_ptr + 0xb0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this_ptr + 0xa8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(int *)(this_ptr + 0xb8) = param_1;
  *(undefined4 *)(this_ptr + 200) = 0;
  *(undefined8 *)(this_ptr + 0xd0) = 0;
  *(undefined8 *)(this_ptr + 0xe8) = 0;
  *(TcpServer **)(this_ptr + 0xd8) = this_ptr + 200;
  *(TcpServer **)(this_ptr + 0xe0) = this_ptr + 200;
  rea_setcloexec(param_1);
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  p_Var9 = p_Var6;
  p_Var7 = p_Var1;
  local_48[0] = param_1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_00118af0:
    uVar11 = 0;
  }
  else {
    do {
      while (p_Var8 = p_Var9, *(int *)(p_Var8 + 0x20) < param_1) {
        p_Var2 = p_Var8 + 0x18;
        p_Var9 = *(_Rb_tree_node_base **)p_Var2;
        p_Var8 = p_Var7;
        if (*(_Rb_tree_node_base **)p_Var2 == (_Rb_tree_node_base *)0x0) goto LAB_0011882b;
      }
      p_Var9 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
      p_Var7 = p_Var8;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011882b:
    if ((p_Var1 == p_Var8) || (param_1 < *(int *)(p_Var8 + 0x20))) goto LAB_00118af0;
    iVar3 = *(int *)(p_Var6 + 0x20);
    p_Var9 = p_Var1;
    while( true ) {
      if (iVar3 < param_1) {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var9 = p_Var6;
      }
      p_Var6 = p_Var7;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) break;
      iVar3 = *(int *)(p_Var6 + 0x20);
    }
    if ((p_Var1 == p_Var9) || (param_1 < *(int *)(p_Var9 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_48[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var9,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
      p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
      p_Var9 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
      if (p_Var7 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var9 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
        *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
        p_Var9 = p_Var6;
      }
    }
    uVar11 = *(uint *)(p_Var9 + 0x24);
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(this_ptr + 0x68);
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(this_00 + 8);
  p_Var9 = p_Var6;
  p_Var7 = p_Var1;
  uVar4 = uVar11;
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var8 = p_Var9, *(int *)(p_Var8 + 0x20) < local_48[0]) {
        p_Var2 = p_Var8 + 0x18;
        p_Var9 = *(_Rb_tree_node_base **)p_Var2;
        p_Var8 = p_Var7;
        if (*(_Rb_tree_node_base **)p_Var2 == (_Rb_tree_node_base *)0x0) goto LAB_001188c2;
      }
      p_Var9 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
      p_Var7 = p_Var8;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001188c2:
    if ((p_Var1 != p_Var8) && (p_Var9 = p_Var1, *(int *)(p_Var8 + 0x20) <= local_48[0])) {
      do {
        while (p_Var7 = p_Var6, *(int *)(p_Var7 + 0x20) < local_48[0]) {
          p_Var8 = p_Var7 + 0x18;
          p_Var6 = *(_Rb_tree_node_base **)p_Var8;
          p_Var7 = p_Var9;
          if (*(_Rb_tree_node_base **)p_Var8 == (_Rb_tree_node_base *)0x0) goto LAB_001188fa;
        }
        p_Var6 = *(_Rb_tree_node_base **)(p_Var7 + 0x10);
        p_Var9 = p_Var7;
      } while (*(_Rb_tree_node_base **)(p_Var7 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001188fa:
      if ((p_Var1 == p_Var7) || (local_48[0] < *(int *)(p_Var7 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var7,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
        p_Var9 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
        p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
        if (p_Var9 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var7 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var9)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var9 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var9,p_Var1);
          *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
          p_Var7 = p_Var6;
        }
      }
      uVar4 = *(uint *)(p_Var7 + 0x24);
    }
  }
  if ((uVar4 | 1) == uVar11) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_48);
    return;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var7 = p_Var1;
  p_Var9 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_00 + 0x10) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var9 = p_Var6, *(int *)(p_Var9 + 0x20) < local_48[0]) {
        p_Var8 = p_Var9 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var8;
        p_Var9 = p_Var7;
        if (*(_Rb_tree_node_base **)p_Var8 == (_Rb_tree_node_base *)0x0) goto LAB_00118952;
      }
      p_Var6 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
      p_Var7 = p_Var9;
    } while (*(_Rb_tree_node_base **)(p_Var9 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00118952:
    if ((p_Var1 != p_Var9) && (*(int *)(p_Var9 + 0x20) <= local_48[0])) goto LAB_001189d8;
  }
  p_Var6 = rea_operator_new(0x28);
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var6 = 0;
    *(undefined8 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined4 *)(p_Var6 + 0x24) = 0;
    *(int *)(p_Var6 + 0x20) = local_48[0];
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(this_00,p_Var9,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
  p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
  p_Var9 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
  if (p_Var7 == (_Rb_tree_node_base *)0x0) {
    rea_operator_delete(p_Var6);
  }
  else {
    bVar10 = true;
    if ((p_Var9 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
      bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
    *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
    p_Var9 = p_Var6;
  }
LAB_001189d8:
  *(uint *)(p_Var9 + 0x24) = uVar4 | 1;
  return;
}





// ------------------------------------------------------------------
// IDX 279  00118c40  TcpServer__TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__TcpServer__dup2(TcpServer * this_ptr, undefined8 * param_1, ushort param_3, long param_4)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_node_base *p_Var8;
  bool bVar9;
  _Rb_tree_node_base *p_Var10;
  TcpServer *this_00;
  uint uVar11;
  undefined1 auVar12 [16];
  undefined4 local_68 [4];
  int local_58 [4];
  sockaddr local_48;
  
  this_00 = this_ptr + 0x38;
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  *(TcpServer **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(TcpServer **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
  *(TcpServer **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(TcpServer **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar4 = PTR_vtable_00324f48;
  *(_Rb_tree_node_base **)(this_ptr + 0x28) = p_Var1;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined **)this_ptr = puVar4 + 0x10;
  *(undefined8 *)(this_ptr + 0xa8) = 0;
  if (*(code **)(param_4 + 0x10) != (code *)0x0) {
    (**(code **)(param_4 + 0x10))(this_ptr + 0x98,param_4,2);
    *(undefined8 *)(this_ptr + 0xb0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this_ptr + 0xa8) = *(undefined8 *)(param_4 + 0x10);
  }
  *(undefined4 *)(this_ptr + 200) = 0;
  *(undefined8 *)(this_ptr + 0xd0) = 0;
  *(TcpServer **)(this_ptr + 0xd8) = this_ptr + 200;
  *(TcpServer **)(this_ptr + 0xe0) = this_ptr + 200;
  *(undefined8 *)(this_ptr + 0xe8) = 0;
  rea_bzero(&local_48,0x10);
  local_48.sa_family = 2;
  local_48.(*(undefined4 *)((uint8_t *)&sa_data + 0x2)) = rea_inet_addr((char *)*param_1);
  local_48.(*(undefined2 *)((uint8_t *)&sa_data + 0x0)) = param_3 >> 8 | param_3 << 8;
  iVar5 = rea_socket(2,1,0);
  *(int *)(this_ptr + 0xb8) = iVar5;
  if (iVar5 < 0) {
    rea_perror("socket");
LAB_001191f4:
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setcloexec(iVar5);
  local_68[0] = 1;
  rea_setsockopt(*(int *)(this_ptr + 0xb8),1,2,local_68,4);
  iVar5 = rea_bind(*(int *)(this_ptr + 0xb8),&local_48,0x10);
  if (iVar5 < 0) {
    rea_perror("bind");
    goto LAB_001191f4;
  }
  iVar5 = rea_listen(*(int *)(this_ptr + 0xb8),0x1ff);
  if (iVar5 < 0) {
    rea_perror("listen");
    goto LAB_001191f4;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  local_58[0] = *(int *)(this_ptr + 0xb8);
  p_Var10 = p_Var6;
  p_Var7 = p_Var1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_00119138:
    uVar11 = 0;
  }
  else {
    do {
      while (p_Var8 = p_Var10, local_58[0] <= *(int *)(p_Var8 + 0x20)) {
        p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_00118e4a;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var10 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_00118e4a:
    if ((p_Var1 == p_Var8) || (local_58[0] < *(int *)(p_Var8 + 0x20))) goto LAB_00119138;
    iVar5 = *(int *)(p_Var6 + 0x20);
    p_Var10 = p_Var1;
    while( true ) {
      if (iVar5 < local_58[0]) {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var10 = p_Var6;
      }
      p_Var6 = p_Var7;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) break;
      iVar5 = *(int *)(p_Var6 + 0x20);
    }
    if ((p_Var1 == p_Var10) || (local_58[0] < *(int *)(p_Var10 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_58[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var10,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
      p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
      p_Var10 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
      if (p_Var7 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar9 = true;
        if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
          bVar9 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var6,p_Var7,p_Var1);
        *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
        p_Var10 = p_Var6;
      }
    }
    uVar11 = *(uint *)(p_Var10 + 0x24);
    this_00 = this_ptr + 0x68;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(this_00 + 8);
  p_Var10 = p_Var6;
  p_Var7 = p_Var1;
  uVar3 = uVar11;
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var8 = p_Var10, local_58[0] <= *(int *)(p_Var8 + 0x20)) {
        p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_00118eda;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var10 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_00118eda:
    if ((p_Var1 != p_Var8) && (p_Var10 = p_Var1, *(int *)(p_Var8 + 0x20) <= local_58[0])) {
      do {
        while (p_Var7 = p_Var6, local_58[0] <= *(int *)(p_Var7 + 0x20)) {
          p_Var6 = *(_Rb_tree_node_base **)(p_Var7 + 0x10);
          p_Var10 = p_Var7;
          if (*(_Rb_tree_node_base **)(p_Var7 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_00118f0a;
        }
        p_Var8 = p_Var7 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var8;
        p_Var7 = p_Var10;
      } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_00118f0a:
      if ((p_Var1 == p_Var7) || (local_58[0] < *(int *)(p_Var7 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_58[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)this_00,p_Var7,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
        p_Var10 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
        p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar9 = true;
          if ((p_Var7 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var10)) {
            bVar9 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var6,p_Var10,p_Var1);
          *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
          p_Var7 = p_Var6;
        }
      }
      uVar3 = *(uint *)(p_Var7 + 0x24);
    }
  }
  if ((uVar3 | 1) == uVar11) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)this_00,local_58);
    return;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var7 = p_Var1;
  p_Var10 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_00 + 0x10) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var10 = p_Var6, local_58[0] <= *(int *)(p_Var10 + 0x20)) {
        p_Var6 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
        p_Var7 = p_Var10;
        if (*(_Rb_tree_node_base **)(p_Var10 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00118f62;
      }
      p_Var8 = p_Var10 + 0x18;
      p_Var6 = *(_Rb_tree_node_base **)p_Var8;
      p_Var10 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_00118f62:
    if ((p_Var1 != p_Var10) && (*(int *)(p_Var10 + 0x20) <= local_58[0])) goto LAB_00118fe9;
  }
  p_Var6 = rea_operator_new(0x28);
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var6 = 0;
    *(undefined8 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined4 *)(p_Var6 + 0x24) = 0;
    *(int *)(p_Var6 + 0x20) = local_58[0];
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos_______________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                        *)this_00,p_Var10,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
  p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
  p_Var10 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
  if (p_Var7 == (_Rb_tree_node_base *)0x0) {
    rea_operator_delete(p_Var6);
  }
  else {
    bVar9 = true;
    if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
      bVar9 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var6,p_Var7,p_Var1);
    *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
    p_Var10 = p_Var6;
  }
LAB_00118fe9:
  *(uint *)(p_Var10 + 0x24) = uVar3 | 1;
  return;
}





// ------------------------------------------------------------------
// IDX 280  00119280  TcpConn__recv_proc
// ------------------------------------------------------------------
void rea_TcpConn__recv_proc__dup2(TcpConn * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var2;
  undefined8 uVar3;
  code *pcVar4;
  long *plVar5;
  int iVar6;
  long *plVar7;
  void *pvVar8;
  size_t sVar9;
  ssize_t sVar10;
  _Rb_tree_node_base *p_Var11;
  long lVar12;
  _Rb_tree_node_base *p_Var13;
  ulong uVar14;
  int *piVar15;
  ulong uVar16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  undefined8 uVar19;
  ulong __n;
  void *pvVar20;
  bool bVar21;
  long lVar22;
  _Rb_tree_node_base *p_Var23;
  uint uVar24;
  size_t __n_00;
  ulong uVar25;
  uint uVar26;
  undefined1 auVar27 [16];
  int local_88 [4];
  int local_78 [4];
  long *local_68 [2];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  
  if (this_ptr[0x88] == (TcpConn)0x0) {
    rea_fprintf(*(FILE **)PTR_stderr_00324fb0,"TcpConn: bogus recv: fd=%d\n",
            (ulong)*(uint *)(this_ptr + 0x40));
    this_ptr[0x58] = (TcpConn)0x0;
    this_ptr[0x59] = (TcpConn)0x0;
    return;
  }
  plVar7 = rea_operator_new(0x18);
  *plVar7 = 0;
  plVar7[1] = 0;
  plVar7[2] = 0;
  pvVar8 = rea_operator_new(0x8000);
  __n_00 = plVar7[1] - *plVar7;
  sVar9 = 0;
  if (__n_00 != 0) {
    rea_memmove(pvVar8,(void *)*plVar7,__n_00);
    sVar9 = __n_00;
  }
  rea_memset((void *)((long)pvVar8 + sVar9),0,0x8000);
  if ((void *)*plVar7 != (void *)0x0) {
    rea_operator_delete((void *)*plVar7);
  }
  iVar6 = *(int *)(this_ptr + 0x40);
  *plVar7 = (long)pvVar8;
  plVar7[1] = (long)((long)pvVar8 + sVar9) + 0x8000;
  plVar7[2] = (long)pvVar8 + 0x8000;
  sVar10 = rea_read(iVar6,pvVar8,0x8000);
  iVar6 = (int)sVar10;
  if (iVar6 == -1) {
    piVar15 = rea___errno_location();
    if (*piVar15 == 0xb) goto LAB_001196ee;
  }
  else if (-1 < iVar6) {
    if (iVar6 != 0) {
      pvVar8 = (void *)plVar7[1];
      pvVar20 = (void *)*plVar7;
      uVar14 = (ulong)iVar6;
      __n = (long)pvVar8 - (long)pvVar20;
      if (__n < uVar14) {
        uVar14 = uVar14 - __n;
        if (uVar14 != 0) {
          if ((ulong)(plVar7[2] - (long)pvVar8) < uVar14) {
            if (~__n < uVar14) {
              uVar19 = rea_std____throw_length_error("vector___M_default_append");
              rea_FUN_00107794(plVar7);
              if (local_48 != (code *)0x0) {
                (*local_48)(&local_58,&local_58,3);
              }
                    /* WARNING: Subroutine does not return */
              rea__Unwind_Resume(uVar19);
            }
            uVar16 = __n;
            if (__n <= uVar14) {
              uVar16 = uVar14;
            }
            uVar25 = 0xffffffffffffffff;
            if ((CARRY8(uVar16,__n)) || (uVar25 = uVar16 + __n, uVar16 + __n != 0)) {
              pvVar8 = rea_operator_new(uVar25);
              pvVar20 = (void *)*plVar7;
              __n = plVar7[1] - (long)pvVar20;
            }
            else {
              uVar25 = 0;
              pvVar8 = (void *)0x0;
            }
            if (__n != 0) {
              rea_memmove(pvVar8,pvVar20,__n);
            }
            pvVar20 = (void *)((long)pvVar8 + __n);
            rea_memset(pvVar20,0,(uVar14 + (long)pvVar20) - (long)pvVar20);
            if ((void *)*plVar7 != (void *)0x0) {
              rea_operator_delete((void *)*plVar7);
            }
            *plVar7 = (long)pvVar8;
            plVar7[1] = uVar14 + (long)pvVar20;
            plVar7[2] = uVar25 + (long)pvVar8;
          }
          else {
            rea_memset(pvVar8,0,uVar14);
            plVar7[1] = plVar7[1] + uVar14;
          }
        }
      }
      else if (uVar14 < __n) {
        plVar7[1] = uVar14 + (long)pvVar20;
      }
      lVar22 = *(long *)(this_ptr + 0x38);
      local_78[0] = *(int *)(this_ptr + 0x40);
      this_ptr[0x88] = (TcpConn)0x0;
      p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
      p_Var18 = p_Var11;
      p_Var23 = p_Var13;
      if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_00119be0:
        lVar12 = 0;
        uVar24 = 0;
      }
      else {
        do {
          while (p_Var17 = p_Var18, *(int *)(p_Var17 + 0x20) < local_78[0]) {
            p_Var1 = p_Var17 + 0x18;
            p_Var18 = *(_Rb_tree_node_base **)p_Var1;
            p_Var17 = p_Var23;
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001197da;
          }
          p_Var18 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var23 = p_Var17;
        } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001197da:
        if ((p_Var13 == p_Var17) || (p_Var18 = p_Var13, local_78[0] < *(int *)(p_Var17 + 0x20)))
        goto LAB_00119be0;
        do {
          while (p_Var23 = p_Var11, *(int *)(p_Var23 + 0x20) < local_78[0]) {
            p_Var17 = p_Var23 + 0x18;
            p_Var11 = *(_Rb_tree_node_base **)p_Var17;
            p_Var23 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_0011980a;
          }
          p_Var11 = *(_Rb_tree_node_base **)(p_Var23 + 0x10);
          p_Var18 = p_Var23;
        } while (*(_Rb_tree_node_base **)(p_Var23 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011980a:
        if ((p_Var13 == p_Var23) || (local_78[0] < *(int *)(p_Var23 + 0x20))) {
          p_Var11 = rea_operator_new(0x28);
          if (p_Var11 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var11 = 0;
            *(undefined8 *)(p_Var11 + 8) = 0;
            *(undefined8 *)(p_Var11 + 0x10) = 0;
            *(undefined8 *)(p_Var11 + 0x18) = 0;
            *(undefined4 *)(p_Var11 + 0x24) = 0;
            *(int *)(p_Var11 + 0x20) = local_78[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos_______________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                                *)(lVar22 + 8),p_Var23,p_Var11 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
          p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
          p_Var23 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
          if (p_Var18 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var11);
          }
          else {
            bVar21 = true;
            if ((p_Var23 == (_Rb_tree_node_base *)0x0) && (p_Var13 != p_Var18)) {
              bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var18 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var18,p_Var13);
            *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
            p_Var23 = p_Var11;
          }
        }
        uVar24 = *(uint *)(p_Var23 + 0x24);
        lVar12 = 1;
      }
      lVar22 = lVar22 + (lVar12 + 1) * 0x30;
      p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                *)(lVar22 + 8);
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var23 = (_Rb_tree_node_base *)(lVar22 + 0x10);
      p_Var11 = p_Var13;
      p_Var18 = p_Var23;
      uVar26 = uVar24;
      if (p_Var13 != (_Rb_tree_node_base *)0x0) {
        do {
          while (p_Var17 = p_Var11, *(int *)(p_Var17 + 0x20) < local_78[0]) {
            p_Var1 = p_Var17 + 0x18;
            p_Var11 = *(_Rb_tree_node_base **)p_Var1;
            p_Var17 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001198ea;
          }
          p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var18 = p_Var17;
        } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001198ea:
        if ((p_Var23 != p_Var17) && (p_Var11 = p_Var23, *(int *)(p_Var17 + 0x20) <= local_78[0])) {
          do {
            while (p_Var18 = p_Var13, *(int *)(p_Var18 + 0x20) < local_78[0]) {
              p_Var17 = p_Var18 + 0x18;
              p_Var13 = *(_Rb_tree_node_base **)p_Var17;
              p_Var18 = p_Var11;
              if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_0011991a;
            }
            p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
            p_Var11 = p_Var18;
          } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011991a:
          if ((p_Var23 == p_Var18) || (local_78[0] < *(int *)(p_Var18 + 0x20))) {
            p_Var13 = rea_operator_new(0x28);
            if (p_Var13 != (_Rb_tree_node_base *)0x0) {
              *(undefined4 *)p_Var13 = 0;
              *(undefined8 *)(p_Var13 + 8) = 0;
              *(undefined8 *)(p_Var13 + 0x10) = 0;
              *(undefined8 *)(p_Var13 + 0x18) = 0;
              *(undefined4 *)(p_Var13 + 0x24) = 0;
              *(int *)(p_Var13 + 0x20) = local_78[0];
            }
            { auto &&__rea_tmp = (std__________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________________M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
            p_Var11 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
            p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
            if (p_Var11 == (_Rb_tree_node_base *)0x0) {
              rea_operator_delete(p_Var13);
            }
            else {
              bVar21 = true;
              if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var11)) {
                bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var11 + 0x20);
              }
              rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var11,p_Var23);
              *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
              p_Var18 = p_Var13;
            }
          }
          uVar26 = *(uint *)(p_Var18 + 0x24);
        }
      }
      if ((uVar26 & 0xfffffffe) == uVar24) {
        std____________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___________erase(p_Var2,local_78);
        goto LAB_00119a77;
      }
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var18 = p_Var23;
      p_Var11 = p_Var23;
      if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_001199f5:
        p_Var13 = rea_operator_new(0x28);
        if (p_Var13 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = local_78[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var11,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
        p_Var11 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
        if (p_Var18 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var11 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var18)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var18,p_Var23);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var11 = p_Var13;
        }
      }
      else {
        do {
          while (p_Var11 = p_Var13, *(int *)(p_Var11 + 0x20) < local_78[0]) {
            p_Var17 = p_Var11 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var11 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_001199ea;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
          p_Var18 = p_Var11;
        } while (*(_Rb_tree_node_base **)(p_Var11 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001199ea:
        if ((p_Var23 == p_Var11) || (local_78[0] < *(int *)(p_Var11 + 0x20))) goto LAB_001199f5;
      }
      *(uint *)(p_Var11 + 0x24) = uVar26 & 0xfffffffe;
LAB_00119a77:
      uVar19 = *(undefined8 *)(this_ptr + 0x98);
      uVar3 = *(undefined8 *)(this_ptr + 0x90);
      local_48 = *(code **)(this_ptr + 0xa0);
      pcVar4 = *(code **)(this_ptr + 0xa8);
      *(undefined8 *)(this_ptr + 0x90) = local_58;
      *(undefined8 *)(this_ptr + 0x98) = local_50;
      *(undefined8 *)(this_ptr + 0xa0) = 0;
      *(code **)(this_ptr + 0xa8) = local_40;
      local_58 = uVar3;
      local_50 = uVar19;
      local_40 = pcVar4;
      if (local_48 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      local_68[0] = plVar7;
      (*pcVar4)(&local_58,local_68);
      plVar7 = local_68[0];
      if (local_68[0] != (long *)0x0) {
        if ((void *)*local_68[0] != (void *)0x0) {
          rea_operator_delete((void *)*local_68[0]);
        }
        rea_operator_delete(plVar7);
      }
      if (local_48 == (code *)0x0) {
        return;
      }
      (*local_48)(&local_58,&local_58,3);
      return;
    }
    lVar22 = *(long *)(this_ptr + 0x38);
    local_88[0] = *(int *)(this_ptr + 0x40);
    this_ptr[0x58] = (TcpConn)0x0;
    this_ptr[0x88] = (TcpConn)0x0;
    p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
    p_Var18 = p_Var11;
    p_Var23 = p_Var13;
    if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_00119bd0:
      lVar12 = 0;
      uVar24 = 0;
    }
    else {
      do {
        while (p_Var17 = p_Var18, *(int *)(p_Var17 + 0x20) < local_88[0]) {
          p_Var1 = p_Var17 + 0x18;
          p_Var18 = *(_Rb_tree_node_base **)p_Var1;
          p_Var17 = p_Var23;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011939a;
        }
        p_Var18 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var23 = p_Var17;
      } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011939a:
      if ((p_Var13 == p_Var17) || (p_Var18 = p_Var13, local_88[0] < *(int *)(p_Var17 + 0x20)))
      goto LAB_00119bd0;
      do {
        while (p_Var23 = p_Var11, *(int *)(p_Var23 + 0x20) < local_88[0]) {
          p_Var17 = p_Var23 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var17;
          p_Var23 = p_Var18;
          if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_001193ca;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var23 + 0x10);
        p_Var18 = p_Var23;
      } while (*(_Rb_tree_node_base **)(p_Var23 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001193ca:
      if ((p_Var13 == p_Var23) || (local_88[0] < *(int *)(p_Var23 + 0x20))) {
        p_Var11 = rea_operator_new(0x28);
        if (p_Var11 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_88[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar22 + 8),p_Var23,p_Var11 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
        p_Var23 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
        if (p_Var18 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var11);
        }
        else {
          bVar21 = true;
          if ((p_Var23 == (_Rb_tree_node_base *)0x0) && (p_Var13 != p_Var18)) {
            bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var18,p_Var13);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var23 = p_Var11;
        }
      }
      uVar24 = *(uint *)(p_Var23 + 0x24);
      lVar12 = 1;
    }
    lVar22 = lVar22 + (lVar12 + 1) * 0x30;
    p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar22 + 8);
    p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    p_Var23 = (_Rb_tree_node_base *)(lVar22 + 0x10);
    p_Var11 = p_Var13;
    p_Var18 = p_Var23;
    uVar26 = uVar24;
    if (p_Var13 != (_Rb_tree_node_base *)0x0) {
      do {
        while (p_Var17 = p_Var11, *(int *)(p_Var17 + 0x20) < local_88[0]) {
          p_Var1 = p_Var17 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var1;
          p_Var17 = p_Var18;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001194aa;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var18 = p_Var17;
      } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001194aa:
      if ((p_Var23 != p_Var17) && (p_Var11 = p_Var23, *(int *)(p_Var17 + 0x20) <= local_88[0])) {
        do {
          while (p_Var18 = p_Var13, *(int *)(p_Var18 + 0x20) < local_88[0]) {
            p_Var17 = p_Var18 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var18 = p_Var11;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_001194da;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
          p_Var11 = p_Var18;
        } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001194da:
        if ((p_Var23 == p_Var18) || (local_88[0] < *(int *)(p_Var18 + 0x20))) {
          p_Var13 = rea_operator_new(0x28);
          if (p_Var13 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var13 = 0;
            *(undefined8 *)(p_Var13 + 8) = 0;
            *(undefined8 *)(p_Var13 + 0x10) = 0;
            *(undefined8 *)(p_Var13 + 0x18) = 0;
            *(undefined4 *)(p_Var13 + 0x24) = 0;
            *(int *)(p_Var13 + 0x20) = local_88[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
          p_Var11 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
          p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
          if (p_Var11 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var13);
          }
          else {
            bVar21 = true;
            if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var11)) {
              bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var11 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var11,p_Var23);
            *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
            p_Var18 = p_Var13;
          }
        }
        uVar26 = *(uint *)(p_Var18 + 0x24);
      }
    }
    if ((uVar26 & 0xfffffffe) == uVar24) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var2,local_88);
    }
    else {
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var18 = p_Var23;
      p_Var11 = p_Var23;
      if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_001195b5:
        p_Var13 = rea_operator_new(0x28);
        if (p_Var13 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = local_88[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var11,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
        p_Var11 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
        if (p_Var18 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var11 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var18)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var18,p_Var23);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var11 = p_Var13;
        }
      }
      else {
        do {
          while (p_Var11 = p_Var13, *(int *)(p_Var11 + 0x20) < local_88[0]) {
            p_Var17 = p_Var11 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var11 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_001195aa;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
          p_Var18 = p_Var11;
        } while (*(_Rb_tree_node_base **)(p_Var11 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001195aa:
        if ((p_Var23 == p_Var11) || (local_88[0] < *(int *)(p_Var11 + 0x20))) goto LAB_001195b5;
      }
      *(uint *)(p_Var11 + 0x24) = uVar26 & 0xfffffffe;
    }
    uVar19 = *(undefined8 *)(this_ptr + 0x98);
    uVar3 = *(undefined8 *)(this_ptr + 0x90);
    local_48 = *(code **)(this_ptr + 0xa0);
    pcVar4 = *(code **)(this_ptr + 0xa8);
    *(undefined8 *)(this_ptr + 0x90) = local_58;
    *(undefined8 *)(this_ptr + 0x98) = local_50;
    *(undefined8 *)(this_ptr + 0xa0) = 0;
    *(code **)(this_ptr + 0xa8) = local_40;
    local_58 = uVar3;
    local_50 = uVar19;
    local_40 = pcVar4;
    if (local_48 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    local_68[0] = (long *)0x0;
    (*pcVar4)(&local_58,local_68);
    plVar5 = local_68[0];
    if (local_68[0] != (long *)0x0) {
      if ((void *)*local_68[0] != (void *)0x0) {
        rea_operator_delete((void *)*local_68[0]);
      }
      rea_operator_delete(plVar5);
    }
    if (local_48 != (code *)0x0) {
      (*local_48)(&local_58,&local_58,3);
    }
    goto LAB_001196ee;
  }
  rea_perror("tcp recv");
  iVar6 = *(int *)(this_ptr + 0x40);
  this_ptr[0x58] = (TcpConn)0x0;
  this_ptr[0x59] = (TcpConn)0x0;
  this_ptr[0x88] = (TcpConn)0x0;
  lVar22 = *(long *)(this_ptr + 0x38);
  local_58 = CONCAT44((*(undefined4 *)((uint8_t *)&local_58 + 0x4)),iVar6);
  p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
  p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
  p_Var18 = p_Var11;
  p_Var23 = p_Var13;
  if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_00119f90:
    lVar12 = 0;
    uVar24 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var18 + 0x20) < iVar6) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var23 = p_Var18;
      }
      p_Var18 = p_Var17;
    } while (p_Var17 != (_Rb_tree_node_base *)0x0);
    if ((p_Var13 == p_Var23) || (p_Var18 = p_Var13, iVar6 < *(int *)(p_Var23 + 0x20)))
    goto LAB_00119f90;
    do {
      if (*(int *)(p_Var11 + 0x20) < iVar6) {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
      }
      else {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
        p_Var18 = p_Var11;
      }
      p_Var11 = p_Var23;
    } while (p_Var23 != (_Rb_tree_node_base *)0x0);
    if ((p_Var13 == p_Var18) || (iVar6 < *(int *)(p_Var18 + 0x20))) {
      p_Var11 = rea_operator_new(0x28);
      if (p_Var11 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var11 = 0;
        *(undefined8 *)(p_Var11 + 8) = 0;
        *(undefined8 *)(p_Var11 + 0x10) = 0;
        *(undefined8 *)(p_Var11 + 0x18) = 0;
        *(undefined4 *)(p_Var11 + 0x24) = 0;
        *(int *)(p_Var11 + 0x20) = (int)local_58;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar22 + 8),p_Var18,p_Var11 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
      p_Var23 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
      p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
      if (p_Var23 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var11);
      }
      else {
        bVar21 = true;
        if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var13 != p_Var23)) {
          bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var23 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var23,p_Var13);
        *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
        p_Var18 = p_Var11;
      }
    }
    uVar24 = *(uint *)(p_Var18 + 0x24);
    lVar12 = 1;
  }
  lVar22 = lVar22 + (lVar12 + 1) * 0x30;
  p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar22 + 8);
  p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(lVar22 + 0x10);
  uVar26 = uVar24;
  if (p_Var13 != (_Rb_tree_node_base *)0x0) {
    p_Var18 = p_Var13;
    p_Var23 = p_Var11;
    do {
      if (*(int *)(p_Var18 + 0x20) < (int)local_58) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var23 = p_Var18;
      }
      p_Var18 = p_Var17;
    } while (p_Var17 != (_Rb_tree_node_base *)0x0);
    if ((p_Var11 != p_Var23) && (p_Var18 = p_Var11, *(int *)(p_Var23 + 0x20) <= (int)local_58)) {
      do {
        if (*(int *)(p_Var13 + 0x20) < (int)local_58) {
          p_Var23 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
        }
        else {
          p_Var23 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
          p_Var18 = p_Var13;
        }
        p_Var13 = p_Var23;
      } while (p_Var23 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var18) || ((int)local_58 < *(int *)(p_Var18 + 0x20))) {
        p_Var13 = rea_operator_new(0x28);
        if (p_Var13 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = (int)local_58;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
        p_Var23 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
        p_Var18 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
        if (p_Var23 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var23)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var23 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var23,p_Var11);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var18 = p_Var13;
        }
      }
      uVar26 = *(uint *)(p_Var18 + 0x24);
    }
  }
  if ((uVar26 & 0xfffffffe) == uVar24) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var2,(int *)&local_58);
    goto LAB_001196ee;
  }
  p_Var13 = p_Var11;
  if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00119efb:
    p_Var18 = rea_operator_new(0x28);
    if (p_Var18 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var18 = 0;
      *(undefined8 *)(p_Var18 + 8) = 0;
      *(undefined8 *)(p_Var18 + 0x10) = 0;
      *(undefined8 *)(p_Var18 + 0x18) = 0;
      *(undefined4 *)(p_Var18 + 0x24) = 0;
      *(int *)(p_Var18 + 0x20) = (int)local_58;
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(p_Var2,p_Var13,p_Var18 + 0x20)); memcpy(auVar27, &__rea_tmp, sizeof(auVar27)); }
    p_Var23 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x8));
    p_Var13 = (*(undefined8 *)((uint8_t *)&auVar27 + 0x0));
    if (p_Var23 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var18);
    }
    else {
      bVar21 = true;
      if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var23)) {
        bVar21 = *(int *)(p_Var18 + 0x20) < *(int *)(p_Var23 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar21,p_Var18,p_Var23,p_Var11);
      *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
      p_Var13 = p_Var18;
    }
  }
  else {
    p_Var18 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    do {
      if (*(int *)(p_Var18 + 0x20) < (int)local_58) {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var13 = p_Var18;
      }
      p_Var18 = p_Var23;
    } while (p_Var23 != (_Rb_tree_node_base *)0x0);
    if ((p_Var11 == p_Var13) || ((int)local_58 < *(int *)(p_Var13 + 0x20))) goto LAB_00119efb;
  }
  *(uint *)(p_Var13 + 0x24) = uVar26 & 0xfffffffe;
LAB_001196ee:
  if ((void *)*plVar7 != (void *)0x0) {
    rea_operator_delete((void *)*plVar7);
  }
  rea_operator_delete(plVar7);
  return;
}





// ------------------------------------------------------------------
// IDX 281  0011a290  TcpClient__TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__TcpClient__dup3(TcpClient * this_ptr, string * param_1, undefined4 param_2, long param_4, long param_5)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  long lVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long *plVar9;
  TcpConn *this_00;
  int *piVar10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  ulong uVar14;
  bool bVar15;
  uint uVar16;
  _Rb_tree_node_base *p_Var17;
  undefined1 auVar18 [16];
  ushort local_b0;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *local_a8;
  int local_88 [4];
  long local_78 [2];
  ulong local_68 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  sockaddr local_48;
  
  local_a8 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 0x38);
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
  *(_Rb_tree_node_base **)(this_ptr + 0x28) = p_Var1;
  *(TcpClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(TcpClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(TcpClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(TcpClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar5 = PTR_vtable_00324f98;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 0;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined **)this_ptr = puVar5 + 0x10;
  if (*(code **)(param_4 + 0x10) != (code *)0x0) {
    (**(code **)(param_4 + 0x10))(this_ptr + 0xa8,param_4,2);
    *(undefined8 *)(this_ptr + 0xc0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this_ptr + 0xb8) = *(undefined8 *)(param_4 + 0x10);
  }
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(this_ptr + 200,param_5,2);
    *(undefined8 *)(this_ptr + 0xe0) = *(undefined8 *)(param_5 + 0x18);
    *(undefined8 *)(this_ptr + 0xd8) = *(undefined8 *)(param_5 + 0x10);
  }
  rea_bzero(&local_48,0x10);
  local_48.sa_family = 2;
  local_48.(*(undefined4 *)((uint8_t *)&sa_data + 0x2)) = rea_inet_addr(*(char **)param_1);
  local_b0 = (ushort)param_2;
  local_48.(*(undefined2 *)((uint8_t *)&sa_data + 0x0)) = local_b0 >> 8 | local_b0 << 8;
  iVar6 = rea_socket(2,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)(this_ptr + 0x98) = 2;
    rea_perror("socket");
    piVar10 = rea___errno_location();
    iVar8 = *piVar10;
    if (*(long *)(param_5 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
LAB_0011a8a1:
    (**(code **)(param_5 + 0x18))(param_5,iVar8);
    return;
  }
  rea_setcloexec(iVar6);
  rea_setnonblock(iVar6);
  local_58 = 1;
  rea_setsockopt(iVar6,6,1,&local_58,4);
  iVar7 = rea_connect(iVar6,&local_48,0x10);
  if (iVar7 < 0) {
    piVar10 = rea___errno_location();
    iVar8 = *piVar10;
    if (iVar8 != 0x73) {
      *(undefined4 *)(this_ptr + 0x98) = 2;
      rea_perror("connect");
      rea_close(iVar6);
      if (*(long *)(param_5 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
        rea_std____throw_bad_function_call();
      }
      goto LAB_0011a8a1;
    }
  }
  rea___gnu_cxx____to_xstring_std__string_char
            ((code *)&local_58,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,(void *)&DAT_0011fd61,param_2);
  rea_std__string__string((string *)local_68,param_1);
  rea_std__string__append((char *)local_68,0x11fcf2);
  uVar14 = *(long *)(local_68[0] - 0x18) + *(long *)(CONCAT44(uStack_54,local_58) + -0x18);
  if ((*(ulong *)(local_68[0] - 0x10) < uVar14) &&
     (uVar14 <= *(ulong *)(CONCAT44(uStack_54,local_58) + -0x10))) {
    plVar9 = (long *)rea_std__string__insert((ulong)&local_58,(char *)0x0,local_68[0]);
  }
  else {
    plVar9 = (long *)rea_std__string__append((string *)local_68);
  }
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  local_78[0] = *plVar9;
  *plVar9 = (long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_68[0] - 0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(local_68[0] - 8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_68[0] - 8);
      *(int *)(local_68[0] - 8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] - 0x18));
    }
  }
  lVar3 = CONCAT44(uStack_54,local_58);
  if ((allocator *)(lVar3 + -0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(lVar3 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(lVar3 + -8);
      *(int *)(lVar3 + -8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar3 + -0x18));
    }
  }
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,iVar6,param_1,(string *)local_78,(EventHandler *)this_ptr);
  plVar9 = *(long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 8))();
  }
  if (iVar7 == 0) {
    *(undefined4 *)(this_ptr + 0x98) = 1;
    if (*(long *)(param_4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (**(code **)(param_4 + 0x18))(param_4,*(undefined8 *)(this_ptr + 0xa0));
    goto LAB_0011a5a3;
  }
  p_Var11 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  p_Var17 = p_Var11;
  p_Var12 = p_Var1;
  local_88[0] = iVar6;
  if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_0011a683:
    uVar16 = 0;
  }
  else {
    do {
      while (p_Var13 = p_Var17, iVar6 <= *(int *)(p_Var13 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a672;
      }
      p_Var2 = p_Var13 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011a672:
    if ((p_Var1 == p_Var13) || (p_Var17 = p_Var1, iVar6 < *(int *)(p_Var13 + 0x20)))
    goto LAB_0011a683;
    do {
      while (p_Var12 = p_Var11, iVar6 <= *(int *)(p_Var12 + 0x20)) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
        p_Var17 = p_Var12;
        if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a8ca;
      }
      p_Var13 = p_Var12 + 0x18;
      p_Var11 = *(_Rb_tree_node_base **)p_Var13;
      p_Var12 = p_Var17;
    } while (*(_Rb_tree_node_base **)p_Var13 != (_Rb_tree_node_base *)0x0);
LAB_0011a8ca:
    if ((p_Var1 == p_Var12) || (iVar6 < *(int *)(p_Var12 + 0x20))) {
      p_Var11 = rea_operator_new(0x28);
      if (p_Var11 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var11 = 0;
        *(undefined8 *)(p_Var11 + 8) = 0;
        *(undefined8 *)(p_Var11 + 0x10) = 0;
        *(undefined8 *)(p_Var11 + 0x18) = 0;
        *(undefined4 *)(p_Var11 + 0x24) = 0;
        *(int *)(p_Var11 + 0x20) = local_88[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var12,p_Var11 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
      p_Var17 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x8));
      p_Var12 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x0));
      if (p_Var17 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var11);
      }
      else {
        bVar15 = true;
        if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var17)) {
          bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var17 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var17,p_Var1);
        *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
        p_Var12 = p_Var11;
      }
    }
    local_a8 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                *)(this_ptr + 0x68);
    uVar16 = *(uint *)(p_Var12 + 0x24);
  }
  p_Var11 = *(_Rb_tree_node_base **)(local_a8 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(local_a8 + 8);
  p_Var17 = p_Var11;
  p_Var12 = p_Var1;
  uVar4 = uVar16;
  if (p_Var11 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var13 = p_Var17, local_88[0] <= *(int *)(p_Var13 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a6ca;
      }
      p_Var2 = p_Var13 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011a6ca:
    if ((p_Var1 != p_Var13) && (p_Var17 = p_Var1, *(int *)(p_Var13 + 0x20) <= local_88[0])) {
      do {
        while (p_Var12 = p_Var11, local_88[0] <= *(int *)(p_Var12 + 0x20)) {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var17 = p_Var12;
          if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011a6fa;
        }
        p_Var13 = p_Var12 + 0x18;
        p_Var11 = *(_Rb_tree_node_base **)p_Var13;
        p_Var12 = p_Var17;
      } while (*(_Rb_tree_node_base **)p_Var13 != (_Rb_tree_node_base *)0x0);
LAB_0011a6fa:
      if ((p_Var1 == p_Var12) || (local_88[0] < *(int *)(p_Var12 + 0x20))) {
        p_Var11 = rea_operator_new(0x28);
        if (p_Var11 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_88[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(local_a8,p_Var12,p_Var11 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
        p_Var17 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x8));
        p_Var12 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x0));
        if (p_Var17 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var11);
        }
        else {
          bVar15 = true;
          if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var17)) {
            bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var17 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var17,p_Var1);
          *(long *)(local_a8 + 0x28) = *(long *)(local_a8 + 0x28) + 1;
          p_Var12 = p_Var11;
        }
      }
      uVar4 = *(uint *)(p_Var12 + 0x24);
    }
  }
  if ((uVar4 | 2) == uVar16) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(local_a8,local_88);
    goto LAB_0011a5a3;
  }
  p_Var11 = *(_Rb_tree_node_base **)(local_a8 + 0x10);
  p_Var12 = p_Var1;
  p_Var17 = p_Var1;
  if (*(_Rb_tree_node_base **)(local_a8 + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0011a7e9:
    p_Var11 = rea_operator_new(0x28);
    if (p_Var11 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var11 = 0;
      *(undefined8 *)(p_Var11 + 8) = 0;
      *(undefined8 *)(p_Var11 + 0x10) = 0;
      *(undefined8 *)(p_Var11 + 0x18) = 0;
      *(undefined4 *)(p_Var11 + 0x24) = 0;
      *(int *)(p_Var11 + 0x20) = local_88[0];
    }
    { auto &&__rea_tmp = (std__________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________________M_get_insert_hint_unique_pos(local_a8,p_Var17,p_Var11 + 0x20)); memcpy(auVar18, &__rea_tmp, sizeof(auVar18)); }
    p_Var12 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x8));
    p_Var17 = (*(undefined8 *)((uint8_t *)&auVar18 + 0x0));
    if (p_Var12 == (_Rb_tree_node_base *)0x0) {
      rea_operator_delete(p_Var11);
    }
    else {
      bVar15 = true;
      if ((p_Var17 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var12)) {
        bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var12 + 0x20);
      }
      rea_std___Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var12,p_Var1);
      *(long *)(local_a8 + 0x28) = *(long *)(local_a8 + 0x28) + 1;
      p_Var17 = p_Var11;
    }
  }
  else {
    do {
      while (p_Var17 = p_Var11, local_88[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var12 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a7da;
      }
      p_Var13 = p_Var17 + 0x18;
      p_Var11 = *(_Rb_tree_node_base **)p_Var13;
      p_Var17 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var13 != (_Rb_tree_node_base *)0x0);
LAB_0011a7da:
    if ((p_Var1 == p_Var17) || (local_88[0] < *(int *)(p_Var17 + 0x20))) goto LAB_0011a7e9;
  }
  *(uint *)(p_Var17 + 0x24) = uVar4 | 2;
LAB_0011a5a3:
  if ((allocator *)(local_78[0] + -0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(local_78[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar6 = *(int *)(local_78[0] + -8);
      *(int *)(local_78[0] + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_78[0] + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 282  0011ac10  TcpConn__send_proc
// ------------------------------------------------------------------
void rea_TcpConn__send_proc__dup2(TcpConn * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  void *__src;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var2;
  undefined8 *puVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  ssize_t sVar10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  void *__dest;
  int *piVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  long lVar18;
  _Rb_tree_node_base *p_Var19;
  uint uVar20;
  undefined1 auVar21 [16];
  int local_78 [4];
  int local_68 [4];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  
  if (this_ptr[0x5a] == (TcpConn)0x0) {
    rea_fprintf(*(FILE **)PTR_stderr_00324fb0,"TcpConn: bogus send: fd=%d\n",
            (ulong)*(uint *)(this_ptr + 0x40));
    return;
  }
  puVar3 = *(undefined8 **)(this_ptr + 0x60);
  if (puVar3 == (undefined8 *)0x0) {
    this_ptr[0x59] = (TcpConn)0x0;
    rea_shutdown(*(int *)(this_ptr + 0x40),1);
    lVar18 = *(long *)(this_ptr + 0x38);
    local_68[0] = *(int *)(this_ptr + 0x40);
    this_ptr[0x5a] = (TcpConn)0x0;
    p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var16 = p_Var14;
    p_Var19 = p_Var12;
    if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0011b430:
      lVar11 = 0;
      uVar20 = 0;
    }
    else {
      do {
        while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < local_68[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var19;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011b17b;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var19 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011b17b:
      if ((p_Var12 == p_Var15) || (p_Var16 = p_Var12, local_68[0] < *(int *)(p_Var15 + 0x20)))
      goto LAB_0011b430;
      do {
        if (*(int *)(p_Var14 + 0x20) < local_68[0]) {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
        }
        else {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
          p_Var16 = p_Var14;
        }
        p_Var14 = p_Var19;
      } while (p_Var19 != (_Rb_tree_node_base *)0x0);
      if ((p_Var12 == p_Var16) || (local_68[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var14 = rea_operator_new(0x28);
        if (p_Var14 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_68[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar18 + 8),p_Var16,p_Var14 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
        p_Var19 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
        if (p_Var19 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var14);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var19)) {
            bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var19,p_Var12);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var16 = p_Var14;
        }
      }
      uVar20 = *(uint *)(p_Var16 + 0x24);
      lVar11 = 1;
    }
    lVar18 = lVar18 + (lVar11 + 1) * 0x30;
    p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar18 + 8);
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var14 = p_Var12;
    p_Var16 = p_Var19;
    uVar9 = uVar20;
    if (p_Var12 != (_Rb_tree_node_base *)0x0) {
      do {
        while (p_Var15 = p_Var14, *(int *)(p_Var15 + 0x20) < local_68[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011b21b;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var16 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011b21b:
      if ((p_Var19 != p_Var15) && (p_Var14 = p_Var19, *(int *)(p_Var15 + 0x20) <= local_68[0])) {
        do {
          if (*(int *)(p_Var12 + 0x20) < local_68[0]) {
            p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
          }
          else {
            p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
            p_Var14 = p_Var12;
          }
          p_Var12 = p_Var16;
        } while (p_Var16 != (_Rb_tree_node_base *)0x0);
        if ((p_Var19 == p_Var14) || (local_68[0] < *(int *)(p_Var14 + 0x20))) {
          p_Var12 = rea_operator_new(0x28);
          if (p_Var12 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var12 = 0;
            *(undefined8 *)(p_Var12 + 8) = 0;
            *(undefined8 *)(p_Var12 + 0x10) = 0;
            *(undefined8 *)(p_Var12 + 0x18) = 0;
            *(undefined4 *)(p_Var12 + 0x24) = 0;
            *(int *)(p_Var12 + 0x20) = local_68[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
          p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
          p_Var14 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
          if (p_Var16 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var12);
          }
          else {
            bVar17 = true;
            if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var16)) {
              bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
            *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
            p_Var14 = p_Var12;
          }
        }
        uVar9 = *(uint *)(p_Var14 + 0x24);
      }
    }
    if ((uVar9 & 0xfffffffd) == uVar20) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var2,local_68);
      goto LAB_0011b3a6;
    }
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var14 = p_Var19;
    if (p_Var12 == (_Rb_tree_node_base *)0x0) {
LAB_0011b32a:
      p_Var12 = rea_operator_new(0x28);
      if (p_Var12 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_68[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
      p_Var14 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var12);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var16)) {
          bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var14 = p_Var12;
      }
    }
    else {
      do {
        if (*(int *)(p_Var12 + 0x20) < local_68[0]) {
          p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
        }
        else {
          p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var14 = p_Var12;
        }
        p_Var12 = p_Var16;
      } while (p_Var16 != (_Rb_tree_node_base *)0x0);
      if ((p_Var19 == p_Var14) || (local_68[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0011b32a;
    }
    *(uint *)(p_Var14 + 0x24) = uVar9 & 0xfffffffd;
LAB_0011b3a6:
    uVar5 = *(undefined8 *)(this_ptr + 0x70);
    uVar6 = *(undefined8 *)(this_ptr + 0x68);
    *(undefined8 *)(this_ptr + 0x70) = local_50;
    local_48 = *(code **)(this_ptr + 0x78);
    *(undefined8 *)(this_ptr + 0x68) = local_58;
    pcVar7 = *(code **)(this_ptr + 0x80);
    *(undefined8 *)(this_ptr + 0x78) = 0;
    *(code **)(this_ptr + 0x80) = local_40;
    local_58 = uVar6;
    local_50 = uVar5;
    local_40 = pcVar7;
    if (local_48 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (*pcVar7)(&local_58);
    if (local_48 == (code *)0x0) {
      return;
    }
    (*local_48)(&local_58,&local_58,3);
    return;
  }
  sVar10 = rea_write(*(int *)(this_ptr + 0x40),(void *)*puVar3,puVar3[1] - (long)*puVar3);
  iVar8 = (int)sVar10;
  if (iVar8 == -1) {
    piVar13 = rea___errno_location();
    if (*piVar13 == 0xb) {
      return;
    }
  }
  else if (-1 < iVar8) {
    puVar3 = *(undefined8 **)(this_ptr + 0x60);
    pvVar4 = (void *)puVar3[1];
    __dest = (void *)*puVar3;
    if ((ulong)(long)iVar8 < (ulong)((long)pvVar4 - (long)__dest)) {
      __src = (void *)((long)__dest + (long)iVar8);
      if (__dest == __src) {
        return;
      }
      lVar18 = 0;
      if ((pvVar4 != __src) && ((long)pvVar4 - (long)__src != 0)) {
        __dest = rea_memmove(__dest,__src,(long)pvVar4 - (long)__src);
        lVar18 = puVar3[1] - (long)__src;
      }
      puVar3[1] = lVar18 + (long)__dest;
      return;
    }
    lVar18 = *(long *)(this_ptr + 0x38);
    local_78[0] = *(int *)(this_ptr + 0x40);
    this_ptr[0x5a] = (TcpConn)0x0;
    p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var16 = p_Var14;
    p_Var19 = p_Var12;
    if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0011acc9:
      lVar11 = 0;
      uVar20 = 0;
    }
    else {
      do {
        while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < local_78[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var19;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011acbb;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var19 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011acbb:
      if ((p_Var12 == p_Var15) || (p_Var16 = p_Var12, local_78[0] < *(int *)(p_Var15 + 0x20)))
      goto LAB_0011acc9;
      do {
        while (p_Var19 = p_Var14, *(int *)(p_Var19 + 0x20) < local_78[0]) {
          p_Var15 = p_Var19 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var15;
          p_Var19 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var15 == (_Rb_tree_node_base *)0x0) goto LAB_0011aceb;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var16 = p_Var19;
      } while (*(_Rb_tree_node_base **)(p_Var19 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011aceb:
      if ((p_Var12 == p_Var19) || (local_78[0] < *(int *)(p_Var19 + 0x20))) {
        p_Var14 = rea_operator_new(0x28);
        if (p_Var14 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_78[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(lVar18 + 8),p_Var19,p_Var14 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
        p_Var19 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
        if (p_Var16 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var14);
        }
        else {
          bVar17 = true;
          if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var16)) {
            bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var16 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var16,p_Var12);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var19 = p_Var14;
        }
      }
      uVar20 = *(uint *)(p_Var19 + 0x24);
      lVar11 = 1;
    }
    lVar18 = lVar18 + (lVar11 + 1) * 0x30;
    p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(lVar18 + 8);
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var14 = p_Var12;
    p_Var16 = p_Var19;
    uVar9 = uVar20;
    if (p_Var12 != (_Rb_tree_node_base *)0x0) {
      do {
        while (p_Var15 = p_Var14, *(int *)(p_Var15 + 0x20) < local_78[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011ad5b;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var16 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011ad5b:
      if ((p_Var19 != p_Var15) && (p_Var14 = p_Var19, *(int *)(p_Var15 + 0x20) <= local_78[0])) {
        do {
          while (p_Var16 = p_Var12, *(int *)(p_Var16 + 0x20) < local_78[0]) {
            p_Var15 = p_Var16 + 0x18;
            p_Var12 = *(_Rb_tree_node_base **)p_Var15;
            p_Var16 = p_Var14;
            if (*(_Rb_tree_node_base **)p_Var15 == (_Rb_tree_node_base *)0x0) goto LAB_0011af4b;
          }
          p_Var12 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
          p_Var14 = p_Var16;
        } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011af4b:
        if ((p_Var19 == p_Var16) || (local_78[0] < *(int *)(p_Var16 + 0x20))) {
          p_Var12 = rea_operator_new(0x28);
          if (p_Var12 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var12 = 0;
            *(undefined8 *)(p_Var12 + 8) = 0;
            *(undefined8 *)(p_Var12 + 0x10) = 0;
            *(undefined8 *)(p_Var12 + 0x18) = 0;
            *(undefined4 *)(p_Var12 + 0x24) = 0;
            *(int *)(p_Var12 + 0x20) = local_78[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var2,p_Var16,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
          p_Var14 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
          p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
          if (p_Var14 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var12);
          }
          else {
            bVar17 = true;
            if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var14)) {
              bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var14 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var14,p_Var19);
            *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
            p_Var16 = p_Var12;
          }
        }
        uVar9 = *(uint *)(p_Var16 + 0x24);
      }
    }
    if ((uVar9 & 0xfffffffd) == uVar20) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var2,local_78);
      goto LAB_0011ae38;
    }
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var16 = p_Var19;
    p_Var14 = p_Var19;
    if (*(_Rb_tree_node_base **)(lVar18 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0011adbc:
      p_Var12 = rea_operator_new(0x28);
      if (p_Var12 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_78[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
      p_Var14 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var12);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var16)) {
          bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var14 = p_Var12;
      }
    }
    else {
      do {
        while (p_Var14 = p_Var12, *(int *)(p_Var14 + 0x20) < local_78[0]) {
          p_Var15 = p_Var14 + 0x18;
          p_Var12 = *(_Rb_tree_node_base **)p_Var15;
          p_Var14 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var15 == (_Rb_tree_node_base *)0x0) goto LAB_0011adb2;
        }
        p_Var12 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
        p_Var16 = p_Var14;
      } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011adb2:
      if ((p_Var19 == p_Var14) || (local_78[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0011adbc;
    }
    *(uint *)(p_Var14 + 0x24) = uVar9 & 0xfffffffd;
LAB_0011ae38:
    puVar3 = *(undefined8 **)(this_ptr + 0x60);
    *(undefined8 *)(this_ptr + 0x60) = 0;
    if (puVar3 != (undefined8 *)0x0) {
      if ((void *)*puVar3 != (void *)0x0) {
        rea_operator_delete((void *)*puVar3);
      }
      rea_operator_delete(puVar3);
    }
    uVar5 = *(undefined8 *)(this_ptr + 0x70);
    uVar6 = *(undefined8 *)(this_ptr + 0x68);
    *(undefined8 *)(this_ptr + 0x70) = local_50;
    local_48 = *(code **)(this_ptr + 0x78);
    *(undefined8 *)(this_ptr + 0x68) = local_58;
    pcVar7 = *(code **)(this_ptr + 0x80);
    *(undefined8 *)(this_ptr + 0x78) = 0;
    *(code **)(this_ptr + 0x80) = local_40;
    local_58 = uVar6;
    local_50 = uVar5;
    local_40 = pcVar7;
    if (local_48 != (code *)0x0) {
      (*pcVar7)(&local_58);
      if (local_48 == (code *)0x0) {
        return;
      }
      (*local_48)(&local_58,&local_58,3);
      return;
    }
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  rea_perror("tcp send");
  lVar18 = *(long *)(this_ptr + 0x38);
  iVar8 = *(int *)(this_ptr + 0x40);
  this_ptr[0x58] = (TcpConn)0x0;
  this_ptr[0x59] = (TcpConn)0x0;
  this_ptr[0x5a] = (TcpConn)0x0;
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  local_58 = CONCAT44((*(undefined4 *)((uint8_t *)&local_58 + 0x4)),iVar8);
  p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var16 = p_Var14;
  p_Var19 = p_Var12;
  if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0011b44e:
    lVar11 = 0;
    uVar20 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var16 + 0x20) < iVar8) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var19 = p_Var16;
      }
      p_Var16 = p_Var15;
    } while (p_Var15 != (_Rb_tree_node_base *)0x0);
    if ((p_Var12 == p_Var19) || (p_Var16 = p_Var12, iVar8 < *(int *)(p_Var19 + 0x20)))
    goto LAB_0011b44e;
    do {
      if (*(int *)(p_Var14 + 0x20) < iVar8) {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
      }
      else {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
        p_Var16 = p_Var14;
      }
      p_Var14 = p_Var19;
    } while (p_Var19 != (_Rb_tree_node_base *)0x0);
    if ((p_Var12 == p_Var16) || (iVar8 < *(int *)(p_Var16 + 0x20))) {
      p_Var14 = rea_operator_new(0x28);
      if (p_Var14 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var14 = 0;
        *(undefined8 *)(p_Var14 + 8) = 0;
        *(undefined8 *)(p_Var14 + 0x10) = 0;
        *(undefined8 *)(p_Var14 + 0x18) = 0;
        *(undefined4 *)(p_Var14 + 0x24) = 0;
        *(int *)(p_Var14 + 0x20) = (int)local_58;
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(lVar18 + 8),p_Var16,p_Var14 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
      p_Var19 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
      p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
      if (p_Var19 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var14);
      }
      else {
        bVar17 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var19)) {
          bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var19,p_Var12);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var16 = p_Var14;
      }
    }
    uVar20 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar18 = lVar18 + (lVar11 + 1) * 0x30;
  p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(lVar18 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  uVar9 = uVar20;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    p_Var16 = p_Var12;
    p_Var19 = p_Var14;
    do {
      if (*(int *)(p_Var16 + 0x20) < (int)local_58) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var19 = p_Var16;
      }
      p_Var16 = p_Var15;
    } while (p_Var15 != (_Rb_tree_node_base *)0x0);
    if ((p_Var14 != p_Var19) && (p_Var16 = p_Var14, *(int *)(p_Var19 + 0x20) <= (int)local_58)) {
      do {
        if (*(int *)(p_Var12 + 0x20) < (int)local_58) {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
        }
        else {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var16 = p_Var12;
        }
        p_Var12 = p_Var19;
      } while (p_Var19 != (_Rb_tree_node_base *)0x0);
      if ((p_Var14 == p_Var16) || ((int)local_58 < *(int *)(p_Var16 + 0x20))) {
        p_Var12 = rea_operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = (int)local_58;
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var2,p_Var16,p_Var12 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
        p_Var19 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
        p_Var16 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
        if (p_Var19 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var12);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var19)) {
            bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var19 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var19,p_Var14);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var16 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var16 + 0x24);
    }
  }
  if ((uVar9 & 0xfffffffd) == uVar20) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var2,(int *)&local_58);
    return;
  }
  p_Var12 = p_Var14;
  if (*(_Rb_tree_node_base **)(lVar18 + 0x18) != (_Rb_tree_node_base *)0x0) {
    p_Var16 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    do {
      if (*(int *)(p_Var16 + 0x20) < (int)local_58) {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var12 = p_Var16;
      }
      p_Var16 = p_Var19;
    } while (p_Var19 != (_Rb_tree_node_base *)0x0);
    if ((p_Var14 != p_Var12) && (*(int *)(p_Var12 + 0x20) <= (int)local_58)) goto LAB_0011b77d;
  }
  p_Var16 = rea_operator_new(0x28);
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var16 = 0;
    *(undefined8 *)(p_Var16 + 8) = 0;
    *(undefined8 *)(p_Var16 + 0x10) = 0;
    *(undefined8 *)(p_Var16 + 0x18) = 0;
    *(undefined4 *)(p_Var16 + 0x24) = 0;
    *(int *)(p_Var16 + 0x20) = (int)local_58;
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(p_Var2,p_Var12,p_Var16 + 0x20)); memcpy(auVar21, &__rea_tmp, sizeof(auVar21)); }
  p_Var19 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x8));
  p_Var12 = (*(undefined8 *)((uint8_t *)&auVar21 + 0x0));
  if (p_Var19 == (_Rb_tree_node_base *)0x0) {
    rea_operator_delete(p_Var16);
  }
  else {
    bVar17 = true;
    if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var19)) {
      bVar17 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var19 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar17,p_Var16,p_Var19,p_Var14);
    *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
    p_Var12 = p_Var16;
  }
LAB_0011b77d:
  *(uint *)(p_Var12 + 0x24) = uVar9 & 0xfffffffd;
  return;
}





// ------------------------------------------------------------------
// IDX 283  0011b9f0  TcpServer__poll
// ------------------------------------------------------------------
undefined8 rea_TcpServer__poll(TcpServer * this_ptr, int param_1, int param_2)
{
  _Rb_tree_node_base *p_Var1;
  TcpServer *pTVar2;
  int *piVar3;
  undefined *puVar4;
  _Rb_tree_node_base *p_Var5;
  TcpServer *pTVar6;
  int iVar7;
  void *pvVar8;
  char *pcVar9;
  long *plVar10;
  TcpConn *this_00;
  TcpServer *pTVar11;
  ulong uVar12;
  TcpServer *pTVar13;
  TcpServer *pTVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  bool bVar18;
  undefined1 local_b9;
  socklen_t local_b8 [4];
  int local_a8 [4];
  long local_98 [2];
  long local_88 [2];
  ulong local_78 [2];
  long local_68 [2];
  int *local_58 [2];
  undefined1 local_48 [24];
  
  if ((*(int *)(this_ptr + 0xb8) != param_1) || ((param_2 & 1U) == 0)) goto LAB_0011ba1e;
  local_b8[0] = 0x10;
  local_a8[0] = rea_accept(*(int *)(this_ptr + 0xb8),(sockaddr *)local_48,local_b8);
  if (local_a8[0] < 0) {
    rea_perror("accept");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setnonblock(local_a8[0]);
  rea_setcloexec(local_a8[0]);
  local_58[0] = (int *)CONCAT44(local_58[0]._4_4_,1);
  rea_setsockopt(local_a8[0],6,1,(allocator *)local_58,4);
  pcVar9 = rea_inet_ntoa((in_addr)(*(undefined4 *)((uint8_t *)&local_48 + 0x4)));
  rea_std__string__string((string *)local_98,pcVar9,(allocator *)local_58);
  rea___gnu_cxx____to_xstring_std__string_char
            ((code *)local_68,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,(void *)&DAT_0011fd61,
             (ulong)(ushort)((ushort)(*(undefined2 *)((uint8_t *)&local_48 + 0x2)) >> 8 | (*(undefined2 *)((uint8_t *)&local_48 + 0x2)) << 8));
  rea_std__string__string((string *)local_78,(string *)local_98);
  rea_std__string__append((char *)local_78,0x11fcf2);
  uVar12 = *(long *)(local_78[0] - 0x18) + *(long *)(local_68[0] + -0x18);
  if ((*(ulong *)(local_78[0] - 0x10) < uVar12) && (uVar12 <= *(ulong *)(local_68[0] + -0x10))) {
    plVar10 = (long *)rea_std__string__insert((ulong)local_68,(char *)0x0,local_78[0]);
  }
  else {
    plVar10 = (long *)rea_std__string__append((string *)local_78);
  }
  puVar4 = PTR__S_empty_rep_storage_00324fa0;
  local_88[0] = *plVar10;
  *plVar10 = (long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_78[0] - 0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_78[0] - 8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_78[0] - 8);
      *(int *)(local_78[0] - 8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_78[0] - 0x18));
    }
  }
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,local_a8[0],(string *)local_98,(string *)local_88,(EventHandler *)this_ptr);
  pTVar14 = this_ptr + 200;
  pTVar6 = *(TcpServer **)(this_ptr + 0xd0);
  pTVar13 = pTVar14;
  if (*(TcpServer **)(this_ptr + 0xd0) == (TcpServer *)0x0) {
LAB_0011bd19:
    local_58[0] = local_a8;
    pTVar11 = (TcpServer *)
              std__________________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________________________________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple__________________________(this_ptr + 0xc0,pTVar14,(void *)&DAT_0011fdcc,(allocator *)local_58,&local_b9);
  }
  else {
    do {
      while (pTVar11 = pTVar6, *(int *)(pTVar11 + 0x20) < local_a8[0]) {
        pTVar2 = pTVar11 + 0x18;
        pTVar6 = *(TcpServer **)pTVar2;
        pTVar11 = pTVar13;
        if (*(TcpServer **)pTVar2 == (TcpServer *)0x0) goto LAB_0011bcaa;
      }
      pTVar6 = *(TcpServer **)(pTVar11 + 0x10);
      pTVar13 = pTVar11;
    } while (*(TcpServer **)(pTVar11 + 0x10) != (TcpServer *)0x0);
LAB_0011bcaa:
    bVar18 = pTVar14 == pTVar11;
    pTVar14 = pTVar11;
    if ((bVar18) || (local_a8[0] < *(int *)(pTVar11 + 0x20))) goto LAB_0011bd19;
  }
  plVar10 = *(long **)(pTVar11 + 0x28);
  *(TcpConn **)(pTVar11 + 0x28) = this_00;
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 8))();
  }
  if (*(long *)(this_ptr + 0xa8) == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  (**(code **)(this_ptr + 0xb0))(this_ptr + 0x98,this_00);
  if ((allocator *)(local_88[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_88[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_88[0] + -8);
      *(int *)(local_88[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_88[0] + -0x18));
    }
  }
  if ((allocator *)(local_98[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_98[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_98[0] + -8);
      *(int *)(local_98[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_98[0] + -0x18));
    }
  }
LAB_0011ba1e:
  p_Var17 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var5 = *(_Rb_tree_node_base **)(this_ptr + 0xd0);
  p_Var15 = p_Var17;
  if (*(_Rb_tree_node_base **)(this_ptr + 0xd0) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var16 = p_Var5, *(int *)(p_Var16 + 0x20) < param_1) {
        p_Var1 = p_Var16 + 0x18;
        p_Var5 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011ba4a;
      }
      p_Var5 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var15 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011ba4a:
    if ((p_Var17 != p_Var16) && (*(int *)(p_Var16 + 0x20) <= param_1)) {
      if ((param_2 & 2U) != 0) {
        rea_TcpConn__send_proc(*(TcpConn **)(p_Var16 + 0x28));
      }
      if ((param_2 & 1U) != 0) {
        rea_TcpConn__recv_proc(*(TcpConn **)(p_Var16 + 0x28));
      }
      if ((*(char *)(*(long *)(p_Var16 + 0x28) + 0x58) == '\0') &&
         (*(char *)(*(long *)(p_Var16 + 0x28) + 0x59) == '\0')) {
        pvVar8 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var16,p_Var17);
        if (*(long **)((long)pvVar8 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar8 + 0x28) = 0;
        rea_operator_delete(pvVar8);
        *(long *)(this_ptr + 0xe8) = *(long *)(this_ptr + 0xe8) + -1;
      }
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 284  0011bf00  TcpClient__poll
// ------------------------------------------------------------------
byte rea_TcpClient__poll(TcpClient * this_ptr, int param_1, int param_2)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  long lVar7;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  bool bVar10;
  TcpConn *this_00;
  _Rb_tree_node_base *p_Var11;
  uint uVar12;
  undefined1 auVar13 [16];
  int local_78 [4];
  socklen_t local_68 [4];
  int local_58 [4];
  int local_48 [6];
  
  if (*(int *)(this_ptr + 0x98) == 1) {
    this_00 = *(TcpConn **)(this_ptr + 0xa0);
    if (*(int *)(this_00 + 0x40) == param_1) {
      if ((param_2 & 2U) != 0) {
        rea_TcpConn__send_proc(this_00);
        this_00 = *(TcpConn **)(this_ptr + 0xa0);
      }
      if ((param_2 & 1U) != 0) {
        rea_TcpConn__recv_proc(this_00);
        this_00 = *(TcpConn **)(this_ptr + 0xa0);
      }
    }
    if (this_00[0x58] != (TcpConn)0x0) {
      return 0;
    }
    return (byte)this_00[0x59] ^ 1;
  }
  if (*(int *)(this_ptr + 0x98) == 2) {
    return 1;
  }
  if (param_1 != *(int *)(*(long *)(this_ptr + 0xa0) + 0x40)) {
    return 0;
  }
  if ((param_2 & 2U) == 0) {
    return 0;
  }
  local_68[0] = 4;
  rea_getsockopt(param_1,1,4,local_78,local_68);
  iVar2 = local_78[0];
  if (local_78[0] == 0) {
    p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
    *(undefined4 *)(this_ptr + 0x98) = 1;
    p_Var9 = (_Rb_tree_node_base *)(this_ptr + 0x10);
    p_Var5 = p_Var6;
    p_Var11 = p_Var9;
    local_48[0] = param_1;
    if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011c67d:
      lVar7 = 0;
      uVar12 = 0;
    }
    else {
      do {
        if (*(int *)(p_Var5 + 0x20) < param_1) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
          p_Var11 = p_Var5;
        }
        p_Var5 = p_Var8;
      } while (p_Var8 != (_Rb_tree_node_base *)0x0);
      if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
      goto LAB_0011c67d;
      do {
        if (*(int *)(p_Var6 + 0x20) < param_1) {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var11;
      } while (p_Var11 != (_Rb_tree_node_base *)0x0);
      if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(this_ptr + 8),p_Var5,p_Var6 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var11 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
        p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
        if (p_Var11 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var5 == (_Rb_tree_node_base *)0x0) && (p_Var9 != p_Var11)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
          *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
          p_Var5 = p_Var6;
        }
      }
      uVar12 = *(uint *)(p_Var5 + 0x24);
      lVar7 = 1;
    }
    lVar7 = lVar7 + 1;
    p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + lVar7 * 0x30 + 8);
    p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
    p_Var11 = (_Rb_tree_node_base *)(this_ptr + lVar7 * 0x30 + 0x10);
    p_Var6 = p_Var9;
    p_Var5 = p_Var11;
    uVar3 = uVar12;
    if (p_Var9 != (_Rb_tree_node_base *)0x0) {
      do {
        if (*(int *)(p_Var6 + 0x20) < local_48[0]) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var8;
      } while (p_Var8 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_48[0])) {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != (_Rb_tree_node_base *)0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) {
          p_Var9 = rea_operator_new(0x28);
          if (p_Var9 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var9 = 0;
            *(undefined8 *)(p_Var9 + 8) = 0;
            *(undefined8 *)(p_Var9 + 0x10) = 0;
            *(undefined8 *)(p_Var9 + 0x18) = 0;
            *(undefined4 *)(p_Var9 + 0x24) = 0;
            *(int *)(p_Var9 + 0x20) = local_48[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
          p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
          p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
          if (p_Var5 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var9);
          }
          else {
            bVar10 = true;
            if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
              bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
            *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
            p_Var6 = p_Var9;
          }
        }
        uVar3 = *(uint *)(p_Var6 + 0x24);
      }
    }
    if ((uVar3 & 0xfffffffd) == uVar12) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var1,local_48);
    }
    else {
      p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
      p_Var6 = p_Var11;
      if (p_Var9 == (_Rb_tree_node_base *)0x0) {
LAB_0011c5d8:
        p_Var9 = rea_operator_new(0x28);
        if (p_Var9 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
        p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
        if (p_Var5 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      else {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != (_Rb_tree_node_base *)0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011c5d8;
      }
      *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
    }
    if (*(long *)(this_ptr + 0xb8) != 0) {
      (**(code **)(this_ptr + 0xc0))(this_ptr + 0xa8,*(undefined8 *)(this_ptr + 0xa0));
      return 0;
    }
    goto LAB_0011c811;
  }
  *(undefined4 *)(this_ptr + 0x98) = 2;
  p_Var9 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  piVar4 = rea___errno_location();
  *piVar4 = iVar2;
  rea_perror("connect");
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  p_Var5 = p_Var6;
  p_Var11 = p_Var9;
  local_58[0] = param_1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011c687:
    lVar7 = 0;
    uVar12 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var5 + 0x20) < param_1) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
        p_Var11 = p_Var5;
      }
      p_Var5 = p_Var8;
    } while (p_Var8 != (_Rb_tree_node_base *)0x0);
    if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
    goto LAB_0011c687;
    do {
      if (*(int *)(p_Var6 + 0x20) < param_1) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var11;
    } while (p_Var11 != (_Rb_tree_node_base *)0x0);
    if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_58[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var5,p_Var6 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
      p_Var11 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
      p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
      if (p_Var11 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var5 == (_Rb_tree_node_base *)0x0) && (p_Var9 != p_Var11)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
        *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
        p_Var5 = p_Var6;
      }
    }
    uVar12 = *(uint *)(p_Var5 + 0x24);
    lVar7 = 1;
  }
  lVar7 = lVar7 + 1;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(this_ptr + lVar7 * 0x30 + 8);
  p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(this_ptr + lVar7 * 0x30 + 0x10);
  p_Var6 = p_Var9;
  p_Var5 = p_Var11;
  uVar3 = uVar12;
  if (p_Var9 != (_Rb_tree_node_base *)0x0) {
    do {
      if (*(int *)(p_Var6 + 0x20) < local_58[0]) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var8;
    } while (p_Var8 != (_Rb_tree_node_base *)0x0);
    if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_58[0])) {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) {
        p_Var9 = rea_operator_new(0x28);
        if (p_Var9 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_58[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
        p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
        if (p_Var5 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      uVar3 = *(uint *)(p_Var6 + 0x24);
    }
  }
  if ((uVar3 & 0xfffffffd) == uVar12) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,local_58);
  }
  else {
    p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
    p_Var6 = p_Var11;
    if (p_Var9 == (_Rb_tree_node_base *)0x0) {
LAB_0011c529:
      p_Var9 = rea_operator_new(0x28);
      if (p_Var9 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var9 = 0;
        *(undefined8 *)(p_Var9 + 8) = 0;
        *(undefined8 *)(p_Var9 + 0x10) = 0;
        *(undefined8 *)(p_Var9 + 0x18) = 0;
        *(undefined4 *)(p_Var9 + 0x24) = 0;
        *(int *)(p_Var9 + 0x20) = local_58[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
      p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
      p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
      if (p_Var5 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var9);
      }
      else {
        bVar10 = true;
        if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
          bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
        *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
        p_Var6 = p_Var9;
      }
    }
    else {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011c529;
    }
    *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
  }
  if (*(long *)(this_ptr + 0xd8) != 0) {
    (**(code **)(this_ptr + 0xe0))(this_ptr + 200,local_78[0]);
    return 1;
  }
LAB_0011c811:
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 285  0011c820  EventHandler__idle
// ------------------------------------------------------------------
undefined8 rea_EventHandler__idle(void)
{
  return 0;
}





// ------------------------------------------------------------------
// IDX 286  0011c830  __gnu_cxx____to_xstring_std__string_char
// ------------------------------------------------------------------
code * rea___gnu_cxx____to_xstring_std__string_char__dup2(code * param_1, ulong param_2, char * param_3, undefined8 param_x3)
{
  undefined8 stack0x00000008;
  undefined1 *__src;
  long lVar1;
  char in_AL;
  int iVar2;
  ulong *puVar3;
  ulong *__dest;
  undefined8 in_RCX;
  undefined8 in_R8;
  undefined8 in_R9;
  ulong __n;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  undefined8 uStack_100;
  allocator local_f1;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 *local_e8;
  undefined1 *local_e0;
  undefined1 local_d8 [32];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  
  if (in_AL != '\0') {
    local_a8 = in_XMM0_Qa;
    local_98 = in_XMM1_Qa;
    local_88 = in_XMM2_Qa;
    local_78 = in_XMM3_Qa;
    local_68 = in_XMM4_Qa;
    local_58 = in_XMM5_Qa;
    local_48 = in_XMM6_Qa;
    local_38 = in_XMM7_Qa;
  }
  local_e8 = (void *)&stack0x00000008;
  lVar1 = -((ulong)(param_3 + 0x1e) & 0xfffffffffffffff0);
  local_e0 = local_d8;
  __src = (undefined1 *)((long)&local_f0 + lVar1);
  local_f0 = 0x20;
  local_ec = 0x30;
  local_b8 = in_R8;
  local_b0 = in_R9;
  *(undefined8 *)((long)&uStack_100 + lVar1) = 0x11c8d4;
  iVar2 = (*(code *)param_2)(__src,param_3,in_RCX,&local_f0);
  if (__src == __src + iVar2) {
    __dest = (ulong *)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  }
  else {
    __n = (long)(__src + iVar2) - (long)__src;
    *(undefined8 *)((long)&uStack_100 + lVar1) = 0x11c8f3;
    puVar3 = (ulong *)rea_std__string___Rep___S_create(__n,0,&local_f1);
    __dest = puVar3 + 3;
    if (__n == 1) {
      *(undefined1 *)(puVar3 + 3) = *__src;
    }
    else {
      *(undefined8 *)((long)&uStack_100 + lVar1) = 0x11c90e;
      __dest = rea_memcpy(__dest,__src,__n);
    }
    if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00324fa0) {
      *(undefined4 *)(puVar3 + 2) = 0;
      *puVar3 = __n;
      *(undefined1 *)((long)puVar3 + __n + 0x18) = 0;
    }
  }
  *(ulong **)param_1 = __dest;
  return param_1;
}





// ------------------------------------------------------------------
// IDX 287  0011c960  EventHandler__dtor_EventHandler
// ------------------------------------------------------------------
void rea_EventHandler__dtor_EventHandler__dup2(EventHandler * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  EventHandler *pEVar3;
  
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  pEVar3 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pEVar3 + -0x30);
    pvVar2 = *(void **)(pEVar3 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pEVar3 = (EventHandler *)this_00;
  } while (this_ptr + 0x38 != (EventHandler *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 288  0011c9e0  EventHandler__dtor_EventHandler
// ------------------------------------------------------------------
void rea_EventHandler__dtor_EventHandler__dup3(EventHandler * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  EventHandler *pEVar3;
  
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  pEVar3 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pEVar3 + -0x30);
    pvVar2 = *(void **)(pEVar3 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pEVar3 = (EventHandler *)this_00;
  } while (this_ptr + 0x38 != (EventHandler *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 289  0011ca70  std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple____________
// ------------------------------------------------------------------
_Rb_tree_node_base * rea_std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple(long param_1, _Rb_tree_node_base * param_2, undefined8 param_3, undefined8 * param_4)
{
  _Rb_tree_node_base *p_Var1;
  undefined4 uVar2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  int iVar7;
  bool bVar8;
  int iVar9;
  
  p_Var3 = rea_operator_new(0x30);
  if (p_Var3 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var3 = 0;
    *(undefined8 *)(p_Var3 + 8) = 0;
    *(undefined8 *)(p_Var3 + 0x10) = 0;
    *(undefined8 *)(p_Var3 + 0x18) = 0;
    uVar2 = *(undefined4 *)*param_4;
    *(undefined8 *)(p_Var3 + 0x28) = 0;
    *(undefined4 *)(p_Var3 + 0x20) = uVar2;
  }
  p_Var1 = (_Rb_tree_node_base *)(param_1 + 8);
  p_Var6 = p_Var1;
  if (p_Var1 == param_2) {
    if ((*(long *)(param_1 + 0x28) == 0) ||
       (p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x20),
       *(int *)(p_Var3 + 0x20) <= *(int *)(p_Var4 + 0x20))) {
      if (*(_Rb_tree_node_base **)(param_1 + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0011cd23:
        if (*(_Rb_tree_node_base **)(param_1 + 0x18) == p_Var6) goto LAB_0011cc9e;
        param_2 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var6);
        iVar9 = *(int *)(p_Var3 + 0x20);
        iVar7 = *(int *)(param_2 + 0x20);
      }
      else {
        iVar9 = *(int *)(p_Var3 + 0x20);
        p_Var6 = *(_Rb_tree_node_base **)(param_1 + 0x10);
        do {
          param_2 = p_Var6;
          iVar7 = *(int *)(param_2 + 0x20);
          if (iVar9 < iVar7) {
            p_Var6 = *(_Rb_tree_node_base **)(param_2 + 0x10);
          }
          else {
            p_Var6 = *(_Rb_tree_node_base **)(param_2 + 0x18);
          }
        } while (p_Var6 != (_Rb_tree_node_base *)0x0);
        p_Var6 = param_2;
        if (iVar9 < iVar7) goto LAB_0011cd23;
      }
      if (iVar9 <= iVar7) goto LAB_0011cba0;
LAB_0011cc9e:
      param_2 = (_Rb_tree_node_base *)0x0;
      p_Var4 = p_Var6;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011cba0:
        if (*(long **)(p_Var3 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)(p_Var3 + 0x28) + 8))();
        }
        *(undefined8 *)(p_Var3 + 0x28) = 0;
        rea_operator_delete(p_Var3);
        return param_2;
      }
    }
LAB_0011cbf0:
    if (p_Var1 == p_Var4) {
      bVar8 = true;
      goto LAB_0011cb1c;
    }
    iVar9 = *(int *)(p_Var3 + 0x20);
    iVar7 = *(int *)(p_Var4 + 0x20);
  }
  else {
    iVar9 = *(int *)(p_Var3 + 0x20);
    iVar7 = *(int *)(param_2 + 0x20);
    if (iVar9 < iVar7) {
      p_Var6 = *(_Rb_tree_node_base **)(param_1 + 0x18);
      p_Var5 = param_2;
      if (p_Var6 != param_2) {
        p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(param_2);
        if (iVar9 <= *(int *)(p_Var4 + 0x20)) {
          p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x10);
          p_Var5 = p_Var1;
          if (*(_Rb_tree_node_base **)(param_1 + 0x10) != (_Rb_tree_node_base *)0x0) {
            do {
              param_2 = p_Var4;
              iVar7 = *(int *)(param_2 + 0x20);
              if (iVar9 < iVar7) {
                p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x10);
              }
              else {
                p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x18);
              }
            } while (p_Var4 != (_Rb_tree_node_base *)0x0);
            p_Var5 = param_2;
            if (iVar9 >= iVar7) goto joined_r0x0011cc92;
          }
          if (p_Var6 != p_Var5) {
            param_2 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
            iVar7 = *(int *)(param_2 + 0x20);
joined_r0x0011cc92:
            p_Var6 = p_Var5;
            if (iVar9 <= iVar7) goto LAB_0011cba0;
          }
          goto LAB_0011cc9e;
        }
        if (*(long *)(p_Var4 + 0x18) == 0) goto LAB_0011cbf0;
      }
LAB_0011cb0b:
      bVar8 = true;
      p_Var4 = p_Var5;
      if (p_Var5 != (_Rb_tree_node_base *)0x0) goto LAB_0011cb1c;
      goto LAB_0011cbf0;
    }
    if (iVar9 <= iVar7) goto LAB_0011cba0;
    p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x20);
    if (p_Var4 == param_2) goto LAB_0011cbf0;
    p_Var5 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(param_2);
    if (*(int *)(p_Var5 + 0x20) <= iVar9) {
      p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x10);
      if (*(_Rb_tree_node_base **)(param_1 + 0x10) != (_Rb_tree_node_base *)0x0) {
        do {
          param_2 = p_Var4;
          iVar7 = *(int *)(param_2 + 0x20);
          if (iVar9 < iVar7) {
            p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x10);
          }
          else {
            p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x18);
          }
        } while (p_Var4 != (_Rb_tree_node_base *)0x0);
        p_Var6 = param_2;
        p_Var5 = param_2;
        if (iVar9 >= iVar7) goto joined_r0x0011cc92;
      }
      if (*(_Rb_tree_node_base **)(param_1 + 0x18) != p_Var6) {
        param_2 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var6);
        iVar7 = *(int *)(param_2 + 0x20);
        p_Var5 = p_Var6;
        goto joined_r0x0011cc92;
      }
      goto LAB_0011cc9e;
    }
    p_Var4 = param_2;
    if (*(long *)(param_2 + 0x18) != 0) goto LAB_0011cb0b;
  }
  bVar8 = iVar9 < iVar7;
LAB_0011cb1c:
  rea_std___Rb_tree_insert_and_rebalance(bVar8,p_Var3,p_Var4,p_Var1);
  *(long *)(param_1 + 0x28) = *(long *)(param_1 + 0x28) + 1;
  return p_Var3;
}





// ------------------------------------------------------------------
// IDX 290  0011cd80  std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase__dup2(_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn * this_ptr, _Rb_tree_node * param_1)
{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  _Rb_tree_node *p_Var9;
  void *pvVar10;
  
  while (param_1 != (_Rb_tree_node *)0x0) {
    pvVar10 = *(void **)(param_1 + 0x18);
    while (pvVar10 != (void *)0x0) {
      pvVar8 = *(void **)((long)pvVar10 + 0x18);
      while (pvVar8 != (void *)0x0) {
        pvVar7 = *(void **)((long)pvVar8 + 0x18);
        while (pvVar7 != (void *)0x0) {
          pvVar6 = *(void **)((long)pvVar7 + 0x18);
          while (pvVar6 != (void *)0x0) {
            pvVar5 = *(void **)((long)pvVar6 + 0x18);
            while (pvVar5 != (void *)0x0) {
              pvVar4 = *(void **)((long)pvVar5 + 0x18);
              while (pvVar4 != (void *)0x0) {
                pvVar3 = *(void **)((long)pvVar4 + 0x18);
                while (pvVar3 != (void *)0x0) {
                  pvVar2 = *(void **)((long)pvVar3 + 0x18);
                  while (pvVar2 != (void *)0x0) {
                    _M_erase(this_ptr,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
                    pvVar1 = *(void **)((long)pvVar2 + 0x10);
                    if (*(long **)((long)pvVar2 + 0x28) != (long *)0x0) {
                      (**(code **)(**(long **)((long)pvVar2 + 0x28) + 8))();
                    }
                    *(undefined8 *)((long)pvVar2 + 0x28) = 0;
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long)pvVar3 + 0x10);
                  if (*(long **)((long)pvVar3 + 0x28) != (long *)0x0) {
                    (**(code **)(**(long **)((long)pvVar3 + 0x28) + 8))();
                  }
                  *(undefined8 *)((long)pvVar3 + 0x28) = 0;
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long)pvVar4 + 0x10);
                if (*(long **)((long)pvVar4 + 0x28) != (long *)0x0) {
                  (**(code **)(**(long **)((long)pvVar4 + 0x28) + 8))();
                }
                *(undefined8 *)((long)pvVar4 + 0x28) = 0;
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long)pvVar5 + 0x10);
              if (*(long **)((long)pvVar5 + 0x28) != (long *)0x0) {
                (**(code **)(**(long **)((long)pvVar5 + 0x28) + 8))();
              }
              *(undefined8 *)((long)pvVar5 + 0x28) = 0;
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long)pvVar6 + 0x10);
            if (*(long **)((long)pvVar6 + 0x28) != (long *)0x0) {
              (**(code **)(**(long **)((long)pvVar6 + 0x28) + 8))();
            }
            *(undefined8 *)((long)pvVar6 + 0x28) = 0;
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long)pvVar7 + 0x10);
          if (*(long **)((long)pvVar7 + 0x28) != (long *)0x0) {
            (**(code **)(**(long **)((long)pvVar7 + 0x28) + 8))();
          }
          *(undefined8 *)((long)pvVar7 + 0x28) = 0;
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long)pvVar8 + 0x10);
        if (*(long **)((long)pvVar8 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar8 + 0x28) = 0;
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long)pvVar10 + 0x10);
      if (*(long **)((long)pvVar10 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)((long)pvVar10 + 0x28) + 8))();
      }
      *(undefined8 *)((long)pvVar10 + 0x28) = 0;
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 8))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 291  0011d030  UnixClient__idle
// ------------------------------------------------------------------
uint rea_UnixClient__idle(UnixClient * this_ptr)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this_ptr + 0x98);
  if (iVar1 == 1) {
    rea_TcpConn__idle_proc(*(TcpConn **)(this_ptr + 0xa0));
    uVar2 = 0;
    if (*(char *)(*(long *)(this_ptr + 0xa0) + 0x58) == '\0') {
      return *(byte *)(*(long *)(this_ptr + 0xa0) + 0x59) ^ 1;
    }
  }
  else {
    uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 2);
  }
  return uVar2;
}





// ------------------------------------------------------------------
// IDX 292  0011d080  UnixServer__idle
// ------------------------------------------------------------------
undefined8 rea_UnixServer__idle(UnixServer * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  void *pvVar3;
  _Rb_tree_node_base *p_Var4;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var4 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  do {
    if (p_Var4 == p_Var1) {
      return 0;
    }
    while( true ) {
      rea_TcpConn__idle_proc(*(TcpConn **)(p_Var4 + 0x28));
      if ((*(char *)(*(long *)(p_Var4 + 0x28) + 0x58) != '\0') ||
         (*(char *)(*(long *)(p_Var4 + 0x28) + 0x59) != '\0')) break;
      p_Var2 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
      pvVar3 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var4,p_Var1);
      if (*(long **)((long)pvVar3 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)((long)pvVar3 + 0x28) + 8))();
      }
      *(undefined8 *)((long)pvVar3 + 0x28) = 0;
      rea_operator_delete(pvVar3);
      *(long *)(this_ptr + 0xe8) = *(long *)(this_ptr + 0xe8) + -1;
      p_Var4 = p_Var2;
      if (p_Var2 == p_Var1) {
        return 0;
      }
    }
    p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
  } while( true );
}





// ------------------------------------------------------------------
// IDX 293  0011d130  UnixServer__iter
// ------------------------------------------------------------------
void rea_UnixServer__iter(UnixServer * this_ptr, long param_2)
{
  _Rb_tree_node_base *p_Var1;
  
  p_Var1 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  while( true ) {
    if (p_Var1 == (_Rb_tree_node_base *)(this_ptr + 200)) {
      return;
    }
    if (*(long *)(param_2 + 0x10) == 0) break;
    (**(code **)(param_2 + 0x18))
              (param_2,*(undefined4 *)(p_Var1 + 0x20),*(undefined8 *)(p_Var1 + 0x28));
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var1);
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 294  0011d180  UnixClient__UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__UnixClient__dup2(UnixClient * this_ptr, string * param_1, long param_3, long param_4)
{
  long *plVar1;
  undefined *puVar2;
  int __fd;
  int iVar3;
  TcpConn *this_00;
  int *piVar4;
  sockaddr local_a8 [7];
  
  *(UnixClient **)(this_ptr + 0x20) = this_ptr + 0x10;
  *(UnixClient **)(this_ptr + 0x28) = this_ptr + 0x10;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(UnixClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(UnixClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(UnixClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(UnixClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar2 = PTR_vtable_00324f70;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 0;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined **)this_ptr = puVar2 + 0x10;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(this_ptr + 0xa8,param_3,2);
    *(undefined8 *)(this_ptr + 0xc0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this_ptr + 0xb8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  if (*(code **)(param_4 + 0x10) != (code *)0x0) {
    (**(code **)(param_4 + 0x10))(this_ptr + 200,param_4,2);
    *(undefined8 *)(this_ptr + 0xe0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this_ptr + 0xd8) = *(undefined8 *)(param_4 + 0x10);
  }
  rea_bzero(local_a8,0x6e);
  local_a8[0].sa_family = 1;
  rea_strncpy(local_a8[0].sa_data,*(char **)param_1,0x6b);
  __fd = rea_socket(1,1,0);
  if (__fd < 0) {
    rea_perror("socket");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setcloexec(__fd);
  iVar3 = rea_connect(__fd,local_a8,0x6e);
  if (iVar3 < 0) {
    piVar4 = rea___errno_location();
    iVar3 = *piVar4;
    *(undefined4 *)(this_ptr + 0x98) = 2;
    rea_perror("connect");
    rea_close(__fd);
    if (*(long *)(param_4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (**(code **)(param_4 + 0x18))(param_4,iVar3);
  }
  rea_setnonblock(__fd);
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,__fd,param_1,param_1,(EventHandler *)this_ptr);
  plVar1 = *(long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 8))();
    this_00 = *(TcpConn **)(this_ptr + 0xa0);
  }
  *(undefined4 *)(this_ptr + 0x98) = 1;
  if (*(long *)(param_3 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  (**(code **)(param_3 + 0x18))(param_3,this_00);
  return;
}





// ------------------------------------------------------------------
// IDX 295  0011d4a0  UnixClient__UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__UnixClient__dup3(UnixClient * this_ptr, int param_1, long param_3)
{
  int *piVar1;
  long *plVar2;
  undefined *puVar3;
  int iVar4;
  TcpConn *this_00;
  allocator local_3a [2];
  long local_38 [2];
  
  *(UnixClient **)(this_ptr + 0x20) = this_ptr + 0x10;
  *(UnixClient **)(this_ptr + 0x28) = this_ptr + 0x10;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(UnixClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(UnixClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(UnixClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(UnixClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar3 = PTR_vtable_00324f70;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 1;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  rea_setcloexec(param_1);
  rea_setnonblock(param_1);
  rea_std__string__string((string *)local_38,"",local_3a);
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,param_1,(string *)local_38,(string *)local_38,(EventHandler *)this_ptr);
  plVar2 = *(long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 8))();
  }
  if ((allocator *)(local_38[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_38[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(local_38[0] + -8);
      *(int *)(local_38[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_38[0] + -0x18));
    }
  }
  if (*(long *)(param_3 + 0x10) != 0) {
    (**(code **)(param_3 + 0x18))(param_3,*(undefined8 *)(this_ptr + 0xa0));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 296  0011d6d0  UnixClient__dtor_UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__dtor_UnixClient__dup2(UnixClient * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  undefined *puVar3;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  UnixClient *pUVar4;
  
  *(undefined **)this_ptr = PTR_vtable_00324f70 + 0x10;
  if (*(code **)(this_ptr + 0xd8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xd8))(this_ptr + 200,this_ptr + 200,3);
  }
  if (*(code **)(this_ptr + 0xb8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xb8))(this_ptr + 0xa8,this_ptr + 0xa8,3);
  }
  if (*(long **)(this_ptr + 0xa0) != (long *)0x0) {
    (**(code **)(**(long **)(this_ptr + 0xa0) + 8))();
  }
  puVar3 = PTR_vtable_00324fb8;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  pUVar4 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pUVar4 + -0x30);
    pvVar2 = *(void **)(pUVar4 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pUVar4 = (UnixClient *)this_00;
  } while (this_ptr + 0x38 != (UnixClient *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 297  0011d7b0  UnixClient__dtor_UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__dtor_UnixClient__dup3(UnixClient * this_ptr)
{
  dtor_UnixClient(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 298  0011d7d0  UnixServer__poll
// ------------------------------------------------------------------
undefined8 rea_UnixServer__poll(UnixServer * this_ptr, int param_1, int param_2)
{
  _Rb_tree_node_base *p_Var1;
  UnixServer *pUVar2;
  int *piVar3;
  uint *puVar4;
  undefined *puVar5;
  _Rb_tree_node_base *p_Var6;
  UnixServer *pUVar7;
  int iVar8;
  uint uVar9;
  void *pvVar10;
  long *plVar11;
  TcpConn *this_00;
  UnixServer *pUVar12;
  ulong uVar13;
  UnixServer *pUVar14;
  UnixServer *pUVar15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  bool bVar19;
  uint local_78 [4];
  long local_68 [2];
  ulong local_58 [2];
  uint *local_48 [3];
  
  if ((*(int *)(this_ptr + 0xb8) != param_1) || ((param_2 & 1U) == 0)) goto LAB_0011d7fb;
  local_78[0] = rea_accept(*(int *)(this_ptr + 0xb8),(sockaddr *)0x0,(socklen_t *)0x0);
  if ((int)local_78[0] < 0) {
    rea_perror("accept");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setnonblock(local_78[0]);
  rea_setcloexec(local_78[0]);
  rea___gnu_cxx____to_xstring_std__string_char
            ((code *)local_48,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,(void *)&DAT_0011fd61,(ulong)local_78[0]);
  rea_std__string__string((string *)local_58,(string *)(this_ptr + 0xf0));
  rea_std__string__append((char *)local_58,0x11fcf2);
  uVar13 = *(long *)(local_58[0] - 0x18) + *(long *)(local_48[0] + -6);
  if ((*(ulong *)(local_58[0] - 0x10) < uVar13) && (uVar13 <= *(ulong *)(local_48[0] + -4))) {
    plVar11 = (long *)rea_std__string__insert((ulong)local_48,(char *)0x0,local_58[0]);
  }
  else {
    plVar11 = (long *)rea_std__string__append((string *)local_58);
  }
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  local_68[0] = *plVar11;
  *plVar11 = (long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_58[0] - 0x18) != (allocator *)puVar5) {
    piVar3 = (int *)(local_58[0] - 8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_58[0] - 8);
      *(int *)(local_58[0] - 8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_58[0] - 0x18));
    }
  }
  if ((allocator *)(local_48[0] + -6) != (allocator *)puVar5) {
    puVar4 = local_48[0] + -2;
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      uVar9 = local_48[0][-2];
      local_48[0][-2] = uVar9 - 1;
    }
    else {
      LOCK();
      uVar9 = *puVar4;
      *puVar4 = *puVar4 - 1;
      UNLOCK();
    }
    if ((int)uVar9 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_48[0] + -6));
    }
  }
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,local_78[0],(string *)(this_ptr + 0xf0),(string *)local_68,
                   (EventHandler *)this_ptr);
  pUVar15 = this_ptr + 200;
  pUVar7 = *(UnixServer **)(this_ptr + 0xd0);
  pUVar14 = pUVar15;
  if (*(UnixServer **)(this_ptr + 0xd0) == (UnixServer *)0x0) {
LAB_0011da73:
    local_48[0] = local_78;
    pUVar12 = (UnixServer *)
              std__________________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________________________________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple__________________________(this_ptr + 0xc0,pUVar15,(void *)&DAT_0011fe15,local_48,(string *)local_58);
  }
  else {
    do {
      while (pUVar12 = pUVar7, *(int *)(pUVar12 + 0x20) < (int)local_78[0]) {
        pUVar2 = pUVar12 + 0x18;
        pUVar7 = *(UnixServer **)pUVar2;
        pUVar12 = pUVar14;
        if (*(UnixServer **)pUVar2 == (UnixServer *)0x0) goto LAB_0011da1a;
      }
      pUVar7 = *(UnixServer **)(pUVar12 + 0x10);
      pUVar14 = pUVar12;
    } while (*(UnixServer **)(pUVar12 + 0x10) != (UnixServer *)0x0);
LAB_0011da1a:
    bVar19 = pUVar15 == pUVar12;
    pUVar15 = pUVar12;
    if ((bVar19) || ((int)local_78[0] < *(int *)(pUVar12 + 0x20))) goto LAB_0011da73;
  }
  plVar11 = *(long **)(pUVar12 + 0x28);
  *(TcpConn **)(pUVar12 + 0x28) = this_00;
  if (plVar11 != (long *)0x0) {
    (**(code **)(*plVar11 + 8))();
  }
  if (*(long *)(this_ptr + 0xa8) == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  (**(code **)(this_ptr + 0xb0))(this_ptr + 0x98,this_00);
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar5) {
    piVar3 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
LAB_0011d7fb:
  p_Var18 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0xd0);
  p_Var16 = p_Var18;
  if (*(_Rb_tree_node_base **)(this_ptr + 0xd0) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var17 = p_Var6, *(int *)(p_Var17 + 0x20) < param_1) {
        p_Var1 = p_Var17 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var1;
        p_Var17 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011d82a;
      }
      p_Var6 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
      p_Var16 = p_Var17;
    } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011d82a:
    if ((p_Var18 != p_Var17) && (*(int *)(p_Var17 + 0x20) <= param_1)) {
      if ((param_2 & 2U) != 0) {
        rea_TcpConn__send_proc(*(TcpConn **)(p_Var17 + 0x28));
      }
      if ((param_2 & 1U) != 0) {
        rea_TcpConn__recv_proc(*(TcpConn **)(p_Var17 + 0x28));
      }
      if ((*(char *)(*(long *)(p_Var17 + 0x28) + 0x58) == '\0') &&
         (*(char *)(*(long *)(p_Var17 + 0x28) + 0x59) == '\0')) {
        pvVar10 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var17,p_Var18);
        if (*(long **)((long)pvVar10 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar10 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar10 + 0x28) = 0;
        rea_operator_delete(pvVar10);
        *(long *)(this_ptr + 0xe8) = *(long *)(this_ptr + 0xe8) + -1;
      }
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 299  0011dc00  UnixServer__dtor_UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__dtor_UnixServer__dup2(UnixServer * this_ptr)
{
  int *piVar1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var2;
  long lVar3;
  int iVar4;
  int local_38 [6];
  
  *(undefined **)this_ptr = PTR_vtable_00324ec8 + 0x10;
  local_38[0] = *(int *)(this_ptr + 0xb8);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 8),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x38),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x68),local_38);
  rea_remove(*(char **)(this_ptr + 0xf0));
  rea_close(*(int *)(this_ptr + 0xb8));
  lVar3 = *(long *)(this_ptr + 0xf0);
  if ((allocator *)(lVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar3 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(lVar3 + -8);
      *(int *)(lVar3 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar3 + -0x18));
    }
  }
  p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(this_ptr + 0x98);
  std______Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn______M_erase((_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn
              *)(this_ptr + 0xc0),*(_Rb_tree_node **)(this_ptr + 0xd0));
  if (*(code **)(this_ptr + 0xa8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xa8))(p_Var2,p_Var2,3);
  }
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  while ((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
          *)(this_ptr + 0x38) != p_Var2) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________M_erase(p_Var2 + -0x30,*(_Rb_tree_node **)(p_Var2 + -0x20));
    p_Var2 = p_Var2 + -0x30;
  }
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 300  0011dd40  UnixServer__dtor_UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__dtor_UnixServer__dup3(UnixServer * this_ptr)
{
  dtor_UnixServer(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 301  0011dd60  UnixServer__UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__UnixServer(UnixServer * this_ptr, string * param_1, long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  bool bVar10;
  uint uVar11;
  undefined1 auVar12 [16];
  int local_b8 [4];
  sockaddr local_a8 [7];
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(this_ptr + 0x38);
  *(UnixServer **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(UnixServer **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
  *(UnixServer **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(UnixServer **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar4 = PTR_vtable_00324ec8;
  *(_Rb_tree_node_base **)(this_ptr + 0x28) = p_Var1;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined **)this_ptr = puVar4 + 0x10;
  *(undefined8 *)(this_ptr + 0xa8) = 0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(this_ptr + 0x98,param_3,2);
    *(undefined8 *)(this_ptr + 0xb0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this_ptr + 0xa8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(undefined4 *)(this_ptr + 200) = 0;
  *(undefined8 *)(this_ptr + 0xd0) = 0;
  *(undefined8 *)(this_ptr + 0xe8) = 0;
  *(UnixServer **)(this_ptr + 0xd8) = this_ptr + 200;
  *(UnixServer **)(this_ptr + 0xe0) = this_ptr + 200;
  rea_std__string__string((string *)(this_ptr + 0xf0),param_1);
  rea_bzero(local_a8,0x6e);
  local_a8[0].sa_family = 1;
  rea_strncpy(local_a8[0].sa_data,*(char **)param_1,0x6b);
  iVar5 = rea_socket(1,1,0);
  *(int *)(this_ptr + 0xb8) = iVar5;
  if (iVar5 < 0) {
    rea_perror("socket");
LAB_0011e337:
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setcloexec(iVar5);
  iVar5 = rea_bind(*(int *)(this_ptr + 0xb8),local_a8,0x6e);
  if (iVar5 < 0) {
    rea_perror("bind");
    goto LAB_0011e337;
  }
  iVar5 = rea_listen(*(int *)(this_ptr + 0xb8),0x1ff);
  if (iVar5 < 0) {
    rea_perror("listen");
    goto LAB_0011e337;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  local_b8[0] = *(int *)(this_ptr + 0xb8);
  p_Var7 = p_Var6;
  p_Var8 = p_Var1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011e210:
    uVar11 = 0;
  }
  else {
    do {
      while (p_Var9 = p_Var7, *(int *)(p_Var9 + 0x20) < local_b8[0]) {
        p_Var2 = p_Var9 + 0x18;
        p_Var7 = *(_Rb_tree_node_base **)p_Var2;
        p_Var9 = p_Var8;
        if (*(_Rb_tree_node_base **)p_Var2 == (_Rb_tree_node_base *)0x0) goto LAB_0011df42;
      }
      p_Var7 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
      p_Var8 = p_Var9;
    } while (*(_Rb_tree_node_base **)(p_Var9 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011df42:
    if ((p_Var1 == p_Var9) || (local_b8[0] < *(int *)(p_Var9 + 0x20))) goto LAB_0011e210;
    iVar5 = *(int *)(p_Var6 + 0x20);
    p_Var7 = p_Var1;
    while( true ) {
      if (iVar5 < local_b8[0]) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var7 = p_Var6;
      }
      p_Var6 = p_Var8;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) break;
      iVar5 = *(int *)(p_Var6 + 0x20);
    }
    if ((p_Var1 == p_Var7) || (local_b8[0] < *(int *)(p_Var7 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_b8[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var7,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
      p_Var8 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
      p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
      if (p_Var8 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var7 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var8)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var8 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var8,p_Var1);
        *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
        p_Var7 = p_Var6;
      }
    }
    uVar11 = *(uint *)(p_Var7 + 0x24);
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(this_ptr + 0x68);
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(this_00 + 8);
  p_Var7 = p_Var6;
  p_Var8 = p_Var1;
  uVar3 = uVar11;
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var9 = p_Var7, *(int *)(p_Var9 + 0x20) < local_b8[0]) {
        p_Var2 = p_Var9 + 0x18;
        p_Var7 = *(_Rb_tree_node_base **)p_Var2;
        p_Var9 = p_Var8;
        if (*(_Rb_tree_node_base **)p_Var2 == (_Rb_tree_node_base *)0x0) goto LAB_0011dfd2;
      }
      p_Var7 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
      p_Var8 = p_Var9;
    } while (*(_Rb_tree_node_base **)(p_Var9 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011dfd2:
    if ((p_Var1 != p_Var9) && (p_Var7 = p_Var1, *(int *)(p_Var9 + 0x20) <= local_b8[0])) {
      do {
        while (p_Var8 = p_Var6, *(int *)(p_Var8 + 0x20) < local_b8[0]) {
          p_Var9 = p_Var8 + 0x18;
          p_Var6 = *(_Rb_tree_node_base **)p_Var9;
          p_Var8 = p_Var7;
          if (*(_Rb_tree_node_base **)p_Var9 == (_Rb_tree_node_base *)0x0) goto LAB_0011e00a;
        }
        p_Var6 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
      } while (*(_Rb_tree_node_base **)(p_Var8 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011e00a:
      if ((p_Var1 == p_Var8) || (local_b8[0] < *(int *)(p_Var8 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_b8[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var8,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
        p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
        p_Var8 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
        if (p_Var7 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var8 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
          *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
          p_Var8 = p_Var6;
        }
      }
      uVar3 = *(uint *)(p_Var8 + 0x24);
    }
  }
  if ((uVar3 | 1) == uVar11) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_b8);
    return;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var8 = p_Var1;
  p_Var7 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_00 + 0x10) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var7 = p_Var6, *(int *)(p_Var7 + 0x20) < local_b8[0]) {
        p_Var9 = p_Var7 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var9;
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)p_Var9 == (_Rb_tree_node_base *)0x0) goto LAB_0011e062;
      }
      p_Var6 = *(_Rb_tree_node_base **)(p_Var7 + 0x10);
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)(p_Var7 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011e062:
    if ((p_Var1 != p_Var7) && (*(int *)(p_Var7 + 0x20) <= local_b8[0])) goto LAB_0011e0eb;
  }
  p_Var6 = rea_operator_new(0x28);
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var6 = 0;
    *(undefined8 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined4 *)(p_Var6 + 0x24) = 0;
    *(int *)(p_Var6 + 0x20) = local_b8[0];
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(this_00,p_Var7,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
  p_Var8 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
  p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
  if (p_Var8 == (_Rb_tree_node_base *)0x0) {
    rea_operator_delete(p_Var6);
  }
  else {
    bVar10 = true;
    if ((p_Var7 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var8)) {
      bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var8 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var8,p_Var1);
    *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
    p_Var7 = p_Var6;
  }
LAB_0011e0eb:
  *(uint *)(p_Var7 + 0x24) = uVar3 | 1;
  return;
}





// ------------------------------------------------------------------
// IDX 302  0011e3a0  UnixServer__UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__UnixServer__dup2(UnixServer * this_ptr, int param_1, long param_3)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  bool bVar10;
  uint uVar11;
  undefined1 auVar12 [16];
  int local_48 [6];
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
             *)(this_ptr + 0x38);
  *(UnixServer **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(UnixServer **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
  *(UnixServer **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(UnixServer **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar5 = PTR_vtable_00324ec8;
  *(_Rb_tree_node_base **)(this_ptr + 0x28) = p_Var1;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined **)this_ptr = puVar5 + 0x10;
  *(undefined8 *)(this_ptr + 0xa8) = 0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(this_ptr + 0x98,param_3,2);
    *(undefined8 *)(this_ptr + 0xb0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this_ptr + 0xa8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(int *)(this_ptr + 0xb8) = param_1;
  *(undefined4 *)(this_ptr + 200) = 0;
  *(undefined8 *)(this_ptr + 0xd0) = 0;
  *(undefined8 *)(this_ptr + 0xe8) = 0;
  *(UnixServer **)(this_ptr + 0xd8) = this_ptr + 200;
  *(UnixServer **)(this_ptr + 0xe0) = this_ptr + 200;
  rea_std__string__string((string *)(this_ptr + 0xf0),"",(allocator *)local_48);
  rea_setcloexec(param_1);
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  p_Var9 = p_Var6;
  p_Var7 = p_Var1;
  local_48[0] = param_1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011e808:
    uVar11 = 0;
  }
  else {
    do {
      while (p_Var8 = p_Var9, param_1 <= *(int *)(p_Var8 + 0x20)) {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0011e513;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var9 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011e513:
    if ((p_Var1 == p_Var8) || (param_1 < *(int *)(p_Var8 + 0x20))) goto LAB_0011e808;
    iVar3 = *(int *)(p_Var6 + 0x20);
    p_Var9 = p_Var1;
    while( true ) {
      if (iVar3 < param_1) {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var9 = p_Var6;
      }
      p_Var6 = p_Var7;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) break;
      iVar3 = *(int *)(p_Var6 + 0x20);
    }
    if ((p_Var1 == p_Var9) || (param_1 < *(int *)(p_Var9 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_48[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var9,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
      p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
      p_Var9 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
      if (p_Var7 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var9 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
        *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
        p_Var9 = p_Var6;
      }
    }
    uVar11 = *(uint *)(p_Var9 + 0x24);
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(this_ptr + 0x68);
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(this_00 + 8);
  p_Var9 = p_Var6;
  p_Var7 = p_Var1;
  uVar4 = uVar11;
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var8 = p_Var9, local_48[0] <= *(int *)(p_Var8 + 0x20)) {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0011e5a2;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var9 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011e5a2:
    if ((p_Var1 != p_Var8) && (p_Var9 = p_Var1, *(int *)(p_Var8 + 0x20) <= local_48[0])) {
      do {
        while (p_Var7 = p_Var6, local_48[0] <= *(int *)(p_Var7 + 0x20)) {
          p_Var6 = *(_Rb_tree_node_base **)(p_Var7 + 0x10);
          p_Var9 = p_Var7;
          if (*(_Rb_tree_node_base **)(p_Var7 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011e5da;
        }
        p_Var8 = p_Var7 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var8;
        p_Var7 = p_Var9;
      } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_0011e5da:
      if ((p_Var1 == p_Var7) || (local_48[0] < *(int *)(p_Var7 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(this_00,p_Var7,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
        p_Var9 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
        p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
        if (p_Var9 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var7 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var9)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var9 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var9,p_Var1);
          *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
          p_Var7 = p_Var6;
        }
      }
      uVar4 = *(uint *)(p_Var7 + 0x24);
    }
  }
  if ((uVar4 | 1) == uVar11) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(this_00,local_48);
    return;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var7 = p_Var1;
  p_Var9 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_00 + 0x10) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var9 = p_Var6, local_48[0] <= *(int *)(p_Var9 + 0x20)) {
        p_Var6 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
        p_Var7 = p_Var9;
        if (*(_Rb_tree_node_base **)(p_Var9 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0011e632;
      }
      p_Var8 = p_Var9 + 0x18;
      p_Var6 = *(_Rb_tree_node_base **)p_Var8;
      p_Var9 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_0011e632:
    if ((p_Var1 != p_Var9) && (*(int *)(p_Var9 + 0x20) <= local_48[0])) goto LAB_0011e6b8;
  }
  p_Var6 = rea_operator_new(0x28);
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var6 = 0;
    *(undefined8 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined4 *)(p_Var6 + 0x24) = 0;
    *(int *)(p_Var6 + 0x20) = local_48[0];
  }
  { auto &&__rea_tmp = (std________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________M_get_insert_hint_unique_pos(this_00,p_Var9,p_Var6 + 0x20)); memcpy(auVar12, &__rea_tmp, sizeof(auVar12)); }
  p_Var7 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x8));
  p_Var9 = (*(undefined8 *)((uint8_t *)&auVar12 + 0x0));
  if (p_Var7 == (_Rb_tree_node_base *)0x0) {
    rea_operator_delete(p_Var6);
  }
  else {
    bVar10 = true;
    if ((p_Var9 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
      bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
    }
    rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
    *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
    p_Var9 = p_Var6;
  }
LAB_0011e6b8:
  *(uint *)(p_Var9 + 0x24) = uVar4 | 1;
  return;
}





// ------------------------------------------------------------------
// IDX 303  0011e940  UnixClient__poll
// ------------------------------------------------------------------
byte rea_UnixClient__poll(UnixClient * this_ptr, int param_1, int param_2)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  long lVar7;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  bool bVar10;
  TcpConn *this_00;
  _Rb_tree_node_base *p_Var11;
  uint uVar12;
  undefined1 auVar13 [16];
  int local_78 [4];
  socklen_t local_68 [4];
  int local_58 [4];
  int local_48 [6];
  
  if (*(int *)(this_ptr + 0x98) == 1) {
    this_00 = *(TcpConn **)(this_ptr + 0xa0);
    if (*(int *)(this_00 + 0x40) == param_1) {
      if ((param_2 & 2U) != 0) {
        rea_TcpConn__send_proc(this_00);
        this_00 = *(TcpConn **)(this_ptr + 0xa0);
      }
      if ((param_2 & 1U) != 0) {
        rea_TcpConn__recv_proc(this_00);
        this_00 = *(TcpConn **)(this_ptr + 0xa0);
      }
    }
    if (this_00[0x58] != (TcpConn)0x0) {
      return 0;
    }
    return (byte)this_00[0x59] ^ 1;
  }
  if (*(int *)(this_ptr + 0x98) == 2) {
    return 1;
  }
  if (param_1 != *(int *)(*(long *)(this_ptr + 0xa0) + 0x40)) {
    return 0;
  }
  if ((param_2 & 2U) == 0) {
    return 0;
  }
  local_68[0] = 4;
  rea_getsockopt(param_1,1,4,local_78,local_68);
  iVar2 = local_78[0];
  if (local_78[0] == 0) {
    p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
    *(undefined4 *)(this_ptr + 0x98) = 1;
    p_Var9 = (_Rb_tree_node_base *)(this_ptr + 0x10);
    p_Var5 = p_Var6;
    p_Var11 = p_Var9;
    local_48[0] = param_1;
    if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011f0bd:
      lVar7 = 0;
      uVar12 = 0;
    }
    else {
      do {
        if (*(int *)(p_Var5 + 0x20) < param_1) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
          p_Var11 = p_Var5;
        }
        p_Var5 = p_Var8;
      } while (p_Var8 != (_Rb_tree_node_base *)0x0);
      if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
      goto LAB_0011f0bd;
      do {
        if (*(int *)(p_Var6 + 0x20) < param_1) {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var11;
      } while (p_Var11 != (_Rb_tree_node_base *)0x0);
      if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
        p_Var6 = rea_operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos_____________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                              *)(this_ptr + 8),p_Var5,p_Var6 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var11 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
        p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
        if (p_Var11 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var5 == (_Rb_tree_node_base *)0x0) && (p_Var9 != p_Var11)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
          *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
          p_Var5 = p_Var6;
        }
      }
      uVar12 = *(uint *)(p_Var5 + 0x24);
      lVar7 = 1;
    }
    lVar7 = lVar7 + 1;
    p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + lVar7 * 0x30 + 8);
    p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
    p_Var11 = (_Rb_tree_node_base *)(this_ptr + lVar7 * 0x30 + 0x10);
    p_Var6 = p_Var9;
    p_Var5 = p_Var11;
    uVar3 = uVar12;
    if (p_Var9 != (_Rb_tree_node_base *)0x0) {
      do {
        if (*(int *)(p_Var6 + 0x20) < local_48[0]) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var8;
      } while (p_Var8 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_48[0])) {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != (_Rb_tree_node_base *)0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) {
          p_Var9 = rea_operator_new(0x28);
          if (p_Var9 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var9 = 0;
            *(undefined8 *)(p_Var9 + 8) = 0;
            *(undefined8 *)(p_Var9 + 0x10) = 0;
            *(undefined8 *)(p_Var9 + 0x18) = 0;
            *(undefined4 *)(p_Var9 + 0x24) = 0;
            *(int *)(p_Var9 + 0x20) = local_48[0];
          }
          { auto &&__rea_tmp = (std________________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
          p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
          p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
          if (p_Var5 == (_Rb_tree_node_base *)0x0) {
            rea_operator_delete(p_Var9);
          }
          else {
            bVar10 = true;
            if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
              bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
            }
            rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
            *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
            p_Var6 = p_Var9;
          }
        }
        uVar3 = *(uint *)(p_Var6 + 0x24);
      }
    }
    if ((uVar3 & 0xfffffffd) == uVar12) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_________erase(p_Var1,local_48);
    }
    else {
      p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
      p_Var6 = p_Var11;
      if (p_Var9 == (_Rb_tree_node_base *)0x0) {
LAB_0011f018:
        p_Var9 = rea_operator_new(0x28);
        if (p_Var9 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_48[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
        p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
        if (p_Var5 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      else {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != (_Rb_tree_node_base *)0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011f018;
      }
      *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
    }
    if (*(long *)(this_ptr + 0xb8) != 0) {
      (**(code **)(this_ptr + 0xc0))(this_ptr + 0xa8,*(undefined8 *)(this_ptr + 0xa0));
      return 0;
    }
    goto LAB_0011f251;
  }
  *(undefined4 *)(this_ptr + 0x98) = 2;
  p_Var9 = (_Rb_tree_node_base *)(this_ptr + 0x10);
  piVar4 = rea___errno_location();
  *piVar4 = iVar2;
  rea_perror("connect");
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0x18);
  p_Var5 = p_Var6;
  p_Var11 = p_Var9;
  local_58[0] = param_1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011f0c7:
    lVar7 = 0;
    uVar12 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var5 + 0x20) < param_1) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
        p_Var11 = p_Var5;
      }
      p_Var5 = p_Var8;
    } while (p_Var8 != (_Rb_tree_node_base *)0x0);
    if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
    goto LAB_0011f0c7;
    do {
      if (*(int *)(p_Var6 + 0x20) < param_1) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var11;
    } while (p_Var11 != (_Rb_tree_node_base *)0x0);
    if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
      p_Var6 = rea_operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_58[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos___________________________((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
                            *)(this_ptr + 8),p_Var5,p_Var6 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
      p_Var11 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
      p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
      if (p_Var11 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var5 == (_Rb_tree_node_base *)0x0) && (p_Var9 != p_Var11)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
        *(long *)(this_ptr + 0x30) = *(long *)(this_ptr + 0x30) + 1;
        p_Var5 = p_Var6;
      }
    }
    uVar12 = *(uint *)(p_Var5 + 0x24);
    lVar7 = 1;
  }
  lVar7 = lVar7 + 1;
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(this_ptr + lVar7 * 0x30 + 8);
  p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(this_ptr + lVar7 * 0x30 + 0x10);
  p_Var6 = p_Var9;
  p_Var5 = p_Var11;
  uVar3 = uVar12;
  if (p_Var9 != (_Rb_tree_node_base *)0x0) {
    do {
      if (*(int *)(p_Var6 + 0x20) < local_58[0]) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var8;
    } while (p_Var8 != (_Rb_tree_node_base *)0x0);
    if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_58[0])) {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) {
        p_Var9 = rea_operator_new(0x28);
        if (p_Var9 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_58[0];
        }
        { auto &&__rea_tmp = (std______________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
        p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
        p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
        if (p_Var5 == (_Rb_tree_node_base *)0x0) {
          rea_operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      uVar3 = *(uint *)(p_Var6 + 0x24);
    }
  }
  if ((uVar3 & 0xfffffffd) == uVar12) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_______erase(p_Var1,local_58);
  }
  else {
    p_Var9 = *(_Rb_tree_node_base **)(this_ptr + lVar7 * 0x30 + 0x18);
    p_Var6 = p_Var11;
    if (p_Var9 == (_Rb_tree_node_base *)0x0) {
LAB_0011ef69:
      p_Var9 = rea_operator_new(0x28);
      if (p_Var9 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var9 = 0;
        *(undefined8 *)(p_Var9 + 8) = 0;
        *(undefined8 *)(p_Var9 + 0x10) = 0;
        *(undefined8 *)(p_Var9 + 0x18) = 0;
        *(undefined4 *)(p_Var9 + 0x24) = 0;
        *(int *)(p_Var9 + 0x20) = local_58[0];
      }
      { auto &&__rea_tmp = (std____________________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____________________M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20)); memcpy(auVar13, &__rea_tmp, sizeof(auVar13)); }
      p_Var5 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x8));
      p_Var6 = (*(undefined8 *)((uint8_t *)&auVar13 + 0x0));
      if (p_Var5 == (_Rb_tree_node_base *)0x0) {
        rea_operator_delete(p_Var9);
      }
      else {
        bVar10 = true;
        if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
          bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
        }
        rea_std___Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
        *(long *)(this_ptr + lVar7 * 0x30 + 0x30) = *(long *)(this_ptr + lVar7 * 0x30 + 0x30) + 1;
        p_Var6 = p_Var9;
      }
    }
    else {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011ef69;
    }
    *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
  }
  if (*(long *)(this_ptr + 0xd8) != 0) {
    (**(code **)(this_ptr + 0xe0))(this_ptr + 200,local_78[0]);
    return 1;
  }
LAB_0011f251:
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 304  0011f258  _fini
// ------------------------------------------------------------------
void rea__fini(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 305  00326000  std__string__append
// ------------------------------------------------------------------
void rea_std__string__append__dup3(char * param_1, ulong param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 306  00326008  std____throw_length_error
// ------------------------------------------------------------------
void rea_std____throw_length_error__dup2(char * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 307  00326010  PyString_AsString
// ------------------------------------------------------------------
void rea_PyString_AsString__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 308  00326018  memset
// ------------------------------------------------------------------
void * rea_memset__dup2(void * __s, int __c, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 309  00326020  shutdown
// ------------------------------------------------------------------
int rea_shutdown__dup2(int __fd, int __how)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 310  00326028  backtrace
// ------------------------------------------------------------------
void rea_backtrace__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 311  00326030  std____detail___List_node_base___M_unhook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_unhook__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 312  00326038  close
// ------------------------------------------------------------------
int rea_close__dup2(int __fd)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 313  00326040  inflateEnd
// ------------------------------------------------------------------
void rea_inflateEnd__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 314  00326048  Py_InitModule4_64
// ------------------------------------------------------------------
void rea_Py_InitModule4_64__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 315  00326050  abort
// ------------------------------------------------------------------
void rea_abort__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 316  00326058  PyLong_FromVoidPtr
// ------------------------------------------------------------------
void rea_PyLong_FromVoidPtr__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 317  00326060  PyLong_AsVoidPtr
// ------------------------------------------------------------------
void rea_PyLong_AsVoidPtr__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 318  00326068  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup4(string * this_ptr, char * param_1, ulong param_2, allocator * param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 319  00326070  __gmon_start__
// ------------------------------------------------------------------
void rea___gmon_start__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 320  00326078  _Jv_RegisterClasses
// ------------------------------------------------------------------
void rea__Jv_RegisterClasses(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 321  00326080  operator_delete
// ------------------------------------------------------------------
void rea_operator__delete__dup2(void * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 322  00326088  std__string__reserve
// ------------------------------------------------------------------
void rea_std__string__reserve__dup2(ulong param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 323  00326090  std__string___Rep___M_dispose
// ------------------------------------------------------------------
void rea_std__string___Rep___M_dispose__dup2(allocator * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 324  00326098  gettimeofday
// ------------------------------------------------------------------
int rea_gettimeofday__dup2(timeval * __tv, __timezone_ptr_t __tz)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 325  003260a0  __cxa_rethrow
// ------------------------------------------------------------------
void rea___cxa_rethrow__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 326  003260a8  deflate
// ------------------------------------------------------------------
void rea_deflate__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 327  003260b0  read
// ------------------------------------------------------------------
ssize_t rea_read__dup2(int __fd, void * __buf, size_t __nbytes)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 328  003260b8  std___Rb_tree_decrement
// ------------------------------------------------------------------
void rea_std___Rb_tree_decrement__dup2(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 329  003260c0  std__string___Rep___S_create
// ------------------------------------------------------------------
void rea_std__string___Rep___S_create__dup2(ulong param_1, ulong param_2, allocator * param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 330  003260c8  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup5(string * this_ptr, string * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 331  003260d0  setsockopt
// ------------------------------------------------------------------
int rea_setsockopt__dup2(int __fd, int __level, int __optname, void * __optval, socklen_t __optlen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 332  003260d8  PyString_FromStringAndSize
// ------------------------------------------------------------------
void rea_PyString_FromStringAndSize__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 333  003260e0  PyLong_AsLong
// ------------------------------------------------------------------
void rea_PyLong_AsLong__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 334  003260e8  PyString_Size
// ------------------------------------------------------------------
void rea_PyString_Size__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 335  003260f0  inflateInit2_
// ------------------------------------------------------------------
void rea_inflateInit2__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 336  003260f8  _ITM_deregisterTMCloneTable
// ------------------------------------------------------------------
void rea__ITM_deregisterTMCloneTable(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 337  00326100  bzero
// ------------------------------------------------------------------
void rea_bzero__dup2(void * __s, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 338  00326108  strnlen
// ------------------------------------------------------------------
size_t rea_strnlen__dup2(char * __string, size_t __maxlen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 339  00326110  PyArg_ParseTuple
// ------------------------------------------------------------------
void rea_PyArg_ParseTuple__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 340  00326118  inflate
// ------------------------------------------------------------------
void rea_inflate__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 341  00326120  backtrace_symbols
// ------------------------------------------------------------------
void rea_backtrace_symbols__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 342  00326128  free
// ------------------------------------------------------------------
void rea_free__dup2(void * __ptr)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 343  00326130  strlen
// ------------------------------------------------------------------
size_t rea_strlen__dup2(char * __s)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 344  00326138  _ITM_registerTMCloneTable
// ------------------------------------------------------------------
void rea__ITM_registerTMCloneTable(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 345  00326140  std__string___Rep___M_destroy
// ------------------------------------------------------------------
void rea_std__string___Rep___M_destroy__dup2(allocator * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 346  00326148  __xstat
// ------------------------------------------------------------------
int rea___xstat__dup2(int __ver, char * __filename, stat * __stat_buf)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 347  00326150  deflateEnd
// ------------------------------------------------------------------
void rea_deflateEnd__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 348  00326158  listen
// ------------------------------------------------------------------
int rea_listen__dup2(int __fd, int __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 349  00326160  __cxa_finalize
// ------------------------------------------------------------------
void rea___cxa_finalize__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 350  00326170  strrchr
// ------------------------------------------------------------------
char * rea_strrchr__dup2(char * __s, int __c)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 351  00326178  std__string__insert
// ------------------------------------------------------------------
void rea_std__string__insert__dup2(ulong param_1, char * param_2, ulong param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 352  00326180  std___Rb_tree_increment
// ------------------------------------------------------------------
void rea_std___Rb_tree_increment__dup3(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 353  00326188  epoll_create1
// ------------------------------------------------------------------
int rea_epoll_create1__dup2(int __flags)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 354  00326190  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup6(string * this_ptr, char * param_1, allocator * param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 355  00326198  epoll_ctl
// ------------------------------------------------------------------
int rea_epoll_ctl__dup2(int __epfd, int __op, int __fd, epoll_event * __event)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 356  003261a0  sigaction
// ------------------------------------------------------------------
int rea_sigaction__dup2(int __sig, sigaction * __act, sigaction * __oact)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 357  003261a8  getifaddrs
// ------------------------------------------------------------------
void rea_getifaddrs__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 358  003261b0  std__terminate
// ------------------------------------------------------------------
void rea_std__terminate__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 359  003261b8  getsockopt
// ------------------------------------------------------------------
int rea_getsockopt__dup2(int __fd, int __level, int __optname, void * __optval, socklen_t * __optlen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 360  003261c0  connect
// ------------------------------------------------------------------
int rea_connect__dup2(int __fd, sockaddr * __addr, socklen_t __len)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 361  003261c8  std____detail___List_node_base___M_hook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_hook__dup2(_List_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 362  003261d0  __cxa_pure_virtual
// ------------------------------------------------------------------
void rea___cxa_pure_virtual(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 363  003261d8  memmove
// ------------------------------------------------------------------
void * rea_memmove__dup2(void * __dest, void * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 364  003261e0  PyFloat_AsDouble
// ------------------------------------------------------------------
void rea_PyFloat_AsDouble__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 365  003261e8  socket
// ------------------------------------------------------------------
int rea_socket__dup2(int __domain, int __type, int __protocol)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 366  003261f0  vsnprintf
// ------------------------------------------------------------------
int rea_vsnprintf__dup2(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 367  003261f8  inet_ntoa
// ------------------------------------------------------------------
char * rea_inet_ntoa__dup2(in_addr __in)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 368  00326200  Py_BuildValue
// ------------------------------------------------------------------
void rea_Py_BuildValue__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 369  00326208  __errno_location
// ------------------------------------------------------------------
int * rea___errno_location__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 370  00326210  std___Rb_tree_insert_and_rebalance________________
// ------------------------------------------------------------------
void rea_std___Rb_tree_insert_and_rebalance__dup2(bool param_1, _Rb_tree_node_base * param_2, _Rb_tree_node_base * param_3, _Rb_tree_node_base * param_4)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 371  00326220  std____throw_bad_function_call
// ------------------------------------------------------------------
void rea_std____throw_bad_function_call__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 372  00326228  std___Rb_tree_rebalance_for_erase
// ------------------------------------------------------------------
void rea_std___Rb_tree_rebalance_for_erase__dup2(_Rb_tree_node_base * param_1, _Rb_tree_node_base * param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 373  00326230  strcmp
// ------------------------------------------------------------------
int rea_strcmp__dup2(char * __s1, char * __s2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 374  00326238  deflateBound
// ------------------------------------------------------------------
void rea_deflateBound__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 375  00326240  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign__dup3(char * param_1, ulong param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 376  00326250  epoll_wait
// ------------------------------------------------------------------
int rea_epoll_wait__dup2(int __epfd, epoll_event * __events, int __maxevents, int __timeout)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 377  00326258  freeifaddrs
// ------------------------------------------------------------------
void rea_freeifaddrs__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 378  00326260  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign__dup4(string * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 379  00326268  deflateInit2_
// ------------------------------------------------------------------
void rea_deflateInit2__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 380  00326270  memmem
// ------------------------------------------------------------------
void * rea_memmem__dup2(void * __haystack, size_t __haystacklen, void * __needle, size_t __needlelen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 381  00326280  remove
// ------------------------------------------------------------------
int rea_remove__dup2(char * __filename)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 382  00326288  strncpy
// ------------------------------------------------------------------
char * rea_strncpy__dup2(char * __dest, char * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 383  00326290  PyTuple_New
// ------------------------------------------------------------------
void rea_PyTuple_New__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 384  00326298  std___Rb_tree_increment
// ------------------------------------------------------------------
void rea_std___Rb_tree_increment__dup4(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 385  003262a0  __cxa_end_catch
// ------------------------------------------------------------------
void rea___cxa_end_catch__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 386  003262b8  sigemptyset
// ------------------------------------------------------------------
int rea_sigemptyset__dup2(sigset_t * __set)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 387  003262c0  __cxa_begin_catch
// ------------------------------------------------------------------
void rea___cxa_begin_catch__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 388  003262c8  bind
// ------------------------------------------------------------------
int rea_bind__dup2(int __fd, sockaddr * __addr, socklen_t __len)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 389  003262d0  fwrite
// ------------------------------------------------------------------
size_t rea_fwrite__dup2(void * __ptr, size_t __size, size_t __n, FILE * __s)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 390  003262d8  perror
// ------------------------------------------------------------------
void rea_perror__dup2(char * __s)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 391  003262e0  __gxx_personality_v0
// ------------------------------------------------------------------
void rea___gxx_personality_v0(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 392  003262e8  fprintf
// ------------------------------------------------------------------
int rea_fprintf__dup2(FILE * __stream, char * __format, undefined8 param_x2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 393  003262f0  write
// ------------------------------------------------------------------
ssize_t rea_write__dup2(int __fd, void * __buf, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 394  003262f8  operator_new
// ------------------------------------------------------------------
void * rea_operator__new__dup2(ulong param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 395  00326300  _Unwind_Resume
// ------------------------------------------------------------------
void rea__Unwind_Resume__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 396  00326308  accept
// ------------------------------------------------------------------
int rea_accept__dup2(int __fd, sockaddr * __addr, socklen_t * __addr_len)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 397  00326310  std__string___M_leak_hard
// ------------------------------------------------------------------
void rea_std__string___M_leak_hard__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 398  00326318  memcpy
// ------------------------------------------------------------------
void * rea_memcpy__dup2(void * __dest, void * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 399  00326320  fcntl
// ------------------------------------------------------------------
int rea_fcntl__dup2(int __fd, int __cmd, undefined8 param_x2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





