#include "StdAfx.h"
#include "Plural.h"


CPlural::CPlural()
{
}


CPlural::~CPlural(void)
{
}

CPlural::CPlural(double r,double i)
{
	this->nImg = i;
	this->nReal = r;
}

CPlural::CPlural(CPlural& cp)
{
	this->nImg = cp.nImg;
	this->nReal = cp.nReal;
}

CPlural operator-(CPlural cp1,CPlural cp2)
{
	CPlural cp;
	cp.nImg = cp1.nImg - cp2.nImg;
	cp.nReal = cp1.nReal - cp2.nReal;
	return cp;
}

CPlural CPlural::operator+(CPlural cp)
{
	CPlural temp;
	temp.nImg = this->nImg + cp.nImg;
	temp.nReal = this->nReal + cp.nReal;
	return temp;
}

ostream& operator<<(ostream& os, CPlural& cp)
{
	if(cp.nReal != 0)
		os<<cp.nReal;
	else if(cp.nImg == 0)
		os<<cp.nImg;

	if(cp.nImg != 0)
	{
		if(cp.nImg>0)
			os<<"+";
		os<<cp.nImg<<"i";
	}

	return os;
}