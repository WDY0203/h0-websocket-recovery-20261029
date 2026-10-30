
void FUN_0010dda0(undefined8 *param_1)

{
  int *piVar1;
  string *psVar2;
  undefined *puVar3;
  int iVar4;
  undefined *local_38 [2];
  long local_28 [2];
  
  psVar2 = (string *)*param_1;
  std::string::string((string *)local_38,psVar2);
  puVar3 = PTR__S_empty_rep_storage_00324fa0;
  if (*(long *)(psVar2 + 0x18) != 0) {
    local_28[0] = (long)local_38[0];
    local_38[0] = PTR__S_empty_rep_storage_00324fa0 + 0x18;
    (**(code **)(psVar2 + 0x20))(psVar2 + 8,local_28);
    if ((allocator *)(local_28[0] + -0x18) != (allocator *)puVar3) {
      piVar1 = (int *)(local_28[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar4 = *(int *)(local_28[0] + -8);
        *(int *)(local_28[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_28[0] + -0x18));
      }
    }
    if ((allocator *)(local_38[0] + -0x18) != (allocator *)puVar3) {
      piVar1 = (int *)(local_38[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar4 = *(int *)(local_38[0] + -8);
        *(int *)(local_38[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_38[0] + -0x18));
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_function_call();
}



