
/* TcpServer::idle() */

undefined8 __thiscall TcpServer::idle(TcpServer *this)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  void *pvVar3;
  _Rb_tree_node_base *p_Var4;
  
  p_Var1 = (_Rb_tree_node_base *)(this + 200);
  p_Var4 = *(_Rb_tree_node_base **)(this + 0xd8);
  do {
    if (p_Var4 == p_Var1) {
      return 0;
    }
    while( true ) {
      TcpConn::idle_proc(*(TcpConn **)(p_Var4 + 0x28));
      if ((*(char *)(*(long *)(p_Var4 + 0x28) + 0x58) != '\0') ||
         (*(char *)(*(long *)(p_Var4 + 0x28) + 0x59) != '\0')) break;
      p_Var2 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var4);
      pvVar3 = (void *)std::_Rb_tree_rebalance_for_erase(p_Var4,p_Var1);
      if (*(long **)((long)pvVar3 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)((long)pvVar3 + 0x28) + 8))();
      }
      *(undefined8 *)((long)pvVar3 + 0x28) = 0;
      operator_delete(pvVar3);
      *(long *)(this + 0xe8) = *(long *)(this + 0xe8) + -1;
      p_Var4 = p_Var2;
      if (p_Var2 == p_Var1) {
        return 0;
      }
    }
    p_Var4 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var4);
  } while( true );
}



