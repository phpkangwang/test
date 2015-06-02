// Tab.cpp : 实现文件
//

#include "stdafx.h"
#include "TabCtrl.h"
#include "Tab.h"

// CTab

IMPLEMENT_DYNAMIC(CTab, CTabCtrl)

CTab::CTab()
{

}

CTab::~CTab()
{
}


BEGIN_MESSAGE_MAP(CTab, CTabCtrl)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CTab::OnTcnSelchange)
END_MESSAGE_MAP()



// CTab 消息处理程序




int CTab::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTabCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	InsertItem(0,_T("标签0"));
	InsertItem(1,_T("标签1"));
	InsertItem(2,_T("标签2"));
	SetCurSel(0);
	m_nSel = 0;

	CRect rc;
	GetWindowRect(rc);

	m_dlg1.Create(CDlg1::IDD,this);
	m_dlg2.Create(CDlg2::IDD,this);
	m_dlg3.Create(CDlg3::IDD,this);

	m_dlg1.ShowWindow(SW_SHOW);
	m_dlg2.ShowWindow(SW_HIDE);
	m_dlg3.ShowWindow(SW_HIDE);

	//m_dlg1.SetWindowPos(NULL,2,22,rc.Width()-4,rc.Height()-26,SWP_SHOWWINDOW);
	//m_dlg2.SetWindowPos(NULL,2,22,rc.Width()-4,rc.Height()-26,SWP_SHOWWINDOW);
	//m_dlg3.SetWindowPos(NULL,2,22,rc.Width()-4,rc.Height()-26,SWP_SHOWWINDOW);

	CRect rcItem;
	GetItemRect(0,&rcItem);
	CRect r;
	GetClientRect(&r);
	r.left += 4;
	r.top = rcItem.Height()+ 4;
	r.right -= 4;
	r.bottom -= 4;
	m_dlg1.MoveWindow(r);
	m_dlg2.MoveWindow(r);
	m_dlg3.MoveWindow(r);

	return 0;
}


void CTab::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	CDialog* dlg[]=
	{
		&m_dlg1,
		&m_dlg2,
		&m_dlg3
	};
	int n = GetCurSel();
	//当前显示
	dlg[n]->ShowWindow(SW_SHOW);
	//以前显示的隐藏
	dlg[m_nSel]->ShowWindow(SW_HIDE);
	m_nSel = n;
	*pResult = 0;
}
