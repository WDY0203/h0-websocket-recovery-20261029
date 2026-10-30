
/* void std::vector<std::unique_ptr<EventHandler, std::default_delete<EventHandler> >,
   std::allocator<std::unique_ptr<EventHandler, std::default_delete<EventHandler> > >
   >::_M_emplace_back_aux<std::unique_ptr<EventHandler, std::default_delete<EventHandler> >
   >(std::unique_ptr<EventHandler, std::default_delete<EventHandler> >&&) */

void __thiscall
std::
vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
::_M_emplace_back_aux<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>
          (vector<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>,std::allocator<std::unique_ptr<EventHandler,std::default_delete<EventHandler>>>>
           *this,unique_ptr *param_1)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  undefined8 *puVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  ulong uVar11;
  long *plVar12;
  
  uVar11 = 8;
  uVar3 = *(long *)(this + 8) - *(long *)this >> 3;
  if (uVar3 != 0) {
    if ((uVar3 * 2 < uVar3) || (0x1fffffffffffffff < uVar3 * 2)) {
      uVar11 = 0xfffffffffffffff8;
    }
    else {
      uVar11 = uVar3 << 4;
    }
  }
  plVar4 = operator_new(uVar11);
  plVar9 = *(long **)(this + 8);
  plVar8 = *(long **)this;
  plVar12 = plVar4 + 1;
  puVar5 = (undefined8 *)(((long)plVar9 - (long)plVar8 & 0xfffffffffffffff8U) + (long)plVar4);
  if (puVar5 != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)param_1;
    *(undefined8 *)param_1 = 0;
    plVar9 = *(long **)(this + 8);
    plVar8 = *(long **)this;
    *puVar5 = uVar1;
  }
  plVar6 = plVar4;
  plVar7 = plVar8;
  plVar10 = plVar9;
  if (plVar9 != plVar8) {
    do {
      if (plVar6 != (long *)0x0) {
        lVar2 = *plVar7;
        *plVar7 = 0;
        *plVar6 = lVar2;
      }
      plVar7 = plVar7 + 1;
      plVar6 = plVar6 + 1;
    } while (plVar7 != plVar9);
    plVar10 = *(long **)(this + 8);
    plVar6 = *(long **)this;
    plVar12 = (long *)((long)plVar4 +
                      ((long)plVar9 - (long)(plVar8 + 1) & 0xfffffffffffffff8U) + 0x10);
    if (plVar10 != plVar6) {
      do {
        if ((long *)*plVar6 != (long *)0x0) {
          (**(code **)(*(long *)*plVar6 + 0x18))();
        }
        *plVar6 = 0;
        plVar6 = plVar6 + 1;
      } while (plVar10 != plVar6);
      plVar10 = *(long **)this;
    }
  }
  if (plVar10 != (long *)0x0) {
    operator_delete(plVar10);
  }
  *(long **)this = plVar4;
  *(long **)(this + 8) = plVar12;
  *(ulong *)(this + 0x10) = (long)plVar4 + uVar11;
  return;
}



