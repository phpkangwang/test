
// SdiSocketClientView.cpp : CSdiSocketClientView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SdiSocketClient.h"
#endif

#include "SdiSocketClientDoc.h"
#include "SdiSocketClientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSocketClientView

IMPLEMENT_DYNCREATE(CSdiSocketClientView, CFormView)

BEGIN_MESSAGE_MAP(CSdiSocketClientView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_CONNECT, &CSdiSocketClientView::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_SEND, &CSdiSocketClientView::OnBnClickedSend)
END_MESSAGE_MAP()

// CSdiSocketClientView 构造/析构

CSdiSocketClientView::CSdiSocketClientView()
	: CFormView(CSdiSocketClientView::IDD)
	, m_msg(_T(""))
{
	// TODO: 在此处添加构造代码
	m_sock.Create();
}

CSdiSocketClientView::~CSdiSocketClientView()
{
}

void CSdiSocketClientView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MESSAGE_EDIT, m_msg);
}

BOOL CSdiSocketClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CSdiSocketClientView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CSdiSocketClientView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSdiSocketClientView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSdiSocketClientView 诊断

#ifdef _DEBUG
void CSdiSocketClientView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSdiSocketClientView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSdiSocketClientDoc* CSdiSocketClientView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSocketClientDoc)));
	return (CSdiSocketClientDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSocketClientView 消息处理程序


void CSdiSocketClientView::OnBnClickedConnect()
{
	m_sock.Connect(_T("192.168.0.16"),8000);
}


void CSdiSocketClientView::OnBnClickedSend()
{
	UpdateData(TRUE);
	CStringA sa = CW2A(m_msg);
	m_sock.Send(sa,sa.GetLength()+1,0);

}
