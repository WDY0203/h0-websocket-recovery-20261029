
/* TcpConn::recv_proc() */

void __thiscall TcpConn::recv_proc(TcpConn *this)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *p_Var2;
  undefined8 uVar3;
  code *pcVar4;
  long *plVar5;
  int iVar6;
  long *plVar7;
  void *pvVar8;
  size_t sVar9;
  ssize_t sVar10;
  _Rb_tree_node_base *p_Var11;
  long lVar12;
  _Rb_tree_node_base *p_Var13;
  ulong uVar14;
  int *piVar15;
  ulong uVar16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  undefined8 uVar19;
  ulong __n;
  void *pvVar20;
  bool bVar21;
  long lVar22;
  _Rb_tree_node_base *p_Var23;
  uint uVar24;
  size_t __n_00;
  ulong uVar25;
  uint uVar26;
  undefined1 auVar27 [16];
  int local_88 [4];
  int local_78 [4];
  long *local_68 [2];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  code *local_40;
  
  if (this[0x88] == (TcpConn)0x0) {
    fprintf(*(FILE **)PTR_stderr_00324fb0,"TcpConn: bogus recv: fd=%d\n",
            (ulong)*(uint *)(this + 0x40));
    this[0x58] = (TcpConn)0x0;
    this[0x59] = (TcpConn)0x0;
    return;
  }
  plVar7 = operator_new(0x18);
  *plVar7 = 0;
  plVar7[1] = 0;
  plVar7[2] = 0;
  pvVar8 = operator_new(0x8000);
  __n_00 = plVar7[1] - *plVar7;
  sVar9 = 0;
  if (__n_00 != 0) {
    memmove(pvVar8,(void *)*plVar7,__n_00);
    sVar9 = __n_00;
  }
  memset((void *)((long)pvVar8 + sVar9),0,0x8000);
  if ((void *)*plVar7 != (void *)0x0) {
    operator_delete((void *)*plVar7);
  }
  iVar6 = *(int *)(this + 0x40);
  *plVar7 = (long)pvVar8;
  plVar7[1] = (long)((long)pvVar8 + sVar9) + 0x8000;
  plVar7[2] = (long)pvVar8 + 0x8000;
  sVar10 = read(iVar6,pvVar8,0x8000);
  iVar6 = (int)sVar10;
  if (iVar6 == -1) {
    piVar15 = __errno_location();
    if (*piVar15 == 0xb) goto LAB_001197ee;
  }
  else if (-1 < iVar6) {
    if (iVar6 != 0) {
      pvVar8 = (void *)plVar7[1];
      pvVar20 = (void *)*plVar7;
      uVar14 = (ulong)iVar6;
      __n = (long)pvVar8 - (long)pvVar20;
      if (__n < uVar14) {
        uVar14 = uVar14 - __n;
        if (uVar14 != 0) {
          if ((ulong)(plVar7[2] - (long)pvVar8) < uVar14) {
            if (~__n < uVar14) {
              uVar19 = std::__throw_length_error("vector::_M_default_append");
              FUN_00107834(plVar7);
              if (local_48 != (code *)0x0) {
                (*local_48)(&local_58,&local_58,3);
              }
                    /* WARNING: Subroutine does not return */
              _Unwind_Resume(uVar19);
            }
            uVar16 = __n;
            if (__n <= uVar14) {
              uVar16 = uVar14;
            }
            uVar25 = 0xffffffffffffffff;
            if ((CARRY8(uVar16,__n)) || (uVar25 = uVar16 + __n, uVar16 + __n != 0)) {
              pvVar8 = operator_new(uVar25);
              pvVar20 = (void *)*plVar7;
              __n = plVar7[1] - (long)pvVar20;
            }
            else {
              uVar25 = 0;
              pvVar8 = (void *)0x0;
            }
            if (__n != 0) {
              memmove(pvVar8,pvVar20,__n);
            }
            pvVar20 = (void *)((long)pvVar8 + __n);
            memset(pvVar20,0,(uVar14 + (long)pvVar20) - (long)pvVar20);
            if ((void *)*plVar7 != (void *)0x0) {
              operator_delete((void *)*plVar7);
            }
            *plVar7 = (long)pvVar8;
            plVar7[1] = uVar14 + (long)pvVar20;
            plVar7[2] = uVar25 + (long)pvVar8;
          }
          else {
            memset(pvVar8,0,uVar14);
            plVar7[1] = plVar7[1] + uVar14;
          }
        }
      }
      else if (uVar14 < __n) {
        plVar7[1] = uVar14 + (long)pvVar20;
      }
      lVar22 = *(long *)(this + 0x38);
      local_78[0] = *(int *)(this + 0x40);
      this[0x88] = (TcpConn)0x0;
      p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
      p_Var18 = p_Var11;
      p_Var23 = p_Var13;
      if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_00119ce0:
        lVar12 = 0;
        uVar24 = 0;
      }
      else {
        do {
          while (p_Var17 = p_Var18, *(int *)(p_Var17 + 0x20) < local_78[0]) {
            p_Var1 = p_Var17 + 0x18;
            p_Var18 = *(_Rb_tree_node_base **)p_Var1;
            p_Var17 = p_Var23;
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001198da;
          }
          p_Var18 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var23 = p_Var17;
        } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001198da:
        if ((p_Var13 == p_Var17) || (p_Var18 = p_Var13, local_78[0] < *(int *)(p_Var17 + 0x20)))
        goto LAB_00119ce0;
        do {
          while (p_Var23 = p_Var11, *(int *)(p_Var23 + 0x20) < local_78[0]) {
            p_Var17 = p_Var23 + 0x18;
            p_Var11 = *(_Rb_tree_node_base **)p_Var17;
            p_Var23 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_0011990a;
          }
          p_Var11 = *(_Rb_tree_node_base **)(p_Var23 + 0x10);
          p_Var18 = p_Var23;
        } while (*(_Rb_tree_node_base **)(p_Var23 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011990a:
        if ((p_Var13 == p_Var23) || (local_78[0] < *(int *)(p_Var23 + 0x20))) {
          p_Var11 = operator_new(0x28);
          if (p_Var11 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var11 = 0;
            *(undefined8 *)(p_Var11 + 8) = 0;
            *(undefined8 *)(p_Var11 + 0x10) = 0;
            *(undefined8 *)(p_Var11 + 0x18) = 0;
            *(undefined4 *)(p_Var11 + 0x24) = 0;
            *(int *)(p_Var11 + 0x20) = local_78[0];
          }
          auVar27 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos
                              ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                                *)(lVar22 + 8),p_Var23,p_Var11 + 0x20);
          p_Var18 = auVar27._8_8_;
          p_Var23 = auVar27._0_8_;
          if (p_Var18 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var11);
          }
          else {
            bVar21 = true;
            if ((p_Var23 == (_Rb_tree_node_base *)0x0) && (p_Var13 != p_Var18)) {
              bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var18 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var18,p_Var13);
            *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
            p_Var23 = p_Var11;
          }
        }
        uVar24 = *(uint *)(p_Var23 + 0x24);
        lVar12 = 1;
      }
      lVar22 = lVar22 + (lVar12 + 1) * 0x30;
      p_Var2 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                *)(lVar22 + 8);
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var23 = (_Rb_tree_node_base *)(lVar22 + 0x10);
      p_Var11 = p_Var13;
      p_Var18 = p_Var23;
      uVar26 = uVar24;
      if (p_Var13 != (_Rb_tree_node_base *)0x0) {
        do {
          while (p_Var17 = p_Var11, *(int *)(p_Var17 + 0x20) < local_78[0]) {
            p_Var1 = p_Var17 + 0x18;
            p_Var11 = *(_Rb_tree_node_base **)p_Var1;
            p_Var17 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001199ea;
          }
          p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
          p_Var18 = p_Var17;
        } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001199ea:
        if ((p_Var23 != p_Var17) && (p_Var11 = p_Var23, *(int *)(p_Var17 + 0x20) <= local_78[0])) {
          do {
            while (p_Var18 = p_Var13, *(int *)(p_Var18 + 0x20) < local_78[0]) {
              p_Var17 = p_Var18 + 0x18;
              p_Var13 = *(_Rb_tree_node_base **)p_Var17;
              p_Var18 = p_Var11;
              if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_00119a1a;
            }
            p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
            p_Var11 = p_Var18;
          } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00119a1a:
          if ((p_Var23 == p_Var18) || (local_78[0] < *(int *)(p_Var18 + 0x20))) {
            p_Var13 = operator_new(0x28);
            if (p_Var13 != (_Rb_tree_node_base *)0x0) {
              *(undefined4 *)p_Var13 = 0;
              *(undefined8 *)(p_Var13 + 8) = 0;
              *(undefined8 *)(p_Var13 + 0x10) = 0;
              *(undefined8 *)(p_Var13 + 0x18) = 0;
              *(undefined4 *)(p_Var13 + 0x24) = 0;
              *(int *)(p_Var13 + 0x20) = local_78[0];
            }
            auVar27 = std::
                      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                      ::_M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20);
            p_Var11 = auVar27._8_8_;
            p_Var18 = auVar27._0_8_;
            if (p_Var11 == (_Rb_tree_node_base *)0x0) {
              operator_delete(p_Var13);
            }
            else {
              bVar21 = true;
              if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var11)) {
                bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var11 + 0x20);
              }
              std::_Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var11,p_Var23);
              *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
              p_Var18 = p_Var13;
            }
          }
          uVar26 = *(uint *)(p_Var18 + 0x24);
        }
      }
      if ((uVar26 & 0xfffffffe) == uVar24) {
        std::
        _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
        ::erase(p_Var2,local_78);
        goto LAB_00119b77;
      }
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var18 = p_Var23;
      p_Var11 = p_Var23;
      if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00119af5:
        p_Var13 = operator_new(0x28);
        if (p_Var13 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = local_78[0];
        }
        auVar27 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var2,p_Var11,p_Var13 + 0x20);
        p_Var18 = auVar27._8_8_;
        p_Var11 = auVar27._0_8_;
        if (p_Var18 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var11 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var18)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var18,p_Var23);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var11 = p_Var13;
        }
      }
      else {
        do {
          while (p_Var11 = p_Var13, *(int *)(p_Var11 + 0x20) < local_78[0]) {
            p_Var17 = p_Var11 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var11 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_00119aea;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
          p_Var18 = p_Var11;
        } while (*(_Rb_tree_node_base **)(p_Var11 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00119aea:
        if ((p_Var23 == p_Var11) || (local_78[0] < *(int *)(p_Var11 + 0x20))) goto LAB_00119af5;
      }
      *(uint *)(p_Var11 + 0x24) = uVar26 & 0xfffffffe;
LAB_00119b77:
      uVar19 = *(undefined8 *)(this + 0x98);
      uVar3 = *(undefined8 *)(this + 0x90);
      local_48 = *(code **)(this + 0xa0);
      pcVar4 = *(code **)(this + 0xa8);
      *(undefined8 *)(this + 0x90) = local_58;
      *(undefined8 *)(this + 0x98) = local_50;
      *(undefined8 *)(this + 0xa0) = 0;
      *(code **)(this + 0xa8) = local_40;
      local_58 = uVar3;
      local_50 = uVar19;
      local_40 = pcVar4;
      if (local_48 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_function_call();
      }
      local_68[0] = plVar7;
      (*pcVar4)(&local_58,local_68);
      plVar7 = local_68[0];
      if (local_68[0] != (long *)0x0) {
        if ((void *)*local_68[0] != (void *)0x0) {
          operator_delete((void *)*local_68[0]);
        }
        operator_delete(plVar7);
      }
      if (local_48 == (code *)0x0) {
        return;
      }
      (*local_48)(&local_58,&local_58,3);
      return;
    }
    lVar22 = *(long *)(this + 0x38);
    local_88[0] = *(int *)(this + 0x40);
    this[0x58] = (TcpConn)0x0;
    this[0x88] = (TcpConn)0x0;
    p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
    p_Var18 = p_Var11;
    p_Var23 = p_Var13;
    if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_00119cd0:
      lVar12 = 0;
      uVar24 = 0;
    }
    else {
      do {
        while (p_Var17 = p_Var18, *(int *)(p_Var17 + 0x20) < local_88[0]) {
          p_Var1 = p_Var17 + 0x18;
          p_Var18 = *(_Rb_tree_node_base **)p_Var1;
          p_Var17 = p_Var23;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011949a;
        }
        p_Var18 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var23 = p_Var17;
      } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011949a:
      if ((p_Var13 == p_Var17) || (p_Var18 = p_Var13, local_88[0] < *(int *)(p_Var17 + 0x20)))
      goto LAB_00119cd0;
      do {
        while (p_Var23 = p_Var11, *(int *)(p_Var23 + 0x20) < local_88[0]) {
          p_Var17 = p_Var23 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var17;
          p_Var23 = p_Var18;
          if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_001194ca;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var23 + 0x10);
        p_Var18 = p_Var23;
      } while (*(_Rb_tree_node_base **)(p_Var23 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001194ca:
      if ((p_Var13 == p_Var23) || (local_88[0] < *(int *)(p_Var23 + 0x20))) {
        p_Var11 = operator_new(0x28);
        if (p_Var11 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var11 = 0;
          *(undefined8 *)(p_Var11 + 8) = 0;
          *(undefined8 *)(p_Var11 + 0x10) = 0;
          *(undefined8 *)(p_Var11 + 0x18) = 0;
          *(undefined4 *)(p_Var11 + 0x24) = 0;
          *(int *)(p_Var11 + 0x20) = local_88[0];
        }
        auVar27 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos
                            ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                              *)(lVar22 + 8),p_Var23,p_Var11 + 0x20);
        p_Var18 = auVar27._8_8_;
        p_Var23 = auVar27._0_8_;
        if (p_Var18 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var11);
        }
        else {
          bVar21 = true;
          if ((p_Var23 == (_Rb_tree_node_base *)0x0) && (p_Var13 != p_Var18)) {
            bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var18,p_Var13);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var23 = p_Var11;
        }
      }
      uVar24 = *(uint *)(p_Var23 + 0x24);
      lVar12 = 1;
    }
    lVar22 = lVar22 + (lVar12 + 1) * 0x30;
    p_Var2 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(lVar22 + 8);
    p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    p_Var23 = (_Rb_tree_node_base *)(lVar22 + 0x10);
    p_Var11 = p_Var13;
    p_Var18 = p_Var23;
    uVar26 = uVar24;
    if (p_Var13 != (_Rb_tree_node_base *)0x0) {
      do {
        while (p_Var17 = p_Var11, *(int *)(p_Var17 + 0x20) < local_88[0]) {
          p_Var1 = p_Var17 + 0x18;
          p_Var11 = *(_Rb_tree_node_base **)p_Var1;
          p_Var17 = p_Var18;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001195aa;
        }
        p_Var11 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var18 = p_Var17;
      } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001195aa:
      if ((p_Var23 != p_Var17) && (p_Var11 = p_Var23, *(int *)(p_Var17 + 0x20) <= local_88[0])) {
        do {
          while (p_Var18 = p_Var13, *(int *)(p_Var18 + 0x20) < local_88[0]) {
            p_Var17 = p_Var18 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var18 = p_Var11;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_001195da;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
          p_Var11 = p_Var18;
        } while (*(_Rb_tree_node_base **)(p_Var18 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001195da:
        if ((p_Var23 == p_Var18) || (local_88[0] < *(int *)(p_Var18 + 0x20))) {
          p_Var13 = operator_new(0x28);
          if (p_Var13 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var13 = 0;
            *(undefined8 *)(p_Var13 + 8) = 0;
            *(undefined8 *)(p_Var13 + 0x10) = 0;
            *(undefined8 *)(p_Var13 + 0x18) = 0;
            *(undefined4 *)(p_Var13 + 0x24) = 0;
            *(int *)(p_Var13 + 0x20) = local_88[0];
          }
          auVar27 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20);
          p_Var11 = auVar27._8_8_;
          p_Var18 = auVar27._0_8_;
          if (p_Var11 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var13);
          }
          else {
            bVar21 = true;
            if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var11)) {
              bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var11 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var11,p_Var23);
            *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
            p_Var18 = p_Var13;
          }
        }
        uVar26 = *(uint *)(p_Var18 + 0x24);
      }
    }
    if ((uVar26 & 0xfffffffe) == uVar24) {
      std::
      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
      ::erase(p_Var2,local_88);
    }
    else {
      p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
      p_Var18 = p_Var23;
      p_Var11 = p_Var23;
      if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_001196b5:
        p_Var13 = operator_new(0x28);
        if (p_Var13 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = local_88[0];
        }
        auVar27 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var2,p_Var11,p_Var13 + 0x20);
        p_Var18 = auVar27._8_8_;
        p_Var11 = auVar27._0_8_;
        if (p_Var18 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var11 == (_Rb_tree_node_base *)0x0) && (p_Var23 != p_Var18)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var18 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var18,p_Var23);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var11 = p_Var13;
        }
      }
      else {
        do {
          while (p_Var11 = p_Var13, *(int *)(p_Var11 + 0x20) < local_88[0]) {
            p_Var17 = p_Var11 + 0x18;
            p_Var13 = *(_Rb_tree_node_base **)p_Var17;
            p_Var11 = p_Var18;
            if (*(_Rb_tree_node_base **)p_Var17 == (_Rb_tree_node_base *)0x0) goto LAB_001196aa;
          }
          p_Var13 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
          p_Var18 = p_Var11;
        } while (*(_Rb_tree_node_base **)(p_Var11 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001196aa:
        if ((p_Var23 == p_Var11) || (local_88[0] < *(int *)(p_Var11 + 0x20))) goto LAB_001196b5;
      }
      *(uint *)(p_Var11 + 0x24) = uVar26 & 0xfffffffe;
    }
    uVar19 = *(undefined8 *)(this + 0x98);
    uVar3 = *(undefined8 *)(this + 0x90);
    local_48 = *(code **)(this + 0xa0);
    pcVar4 = *(code **)(this + 0xa8);
    *(undefined8 *)(this + 0x90) = local_58;
    *(undefined8 *)(this + 0x98) = local_50;
    *(undefined8 *)(this + 0xa0) = 0;
    *(code **)(this + 0xa8) = local_40;
    local_58 = uVar3;
    local_50 = uVar19;
    local_40 = pcVar4;
    if (local_48 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    local_68[0] = (long *)0x0;
    (*pcVar4)(&local_58,local_68);
    plVar5 = local_68[0];
    if (local_68[0] != (long *)0x0) {
      if ((void *)*local_68[0] != (void *)0x0) {
        operator_delete((void *)*local_68[0]);
      }
      operator_delete(plVar5);
    }
    if (local_48 != (code *)0x0) {
      (*local_48)(&local_58,&local_58,3);
    }
    goto LAB_001197ee;
  }
  perror("tcp recv");
  iVar6 = *(int *)(this + 0x40);
  this[0x58] = (TcpConn)0x0;
  this[0x59] = (TcpConn)0x0;
  this[0x88] = (TcpConn)0x0;
  lVar22 = *(long *)(this + 0x38);
  local_58 = CONCAT44(local_58._4_4_,iVar6);
  p_Var11 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
  p_Var13 = (_Rb_tree_node_base *)(lVar22 + 0x10);
  p_Var18 = p_Var11;
  p_Var23 = p_Var13;
  if (p_Var11 == (_Rb_tree_node_base *)0x0) {
LAB_0011a090:
    lVar12 = 0;
    uVar24 = 0;
  }
  else {
    do {
      if (*(int *)(p_Var18 + 0x20) < iVar6) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var23 = p_Var18;
      }
      p_Var18 = p_Var17;
    } while (p_Var17 != (_Rb_tree_node_base *)0x0);
    if ((p_Var13 == p_Var23) || (p_Var18 = p_Var13, iVar6 < *(int *)(p_Var23 + 0x20)))
    goto LAB_0011a090;
    do {
      if (*(int *)(p_Var11 + 0x20) < iVar6) {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
      }
      else {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
        p_Var18 = p_Var11;
      }
      p_Var11 = p_Var23;
    } while (p_Var23 != (_Rb_tree_node_base *)0x0);
    if ((p_Var13 == p_Var18) || (iVar6 < *(int *)(p_Var18 + 0x20))) {
      p_Var11 = operator_new(0x28);
      if (p_Var11 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var11 = 0;
        *(undefined8 *)(p_Var11 + 8) = 0;
        *(undefined8 *)(p_Var11 + 0x10) = 0;
        *(undefined8 *)(p_Var11 + 0x18) = 0;
        *(undefined4 *)(p_Var11 + 0x24) = 0;
        *(int *)(p_Var11 + 0x20) = (int)local_58;
      }
      auVar27 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar22 + 8),p_Var18,p_Var11 + 0x20);
      p_Var23 = auVar27._8_8_;
      p_Var18 = auVar27._0_8_;
      if (p_Var23 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var11);
      }
      else {
        bVar21 = true;
        if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var13 != p_Var23)) {
          bVar21 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var23 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar21,p_Var11,p_Var23,p_Var13);
        *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
        p_Var18 = p_Var11;
      }
    }
    uVar24 = *(uint *)(p_Var18 + 0x24);
    lVar12 = 1;
  }
  lVar22 = lVar22 + (lVar12 + 1) * 0x30;
  p_Var2 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(lVar22 + 8);
  p_Var13 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
  p_Var11 = (_Rb_tree_node_base *)(lVar22 + 0x10);
  uVar26 = uVar24;
  if (p_Var13 != (_Rb_tree_node_base *)0x0) {
    p_Var18 = p_Var13;
    p_Var23 = p_Var11;
    do {
      if (*(int *)(p_Var18 + 0x20) < (int)local_58) {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var17 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var23 = p_Var18;
      }
      p_Var18 = p_Var17;
    } while (p_Var17 != (_Rb_tree_node_base *)0x0);
    if ((p_Var11 != p_Var23) && (p_Var18 = p_Var11, *(int *)(p_Var23 + 0x20) <= (int)local_58)) {
      do {
        if (*(int *)(p_Var13 + 0x20) < (int)local_58) {
          p_Var23 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
        }
        else {
          p_Var23 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
          p_Var18 = p_Var13;
        }
        p_Var13 = p_Var23;
      } while (p_Var23 != (_Rb_tree_node_base *)0x0);
      if ((p_Var11 == p_Var18) || ((int)local_58 < *(int *)(p_Var18 + 0x20))) {
        p_Var13 = operator_new(0x28);
        if (p_Var13 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var13 = 0;
          *(undefined8 *)(p_Var13 + 8) = 0;
          *(undefined8 *)(p_Var13 + 0x10) = 0;
          *(undefined8 *)(p_Var13 + 0x18) = 0;
          *(undefined4 *)(p_Var13 + 0x24) = 0;
          *(int *)(p_Var13 + 0x20) = (int)local_58;
        }
        auVar27 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var2,p_Var18,p_Var13 + 0x20);
        p_Var23 = auVar27._8_8_;
        p_Var18 = auVar27._0_8_;
        if (p_Var23 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var13);
        }
        else {
          bVar21 = true;
          if ((p_Var18 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var23)) {
            bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var23 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var23,p_Var11);
          *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
          p_Var18 = p_Var13;
        }
      }
      uVar26 = *(uint *)(p_Var18 + 0x24);
    }
  }
  if ((uVar26 & 0xfffffffe) == uVar24) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(p_Var2,(int *)&local_58);
    goto LAB_001197ee;
  }
  p_Var13 = p_Var11;
  if (*(_Rb_tree_node_base **)(lVar22 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00119ffb:
    p_Var18 = operator_new(0x28);
    if (p_Var18 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var18 = 0;
      *(undefined8 *)(p_Var18 + 8) = 0;
      *(undefined8 *)(p_Var18 + 0x10) = 0;
      *(undefined8 *)(p_Var18 + 0x18) = 0;
      *(undefined4 *)(p_Var18 + 0x24) = 0;
      *(int *)(p_Var18 + 0x20) = (int)local_58;
    }
    auVar27 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(p_Var2,p_Var13,p_Var18 + 0x20);
    p_Var23 = auVar27._8_8_;
    p_Var13 = auVar27._0_8_;
    if (p_Var23 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var18);
    }
    else {
      bVar21 = true;
      if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var11 != p_Var23)) {
        bVar21 = *(int *)(p_Var18 + 0x20) < *(int *)(p_Var23 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar21,p_Var18,p_Var23,p_Var11);
      *(long *)(lVar22 + 0x30) = *(long *)(lVar22 + 0x30) + 1;
      p_Var13 = p_Var18;
    }
  }
  else {
    p_Var18 = *(_Rb_tree_node_base **)(lVar22 + 0x18);
    do {
      if (*(int *)(p_Var18 + 0x20) < (int)local_58) {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var18 + 0x18);
      }
      else {
        p_Var23 = *(_Rb_tree_node_base **)(p_Var18 + 0x10);
        p_Var13 = p_Var18;
      }
      p_Var18 = p_Var23;
    } while (p_Var23 != (_Rb_tree_node_base *)0x0);
    if ((p_Var11 == p_Var13) || ((int)local_58 < *(int *)(p_Var13 + 0x20))) goto LAB_00119ffb;
  }
  *(uint *)(p_Var13 + 0x24) = uVar26 & 0xfffffffe;
LAB_001197ee:
  if ((void *)*plVar7 != (void *)0x0) {
    operator_delete((void *)*plVar7);
  }
  operator_delete(plVar7);
  return;
}



