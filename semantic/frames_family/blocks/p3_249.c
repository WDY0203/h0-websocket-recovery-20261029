
/* dirname(std::string const&) */

string * dirname(string *param_1)

{
  char *__s;
  char *pcVar1;
  undefined8 *in_RSI;
  allocator local_19 [9];
  
  __s = (char *)*in_RSI;
  pcVar1 = strrchr(__s,0x2f);
  if (pcVar1 == (char *)0x0) {
    *(undefined **)param_1 = PTR__S_empty_rep_storage_00324fa0 + 0x18;
    return param_1;
  }
  if (__s < pcVar1) {
    do {
      if (pcVar1[-1] != '/') break;
      pcVar1 = pcVar1 + -1;
    } while (pcVar1 != __s);
  }
  std::string::string(param_1,__s,(long)pcVar1 - (long)__s,local_19);
  return param_1;
}



