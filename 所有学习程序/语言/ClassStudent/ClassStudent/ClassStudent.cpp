// ClassStudent.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Student.h"

void DoInput()
{
	char id[10];
	char name[20];
	memset(id,0,10);
	memset(name,0,20);
	int age;

	do
	{
		cout<<"������ѧ�� ���� ����:";
		cin>>id>>name>>age;
		Student stu(id,name,age);

		//��Ϣд�뵽�ļ�
		ofstream ofs("student.txt",ios::app);
		if (!ofs.bad())
		{
			ofs<<stu;
			ofs.close();
		}
		cout<<"�Ƿ����:";
		cin>>name;

	}while(strcmp(name,"y")==0);

}

int _tmain(int argc, _TCHAR* argv[])
{

	//Student stu[10];
	//DoInput();

	char strBuf[50];
	ifstream ifs("student.txt",ios::app);
	if (!ifs.bad())
	{
		ifs.getline(strBuf,50);
		ifs.close();
	}
	return 0;
}

