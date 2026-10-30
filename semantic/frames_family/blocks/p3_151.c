
void _FINI_0(void)

{
  if (__bss_start == '\0') {
    if (PTR___cxa_finalize_00324f28 != (undefined *)0x0) {
      __cxa_finalize(&PTR_LOOP_00324740);
    }
    FUN_00107860();
    __bss_start = '\x01';
  }
  return;
}



