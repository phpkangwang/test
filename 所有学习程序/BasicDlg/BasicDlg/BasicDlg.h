
// BasicDlg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBasicDlgApp:
// �йش����ʵ�֣������ BasicDlg.cpp
//

class CBasicDlgApp : public CWinApp
{
public:
	CBasicDlgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBasicDlgApp theApp;