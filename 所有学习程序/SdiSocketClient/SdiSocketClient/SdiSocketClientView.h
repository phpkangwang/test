
// SdiSocketClientView.h : CSdiSocketClientView 类的接口
//

#pragma once

#include "resource.h"

#include"TcpClient.h"


class CSdiSocketClientView : public CFormView
{
public:
	CTcpClient m_sock;
public: // 仅从序列化创建
	CSdiSocketClientView();
	DECLARE_DYNCREATE(CSdiSocketClientView)

public:
	enum{ IDD = IDD_SDISOCKETCLIENT_FORM };

// 特性
public:
	CSdiSocketClientDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CSdiSocketClientView();
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
	CString m_msg;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedSend();
};

#ifndef _DEBUG  // SdiSocketClientView.cpp 中的调试版本
inline CSdiSocketClientDoc* CSdiSocketClientView::GetDocument() const
   { return reinterpret_cast<CSdiSocketClientDoc*>(m_pDocument); }
#endif

