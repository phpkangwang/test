
// ThreadSyn.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include<GdiPlus.h>
using namespace Gdiplus;

// CThreadSynApp:
// �йش����ʵ�֣������ ThreadSyn.cpp
//

class CThreadSynApp : public CWinApp
{
public:
	CThreadSynApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CThreadSynApp theApp;