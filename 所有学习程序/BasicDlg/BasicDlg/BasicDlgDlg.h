
// BasicDlgDlg.h : ͷ�ļ�
//

#pragma once


// CBasicDlgDlg �Ի���
class CBasicDlgDlg : public CDialogEx
{
// ����
public:
	CBasicDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BASICDLG_DIALOG };

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
