
/* WARNING: Switch with 1 destination removed at 0x00106f70 */

long __thiscall
std::
_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
::erase(_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
        *this,int *param_1)

{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  int iVar3;
  _Rb_tree_node *p_Var4;
  long lVar5;
  _Rb_tree_node *p_Var6;
  long lVar7;
  _Rb_tree_node_base *p_Var8;
  void *pvVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  
  p_Var1 = (_Rb_tree_node_base *)(this + 8);
  p_Var4 = *(_Rb_tree_node **)(this + 0x10);
  p_Var11 = p_Var1;
  p_Var13 = p_Var1;
  if (p_Var4 != (_Rb_tree_node *)0x0) {
    iVar3 = *param_1;
    p_Var6 = p_Var4;
    do {
      while (p_Var8 = (_Rb_tree_node_base *)p_Var6, iVar3 <= *(int *)(p_Var8 + 0x20)) {
        if (*(int *)(p_Var8 + 0x20) <= iVar3) {
          p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
          p_Var12 = *(_Rb_tree_node_base **)(p_Var8 + 0x18);
          while (p_Var13 = p_Var11, p_Var12 != (_Rb_tree_node_base *)0x0) {
            while (p_Var13 = p_Var12, iVar3 < *(int *)(p_Var13 + 0x20)) {
              p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var11 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010b800;
            }
            p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
          }
LAB_0010b800:
          do {
            p_Var11 = p_Var8;
            if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
            iVar2 = *(int *)(p_Var10 + 0x20);
            while (p_Var11 = p_Var10, iVar3 <= iVar2) {
              p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
              if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
              iVar2 = *(int *)(p_Var10 + 0x20);
              p_Var8 = p_Var11;
            }
            p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
          } while( true );
        }
        p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var11 = p_Var8;
        p_Var13 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
      }
      p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x18);
      p_Var13 = p_Var11;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x18) != (_Rb_tree_node_base *)0x0);
  }
LAB_0010b763:
  lVar5 = *(long *)(this + 0x28);
  if ((p_Var11 == *(_Rb_tree_node_base **)(this + 0x18)) && (p_Var1 == p_Var13)) {
    _M_erase(this,p_Var4);
    *(_Rb_tree_node_base **)(this + 0x18) = p_Var1;
    *(undefined8 *)(this + 0x10) = 0;
    *(_Rb_tree_node_base **)(this + 0x20) = p_Var1;
    *(undefined8 *)(this + 0x28) = 0;
    lVar7 = lVar5;
  }
  else {
    lVar7 = 0;
    if (p_Var11 != p_Var13) {
      do {
        p_Var8 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var11);
        pvVar9 = (void *)std::_Rb_tree_rebalance_for_erase(p_Var11,p_Var1);
        operator_delete(pvVar9);
        lVar7 = *(long *)(this + 0x28);
        *(long *)(this + 0x28) = lVar7 + -1;
        p_Var11 = p_Var8;
      } while (p_Var8 != p_Var13);
      lVar7 = lVar5 - (lVar7 + -1);
    }
  }
  return lVar7;
}



