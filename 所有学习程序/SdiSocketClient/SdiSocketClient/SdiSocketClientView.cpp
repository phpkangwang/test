
// SdiSocketClientView.cpp : CSdiSocketClientView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CSdiSocketClientView ����/����

CSdiSocketClientView::CSdiSocketClientView()
	: CFormView(CSdiSocketClientView::IDD)
	, m_msg(_T(""))
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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


// CSdiSocketClientView ���

#ifdef _DEBUG
void CSdiSocketClientView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSdiSocketClientView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSdiSocketClientDoc* CSdiSocketClientView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSocketClientDoc)));
	return (CSdiSocketClientDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSocketClientView ��Ϣ�������


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
