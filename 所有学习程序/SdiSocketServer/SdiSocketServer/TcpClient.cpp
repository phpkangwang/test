// TcpClient.cpp : 实现文件
//

#include "stdafx.h"
#include "SdiSocketServer.h"
#include "TcpClient.h"


// CTcpClient

CTcpClient::CTcpClient()
{
}

CTcpClient::~CTcpClient()
{
}


// CTcpClient 成员函数


void CTcpClient::OnReceive(int nErrorCode)
{
	char buf[256];
	memset(buf,0,256);
	this->Receive(buf,256,0);

	CStringA sa = "i had receive";
	this->Send(sa,sa.GetLength()+1,0);

	CAsyncSocket::OnReceive(nErrorCode);
}
