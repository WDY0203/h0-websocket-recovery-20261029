
void FUN_00107834(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      operator_delete((void *)*param_1);
    }
    operator_delete(param_1);
    return;
  }
  return;
}



