
// GDIGif.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGDIGifApp:
// �йش����ʵ�֣������ GDIGif.cpp
//

class CGDIGifApp : public CWinApp
{
public:
	CGDIGifApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGDIGifApp theApp;