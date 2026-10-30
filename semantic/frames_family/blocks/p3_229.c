
void FUN_00111d50(long *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  void *__src;
  ulong uVar2;
  void *__dest;
  undefined8 uVar3;
  WSConn *pWVar4;
  size_t sVar5;
  void *__src_00;
  void *pvVar6;
  long *plVar7;
  ulong uVar8;
  size_t __n;
  ulong local_68;
  undefined1 local_58 [16];
  code *local_48;
  long lStack_40;
  
  puVar1 = (undefined8 *)*param_2;
  *param_2 = 0;
  param_1 = (long *)*param_1;
  if (puVar1 == (undefined8 *)0x0) {
    WSConn::exit((WSConn *)*param_1);
    return;
  }
  pWVar4 = (WSConn *)*param_1;
  __src = (void *)*puVar1;
  plVar7 = *(long **)(pWVar4 + 0x40);
  __src_00 = (void *)plVar7[1];
  if (__src != (void *)puVar1[1]) {
    uVar8 = (long)puVar1[1] - (long)__src;
    if ((ulong)(plVar7[2] - (long)__src_00) < uVar8) {
      pvVar6 = (void *)*plVar7;
      sVar5 = (long)__src_00 - (long)pvVar6;
      if (~sVar5 < uVar8) {
        uVar3 = std::__throw_length_error("vector::_M_range_insert");
        FUN_00107812(puVar1);
                    /* WARNING: Subroutine does not return */
        _Unwind_Resume(uVar3);
      }
      local_68 = 0xffffffffffffffff;
      uVar2 = sVar5;
      if (sVar5 <= uVar8) {
        uVar2 = uVar8;
      }
      if ((CARRY8(uVar2,sVar5)) || (local_68 = uVar2 + sVar5, uVar2 + sVar5 != 0)) {
        __dest = operator_new(local_68);
        pvVar6 = (void *)*plVar7;
        sVar5 = (long)__src_00 - (long)pvVar6;
      }
      else {
        local_68 = 0;
        __dest = (void *)0x0;
      }
      if (sVar5 != 0) {
        __dest = memmove(__dest,pvVar6,sVar5);
      }
      pvVar6 = (void *)(sVar5 + (long)__dest);
      if (uVar8 != 0) {
        pvVar6 = memmove(pvVar6,__src,uVar8);
      }
      __n = plVar7[1] - (long)__src_00;
      sVar5 = 0;
      if (__n != 0) {
        memmove((void *)(uVar8 + (long)pvVar6),__src_00,__n);
        sVar5 = __n;
      }
      if ((void *)*plVar7 != (void *)0x0) {
        operator_delete((void *)*plVar7);
      }
      *plVar7 = (long)__dest;
      pWVar4 = (WSConn *)*param_1;
      plVar7[1] = (long)(uVar8 + (long)pvVar6) + sVar5;
      plVar7[2] = (long)__dest + local_68;
      plVar7 = *(long **)(pWVar4 + 0x40);
      __src_00 = (void *)plVar7[1];
    }
    else {
      if (uVar8 != 0) {
        memmove(__src_00,__src,uVar8);
        __src_00 = (void *)plVar7[1];
        pWVar4 = (WSConn *)*param_1;
      }
      plVar7[1] = (long)__src_00 + uVar8;
      plVar7 = *(long **)(pWVar4 + 0x40);
      __src_00 = (void *)plVar7[1];
    }
  }
  uVar8 = param_1[1];
  if ((ulong)((long)__src_00 - *plVar7) < uVar8) {
    local_48 = (code *)0x0;
    if ((code *)param_1[4] != (code *)0x0) {
      (*(code *)param_1[4])(local_58,param_1 + 2,2);
      local_48 = (code *)param_1[4];
      lStack_40 = param_1[5];
      uVar8 = param_1[1];
      pWVar4 = (WSConn *)*param_1;
    }
    WSConn::recv_more(pWVar4,uVar8,local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)(local_58,local_58,3);
    }
  }
  else {
    if (param_1[4] == 0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*(code *)param_1[5])(param_1 + 2);
  }
  if ((void *)*puVar1 != (void *)0x0) {
    operator_delete((void *)*puVar1);
  }
  operator_delete(puVar1);
  return;
}



