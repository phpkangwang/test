
// MyCDC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyCDCApp:
// �йش����ʵ�֣������ MyCDC.cpp
//

class CMyCDCApp : public CWinApp
{
public:
	CMyCDCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyCDCApp theApp;