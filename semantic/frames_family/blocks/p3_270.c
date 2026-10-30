
/* TcpClient::~TcpClient() */

void __thiscall TcpClient::~TcpClient(TcpClient *this)

{
  void *pvVar1;
  void *pvVar2;
  undefined *puVar3;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  TcpClient *pTVar4;
  
  *(undefined **)this = PTR_vtable_00324f98 + 0x10;
  if (*(code **)(this + 0xd8) != (code *)0x0) {
    (**(code **)(this + 0xd8))(this + 200,this + 200,3);
  }
  if (*(code **)(this + 0xb8) != (code *)0x0) {
    (**(code **)(this + 0xb8))(this + 0xa8,this + 0xa8,3);
  }
  if (*(long **)(this + 0xa0) != (long *)0x0) {
    (**(code **)(**(long **)(this + 0xa0) + 8))();
  }
  puVar3 = PTR_vtable_00324fb8;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined **)this = puVar3 + 0x10;
  pTVar4 = this + 0x98;
  do {
    this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
               *)(pTVar4 + -0x30);
    pvVar2 = *(void **)(pTVar4 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std::
      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
      ::_M_erase(this_00,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long)pvVar2 + 0x10);
      operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pTVar4 = (TcpClient *)this_00;
  } while (this + 0x38 != (TcpClient *)this_00);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::_M_erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(this + 8),*(_Rb_tree_node **)(this + 0x18));
  return;
}



