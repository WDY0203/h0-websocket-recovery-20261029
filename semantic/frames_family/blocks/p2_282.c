
/* TcpConn::send_proc() */

void __thiscall TcpConn::send_proc(TcpConn *this)

{
  _Rb_tree_node_base *p_Var1;
  void *__src;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *p_Var2;
  undefined8 *puVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  ssize_t sVar10;
  long lVar11;
  _Rb_tree_node_base *p_Var12;
  void *__dest;
  int *piVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  bool bVar17;
  long lVar18;
  _Rb_tree_node_base *p_Var19;
  uint uVar20;
  undefined1 auVar21 [16];
  int local_78 [4];
  int local_68 [4];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  
  if (this[0x5a] == (TcpConn)0x0) {
    fprintf(*(FILE **)PTR_stderr_00324fb0,"TcpConn: bogus send: fd=%d\n",
            (ulong)*(uint *)(this + 0x40));
    return;
  }
  puVar3 = *(undefined8 **)(this + 0x60);
  if (puVar3 == (undefined8 *)0x0) {
    this[0x59] = (TcpConn)0x0;
    shutdown(*(int *)(this + 0x40),1);
    lVar18 = *(long *)(this + 0x38);
    local_68[0] = *(int *)(this + 0x40);
    this[0x5a] = (TcpConn)0x0;
    p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var16 = p_Var14;
    p_Var19 = p_Var12;
    if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0011b430:
      lVar11 = 0;
      uVar20 = 0;
    }
    else {
      do {
        while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < local_68[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var19;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011b17b;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var19 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011b17b:
      if ((p_Var12 == p_Var15) || (p_Var16 = p_Var12, local_68[0] < *(int *)(p_Var15 + 0x20)))
      goto LAB_0011b430;
      do {
        if (*(int *)(p_Var14 + 0x20) < local_68[0]) {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
        }
        else {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
          p_Var16 = p_Var14;
        }
        p_Var14 = p_Var19;
      } while (p_Var19 != (_Rb_tree_node_base *)0x0);
      if ((p_Var12 == p_Var16) || (local_68[0] < *(int *)(p_Var16 + 0x20))) {
        p_Var14 = operator_new(0x28);
        if (p_Var14 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_68[0];
        }
        auVar21 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos
                            ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                              *)(lVar18 + 8),p_Var16,p_Var14 + 0x20);
        p_Var19 = auVar21._8_8_;
        p_Var16 = auVar21._0_8_;
        if (p_Var19 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var14);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var19)) {
            bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var19,p_Var12);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var16 = p_Var14;
        }
      }
      uVar20 = *(uint *)(p_Var16 + 0x24);
      lVar11 = 1;
    }
    lVar18 = lVar18 + (lVar11 + 1) * 0x30;
    p_Var2 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(lVar18 + 8);
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var14 = p_Var12;
    p_Var16 = p_Var19;
    uVar9 = uVar20;
    if (p_Var12 != (_Rb_tree_node_base *)0x0) {
      do {
        while (p_Var15 = p_Var14, *(int *)(p_Var15 + 0x20) < local_68[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011b21b;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var16 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011b21b:
      if ((p_Var19 != p_Var15) && (p_Var14 = p_Var19, *(int *)(p_Var15 + 0x20) <= local_68[0])) {
        do {
          if (*(int *)(p_Var12 + 0x20) < local_68[0]) {
            p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
          }
          else {
            p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
            p_Var14 = p_Var12;
          }
          p_Var12 = p_Var16;
        } while (p_Var16 != (_Rb_tree_node_base *)0x0);
        if ((p_Var19 == p_Var14) || (local_68[0] < *(int *)(p_Var14 + 0x20))) {
          p_Var12 = operator_new(0x28);
          if (p_Var12 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var12 = 0;
            *(undefined8 *)(p_Var12 + 8) = 0;
            *(undefined8 *)(p_Var12 + 0x10) = 0;
            *(undefined8 *)(p_Var12 + 0x18) = 0;
            *(undefined4 *)(p_Var12 + 0x24) = 0;
            *(int *)(p_Var12 + 0x20) = local_68[0];
          }
          auVar21 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20);
          p_Var16 = auVar21._8_8_;
          p_Var14 = auVar21._0_8_;
          if (p_Var16 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var12);
          }
          else {
            bVar17 = true;
            if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var16)) {
              bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
            *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
            p_Var14 = p_Var12;
          }
        }
        uVar9 = *(uint *)(p_Var14 + 0x24);
      }
    }
    if ((uVar9 & 0xfffffffd) == uVar20) {
      std::
      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
      ::erase(p_Var2,local_68);
      goto LAB_0011b3a6;
    }
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var14 = p_Var19;
    if (p_Var12 == (_Rb_tree_node_base *)0x0) {
LAB_0011b32a:
      p_Var12 = operator_new(0x28);
      if (p_Var12 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_68[0];
      }
      auVar21 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20);
      p_Var16 = auVar21._8_8_;
      p_Var14 = auVar21._0_8_;
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var12);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var16)) {
          bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var14 = p_Var12;
      }
    }
    else {
      do {
        if (*(int *)(p_Var12 + 0x20) < local_68[0]) {
          p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
        }
        else {
          p_Var16 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var14 = p_Var12;
        }
        p_Var12 = p_Var16;
      } while (p_Var16 != (_Rb_tree_node_base *)0x0);
      if ((p_Var19 == p_Var14) || (local_68[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0011b32a;
    }
    *(uint *)(p_Var14 + 0x24) = uVar9 & 0xfffffffd;
LAB_0011b3a6:
    uVar5 = *(undefined8 *)(this + 0x70);
    uVar6 = *(undefined8 *)(this + 0x68);
    *(undefined8 *)(this + 0x70) = local_50;
    local_48 = *(code **)(this + 0x78);
    *(undefined8 *)(this + 0x68) = local_58;
    pcVar7 = *(code **)(this + 0x80);
    *(undefined8 *)(this + 0x78) = 0;
    *(code **)(this + 0x80) = local_40;
    local_58 = uVar6;
    local_50 = uVar5;
    local_40 = pcVar7;
    if (local_48 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*pcVar7)(&local_58);
    if (local_48 == (code *)0x0) {
      return;
    }
    (*local_48)(&local_58,&local_58,3);
    return;
  }
  sVar10 = write(*(int *)(this + 0x40),(void *)*puVar3,puVar3[1] - (long)*puVar3);
  iVar8 = (int)sVar10;
  if (iVar8 == -1) {
    piVar13 = __errno_location();
    if (*piVar13 == 0xb) {
      return;
    }
  }
  else if (-1 < iVar8) {
    puVar3 = *(undefined8 **)(this + 0x60);
    pvVar4 = (void *)puVar3[1];
    __dest = (void *)*puVar3;
    if ((ulong)(long)iVar8 < (ulong)((long)pvVar4 - (long)__dest)) {
      __src = (void *)((long)__dest + (long)iVar8);
      if (__dest == __src) {
        return;
      }
      lVar18 = 0;
      if ((pvVar4 != __src) && ((long)pvVar4 - (long)__src != 0)) {
        __dest = memmove(__dest,__src,(long)pvVar4 - (long)__src);
        lVar18 = puVar3[1] - (long)__src;
      }
      puVar3[1] = lVar18 + (long)__dest;
      return;
    }
    lVar18 = *(long *)(this + 0x38);
    local_78[0] = *(int *)(this + 0x40);
    this[0x5a] = (TcpConn)0x0;
    p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var16 = p_Var14;
    p_Var19 = p_Var12;
    if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0011acc9:
      lVar11 = 0;
      uVar20 = 0;
    }
    else {
      do {
        while (p_Var15 = p_Var16, *(int *)(p_Var15 + 0x20) < local_78[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var16 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var19;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011acbb;
        }
        p_Var16 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var19 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011acbb:
      if ((p_Var12 == p_Var15) || (p_Var16 = p_Var12, local_78[0] < *(int *)(p_Var15 + 0x20)))
      goto LAB_0011acc9;
      do {
        while (p_Var19 = p_Var14, *(int *)(p_Var19 + 0x20) < local_78[0]) {
          p_Var15 = p_Var19 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var15;
          p_Var19 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var15 == (_Rb_tree_node_base *)0x0) goto LAB_0011aceb;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var16 = p_Var19;
      } while (*(_Rb_tree_node_base **)(p_Var19 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011aceb:
      if ((p_Var12 == p_Var19) || (local_78[0] < *(int *)(p_Var19 + 0x20))) {
        p_Var14 = operator_new(0x28);
        if (p_Var14 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = local_78[0];
        }
        auVar21 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos
                            ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                              *)(lVar18 + 8),p_Var19,p_Var14 + 0x20);
        p_Var16 = auVar21._8_8_;
        p_Var19 = auVar21._0_8_;
        if (p_Var16 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var14);
        }
        else {
          bVar17 = true;
          if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var16)) {
            bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var16 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var16,p_Var12);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var19 = p_Var14;
        }
      }
      uVar20 = *(uint *)(p_Var19 + 0x24);
      lVar11 = 1;
    }
    lVar18 = lVar18 + (lVar11 + 1) * 0x30;
    p_Var2 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(lVar18 + 8);
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
    p_Var14 = p_Var12;
    p_Var16 = p_Var19;
    uVar9 = uVar20;
    if (p_Var12 != (_Rb_tree_node_base *)0x0) {
      do {
        while (p_Var15 = p_Var14, *(int *)(p_Var15 + 0x20) < local_78[0]) {
          p_Var1 = p_Var15 + 0x18;
          p_Var14 = *(_Rb_tree_node_base **)p_Var1;
          p_Var15 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011ad5b;
        }
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var16 = p_Var15;
      } while (*(_Rb_tree_node_base **)(p_Var15 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011ad5b:
      if ((p_Var19 != p_Var15) && (p_Var14 = p_Var19, *(int *)(p_Var15 + 0x20) <= local_78[0])) {
        do {
          while (p_Var16 = p_Var12, *(int *)(p_Var16 + 0x20) < local_78[0]) {
            p_Var15 = p_Var16 + 0x18;
            p_Var12 = *(_Rb_tree_node_base **)p_Var15;
            p_Var16 = p_Var14;
            if (*(_Rb_tree_node_base **)p_Var15 == (_Rb_tree_node_base *)0x0) goto LAB_0011af4b;
          }
          p_Var12 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
          p_Var14 = p_Var16;
        } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011af4b:
        if ((p_Var19 == p_Var16) || (local_78[0] < *(int *)(p_Var16 + 0x20))) {
          p_Var12 = operator_new(0x28);
          if (p_Var12 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var12 = 0;
            *(undefined8 *)(p_Var12 + 8) = 0;
            *(undefined8 *)(p_Var12 + 0x10) = 0;
            *(undefined8 *)(p_Var12 + 0x18) = 0;
            *(undefined4 *)(p_Var12 + 0x24) = 0;
            *(int *)(p_Var12 + 0x20) = local_78[0];
          }
          auVar21 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos(p_Var2,p_Var16,p_Var12 + 0x20);
          p_Var14 = auVar21._8_8_;
          p_Var16 = auVar21._0_8_;
          if (p_Var14 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var12);
          }
          else {
            bVar17 = true;
            if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var14)) {
              bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var14 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var14,p_Var19);
            *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
            p_Var16 = p_Var12;
          }
        }
        uVar9 = *(uint *)(p_Var16 + 0x24);
      }
    }
    if ((uVar9 & 0xfffffffd) == uVar20) {
      std::
      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
      ::erase(p_Var2,local_78);
      goto LAB_0011ae38;
    }
    p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    p_Var16 = p_Var19;
    p_Var14 = p_Var19;
    if (*(_Rb_tree_node_base **)(lVar18 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0011adbc:
      p_Var12 = operator_new(0x28);
      if (p_Var12 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var12 = 0;
        *(undefined8 *)(p_Var12 + 8) = 0;
        *(undefined8 *)(p_Var12 + 0x10) = 0;
        *(undefined8 *)(p_Var12 + 0x18) = 0;
        *(undefined4 *)(p_Var12 + 0x24) = 0;
        *(int *)(p_Var12 + 0x20) = local_78[0];
      }
      auVar21 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos(p_Var2,p_Var14,p_Var12 + 0x20);
      p_Var16 = auVar21._8_8_;
      p_Var14 = auVar21._0_8_;
      if (p_Var16 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var12);
      }
      else {
        bVar17 = true;
        if ((p_Var14 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var16)) {
          bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var16 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var16,p_Var19);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var14 = p_Var12;
      }
    }
    else {
      do {
        while (p_Var14 = p_Var12, *(int *)(p_Var14 + 0x20) < local_78[0]) {
          p_Var15 = p_Var14 + 0x18;
          p_Var12 = *(_Rb_tree_node_base **)p_Var15;
          p_Var14 = p_Var16;
          if (*(_Rb_tree_node_base **)p_Var15 == (_Rb_tree_node_base *)0x0) goto LAB_0011adb2;
        }
        p_Var12 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
        p_Var16 = p_Var14;
      } while (*(_Rb_tree_node_base **)(p_Var14 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011adb2:
      if ((p_Var19 == p_Var14) || (local_78[0] < *(int *)(p_Var14 + 0x20))) goto LAB_0011adbc;
    }
    *(uint *)(p_Var14 + 0x24) = uVar9 & 0xfffffffd;
LAB_0011ae38:
    puVar3 = *(undefined8 **)(this + 0x60);
    *(undefined8 *)(this + 0x60) = 0;
    if (puVar3 != (undefined8 *)0x0) {
      if ((void *)*puVar3 != (void *)0x0) {
        operator_delete((void *)*puVar3);
      }
      operator_delete(puVar3);
    }
    uVar5 = *(undefined8 *)(this + 0x70);
    uVar6 = *(undefined8 *)(this + 0x68);
    *(undefined8 *)(this + 0x70) = local_50;
    local_48 = *(code **)(this + 0x78);
    *(undefined8 *)(this + 0x68) = local_58;
    pcVar7 = *(code **)(this + 0x80);
    *(undefined8 *)(this + 0x78) = 0;
    *(code **)(this + 0x80) = local_40;
    local_58 = uVar6;
    local_50 = uVar5;
    local_40 = pcVar7;
    if (local_48 != (code *)0x0) {
      (*pcVar7)(&local_58);
      if (local_48 == (code *)0x0) {
        return;
      }
      (*local_48)(&local_58,&local_58,3);
      return;
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_function_call();
  }
  perror("tcp send");
  lVar18 = *(long *)(this + 0x38);
  iVar8 = *(int *)(this + 0x40);
  this[0x58] = (TcpConn)0x0;
  this[0x59] = (TcpConn)0x0;
  this[0x5a] = (TcpConn)0x0;
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  local_58 = CONCAT44(local_58._4_4_,iVar8);
  p_Var12 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var16 = p_Var14;
  p_Var19 = p_Var12;
  if (p_Var14 == (_Rb_tree_node_base *)0x0) {
LAB_0011b44e:
    lVar11 = 0;
    uVar20 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var16 + 0x20) < iVar8) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var19 = p_Var16;
      }
      p_Var16 = p_Var15;
    } while (p_Var15 != (_Rb_tree_node_base *)0x0);
    if ((p_Var12 == p_Var19) || (p_Var16 = p_Var12, iVar8 < *(int *)(p_Var19 + 0x20)))
    goto LAB_0011b44e;
    do {
      if (*(int *)(p_Var14 + 0x20) < iVar8) {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
      }
      else {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
        p_Var16 = p_Var14;
      }
      p_Var14 = p_Var19;
    } while (p_Var19 != (_Rb_tree_node_base *)0x0);
    if ((p_Var12 == p_Var16) || (iVar8 < *(int *)(p_Var16 + 0x20))) {
      p_Var14 = operator_new(0x28);
      if (p_Var14 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var14 = 0;
        *(undefined8 *)(p_Var14 + 8) = 0;
        *(undefined8 *)(p_Var14 + 0x10) = 0;
        *(undefined8 *)(p_Var14 + 0x18) = 0;
        *(undefined4 *)(p_Var14 + 0x24) = 0;
        *(int *)(p_Var14 + 0x20) = (int)local_58;
      }
      auVar21 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar18 + 8),p_Var16,p_Var14 + 0x20);
      p_Var19 = auVar21._8_8_;
      p_Var16 = auVar21._0_8_;
      if (p_Var19 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var14);
      }
      else {
        bVar17 = true;
        if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var12 != p_Var19)) {
          bVar17 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var19 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar17,p_Var14,p_Var19,p_Var12);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var16 = p_Var14;
      }
    }
    uVar20 = *(uint *)(p_Var16 + 0x24);
    lVar11 = 1;
  }
  lVar18 = lVar18 + (lVar11 + 1) * 0x30;
  p_Var2 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(lVar18 + 8);
  p_Var12 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  uVar9 = uVar20;
  if (p_Var12 != (_Rb_tree_node_base *)0x0) {
    p_Var16 = p_Var12;
    p_Var19 = p_Var14;
    do {
      if (*(int *)(p_Var16 + 0x20) < (int)local_58) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var19 = p_Var16;
      }
      p_Var16 = p_Var15;
    } while (p_Var15 != (_Rb_tree_node_base *)0x0);
    if ((p_Var14 != p_Var19) && (p_Var16 = p_Var14, *(int *)(p_Var19 + 0x20) <= (int)local_58)) {
      do {
        if (*(int *)(p_Var12 + 0x20) < (int)local_58) {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var12 + 0x18);
        }
        else {
          p_Var19 = *(_Rb_tree_node_base **)(p_Var12 + 0x10);
          p_Var16 = p_Var12;
        }
        p_Var12 = p_Var19;
      } while (p_Var19 != (_Rb_tree_node_base *)0x0);
      if ((p_Var14 == p_Var16) || ((int)local_58 < *(int *)(p_Var16 + 0x20))) {
        p_Var12 = operator_new(0x28);
        if (p_Var12 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var12 = 0;
          *(undefined8 *)(p_Var12 + 8) = 0;
          *(undefined8 *)(p_Var12 + 0x10) = 0;
          *(undefined8 *)(p_Var12 + 0x18) = 0;
          *(undefined4 *)(p_Var12 + 0x24) = 0;
          *(int *)(p_Var12 + 0x20) = (int)local_58;
        }
        auVar21 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var2,p_Var16,p_Var12 + 0x20);
        p_Var19 = auVar21._8_8_;
        p_Var16 = auVar21._0_8_;
        if (p_Var19 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var12);
        }
        else {
          bVar17 = true;
          if ((p_Var16 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var19)) {
            bVar17 = *(int *)(p_Var12 + 0x20) < *(int *)(p_Var19 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar17,p_Var12,p_Var19,p_Var14);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var16 = p_Var12;
        }
      }
      uVar9 = *(uint *)(p_Var16 + 0x24);
    }
  }
  if ((uVar9 & 0xfffffffd) == uVar20) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(p_Var2,(int *)&local_58);
    return;
  }
  p_Var12 = p_Var14;
  if (*(_Rb_tree_node_base **)(lVar18 + 0x18) != (_Rb_tree_node_base *)0x0) {
    p_Var16 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
    do {
      if (*(int *)(p_Var16 + 0x20) < (int)local_58) {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var16 + 0x18);
      }
      else {
        p_Var19 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
        p_Var12 = p_Var16;
      }
      p_Var16 = p_Var19;
    } while (p_Var19 != (_Rb_tree_node_base *)0x0);
    if ((p_Var14 != p_Var12) && (*(int *)(p_Var12 + 0x20) <= (int)local_58)) goto LAB_0011b77d;
  }
  p_Var16 = operator_new(0x28);
  if (p_Var16 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var16 = 0;
    *(undefined8 *)(p_Var16 + 8) = 0;
    *(undefined8 *)(p_Var16 + 0x10) = 0;
    *(undefined8 *)(p_Var16 + 0x18) = 0;
    *(undefined4 *)(p_Var16 + 0x24) = 0;
    *(int *)(p_Var16 + 0x20) = (int)local_58;
  }
  auVar21 = std::
            _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            ::_M_get_insert_hint_unique_pos(p_Var2,p_Var12,p_Var16 + 0x20);
  p_Var19 = auVar21._8_8_;
  p_Var12 = auVar21._0_8_;
  if (p_Var19 == (_Rb_tree_node_base *)0x0) {
    operator_delete(p_Var16);
  }
  else {
    bVar17 = true;
    if ((p_Var12 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var19)) {
      bVar17 = *(int *)(p_Var16 + 0x20) < *(int *)(p_Var19 + 0x20);
    }
    std::_Rb_tree_insert_and_rebalance(bVar17,p_Var16,p_Var19,p_Var14);
    *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
    p_Var12 = p_Var16;
  }
LAB_0011b77d:
  *(uint *)(p_Var12 + 0x24) = uVar9 & 0xfffffffd;
  return;
}



