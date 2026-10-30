
/* TcpConn::~TcpConn() */

void __thiscall TcpConn::~TcpConn(TcpConn *this)

{
  ~TcpConn(this);
  operator_delete(this);
  return;
}



