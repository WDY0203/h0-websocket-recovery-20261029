
/* std::_Rb_tree<int, std::pair<int const, int>, std::_Select1st<std::pair<int const, int> >,
   std::less<int>, std::allocator<std::pair<int const, int> >
   >::_M_get_insert_hint_unique_pos(std::_Rb_tree_const_iterator<std::pair<int const, int> >, int
   const&) */

undefined1  [16] __thiscall
std::
_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
::_M_get_insert_hint_unique_pos
          (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
           *this,_Rb_tree_node_base *param_2,int *param_3)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  int iVar5;
  int iVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  p_Var4 = (_Rb_tree_node_base *)(this + 8);
  if (p_Var4 != param_2) {
    iVar6 = *param_3;
    if (iVar6 < *(int *)(param_2 + 0x20)) {
      p_Var2 = *(_Rb_tree_node_base **)(this + 0x18);
      p_Var3 = p_Var2;
      if (p_Var2 == param_2) goto LAB_0010bfe8;
      p_Var1 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(param_2);
      if (*(int *)(p_Var1 + 0x20) < iVar6) {
        p_Var3 = (_Rb_tree_node_base *)0x0;
        p_Var2 = p_Var1;
        if (*(long *)(p_Var1 + 0x18) != 0) {
          p_Var3 = param_2;
          p_Var2 = param_2;
        }
        goto LAB_0010bfe8;
      }
      p_Var3 = *(_Rb_tree_node_base **)(this + 0x10);
      if (*(_Rb_tree_node_base **)(this + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c110:
        if (p_Var2 == p_Var4) goto LAB_0010c12b;
        p_Var1 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var4);
        iVar5 = *(int *)(p_Var1 + 0x20);
      }
      else {
        do {
          p_Var4 = p_Var3;
          iVar5 = *(int *)(p_Var4 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var4 + 0x18);
          }
        } while (p_Var3 != (_Rb_tree_node_base *)0x0);
        p_Var1 = p_Var4;
        if (iVar6 < iVar5) goto LAB_0010c110;
      }
      p_Var3 = (_Rb_tree_node_base *)0x0;
      p_Var2 = p_Var4;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var1;
        p_Var2 = (_Rb_tree_node_base *)0x0;
      }
      goto LAB_0010bfe8;
    }
    if (iVar6 <= *(int *)(param_2 + 0x20)) {
      auVar9._8_8_ = 0;
      auVar9._0_8_ = param_2;
      return auVar9;
    }
    p_Var2 = *(_Rb_tree_node_base **)(this + 0x20);
    if (p_Var2 == param_2) {
LAB_0010c12b:
      p_Var3 = (_Rb_tree_node_base *)0x0;
    }
    else {
      p_Var2 = (_Rb_tree_node_base *)std::_Rb_tree_increment(param_2);
      if (iVar6 < *(int *)(p_Var2 + 0x20)) {
        p_Var4 = p_Var2;
        if (*(long *)(param_2 + 0x18) == 0) {
          p_Var2 = param_2;
          p_Var4 = (_Rb_tree_node_base *)0x0;
        }
        auVar8._8_8_ = p_Var2;
        auVar8._0_8_ = p_Var4;
        return auVar8;
      }
      p_Var3 = *(_Rb_tree_node_base **)(this + 0x10);
      p_Var2 = p_Var4;
      if (*(_Rb_tree_node_base **)(this + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c1e0:
        if (*(_Rb_tree_node_base **)(this + 0x18) == p_Var2) goto LAB_0010c12b;
        p_Var4 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var2);
        iVar5 = *(int *)(p_Var4 + 0x20);
      }
      else {
        do {
          p_Var2 = p_Var3;
          iVar5 = *(int *)(p_Var2 + 0x20);
          if (iVar6 < iVar5) {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x10);
          }
          else {
            p_Var3 = *(_Rb_tree_node_base **)(p_Var2 + 0x18);
          }
        } while (p_Var3 != (_Rb_tree_node_base *)0x0);
        p_Var4 = p_Var2;
        if (iVar6 < iVar5) goto LAB_0010c1e0;
      }
      p_Var3 = (_Rb_tree_node_base *)0x0;
      if (iVar6 <= iVar5) {
        p_Var3 = p_Var4;
        p_Var2 = (_Rb_tree_node_base *)0x0;
      }
    }
    goto LAB_0010bfe8;
  }
  if ((*(long *)(this + 0x28) != 0) &&
     (*(int *)(*(_Rb_tree_node_base **)(this + 0x20) + 0x20) < *param_3)) {
    p_Var3 = (_Rb_tree_node_base *)0x0;
    p_Var2 = *(_Rb_tree_node_base **)(this + 0x20);
    goto LAB_0010bfe8;
  }
  if (*(_Rb_tree_node_base **)(this + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0010c1b7:
    if (*(_Rb_tree_node_base **)(this + 0x18) == p_Var4) {
      p_Var3 = (_Rb_tree_node_base *)0x0;
      p_Var2 = p_Var4;
      goto LAB_0010bfe8;
    }
    p_Var3 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var4);
    iVar5 = *(int *)(p_Var3 + 0x20);
    iVar6 = *param_3;
  }
  else {
    iVar6 = *param_3;
    p_Var4 = *(_Rb_tree_node_base **)(this + 0x10);
    do {
      p_Var3 = p_Var4;
      iVar5 = *(int *)(p_Var3 + 0x20);
      if (iVar6 < iVar5) {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x10);
      }
      else {
        p_Var4 = *(_Rb_tree_node_base **)(p_Var3 + 0x18);
      }
    } while (p_Var4 != (_Rb_tree_node_base *)0x0);
    p_Var4 = p_Var3;
    if (iVar6 < iVar5) goto LAB_0010c1b7;
  }
  p_Var2 = (_Rb_tree_node_base *)0x0;
  if (iVar5 < iVar6) {
    p_Var3 = p_Var2;
    p_Var2 = p_Var4;
  }
LAB_0010bfe8:
  auVar7._8_8_ = p_Var2;
  auVar7._0_8_ = p_Var3;
  return auVar7;
}



