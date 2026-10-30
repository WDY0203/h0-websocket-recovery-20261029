
/* UnixServer::~UnixServer() */

void __thiscall UnixServer::~UnixServer(UnixServer *this)

{
  ~UnixServer(this);
  operator_delete(this);
  return;
}



