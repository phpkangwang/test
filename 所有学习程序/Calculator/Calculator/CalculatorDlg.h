
// CalculatorDlg.h : 头文件
//

#pragma once
#include"TCalculate.h"
using namespace TCalLib;
// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:
	TCalculate cal;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
