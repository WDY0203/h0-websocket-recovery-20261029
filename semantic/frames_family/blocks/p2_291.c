
/* UnixClient::idle() */

uint __thiscall UnixClient::idle(UnixClient *this)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this + 0x98);
  if (iVar1 == 1) {
    TcpConn::idle_proc(*(TcpConn **)(this + 0xa0));
    uVar2 = 0;
    if (*(char *)(*(long *)(this + 0xa0) + 0x58) == '\0') {
      return *(byte *)(*(long *)(this + 0xa0) + 0x59) ^ 1;
    }
  }
  else {
    uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),iVar1 == 2);
  }
  return uVar2;
}



