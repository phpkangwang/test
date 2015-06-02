
// MFCSockDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCSock.h"
#include "MFCSockDlg.h"
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


// CMFCSockDlg 对话框




CMFCSockDlg::CMFCSockDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCSockDlg::IDD, pParent),m_sock(this)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_msg = _T("孙浩");
	m_ToIp = _T("192.168.0.16");
	m_ToPort = 8000;
}

void CMFCSockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RECORD_LIST, m_RecordList);
	DDX_Text(pDX, IDC_MSG_RICH, m_msg);
	DDX_Text(pDX, IDC_TOIP_EDIT, m_ToIp);
	DDX_Text(pDX, IDC_TOPORT_EDIT, m_ToPort);
	DDX_Control(pDX, IDC_IP_COMBOX, m_IpCombox);
	DDX_Control(pDX, IDC_PORT_COMBOX, m_PortCombox);
}

BEGIN_MESSAGE_MAP(CMFCSockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND_BTN, &CMFCSockDlg::OnBnClickedSendBtn)
END_MESSAGE_MAP()


// CMFCSockDlg 消息处理程序

BOOL CMFCSockDlg::OnInitDialog()
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

	m_IpCombox.SetCurSel(0);
	m_PortCombox.SetCurSel(0);

	m_sock.Create(8000,SOCK_DGRAM,FD_READ,_T("192.168.0.16"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCSockDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCSockDlg::OnPaint()
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
HCURSOR CMFCSockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSockDlg::OnBnClickedSendBtn()
{
	UpdateData(TRUE);
	if(m_msg == "")
	{
		MessageBox(_T("发送内容不能为空"),_T("提示"),MB_OK|MB_ICONERROR);
		return;
	}
	CStringA sa = CW2A(m_msg);
	CString sIp;
	m_IpCombox.GetWindowText(sIp);
	UINT nPort;
	CString sPort;
	m_PortCombox.GetWindowText(sPort);
	nPort = atoi( CW2A(sPort) );
	
	int nRet = m_sock.SendTo(sa,sa.GetLength()+1,nPort,sIp);
	if(nRet == SOCKET_ERROR)
	{
		int nErrorCode = GetLastError();
		CString sError;
		sError.Format(_T("错误代码为:%d"),nErrorCode);
		MessageBox(sError,_T("提示"),MB_OK|MB_ICONERROR);
		return ;
	}
	//m_sock.SendTo(sa,sa.GetLength()+1,m_ToPort,m_ToIp);
}
