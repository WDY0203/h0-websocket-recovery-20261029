
/* TcpConn::TcpConn(int, std::string const&, std::string const&, EventHandler*) */

void __thiscall
TcpConn::TcpConn(TcpConn *this,int param_1,string *param_2,string *param_3,EventHandler *param_4)

{
  undefined *puVar1;
  void *pvVar2;
  
  *(TcpConn **)(this + 0x20) = this + 0x10;
  *(TcpConn **)(this + 0x28) = this + 0x10;
  puVar1 = PTR_vtable_00324f08;
  *(int *)(this + 0x40) = param_1;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(EventHandler **)(this + 0x38) = param_4;
  *(undefined **)this = puVar1 + 0x10;
  std::string::string((string *)(this + 0x48),param_2);
  std::string::string((string *)(this + 0x50),param_3);
  this[0x58] = (TcpConn)0x1;
  this[0x59] = (TcpConn)0x1;
  this[0x5a] = (TcpConn)0x0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  this[0x88] = (TcpConn)0x0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  pvVar2 = operator_new(1);
  *(void **)(this + 0xb0) = pvVar2;
  *(code **)(this + 200) = FUN_00117d90;
  *(code **)(this + 0xc0) = FUN_00117da0;
  return;
}



