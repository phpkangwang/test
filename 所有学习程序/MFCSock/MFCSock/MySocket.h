#pragma once

// CMySocket ÃüÁîÄ¿±ê

class CMySocket : public CAsyncSocket
{
public:
	CWnd* m_CWnd;
public:
	CMySocket(CWnd* CWnd);
	virtual ~CMySocket();
	virtual void OnReceive(int nErrorCode);
};


