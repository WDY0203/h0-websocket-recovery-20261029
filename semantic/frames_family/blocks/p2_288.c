
/* EventHandler::~EventHandler() */

void __thiscall EventHandler::~EventHandler(EventHandler *this)

{
  void *pvVar1;
  void *pvVar2;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  EventHandler *pEVar3;
  
  *(undefined **)this = PTR_vtable_00324fb8 + 0x10;
  pEVar3 = this + 0x98;
  do {
    this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
               *)(pEVar3 + -0x30);
    pvVar2 = *(void **)(pEVar3 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std::
      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
      ::_M_erase(this_00,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long)pvVar2 + 0x10);
      operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pEVar3 = (EventHandler *)this_00;
  } while (this + 0x38 != (EventHandler *)this_00);
  std::
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  ::_M_erase((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(this + 8),*(_Rb_tree_node **)(this + 0x18));
  operator_delete(this);
  return;
}



