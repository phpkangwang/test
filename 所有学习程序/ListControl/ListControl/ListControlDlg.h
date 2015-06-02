
// ListControlDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CListControlDlg �Ի���
class CListControlDlg : public CDialogEx
{
// ����
public:
	CListControlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LISTCONTROL_DIALOG };

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
	CComboBox m_ViewCombo;
public:
	CImageList m_IList;
public:
	afx_msg void OnCbnSelchangeViewCombox();
	afx_msg void OnBnClickedSelOpBtn();
	afx_msg void OnHdnItemclickListControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListControl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedGetdriveBtn();
	CComboBox m_DriveCombo;
};
