
/* WARNING: Switch with 1 destination removed at 0x00106f80 */

void __thiscall EventLoop2::~EventLoop2(EventLoop2 *this)

{
  void *pvVar1;
  long *plVar2;
  void *pvVar3;
  long *plVar4;
  
  *(undefined **)this = PTR_vtable_00324f00 + 0x10;
  close(*(int *)(this + 0x50));
  pvVar3 = *(void **)(this + 0x40);
  pvVar1 = *(void **)(this + 0x38);
  if (pvVar3 != pvVar1) {
    do {
      if (*(code **)((long)pvVar1 + 0x18) != (code *)0x0) {
        (**(code **)((long)pvVar1 + 0x18))((long)pvVar1 + 8,(long)pvVar1 + 8,3);
      }
      pvVar1 = (void *)((long)pvVar1 + 0x28);
    } while (pvVar3 != pvVar1);
    pvVar3 = *(void **)(this + 0x38);
  }
  if (pvVar3 != (void *)0x0) {
    operator_delete(pvVar3);
  }
  plVar4 = *(long **)(this + 0x28);
  plVar2 = *(long **)(this + 0x20);
  if (plVar4 != plVar2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long **)(this + 0x20);
  }
  if (plVar4 != (long *)0x0) {
    operator_delete(plVar4);
  }
  plVar4 = *(long **)(this + 0x10);
  plVar2 = *(long **)(this + 8);
  if (plVar4 != plVar2) {
    do {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long **)(this + 8);
  }
  if (plVar4 == (long *)0x0) {
    return;
  }
  operator_delete(plVar4);
  return;
}



