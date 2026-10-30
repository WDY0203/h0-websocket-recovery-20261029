
/* is_myaddr(char const*) */

undefined8 is_myaddr(char *param_1)

{
  short *psVar1;
  int iVar2;
  char *__s2;
  long *plVar3;
  long *local_28 [3];
  
  getifaddrs(local_28);
  plVar3 = local_28[0];
  if (local_28[0] == (long *)0x0) {
    local_28[0] = (long *)0x0;
  }
  else {
    do {
      psVar1 = (short *)plVar3[3];
      if ((psVar1 != (short *)0x0) && (*psVar1 == 2)) {
        __s2 = inet_ntoa((in_addr)*(in_addr_t *)(psVar1 + 2));
        iVar2 = strcmp(param_1,__s2);
        if (iVar2 == 0) {
          freeifaddrs(local_28[0]);
          return 1;
        }
      }
      plVar3 = (long *)*plVar3;
    } while (plVar3 != (long *)0x0);
  }
  freeifaddrs(local_28[0]);
  return 0;
}



