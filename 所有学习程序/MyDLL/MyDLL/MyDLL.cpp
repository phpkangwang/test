// MyDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MyDLL.h"
using namespace mydll;

// ���ǵ���������һ��ʾ��
MYDLL_API int nMyDLL=0;

// ���ǵ���������һ��ʾ����
MYDLL_API int fnMyDLL(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MyDLL.h
CMyDLL::CMyDLL()
{
	return;
}

int CMyDLL::Inc(int& nData)
{
	nData++;
	return nData;
}
