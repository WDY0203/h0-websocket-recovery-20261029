
undefined8 FUN_001079a0(long *param_1,long *param_2,int param_3)

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
      *param_1 = (long)&PTR_vtable_00324770;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      puVar1 = (undefined8 *)*param_2;
      puVar3 = operator_new(0x10);
      uVar2 = puVar1[1];
      *puVar3 = *puVar1;
      puVar3[1] = uVar2;
      *param_1 = (long)puVar3;
      return 0;
    }
    if (param_3 == 3) {
      operator_delete((void *)*param_1);
    }
  }
  return 0;
}



