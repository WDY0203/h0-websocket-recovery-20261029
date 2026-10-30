
undefined8 FUN_0010e140(undefined8 *param_1,undefined8 *param_2,int param_3)

{
  int *piVar1;
  long *plVar2;
  long lVar3;
  string *psVar4;
  int iVar5;
  string *this;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = &PTR_vtable_003248f0;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      psVar4 = (string *)*param_2;
      this = operator_new(0x28);
      std::string::string(this,psVar4);
      *(undefined8 *)(this + 0x18) = 0;
      if (*(code **)(psVar4 + 0x18) != (code *)0x0) {
        (**(code **)(psVar4 + 0x18))(this + 8,psVar4 + 8,2);
        *(undefined8 *)(this + 0x20) = *(undefined8 *)(psVar4 + 0x20);
        *(undefined8 *)(this + 0x18) = *(undefined8 *)(psVar4 + 0x18);
      }
      *param_1 = this;
      return 0;
    }
    if ((param_3 == 3) && (plVar2 = (long *)*param_1, plVar2 != (long *)0x0)) {
      if ((code *)plVar2[3] != (code *)0x0) {
        (*(code *)plVar2[3])(plVar2 + 1,plVar2 + 1,3);
      }
      lVar3 = *plVar2;
      if ((allocator *)(lVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
        piVar1 = (int *)(lVar3 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar5 = *(int *)(lVar3 + -8);
          *(int *)(lVar3 + -8) = iVar5 + -1;
        }
        else {
          LOCK();
          iVar5 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar5 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(lVar3 + -0x18));
        }
      }
      operator_delete(plVar2);
    }
  }
  return 0;
}



