
/* EventLoop2::del(EventHandler*, std::function<void ()>) */

void __thiscall EventLoop2::del(EventLoop2 *this,undefined8 param_1,long param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  code *local_30;
  undefined8 local_28;
  
  local_30 = (code *)0x0;
  local_48 = param_1;
  if (*(code **)(param_3 + 0x10) != (code *)0x0) {
    (**(code **)(param_3 + 0x10))(&local_40,param_3,2);
    local_28 = *(undefined8 *)(param_3 + 0x18);
    local_30 = *(code **)(param_3 + 0x10);
  }
  pcVar5 = local_30;
  puVar1 = *(undefined8 **)(this + 0x40);
  if (puVar1 == *(undefined8 **)(this + 0x48)) {
    std::
    vector<std::pair<EventHandler*,std::function<void()>>,std::allocator<std::pair<EventHandler*,std::function<void()>>>>
    ::_M_emplace_back_aux<std::pair<EventHandler*,std::function<void()>>>
              ((vector<std::pair<EventHandler*,std::function<void()>>,std::allocator<std::pair<EventHandler*,std::function<void()>>>>
                *)(this + 0x38),(pair *)&local_48);
  }
  else {
    lVar6 = 0;
    if (puVar1 != (undefined8 *)0x0) {
      puVar1[3] = 0;
      uVar2 = puVar1[2];
      *puVar1 = local_48;
      uVar3 = puVar1[1];
      uVar4 = puVar1[4];
      puVar1[1] = local_40;
      puVar1[2] = local_38;
      local_30 = (code *)0x0;
      puVar1[3] = pcVar5;
      puVar1[4] = local_28;
      lVar6 = *(long *)(this + 0x40);
      local_40 = uVar3;
      local_38 = uVar2;
      local_28 = uVar4;
    }
    *(long *)(this + 0x40) = lVar6 + 0x28;
  }
  if (local_30 != (code *)0x0) {
    (*local_30)(&local_40,&local_40,3);
  }
  return;
}



