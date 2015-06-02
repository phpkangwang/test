#pragma once //±‡“Î“ª¥Œ
#define NUMBER 20
#include "stdafx.h"
class CFixedSet
{
	friend ostream& operator<<(ostream& os,CFixedSet& set);
public:
	CFixedSet(void);
	~CFixedSet(void);
private:
	int m_nBuf[NUMBER];
	int m_nCount;
public:
	void Print(void);
public:
	void AddData(int data);
	void DeleteData(int data);
	bool IsExist(int n);
	bool IsFull(void);
public:
	int& operator[](int index);
};

