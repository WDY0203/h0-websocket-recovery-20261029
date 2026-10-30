
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* print_stack_abort() */

void print_stack_abort(void)

{
  print_stack();
                    /* WARNING: Subroutine does not return */
  abort();
}



