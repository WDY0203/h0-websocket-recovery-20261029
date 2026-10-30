
void FUN_001093b0(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  allocator *paVar1;
  int *piVar2;
  ulong *puVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long *plVar9;
  ulong *puVar10;
  ulong *puVar11;
  void *pvVar12;
  long lVar13;
  long lVar14;
  code *pcVar15;
  int iVar16;
  ulong *puVar17;
  _List_node_base *p_Var18;
  ulong uVar19;
  long lVar20;
  ulong uVar21;
  allocator *paVar22;
  ulong uVar23;
  allocator local_cb [3];
  ulong *local_c8 [2];
  undefined4 local_b8;
  allocator *local_b0;
  undefined4 local_a8 [2];
  long local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  code *local_68;
  undefined8 uStack_60;
  undefined8 *local_58 [2];
  code *local_48;
  undefined *local_40;
  
  puVar5 = (undefined8 *)*param_3;
  uVar6 = *param_2;
  *param_3 = 0;
  uVar7 = param_2[1];
  *param_2 = local_98;
  local_88 = (code *)param_2[2];
  param_2[1] = local_90;
  param_2[2] = 0;
  uVar8 = param_2[3];
  param_2[3] = uStack_80;
  plVar9 = (long *)*param_1;
  local_98 = uVar6;
  local_90 = uVar7;
  uStack_80 = uVar8;
  if (puVar5 == (undefined8 *)0x0) {
    WSConn::exit(*(WSConn **)(*plVar9 + 0x68));
  }
  else {
    puVar10 = (ulong *)puVar5[1];
    puVar11 = (ulong *)*puVar5;
    if (puVar10 == puVar11) {
      local_c8[0] = (ulong *)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
      paVar22 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
    }
    else {
      uVar23 = (long)puVar10 - (long)puVar11;
      puVar17 = (ulong *)std::string::_Rep::_S_create(uVar23,0,local_cb);
      local_c8[0] = puVar17 + 3;
      if ((uVar23 < 0x10) || (local_c8[0] < puVar11 + 2 && puVar11 < puVar17 + 5)) {
        lVar20 = 0;
        do {
          *(undefined1 *)((long)local_c8[0] + lVar20) = *(undefined1 *)((long)puVar11 + lVar20);
          lVar20 = lVar20 + 1;
        } while (lVar20 != (long)puVar10 - (long)puVar11);
      }
      else {
        lVar20 = 0;
        uVar21 = 0;
        uVar19 = uVar23 >> 4;
        do {
          uVar6 = ((undefined8 *)((long)puVar11 + lVar20))[1];
          uVar21 = uVar21 + 1;
          *(undefined8 *)((long)local_c8[0] + lVar20) = *(undefined8 *)((long)puVar11 + lVar20);
          ((undefined8 *)((long)local_c8[0] + lVar20))[1] = uVar6;
          lVar20 = lVar20 + 0x10;
        } while (uVar21 < uVar19);
        puVar11 = puVar11 + uVar19 * 2;
        puVar3 = local_c8[0] + uVar19 * 2;
        if (((((((uVar19 * 0x10 != uVar23) &&
                (*(char *)puVar3 = (char)*puVar11, puVar10 != (ulong *)((long)puVar11 + 1))) &&
               (*(undefined1 *)((long)puVar3 + 1) = *(undefined1 *)((long)puVar11 + 1),
               puVar10 != (ulong *)((long)puVar11 + 2))) &&
              ((*(undefined1 *)((long)puVar3 + 2) = *(undefined1 *)((long)puVar11 + 2),
               puVar10 != (ulong *)((long)puVar11 + 3) &&
               (*(undefined1 *)((long)puVar3 + 3) = *(undefined1 *)((long)puVar11 + 3),
               puVar10 != (ulong *)((long)puVar11 + 4))))) &&
             ((*(undefined1 *)((long)puVar3 + 4) = *(undefined1 *)((long)puVar11 + 4),
              puVar10 != (ulong *)((long)puVar11 + 5) &&
              ((*(undefined1 *)((long)puVar3 + 5) = *(undefined1 *)((long)puVar11 + 5),
               puVar10 != (ulong *)((long)puVar11 + 6) &&
               (*(undefined1 *)((long)puVar3 + 6) = *(undefined1 *)((long)puVar11 + 6),
               puVar10 != (ulong *)((long)puVar11 + 7))))))) &&
            (*(undefined1 *)((long)puVar3 + 7) = *(undefined1 *)((long)puVar11 + 7),
            puVar10 != puVar11 + 1)) &&
           ((((*(char *)(puVar3 + 1) = (char)puVar11[1], puVar10 != (ulong *)((long)puVar11 + 9) &&
              (*(undefined1 *)((long)puVar3 + 9) = *(undefined1 *)((long)puVar11 + 9),
              puVar10 != (ulong *)((long)puVar11 + 10))) &&
             (*(undefined1 *)((long)puVar3 + 10) = *(undefined1 *)((long)puVar11 + 10),
             puVar10 != (ulong *)((long)puVar11 + 0xb))) &&
            (((*(undefined1 *)((long)puVar3 + 0xb) = *(undefined1 *)((long)puVar11 + 0xb),
              puVar10 != (ulong *)((long)puVar11 + 0xc) &&
              (*(undefined1 *)((long)puVar3 + 0xc) = *(undefined1 *)((long)puVar11 + 0xc),
              puVar10 != (ulong *)((long)puVar11 + 0xd))) &&
             (*(undefined1 *)((long)puVar3 + 0xd) = *(undefined1 *)((long)puVar11 + 0xd),
             puVar10 != (ulong *)((long)puVar11 + 0xe))))))) {
          *(undefined1 *)((long)puVar3 + 0xe) = *(undefined1 *)((long)puVar11 + 0xe);
        }
      }
      paVar22 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
      if (puVar17 != (ulong *)PTR__S_empty_rep_storage_00324fa0) {
        *(undefined4 *)(puVar17 + 2) = 0;
        *puVar17 = uVar23;
        *(undefined1 *)((long)puVar17 + uVar23 + 0x18) = 0;
      }
    }
    local_b8 = 0;
    std::string::string((string *)&local_b0,(string *)local_c8);
    lVar20 = *plVar9;
    p_Var18 = operator_new(0x20);
    if (p_Var18 != (_List_node_base *)0x0) {
      *(undefined8 *)p_Var18 = 0;
      *(undefined8 *)(p_Var18 + 8) = 0;
      *(undefined4 *)(p_Var18 + 0x10) = local_b8;
      *(allocator **)(p_Var18 + 0x18) = local_b0;
      local_b0 = paVar22 + 0x18;
    }
    std::__detail::_List_node_base::_M_hook(p_Var18);
    if ((*(char *)(lVar20 + 0xb8) != '\0') &&
       (pvVar12 = *(void **)(lVar20 + 0xa8), (void *)(lVar20 + 0xa8) != pvVar12)) {
      uVar4 = *(undefined4 *)((long)pvVar12 + 0x10);
      lVar13 = *(long *)((long)pvVar12 + 0x18);
      *(allocator **)((long)pvVar12 + 0x18) = paVar22 + 0x18;
      std::__detail::_List_node_base::_M_unhook();
      lVar14 = *(long *)((long)pvVar12 + 0x18);
      if ((allocator *)(lVar14 + -0x18) != paVar22) {
        piVar2 = (int *)(lVar14 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar16 = *(int *)(lVar14 + -8);
          *(int *)(lVar14 + -8) = iVar16 + -1;
        }
        else {
          LOCK();
          iVar16 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar16 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(lVar14 + -0x18));
        }
      }
      operator_delete(pvVar12);
      *(undefined1 *)(lVar20 + 0xb8) = 0;
      if (*(long *)(lVar20 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_bad_function_call();
      }
      local_a8[0] = uVar4;
      local_a0 = lVar13;
      (**(code **)(lVar20 + 0xd8))(lVar20 + 0xc0,local_a8);
      if ((allocator *)(local_a0 + -0x18) != paVar22) {
        piVar2 = (int *)(local_a0 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar16 = *(int *)(local_a0 + -8);
          *(int *)(local_a0 + -8) = iVar16 + -1;
        }
        else {
          LOCK();
          iVar16 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar16 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(local_a0 + -0x18));
        }
      }
    }
    if (local_b0 + -0x18 != paVar22) {
      paVar1 = local_b0 + -8;
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar16 = *(int *)(local_b0 + -8);
        *(int *)(local_b0 + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *(int *)paVar1;
        *(int *)paVar1 = *(int *)paVar1 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        std::string::_Rep::_M_destroy(local_b0 + -0x18);
      }
    }
    if ((allocator *)(local_c8[0] + -3) != paVar22) {
      puVar11 = local_c8[0] + -1;
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar16 = (int)local_c8[0][-1];
        *(int *)(local_c8[0] + -1) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = (int)*puVar11;
        *(int *)puVar11 = (int)*puVar11 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_c8[0] + -3));
      }
    }
    local_68 = (code *)0x0;
    if (local_88 != (code *)0x0) {
      (*local_88)(&local_78,&local_98,2);
      local_68 = local_88;
      uStack_60 = uStack_80;
    }
    local_48 = (code *)0x0;
    local_58[0] = operator_new(0x20);
    pcVar15 = local_68;
    local_58[0][2] = 0;
    uVar6 = *local_58[0];
    uVar7 = local_58[0][1];
    uVar8 = local_58[0][3];
    local_58[0][1] = local_70;
    *local_58[0] = local_78;
    local_68 = (code *)0x0;
    local_58[0][2] = pcVar15;
    local_58[0][3] = uStack_60;
    local_40 = PTR__M_invoke_00324fe0;
    local_48 = (code *)PTR__M_manager_00324f88;
    local_78 = uVar6;
    local_70 = uVar7;
    uStack_60 = uVar8;
    WSConn::recv(*(WSConn **)(*plVar9 + 0x68),local_58);
    if (local_48 != (code *)0x0) {
      (*local_48)(local_58,local_58,3);
    }
    if (local_68 != (code *)0x0) {
      (*local_68)(&local_78,&local_78,3);
    }
  }
  if (local_88 != (code *)0x0) {
    (*local_88)(&local_98,&local_98,3);
  }
  if (puVar5 != (undefined8 *)0x0) {
    if ((void *)*puVar5 != (void *)0x0) {
      operator_delete((void *)*puVar5);
    }
    operator_delete(puVar5);
  }
  return;
}



