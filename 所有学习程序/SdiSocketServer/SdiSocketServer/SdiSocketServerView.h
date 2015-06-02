
// SdiSocketServerView.h : CSdiSocketServerView ��Ľӿ�
//

#pragma once

#include "resource.h"

#include"TcpServer.h"
#include"TcpClient.h"

class CSdiSocketServerView : public CFormView
{
public:
	CTcpServer m_sock;

protected: // �������л�����
	CSdiSocketServerView();
	DECLARE_DYNCREATE(CSdiSocketServerView)

public:
	enum{ IDD = IDD_SDISOCKETSERVER_FORM };

// ����
public:
	CSdiSocketServerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CSdiSocketServerView();
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
};

#ifndef _DEBUG  // SdiSocketServerView.cpp �еĵ��԰汾
inline CSdiSocketServerDoc* CSdiSocketServerView::GetDocument() const
   { return reinterpret_cast<CSdiSocketServerDoc*>(m_pDocument); }
#endif

