
// SdiDockablePane.h : SdiDockablePane Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#define VIEWS_NUM 6
#include "resource.h"       // ������

#include"NewFormView.h"
#include"NewListView.h"
// CSdiDockablePaneApp:
// �йش����ʵ�֣������ SdiDockablePane.cpp
//

class CSdiDockablePaneApp : public CWinAppEx
{
public:
	CSdiDockablePaneApp();
	//����ͼ���еĲ���
public:
	CView* views[VIEWS_NUM];

	int m_nActive;//��ʶ��ǰ������ʾ����ͼ

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
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
