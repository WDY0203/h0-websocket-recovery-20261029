
/* std::_Function_base::_Base_manager<TcpConn::exit()::{lambda()#2}>::_M_manager(std::_Any_data&,
   std::_Any_data const&, std::_Manager_operation) */

undefined8
std::_Function_base::_Base_manager<TcpConn::exit()::{lambda()#2}>::_M_manager
          (undefined8 *param_1,undefined8 *param_2,int param_3)

{
  void *pvVar1;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = PTR_typeinfo_00324fc8;
      return 0;
    }
  }
  else {
    if (param_3 == 2) {
      pvVar1 = operator_new(1);
      *param_1 = pvVar1;
      return 0;
    }
    if (param_3 == 3) {
      operator_delete((void *)*param_1);
    }
  }
  return 0;
}



