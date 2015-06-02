// CStringTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstring>
#include<iostream>
using namespace std;
class CString
{
public:
	CString(char* str = nullptr);//CString();不在需要，否则使用时会出错
	CString(CString& str);
	~CString();
public:
	operator char*();

public:
	char& operator[](int index);
	CString& operator=(CString& str);
	CString& operator=(char* str);

	friend ostream& operator<<(ostream& os,CString& str);
private:
	void FreeBuf();

	friend CString copy(char* str1,char* str2); 
	friend CString operator+(CString& str1,CString& str2);
	friend CString operator+(CString& str1,char* str2);
	friend CString operator+(char* str1,CString& str2);

private:
	char* m_pBuf;
	void SetBuf(char* str);	

};

CString::operator char *()
{
	return this->m_pBuf;
}
//================================
ostream& operator<<(ostream& os,CString& str)
{
	if(str.m_pBuf == nullptr)
		os<<"";
	else
		os<<str.m_pBuf;
	return os;
}
//
void CString::FreeBuf()
{
	if(this->m_pBuf)
	{
		delete[] this->m_pBuf;
		this->m_pBuf = nullptr;
	}
}

//====================================
CString& CString::operator=(char* str)
{
	FreeBuf();
	SetBuf(str);
	return *this;
}

CString& CString::operator=(CString& str)
{
	FreeBuf();
	SetBuf(str.m_pBuf);
	return *this;
}

CString copy(char* str1,char* str2)
{
	CString temp; 
	if(str1 == nullptr)
	{	
		temp.m_pBuf = new char[strlen(str2)+1];
		strcpy(temp.m_pBuf,str2);
		return temp;
	}

	if(str2 == nullptr)
	{	
		temp.m_pBuf = new char[strlen(str1)+1];
		strcpy(temp.m_pBuf,str1);
		return temp;
	}
	//
	temp.m_pBuf	= new char[strlen(str1)+strlen(str2)+1];
	strcpy(temp.m_pBuf,str1);
	strcat(temp.m_pBuf,str2);
	return temp;
}

CString operator+(CString& str1,CString& str2)
{
	return copy(str1.m_pBuf,str2.m_pBuf);
}

CString operator+(CString& str1,char* str2)
{
	return copy(str1.m_pBuf,str2);
}

CString operator+(char* str1,CString& str2)
{
	return copy(str1,str2.m_pBuf);
}

//=================================
void CString::SetBuf(char* str)
{
	if(str == NULL)
		this->m_pBuf = nullptr;
	else
	{
		int nLen = strlen(str)+1;
		this->m_pBuf = new char[nLen];
		strcpy(this->m_pBuf,str);
	}
}

CString::CString(char* str)
{
	SetBuf(str);
}

CString::CString(CString& str)
{
	SetBuf(str.m_pBuf);
}

CString::~CString()
{
	//删除分配的空间
	if(m_pBuf)
	{
		delete[] m_pBuf;
		m_pBuf = nullptr;
	}
}

//===============================

char& CString::operator[](int index)
{
	return m_pBuf[index];
}

//====================================
int _tmain(int argc, _TCHAR* argv[])
{
	CString s1;
	CString s2("hello");
	CString s3(s2);
	//char c = s2[0];
	//s2[3] = 'a';

	//s1 = s2;
	
	//char* t = s2.operator char *();

	char* t = (char*)s2;
	//s1 = t + s2;
	//cout<<s1;
	return 0;
}