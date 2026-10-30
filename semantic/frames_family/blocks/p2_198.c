
void FUN_0010db50(long *param_1)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  
  if ((code *)param_1[3] != (code *)0x0) {
    (*(code *)param_1[3])(param_1 + 1,param_1 + 1,3);
  }
  lVar2 = *param_1;
  if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar3 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}



