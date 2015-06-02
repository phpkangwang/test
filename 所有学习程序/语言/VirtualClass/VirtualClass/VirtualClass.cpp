// VirtualClass.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Shape
{
public:
	virtual void Draw();
private:
};

void Shape::Draw()
{
	cout<<"Shape"<<endl;
}
class Circle : public Shape
{
public:
	void Draw()
	{
		cout<<"Circle"<<endl;
	}
};

class Rect : public Shape
{
public:
	void Draw()
	{
		cout<<"Rect"<<endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Circle c;
	c.Draw();
	Shape* pS= new Circle();
	pS->Draw();

	return 0;
}

