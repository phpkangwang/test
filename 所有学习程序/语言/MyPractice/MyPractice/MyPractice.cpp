// MyPractice.cpp : 定义控制台应用程序的入口点。
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
		printf("请输入菱形的大小(奇数):");
		scanf("%d",&nGraphSize);
		temp = nGraphSize%2;
		if(temp==0)
			printf("Error!不能输入偶数!\n");
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