
// SdiPaintView.h : CSdiPaintView ��Ľӿ�
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
	GraphType m_GraphType;//ѡ��Ļ�ͼ����
	CPoint m_ptStart;//�����������¼��ͼ����ʼ��
	CPoint m_ptMove;//������ɿ�������ƶ�ʱ�����һ�μ�¼λ��
	BOOL m_bIsDrawing;//��ʶ����Ƿ񱻰��£���ʼ��ͼ
public:
	CDC m_mdc;
	CBitmap m_mbmp;
	int w;
	int h;
	DWORD oldCursor; 
protected: // �������л�����
	CSdiPaintView();
	DECLARE_DYNCREATE(CSdiPaintView)

// ����
public:
	CSdiPaintDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSdiPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // SdiPaintView.cpp �еĵ��԰汾
inline CSdiPaintDoc* CSdiPaintView::GetDocument() const
   { return reinterpret_cast<CSdiPaintDoc*>(m_pDocument); }
#endif

