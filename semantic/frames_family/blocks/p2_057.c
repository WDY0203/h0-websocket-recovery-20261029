
/* WARNING: Switch with 1 destination removed at 0x001071f0 */

void __thiscall
WSConn::read_data(WSConn *this,undefined4 param_1,undefined1 param_2,undefined8 param_3,long param_5
                 )

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *apuStack_88 [2];
  code *pcStack_78;
  code *pcStack_70;
  WSConn *pWStack_68;
  undefined8 uStack_60;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined8 uStack_50;
  undefined8 uStack_48;
  code *pcStack_40;
  undefined8 uStack_38;
  
  pcStack_40 = (code *)0x0;
  pWStack_68 = this;
  uStack_60 = param_3;
  uStack_58 = param_2;
  uStack_54 = param_1;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(&uStack_50,param_5,2);
    uStack_38 = *(undefined8 *)(param_5 + 0x18);
    pcStack_40 = *(code **)(param_5 + 0x10);
  }
  pcStack_78 = (code *)0x0;
  apuStack_88[0] = operator_new(0x38);
  pcVar4 = pcStack_40;
  uVar1 = apuStack_88[0][3];
  uVar2 = apuStack_88[0][4];
  apuStack_88[0][5] = 0;
  uVar3 = apuStack_88[0][6];
  *apuStack_88[0] = pWStack_68;
  apuStack_88[0][1] = uStack_60;
  *(undefined1 *)(apuStack_88[0] + 2) = uStack_58;
  *(undefined4 *)((long)apuStack_88[0] + 0x14) = uStack_54;
  apuStack_88[0][3] = uStack_50;
  apuStack_88[0][4] = uStack_48;
  pcStack_40 = (code *)0x0;
  apuStack_88[0][5] = pcVar4;
  apuStack_88[0][6] = uStack_38;
  pcStack_70 = FUN_00111100;
  pcStack_78 = FUN_0010e980;
  uStack_50 = uVar1;
  uStack_48 = uVar2;
  uStack_38 = uVar3;
  recv_more(this,param_3,apuStack_88);
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(apuStack_88,apuStack_88,3);
  }
  if (pcStack_40 != (code *)0x0) {
    (*pcStack_40)(&uStack_50,&uStack_50,3);
  }
  return;
}



