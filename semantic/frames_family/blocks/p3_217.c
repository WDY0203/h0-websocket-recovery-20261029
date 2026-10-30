
/* WSConn::accept(std::function<void ()>, std::function<void (std::string)>) */

void __thiscall WSConn::accept(WSConn *this,long param_2,long param_3)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  code *pcVar9;
  int iVar10;
  allocator local_aa [2];
  long local_a8 [2];
  undefined8 *local_98 [2];
  code *local_88;
  code *local_80;
  WSConn *local_78;
  undefined8 local_70;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  code *local_40;
  undefined8 local_38;
  
  local_60 = (code *)0x0;
  local_78 = this;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(&local_70,param_2,2);
    local_58 = *(undefined8 *)(param_2 + 0x18);
    local_60 = *(code **)(param_2 + 0x10);
  }
  local_40 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(&local_50,param_3,2);
    local_38 = *(undefined8 *)(param_3 + 0x18);
    local_40 = *(code **)(param_3 + 0x10);
  }
  local_88 = (code *)0x0;
  local_98[0] = operator_new(0x48);
  pcVar9 = local_40;
  pcVar8 = local_60;
  local_98[0][3] = 0;
  uVar2 = local_98[0][1];
  uVar3 = local_98[0][2];
  uVar4 = local_98[0][4];
  local_98[0][7] = 0;
  *local_98[0] = local_78;
  uVar5 = local_98[0][6];
  local_98[0][2] = local_68;
  uVar6 = local_98[0][5];
  local_98[0][1] = local_70;
  local_60 = (code *)0x0;
  local_98[0][3] = pcVar8;
  uVar7 = local_98[0][8];
  local_98[0][4] = local_58;
  local_98[0][6] = local_48;
  local_98[0][5] = local_50;
  local_40 = (code *)0x0;
  local_98[0][7] = pcVar9;
  local_98[0][8] = local_38;
  local_80 = FUN_00112c60;
  local_88 = FUN_0010e660;
  local_70 = uVar2;
  local_68 = uVar3;
  local_58 = uVar4;
  local_50 = uVar6;
  local_48 = uVar5;
  local_38 = uVar7;
  std::string::string((string *)local_a8,"\r\n\r\n",local_aa);
  recv_pat(this,(string *)local_a8,local_98);
  if ((allocator *)(local_a8[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_a8[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar10 = *(int *)(local_a8[0] + -8);
      *(int *)(local_a8[0] + -8) = iVar10 + -1;
    }
    else {
      LOCK();
      iVar10 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar10 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_a8[0] + -0x18));
    }
  }
  if (local_88 != (code *)0x0) {
    (*local_88)(local_98,local_98,3);
  }
  if (local_40 != (code *)0x0) {
    (*local_40)(&local_50,&local_50,3);
  }
  if (local_60 != (code *)0x0) {
    (*local_60)(&local_70,&local_70,3);
  }
  return;
}



