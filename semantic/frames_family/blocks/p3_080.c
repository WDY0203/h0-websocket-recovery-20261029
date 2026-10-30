
/* WARNING: Switch with 1 destination removed at 0x001073f0 */

void __thiscall WSConn::~WSConn(WSConn *this)

{
  undefined8 *puVar1;
  
  *(undefined **)this = PTR_vtable_00324f30 + 0x10;
  if (this[0x58] != (WSConn)0x0) {
    inflateEnd(*(undefined8 *)(this + 0x60));
    deflateEnd(*(undefined8 *)(this + 0x68));
    operator_delete(*(void **)(this + 0x60));
    operator_delete(*(void **)(this + 0x68));
  }
  puVar1 = *(undefined8 **)(this + 0x50);
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this + 0x48);
  *(undefined8 *)(this + 0x50) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this + 0x40);
  *(undefined8 *)(this + 0x48) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      operator_delete((void *)*puVar1);
    }
    operator_delete(puVar1);
  }
  *(undefined8 *)(this + 0x40) = 0;
  std::
  _Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
  ::_M_erase((_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
              *)(this + 8),*(_Rb_tree_node **)(this + 0x18));
  *(undefined **)this = PTR_vtable_00324ef0 + 0x10;
  return;
}



