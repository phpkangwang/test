// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabCtrl.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg �Ի���

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg::IDD, pParent)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg ��Ϣ�������


BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	tab.Create(WS_CHILD|WS_VISIBLE,CRect(10,10,400,400),this,1218);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
