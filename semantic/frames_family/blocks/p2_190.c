
/* Channel<std::pair<int, std::string > >::~Channel() */

void __thiscall
Channel<std::pair<int,std::string>>::~Channel(Channel<std::pair<int,std::string>> *this)

{
  Channel<std::pair<int,std::string>> *pCVar1;
  allocator *paVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  Channel<std::pair<int,std::string>> *pCVar6;
  undefined *puVar7;
  Channel<std::pair<int,std::string>> *pCVar8;
  
  *(undefined **)this = PTR_vtable_00324f90 + 0x10;
  if (*(code **)(this + 0x60) != (code *)0x0) {
    (**(code **)(this + 0x60))(this + 0x50,this + 0x50,3);
  }
  puVar7 = PTR__S_empty_rep_storage_00324fa0;
  pCVar8 = *(Channel<std::pair<int,std::string>> **)(this + 0x38);
  pCVar1 = this + 0x38;
  if (pCVar8 != pCVar1) {
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      do {
        lVar5 = *(long *)(pCVar8 + 0x18);
        pCVar6 = *(Channel<std::pair<int,std::string>> **)pCVar8;
        if (((allocator *)(lVar5 + -0x18) != (allocator *)puVar7) &&
           (iVar4 = *(int *)(lVar5 + -8), *(int *)(lVar5 + -8) = iVar4 + -1, iVar4 < 1)) {
          std::string::_Rep::_M_destroy((allocator *)(lVar5 + -0x18));
        }
        operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
    else {
      do {
        pCVar6 = *(Channel<std::pair<int,std::string>> **)pCVar8;
        paVar2 = (allocator *)(*(long *)(pCVar8 + 0x18) + -0x18);
        if (paVar2 != (allocator *)puVar7) {
          LOCK();
          piVar3 = (int *)(*(long *)(pCVar8 + 0x18) + -8);
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 < 1) {
            std::string::_Rep::_M_destroy(paVar2);
          }
        }
        operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
  }
  std::
  _Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
  ::_M_erase((_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
              *)(this + 8),*(_Rb_tree_node **)(this + 0x18));
  *(undefined **)this = PTR_vtable_00324ef0 + 0x10;
  return;
}



