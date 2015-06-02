
// TabCtrlDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "Dlg1.h"
#include "Dlg2.h"
#include "Dlg3.h"
// CTabCtrlDlg �Ի���
#include "Tab.h"

class CTabCtrlDlg : public CDialogEx
{
// ����
public:
	CTab tab;

public:
	CTabCtrlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MAIN_DLG };

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
	CTabCtrl m_TabCtrl;
	CDlg1 m_dlg1;
	CDlg2 m_dlg2;
	CDlg3 m_dlg3;
	int m_nSel;
	CImageList Imglst;

	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedShowBtn();
	afx_msg void OnBnClickedShow();
};
