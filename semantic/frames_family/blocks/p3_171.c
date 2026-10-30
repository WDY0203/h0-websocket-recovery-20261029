
void FUN_00108d10(long *param_1)

{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  long *plVar8;
  _Rb_tree_node_base *p_Var9;
  _Rb_tree_node_base *p_Var10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  _Rb_tree_node_base *p_Var14;
  bool bVar15;
  long *local_78;
  undefined8 local_70;
  code *local_68;
  code *pcStack_60;
  undefined8 *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  
  param_1 = (long *)*param_1;
  lVar3 = *param_1;
  lVar12 = param_1[1];
  *(undefined8 *)(lVar3 + 0xe0) = 0;
  *(long *)(lVar3 + 0x68) = lVar12;
  *(undefined8 *)(lVar3 + 0xe8) = 0;
  plVar8 = operator_new(0x18);
  lVar12 = *param_1;
  plVar8[2] = lVar3;
  *(undefined1 *)(plVar8 + 1) = 1;
  *plVar8 = (long)&PTR_FUN_00324730;
  lVar3 = *(long *)(lVar12 + 0x68);
  p_Var2 = (_Rb_tree_node_base *)(lVar3 + 0x10);
  p_Var10 = p_Var2;
  p_Var14 = *(_Rb_tree_node_base **)(lVar3 + 0x18);
  if (*(_Rb_tree_node_base **)(lVar3 + 0x18) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var9 = p_Var14, plVar8 <= *(long **)(p_Var9 + 0x20)) {
        p_Var10 = p_Var9;
        p_Var14 = *(_Rb_tree_node_base **)(p_Var9 + 0x10);
        if (*(_Rb_tree_node_base **)(p_Var9 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_00108da3;
      }
      p_Var1 = p_Var9 + 0x18;
      p_Var9 = p_Var10;
      p_Var14 = *(_Rb_tree_node_base **)p_Var1;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_00108da3:
    if ((p_Var2 != p_Var9) && (*(long **)(p_Var9 + 0x20) <= plVar8)) goto LAB_00108db9;
  }
  p_Var10 = operator_new(0x30);
  if (p_Var10 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var10 = 0;
    *(undefined8 *)(p_Var10 + 8) = 0;
    *(undefined8 *)(p_Var10 + 0x10) = 0;
    *(undefined8 *)(p_Var10 + 0x18) = 0;
    *(long **)(p_Var10 + 0x20) = plVar8;
    *(long **)(p_Var10 + 0x28) = plVar8;
    plVar8 = (long *)0x0;
  }
  p_Var14 = p_Var2;
  if (*(_Rb_tree_node_base **)(lVar3 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00109082:
    if (*(_Rb_tree_node_base **)(lVar3 + 0x20) != p_Var14) {
      lVar12 = std::_Rb_tree_decrement(p_Var14);
      uVar13 = *(ulong *)(lVar12 + 0x20);
      uVar11 = *(ulong *)(p_Var10 + 0x20);
      goto LAB_00109045;
    }
LAB_0010909b:
    if (p_Var14 == (_Rb_tree_node_base *)0x0) goto LAB_0010904a;
    if (p_Var2 == p_Var14) {
      bVar15 = true;
    }
    else {
      bVar15 = *(ulong *)(p_Var10 + 0x20) < *(ulong *)(p_Var14 + 0x20);
    }
    std::_Rb_tree_insert_and_rebalance(bVar15,p_Var10,p_Var14,p_Var2);
    *(long *)(lVar3 + 0x30) = *(long *)(lVar3 + 0x30) + 1;
  }
  else {
    uVar11 = *(ulong *)(p_Var10 + 0x20);
    p_Var9 = *(_Rb_tree_node_base **)(lVar3 + 0x18);
    do {
      p_Var14 = p_Var9;
      uVar13 = *(ulong *)(p_Var14 + 0x20);
      if (uVar11 < uVar13) {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var14 + 0x10);
      }
      else {
        p_Var9 = *(_Rb_tree_node_base **)(p_Var14 + 0x18);
      }
    } while (p_Var9 != (_Rb_tree_node_base *)0x0);
    if (uVar11 < uVar13) goto LAB_00109082;
LAB_00109045:
    if (uVar13 < uVar11) goto LAB_0010909b;
LAB_0010904a:
    if (*(long **)(p_Var10 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(p_Var10 + 0x28) + 8))();
    }
    *(undefined8 *)(p_Var10 + 0x28) = 0;
    operator_delete(p_Var10);
  }
  if (plVar8 != (long *)0x0) {
    (**(code **)(*plVar8 + 8))(plVar8);
  }
  lVar12 = *param_1;
LAB_00108db9:
  local_68 = (code *)0x0;
  local_78 = operator_new(8);
  *local_78 = lVar12;
  pcStack_60 = FUN_001083a0;
  local_68 = FUN_00107cc0;
  lVar3 = *(long *)(*(long *)(*param_1 + 0x68) + 0x38);
  local_48 = (code *)0x0;
  FUN_00107cc0(&local_58,&local_78,2);
  puVar4 = *(undefined8 **)(lVar3 + 0xb0);
  uVar5 = *(undefined8 *)(lVar3 + 0xb8);
  local_48 = *(code **)(lVar3 + 0xc0);
  *(undefined8 **)(lVar3 + 0xb0) = local_58;
  *(undefined8 *)(lVar3 + 0xb8) = local_50;
  puStack_40 = *(undefined **)(lVar3 + 200);
  *(code **)(lVar3 + 0xc0) = local_68;
  *(code **)(lVar3 + 200) = pcStack_60;
  local_58 = puVar4;
  local_50 = uVar5;
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  lVar3 = *param_1;
  local_68 = (code *)0x0;
  local_78 = operator_new(8);
  *local_78 = lVar3;
  local_48 = (code *)0x0;
  pcStack_60 = FUN_00109450;
  local_68 = FUN_00107d40;
  local_58 = operator_new(0x20);
  pcVar7 = local_68;
  local_58[2] = 0;
  plVar8 = (long *)*local_58;
  uVar5 = local_58[1];
  *local_58 = local_78;
  local_58[1] = local_70;
  local_68 = (code *)0x0;
  uVar6 = local_58[3];
  local_58[2] = pcVar7;
  local_58[3] = pcStack_60;
  puStack_40 = PTR__M_invoke_00324fe0;
  local_48 = (code *)PTR__M_manager_00324f88;
  local_78 = plVar8;
  local_70 = uVar5;
  pcStack_60 = (code *)uVar6;
  WSConn::recv(*(WSConn **)(*param_1 + 0x68),&local_58);
  if (local_48 != (code *)0x0) {
    (*local_48)(&local_58,&local_58,3);
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  EventLoop2::exit((EventLoop2 *)*param_1,1);
  return;
}



