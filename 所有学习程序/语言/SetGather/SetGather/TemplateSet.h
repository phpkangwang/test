#pragma once
#include<iostream>
#include<string>
using namespace std;


class Stu
{
public:
	Stu(){}
	Stu(string id,string name,int age);
	friend ostream& operator<<(ostream& os,Stu& stu);
	friend bool operator==(Stu& stu1,Stu& stu2);
	friend bool DeleteById(Stu& stu1,Stu& stu2);
	friend bool DeleteByName(Stu& stu1,Stu& stu2);
public:
	string GetId()
	{
		return this->id;
	}
	string GetName()
	{
		return this->name;
	}
private:
	string id;
	string name;
	int age;
};

bool DeleteById(Stu& stu1,Stu& stu2)
{
	return stu1.id == stu2.id;
}

bool DeleteByName(Stu& stu1,Stu& stu2)
{
	return stu1.name == stu2.name;
}

ostream& operator<<(ostream& os,Stu& stu)
{
	os<<stu.id<<" "<<stu.name<<" "<<stu.age<<endl;
	return os;
}

bool operator==(Stu& stu1,Stu& stu2)
{
	return stu1.id == stu2.id;
}

Stu::Stu(string id,string name,int age)
{
	this->age = age;
	this->id = id;
	this->name = name;
}

//==================================
typedef bool (*CMP)(void* );
template<class T,int MAX_COUNT = 10>
class TemplateSet
{
public:
	TemplateSet(void);
public:
	bool IsExist(T data);
	bool IsFull();
	void AddData(T data);
	void Print();
public:
	void MoveByIndex(int i);
	void DeleteData(T data);
	void DeleteIf(CMP cmp);
	template<class _Predict>
	void DeleteIfEx(_Predict cmp)
	{
		for(int i =0;i <nCount;i++)
			if( cmp(m_buf[i]) )
			{
				MoveByIndex(i);
				i--;
			}
	}


	template<class _Predict>
	void Delete(T data,_Predict cmp)
	{
		for(int i =0;i <nCount;i++)
		{
			if( cmp(data,m_buf[i]) )
			{
				MoveByIndex(i);
				break;
			}
		}
	}

private:
	T m_buf[MAX_COUNT];
	int nCount;
};

template<class T,int MAX_COUNT>
void TemplateSet<T,MAX_COUNT>::MoveByIndex(int i)
{
	for(int j =i;j<nCount-1;j++)
		m_buf[j] = m_buf[j+1];
	int len = sizeof(m_buf[nCount]);
	memset(&m_buf[nCount-1],0,len);
	nCount--;
}

template<class T,int MAX_COUNT>
void TemplateSet<T,MAX_COUNT>::DeleteIf(CMP cmp)
{
	for(int i =0;i<nCount;)
	{
		if( cmp(&m_buf[i]) )
			MoveByIndex(i);
		else
			i++;
	}
}


template<class T,int MAX_COUNT>
TemplateSet<T,MAX_COUNT>::TemplateSet(void)
{
	this->nCount = 0;
}

template<class T,int MAX_COUNT>
void TemplateSet<T,MAX_COUNT>::DeleteData(T data)
{
	for(int i =0;i <nCount;i++)
	{
		if(data == m_buf[i])
		{
			MoveByIndex(i);
			break;
		}
	}
}

template<class T,int MAX_COUNT>
bool TemplateSet<T,MAX_COUNT>::IsExist( T data)
{
	for(int i =0;i<nCount;i++)
		if(m_buf[i] == data)
			return true;
	return false;
}

template<class T,int MAX_COUNT>
bool TemplateSet<T,MAX_COUNT>::IsFull()
{
	return MAX_COUNT == nCount;
}

template<class T,int MAX_COUNT>
void TemplateSet<T,MAX_COUNT>::AddData(T data)
{
	if(IsExist(data) || IsFull() )
		return;
	m_buf[nCount] = data;
	nCount ++;
}

template<class T,int MAX_COUNT>
void TemplateSet<T,MAX_COUNT>::Print()
{
	for(int i =0;i<nCount;i++)
		cout<<m_buf[i]<<" ";
}

bool DeleteEven(void* data)
{
	return ( *((int*)data) % 2 == 0);
}

bool DeleteOdd(void* data)
{
	return ( *((int*)data) % 2 == 1);
}

bool DelEven(int data)
{
	return data % 2 == 0;
}

bool DelOdd(int data)
{
	return data % 2 == 1;
}


//bool DelByID(void* data)
//{
//
//}

bool DelNameBegin(void* data)
{
	Stu p = *(Stu*) data;
	string name = p.GetName();
	string request = "уе";
	string lefts = name.substr(0,request.length());
	return request == lefts;

}

bool DeleteStrSome(void* data)
{
	string str = *(string*)data;
	return str.find("23") != string::npos;
}