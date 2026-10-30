
void FUN_00110e50(long *param_1)

{
  undefined4 *__src;
  long *plVar1;
  char cVar2;
  ulong uVar3;
  undefined4 *__dest;
  void *pvVar4;
  size_t sVar5;
  ulong uVar6;
  undefined1 uVar7;
  void *pvVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  undefined4 local_68 [4];
  undefined8 *local_58 [2];
  code *local_48;
  long lStack_40;
  
  param_1 = (long *)*param_1;
  lVar9 = *param_1;
  uVar3 = param_1[1];
  puVar11 = *(undefined8 **)(lVar9 + 0x40);
  plVar1 = *(long **)(lVar9 + 0x48);
  __dest = (undefined4 *)*puVar11;
  pvVar4 = (void *)plVar1[1];
  local_68[0] = *__dest;
  pvVar8 = (void *)*plVar1;
  uVar10 = (long)pvVar4 - (long)pvVar8;
  uVar6 = uVar10 + uVar3;
  if (uVar10 < uVar6) {
    uVar6 = 0;
    if (uVar3 != 0) {
      if ((ulong)(plVar1[2] - (long)pvVar4) < uVar3) {
        if (~uVar10 < uVar3) {
          std::__throw_length_error("vector::_M_default_append");
          goto LAB_001111e1;
        }
        uVar6 = uVar3;
        if (uVar3 <= uVar10) {
          uVar6 = uVar10;
        }
        uVar12 = 0xffffffffffffffff;
        if ((CARRY8(uVar6,uVar10)) || (uVar12 = uVar6 + uVar10, uVar6 + uVar10 != 0)) {
          pvVar4 = operator_new(uVar12);
          pvVar8 = (void *)*plVar1;
          sVar5 = plVar1[1] - (long)pvVar8;
        }
        else {
          uVar12 = 0;
          pvVar4 = (void *)0x0;
          sVar5 = uVar10;
        }
        if (sVar5 != 0) {
          memmove(pvVar4,pvVar8,sVar5);
        }
        pvVar8 = (void *)((long)pvVar4 + sVar5);
        memset(pvVar8,0,(uVar3 + (long)pvVar8) - (long)pvVar8);
        if ((void *)*plVar1 != (void *)0x0) {
          operator_delete((void *)*plVar1);
        }
        lVar9 = *param_1;
        plVar1[1] = uVar3 + (long)pvVar8;
        *plVar1 = (long)pvVar4;
        plVar1[2] = uVar12 + (long)pvVar4;
        uVar3 = param_1[1];
        puVar11 = *(undefined8 **)(lVar9 + 0x40);
        __dest = (undefined4 *)*puVar11;
      }
      else {
        memset(pvVar4,0,uVar3);
        lVar9 = *param_1;
        plVar1[1] = plVar1[1] + uVar3;
        uVar3 = param_1[1];
        puVar11 = *(undefined8 **)(lVar9 + 0x40);
        __dest = (undefined4 *)*puVar11;
      }
      goto LAB_00110ea8;
    }
  }
  else {
    if (uVar6 < uVar10) {
      plVar1[1] = (long)pvVar8 + uVar6;
      lVar9 = *param_1;
      puVar11 = *(undefined8 **)(lVar9 + 0x40);
      __dest = (undefined4 *)*puVar11;
    }
LAB_00110ea8:
    uVar6 = 0;
    if (uVar3 != 0) {
      uVar3 = 0;
      while( true ) {
        *(byte *)(uVar10 + **(long **)(lVar9 + 0x48) + uVar3) =
             *(byte *)((long)__dest + uVar3 + 4) ^
             *(byte *)((long)local_68 + (ulong)((uint)uVar3 & 3));
        uVar6 = param_1[1];
        uVar3 = uVar3 + 1;
        if (uVar6 <= uVar3) break;
        lVar9 = *param_1;
        __dest = (undefined4 *)**(undefined8 **)(lVar9 + 0x40);
      }
      puVar11 = *(undefined8 **)(*param_1 + 0x40);
      __dest = (undefined4 *)*puVar11;
    }
  }
  __src = (undefined4 *)((long)__dest + uVar6 + 4);
  if (__src != __dest) {
    lVar9 = 0;
    if ((__src != (undefined4 *)puVar11[1]) && (sVar5 = (long)puVar11[1] - (long)__src, sVar5 != 0))
    {
      __dest = memmove(__dest,__src,sVar5);
      lVar9 = puVar11[1] - (long)__src;
    }
    puVar11[1] = lVar9 + (long)__dest;
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
    lVar9 = *param_1;
    uVar7 = 0;
    if (*(char *)(lVar9 + 0x58) != '\0') {
      uVar7 = *(undefined1 *)(lVar9 + 0x59);
    }
    cVar2 = FUN_0010ef80(lVar9 + 0x48,uVar7,*(undefined8 *)(lVar9 + 0x60));
    if (cVar2 != '\0') {
      if (*(int *)((long)param_1 + 0x14) == 1) {
        local_58[0] = *(undefined8 **)(*param_1 + 0x48);
        *(undefined8 *)(*param_1 + 0x48) = 0;
        if (param_1[5] == 0) {
LAB_001111e1:
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
      puVar11 = local_58[0];
      if (local_58[0] != (undefined8 *)0x0) {
        if ((void *)*local_58[0] != (void *)0x0) {
          operator_delete((void *)*local_58[0]);
        }
        operator_delete(puVar11);
      }
    }
  }
  return;
}



