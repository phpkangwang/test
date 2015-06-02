
// GraphicsDlg.h : 头文件
//

#pragma once

#include<vector>
using namespace std;
#include<GdiPlus.h>
using namespace Gdiplus;
// CGraphicsDlg 对话框
class CGraphicsDlg : public CDialogEx
{
public:
	vector<Point> m_pos;
	ULONG_PTR m_gdiplusToken;
	Point m_start;
	Point m_end;
	BOOL bFlag;

// 构造
public:
	CGraphicsDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GRAPHICS_DIALOG };

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedDrawrectBtn();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
