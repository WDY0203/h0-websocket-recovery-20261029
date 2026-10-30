
/* TcpServer::TcpServer(std::string const&, int, std::function<void (TcpConn*)>) */

void __thiscall
TcpServer::TcpServer(TcpServer *this,undefined8 *param_1,ushort param_3,long param_4)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  _Rb_tree_node_base *p_Var6;
  _Rb_tree_node_base *p_Var7;
  _Rb_tree_node_base *p_Var8;
  bool bVar9;
  _Rb_tree_node_base *p_Var10;
  TcpServer *this_00;
  uint uVar11;
  undefined1 auVar12 [16];
  undefined4 local_68 [4];
  int local_58 [4];
  sockaddr local_48;
  
  this_00 = this + 0x38;
  p_Var1 = (_Rb_tree_node_base *)(this + 0x10);
  *(TcpServer **)(this + 0x50) = this + 0x40;
  *(TcpServer **)(this + 0x58) = this + 0x40;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(_Rb_tree_node_base **)(this + 0x20) = p_Var1;
  *(TcpServer **)(this + 0x80) = this + 0x70;
  *(TcpServer **)(this + 0x88) = this + 0x70;
  puVar4 = PTR_vtable_00324f48;
  *(_Rb_tree_node_base **)(this + 0x28) = p_Var1;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined **)this = puVar4 + 0x10;
  *(undefined8 *)(this + 0xa8) = 0;
  if (*(code **)(param_4 + 0x10) != (code *)0x0) {
    (**(code **)(param_4 + 0x10))(this + 0x98,param_4,2);
    *(undefined8 *)(this + 0xb0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this + 0xa8) = *(undefined8 *)(param_4 + 0x10);
  }
  *(undefined4 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(TcpServer **)(this + 0xd8) = this + 200;
  *(TcpServer **)(this + 0xe0) = this + 200;
  *(undefined8 *)(this + 0xe8) = 0;
  bzero(&local_48,0x10);
  local_48.sa_family = 2;
  local_48.sa_data._2_4_ = inet_addr((char *)*param_1);
  local_48.sa_data._0_2_ = param_3 >> 8 | param_3 << 8;
  iVar5 = socket(2,1,0);
  *(int *)(this + 0xb8) = iVar5;
  if (iVar5 < 0) {
    perror("socket");
LAB_001192f4:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  setcloexec(iVar5);
  local_68[0] = 1;
  setsockopt(*(int *)(this + 0xb8),1,2,local_68,4);
  iVar5 = bind(*(int *)(this + 0xb8),&local_48,0x10);
  if (iVar5 < 0) {
    perror("bind");
    goto LAB_001192f4;
  }
  iVar5 = listen(*(int *)(this + 0xb8),0x1ff);
  if (iVar5 < 0) {
    perror("listen");
    goto LAB_001192f4;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this + 0x18);
  local_58[0] = *(int *)(this + 0xb8);
  p_Var10 = p_Var6;
  p_Var7 = p_Var1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_00119238:
    uVar11 = 0;
  }
  else {
    do {
      while (p_Var8 = p_Var10, local_58[0] <= *(int *)(p_Var8 + 0x20)) {
        p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_00118f4a;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var10 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_00118f4a:
    if ((p_Var1 == p_Var8) || (local_58[0] < *(int *)(p_Var8 + 0x20))) goto LAB_00119238;
    iVar5 = *(int *)(p_Var6 + 0x20);
    p_Var10 = p_Var1;
    while( true ) {
      if (iVar5 < local_58[0]) {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var7 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var10 = p_Var6;
      }
      p_Var6 = p_Var7;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) break;
      iVar5 = *(int *)(p_Var6 + 0x20);
    }
    if ((p_Var1 == p_Var10) || (local_58[0] < *(int *)(p_Var10 + 0x20))) {
      p_Var6 = operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_58[0];
      }
      auVar12 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(this + 8),p_Var10,p_Var6 + 0x20);
      p_Var7 = auVar12._8_8_;
      p_Var10 = auVar12._0_8_;
      if (p_Var7 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var6);
      }
      else {
        bVar9 = true;
        if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
          bVar9 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar9,p_Var6,p_Var7,p_Var1);
        *(long *)(this + 0x30) = *(long *)(this + 0x30) + 1;
        p_Var10 = p_Var6;
      }
    }
    uVar11 = *(uint *)(p_Var10 + 0x24);
    this_00 = this + 0x68;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(this_00 + 8);
  p_Var10 = p_Var6;
  p_Var7 = p_Var1;
  uVar3 = uVar11;
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var8 = p_Var10, local_58[0] <= *(int *)(p_Var8 + 0x20)) {
        p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var7 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_00118fda;
      }
      p_Var2 = p_Var8 + 0x18;
      p_Var10 = *(_Rb_tree_node_base **)p_Var2;
      p_Var8 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_00118fda:
    if ((p_Var1 != p_Var8) && (p_Var10 = p_Var1, *(int *)(p_Var8 + 0x20) <= local_58[0])) {
      do {
        while (p_Var7 = p_Var6, local_58[0] <= *(int *)(p_Var7 + 0x20)) {
          p_Var6 = *(_Rb_tree_node_base **)(p_Var7 + 0x10);
          p_Var10 = p_Var7;
          if (*(_Rb_tree_node_base **)(p_Var7 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011900a;
        }
        p_Var8 = p_Var7 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var8;
        p_Var7 = p_Var10;
      } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_0011900a:
      if ((p_Var1 == p_Var7) || (local_58[0] < *(int *)(p_Var7 + 0x20))) {
        p_Var6 = operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_58[0];
        }
        auVar12 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos
                            ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                              *)this_00,p_Var7,p_Var6 + 0x20);
        p_Var10 = auVar12._8_8_;
        p_Var7 = auVar12._0_8_;
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var6);
        }
        else {
          bVar9 = true;
          if ((p_Var7 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var10)) {
            bVar9 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar9,p_Var6,p_Var10,p_Var1);
          *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
          p_Var7 = p_Var6;
        }
      }
      uVar3 = *(uint *)(p_Var7 + 0x24);
    }
  }
  if ((uVar3 | 1) == uVar11) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
             *)this_00,local_58);
    return;
  }
  p_Var6 = *(_Rb_tree_node_base **)(this_00 + 0x10);
  p_Var7 = p_Var1;
  p_Var10 = p_Var1;
  if (*(_Rb_tree_node_base **)(this_00 + 0x10) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var10 = p_Var6, local_58[0] <= *(int *)(p_Var10 + 0x20)) {
        p_Var6 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
        p_Var7 = p_Var10;
        if (*(_Rb_tree_node_base **)(p_Var10 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00119062;
      }
      p_Var8 = p_Var10 + 0x18;
      p_Var6 = *(_Rb_tree_node_base **)p_Var8;
      p_Var10 = p_Var7;
    } while (*(_Rb_tree_node_base **)p_Var8 != (_Rb_tree_node_base *)0x0);
LAB_00119062:
    if ((p_Var1 != p_Var10) && (*(int *)(p_Var10 + 0x20) <= local_58[0])) goto LAB_001190e9;
  }
  p_Var6 = operator_new(0x28);
  if (p_Var6 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var6 = 0;
    *(undefined8 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined4 *)(p_Var6 + 0x24) = 0;
    *(int *)(p_Var6 + 0x20) = local_58[0];
  }
  auVar12 = std::
            _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            ::_M_get_insert_hint_unique_pos
                      ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                        *)this_00,p_Var10,p_Var6 + 0x20);
  p_Var7 = auVar12._8_8_;
  p_Var10 = auVar12._0_8_;
  if (p_Var7 == (_Rb_tree_node_base *)0x0) {
    operator_delete(p_Var6);
  }
  else {
    bVar9 = true;
    if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var7)) {
      bVar9 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var7 + 0x20);
    }
    std::_Rb_tree_insert_and_rebalance(bVar9,p_Var6,p_Var7,p_Var1);
    *(long *)(this_00 + 0x28) = *(long *)(this_00 + 0x28) + 1;
    p_Var10 = p_Var6;
  }
LAB_001190e9:
  *(uint *)(p_Var10 + 0x24) = uVar3 | 1;
  return;
}



