
/* UnixServer::poll(int, int) */

undefined8 __thiscall UnixServer::poll(UnixServer *this,int param_1,int param_2)

{
  _Rb_tree_node_base *p_Var1;
  UnixServer *pUVar2;
  int *piVar3;
  uint *puVar4;
  undefined *puVar5;
  _Rb_tree_node_base *p_Var6;
  UnixServer *pUVar7;
  int iVar8;
  uint uVar9;
  void *pvVar10;
  long *plVar11;
  TcpConn *this_00;
  UnixServer *pUVar12;
  ulong uVar13;
  UnixServer *pUVar14;
  UnixServer *pUVar15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  bool bVar19;
  uint local_78 [4];
  long local_68 [2];
  ulong local_58 [2];
  uint *local_48 [3];
  
  if ((*(int *)(this + 0xb8) != param_1) || ((param_2 & 1U) == 0)) goto LAB_0011d8fb;
  local_78[0] = accept(*(int *)(this + 0xb8),(sockaddr *)0x0,(socklen_t *)0x0);
  if ((int)local_78[0] < 0) {
    perror("accept");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  setnonblock(local_78[0]);
  setcloexec(local_78[0]);
  __gnu_cxx::__to_xstring<std::string,char>
            ((_func_int_char_ptr_ulong_char_ptr___va_list_tag_ptr *)local_48,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,&DAT_0011fe68,(ulong)local_78[0]);
  std::string::string((string *)local_58,(string *)(this + 0xf0));
  std::string::append((char *)local_58,0x11fdf2);
  uVar13 = *(long *)(local_58[0] - 0x18) + *(long *)(local_48[0] + -6);
  if ((*(ulong *)(local_58[0] - 0x10) < uVar13) && (uVar13 <= *(ulong *)(local_48[0] + -4))) {
    plVar11 = (long *)std::string::insert((ulong)local_48,(char *)0x0,local_58[0]);
  }
  else {
    plVar11 = (long *)std::string::append((string *)local_58);
  }
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  local_68[0] = *plVar11;
  *plVar11 = (long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_58[0] - 0x18) != (allocator *)puVar5) {
    piVar3 = (int *)(local_58[0] - 8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_58[0] - 8);
      *(int *)(local_58[0] - 8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_58[0] - 0x18));
    }
  }
  if ((allocator *)(local_48[0] + -6) != (allocator *)puVar5) {
    puVar4 = local_48[0] + -2;
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      uVar9 = local_48[0][-2];
      local_48[0][-2] = uVar9 - 1;
    }
    else {
      LOCK();
      uVar9 = *puVar4;
      *puVar4 = *puVar4 - 1;
      UNLOCK();
    }
    if ((int)uVar9 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_48[0] + -6));
    }
  }
  this_00 = operator_new(0xd0);
  TcpConn::TcpConn(this_00,local_78[0],(string *)(this + 0xf0),(string *)local_68,
                   (EventHandler *)this);
  pUVar15 = this + 200;
  pUVar7 = *(UnixServer **)(this + 0xd0);
  pUVar14 = pUVar15;
  if (*(UnixServer **)(this + 0xd0) == (UnixServer *)0x0) {
LAB_0011db73:
    local_48[0] = local_78;
    pUVar12 = (UnixServer *)
              std::
              _Rb_tree<int,std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>,std::_Select1st<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>,std::less<int>,std::allocator<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>>
              ::
              _M_emplace_hint_unique<std::piecewise_construct_t_const&,std::tuple<int_const&>,std::tuple<>>
                        (this + 0xc0,pUVar15,&DAT_0011ff15,local_48,(string *)local_58);
  }
  else {
    do {
      while (pUVar12 = pUVar7, *(int *)(pUVar12 + 0x20) < (int)local_78[0]) {
        pUVar2 = pUVar12 + 0x18;
        pUVar7 = *(UnixServer **)pUVar2;
        pUVar12 = pUVar14;
        if (*(UnixServer **)pUVar2 == (UnixServer *)0x0) goto LAB_0011db1a;
      }
      pUVar7 = *(UnixServer **)(pUVar12 + 0x10);
      pUVar14 = pUVar12;
    } while (*(UnixServer **)(pUVar12 + 0x10) != (UnixServer *)0x0);
LAB_0011db1a:
    bVar19 = pUVar15 == pUVar12;
    pUVar15 = pUVar12;
    if ((bVar19) || ((int)local_78[0] < *(int *)(pUVar12 + 0x20))) goto LAB_0011db73;
  }
  plVar11 = *(long **)(pUVar12 + 0x28);
  *(TcpConn **)(pUVar12 + 0x28) = this_00;
  if (plVar11 != (long *)0x0) {
    (**(code **)(*plVar11 + 8))();
  }
  if (*(long *)(this + 0xa8) == 0) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_function_call();
  }
  (**(code **)(this + 0xb0))(this + 0x98,this_00);
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar5) {
    piVar3 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
LAB_0011d8fb:
  p_Var18 = (_Rb_tree_node_base *)(this + 200);
  p_Var6 = *(_Rb_tree_node_base **)(this + 0xd0);
  p_Var16 = p_Var18;
  if (*(_Rb_tree_node_base **)(this + 0xd0) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var17 = p_Var6, *(int *)(p_Var17 + 0x20) < param_1) {
        p_Var1 = p_Var17 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var1;
        p_Var17 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011d92a;
      }
      p_Var6 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
      p_Var16 = p_Var17;
    } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011d92a:
    if ((p_Var18 != p_Var17) && (*(int *)(p_Var17 + 0x20) <= param_1)) {
      if ((param_2 & 2U) != 0) {
        TcpConn::send_proc(*(TcpConn **)(p_Var17 + 0x28));
      }
      if ((param_2 & 1U) != 0) {
        TcpConn::recv_proc(*(TcpConn **)(p_Var17 + 0x28));
      }
      if ((*(char *)(*(long *)(p_Var17 + 0x28) + 0x58) == '\0') &&
         (*(char *)(*(long *)(p_Var17 + 0x28) + 0x59) == '\0')) {
        pvVar10 = (void *)std::_Rb_tree_rebalance_for_erase(p_Var17,p_Var18);
        if (*(long **)((long)pvVar10 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar10 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar10 + 0x28) = 0;
        operator_delete(pvVar10);
        *(long *)(this + 0xe8) = *(long *)(this + 0xe8) + -1;
      }
    }
  }
  return 0;
}



