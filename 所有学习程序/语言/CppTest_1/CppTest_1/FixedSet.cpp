#include "StdAfx.h"
#include "FixedSet.h"
#include<iostream>
using namespace std;

CFixedSet::CFixedSet(void)
{
	m_nCount = 0;
}

CFixedSet::~CFixedSet(void)
{
}


void CFixedSet::Print(void)
{
	if(m_nCount <= 0)
		return;
	cout<<"{";
	for(int i =0;i <m_nCount-1;i++)
		cout<<m_nBuf[i]<<",";
	cout<<m_nBuf[m_nCount -1]<<"}"<<endl;
}

ostream& operator<<(ostream& os,CFixedSet& set)
{
	if(set.m_nBuf>0)
	{
		os<<"{";
		for(int i = 0;i<set.m_nCount-1;i++)
			os<<set.m_nBuf[i]<<",";
		os<<set.m_nBuf[set.m_nCount -1]<<"}"<<endl;
	}
	return os;
}

void CFixedSet::AddData(int data)
{
	//是否满，是否存在
	if( IsFull() || IsExist(data) )
		return;
	//添加
	m_nBuf[m_nCount] = data;
	m_nCount++;
}

void CFixedSet::DeleteData(int data)
{
	if(!IsExist(data))
		return;
	for(int i =0;i <m_nCount; i++)
		if(m_nBuf[i] == data)
		{
			for(int j=i;j<m_nCount -1;j++)
				m_nBuf[j] = m_nBuf[j+1];
			m_nCount--;
			break;
		}
}

bool CFixedSet::IsExist(int n)
{
	for(int i =0;i<m_nCount;i++)
		if(m_nBuf[i] == n)
			return true;
	return false;
}


bool CFixedSet::IsFull(void)
{
	return m_nCount == NUMBER;
}

int& CFixedSet::operator[](int index)
{
	return m_nBuf[index];
}
