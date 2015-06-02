#include "stdafx.h"
class Student
{
public:
	Student(string id,string name,int age);
	Student()
	{

	}
public:
	bool operator==(Student& stu);
	friend ostream& operator<<(ostream& os,Student& stu);
	friend istream& operator>>(istream& is,Student& stu);
	
private:
	string ID;
	string Name;
	int nAge;
};