#pragma once
#include "atlimage.h"


// CutDialog �Ի���

class CutDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CutDialog)

public:
	CutDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CutDialog();

// �Ի�������
	enum { IDD = IDD_CUT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
