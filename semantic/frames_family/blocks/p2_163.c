
void FUN_00107d20(long *param_1,undefined4 *param_2)

{
  int *piVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  lVar2 = *(long *)(param_2 + 2);
  *(undefined **)(param_2 + 2) = PTR__S_empty_rep_storage_00324fa0 + 0x18;
  puVar3 = (undefined8 *)*param_1;
  puVar4 = (undefined4 *)puVar3[1];
  *puVar4 = *param_2;
  std::string::assign((string *)(puVar4 + 2));
  EventLoop2::exit((EventLoop2 *)*puVar3,0);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar5) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar6 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}



