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

//函数返回-1表示参数非法，0表示成功
//插入到头结点之后
bool NodeIsExist(List* lst,char* id);
//构造新节点
TNode* MakeNode(char* id,char* name,int age);
int AddFirst(List* lst,char* id,char* name,int age);
//找到尾部节点
TNode* GetLastNode(List* lst);
//插入到尾部
int AddLast(List* lst,char* id,char* name,int age);
//插入到指定位置
int AddAppoint(List* lst,char* addid,char* id,char* name,int age);
//删除某一个节点
int DeleteNode(List* lst,char* id);
//清空链表
void FreeList(List* lst);
//显示链表
int ShowList(List* lst);
//求链表节点数
int Count(List* lst);
//按学号进行排序
void OrderList(List* lst);
//冒泡排序
int BubbleSort(List* lst,char* Method);
//将错误存储到文件
void SaveErrorToTxtFile(char* error,int nRows);
//数据存储到文件
void SaveToTxtFile(List* lst,char* fileName);
//从文件读取数据
void ReadFromTxtFile(List* lst,char* fileName);
//
void WriteToBinaryFile(List* lst,char* fileName);
//
void ReadFromBinaryFile(List* lst,char* fileName);

#endif