#pragma once
#include "afxwin.h"


// DlgOp �Ի���

class DlgOp : public CDialogEx
{
	DECLARE_DYNAMIC(DlgOp)

public:
	DlgOp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgOp();

// �Ի�������
	enum { IDD = IDD_OpDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_age;
//	CTime m_birth;
	CString m_id;
	CString m_name;
public:
	virtual BOOL OnInitDialog();
	// �Ի������
	CString m_strCaption;
	CEdit m_EnableEdit;
	COleDateTime m_birth;
};
