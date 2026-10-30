
undefined8 FUN_0010ef80(long *param_1,char param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  long *plVar4;
  ulong uVar5;
  void *__dest;
  size_t sVar6;
  void *__dest_00;
  undefined8 uVar7;
  size_t sVar8;
  void *__src;
  void *__dest_01;
  uchar *puVar9;
  ulong __n;
  ulong local_4050;
  uchar local_4038 [16392];
  
  if (param_2 != '\0') {
    plVar4 = operator_new(0x18);
    *plVar4 = 0;
    plVar4[1] = 0;
    plVar4[2] = 0;
    local_4038[0] = '\0';
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              ((vector<unsigned_char,std::allocator<unsigned_char>> *)*param_1,local_4038);
    local_4038[0] = '\0';
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              ((vector<unsigned_char,std::allocator<unsigned_char>> *)*param_1,local_4038);
    local_4038[0] = 0xff;
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              ((vector<unsigned_char,std::allocator<unsigned_char>> *)*param_1,local_4038);
    local_4038[0] = 0xff;
    std::vector<unsigned_char,std::allocator<unsigned_char>>::emplace_back<unsigned_char>
              ((vector<unsigned_char,std::allocator<unsigned_char>> *)*param_1,local_4038);
    uVar7 = *(undefined8 *)*param_1;
    uVar1 = ((undefined8 *)*param_1)[1];
    *param_3 = uVar7;
    *(int *)(param_3 + 1) = (int)uVar1 - (int)uVar7;
    do {
      while( true ) {
        *(undefined4 *)(param_3 + 4) = 0x4000;
        param_3[3] = local_4038;
        iVar3 = inflate(param_3,0);
        if ((iVar3 + 4U < 7) && ((1L << ((byte)(iVar3 + 4U) & 0x3f) & 0x47U) != 0)) {
          if ((void *)*plVar4 != (void *)0x0) {
            operator_delete((void *)*plVar4);
          }
          operator_delete(plVar4);
          return 0;
        }
        iVar3 = *(int *)(param_3 + 4);
        __dest_01 = (void *)plVar4[1];
        puVar9 = local_4038 + (0x4000 - iVar3);
        if (puVar9 != local_4038) break;
LAB_0010f054:
        if (iVar3 != 0) goto LAB_0010f157;
      }
      __n = (long)puVar9 - (long)local_4038;
      if (__n <= (ulong)(plVar4[2] - (long)__dest_01)) {
        if (__n != 0) {
          memmove(__dest_01,local_4038,__n);
          __dest_01 = (void *)plVar4[1];
          iVar3 = *(int *)(param_3 + 4);
        }
        plVar4[1] = (long)__dest_01 + __n;
        goto LAB_0010f054;
      }
      __src = (void *)*plVar4;
      sVar8 = (long)__dest_01 - (long)__src;
      if (~sVar8 < __n) {
        uVar7 = std::__throw_length_error("vector::_M_range_insert");
        FUN_00107812(plVar4);
                    /* WARNING: Subroutine does not return */
        _Unwind_Resume(uVar7);
      }
      local_4050 = 0xffffffffffffffff;
      uVar5 = __n;
      if (__n <= sVar8) {
        uVar5 = sVar8;
      }
      if ((CARRY8(uVar5,sVar8)) || (local_4050 = uVar5 + sVar8, uVar5 + sVar8 != 0)) {
        __dest = operator_new(local_4050);
        __src = (void *)*plVar4;
        sVar8 = (long)__dest_01 - (long)__src;
        __dest_00 = __dest;
        if (sVar8 == 0) goto LAB_0010f10c;
LAB_0010f1d1:
        memmove(__dest,__src,sVar8);
        __dest_00 = (void *)(sVar8 + (long)__dest);
        if (__n != 0) goto LAB_0010f1f2;
LAB_0010f118:
        sVar8 = plVar4[1] - (long)__dest_01;
      }
      else {
        __dest = (void *)0x0;
        local_4050 = 0;
        __dest_00 = __dest;
        if (sVar8 != 0) goto LAB_0010f1d1;
LAB_0010f10c:
        __dest = __dest_00;
        if (__n == 0) goto LAB_0010f118;
LAB_0010f1f2:
        __dest_00 = memmove(__dest_00,local_4038,__n);
        sVar8 = plVar4[1] - (long)__dest_01;
      }
      sVar6 = 0;
      if (sVar8 != 0) {
        memmove((void *)(__n + (long)__dest_00),__dest_01,sVar8);
        sVar6 = sVar8;
      }
      if ((void *)*plVar4 != (void *)0x0) {
        operator_delete((void *)*plVar4);
      }
      *plVar4 = (long)__dest;
      iVar3 = *(int *)(param_3 + 4);
      plVar4[1] = (long)(__n + (long)__dest_00) + sVar6;
      plVar4[2] = (long)__dest + local_4050;
    } while (iVar3 == 0);
LAB_0010f157:
    puVar2 = (undefined8 *)*param_1;
    *param_1 = (long)plVar4;
    if (puVar2 != (undefined8 *)0x0) {
      if ((void *)*puVar2 != (void *)0x0) {
        operator_delete((void *)*puVar2);
      }
      operator_delete(puVar2);
    }
  }
  return 1;
}



