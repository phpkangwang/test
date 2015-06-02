#include"stdafx.h"
#include"function.h"

#pragma warning(disable:4996)//����4996����

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

//�����½��
TNode* MakeNode(char* id,char* name,int age)
{
	//�ڵ����ռ�
	TNode* node = new TNode;
	//�ڵ���Ϣ��ֵ
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
//��ӵ�ͷ���
int AddFirst(List* lst,char* id,char* name,int age)
{
	if(lst == nullptr || id == nullptr)
		return -1;
	if(NodeIsExist(lst,id))
	{
		printf("��ѧ�Ŵ���!\n");
		return -1;
	}
	//ִ�в������
	TNode* pNode = MakeNode(id,name,age);
	pNode->next = lst->next;
	lst->next = pNode;
	return 0;
}
//�ҵ�β�����
TNode* GetLastNode(List* lst)
{
	TNode* p = lst;
	while(p->next !=NULL)
		p = p->next;
	return p;
}
//���뵽β��
int AddLast(List* lst,char* id,char* name,int age)
{
	if(id == nullptr)
		return -1;
	if(NodeIsExist(lst,id))
	{
		printf("��ѧ�Ŵ���!\n");
		return -1;
	}
	//�ڵ����ռ�
	TNode* pNode = MakeNode(id,name,age);
	//�ҵ����һ���ڵ�
	TNode* LastNode = GetLastNode(lst);
	//ִ�в������
	LastNode->next = pNode;
	return 0;
}
//���뵽ָ��λ��
int AddAppoint(List* lst,char* addid,char* id,char* name,int age)
{
	if(lst == NULL || addid == NULL || id == NULL)
		return -1;
	//ѧ���Ƿ����
	if(NodeIsExist(lst,id))
	{
		printf("��ѧ�Ŵ���!\n");
		return -1;
	}
	//�ڵ����ռ�
	TNode* pNode = MakeNode(id,name,age);
	//�ҵ�ָ���ڵ�,�ж�����ڵ��Ƿ�Ϸ�
	TNode* p = lst->next;
	int nFlag = 0;
	while(p != NULL)
	{
		if(strcmp(p->stu.ID,addid)==0)//�ҵ�ָ���ڵ��ǰһ���ڵ�
		{
			nFlag = 1;
			break;
		}
		p = p->next;
	}
	if(nFlag == 0)//����Ľڵ㲻����
		return -1;
	//����ָ���ڵ��ǰ��
	pNode->next = p->next;
	p->next = pNode;
	//����ָ���ڵ�֮��
	return 0;
}
//ɾ��ĳһ���ڵ�
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
//�������
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
//��ʾ����
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
//������ڵ���
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
//��ѧ�Ž�������
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
//ð������
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
	fprintf(fp,"��%d�������д���!%s\n",nRows,error);
	fclose(fp);
}
//���ݴ洢���ı��ļ�
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
//���ı��ļ���ȡ����
void ReadFromTxtFile(List* lst,char* fileName)
{
	if(lst == nullptr||fileName == nullptr)
		return;
	//��������������
	if(lst->next)
		FreeList(lst);
	//���ļ�
	FILE* fp = fopen(fileName,"r");
	//�жϺϷ���
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
		//���ļ��е��������������Ӱ�쵽�������Ժ����������
		//int n = fscanf(fp,"%s%s%d",id,name,&age);
		//if(n<0)
		//	break;
		//AddFirst(lst,id,name,age);
		//�Ľ������ļ�������Գ�����д�����Ӱ������������
		char * result = fgets(buffer,50,fp);
		if(result==NULL)
			break;
		int n = sscanf(buffer,"%s%s%d",id,name,&age);
		nRows++;
		if(n==3)
			AddFirst(lst,id,name,age);
		else
		{
			SaveErrorToTxtFile(buffer,nRows);//������
		}
	}
	fclose(fp);
}
//���ݴ洢���������ļ�
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
		//������ڵ����Ϣ��ֵ����ʱ��data�ṹ����
		memset(&data,0,sizeof(data));
		strcpy(data.ID,p->stu.ID);
		strcpy(data.strName,(p->stu.strName == nullptr)?"":p->stu.strName);
		data.nAge = p->stu.nAge;
		//д��data
		fwrite(&data,sizeof(data),1,fp);
		p = p->next;
	}
	fclose(fp);
}
//�Ӷ������ļ���ȡ����
void ReadFromBinaryFile(List* lst,char* fileName)
{
	if(lst == nullptr || fileName == nullptr)
		return;
	//�����գ�Ҫ�������
	if(lst->next)
		FreeList(lst);
	//���ļ�
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
