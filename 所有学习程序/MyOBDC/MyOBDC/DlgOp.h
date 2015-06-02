#pragma once
#include "afxwin.h"


// DlgOp 对话框

class DlgOp : public CDialogEx
{
	DECLARE_DYNAMIC(DlgOp)

public:
	DlgOp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgOp();

// 对话框数据
	enum { IDD = IDD_OpDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_age;
//	CTime m_birth;
	CString m_id;
	CString m_name;
public:
	virtual BOOL OnInitDialog();
	// 对话框标题
	CString m_strCaption;
	CEdit m_EnableEdit;
	COleDateTime m_birth;
};
