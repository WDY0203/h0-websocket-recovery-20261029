
/* std::vector<std::pair<EventHandler*, std::function<void ()> >,
   std::allocator<std::pair<EventHandler*, std::function<void ()> > > >::~vector() */

void __thiscall
std::
vector<std::pair<EventHandler*,std::function<void()>>,std::allocator<std::pair<EventHandler*,std::function<void()>>>>
::~vector(vector<std::pair<EventHandler*,std::function<void()>>,std::allocator<std::pair<EventHandler*,std::function<void()>>>>
          *this)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)(this + 8);
  pvVar1 = *(void **)this;
  if (pvVar2 != pvVar1) {
    do {
      if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
        (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
      }
      pvVar1 = (void *)((long)pvVar1 + 0x28);
    } while (pvVar2 != pvVar1);
    pvVar2 = *(void **)this;
  }
  if (pvVar2 == (void *)0x0) {
    return;
  }
  operator_delete(pvVar2);
  return;
}



