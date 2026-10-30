
/* UnixServer::~UnixServer() */

void __thiscall UnixServer::~UnixServer(UnixServer *this)

{
  int *piVar1;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *p_Var2;
  long lVar3;
  int iVar4;
  int local_38 [6];
  
  *(undefined **)this = PTR_vtable_00324ec8 + 0x10;
  local_38[0] = *(int *)(this + 0xb8);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
           *)(this + 8),local_38);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
           *)(this + 0x38),local_38);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
           *)(this + 0x68),local_38);
  remove(*(char **)(this + 0xf0));
  close(*(int *)(this + 0xb8));
  lVar3 = *(long *)(this + 0xf0);
  if ((allocator *)(lVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar3 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(lVar3 + -8);
      *(int *)(lVar3 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(lVar3 + -0x18));
    }
  }
  p_Var2 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(this + 0x98);
  std::
  _Rb_tree<int,std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>,std::_Select1st<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>,std::less<int>,std::allocator<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>>
  ::_M_erase((_Rb_tree<int,std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>,std::_Select1st<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>,std::less<int>,std::allocator<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>>
              *)(this + 0xc0),*(_Rb_tree_node **)(this + 0xd0));
  if (*(code **)(this + 0xa8) != (code *)0x0) {
    (**(code **)(this + 0xa8))(p_Var2,p_Var2,3);
  }
  *(undefined **)this = PTR_vtable_00324fb8 + 0x10;
  while ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
          *)(this + 0x38) != p_Var2) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::_M_erase(p_Var2 + -0x30,*(_Rb_tree_node **)(p_Var2 + -0x20));
    p_Var2 = p_Var2 + -0x30;
  }
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::_M_erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(this + 8),*(_Rb_tree_node **)(this + 0x18));
  return;
}



