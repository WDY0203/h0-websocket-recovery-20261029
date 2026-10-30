
void FUN_0010fb50(allocator *param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  code *in_stack_00000030;
  code *in_stack_00000058;
  code *in_stack_00000078;
  
  LOCK();
  iVar1 = *param_3;
  *param_3 = *param_3 + -1;
  UNLOCK();
  if (iVar1 < 1) {
    std::string::_Rep::_M_destroy(param_1);
  }
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
  if (in_stack_00000078 != (code *)0x0) {
    (*in_stack_00000078)(&stack0x00000068,&stack0x00000068,3);
  }
  if (in_stack_00000058 != (code *)0x0) {
    (*in_stack_00000058)(&stack0x00000048,&stack0x00000048,3);
  }
  return;
}



