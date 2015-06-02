// ClassTest_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "header1.h"

class Person
{
public:
	void SetName(char* name);
	void SetAge(int age);
	void SetHeight(int height);
public:
	char* GetName();
	int GetAge();
	int GetHeight();
protected:
	char* strName;
	int nAge;
	int nHeight;
};

void Person::SetName(char* name)
{
	if(name == nullptr)
		this->strName = nullptr;
	else
	{
		int nLen = strlen(name)+ 1;
		this->strName = new char[nLen];
		strcpy(this->strName,name);
	}
}

void Person::SetAge(int age)
{
	this->nAge = age;
}

void Person::SetHeight(int height)
{
	this->nHeight = height;
}

char* Person::GetName()
{
	return this->strName;
}

int Person::GetAge()
{
	return this->nAge;
}

int Person::GetHeight()
{
	return this->nHeight;
}

class Student:public Person
{
protected:
	char id[10];
public:
};



int _tmain(int argc, _TCHAR* argv[])
{
	//StudentCount stu1;
	//StudentCount stu2;
	//StudentCount stu3;
	//int n = StudentCount::GetnCount();

	return 0;
}

