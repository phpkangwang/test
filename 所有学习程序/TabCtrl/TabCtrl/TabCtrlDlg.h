
// TabCtrlDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "Dlg1.h"
#include "Dlg2.h"
#include "Dlg3.h"
// CTabCtrlDlg 对话框
#include "Tab.h"

class CTabCtrlDlg : public CDialogEx
{
// 构造
public:
	CTab tab;

public:
	CTabCtrlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MAIN_DLG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_TabCtrl;
	CDlg1 m_dlg1;
	CDlg2 m_dlg2;
	CDlg3 m_dlg3;
	int m_nSel;
	CImageList Imglst;

	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedShowBtn();
	afx_msg void OnBnClickedShow();
};
