
/* WARNING: Switch with 1 destination removed at 0x00107530 */

void __thiscall
std::
_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
::_M_erase(_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
           *this,_Rb_tree_node *param_1)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  void *pvVar8;
  _Rb_tree_node *p_Var9;
  void *pvVar10;
  
  while (param_1 != (_Rb_tree_node *)0x0) {
    pvVar10 = *(void **)(param_1 + 0x18);
    while (pvVar10 != (void *)0x0) {
      pvVar8 = *(void **)((long)pvVar10 + 0x18);
      while (pvVar8 != (void *)0x0) {
        pvVar7 = *(void **)((long)pvVar8 + 0x18);
        while (pvVar7 != (void *)0x0) {
          pvVar6 = *(void **)((long)pvVar7 + 0x18);
          while (pvVar6 != (void *)0x0) {
            pvVar5 = *(void **)((long)pvVar6 + 0x18);
            while (pvVar5 != (void *)0x0) {
              pvVar4 = *(void **)((long)pvVar5 + 0x18);
              while (pvVar4 != (void *)0x0) {
                pvVar3 = *(void **)((long)pvVar4 + 0x18);
                while (pvVar3 != (void *)0x0) {
                  pvVar2 = *(void **)((long)pvVar3 + 0x18);
                  while (pvVar2 != (void *)0x0) {
                    _M_erase(this,*(_Rb_tree_node **)((long)pvVar2 + 0x18));
                    pvVar1 = *(void **)((long)pvVar2 + 0x10);
                    if (*(long **)((long)pvVar2 + 0x28) != (long *)0x0) {
                      (**(code **)(**(long **)((long)pvVar2 + 0x28) + 8))();
                    }
                    *(undefined8 *)((long)pvVar2 + 0x28) = 0;
                    operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long)pvVar3 + 0x10);
                  if (*(long **)((long)pvVar3 + 0x28) != (long *)0x0) {
                    (**(code **)(**(long **)((long)pvVar3 + 0x28) + 8))();
                  }
                  *(undefined8 *)((long)pvVar3 + 0x28) = 0;
                  operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long)pvVar4 + 0x10);
                if (*(long **)((long)pvVar4 + 0x28) != (long *)0x0) {
                  (**(code **)(**(long **)((long)pvVar4 + 0x28) + 8))();
                }
                *(undefined8 *)((long)pvVar4 + 0x28) = 0;
                operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long)pvVar5 + 0x10);
              if (*(long **)((long)pvVar5 + 0x28) != (long *)0x0) {
                (**(code **)(**(long **)((long)pvVar5 + 0x28) + 8))();
              }
              *(undefined8 *)((long)pvVar5 + 0x28) = 0;
              operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long)pvVar6 + 0x10);
            if (*(long **)((long)pvVar6 + 0x28) != (long *)0x0) {
              (**(code **)(**(long **)((long)pvVar6 + 0x28) + 8))();
            }
            *(undefined8 *)((long)pvVar6 + 0x28) = 0;
            operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long)pvVar7 + 0x10);
          if (*(long **)((long)pvVar7 + 0x28) != (long *)0x0) {
            (**(code **)(**(long **)((long)pvVar7 + 0x28) + 8))();
          }
          *(undefined8 *)((long)pvVar7 + 0x28) = 0;
          operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long)pvVar8 + 0x10);
        if (*(long **)((long)pvVar8 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)((long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long)pvVar8 + 0x28) = 0;
        operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long)pvVar10 + 0x10);
      if (*(long **)((long)pvVar10 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)((long)pvVar10 + 0x28) + 8))();
      }
      *(undefined8 *)((long)pvVar10 + 0x28) = 0;
      operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 8))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}



