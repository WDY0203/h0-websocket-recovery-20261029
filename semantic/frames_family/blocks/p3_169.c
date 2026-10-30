
undefined8 FUN_00108a30(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_198 [2];
  long local_188 [2];
  undefined2 local_178 [4];
  long local_170;
  _union_1457 local_168;
  sigset_t local_160;
  undefined4 local_e0;
  sigaction local_c8;
  
  local_168.sa_handler = (__sighandler_t)0x0;
  local_e0 = 0;
  sigemptyset(&local_160);
  sigaction(2,(sigaction *)&local_168,&local_c8);
  local_178[0] = 0x4f;
  iVar3 = PyArg_ParseTuple(param_2,local_178,local_198);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = PyLong_AsVoidPtr(local_198[0]);
    FUN_00108660(0,local_178,uVar4);
    std::string::string((string *)local_188,(string *)&local_170);
    puVar2 = PTR__S_empty_rep_storage_00324fa0;
    if ((allocator *)(local_170 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_170 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar3 = *(int *)(local_170 + -8);
        *(int *)(local_170 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_170 + -0x18));
      }
    }
    uVar4 = PyBytes_FromStringAndSize(local_188[0],*(undefined8 *)(local_188[0] + -0x18));
    if ((allocator *)(local_188[0] + -0x18) != (allocator *)puVar2) {
      piVar1 = (int *)(local_188[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar3 = *(int *)(local_188[0] + -8);
        *(int *)(local_188[0] + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_188[0] + -0x18));
      }
    }
  }
  sigaction(2,&local_c8,(sigaction *)0x0);
  return uVar4;
}



