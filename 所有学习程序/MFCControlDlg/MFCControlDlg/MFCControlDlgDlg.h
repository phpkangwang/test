
// MFCControlDlgDlg.h : ͷ�ļ�
//

#pragma once
#include "afxbutton.h"
#include "afxwin.h"
#include "afxcmn.h"


// CMFCControlDlgDlg �Ի���
class CMFCControlDlgDlg : public CDialogEx
{
// ����
public:
	CMFCControlDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCCONTROLDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:
		CImageList m_IList;

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
	CMFCButton m_mfcBtn;
	CComboBox m_CBoxCtrl;
	CTreeCtrl m_CityTree;
	CTreeCtrl m_TreeCtrl;
public:
	bool IsExist(CString s);
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnBnClickedTreeOpBtn();
	afx_msg void OnBnClickedTraverasalNodeBtn();
	afx_msg void OnTvnSelchangedCityTree(NMHDR *pNMHDR, LRESULT *pResult);
		afx_msg void OnNMClickTreeImage(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTreeImage(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnNMSetfocusTreeImage(NMHDR *pNMHDR, LRESULT *pResult);
};
