
undefined8 FUN_00107ca0(undefined8 *param_1,undefined8 *param_2,int param_3)

{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = &PTR_vtable_00324760;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      operator_delete((void *)*param_1);
    }
  }
  return 0;
}



