// FilePractice.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
int _tmain(int argc, _TCHAR* argv[])
{
	FILE* fp = fopen("C:\\Documents and Settings\\Administrator\\����\\test.txt","rb+");
	if(fp == nullptr)
		return -1;
	char* str1 = "sunhao";
	fprintf(fp,"hello,%s",str1);
	fclose(fp);


	//fp = fopen("C:\\Documents and Settings\\Administrator\\����\\test.txt","rb");
	//char str[100];
	//fscanf(fp,"%s",str);
	//printf(str);
	//fclose(fp);

	fp = fopen("C:\\Documents and Settings\\Administrator\\����\\test.txt","ab");
	if(fp == nullptr)
		return -1;
	//char* str1 = "sunhao";
	fprintf(fp,"hello,%s",str1);
	fclose(fp);

	return 0;
}

