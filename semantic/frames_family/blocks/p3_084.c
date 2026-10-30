
/* WARNING: Switch with 1 destination removed at 0x00107430 */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_stack_abort(void)

{
  print_stack();
                    /* WARNING: Subroutine does not return */
  abort();
}



