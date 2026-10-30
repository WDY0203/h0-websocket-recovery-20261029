
/* WARNING: Switch with 1 destination removed at 0x00107100 */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_stack(void)

{
  char *__s;
  int iVar1;
  void *__ptr;
  size_t __n;
  long lVar2;
  undefined1 auStack_348 [808];
  
  iVar1 = backtrace(auStack_348,100);
  __ptr = (void *)backtrace_symbols(auStack_348,iVar1);
  write(2,"backtrace:",10);
  write(2,"\n",1);
  write(2,"<<<<<",5);
  write(2,"\n",1);
  if (__ptr != (void *)0x0) {
    lVar2 = 0;
    if (0 < iVar1) {
      do {
        __s = *(char **)((long)__ptr + lVar2 * 8);
        lVar2 = lVar2 + 1;
        __n = strlen(__s);
        write(2,__s,__n);
        write(2,"\n",1);
      } while ((int)lVar2 < iVar1);
    }
    free(__ptr);
  }
  write(2,">>>>>",5);
  write(2,"\n",1);
  return;
}



