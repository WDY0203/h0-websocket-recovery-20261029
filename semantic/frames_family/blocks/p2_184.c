
/* std::_Function_base::_Base_manager<_<void, std::unique_ptr<Buffer, std::default_delete<Buffer> >
   > >::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) */

undefined8
std::_Function_base::_Base_manager<_<void,std::unique_ptr<Buffer,std::default_delete<Buffer>>>>::
_M_manager(long *param_1,long *param_2,int param_3)

{
  long lVar1;
  void *pvVar2;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long)PTR_typeinfo_00324ee0;
      return 0;
    }
  }
  else if (param_3 == 2) {
    lVar1 = *param_2;
    pvVar2 = operator_new(0x20);
    *(undefined8 *)((long)pvVar2 + 0x10) = 0;
    if (*(code **)(lVar1 + 0x10) != (code *)0x0) {
      (**(code **)(lVar1 + 0x10))(pvVar2,lVar1,2);
      *(undefined8 *)((long)pvVar2 + 0x18) = *(undefined8 *)(lVar1 + 0x18);
      *(undefined8 *)((long)pvVar2 + 0x10) = *(undefined8 *)(lVar1 + 0x10);
    }
    *param_1 = (long)pvVar2;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
    if (*(code **)((long)pvVar2 + 0x10) != (code *)0x0) {
      (**(code **)((long)pvVar2 + 0x10))(pvVar2,pvVar2,3);
    }
    operator_delete(pvVar2);
    return 0;
  }
  return 0;
}



