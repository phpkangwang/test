// Client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32")//����

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
	//����
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
	
	//printf("����������߶˿ں�:");
	//scanf("%d",&nProt);
	//addr.sin_port = htons(nProt);
	addr.sin_port = htons(8000);
	//printf("�����������IP��ַ:");
	//scanf("%s",sIP);
	//addr.sin_addr.S_un.S_addr = inet_addr(sIP);
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.11");
	int nLen = sizeof(addr);
	char buf[256];
	do
	{
		printf("����������:");
		scanf_s("%s",buf);
		sendto(sock,buf,strlen(buf)+1,0,(sockaddr*)&addr,nLen);
		printf("�Ƿ����(Y):");
		scanf_s("%s",buf);
	}while(strcmp(buf,"Y") == 0 || strcmp(buf,"y") == 0);
	//ж��
	closesocket(sock);
	WSACleanup();
	return 0;
}

