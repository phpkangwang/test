#pragma once
#include "atlimage.h"


// CutDialog 对话框

class CutDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CutDialog)

public:
	CutDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CutDialog();

// 对话框数据
	enum { IDD = IDD_CUT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CImage* m_img;
	CPoint m_startp;
	CPoint m_endp;
	BOOL bFlag;
	CPoint m_temp;

public:
	virtual BOOL OnInitDialog();
	void GetImage(CImage* img);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};
