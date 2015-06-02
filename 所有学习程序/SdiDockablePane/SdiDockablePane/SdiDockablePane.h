
// SdiDockablePane.h : SdiDockablePane 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#define VIEWS_NUM 6
#include "resource.h"       // 主符号

#include"NewFormView.h"
#include"NewListView.h"
// CSdiDockablePaneApp:
// 有关此类的实现，请参阅 SdiDockablePane.cpp
//

class CSdiDockablePaneApp : public CWinAppEx
{
public:
	CSdiDockablePaneApp();
	//对视图进行的操作
public:
	CView* views[VIEWS_NUM];

	int m_nActive;//标识当前正在显示的视图

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
	void InitViews(void);
	void SwitchView(int nIndex);
};

extern CSdiDockablePaneApp theApp;
