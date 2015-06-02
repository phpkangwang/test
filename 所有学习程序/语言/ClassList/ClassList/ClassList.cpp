// ClassList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//
#pragma warning(disable:4996)//消除4996警告
//

class CNode
{
	friend class CList;
	CNode();
	CNode(char* id,char* name,char* gender,int age);
	~CNode();
	friend ostream& operator<<(ostream& os,CNode& node);
private:
	char ID[10];
	char* strName;
	char Gender[3];
	int nAge;
private:
	CNode* next;
};

CNode::CNode()
{
	memset(ID,0,strlen(ID));
	this->strName = nullptr;
	memset(Gender,0,strlen(Gender));
	nAge = -1;
	next = nullptr;
}
CNode::CNode(char*id,char* name,char* gender,int age)
{
	strcpy(ID,id);
	if(name == nullptr)
		strName = nullptr;
	else
	{
		int nLen = strlen(name)+ 1;
		strName = new char[nLen];
		strcpy(strName,name);
	}
	strcpy(Gender,gender);
	nAge = age;
	next = nullptr;
}
CNode::~CNode()
{
	if(strName)
	{
		delete[] strName;
		strName =nullptr;
	}
}
ostream& operator<<(ostream& os,CNode& node)
{
	os<<node.ID<<" "<<node.strName<<" "<<node.Gender<<" "<<node.nAge;
	return os;
}
//==========================
class CList
{
public:
	CList();
	~CList();
public:
	void AddFirst(char*id,char* name,char* gender,int age);
	void AddLast(char*id,char* name,char* gender,int age);
public:
	CNode* GetLastNode();
	CNode* GetNextNode();
public:
	void SaveToFile(CList& lst);
	void ReadFromFile(CList& lst);
	friend ostream& operator<<(ostream& os,CList& lst);
private:
	CNode head;
	CNode* pFlag;
};
void CList::ReadFromFile(CList& lst)
{
	//
	if(lst.head.next)
	{
		cout<<"123";
	}
	else
	{
		ifstream ifs("student.txt");
		char buffer[50];
		while(!ifs.bad())
		{
			ifs.getline(buffer,50);
		}
		ifs.close();
	}
}

void CList::SaveToFile(CList& lst)
{
	ofstream ofs("student.txt");
	while(!ofs.bad())
	{
		ofs<<lst<<endl;
	}
	ofs.close();
}

CNode* CList::GetNextNode()
{
	if(pFlag == nullptr)
		pFlag = nullptr;
	else
		pFlag = pFlag->next;
	return pFlag;
}

ostream& operator<<(ostream& os,CList& lst)
{
	CNode* p = lst.GetNextNode();
	while(p)
	{
		os<<*p<<endl;
		p = lst.GetNextNode();
	}
	return os;
}

CList::CList()
{
	pFlag = &head;
}
CList::~CList()
{
	CNode* p = head.next;
	head.next = nullptr;
	while(p)
	{
		CNode* del = p;
		p = p->next;
		delete del;
	}
}

CNode* CList::GetLastNode()
{
	CNode* p = &head;
	while(p->next)
		p = p->next;
	return p;
}

void CList::AddLast(char*id,char* name,char* gender,int age)
{
	//节点分配空间
	CNode* node = new CNode(id,name,gender,age);
	//插入操作
	CNode* p = GetLastNode();
	p->next = node;
}

void  CList::AddFirst(char*id,char* name,char* gender,int age)
{
	//节点分配空间
	CNode* node = new CNode(id,name,gender,age);
	//插入操作
	node->next = head.next;
	head.next = node;
}


int _tmain(int argc, _TCHAR* argv[])
{
	CList lst;
	//lst.AddFirst("13517","孙浩","男",23);
	//lst.AddFirst("13518","张宏杰","女",23);
	//lst.AddFirst("13519","张卫卫","男",24);
	//lst.AddFirst("13520","张盼盼","男",22);
	//lst.AddLast("13521","张","男",22);
	//cout<<lst;
	lst.ReadFromFile(lst);
	lst.SaveToFile(lst);
	return 0;
}

