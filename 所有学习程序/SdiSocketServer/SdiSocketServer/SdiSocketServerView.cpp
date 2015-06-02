
// SdiSocketServerView.cpp : CSdiSocketServerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CSdiSocketServerView ����/����

CSdiSocketServerView::CSdiSocketServerView()
	: CFormView(CSdiSocketServerView::IDD)
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CSdiSocketServerView ���

#ifdef _DEBUG
void CSdiSocketServerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSdiSocketServerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSdiSocketServerDoc* CSdiSocketServerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSocketServerDoc)));
	return (CSdiSocketServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSocketServerView ��Ϣ�������
