
// MyCDCDlg.h : 头文件
//

#pragma once
#include<vector>
using namespace std;

// CMyCDCDlg 对话框
class CMyCDCDlg : public CDialogEx
{
	friend ostream& operator<<(ostream& os,CPoint& point);
	//friend istream& operator>>(istream& is,CPoint& point);
// 构造
public:
	vector<CPoint> m_points;
	CPoint m_pTemp;

public:
	CMyCDCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYCDC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
	afx_msg void OnBnClickedTestBtn();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedSaveimageBtn();
	afx_msg void OnBnClickedCutscreenBtn();
	afx_msg void OnBnClickedSavepointBtn();
	afx_msg void OnBnClickedReadpointBtn();
	afx_msg void OnBnClickedDrawimageBtn();
};
