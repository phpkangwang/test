#pragma once
#include "stdafx.h"

class CPlural
{
		//友元函数
	friend CPlural operator- (CPlural cp1,CPlural cp2);
	friend ostream& operator<< (ostream& os, CPlural& cp);
public:
	CPlural(void);
	~CPlural(void);
public:
	//自定义构造函数
	CPlural(double r,double i);
	CPlural(CPlural& cp);
public:
	CPlural operator+(CPlural cp);
private:
	double nReal;
	double nImg;
};

