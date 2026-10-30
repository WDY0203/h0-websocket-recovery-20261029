
/* WARNING: Switch with 1 destination removed at 0x00107720 */

void __thiscall EventLoop2::add(EventLoop2 *this,EventHandler *param_1)

{
  undefined8 *puVar1;
  EventHandler *apEStack_18 [2];
  
  puVar1 = *(undefined8 **)(this + 0x28);
  apEStack_18[0] = param_1;
  if (puVar1 == *(undefined8 **)(this + 0x30)) {
    std::
    vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
    ::_M_emplace_back_aux<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>
              ((vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
                *)(this + 0x20),(unique_ptr *)apEStack_18);
  }
  else {
    if (puVar1 != (undefined8 *)0x0) {
      apEStack_18[0] = (EventHandler *)0x0;
      *puVar1 = param_1;
    }
    *(undefined8 **)(this + 0x28) = puVar1 + 1;
  }
  if (apEStack_18[0] != (EventHandler *)0x0) {
    (**(code **)(*(long *)apEStack_18[0] + 0x18))();
  }
  return;
}



