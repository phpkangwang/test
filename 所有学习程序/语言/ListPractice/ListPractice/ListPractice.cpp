// ListPractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "function.h"
#pragma warning(disable:4996)//消除4996警告

void ShowMenu()
{
	char* menu[]=
	{
		"1.添加信息到第一个位置",
		"2.添加信息到最后一个位置",
		"3.添加信息到指定位置",
		"4.显示所有",
		"5.清空所有信息",
		"6.查看总共的信息条数",
		"7.排序",
		"0.退出程序"
	};
	int nCount = 8;
	for(int i=0; i< 8;i++)
		printf("%s\n",menu[i]);
}

void DoInput(List* lst,int nChoose)
{
	char id[10];
	char name[20];
	int age;
	switch(nChoose)
	{
	case 1:
		printf("Please input id name age:");
		scanf("%s%s%d",id,name,&age);
		AddFirst(lst,id,name,age);
		break;
	case 2:
		printf("Please input id name age:");
		scanf("%s%s%d",id,name,&age);
		AddLast(lst,id,name,age);
		break;
	case 3:
		printf("Please input id id name age:");
		scanf("%s%s%s%d",id,name,&age);
		char ID[10];
		AddAppoint(lst,ID,id,name,age);
		break;
	case 4:
		ShowList(lst);
		break;
	case 5:
		FreeList(lst);
		break;
	case 6:
		printf("一共有%d条信息记录。\n",Count(lst));
		break;
	case 7:
		printf("排序方式:(id/name)");
		char temp[5];
		scanf("%s",temp);
		BubbleSort(lst,temp);
		break;
	default:
		printf("选择有误!\n");
		break;
	}
}

void ApplicationRun(List* lst)
{
	char nChoose[5];
	while(true)
	{
		//显示菜单
		ShowMenu();
		//选择判断
		printf("Input choose：");
		scanf("%s",nChoose);
		int n = atoi(nChoose);
		if( n == 0 )
			break;
		//选择处理
		DoInput(lst,n);
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	List lst;
	lst.next = NULL;//nullptr
	ReadFromTxtFile(&lst,"student.txt");
	ApplicationRun(&lst);
	SaveToTxtFile(&lst,"student.txt");
	return 0;
}

