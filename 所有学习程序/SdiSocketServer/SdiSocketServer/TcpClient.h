#pragma once

// CTcpClient ����Ŀ��

class CTcpClient : public CAsyncSocket
{
public:
	CTcpClient();
	virtual ~CTcpClient();
	virtual void OnReceive(int nErrorCode);
};


