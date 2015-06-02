
// BasicDlgDlg.h : 头文件
//

#pragma once


// CBasicDlgDlg 对话框
class CBasicDlgDlg : public CDialogEx
{
// 构造
public:
	CBasicDlgDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BASICDLG_DIALOG };

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
	int m_nDest;
	int m_nType;
	afx_msg void OnBnClickedSubmitBtn();
	CButton m_cbMountion;
	CButton m_cbShopping;
	CButton m_cbTravel;
	afx_msg void OnBnClickedMountionCheck();
	CString m_StrComputerName;
	afx_msg void OnBnClickedQueryComputerInfo();
	CString m_Computer_HWInfo;
	CString m_TotalMemory;
	afx_msg void OnBnClickedCreatedlgBtn();
	afx_msg void OnBnClickedChoosecolor();
};
