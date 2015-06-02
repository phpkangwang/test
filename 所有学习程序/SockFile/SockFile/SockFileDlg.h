
// SockFileDlg.h : 头文件
//

#pragma once

#include "MySock.h"
#include "afxcmn.h"
// CSockFileDlg 对话框
class CSockFileDlg : public CDialogEx
{
// 构造
	CMySock m_sock;
public:
	CSockFileDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SOCKFILE_DIALOG };

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
	afx_msg void OnLbnSelchangeRecordList();
	CString m_msg;
	CListBox m_RecordList;
	UINT m_nToPort;
	CString m_sToIp;
	CString m_sMyIp;
	UINT m_nMyPort;
	afx_msg void OnBnClickedInit();
	afx_msg void OnBnClickedSend();
	CProgressCtrl m_progress;
	afx_msg void OnBnClickedSendfile();
	afx_msg void OnBnClickedCancelSendfileBtn();
};
