
/* std::_Rb_tree_iterator<std::pair<int const, std::unique_ptr<TcpConn, std::default_delete<TcpConn>
   > > > std::_Rb_tree<int, std::pair<int const, std::unique_ptr<TcpConn,
   std::default_delete<TcpConn> > >, std::_Select1st<std::pair<int const, std::unique_ptr<TcpConn,
   std::default_delete<TcpConn> > > >, std::less<int>, std::allocator<std::pair<int const,
   std::unique_ptr<TcpConn, std::default_delete<TcpConn> > > >
   >::_M_emplace_hint_unique<std::piecewise_construct_t const&, std::tuple<int const&>, std::tuple<>
   >(std::_Rb_tree_const_iterator<std::pair<int const, std::unique_ptr<TcpConn,
   std::default_delete<TcpConn> > > >, std::piecewise_construct_t const&, std::tuple<int const&>&&,
   std::tuple<>&&) */

_Rb_tree_node_base *
std::
_Rb_tree<int,std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>,std::_Select1st<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>,std::less<int>,std::allocator<std::pair<int_const,std::unique_ptr<TcpConn,std::default_delete<TcpConn>>>>>
::_M_emplace_hint_unique<std::piecewise_construct_t_const&,std::tuple<int_const&>,std::tuple<>>
          (long param_1,_Rb_tree_node_base *param_2,undefined8 param_3,undefined8 *param_4)

{
  _Rb_tree_node_base *p_Var1;
  undefined4 uVar2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  int iVar7;
  bool bVar8;
  int iVar9;
  
  p_Var3 = operator_new(0x30);
  if (p_Var3 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var3 = 0;
    *(undefined8 *)(p_Var3 + 8) = 0;
    *(undefined8 *)(p_Var3 + 0x10) = 0;
    *(undefined8 *)(p_Var3 + 0x18) = 0;
    uVar2 = *(undefined4 *)*param_4;
    *(undefined8 *)(p_Var3 + 0x28) = 0;
    *(undefined4 *)(p_Var3 + 0x20) = uVar2;
  }
  p_Var1 = (_Rb_tree_node_base *)(param_1 + 8);
  p_Var6 = p_Var1;
  if (p_Var1 == param_2) {
    if ((*(long *)(param_1 + 0x28) == 0) ||
       (p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x20),
       *(int *)(p_Var3 + 0x20) <= *(int *)(p_Var4 + 0x20))) {
      if (*(_Rb_tree_node_base **)(param_1 + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0011ce23:
        if (*(_Rb_tree_node_base **)(param_1 + 0x18) == p_Var6) goto LAB_0011cd9e;
        param_2 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var6);
        iVar9 = *(int *)(p_Var3 + 0x20);
        iVar7 = *(int *)(param_2 + 0x20);
      }
      else {
        iVar9 = *(int *)(p_Var3 + 0x20);
        p_Var6 = *(_Rb_tree_node_base **)(param_1 + 0x10);
        do {
          param_2 = p_Var6;
          iVar7 = *(int *)(param_2 + 0x20);
          if (iVar9 < iVar7) {
            p_Var6 = *(_Rb_tree_node_base **)(param_2 + 0x10);
          }
          else {
            p_Var6 = *(_Rb_tree_node_base **)(param_2 + 0x18);
          }
        } while (p_Var6 != (_Rb_tree_node_base *)0x0);
        p_Var6 = param_2;
        if (iVar9 < iVar7) goto LAB_0011ce23;
      }
      if (iVar9 <= iVar7) goto LAB_0011cca0;
LAB_0011cd9e:
      param_2 = (_Rb_tree_node_base *)0x0;
      p_Var4 = p_Var6;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011cca0:
        if (*(long **)(p_Var3 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)(p_Var3 + 0x28) + 8))();
        }
        *(undefined8 *)(p_Var3 + 0x28) = 0;
        operator_delete(p_Var3);
        return param_2;
      }
    }
LAB_0011ccf0:
    if (p_Var1 == p_Var4) {
      bVar8 = true;
      goto LAB_0011cc1c;
    }
    iVar9 = *(int *)(p_Var3 + 0x20);
    iVar7 = *(int *)(p_Var4 + 0x20);
  }
  else {
    iVar9 = *(int *)(p_Var3 + 0x20);
    iVar7 = *(int *)(param_2 + 0x20);
    if (iVar9 < iVar7) {
      p_Var6 = *(_Rb_tree_node_base **)(param_1 + 0x18);
      p_Var5 = param_2;
      if (p_Var6 != param_2) {
        p_Var4 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(param_2);
        if (iVar9 <= *(int *)(p_Var4 + 0x20)) {
          p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x10);
          p_Var5 = p_Var1;
          if (*(_Rb_tree_node_base **)(param_1 + 0x10) != (_Rb_tree_node_base *)0x0) {
            do {
              param_2 = p_Var4;
              iVar7 = *(int *)(param_2 + 0x20);
              if (iVar9 < iVar7) {
                p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x10);
              }
              else {
                p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x18);
              }
            } while (p_Var4 != (_Rb_tree_node_base *)0x0);
            p_Var5 = param_2;
            if (iVar9 >= iVar7) goto joined_r0x0011cd92;
          }
          if (p_Var6 != p_Var5) {
            param_2 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var5);
            iVar7 = *(int *)(param_2 + 0x20);
joined_r0x0011cd92:
            p_Var6 = p_Var5;
            if (iVar9 <= iVar7) goto LAB_0011cca0;
          }
          goto LAB_0011cd9e;
        }
        if (*(long *)(p_Var4 + 0x18) == 0) goto LAB_0011ccf0;
      }
LAB_0011cc0b:
      bVar8 = true;
      p_Var4 = p_Var5;
      if (p_Var5 != (_Rb_tree_node_base *)0x0) goto LAB_0011cc1c;
      goto LAB_0011ccf0;
    }
    if (iVar9 <= iVar7) goto LAB_0011cca0;
    p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x20);
    if (p_Var4 == param_2) goto LAB_0011ccf0;
    p_Var5 = (_Rb_tree_node_base *)std::_Rb_tree_increment(param_2);
    if (*(int *)(p_Var5 + 0x20) <= iVar9) {
      p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x10);
      if (*(_Rb_tree_node_base **)(param_1 + 0x10) != (_Rb_tree_node_base *)0x0) {
        do {
          param_2 = p_Var4;
          iVar7 = *(int *)(param_2 + 0x20);
          if (iVar9 < iVar7) {
            p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x10);
          }
          else {
            p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x18);
          }
        } while (p_Var4 != (_Rb_tree_node_base *)0x0);
        p_Var6 = param_2;
        p_Var5 = param_2;
        if (iVar9 >= iVar7) goto joined_r0x0011cd92;
      }
      if (*(_Rb_tree_node_base **)(param_1 + 0x18) != p_Var6) {
        param_2 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var6);
        iVar7 = *(int *)(param_2 + 0x20);
        p_Var5 = p_Var6;
        goto joined_r0x0011cd92;
      }
      goto LAB_0011cd9e;
    }
    p_Var4 = param_2;
    if (*(long *)(param_2 + 0x18) != 0) goto LAB_0011cc0b;
  }
  bVar8 = iVar9 < iVar7;
LAB_0011cc1c:
  std::_Rb_tree_insert_and_rebalance(bVar8,p_Var3,p_Var4,p_Var1);
  *(long *)(param_1 + 0x28) = *(long *)(param_1 + 0x28) + 1;
  return p_Var3;
}



