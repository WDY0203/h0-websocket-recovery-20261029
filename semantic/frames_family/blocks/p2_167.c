
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_001085c0(double param_1,undefined4 *param_2,EventLoop2 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  EventLoop2 *pEVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 local_98 [2];
  undefined8 local_90;
  undefined4 local_88 [2];
  long local_80;
  undefined8 *local_78 [2];
  code *local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  
  if ((param_3 == (EventLoop2 *)0x0) || (*(long *)(param_3 + 0x68) == 0)) {
    *param_2 = 0xffffffff;
    std::string::string((string *)(param_2 + 2),"",(allocator *)&local_58);
  }
  else {
    local_98[0] = 0xffffffff;
    std::string::string((string *)&local_90,"",(allocator *)&local_58);
    *(long *)(param_3 + 0xe8) = (long)(param_1 * _DAT_0011f630);
    uVar8 = current_time();
    *(undefined8 *)(param_3 + 0xe0) = uVar8;
    local_68 = (code *)0x0;
    local_78[0] = operator_new(0x10);
    *local_78[0] = param_3;
    local_78[0][1] = local_98;
    local_48 = (code *)0x0;
    local_60 = FUN_00107d20;
    local_68 = FUN_00107900;
    FUN_00107900((allocator *)&local_58,local_78,2);
    uVar8 = *(undefined8 *)(param_3 + 200);
    uVar3 = *(undefined8 *)(param_3 + 0xc0);
    local_48 = *(code **)(param_3 + 0xd0);
    *(undefined8 *)(param_3 + 0xc0) = local_58;
    *(undefined8 *)(param_3 + 200) = local_50;
    *(code **)(param_3 + 0xd0) = local_68;
    local_40 = *(undefined8 *)(param_3 + 0xd8);
    *(code **)(param_3 + 0xd8) = local_60;
    local_58 = uVar3;
    local_50 = uVar8;
    if (local_48 != (code *)0x0) {
      (*local_48)((allocator *)&local_58,(allocator *)&local_58,3);
    }
    pEVar4 = *(EventLoop2 **)(param_3 + 0xa8);
    param_3[0xb8] = (EventLoop2)0x1;
    if (pEVar4 != param_3 + 0xa8) {
      uVar2 = *(undefined4 *)(pEVar4 + 0x10);
      lVar5 = *(long *)(pEVar4 + 0x18);
      *(undefined **)(pEVar4 + 0x18) = PTR__S_empty_rep_storage_00324fa0 + 0x18;
      std::__detail::_List_node_base::_M_unhook();
      lVar6 = *(long *)(pEVar4 + 0x18);
      if ((allocator *)(lVar6 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(lVar6 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar7 = *(int *)(lVar6 + -8);
          *(int *)(lVar6 + -8) = iVar7 + -1;
        }
        else {
          LOCK();
          iVar7 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar7 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(lVar6 + -0x18));
        }
      }
      operator_delete(pEVar4);
      param_3[0xb8] = (EventLoop2)0x0;
      if (*(long *)(param_3 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_function_call();
      }
      local_88[0] = uVar2;
      local_80 = lVar5;
      (**(code **)(param_3 + 0xd8))(param_3 + 0xc0,local_88);
      if ((allocator *)(local_80 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(local_80 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar7 = *(int *)(local_80 + -8);
          *(int *)(local_80 + -8) = iVar7 + -1;
        }
        else {
          LOCK();
          iVar7 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar7 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(local_80 + -0x18));
        }
      }
    }
    if (local_68 != (code *)0x0) {
      (*local_68)(local_78,local_78,3);
    }
    local_48 = (code *)0x0;
    EventLoop2::run(param_3,(allocator *)&local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)((allocator *)&local_58,(allocator *)&local_58,3);
    }
    *param_2 = local_98[0];
    *(undefined8 *)(param_2 + 2) = local_90;
  }
  return param_2;
}



