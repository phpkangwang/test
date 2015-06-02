// TcpClient.cpp : 实现文件
//

#include "stdafx.h"
#include "SdiSocketClient.h"
#include "TcpClient.h"


// CTcpClient

CTcpClient::CTcpClient()
{
}

CTcpClient::~CTcpClient()
{
}


// CTcpClient 成员函数


void CTcpClient::OnSend(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	

	CAsyncSocket::OnSend(nErrorCode);
}

void CTcpClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	char buf[256];
	memset(buf,0,256);
	this->Receive(buf,256,0);
	CStringA sa = buf;
	CString s = CA2W(sa);
	theApp.ReceiveInfo(s);
	

	CAsyncSocket::OnReceive(nErrorCode);
}
