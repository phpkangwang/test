// Server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{

	/*int nPost = _wtoi(argv[2]);
	char sIP[256];
	wcstombs(sIP,argv[1],256);*/
	//初始化_DLL
	WSADATA wd;
	int nJudge = WSAStartup(MAKEWORD(2,2),&wd);
	if(nJudge != 0)
	{
		printf("Error!初始化失败!");
		return -1;
	}
	//创建套接字
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		int nError = WSAGetLastError();
		printf("Error!Error Type Is:%d",nError);
		WSACleanup();
		return -1;
	}
	//关联地址和端口
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	//addr.sin_port = htons(nPost); 
	addr.sin_port = htons(8000);
	//addr.sin_addr.S_un.S_addr = inet_addr(sIP); 
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.11");
	
	//绑定地址和端口，成功返回
	int nFlag = bind(sock,(sockaddr*)&addr,sizeof(addr));
	if(nFlag != 0)
	{
		int nError = WSAGetLastError();
		printf("Error!Error Type Is:%d",nError);
		closesocket(sock);
		WSACleanup();
		return -1;
	}
	//开始接收数据
	while(true)
	{
		char buf[256];
		sockaddr_in remoteaddr;
		int nLen = sizeof(remoteaddr);
		int nGet = recvfrom(sock,buf,256,0,(sockaddr*)&remoteaddr,&nLen);//返回接收字节数
		if( nGet < 0)
		{
			int nError = WSAGetLastError();
			printf("Error!Error Type Is %d\n",nError);
			closesocket(sock);
			WSACleanup();
			return -1;
		}
		else
		{
			printf("%s\n",buf);
		}
	}
	//卸载DLL
	closesocket(sock);
	WSACleanup();
	return 0;
}

