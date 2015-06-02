// CinCout.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void Cout()
{
	/*bool b = true;
	cout<<b<<endl;
	cout<<boolalpha<<b<<endl;*/

	//cout<<left;//对齐方式
	//cout.width(10);//显示宽度
	//cout<<"13517";
	//cout.width(10);
	//cout<<"孙浩";
	//cout.width(4);
	//cout<<22<<endl;

	cout<<23<<endl;//默认十进制输出 dec
	cout<<hex<<uppercase<<28<<endl;//十六进制输出
	cout<<oct<<23<<endl;//八进制输出

	/*cout.width(10);
	cout<<"13518";
	cout.width(10);
	cout<<"张宏杰";
	cout.width(4);
	cout<<22;*/
}

void Cin()
{

}


int _tmain(int argc, _TCHAR* argv[])
{
	ofstream ofs;
	ofs.open("sunhao.txt");
	if(!ofs.is_open())
		return -1;
	if(!ofs.bad())
	{
		ofs<<"孙浩"<<endl;
		ofs<<"我正在学习"<<endl;
		ofs<<"我喜欢编程"<<endl;
		ofs.close();
	}
		string ss;
	ifstream ifs("sunhao.txt");
	if(!ifs.is_open())
		return -1;
	char buf[20];
	if(!ifs.bad())
	{
		getline(cin,ss);
		ifs>>buf;
		ifs.close();
	}
	cout<<buf<<endl;



	istringstream iss;


	return 0;
}

