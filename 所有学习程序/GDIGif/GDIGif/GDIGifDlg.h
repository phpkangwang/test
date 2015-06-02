
// GDIGifDlg.h : 头文件
//

#pragma once
#include <gdiplus.h>
using namespace Gdiplus;


// CGDIGifDlg 对话框
class CGDIGifDlg : public CDialogEx
{
// 构造
public:
	Image* m_pImg;//图片
	GUID * m_pDimenGUID;//
	UINT m_nFrameCount;//
	int m_nIndex;//当前帧
public:
	int m_x;
	int m_y;
public:
	CGDIGifDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GDIGIF_DIALOG };

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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
