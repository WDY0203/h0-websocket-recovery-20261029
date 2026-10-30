
/* std::_Function_handler<void (std::unique_ptr<Buffer, std::default_delete<Buffer> >), _<void,
   std::unique_ptr<Buffer, std::default_delete<Buffer> > > >::_M_invoke(std::_Any_data const&,
   std::unique_ptr<Buffer, std::default_delete<Buffer> >) */

void std::
     _Function_handler<void(std::unique_ptr<Buffer,std::default_delete<Buffer>>),_<void,std::unique_ptr<Buffer,std::default_delete<Buffer>>>>
     ::_M_invoke(long *param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *local_68 [2];
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  code *local_28;
  undefined8 local_20;
  
  lVar1 = *param_1;
  puVar2 = (undefined8 *)*param_2;
  local_48 = (code *)0x0;
  *param_2 = 0;
  if (*(code **)(lVar1 + 0x10) != (code *)0x0) {
    (**(code **)(lVar1 + 0x10))(&local_58,lVar1,2);
    uVar4 = local_50;
    uVar3 = local_58;
    local_28 = *(code **)(lVar1 + 0x10);
    local_48 = local_28;
    local_40 = *(undefined8 *)(lVar1 + 0x18);
    if (*(long *)(lVar1 + 0x10) != 0) {
      local_58 = local_38;
      local_50 = local_30;
      local_38 = uVar3;
      local_30 = uVar4;
      local_48 = (code *)0x0;
      local_40 = local_20;
      local_68[0] = puVar2;
      local_20 = *(undefined8 *)(lVar1 + 0x18);
      (**(code **)(lVar1 + 0x18))(lVar1,&local_38,local_68);
      if (local_28 != (code *)0x0) {
        (*local_28)(&local_38,&local_38,3);
      }
      puVar2 = local_68[0];
      if (local_68[0] != (undefined8 *)0x0) {
        if ((void *)*local_68[0] != (void *)0x0) {
          operator_delete((void *)*local_68[0]);
        }
        operator_delete(puVar2);
      }
      if (local_48 != (code *)0x0) {
        (*local_48)(&local_58,&local_58,3);
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_function_call();
}



