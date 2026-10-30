
long FUN_00108b30(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 local_48 [2];
  undefined8 local_38 [2];
  undefined4 local_28;
  long local_20;
  
  uVar2 = (uint)local_28 >> 0x10;
  local_28 = CONCAT22((ushort)uVar2 & 0xff00,0x4f4f);
  iVar3 = PyArg_ParseTuple(param_2,&local_28,local_48,local_38);
  if (iVar3 != 0) {
    uVar6 = PyFloat_AsDouble(local_38[0]);
    uVar4 = PyLong_AsVoidPtr(local_48[0]);
    FUN_001085c0(uVar6,&local_28,uVar4);
    uVar4 = Py_BuildValue("l",(long)local_28);
    uVar6 = PyString_FromStringAndSize(local_20,*(undefined8 *)(local_20 + -0x18));
    lVar5 = PyTuple_New(2);
    *(undefined8 *)(lVar5 + 0x18) = uVar4;
    *(undefined8 *)(lVar5 + 0x20) = uVar6;
    if ((allocator *)(local_20 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
      piVar1 = (int *)(local_20 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar3 = *(int *)(local_20 + -8);
        *(int *)(local_20 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_20 + -0x18));
      }
    }
    return lVar5;
  }
  return 0;
}



