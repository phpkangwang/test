
// TheardDlg.h : ͷ�ļ�
//

#pragma once

//#define WM_MSG WM_USER+1
const UINT WM_Msg = WM_USER+1;


// CTheardDlg �Ի���
class CTheardDlg : public CDialogEx
{
// ����
public:
	CTheardDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_THEARD_DIALOG };

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
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedResume();
	afx_msg void OnBnClickedSuspend();
	afx_msg void OnBnClickedEnd();
	afx_msg LRESULT OnMsg(WPARAM wParam,LPARAM lParam);
	afx_msg void OnBnClickedSiganl();
	afx_msg void OnBnClickedSiganlexit();
};
