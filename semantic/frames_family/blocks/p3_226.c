
void FUN_00111200(long *param_1)

{
  undefined8 *puVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  void *__dest;
  void *pvVar5;
  long lVar6;
  size_t sVar7;
  void *pvVar8;
  undefined1 uVar9;
  void *pvVar10;
  ulong __n;
  long *plVar11;
  size_t __n_00;
  ulong local_68;
  undefined8 *local_58 [2];
  code *local_48;
  long lStack_40;
  
  param_1 = (long *)*param_1;
  lVar6 = *param_1;
  lVar3 = param_1[1];
  plVar11 = *(long **)(lVar6 + 0x48);
  pvVar8 = (void *)**(undefined8 **)(lVar6 + 0x40);
  pvVar5 = (void *)plVar11[1];
  if (pvVar8 != (void *)((long)pvVar8 + lVar3)) {
    __n = ((long)pvVar8 + lVar3) - (long)pvVar8;
    if ((ulong)(plVar11[2] - (long)pvVar5) < __n) {
      pvVar10 = (void *)*plVar11;
      sVar7 = (long)pvVar5 - (long)pvVar10;
      if (~sVar7 < __n) {
        std::__throw_length_error("vector::_M_range_insert");
        goto LAB_00111527;
      }
      local_68 = 0xffffffffffffffff;
      uVar4 = sVar7;
      if (sVar7 <= __n) {
        uVar4 = __n;
      }
      if ((CARRY8(uVar4,sVar7)) || (local_68 = uVar4 + sVar7, uVar4 + sVar7 != 0)) {
        __dest = operator_new(local_68);
        pvVar10 = (void *)*plVar11;
        sVar7 = (long)pvVar5 - (long)pvVar10;
      }
      else {
        local_68 = 0;
        __dest = (void *)0x0;
      }
      if (sVar7 != 0) {
        memmove(__dest,pvVar10,sVar7);
      }
      pvVar10 = (void *)(sVar7 + (long)__dest);
      if (__n != 0) {
        pvVar10 = memmove(pvVar10,pvVar8,__n);
      }
      __n_00 = plVar11[1] - (long)pvVar5;
      sVar7 = 0;
      if (__n_00 != 0) {
        memmove((void *)(__n + (long)pvVar10),pvVar5,__n_00);
        sVar7 = __n_00;
      }
      if ((void *)*plVar11 != (void *)0x0) {
        operator_delete((void *)*plVar11);
      }
      *plVar11 = (long)__dest;
      lVar6 = *param_1;
      plVar11[1] = (long)(__n + (long)pvVar10) + sVar7;
      plVar11[2] = (long)__dest + local_68;
      plVar11 = *(long **)(lVar6 + 0x40);
      pvVar5 = (void *)*plVar11;
      pvVar8 = (void *)((long)pvVar5 + param_1[1]);
    }
    else {
      if (__n != 0) {
        memmove(pvVar5,pvVar8,__n);
        pvVar5 = (void *)plVar11[1];
        lVar3 = param_1[1];
        lVar6 = *param_1;
      }
      plVar11[1] = (long)pvVar5 + __n;
      plVar11 = *(long **)(lVar6 + 0x40);
      pvVar5 = (void *)*plVar11;
      pvVar8 = (void *)((long)pvVar5 + lVar3);
    }
    if (pvVar8 != pvVar5) {
      lVar6 = 0;
      if ((pvVar8 != (void *)plVar11[1]) && (sVar7 = plVar11[1] - (long)pvVar8, sVar7 != 0)) {
        pvVar5 = memmove(pvVar5,pvVar8,sVar7);
        lVar6 = plVar11[1] - (long)pvVar8;
      }
      plVar11[1] = (long)pvVar5 + lVar6;
    }
  }
  if ((char)param_1[2] == '\0') {
    local_48 = (code *)0x0;
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(local_58,param_1 + 3,2);
      local_48 = (code *)param_1[5];
      lStack_40 = param_1[6];
    }
    WSConn::read_head((WSConn *)*param_1,local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)(local_58,local_58,3);
      return;
    }
  }
  else {
    lVar6 = *param_1;
    uVar9 = 0;
    if (*(char *)(lVar6 + 0x58) != '\0') {
      uVar9 = *(undefined1 *)(lVar6 + 0x59);
    }
    cVar2 = FUN_0010ef80(lVar6 + 0x48,uVar9,*(undefined8 *)(lVar6 + 0x60));
    if (cVar2 != '\0') {
      if (*(int *)((long)param_1 + 0x14) == 1) {
        local_58[0] = *(undefined8 **)(*param_1 + 0x48);
        *(undefined8 *)(*param_1 + 0x48) = 0;
        if (param_1[5] == 0) {
LAB_00111527:
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      else {
        if (*(int *)((long)param_1 + 0x14) != 8) {
          return;
        }
        if (param_1[5] == 0) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        local_58[0] = (undefined8 *)0x0;
        (*(code *)param_1[6])(param_1 + 3,local_58);
      }
      puVar1 = local_58[0];
      if (local_58[0] != (undefined8 *)0x0) {
        if ((void *)*local_58[0] != (void *)0x0) {
          operator_delete((void *)*local_58[0]);
        }
        operator_delete(puVar1);
      }
    }
  }
  return;
}



