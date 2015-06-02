#include"stdafx.h"
#include"function.h"

#pragma warning(disable:4996)//消除4996警告

bool NodeIsExist(List* lst,char* id)
{
	TNode* p = lst->next;
	while(p)
	{
		if(strcmp(p->stu.ID,id)==0)
			return true;
		p = p->next;
	}
	return false;
}

//构造新结点
TNode* MakeNode(char* id,char* name,int age)
{
	//节点分配空间
	TNode* node = new TNode;
	//节点信息赋值
	strcpy_s(node->stu.ID,strlen(id)+1,id);
	if(name == nullptr)
		node->stu.strName = nullptr;
	else
	{
		int nLen = strlen(name)+1;
		node->stu.strName = new char[nLen];
		strcpy_s(node->stu.strName,nLen,name);
	}
	node->stu.nAge = age;
	node->next = nullptr;
	return node;
}
//添加到头结点
int AddFirst(List* lst,char* id,char* name,int age)
{
	if(lst == nullptr || id == nullptr)
		return -1;
	if(NodeIsExist(lst,id))
	{
		printf("该学号存在!\n");
		return -1;
	}
	//执行插入操作
	TNode* pNode = MakeNode(id,name,age);
	pNode->next = lst->next;
	lst->next = pNode;
	return 0;
}
//找到尾部结点
TNode* GetLastNode(List* lst)
{
	TNode* p = lst;
	while(p->next !=NULL)
		p = p->next;
	return p;
}
//插入到尾部
int AddLast(List* lst,char* id,char* name,int age)
{
	if(id == nullptr)
		return -1;
	if(NodeIsExist(lst,id))
	{
		printf("该学号存在!\n");
		return -1;
	}
	//节点分配空间
	TNode* pNode = MakeNode(id,name,age);
	//找到最后一个节点
	TNode* LastNode = GetLastNode(lst);
	//执行插入操作
	LastNode->next = pNode;
	return 0;
}
//插入到指定位置
int AddAppoint(List* lst,char* addid,char* id,char* name,int age)
{
	if(lst == NULL || addid == NULL || id == NULL)
		return -1;
	//学号是否存在
	if(NodeIsExist(lst,id))
	{
		printf("该学号存在!\n");
		return -1;
	}
	//节点分配空间
	TNode* pNode = MakeNode(id,name,age);
	//找到指定节点,判断输入节点是否合法
	TNode* p = lst->next;
	int nFlag = 0;
	while(p != NULL)
	{
		if(strcmp(p->stu.ID,addid)==0)//找到指定节点的前一个节点
		{
			nFlag = 1;
			break;
		}
		p = p->next;
	}
	if(nFlag == 0)//输入的节点不存在
		return -1;
	//插入指定节点的前边
	pNode->next = p->next;
	p->next = pNode;
	//插入指定节点之后
	return 0;
}
//删除某一个节点
int DeleteNode(List* lst,char* id)
{
	if(lst == nullptr||id==nullptr)
		return -1;
	TNode* p = lst;
	TNode* DelNode = nullptr;
	while(p->next)
	{
		if(strcmp(p->next->stu.ID,id) == 0)
		{
			DelNode = p->next;
			p->next = DelNode->next;
			if(DelNode->stu.strName)
				delete[] DelNode->stu.strName;
			delete DelNode;
			return 0;
		}
		p = p->next;
	}
	printf("%s is not found!\n",id);
	return -1;
}
//清空链表
void FreeList(List* lst)
{
	TNode* p = lst->next;
	TNode* DelNode = nullptr;
	while(p)
	{
		DelNode = p;
		p = p->next;
		if(DelNode->stu.strName)
			delete[] DelNode->stu.strName;
		delete DelNode;
	}
	lst->next = nullptr;
}
//显示链表
int ShowList(List* lst)
{
	if(lst->next == NULL)
		return -1;
	TNode* p = lst->next;
	while(p)
	{
		printf("%8s %8s %3d\n",
			p->stu.ID,
			(p->stu.strName ? p->stu.strName :"null"),
			p->stu.nAge);
		p = p->next;
	}
	return 0;
}
//求链表节点数
int Count(List* lst)
{
	if(lst->next == NULL)
		return -1;
	int nCount = 0;
	List* p = lst;
	while(p->next)
	{
		nCount++;
		p=p->next;
	}
	return nCount;
}
//按学号进行排序
void OrderList(List* lst)
{
	TNode* p = lst->next;
	lst->next = nullptr;
	TNode* temp,*pMin;
	while(p->next)
	{
		pMin = p;
		temp = p;
		bool bflag = true;
		while(temp->next)
		{
			if(strcmp(temp->next->stu.ID,pMin->stu.ID)<0)
			{
				pMin = temp;
				bflag = false;
			}
			temp = temp->next;
		}
		TNode* q = pMin->next;
		if(bflag)
		{
			p = p->next;
			pMin->next = lst->next;
			lst->next = pMin;
		}	
		else
		{
			pMin->next = q->next;
			q->next = lst->next;
			lst->next = q;
		}
	}
	p->next = lst->next;
	lst->next = p;
}
//冒泡排序
int BubbleSort(List* lst,char* Method)
{
	if(lst->next == NULL)
		return -1;
	int nCount = Count(lst);
	if(nCount<= 1)
		return -1;
	TNode*p ,*q,*t;
	for(int i= 1; i<= nCount; i++)
	{
		p = lst;
		q = p->next;
		t = q->next;
		for(int j= 1;j<= nCount -i;j++)
		{
			if(strcmp(Method,"id")==0)
			{
				if(strcmp(q->stu.ID,t->stu.ID)>0)
				{
					q->next = t->next;
					p->next = t;
					t->next = q;
					p = p->next;
					t = q->next;
					continue;
				}
			}
			if(strcmp(Method,"name")==0)
			{
				if(strcmp(q->stu.strName,t->stu.strName)>0)
				{
					q->next = t->next;
					p->next = t;
					t->next = q;
					p = p->next;
					t = q->next;
					continue;
				}
			}
			if(strcmp(Method,"age")==0)
			{
				if(q->stu.nAge>t->stu.nAge)
				{
					q->next = t->next;
					p->next = t;
					t->next = q;
					p = p->next;
					t = q->next;
					continue;
				}
			}
			p =p->next;
			q =q->next;
			t =t->next;
		}
	}
	return 0;
}
//
void SaveErrorToTxtFile(char* error,int nRows)
{
	FILE* fp = fopen("error.txt","w");
	if( fp == nullptr)
		return;
	fprintf(fp,"第%d行数据有错误!%s\n",nRows,error);
	fclose(fp);
}
//数据存储到文本文件
void SaveToTxtFile(List* lst,char* fileName)
{
	FILE* fp = fopen("student.txt","w");
	if(fp == nullptr)
		return;
	TNode* p = lst->next;
	while(p)
	{
		fprintf(fp,"%s %s %d\n",p->stu.ID,p->stu.strName,p->stu.nAge);
		p = p->next;
	}
	fclose(fp);
}
//从文本文件读取数据
void ReadFromTxtFile(List* lst,char* fileName)
{
	if(lst == nullptr||fileName == nullptr)
		return;
	//将链表的数据清空
	if(lst->next)
		FreeList(lst);
	//打开文件
	FILE* fp = fopen(fileName,"r");
	//判断合法性
	if(fp == nullptr)
		return;
	char buffer[50];
	memset(buffer,0,50);
	char id[10];
	char name[20];
	int age;
	int nRows = 0;
	while(!feof(fp))
	{
		//若文件中的数据行有问题会影响到，该行以后的所有数据
		//int n = fscanf(fp,"%s%s%d",id,name,&age);
		//if(n<0)
		//	break;
		//AddFirst(lst,id,name,age);
		//改进，若文件出错，针对出错的行处理，不影响其他行数据
		char * result = fgets(buffer,50,fp);
		if(result==NULL)
			break;
		int n = sscanf(buffer,"%s%s%d",id,name,&age);
		nRows++;
		if(n==3)
			AddFirst(lst,id,name,age);
		else
		{
			SaveErrorToTxtFile(buffer,nRows);//出错处理
		}
	}
	fclose(fp);
}
//数据存储到二进制文件
void WriteToBinaryFile(List* lst,char* fileName)
{
	if(lst == nullptr || fileName == nullptr)
		return;
	FILE* fp = fopen("stu.txt","wb");
	if(fp == nullptr)
		return;
	TNode* p = lst->next;
	TempNodeData data;
	while(p)
	{
		//将链表节点的信息赋值到临时的data结构体中
		memset(&data,0,sizeof(data));
		strcpy(data.ID,p->stu.ID);
		strcpy(data.strName,(p->stu.strName == nullptr)?"":p->stu.strName);
		data.nAge = p->stu.nAge;
		//写入data
		fwrite(&data,sizeof(data),1,fp);
		p = p->next;
	}
	fclose(fp);
}
//从二进制文件读取数据
void ReadFromBinaryFile(List* lst,char* fileName)
{
	if(lst == nullptr || fileName == nullptr)
		return;
	//链表不空，要清空数据
	if(lst->next)
		FreeList(lst);
	//打开文件
	FILE* fp = fopen(fileName,"rb");
	if(fp == nullptr)
		return;
	//
	TempNodeData data;
	while( !feof(fp) )
	{
		int nReturn = fread(&data,sizeof(data),1,fp);
		if(nReturn >0)
			AddLast(lst,data.ID,data.strName,data.nAge);
	}
	fclose(fp);
}
