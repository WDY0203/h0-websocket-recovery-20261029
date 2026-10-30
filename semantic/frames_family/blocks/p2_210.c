
undefined8 FUN_0010ead0(long *param_1,long *param_2,int param_3)

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
      *param_1 = (long)&PTR_vtable_00324960;
      return 0;
    }
  }
  else if (param_3 == 2) {
    puVar3 = (undefined8 *)*param_2;
    puVar4 = operator_new(0x38);
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
    operator_delete(pvVar2);
    return 0;
  }
  return 0;
}



