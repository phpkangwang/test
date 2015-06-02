
// MyOBDCDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMyOBDCDlg 对话框
class CMyOBDCDlg : public CDialogEx
{
// 构造
public:
	CMyOBDCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYOBDC_DIALOG };

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
	CListCtrl m_DataList;
	afx_msg void OnBnClickedQuerydataBtn();
	afx_msg void OnBnClickedAddBtn();
	afx_msg void OnBnClickedDeleteBtn();
	afx_msg void OnBnClickedUpdateBtn();
	void ShowData();
	CTime CStringToCtime(CString& s);
	COleDateTime CStringToCOleDateTime(CString s);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void DlgSizeChange(int,int);
	afx_msg void OnNMRClickShowdataList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnReflesh();
	afx_msg void OnBnClickedListStyle();
	int m_nStyle;
	afx_msg void OnDetailinfo();
	afx_msg void OnThumbanail();
	afx_msg void OnTile();
	afx_msg void OnListing();
	afx_msg void OnIcon();
	void InitImageList(void);
	CImageList m_ImgList;
//	afx_msg void OnLvnItemchangedShowdataList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickShowdataList(NMHDR *pNMHDR, LRESULT *pResult);
};
