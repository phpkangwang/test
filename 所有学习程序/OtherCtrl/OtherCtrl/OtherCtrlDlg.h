
// OtherCtrlDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// COtherCtrlDlg �Ի���
class COtherCtrlDlg : public CDialogEx
{
// ����
public:
	COLORREF c;

public:
	COtherCtrlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OTHERCTRL_DIALOG };

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
	CSliderCtrl m_slider;
	CProgressCtrl m_progress;
	afx_msg void OnBnClickedStartBtn();
	afx_msg void OnBnClickedEndBtn();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CSliderCtrl m_rSlider;
	CSliderCtrl m_gSlider;
	CSliderCtrl m_bSlider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnNMThemeChangedProgress(NMHDR *pNMHDR, LRESULT *pResult);
};
