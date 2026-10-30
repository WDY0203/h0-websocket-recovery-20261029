
/* setcloexec(int) */

void setcloexec(int param_1)

{
  uint uVar1;
  
  uVar1 = fcntl(param_1,1);
  if (-1 < (int)uVar1) {
    fcntl(param_1,2,(ulong)(uVar1 | 1));
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}



