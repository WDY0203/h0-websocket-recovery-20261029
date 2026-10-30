
/* UnixClient::UnixClient(std::string const&, std::function<void (TcpConn*)>, std::function<void
   (int)>) */

void __thiscall UnixClient::UnixClient(UnixClient *this,string *param_1,long param_3,long param_4)

{
  long *plVar1;
  undefined *puVar2;
  int __fd;
  int iVar3;
  TcpConn *this_00;
  int *piVar4;
  sockaddr local_a8 [7];
  
  *(UnixClient **)(this + 0x20) = this + 0x10;
  *(UnixClient **)(this + 0x28) = this + 0x10;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(UnixClient **)(this + 0x50) = this + 0x40;
  *(UnixClient **)(this + 0x58) = this + 0x40;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(UnixClient **)(this + 0x80) = this + 0x70;
  *(UnixClient **)(this + 0x88) = this + 0x70;
  puVar2 = PTR_vtable_00324f70;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined **)this = puVar2 + 0x10;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(this + 0xa8,param_3,2);
    *(undefined8 *)(this + 0xc0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this + 0xb8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(undefined8 *)(this + 0xd8) = 0;
  if (*(code **)(param_4 + 0x10) != (code *)0x0) {
    (**(code **)(param_4 + 0x10))(this + 200,param_4,2);
    *(undefined8 *)(this + 0xe0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this + 0xd8) = *(undefined8 *)(param_4 + 0x10);
  }
  bzero(local_a8,0x6e);
  local_a8[0].sa_family = 1;
  strncpy(local_a8[0].sa_data,*(char **)param_1,0x6b);
  __fd = socket(1,1,0);
  if (__fd < 0) {
    perror("socket");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  setcloexec(__fd);
  iVar3 = connect(__fd,local_a8,0x6e);
  if (iVar3 < 0) {
    piVar4 = __errno_location();
    iVar3 = *piVar4;
    *(undefined4 *)(this + 0x98) = 2;
    perror("connect");
    close(__fd);
    if (*(long *)(param_4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (**(code **)(param_4 + 0x18))(param_4,iVar3);
  }
  setnonblock(__fd);
  this_00 = operator_new(0xd0);
  TcpConn::TcpConn(this_00,__fd,param_1,param_1,(EventHandler *)this);
  plVar1 = *(long **)(this + 0xa0);
  *(TcpConn **)(this + 0xa0) = this_00;
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 8))();
    this_00 = *(TcpConn **)(this + 0xa0);
  }
  *(undefined4 *)(this + 0x98) = 1;
  if (*(long *)(param_3 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_function_call();
  }
  (**(code **)(param_3 + 0x18))(param_3,this_00);
  return;
}



