// My_CDialog1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "My_CDialog1_i.h"


// CMy_CDialog1App:
// �йش����ʵ�֣������ My_CDialog1.cpp
//

class CMy_CDialog1App : public CWinApp
{
public:
	CMy_CDialog1App();

public:
	int m_nData;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	BOOL ExitInstance(void);
};

//���������������ط�Ҫʹ��
extern CMy_CDialog1App theApp;