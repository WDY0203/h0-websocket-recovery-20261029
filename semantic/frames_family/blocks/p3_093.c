
/* WARNING: Switch with 1 destination removed at 0x001074c0 */

void __thiscall WSConn::recv(WSConn *this,long param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 auStack_38 [16];
  code *pcStack_28;
  undefined8 uStack_20;
  
  puVar2 = operator_new(0x18);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar1 = *(undefined8 **)(this + 0x48);
  *(undefined8 **)(this + 0x48) = puVar2;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    operator_delete(puVar1);
  }
  this[0x59] = (WSConn)0x0;
  pcStack_28 = (code *)0x0;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(auStack_38,param_2,2);
    pcStack_28 = *(code **)(param_2 + 0x10);
    uStack_20 = *(undefined8 *)(param_2 + 0x18);
  }
  read_head(this,auStack_38);
  if (pcStack_28 != (code *)0x0) {
    (*pcStack_28)(auStack_38,auStack_38,3);
  }
  return;
}



