
/* WARNING: Switch with 1 destination removed at 0x00106f10 */

void __thiscall WSConn::recv_pat(WSConn *this,string *param_2,long param_3)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  int *piVar2;
  char cVar3;
  void *__haystack;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  void *pvVar12;
  undefined8 *puVar13;
  _Rb_tree_node_base *p_Var14;
  long lVar15;
  _Rb_tree_node_base *p_Var16;
  long lVar17;
  _Rb_tree_node_base *p_Var18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  uint uVar22;
  uint uVar23;
  undefined1 auVar24 [16];
  int aiStack_c8 [4];
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  WSConn *pWStack_98;
  long lStack_90;
  undefined1 auStack_88 [16];
  code *pcStack_78;
  undefined8 uStack_70;
  WSConn *pWStack_68;
  undefined *puStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  __haystack = (void *)**(undefined8 **)(this + 0x40);
  pvVar12 = memmem(__haystack,(*(undefined8 **)(this + 0x40))[1] - (long)__haystack,
                   *(void **)param_2,*(size_t *)((long)*(void **)param_2 + -0x18));
  if (pvVar12 != (void *)0x0) {
    if (*(long *)(param_3 + 0x10) != 0) {
      (**(code **)(param_3 + 0x18))(param_3,(long)pvVar12 - (long)__haystack);
      return;
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_function_call();
  }
  pWStack_98 = this;
  std::string::string((string *)&lStack_90,param_2);
  pcStack_78 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(auStack_88,param_3,2);
    pcStack_78 = *(code **)(param_3 + 0x10);
    uStack_70 = *(undefined8 *)(param_3 + 0x18);
  }
  lVar17 = *(long *)(this + 0x38);
  if (*(char *)(lVar17 + 0x88) != '\0') {
    fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  *(undefined1 *)(lVar17 + 0x88) = 1;
  pWStack_68 = pWStack_98;
  std::string::string((string *)&puStack_60,(string *)&lStack_90);
  pcStack_48 = (code *)0x0;
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(&uStack_58,auStack_88,2);
    pcStack_48 = pcStack_78;
    uStack_40 = uStack_70;
  }
  pcStack_a8 = (code *)0x0;
  puVar13 = operator_new(0x30);
  pcVar9 = pcStack_48;
  puVar8 = PTR__S_empty_rep_storage_00324fa0;
  *puVar13 = pWStack_68;
  puVar13[1] = puStack_60;
  puStack_60 = puVar8 + 0x18;
  puVar13[4] = 0;
  uVar4 = puVar13[2];
  uVar5 = puVar13[3];
  puVar13[2] = uStack_58;
  puVar13[3] = uStack_50;
  pcStack_48 = (code *)0x0;
  uVar6 = puVar13[5];
  puVar13[4] = pcVar9;
  puVar13[5] = uStack_40;
  uStack_b8 = *(undefined8 *)(lVar17 + 0x90);
  uVar7 = *(undefined8 *)(lVar17 + 0x98);
  pcStack_a8 = *(code **)(lVar17 + 0xa0);
  *(undefined8 *)(lVar17 + 0x98) = uStack_b0;
  *(undefined8 **)(lVar17 + 0x90) = puVar13;
  *(code **)(lVar17 + 0xa0) = FUN_0010dfb0;
  uStack_a0 = *(undefined8 *)(lVar17 + 0xa8);
  *(code **)(lVar17 + 0xa8) = FUN_00112080;
  uStack_b0 = uVar7;
  uStack_58 = uVar4;
  uStack_50 = uVar5;
  uStack_40 = uVar6;
  if (pcStack_a8 != (code *)0x0) {
    (*pcStack_a8)(&uStack_b8,&uStack_b8,3);
  }
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  if ((allocator *)(puStack_60 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(puStack_60 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar11 = *(int *)(puStack_60 + -8);
      *(int *)(puStack_60 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(puStack_60 + -0x18));
    }
  }
  cVar3 = *(char *)(lVar17 + 0x88);
  aiStack_c8[0] = *(int *)(lVar17 + 0x40);
  lVar17 = *(long *)(lVar17 + 0x38);
  p_Var14 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var16 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var19 = p_Var14;
  p_Var18 = p_Var16;
  if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0010f630:
    lVar15 = 0;
    uVar23 = 0;
  }
  else {
    do {
      while (p_Var20 = p_Var19, *(int *)(p_Var20 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var19 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var18;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0010f53a;
      }
      p_Var19 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var18 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f53a:
    if ((p_Var16 == p_Var20) || (p_Var19 = p_Var16, aiStack_c8[0] < *(int *)(p_Var20 + 0x20)))
    goto LAB_0010f630;
    do {
      while (p_Var18 = p_Var14, *(int *)(p_Var18 + 0x20) < aiStack_c8[0]) {
        p_Var20 = p_Var18 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var20;
        p_Var18 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f56a;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
      p_Var19 = p_Var18;
    } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f56a:
    if ((p_Var16 == p_Var18) || (aiStack_c8[0] < *(int *)(p_Var18 + 0x20))) {
      p_Var14 = operator_new(0x28);
      if (p_Var14 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var14 = 0;
        *(undefined8 *)(p_Var14 + 8) = 0;
        *(undefined8 *)(p_Var14 + 0x10) = 0;
        *(undefined8 *)(p_Var14 + 0x18) = 0;
        *(undefined4 *)(p_Var14 + 0x24) = 0;
        *(int *)(p_Var14 + 0x20) = aiStack_c8[0];
      }
      auVar24 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar17 + 8),p_Var18,p_Var14 + 0x20);
      p_Var19 = auVar24._8_8_;
      p_Var18 = auVar24._0_8_;
      if (p_Var19 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var14);
      }
      else {
        bVar21 = true;
        if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var16 != p_Var19)) {
          bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var19,p_Var16);
        *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
        p_Var18 = p_Var14;
      }
    }
    uVar23 = *(uint *)(p_Var18 + 0x24);
    lVar15 = 1;
  }
  lVar17 = lVar17 + (lVar15 + 1) * 0x30;
  this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
             *)(lVar17 + 8);
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var18 = (_Rb_tree_node_base *)(lVar17 + 0x10);
  p_Var14 = p_Var16;
  p_Var19 = p_Var18;
  uVar10 = uVar23;
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var20 = p_Var14, *(int *)(p_Var20 + 0x20) < aiStack_c8[0]) {
        p_Var1 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var1;
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0010f682;
      }
      p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)(p_Var20 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f682:
    if ((p_Var18 != p_Var20) && (p_Var14 = p_Var18, *(int *)(p_Var20 + 0x20) <= aiStack_c8[0])) {
      do {
        while (p_Var19 = p_Var16, *(int *)(p_Var19 + 0x20) < aiStack_c8[0]) {
          p_Var20 = p_Var19 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var20;
          p_Var19 = p_Var14;
          if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f6ba;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var14 = p_Var19;
      } while (*(_Rb_tree_node_base **)(p_Var19 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f6ba:
      if ((p_Var18 == p_Var19) || (aiStack_c8[0] < *(int *)(p_Var19 + 0x20))) {
        p_Var16 = operator_new(0x28);
        if (p_Var16 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var16 = 0;
          *(undefined8 *)(p_Var16 + 8) = 0;
          *(undefined8 *)(p_Var16 + 0x10) = 0;
          *(undefined8 *)(p_Var16 + 0x18) = 0;
          *(undefined4 *)(p_Var16 + 0x24) = 0;
          *(int *)(p_Var16 + 0x20) = aiStack_c8[0];
        }
        auVar24 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(this_00,p_Var19,p_Var16 + 0x20);
        p_Var14 = auVar24._8_8_;
        p_Var19 = auVar24._0_8_;
        if (p_Var14 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var16);
        }
        else {
          bVar21 = true;
          if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var18 != p_Var14)) {
            bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var14 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var14,p_Var18);
          *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
          p_Var19 = p_Var16;
        }
      }
      uVar10 = *(uint *)(p_Var19 + 0x24);
    }
  }
  uVar22 = uVar10 | 1;
  if (cVar3 == '\0') {
    uVar22 = uVar10 & 0xfffffffe;
  }
  if (uVar23 == uVar22) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(this_00,aiStack_c8);
    goto LAB_0010f82d;
  }
  p_Var16 = *(_Rb_tree_node_base **)(lVar17 + 0x18);
  p_Var19 = p_Var18;
  p_Var14 = p_Var18;
  if (*(_Rb_tree_node_base **)(lVar17 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010f7ad:
    p_Var16 = operator_new(0x28);
    if (p_Var16 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var16 = 0;
      *(undefined8 *)(p_Var16 + 8) = 0;
      *(undefined8 *)(p_Var16 + 0x10) = 0;
      *(undefined8 *)(p_Var16 + 0x18) = 0;
      *(undefined4 *)(p_Var16 + 0x24) = 0;
      *(int *)(p_Var16 + 0x20) = aiStack_c8[0];
    }
    auVar24 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(this_00,p_Var14,p_Var16 + 0x20);
    p_Var19 = auVar24._8_8_;
    p_Var14 = auVar24._0_8_;
    if (p_Var19 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var16);
    }
    else {
      bVar21 = true;
      if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var18 != p_Var19)) {
        bVar21 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var19 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar21,p_Var16,p_Var19,p_Var18);
      *(long *)(lVar17 + 0x30) = *(long *)(lVar17 + 0x30) + 1;
      p_Var14 = p_Var16;
    }
  }
  else {
    do {
      while (p_Var14 = p_Var16, *(int *)(p_Var14 + 0x20) < aiStack_c8[0]) {
        p_Var20 = p_Var14 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var20;
        p_Var14 = p_Var19;
        if (*(_Rb_tree_node_base **)p_Var20 == (_Rb_tree_node_base *)0x0) goto LAB_0010f7a2;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var19 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0010f7a2:
    if ((p_Var18 == p_Var14) || (aiStack_c8[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0010f7ad;
  }
  *(uint *)(p_Var14 + 0x24) = uVar22;
LAB_0010f82d:
  if (pcStack_78 != (code *)0x0) {
    (*pcStack_78)(auStack_88,auStack_88,3);
  }
  if ((allocator *)(lStack_90 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar2 = (int *)(lStack_90 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar11 = *(int *)(lStack_90 + -8);
      *(int *)(lStack_90 + -8) = iVar11 + -1;
    }
    else {
      LOCK();
      iVar11 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar11 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(lStack_90 + -0x18));
    }
  }
  return;
}



