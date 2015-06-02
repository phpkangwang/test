
// SdiSocketServerView.h : CSdiSocketServerView 类的接口
//

#pragma once

#include "resource.h"

#include"TcpServer.h"
#include"TcpClient.h"

class CSdiSocketServerView : public CFormView
{
public:
	CTcpServer m_sock;

protected: // 仅从序列化创建
	CSdiSocketServerView();
	DECLARE_DYNCREATE(CSdiSocketServerView)

public:
	enum{ IDD = IDD_SDISOCKETSERVER_FORM };

// 特性
public:
	CSdiSocketServerDoc* GetDocument() const;

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
	virtual ~CSdiSocketServerView();
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
};

#ifndef _DEBUG  // SdiSocketServerView.cpp 中的调试版本
inline CSdiSocketServerDoc* CSdiSocketServerView::GetDocument() const
   { return reinterpret_cast<CSdiSocketServerDoc*>(m_pDocument); }
#endif

