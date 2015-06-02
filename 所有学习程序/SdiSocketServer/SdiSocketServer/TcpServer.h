#pragma once

// CTcpServer ÃüÁîÄ¿±ê
#include"TcpClient.h"
#include<list>
using namespace std;

class CTcpServer : public CAsyncSocket
{
public:

	list<CTcpClient*> m_lst;
public:
	CTcpServer();
	virtual ~CTcpServer();
	virtual void OnAccept(int nErrorCode);
};


