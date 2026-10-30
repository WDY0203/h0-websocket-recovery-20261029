
/* std::vector<std::unique_ptr<EventHandler, std::default_delete<EventHandler> >,
   std::allocator<std::unique_ptr<EventHandler, std::default_delete<EventHandler> > > >::~vector()
    */

void __thiscall
std::
vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
::~vector(vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
          *this)

{
  long *plVar1;
  long *plVar2;
  
  plVar2 = *(long **)(this + 8);
  plVar1 = *(long **)this;
  if (plVar2 != plVar1) {
    do {
      if ((long *)*plVar1 != (long *)0x0) {
        (**(code **)(*(long *)*plVar1 + 0x18))();
      }
      *plVar1 = 0;
      plVar1 = plVar1 + 1;
    } while (plVar2 != plVar1);
    plVar2 = *(long **)this;
  }
  if (plVar2 == (long *)0x0) {
    return;
  }
  operator_delete(plVar2);
  return;
}



