
/* WSConn::recv_more(unsigned long, std::function<void ()>) */

void __thiscall WSConn::recv_more(WSConn *this,ulong param_1,long param_3)

{
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  long lVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  code *pcVar12;
  _Rb_tree_node_base *p_Var13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auVar20 [16];
  int local_c8 [4];
  undefined8 local_b8;
  undefined8 local_b0;
  code *local_a8;
  undefined8 local_a0;
  WSConn *local_98;
  ulong local_90;
  undefined1 local_88 [16];
  code *local_78;
  undefined8 uStack_70;
  WSConn *local_68;
  ulong local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 uStack_40;
  
  if (param_1 <= (ulong)((*(long **)(this + 0x40))[1] - **(long **)(this + 0x40))) {
    if (*(long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3);
      return;
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_function_call();
  }
  local_78 = (code *)0x0;
  local_98 = this;
  local_90 = param_1;
  if (*(code **)(param_3 + 0x10) == (code *)0x0) {
    pcVar12 = (code *)0x0;
  }
  else {
    (**(code **)(param_3 + 0x10))(local_88,param_3,2);
    local_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
    pcVar12 = *(code **)(param_3 + 0x10);
  }
  lVar14 = *(long *)(this + 0x38);
  if (*(char *)(lVar14 + 0x88) != '\0') {
    fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
    pcVar12 = local_78;
  }
  *(undefined1 *)(lVar14 + 0x88) = 1;
  local_48 = (code *)0x0;
  local_68 = local_98;
  local_60 = local_90;
  if (pcVar12 != (code *)0x0) {
    (*pcVar12)(&local_58,local_88,2);
    local_48 = local_78;
    uStack_40 = uStack_70;
  }
  local_a8 = (code *)0x0;
  puVar8 = operator_new(0x30);
  pcVar12 = local_48;
  puVar8[4] = 0;
  uVar3 = puVar8[2];
  uVar4 = puVar8[3];
  uVar5 = puVar8[5];
  *puVar8 = local_68;
  puVar8[1] = local_60;
  puVar8[3] = local_50;
  puVar8[2] = local_58;
  local_48 = (code *)0x0;
  puVar8[4] = pcVar12;
  puVar8[5] = uStack_40;
  local_b8 = *(undefined8 *)(lVar14 + 0x90);
  uVar6 = *(undefined8 *)(lVar14 + 0x98);
  *(undefined8 *)(lVar14 + 0x98) = local_b0;
  *(undefined8 **)(lVar14 + 0x90) = puVar8;
  local_a8 = *(code **)(lVar14 + 0xa0);
  local_a0 = *(undefined8 *)(lVar14 + 0xa8);
  *(code **)(lVar14 + 0xa0) = FUN_0010e430;
  *(code **)(lVar14 + 0xa8) = FUN_00111c50;
  local_b0 = uVar6;
  local_58 = uVar3;
  local_50 = uVar4;
  uStack_40 = uVar5;
  if (local_a8 != (code *)0x0) {
    (*local_a8)(&local_b8,&local_b8,3);
  }
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  local_c8[0] = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x88);
  lVar14 = *(long *)(lVar14 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var16 = p_Var10;
  p_Var15 = p_Var11;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
LAB_001103f0:
    lVar9 = 0;
    uVar18 = 0;
  }
  else {
    do {
      while (p_Var13 = p_Var16, *(int *)(p_Var13 + 0x20) < local_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001100b3;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var15 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001100b3:
    if ((p_Var11 == p_Var13) || (p_Var16 = p_Var11, local_c8[0] < *(int *)(p_Var13 + 0x20)))
    goto LAB_001103f0;
    do {
      while (p_Var15 = p_Var10, *(int *)(p_Var15 + 0x20) < local_c8[0]) {
        p_Var13 = p_Var15 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var13;
        p_Var15 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_001100eb;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var16 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001100eb:
    if ((p_Var11 == p_Var15) || (local_c8[0] < *(int *)(p_Var15 + 0x20))) {
      p_Var10 = operator_new(0x28);
      if (p_Var10 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = local_c8[0];
      }
      auVar20 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar14 + 8),p_Var15,p_Var10 + 0x20);
      p_Var16 = auVar20._8_8_;
      p_Var15 = auVar20._0_8_;
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var16)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var16,p_Var11);
        *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
        p_Var15 = p_Var10;
      }
    }
    uVar18 = *(uint *)(p_Var15 + 0x24);
    lVar9 = 1;
  }
  lVar14 = lVar14 + (lVar9 + 1) * 0x30;
  this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
             *)(lVar14 + 8);
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var15 = (_Rb_tree_node_base *)(lVar14 + 0x10);
  p_Var10 = p_Var11;
  p_Var16 = p_Var15;
  uVar7 = uVar18;
  if (p_Var11 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var13 = p_Var10, *(int *)(p_Var13 + 0x20) < local_c8[0]) {
        p_Var1 = p_Var13 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var13 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011015a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
      p_Var16 = p_Var13;
    } while (*(_Rb_tree_node_base **)(p_Var13 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011015a:
    if ((p_Var15 != p_Var13) && (p_Var10 = p_Var15, *(int *)(p_Var13 + 0x20) <= local_c8[0])) {
      do {
        while (p_Var16 = p_Var11, *(int *)(p_Var16 + 0x20) < local_c8[0]) {
          p_Var13 = p_Var16 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var13;
          p_Var16 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_0011018a;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var10 = p_Var16;
      } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011018a:
      if ((p_Var15 == p_Var16) || (local_c8[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var11 = operator_new(0x28);
        if (p_Var11 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_c8[0];
        }
        auVar20 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(this_00,p_Var16,p_Var11 + 0x20);
        p_Var10 = auVar20._8_8_;
        p_Var16 = auVar20._0_8_;
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var11);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var10)) {
            bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var10,p_Var15);
          *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
          p_Var16 = p_Var11;
        }
      }
      uVar7 = *(uint *)(p_Var16 + 0x24);
    }
  }
  uVar19 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar19 = uVar7 & 0xfffffffe;
  }
  if (uVar18 == uVar19) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(this_00,local_c8);
    goto LAB_00110208;
  }
  p_Var11 = *(_Rb_tree_node_base **)(lVar14 + 0x18);
  p_Var16 = p_Var15;
  p_Var10 = p_Var15;
  if (*(_Rb_tree_node_base **)(lVar14 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00110360:
    p_Var11 = operator_new(0x28);
    if (p_Var11 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var11 = 0;
      *(undefined8 *)(p_Var11 + 8) = 0;
      *(undefined8 *)(p_Var11 + 0x10) = 0;
      *(undefined8 *)(p_Var11 + 0x18) = 0;
      *(undefined4 *)(p_Var11 + 0x24) = 0;
      *(int *)(p_Var11 + 0x20) = local_c8[0];
    }
    auVar20 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var11 + 0x20);
    p_Var16 = auVar20._8_8_;
    p_Var10 = auVar20._0_8_;
    if (p_Var16 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var11);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var16)) {
        bVar17 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var16 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar17,p_Var11,p_Var16,p_Var15);
      *(long *)(lVar14 + 0x30) = *(long *)(lVar14 + 0x30) + 1;
      p_Var10 = p_Var11;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var11, *(int *)(p_Var10 + 0x20) < local_c8[0]) {
        p_Var13 = p_Var10 + 0x18;
        p_Var11 = *(_Rb_tree_node_base **)p_Var13;
        p_Var10 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var13 == (_Rb_tree_node_base *)0x0) goto LAB_001101f2;
      }
      p_Var11 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var16 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001101f2:
    if ((p_Var15 == p_Var10) || (local_c8[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00110360;
  }
  *(uint *)(p_Var10 + 0x24) = uVar19;
LAB_00110208:
  if (local_78 != (code *)0x0) {
    (*local_78)(local_88,local_88,3);
  }
  return;
}



