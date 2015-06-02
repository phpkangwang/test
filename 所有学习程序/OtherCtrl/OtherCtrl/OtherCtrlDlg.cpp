
// OtherCtrlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OtherCtrl.h"
#include "OtherCtrlDlg.h"
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


// COtherCtrlDlg 对话框




COtherCtrlDlg::COtherCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COtherCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COtherCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER, m_slider);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_RSLIDER, m_rSlider);
	DDX_Control(pDX, IDC_GSLIDER, m_gSlider);
	DDX_Control(pDX, IDC_BSLIDER, m_bSlider);
}

BEGIN_MESSAGE_MAP(COtherCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BTN, &COtherCtrlDlg::OnBnClickedStartBtn)
	ON_BN_CLICKED(IDC_END_BTN, &COtherCtrlDlg::OnBnClickedEndBtn)
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON3, &COtherCtrlDlg::OnBnClickedButton3)
	ON_NOTIFY(NM_THEMECHANGED, IDC_PROGRESS, &COtherCtrlDlg::OnNMThemeChangedProgress)
END_MESSAGE_MAP()


// COtherCtrlDlg 消息处理程序

BOOL COtherCtrlDlg::OnInitDialog()
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

	m_slider.SetRange(0,50,TRUE);
	m_progress.SetRange(0,50);


	m_rSlider.SetRange(0,255);
	m_gSlider.SetRange(0,255);
	m_bSlider.SetRange(0,255);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COtherCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COtherCtrlDlg::OnPaint()
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
HCURSOR COtherCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COtherCtrlDlg::OnBnClickedStartBtn()
{
	SetTimer(1,200,NULL);
}


void COtherCtrlDlg::OnBnClickedEndBtn()
{
	KillTimer(1);
}


void COtherCtrlDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == 1)
	{
		int nPos = m_slider.GetPos();
		m_slider.SetPos(nPos+1);
		m_progress.SetPos(nPos+1);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void COtherCtrlDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
	if(pSlider == &m_rSlider || pSlider == &m_gSlider || pSlider == &m_bSlider)
	{
		int r = m_rSlider.GetPos();
		int g = m_gSlider.GetPos();
		int b = m_bSlider.GetPos();
		c = RGB(r,g,b);
		this->SetBackgroundColor(c);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void COtherCtrlDlg::OnBnClickedButton3()
{
	int n = m_rSlider.GetPageSize();
	m_progress.SetBkColor(RGB(255,0,255));
	m_progress.SetBarColor(RGB(0,255,0));
}


void COtherCtrlDlg::OnNMThemeChangedProgress(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
