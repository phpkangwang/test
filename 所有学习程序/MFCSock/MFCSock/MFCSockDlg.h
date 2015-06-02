
// MFCSockDlg.h : ͷ�ļ�
//

#pragma once

#include "MySocket.h"

// CMFCSockDlg �Ի���
class CMFCSockDlg : public CDialogEx
{
// ����
public:
	CMySocket m_sock;
public:
	CMFCSockDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCSOCK_DIALOG };

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
	CListBox m_RecordList;
	CString m_msg;
	CString m_ToIp;
	UINT m_ToPort;
	afx_msg void OnBnClickedSendBtn();
	CComboBox m_IpCombox;
	CComboBox m_PortCombox;
};
