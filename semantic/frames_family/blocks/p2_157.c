
undefined8 FUN_00107a20(undefined8 *param_1,undefined8 *param_2,int param_3)

{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = &PTR_vtable_00324790;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      operator_delete((void *)*param_1);
    }
  }
  return 0;
}



