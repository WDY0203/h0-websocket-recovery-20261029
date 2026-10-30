
/* WARNING: Switch with 1 destination removed at 0x001070b0 */

void __thiscall EventLoop2::exit(EventLoop2 *this,int param_1)

{
  *(int *)(this + 0x58) = param_1;
  this[0x54] = (EventLoop2)0x0;
  return;
}



