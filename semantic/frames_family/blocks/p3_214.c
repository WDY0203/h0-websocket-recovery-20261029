
/* WSConn::~WSConn() */

void __thiscall WSConn::~WSConn(WSConn *this)

{
  ~WSConn(this);
  operator_delete(this);
  return;
}



