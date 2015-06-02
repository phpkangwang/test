#pragma once

// CTcpClient ÃüÁîÄ¿±ê

class CTcpClient : public CAsyncSocket
{
public:
	CTcpClient();
	virtual ~CTcpClient();
	virtual void OnSend(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


