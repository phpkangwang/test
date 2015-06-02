#include "stdafx.h"
#include "Student.h"
bool Student::operator==(Student& stu)
{
	if(this->ID == stu.ID)
		return true;
	return false;
}

ostream& operator<<(ostream& os,Student& stu)
{
	os<<stu.ID<<" "<<stu.Name<<" "<<stu.nAge; 
	return os;
}

istream& operator>>(istream& is,Student& stu)
{
	is>>stu.ID>>stu.Name>>stu.nAge; 
	return is;
}
Student::Student(string id,string name,int age)
{
	ID = id;
	Name = name;
	nAge = age;
}