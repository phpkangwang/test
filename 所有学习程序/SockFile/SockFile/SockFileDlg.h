
// SockFileDlg.h : ͷ�ļ�
//

#pragma once

#include "MySock.h"
#include "afxcmn.h"
// CSockFileDlg �Ի���
class CSockFileDlg : public CDialogEx
{
// ����
	CMySock m_sock;
public:
	CSockFileDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SOCKFILE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
