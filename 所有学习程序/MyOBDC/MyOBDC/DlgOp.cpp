// DlgOp.cpp : 实现文件
//

#include "stdafx.h"
#include "MyOBDC.h"
#include "DlgOp.h"
#include "afxdialogex.h"


// DlgOp 对话框

IMPLEMENT_DYNAMIC(DlgOp, CDialogEx)

DlgOp::DlgOp(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgOp::IDD, pParent)
{

	m_age = 0;
	m_id = _T("");
	m_name = _T("");
	m_strCaption = _T("添加学生信息");
	m_birth = COleDateTime::GetCurrentTime();
}

DlgOp::~DlgOp()
{
}

void DlgOp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_AGE, m_age);
	//  DDX_DateTimeCtrl(pDX, IDC_BIRTH, m_birth);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Control(pDX, IDC_ID, m_EnableEdit);
	DDX_DateTimeCtrl(pDX, IDC_BIRTH, m_birth);
}


BEGIN_MESSAGE_MAP(DlgOp, CDialogEx)
END_MESSAGE_MAP()


// DlgOp 消息处理程序


BOOL DlgOp::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetWindowText(m_strCaption);
	if(m_strCaption == _T("修改学生信息"))
	{
		m_EnableEdit.SetReadOnly(TRUE);
		HICON icon = theApp.LoadIcon(IDI_UPDATEICON);
		SetIcon(icon,TRUE);
		SetIcon(icon,FALSE);
	}
	else
	{
		//set icon
		HICON icon = theApp.LoadIcon(IDI_ADDICON);
		SetIcon(icon,TRUE);
		SetIcon(icon,FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
