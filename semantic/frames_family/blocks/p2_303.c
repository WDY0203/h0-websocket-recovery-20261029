
/* UnixClient::poll(int, int) */

byte __thiscall UnixClient::poll(UnixClient *this,int param_1,int param_2)

{
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *p_Var1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  long lVar7;
  _Rb_tree_node_base *p_Var8;
  _Rb_tree_node_base *p_Var9;
  bool bVar10;
  TcpConn *this_00;
  _Rb_tree_node_base *p_Var11;
  uint uVar12;
  undefined1 auVar13 [16];
  int local_78 [4];
  socklen_t local_68 [4];
  int local_58 [4];
  int local_48 [6];
  
  if (*(int *)(this + 0x98) == 1) {
    this_00 = *(TcpConn **)(this + 0xa0);
    if (*(int *)(this_00 + 0x40) == param_1) {
      if ((param_2 & 2U) != 0) {
        TcpConn::send_proc(this_00);
        this_00 = *(TcpConn **)(this + 0xa0);
      }
      if ((param_2 & 1U) != 0) {
        TcpConn::recv_proc(this_00);
        this_00 = *(TcpConn **)(this + 0xa0);
      }
    }
    if (this_00[0x58] != (TcpConn)0x0) {
      return 0;
    }
    return (byte)this_00[0x59] ^ 1;
  }
  if (*(int *)(this + 0x98) == 2) {
    return 1;
  }
  if (param_1 != *(int *)(*(long *)(this + 0xa0) + 0x40)) {
    return 0;
  }
  if ((param_2 & 2U) == 0) {
    return 0;
  }
  local_68[0] = 4;
  getsockopt(param_1,1,4,local_78,local_68);
  iVar2 = local_78[0];
  if (local_78[0] == 0) {
    p_Var6 = *(_Rb_tree_node_base **)(this + 0x18);
    *(undefined4 *)(this + 0x98) = 1;
    p_Var9 = (_Rb_tree_node_base *)(this + 0x10);
    p_Var5 = p_Var6;
    p_Var11 = p_Var9;
    local_48[0] = param_1;
    if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011f0bd:
      lVar7 = 0;
      uVar12 = 0;
    }
    else {
      do {
        if (*(int *)(p_Var5 + 0x20) < param_1) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
          p_Var11 = p_Var5;
        }
        p_Var5 = p_Var8;
      } while (p_Var8 != (_Rb_tree_node_base *)0x0);
      if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
      goto LAB_0011f0bd;
      do {
        if (*(int *)(p_Var6 + 0x20) < param_1) {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var11;
      } while (p_Var11 != (_Rb_tree_node_base *)0x0);
      if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
        p_Var6 = operator_new(0x28);
        if (p_Var6 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var6 = 0;
          *(undefined8 *)(p_Var6 + 8) = 0;
          *(undefined8 *)(p_Var6 + 0x10) = 0;
          *(undefined8 *)(p_Var6 + 0x18) = 0;
          *(undefined4 *)(p_Var6 + 0x24) = 0;
          *(int *)(p_Var6 + 0x20) = local_48[0];
        }
        auVar13 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos
                            ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                              *)(this + 8),p_Var5,p_Var6 + 0x20);
        p_Var11 = auVar13._8_8_;
        p_Var5 = auVar13._0_8_;
        if (p_Var11 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var6);
        }
        else {
          bVar10 = true;
          if ((p_Var5 == (_Rb_tree_node_base *)0x0) && (p_Var9 != p_Var11)) {
            bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
          *(long *)(this + 0x30) = *(long *)(this + 0x30) + 1;
          p_Var5 = p_Var6;
        }
      }
      uVar12 = *(uint *)(p_Var5 + 0x24);
      lVar7 = 1;
    }
    lVar7 = lVar7 + 1;
    p_Var1 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(this + lVar7 * 0x30 + 8);
    p_Var9 = *(_Rb_tree_node_base **)(this + lVar7 * 0x30 + 0x18);
    p_Var11 = (_Rb_tree_node_base *)(this + lVar7 * 0x30 + 0x10);
    p_Var6 = p_Var9;
    p_Var5 = p_Var11;
    uVar3 = uVar12;
    if (p_Var9 != (_Rb_tree_node_base *)0x0) {
      do {
        if (*(int *)(p_Var6 + 0x20) < local_48[0]) {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
        }
        else {
          p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
          p_Var5 = p_Var6;
        }
        p_Var6 = p_Var8;
      } while (p_Var8 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_48[0])) {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != (_Rb_tree_node_base *)0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) {
          p_Var9 = operator_new(0x28);
          if (p_Var9 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var9 = 0;
            *(undefined8 *)(p_Var9 + 8) = 0;
            *(undefined8 *)(p_Var9 + 0x10) = 0;
            *(undefined8 *)(p_Var9 + 0x18) = 0;
            *(undefined4 *)(p_Var9 + 0x24) = 0;
            *(int *)(p_Var9 + 0x20) = local_48[0];
          }
          auVar13 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20);
          p_Var5 = auVar13._8_8_;
          p_Var6 = auVar13._0_8_;
          if (p_Var5 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var9);
          }
          else {
            bVar10 = true;
            if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
              bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
            *(long *)(this + lVar7 * 0x30 + 0x30) = *(long *)(this + lVar7 * 0x30 + 0x30) + 1;
            p_Var6 = p_Var9;
          }
        }
        uVar3 = *(uint *)(p_Var6 + 0x24);
      }
    }
    if ((uVar3 & 0xfffffffd) == uVar12) {
      std::
      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
      ::erase(p_Var1,local_48);
    }
    else {
      p_Var9 = *(_Rb_tree_node_base **)(this + lVar7 * 0x30 + 0x18);
      p_Var6 = p_Var11;
      if (p_Var9 == (_Rb_tree_node_base *)0x0) {
LAB_0011f018:
        p_Var9 = operator_new(0x28);
        if (p_Var9 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_48[0];
        }
        auVar13 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20);
        p_Var5 = auVar13._8_8_;
        p_Var6 = auVar13._0_8_;
        if (p_Var5 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long *)(this + lVar7 * 0x30 + 0x30) = *(long *)(this + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      else {
        do {
          if (*(int *)(p_Var9 + 0x20) < local_48[0]) {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
          }
          else {
            p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
            p_Var6 = p_Var9;
          }
          p_Var9 = p_Var5;
        } while (p_Var5 != (_Rb_tree_node_base *)0x0);
        if ((p_Var11 == p_Var6) || (local_48[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011f018;
      }
      *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
    }
    if (*(long *)(this + 0xb8) != 0) {
      (**(code **)(this + 0xc0))(this + 0xa8,*(undefined8 *)(this + 0xa0));
      return 0;
    }
    goto LAB_0011f251;
  }
  *(undefined4 *)(this + 0x98) = 2;
  p_Var9 = (_Rb_tree_node_base *)(this + 0x10);
  piVar4 = __errno_location();
  *piVar4 = iVar2;
  perror("connect");
  p_Var6 = *(_Rb_tree_node_base **)(this + 0x18);
  p_Var5 = p_Var6;
  p_Var11 = p_Var9;
  local_58[0] = param_1;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011f0c7:
    lVar7 = 0;
    uVar12 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var5 + 0x20) < param_1) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var5 + 0x10);
        p_Var11 = p_Var5;
      }
      p_Var5 = p_Var8;
    } while (p_Var8 != (_Rb_tree_node_base *)0x0);
    if ((p_Var9 == p_Var11) || (p_Var5 = p_Var9, param_1 < *(int *)(p_Var11 + 0x20)))
    goto LAB_0011f0c7;
    do {
      if (*(int *)(p_Var6 + 0x20) < param_1) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var11;
    } while (p_Var11 != (_Rb_tree_node_base *)0x0);
    if ((p_Var9 == p_Var5) || (param_1 < *(int *)(p_Var5 + 0x20))) {
      p_Var6 = operator_new(0x28);
      if (p_Var6 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var6 = 0;
        *(undefined8 *)(p_Var6 + 8) = 0;
        *(undefined8 *)(p_Var6 + 0x10) = 0;
        *(undefined8 *)(p_Var6 + 0x18) = 0;
        *(undefined4 *)(p_Var6 + 0x24) = 0;
        *(int *)(p_Var6 + 0x20) = local_58[0];
      }
      auVar13 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(this + 8),p_Var5,p_Var6 + 0x20);
      p_Var11 = auVar13._8_8_;
      p_Var5 = auVar13._0_8_;
      if (p_Var11 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var6);
      }
      else {
        bVar10 = true;
        if ((p_Var5 == (_Rb_tree_node_base *)0x0) && (p_Var9 != p_Var11)) {
          bVar10 = *(int *)(p_Var6 + 0x20) < *(int *)(p_Var11 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar10,p_Var6,p_Var11,p_Var9);
        *(long *)(this + 0x30) = *(long *)(this + 0x30) + 1;
        p_Var5 = p_Var6;
      }
    }
    uVar12 = *(uint *)(p_Var5 + 0x24);
    lVar7 = 1;
  }
  lVar7 = lVar7 + 1;
  p_Var1 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(this + lVar7 * 0x30 + 8);
  p_Var9 = *(_Rb_tree_node_base **)(this + lVar7 * 0x30 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(this + lVar7 * 0x30 + 0x10);
  p_Var6 = p_Var9;
  p_Var5 = p_Var11;
  uVar3 = uVar12;
  if (p_Var9 != (_Rb_tree_node_base *)0x0) {
    do {
      if (*(int *)(p_Var6 + 0x20) < local_58[0]) {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
      else {
        p_Var8 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
        p_Var5 = p_Var6;
      }
      p_Var6 = p_Var8;
    } while (p_Var8 != (_Rb_tree_node_base *)0x0);
    if ((p_Var11 != p_Var5) && (p_Var6 = p_Var11, *(int *)(p_Var5 + 0x20) <= local_58[0])) {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) {
        p_Var9 = operator_new(0x28);
        if (p_Var9 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var9 = 0;
          *(undefined8 *)(p_Var9 + 8) = 0;
          *(undefined8 *)(p_Var9 + 0x10) = 0;
          *(undefined8 *)(p_Var9 + 0x18) = 0;
          *(undefined4 *)(p_Var9 + 0x24) = 0;
          *(int *)(p_Var9 + 0x20) = local_58[0];
        }
        auVar13 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20);
        p_Var5 = auVar13._8_8_;
        p_Var6 = auVar13._0_8_;
        if (p_Var5 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var9);
        }
        else {
          bVar10 = true;
          if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
            bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
          *(long *)(this + lVar7 * 0x30 + 0x30) = *(long *)(this + lVar7 * 0x30 + 0x30) + 1;
          p_Var6 = p_Var9;
        }
      }
      uVar3 = *(uint *)(p_Var6 + 0x24);
    }
  }
  if ((uVar3 & 0xfffffffd) == uVar12) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(p_Var1,local_58);
  }
  else {
    p_Var9 = *(_Rb_tree_node_base **)(this + lVar7 * 0x30 + 0x18);
    p_Var6 = p_Var11;
    if (p_Var9 == (_Rb_tree_node_base *)0x0) {
LAB_0011ef69:
      p_Var9 = operator_new(0x28);
      if (p_Var9 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var9 = 0;
        *(undefined8 *)(p_Var9 + 8) = 0;
        *(undefined8 *)(p_Var9 + 0x10) = 0;
        *(undefined8 *)(p_Var9 + 0x18) = 0;
        *(undefined4 *)(p_Var9 + 0x24) = 0;
        *(int *)(p_Var9 + 0x20) = local_58[0];
      }
      auVar13 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos(p_Var1,p_Var6,p_Var9 + 0x20);
      p_Var5 = auVar13._8_8_;
      p_Var6 = auVar13._0_8_;
      if (p_Var5 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var9);
      }
      else {
        bVar10 = true;
        if ((p_Var6 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var5)) {
          bVar10 = *(int *)(p_Var9 + 0x20) < *(int *)(p_Var5 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar10,p_Var9,p_Var5,p_Var11);
        *(long *)(this + lVar7 * 0x30 + 0x30) = *(long *)(this + lVar7 * 0x30 + 0x30) + 1;
        p_Var6 = p_Var9;
      }
    }
    else {
      do {
        if (*(int *)(p_Var9 + 0x20) < local_58[0]) {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x18);
        }
        else {
          p_Var5 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
          p_Var6 = p_Var9;
        }
        p_Var9 = p_Var5;
      } while (p_Var5 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var6) || (local_58[0] < *(int *)(p_Var6 + 0x20))) goto LAB_0011ef69;
    }
    *(uint *)(p_Var6 + 0x24) = uVar3 & 0xfffffffd;
  }
  if (*(long *)(this + 0xd8) != 0) {
    (**(code **)(this + 0xe0))(this + 200,local_78[0]);
    return 1;
  }
LAB_0011f251:
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_function_call();
}



