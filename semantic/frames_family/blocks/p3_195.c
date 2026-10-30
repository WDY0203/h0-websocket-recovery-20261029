
/* WSConn::exit() */

void __thiscall WSConn::exit(WSConn *this)

{
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *p_Var1;
  _Rb_tree_node_base *p_Var2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 *puVar10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  undefined *puVar14;
  long lVar15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  bool bVar19;
  code *pcVar20;
  uint uVar21;
  uint uVar22;
  undefined1 auVar23 [16];
  int local_a8 [4];
  undefined8 *local_98 [2];
  code *local_88;
  undefined *puStack_80;
  void *local_78;
  undefined8 local_70;
  code *local_68;
  undefined *puStack_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  
  local_88 = (code *)0x0;
  local_98[0] = operator_new(8);
  lVar15 = *(long *)(this + 0x38);
  *local_98[0] = this;
  puStack_80 = PTR__M_invoke_00324f38;
  local_88 = (code *)PTR__M_manager_00324ec0;
  if (*(char *)(lVar15 + 0x88) != '\0') {
    fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  *(undefined1 *)(lVar15 + 0x88) = 1;
  local_68 = (code *)0x0;
  if (local_88 != (code *)0x0) {
    (*local_88)(&local_78,local_98,2);
    local_68 = local_88;
    puStack_60 = puStack_80;
  }
  local_48 = (code *)0x0;
  puVar10 = operator_new(0x20);
  pcVar20 = local_68;
  puVar10[2] = 0;
  pvVar5 = (void *)*puVar10;
  uVar6 = puVar10[1];
  *puVar10 = local_78;
  puVar10[1] = local_70;
  local_68 = (code *)0x0;
  uVar7 = puVar10[3];
  puVar10[2] = pcVar20;
  puVar10[3] = puStack_60;
  puVar14 = PTR__M_manager_00324f88;
  local_58 = *(undefined8 *)(lVar15 + 0x90);
  uVar8 = *(undefined8 *)(lVar15 + 0x98);
  local_48 = *(code **)(lVar15 + 0xa0);
  *(undefined8 **)(lVar15 + 0x90) = puVar10;
  *(undefined8 *)(lVar15 + 0x98) = local_50;
  *(undefined **)(lVar15 + 0xa0) = puVar14;
  puStack_40 = *(undefined **)(lVar15 + 0xa8);
  *(undefined **)(lVar15 + 0xa8) = PTR__M_invoke_00324fe0;
  local_78 = pvVar5;
  local_70 = uVar6;
  puStack_60 = (undefined *)uVar7;
  local_50 = uVar8;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  local_a8[0] = *(int *)(lVar15 + 0x40);
  cVar3 = *(char *)(lVar15 + 0x88);
  lVar15 = *(long *)(lVar15 + 0x38);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == (_Rb_tree_node_base *)0x0) {
LAB_0010cc60:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, local_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c3da;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c3da:
    if ((p_Var12 == p_Var18) || (p_Var13 = p_Var12, local_a8[0] < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cc60;
    do {
      while (p_Var16 = p_Var17, local_a8[0] <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c40a;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c40a:
    if ((p_Var12 == p_Var16) || (local_a8[0] < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = operator_new(0x28);
      if (p_Var17 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = local_a8[0];
      }
      auVar23 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20);
      p_Var13 = auVar23._8_8_;
      p_Var16 = auVar23._0_8_;
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var17 = p_Var12;
  p_Var13 = p_Var16;
  uVar9 = uVar21;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var18 = p_Var17, local_a8[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var13 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c47a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c47a:
    if ((p_Var16 != p_Var18) && (p_Var17 = p_Var16, *(int *)(p_Var18 + 0x20) <= local_a8[0])) {
      do {
        while (p_Var13 = p_Var12, local_a8[0] <= *(int *)(p_Var13 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
          p_Var17 = p_Var13;
          if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c4aa;
        }
        p_Var18 = p_Var13 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var13 = p_Var17;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c4aa:
      if ((p_Var16 == p_Var13) || (local_a8[0] < *(int *)(p_Var13 + 0x20))) {
        p_Var12 = operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = local_a8[0];
        }
        auVar23 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var1,p_Var13,p_Var12 + 0x20);
        p_Var17 = auVar23._8_8_;
        p_Var13 = auVar23._0_8_;
        if (p_Var17 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var17)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var17 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var17,p_Var16);
          *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
          p_Var13 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var13 + 0x24);
    }
  }
  uVar22 = uVar9 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffe;
  }
  if (uVar21 == uVar22) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(p_Var1,local_a8);
  }
  else {
    p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var13 = p_Var16;
    p_Var17 = p_Var16;
    if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010cb20:
      p_Var12 = operator_new(0x28);
      if (p_Var12 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_a8[0];
      }
      auVar23 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos(p_Var1,p_Var17,p_Var12 + 0x20);
      p_Var13 = auVar23._8_8_;
      p_Var17 = auVar23._0_8_;
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var12);
      }
      else {
        bVar19 = true;
        if ((p_Var17 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var13)) {
          bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var16);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var17 = p_Var12;
      }
    }
    else {
      do {
        while (p_Var17 = p_Var12, local_a8[0] <= *(int *)(p_Var17 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var13 = p_Var17;
          if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c512;
        }
        p_Var18 = p_Var17 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var17 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c512:
      if ((p_Var16 == p_Var17) || (local_a8[0] < *(int *)(p_Var17 + 0x20))) goto LAB_0010cb20;
    }
    *(uint *)(p_Var17 + 0x24) = uVar22;
  }
  if (local_88 != (code *)0x0) {
    (*local_88)(local_98,local_98,3);
  }
  local_68 = (code *)0x0;
  local_78 = operator_new(1);
  lVar15 = *(long *)(this + 0x38);
  puStack_60 = PTR__M_invoke_00324fd8;
  local_68 = (code *)PTR__M_manager_00324ef8;
  if (*(char *)(lVar15 + 0x5a) != '\0') {
    fwrite("close(): send_flag != false\n",1,0x1c,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  puVar10 = *(undefined8 **)(lVar15 + 0x60);
  *(undefined1 *)(lVar15 + 0x5a) = 1;
  *(undefined8 *)(lVar15 + 0x60) = 0;
  if (puVar10 != (undefined8 *)0x0) {
    if ((void *)*puVar10 != (void *)0x0) {
      operator_delete((void *)*puVar10);
    }
    operator_delete(puVar10);
  }
  local_48 = (code *)0x0;
  if (local_68 == (code *)0x0) {
    pcVar20 = (code *)0x0;
    puVar14 = puStack_40;
  }
  else {
    (*local_68)(&local_58,&local_78,2);
    puVar14 = puStack_60;
    pcVar20 = local_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0x68);
  uVar7 = *(undefined8 *)(lVar15 + 0x70);
  local_48 = *(code **)(lVar15 + 0x78);
  *(undefined8 *)(lVar15 + 0x68) = local_58;
  *(undefined8 *)(lVar15 + 0x70) = local_50;
  puStack_40 = *(undefined **)(lVar15 + 0x80);
  *(code **)(lVar15 + 0x78) = pcVar20;
  *(undefined **)(lVar15 + 0x80) = puVar14;
  local_58 = uVar6;
  local_50 = uVar7;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  cVar3 = *(char *)(lVar15 + 0x5a);
  iVar4 = *(int *)(lVar15 + 0x40);
  lVar15 = *(long *)(lVar15 + 0x38);
  local_98[0] = (undefined8 *)CONCAT44(local_98[0]._4_4_,iVar4);
  p_Var17 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  p_Var13 = p_Var17;
  p_Var16 = p_Var12;
  if (p_Var17 == (_Rb_tree_node_base *)0x0) {
LAB_0010cc40:
    lVar11 = 0;
    uVar21 = 0;
  }
  else {
    do {
      while (p_Var18 = p_Var13, iVar4 <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c68a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c68a:
    if ((p_Var18 == p_Var12) || (p_Var13 = p_Var12, iVar4 < *(int *)(p_Var18 + 0x20)))
    goto LAB_0010cc40;
    do {
      while (p_Var16 = p_Var17, iVar4 <= *(int *)(p_Var16 + 0x20)) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c6ba;
      }
      p_Var18 = p_Var16 + 0x18;
      p_Var17 = *(_Rb_tree_node_base **)p_Var18;
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c6ba:
    if ((p_Var16 == p_Var12) || (iVar4 < *(int *)(p_Var16 + 0x20))) {
      p_Var17 = operator_new(0x28);
      if (p_Var17 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var17 = 0;
        *(undefined8 *)(p_Var17 + 8) = 0;
        *(undefined8 *)(p_Var17 + 0x10) = 0;
        *(undefined8 *)(p_Var17 + 0x18) = 0;
        *(undefined4 *)(p_Var17 + 0x24) = 0;
        *(int *)(p_Var17 + 0x20) = (int)local_98[0];
      }
      auVar23 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar15 + 8),p_Var16,p_Var17 + 0x20);
      p_Var13 = auVar23._8_8_;
      p_Var16 = auVar23._0_8_;
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var17);
      }
      else {
        bVar19 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
          bVar19 = *(int *)(p_Var17 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar19,p_Var17,p_Var13,p_Var12);
        *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
        p_Var16 = p_Var17;
      }
    }
    uVar21 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar15 = lVar15 + (lVar11 + 1) * 0x30;
  p_Var1 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(lVar15 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
  p_Var17 = (_Rb_tree_node_base *)(lVar15 + 0x10);
  uVar9 = uVar21;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    p_Var13 = p_Var12;
    p_Var16 = p_Var17;
    do {
      while (p_Var18 = p_Var13, (int)local_98[0] <= *(int *)(p_Var18 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var16 = p_Var18;
        if (*(_Rb_tree_node_base **)(p_Var18 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c72a;
      }
      p_Var2 = p_Var18 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var2;
      p_Var18 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_0010c72a:
    if ((p_Var18 != p_Var17) && (p_Var13 = p_Var17, *(int *)(p_Var18 + 0x20) <= (int)local_98[0])) {
      do {
        while (p_Var16 = p_Var12, (int)local_98[0] <= *(int *)(p_Var16 + 0x20)) {
          p_Var12 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
          p_Var13 = p_Var16;
          if (*(_Rb_tree_node_base **)(p_Var16 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0010c75a;
        }
        p_Var18 = p_Var16 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var18;
        p_Var16 = p_Var13;
      } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c75a:
      if ((p_Var16 == p_Var17) || ((int)local_98[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var12 = operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = (int)local_98[0];
        }
        auVar23 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var1,p_Var16,p_Var12 + 0x20);
        p_Var13 = auVar23._8_8_;
        p_Var16 = auVar23._0_8_;
        if (p_Var13 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var12);
        }
        else {
          bVar19 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var17 != p_Var13)) {
            bVar19 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var13 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar19,p_Var12,p_Var13,p_Var17);
          *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
          p_Var16 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar22 = uVar9 | 2;
  if (cVar3 == '\0') {
    uVar22 = uVar9 & 0xfffffffd;
  }
  if (uVar21 == uVar22) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(p_Var1,(int *)local_98);
    goto LAB_0010c7db;
  }
  p_Var12 = p_Var17;
  if (*(_Rb_tree_node_base **)(lVar15 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010cbb0:
    p_Var13 = operator_new(0x28);
    if (p_Var13 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var13 = 0;
      *(undefined8 *)(p_Var13 + 8) = 0;
      *(undefined8 *)(p_Var13 + 0x10) = 0;
      *(undefined8 *)(p_Var13 + 0x18) = 0;
      *(undefined4 *)(p_Var13 + 0x24) = 0;
      *(int *)(p_Var13 + 0x20) = (int)local_98[0];
    }
    auVar23 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(p_Var1,p_Var12,p_Var13 + 0x20);
    p_Var16 = auVar23._8_8_;
    p_Var12 = auVar23._0_8_;
    if (p_Var16 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var13);
    }
    else {
      bVar19 = true;
      if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var17 != p_Var16)) {
        bVar19 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar19,p_Var13,p_Var16,p_Var17);
      *(long *)(lVar15 + 0x30) = *(long *)(lVar15 + 0x30) + 1;
      p_Var12 = p_Var13;
    }
  }
  else {
    p_Var13 = *(_Rb_tree_node_base **)(lVar15 + 0x18);
    p_Var16 = p_Var17;
    do {
      while (p_Var12 = p_Var13, (int)local_98[0] <= *(int *)(p_Var12 + 0x20)) {
        p_Var13 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
        p_Var16 = p_Var12;
        if (*(_Rb_tree_node_base **)(p_Var12 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0010c7c2;
      }
      p_Var18 = p_Var12 + 0x18;
      p_Var13 = *(_Rb_tree_node_base **)p_Var18;
      p_Var12 = p_Var16;
    } while (*(_Rb_tree_node_base **)p_Var18 != (_Rb_tree_node_base *)0x0);
LAB_0010c7c2:
    if ((p_Var12 == p_Var17) || ((int)local_98[0] < *(int *)(p_Var12 + 0x20))) goto LAB_0010cbb0;
  }
  *(uint *)(p_Var12 + 0x24) = uVar22;
LAB_0010c7db:
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  local_68 = (code *)0x0;
  local_78 = operator_new(1);
  lVar15 = *(long *)(this + 0x38);
  local_48 = (code *)0x0;
  puStack_60 = PTR__M_invoke_00324fd0;
  local_68 = (code *)PTR__M_manager_00324fc0;
  if (PTR__M_manager_00324fc0 == (undefined *)0x0) {
    pcVar20 = (code *)0x0;
    puVar14 = puStack_40;
  }
  else {
    std::_Function_base::_Base_manager<WSConn::exit()::{lambda()#3}>::_M_manager
              (&local_58,&local_78,2);
    puVar14 = puStack_60;
    pcVar20 = local_68;
  }
  uVar6 = *(undefined8 *)(lVar15 + 0xb0);
  uVar7 = *(undefined8 *)(lVar15 + 0xb8);
  local_48 = *(code **)(lVar15 + 0xc0);
  *(undefined8 *)(lVar15 + 0xb0) = local_58;
  *(undefined8 *)(lVar15 + 0xb8) = local_50;
  puStack_40 = *(undefined **)(lVar15 + 200);
  *(code **)(lVar15 + 0xc0) = pcVar20;
  *(undefined **)(lVar15 + 200) = puVar14;
  local_58 = uVar6;
  local_50 = uVar7;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
    pcVar20 = local_68;
  }
  if (pcVar20 != (code *)0x0) {
    (*pcVar20)(&local_78,&local_78,3);
  }
  return;
}



