
/* WARNING: Switch with 1 destination removed at 0x001077c0 */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long current_time(void)

{
  timeval tStack_18;
  
  gettimeofday(&tStack_18,(__timezone_ptr_t)0x0);
  return tStack_18.tv_sec * 1000000 + tStack_18.tv_usec;
}



