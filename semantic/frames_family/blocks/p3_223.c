
/* WSConn::read_head(std::function<void (std::unique_ptr<Buffer, std::default_delete<Buffer> >)>) */

void __thiscall WSConn::read_head(WSConn *this,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *local_68 [2];
  code *local_58;
  code *local_50;
  WSConn *local_48;
  undefined8 local_40;
  undefined8 local_38;
  code *local_30;
  undefined8 local_28;
  
  local_30 = (code *)0x0;
  local_48 = this;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(&local_40,param_2,2);
    local_28 = *(undefined8 *)(param_2 + 0x18);
    local_30 = *(code **)(param_2 + 0x10);
  }
  local_58 = (code *)0x0;
  local_68[0] = operator_new(0x28);
  pcVar4 = local_30;
  local_68[0][3] = 0;
  uVar1 = local_68[0][1];
  uVar2 = local_68[0][2];
  uVar3 = local_68[0][4];
  *local_68[0] = local_48;
  local_68[0][2] = local_38;
  local_68[0][1] = local_40;
  local_30 = (code *)0x0;
  local_68[0][3] = pcVar4;
  local_68[0][4] = local_28;
  local_50 = FUN_001115a0;
  local_58 = FUN_0010e800;
  local_40 = uVar1;
  local_38 = uVar2;
  local_28 = uVar3;
  recv_more(this,2,local_68);
  if (local_58 != (code *)0x0) {
    (*local_58)(local_68,local_68,3);
  }
  if (local_30 != (code *)0x0) {
    (*local_30)(&local_40,&local_40,3);
  }
  return;
}



