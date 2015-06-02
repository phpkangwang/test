
// MFCSockDlg.h : 头文件
//

#pragma once

#include "MySocket.h"

// CMFCSockDlg 对话框
class CMFCSockDlg : public CDialogEx
{
// 构造
public:
	CMySocket m_sock;
public:
	CMFCSockDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCSOCK_DIALOG };

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
	CListBox m_RecordList;
	CString m_msg;
	CString m_ToIp;
	UINT m_ToPort;
	afx_msg void OnBnClickedSendBtn();
	CComboBox m_IpCombox;
	CComboBox m_PortCombox;
};
