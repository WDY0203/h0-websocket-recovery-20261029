
void FUN_001078c0(long *param_1)

{
  EventLoop2 *this;
  
  this = *(EventLoop2 **)*param_1;
  *(undefined1 *)((undefined8 *)*param_1)[1] = 1;
  EventLoop2::exit(this,0);
  return;
}



