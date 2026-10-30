
/* std::string __gnu_cxx::__to_xstring<std::string, char>(int (*)(char*, unsigned long, char const*,
   __va_list_tag*), unsigned long, char const*, ...) */

_func_int_char_ptr_ulong_char_ptr___va_list_tag_ptr *
__gnu_cxx::__to_xstring<std::string,char>
          (_func_int_char_ptr_ulong_char_ptr___va_list_tag_ptr *param_1,ulong param_2,char *param_3,
          ...)

{
  undefined1 *__src;
  long lVar1;
  char in_AL;
  int iVar2;
  ulong *puVar3;
  ulong *__dest;
  undefined8 in_RCX;
  undefined8 in_R8;
  undefined8 in_R9;
  ulong __n;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  undefined8 uStack_100;
  allocator local_f1;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 *local_e8;
  undefined1 *local_e0;
  undefined1 local_d8 [32];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  
  if (in_AL != '\0') {
    local_a8 = in_XMM0_Qa;
    local_98 = in_XMM1_Qa;
    local_88 = in_XMM2_Qa;
    local_78 = in_XMM3_Qa;
    local_68 = in_XMM4_Qa;
    local_58 = in_XMM5_Qa;
    local_48 = in_XMM6_Qa;
    local_38 = in_XMM7_Qa;
  }
  local_e8 = &stack0x00000008;
  lVar1 = -((ulong)(param_3 + 0x1e) & 0xfffffffffffffff0);
  local_e0 = local_d8;
  __src = (undefined1 *)((long)&local_f0 + lVar1);
  local_f0 = 0x20;
  local_ec = 0x30;
  local_b8 = in_R8;
  local_b0 = in_R9;
  *(undefined8 *)((long)&uStack_100 + lVar1) = 0x11c8d4;
  iVar2 = (*(code *)param_2)(__src,param_3,in_RCX,&local_f0);
  if (__src == __src + iVar2) {
    __dest = (ulong *)(PTR__S_empty_rep_storage_00324fa0 + 0x18);
  }
  else {
    __n = (long)(__src + iVar2) - (long)__src;
    *(undefined8 *)((long)&uStack_100 + lVar1) = 0x11c8f3;
    puVar3 = (ulong *)std::string::_Rep::_S_create(__n,0,&local_f1);
    __dest = puVar3 + 3;
    if (__n == 1) {
      *(undefined1 *)(puVar3 + 3) = *__src;
    }
    else {
      *(undefined8 *)((long)&uStack_100 + lVar1) = 0x11c90e;
      __dest = memcpy(__dest,__src,__n);
    }
    if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00324fa0) {
      *(undefined4 *)(puVar3 + 2) = 0;
      *puVar3 = __n;
      *(undefined1 *)((long)puVar3 + __n + 0x18) = 0;
    }
  }
  *(ulong **)param_1 = __dest;
  return param_1;
}



