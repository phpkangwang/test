// FileTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "SdiDockablePane.h"
#include "FileTreeView.h"


// CFileTreeView

IMPLEMENT_DYNAMIC(CFileTreeView, CDockablePane)

CFileTreeView::CFileTreeView()
{

}

CFileTreeView::~CFileTreeView()
{
}


BEGIN_MESSAGE_MAP(CFileTreeView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CFileTreeView 消息处理程序




int CFileTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	UINT style = WS_VISIBLE | WS_TABSTOP | WS_CHILD |
		TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES |
		TVS_DISABLEDRAGDROP | TVS_NOTOOLTIPS | TVS_EDITLABELS;

	CRect rc;
	GetClientRect(rc);
	m_tree.Create(style,rc,this,ID_MY_TREEVIEW);

	HTREEITEM FirstRoot = m_tree.InsertItem(_T("孙浩"));
	m_tree.InsertItem(_T("张宏杰"),FirstRoot);
	m_tree.InsertItem(_T("张盼盼"),FirstRoot);

	if(
		!m_toolBar.Create(this,WS_CHILD|WS_VISIBLE|CBRS_TOP)
		||
		!m_toolBar.LoadToolBar(IDR_MY_TOOLBAR)
	  )
	  return -1;





	return 0;
}


void CFileTreeView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if(m_tree.GetSafeHwnd())
	{
		CRect toolRect(0,0,200,23);
		m_toolBar.MoveWindow(toolRect);

		CRect treeRect(0,23,cx,cy);
		//rc.DeflateRect(1,1,1,1);
		m_tree.MoveWindow(treeRect);
	}
}

int& CFileTreeView::GetData(void)
{
	return this->m_nSlideSteps;
}
