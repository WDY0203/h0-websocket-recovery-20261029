#include "../H0WS2_shim.hpp"

// ------------------------------------------------------------------
// IDX 1  00106e70  FUN_00106e70
// ------------------------------------------------------------------
void rea_FUN_00106e70(void)
{
  (*(code *)PTR_00325010)();
  return;
}





// ------------------------------------------------------------------
// IDX 3  00106e90  std__string__append
// ------------------------------------------------------------------
undefined8 rea_std__string__append(char * param_1, ulong param_2)
{
  (*(code *)PTR_append_00325020)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 4  00106ea0  std____throw_length_error
// ------------------------------------------------------------------
undefined8 rea_std____throw_length_error(char * param_1)
{
  (*(code *)PTR___throw_length_error_00325028)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 5  00106eb0  PyString_AsString
// ------------------------------------------------------------------
undefined8 rea_PyString_AsString(...)
{
  (*(code *)PTR_PyString_AsString_00325030)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 6  00106ec0  memset
// ------------------------------------------------------------------
void * rea_memset(void * __s, int __c, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00325038)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 7  00106ed0  shutdown
// ------------------------------------------------------------------
int rea_shutdown(int __fd, int __how)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_shutdown_00325040)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 8  00106ee0  backtrace
// ------------------------------------------------------------------
undefined8 rea_backtrace(...)
{
  (*(code *)PTR_backtrace_00325048)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 9  00106ef0  std____detail___List_node_base___M_unhook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_unhook(void)
{
  (*(code *)PTR__M_unhook_00325050)();
  return;
}





// ------------------------------------------------------------------
// IDX 10  00106f00  close
// ------------------------------------------------------------------
int rea_close(int __fd)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00325058)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 11  00106f10  inflateEnd
// ------------------------------------------------------------------
void rea_inflateEnd(...)
{
  (*(code *)PTR_inflateEnd_00325060)();
  return;
}





// ------------------------------------------------------------------
// IDX 12  00106f20  Py_InitModule4_64
// ------------------------------------------------------------------
void rea_Py_InitModule4_64(...)
{
  (*(code *)PTR_Py_InitModule4_64_00325068)();
  return;
}





// ------------------------------------------------------------------
// IDX 13  00106f30  abort
// ------------------------------------------------------------------
void rea_abort(void)
{
  (*(code *)PTR_abort_00325070)();
  return;
}





// ------------------------------------------------------------------
// IDX 14  00106f40  PyLong_FromVoidPtr
// ------------------------------------------------------------------
undefined8 rea_PyLong_FromVoidPtr(...)
{
  (*(code *)PTR_PyLong_FromVoidPtr_00325078)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 15  00106f50  PyLong_AsVoidPtr
// ------------------------------------------------------------------
undefined8 rea_PyLong_AsVoidPtr(...)
{
  (*(code *)PTR_PyLong_AsVoidPtr_00325080)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 16  00106f60  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string(string * this_ptr, char * param_1, ulong param_2, allocator * param_3)
{
  (*(code *)PTR_string_00325088)();
  return;
}





// ------------------------------------------------------------------
// IDX 17  00106f70  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase
// ------------------------------------------------------------------
long long rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, int * param_1)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  int iVar3;
  _Rb_tree_node *p_Var4;
  long long lVar5;
  _Rb_tree_node *p_Var6;
  long long lVar7;
  _Rb_tree_node_base *p_Var8;
  void *pvVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 8);
  p_Var4 = *(_Rb_tree_node **)(this_ptr + 0x10);
  p_Var11 = p_Var1;
  p_Var13 = p_Var1;
  if (p_Var4 != (_Rb_tree_node *)0x0) {
    iVar3 = *param_1;
    p_Var6 = p_Var4;
    do {
      while (p_Var8 = (_Rb_tree_node_base *)p_Var6, iVar3 <= *(int *)(p_Var8 + 0x20)) {
        if (*(int *)(p_Var8 + 0x20) <= iVar3) {
          p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
          p_Var12 = *(_Rb_tree_node_base **)(p_Var8 + 0x18);
          while (p_Var13 = p_Var11, p_Var12 != (_Rb_tree_node_base *)0x0) {
            while (p_Var13 = p_Var12, iVar3 < *(int *)(p_Var13 + 0x20)) {
              p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var11 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010b800;
            }
            p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
          }
LAB_0010b800:
          do {
            p_Var11 = p_Var8;
            if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
            iVar2 = *(int *)(p_Var10 + 0x20);
            while (p_Var11 = p_Var10, iVar3 <= iVar2) {
              p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
              if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
              iVar2 = *(int *)(p_Var10 + 0x20);
              p_Var8 = p_Var11;
            }
            p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
          } while( true );
        }
        p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var11 = p_Var8;
        p_Var13 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
      }
      p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x18);
      p_Var13 = p_Var11;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x18) != (_Rb_tree_node_base *)0x0);
  }
LAB_0010b763:
  lVar5 = *(long long *)(this_ptr + 0x28);
  if ((p_Var11 == *(_Rb_tree_node_base **)(this_ptr + 0x18)) && (p_Var1 == p_Var13)) {
    _M_erase(this_ptr,p_Var4);
    *(_Rb_tree_node_base **)(this_ptr + 0x18) = p_Var1;
    *(undefined8 *)(this_ptr + 0x10) = 0;
    *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
    *(undefined8 *)(this_ptr + 0x28) = 0;
    lVar7 = lVar5;
  }
  else {
    lVar7 = 0;
    if (p_Var11 != p_Var13) {
      do {
        p_Var8 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var11);
        pvVar9 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var11,p_Var1);
        rea_operator_delete(pvVar9);
        lVar7 = *(long long *)(this_ptr + 0x28);
        *(long long *)(this_ptr + 0x28) = lVar7 + -1;
        p_Var11 = p_Var8;
      } while (p_Var8 != p_Var13);
      lVar7 = lVar5 - (lVar7 + -1);
    }
  }
  return lVar7;
}





// ------------------------------------------------------------------
// IDX 18  00106f80  EventLoop2__dtor_EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__dtor_EventLoop2(EventLoop2 * this_ptr)
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
// IDX 19  00106f90  operator_delete
// ------------------------------------------------------------------
void rea_operator__delete(void * param_1)
{
  (*(code *)PTR_operator_delete_003250a0)();
  return;
}





// ------------------------------------------------------------------
// IDX 20  00106fa0  std__string__reserve
// ------------------------------------------------------------------
void rea_std__string__reserve(ulong param_1)
{
  (*(code *)PTR_reserve_003250a8)();
  return;
}





// ------------------------------------------------------------------
// IDX 21  00106fb0  std__string___Rep___M_dispose
// ------------------------------------------------------------------
void rea_std__string___Rep___M_dispose(allocator * param_1)
{
  (*(code *)PTR__M_dispose_003250b0)();
  return;
}





// ------------------------------------------------------------------
// IDX 23  00106fd0  gettimeofday
// ------------------------------------------------------------------
int rea_gettimeofday(timeval * __tv, __timezone_ptr_t __tz)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_gettimeofday_003250c0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 24  00106fe0  __cxa_rethrow
// ------------------------------------------------------------------
void rea___cxa_rethrow(void)
{
  (*(code *)PTR___cxa_rethrow_003250c8)();
  return;
}





// ------------------------------------------------------------------
// IDX 26  00107000  deflate
// ------------------------------------------------------------------
undefined8 rea_deflate(void)
{
  (*(code *)PTR_deflate_003250d8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 27  00107010  read
// ------------------------------------------------------------------
ssize_t rea_read(int __fd, void * __buf, size_t __nbytes)
{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_003250e0)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 28  00107020  TcpClient__dtor_TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__dtor_TcpClient(TcpClient * this_ptr)
{
  (*(code *)PTR__TcpClient_003250e8)();
  return;
}





// ------------------------------------------------------------------
// IDX 29  00107030  EventLoop2__exit
// ------------------------------------------------------------------
void rea_EventLoop2__exit(EventLoop2 * this_ptr, int param_1)
{
  *(int *)(this_ptr + 0x58) = param_1;
  this_ptr[0x54] = (EventLoop2)0x0;
  return;
}





// ------------------------------------------------------------------
// IDX 30  00107040  std___Rb_tree_decrement
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_decrement(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_decrement_003250f8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 31  00107050  std__string___Rep___S_create
// ------------------------------------------------------------------
undefined8 rea_std__string___Rep___S_create(ulong param_1, ulong param_2, allocator * param_3)
{
  (*(code *)PTR__S_create_00325100)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 32  00107060  UnixClient__dtor_UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__dtor_UnixClient(UnixClient * this_ptr)
{
  (*(code *)PTR__UnixClient_00325108)();
  return;
}





// ------------------------------------------------------------------
// IDX 33  00107070  std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char________________
// ------------------------------------------------------------------
void rea_std__vector_unsigned_char_std__allocator_unsigned_char_________M_range_insert___gnu_cxx____normal_iterator_unsigned_char__std__vector_unsigned_char_std__allocator_unsigned_char(long long * param_1, void * param_2, void * param_3, void * param_4)
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
        goto LAB_00116338;
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
LAB_00116338:
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
      goto LAB_00116398;
    }
  }
  pvVar3 = rea_operator_new(uVar6);
  pvVar1 = (void *)*param_1;
LAB_00116398:
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
// IDX 34  00107080  print_stack
// ------------------------------------------------------------------
void rea_print_stack(void)
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
// IDX 35  00107090  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup2(string * this_ptr, string * param_1)
{
  (*(code *)PTR_string_00325120)();
  return;
}





// ------------------------------------------------------------------
// IDX 36  001070a0  setsockopt
// ------------------------------------------------------------------
int rea_setsockopt(int __fd, int __level, int __optname, void * __optval, socklen_t __optlen)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setsockopt_00325128)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 37  001070b0  PyString_FromStringAndSize
// ------------------------------------------------------------------
undefined8 rea_PyString_FromStringAndSize(...)
{
  (*(code *)PTR_PyString_FromStringAndSize_00325130)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 39  001070d0  TcpConn__idle_proc
// ------------------------------------------------------------------
void rea_TcpConn__idle_proc(TcpConn * this_ptr)
{
  (*(code *)PTR_idle_proc_00325140)();
  return;
}





// ------------------------------------------------------------------
// IDX 40  001070e0  PyLong_AsLong
// ------------------------------------------------------------------
undefined8 rea_PyLong_AsLong(...)
{
  (*(code *)PTR_PyLong_AsLong_00325148)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 41  001070f0  TcpConn__send_proc
// ------------------------------------------------------------------
void rea_TcpConn__send_proc(TcpConn * this_ptr)
{
  (*(code *)PTR_send_proc_00325150)();
  return;
}





// ------------------------------------------------------------------
// IDX 42  00107100  PyString_Size
// ------------------------------------------------------------------
undefined8 rea_PyString_Size(...)
{
  (*(code *)PTR_PyString_Size_00325158)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 43  00107110  inflateInit2_
// ------------------------------------------------------------------
void rea_inflateInit2(void)
{
  (*(code *)PTR_inflateInit2__00325160)();
  return;
}





// ------------------------------------------------------------------
// IDX 44  00107120  bzero
// ------------------------------------------------------------------
void rea_bzero(void * __s, size_t __n)
{
  (*(code *)PTR_bzero_00325168)();
  return;
}





// ------------------------------------------------------------------
// IDX 45  00107130  strnlen
// ------------------------------------------------------------------
size_t rea_strnlen(char * __string, size_t __maxlen)
{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strnlen_00325170)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 46  00107140  PyArg_ParseTuple
// ------------------------------------------------------------------
undefined8 rea_PyArg_ParseTuple(...)
{
  (*(code *)PTR_PyArg_ParseTuple_00325178)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 47  00107150  inflate
// ------------------------------------------------------------------
undefined8 rea_inflate(...)
{
  (*(code *)PTR_inflate_00325180)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 48  00107160  backtrace_symbols
// ------------------------------------------------------------------
undefined8 rea_backtrace_symbols(...)
{
  (*(code *)PTR_backtrace_symbols_00325188)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 49  00107170  free
// ------------------------------------------------------------------
void rea_free(void * __ptr)
{
  (*(code *)PTR_free_00325190)();
  return;
}





// ------------------------------------------------------------------
// IDX 50  00107180  strlen
// ------------------------------------------------------------------
size_t rea_strlen(char * __s)
{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00325198)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 51  00107190  std__string___Rep___M_destroy
// ------------------------------------------------------------------
void rea_std__string___Rep___M_destroy(allocator * param_1)
{
  (*(code *)PTR__M_destroy_003251a0)();
  return;
}





// ------------------------------------------------------------------
// IDX 52  001071a0  __xstat
// ------------------------------------------------------------------
int rea___xstat(int __ver, char * __filename, stat * __stat_buf)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR___xstat_003251a8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 53  001071b0  deflateEnd
// ------------------------------------------------------------------
void rea_deflateEnd(...)
{
  (*(code *)PTR_deflateEnd_003251b0)();
  return;
}





// ------------------------------------------------------------------
// IDX 54  001071c0  std_________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple_________________
// ------------------------------------------------------------------
void rea_std_________Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_________M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple(void)
{
  (*(code *)
    PTR__M_emplace_hint_unique_std__piecewise_construct_t_const__std__tuple_int_const__std__tuple__003251b8
  )();
  return;
}





// ------------------------------------------------------------------
// IDX 55  001071d0  listen
// ------------------------------------------------------------------
int rea_listen(int __fd, int __n)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_listen_003251c0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 56  001071e0  TcpConn__TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__TcpConn(TcpConn * this_ptr, int param_1, string * param_2, string * param_3, EventHandler * param_4)
{
  (*(code *)PTR_TcpConn_003251c8)();
  return;
}





// ------------------------------------------------------------------
// IDX 58  00107200  strrchr
// ------------------------------------------------------------------
char * rea_strrchr(char * __s, int __c)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strrchr_003251d8)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 59  00107210  std__string__insert
// ------------------------------------------------------------------
undefined8 rea_std__string__insert(ulong param_1, char * param_2, ulong param_3)
{
  (*(code *)PTR_insert_003251e0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 60  00107220  std___Rb_tree_increment
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_increment(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_increment_003251e8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 61  00107230  epoll_create1
// ------------------------------------------------------------------
int rea_epoll_create1(int __flags)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_epoll_create1_003251f0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 64  00107260  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup3(string * this_ptr, char * param_1, allocator * param_2)
{
  (*(code *)PTR_string_00325208)();
  return;
}





// ------------------------------------------------------------------
// IDX 65  00107270  epoll_ctl
// ------------------------------------------------------------------
int rea_epoll_ctl(int __epfd, int __op, int __fd, epoll_event * __event)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_epoll_ctl_00325210)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 66  00107280  sigaction
// ------------------------------------------------------------------
int rea_sigaction(int __sig, sigaction * __act, sigaction * __oact)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sigaction_00325218)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 67  00107290  getifaddrs
// ------------------------------------------------------------------
void rea_getifaddrs(...)
{
  (*(code *)PTR_getifaddrs_00325220)();
  return;
}





// ------------------------------------------------------------------
// IDX 68  001072a0  std__terminate
// ------------------------------------------------------------------
void rea_std__terminate(void)
{
  (*(code *)PTR_terminate_00325228)();
  return;
}





// ------------------------------------------------------------------
// IDX 70  001072c0  getsockopt
// ------------------------------------------------------------------
int rea_getsockopt(int __fd, int __level, int __optname, void * __optval, socklen_t * __optlen)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getsockopt_00325238)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 71  001072d0  UnixServer__dtor_UnixServer
// ------------------------------------------------------------------
void rea_UnixServer__dtor_UnixServer(UnixServer * this_ptr)
{
  (*(code *)PTR__UnixServer_00325240)();
  return;
}





// ------------------------------------------------------------------
// IDX 72  001072e0  connect
// ------------------------------------------------------------------
int rea_connect(int __fd, sockaddr * __addr, socklen_t __len)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_connect_00325248)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 74  00107300  TcpConn__dtor_TcpConn
// ------------------------------------------------------------------
void rea_TcpConn__dtor_TcpConn(TcpConn * this_ptr)
{
  (*(code *)PTR__TcpConn_00325258)();
  return;
}





// ------------------------------------------------------------------
// IDX 75  00107310  std____detail___List_node_base___M_hook
// ------------------------------------------------------------------
void rea_std____detail___List_node_base___M_hook(_List_node_base * param_1)
{
  (*(code *)PTR__M_hook_00325260)();
  return;
}





// ------------------------------------------------------------------
// IDX 77  00107330  setcloexec
// ------------------------------------------------------------------
void rea_setcloexec(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,1);
  if ((int)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_fcntl(param_1,2,(ulong)(uVar1 | 1));
  return;
}





// ------------------------------------------------------------------
// IDX 79  00107350  memmove
// ------------------------------------------------------------------
void * rea_memmove(void * __dest, void * __src, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmove_00325280)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 80  00107360  setnonblock
// ------------------------------------------------------------------
void rea_setnonblock(int param_1)
{
  uint uVar1;
  
  uVar1 = rea_fcntl(param_1,3);
  if ((int)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_fcntl(param_1,4,(ulong)(uVar1 | 0x800));
  return;
}





// ------------------------------------------------------------------
// IDX 81  00107370  TcpConn__recv_proc
// ------------------------------------------------------------------
void rea_TcpConn__recv_proc(TcpConn * this_ptr)
{
  (*(code *)PTR_recv_proc_00325290)();
  return;
}





// ------------------------------------------------------------------
// IDX 82  00107380  WSConn__dtor_WSConn
// ------------------------------------------------------------------
void rea_WSConn__dtor_WSConn(WSConn * this_ptr)
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
// IDX 83  00107390  PyFloat_AsDouble
// ------------------------------------------------------------------
undefined8 rea_PyFloat_AsDouble(...)
{
  (*(code *)PTR_PyFloat_AsDouble_003252a0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 84  001073a0  socket
// ------------------------------------------------------------------
int rea_socket(int __domain, int __type, int __protocol)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_003252a8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 85  001073b0  inet_ntoa
// ------------------------------------------------------------------
char * rea_inet_ntoa(in_addr __in)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_inet_ntoa_003252b0)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 86  001073c0  print_stack_abort
// ------------------------------------------------------------------
void rea_print_stack_abort(void)
{
  rea_print_stack();
                    /* WARNING: Subroutine does not return */
  rea_abort();
}





// ------------------------------------------------------------------
// IDX 87  001073d0  Py_BuildValue
// ------------------------------------------------------------------
undefined8 rea_Py_BuildValue(...)
{
  (*(code *)PTR_Py_BuildValue_003252c0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 88  001073e0  __errno_location
// ------------------------------------------------------------------
int * rea___errno_location(void)
{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR___errno_location_003252c8)();
  return piVar1;
}





// ------------------------------------------------------------------
// IDX 90  00107400  std___Rb_tree_insert_and_rebalance________________
// ------------------------------------------------------------------
void rea_std___Rb_tree_insert_and_rebalance(bool param_1, _Rb_tree_node_base * param_2, _Rb_tree_node_base * param_3, _Rb_tree_node_base * param_4)
{
  (*(code *)PTR__Rb_tree_insert_and_rebalance_003252d8)();
  return;
}





// ------------------------------------------------------------------
// IDX 92  00107420  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____vector(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr)
{
  (*(code *)PTR__vector_003252e8)();
  return;
}





// ------------------------------------------------------------------
// IDX 94  00107440  std____throw_bad_function_call
// ------------------------------------------------------------------
void rea_std____throw_bad_function_call(void)
{
  (*(code *)PTR___throw_bad_function_call_003252f8)();
  return;
}





// ------------------------------------------------------------------
// IDX 96  00107460  UnixClient__UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__UnixClient(...)
{
  (*(code *)PTR_UnixClient_00325308)();
  return;
}





// ------------------------------------------------------------------
// IDX 97  00107470  std___Rb_tree_rebalance_for_erase
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_rebalance_for_erase(_Rb_tree_node_base * param_1, _Rb_tree_node_base * param_2)
{
  (*(code *)PTR__Rb_tree_rebalance_for_erase_00325310)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 98  00107480  strcmp
// ------------------------------------------------------------------
int rea_strcmp(char * __s1, char * __s2)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00325318)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 99  00107490  TcpClient__TcpClient
// ------------------------------------------------------------------
void rea_TcpClient__TcpClient(...)
{
  (*(code *)PTR_TcpClient_00325320)();
  return;
}





// ------------------------------------------------------------------
// IDX 100  001074a0  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, _Rb_tree_node * param_1)
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
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long long)pvVar3 + 0x10);
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long long)pvVar4 + 0x10);
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long long)pvVar5 + 0x10);
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long long)pvVar6 + 0x10);
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long long)pvVar7 + 0x10);
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long long)pvVar8 + 0x10);
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long long)pvVar10 + 0x10);
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 101  001074b0  deflateBound
// ------------------------------------------------------------------
undefined8 rea_deflateBound(...)
{
  (*(code *)PTR_deflateBound_00325330)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 102  001074c0  std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase(_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root * this_ptr, _Rb_tree_node * param_1)
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
// IDX 103  001074d0  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign(char * param_1, ulong param_2)
{
  (*(code *)PTR_assign_00325340)();
  return;
}





// ------------------------------------------------------------------
// IDX 104  001074e0  TcpServer__dtor_TcpServer
// ------------------------------------------------------------------
void rea_TcpServer__dtor_TcpServer(TcpServer * this_ptr)
{
  (*(code *)PTR__TcpServer_00325348)();
  return;
}





// ------------------------------------------------------------------
// IDX 105  001074f0  epoll_wait
// ------------------------------------------------------------------
int rea_epoll_wait(int __epfd, epoll_event * __events, int __maxevents, int __timeout)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_epoll_wait_00325350)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 106  00107500  freeifaddrs
// ------------------------------------------------------------------
void rea_freeifaddrs(...)
{
  (*(code *)PTR_freeifaddrs_00325358)();
  return;
}





// ------------------------------------------------------------------
// IDX 107  00107510  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign__dup2(string * param_1)
{
  (*(code *)PTR_assign_00325360)();
  return;
}





// ------------------------------------------------------------------
// IDX 109  00107530  std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler___________
// ------------------------------------------------------------------
void rea_std___vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler____M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler(vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler * this_ptr, unique_ptr * param_1)
{
  (*(code *)
    PTR__M_emplace_back_aux_std__unique_ptr_EventHandler_std__default_delete_EventHandler_00325370
  )();
  return;
}





// ------------------------------------------------------------------
// IDX 110  00107540  deflateInit2_
// ------------------------------------------------------------------
void rea_deflateInit2(void)
{
  (*(code *)PTR_deflateInit2__00325378)();
  return;
}





// ------------------------------------------------------------------
// IDX 111  00107550  memmem
// ------------------------------------------------------------------
void * rea_memmem(void * __haystack, size_t __haystacklen, void * __needle, size_t __needlelen)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmem_00325380)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 112  00107560  EventLoop2__EventLoop2
// ------------------------------------------------------------------
void rea_EventLoop2__EventLoop2(EventLoop2 * this_ptr)
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
  if (iVar2 < 0) {
    rea_perror("epoll_create1");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  return;
}





// ------------------------------------------------------------------
// IDX 113  00107570  remove
// ------------------------------------------------------------------
int rea_remove(char * __filename)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_remove_00325390)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 114  00107580  strncpy
// ------------------------------------------------------------------
char * rea_strncpy(char * __dest, char * __src, size_t __n)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strncpy_00325398)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 115  00107590  PyTuple_New
// ------------------------------------------------------------------
undefined8 rea_PyTuple_New(...)
{
  (*(code *)PTR_PyTuple_New_003253a0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 116  001075a0  std___Rb_tree_increment
// ------------------------------------------------------------------
void rea_std___Rb_tree_increment__dup2(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_increment_003253a8)();
  return;
}





// ------------------------------------------------------------------
// IDX 117  001075b0  __cxa_end_catch
// ------------------------------------------------------------------
void rea___cxa_end_catch(void)
{
  (*(code *)PTR___cxa_end_catch_003253b0)();
  return;
}





// ------------------------------------------------------------------
// IDX 118  001075c0  sigemptyset
// ------------------------------------------------------------------
int rea_sigemptyset(sigset_t * __set)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sigemptyset_003253b8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 119  001075d0  EventHandler__dtor_EventHandler
// ------------------------------------------------------------------
void rea_EventHandler__dtor_EventHandler(EventHandler * this_ptr)
{
  (*(code *)PTR__EventHandler_003253c0)();
  return;
}





// ------------------------------------------------------------------
// IDX 120  001075e0  __cxa_begin_catch
// ------------------------------------------------------------------
void rea___cxa_begin_catch(void)
{
  (*(code *)PTR___cxa_begin_catch_003253c8)();
  return;
}





// ------------------------------------------------------------------
// IDX 122  00107600  bind
// ------------------------------------------------------------------
int rea_bind(int __fd, sockaddr * __addr, socklen_t __len)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_bind_003253d8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 123  00107610  fwrite
// ------------------------------------------------------------------
size_t rea_fwrite(void * __ptr, size_t __size, size_t __n, FILE * __s)
{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_003253e0)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 124  00107620  std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler________________
// ------------------------------------------------------------------
void rea_std________vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_______________M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler(void)
{
  (*(code *)
    PTR__M_range_insert_std__move_iterator___gnu_cxx____normal_iterator_std__unique_ptr_EventHandler_std__default_delete_EventHandler__std__vector_std__unique_ptr_EventHandler_std__default_delete_EventHandler_std__allocator_std__unique_ptr_EventHandler_std__default_delete_EventHandler_003253e8
  )();
  return;
}





// ------------------------------------------------------------------
// IDX 125  00107630  perror
// ------------------------------------------------------------------
void rea_perror(char * __s)
{
  (*(code *)PTR_perror_003253f0)();
  return;
}





// ------------------------------------------------------------------
// IDX 126  00107640  fprintf
// ------------------------------------------------------------------
int rea_fprintf(FILE * __stream, char * __format, undefined8 param_x2)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fprintf_003253f8)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 127  00107650  write
// ------------------------------------------------------------------
ssize_t rea_write(int __fd, void * __buf, size_t __n)
{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_00325400)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 128  00107660  operator_new
// ------------------------------------------------------------------
void * rea_operator__new(ulong param_1)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new_00325408)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 129  00107670  _Unwind_Resume
// ------------------------------------------------------------------
void rea__Unwind_Resume(...)
{
  (*(code *)PTR__Unwind_Resume_00325410)();
  return;
}





// ------------------------------------------------------------------
// IDX 130  00107680  accept
// ------------------------------------------------------------------
int rea_accept(int __fd, sockaddr * __addr, socklen_t * __addr_len)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_accept_00325418)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 132  001076a0  std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn____M_erase(_Rb_tree_int_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std___Select1st_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn_std__less_int_std__allocator_std__pair_int_const_std__unique_ptr_TcpConn_std__default_delete_TcpConn * this_ptr, _Rb_tree_node * param_1)
{
  (*(code *)PTR__M_erase_00325428)();
  return;
}





// ------------------------------------------------------------------
// IDX 133  001076b0  std__string___M_leak_hard
// ------------------------------------------------------------------
void rea_std__string___M_leak_hard(void)
{
  (*(code *)PTR__M_leak_hard_00325430)();
  return;
}





// ------------------------------------------------------------------
// IDX 134  001076c0  memcpy
// ------------------------------------------------------------------
void * rea_memcpy(void * __dest, void * __src, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00325438)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 135  001076d0  fcntl
// ------------------------------------------------------------------
int rea_fcntl(int __fd, int __cmd, undefined8 param_x2)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fcntl_00325440)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 136  001076e0  std__string__append
// ------------------------------------------------------------------
void rea_std__string__append__dup2(string * param_1)
{
  (*(code *)PTR_append_00325448)();
  return;
}





// ------------------------------------------------------------------
// IDX 137  001076f0  mkdir
// ------------------------------------------------------------------
int rea_mkdir(char * __path, __mode_t __mode)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mkdir_00325450)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 138  00107700  inet_addr
// ------------------------------------------------------------------
in_addr_t rea_inet_addr(char * __cp)
{
  in_addr_t iVar1;
  
  iVar1 = (*(code *)PTR_inet_addr_00325458)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 139  00107710  __gnu_cxx____to_xstring_std__string_char
// ------------------------------------------------------------------
void rea___gnu_cxx____to_xstring_std__string_char(code * param_1, ulong param_2, char * param_3, undefined8 param_x3)
{
  (*(code *)PTR___to_xstring_std__string_char_00325460)();
  return;
}





// ------------------------------------------------------------------
// IDX 140  00107720  current_time
// ------------------------------------------------------------------
long long rea_current_time(void)
{
  timeval tStack_18;
  
  rea_gettimeofday(&tStack_18,(__timezone_ptr_t)0x0);
  return tStack_18.tv_sec * 1000000 + tStack_18.tv_usec;
}





// ------------------------------------------------------------------
// IDX 141  00107730  __gmon_start__
// ------------------------------------------------------------------
void rea___gmon_start(void)
{
  (*(code *)PTR___gmon_start___00324ed0)();
  return;
}





// ------------------------------------------------------------------
// IDX 142  00107738  __cxa_finalize
// ------------------------------------------------------------------
void rea___cxa_finalize(...)
{
  (*(code *)PTR___cxa_finalize_00324f28)();
  return;
}





// ------------------------------------------------------------------
// IDX 143  00107740  vsnprintf
// ------------------------------------------------------------------
int rea_vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_vsnprintf_00324f60)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 146  00107772  FUN_00107772
// ------------------------------------------------------------------
void rea_FUN_00107772(undefined8 * param_1)
{
  if (param_1 != (undefined8 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      rea_operator_delete((void *)*param_1);
    }
    rea_operator_delete(param_1);
    return;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 147  00107794  FUN_00107794
// ------------------------------------------------------------------
void rea_FUN_00107794(undefined8 * param_1)
{
  if (param_1 != (undefined8 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      rea_operator_delete((void *)*param_1);
    }
    rea_operator_delete(param_1);
    return;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 148  001077c0  FUN_001077c0
// ------------------------------------------------------------------
void rea_FUN_001077c0(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 149  001077f0  FUN_001077f0
// ------------------------------------------------------------------
void rea_FUN_001077f0(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 152  001078b0  FUN_001078b0
// ------------------------------------------------------------------
void rea_FUN_001078b0(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 153  001078c0  FUN_001078c0
// ------------------------------------------------------------------
void rea_FUN_001078c0(long long * param_1)
{
  EventLoop2 *this_ptr;
  
  this_ptr = *(EventLoop2 **)*param_1;
  *(undefined1 *)((undefined8 *)*param_1)[1] = 1;
  rea_EventLoop2__exit(this_ptr,0);
  return;
}





// ------------------------------------------------------------------
// IDX 154  001078e0  FUN_001078e0
// ------------------------------------------------------------------
void rea_FUN_001078e0(undefined8 * param_1)
{
  EventLoop2 *this_ptr;
  
  this_ptr = *(EventLoop2 **)*param_1;
  *(undefined8 *)(this_ptr + 0x68) = 0;
  rea_EventLoop2__exit(this_ptr,0);
  return;
}





// ------------------------------------------------------------------
// IDX 163  00107d20  FUN_00107d20
// ------------------------------------------------------------------
void rea_FUN_00107d20(long long * param_1, undefined4 * param_2)
{
  int *piVar1;
  long long lVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = PTR__S_empty_rep_storage_00324fa0;
  lVar2 = *(long long *)(param_2 + 2);
  *(undefined **)(param_2 + 2) = PTR__S_empty_rep_storage_00324fa0 + 0x18;
  puVar3 = (undefined8 *)*param_1;
  puVar4 = (undefined4 *)puVar3[1];
  *puVar4 = *param_2;
  rea_std__string__assign((string *)(puVar4 + 2));
  rea_EventLoop2__exit((EventLoop2 *)*puVar3,0);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)puVar5) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar6 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 166  00108300  FUN_00108300
// ------------------------------------------------------------------
void rea_FUN_00108300(undefined8 * param_1)
{
  int *piVar1;
  undefined4 uVar2;
  long long *plVar3;
  long long lVar4;
  void *pvVar5;
  long long lVar6;
  long long lVar7;
  undefined *puVar8;
  int iVar9;
  long long lVar10;
  _List_node_base *p_Var11;
  undefined *local_50;
  undefined4 local_48 [2];
  long long local_40;
  
  plVar3 = (long long *)*param_1;
  if ((*(long long *)(*plVar3 + 0xe8) == 0) ||
     (lVar10 = rea_current_time(), lVar10 - *(long long *)(*plVar3 + 0xe0) <= *(long long *)(*plVar3 + 0xe8))) {
    return;
  }
  rea_std__string__string((string *)&local_50,"",(allocator *)local_48);
  lVar4 = *plVar3;
  p_Var11 = rea_operator_new(0x20);
  puVar8 = PTR__S_empty_rep_storage_00324fa0;
  if (p_Var11 != (_List_node_base *)0x0) {
    *(undefined8 *)p_Var11 = 0;
    *(undefined8 *)(p_Var11 + 8) = 0;
    *(undefined4 *)(p_Var11 + 0x10) = 1;
    *(undefined **)(p_Var11 + 0x18) = local_50;
    local_50 = puVar8 + 0x18;
  }
  rea_std____detail___List_node_base___M_hook(p_Var11);
  if ((*(char *)(lVar4 + 0xb8) != '\0') &&
     (pvVar5 = *(void **)(lVar4 + 0xa8), (void *)(lVar4 + 0xa8) != pvVar5)) {
    uVar2 = *(undefined4 *)((long long)pvVar5 + 0x10);
    lVar6 = *(long long *)((long long)pvVar5 + 0x18);
    *(undefined **)((long long)pvVar5 + 0x18) = puVar8 + 0x18;
    rea_std____detail___List_node_base___M_unhook();
    lVar7 = *(long long *)((long long)pvVar5 + 0x18);
    if ((allocator *)(lVar7 + -0x18) != (allocator *)puVar8) {
      piVar1 = (int *)(lVar7 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar9 = *(int *)(lVar7 + -8);
        *(int *)(lVar7 + -8) = iVar9 + -1;
      }
      else {
        LOCK();
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar9 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar7 + -0x18));
      }
    }
    rea_operator_delete(pvVar5);
    *(undefined1 *)(lVar4 + 0xb8) = 0;
    if (*(long long *)(lVar4 + 0xd0) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    local_48[0] = uVar2;
    local_40 = lVar6;
    (**(code **)(lVar4 + 0xd8))(lVar4 + 0xc0,(allocator *)local_48);
    if ((allocator *)(local_40 + -0x18) != (allocator *)puVar8) {
      piVar1 = (int *)(local_40 + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar9 = *(int *)(local_40 + -8);
        *(int *)(local_40 + -8) = iVar9 + -1;
      }
      else {
        LOCK();
        iVar9 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar9 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_40 + -0x18));
      }
    }
  }
  if ((allocator *)(local_50 + -0x18) != (allocator *)puVar8) {
    piVar1 = (int *)(local_50 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar9 = *(int *)(local_50 + -8);
      *(int *)(local_50 + -8) = iVar9 + -1;
    }
    else {
      LOCK();
      iVar9 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar9 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_50 + -0x18));
    }
  }
  *(long long *)(*plVar3 + 0xe0) = lVar10;
  return;
}





// ------------------------------------------------------------------
// IDX 171  00109120  initbbwebsocket
// ------------------------------------------------------------------
void rea_initbbwebsocket(void)
{
  rea_Py_InitModule4_64("bbwebsocket",(void *)&PTR_s_connect_0011f2df_3_00325480,0,0,0x3f5);
  return;
}





// ------------------------------------------------------------------
// IDX 177  0010aef0  Root__dtor_Root
// ------------------------------------------------------------------
void rea_Root__dtor_Root(Root * this_ptr)
{
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 178  0010af00  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 179  0010af10  std___Function_handler<void
// ------------------------------------------------------------------
void rea_std___Function_handler_void__dup2(undefined8 * param_1)
{
  return;
}





// ------------------------------------------------------------------
// IDX 180  0010af20  Root__dtor_Root
// ------------------------------------------------------------------
void rea_Root__dtor_Root__dup2(Root * this_ptr)
{
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 184  0010b0a0  std___Function_base___Base_manager___void_std__unique_ptr_Buffer_std__default_delete_Buffer____M_manager
// ------------------------------------------------------------------
undefined8 rea_std___Function_base___Base_manager___void_std__unique_ptr_Buffer_std__default_delete_Buffer____M_manager(long long * param_1, long long * param_2, int param_3)
{
  long long lVar1;
  void *pvVar2;
  
  if (param_3 == 1) {
    *param_1 = *param_2;
    return 0;
  }
  if (param_3 < 2) {
    if (param_3 == 0) {
      *param_1 = (long long)PTR_typeinfo_00324ee0;
      return 0;
    }
  }
  else if (param_3 == 2) {
    lVar1 = *param_2;
    pvVar2 = rea_operator_new(0x20);
    *(undefined8 *)((long long)pvVar2 + 0x10) = 0;
    if (*(code **)(lVar1 + 0x10) != (code *)0x0) {
      (**(code **)(lVar1 + 0x10))(pvVar2,lVar1,2);
      *(undefined8 *)((long long)pvVar2 + 0x18) = *(undefined8 *)(lVar1 + 0x18);
      *(undefined8 *)((long long)pvVar2 + 0x10) = *(undefined8 *)(lVar1 + 0x10);
    }
    *param_1 = (long long)pvVar2;
  }
  else if ((param_3 == 3) && (pvVar2 = (void *)*param_1, pvVar2 != (void *)0x0)) {
    if (*(code **)((long long)pvVar2 + 0x10) != (code *)0x0) {
      (**(code **)((long long)pvVar2 + 0x10))(pvVar2,pvVar2,3);
    }
    rea_operator_delete(pvVar2);
    return 0;
  }
  return 0;
}





// ------------------------------------------------------------------
// IDX 187  0010b540  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int____M_erase__dup2(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, _Rb_tree_node * param_1)
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
                    rea_operator_delete(pvVar2);
                    pvVar2 = pvVar1;
                  }
                  pvVar2 = *(void **)((long long)pvVar3 + 0x10);
                  rea_operator_delete(pvVar3);
                  pvVar3 = pvVar2;
                }
                pvVar3 = *(void **)((long long)pvVar4 + 0x10);
                rea_operator_delete(pvVar4);
                pvVar4 = pvVar3;
              }
              pvVar4 = *(void **)((long long)pvVar5 + 0x10);
              rea_operator_delete(pvVar5);
              pvVar5 = pvVar4;
            }
            pvVar5 = *(void **)((long long)pvVar6 + 0x10);
            rea_operator_delete(pvVar6);
            pvVar6 = pvVar5;
          }
          pvVar6 = *(void **)((long long)pvVar7 + 0x10);
          rea_operator_delete(pvVar7);
          pvVar7 = pvVar6;
        }
        pvVar7 = *(void **)((long long)pvVar8 + 0x10);
        rea_operator_delete(pvVar8);
        pvVar8 = pvVar7;
      }
      pvVar8 = *(void **)((long long)pvVar10 + 0x10);
      rea_operator_delete(pvVar10);
      pvVar10 = pvVar8;
    }
    p_Var9 = *(_Rb_tree_node **)(param_1 + 0x10);
    rea_operator_delete(param_1);
    param_1 = p_Var9;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 188  0010b710  std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase
// ------------------------------------------------------------------
long long rea_std____Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int___erase__dup2(_Rb_tree_int_std__pair_int_const_int_std___Select1st_std__pair_int_const_int_std__less_int_std__allocator_std__pair_int_const_int * this_ptr, int * param_1)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  int iVar3;
  _Rb_tree_node *p_Var4;
  long long lVar5;
  _Rb_tree_node *p_Var6;
  long long lVar7;
  _Rb_tree_node_base *p_Var8;
  void *pvVar9;
  _Rb_tree_node_base *p_Var10;
  _Rb_tree_node_base *p_Var11;
  _Rb_tree_node_base *p_Var12;
  _Rb_tree_node_base *p_Var13;
  
  p_Var1 = (_Rb_tree_node_base *)(this_ptr + 8);
  p_Var4 = *(_Rb_tree_node **)(this_ptr + 0x10);
  p_Var11 = p_Var1;
  p_Var13 = p_Var1;
  if (p_Var4 != (_Rb_tree_node *)0x0) {
    iVar3 = *param_1;
    p_Var6 = p_Var4;
    do {
      while (p_Var8 = (_Rb_tree_node_base *)p_Var6, iVar3 <= *(int *)(p_Var8 + 0x20)) {
        if (*(int *)(p_Var8 + 0x20) <= iVar3) {
          p_Var10 = *(_Rb_tree_node_base **)(p_Var8 + 0x10);
          p_Var12 = *(_Rb_tree_node_base **)(p_Var8 + 0x18);
          while (p_Var13 = p_Var11, p_Var12 != (_Rb_tree_node_base *)0x0) {
            while (p_Var13 = p_Var12, iVar3 < *(int *)(p_Var13 + 0x20)) {
              p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x10);
              p_Var11 = p_Var13;
              if (*(_Rb_tree_node_base **)(p_Var13 + 0x10) == (_Rb_tree_node_base *)0x0)
              goto LAB_0010b800;
            }
            p_Var12 = *(_Rb_tree_node_base **)(p_Var13 + 0x18);
          }
LAB_0010b800:
          do {
            p_Var11 = p_Var8;
            if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
            iVar2 = *(int *)(p_Var10 + 0x20);
            while (p_Var11 = p_Var10, iVar3 <= iVar2) {
              p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x10);
              if (p_Var10 == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
              iVar2 = *(int *)(p_Var10 + 0x20);
              p_Var8 = p_Var11;
            }
            p_Var10 = *(_Rb_tree_node_base **)(p_Var11 + 0x18);
          } while( true );
        }
        p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x10);
        p_Var11 = p_Var8;
        p_Var13 = p_Var8;
        if (*(_Rb_tree_node_base **)(p_Var8 + 0x10) == (_Rb_tree_node_base *)0x0) goto LAB_0010b763;
      }
      p_Var6 = (_Rb_tree_node *)*(_Rb_tree_node_base **)(p_Var8 + 0x18);
      p_Var13 = p_Var11;
    } while (*(_Rb_tree_node_base **)(p_Var8 + 0x18) != (_Rb_tree_node_base *)0x0);
  }
LAB_0010b763:
  lVar5 = *(long long *)(this_ptr + 0x28);
  if ((p_Var11 == *(_Rb_tree_node_base **)(this_ptr + 0x18)) && (p_Var1 == p_Var13)) {
    _M_erase(this_ptr,p_Var4);
    *(_Rb_tree_node_base **)(this_ptr + 0x18) = p_Var1;
    *(undefined8 *)(this_ptr + 0x10) = 0;
    *(_Rb_tree_node_base **)(this_ptr + 0x20) = p_Var1;
    *(undefined8 *)(this_ptr + 0x28) = 0;
    lVar7 = lVar5;
  }
  else {
    lVar7 = 0;
    if (p_Var11 != p_Var13) {
      do {
        p_Var8 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var11);
        pvVar9 = (void *)rea_std___Rb_tree_rebalance_for_erase(p_Var11,p_Var1);
        rea_operator_delete(pvVar9);
        lVar7 = *(long long *)(this_ptr + 0x28);
        *(long long *)(this_ptr + 0x28) = lVar7 + -1;
        p_Var11 = p_Var8;
      } while (p_Var8 != p_Var13);
      lVar7 = lVar5 - (lVar7 + -1);
    }
  }
  return lVar7;
}





// ------------------------------------------------------------------
// IDX 189  0010b880  std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root____M_erase__dup2(_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root * this_ptr, _Rb_tree_node * param_1)
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
// IDX 190  0010bb30  Channel_std__pair_int_std__string___Channel
// ------------------------------------------------------------------
void rea_Channel_std__pair_int_std__string___Channel(Channel_std__pair_int_std__string * this_ptr)
{
  Channel_std__pair_int_std__string *pCVar1;
  allocator *paVar2;
  int *piVar3;
  int iVar4;
  long long lVar5;
  Channel_std__pair_int_std__string *pCVar6;
  undefined *puVar7;
  Channel_std__pair_int_std__string *pCVar8;
  
  *(undefined **)this_ptr = PTR_vtable_00324f90 + 0x10;
  if (*(code **)(this_ptr + 0x60) != (code *)0x0) {
    (**(code **)(this_ptr + 0x60))(this_ptr + 0x50,this_ptr + 0x50,3);
  }
  puVar7 = PTR__S_empty_rep_storage_00324fa0;
  pCVar8 = *(Channel_std__pair_int_std__string **)(this_ptr + 0x38);
  pCVar1 = this_ptr + 0x38;
  if (pCVar8 != pCVar1) {
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      do {
        lVar5 = *(long long *)(pCVar8 + 0x18);
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        if (((allocator *)(lVar5 + -0x18) != (allocator *)puVar7) &&
           (iVar4 = *(int *)(lVar5 + -8), *(int *)(lVar5 + -8) = iVar4 + -1, iVar4 < 1)) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar5 + -0x18));
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
    else {
      do {
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        paVar2 = (allocator *)(*(long long *)(pCVar8 + 0x18) + -0x18);
        if (paVar2 != (allocator *)puVar7) {
          LOCK();
          piVar3 = (int *)(*(long long *)(pCVar8 + 0x18) + -8);
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 < 1) {
            rea_std__string___Rep___M_destroy(paVar2);
          }
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
  }
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  return;
}





// ------------------------------------------------------------------
// IDX 191  0010bc30  Channel_std__pair_int_std__string___Channel
// ------------------------------------------------------------------
void rea_Channel_std__pair_int_std__string___Channel__dup2(Channel_std__pair_int_std__string * this_ptr)
{
  Channel_std__pair_int_std__string *pCVar1;
  allocator *paVar2;
  int *piVar3;
  int iVar4;
  long long lVar5;
  Channel_std__pair_int_std__string *pCVar6;
  undefined *puVar7;
  Channel_std__pair_int_std__string *pCVar8;
  
  *(undefined **)this_ptr = PTR_vtable_00324f90 + 0x10;
  if (*(code **)(this_ptr + 0x60) != (code *)0x0) {
    (**(code **)(this_ptr + 0x60))(this_ptr + 0x50,this_ptr + 0x50,3);
  }
  puVar7 = PTR__S_empty_rep_storage_00324fa0;
  pCVar8 = *(Channel_std__pair_int_std__string **)(this_ptr + 0x38);
  pCVar1 = this_ptr + 0x38;
  if (pCVar8 != pCVar1) {
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      do {
        lVar5 = *(long long *)(pCVar8 + 0x18);
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        if (((allocator *)(lVar5 + -0x18) != (allocator *)puVar7) &&
           (iVar4 = *(int *)(lVar5 + -8), *(int *)(lVar5 + -8) = iVar4 + -1, iVar4 < 1)) {
          rea_std__string___Rep___M_destroy((allocator *)(lVar5 + -0x18));
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
    else {
      do {
        pCVar6 = *(Channel_std__pair_int_std__string **)pCVar8;
        paVar2 = (allocator *)(*(long long *)(pCVar8 + 0x18) + -0x18);
        if (paVar2 != (allocator *)puVar7) {
          LOCK();
          piVar3 = (int *)(*(long long *)(pCVar8 + 0x18) + -8);
          iVar4 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar4 < 1) {
            rea_std__string___Rep___M_destroy(paVar2);
          }
        }
        rea_operator_delete(pCVar8);
        pCVar8 = pCVar6;
      } while (pCVar6 != pCVar1);
    }
  }
  std______Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root______M_erase((_Rb_tree_Root__std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std___Select1st_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root_std__less_Root__std__allocator_std__pair_Root_const_std__unique_ptr_Root_std__default_delete_Root
              *)(this_ptr + 8),*(_Rb_tree_node **)(this_ptr + 0x18));
  *(undefined **)this_ptr = PTR_vtable_00324ef0 + 0x10;
  rea_operator_delete(this_ptr);
  return;
}





// ------------------------------------------------------------------
// IDX 197  0010dae0  FUN_0010dae0
// ------------------------------------------------------------------
void rea_FUN_0010dae0(long long param_1)
{
  int *piVar1;
  long long lVar2;
  int iVar3;
  
  if (*(code **)(param_1 + 0x20) != (code *)0x0) {
    (**(code **)(param_1 + 0x20))(param_1 + 0x10,param_1 + 0x10,3);
  }
  lVar2 = *(long long *)(param_1 + 8);
  if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar3 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 198  0010db50  FUN_0010db50
// ------------------------------------------------------------------
void rea_FUN_0010db50(long long * param_1)
{
  int *piVar1;
  long long lVar2;
  int iVar3;
  
  if ((code *)param_1[3] != (code *)0x0) {
    (*(code *)param_1[3])(param_1 + 1,param_1 + 1,3);
  }
  lVar2 = *param_1;
  if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00324fa0) {
    piVar1 = (int *)(lVar2 + -8);
    if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
      iVar3 = *(int *)(lVar2 + -8);
      *(int *)(lVar2 + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
    }
  }
  return;
}





