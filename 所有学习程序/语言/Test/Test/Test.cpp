// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<cstringt.h >
using namespace std;
//
//void StrTest()
//{
//	//�ַ���������
//	char* sz = "192.168.0.11;8000;admin;123456";
//	char szIP[20];
//	char szPort[20];
//	char szUser[20];
//	char szPass[20];
//	memset(szIP,0,sizeof(szIP));
//	memset(szPort,0,sizeof(szPort));
//	memset(szUser,0,sizeof(szUser));
//	memset(szPass,0,sizeof(szPass));
//	//����IP
//	char* index = strchr(sz,';');
//	strncpy_s(szIP,sz,index - sz);
//	char* p = index+1; 
//	//�����˿�
//	index = strchr(p,';');
//	strncpy_s(szPort,p,index - p);
//	p = index+1; 
//	//�õ��û���
//	index = strchr(p,';');
//	strncpy_s(szUser,p,index - p);
//	p = index+1; 
//	//�õ�����
//	strcpy_s(szPass,p);
//	//
//	char* index1 = strrchr(sz,';');
//	//
//	char buf[20] = "HELLO";
//	_strlwr_s(buf);//��дת��Сд
//	char buf1[20] = "china";
//	_strupr_s(buf1);//Сдת����д
//}
//
//void StrChr()
//{
//	char* address = "�й�#����ʡ#֣����#֣������#����ˮ��ˮ���ѧ#��Ϣ����ѧԺ";
//	int c = '#';
//	char* p = address;
//	char** strResult;
//	char* index;
//	int nCount = 0;
//	//�õ��Ӵ�����
//	while(true)
//	{
//		index = strchr(p,c);
//		if(index == NULL)
//		{	
//			nCount ++;
//			break;
//		}
//		p = index + 1;
//		nCount ++;
//	}
//	//���Ӵ�
//	strResult = new char* [nCount];
//	p = address;
//	int nLen = 0;
//	int i = 0;
//	while(true)
//	{
//		index = strchr(p,c);
//		if(index == NULL)
//		{
//			nLen = strlen(p) +1;
//			strResult[i] = new char [nLen];
//			memset(strResult[i],0,nLen);
//			strcpy_s(strResult[i],nLen,p);
//			//strcpy_s(strResult[i],nLen,p);
//			break;
//		}
//		nLen = index -p +1;
//		strResult[i] = new char [nLen];
//		memset(strResult[i],0,nLen );
//		strncpy_s(strResult[i],nLen,p,index - p);
//		//strncpy_s(strResult[i],nLen,p,index - p);
//		p = index +1;
//		i++;
//	}
//	for(int j= 0;j<= i;j++)
//		printf("%s\n",strResult[j]);
//
//}

int _tmain(int argc, _TCHAR* argv[])
{

	CString s = _T("4.");
	double d = stod(s);
	//char a[5];
	//scanf("%s",a);
	////int b = a;
	//int c = (int)a;

	return 0;
}

