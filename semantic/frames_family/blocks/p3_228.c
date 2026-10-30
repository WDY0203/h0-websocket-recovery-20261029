
void FUN_00111b50(long *param_1)

{
  void *__src;
  char cVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  void *__dest;
  long lVar5;
  size_t __n;
  long lVar6;
  undefined1 auStack_48 [16];
  code *local_38;
  undefined8 uStack_30;
  
  puVar2 = (undefined8 *)*param_1;
  puVar3 = *(undefined8 **)((WSConn *)*puVar2 + 0x40);
  __dest = (void *)*puVar3;
  if ((((*(char *)((long)__dest + 2) == '\0') && (*(char *)((long)__dest + 3) == '\0')) &&
      (*(char *)((long)__dest + 4) == '\0')) && (*(char *)((long)__dest + 5) == '\0')) {
    __src = (void *)((long)__dest + 10);
    lVar5 = 0;
    lVar6 = (long)(int)((uint)*(byte *)((long)__dest + 6) << 0x18 |
                        (uint)*(byte *)((long)__dest + 7) << 0x10 |
                        (uint)*(byte *)((long)__dest + 9) | (uint)*(byte *)((long)__dest + 8) << 8);
    if ((__src != (void *)puVar3[1]) && (__n = (long)puVar3[1] - (long)__src, __n != 0)) {
      __dest = memmove(__dest,__src,__n);
      lVar5 = puVar3[1] - (long)__src;
    }
    cVar1 = *(char *)(puVar2 + 1);
    puVar3[1] = (long)__dest + lVar5;
    local_38 = (code *)0x0;
    pcVar4 = (code *)puVar2[5];
    if (cVar1 == '\0') {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(auStack_48,puVar2 + 3,2);
        local_38 = (code *)puVar2[5];
        uStack_30 = puVar2[6];
      }
      WSConn::read_data((WSConn *)*puVar2,*(undefined4 *)((long)puVar2 + 0xc),
                        *(undefined1 *)(puVar2 + 2),lVar6,auStack_48);
      if (local_38 != (code *)0x0) {
        (*local_38)(auStack_48,auStack_48,3);
        return;
      }
    }
    else {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(auStack_48,puVar2 + 3,2);
        local_38 = (code *)puVar2[5];
        uStack_30 = puVar2[6];
      }
      WSConn::read_data_mask
                ((WSConn *)*puVar2,*(undefined4 *)((long)puVar2 + 0xc),*(undefined1 *)(puVar2 + 2),
                 lVar6,auStack_48);
      if (local_38 != (code *)0x0) {
        (*local_38)(auStack_48,auStack_48,3);
        return;
      }
    }
  }
  else {
    WSConn::exit((WSConn *)*puVar2);
  }
  return;
}



