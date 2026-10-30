
/* TcpServer::~TcpServer() */

void __thiscall TcpServer::~TcpServer(TcpServer *this)

{
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *p_Var1;
  int local_38 [6];
  
  p_Var1 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(this + 0x98);
  *(undefined **)this = PTR_vtable_00324f48 + 0x10;
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
  close(*(int *)(this + 0xb8));
  std::
  _Rb_tree<int,std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>,std::_Select1st<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>,std::less<int>,std::allocator<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>>
  ::_M_erase((_Rb_tree<int,std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>,std::_Select1st<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>,std::less<int>,std::allocator<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>>
              *)(this + 0xc0),*(_Rb_tree_node **)(this + 0xd0));
  if (*(code **)(this + 0xa8) != (code *)0x0) {
    (**(code **)(this + 0xa8))(p_Var1,p_Var1,3);
  }
  *(undefined **)this = PTR_vtable_00324fb8 + 0x10;
  while ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
          *)(this + 0x38) != p_Var1) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::_M_erase(p_Var1 + -0x30,*(_Rb_tree_node **)(p_Var1 + -0x20));
    p_Var1 = p_Var1 + -0x30;
  }
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::_M_erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(this + 8),*(_Rb_tree_node **)(this + 0x18));
  return;
}



