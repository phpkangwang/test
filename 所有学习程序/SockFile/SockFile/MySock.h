#pragma once


#define FILE_BLOCK_SIZE 256
#define BUF_SIZE FILE_BLOCK_SIZE+3
// CMySock ÃüÁîÄ¿±ê

class CMySock : public CAsyncSocket
{
public:
	CMySock(CWnd* pWnd);
	virtual ~CMySock();
	virtual void OnReceive(int nErrorCode);
public:
	CWnd* m_pWnd;
	FILE* m_fp;
	int m_nCount;
	FILE* fp[10];
	CMutex m_mutex;
	virtual void OnSend(int nErrorCode);
};


