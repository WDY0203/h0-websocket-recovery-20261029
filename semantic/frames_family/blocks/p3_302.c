
/* UnixServer::UnixServer(int, std::function<void (TcpConn*)>) */

void __thiscall UnixServer::UnixServer(UnixServer *this,int param_1,long param_3)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  bool bVar10;
  uint uVar11;
  undefined1 auVar12 [16];
  int local_48 [6];
  
  p_Var1 = (_Rb_tree_node_base *)(this + 0x10);
  this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
             *)(this + 0x38);
  *(UnixServer **)(this + 0x50) = this + 0x40;
  *(UnixServer **)(this + 0x58) = this + 0x40;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(_Rb_tree_node_base **)(this + 0x20) = p_Var1;
  *(UnixServer **)(this + 0x80) = this + 0x70;
  *(UnixServer **)(this + 0x88) = this + 0x70;
  puVar5 = PTR_vtable_00324ec8;
  *(_Rb_tree_node_base **)(this + 0x28) = p_Var1;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined **)this = puVar5 + 0x10;
  *(undefined8 *)(this + 0xa8) = 0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(this + 0x98,param_3,2);
    *(undefined8 *)(this + 0xb0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this + 0xa8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(int *)(this + 0xb8) = param_1;
  *(undefined4 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(UnixServer **)(this + 0xd8) = this + 200;
  *(UnixServer **)(this + 0xe0) = this + 200;
  std::string::string((string *)(this + 0xf0),"",(allocator *)local_48);
  setcloexec(param_1);
  p_Var6 = *(_Rb_tree_node_base **)(this + 0x18);
  p_Var9 = p_Var6;
  p_Var7 = p_Var1;
  local_48[0] = param_1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011e908:
    uVar11 = 0;
  }
  else {
    do {
      while (p_Var8 = p_Var9, param_1 <= *(int *)(p_Var8 + 0x20)) {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0011e613;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var9 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011e613:
    if ((p_Var1 == p_Var8) || (param_1 < *(int *)(p_Var8 + 0x20))) goto LAB_0011e908;
    iVar3 = *(int *)(p_Var6 + 0x20);
    p_Var9 = p_Var1;
    while( true ) {
      if (iVar3 < param_1) {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var9 = p_Var6;
      }
      p_Var6 = p_Var7;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) break;
      iVar3 = *(int *)(p_Var6 + 0x20);
    }
    if ((p_Var1 == p_Var9) || (param_1 < *(int *)(p_Var9 + 0x20))) {
      p_Var6 = operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_48[0];
      }
      auVar12 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(this + 8),p_Var9,p_Var6 + 0x20);
      p_Var7 = auVar12._8_8_;
      p_Var9 = auVar12._0_8_;
      if (p_Var7 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var9 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
        *(long *)(this + 0x30) = *(long *)(this + 0x30) + 1;
        p_Var9 = p_Var6;
      }
    }
    uVar11 = *(uint *)(p_Var9 + 0x24);
    this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
               *)(this + 0x68);
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(this_00 + 8);
  p_Var9 = p_Var6;
  p_Var7 = p_Var1;
  uVar4 = uVar11;
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var8 = p_Var9, local_48[0] <= *(int *)(p_Var8 + 0x20)) {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0011e6a2;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var9 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011e6a2:
    if ((p_Var1 != p_Var8) && (p_Var9 = p_Var1, *(int *)(p_Var8 + 0x20) <= local_48[0])) {
      do {
        while (p_Var7 = p_Var6, local_48[0] <= *(int *)(p_Var7 + 0x20)) {
          p_Var6 = *(_Rb_tree_node_base **)(p_Var7 + 0x10);
          p_Var9 = p_Var7;
          if (*(_Rb_tree_node_base **)(p_Var7 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011e6da;
        }
        p_Var8 = p_Var7 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var8;
        p_Var7 = p_Var9;
      } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_0011e6da:
      if ((p_Var1 == p_Var7) || (local_48[0] < *(int *)(p_Var7 + 0x20))) {
        p_Var6 = operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_48[0];
        }
        auVar12 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(this_00,p_Var7,p_Var6 + 0x20);
        p_Var9 = auVar12._8_8_;
        p_Var7 = auVar12._0_8_;
        if (p_Var9 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var7 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var9)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var9 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var9,p_Var1);
          *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
          p_Var7 = p_Var6;
        }
      }
      uVar4 = *(uint *)(p_Var7 + 0x24);
    }
  }
  if ((uVar4 | 1) == uVar11) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(this_00,local_48);
    return;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var7 = p_Var1;
  p_Var9 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_00 + 0x10) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var9 = p_Var6, local_48[0] <= *(int *)(p_Var9 + 0x20)) {
        p_Var6 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
        p_Var7 = p_Var9;
        if (*(_Rb_tree_node_base **)(p_Var9 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0011e732;
      }
      p_Var8 = p_Var9 + 0x18;
      p_Var6 = *(_Rb_tree_node_base **)p_Var8;
      p_Var9 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_0011e732:
    if ((p_Var1 != p_Var9) && (*(int *)(p_Var9 + 0x20) <= local_48[0])) goto LAB_0011e7b8;
  }
  p_Var6 = operator_new(0x28);
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var6 = 0;
    *(undefined8 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined4 *)(p_Var6 + 0x24) = 0;
    *(int *)(p_Var6 + 0x20) = local_48[0];
  }
  auVar12 = std::
            _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            ::_M_get_insert_hint_unique_pos(this_00,p_Var9,p_Var6 + 0x20);
  p_Var7 = auVar12._8_8_;
  p_Var9 = auVar12._0_8_;
  if (p_Var7 == (_Rb_tree_node_base *)0x0) {
    operator_delete(p_Var6);
  }
  else {
    bVar10 = true;
    if ((p_Var9 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
      bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
    }
    std::_Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var7,p_Var1);
    *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
    p_Var9 = p_Var6;
  }
LAB_0011e7b8:
  *(uint *)(p_Var9 + 0x24) = uVar4 | 1;
  return;
}



