
// MyCDCDlg.h : ͷ�ļ�
//

#pragma once
#include<vector>
using namespace std;

// CMyCDCDlg �Ի���
class CMyCDCDlg : public CDialogEx
{
	friend ostream& operator<<(ostream& os,CPoint& point);
	//friend istream& operator>>(istream& is,CPoint& point);
// ����
public:
	vector<CPoint> m_points;
	CPoint m_pTemp;

public:
	CMyCDCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYCDC_DIALOG };

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
	afx_msg void OnBnClickedTestBtn();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedSaveimageBtn();
	afx_msg void OnBnClickedCutscreenBtn();
	afx_msg void OnBnClickedSavepointBtn();
	afx_msg void OnBnClickedReadpointBtn();
	afx_msg void OnBnClickedDrawimageBtn();
};
