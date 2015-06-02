
// SdiDockablePaneView.cpp : CSdiDockablePaneView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SdiDockablePane.h"
#endif

#include "SdiDockablePaneDoc.h"
#include "SdiDockablePaneView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiDockablePaneView

IMPLEMENT_DYNCREATE(CSdiDockablePaneView, CView)

BEGIN_MESSAGE_MAP(CSdiDockablePaneView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSdiDockablePaneView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSdiDockablePaneView ����/����

CSdiDockablePaneView::CSdiDockablePaneView()
{
	// TODO: �ڴ˴���ӹ������

}

CSdiDockablePaneView::~CSdiDockablePaneView()
{
}

BOOL CSdiDockablePaneView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSdiDockablePaneView ����

void CSdiDockablePaneView::OnDraw(CDC* /*pDC*/)
{
	CSdiDockablePaneDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSdiDockablePaneView ��ӡ


void CSdiDockablePaneView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSdiDockablePaneView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSdiDockablePaneView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSdiDockablePaneView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSdiDockablePaneView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSdiDockablePaneView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSdiDockablePaneView ���

#ifdef _DEBUG
void CSdiDockablePaneView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiDockablePaneView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiDockablePaneDoc* CSdiDockablePaneView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiDockablePaneDoc)));
	return (CSdiDockablePaneDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiDockablePaneView ��Ϣ�������
