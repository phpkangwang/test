// FuncPane.cpp : 实现文件
//

#include "stdafx.h"
#include "SdiDockablePane.h"
#include "FuncPane.h"


// CFuncPane

IMPLEMENT_DYNAMIC(CFuncPane, CDockablePane)

CFuncPane::CFuncPane()
{

}

CFuncPane::~CFuncPane()
{
}


BEGIN_MESSAGE_MAP(CFuncPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CFuncPane 消息处理程序


int CFuncPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rc;
	GetClientRect(rc);
	// TODO:  在此添加您专用的创建代码
	if(!m_Outlook.Create(
		_T("图书管理"),
		this,
		rc,
		ID_OUTLOOK,
		WS_CHILD|WS_VISIBLE|CBRS_ALIGN_ANY)
	   )
	   return -1;

	CMFCOutlookBarTabCtrl* pTab = 
		(CMFCOutlookBarTabCtrl*)m_Outlook.GetUnderlyingWindow();

	if(!m_paneBorrow.Create(
		&m_Outlook,
		AFX_DEFAULT_TOOLBAR_STYLE,//WS_CHILD|WS_VISIBLE,//|AFX_CBRS_FLOAT,
		ID_PANAE_BORROW_1)
		)
		return -1;
	pTab->AddTab(&m_paneBorrow,_T("管理员"),-1,FALSE);
	if(!m_paneReturn.Create(
		&m_Outlook,
		AFX_DEFAULT_TOOLBAR_STYLE,
		ID_PANAE_RETURN_1)
		)
		return -1;
	pTab->AddTab(&m_paneReturn,_T("用户"),-1,FALSE);

	CString ImgNames[] = 
	{
		_T("录入.png"),
		_T("归还.png"),
		_T("借阅.png"),
		_T("复件 归还.png"),
		_T("复件 归还.png"),
		_T("复件 归还.png")
	};
	CString Lables[] = 
	{
		_T("录入"),
		_T("归还"),
		_T("借阅"),
		_T("录入"),
		_T("归还"),
		_T("录入")
	};

	UINT ID[] = 
	{
		ID_BOOK_borrow,
		ID_BOOK_borrow_return_search,
		ID_BOOK_history_search,
		ID_BOOK_new_book_search,
		ID_BOOK_insert_new_book_info,
		ID_BOOK_return
	};

	m_ImgList.Create(85,43,ILC_COLOR24,6,1);
	CImage img;
	CBitmap* bmp;
	COLORREF color = RGB(255,0,255);
	CString s;
	for(int i =0;i <6;i++)
	{
		s.Format(_T("images\\%s"),ImgNames[i]);
		img.Load(s);
		bmp = CBitmap::FromHandle(img);
		m_ImgList.Add(bmp,color);
		img.Detach();
	}

	for(int i =0;i <3;i++)
	{
		m_paneBorrow.AddButton(
			m_ImgList.ExtractIcon(i),
			Lables[i],
			ID[i],
			-1,
			TRUE
			);
	}
	
	
	for(int i =3;i <6;i++)
	{
		m_paneReturn.AddButton(
			m_ImgList.ExtractIcon(i),
			Lables[i],
			ID[i],
			-1,
			TRUE
			);
	}

	return 0;
}


void CFuncPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	if(m_Outlook.GetSafeHwnd())
	{
		m_Outlook.MoveWindow(CRect(0,0,cx,cy));
	}
	// TODO: 在此处添加消息处理程序代码
}
