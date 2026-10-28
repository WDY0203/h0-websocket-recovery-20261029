#include "../H0WS3_shim.hpp"

// ------------------------------------------------------------------
// IDX 201  0010dea0  FUN_0010dea0
// ------------------------------------------------------------------
void rea_FUN_0010dea0(undefined8 * param_1)
{
  int *piVar1;
  string *psVar2;
  undefined *puVar3;
  int iVar4;
  undefined *local_38 [2];
  long long local_28 [2];
  
  psVar2 = (string *)*param_1;
  rea_std__string__string((string *)local_38,psVar2);
  puVar3 = PTR__S_empty_rep_storage_00324fa0;
  if (*(long long *)(psVar2 + 0x18) != 0) {
    local_28[0] = (long long)local_38[0];
    local_38[0] = PTR__S_empty_rep_storage_00324fa0 + 0x18;
    (**(code **)(psVar2 + 0x20))(psVar2 + 8,local_28);
    if ((allocator *)(local_28[0] + -0x18) != (allocator *)puVar3) {
      piVar1 = (int *)(local_28[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar4 = *(int *)(local_28[0] + -8);
        *(int *)(local_28[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_28[0] + -0x18));
      }
    }
    if ((allocator *)(local_38[0] + -0x18) != (allocator *)puVar3) {
      piVar1 = (int *)(local_38[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar4 = *(int *)(local_38[0] + -8);
        *(int *)(local_38[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_38[0] + -0x18));
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 213  0010ee70  WSConn__dtor_WSConn
// ------------------------------------------------------------------
void rea_WSConn__dtor_WSConn__dup2(WSConn * this_ptr)
{
  undefined8 *puVar1;
  
  *(undefined **)this_ptr = PTR_vtable_00324f30 + 0x10;
  if (this_ptr[0x58] != (WSConn)0x0) {
    rea_inflateEnd(*(undefined8 *)(this_ptr + 0x60));
    rea_deflateEnd(*(undefined8 *)(this_ptr + 0x68));
    rea_operator_delete(*(void **)(this_ptr + 0x60));
    rea_operator_delete(*(void **)(this_ptr + 0x68));
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x50);
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x48);
  *(undefined8 *)(this_ptr + 0x50) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  puVar1 = *(undefined8 **)(this_ptr + 0x40);
  *(undefined8 *)(this_ptr + 0x48) = 0;
  if (puVar1 != (undefined8 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      rea_operator_delete((void *)*puVar1);
    }
    rea_operator_delete(puVar1);
  }
  *(undefined8 *)(this_ptr + 0x40) = 0;
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 214  0010ef60  WSConn__dtor_WSConn
// ------------------------------------------------------------------
void rea_WSConn__dtor_WSConn__dup3(WSConn * this_ptr)
{
  dtor_WSConn(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 234  00115840  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void__dup3(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 235  00115850  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void__dup4(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 242  00116380  std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char________________
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char__dup2(long long * param_1, void * param_2, void * param_3, void * param_4)
{
  void *pvVar1;
  size_t sVar2;
  size_t __n;
  void *pvVar3;
  ulong uVar4;
  size_t sVar5;
  ulong uVar6;
  void *__src;
  bool bVar7;
  
  if (param_3 == param_4) {
    return;
  }
  pvVar3 = (void *)param_1[1];
  __n = (long long)param_4 - (long long)param_3;
  if (__n <= (ulong)(param_1[2] - (long long)pvVar3)) {
    uVar6 = (long long)pvVar3 - (long long)param_2;
    if (__n < uVar6) {
      __src = (void *)((long long)pvVar3 - __n);
      pvVar1 = pvVar3;
      if ((long long)pvVar3 - (long long)__src != 0) {
        pvVar1 = rea_memmove(pvVar3,__src,(long long)pvVar3 - (long long)__src);
        pvVar3 = (void *)param_1[1];
      }
      sVar2 = (long long)__src - (long long)param_2;
      param_1[1] = (long long)pvVar3 + __n;
      if (sVar2 != 0) {
        rea_memmove((void *)((long long)pvVar1 - sVar2),param_2,sVar2);
        if (__n == 0) {
          return;
        }
        goto LAB_00116438;
      }
    }
    else {
      pvVar1 = (void *)((long long)param_3 + uVar6);
      if ((long long)param_4 - (long long)pvVar1 != 0) {
        rea_memmove(pvVar3,pvVar1,(long long)param_4 - (long long)pvVar1);
        pvVar3 = (void *)param_1[1];
      }
      pvVar3 = (void *)((long long)pvVar3 + (__n - uVar6));
      param_1[1] = (long long)pvVar3;
      if (uVar6 != 0) {
        rea_memmove(pvVar3,param_2,uVar6);
        pvVar3 = (void *)param_1[1];
      }
      __n = (long long)pvVar1 - (long long)param_3;
      param_1[1] = (long long)pvVar3 + uVar6;
    }
    if (__n == 0) {
      return;
    }
LAB_00116438:
    rea_memmove(param_2,param_3,__n);
    return;
  }
  pvVar1 = (void *)*param_1;
  uVar6 = (long long)pvVar3 - (long long)pvVar1;
  if (~uVar6 < __n) {
    rea_std____throw_length_error("vector___M_range_insert");
  }
  else {
    uVar4 = __n;
    if (__n <= uVar6) {
      uVar4 = uVar6;
    }
    bVar7 = CARRY8(uVar6,uVar4);
    uVar4 = uVar6 + uVar4;
    uVar6 = 0xffffffffffffffff;
    if ((!bVar7) && (uVar6 = uVar4, uVar4 == 0)) {
      uVar6 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_00116498;
    }
  }
  pvVar3 = rea_operator_new(uVar6);
  pvVar1 = (void *)*param_1;
LAB_00116498:
  sVar5 = (long long)param_2 - (long long)pvVar1;
  sVar2 = 0;
  if (sVar5 != 0) {
    rea_memmove(pvVar3,pvVar1,sVar5);
    sVar2 = sVar5;
  }
  pvVar1 = (void *)(sVar2 + (long long)pvVar3);
  if (__n != 0) {
    pvVar1 = rea_memmove(pvVar1,param_3,__n);
  }
  sVar5 = param_1[1] - (long long)param_2;
  sVar2 = 0;
  if (sVar5 != 0) {
    rea_memmove((void *)(__n + (long long)pvVar1),param_2,sVar5);
    sVar2 = sVar5;
  }
  if ((void *)*param_1 != (void *)0x0) {
    rea_operator_delete((void *)*param_1);
  }
  *param_1 = (long long)pvVar3;
  param_1[1] = (long long)(__n + (long long)pvVar1) + sVar2;
  param_1[2] = uVar6 + (long long)pvVar3;
  return;
}





// ------------------------------------------------------------------
// IDX 243  00116600  setnonblock
// ------------------------------------------------------------------
void rea_setnonblock__dup2(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,3);
  if (-1 < (int)uVar1) {
    rea_fcntl(param_1,4,(ulong)(uVar1 | 0x800));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 244  00116630  setcloexec
// ------------------------------------------------------------------
void rea_setcloexec__dup2(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,1);
  if (-1 < (int)uVar1) {
    rea_fcntl(param_1,2,(ulong)(uVar1 | 1));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 245  00116660  print_stack
// ------------------------------------------------------------------
void rea_print_stack__dup2(void)
{
  char *__s;
  int iVar1;
  void *__ptr;
  size_t __n;
  long long lVar2;
  undefined1 auStack_348 [808];
  
  iVar1 = rea_backtrace(auStack_348,100);
  __ptr = (void *)rea_backtrace_symbols(auStack_348,iVar1);
  rea_write(2,"backtrace:",10);
  rea_write(2,"\n",1);
  rea_write(2,"<<<<<",5);
  rea_write(2,"\n",1);
  if (__ptr != (void *)0x0) {
    lVar2 = 0;
    if (0 < iVar1) {
      do {
        __s = *(char **)((long long)__ptr + lVar2 * 8);
        lVar2 = lVar2 + 1;
        __n = rea_strlen(__s);
        rea_write(2,__s,__n);
        rea_write(2,"\n",1);
      } while ((int)lVar2 < iVar1);
    }
    rea_free(__ptr);
  }
  rea_write(2,">>>>>",5);
  rea_write(2,"\n",1);
  return;
}





// ------------------------------------------------------------------
// IDX 246  00116770  print_stack_abort
// ------------------------------------------------------------------
void rea_print_stack_abort__dup2(void)
{
  rea_print_stack();
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 247  00116780  is_myaddr
// ------------------------------------------------------------------
undefined8 rea_is_myaddr(char * param_1)
{
  short *psVar1;
  int iVar2;
  char *__s2;
  long long *plVar3;
  long long *local_28 [3];
  
  rea_getifaddrs(local_28);
  plVar3 = local_28[0];
  if (local_28[0] == (long long *)0x0) {
    local_28[0] = (long long *)0x0;
  }
  else {
    do {
      psVar1 = (short *)plVar3[3];
      if ((psVar1 != (short *)0x0) && (*psVar1 == 2)) {
        __s2 = rea_inet_ntoa((in_addr)*(in_addr_t *)(psVar1 + 2));
        iVar2 = rea_strcmp(param_1,__s2);
        if (iVar2 == 0) {
          rea_freeifaddrs(local_28[0]);
          return 1;
        }
      }
      plVar3 = (long long *)*plVar3;
    } while (plVar3 != (long long *)0x0);
  }
  rea_freeifaddrs(local_28[0]);
  return 0;
}





// ------------------------------------------------------------------
// IDX 249  00116910  dirname
// ------------------------------------------------------------------
string * rea_dirname(string * param_1)
{
  char *__s;
  char *pcVar1;
  undefined8 *in_RSI;
  allocator local_19 [9];
  
  __s = (char *)*in_RSI;
  pcVar1 = rea_strrchr(__s,0x2f);
  if (pcVar1 == (char *)0x0) {
    *(undefined **)param_1 = PTR__S_empty_rep_storage_00324fa0 + 0x18;
    return param_1;
  }
  if (__s < pcVar1) {
    do {
      if (pcVar1[-1] != '/') break;
      pcVar1 = pcVar1 + -1;
    } while (pcVar1 != __s);
  }
  rea_std__string__string(param_1,__s,(long long)pcVar1 - (long long)__s,local_19);
  return param_1;
}





// ------------------------------------------------------------------
// IDX 250  00116990  current_time
// ------------------------------------------------------------------
long long rea_current_time__dup2(void)
{
  timeval local_18;
  
  rea_gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  return local_18.tv_sec * 1000000 + local_18.tv_usec;
}





// ------------------------------------------------------------------
// IDX 251  001169c0  EventLoop2__dtor_EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__dtor_EventLoop2__dup2(EventLoop2 * this_ptr)
{
  void *pvVar1;
  long long *plVar2;
  void *pvVar3;
  long long *plVar4;
  
  *(undefined **)this_ptr = PTR_vtable_00324f00 + 0x10;
  rea_close(*(int *)(this_ptr + 0x50));
  pvVar3 = *(void **)(this_ptr + 0x40);
  pvVar1 = *(void **)(this_ptr + 0x38);
  if (pvVar3 != pvVar1) {
    do {
      if (*(code **)((long long)pvVar1 + 0x18) != (code *)0x0) {
        (**(code **)((long long)pvVar1 + 0x18))((long long)pvVar1 + 8,(long long)pvVar1 + 8,3);
      }
      pvVar1 = (void *)((long long)pvVar1 + 0x28);
    } while (pvVar3 != pvVar1);
    pvVar3 = *(void **)(this_ptr + 0x38);
  }
  if (pvVar3 != (void *)0x0) {
    rea_operator_delete(pvVar3);
  }
  plVar4 = *(long long **)(this_ptr + 0x28);
  plVar2 = *(long long **)(this_ptr + 0x20);
  if (plVar4 != plVar2) {
    do {
      if ((long long *)*plVar2 != (long long *)0x0) {
        (**(code **)(*(long long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long long **)(this_ptr + 0x20);
  }
  if (plVar4 != (long long *)0x0) {
    rea_operator_delete(plVar4);
  }
  plVar4 = *(long long **)(this_ptr + 0x10);
  plVar2 = *(long long **)(this_ptr + 8);
  if (plVar4 != plVar2) {
    do {
      if ((long long *)*plVar2 != (long long *)0x0) {
        (**(code **)(*(long long *)*plVar2 + 0x18))();
      }
      *plVar2 = 0;
      plVar2 = plVar2 + 1;
    } while (plVar4 != plVar2);
    plVar4 = *(long long **)(this_ptr + 8);
  }
  if (plVar4 == (long long *)0x0) {
    return;
  }
  rea_operator_delete(plVar4);
  return;
}





// ------------------------------------------------------------------
// IDX 252  00116af0  EventLoop2__dtor_EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__dtor_EventLoop2__dup3(EventLoop2 * this_ptr)
{
  dtor_EventLoop2(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 253  00116b10  EventLoop2__exit
// ------------------------------------------------------------------
void rea_EventLoop2__exit__dup2(EventLoop2 * this_ptr, int param_1)
{
  *(int *)(this_ptr + 0x58) = param_1;
  this_ptr[0x54] = (EventLoop2)0x0;
  return;
}





// ------------------------------------------------------------------
// IDX 254  00116b20  EventLoop2__set_timeout
// ------------------------------------------------------------------
void rea_EventLoop2__set_timeout(EventLoop2 * this_ptr, long long param_1)
{
  *(long long *)(this_ptr + 0x60) = param_1;
  return;
}





// ------------------------------------------------------------------
// IDX 255  00116b30  EventLoop2__EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__EventLoop2__dup2(EventLoop2 * this_ptr)
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_vtable_00324f00;
  *(undefined8 *)(this_ptr + 8) = 0;
  *(undefined8 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x20) = 0;
  *(undefined8 *)(this_ptr + 0x28) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined8 *)(this_ptr + 0x38) = 0;
  *(undefined **)this_ptr = puVar1 + 0x10;
  *(undefined8 *)(this_ptr + 0x40) = 0;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  this_ptr[0x54] = (EventLoop2)0x1;
  *(undefined4 *)(this_ptr + 0x58) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 1000000;
  iVar2 = rea_epoll_create1(0x80000);
  *(int *)(this_ptr + 0x50) = iVar2;
  if (-1 < iVar2) {
    return;
  }
  rea_perror("epoll_create1");
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 259  001175a0  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector__dup2(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr)
{
  long long *plVar1;
  long long *plVar2;
  
  plVar2 = *(long long **)(this_ptr + 8);
  plVar1 = *(long long **)this_ptr;
  if (plVar2 != plVar1) {
    do {
      if ((long long *)*plVar1 != (long long *)0x0) {
        (**(code **)(*(long long *)*plVar1 + 0x18))();
      }
      *plVar1 = 0;
      plVar1 = plVar1 + 1;
    } while (plVar2 != plVar1);
    plVar2 = *(long long **)this_ptr;
  }
  if (plVar2 == (long long *)0x0) {
    return;
  }
  rea_operator_delete(plVar2);
  return;
}





// ------------------------------------------------------------------
// IDX 264  00117e90  FUN_00117e90
// ------------------------------------------------------------------
void rea_FUN_00117e90(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 266  00117f10  TcpConn__idle_proc
// ------------------------------------------------------------------
void rea_TcpConn__idle_proc__dup2(TcpConn * this_ptr)
{
  if (*(long long *)(this_ptr + 0xc0) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00117f2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(this_ptr + 200))(this_ptr + 0xb0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 268  00117f90  TcpServer__idle
// ------------------------------------------------------------------
undefined8 rea_TcpServer__idle(TcpServer * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  void *pvVar3;
  _Rb_tree_node_base *p_Var4;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var4 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  do {
    if (p_Var4 == p_Var1) {
      return 0;
    }
    while( true ) {
      rea_TcpConn__idle_proc(*(TcpConn **)(p_Var4 + 0x28));
      if ((*(char *)(*(long long *)(p_Var4 + 0x28) + 0x58) != '\0') ||
         (*(char *)(*(long long *)(p_Var4 + 0x28) + 0x59) != '\0')) break;
      p_Var2 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
      pvVar3 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var4,p_Var1);
      if (*(long long **)((long long)pvVar3 + 0x28) != (long long *)0x0) {
        (**(code **)(**(long long **)((long long)pvVar3 + 0x28) + 8))();
      }
      *(undefined8 *)((long long)pvVar3 + 0x28) = 0;
      rea_operator_delete(pvVar3);
      *(long long *)(this_ptr + 0xe8) = *(long long *)(this_ptr + 0xe8) + -1;
      p_Var4 = p_Var2;
      if (p_Var2 == p_Var1) {
        return 0;
      }
    }
    p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
  } while( true );
}





// ------------------------------------------------------------------
// IDX 269  00118040  TcpServer__iter
// ------------------------------------------------------------------
void rea_TcpServer__iter(TcpServer * this_ptr, long long param_2)
{
  _Rb_tree_node_base *p_Var1;
  
  p_Var1 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  while( true ) {
    if (p_Var1 == (_Rb_tree_node_base *)(this_ptr + 200)) {
      return;
    }
    if (*(long long *)(param_2 + 0x10) == 0) break;
    (**(code **)(param_2 + 0x18))
              (param_2,*(undefined4 *)(p_Var1 + 0x20),*(undefined8 *)(p_Var1 + 0x28));
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var1);
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 270  00118090  TcpClient__dtor_TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__dtor_TcpClient__dup2(TcpClient * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  undefined *puVar3;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  TcpClient *pTVar4;
  
  *(undefined **)this_ptr = PTR_vtable_00324f98 + 0x10;
  if (*(code **)(this_ptr + 0xd8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xd8))(this_ptr + 200,this_ptr + 200,3);
  }
  if (*(code **)(this_ptr + 0xb8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xb8))(this_ptr + 0xa8,this_ptr + 0xa8,3);
  }
  if (*(long long **)(this_ptr + 0xa0) != (long long *)0x0) {
    (**(code **)(**(long long **)(this_ptr + 0xa0) + 8))();
  }
  puVar3 = PTR_vtable_00324fb8;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  pTVar4 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pTVar4 + -0x30);
    pvVar2 = *(void **)(pTVar4 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pTVar4 = (TcpClient *)this_00;
  } while (this_ptr + 0x38 != (TcpClient *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 271  00118170  TcpClient__dtor_TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__dtor_TcpClient__dup3(TcpClient * this_ptr)
{
  dtor_TcpClient(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 273  00118320  TcpClient__TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__TcpClient__dup2(TcpClient * this_ptr, int param_1, long long param_3)
{
  int *piVar1;
  long long *plVar2;
  undefined *puVar3;
  int iVar4;
  TcpConn *this_00;
  allocator local_3a [2];
  long long local_38 [2];
  
  *(TcpClient **)(this_ptr + 0x20) = this_ptr + 0x10;
  *(TcpClient **)(this_ptr + 0x28) = this_ptr + 0x10;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(TcpClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(TcpClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(TcpClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(TcpClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar3 = PTR_vtable_00324f98;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 1;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  rea_setcloexec(param_1);
  rea_setnonblock(param_1);
  rea_std__string__string((string *)local_38,"",local_3a);
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,param_1,(string *)local_38,(string *)local_38,(EventHandler *)this_ptr);
  plVar2 = *(long long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar2 != (long long *)0x0) {
    (**(code **)(*plVar2 + 8))();
  }
  if ((allocator *)(local_38[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_38[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(local_38[0] + -8);
      *(int *)(local_38[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_38[0] + -0x18));
    }
  }
  if (*(long long *)(param_3 + 0x10) != 0) {
    (**(code **)(param_3 + 0x18))(param_3,*(undefined8 *)(this_ptr + 0xa0));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 274  00118550  TcpConn__dtor_TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__dtor_TcpConn__dup2(TcpConn * this_ptr)
{
  int *piVar1;
  long long lVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  int iVar5;
  int local_28 [4];
  
  lVar2 = *(long long *)(this_ptr + 0x38);
  *(undefined **)this_ptr = PTR_vtable_00324f08 + 0x10;
  local_28[0] = *(int *)(this_ptr + 0x40);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(lVar2 + 8),local_28);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(lVar2 + 0x38),local_28);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(lVar2 + 0x68),local_28);
  rea_close(*(int *)(this_ptr + 0x40));
  if (*(code **)(this_ptr + 0xc0) != (code *)0x0) {
    (**(code **)(this_ptr + 0xc0))(this_ptr + 0xb0,this_ptr + 0xb0,3);
  }
  if (*(code **)(this_ptr + 0xa0) != (code *)0x0) {
    (**(code **)(this_ptr + 0xa0))(this_ptr + 0x90,this_ptr + 0x90,3);
  }
  if (*(code **)(this_ptr + 0x78) != (code *)0x0) {
    (**(code **)(this_ptr + 0x78))(this_ptr + 0x68,this_ptr + 0x68,3);
  }
  puVar3 = *(undefined8 **)(this_ptr + 0x60);
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)*puVar3 != (void *)0x0) {
      rea_operator_delete((void *)*puVar3);
    }
    rea_operator_delete(puVar3);
  }
  puVar4 = PTR__S_empty_rep_storage_00324fa0;
  lVar2 = *(long long *)(this_ptr + 0x50);
  *(undefined8 *)(this_ptr + 0x60) = 0;
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar4) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar5 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  lVar2 = *(long long *)(this_ptr + 0x48);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar4) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar5 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 275  001186c0  TcpConn__dtor_TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__dtor_TcpConn__dup3(TcpConn * this_ptr)
{
  dtor_TcpConn(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 276  001186e0  TcpServer__dtor_TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__dtor_TcpServer__dup2(TcpServer * this_ptr)
{
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var1;
  int local_38 [6];
  
  p_Var1 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(this_ptr + 0x98);
  *(undefined **)this_ptr = PTR_vtable_00324f48 + 0x10;
  local_38[0] = *(int *)(this_ptr + 0xb8);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 8),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x38),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x68),local_38);
  rea_close(*(int *)(this_ptr + 0xb8));
  std______Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn______M_erase((_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn
              *)(this_ptr + 0xc0),*(_Rb_tree_node **)(this_ptr + 0xd0));
  if (*(code **)(this_ptr + 0xa8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xa8))(p_Var1,p_Var1,3);
  }
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  while ((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
          *)(this_ptr + 0x38) != p_Var1) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________M_erase(p_Var1 + -0x30,*(_Rb_tree_node **)(p_Var1 + -0x20));
    p_Var1 = p_Var1 + -0x30;
  }
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 277  001187b0  TcpServer__dtor_TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__dtor_TcpServer__dup3(TcpServer * this_ptr)
{
  dtor_TcpServer(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 285  0011c920  EventHandler__idle
// ------------------------------------------------------------------
undefined8 rea_EventHandler__idle(void)
{
  return 0;
}





// ------------------------------------------------------------------
// IDX 287  0011ca60  EventHandler__dtor_EventHandler
// ------------------------------------------------------------------
void rea_EventHandler__dtor_EventHandler__dup2(EventHandler * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  EventHandler *pEVar3;
  
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  pEVar3 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pEVar3 + -0x30);
    pvVar2 = *(void **)(pEVar3 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pEVar3 = (EventHandler *)this_00;
  } while (this_ptr + 0x38 != (EventHandler *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 288  0011cae0  EventHandler__dtor_EventHandler
// ------------------------------------------------------------------
void rea_EventHandler__dtor_EventHandler__dup3(EventHandler * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  EventHandler *pEVar3;
  
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  pEVar3 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pEVar3 + -0x30);
    pvVar2 = *(void **)(pEVar3 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pEVar3 = (EventHandler *)this_00;
  } while (this_ptr + 0x38 != (EventHandler *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 289  0011cb70  std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple____________
// ------------------------------------------------------------------
_Rb_tree_node_base * rea_std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple(long long param_1, _Rb_tree_node_base * param_2, undefined8 param_3, undefined8 * param_4)
{
  _Rb_tree_node_base *p_Var1;
  undefined4 uVar2;
  _Rb_tree_node_base *p_Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  _Rb_tree_node_base *p_Var6;
  int iVar7;
  bool bVar8;
  int iVar9;
  
  p_Var3 = rea_operator_new(0x30);
  if (p_Var3 != (_Rb_tree_node_base *)0x0) {
    *(undefined4 *)p_Var3 = 0;
    *(undefined8 *)(p_Var3 + 8) = 0;
    *(undefined8 *)(p_Var3 + 0x10) = 0;
    *(undefined8 *)(p_Var3 + 0x18) = 0;
    uVar2 = *(undefined4 *)*param_4;
    *(undefined8 *)(p_Var3 + 0x28) = 0;
    *(undefined4 *)(p_Var3 + 0x20) = uVar2;
  }
  p_Var1 = (_Rb_tree_node_base *)(param_1 + 8);
  p_Var6 = p_Var1;
  if (p_Var1 == param_2) {
    if ((*(long long *)(param_1 + 0x28) == 0) ||
       (p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x20),
       *(int *)(p_Var3 + 0x20) <= *(int *)(p_Var4 + 0x20))) {
      if (*(_Rb_tree_node_base **)(param_1 + 0x10) == (_Rb_tree_node_base *)0x0) {
LAB_0011ce23:
        if (*(_Rb_tree_node_base **)(param_1 + 0x18) == p_Var6) goto LAB_0011cd9e;
        param_2 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var6);
        iVar9 = *(int *)(p_Var3 + 0x20);
        iVar7 = *(int *)(param_2 + 0x20);
      }
      else {
        iVar9 = *(int *)(p_Var3 + 0x20);
        p_Var6 = *(_Rb_tree_node_base **)(param_1 + 0x10);
        do {
          param_2 = p_Var6;
          iVar7 = *(int *)(param_2 + 0x20);
          if (iVar9 < iVar7) {
            p_Var6 = *(_Rb_tree_node_base **)(param_2 + 0x10);
          }
          else {
            p_Var6 = *(_Rb_tree_node_base **)(param_2 + 0x18);
          }
        } while (p_Var6 != (_Rb_tree_node_base *)0x0);
        p_Var6 = param_2;
        if (iVar9 < iVar7) goto LAB_0011ce23;
      }
      if (iVar9 <= iVar7) goto LAB_0011cca0;
LAB_0011cd9e:
      param_2 = (_Rb_tree_node_base *)0x0;
      p_Var4 = p_Var6;
      if (p_Var6 == (_Rb_tree_node_base *)0x0) {
LAB_0011cca0:
        if (*(long long **)(p_Var3 + 0x28) != (long long *)0x0) {
          (**(code **)(**(long long **)(p_Var3 + 0x28) + 8))();
        }
        *(undefined8 *)(p_Var3 + 0x28) = 0;
        rea_operator_delete(p_Var3);
        return param_2;
      }
    }
LAB_0011ccf0:
    if (p_Var1 == p_Var4) {
      bVar8 = true;
      goto LAB_0011cc1c;
    }
    iVar9 = *(int *)(p_Var3 + 0x20);
    iVar7 = *(int *)(p_Var4 + 0x20);
  }
  else {
    iVar9 = *(int *)(p_Var3 + 0x20);
    iVar7 = *(int *)(param_2 + 0x20);
    if (iVar9 < iVar7) {
      p_Var6 = *(_Rb_tree_node_base **)(param_1 + 0x18);
      p_Var5 = param_2;
      if (p_Var6 != param_2) {
        p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(param_2);
        if (iVar9 <= *(int *)(p_Var4 + 0x20)) {
          p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x10);
          p_Var5 = p_Var1;
          if (*(_Rb_tree_node_base **)(param_1 + 0x10) != (_Rb_tree_node_base *)0x0) {
            do {
              param_2 = p_Var4;
              iVar7 = *(int *)(param_2 + 0x20);
              if (iVar9 < iVar7) {
                p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x10);
              }
              else {
                p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x18);
              }
            } while (p_Var4 != (_Rb_tree_node_base *)0x0);
            p_Var5 = param_2;
            if (iVar9 >= iVar7) goto joined_r0x0011cd92;
          }
          if (p_Var6 != p_Var5) {
            param_2 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
            iVar7 = *(int *)(param_2 + 0x20);
joined_r0x0011cd92:
            p_Var6 = p_Var5;
            if (iVar9 <= iVar7) goto LAB_0011cca0;
          }
          goto LAB_0011cd9e;
        }
        if (*(long long *)(p_Var4 + 0x18) == 0) goto LAB_0011ccf0;
      }
LAB_0011cc0b:
      bVar8 = true;
      p_Var4 = p_Var5;
      if (p_Var5 != (_Rb_tree_node_base *)0x0) goto LAB_0011cc1c;
      goto LAB_0011ccf0;
    }
    if (iVar9 <= iVar7) goto LAB_0011cca0;
    p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x20);
    if (p_Var4 == param_2) goto LAB_0011ccf0;
    p_Var5 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(param_2);
    if (*(int *)(p_Var5 + 0x20) <= iVar9) {
      p_Var4 = *(_Rb_tree_node_base **)(param_1 + 0x10);
      if (*(_Rb_tree_node_base **)(param_1 + 0x10) != (_Rb_tree_node_base *)0x0) {
        do {
          param_2 = p_Var4;
          iVar7 = *(int *)(param_2 + 0x20);
          if (iVar9 < iVar7) {
            p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x10);
          }
          else {
            p_Var4 = *(_Rb_tree_node_base **)(param_2 + 0x18);
          }
        } while (p_Var4 != (_Rb_tree_node_base *)0x0);
        p_Var6 = param_2;
        p_Var5 = param_2;
        if (iVar9 >= iVar7) goto joined_r0x0011cd92;
      }
      if (*(_Rb_tree_node_base **)(param_1 + 0x18) != p_Var6) {
        param_2 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var6);
        iVar7 = *(int *)(param_2 + 0x20);
        p_Var5 = p_Var6;
        goto joined_r0x0011cd92;
      }
      goto LAB_0011cd9e;
    }
    p_Var4 = param_2;
    if (*(long long *)(param_2 + 0x18) != 0) goto LAB_0011cc0b;
  }
  bVar8 = iVar9 < iVar7;
LAB_0011cc1c:
  rea_std___Rb_tree_insert_and_rebalance(bVar8,p_Var3,p_Var4,p_Var1);
  *(long long *)(param_1 + 0x28) = *(long long *)(param_1 + 0x28) + 1;
  return p_Var3;
}





// ------------------------------------------------------------------
// IDX 290  0011ce80  std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase__dup2(_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn * this_ptr, _Rb_tree_node * param_1)
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
      pvVar8 = *(void **)((long long)pvVar10 + 0x18);
      while (pvVar8 != (void *)0x0) {
        pvVar7 = *(void **)((long long)pvVar8 + 0x18);
        while (pvVar7 != (void *)0x0) {
          pvVar6 = *(void **)((long long)pvVar7 + 0x18);
          while (pvVar6 != (void *)0x0) {
            pvVar5 = *(void **)((long long)pvVar6 + 0x18);
            while (pvVar5 != (void *)0x0) {
              pvVar4 = *(void **)((long long)pvVar5 + 0x18);
              while (pvVar4 != (void *)0x0) {
                pvVar3 = *(void **)((long long)pvVar4 + 0x18);
                while (pvVar3 != (void *)0x0) {
                  pvVar2 = *(void **)((long long)pvVar3 + 0x18);
                  while (pvVar2 != (void *)0x0) {
                    _M_erase(this_ptr,*(_Rb_tree_node **)((long long)pvVar2 + 0x18));
                    pvVar1 = *(void **)((long long)pvVar2 + 0x10);
                    if (*(long long **)((long long)pvVar2 + 0x28) != (long long *)0x0) {
                      (**(code **)(**(long long **)((long long)pvVar2 + 0x28) + 8))();
                    }
                    *(undefined8 *)((long long)pvVar2 + 0x28) = 0;
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long long)pvVar3 + 0x10);
                  if (*(long long **)((long long)pvVar3 + 0x28) != (long long *)0x0) {
                    (**(code **)(**(long long **)((long long)pvVar3 + 0x28) + 8))();
                  }
                  *(undefined8 *)((long long)pvVar3 + 0x28) = 0;
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long long)pvVar4 + 0x10);
                if (*(long long **)((long long)pvVar4 + 0x28) != (long long *)0x0) {
                  (**(code **)(**(long long **)((long long)pvVar4 + 0x28) + 8))();
                }
                *(undefined8 *)((long long)pvVar4 + 0x28) = 0;
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long long)pvVar5 + 0x10);
              if (*(long long **)((long long)pvVar5 + 0x28) != (long long *)0x0) {
                (**(code **)(**(long long **)((long long)pvVar5 + 0x28) + 8))();
              }
              *(undefined8 *)((long long)pvVar5 + 0x28) = 0;
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long long)pvVar6 + 0x10);
            if (*(long long **)((long long)pvVar6 + 0x28) != (long long *)0x0) {
              (**(code **)(**(long long **)((long long)pvVar6 + 0x28) + 8))();
            }
            *(undefined8 *)((long long)pvVar6 + 0x28) = 0;
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long long)pvVar7 + 0x10);
          if (*(long long **)((long long)pvVar7 + 0x28) != (long long *)0x0) {
            (**(code **)(**(long long **)((long long)pvVar7 + 0x28) + 8))();
          }
          *(undefined8 *)((long long)pvVar7 + 0x28) = 0;
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long long)pvVar8 + 0x10);
        if (*(long long **)((long long)pvVar8 + 0x28) != (long long *)0x0) {
          (**(code **)(**(long long **)((long long)pvVar8 + 0x28) + 8))();
        }
        *(undefined8 *)((long long)pvVar8 + 0x28) = 0;
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long long)pvVar10 + 0x10);
      if (*(long long **)((long long)pvVar10 + 0x28) != (long long *)0x0) {
        (**(code **)(**(long long **)((long long)pvVar10 + 0x28) + 8))();
      }
      *(undefined8 *)((long long)pvVar10 + 0x28) = 0;
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    if (*(long long **)(param_1 + 0x28) != (long long *)0x0) {
      (**(code **)(**(long long **)(param_1 + 0x28) + 8))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 292  0011d180  UnixServer__idle
// ------------------------------------------------------------------
undefined8 rea_UnixServer__idle(UnixServer * this_ptr)
{
  _Rb_tree_node_base *p_Var1;
  _Rb_tree_node_base *p_Var2;
  void *pvVar3;
  _Rb_tree_node_base *p_Var4;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var4 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  do {
    if (p_Var4 == p_Var1) {
      return 0;
    }
    while( true ) {
      rea_TcpConn__idle_proc(*(TcpConn **)(p_Var4 + 0x28));
      if ((*(char *)(*(long long *)(p_Var4 + 0x28) + 0x58) != '\0') ||
         (*(char *)(*(long long *)(p_Var4 + 0x28) + 0x59) != '\0')) break;
      p_Var2 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
      pvVar3 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var4,p_Var1);
      if (*(long long **)((long long)pvVar3 + 0x28) != (long long *)0x0) {
        (**(code **)(**(long long **)((long long)pvVar3 + 0x28) + 8))();
      }
      *(undefined8 *)((long long)pvVar3 + 0x28) = 0;
      rea_operator_delete(pvVar3);
      *(long long *)(this_ptr + 0xe8) = *(long long *)(this_ptr + 0xe8) + -1;
      p_Var4 = p_Var2;
      if (p_Var2 == p_Var1) {
        return 0;
      }
    }
    p_Var4 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var4);
  } while( true );
}





// ------------------------------------------------------------------
// IDX 293  0011d230  UnixServer__iter
// ------------------------------------------------------------------
void rea_UnixServer__iter(UnixServer * this_ptr, long long param_2)
{
  _Rb_tree_node_base *p_Var1;
  
  p_Var1 = *(_Rb_tree_node_base **)(this_ptr + 0xd8);
  while( true ) {
    if (p_Var1 == (_Rb_tree_node_base *)(this_ptr + 200)) {
      return;
    }
    if (*(long long *)(param_2 + 0x10) == 0) break;
    (**(code **)(param_2 + 0x18))
              (param_2,*(undefined4 *)(p_Var1 + 0x20),*(undefined8 *)(p_Var1 + 0x28));
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var1);
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 295  0011d5a0  UnixClient__UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__UnixClient__dup3(UnixClient * this_ptr, int param_1, long long param_3)
{
  int *piVar1;
  long long *plVar2;
  undefined *puVar3;
  int iVar4;
  TcpConn *this_00;
  allocator local_3a [2];
  long long local_38 [2];
  
  *(UnixClient **)(this_ptr + 0x20) = this_ptr + 0x10;
  *(UnixClient **)(this_ptr + 0x28) = this_ptr + 0x10;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(UnixClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(UnixClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(UnixClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(UnixClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar3 = PTR_vtable_00324f70;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 1;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  rea_setcloexec(param_1);
  rea_setnonblock(param_1);
  rea_std__string__string((string *)local_38,"",local_3a);
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,param_1,(string *)local_38,(string *)local_38,(EventHandler *)this_ptr);
  plVar2 = *(long long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar2 != (long long *)0x0) {
    (**(code **)(*plVar2 + 8))();
  }
  if ((allocator *)(local_38[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(local_38[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(local_38[0] + -8);
      *(int *)(local_38[0] + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_38[0] + -0x18));
    }
  }
  if (*(long long *)(param_3 + 0x10) != 0) {
    (**(code **)(param_3 + 0x18))(param_3,*(undefined8 *)(this_ptr + 0xa0));
    return;
  }
                    /* WARNING: Subroutine does not return */
  rea_std____throw_bad_function_call();
}





// ------------------------------------------------------------------
// IDX 296  0011d7d0  UnixClient__dtor_UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__dtor_UnixClient__dup2(UnixClient * this_ptr)
{
  void *pvVar1;
  void *pvVar2;
  undefined *puVar3;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *this_00;
  UnixClient *pUVar4;
  
  *(undefined **)this_ptr = PTR_vtable_00324f70 + 0x10;
  if (*(code **)(this_ptr + 0xd8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xd8))(this_ptr + 200,this_ptr + 200,3);
  }
  if (*(code **)(this_ptr + 0xb8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xb8))(this_ptr + 0xa8,this_ptr + 0xa8,3);
  }
  if (*(long long **)(this_ptr + 0xa0) != (long long *)0x0) {
    (**(code **)(**(long long **)(this_ptr + 0xa0) + 8))();
  }
  puVar3 = PTR_vtable_00324fb8;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined **)this_ptr = puVar3 + 0x10;
  pUVar4 = this_ptr + 0x98;
  do {
    this_00 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
               *)(pUVar4 + -0x30);
    pvVar2 = *(void **)(pUVar4 + -0x20);
    while (pvVar2 != (void *)0x0) {
      std__________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int__________M_erase(this_00,*(_Rb_tree_node **)((long long)pvVar2 + 0x18));
      pvVar1 = *(void **)((long long)pvVar2 + 0x10);
      rea_operator_delete(pvVar2);
      pvVar2 = pvVar1;
    }
    pUVar4 = (UnixClient *)this_00;
  } while (this_ptr + 0x38 != (UnixClient *)this_00);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 297  0011d8b0  UnixClient__dtor_UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__dtor_UnixClient__dup3(UnixClient * this_ptr)
{
  dtor_UnixClient(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 298  0011d8d0  UnixServer__poll
// ------------------------------------------------------------------
undefined8 rea_UnixServer__poll(UnixServer * this_ptr, int param_1, int param_2)
{
  _Rb_tree_node_base *p_Var1;
  UnixServer *pUVar2;
  int *piVar3;
  uint *puVar4;
  undefined *puVar5;
  _Rb_tree_node_base *p_Var6;
  UnixServer *pUVar7;
  int iVar8;
  uint uVar9;
  void *pvVar10;
  long long *plVar11;
  TcpConn *this_00;
  UnixServer *pUVar12;
  ulong uVar13;
  UnixServer *pUVar14;
  UnixServer *pUVar15;
  _Rb_tree_node_base *p_Var16;
  _Rb_tree_node_base *p_Var17;
  _Rb_tree_node_base *p_Var18;
  bool bVar19;
  uint local_78 [4];
  long long local_68 [2];
  ulong local_58 [2];
  uint *local_48 [3];
  
  if ((*(int *)(this_ptr + 0xb8) != param_1) || ((param_2 & 1U) == 0)) goto LAB_0011d8fb;
  local_78[0] = rea_accept(*(int *)(this_ptr + 0xb8),(sockaddr *)0x0,(socklen_t *)0x0);
  if ((int)local_78[0] < 0) {
    rea_perror("accept");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setnonblock(local_78[0]);
  rea_setcloexec(local_78[0]);
  rea___gnu_cxx____to_xstring_std__string_char
            ((code *)local_48,
             (ulong)PTR_vsnprintf_00324f60,(char *)0x10,(void *)&DAT_0011fe68,(ulong)local_78[0]);
  rea_std__string__string((string *)local_58,(string *)(this_ptr + 0xf0));
  rea_std__string__append((char *)local_58,0x11fdf2);
  uVar13 = *(long long *)(local_58[0] - 0x18) + *(long long *)(local_48[0] + -6);
  if ((*(ulong *)(local_58[0] - 0x10) < uVar13) && (uVar13 <= *(ulong *)(local_48[0] + -4))) {
    plVar11 = (long long *)rea_std__string__insert((ulong)local_48,(char *)0x0,local_58[0]);
  }
  else {
    plVar11 = (long long *)rea_std__string__append((string *)local_58);
  }
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  local_68[0] = *plVar11;
  *plVar11 = (long long)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  if ((allocator *)(local_58[0] - 0x18) != (allocator *)puVar5) {
    piVar3 = (int *)(local_58[0] - 8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_58[0] - 8);
      *(int *)(local_58[0] - 8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_58[0] - 0x18));
    }
  }
  if ((allocator *)(local_48[0] + -6) != (allocator *)puVar5) {
    puVar4 = local_48[0] + -2;
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      uVar9 = local_48[0][-2];
      local_48[0][-2] = uVar9 - 1;
    }
    else {
      LOCK();
      uVar9 = *puVar4;
      *puVar4 = *puVar4 - 1;
      UNLOCK();
    }
    if ((int)uVar9 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_48[0] + -6));
    }
  }
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,local_78[0],(string *)(this_ptr + 0xf0),(string *)local_68,
                   (EventHandler *)this_ptr);
  pUVar15 = this_ptr + 200;
  pUVar7 = *(UnixServer **)(this_ptr + 0xd0);
  pUVar14 = pUVar15;
  if (*(UnixServer **)(this_ptr + 0xd0) == (UnixServer *)0x0) {
LAB_0011db73:
    local_48[0] = local_78;
    pUVar12 = (UnixServer *)
              std__________________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________________________________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple__________________________(this_ptr + 0xc0,pUVar15,(void *)&DAT_0011ff15,local_48,(string *)local_58);
  }
  else {
    do {
      while (pUVar12 = pUVar7, *(int *)(pUVar12 + 0x20) < (int)local_78[0]) {
        pUVar2 = pUVar12 + 0x18;
        pUVar7 = *(UnixServer **)pUVar2;
        pUVar12 = pUVar14;
        if (*(UnixServer **)pUVar2 == (UnixServer *)0x0) goto LAB_0011db1a;
      }
      pUVar7 = *(UnixServer **)(pUVar12 + 0x10);
      pUVar14 = pUVar12;
    } while (*(UnixServer **)(pUVar12 + 0x10) != (UnixServer *)0x0);
LAB_0011db1a:
    bVar19 = pUVar15 == pUVar12;
    pUVar15 = pUVar12;
    if ((bVar19) || ((int)local_78[0] < *(int *)(pUVar12 + 0x20))) goto LAB_0011db73;
  }
  plVar11 = *(long long **)(pUVar12 + 0x28);
  *(TcpConn **)(pUVar12 + 0x28) = this_00;
  if (plVar11 != (long long *)0x0) {
    (**(code **)(*plVar11 + 8))();
  }
  if (*(long long *)(this_ptr + 0xa8) == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  (**(code **)(this_ptr + 0xb0))(this_ptr + 0x98,this_00);
  if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar5) {
    piVar3 = (int *)(local_68[0] + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar8 = *(int *)(local_68[0] + -8);
      *(int *)(local_68[0] + -8) = iVar8 + -1;
    }
    else {
      LOCK();
      iVar8 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar8 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
    }
  }
LAB_0011d8fb:
  p_Var18 = (_Rb_tree_node_base *)(this_ptr + 200);
  p_Var6 = *(_Rb_tree_node_base **)(this_ptr + 0xd0);
  p_Var16 = p_Var18;
  if (*(_Rb_tree_node_base **)(this_ptr + 0xd0) != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var17 = p_Var6, *(int *)(p_Var17 + 0x20) < param_1) {
        p_Var1 = p_Var17 + 0x18;
        p_Var6 = *(_Rb_tree_node_base **)p_Var1;
        p_Var17 = p_Var16;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011d92a;
      }
      p_Var6 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
      p_Var16 = p_Var17;
    } while (*(_Rb_tree_node_base **)(p_Var17 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011d92a:
    if ((p_Var18 != p_Var17) && (*(int *)(p_Var17 + 0x20) <= param_1)) {
      if ((param_2 & 2U) != 0) {
        rea_TcpConn__send_proc(*(TcpConn **)(p_Var17 + 0x28));
      }
      if ((param_2 & 1U) != 0) {
        rea_TcpConn__recv_proc(*(TcpConn **)(p_Var17 + 0x28));
      }
      if ((*(char *)(*(long long *)(p_Var17 + 0x28) + 0x58) == '\0') &&
         (*(char *)(*(long long *)(p_Var17 + 0x28) + 0x59) == '\0')) {
        pvVar10 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var17,p_Var18);
        if (*(long long **)((long long)pvVar10 + 0x28) != (long long *)0x0) {
          (**(code **)(**(long long **)((long long)pvVar10 + 0x28) + 8))();
        }
        *(undefined8 *)((long long)pvVar10 + 0x28) = 0;
        rea_operator_delete(pvVar10);
        *(long long *)(this_ptr + 0xe8) = *(long long *)(this_ptr + 0xe8) + -1;
      }
    }
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 299  0011dd00  UnixServer__dtor_UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__dtor_UnixServer__dup2(UnixServer * this_ptr)
{
  int *piVar1;
  _Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
  *p_Var2;
  long long lVar3;
  int iVar4;
  int local_38 [6];
  
  *(undefined **)this_ptr = PTR_vtable_00324ec8 + 0x10;
  local_38[0] = *(int *)(this_ptr + 0xb8);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 8),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x38),local_38);
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int_____erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
           *)(this_ptr + 0x68),local_38);
  rea_remove(*(char **)(this_ptr + 0xf0));
  rea_close(*(int *)(this_ptr + 0xb8));
  lVar3 = *(long long *)(this_ptr + 0xf0);
  if ((allocator *)(lVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar3 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar4 = *(int *)(lVar3 + -8);
      *(int *)(lVar3 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar3 + -0x18));
    }
  }
  p_Var2 = (_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
            *)(this_ptr + 0x98);
  std______Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn______M_erase((_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn
              *)(this_ptr + 0xc0),*(_Rb_tree_node **)(this_ptr + 0xd0));
  if (*(code **)(this_ptr + 0xa8) != (code *)0x0) {
    (**(code **)(this_ptr + 0xa8))(p_Var2,p_Var2,3);
  }
  *(undefined **)this_ptr = PTR_vtable_00324fb8 + 0x10;
  while ((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
          *)(this_ptr + 0x38) != p_Var2) {
    std________Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int________M_erase(p_Var2 + -0x30,*(_Rb_tree_node **)(p_Var2 + -0x20));
    p_Var2 = p_Var2 + -0x30;
  }
  std______Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int______M_erase((_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  return;
}





// ------------------------------------------------------------------
// IDX 300  0011de40  UnixServer__dtor_UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__dtor_UnixServer__dup3(UnixServer * this_ptr)
{
  dtor_UnixServer(this_ptr);
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 304  0011f358  _fini
// ------------------------------------------------------------------
void rea__fini(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 305  00326000  std__string__append
// ------------------------------------------------------------------
void rea_std__string__append__dup3(char * param_1, ulong param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 306  00326008  std____throw_length_error
// ------------------------------------------------------------------
void rea_std____throw_length_error__dup2(char * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 307  00326010  memset
// ------------------------------------------------------------------
void * rea_memset__dup2(void * __s, int __c, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 308  00326018  shutdown
// ------------------------------------------------------------------
int rea_shutdown__dup2(int __fd, int __how)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 309  00326020  backtrace
// ------------------------------------------------------------------
void rea_backtrace__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 310  00326028  std____detail___List_node_base___M_unhook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_unhook__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 311  00326030  close
// ------------------------------------------------------------------
int rea_close__dup2(int __fd)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 312  00326038  inflateEnd
// ------------------------------------------------------------------
void rea_inflateEnd__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 313  00326040  abort
// ------------------------------------------------------------------
void rea_abort__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 314  00326048  PyLong_FromVoidPtr
// ------------------------------------------------------------------
void rea_PyLong_FromVoidPtr__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 315  00326050  PyLong_AsVoidPtr
// ------------------------------------------------------------------
void rea_PyLong_AsVoidPtr__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 316  00326058  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup4(string * this_ptr, char * param_1, ulong param_2, allocator * param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 317  00326060  __gmon_start__
// ------------------------------------------------------------------
void rea___gmon_start__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 318  00326068  _Jv_RegisterClasses
// ------------------------------------------------------------------
void rea__Jv_RegisterClasses(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 319  00326070  operator_delete
// ------------------------------------------------------------------
void rea_operator__delete__dup2(void * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 320  00326078  std__string__reserve
// ------------------------------------------------------------------
void rea_std__string__reserve__dup2(ulong param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 321  00326080  std__string___Rep___M_dispose
// ------------------------------------------------------------------
void rea_std__string___Rep___M_dispose__dup2(allocator * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 322  00326088  PyBytes_Size
// ------------------------------------------------------------------
void rea_PyBytes_Size__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 323  00326090  gettimeofday
// ------------------------------------------------------------------
int rea_gettimeofday__dup2(timeval * __tv, __timezone_ptr_t __tz)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 324  00326098  __cxa_rethrow
// ------------------------------------------------------------------
void rea___cxa_rethrow__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 325  003260a0  deflate
// ------------------------------------------------------------------
void rea_deflate__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 326  003260a8  read
// ------------------------------------------------------------------
ssize_t rea_read__dup2(int __fd, void * __buf, size_t __nbytes)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 327  003260b0  std___Rb_tree_decrement
// ------------------------------------------------------------------
void rea_std___Rb_tree_decrement__dup2(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 328  003260b8  std__string___Rep___S_create
// ------------------------------------------------------------------
void rea_std__string___Rep___S_create__dup2(ulong param_1, ulong param_2, allocator * param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 329  003260c0  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup5(string * this_ptr, string * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 330  003260c8  setsockopt
// ------------------------------------------------------------------
int rea_setsockopt__dup2(int __fd, int __level, int __optname, void * __optval, socklen_t __optlen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 331  003260d0  PyLong_AsLong
// ------------------------------------------------------------------
void rea_PyLong_AsLong__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 332  003260d8  inflateInit2_
// ------------------------------------------------------------------
void rea_inflateInit2__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 333  003260e0  _ITM_deregisterTMCloneTable
// ------------------------------------------------------------------
void rea__ITM_deregisterTMCloneTable(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 334  003260e8  bzero
// ------------------------------------------------------------------
void rea_bzero__dup2(void * __s, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 335  003260f0  strnlen
// ------------------------------------------------------------------
size_t rea_strnlen__dup2(char * __string, size_t __maxlen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 336  003260f8  PyArg_ParseTuple
// ------------------------------------------------------------------
void rea_PyArg_ParseTuple__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 337  00326100  inflate
// ------------------------------------------------------------------
void rea_inflate__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 338  00326108  backtrace_symbols
// ------------------------------------------------------------------
void rea_backtrace_symbols__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 339  00326110  free
// ------------------------------------------------------------------
void rea_free__dup2(void * __ptr)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 340  00326118  strlen
// ------------------------------------------------------------------
size_t rea_strlen__dup2(char * __s)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 341  00326120  _ITM_registerTMCloneTable
// ------------------------------------------------------------------
void rea__ITM_registerTMCloneTable(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 342  00326128  std__string___Rep___M_destroy
// ------------------------------------------------------------------
void rea_std__string___Rep___M_destroy__dup2(allocator * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 343  00326130  __xstat
// ------------------------------------------------------------------
int rea___xstat__dup2(int __ver, char * __filename, stat * __stat_buf)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 344  00326138  deflateEnd
// ------------------------------------------------------------------
void rea_deflateEnd__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 345  00326140  listen
// ------------------------------------------------------------------
int rea_listen__dup2(int __fd, int __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 346  00326148  __cxa_finalize
// ------------------------------------------------------------------
void rea___cxa_finalize__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 347  00326150  PyBytes_AsString
// ------------------------------------------------------------------
void rea_PyBytes_AsString__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 348  00326160  strrchr
// ------------------------------------------------------------------
char * rea_strrchr__dup2(char * __s, int __c)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 349  00326168  std__string__insert
// ------------------------------------------------------------------
void rea_std__string__insert__dup2(ulong param_1, char * param_2, ulong param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 350  00326170  std___Rb_tree_increment
// ------------------------------------------------------------------
void rea_std___Rb_tree_increment__dup3(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 351  00326178  epoll_create1
// ------------------------------------------------------------------
int rea_epoll_create1__dup2(int __flags)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 352  00326180  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup6(string * this_ptr, char * param_1, allocator * param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 353  00326188  epoll_ctl
// ------------------------------------------------------------------
int rea_epoll_ctl__dup2(int __epfd, int __op, int __fd, epoll_event * __event)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 354  00326190  sigaction
// ------------------------------------------------------------------
int rea_sigaction__dup2(int __sig, sigaction * __act, sigaction * __oact)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 355  00326198  getifaddrs
// ------------------------------------------------------------------
void rea_getifaddrs__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 356  003261a0  std__terminate
// ------------------------------------------------------------------
void rea_std__terminate__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 357  003261a8  getsockopt
// ------------------------------------------------------------------
int rea_getsockopt__dup2(int __fd, int __level, int __optname, void * __optval, socklen_t * __optlen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 358  003261b0  connect
// ------------------------------------------------------------------
int rea_connect__dup2(int __fd, sockaddr * __addr, socklen_t __len)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 359  003261b8  std____detail___List_node_base___M_hook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_hook__dup2(_List_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 360  003261c0  __cxa_pure_virtual
// ------------------------------------------------------------------
void rea___cxa_pure_virtual(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 361  003261c8  memmove
// ------------------------------------------------------------------
void * rea_memmove__dup2(void * __dest, void * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 362  003261d0  PyFloat_AsDouble
// ------------------------------------------------------------------
void rea_PyFloat_AsDouble__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 363  003261d8  socket
// ------------------------------------------------------------------
int rea_socket__dup2(int __domain, int __type, int __protocol)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 364  003261e0  vsnprintf
// ------------------------------------------------------------------
int rea_vsnprintf__dup2(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 365  003261e8  inet_ntoa
// ------------------------------------------------------------------
char * rea_inet_ntoa__dup2(in_addr __in)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 366  003261f0  Py_BuildValue
// ------------------------------------------------------------------
void rea_Py_BuildValue__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 367  003261f8  __errno_location
// ------------------------------------------------------------------
int * rea___errno_location__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 368  00326200  std___Rb_tree_insert_and_rebalance________________
// ------------------------------------------------------------------
void rea_std___Rb_tree_insert_and_rebalance__dup2(bool param_1, _Rb_tree_node_base * param_2, _Rb_tree_node_base * param_3, _Rb_tree_node_base * param_4)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 369  00326210  std____throw_bad_function_call
// ------------------------------------------------------------------
void rea_std____throw_bad_function_call__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 370  00326218  std___Rb_tree_rebalance_for_erase
// ------------------------------------------------------------------
void rea_std___Rb_tree_rebalance_for_erase__dup2(_Rb_tree_node_base * param_1, _Rb_tree_node_base * param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 371  00326220  strcmp
// ------------------------------------------------------------------
int rea_strcmp__dup2(char * __s1, char * __s2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 372  00326228  deflateBound
// ------------------------------------------------------------------
void rea_deflateBound__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 373  00326230  PyBytes_FromStringAndSize
// ------------------------------------------------------------------
void rea_PyBytes_FromStringAndSize__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 374  00326238  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign__dup3(char * param_1, ulong param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 375  00326248  epoll_wait
// ------------------------------------------------------------------
int rea_epoll_wait__dup2(int __epfd, epoll_event * __events, int __maxevents, int __timeout)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 376  00326250  freeifaddrs
// ------------------------------------------------------------------
void rea_freeifaddrs__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 377  00326258  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign__dup4(string * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 378  00326260  deflateInit2_
// ------------------------------------------------------------------
void rea_deflateInit2__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 379  00326268  memmem
// ------------------------------------------------------------------
void * rea_memmem__dup2(void * __haystack, size_t __haystacklen, void * __needle, size_t __needlelen)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 380  00326278  remove
// ------------------------------------------------------------------
int rea_remove__dup2(char * __filename)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 381  00326280  PyModule_Create2
// ------------------------------------------------------------------
void rea_PyModule_Create2__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 382  00326288  strncpy
// ------------------------------------------------------------------
char * rea_strncpy__dup2(char * __dest, char * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 383  00326290  PyTuple_New
// ------------------------------------------------------------------
void rea_PyTuple_New__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 384  00326298  std___Rb_tree_increment
// ------------------------------------------------------------------
void rea_std___Rb_tree_increment__dup4(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 385  003262a0  __cxa_end_catch
// ------------------------------------------------------------------
void rea___cxa_end_catch__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 386  003262b8  sigemptyset
// ------------------------------------------------------------------
int rea_sigemptyset__dup2(sigset_t * __set)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 387  003262c0  __cxa_begin_catch
// ------------------------------------------------------------------
void rea___cxa_begin_catch__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 388  003262c8  bind
// ------------------------------------------------------------------
int rea_bind__dup2(int __fd, sockaddr * __addr, socklen_t __len)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 389  003262d0  fwrite
// ------------------------------------------------------------------
size_t rea_fwrite__dup2(void * __ptr, size_t __size, size_t __n, FILE * __s)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 390  003262d8  perror
// ------------------------------------------------------------------
void rea_perror__dup2(char * __s)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 391  003262e0  __gxx_personality_v0
// ------------------------------------------------------------------
void rea___gxx_personality_v0(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 392  003262e8  fprintf
// ------------------------------------------------------------------
int rea_fprintf__dup2(FILE * __stream, char * __format, undefined8 param_x2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 393  003262f0  write
// ------------------------------------------------------------------
ssize_t rea_write__dup2(int __fd, void * __buf, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 394  003262f8  operator_new
// ------------------------------------------------------------------
void * rea_operator__new__dup2(ulong param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 395  00326300  _Unwind_Resume
// ------------------------------------------------------------------
void rea__Unwind_Resume__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 396  00326308  accept
// ------------------------------------------------------------------
int rea_accept__dup2(int __fd, sockaddr * __addr, socklen_t * __addr_len)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 397  00326310  std__string___M_leak_hard
// ------------------------------------------------------------------
void rea_std__string___M_leak_hard__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 398  00326318  PyUnicode_AsUTF8
// ------------------------------------------------------------------
void rea_PyUnicode_AsUTF8__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 399  00326320  memcpy
// ------------------------------------------------------------------
void * rea_memcpy__dup2(void * __dest, void * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





