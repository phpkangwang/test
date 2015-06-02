// 链表遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<list>
#include<iostream>
#include<algorithm>
using namespace std;

bool RemoveEven(int data)
{
	return data%2 == 0;
}

class RemoveByCondition
{
public:
	RemoveByCondition(bool b)
	{
		IsEven = b;
	}
public:
	bool operator()(int data)
	{
		if(IsEven)
			return data % 2 == 0;
		return data % 2 == 1;
	}
private:
	bool IsEven;
};


class ListOutput
{
public:
	void operator()(int data)
	{
		cout<<data<<endl;
	}
};

//函数
void DoubleValue(int& data)
{
	data *= 2;
}
//函数对象
class doubleValue
{
public:
	void operator()(int& data)
	{
		data *= 2;
	}
};

class Count
{
public:
	Count(int data)
	{
		iCondition = data;
	}
public:
	bool operator()(int data)
	{
		return iCondition == data;
	}
private:
	int iCondition;
};

int _tmain(int argc, _TCHAR* argv[])
{
	list<int> il;
	il.push_back(1);
	il.push_back(2);
	il.push_front(15);
	il.push_back(3);
	il.push_back(4);
	il.push_back(2);

	//il.remove_if(RemoveEven);
	//il.remove_if(RemoveByCondition(false));
	int nCount = count_if(il.begin(),il.end(),Count(2));
	nCount = count(il.begin(),il.end(),3);
	for_each(il.begin(),il.end(),ListOutput());
	for_each(il.begin(),il.end(),DoubleValue);

	return 0;
}

