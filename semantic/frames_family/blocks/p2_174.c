
undefined8
FUN_00109b10(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  char *pcVar5;
  EventLoop2 *pEVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  char local_208 [16];
  undefined2 local_1f8;
  undefined1 local_1f6;
  undefined1 local_1e8;
  undefined1 local_1e7;
  undefined1 local_1e6;
  undefined8 local_1d8 [2];
  undefined8 local_1c8 [2];
  long local_1b8 [2];
  undefined8 *local_1a8 [2];
  undefined8 *local_198 [2];
  code *local_188;
  code *local_180;
  _union_1457 local_178;
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  local_178.sa_handler = (__sighandler_t)0x0;
  local_f0 = 0;
  sigemptyset(&local_170);
  sigaction(2,(sigaction *)&local_178,&local_d8);
  local_1f8 = 0x4f4f;
  local_1e6 = 0;
  local_1e8 = 0x4f;
  local_1e7 = 0x4f;
  local_1f6 = 0;
  uVar4 = (ulong)local_198[0] >> 0x10;
  local_198[0] = (undefined8 *)CONCAT62((uint6)uVar4 & 0xffffffffff00,0x4f4f);
  iVar3 = PyArg_ParseTuple(param_2,(allocator *)local_198,local_1d8,local_1c8);
  if (iVar3 == 0) {
    uVar8 = 0;
  }
  else {
    uVar4 = PyString_Size(local_1c8[0]);
    pcVar5 = (char *)PyString_AsString(local_1c8[0]);
    std::string::string((string *)local_1b8,pcVar5,uVar4,(allocator *)local_198);
    pEVar6 = (EventLoop2 *)PyLong_AsVoidPtr(local_1d8[0]);
    if ((pEVar6 == (EventLoop2 *)0x0) || (*(long *)(pEVar6 + 0x68) == 0)) {
      uVar8 = 1;
    }
    else {
      local_208[0] = '\0';
      puVar7 = operator_new(0x18);
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      uVar8 = 0;
      lVar2 = *(long *)(local_1b8[0] + -0x18);
      if (-1 < *(int *)(local_1b8[0] + -8)) {
        std::string::_M_leak_hard();
        uVar8 = puVar7[1];
      }
      std::vector<unsigned_char,std::allocator<unsigned_char>>::
      _M_range_insert<__gnu_cxx::__normal_iterator<char*,std::string>>
                (puVar7,uVar8,local_1b8[0],local_1b8[0] + lVar2,param_5,param_6,0);
      local_188 = (code *)0x0;
      local_198[0] = operator_new(0x10);
      *local_198[0] = pEVar6;
      local_198[0][1] = local_208;
      local_180 = FUN_001078c0;
      local_188 = FUN_00107990;
      local_1a8[0] = puVar7;
      WSConn::send(*(WSConn **)(pEVar6 + 0x68),local_1a8,(allocator *)local_198);
      puVar7 = local_1a8[0];
      if (local_1a8[0] != (undefined8 *)0x0) {
        if ((void *)*local_1a8[0] != (void *)0x0) {
          operator_delete((void *)*local_1a8[0]);
        }
        operator_delete(puVar7);
      }
      if (local_188 != (code *)0x0) {
        (*local_188)((allocator *)local_198,(allocator *)local_198,3);
      }
      while (local_208[0] == '\0') {
        while( true ) {
          local_188 = (code *)0x0;
          EventLoop2::run(pEVar6,(allocator *)local_198);
          if (local_188 == (code *)0x0) break;
          (*local_188)((allocator *)local_198,(allocator *)local_198,3);
          if (local_208[0] != '\0') goto LAB_00109d4f;
        }
      }
LAB_00109d4f:
      uVar8 = 0;
    }
    if ((allocator *)(local_1b8[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_1b8[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar3 = *(int *)(local_1b8[0] + -8);
        *(int *)(local_1b8[0] + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_1b8[0] + -0x18));
      }
    }
    uVar8 = Py_BuildValue("l",uVar8);
  }
  sigaction(2,&local_d8,(sigaction *)0x0);
  return uVar8;
}



