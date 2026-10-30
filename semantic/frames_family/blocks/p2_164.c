
void FUN_00107dd0(undefined8 *param_1)

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
  
  *param_1 = &PTR_FUN_00324730;
  if (*(char *)(param_1 + 1) != '\0') {
    std::string::string((string *)&local_50,"",(allocator *)local_48);
    lVar3 = param_1[2];
    p_Var9 = operator_new(0x20);
    puVar7 = PTR__S_empty_rep_storage_00324fa0;
    if (p_Var9 != (_List_node_base *)0x0) {
      *(undefined8 *)p_Var9 = 0;
      *(undefined8 *)(p_Var9 + 8) = 0;
      *(undefined4 *)(p_Var9 + 0x10) = 0xffffffff;
      *(undefined **)(p_Var9 + 0x18) = local_50;
      local_50 = puVar7 + 0x18;
    }
    std::__detail::_List_node_base::_M_hook(p_Var9);
    if ((*(char *)(lVar3 + 0xb8) != '\0') &&
       (pvVar4 = *(void **)(lVar3 + 0xa8), (void *)(lVar3 + 0xa8) != pvVar4)) {
      uVar2 = *(undefined4 *)((long)pvVar4 + 0x10);
      lVar5 = *(long *)((long)pvVar4 + 0x18);
      *(undefined **)((long)pvVar4 + 0x18) = puVar7 + 0x18;
      std::__detail::_List_node_base::_M_unhook();
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
          std::string::_Rep::_M_destroy((allocator *)(lVar6 + -0x18));
        }
      }
      operator_delete(pvVar4);
      *(undefined1 *)(lVar3 + 0xb8) = 0;
      if (*(long *)(lVar3 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_function_call();
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
          std::string::_Rep::_M_destroy((allocator *)(local_40 + -0x18));
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
        std::string::_Rep::_M_destroy((allocator *)(local_50 + -0x18));
      }
    }
    *(undefined8 *)(param_1[2] + 0x68) = 0;
  }
  *param_1 = PTR_vtable_00324ef0 + 0x10;
  return;
}



