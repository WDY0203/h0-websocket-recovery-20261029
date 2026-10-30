
/* TcpClient::TcpClient(int, std::function<void (TcpConn*)>) */

void __thiscall TcpClient::TcpClient(TcpClient *this,int param_1,long param_3)

{
  int *piVar1;
  long *plVar2;
  undefined *puVar3;
  int iVar4;
  TcpConn *this_00;
  allocator local_3a [2];
  long local_38 [2];
  
  *(TcpClient **)(this + 0x20) = this + 0x10;
  *(TcpClient **)(this + 0x28) = this + 0x10;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(TcpClient **)(this + 0x50) = this + 0x40;
  *(TcpClient **)(this + 0x58) = this + 0x40;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(TcpClient **)(this + 0x80) = this + 0x70;
  *(TcpClient **)(this + 0x88) = this + 0x70;
  puVar3 = PTR_vtable_00324f98;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x98) = 1;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined **)this = puVar3 + 0x10;
  setcloexec(param_1);
  setnonblock(param_1);
  std::string::string((string *)local_38,"",local_3a);
  this_00 = operator_new(0xd0);
  TcpConn::TcpConn(this_00,param_1,(string *)local_38,(string *)local_38,(EventHandler *)this);
  plVar2 = *(long **)(this + 0xa0);
  *(TcpConn **)(this + 0xa0) = this_00;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 8))();
  }
  if ((allocator *)(local_38[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_38[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(local_38[0] + -8);
      *(int *)(local_38[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_38[0] + -0x18));
    }
  }
  if (*(long *)(param_3 + 0x10) != 0) {
    (**(code **)(param_3 + 0x18))(param_3,*(undefined8 *)(this + 0xa0));
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_function_call();
}



