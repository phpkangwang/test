// FilePractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
int _tmain(int argc, _TCHAR* argv[])
{
	FILE* fp = fopen("C:\\Documents and Settings\\Administrator\\桌面\\test.txt","rb+");
	if(fp == nullptr)
		return -1;
	char* str1 = "sunhao";
	fprintf(fp,"hello,%s",str1);
	fclose(fp);


	//fp = fopen("C:\\Documents and Settings\\Administrator\\桌面\\test.txt","rb");
	//char str[100];
	//fscanf(fp,"%s",str);
	//printf(str);
	//fclose(fp);

	fp = fopen("C:\\Documents and Settings\\Administrator\\桌面\\test.txt","ab");
	if(fp == nullptr)
		return -1;
	//char* str1 = "sunhao";
	fprintf(fp,"hello,%s",str1);
	fclose(fp);

	return 0;
}

