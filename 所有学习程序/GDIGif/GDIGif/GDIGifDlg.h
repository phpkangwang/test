
// GDIGifDlg.h : ͷ�ļ�
//

#pragma once
#include <gdiplus.h>
using namespace Gdiplus;


// CGDIGifDlg �Ի���
class CGDIGifDlg : public CDialogEx
{
// ����
public:
	Image* m_pImg;//ͼƬ
	GUID * m_pDimenGUID;//
	UINT m_nFrameCount;//
	int m_nIndex;//��ǰ֡
public:
	int m_x;
	int m_y;
public:
	CGDIGifDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GDIGIF_DIALOG };

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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
