// CppTest_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"FixedSet.h"
#include"Plural.h"

void m()
{
	ofstream ofs("ofstream.txt");
    if (!ofs.bad())
    {
        ofs << "Writing to a basic_ofstream object..." << endl;
		ofs.close();
    }
}


template<typename T1,typename T2>
class Sum
{
public:
	Sum(T1 a,T2 b);
public:
	T1 Add();
private:
	T1 n;
	T2 m;
};
template<typename T1,typename T2>
Sum<T1,T2>::Sum(T1 a,T2 b)
{
	n = a;
	m = b;
}

template<typename T1,typename T2>
T1 Sum<T1,T2>::Add()
{
	return m+n;

}

int _tmain(int argc, _TCHAR* argv[])
{
	Sum<int,double> a(10,9.5);
	//int n = a.Add();
	double m = a.Add();
	return 0;
}

