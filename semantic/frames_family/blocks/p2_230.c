
void FUN_00111f80(long *param_1,undefined8 *param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  void *__src;
  long *plVar3;
  int iVar4;
  ulong uVar5;
  void *__dest;
  undefined8 uVar6;
  size_t sVar7;
  void *__src_00;
  void *pvVar8;
  ulong __n;
  size_t __n_00;
  ulong local_88;
  long local_68 [2];
  undefined1 local_58 [16];
  code *local_48;
  long lStack_40;
  
  puVar2 = (undefined8 *)*param_2;
  *param_2 = 0;
  param_1 = (long *)*param_1;
  if (puVar2 == (undefined8 *)0x0) {
    WSConn::exit((WSConn *)*param_1);
    return;
  }
  __src = (void *)*puVar2;
  plVar3 = *(long **)(*param_1 + 0x40);
  __src_00 = (void *)plVar3[1];
  if (__src != (void *)puVar2[1]) {
    __n = (long)puVar2[1] - (long)__src;
    if ((ulong)(plVar3[2] - (long)__src_00) < __n) {
      pvVar8 = (void *)*plVar3;
      sVar7 = (long)__src_00 - (long)pvVar8;
      if (~sVar7 < __n) {
        uVar6 = std::__throw_length_error("vector::_M_range_insert");
        FUN_00107772(puVar2);
                    /* WARNING: Subroutine does not return */
        _Unwind_Resume(uVar6);
      }
      local_88 = 0xffffffffffffffff;
      uVar5 = sVar7;
      if (sVar7 <= __n) {
        uVar5 = __n;
      }
      if ((CARRY8(uVar5,sVar7)) || (local_88 = uVar5 + sVar7, uVar5 + sVar7 != 0)) {
        __dest = operator_new(local_88);
        pvVar8 = (void *)*plVar3;
        sVar7 = (long)__src_00 - (long)pvVar8;
      }
      else {
        local_88 = 0;
        __dest = (void *)0x0;
      }
      if (sVar7 != 0) {
        __dest = memmove(__dest,pvVar8,sVar7);
      }
      pvVar8 = (void *)(sVar7 + (long)__dest);
      if (__n != 0) {
        pvVar8 = memmove(pvVar8,__src,__n);
      }
      __n_00 = plVar3[1] - (long)__src_00;
      sVar7 = 0;
      if (__n_00 != 0) {
        memmove((void *)(__n + (long)pvVar8),__src_00,__n_00);
        sVar7 = __n_00;
      }
      if ((void *)*plVar3 != (void *)0x0) {
        operator_delete((void *)*plVar3);
      }
      *plVar3 = (long)__dest;
      plVar3[1] = (long)(__n + (long)pvVar8) + sVar7;
      plVar3[2] = (long)__dest + local_88;
    }
    else {
      if (__n != 0) {
        memmove(__src_00,__src,__n);
        __src_00 = (void *)plVar3[1];
      }
      plVar3[1] = (long)__src_00 + __n;
    }
  }
  local_48 = (code *)0x0;
  if ((code *)param_1[4] != (code *)0x0) {
    (*(code *)param_1[4])(local_58,param_1 + 2,2);
    local_48 = (code *)param_1[4];
    lStack_40 = param_1[5];
  }
  std::string::string((string *)local_68,(string *)(param_1 + 1));
  WSConn::recv_pat((WSConn *)*param_1,(string *)local_68,local_58);
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
  if (local_48 != (code *)0x0) {
    (*local_48)(local_58,local_58,3);
  }
  if ((void *)*puVar2 != (void *)0x0) {
    operator_delete((void *)*puVar2);
  }
  operator_delete(puVar2);
  return;
}



