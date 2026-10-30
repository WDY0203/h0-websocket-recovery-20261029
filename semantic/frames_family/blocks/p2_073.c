
/* WARNING: Switch with 1 destination removed at 0x001072f0 */

void __thiscall
std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
          (vector<unsigned_char,std::allocator<unsigned_char>> *this,uchar *param_1)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  char cVar2;
  uchar *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined *puVar6;
  uint uVar7;
  ulong uVar8;
  void *__dest;
  size_t __n;
  long *plVar9;
  _Rb_tree_node_base *p_Var10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  void *__src;
  char *pcVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  undefined1 auVar22 [16];
  int aiStack_a0 [4];
  undefined8 uStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined8 uStack_78;
  vector<unsigned_char,std::allocator<unsigned_char>> *pvStack_68;
  
  puVar3 = *(uchar **)(this + 8);
  if (puVar3 != *(uchar **)(this + 0x10)) {
    if (puVar3 == (uchar *)0x0) {
      lVar13 = 0;
    }
    else {
      *puVar3 = *param_1;
      lVar13 = *(long *)(this + 8);
    }
    *(long *)(this + 8) = lVar13 + 1;
    return;
  }
  uVar8 = (long)puVar3 - *(long *)this;
  if (uVar8 != 0xffffffffffffffff) {
    uVar19 = 1;
    if (uVar8 != 0) {
      uVar19 = 0xffffffffffffffff;
      if (uVar8 <= uVar8 * 2) {
        uVar19 = uVar8 * 2;
      }
    }
    __dest = operator_new(uVar19);
    __src = *(void **)this;
    __n = *(long *)(this + 8) - (long)__src;
    if ((uchar *)((long)__dest + __n) == (uchar *)0x0) {
      lVar13 = 0;
    }
    else {
      *(uchar *)((long)__dest + __n) = *param_1;
      __src = *(void **)this;
      __n = *(long *)(this + 8) - (long)__src;
      lVar13 = (long)__dest + __n;
    }
    if (__n != 0) {
      memmove(__dest,__src,__n);
      __src = *(void **)this;
    }
    if (__src != (void *)0x0) {
      operator_delete(__src);
    }
    *(void **)this = __dest;
    *(long *)(this + 8) = lVar13 + 1;
    *(ulong *)(this + 0x10) = (long)__dest + uVar19;
    return;
  }
  pcVar18 = "vector::_M_emplace_back_aux";
  std::__throw_length_error("vector::_M_emplace_back_aux");
  puVar4 = *(undefined8 **)param_1;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  if (puVar4 == (undefined8 *)0x0) {
    return;
  }
  lVar13 = **(long **)pcVar18;
  pvStack_68 = this;
  if (*(char *)(lVar13 + 0x88) != '\0') {
    fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  *(undefined1 *)(lVar13 + 0x88) = 1;
  pcStack_80 = (code *)0x0;
  plVar9 = operator_new(8);
  *plVar9 = lVar13;
  puVar6 = PTR__M_manager_00324f68;
  uVar5 = *(undefined8 *)(lVar13 + 0x98);
  uStack_90 = *(undefined8 *)(lVar13 + 0x90);
  *(undefined8 *)(lVar13 + 0x98) = uStack_88;
  pcStack_80 = *(code **)(lVar13 + 0xa0);
  *(undefined **)(lVar13 + 0xa0) = puVar6;
  uStack_78 = *(undefined8 *)(lVar13 + 0xa8);
  *(long **)(lVar13 + 0x90) = plVar9;
  *(undefined **)(lVar13 + 0xa8) = PTR__M_invoke_00324f40;
  uStack_88 = uVar5;
  if (pcStack_80 != (code *)0x0) {
    (*pcStack_80)(&uStack_90,&uStack_90,3);
  }
  aiStack_a0[0] = *(int *)(lVar13 + 0x40);
  cVar2 = *(char *)(lVar13 + 0x88);
  lVar13 = *(long *)(lVar13 + 0x38);
  p_Var10 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var12 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var15 = p_Var10;
  p_Var14 = p_Var12;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
LAB_00115e7b:
    lVar11 = 0;
    uVar20 = 0;
  }
  else {
    do {
      while (p_Var16 = p_Var15, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var15 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var14;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115e6a;
      }
      p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var14 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115e6a:
    if ((p_Var12 == p_Var16) || (p_Var15 = p_Var12, aiStack_a0[0] < *(int *)(p_Var16 + 0x20)))
    goto LAB_00115e7b;
    do {
      while (p_Var14 = p_Var10, *(int *)(p_Var14 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var14 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var16;
        p_Var14 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_0011603a;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      p_Var15 = p_Var14;
    } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011603a:
    if ((p_Var12 == p_Var14) || (aiStack_a0[0] < *(int *)(p_Var14 + 0x20))) {
      p_Var10 = operator_new(0x28);
      if (p_Var10 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var10 = 0;
        *(undefined8 *)(p_Var10 + 8) = 0;
        *(undefined8 *)(p_Var10 + 0x10) = 0;
        *(undefined8 *)(p_Var10 + 0x18) = 0;
        *(undefined4 *)(p_Var10 + 0x24) = 0;
        *(int *)(p_Var10 + 0x20) = aiStack_a0[0];
      }
      auVar22 = _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar13 + 8),p_Var14,p_Var10 + 0x20);
      p_Var15 = auVar22._8_8_;
      p_Var14 = auVar22._0_8_;
      if (p_Var15 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var10);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var15)) {
          bVar17 = *(int *)(p_Var10 + 0x20) < *(int *)(p_Var15 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar17,p_Var10,p_Var15,p_Var12);
        *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
        p_Var14 = p_Var10;
      }
    }
    uVar20 = *(uint *)(p_Var14 + 0x24);
    lVar11 = 1;
  }
  lVar13 = lVar13 + (lVar11 + 1) * 0x30;
  this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
             *)(lVar13 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar13 + 0x10);
  p_Var10 = p_Var12;
  p_Var15 = p_Var14;
  uVar7 = uVar20;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var16 = p_Var10, *(int *)(p_Var16 + 0x20) < aiStack_a0[0]) {
        p_Var1 = p_Var16 + 0x18;
        p_Var10 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115eca;
      }
      p_Var10 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var15 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115eca:
    if ((p_Var14 != p_Var16) && (p_Var10 = p_Var14, *(int *)(p_Var16 + 0x20) <= aiStack_a0[0])) {
      do {
        while (p_Var15 = p_Var12, *(int *)(p_Var15 + 0x20) < aiStack_a0[0]) {
          p_Var16 = p_Var15 + 0x18;
          p_Var12 = *(_Rb_tree_node_base **)p_Var16;
          p_Var15 = p_Var10;
          if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_00115efa;
        }
        p_Var12 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var10 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115efa:
      if ((p_Var14 == p_Var15) || (aiStack_a0[0] < *(int *)(p_Var15 + 0x20))) {
        p_Var12 = operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
        }
        auVar22 = _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var12 + 0x20);
        p_Var10 = auVar22._8_8_;
        p_Var15 = auVar22._0_8_;
        if (p_Var10 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var12);
        }
        else {
          bVar17 = true;
          if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var10)) {
            bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var10 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var10,p_Var14);
          *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
          p_Var15 = p_Var12;
        }
      }
      uVar7 = *(uint *)(p_Var15 + 0x24);
    }
  }
  uVar21 = uVar7 | 1;
  if (cVar2 == '\0') {
    uVar21 = uVar7 & 0xfffffffe;
  }
  if (uVar20 == uVar21) {
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(this_00,aiStack_a0);
    goto LAB_00115ff3;
  }
  p_Var12 = *(_Rb_tree_node_base **)(lVar13 + 0x18);
  p_Var15 = p_Var14;
  p_Var10 = p_Var14;
  if (*(_Rb_tree_node_base **)(lVar13 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116100:
    p_Var12 = operator_new(0x28);
    if (p_Var12 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var12 = 0;
      *(undefined8 *)(p_Var12 + 8) = 0;
      *(undefined8 *)(p_Var12 + 0x10) = 0;
      *(undefined8 *)(p_Var12 + 0x18) = 0;
      *(undefined4 *)(p_Var12 + 0x24) = 0;
      *(int *)(p_Var12 + 0x20) = aiStack_a0[0];
    }
    auVar22 = _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(this_00,p_Var10,p_Var12 + 0x20);
    p_Var15 = auVar22._8_8_;
    p_Var10 = auVar22._0_8_;
    if (p_Var15 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var12);
    }
    else {
      bVar17 = true;
      if ((p_Var10 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var15)) {
        bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var15 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var15,p_Var14);
      *(long *)(lVar13 + 0x30) = *(long *)(lVar13 + 0x30) + 1;
      p_Var10 = p_Var12;
    }
  }
  else {
    do {
      while (p_Var10 = p_Var12, *(int *)(p_Var10 + 0x20) < aiStack_a0[0]) {
        p_Var16 = p_Var10 + 0x18;
        p_Var12 = *(_Rb_tree_node_base **)p_Var16;
        p_Var10 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var16 == (_Rb_tree_node_base *)0x0) goto LAB_00115fda;
      }
      p_Var12 = *(_Rb_tree_node_base **)(p_Var10 + 0x10);
      p_Var15 = p_Var10;
    } while (*(_Rb_tree_node_base **)(p_Var10 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115fda:
    if ((p_Var14 == p_Var10) || (aiStack_a0[0] < *(int *)(p_Var10 + 0x20))) goto LAB_00116100;
  }
  *(uint *)(p_Var10 + 0x24) = uVar21;
LAB_00115ff3:
  if ((void *)*puVar4 != (void *)0x0) {
    operator_delete((void *)*puVar4);
  }
  operator_delete(puVar4);
  return;
}



