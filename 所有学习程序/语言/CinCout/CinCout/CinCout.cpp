// CinCout.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//cout<<left;//���뷽ʽ
	//cout.width(10);//��ʾ���
	//cout<<"13517";
	//cout.width(10);
	//cout<<"���";
	//cout.width(4);
	//cout<<22<<endl;

	cout<<23<<endl;//Ĭ��ʮ������� dec
	cout<<hex<<uppercase<<28<<endl;//ʮ���������
	cout<<oct<<23<<endl;//�˽������

	/*cout.width(10);
	cout<<"13518";
	cout.width(10);
	cout<<"�ź��";
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
		ofs<<"���"<<endl;
		ofs<<"������ѧϰ"<<endl;
		ofs<<"��ϲ�����"<<endl;
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

