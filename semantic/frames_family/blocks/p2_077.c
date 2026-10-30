
/* WARNING: Switch with 1 destination removed at 0x00107330 */

void setcloexec(int param_1)

{
  uint uVar1;
  
  uVar1 = fcntl(param_1,1);
  if ((int)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  fcntl(param_1,2,(ulong)(uVar1 | 1));
  return;
}



