
void FUN_001091e0(undefined8 *param_1,long param_2)

{
  long *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined *puVar4;
  long lVar5;
  WSConn *pWVar6;
  undefined8 *puVar7;
  long lVar8;
  long lVar9;
  WSConn *local_58 [2];
  WSConn *local_48 [2];
  code *local_38;
  code *local_30;
  
  param_1 = (undefined8 *)*param_1;
  pWVar6 = operator_new(0x70);
  *(undefined4 *)(pWVar6 + 0x10) = 0;
  *(long *)(pWVar6 + 0x18) = 0;
  *(long *)(pWVar6 + 0x30) = 0;
  *(long *)(pWVar6 + 0x38) = param_2;
  *(long *)(pWVar6 + 0x40) = 0;
  *(long *)(pWVar6 + 0x48) = 0;
  *(WSConn **)(pWVar6 + 0x20) = pWVar6 + 0x10;
  *(WSConn **)(pWVar6 + 0x28) = pWVar6 + 0x10;
  puVar4 = PTR_vtable_00324f30;
  *(long *)(pWVar6 + 0x50) = 0;
  pWVar6[0x58] = (WSConn)0x0;
  *(undefined **)pWVar6 = puVar4 + 0x10;
  puVar7 = operator_new(0x18);
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar2 = *(undefined8 **)(pWVar6 + 0x40);
  *(undefined8 **)(pWVar6 + 0x40) = puVar7;
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2);
  }
  lVar8 = param_2 + 0x10;
  lVar5 = *(long *)(param_2 + 0x18);
  local_58[0] = pWVar6;
  if (*(long *)(param_2 + 0x18) != 0) {
    do {
      while (lVar9 = lVar5, pWVar6 <= *(WSConn **)(lVar9 + 0x20)) {
        lVar8 = lVar9;
        lVar5 = *(long *)(lVar9 + 0x10);
        if (*(long *)(lVar9 + 0x10) == 0) goto LAB_001092cb;
      }
      plVar1 = (long *)(lVar9 + 0x18);
      lVar9 = lVar8;
      lVar5 = *plVar1;
    } while (*plVar1 != 0);
LAB_001092cb:
    if ((param_2 + 0x10 != lVar9) && (*(WSConn **)(lVar9 + 0x20) <= pWVar6)) goto LAB_001092d6;
  }
  local_48[0] = pWVar6;
  std::
  _Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
  ::_M_emplace_unique<WSConn*&,std::unique_ptr<Root,std::default_delete<Root>>>
            ((_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
              *)(param_2 + 8),local_58,(unique_ptr *)local_48);
  if (local_48[0] != (WSConn *)0x0) {
    (**(code **)(*(long *)local_48[0] + 8))();
  }
LAB_001092d6:
  pWVar6 = local_58[0];
  uVar3 = *param_1;
  local_38 = (code *)0x0;
  local_48[0] = operator_new(0x10);
  *(undefined8 *)local_48[0] = uVar3;
  *(WSConn **)(local_48[0] + 8) = pWVar6;
  local_30 = FUN_00108d10;
  local_38 = FUN_00107c30;
  WSConn::connect(pWVar6,local_48);
  if (local_38 != (code *)0x0) {
    (*local_38)(local_48,local_48,3);
  }
  return;
}



