
// SdiSocketClientView.h : CSdiSocketClientView ��Ľӿ�
//

#pragma once

#include "resource.h"

#include"TcpClient.h"


class CSdiSocketClientView : public CFormView
{
public:
	CTcpClient m_sock;
public: // �������л�����
	CSdiSocketClientView();
	DECLARE_DYNCREATE(CSdiSocketClientView)

public:
	enum{ IDD = IDD_SDISOCKETCLIENT_FORM };

// ����
public:
	CSdiSocketClientDoc* GetDocument() const;

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
	virtual ~CSdiSocketClientView();
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
	CString m_msg;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedSend();
};

#ifndef _DEBUG  // SdiSocketClientView.cpp �еĵ��԰汾
inline CSdiSocketClientDoc* CSdiSocketClientView::GetDocument() const
   { return reinterpret_cast<CSdiSocketClientDoc*>(m_pDocument); }
#endif

