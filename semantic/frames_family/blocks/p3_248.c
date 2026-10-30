
/* mkdir_p(char const*, int) */

undefined4 mkdir_p(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  size_t __n;
  char *pcVar3;
  stat sStack_10b8;
  char local_1028 [4104];
  
  __n = strnlen(param_1,0x1000);
  uVar2 = 0xffffffff;
  if ((__n & 0xffffffffffffefff) != 0) {
    memcpy(local_1028,param_1,__n);
    local_1028[__n] = '\0';
    if (*(char *)((long)sStack_10b8.__unused + __n + 0x17) == '/') {
      *(undefined1 *)((long)sStack_10b8.__unused + __n + 0x17) = 0;
    }
    iVar1 = __xstat(1,local_1028,&sStack_10b8);
    if ((iVar1 == 0) && ((sStack_10b8.st_mode & 0xf000) == 0x4000)) {
      uVar2 = 0;
    }
    else {
      pcVar3 = local_1028 + 1;
      while (local_1028[1] != '\0') {
        while (local_1028[1] != '/') {
          pcVar3 = pcVar3 + 1;
          local_1028[1] = *pcVar3;
          if (local_1028[1] == '\0') goto LAB_001168c0;
        }
        *pcVar3 = '\0';
        mkdir(local_1028,param_2);
        *pcVar3 = '/';
        local_1028[1] = pcVar3[1];
        pcVar3 = pcVar3 + 1;
      }
LAB_001168c0:
      mkdir(local_1028,param_2);
      uVar2 = 0;
    }
  }
  return uVar2;
}



