// Server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{

	/*int nPost = _wtoi(argv[2]);
	char sIP[256];
	wcstombs(sIP,argv[1],256);*/
	//��ʼ��_DLL
	WSADATA wd;
	int nJudge = WSAStartup(MAKEWORD(2,2),&wd);
	if(nJudge != 0)
	{
		printf("Error!��ʼ��ʧ��!");
		return -1;
	}
	//�����׽���
	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock == INVALID_SOCKET)
	{
		int nError = WSAGetLastError();
		printf("Error!Error Type Is:%d",nError);
		WSACleanup();
		return -1;
	}
	//������ַ�Ͷ˿�
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	//addr.sin_port = htons(nPost); 
	addr.sin_port = htons(8000);
	//addr.sin_addr.S_un.S_addr = inet_addr(sIP); 
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.11");
	
	//�󶨵�ַ�Ͷ˿ڣ��ɹ�����
	int nFlag = bind(sock,(sockaddr*)&addr,sizeof(addr));
	if(nFlag != 0)
	{
		int nError = WSAGetLastError();
		printf("Error!Error Type Is:%d",nError);
		closesocket(sock);
		WSACleanup();
		return -1;
	}
	//��ʼ��������
	while(true)
	{
		char buf[256];
		sockaddr_in remoteaddr;
		int nLen = sizeof(remoteaddr);
		int nGet = recvfrom(sock,buf,256,0,(sockaddr*)&remoteaddr,&nLen);//���ؽ����ֽ���
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
	//ж��DLL
	closesocket(sock);
	WSACleanup();
	return 0;
}

