
/* WARNING: Switch with 1 destination removed at 0x001072c0 */

undefined1  [16] __thiscall
std::
_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
::_M_emplace_unique<WSConn*&,std::unique_ptr<Root,std::default_delete<Root>>>
          (_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
           *this,WSConn **param_1,unique_ptr *param_2)

{
  _Rb_tree_node_base *p_Var1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  bool bVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  auVar9._0_8_ = operator_new(0x30);
  if (auVar9._0_8_ != (_Rb_tree_node_base *)0x0) {
    *(undefined8 *)(auVar9._0_8_ + 8) = 0;
    *(undefined8 *)(auVar9._0_8_ + 0x10) = 0;
    *(undefined8 *)(auVar9._0_8_ + 0x18) = 0;
    *(undefined4 *)auVar9._0_8_ = 0;
    *(WSConn **)(auVar9._0_8_ + 0x20) = *param_1;
    uVar2 = *(undefined8 *)param_2;
    *(undefined8 *)param_2 = 0;
    *(undefined8 *)(auVar9._0_8_ + 0x28) = uVar2;
  }
  p_Var1 = (_Rb_tree_node_base *)(this + 8);
  p_Var6 = p_Var1;
  if (*(_Rb_tree_node_base **)(this + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010bf18:
    p_Var5 = *(_Rb_tree_node_base **)(this + 0x18);
    if (p_Var5 == p_Var6) goto LAB_0010bf50;
    p_Var5 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var6);
    if (*(ulong *)(auVar9._0_8_ + 0x20) <= *(ulong *)(p_Var5 + 0x20)) goto LAB_0010bee1;
  }
  else {
    uVar3 = *(ulong *)(auVar9._0_8_ + 0x20);
    p_Var5 = *(_Rb_tree_node_base **)(this + 0x10);
    do {
      p_Var6 = p_Var5;
      uVar4 = *(ulong *)(p_Var6 + 0x20);
      if (uVar3 < uVar4) {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x10);
      }
      else {
        p_Var5 = *(_Rb_tree_node_base **)(p_Var6 + 0x18);
      }
    } while (p_Var5 != (_Rb_tree_node_base *)0x0);
    if (uVar3 < uVar4) goto LAB_0010bf18;
    p_Var5 = p_Var6;
    if (uVar3 <= uVar4) goto LAB_0010bee1;
  }
  p_Var5 = p_Var6;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = (_Rb_tree_node_base *)0x0;
LAB_0010bee1:
    if (*(long **)(auVar9._0_8_ + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(auVar9._0_8_ + 0x28) + 8))();
    }
    *(undefined8 *)(auVar9._0_8_ + 0x28) = 0;
    operator_delete(auVar9._0_8_);
    auVar8._8_8_ = 0;
    auVar8._0_8_ = p_Var5;
    return auVar8;
  }
LAB_0010bf50:
  if (p_Var1 == p_Var5) {
    bVar7 = true;
  }
  else {
    bVar7 = *(ulong *)(auVar9._0_8_ + 0x20) < *(ulong *)(p_Var5 + 0x20);
  }
  std::_Rb_tree_insert_and_rebalance(bVar7,auVar9._0_8_,p_Var5,p_Var1);
  *(long *)(this + 0x28) = *(long *)(this + 0x28) + 1;
  auVar9._8_8_ = 1;
  return auVar9;
}



