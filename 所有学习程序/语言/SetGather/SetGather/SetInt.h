#pragma once
#include<iostream>
using namespace std;

template<int MAX_COUNT = 10>
class SetInt
{
public:
	SetInt(void);
public:
	bool IsExist(int data);
	bool IsFull();
	void AddData(int data);
	void Print();
private:
	int m_buf[MAX_COUNT];
	int nCount;
};

template<int MAX_COUNT>
SetInt<MAX_COUNT>::SetInt(void)
{
	//this->m_buf;
	memset(m_buf,0,MAX_COUNT);
	this->nCount = 0;
}

template<int MAX_COUNT>
bool SetInt<MAX_COUNT>::IsExist( int data)
{
	for(int i =0;i<nCount;i++)
		if(m_buf[i] == data)
			return true;
	return false;
}

template<int MAX_COUNT>
bool SetInt<MAX_COUNT>::IsFull()
{
	return MAX_COUNT == nCount;
}

template<int MAX_COUNT>
void SetInt<MAX_COUNT>::AddData(int data)
{
	if(IsExist(data) || IsFull() )
		return;
	m_buf[nCount] = data;
	nCount ++;
}

template<int MAX_COUNT>
void SetInt<MAX_COUNT>::Print()
{
	for(int i =0;i<nCount;i++)
		cout<<m_buf[i]<<" ";
}