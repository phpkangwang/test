// StydentClassTemplate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "NodeList.h"
//#include "Student.h"

#include<iostream>
using namespace std;

class Student
{
public:
	Student(string id,string name,int age);
	Student()
	{

	}
public:
	bool operator==(Student& stu);
	friend ostream& operator<<(ostream& os,Student& stu);
	friend istream& operator>>(istream& is,Student& stu);
	
private:
	string ID;
	string Name;
	int nAge;
};

bool Student::operator==(Student& stu)
{
	if(this->ID == stu.ID)
		return true;
	return false;
}

ostream& operator<<(ostream& os,Student& stu)
{
	os<<stu.ID<<" "<<stu.Name<<" "<<stu.nAge; 
	return os;
}

istream& operator>>(istream& is,Student& stu)
{
	is>>stu.ID>>stu.Name>>stu.nAge; 
	return is;
}
Student::Student(string id,string name,int age)
{
	ID = id;
	Name = name;
	nAge = age;
}

//======================

emplate <class T> class CList;
template <class T>
class CNode
{
	friend class CList<T>;
	template <class T>
	friend ostream& operator<<(ostream& os,CNode<T>& node);
	template <class T>
	friend bool operator==(CNode<T>& node1,CNode<T>& node2);
	/*template <class T>
	friend istream& operator>>(istream& is,CNode<T>& node);*/
public:
	CNode();
	CNode(T data);
	~CNode()
	{
		;
	}
private:
	T m_data;
	CNode<T>* next;
};

template <class T>
class InterfaceList
{
public:
	virtual void AddFirst(T data) = 0;
	virtual void AddLast(T data) = 0;
	//virtual void DeleteNode(T data) = 0;
	virtual void SaveToFile() = 0;
	virtual void ReadFromFile() = 0;
};
//===============================
template <class T>
class CList : public InterfaceList<T>
{
public:
	CList()
	{
		pFlag = &head;
	}

	~CList();
public:
	void AddFirst(T data);
	void AddLast(T data);
	void FreeList();
	void DeleteNode(T data);
public:
	void SaveToFile();
	void ReadFromFile();
public:
	CNode<T>* GetLastNode();
	CNode<T>* GetNextNode();
	template <class T>
	friend ostream& operator<<(ostream& os,CList<T>& lst);
	template <class T>
	friend istream& operator>>(istream& is,CList<T>& lst);
	//template <class T>
	//friend bool operator==(Clist&<T> lst1,CList<T>& lst2);
private:
	CNode<T> head;
	CNode<T>* pFlag;
};

template <class T>
ostream& operator<<(ostream& os,CNode<T>& node)
{
	os<<node.m_data;
	return os;
}

template <class T>
bool operator==(CNode<T>& node1,CNode<T>& node2)
{
	if(node1 == node2)
		return true;
	return false;
}

//template <class T>
//istream& operator>>(istream& is,CNode<T>& node)
//{
//	is>>node.m_data;
//	return is;
//}

template <class T>
CNode<T>::CNode()
{
	next = nullptr;
}

template <class T>
CNode<T>::CNode(T data)
{
	this->m_data = data;
	next = nullptr;
}
//===============================
template <class T>
ostream& operator<<(ostream& os,CList<T>& lst)
{
	CNode<T>* p = lst.GetNextNode();
	while(p)
	{
		os<<*p<<endl;
		p = lst.GetNextNode();
	}
	return os;
}

template <class T>
istream& operator>>(istream& is,CList<T>& lst)
{
	T data;
	while(is>>data)
	{
		lst.AddLast(data);
	}
	return is;
}

//CList析构函数
template <class T>
CList<T>::~CList()
{
	CNode<T>* p = head.next;
	head.next = nullptr;
	while(p)
	{
		CNode<T>* del = p;
		p = p->next;
		delete del;
	}
}
//清空链表
template <class T>
void CList<T>::FreeList()
{
	CNode<T>* p = &head;
	head.next = nullptr;
	while(p->next)
	{
		CNode<T>* del = p->next;
		p = p->next;
		delete del;
	}
}

template <class T>
CNode<T>* CList<T>::GetNextNode()
{
	if(pFlag == nullptr)
		pFlag = &head;
	pFlag = pFlag->next;
	return pFlag;
}

template <class T>
void CList<T>::DeleteNode(T data)
{
	if(head.next == nullptr)
		return;
	CNode<T>* p = &head;
	while(p)
	{
		if(p->next->m_data == data)
		{
			CNode<T>* del = p->next;
			p->next = del->next;
			delete del;
			break;
		}
		else
			p = p->next;
	}
}

//添加到头节点
template <class T>
void CList<T>::AddFirst(T data)
{
	//节点分配空间
	CNode<T>* node = new CNode<T>(data);
	//插入操作
	node->next = head.next;
	head.next = node;
}
//得到尾部节点
template <class T>
CNode<T>* CList<T>::GetLastNode()
{
	CNode<T>* LastNode = &head;
	//
	while(LastNode->next)
		LastNode = LastNode->next;
	return LastNode;
}
//添加到尾部节点
template <class T>
void CList<T>::AddLast(T data)
{
	//节点分配空间
	CNode<T>* node = new CNode<T>(data);
	//找到最后节点
	CNode<T>* p = GetLastNode();
	//插入操作
	p->next = node;
}
//数据存储到文件
template <class T>
void CList<T>::SaveToFile()
{
	if(head.next == nullptr)
		return;
	ofstream ofs("StuInfo.txt");
	if(!ofs.bad())
	{
		ofs<<*this;
		ofs.close();
	}
}
//从文件中读取数据
template <class T>
void CList<T>::ReadFromFile()
{
	ifstream ifs("StuInfo.txt");
	if(!ifs.bad())
	{
		ifs>>*this;
		ifs.close();
	}
}

//==============================

int _tmain(int argc, _TCHAR* argv[])
{

	CList<Student> lst1;
	lst1.AddFirst(Student("13517","孙浩",23));
	lst1.AddFirst(Student("13518","张宏杰",23));
	lst1.AddFirst(Student("13507","王子奇",21));
	lst1.AddLast(Student("13519","张卫卫",24));
	lst1.AddLast(Student("13520","张盼盼",22));
	lst1.DeleteNode(Student("13507","王子奇",21));
	//lst1.SaveToFile();
	//lst1.ReadFromFile();
	//cout<<"Input id name age(end with(Ctrl+Z)):";
	//cin>>lst1;
	cout<<lst1;
	/*InterfaceList<int>* IList= new CList<int>();
	IList->AddFirst(1);
	IList->AddFirst(2);
	IList->AddFirst(3);
	IList->AddFirst(4);
	IList->SaveToFile();
	IList->ReadFromFile();*/

	/*CList<int> lst;
	lst.AddFirst(1);
	lst.AddFirst(2);
	lst.AddFirst(3);
	lst.AddFirst(4);
	lst.DeleteNode(2);
	cout<<lst;*/
	return 0;
}

