
void FUN_001083a0(undefined8 *param_1)

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
     (lVar10 = current_time(), lVar10 - *(long *)(*plVar3 + 0xe0) <= *(long *)(*plVar3 + 0xe8))) {
    return;
  }
  std::string::string((string *)&local_50,"",(allocator *)local_48);
  lVar4 = *plVar3;
  p_Var11 = operator_new(0x20);
  puVar8 = PTR__S_empty_rep_storage_00324fa0;
  if (p_Var11 != (_List_node_base *)0x0) {
    *(undefined8 *)p_Var11 = 0;
    *(undefined8 *)(p_Var11 + 8) = 0;
    *(undefined4 *)(p_Var11 + 0x10) = 1;
    *(undefined **)(p_Var11 + 0x18) = local_50;
    local_50 = puVar8 + 0x18;
  }
  std::__detail::_List_node_base::_M_hook(p_Var11);
  if ((*(char *)(lVar4 + 0xb8) != '\0') &&
     (pvVar5 = *(void **)(lVar4 + 0xa8), (void *)(lVar4 + 0xa8) != pvVar5)) {
    uVar2 = *(undefined4 *)((long)pvVar5 + 0x10);
    lVar6 = *(long *)((long)pvVar5 + 0x18);
    *(undefined **)((long)pvVar5 + 0x18) = puVar8 + 0x18;
    std::__detail::_List_node_base::_M_unhook();
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
        std::string::_Rep::_M_destroy((allocator *)(lVar7 + -0x18));
      }
    }
    operator_delete(pvVar5);
    *(undefined1 *)(lVar4 + 0xb8) = 0;
    if (*(long *)(lVar4 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
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
        std::string::_Rep::_M_destroy((allocator *)(local_40 + -0x18));
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
      std::string::_Rep::_M_destroy((allocator *)(local_50 + -0x18));
    }
  }
  *(long *)(*plVar3 + 0xe0) = lVar10;
  return;
}



