
// WinFileOpDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CWinFileOpDlg �Ի���
class CWinFileOpDlg : public CDialogEx
{
// ����
public:
	CWinFileOpDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WINFILEOP_DIALOG };

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
	CListCtrl m_ListControl;
	afx_msg void OnBnClickedGetfileinfoBtn();
};
