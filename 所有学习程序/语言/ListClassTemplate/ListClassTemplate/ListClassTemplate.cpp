// ListClassTemplate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class Student
{
public:
	Student(string id,string name,int age);
	Student()
	{
	}
	Student(string id,string name)
	{
		ID = id;
		Name = name;
	}
public:
	bool operator==(Student& stu);
	friend ostream& operator<<(ostream& os,Student& stu);
	friend istream& operator>>(istream& is,Student& stu);
	friend bool DeleteById(Student& stu1,Student& stu2)
	{
		return (stu1.ID == stu2.ID);
	}

	friend bool DeleteByIName(Student& stu1,Student& stu2)
	{
		return (stu1.Name == stu2.Name);
	}
private:
	string ID;
	string Name;
	int nAge;
};

bool Student::operator==(Student& stu)
{
	if(stu.ID == "")
		return (this->Name == stu.Name);
	else
		return (this->ID == stu.ID);	
}

ostream& operator<<(ostream& os,Student& stu)
{
	//os<<stu.ID<<" "<<stu.Name<<" "<<stu.nAge;
	os<<left;
	os.width(10);
	os<<stu.ID;
	os.width(10);
	os<<stu.Name;
	os.width(4);
	os<<stu.nAge;
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
template <class T> class CList;
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
//==================================
template <class T>
class InterFaceList
{
public:
	virtual void AddFirst(T data) = 0;
	virtual void AddLast(T data) = 0;
	virtual void DeleteNode(T data) = 0;
	virtual void FreeList() = 0;
	virtual void ShowList() = 0;
	virtual bool FindNode(T data) = 0;
	virtual void SaveToFile() = 0;
	virtual void ReadFromFile() = 0;
};
//===============================
template <class T>
class CList : public InterFaceList<T>
{
public:
	CList()
	{
		pFlag = &head;
	}

	~CList();
public:
	void AddFirst(T data);
	void FreeList();
	void AddLast(T data);
	void DeleteNode(T data);
public:
	template <class _Predict>
	void Delete(T data,_Predict cmp)
	{
		CNode<T>* p = &head;
		while(p)
		{
			if(cmp(p->next->m_data,data))
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
	void ShowList();
	bool FindNode(T data);
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

//CList��������
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

//�������
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
//�õ���һ���ڵ�
template <class T>
CNode<T>* CList<T>::GetNextNode()
{
	if(pFlag == nullptr)
		pFlag = &head;
	pFlag = pFlag->next;
	return pFlag;
}
//�ҵ��ڵ�
template <class T>
bool CList<T>::FindNode(T data)
{
	CNode<T>* p = &head;
	p = p->next;
	while(p)
	{
		if(p->m_data == data)
			return true;
		p = p->next;
	}
	return false;
}
//ɾ��ĳ���ڵ�
template <class T>
void CList<T>::DeleteNode(T data)
{
	if(FindNode(data) == false)
	{
		cout<<"������"<<endl;
		return;
	}
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

//��ӵ�ͷ�ڵ�
template <class T>
void CList<T>::AddFirst(T data)
{
	//�ڵ����ռ�
	CNode<T>* node = new CNode<T>(data);
	//�������
	node->next = head.next;
	head.next = node;
}
//�õ�β���ڵ�
template <class T>
CNode<T>* CList<T>::GetLastNode()
{
	CNode<T>* LastNode = &head;
	//
	while(LastNode->next)
		LastNode = LastNode->next;
	return LastNode;
}
//��ӵ�β���ڵ�
template <class T>
void CList<T>::AddLast(T data)
{
	//�ڵ����ռ�
	CNode<T>* node = new CNode<T>(data);
	//�ҵ����ڵ�
	CNode<T>* p = GetLastNode();
	//�������
	p->next = node;
}

//��ʾ������Ϣ
template <class T>
void CList<T>::ShowList()
{
	cout<<*this<<endl;
}

//���ݴ洢���ļ�
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
//���ļ��ж�ȡ����
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

class MyApp
{
public:
	MyApp(InterFaceList<Student>* lst);
public:
	void Run();
	void ShowMenu();
	void DoInput(int nChoose);
private:
	InterFaceList<Student>* lst;
};

MyApp::MyApp(InterFaceList<Student>* lst)
{
	this->lst = lst;
	Run();
}

void MyApp::Run()
{
	while(true)
	{
		ShowMenu();

	/*	int Choose;
		cin>>Choose;
		if(Choose == -1)
			break;
		DoInput(Choose);
*/
		string Choose;
		cin>>Choose;
		/*if(Choose.length() > 1)
		{
			cout<<"Input Error!"<<endl;
			continue;
		}*/
		int len = Choose.length();
		char* c = new char [len];
		Choose.copy(c,Choose.length());
		int temp = atoi(c);
		if(temp == -1)
			break;
		DoInput(temp);
	}
}

void MyApp::ShowMenu()
{
	string menu[]=
	{
		"1.��ӵ�ͷ��",
		"2.��ӵ�β��",
		"3.��ʾ��������",
		"4.�����������",
		"5.ɾ��ĳ��ѧ����Ϣ",
		"6.���ļ��ж�ȡ��Ϣ",
		"7.��������Ϣд�뵽�ļ�",
		"-1.�˳�����"
	};
	int nCount = 8;
	for(int i = 0;i < nCount;i++)
		cout<<menu[i]<<endl;
}
void MyApp::DoInput(int nChoose)
{
	string id,name;
	int age;
	switch(nChoose)
	{
	case 1:
		cout<<"Input<id name age>:";
		cin>>id>>name>>age;
		lst->AddFirst(Student(id,name,age));
		break;
	case 2:
		cout<<"Input<id name age>:";
		cin>>id>>name>>age;
		lst->AddLast(Student(id,name,age));
		break;
	case 3:
		lst->ShowList();
		break;
	case 4:
		lst->FreeList();
		break;
	case 5:
		cout<<"ɾ����ʽ(0.ѧ�� 1.����)";
		cin>>age;
		if(age == 0)
		{
			cout<<"Input<id>:";
			cin>>id;
			lst->DeleteNode(Student(id,""));
		}
		else
		{
			cout<<"Input<name>:";
			cin>>name;
			lst->DeleteNode(Student("",name));
		}
		break;
	case 6:
		lst->ReadFromFile();
		break;
	case 7:
		lst->SaveToFile();
	default:
		cout<<"Input Error!"<<endl;
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyApp app(new CList<Student>);

	CList<Student> stu;
	stu.AddFirst(Student("1000","1000",20));
	stu.AddFirst(Student("1001","1001",21));
	stu.AddFirst(Student("1002","1002",22));
	stu.AddFirst(Student("1003","1003",23));
	stu.Delete(Student("1000","1000",20),DeleteById);
	stu.ShowList();

	return 0;
}

