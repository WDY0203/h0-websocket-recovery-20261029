
/* UnixClient::~UnixClient() */

void __thiscall UnixClient::~UnixClient(UnixClient *this)

{
  ~UnixClient(this);
  operator_delete(this);
  return;
}



