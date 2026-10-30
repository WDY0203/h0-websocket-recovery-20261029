
/* std::_Function_handler<void (std::unique_ptr<Buffer, std::default_delete<Buffer> >),
   TcpConn::discard>::_M_invoke(std::_Any_data const&, std::unique_ptr<Buffer,
   std::default_delete<Buffer> >) */

void std::
     _Function_handler<void(std::unique_ptr<Buffer,std::default_delete<Buffer>>),TcpConn::discard>::
     _M_invoke(undefined8 *param_1,undefined8 *param_2)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined *puVar5;
  uint uVar6;
  long *plVar7;
  _Rb_tree_node_base *p_Var8;
  long lVar9;
  _Rb_tree_node_base *p_Var10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  _Rb_tree_node_base *p_Var14;
  bool bVar15;
  uint uVar16;
  uint uVar17;
  undefined1 auVar18 [16];
  int local_68 [4];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  
  puVar3 = (undefined8 *)*param_2;
  *param_2 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    return;
  }
  lVar11 = *(long *)*param_1;
  if (*(char *)(lVar11 + 0x88) != '\0') {
    fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  *(undefined1 *)(lVar11 + 0x88) = 1;
  local_48 = (code *)0x0;
  plVar7 = operator_new(8);
  *plVar7 = lVar11;
  puVar5 = PTR__M_manager_00324f68;
  uVar4 = *(undefined8 *)(lVar11 + 0x98);
  local_58 = *(undefined8 *)(lVar11 + 0x90);
  *(undefined8 *)(lVar11 + 0x98) = local_50;
  local_48 = *(code **)(lVar11 + 0xa0);
  *(undefined **)(lVar11 + 0xa0) = puVar5;
  local_40 = *(undefined8 *)(lVar11 + 0xa8);
  *(long **)(lVar11 + 0x90) = plVar7;
  *(undefined **)(lVar11 + 0xa8) = PTR__M_invoke_00324f40;
  local_50 = uVar4;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  local_68[0] = *(int *)(lVar11 + 0x40);
  cVar2 = *(char *)(lVar11 + 0x88);
  lVar11 = *(long *)(lVar11 + 0x38);
  p_Var8 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var10 = (_Rb_tree_node_base *)(lVar11 + 0x10);
  p_Var13 = p_Var8;
  p_Var12 = p_Var10;
  if (p_Var8 == (_Rb_tree_node_base *)0x0) {
LAB_00115e7b:
    lVar9 = 0;
    uVar16 = 0;
  }
  else {
    do {
      while (p_Var14 = p_Var13, *(int *)(p_Var14 + 0x20) < local_68[0]) {
        p_Var1 = p_Var14 + 0x18;
        p_Var13 = *(_Rb_tree_node_base **)p_Var1;
        p_Var14 = p_Var12;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115e6a;
      }
      p_Var13 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var12 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115e6a:
    if ((p_Var10 == p_Var14) || (p_Var13 = p_Var10, local_68[0] < *(int *)(p_Var14 + 0x20)))
    goto LAB_00115e7b;
    do {
      while (p_Var12 = p_Var8, *(int *)(p_Var12 + 0x20) < local_68[0]) {
        p_Var14 = p_Var12 + 0x18;
        p_Var8 = *(_Rb_tree_node_base **)p_Var14;
        p_Var12 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_0011603a;
      }
      p_Var8 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
      p_Var13 = p_Var12;
    } while (*(_Rb_tree_node_base **)(p_Var12 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011603a:
    if ((p_Var10 == p_Var12) || (local_68[0] < *(int *)(p_Var12 + 0x20))) {
      p_Var8 = operator_new(0x28);
      if (p_Var8 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var8 = 0;
        *(undefined8 *)(p_Var8 + 8) = 0;
        *(undefined8 *)(p_Var8 + 0x10) = 0;
        *(undefined8 *)(p_Var8 + 0x18) = 0;
        *(undefined4 *)(p_Var8 + 0x24) = 0;
        *(int *)(p_Var8 + 0x20) = local_68[0];
      }
      auVar18 = _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar11 + 8),p_Var12,p_Var8 + 0x20);
      p_Var13 = auVar18._8_8_;
      p_Var12 = auVar18._0_8_;
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var8);
      }
      else {
        bVar15 = true;
        if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var10 != p_Var13)) {
          bVar15 = *(int *)(p_Var8 + 0x20) < *(int *)(p_Var13 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar15,p_Var8,p_Var13,p_Var10);
        *(long *)(lVar11 + 0x30) = *(long *)(lVar11 + 0x30) + 1;
        p_Var12 = p_Var8;
      }
    }
    uVar16 = *(uint *)(p_Var12 + 0x24);
    lVar9 = 1;
  }
  lVar11 = lVar11 + (lVar9 + 1) * 0x30;
  this = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
          *)(lVar11 + 8);
  p_Var10 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar11 + 0x10);
  p_Var8 = p_Var10;
  p_Var13 = p_Var12;
  uVar6 = uVar16;
  if (p_Var10 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var14 = p_Var8, *(int *)(p_Var14 + 0x20) < local_68[0]) {
        p_Var1 = p_Var14 + 0x18;
        p_Var8 = *(_Rb_tree_node_base **)p_Var1;
        p_Var14 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115eca;
      }
      p_Var8 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var13 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115eca:
    if ((p_Var12 != p_Var14) && (p_Var8 = p_Var12, *(int *)(p_Var14 + 0x20) <= local_68[0])) {
      do {
        while (p_Var13 = p_Var10, *(int *)(p_Var13 + 0x20) < local_68[0]) {
          p_Var14 = p_Var13 + 0x18;
          p_Var10 = *(_Rb_tree_node_base **)p_Var14;
          p_Var13 = p_Var8;
          if (*(_Rb_tree_node_base **)p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_00115efa;
        }
        p_Var10 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
        p_Var8 = p_Var13;
      } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115efa:
      if ((p_Var12 == p_Var13) || (local_68[0] < *(int *)(p_Var13 + 0x20))) {
        p_Var10 = operator_new(0x28);
        if (p_Var10 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var10 = 0;
          *(undefined8 *)(p_Var10 + 8) = 0;
          *(undefined8 *)(p_Var10 + 0x10) = 0;
          *(undefined8 *)(p_Var10 + 0x18) = 0;
          *(undefined4 *)(p_Var10 + 0x24) = 0;
          *(int *)(p_Var10 + 0x20) = local_68[0];
        }
        auVar18 = _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(this,p_Var13,p_Var10 + 0x20);
        p_Var8 = auVar18._8_8_;
        p_Var13 = auVar18._0_8_;
        if (p_Var8 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var10);
        }
        else {
          bVar15 = true;
          if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var8)) {
            bVar15 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var8 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var8,p_Var12);
          *(long *)(lVar11 + 0x30) = *(long *)(lVar11 + 0x30) + 1;
          p_Var13 = p_Var10;
        }
      }
      uVar6 = *(uint *)(p_Var13 + 0x24);
    }
  }
  uVar17 = uVar6 | 1;
  if (cVar2 == '\0') {
    uVar17 = uVar6 & 0xfffffffe;
  }
  if (uVar16 == uVar17) {
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(this,local_68);
    goto LAB_00115ff3;
  }
  p_Var10 = *(_Rb_tree_node_base **)(lVar11 + 0x18);
  p_Var13 = p_Var12;
  p_Var8 = p_Var12;
  if (*(_Rb_tree_node_base **)(lVar11 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116100:
    p_Var10 = operator_new(0x28);
    if (p_Var10 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var10 = 0;
      *(undefined8 *)(p_Var10 + 8) = 0;
      *(undefined8 *)(p_Var10 + 0x10) = 0;
      *(undefined8 *)(p_Var10 + 0x18) = 0;
      *(undefined4 *)(p_Var10 + 0x24) = 0;
      *(int *)(p_Var10 + 0x20) = local_68[0];
    }
    auVar18 = _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(this,p_Var8,p_Var10 + 0x20);
    p_Var13 = auVar18._8_8_;
    p_Var8 = auVar18._0_8_;
    if (p_Var13 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var10);
    }
    else {
      bVar15 = true;
      if ((p_Var8 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var13)) {
        bVar15 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var13 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var13,p_Var12);
      *(long *)(lVar11 + 0x30) = *(long *)(lVar11 + 0x30) + 1;
      p_Var8 = p_Var10;
    }
  }
  else {
    do {
      while (p_Var8 = p_Var10, *(int *)(p_Var8 + 0x20) < local_68[0]) {
        p_Var14 = p_Var8 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var14;
        p_Var8 = p_Var13;
        if (*(_Rb_tree_node_base **)p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_00115fda;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
      p_Var13 = p_Var8;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115fda:
    if ((p_Var12 == p_Var8) || (local_68[0] < *(int *)(p_Var8 + 0x20))) goto LAB_00116100;
  }
  *(uint *)(p_Var8 + 0x24) = uVar17;
LAB_00115ff3:
  if ((void *)*puVar3 != (void *)0x0) {
    operator_delete((void *)*puVar3);
  }
  operator_delete(puVar3);
  return;
}



