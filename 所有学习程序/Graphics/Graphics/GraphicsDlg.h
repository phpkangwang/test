
// GraphicsDlg.h : ͷ�ļ�
//

#pragma once

#include<vector>
using namespace std;
#include<GdiPlus.h>
using namespace Gdiplus;
// CGraphicsDlg �Ի���
class CGraphicsDlg : public CDialogEx
{
public:
	vector<Point> m_pos;
	ULONG_PTR m_gdiplusToken;
	Point m_start;
	Point m_end;
	BOOL bFlag;

// ����
public:
	CGraphicsDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GRAPHICS_DIALOG };

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedDrawrectBtn();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
