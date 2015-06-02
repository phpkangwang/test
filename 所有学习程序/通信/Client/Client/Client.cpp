// Client.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32")//加载

int _tmain(int argc, _TCHAR* argv[])
{
	//if(argc < 3)
	//{
	//	int nError = WSAGetLastError();
	//	printf("Error!Error Type Is:%d",nError);
	//	return -1;
	//}
	//int nProt = _wtoi(argv[2]);
	//char sIP[256];
	//wcstombs(sIP,argv[1],256);
	WSADATA wd;
	//加载
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
	
	//printf("请输入接收者端口号:");
	//scanf("%d",&nProt);
	//addr.sin_port = htons(nProt);
	addr.sin_port = htons(8000);
	//printf("请输入接收者IP地址:");
	//scanf("%s",sIP);
	//addr.sin_addr.S_un.S_addr = inet_addr(sIP);
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.11");
	int nLen = sizeof(addr);
	char buf[256];
	do
	{
		printf("请输入数据:");
		scanf_s("%s",buf);
		sendto(sock,buf,strlen(buf)+1,0,(sockaddr*)&addr,nLen);
		printf("是否继续(Y):");
		scanf_s("%s",buf);
	}while(strcmp(buf,"Y") == 0 || strcmp(buf,"y") == 0);
	//卸载
	closesocket(sock);
	WSACleanup();
	return 0;
}

