
// My_CDialog1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMy_CDialog1Dlg 对话框
class CMy_CDialog1Dlg : public CDialogEx
{
// 构造
public:
	CMy_CDialog1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_CDIALOG1_DIALOG };

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
	afx_msg void OnBnClickedBtnMesbox();
	CEdit m_name_edit;
	afx_msg void OnBnClickedBtnShowOrHide();
	afx_msg void OnBnClickedUpadateTitleBtn();
	afx_msg void OnBnClickedLoginBtn();
	afx_msg void OnBnClickedLoginCancelBtn();
	afx_msg void OnBnClickedEnableBtn();
	afx_msg void OnBnClickedMsgboxBtn();
};
