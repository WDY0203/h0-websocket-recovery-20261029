
/* WARNING: Switch with 1 destination removed at 0x001075e0 */

void __thiscall EventLoop2::EventLoop2(EventLoop2 *this)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_vtable_00324f00;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined **)this = puVar1 + 0x10;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  this[0x54] = (EventLoop2)0x1;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 1000000;
  iVar2 = epoll_create1(0x80000);
  *(int *)(this + 0x50) = iVar2;
  if (iVar2 < 0) {
    perror("epoll_create1");
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return;
}



