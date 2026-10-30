
undefined8 FUN_0010e530(long *param_1,long *param_2,int param_3)

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
      *param_1 = (long)&PTR_vtable_00324910;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar2 = (undefined8 *)*param_2;
    puVar4 = operator_new(0x30);
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
    operator_delete(pvVar1);
    return 0;
  }
  return 0;
}



