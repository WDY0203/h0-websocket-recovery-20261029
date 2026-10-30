
/* WSConn::read_data_mask(int, bool, unsigned long, std::function<void (std::unique_ptr<Buffer,
   std::default_delete<Buffer> >)>) */

void __thiscall
WSConn::read_data_mask(WSConn *this,undefined4 param_1,undefined1 param_2,long param_3,long param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *local_88 [2];
  code *local_78;
  code *local_70;
  WSConn *local_68;
  long local_60;
  undefined1 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  code *local_40;
  undefined8 local_38;
  
  local_40 = (code *)0x0;
  local_68 = this;
  local_60 = param_3;
  local_58 = param_2;
  local_54 = param_1;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(&local_50,param_5,2);
    local_38 = *(undefined8 *)(param_5 + 0x18);
    local_40 = *(code **)(param_5 + 0x10);
  }
  local_78 = (code *)0x0;
  local_88[0] = operator_new(0x38);
  pcVar4 = local_40;
  uVar1 = local_88[0][3];
  uVar2 = local_88[0][4];
  local_88[0][5] = 0;
  uVar3 = local_88[0][6];
  *local_88[0] = local_68;
  local_88[0][1] = local_60;
  *(undefined1 *)(local_88[0] + 2) = local_58;
  *(undefined4 *)((long)local_88[0] + 0x14) = local_54;
  local_88[0][3] = local_50;
  local_88[0][4] = uStack_48;
  local_40 = (code *)0x0;
  local_88[0][5] = pcVar4;
  local_88[0][6] = local_38;
  local_70 = FUN_00110d50;
  local_78 = FUN_0010ec20;
  local_50 = uVar1;
  uStack_48 = uVar2;
  local_38 = uVar3;
  recv_more(this,param_3 + 4,local_88);
  if (local_78 != (code *)0x0) {
    (*local_78)(local_88,local_88,3);
  }
  if (local_40 != (code *)0x0) {
    (*local_40)(&local_50,&local_50,3);
  }
  return;
}



