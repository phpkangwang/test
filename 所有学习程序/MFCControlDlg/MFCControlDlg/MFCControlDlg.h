
// MFCControlDlg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCControlDlgApp:
// �йش����ʵ�֣������ MFCControlDlg.cpp
//

class CMFCControlDlgApp : public CWinApp
{
public:
	CMFCControlDlgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCControlDlgApp theApp;