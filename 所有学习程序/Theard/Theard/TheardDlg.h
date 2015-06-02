
// TheardDlg.h : 头文件
//

#pragma once

//#define WM_MSG WM_USER+1
const UINT WM_Msg = WM_USER+1;


// CTheardDlg 对话框
class CTheardDlg : public CDialogEx
{
// 构造
public:
	CTheardDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_THEARD_DIALOG };

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
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedResume();
	afx_msg void OnBnClickedSuspend();
	afx_msg void OnBnClickedEnd();
	afx_msg LRESULT OnMsg(WPARAM wParam,LPARAM lParam);
	afx_msg void OnBnClickedSiganl();
	afx_msg void OnBnClickedSiganlexit();
};
