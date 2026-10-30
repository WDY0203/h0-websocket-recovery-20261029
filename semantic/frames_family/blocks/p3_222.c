
void FUN_00110a20(long *param_1)

{
  void *__src;
  undefined8 *puVar1;
  code *pcVar2;
  undefined2 uVar3;
  long lVar4;
  void *__dest;
  long lVar5;
  size_t __n;
  undefined1 auStack_48 [16];
  code *local_38;
  long lStack_30;
  
  param_1 = (long *)*param_1;
  puVar1 = *(undefined8 **)(*param_1 + 0x40);
  __dest = (void *)*puVar1;
  __src = (void *)((long)__dest + 4);
  uVar3 = CONCAT11(*(undefined1 *)((long)__dest + 2),*(undefined1 *)((long)__dest + 3));
  lVar5 = 0;
  if ((__src != (void *)puVar1[1]) && (__n = (long)puVar1[1] - (long)__src, __n != 0)) {
    __dest = memmove(__dest,__src,__n);
    lVar5 = puVar1[1] - (long)__src;
  }
  lVar4 = param_1[1];
  puVar1[1] = (long)__dest + lVar5;
  local_38 = (code *)0x0;
  pcVar2 = (code *)param_1[5];
  if ((char)lVar4 == '\0') {
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(auStack_48,param_1 + 3,2);
      local_38 = (code *)param_1[5];
      lStack_30 = param_1[6];
    }
    WSConn::read_data((WSConn *)*param_1,*(undefined4 *)((long)param_1 + 0xc),(char)param_1[2],uVar3
                      ,auStack_48);
    if (local_38 != (code *)0x0) {
      (*local_38)(auStack_48,auStack_48,3);
      return;
    }
  }
  else {
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(auStack_48,param_1 + 3,2);
      local_38 = (code *)param_1[5];
      lStack_30 = param_1[6];
    }
    WSConn::read_data_mask
              ((WSConn *)*param_1,*(undefined4 *)((long)param_1 + 0xc),(char)param_1[2],uVar3,
               auStack_48);
    if (local_38 != (code *)0x0) {
      (*local_38)(auStack_48,auStack_48,3);
    }
  }
  return;
}



