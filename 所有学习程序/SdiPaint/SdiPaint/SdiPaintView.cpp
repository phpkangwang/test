
// SdiPaintView.cpp : CSdiPaintView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SdiPaint.h"
#endif

#include "SdiPaintDoc.h"
#include "SdiPaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiPaintView

IMPLEMENT_DYNCREATE(CSdiPaintView, CView)

BEGIN_MESSAGE_MAP(CSdiPaintView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSdiPaintView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_LINE, &CSdiPaintView::OnLine)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CSdiPaintView::OnUpdateLine)
	ON_COMMAND(ID_RECT, &CSdiPaintView::OnRect)
	ON_COMMAND(ID_ELLIPSE, &CSdiPaintView::OnEllipse)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CSdiPaintView 构造/析构

CSdiPaintView::CSdiPaintView()
{
	// TODO: 在此处添加构造代码
	m_GraphType = GT_RECT;
	m_bIsDrawing = FALSE;

}

CSdiPaintView::~CSdiPaintView()
{
}

BOOL CSdiPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSdiPaintView 绘制

void CSdiPaintView::OnDraw(CDC* pDC)
{
	CSdiPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//填充背景
	CBitmap* pOldBmp = m_mdc.SelectObject(&m_mbmp);
	pDC->BitBlt(0,0,w,h,&m_mdc,0,0,SRCCOPY);
	m_mdc.SelectObject(pOldBmp);
}


// CSdiPaintView 打印


void CSdiPaintView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSdiPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSdiPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSdiPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CSdiPaintView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSdiPaintView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSdiPaintView 诊断

#ifdef _DEBUG
void CSdiPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiPaintDoc* CSdiPaintView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiPaintDoc)));
	return (CSdiPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiPaintView 消息处理程序


void CSdiPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(m_GraphType != GT_NULL)
	{
		m_bIsDrawing = TRUE;
		m_ptStart = point;
		m_ptMove = m_ptStart;
		HCURSOR hCursor = theApp.LoadStandardCursor(IDC_CROSS);
		oldCursor = SetClassLong(this->m_hWnd,GCL_HCURSOR,(long)hCursor);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CSdiPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if( !m_bIsDrawing )
		return;
	//CDC* pDC = GetDC();
	CDC* pDC = &m_mdc;
	
	//矩形,画矩形和椭圆时使用
	CRect rc(m_ptStart,point);
	rc.NormalizeRect();
	CBitmap* pOldBmp = m_mdc.SelectObject(&m_mbmp);
	CBrush* pOldBr = (CBrush*)m_mdc.SelectStockObject(NULL_BRUSH);
	switch(m_GraphType)
	{
	case GT_LINE:
		pDC->MoveTo(m_ptStart);
		pDC->LineTo(point);
		InvalidateRect(rc);
		break;
	case GT_RECT:
		pDC->Rectangle(rc);
		InvalidateRect(rc);
		break;
	case GT_ELLIPSE:
		pDC->Ellipse(rc);
		InvalidateRect(rc);
		break;
	}
	m_mdc.SelectObject(pOldBr);
	m_mdc.SelectObject(pOldBmp);
	m_bIsDrawing = FALSE;
	//ReleaseDC(pDC);
	SetClassLong(this->m_hWnd,GCL_HCURSOR,oldCursor);
	CView::OnLButtonUp(nFlags, point);
}


void CSdiPaintView::OnMouseMove(UINT nFlags, CPoint point)
{	
	if( !m_bIsDrawing )//左键没有被按下
		return;
	//使上次的区域无效
	CRect rcOld(m_ptStart,m_ptMove);
	rcOld.NormalizeRect();
	rcOld.InflateRect(1,1);
	InvalidateRect(rcOld,FALSE);
	UpdateWindow();
	//
	CDC* pDC = GetDC();
	CRect rc(m_ptStart,point);
	rc.NormalizeRect();
	CBrush* pOldBr = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	switch(m_GraphType)
	{
	case GT_LINE:
		pDC->MoveTo(m_ptStart);
		pDC->LineTo(point);
		break;
	case GT_RECT:
		pDC->Rectangle(rc);
		break;
	case GT_ELLIPSE:
		pDC->Ellipse(rc);
		break;
	}
	pDC->SelectObject(pOldBr);
	ReleaseDC(pDC);

	m_ptMove = point;

	CView::OnMouseMove(nFlags, point);
}


void CSdiPaintView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_GraphType = GT_LINE;
}


void CSdiPaintView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck( m_GraphType == GT_LINE );
}


void CSdiPaintView::OnRect()
{
	// TODO: 在此添加命令处理程序代码
	m_GraphType = GT_RECT;
}


void CSdiPaintView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_GraphType = GT_ELLIPSE;
}


int CSdiPaintView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	w = ::GetSystemMetrics(SM_CXSCREEN);
	h = ::GetSystemMetrics(SM_CYSCREEN);
	
	CDC* pDC = GetDC();
	m_mdc.CreateCompatibleDC(pDC);
	m_mbmp.CreateCompatibleBitmap(pDC,w,h);
	ReleaseDC(pDC);

	COLORREF color = RGB(200,200,200);
	CBrush br(color);
	CBitmap* pOldBmp = m_mdc.SelectObject(&m_mbmp);
	m_mdc.FillRect(CRect(0,0,w,h),&br);
	m_mdc.SelectObject(pOldBmp);

	return 0;
}
