
// ODBCMoreTable.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CODBCMoreTableApp:
// �йش����ʵ�֣������ ODBCMoreTable.cpp
//

class CODBCMoreTableApp : public CWinApp
{
public:
	CODBCMoreTableApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CODBCMoreTableApp theApp;