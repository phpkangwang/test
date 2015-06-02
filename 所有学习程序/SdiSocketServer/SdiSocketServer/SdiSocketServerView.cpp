
// SdiSocketServerView.cpp : CSdiSocketServerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SdiSocketServer.h"
#endif

#include "SdiSocketServerDoc.h"
#include "SdiSocketServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSocketServerView

IMPLEMENT_DYNCREATE(CSdiSocketServerView, CFormView)

BEGIN_MESSAGE_MAP(CSdiSocketServerView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSdiSocketServerView 构造/析构

CSdiSocketServerView::CSdiSocketServerView()
	: CFormView(CSdiSocketServerView::IDD)
{
	// TODO: 在此处添加构造代码
	m_sock.Create(8000);
	m_sock.Listen();
}

CSdiSocketServerView::~CSdiSocketServerView()
{
}

void CSdiSocketServerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CSdiSocketServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CSdiSocketServerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CSdiSocketServerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSdiSocketServerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSdiSocketServerView 诊断

#ifdef _DEBUG
void CSdiSocketServerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSdiSocketServerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSdiSocketServerDoc* CSdiSocketServerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSocketServerDoc)));
	return (CSdiSocketServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSocketServerView 消息处理程序
