
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* current_time() */

long current_time(void)

{
  timeval local_18;
  
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  return local_18.tv_sec * 1000000 + local_18.tv_usec;
}



