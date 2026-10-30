
undefined8 FUN_0010a780(undefined8 param_1,undefined8 param_2)

{
  allocator *paVar1;
  int *piVar2;
  EventLoop2 *pEVar3;
  long lVar4;
  EventLoop2 *pEVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  EventLoop2 *this;
  UnixClient *pUVar10;
  undefined8 uVar11;
  ulong uVar12;
  EventLoop2 *pEVar13;
  allocator *paVar14;
  long local_268 [2];
  undefined8 local_258 [2];
  char *local_248 [2];
  undefined8 *local_238 [2];
  code *local_228;
  code *pcStack_220;
  undefined8 *local_218 [2];
  code *local_208;
  code *pcStack_200;
  undefined1 local_1f8 [16];
  code *local_1e8;
  code *pcStack_1e0;
  undefined1 local_1d8 [16];
  code *local_1c8;
  code *pcStack_1c0;
  undefined1 local_1b8 [16];
  code *local_1a8;
  code *pcStack_1a0;
  undefined2 local_198;
  undefined1 local_196;
  code *local_188;
  code *pcStack_180;
  _union_1457 local_178;
  sigset_t local_170;
  undefined4 local_f0;
  sigaction local_d8;
  
  local_178.sa_handler = (__sighandler_t)0x0;
  local_f0 = 0;
  sigemptyset(&local_170);
  sigaction(2,(sigaction *)&local_178,&local_d8);
  local_196 = 0;
  local_198 = 0x4f4f;
  iVar7 = PyArg_ParseTuple(param_2,(allocator *)&local_198,local_268,local_258);
  if (iVar7 == 0) {
    uVar11 = 0;
  }
  else {
    uVar8 = PyLong_AsLong(local_258[0]);
    if ((*(byte *)(*(long *)(local_268[0] + 8) + 0xab) & 8) == 0) {
      pcVar9 = (char *)PyUnicode_AsUTF8();
      std::string::string((string *)local_248,pcVar9,(allocator *)&local_198);
    }
    else {
      uVar12 = PyBytes_Size();
      pcVar9 = (char *)PyBytes_AsString(local_268[0]);
      std::string::string((string *)local_248,pcVar9,uVar12,(allocator *)&local_198);
    }
    this = operator_new(0xf0);
    EventLoop2::EventLoop2(this);
    pEVar3 = this + 0xa8;
    *(undefined4 *)(this + 0x80) = 0;
    *(undefined8 *)(this + 0x88) = 0;
    *(undefined8 *)(this + 0xa0) = 0;
    *(EventLoop2 **)(this + 0x90) = this + 0x80;
    *(EventLoop2 **)(this + 0x98) = this + 0x80;
    puVar6 = PTR_vtable_00324f90;
    *(EventLoop2 **)(this + 0xa8) = pEVar3;
    *(EventLoop2 **)(this + 0xb0) = pEVar3;
    this[0xb8] = (EventLoop2)0x0;
    *(undefined8 *)(this + 0xd0) = 0;
    local_208 = (code *)0x0;
    *(undefined **)(this + 0x70) = puVar6 + 0x10;
    local_218[0] = operator_new(8);
    *local_218[0] = this;
    local_228 = (code *)0x0;
    pcStack_200 = FUN_00107980;
    local_208 = FUN_00107b30;
    local_238[0] = operator_new(8);
    *local_238[0] = this;
    pcStack_220 = FUN_001091e0;
    local_228 = FUN_00107bb0;
    if ((*(long *)(local_248[0] + -0x18) == 0) || (*local_248[0] != '/')) {
      local_1c8 = (code *)0x0;
      FUN_00107bb0(local_1d8,local_238,2);
      local_1e8 = (code *)0x0;
      local_1c8 = local_228;
      pcStack_1c0 = pcStack_220;
      if (local_208 != (code *)0x0) {
        (*local_208)(local_1f8,local_218,2);
        local_1e8 = local_208;
        pcStack_1e0 = pcStack_200;
      }
      pUVar10 = operator_new(0xe8);
      TcpClient::TcpClient((TcpClient *)pUVar10,local_248,uVar8,local_1d8,local_1f8);
      if (local_1e8 != (code *)0x0) {
        (*local_1e8)(local_1f8,local_1f8,3);
      }
      if (local_1c8 != (code *)0x0) {
        (*local_1c8)(local_1d8,local_1d8,3);
      }
    }
    else {
      local_188 = (code *)0x0;
      FUN_00107bb0((allocator *)&local_198,local_238,2);
      local_1a8 = (code *)0x0;
      local_188 = local_228;
      pcStack_180 = pcStack_220;
      if (local_208 != (code *)0x0) {
        (*local_208)(local_1b8,local_218,2);
        local_1a8 = local_208;
        pcStack_1a0 = pcStack_200;
      }
      pUVar10 = operator_new(0xe8);
      UnixClient::UnixClient(pUVar10,local_248,(allocator *)&local_198);
      if (local_1a8 != (code *)0x0) {
        (*local_1a8)(local_1b8,local_1b8,3);
      }
      if (local_188 != (code *)0x0) {
        (*local_188)((allocator *)&local_198,(allocator *)&local_198,3);
      }
    }
    EventLoop2::add(this,(EventHandler *)pUVar10);
    if (local_228 != (code *)0x0) {
      (*local_228)(local_238,local_238,3);
    }
    if (local_208 != (code *)0x0) {
      (*local_208)(local_218,local_218,3);
    }
    local_188 = (code *)0x0;
    iVar7 = EventLoop2::run(this,(allocator *)&local_198);
    if (local_188 != (code *)0x0) {
      (*local_188)((allocator *)&local_198,(allocator *)&local_198,3);
    }
    paVar14 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
    if (iVar7 == 0) {
      *(undefined **)(this + 0x70) = PTR_vtable_00324f90 + 0x10;
      if (*(code **)(this + 0xd0) != (code *)0x0) {
        (**(code **)(this + 0xd0))(this + 0xc0,this + 0xc0,3);
      }
      paVar14 = (allocator *)PTR__S_empty_rep_storage_00324fa0;
      pEVar13 = *(EventLoop2 **)(this + 0xa8);
      if (pEVar3 != pEVar13) {
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          do {
            lVar4 = *(long *)(pEVar13 + 0x18);
            pEVar5 = *(EventLoop2 **)pEVar13;
            if (((allocator *)(lVar4 + -0x18) != paVar14) &&
               (iVar7 = *(int *)(lVar4 + -8), *(int *)(lVar4 + -8) = iVar7 + -1, iVar7 < 1)) {
              std::string::_Rep::_M_destroy((allocator *)(lVar4 + -0x18));
            }
            operator_delete(pEVar13);
            pEVar13 = pEVar5;
          } while (pEVar3 != pEVar5);
        }
        else {
          do {
            pEVar5 = *(EventLoop2 **)pEVar13;
            paVar1 = (allocator *)(*(long *)(pEVar13 + 0x18) + -0x18);
            if (paVar1 != paVar14) {
              LOCK();
              piVar2 = (int *)(*(long *)(pEVar13 + 0x18) + -8);
              iVar7 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
              if (iVar7 < 1) {
                std::string::_Rep::_M_destroy(paVar1);
              }
            }
            operator_delete(pEVar13);
            pEVar13 = pEVar5;
          } while (pEVar3 != pEVar5);
        }
      }
      std::
      _Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
      ::_M_erase((_Rb_tree<Root*,std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>,std::_Select1st<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>,std::less<Root*>,std::allocator<std::pair<Root*const,std::unique_ptr<Root,std::default_delete<Root>>>>>
                  *)(this + 0x78),*(_Rb_tree_node **)(this + 0x88));
      *(undefined **)(this + 0x70) = PTR_vtable_00324ef0 + 0x10;
      EventLoop2::~EventLoop2(this);
      operator_delete(this);
      this = (EventLoop2 *)0x0;
    }
    if ((allocator *)(local_248[0] + -0x18) != paVar14) {
      piVar2 = (int *)(local_248[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar7 = *(int *)(local_248[0] + -8);
        *(int *)(local_248[0] + -8) = iVar7 + -1;
      }
      else {
        LOCK();
        iVar7 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar7 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_248[0] + -0x18));
      }
    }
    uVar11 = PyLong_FromVoidPtr(this);
  }
  sigaction(2,&local_d8,(sigaction *)0x0);
  return uVar11;
}



