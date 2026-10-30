
/* WARNING: Switch with 1 destination removed at 0x001073b0 */

undefined4 __thiscall EventLoop2::run(EventLoop2 *this,long param_2)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  epoll_data_t *peVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  char cVar7;
  uint32_t uVar8;
  int iVar9;
  int iVar10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  int *piVar13;
  long *plVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  bool bVar18;
  long lVar19;
  _Rb_tree_node_base *p_Var20;
  _Rb_tree_node_base *p_Var21;
  undefined8 *puVar22;
  long *plVar23;
  long *plVar24;
  byte bVar25;
  undefined1 auVar26 [16];
  long *plStack_c8;
  _Rb_tree_node_base *p_Stack_c0;
  int iStack_b0;
  int iStack_ac;
  long *plStack_a0;
  epoll_event eStack_78;
  epoll_event eStack_68;
  code *pcStack_50;
  code *pcStack_48;
  
  if (this[0x54] != (EventLoop2)0x0) {
    peVar3 = &eStack_68.data;
    do {
      plStack_a0 = *(long **)(this + 0x10);
      plStack_c8 = *(long **)(this + 8);
      if (plStack_a0 == plStack_c8) {
        if (*(long *)(this + 0x28) == *(long *)(this + 0x20)) break;
      }
      else if (*(long *)(this + 0x28) == *(long *)(this + 0x20)) goto LAB_00116ec6;
      std::
      vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
      ::
      _M_range_insert<std::move_iterator<__gnu_cxx::__normal_iterator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>*,std::vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>>>>
                (this + 8);
      plVar24 = *(long **)(this + 0x28);
      plVar23 = *(long **)(this + 0x20);
      for (plVar14 = plVar23; plVar14 != plVar24; plVar14 = plVar14 + 1) {
        if ((long *)*plVar14 != (long *)0x0) {
          (**(code **)(*(long *)*plVar14 + 0x18))();
        }
        *plVar14 = 0;
      }
      plStack_c8 = *(long **)(this + 8);
      *(long **)(this + 0x28) = plVar23;
      plStack_a0 = *(long **)(this + 0x10);
      if (plStack_c8 != plStack_a0) {
LAB_00116ec6:
        iStack_ac = 0;
        iStack_b0 = 1;
        do {
          lVar19 = ((long)iStack_ac + 1) * 0x30 + *plStack_c8;
          p_Var12 = *(_Rb_tree_node_base **)(lVar19 + 0x20);
          p_Stack_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          if (p_Var12 != p_Stack_c0) {
            do {
              uVar4 = *(uint *)(p_Var12 + 0x24);
              iVar10 = *(int *)(p_Var12 + 0x20);
              uVar8 = 0x11;
              eStack_68.events = 0;
              eStack_68.data.fd = 0;
              if ((uVar4 & 2) != 0) {
                eStack_68.events = 4;
                uVar8 = 0x15;
              }
              if ((uVar4 & 1) != 0) {
                eStack_68.events = uVar8;
              }
              eStack_68._4_4_ = iVar10;
              iVar9 = epoll_ctl(*(int *)(this + 0x50),iStack_b0,iVar10,&eStack_68);
              if (iVar9 != 0) {
                perror("epoll_ctl");
              }
              lVar19 = *plStack_c8;
              p_Var1 = (_Rb_tree_node_base *)(lVar19 + 0x10);
              p_Var11 = *(_Rb_tree_node_base **)(lVar19 + 0x18);
              p_Var20 = p_Var1;
              p_Var21 = p_Var1;
              if (*(_Rb_tree_node_base **)(lVar19 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00116fcb:
                p_Var11 = operator_new(0x28);
                if (p_Var11 != (_Rb_tree_node_base *)0x0) {
                  *(undefined4 *)p_Var11 = 0;
                  *(undefined8 *)(p_Var11 + 8) = 0;
                  *(undefined8 *)(p_Var11 + 0x10) = 0;
                  *(undefined8 *)(p_Var11 + 0x18) = 0;
                  *(int *)(p_Var11 + 0x20) = iVar10;
                  *(undefined4 *)(p_Var11 + 0x24) = 0;
                }
                auVar26 = std::
                          _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                          ::_M_get_insert_hint_unique_pos
                                    ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                                      *)(lVar19 + 8),p_Var21,p_Var11 + 0x20);
                p_Var20 = auVar26._8_8_;
                p_Var21 = auVar26._0_8_;
                if (p_Var20 == (_Rb_tree_node_base *)0x0) {
                  operator_delete(p_Var11);
                }
                else {
                  bVar18 = true;
                  if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var1 != p_Var20)) {
                    bVar18 = *(int *)(p_Var11 + 0x20) < *(int *)(p_Var20 + 0x20);
                  }
                  std::_Rb_tree_insert_and_rebalance(bVar18,p_Var11,p_Var20,p_Var1);
                  *(long *)(lVar19 + 0x30) = *(long *)(lVar19 + 0x30) + 1;
                  p_Var21 = p_Var11;
                }
              }
              else {
                do {
                  while (p_Var21 = p_Var11, iVar10 <= *(int *)(p_Var21 + 0x20)) {
                    p_Var11 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
                    p_Var20 = p_Var21;
                    if (*(_Rb_tree_node_base **)(p_Var21 + 0x10) == (_Rb_tree_node_base *)0x0)
                    goto LAB_00116fbb;
                  }
                  p_Var2 = p_Var21 + 0x18;
                  p_Var11 = *(_Rb_tree_node_base **)p_Var2;
                  p_Var21 = p_Var20;
                } while (*(_Rb_tree_node_base **)p_Var2 != (_Rb_tree_node_base *)0x0);
LAB_00116fbb:
                if ((p_Var21 == p_Var1) || (iVar10 < *(int *)(p_Var21 + 0x20))) goto LAB_00116fcb;
              }
              *(uint *)(p_Var21 + 0x24) = uVar4;
              p_Var12 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var12);
            } while (p_Stack_c0 != p_Var12);
            lVar19 = ((long)iStack_ac + 1) * 0x30 + *plStack_c8;
            p_Stack_c0 = (_Rb_tree_node_base *)(lVar19 + 0x10);
          }
          std::
          _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
          ::_M_erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                      *)(lVar19 + 8),*(_Rb_tree_node **)(lVar19 + 0x18));
          *(undefined8 *)(lVar19 + 0x18) = 0;
          *(undefined8 *)(lVar19 + 0x30) = 0;
          *(_Rb_tree_node_base **)(lVar19 + 0x20) = p_Stack_c0;
          *(_Rb_tree_node_base **)(lVar19 + 0x28) = p_Stack_c0;
          if (iStack_ac == 1) goto code_r0x001170c4;
          iStack_b0 = 3;
          iStack_ac = 1;
        } while( true );
      }
LAB_001170da:
      iVar10 = epoll_wait(*(int *)(this + 0x50),&eStack_78,1,(int)(*(long *)(this + 0x60) / 1000));
      if (iVar10 == -1) {
        piVar13 = __errno_location();
        if (*piVar13 != 4) {
          perror("epoll_wait");
          print_stack_abort();
        }
      }
      else if (iVar10 == 0) {
        puVar17 = *(undefined8 **)(this + 0x38);
        puVar15 = *(undefined8 **)(this + 0x40);
        if (puVar17 != puVar15) {
          do {
            pcStack_50 = (code *)0x0;
            eStack_68.events = (uint32_t)*puVar17;
            eStack_68._4_4_ = SUB84((ulong)*puVar17 >> 0x20,0);
            if ((code *)puVar17[3] != (code *)0x0) {
              (*(code *)puVar17[3])(peVar3,puVar17 + 1,2);
              pcStack_48 = (code *)puVar17[4];
              pcStack_50 = (code *)puVar17[3];
            }
            plVar23 = *(long **)(this + 8);
            plVar24 = *(long **)(this + 0x10);
            if (plVar23 != plVar24) {
              lVar19 = *plVar23;
              while (CONCAT44(eStack_68._4_4_,eStack_68.events) != lVar19) {
                plVar23 = plVar23 + 1;
                if (plVar23 == plVar24) goto joined_r0x00117359;
                lVar19 = *plVar23;
              }
              plVar23 = plVar23 + 1;
              if ((plVar23 != plVar24) && (lVar19 = (long)plVar24 - (long)plVar23 >> 3, 0 < lVar19))
              {
                do {
                  plVar24 = (long *)plVar23[-1];
                  lVar6 = *plVar23;
                  *plVar23 = 0;
                  plVar23[-1] = lVar6;
                  if (plVar24 != (long *)0x0) {
                    (**(code **)(*plVar24 + 0x18))();
                  }
                  plVar23 = plVar23 + 1;
                  lVar19 = lVar19 + -1;
                } while (lVar19 != 0);
                plVar24 = *(long **)(this + 0x10);
              }
              *(long **)(this + 0x10) = plVar24 + -1;
              if ((long *)plVar24[-1] != (long *)0x0) {
                (**(code **)(*(long *)plVar24[-1] + 0x18))();
              }
              plVar24[-1] = 0;
            }
joined_r0x00117359:
            if (pcStack_50 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
              std::__throw_bad_function_call();
            }
            (*pcStack_48)(peVar3);
            if (pcStack_50 != (code *)0x0) {
              (*pcStack_50)(peVar3,peVar3,3);
            }
            puVar17 = puVar17 + 5;
          } while (puVar15 != puVar17);
          puVar16 = *(undefined8 **)(this + 0x40);
          puVar15 = *(undefined8 **)(this + 0x38);
          puVar17 = puVar16;
          for (puVar22 = puVar15; puVar16 != puVar22; puVar22 = puVar22 + 5) {
            if ((code *)puVar22[3] != (code *)0x0) {
              (*(code *)puVar22[3])(puVar22 + 1,puVar22 + 1,3);
            }
            puVar17 = puVar15;
          }
        }
        puVar15 = *(undefined8 **)(this + 8);
        *(undefined8 **)(this + 0x40) = puVar17;
        while (puVar15 != *(undefined8 **)(this + 0x10)) {
          cVar7 = (**(code **)(*(long *)*puVar15 + 8))();
          while (cVar7 == '\0') {
            puVar15 = puVar15 + 1;
            if (puVar15 == *(undefined8 **)(this + 0x10)) goto LAB_0011724d;
            cVar7 = (**(code **)(*(long *)*puVar15 + 8))();
          }
          puVar16 = *(undefined8 **)(this + 0x10);
          puVar17 = puVar15 + 1;
          if ((puVar16 != puVar17) && (lVar19 = (long)puVar16 - (long)puVar17 >> 3, 0 < lVar19)) {
            do {
              plVar23 = (long *)puVar17[-1];
              uVar5 = *puVar17;
              *puVar17 = 0;
              puVar17[-1] = uVar5;
              if (plVar23 != (long *)0x0) {
                (**(code **)(*plVar23 + 0x18))();
              }
              puVar17 = puVar17 + 1;
              lVar19 = lVar19 + -1;
            } while (lVar19 != 0);
            puVar16 = *(undefined8 **)(this + 0x10);
          }
          *(undefined8 **)(this + 0x10) = puVar16 + -1;
          if ((long *)puVar16[-1] != (long *)0x0) {
            (**(code **)(*(long *)puVar16[-1] + 0x18))();
          }
          puVar16[-1] = 0;
        }
      }
      else {
        puVar17 = *(undefined8 **)(this + 8);
        while (puVar17 != *(undefined8 **)(this + 0x10)) {
          bVar25 = (eStack_78.events & 0x11) != 0;
          if ((eStack_78.events & 4) != 0) {
            bVar25 = bVar25 | 2;
          }
          cVar7 = (*(code *)**(undefined8 **)*puVar17)
                            ((undefined8 *)*puVar17,eStack_78._4_4_,bVar25);
          if ((cVar7 == '\0') && (cVar7 = (**(code **)(*(long *)*puVar17 + 8))(), cVar7 == '\0')) {
            puVar17 = puVar17 + 1;
          }
          else {
            puVar16 = *(undefined8 **)(this + 0x10);
            puVar15 = puVar17 + 1;
            if ((puVar16 != puVar15) && (lVar19 = (long)puVar16 - (long)puVar15 >> 3, 0 < lVar19)) {
              do {
                plVar23 = (long *)puVar15[-1];
                uVar5 = *puVar15;
                *puVar15 = 0;
                puVar15[-1] = uVar5;
                if (plVar23 != (long *)0x0) {
                  (**(code **)(*plVar23 + 0x18))();
                }
                puVar15 = puVar15 + 1;
                lVar19 = lVar19 + -1;
              } while (lVar19 != 0);
              puVar16 = *(undefined8 **)(this + 0x10);
            }
            *(undefined8 **)(this + 0x10) = puVar16 + -1;
            if ((long *)puVar16[-1] != (long *)0x0) {
              (**(code **)(*(long *)puVar16[-1] + 0x18))();
            }
            puVar16[-1] = 0;
          }
        }
      }
LAB_0011724d:
      if (*(long *)(param_2 + 0x10) != 0) {
        (**(code **)(param_2 + 0x18))(param_2);
      }
    } while (this[0x54] != (EventLoop2)0x0);
  }
  this[0x54] = (EventLoop2)0x1;
  return *(undefined4 *)(this + 0x58);
code_r0x001170c4:
  plStack_c8 = plStack_c8 + 1;
  if (plStack_a0 == plStack_c8) goto LAB_001170da;
  goto LAB_00116ec6;
}



