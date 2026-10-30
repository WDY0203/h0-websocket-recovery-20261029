
/* TcpClient::~TcpClient() */

void __thiscall TcpClient::~TcpClient(TcpClient *this)

{
  ~TcpClient(this);
  operator_delete(this);
  return;
}



