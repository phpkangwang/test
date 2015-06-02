
// ListControlDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CListControlDlg 对话框
class CListControlDlg : public CDialogEx
{
// 构造
public:
	CListControlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LISTCONTROL_DIALOG };

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
	CListCtrl m_ListControl;
	CComboBox m_ViewCombo;
public:
	CImageList m_IList;
public:
	afx_msg void OnCbnSelchangeViewCombox();
	afx_msg void OnBnClickedSelOpBtn();
	afx_msg void OnHdnItemclickListControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedGetdriveBtn();
	CComboBox m_DriveCombo;
};
