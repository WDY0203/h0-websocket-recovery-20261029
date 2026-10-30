
void FUN_001114a0(long *param_1)

{
  byte *__src;
  byte bVar1;
  byte bVar2;
  undefined8 *puVar3;
  code *pcVar4;
  byte *__dest;
  long lVar5;
  size_t __n;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  long *local_98 [2];
  code *local_88;
  code *local_80;
  long local_78;
  byte local_70;
  uint local_6c;
  code *local_68;
  long alStack_60 [2];
  code *local_50;
  long local_48;
  
  param_1 = (long *)*param_1;
  local_78 = *param_1;
  puVar3 = *(undefined8 **)(local_78 + 0x40);
  __dest = (byte *)*puVar3;
  bVar1 = *__dest;
  bVar2 = __dest[1];
  bVar8 = bVar1 >> 7;
  local_70 = bVar2 >> 7;
  uVar7 = bVar1 & 0xf;
  bVar6 = bVar2;
  if ((bVar1 & 0x40) != 0) {
    *(undefined1 *)(local_78 + 0x59) = 1;
    bVar6 = __dest[1];
  }
  bVar6 = bVar6 & 0x7f;
  local_6c = uVar7;
  if (bVar6 == 0x7e) {
    local_68 = (code *)CONCAT71(local_68._1_7_,bVar8);
    local_50 = (code *)0x0;
    if ((code *)param_1[3] != (code *)0x0) {
      (*(code *)param_1[3])(alStack_60,param_1 + 1,2);
      local_48 = param_1[4];
      local_50 = (code *)param_1[3];
    }
    local_88 = (code *)0x0;
    local_98[0] = operator_new(0x38);
    *local_98[0] = local_78;
    *(byte *)(local_98[0] + 1) = local_70;
    *(uint *)((long)local_98[0] + 0xc) = local_6c;
    local_98[0][5] = 0;
    *(undefined1 *)(local_98[0] + 2) = local_68._0_1_;
    if (local_50 != (code *)0x0) {
      (*local_50)(local_98[0] + 3,alStack_60,2);
      local_98[0][6] = local_48;
      local_98[0][5] = (long)local_50;
    }
    local_80 = FUN_00110920;
    local_88 = FUN_0010ead0;
    WSConn::recv_more((WSConn *)*param_1,4,local_98);
    if (local_88 != (code *)0x0) {
      (*local_88)(local_98,local_98,3);
    }
    if (local_50 != (code *)0x0) {
      (*local_50)(alStack_60,alStack_60,3);
      return;
    }
  }
  else if (bVar6 == 0x7f) {
    local_68 = (code *)CONCAT71(local_68._1_7_,bVar8);
    local_50 = (code *)0x0;
    if ((code *)param_1[3] != (code *)0x0) {
      (*(code *)param_1[3])(alStack_60,param_1 + 1,2);
      local_48 = param_1[4];
      local_50 = (code *)param_1[3];
    }
    local_88 = (code *)0x0;
    local_98[0] = operator_new(0x38);
    *local_98[0] = local_78;
    *(byte *)(local_98[0] + 1) = local_70;
    *(uint *)((long)local_98[0] + 0xc) = local_6c;
    local_98[0][5] = 0;
    *(undefined1 *)(local_98[0] + 2) = local_68._0_1_;
    if (local_50 != (code *)0x0) {
      (*local_50)(local_98[0] + 3,alStack_60,2);
      local_98[0][6] = local_48;
      local_98[0][5] = (long)local_50;
    }
    local_80 = FUN_00111a50;
    local_88 = FUN_0010e830;
    WSConn::recv_more((WSConn *)*param_1,10,local_98);
    if (local_88 != (code *)0x0) {
      (*local_88)(local_98,local_98,3);
    }
    if (local_50 != (code *)0x0) {
      (*local_50)(alStack_60,alStack_60,3);
      return;
    }
  }
  else {
    __src = __dest + 2;
    lVar5 = 0;
    if ((__src != (byte *)puVar3[1]) && (__n = (long)puVar3[1] - (long)__src, __n != 0)) {
      __dest = memmove(__dest,__src,__n);
      lVar5 = puVar3[1] - (long)__src;
    }
    puVar3[1] = __dest + lVar5;
    local_68 = (code *)0x0;
    pcVar4 = (code *)param_1[3];
    if ((char)bVar2 < '\0') {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(&local_78,param_1 + 1,2);
        local_68 = (code *)param_1[3];
        alStack_60[0] = param_1[4];
      }
      WSConn::read_data_mask((WSConn *)*param_1,uVar7,bVar8,bVar6,&local_78);
      if (local_68 != (code *)0x0) {
        (*local_68)(&local_78,&local_78,3);
        return;
      }
    }
    else {
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(&local_78,param_1 + 1,2);
        local_68 = (code *)param_1[3];
        alStack_60[0] = param_1[4];
      }
      WSConn::read_data((WSConn *)*param_1,uVar7,bVar8,bVar6,&local_78);
      if (local_68 != (code *)0x0) {
        (*local_68)(&local_78,&local_78,3);
      }
    }
  }
  return;
}



