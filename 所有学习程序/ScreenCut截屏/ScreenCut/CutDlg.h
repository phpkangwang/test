#pragma once


// CCutDlg �Ի���

class CCutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCutDlg)

public:
	CDC m_mdc;
	CBitmap m_mbmap;
	int m_width;
	int m_height;
	CBitmap* m_oldBmap;
public:
	CPoint m_start;
	CPoint m_end;
	CPoint m_move;
	BOOL bLClicked;
public:
	HCURSOR hCursor;//�ı������ʽ
	DWORD hOldCursor;//
	
	ULONG_PTR m_gdiplusToken;//�����Լ�ж��graphicsʱʹ�õı���
public:
	CCutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCutDlg();

// �Ի�������
	enum { IDD = IDD_CUT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void SaveCutImage(CPoint point);
	afx_msg void OnDestroy();
};
