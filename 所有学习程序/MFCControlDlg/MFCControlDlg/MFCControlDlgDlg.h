
// MFCControlDlgDlg.h : 头文件
//

#pragma once
#include "afxbutton.h"
#include "afxwin.h"
#include "afxcmn.h"


// CMFCControlDlgDlg 对话框
class CMFCControlDlgDlg : public CDialogEx
{
// 构造
public:
	CMFCControlDlgDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCCONTROLDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:
		CImageList m_IList;

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
	CMFCButton m_mfcBtn;
	CComboBox m_CBoxCtrl;
	CTreeCtrl m_CityTree;
	CTreeCtrl m_TreeCtrl;
public:
	bool IsExist(CString s);
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedTreeOpBtn();
	afx_msg void OnBnClickedTraverasalNodeBtn();
	afx_msg void OnTvnSelchangedCityTree(NMHDR *pNMHDR, LRESULT *pResult);
		afx_msg void OnNMClickTreeImage(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTreeImage(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnNMSetfocusTreeImage(NMHDR *pNMHDR, LRESULT *pResult);
};
