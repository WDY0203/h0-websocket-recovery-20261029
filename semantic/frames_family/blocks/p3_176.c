
undefined8 FUN_00109f70(undefined8 param_1,undefined8 param_2)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this;
  allocator *paVar2;
  int *piVar3;
  EventLoop2 *pEVar4;
  char cVar5;
  uint uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  EventLoop2 *pEVar9;
  undefined *puVar10;
  int iVar11;
  uint uVar12;
  EventLoop2 *this_00;
  _Rb_tree_node_base *p_Var13;
  long lVar14;
  _Rb_tree_node_base *p_Var15;
  undefined8 uVar16;
  EventLoop2 *pEVar17;
  code *pcVar18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  code *pcVar22;
  long lVar23;
  _Rb_tree_node_base *p_Var24;
  uint uVar25;
  undefined1 auVar26 [16];
  int local_1d8 [4];
  undefined8 local_1c8 [2];
  void *local_1b8 [2];
  code *local_1a8;
  code *pcStack_1a0;
  undefined8 local_198;
  undefined8 local_190;
  code *local_188;
  code *pcStack_180;
  _union_1457 local_178;
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  local_178.sa_handler = (__sighandler_t)0x0;
  local_f0 = 0;
  sigemptyset(&local_170);
  sigaction(2,(sigaction *)&local_178,&local_d8);
  local_198 = CONCAT62(local_198._2_6_,0x4f);
  iVar11 = PyArg_ParseTuple(param_2,&local_198,local_1c8);
  if (iVar11 == 0) {
    uVar16 = 0;
    goto LAB_0010a4b6;
  }
  this_00 = (EventLoop2 *)PyLong_AsVoidPtr(local_1c8[0]);
  if (this_00 != (EventLoop2 *)0x0) {
    if (*(long *)(this_00 + 0x68) != 0) {
      local_1a8 = (code *)0x0;
      local_1b8[0] = operator_new(1);
      pcStack_1a0 = FUN_00107950;
      local_1a8 = FUN_00107ac0;
      lVar23 = *(long *)(*(long *)(this_00 + 0x68) + 0x38);
      if (*(char *)(lVar23 + 0x5a) != '\0') {
        fwrite("close(): send_flag != false\n",1,0x1c,*(FILE **)PTR_stderr_00324fb0);
        print_stack();
      }
      puVar7 = *(undefined8 **)(lVar23 + 0x60);
      *(undefined1 *)(lVar23 + 0x5a) = 1;
      *(undefined8 *)(lVar23 + 0x60) = 0;
      if (puVar7 != (undefined8 *)0x0) {
        if ((void *)*puVar7 != (void *)0x0) {
          operator_delete((void *)*puVar7);
        }
        operator_delete(puVar7);
      }
      local_188 = (code *)0x0;
      if (local_1a8 == (code *)0x0) {
        pcVar22 = (code *)0x0;
        pcVar18 = pcStack_180;
      }
      else {
        (*local_1a8)(&local_198,local_1b8,2);
        pcVar18 = pcStack_1a0;
        pcVar22 = local_1a8;
      }
      uVar16 = *(undefined8 *)(lVar23 + 0x68);
      uVar8 = *(undefined8 *)(lVar23 + 0x70);
      local_188 = *(code **)(lVar23 + 0x78);
      *(undefined8 *)(lVar23 + 0x68) = local_198;
      *(undefined8 *)(lVar23 + 0x70) = local_190;
      pcStack_180 = *(code **)(lVar23 + 0x80);
      *(code **)(lVar23 + 0x78) = pcVar22;
      *(code **)(lVar23 + 0x80) = pcVar18;
      local_198 = uVar16;
      local_190 = uVar8;
      if (local_188 != (code *)0x0) {
        (*local_188)(&local_198,&local_198,3);
      }
      cVar5 = *(char *)(lVar23 + 0x5a);
      local_1d8[0] = *(int *)(lVar23 + 0x40);
      lVar23 = *(long *)(lVar23 + 0x38);
      p_Var13 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
      p_Var15 = (_Rb_tree_node_base *)(lVar23 + 0x10);
      p_Var19 = p_Var13;
      p_Var24 = p_Var15;
      if (p_Var13 == (_Rb_tree_node_base *)0x0) {
LAB_0010a4f0:
        lVar14 = 0;
        uVar6 = 0;
      }
      else {
        do {
          while (p_Var20 = p_Var19, local_1d8[0] <= *(int *)(p_Var20 + 0x20)) {
            p_Var19 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
            p_Var24 = p_Var20;
            if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == (_Rb_tree_node_base *)0x0)
            goto LAB_0010a15a;
          }
          p_Var1 = p_Var20 + 0x18;
          p_Var19 = *(_Rb_tree_node_base **)p_Var1;
          p_Var20 = p_Var24;
        } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_0010a15a:
        if ((p_Var15 == p_Var20) || (p_Var19 = p_Var15, local_1d8[0] < *(int *)(p_Var20 + 0x20)))
        goto LAB_0010a4f0;
        do {
          while (p_Var24 = p_Var13, local_1d8[0] <= *(int *)(p_Var24 + 0x20)) {
            p_Var13 = *(_Rb_tree_node_base **)(p_Var24 + 0x10);
            p_Var19 = p_Var24;
            if (*(_Rb_tree_node_base **)(p_Var24 + 0x10) == (_Rb_tree_node_base *)0x0)
            goto LAB_0010a18a;
          }
          p_Var20 = p_Var24 + 0x18;
          p_Var13 = *(_Rb_tree_node_base **)p_Var20;
          p_Var24 = p_Var19;
        } while (*(_Rb_tree_node_base **)p_Var20 != (_Rb_tree_node_base *)0x0);
LAB_0010a18a:
        if ((p_Var15 == p_Var24) || (local_1d8[0] < *(int *)(p_Var24 + 0x20))) {
          p_Var13 = operator_new(0x28);
          if (p_Var13 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var13 = 0;
            *(undefined8 *)(p_Var13 + 8) = 0;
            *(undefined8 *)(p_Var13 + 0x10) = 0;
            *(undefined8 *)(p_Var13 + 0x18) = 0;
            *(undefined4 *)(p_Var13 + 0x24) = 0;
            *(int *)(p_Var13 + 0x20) = local_1d8[0];
          }
          auVar26 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos
                              ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                                *)(lVar23 + 8),p_Var24,p_Var13 + 0x20);
          p_Var19 = auVar26._8_8_;
          p_Var24 = auVar26._0_8_;
          if (p_Var19 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var13);
          }
          else {
            bVar21 = true;
            if ((p_Var24 == (_Rb_tree_node_base *)0x0) && (p_Var15 != p_Var19)) {
              bVar21 = *(int *)(p_Var13 + 0x20) < *(int *)(p_Var19 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar21,p_Var13,p_Var19,p_Var15);
            *(long *)(lVar23 + 0x30) = *(long *)(lVar23 + 0x30) + 1;
            p_Var24 = p_Var13;
          }
        }
        uVar6 = *(uint *)(p_Var24 + 0x24);
        lVar14 = 1;
      }
      lVar23 = lVar23 + (lVar14 + 1) * 0x30;
      this = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(lVar23 + 8);
      p_Var15 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
      p_Var24 = (_Rb_tree_node_base *)(lVar23 + 0x10);
      p_Var13 = p_Var15;
      p_Var19 = p_Var24;
      uVar12 = uVar6;
      if (p_Var15 != (_Rb_tree_node_base *)0x0) {
        do {
          while (p_Var20 = p_Var13, local_1d8[0] <= *(int *)(p_Var20 + 0x20)) {
            p_Var13 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
            p_Var19 = p_Var20;
            if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == (_Rb_tree_node_base *)0x0)
            goto LAB_0010a272;
          }
          p_Var1 = p_Var20 + 0x18;
          p_Var13 = *(_Rb_tree_node_base **)p_Var1;
          p_Var20 = p_Var19;
        } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_0010a272:
        if ((p_Var24 != p_Var20) && (p_Var13 = p_Var24, *(int *)(p_Var20 + 0x20) <= local_1d8[0])) {
          do {
            while (p_Var19 = p_Var15, local_1d8[0] <= *(int *)(p_Var19 + 0x20)) {
              p_Var15 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
              p_Var13 = p_Var19;
              if (*(_Rb_tree_node_base **)(p_Var19 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010a2aa;
            }
            p_Var20 = p_Var19 + 0x18;
            p_Var15 = *(_Rb_tree_node_base **)p_Var20;
            p_Var19 = p_Var13;
          } while (*(_Rb_tree_node_base **)p_Var20 != (_Rb_tree_node_base *)0x0);
LAB_0010a2aa:
          if ((p_Var24 == p_Var19) || (local_1d8[0] < *(int *)(p_Var19 + 0x20))) {
            p_Var15 = operator_new(0x28);
            if (p_Var15 != (_Rb_tree_node_base *)0x0) {
              *(undefined4 *)p_Var15 = 0;
              *(undefined8 *)(p_Var15 + 8) = 0;
              *(undefined8 *)(p_Var15 + 0x10) = 0;
              *(undefined8 *)(p_Var15 + 0x18) = 0;
              *(undefined4 *)(p_Var15 + 0x24) = 0;
              *(int *)(p_Var15 + 0x20) = local_1d8[0];
            }
            auVar26 = std::
                      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                      ::_M_get_insert_hint_unique_pos(this,p_Var19,p_Var15 + 0x20);
            p_Var13 = auVar26._8_8_;
            p_Var19 = auVar26._0_8_;
            if (p_Var13 == (_Rb_tree_node_base *)0x0) {
              operator_delete(p_Var15);
            }
            else {
              bVar21 = true;
              if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var24 != p_Var13)) {
                bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var13 + 0x20);
              }
              std::_Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var13,p_Var24);
              *(long *)(lVar23 + 0x30) = *(long *)(lVar23 + 0x30) + 1;
              p_Var19 = p_Var15;
            }
          }
          uVar12 = *(uint *)(p_Var19 + 0x24);
        }
      }
      uVar25 = uVar12 | 2;
      if (cVar5 == '\0') {
        uVar25 = uVar12 & 0xfffffffd;
      }
      if (uVar6 == uVar25) {
        std::
        _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
        ::erase(this,local_1d8);
      }
      else {
        p_Var15 = *(_Rb_tree_node_base **)(lVar23 + 0x18);
        p_Var19 = p_Var24;
        p_Var13 = p_Var24;
        if (*(_Rb_tree_node_base **)(lVar23 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0010a321:
          p_Var15 = operator_new(0x28);
          if (p_Var15 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var15 = 0;
            *(undefined8 *)(p_Var15 + 8) = 0;
            *(undefined8 *)(p_Var15 + 0x10) = 0;
            *(undefined8 *)(p_Var15 + 0x18) = 0;
            *(undefined4 *)(p_Var15 + 0x24) = 0;
            *(int *)(p_Var15 + 0x20) = local_1d8[0];
          }
          auVar26 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos(this,p_Var13,p_Var15 + 0x20);
          p_Var19 = auVar26._8_8_;
          p_Var13 = auVar26._0_8_;
          if (p_Var19 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var15);
          }
          else {
            bVar21 = true;
            if ((p_Var13 == (_Rb_tree_node_base *)0x0) && (p_Var24 != p_Var19)) {
              bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var19 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var19,p_Var24);
            *(long *)(lVar23 + 0x30) = *(long *)(lVar23 + 0x30) + 1;
            p_Var13 = p_Var15;
          }
        }
        else {
          do {
            while (p_Var13 = p_Var15, local_1d8[0] <= *(int *)(p_Var13 + 0x20)) {
              p_Var15 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var19 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010a312;
            }
            p_Var20 = p_Var13 + 0x18;
            p_Var15 = *(_Rb_tree_node_base **)p_Var20;
            p_Var13 = p_Var19;
          } while (*(_Rb_tree_node_base **)p_Var20 != (_Rb_tree_node_base *)0x0);
LAB_0010a312:
          if ((p_Var24 == p_Var13) || (local_1d8[0] < *(int *)(p_Var13 + 0x20))) goto LAB_0010a321;
        }
        *(uint *)(p_Var13 + 0x24) = uVar25;
      }
      if (local_1a8 != (code *)0x0) {
        (*local_1a8)(local_1b8,local_1b8,3);
      }
      local_188 = (code *)0x0;
      EventLoop2::run(this_00,&local_198);
      if (local_188 != (code *)0x0) {
        (*local_188)(&local_198,&local_198,3);
      }
    }
    *(undefined **)(this_00 + 0x70) = PTR_vtable_00324f90 + 0x10;
    if (*(code **)(this_00 + 0xd0) != (code *)0x0) {
      (**(code **)(this_00 + 0xd0))(this_00 + 0xc0,this_00 + 0xc0,3);
    }
    puVar10 = PTR__S_empty_rep_storage_00324fa0;
    pEVar17 = *(EventLoop2 **)(this_00 + 0xa8);
    pEVar4 = this_00 + 0xa8;
    if (pEVar4 != pEVar17) {
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        do {
          lVar23 = *(long *)(pEVar17 + 0x18);
          pEVar9 = *(EventLoop2 **)pEVar17;
          if (((allocator *)(lVar23 + -0x18) != (allocator *)puVar10) &&
             (iVar11 = *(int *)(lVar23 + -8), *(int *)(lVar23 + -8) = iVar11 + -1, iVar11 < 1)) {
            std::string::_Rep::_M_destroy((allocator *)(lVar23 + -0x18));
          }
          operator_delete(pEVar17);
          pEVar17 = pEVar9;
        } while (pEVar4 != pEVar9);
      }
      else {
        do {
          pEVar9 = *(EventLoop2 **)pEVar17;
          paVar2 = (allocator *)(*(long *)(pEVar17 + 0x18) + -0x18);
          if (paVar2 != (allocator *)puVar10) {
            LOCK();
            piVar3 = (int *)(*(long *)(pEVar17 + 0x18) + -8);
            iVar11 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
            if (iVar11 < 1) {
              std::string::_Rep::_M_destroy(paVar2);
            }
          }
          operator_delete(pEVar17);
          pEVar17 = pEVar9;
        } while (pEVar4 != pEVar9);
      }
    }
    std::
    _Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
    ::_M_erase((_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
                *)(this_00 + 0x78),*(_Rb_tree_node **)(this_00 + 0x88));
    *(undefined **)(this_00 + 0x70) = PTR_vtable_00324ef0 + 0x10;
    EventLoop2::~EventLoop2(this_00);
    operator_delete(this_00);
  }
  uVar16 = Py_BuildValue(&DAT_0011f3d1,0);
LAB_0010a4b6:
  sigaction(2,&local_d8,(sigaction *)0x0);
  return uVar16;
}



