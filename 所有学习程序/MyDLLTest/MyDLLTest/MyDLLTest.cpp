// MyDLLTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyDLL.h"
using namespace mydll;
#include<cstring>

#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	CMyDLL dll;
	int d = 5;
	int m = dll.Inc(d);
	cout<<m<<" "<<d<<endl;
	return 0;
}

