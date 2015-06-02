// ServerClient.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>
#include <process.h>
#pragma comment(lib,"Ws2_32")

struct ThreadData
{
	SOCKET sock;
	sockaddr_in from;
	bool b;
};

void Thread(void *p)
{
	ThreadData* pSock = (ThreadData*)p;
	char buf[256];
	sockaddr_in remoteaddr;
	while(true)
	{
		int nLen = sizeof(remoteaddr);
		int nGet = recvfrom(pSock->sock,buf,256,0,(sockaddr*)&(pSock->from),&nLen);//返回接收字节数
		if( nGet > 0)
		{
			printf("%s\n",buf);
			pSock->b = true;
		}
		else
		{
			int nError = WSAGetLastError();
			printf("1Error!Error Type Is %d\n",nError);
			closesocket(pSock->sock);
			WSACleanup();
			return ;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nPost = _wtoi(argv[2]);
	char sIP[256];
	wcstombs(sIP,argv[1],256);
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
		printf("2Error!Error Type Is:%d",nError);
		WSACleanup();
		return -1;
	}
	//关联地址和端口
	
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(nPost); 
	//addr.sin_port = htons(8000);
	addr.sin_addr.S_un.S_addr = inet_addr(sIP); 
	//addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.11");
	
	//绑定地址和端口，成功返回
	int nFlag = bind(sock,(sockaddr*)&addr,sizeof(addr));
	if(nFlag != 0)
	{
		int nError = WSAGetLastError();
		printf("3Error!Error Type Is:%d",nError);
		closesocket(sock);
		WSACleanup();
		return -1;
	}

	//开启一个线程
	ThreadData thread;
	thread.sock =sock;
	thread.b = false;
	_beginthread(Thread,0,&thread);

	while(true)
	{
		//关联地址和端口
		sockaddr_in addr;
		if(!thread.b)
		{
			char sIP[20];
			int nProt;
			printf("请输入接收者IP 端口号:");
			scanf("%s %d",sIP,&nProt);
			addr.sin_family = AF_INET;
			addr.sin_port = htons(nProt);
			addr.sin_addr.S_un.S_addr = inet_addr(sIP);
		}
		else
		{
			int choose;
			printf("向其他地址发送数据(1):");
			scanf("%d",&choose);
			if(choose == 1)
			{
				char sIP[20];
				int nProt;
				printf("请输入接收者IP 端口号:");
				scanf("%s %d",sIP,&nProt);
				addr.sin_family = AF_INET;
				addr.sin_port = htons(nProt);
				addr.sin_addr.S_un.S_addr = inet_addr(sIP);
			}
			else
			{
				//addr = thread.from;
				addr.sin_family = thread.from.sin_family;
				addr.sin_port = thread.from.sin_port;
				addr.sin_addr.S_un.S_addr = thread.from.sin_addr.S_un.S_addr;
			}
		}
		int nLen = sizeof(addr);
		char buf[3];
		//do
		//{
		printf("请输入数据:");
		scanf_s("%s",buf);
		sendto(sock,buf,strlen(buf)+1,0,(sockaddr*)&addr,nLen);
		printf("是否继续(Y):");
		scanf_s("%s",buf);
		if(  !(strcmp(buf,"Y") == 0 || strcmp(buf,"y") == 0) )
			break;
	}
	//卸载DLL
	closesocket(sock);
	WSACleanup();
	return 0;
}

