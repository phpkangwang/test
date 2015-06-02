// NewListView.cpp : 实现文件
//

#include "stdafx.h"
#include "SdiDockablePane.h"
#include "NewListView.h"


// CNewListView

IMPLEMENT_DYNCREATE(CNewListView, CListView)

CNewListView::CNewListView()
{

}

CNewListView::~CNewListView()
{
}

BEGIN_MESSAGE_MAP(CNewListView, CListView)
END_MESSAGE_MAP()


// CNewListView 诊断

#ifdef _DEBUG
void CNewListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CNewListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CNewListView 消息处理程序
