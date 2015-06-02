// ClassStudent.cpp : 定义控制台应用程序的入口点。
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
		cout<<"请输入学号 姓名 年龄:";
		cin>>id>>name>>age;
		Student stu(id,name,age);

		//信息写入到文件
		ofstream ofs("student.txt",ios::app);
		if (!ofs.bad())
		{
			ofs<<stu;
			ofs.close();
		}
		cout<<"是否继续:";
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

