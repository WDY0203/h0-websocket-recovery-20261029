
/* WARNING: Switch with 1 destination removed at 0x00107360 */

void setnonblock(int param_1)

{
  uint uVar1;
  
  uVar1 = fcntl(param_1,3);
  if ((int)uVar1 < 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  fcntl(param_1,4,(ulong)(uVar1 | 0x800));
  return;
}



