
/* TcpConn::idle_proc() */

void __thiscall TcpConn::idle_proc(TcpConn *this)

{
  if (*(long *)(this + 0xc0) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00117f2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(this + 200))(this + 0xb0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_function_call();
}



