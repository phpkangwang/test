// MyPractice.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "function.h"
#include<string.h>
void Run()
{
	int nGraphSize;
	int temp;
	do
	{
		printf("���������εĴ�С(����):");
		scanf("%d",&nGraphSize);
		temp = nGraphSize%2;
		if(temp==0)
			printf("Error!��������ż��!\n");
	}while(temp==0);
	OutputGraph(nGraphSize);
}
int _tmain(int argc, _TCHAR* argv[])
{
	char buffer[] = "My name is sunhao!";
	char str1[10];
	char str2[10];
	char str3[10];
	memset(str1,0,sizeof(str1));
	memset(str2,0,sizeof(str2));
	memset(str3,0,sizeof(str3));
	sscanf(buffer,"%s%s%s",str1,str2,str3);

	char buffer1[20];
	memset(buffer,0,20);
	//strcpy(str1,""


	return 0;
}