#pragma once
#include"stdafx.h"
class Student
{
	friend ostream& operator<<(ostream& os,Student& stu);
	friend istream& operator>>(istream& is,Student& stu);
public:
	Student(void);
	~Student(void);
private:
	char ID[10];
	char* strName;
	int nAge;
public:
	Student(char* id,char* name,int age);
};

