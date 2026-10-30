
/* WARNING: Switch with 1 destination removed at 0x00107070 */

void std::vector<unsigned_char,std::allocator<unsigned_char>>::
     _M_range_insert<__gnu_cxx::__normal_iterator<unsigned_char*,std::vector<unsigned_char,std::allocator<unsigned_char>>>>
               (long *param_1,void *param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  size_t sVar2;
  size_t __n;
  void *pvVar3;
  ulong uVar4;
  size_t sVar5;
  ulong uVar6;
  void *__src;
  bool bVar7;
  
  if (param_3 == param_4) {
    return;
  }
  pvVar3 = (void *)param_1[1];
  __n = (long)param_4 - (long)param_3;
  if (__n <= (ulong)(param_1[2] - (long)pvVar3)) {
    uVar6 = (long)pvVar3 - (long)param_2;
    if (__n < uVar6) {
      __src = (void *)((long)pvVar3 - __n);
      pvVar1 = pvVar3;
      if ((long)pvVar3 - (long)__src != 0) {
        pvVar1 = memmove(pvVar3,__src,(long)pvVar3 - (long)__src);
        pvVar3 = (void *)param_1[1];
      }
      sVar2 = (long)__src - (long)param_2;
      param_1[1] = (long)pvVar3 + __n;
      if (sVar2 != 0) {
        memmove((void *)((long)pvVar1 - sVar2),param_2,sVar2);
        if (__n == 0) {
          return;
        }
        goto LAB_00116338;
      }
    }
    else {
      pvVar1 = (void *)((long)param_3 + uVar6);
      if ((long)param_4 - (long)pvVar1 != 0) {
        memmove(pvVar3,pvVar1,(long)param_4 - (long)pvVar1);
        pvVar3 = (void *)param_1[1];
      }
      pvVar3 = (void *)((long)pvVar3 + (__n - uVar6));
      param_1[1] = (long)pvVar3;
      if (uVar6 != 0) {
        memmove(pvVar3,param_2,uVar6);
        pvVar3 = (void *)param_1[1];
      }
      __n = (long)pvVar1 - (long)param_3;
      param_1[1] = (long)pvVar3 + uVar6;
    }
    if (__n == 0) {
      return;
    }
LAB_00116338:
    memmove(param_2,param_3,__n);
    return;
  }
  pvVar1 = (void *)*param_1;
  uVar6 = (long)pvVar3 - (long)pvVar1;
  if (~uVar6 < __n) {
    std::__throw_length_error("vector::_M_range_insert");
  }
  else {
    uVar4 = __n;
    if (__n <= uVar6) {
      uVar4 = uVar6;
    }
    bVar7 = CARRY8(uVar6,uVar4);
    uVar4 = uVar6 + uVar4;
    uVar6 = 0xffffffffffffffff;
    if ((!bVar7) && (uVar6 = uVar4, uVar4 == 0)) {
      uVar6 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_00116398;
    }
  }
  pvVar3 = operator_new(uVar6);
  pvVar1 = (void *)*param_1;
LAB_00116398:
  sVar5 = (long)param_2 - (long)pvVar1;
  sVar2 = 0;
  if (sVar5 != 0) {
    memmove(pvVar3,pvVar1,sVar5);
    sVar2 = sVar5;
  }
  pvVar1 = (void *)(sVar2 + (long)pvVar3);
  if (__n != 0) {
    pvVar1 = memmove(pvVar1,param_3,__n);
  }
  sVar5 = param_1[1] - (long)param_2;
  sVar2 = 0;
  if (sVar5 != 0) {
    memmove((void *)(__n + (long)pvVar1),param_2,sVar5);
    sVar2 = sVar5;
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  *param_1 = (long)pvVar3;
  param_1[1] = (long)(__n + (long)pvVar1) + sVar2;
  param_1[2] = uVar6 + (long)pvVar3;
  return;
}



