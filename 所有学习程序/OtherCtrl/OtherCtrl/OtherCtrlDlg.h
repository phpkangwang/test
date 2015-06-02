
// OtherCtrlDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// COtherCtrlDlg 对话框
class COtherCtrlDlg : public CDialogEx
{
// 构造
public:
	COLORREF c;

public:
	COtherCtrlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OTHERCTRL_DIALOG };

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
	CSliderCtrl m_slider;
	CProgressCtrl m_progress;
	afx_msg void OnBnClickedStartBtn();
	afx_msg void OnBnClickedEndBtn();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CSliderCtrl m_rSlider;
	CSliderCtrl m_gSlider;
	CSliderCtrl m_bSlider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnNMThemeChangedProgress(NMHDR *pNMHDR, LRESULT *pResult);
};
