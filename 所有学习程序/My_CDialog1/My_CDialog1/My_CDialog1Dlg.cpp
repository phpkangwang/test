
// My_CDialog1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "My_CDialog1.h"
#include "My_CDialog1Dlg.h"
#include "afxdialogex.h"
#include <sstream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy_CDialog1Dlg 对话框




CMy_CDialog1Dlg::CMy_CDialog1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy_CDialog1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy_CDialog1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME_EDIT, m_name_edit);
}

BEGIN_MESSAGE_MAP(CMy_CDialog1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_MESBOX, &CMy_CDialog1Dlg::OnBnClickedBtnMesbox)
	ON_BN_CLICKED(IDC_BTN_SHOW_OR_HIDE, &CMy_CDialog1Dlg::OnBnClickedBtnShowOrHide)
	ON_BN_CLICKED(IDC_UPADATE_TITLE_BTN, &CMy_CDialog1Dlg::OnBnClickedUpadateTitleBtn)
	ON_BN_CLICKED(IDC_LOGIN_BTN, &CMy_CDialog1Dlg::OnBnClickedLoginBtn)
	ON_BN_CLICKED(IDC_LOGIN_CANCEL_BTN, &CMy_CDialog1Dlg::OnBnClickedLoginCancelBtn)
	ON_BN_CLICKED(IDC_ENABLE_BTN, &CMy_CDialog1Dlg::OnBnClickedEnableBtn)
	ON_BN_CLICKED(IDC_MSGBOX_BTN, &CMy_CDialog1Dlg::OnBnClickedMsgboxBtn)
END_MESSAGE_MAP()


// CMy_CDialog1Dlg 消息处理程序

BOOL CMy_CDialog1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy_CDialog1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy_CDialog1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy_CDialog1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy_CDialog1Dlg::OnBnClickedBtnMesbox()
{
	CMy_CDialog1App* p = (CMy_CDialog1App*)::AfxGetApp();
	int n = p->m_nData;

	//STL
	wostringstream oss;
	oss<<n;
	wstring ss = oss.str();
	if( MessageBox(_T("是否显示"),_T("提示"),MB_YESNO |MB_ICONWARNING) == IDYES )
	{
		MessageBox(ss.c_str(),_T("数据"));
	}
	/*CString s;
	s.Format(_T("m_nData = %d"),n);

	MessageBox(s,_T("数据"),MB_OKCANCEL |MB_ICONWARNING);*/

	/*if(MessageBox(_T("我的名字叫孙浩"),_T("信息提示"),MB_OKCANCEL|MB_ICONWARNING) == IDOK)
	{
		MessageBox(_T("我的名字叫孙浩"));
	}
	else
	{
		MessageBox(_T("I LOVE YOU"));
	}*/
	//::MessageBox();
	//::AfxMessageBox(_T("信息显示"));
}


void CMy_CDialog1Dlg::OnBnClickedBtnShowOrHide()
{
	if(m_name_edit.IsWindowVisible())
		m_name_edit.ShowWindow(SW_HIDE);
	else
		m_name_edit.ShowWindow(SW_SHOW);
}


void CMy_CDialog1Dlg::OnBnClickedUpadateTitleBtn()
{
	CWnd* pEdit = GetDlgItem(IDC_TITLE_EDIT);
	CString s;
	pEdit->GetWindowText(s);
	pEdit->SetWindowText(_T(""));
	CWnd* pBtn = GetDlgItem(IDC_ISUPDATE_TITLE_BTN);
	pBtn->SetWindowText(s);
}


void CMy_CDialog1Dlg::OnBnClickedLoginBtn()
{
	//得到名字
	CWnd* pEdit = GetDlgItem(IDC_LOGIN_NAME_EDIT);
	CString name;
	pEdit->GetWindowText(name);
	//得到密码
	pEdit = GetDlgItem(IDC_LOGIN_PASSWORD_EDIT);
	CString password;
	pEdit->GetWindowText(password);
	if(name == "孙浩" && password == "1218")
	{

	}
	else
		MessageBox(_T("用户名或密码错误"),_T("错误提示"),MB_ICONHAND);

}


void CMy_CDialog1Dlg::OnBnClickedLoginCancelBtn()
{
	CWnd* pEdit = GetDlgItem(IDC_LOGIN_NAME_EDIT);
	pEdit->SetWindowText(_T(""));
	//得到密码
	pEdit = GetDlgItem(IDC_LOGIN_PASSWORD_EDIT);
	pEdit->SetWindowText(_T(""));
}


void CMy_CDialog1Dlg::OnBnClickedEnableBtn()
{
	CWnd* pBtn = GetDlgItem(IDC_MSGBOX_BTN);
	pBtn->EnableWindow(!IsWindowEnabled());
	CString text = pBtn->IsWindowEnabled()?_T("禁用"):_T("启用");
	GetDlgItem(IDC_ENABLE_BTN)->SetWindowText(text);
}


void CMy_CDialog1Dlg::OnBnClickedMsgboxBtn()
{
	MessageBox(_T("QWERTY"));
}
