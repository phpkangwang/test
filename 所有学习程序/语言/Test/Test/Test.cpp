// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<cstringt.h >
using namespace std;
//
//void StrTest()
//{
//	//字符串处理函数
//	char* sz = "192.168.0.11;8000;admin;123456";
//	char szIP[20];
//	char szPort[20];
//	char szUser[20];
//	char szPass[20];
//	memset(szIP,0,sizeof(szIP));
//	memset(szPort,0,sizeof(szPort));
//	memset(szUser,0,sizeof(szUser));
//	memset(szPass,0,sizeof(szPass));
//	//解析IP
//	char* index = strchr(sz,';');
//	strncpy_s(szIP,sz,index - sz);
//	char* p = index+1; 
//	//解析端口
//	index = strchr(p,';');
//	strncpy_s(szPort,p,index - p);
//	p = index+1; 
//	//得到用户名
//	index = strchr(p,';');
//	strncpy_s(szUser,p,index - p);
//	p = index+1; 
//	//得到密码
//	strcpy_s(szPass,p);
//	//
//	char* index1 = strrchr(sz,';');
//	//
//	char buf[20] = "HELLO";
//	_strlwr_s(buf);//大写转换小写
//	char buf1[20] = "china";
//	_strupr_s(buf1);//小写转换大写
//}
//
//void StrChr()
//{
//	char* address = "中国#河南省#郑州市#郑东新区#华北水利水电大学#信息工程学院";
//	int c = '#';
//	char* p = address;
//	char** strResult;
//	char* index;
//	int nCount = 0;
//	//得到子串个数
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
//	//求子串
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

