// MySocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCSock.h"
#include "MySocket.h"


// CMySocket

CMySocket::CMySocket(CWnd* CWnd)
{
	m_CWnd = CWnd;
}

CMySocket::~CMySocket()
{
}


// CMySocket ��Ա����

#include "MFCSockDlg.h"
void CMySocket::OnReceive(int nErrorCode)
{
	char buf[256];
	CString ip;
	UINT port;
	ReceiveFrom(buf,256,ip,port);
	CMFCSockDlg* p = (CMFCSockDlg*)m_CWnd;

	CStringA as = buf;
	p->m_RecordList.AddString( CA2W(as) );

	CAsyncSocket::OnReceive(nErrorCode);
}
