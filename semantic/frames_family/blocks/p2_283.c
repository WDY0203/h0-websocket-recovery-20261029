
/* TcpServer::poll(int, int) */

undefined8 __thiscall TcpServer::poll(TcpServer *this,int param_1,int param_2)

{
  _Rb_tree_node_base *p_Var1;
  TcpServer *pTVar2;
  int *piVar3;
  undefined *puVar4;
  _Rb_tree_node_base *p_Var5;
  TcpServer *pTVar6;
  int iVar7;
  void *pvVar8;
  char *pcVar9;
  long *plVar10;
  TcpConn *this_00;
  TcpServer *pTVar11;
  ulong uVar12;
  TcpServer *pTVar13;
  TcpServer *pTVar14;
  _Rb_tree_node_base *p_Var15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  bool bVar18;
  undefined1 local_b9;
  socklen_t local_b8 [4];
  int local_a8 [4];
  long local_98 [2];
  long local_88 [2];
  ulong local_78 [2];
  long local_68 [2];
  int *local_58 [2];
  undefined1 local_48 [24];
  
  if ((*(int *)(this + 0xb8) != param_1) || ((param_2 & 1U) == 0)) goto LAB_0011ba1e;
  local_b8[0] = 0x10;
  local_a8[0] = accept(*(int *)(this + 0xb8),(sockaddr *)local_48,local_b8);
  if (local_a8[0] < 0) {
    perror("accept");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  setnonblock(local_a8[0]);
  setcloexec(local_a8[0]);
  local_58[0] = (int *)CONCAT44(local_58[0]._4_4_,1);
  setsockopt(local_a8[0],6,1,(allocator *)local_58,4);
  pcVar9 = inet_ntoa((in_addr)local_48._4_4_);
  std::string::string((string *)local_98,pcVar9,(allocator *)local_58);
  __gnu_cxx::__to_xstring<std::string,char>
            ((_func_int_char_ptr_ulong_char_ptr___va_list_tag_ptr *)local_68,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,&DAT_0011fd61,
             (ulong)(ushort)((ushort)local_48._2_2_ >> 8 | local_48._2_2_ << 8));
  std::string::string((string *)local_78,(string *)local_98);
  std::string::append((char *)local_78,0x11fcf2);
  uVar12 = *(long *)(local_78[0] - 0x18) + *(long *)(local_68[0] + -0x18);
  if ((*(ulong *)(local_78[0] - 0x10) < uVar12) && (uVar12 <= *(ulong *)(local_68[0] + -0x10))) {
    plVar10 = (long *)std::string::insert((ulong)local_68,(char *)0x0,local_78[0]);
  }
  else {
    plVar10 = (long *)std::string::append((string *)local_78);
  }
  puVar4 = PTR__S_empty_rep_storage_00324fa0;
  local_88[0] = *plVar10;
  *plVar10 = (long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_78[0] - 0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_78[0] - 8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_78[0] - 8);
      *(int *)(local_78[0] - 8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_78[0] - 0x18));
    }
  }
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
  this_00 = operator_new(0xd0);
  TcpConn::TcpConn(this_00,local_a8[0],(string *)local_98,(string *)local_88,(EventHandler *)this);
  pTVar14 = this + 200;
  pTVar6 = *(TcpServer **)(this + 0xd0);
  pTVar13 = pTVar14;
  if (*(TcpServer **)(this + 0xd0) == (TcpServer *)0x0) {
LAB_0011bd19:
    local_58[0] = local_a8;
    pTVar11 = (TcpServer *)
              std::
              _Rb_tree<int,std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>,std::_Select1st<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>,std::less<int>,std::allocator<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>>
              ::
              _M_emplace_hint_unique<std::piecewise_construct_t_const&,std::tuple<int_const&>,std::tuple<>>
                        (this + 0xc0,pTVar14,&DAT_0011fdcc,(allocator *)local_58,&local_b9);
  }
  else {
    do {
      while (pTVar11 = pTVar6, *(int *)(pTVar11 + 0x20) < local_a8[0]) {
        pTVar2 = pTVar11 + 0x18;
        pTVar6 = *(TcpServer **)pTVar2;
        pTVar11 = pTVar13;
        if (*(TcpServer **)pTVar2 == (TcpServer *)0x0) goto LAB_0011bcaa;
      }
      pTVar6 = *(TcpServer **)(pTVar11 + 0x10);
      pTVar13 = pTVar11;
    } while (*(TcpServer **)(pTVar11 + 0x10) != (TcpServer *)0x0);
LAB_0011bcaa:
    bVar18 = pTVar14 == pTVar11;
    pTVar14 = pTVar11;
    if ((bVar18) || (local_a8[0] < *(int *)(pTVar11 + 0x20))) goto LAB_0011bd19;
  }
  plVar10 = *(long **)(pTVar11 + 0x28);
  *(TcpConn **)(pTVar11 + 0x28) = this_00;
  if (plVar10 != (long *)0x0) {
    (**(code **)(*plVar10 + 8))();
  }
  if (*(long *)(this + 0xa8) == 0) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_function_call();
  }
  (**(code **)(this + 0xb0))(this + 0x98,this_00);
  if ((allocator *)(local_88[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_88[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_88[0] + -8);
      *(int *)(local_88[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_88[0] + -0x18));
    }
  }
  if ((allocator *)(local_98[0] + -0x18) != (allocator *)puVar4) {
    piVar3 = (int *)(local_98[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar7 = *(int *)(local_98[0] + -8);
      *(int *)(local_98[0] + -8) = iVar7 + -1;
    }
    else {
      LOCK();
      iVar7 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar7 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_98[0] + -0x18));
    }
  }
LAB_0011ba1e:
  p_Var17 = (_Rb_tree_node_base *)(this + 200);
  p_Var5 = *(_Rb_tree_node_base **)(this + 0xd0);
  p_Var15 = p_Var17;
  if (*(_Rb_tree_node_base **)(this + 0xd0) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var16 = p_Var5, *(int *)(p_Var16 + 0x20) < param_1) {
        p_Var1 = p_Var16 + 0x18;
        p_Var5 = *(_Rb_tree_node_base **)p_Var1;
        p_Var16 = p_Var15;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011ba4a;
      }
      p_Var5 = *(_Rb_tree_node_base **)(p_Var16 + 0x10);
      p_Var15 = p_Var16;
    } while (*(_Rb_tree_node_base **)(p_Var16 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011ba4a:
    if ((p_Var17 != p_Var16) && (*(int *)(p_Var16 + 0x20) <= param_1)) {
      if ((param_2 & 2U) != 0) {
        TcpConn::send_proc(*(TcpConn **)(p_Var16 + 0x28));
      }
      if ((param_2 & 1U) != 0) {
        TcpConn::recv_proc(*(TcpConn **)(p_Var16 + 0x28));
      }
      if ((*(char *)(*(long *)(p_Var16 + 0x28) + 0x58) == '\0') &&
         (*(char *)(*(long *)(p_Var16 + 0x28) + 0x59) == '\0')) {
        pvVar8 = (void *)std::_Rb_tree_rebalance_for_erase(p_Var16,p_Var17);
        if (*(long **)((long)pvVar8 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar8 + 0x28) = 0;
        operator_delete(pvVar8);
        *(long *)(this + 0xe8) = *(long *)(this + 0xe8) + -1;
      }
    }
  }
  return 0;
}



