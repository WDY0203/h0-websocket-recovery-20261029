
/* WARNING: Switch with 1 destination removed at 0x00107460 */

void __thiscall WSConn::send(WSConn *this,long *param_2,long param_3)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  char cVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  void *pvVar17;
  void *pvVar18;
  ulong uVar19;
  undefined8 uVar20;
  _Rb_tree_node_base *p_Var21;
  _Rb_tree_node_base *p_Var22;
  ulong uVar23;
  bool bVar24;
  long lVar25;
  _Rb_tree_node_base *p_Var26;
  uint uVar27;
  undefined1 auVar28 [16];
  ulong uStack_68;
  void *pvStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  code *pcStack_48;
  undefined8 uStack_40;
  
  puVar10 = operator_new(0x18);
  *puVar10 = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar3 = *(undefined8 **)(this + 0x50);
  *(undefined8 **)(this + 0x50) = puVar10;
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete((void *)*puVar3);
    }
    operator_delete(puVar3);
  }
  if (this[0x58] == (WSConn)0x0) {
    uStack_58 = CONCAT71(uStack_58._1_7_,0x81);
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
               (uchar *)&uStack_58);
    plVar11 = (long *)*param_2;
LAB_0011535a:
    uVar12 = plVar11[1] - *plVar11;
  }
  else {
    puVar3 = *(undefined8 **)(this + 0x68);
    uVar20 = *(undefined8 *)*param_2;
    uVar4 = ((undefined8 *)*param_2)[1];
    *puVar3 = uVar20;
    *(int *)(puVar3 + 1) = (int)uVar4 - (int)uVar20;
    plVar11 = operator_new(0x18);
    *plVar11 = 0;
    plVar11[1] = 0;
    plVar11[2] = 0;
    uVar12 = deflateBound(*(undefined8 *)(this + 0x68));
    pvVar17 = (void *)plVar11[1];
    pvVar18 = (void *)*plVar11;
    uVar23 = (long)pvVar17 - (long)pvVar18;
    if (uVar23 < uVar12) {
      uVar12 = uVar12 - uVar23;
      if (uVar12 != 0) {
        if ((ulong)(plVar11[2] - (long)pvVar17) < uVar12) {
          if (uVar12 <= ~uVar23) {
            uVar13 = uVar23;
            if (uVar23 <= uVar12) {
              uVar13 = uVar12;
            }
            uVar19 = 0xffffffffffffffff;
            if (CARRY8(uVar13,uVar23)) goto LAB_00115565;
            uVar19 = uVar13 + uVar23;
            if (uVar13 + uVar23 != 0) goto LAB_00115565;
            pvStack_60 = (void *)0x0;
            uVar19 = 0;
            pvVar17 = pvVar18;
            goto LAB_00115583;
          }
          uVar20 = std::__throw_length_error("vector::_M_default_append");
          FUN_00107812(plVar11);
                    /* WARNING: Subroutine does not return */
          _Unwind_Resume(uVar20);
        }
        memset(pvVar17,0,uVar12);
        lVar14 = plVar11[1];
        pvVar18 = (void *)*plVar11;
        plVar11[1] = uVar12 + lVar14;
        uVar23 = (uVar12 + lVar14) - (long)pvVar18;
      }
    }
    else if (uVar12 < uVar23) {
      plVar11[1] = (long)pvVar18 + uVar12;
      uVar23 = ((long)pvVar18 + uVar12) - (long)pvVar18;
    }
    while( true ) {
      lVar14 = *(long *)(this + 0x68);
      *(int *)(lVar14 + 0x20) = (int)uVar23;
      *(void **)(lVar14 + 0x18) = pvVar18;
      iVar8 = deflate();
      if (iVar8 != 0) break;
      pvVar17 = (void *)plVar11[1];
      pvVar18 = (void *)*plVar11;
      uVar13 = (long)pvVar17 - (long)pvVar18;
      uVar12 = -(ulong)*(uint *)(*(long *)(this + 0x68) + 0x20) - 4;
      uVar23 = uVar13 + uVar12;
      if (uVar23 <= uVar13) {
        if (uVar23 < uVar13) {
          plVar11[1] = uVar23 + (long)pvVar18;
        }
        break;
      }
      if (uVar12 <= (ulong)(plVar11[2] - (long)pvVar17)) {
        memset(pvVar17,0,uVar12);
        plVar11[1] = plVar11[1] + uVar12;
        break;
      }
      if (uVar12 <= ~uVar13) {
        uStack_68 = 0xffffffffffffffff;
        uVar23 = uVar12;
        if (uVar12 <= uVar13) {
          uVar23 = uVar13;
        }
        if ((CARRY8(uVar23,uVar13)) || (uStack_68 = uVar23 + uVar13, uVar23 + uVar13 != 0)) {
          pvVar17 = operator_new(uStack_68);
          pvVar18 = (void *)*plVar11;
          uVar13 = plVar11[1] - (long)pvVar18;
        }
        else {
          uStack_68 = 0;
          pvVar17 = (void *)0x0;
        }
        if (uVar13 != 0) {
          memmove(pvVar17,pvVar18,uVar13);
        }
        pvVar18 = (void *)((long)pvVar17 + uVar13);
        memset(pvVar18,0,(uVar12 + (long)pvVar18) - (long)pvVar18);
        if ((void *)*plVar11 != (void *)0x0) {
          operator_delete((void *)*plVar11);
        }
        *plVar11 = (long)pvVar17;
        plVar11[1] = uVar12 + (long)pvVar18;
        plVar11[2] = (long)pvVar17 + uStack_68;
        break;
      }
      uVar19 = std::__throw_length_error("vector::_M_default_append");
LAB_00115565:
      pvStack_60 = operator_new(uVar19);
      uVar23 = plVar11[1] - *plVar11;
      pvVar17 = (void *)*plVar11;
LAB_00115583:
      pvVar18 = pvStack_60;
      if (uVar23 != 0) {
        pvVar18 = memmove(pvStack_60,pvVar17,uVar23);
      }
      pvVar17 = (void *)((long)pvVar18 + uVar23);
      lVar14 = uVar12 + (long)pvVar17;
      memset(pvVar17,0,lVar14 - (long)pvVar17);
      if ((void *)*plVar11 != (void *)0x0) {
        operator_delete((void *)*plVar11);
      }
      *plVar11 = (long)pvVar18;
      plVar11[1] = lVar14;
      plVar11[2] = uVar19 + (long)pvVar18;
      uVar23 = lVar14 - (long)pvStack_60;
    }
    uStack_58 = CONCAT71(uStack_58._1_7_,0xc1);
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
               (uchar *)&uStack_58);
    puVar3 = (undefined8 *)*param_2;
    *param_2 = (long)plVar11;
    if (puVar3 == (undefined8 *)0x0) goto LAB_0011535a;
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete((void *)*puVar3);
    }
    operator_delete(puVar3);
    uVar12 = ((long *)*param_2)[1] - *(long *)*param_2;
  }
  if (0x7d < uVar12) {
    uStack_58._1_7_ = (undefined7)((ulong)uStack_58 >> 8);
    if (uVar12 < 0xffff) {
      uStack_58._0_1_ = '~';
    }
    else {
      uStack_58._0_1_ = '\x7f';
      std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
                (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
                 (uchar *)&uStack_58);
      uStack_58._0_1_ = '\0';
      std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
                (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
                 (uchar *)&uStack_58);
      uStack_58._0_1_ = '\0';
      std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
                (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
                 (uchar *)&uStack_58);
      uStack_58._0_1_ = '\0';
      std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
                (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
                 (uchar *)&uStack_58);
      uStack_58._0_1_ = '\0';
      std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
                (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
                 (uchar *)&uStack_58);
      uStack_58._0_1_ = (uchar)(uVar12 >> 0x18);
      std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
                (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
                 (uchar *)&uStack_58);
      uStack_58._0_1_ = (uchar)(uVar12 >> 0x10);
    }
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
               (uchar *)&uStack_58);
    uStack_58 = CONCAT71(uStack_58._1_7_,(char)(uVar12 >> 8));
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
               (uchar *)&uStack_58);
  }
  uStack_58 = CONCAT71(uStack_58._1_7_,(char)uVar12);
  std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
            (*(vector<unsigned_char,std::allocator<unsigned_char>> **)(this + 0x50),
             (uchar *)&uStack_58);
  std::vector<unsigned_char,std::allocator<unsigned_char>>::
  _M_range_insert<__gnu_cxx::__normal_iterator<unsigned_char*,std::vector<unsigned_char,std::allocator<unsigned_char>>>>
            (*(long *)(this + 0x50),*(undefined8 *)(*(long *)(this + 0x50) + 8),*(long *)*param_2,
             *(long *)*param_2 + uVar12);
  uVar20 = *(undefined8 *)(this + 0x50);
  *(undefined8 *)(this + 0x50) = 0;
  lVar14 = *(long *)(this + 0x38);
  if (*(char *)(lVar14 + 0x5a) != '\0') {
    fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  puVar3 = *(undefined8 **)(lVar14 + 0x60);
  *(undefined1 *)(lVar14 + 0x5a) = 1;
  *(undefined8 *)(lVar14 + 0x60) = uVar20;
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      operator_delete((void *)*puVar3);
    }
    operator_delete(puVar3);
  }
  pcStack_48 = (code *)0x0;
  if (*(code **)(param_3 + 0x10) == (code *)0x0) {
    uVar20 = 0;
  }
  else {
    (**(code **)(param_3 + 0x10))(&uStack_58,param_3,2);
    uStack_40 = *(undefined8 *)(param_3 + 0x18);
    uVar20 = *(undefined8 *)(param_3 + 0x10);
  }
  uVar4 = *(undefined8 *)(lVar14 + 0x68);
  uVar5 = *(undefined8 *)(lVar14 + 0x70);
  pcStack_48 = *(code **)(lVar14 + 0x78);
  *(undefined8 *)(lVar14 + 0x68) = uStack_58;
  *(undefined8 *)(lVar14 + 0x70) = uStack_50;
  uVar6 = *(undefined8 *)(lVar14 + 0x80);
  *(undefined8 *)(lVar14 + 0x78) = uVar20;
  *(undefined8 *)(lVar14 + 0x80) = uStack_40;
  uStack_58 = uVar4;
  uStack_50 = uVar5;
  uStack_40 = uVar6;
  if (pcStack_48 != (code *)0x0) {
    (*pcStack_48)(&uStack_58,&uStack_58,3);
  }
  lVar25 = *(long *)(lVar14 + 0x38);
  iVar8 = *(int *)(lVar14 + 0x40);
  cVar2 = *(char *)(lVar14 + 0x5a);
  p_Var26 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  uStack_58 = CONCAT44(uStack_58._4_4_,iVar8);
  p_Var15 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  p_Var16 = p_Var26;
  p_Var21 = p_Var15;
  if (p_Var26 == (_Rb_tree_node_base *)0x0) {
LAB_001154b0:
    lVar14 = 0;
    uVar27 = 0;
  }
  else {
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < iVar8) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001150cb;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001150cb:
    if ((p_Var15 == p_Var22) || (p_Var16 = p_Var15, iVar8 < *(int *)(p_Var22 + 0x20)))
    goto LAB_001154b0;
    do {
      while (p_Var21 = p_Var26, *(int *)(p_Var21 + 0x20) < iVar8) {
        p_Var22 = p_Var21 + 0x18;
        p_Var26 = *(_Rb_tree_node_base **)p_Var22;
        p_Var21 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_00115103;
      }
      p_Var26 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
      p_Var16 = p_Var21;
    } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115103:
    if ((p_Var15 == p_Var21) || (iVar8 < *(int *)(p_Var21 + 0x20))) {
      p_Var26 = operator_new(0x28);
      if (p_Var26 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var26 = 0;
        *(undefined8 *)(p_Var26 + 8) = 0;
        *(undefined8 *)(p_Var26 + 0x10) = 0;
        *(undefined8 *)(p_Var26 + 0x18) = 0;
        *(undefined4 *)(p_Var26 + 0x24) = 0;
        *(int *)(p_Var26 + 0x20) = (int)uStack_58;
      }
      auVar28 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar25 + 8),p_Var21,p_Var26 + 0x20);
      p_Var16 = auVar28._8_8_;
      p_Var21 = auVar28._0_8_;
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var26);
      }
      else {
        bVar24 = true;
        if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var16)) {
          bVar24 = *(int *)(p_Var26 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar24,p_Var26,p_Var16,p_Var15);
        *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
        p_Var21 = p_Var26;
      }
    }
    uVar27 = *(uint *)(p_Var21 + 0x24);
    lVar14 = 1;
  }
  lVar25 = lVar25 + (lVar14 + 1) * 0x30;
  this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
             *)(lVar25 + 8);
  p_Var15 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
  p_Var26 = (_Rb_tree_node_base *)(lVar25 + 0x10);
  uVar9 = uVar27;
  if (p_Var15 != (_Rb_tree_node_base *)0x0) {
    p_Var16 = p_Var15;
    p_Var21 = p_Var26;
    do {
      while (p_Var22 = p_Var16, *(int *)(p_Var22 + 0x20) < (int)uStack_58) {
        p_Var1 = p_Var22 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var1;
        p_Var22 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00115173;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
      p_Var21 = p_Var22;
    } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115173:
    if ((p_Var26 != p_Var22) && (p_Var16 = p_Var26, *(int *)(p_Var22 + 0x20) <= (int)uStack_58)) {
      do {
        while (p_Var21 = p_Var15, *(int *)(p_Var21 + 0x20) < (int)uStack_58) {
          p_Var22 = p_Var21 + 0x18;
          p_Var15 = *(_Rb_tree_node_base **)p_Var22;
          p_Var21 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_001151ab;
        }
        p_Var15 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
        p_Var16 = p_Var21;
      } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001151ab:
      if ((p_Var26 == p_Var21) || ((int)uStack_58 < *(int *)(p_Var21 + 0x20))) {
        p_Var15 = operator_new(0x28);
        if (p_Var15 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var15 = 0;
          *(undefined8 *)(p_Var15 + 8) = 0;
          *(undefined8 *)(p_Var15 + 0x10) = 0;
          *(undefined8 *)(p_Var15 + 0x18) = 0;
          *(undefined4 *)(p_Var15 + 0x24) = 0;
          *(int *)(p_Var15 + 0x20) = (int)uStack_58;
        }
        auVar28 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(this_00,p_Var21,p_Var15 + 0x20);
        p_Var16 = auVar28._8_8_;
        p_Var21 = auVar28._0_8_;
        if (p_Var16 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var15);
        }
        else {
          bVar24 = true;
          if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var26 != p_Var16)) {
            bVar24 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var16 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar24,p_Var15,p_Var16,p_Var26);
          *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
          p_Var21 = p_Var15;
        }
      }
      uVar9 = *(uint *)(p_Var21 + 0x24);
    }
  }
  uVar7 = uVar9 | 2;
  if (cVar2 == '\0') {
    uVar7 = uVar9 & 0xfffffffd;
  }
  if (uVar27 == uVar7) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(this_00,(int *)&uStack_58);
    return;
  }
  p_Var15 = p_Var26;
  if (*(_Rb_tree_node_base **)(lVar25 + 0x18) != (_Rb_tree_node_base *)0x0) {
    p_Var16 = *(_Rb_tree_node_base **)(lVar25 + 0x18);
    p_Var21 = p_Var26;
    do {
      while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < (int)uStack_58) {
        p_Var22 = p_Var15 + 0x18;
        p_Var16 = *(_Rb_tree_node_base **)p_Var22;
        p_Var15 = p_Var21;
        if (*(_Rb_tree_node_base **)p_Var22 == (_Rb_tree_node_base *)0x0) goto LAB_00115282;
      }
      p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
      p_Var21 = p_Var15;
    } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00115282:
    if ((p_Var26 != p_Var15) && (*(int *)(p_Var15 + 0x20) <= (int)uStack_58)) goto LAB_00115325;
  }
  p_Var16 = operator_new(0x28);
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var16 = 0;
    *(undefined8 *)(p_Var16 + 8) = 0;
    *(undefined8 *)(p_Var16 + 0x10) = 0;
    *(undefined8 *)(p_Var16 + 0x18) = 0;
    *(undefined4 *)(p_Var16 + 0x24) = 0;
    *(int *)(p_Var16 + 0x20) = (int)uStack_58;
  }
  auVar28 = std::
            _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            ::_M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var16 + 0x20);
  p_Var21 = auVar28._8_8_;
  p_Var15 = auVar28._0_8_;
  if (p_Var21 == (_Rb_tree_node_base *)0x0) {
    operator_delete(p_Var16);
  }
  else {
    bVar24 = true;
    if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var26 != p_Var21)) {
      bVar24 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var21 + 0x20);
    }
    std::_Rb_tree_insert_and_rebalance(bVar24,p_Var16,p_Var21,p_Var26);
    *(long *)(lVar25 + 0x30) = *(long *)(lVar25 + 0x30) + 1;
    p_Var15 = p_Var16;
  }
LAB_00115325:
  *(uint *)(p_Var15 + 0x24) = uVar7;
  return;
}



