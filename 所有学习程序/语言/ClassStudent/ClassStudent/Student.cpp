#include "StdAfx.h"
#include "Student.h"



Student::Student(void)
{
}


Student::~Student(void)
{
	if(strName == nullptr)
		return;
	delete[] strName;
}

Student::Student(char* id,char* name,int age)
{
	strcpy(ID,id);
	if(name == nullptr)
	{
		strName = new char[5]; 
		strcpy(strName,"null");
	}
	else
	{
		int nLen = strlen(name) +1;
		strName = new char[nLen];
		strcpy(strName,name);
	}
	nAge = age;
}

ostream& operator<<(ostream& os,Student& stu)
{
	if(stu.ID)
		os<<stu.ID<<" ";
	if(stu.strName)
		os<<stu.strName<<" ";
	os<<stu.nAge<<endl;
	return os;

}

istream& operator>>(istream& is,Student& stu)
{
	is>>stu.ID>>stu.strName>>stu.nAge;
	return is;

}

