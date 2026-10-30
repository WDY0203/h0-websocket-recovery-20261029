
/* TcpConn::~TcpConn() */

void __thiscall TcpConn::~TcpConn(TcpConn *this)

{
  int *piVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  int iVar5;
  int local_28 [4];
  
  lVar2 = *(long *)(this + 0x38);
  *(undefined **)this = PTR_vtable_00324f08 + 0x10;
  local_28[0] = *(int *)(this + 0x40);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
           *)(lVar2 + 8),local_28);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
           *)(lVar2 + 0x38),local_28);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
           *)(lVar2 + 0x68),local_28);
  close(*(int *)(this + 0x40));
  if (*(code **)(this + 0xc0) != (code *)0x0) {
    (**(code **)(this + 0xc0))(this + 0xb0,this + 0xb0,3);
  }
  if (*(code **)(this + 0xa0) != (code *)0x0) {
    (**(code **)(this + 0xa0))(this + 0x90,this + 0x90,3);
  }
  if (*(code **)(this + 0x78) != (code *)0x0) {
    (**(code **)(this + 0x78))(this + 0x68,this + 0x68,3);
  }
  puVar3 = *(undefined8 **)(this + 0x60);
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete((void *)*puVar3);
    }
    operator_delete(puVar3);
  }
  puVar4 = PTR__S_empty_rep_storage_00324fa0;
  lVar2 = *(long *)(this + 0x50);
  *(undefined8 *)(this + 0x60) = 0;
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar4) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar5 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  lVar2 = *(long *)(this + 0x48);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar4) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar5 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  std::
  _Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
  ::_M_erase((_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
              *)(this + 8),*(_Rb_tree_node **)(this + 0x18));
  return;
}



