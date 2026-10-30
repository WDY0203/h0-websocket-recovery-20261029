
/* std::_Function_base::_Base_manager<WSConn::exit()::{lambda(_<void, std::unique_ptr<Buffer,
   std::default_delete<Buffer> > >, std::unique_ptr<Buffer, std::default_delete<Buffer>
   >)#1}>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) */

undefined8
std::_Function_base::
_Base_manager<WSConn::exit()::{lambda(_<void,std::unique_ptr<Buffer,std::default_delete<Buffer>>>,std::unique_ptr<Buffer,std::default_delete<Buffer>>)#1}>
::_M_manager(undefined8 *param_1,undefined8 *param_2,int param_3)

{
  undefined8 *puVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324fa8;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      param_2 = (undefined8 *)*param_2;
      puVar1 = operator_new(8);
      *puVar1 = *param_2;
      *param_1 = puVar1;
      return 0;
    }
    if (param_3 == 3) {
      operator_delete((void *)*param_1);
    }
  }
  return 0;
}



