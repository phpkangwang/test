// test004.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/* ָ��
typedef unsigned short int ut;
int main(int argc, char* argv[])
{
	ut i;
	ut* p;
	p=&i;
	cout<<i<<endl;
	cout<<*p<<endl;
	*p=90;
	cout<<i<<endl;
	cout<<*p<<endl;
	i=5;
	cout<<i<<endl;
	cout<<*p<<endl;
	return 0;
}
*/

/*
   new��ʹ��

int main(){
    int *p=new int;
	*p=4;
	cout<<*p<<endl;
	delete p;
	cout<<p<<endl;
	cout<<*p<<endl;
	return 0;
}
*/

/*
   �ڴ�й¶

int main(){
    int *p=new int;
	cout<<p<<endl;
	cout<<*p<<endl;
	p=new int;
	cout<<p<<endl;
	cout<<*p<<endl;
	return 0;
}
*/
/*��ĳ�ʼ��
class A
{
public:
	A(){
		cout<<"aaaaaa\n";i=999;
	}
private:
	int i;
};
int main(){
	A* p=new A;
	return 0;
}
*/
/*ָ�����ĸ�ֵȡֵ
class A
{
public:
	int get() const{return i;}
		void set(int x){i=x;}
private:
	int i;
};
int main(){
	A* a=new A;
	a->set(1);
	cout<<a->get()<<endl;
	delete a;
	return 0;
}
*/

/*�����ͷ��ڴ�
class A
{
public:
	A();
	~A();
	int get() const{
			return *i;
		}
			void set(int x){
			*i=x;
		}
private:
	int* i;
};
int main()
{
	A a;
	cout<<a.get()<<endl;
	a.set(0);
	cout<<a.get()<<endl;
	return 0;
}

A::A(){
	cout<<"aaaaaaa\n";
	i=new int(999);
}
A::~A(){
	cout<<"bbbbbbbb\n";
	delete i;
}
*/
