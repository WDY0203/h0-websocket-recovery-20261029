
/* TcpClient::TcpClient(std::string const&, int, std::function<void (TcpConn*)>, std::function<void
   (int)>) */

void __thiscall
TcpClient::TcpClient(TcpClient *this,string *param_1,undefined4 param_2,long param_4,long param_5)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  long lVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long *plVar9;
  TcpConn *this_00;
  int *piVar10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  ulong uVar14;
  bool bVar15;
  uint uVar16;
  _Rb_tree_node_base *p_Var17;
  undefined1 auVar18 [16];
  ushort local_b0;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *local_a8;
  int local_88 [4];
  long local_78 [2];
  ulong local_68 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  sockaddr local_48;
  
  local_a8 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(this + 0x38);
  p_Var1 = (_Rb_tree_node_base *)(this + 0x10);
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(_Rb_tree_node_base **)(this + 0x20) = p_Var1;
  *(_Rb_tree_node_base **)(this + 0x28) = p_Var1;
  *(TcpClient **)(this + 0x50) = this + 0x40;
  *(TcpClient **)(this + 0x58) = this + 0x40;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(TcpClient **)(this + 0x80) = this + 0x70;
  *(TcpClient **)(this + 0x88) = this + 0x70;
  puVar5 = PTR_vtable_00324f98;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined8 *)(this + 0xa0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined **)this = puVar5 + 0x10;
  if (*(code **)(param_4 + 0x10) != (code *)0x0) {
    (**(code **)(param_4 + 0x10))(this + 0xa8,param_4,2);
    *(undefined8 *)(this + 0xc0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this + 0xb8) = *(undefined8 *)(param_4 + 0x10);
  }
  *(undefined8 *)(this + 0xd8) = 0;
  if (*(code **)(param_5 + 0x10) != (code *)0x0) {
    (**(code **)(param_5 + 0x10))(this + 200,param_5,2);
    *(undefined8 *)(this + 0xe0) = *(undefined8 *)(param_5 + 0x18);
    *(undefined8 *)(this + 0xd8) = *(undefined8 *)(param_5 + 0x10);
  }
  bzero(&local_48,0x10);
  local_48.sa_family = 2;
  local_48.sa_data._2_4_ = inet_addr(*(char **)param_1);
  local_b0 = (ushort)param_2;
  local_48.sa_data._0_2_ = local_b0 >> 8 | local_b0 << 8;
  iVar6 = socket(2,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)(this + 0x98) = 2;
    perror("socket");
    piVar10 = __errno_location();
    iVar8 = *piVar10;
    if (*(long *)(param_5 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
LAB_0011a9a1:
    (**(code **)(param_5 + 0x18))(param_5,iVar8);
    return;
  }
  setcloexec(iVar6);
  setnonblock(iVar6);
  local_58 = 1;
  setsockopt(iVar6,6,1,&local_58,4);
  iVar7 = connect(iVar6,&local_48,0x10);
  if (iVar7 < 0) {
    piVar10 = __errno_location();
    iVar8 = *piVar10;
    if (iVar8 != 0x73) {
      *(undefined4 *)(this + 0x98) = 2;
      perror("connect");
      close(iVar6);
      if (*(long *)(param_5 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_function_call();
      }
      goto LAB_0011a9a1;
    }
  }
  __gnu_cxx::__to_xstring<std::string,char>
            ((_func_int_char_ptr_ulong_char_ptr___va_list_tag_ptr *)&local_58,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,&DAT_0011fe68,param_2);
  std::string::string((string *)local_68,param_1);
  std::string::append((char *)local_68,0x11fdf2);
  uVar14 = *(long *)(local_68[0] - 0x18) + *(long *)(CONCAT44(uStack_54,local_58) + -0x18);
  if ((*(ulong *)(local_68[0] - 0x10) < uVar14) &&
     (uVar14 <= *(ulong *)(CONCAT44(uStack_54,local_58) + -0x10))) {
    plVar9 = (long *)std::string::insert((ulong)&local_58,(char *)0x0,local_68[0]);
  }
  else {
    plVar9 = (long *)std::string::append((string *)local_68);
  }
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  local_78[0] = *plVar9;
  *plVar9 = (long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_68[0] - 0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(local_68[0] - 8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_68[0] - 8);
      *(int *)(local_68[0] - 8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_68[0] - 0x18));
    }
  }
  lVar3 = CONCAT44(uStack_54,local_58);
  if ((allocator *)(lVar3 + -0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(lVar3 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(lVar3 + -8);
      *(int *)(lVar3 + -8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(lVar3 + -0x18));
    }
  }
  this_00 = operator_new(0xd0);
  TcpConn::TcpConn(this_00,iVar6,param_1,(string *)local_78,(EventHandler *)this);
  plVar9 = *(long **)(this + 0xa0);
  *(TcpConn **)(this + 0xa0) = this_00;
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 8))();
  }
  if (iVar7 == 0) {
    *(undefined4 *)(this + 0x98) = 1;
    if (*(long *)(param_4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (**(code **)(param_4 + 0x18))(param_4,*(undefined8 *)(this + 0xa0));
    goto LAB_0011a6a3;
  }
  p_Var11 = *(_Rb_tree_node_base **)(this + 0x18);
  p_Var17 = p_Var11;
  p_Var12 = p_Var1;
  local_88[0] = iVar6;
  if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_0011a783:
    uVar16 = 0;
  }
  else {
    do {
      while (p_Var13 = p_Var17, iVar6 <= *(int *)(p_Var13 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a772;
      }
      p_Var2 = p_Var13 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011a772:
    if ((p_Var1 == p_Var13) || (p_Var17 = p_Var1, iVar6 < *(int *)(p_Var13 + 0x20)))
    goto LAB_0011a783;
    do {
      while (p_Var12 = p_Var11, iVar6 <= *(int *)(p_Var12 + 0x20)) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
        p_Var17 = p_Var12;
        if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a9ca;
      }
      p_Var13 = p_Var12 + 0x18;
      p_Var11 = *(_Rb_tree_node_base **)p_Var13;
      p_Var12 = p_Var17;
    } while (*(_Rb_tree_node_base **)p_Var13 != (_Rb_tree_node_base *)0x0);
LAB_0011a9ca:
    if ((p_Var1 == p_Var12) || (iVar6 < *(int *)(p_Var12 + 0x20))) {
      p_Var11 = operator_new(0x28);
      if (p_Var11 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var11 = 0;
        *(undefined8 *)(p_Var11 + 8) = 0;
        *(undefined8 *)(p_Var11 + 0x10) = 0;
        *(undefined8 *)(p_Var11 + 0x18) = 0;
        *(undefined4 *)(p_Var11 + 0x24) = 0;
        *(int *)(p_Var11 + 0x20) = local_88[0];
      }
      auVar18 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(this + 8),p_Var12,p_Var11 + 0x20);
      p_Var17 = auVar18._8_8_;
      p_Var12 = auVar18._0_8_;
      if (p_Var17 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var11);
      }
      else {
        bVar15 = true;
        if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var17)) {
          bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var17 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var17,p_Var1);
        *(long *)(this + 0x30) = *(long *)(this + 0x30) + 1;
        p_Var12 = p_Var11;
      }
    }
    local_a8 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                *)(this + 0x68);
    uVar16 = *(uint *)(p_Var12 + 0x24);
  }
  p_Var11 = *(_Rb_tree_node_base **)(local_a8 + 0x10);
  p_Var1 = (_Rb_tree_node_base *)(local_a8 + 8);
  p_Var17 = p_Var11;
  p_Var12 = p_Var1;
  uVar4 = uVar16;
  if (p_Var11 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var13 = p_Var17, local_88[0] <= *(int *)(p_Var13 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a7ca;
      }
      p_Var2 = p_Var13 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0011a7ca:
    if ((p_Var1 != p_Var13) && (p_Var17 = p_Var1, *(int *)(p_Var13 + 0x20) <= local_88[0])) {
      do {
        while (p_Var12 = p_Var11, local_88[0] <= *(int *)(p_Var12 + 0x20)) {
          p_Var11 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var17 = p_Var12;
          if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011a7fa;
        }
        p_Var13 = p_Var12 + 0x18;
        p_Var11 = *(_Rb_tree_node_base **)p_Var13;
        p_Var12 = p_Var17;
      } while (*(_Rb_tree_node_base **)p_Var13 != (_Rb_tree_node_base *)0x0);
LAB_0011a7fa:
      if ((p_Var1 == p_Var12) || (local_88[0] < *(int *)(p_Var12 + 0x20))) {
        p_Var11 = operator_new(0x28);
        if (p_Var11 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_88[0];
        }
        auVar18 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(local_a8,p_Var12,p_Var11 + 0x20);
        p_Var17 = auVar18._8_8_;
        p_Var12 = auVar18._0_8_;
        if (p_Var17 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var11);
        }
        else {
          bVar15 = true;
          if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var17)) {
            bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var17 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var17,p_Var1);
          *(long *)(local_a8 + 0x28) = *(long *)(local_a8 + 0x28) + 1;
          p_Var12 = p_Var11;
        }
      }
      uVar4 = *(uint *)(p_Var12 + 0x24);
    }
  }
  if ((uVar4 | 2) == uVar16) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(local_a8,local_88);
    goto LAB_0011a6a3;
  }
  p_Var11 = *(_Rb_tree_node_base **)(local_a8 + 0x10);
  p_Var12 = p_Var1;
  p_Var17 = p_Var1;
  if (*(_Rb_tree_node_base **)(local_a8 + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0011a8e9:
    p_Var11 = operator_new(0x28);
    if (p_Var11 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var11 = 0;
      *(undefined8 *)(p_Var11 + 8) = 0;
      *(undefined8 *)(p_Var11 + 0x10) = 0;
      *(undefined8 *)(p_Var11 + 0x18) = 0;
      *(undefined4 *)(p_Var11 + 0x24) = 0;
      *(int *)(p_Var11 + 0x20) = local_88[0];
    }
    auVar18 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(local_a8,p_Var17,p_Var11 + 0x20);
    p_Var12 = auVar18._8_8_;
    p_Var17 = auVar18._0_8_;
    if (p_Var12 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var11);
    }
    else {
      bVar15 = true;
      if ((p_Var17 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var12)) {
        bVar15 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var12 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar15,p_Var11,p_Var12,p_Var1);
      *(long *)(local_a8 + 0x28) = *(long *)(local_a8 + 0x28) + 1;
      p_Var17 = p_Var11;
    }
  }
  else {
    do {
      while (p_Var17 = p_Var11, local_88[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var12 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011a8da;
      }
      p_Var13 = p_Var17 + 0x18;
      p_Var11 = *(_Rb_tree_node_base **)p_Var13;
      p_Var17 = p_Var12;
    } while (*(_Rb_tree_node_base **)p_Var13 != (_Rb_tree_node_base *)0x0);
LAB_0011a8da:
    if ((p_Var1 == p_Var17) || (local_88[0] < *(int *)(p_Var17 + 0x20))) goto LAB_0011a8e9;
  }
  *(uint *)(p_Var17 + 0x24) = uVar4 | 2;
LAB_0011a6a3:
  if ((allocator *)(local_78[0] + -0x18) != (allocator *)puVar5) {
    piVar10 = (int *)(local_78[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar6 = *(int *)(local_78[0] + -8);
      *(int *)(local_78[0] + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar10;
      *piVar10 = *piVar10 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_78[0] + -0x18));
    }
  }
  return;
}



