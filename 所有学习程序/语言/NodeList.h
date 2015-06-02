#pragma once
#include "stdafx.h"

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
