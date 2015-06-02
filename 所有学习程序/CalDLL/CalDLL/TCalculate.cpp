#include "StdAfx.h"
#include "TCalculate.h"
#include <math.h>
using namespace TCalLib;

TCalculate::TCalculate(void)
	: m_ShowRes(_T(""))
{
	Init();
}


TCalculate::~TCalculate(void)
{
}

void TCalculate::Init(void)
{
	m_dLeft = 0;
	m_dRight = 0;
	m_CharOp = '+';
	m_dCoff = 1.0;
}

double TCalculate::DoInput(int data)
{
	//��������
	if(m_dCoff == 1.0)
	{
		if(m_dRight >= 0)
			m_dRight = m_dRight*10 + data;
		else
			m_dRight = m_dRight*10 - data;
	}
	else//С������
	{
		if(m_dRight >= 0)
			m_dRight += data*m_dCoff;
		else
			m_dRight -= data*m_dCoff;
		m_dCoff *= 0.1;
	}
	m_ShowRes.Format(_T("%f"),m_dRight);
	return m_dRight;
}

double TCalculate::DoCalculate(char newOp)
{
	//ִ������
	switch(m_CharOp)
	{
	case '+':
		m_dLeft += m_dRight;
		break;
	case '-':
		m_dLeft -= m_dRight;
		break;
	case '*':
		m_dLeft *= m_dRight;
		break;
	case '/':
		m_dLeft /= m_dRight;
		break;
	}
	//����
	m_dRight = 0;
	m_dCoff = 1.0;
	//���������ֵ
	m_CharOp = newOp;
	//��Ҫ��ʾ�Ľ������
	m_ShowRes.Format(_T("%f"),m_dLeft);
	return m_dLeft;
}


double TCalculate::QuFan(void)
{
	m_dRight = 0 - m_dRight;
	m_ShowRes.Format(_T("%f"),m_dRight);
	return m_dRight;
}


double TCalculate::GetCoff(void)
{
	return m_dCoff;
}


void TCalculate::ChangeCoff(void)
{
	if(m_dCoff == 1.0)
		m_dCoff = 0.1;
}


double TCalculate::Recip(CString cstr)
{
	CString s = DoubleToCString(m_dLeft);
	if(cstr == s)
	{
		m_dLeft = 1/m_dLeft;
		return m_dLeft;
	}
	else
	{
		m_dRight = 1/m_dRight;
		return m_dRight;
	}
}


double TCalculate::Evol(double d)
{
	if(d == m_dLeft)
	{
		m_dLeft = sqrt(m_dLeft);
		return m_dLeft;
	}
	else
	{
		m_dRight = sqrt(m_dRight);
		return m_dRight;
	}
}


CString TCalculate::DoubleToCString(double d)
{
	CString s ;
	s.Format(_T("%f"),d);
	int nLen = s.GetLength() - 1;
	while(true)
	{
		if( s[nLen] == '0')
		{
			s.Delete(nLen);
			nLen--;
		}
		else
			break;
	}
	return s;
}
