
// SockFileDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SockFile.h"
#include "SockFileDlg.h"
#include "afxdialogex.h"

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


// CSockFileDlg 对话框




CSockFileDlg::CSockFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSockFileDlg::IDD, pParent),m_sock(this)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_msg = _T("孙浩");
	m_nToPort = 9000;
	m_sToIp = _T("192.168.0.16");
	m_nMyPort = 8000;
	m_sMyIp = _T("192.168.0.16");

}

void CSockFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MSG_EDIT, m_msg);
	DDX_Control(pDX, IDC_RECORD_LIST, m_RecordList);
	DDX_Text(pDX, IDC_TOPORT, m_nToPort);
	DDX_Text(pDX, IDC_TOIP, m_sToIp);
	DDX_Text(pDX, IDC_MYPORT, m_nMyPort);
	DDX_Text(pDX, IDC_MYIP, m_sMyIp);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
}

BEGIN_MESSAGE_MAP(CSockFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INIT, &CSockFileDlg::OnBnClickedInit)
	ON_BN_CLICKED(IDC_SEND, &CSockFileDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_SENDFILE, &CSockFileDlg::OnBnClickedSendfile)
	ON_BN_CLICKED(IDC_CANCEL_SENDFILE_BTN, &CSockFileDlg::OnBnClickedCancelSendfileBtn)
END_MESSAGE_MAP()


// CSockFileDlg 消息处理程序

BOOL CSockFileDlg::OnInitDialog()
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

void CSockFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSockFileDlg::OnPaint()
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
HCURSOR CSockFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSockFileDlg::OnBnClickedInit()
{
	UpdateData(TRUE);
	m_sock.Create(m_nMyPort, SOCK_DGRAM,FD_READ,m_sMyIp);
	CWnd* p = GetDlgItem(IDC_INIT);
	p->EnableWindow(FALSE);
}


void CSockFileDlg::OnBnClickedSend()
{
	UpdateData(TRUE);
	m_msg;
	CStringA sa = CW2A(m_msg);
	sa = "000" + sa;
	m_sock.SendTo(sa,sa.GetLength()+1,m_nToPort,m_sToIp);
}


void CSockFileDlg::OnBnClickedSendfile()
{
	UpdateData(TRUE);
//	if(m_sock.m_nCount>9)

	if(m_sock.m_fp == NULL)
	{
		//发送文件
		CFileDialog fd(TRUE);
		if(fd.DoModal() == IDCANCEL)//取消发送
			return;
		CStringA Name = CW2A( fd.GetFileName() );
		m_sock.m_fp = fopen(Name,"rb");
		fseek(m_sock.m_fp,0,SEEK_END);
		long nSize = ftell(m_sock.m_fp);
		//设置进度条
		m_progress.SetRange32(0,nSize);
		m_progress.SetPos(0);

		CString size;
		size.Format(_T("%d"),nSize);
		fseek(m_sock.m_fp,0,SEEK_SET);

		CStringA sa = "111";
		sa += Name;
		sa += '#';
		sa += CW2A(size);
		m_sock.SendTo(sa,sa.GetLength()+1,m_nToPort,m_sToIp);
	}
	else
	{
		//MessageBox(_T("正在发送"));

	}
}


void CSockFileDlg::OnBnClickedCancelSendfileBtn()
{
	UpdateData();
	if(m_sock.m_fp == NULL)
	{
		//没有正在发送文件,处理
		return;
	}
	else
	{
		m_sock.SendTo("555",4,m_nToPort,m_sToIp);
		fclose(m_sock.m_fp);
		m_sock.m_fp = NULL;
		m_progress.SetPos(0);
	}
}
