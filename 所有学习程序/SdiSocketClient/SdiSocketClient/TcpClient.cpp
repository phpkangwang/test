// TcpClient.cpp : ʵ���ļ�
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


// CTcpClient ��Ա����


void CTcpClient::OnSend(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	

	CAsyncSocket::OnSend(nErrorCode);
}

void CTcpClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	char buf[256];
	memset(buf,0,256);
	this->Receive(buf,256,0);
	CStringA sa = buf;
	CString s = CA2W(sa);
	theApp.ReceiveInfo(s);
	

	CAsyncSocket::OnReceive(nErrorCode);
}
