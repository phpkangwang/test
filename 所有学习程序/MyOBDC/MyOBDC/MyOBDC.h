
// MyOBDC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyOBDCApp:
// �йش����ʵ�֣������ MyOBDC.cpp
//

class CMyOBDCApp : public CWinApp
{
public:
	CMyOBDCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyOBDCApp theApp;