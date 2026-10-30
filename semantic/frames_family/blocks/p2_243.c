
/* setnonblock(int) */

void setnonblock(int param_1)

{
  uint uVar1;
  
  uVar1 = fcntl(param_1,3);
  if (-1 < (int)uVar1) {
    fcntl(param_1,4,(ulong)(uVar1 | 0x800));
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}



