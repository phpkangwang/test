
// My_CDialog1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy_CDialog1Dlg �Ի���
class CMy_CDialog1Dlg : public CDialogEx
{
// ����
public:
	CMy_CDialog1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_CDIALOG1_DIALOG };

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
	afx_msg void OnBnClickedBtnMesbox();
	CEdit m_name_edit;
	afx_msg void OnBnClickedBtnShowOrHide();
	afx_msg void OnBnClickedUpadateTitleBtn();
	afx_msg void OnBnClickedLoginBtn();
	afx_msg void OnBnClickedLoginCancelBtn();
	afx_msg void OnBnClickedEnableBtn();
	afx_msg void OnBnClickedMsgboxBtn();
};
