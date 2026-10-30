
/* std::_Function_handler<void (_<void, std::unique_ptr<Buffer, std::default_delete<Buffer> > >,
   std::unique_ptr<Buffer, std::default_delete<Buffer> >), WSConn::exit()::{lambda(_<void,
   std::unique_ptr<Buffer, std::default_delete<Buffer> > >, std::unique_ptr<Buffer,
   std::default_delete<Buffer> >)#1}>::_M_invoke(std::_Any_data const&, _<void,
   std::unique_ptr<Buffer, std::default_delete<Buffer> > >, std::unique_ptr<Buffer,
   std::default_delete<Buffer> >) */

void std::
     _Function_handler<void(_<void,std::unique_ptr<Buffer,std::default_delete<Buffer>>>,std::unique_ptr<Buffer,std::default_delete<Buffer>>),WSConn::exit()::{lambda(_<void,std::unique_ptr<Buffer,std::default_delete<Buffer>>>,std::unique_ptr<Buffer,std::default_delete<Buffer>>)#1}>
     ::_M_invoke(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 local_78;
  undefined8 local_70;
  code *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  code *local_48;
  undefined8 uStack_40;
  undefined8 *local_38 [2];
  code *local_28;
  undefined *local_20;
  
  puVar1 = (undefined8 *)*param_3;
  *param_3 = 0;
  uVar2 = *param_2;
  uVar3 = param_2[1];
  *param_2 = local_78;
  param_2[1] = local_70;
  local_68 = (code *)param_2[2];
  uVar4 = param_2[3];
  param_2[2] = 0;
  param_2[3] = uStack_60;
  param_1 = (undefined8 *)*param_1;
  local_78 = uVar2;
  local_70 = uVar3;
  uStack_60 = uVar4;
  if (puVar1 != (undefined8 *)0x0) {
    local_48 = (code *)0x0;
    if (local_68 != (code *)0x0) {
      (*local_68)(&local_58,&local_78,2);
      local_48 = local_68;
      uStack_40 = uStack_60;
    }
    local_28 = (code *)0x0;
    local_38[0] = operator_new(0x20);
    pcVar5 = local_48;
    local_38[0][2] = 0;
    uVar2 = *local_38[0];
    uVar3 = local_38[0][1];
    uVar4 = local_38[0][3];
    local_38[0][1] = local_50;
    *local_38[0] = local_58;
    local_48 = (code *)0x0;
    local_38[0][2] = pcVar5;
    local_38[0][3] = uStack_40;
    local_20 = PTR__M_invoke_00324fe0;
    local_28 = (code *)PTR__M_manager_00324f88;
    local_58 = uVar2;
    local_50 = uVar3;
    uStack_40 = uVar4;
    WSConn::recv((WSConn *)*param_1,local_38);
    if (local_28 != (code *)0x0) {
      (*local_28)(local_38,local_38,3);
    }
    if (local_48 != (code *)0x0) {
      (*local_48)(&local_58,&local_58,3);
    }
  }
  if (local_68 != (code *)0x0) {
    (*local_68)(&local_78,&local_78,3);
  }
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    operator_delete(puVar1);
  }
  return;
}



