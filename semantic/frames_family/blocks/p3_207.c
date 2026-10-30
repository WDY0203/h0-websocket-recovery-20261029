
undefined8 FUN_0010e660(long *param_1,long *param_2,int param_3)

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
      *param_1 = (long)&PTR_vtable_00324930;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar2 = (undefined8 *)*param_2;
      puVar4 = operator_new(0x48);
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
      operator_delete(pvVar1);
    }
  }
  return 0;
}



