
void FUN_0010dcc0(long *param_1,int param_2)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  long lVar6;
  size_t __n;
  undefined8 *puVar7;
  
  param_1 = (long *)*param_1;
  lVar6 = *param_1;
  puVar7 = *(undefined8 **)(lVar6 + 0x40);
  pvVar5 = (void *)*puVar7;
  pvVar4 = memmem(pvVar5,puVar7[1] - (long)pvVar5,"permessage-deflate",0x12);
  if (pvVar4 == (void *)0x0) goto LAB_0010dd9e;
  *(undefined1 *)(lVar6 + 0x58) = 1;
  pvVar5 = operator_new(0x70);
  lVar1 = *param_1;
  *(void **)(lVar6 + 0x60) = pvVar5;
  pvVar5 = operator_new(0x70);
  *(void **)(lVar1 + 0x68) = pvVar5;
  puVar7 = *(undefined8 **)(*param_1 + 0x60);
  puVar2 = *(undefined8 **)(*param_1 + 0x68);
  puVar7[8] = 0;
  puVar7[9] = 0;
  puVar7[10] = 0;
  *(undefined4 *)(puVar7 + 1) = 0;
  *puVar7 = 0;
  iVar3 = inflateInit2_(puVar7,0xfffffff1,"1.2.7",0x70);
  if (iVar3 == 0) {
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    *(undefined4 *)(puVar2 + 1) = 0;
    *puVar2 = 0;
    iVar3 = deflateInit2_(puVar2,0xffffffff,8,0xfffffff1,8,0,"1.2.7",0x70);
    if (iVar3 != 0) {
      inflateEnd(puVar7);
      goto LAB_0010dd77;
    }
  }
  else {
LAB_0010dd77:
    lVar6 = *param_1;
    *(undefined1 *)(lVar6 + 0x58) = 0;
    operator_delete(*(void **)(lVar6 + 0x60));
    operator_delete(*(void **)(*param_1 + 0x68));
  }
  puVar7 = *(undefined8 **)(*param_1 + 0x40);
  pvVar5 = (void *)*puVar7;
LAB_0010dd9e:
  pvVar4 = (void *)((long)(param_2 + 4) + (long)pvVar5);
  if (pvVar4 != pvVar5) {
    lVar6 = 0;
    if ((pvVar4 != (void *)puVar7[1]) && (__n = (long)puVar7[1] - (long)pvVar4, __n != 0)) {
      pvVar5 = memmove(pvVar5,pvVar4,__n);
      lVar6 = puVar7[1] - (long)pvVar4;
    }
    puVar7[1] = (long)pvVar5 + lVar6;
  }
  if (param_1[3] == 0) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_function_call();
  }
                    /* WARNING: Could not recover jumptable at 0x0010dde9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1[4])(param_1 + 1);
  return;
}



