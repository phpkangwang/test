
// SdiPaintView.h : CSdiPaintView 类的接口
//

#pragma once

enum GraphType
{
	GT_NULL,
	GT_LINE,
	GT_RECT,
	GT_ELLIPSE,
	GT_PLOYLINE
};

class CSdiPaintView : public CView
{
	
public:
	GraphType m_GraphType;//选择的画图类型
	CPoint m_ptStart;//单击左键，记录画图的起始点
	CPoint m_ptMove;//左键不松开，鼠标移动时的最后一次记录位置
	BOOL m_bIsDrawing;//标识左键是否被按下，开始画图
public:
	CDC m_mdc;
	CBitmap m_mbmp;
	int w;
	int h;
	DWORD oldCursor; 
protected: // 仅从序列化创建
	CSdiPaintView();
	DECLARE_DYNCREATE(CSdiPaintView)

// 特性
public:
	CSdiPaintDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSdiPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnRect();
	afx_msg void OnEllipse();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // SdiPaintView.cpp 中的调试版本
inline CSdiPaintDoc* CSdiPaintView::GetDocument() const
   { return reinterpret_cast<CSdiPaintDoc*>(m_pDocument); }
#endif

