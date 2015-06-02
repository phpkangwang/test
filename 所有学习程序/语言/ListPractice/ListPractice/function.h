#ifndef __FUNCYION_H__
#define __FUNCYION_H__
struct Student
{
	char ID[10];
	char* strName;
	int nAge;
};
typedef Student Stu;

struct TNode
{
	Stu stu;
	TNode* next;
};

struct TempNodeData
{
	char ID[10];
	char strName[20];
	int nAge;
};
typedef TNode List;
typedef TNode* PList;

//��������-1��ʾ�����Ƿ���0��ʾ�ɹ�
//���뵽ͷ���֮��
bool NodeIsExist(List* lst,char* id);
//�����½ڵ�
TNode* MakeNode(char* id,char* name,int age);
int AddFirst(List* lst,char* id,char* name,int age);
//�ҵ�β���ڵ�
TNode* GetLastNode(List* lst);
//���뵽β��
int AddLast(List* lst,char* id,char* name,int age);
//���뵽ָ��λ��
int AddAppoint(List* lst,char* addid,char* id,char* name,int age);
//ɾ��ĳһ���ڵ�
int DeleteNode(List* lst,char* id);
//�������
void FreeList(List* lst);
//��ʾ����
int ShowList(List* lst);
//������ڵ���
int Count(List* lst);
//��ѧ�Ž�������
void OrderList(List* lst);
//ð������
int BubbleSort(List* lst,char* Method);
//������洢���ļ�
void SaveErrorToTxtFile(char* error,int nRows);
//���ݴ洢���ļ�
void SaveToTxtFile(List* lst,char* fileName);
//���ļ���ȡ����
void ReadFromTxtFile(List* lst,char* fileName);
//
void WriteToBinaryFile(List* lst,char* fileName);
//
void ReadFromBinaryFile(List* lst,char* fileName);

#endif