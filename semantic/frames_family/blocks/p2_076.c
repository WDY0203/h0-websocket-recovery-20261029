
/* WARNING: Switch with 1 destination removed at 0x00107320 */

void Buffer::appendf(char *param_1,...)

{
  int iVar1;
  char in_AL;
  int iVar2;
  void *pvVar3;
  undefined8 in_RCX;
  undefined8 in_RDX;
  ulong uVar4;
  ulong extraout_RDX;
  size_t __n;
  ulong uVar5;
  char *in_RSI;
  void *pvVar6;
  undefined8 in_R8;
  undefined8 in_R9;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  void *pvStack_128;
  ulong uStack_120;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined1 *puStack_f8;
  undefined1 *puStack_f0;
  undefined1 auStack_e8 [16];
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_a8;
  undefined8 uStack_98;
  undefined8 uStack_88;
  undefined8 uStack_78;
  undefined8 uStack_68;
  undefined8 uStack_58;
  undefined8 uStack_48;
  
  if (in_AL != '\0') {
    uStack_b8 = in_XMM0_Qa;
    uStack_a8 = in_XMM1_Qa;
    uStack_98 = in_XMM2_Qa;
    uStack_88 = in_XMM3_Qa;
    uStack_78 = in_XMM4_Qa;
    uStack_68 = in_XMM5_Qa;
    uStack_58 = in_XMM6_Qa;
    uStack_48 = in_XMM7_Qa;
  }
  puStack_f8 = &stack0x00000008;
  puStack_f0 = auStack_e8;
  uStack_100 = 0x10;
  uStack_fc = 0x30;
  uStack_d8 = in_RDX;
  uStack_d0 = in_RCX;
  uStack_c8 = in_R8;
  uStack_c0 = in_R9;
  iVar2 = vsnprintf((char *)0x0,0,in_RSI,&uStack_100);
  pvVar3 = *(void **)(param_1 + 8);
  pvVar6 = *(void **)param_1;
  __n = (long)pvVar3 - (long)pvVar6;
  iVar1 = (int)__n;
  uVar7 = iVar2 + iVar1;
  uVar8 = (ulong)uVar7;
  uVar9 = (ulong)(int)(uVar7 + 1);
  if (__n < uVar9) {
    uVar9 = uVar9 - __n;
    if (uVar9 == 0) goto LAB_00115994;
    if (uVar9 <= (ulong)(*(long *)(param_1 + 0x10) - (long)pvVar3)) {
      memset(pvVar3,0,uVar9);
      *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + uVar9;
      goto LAB_00115994;
    }
    if (uVar9 <= ~__n) {
      uStack_120 = 0xffffffffffffffff;
      uVar8 = __n;
      if (__n <= uVar9) {
        uVar8 = uVar9;
      }
      if ((CARRY8(uVar8,__n)) || (uStack_120 = uVar8 + __n, uVar8 + __n != 0)) {
        pvStack_128 = operator_new(uStack_120);
        pvVar6 = *(void **)param_1;
        __n = *(long *)(param_1 + 8) - (long)pvVar6;
      }
      else {
        uStack_120 = 0;
        pvStack_128 = (void *)0x0;
      }
      if (__n != 0) {
        memmove(pvStack_128,pvVar6,__n);
      }
      pvVar3 = (void *)((long)pvStack_128 + __n);
      memset(pvVar3,0,(uVar9 + (long)pvVar3) - (long)pvVar3);
      if (*(void **)param_1 != (void *)0x0) {
        operator_delete(*(void **)param_1);
      }
      *(ulong *)(param_1 + 8) = uVar9 + (long)pvVar3;
      *(void **)param_1 = pvStack_128;
      *(ulong *)(param_1 + 0x10) = (long)pvStack_128 + uStack_120;
      goto LAB_00115994;
    }
LAB_00115c22:
    std::__throw_length_error("vector::_M_default_append");
    uVar5 = extraout_RDX;
  }
  else {
    if (uVar9 < __n) {
      *(ulong *)(param_1 + 8) = uVar9 + (long)pvVar6;
    }
LAB_00115994:
    puStack_f8 = &stack0x00000008;
    uStack_100 = 0x10;
    puStack_f0 = auStack_e8;
    uStack_fc = 0x30;
    uVar8 = (ulong)(int)uVar7;
    vsnprintf((char *)((long)iVar1 + *(long *)param_1),(long)(iVar2 + 1),in_RSI,&uStack_100);
    pvVar3 = *(void **)(param_1 + 8);
    pvVar6 = *(void **)param_1;
    uVar9 = (long)pvVar3 - (long)pvVar6;
    if (uVar8 <= uVar9) {
      if (uVar9 <= uVar8) {
        return;
      }
      *(ulong *)(param_1 + 8) = uVar8 + (long)pvVar6;
      return;
    }
    uVar8 = uVar8 - uVar9;
    if (uVar8 == 0) {
      return;
    }
    if (uVar8 <= (ulong)(*(long *)(param_1 + 0x10) - (long)pvVar3)) {
      memset(pvVar3,0,uVar8);
      *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + uVar8;
      return;
    }
    if (~uVar9 < uVar8) goto LAB_00115c22;
    uVar4 = uVar9;
    if (uVar9 <= uVar8) {
      uVar4 = uVar8;
    }
    uVar5 = 0xffffffffffffffff;
    if ((!CARRY8(uVar4,uVar9)) && (uVar5 = uVar4 + uVar9, uVar4 + uVar9 == 0)) {
      uVar5 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_00115a5e;
    }
  }
  pvVar3 = operator_new(uVar5);
  pvVar6 = *(void **)param_1;
  uVar9 = *(long *)(param_1 + 8) - (long)pvVar6;
LAB_00115a5e:
  if (uVar9 != 0) {
    memmove(pvVar3,pvVar6,uVar9);
  }
  pvVar6 = (void *)((long)pvVar3 + uVar9);
  memset(pvVar6,0,(uVar8 + (long)pvVar6) - (long)pvVar6);
  if (*(void **)param_1 != (void *)0x0) {
    operator_delete(*(void **)param_1);
  }
  *(void **)param_1 = pvVar3;
  *(ulong *)(param_1 + 8) = uVar8 + (long)pvVar6;
  *(ulong *)(param_1 + 0x10) = uVar5 + (long)pvVar3;
  return;
}



