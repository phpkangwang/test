
// CalculatorDlg.h : ͷ�ļ�
//

#pragma once
#include"TCalculate.h"
using namespace TCalLib;
// CCalculatorDlg �Ի���
class CCalculatorDlg : public CDialogEx
{
// ����
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:
	TCalculate cal;

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
	CString m_StrResult;
	void DoInput(int data);
	afx_msg void DoNum0_9(UINT);
	afx_msg void DoOperator(UINT);
	afx_msg void OnBnClickedChangeBtn();
	void Show(double d);
	afx_msg void OnBnClickedPointBtn();

	void DoCompute(char newOp);
	afx_msg void OnBnClickedClearBtn();
	afx_msg void OnBnClickedReciprocalBtn();
	afx_msg void OnBnClickedEvolutionBtn();
	afx_msg void OnBnClickedEqualBtn();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBackBtn();
	CString ChangeToCString(double d);
};
