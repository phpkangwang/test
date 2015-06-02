// ListPractice.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "function.h"
#pragma warning(disable:4996)//����4996����

void ShowMenu()
{
	char* menu[]=
	{
		"1.�����Ϣ����һ��λ��",
		"2.�����Ϣ�����һ��λ��",
		"3.�����Ϣ��ָ��λ��",
		"4.��ʾ����",
		"5.���������Ϣ",
		"6.�鿴�ܹ�����Ϣ����",
		"7.����",
		"0.�˳�����"
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
		printf("һ����%d����Ϣ��¼��\n",Count(lst));
		break;
	case 7:
		printf("����ʽ:(id/name)");
		char temp[5];
		scanf("%s",temp);
		BubbleSort(lst,temp);
		break;
	default:
		printf("ѡ������!\n");
		break;
	}
}

void ApplicationRun(List* lst)
{
	char nChoose[5];
	while(true)
	{
		//��ʾ�˵�
		ShowMenu();
		//ѡ���ж�
		printf("Input choose��");
		scanf("%s",nChoose);
		int n = atoi(nChoose);
		if( n == 0 )
			break;
		//ѡ����
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

