
/* UnixServer::iter(std::function<void (int, TcpConn*)>) */

void __thiscall UnixServer::iter(UnixServer *this,long param_2)

{
  _Rb_tree_node_base *p_Var1;
  
  p_Var1 = *(_Rb_tree_node_base **)(this + 0xd8);
  while( true ) {
    if (p_Var1 == (_Rb_tree_node_base *)(this + 200)) {
      return;
    }
    if (*(long *)(param_2 + 0x10) == 0) break;
    (**(code **)(param_2 + 0x18))
              (param_2,*(undefined4 *)(p_Var1 + 0x20),*(undefined8 *)(p_Var1 + 0x28));
    p_Var1 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var1);
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_function_call();
}



