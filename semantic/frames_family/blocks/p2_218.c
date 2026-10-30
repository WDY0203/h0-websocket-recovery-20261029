
void FUN_0010fc40(long *param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  allocator local_79;
  long local_78 [2];
  undefined8 *local_68 [2];
  code *local_58;
  code *local_50;
  undefined8 local_48;
  undefined1 local_40 [16];
  code *local_30;
  undefined8 local_28;
  
  puVar2 = (undefined8 *)*param_1;
  local_48 = *puVar2;
  local_30 = (code *)0x0;
  if ((code *)puVar2[3] != (code *)0x0) {
    (*(code *)puVar2[3])(local_40,puVar2 + 1,2);
    local_28 = puVar2[4];
    local_30 = (code *)puVar2[3];
  }
  local_58 = (code *)0x0;
  local_68[0] = operator_new(0x28);
  local_68[0][3] = 0;
  *local_68[0] = local_48;
  if (local_30 != (code *)0x0) {
    (*local_30)(local_68[0] + 1,local_40,2);
    local_68[0][4] = local_28;
    local_68[0][3] = local_30;
  }
  local_50 = FUN_0010dbc0;
  local_58 = FUN_0010e300;
  std::string::string((string *)local_78,"\r\n\r\n",&local_79);
  WSConn::recv_pat((WSConn *)*puVar2,(string *)local_78,local_68);
  if ((allocator *)(local_78[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_78[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar3 = *(int *)(local_78[0] + -8);
      *(int *)(local_78[0] + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_78[0] + -0x18));
    }
  }
  if (local_58 != (code *)0x0) {
    (*local_58)(local_68,local_68,3);
  }
  if (local_30 != (code *)0x0) {
    (*local_30)(local_40,local_40,3);
  }
  return;
}



