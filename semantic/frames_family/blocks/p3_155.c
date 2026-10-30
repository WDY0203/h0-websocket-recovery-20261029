
void FUN_00107980(undefined8 *param_1)

{
  EventLoop2 *this;
  
  this = *(EventLoop2 **)*param_1;
  *(undefined8 *)(this + 0x68) = 0;
  EventLoop2::exit(this,0);
  return;
}



