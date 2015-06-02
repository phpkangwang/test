// S-ringDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	string s = "123456";
	size_t n = 2;
	int m= stoi(s,&n);


	//string line = "My Name Is Sun";//"我的名字叫张红姐";
	//string::iterator first = line.begin();
	//string::iterator last = line.end();
	//string::iterator p = first;
	////遍历line中的字符  
	//for(;p<last;p++)
	//	cout<<*p;
	//string::reference rf = line.at(0);
	////rf = 'p';	// 等价于 line.at(0)='p';
	//while(p != line.end())
	//{
	//	cout<<*p;
	//	p++;
	//}
	//string::size_type Len = line.length();
	//int len = line.size();
	//for(string::size_type i = 0;i < Len;i++)
	//	cout<<line.at(i)<<line[i];
	
	/*	wchar_t temp ;
	wstring s = (L"嗨，我的名字叫孙浩");
	wstring::iterator first = s.begin();
	wstring::iterator last = s.end();

	wstring::iterator p = first;
	char c;
	for(;p<last;p++)
		 temp = *p;*/
	/*wstring::size_type len = s.length();
	for(wstring::size_type i = 0;i<len;i++)
	wcout<<L"SUNHAO"<<s.at(i);*/

	//vector<int> iv;
	//int a;
	//do
	//{
	//	cin>>a;
	//	iv.push_back(a);
	//}while(a<10);

	///*for(vector<int>::size_type i = 0;i<iv.size();i++)
	//	cout<<iv[i];
	//cout<<endl;
	//for(vector<int>::iterator p = iv.begin(); p<iv.end();p++)
	//	cout<<*p;*/

	//iv.pop_back();

	return 0;
}