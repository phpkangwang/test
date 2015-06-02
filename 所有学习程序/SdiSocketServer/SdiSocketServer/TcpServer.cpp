// TcpServer.cpp : 实现文件
//

#include "stdafx.h"
#include "SdiSocketServer.h"
#include "TcpServer.h"


// CTcpServer

CTcpServer::CTcpServer()
{
}

CTcpServer::~CTcpServer()
{
}


// CTcpServer 成员函数


void CTcpServer::OnAccept(int nErrorCode)
{
	CTcpClient* tc = new CTcpClient();
	this->Accept(*tc);
	m_lst.push_back(tc);

	CAsyncSocket::OnAccept(nErrorCode);
}
