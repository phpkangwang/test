// My_CDialog1.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "My_CDialog1_i.h"


// CMy_CDialog1App:
// 有关此类的实现，请参阅 My_CDialog1.cpp
//

class CMy_CDialog1App : public CWinApp
{
public:
	CMy_CDialog1App();

public:
	int m_nData;

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
	BOOL ExitInstance(void);
};

//声明对象，在其他地方要使用
extern CMy_CDialog1App theApp;