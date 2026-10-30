
/* WARNING: Switch with 1 destination removed at 0x00107680 */

void __thiscall WSConn::read_head(WSConn *this,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *apuStack_68 [2];
  code *pcStack_58;
  code *pcStack_50;
  WSConn *pWStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  code *pcStack_30;
  undefined8 uStack_28;
  
  pcStack_30 = (code *)0x0;
  pWStack_48 = this;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(&uStack_40,param_2,2);
    uStack_28 = *(undefined8 *)(param_2 + 0x18);
    pcStack_30 = *(code **)(param_2 + 0x10);
  }
  pcStack_58 = (code *)0x0;
  apuStack_68[0] = operator_new(0x28);
  pcVar4 = pcStack_30;
  apuStack_68[0][3] = 0;
  uVar1 = apuStack_68[0][1];
  uVar2 = apuStack_68[0][2];
  uVar3 = apuStack_68[0][4];
  *apuStack_68[0] = pWStack_48;
  apuStack_68[0][2] = uStack_38;
  apuStack_68[0][1] = uStack_40;
  pcStack_30 = (code *)0x0;
  apuStack_68[0][3] = pcVar4;
  apuStack_68[0][4] = uStack_28;
  pcStack_50 = FUN_001115a0;
  pcStack_58 = FUN_0010e800;
  uStack_40 = uVar1;
  uStack_38 = uVar2;
  uStack_28 = uVar3;
  recv_more(this,2,apuStack_68);
  if (pcStack_58 != (code *)0x0) {
    (*pcStack_58)(apuStack_68,apuStack_68,3);
  }
  if (pcStack_30 != (code *)0x0) {
    (*pcStack_30)(&uStack_40,&uStack_40,3);
  }
  return;
}



