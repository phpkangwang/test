#pragma once
#include "stdafx.h"
#include "NodeList.h"


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