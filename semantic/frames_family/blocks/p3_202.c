
undefined8 FUN_0010dfb0(long *param_1,long *param_2,int param_3)

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
      *param_1 = (long)&PTR_vtable_00324900;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar4 = (undefined8 *)*param_2;
      puVar6 = operator_new(0x30);
      *puVar6 = *puVar4;
      std::string::string((string *)(puVar6 + 1),(string *)(puVar4 + 1));
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
          std::string::_Rep::_M_destroy((allocator *)(lVar3 + -0x18));
        }
      }
      operator_delete(pvVar2);
    }
  }
  return 0;
}



