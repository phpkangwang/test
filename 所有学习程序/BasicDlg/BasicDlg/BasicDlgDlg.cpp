
// BasicDlgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BasicDlg.h"
#include "BasicDlgDlg.h"
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


// CBasicDlgDlg 对话框




CBasicDlgDlg::CBasicDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBasicDlgDlg::IDD, pParent)
	, m_StrComputerName(_T(""))
	, m_TotalMemory(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nDest = 0;
	m_nType = 0;
	m_Computer_HWInfo = _T("");
}

void CBasicDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_DESTINATION_RADIO, m_nDest);
	DDX_Radio(pDX, IDC_HOTLE_TYPE_RADIO, m_nType);
	DDX_Control(pDX, IDC_MOUNTION_CHECK, m_cbMountion);
	DDX_Control(pDX, IDC_SHOPPING_CHECK, m_cbShopping);
	DDX_Control(pDX, IDC_TRAVEL_CHECK, m_cbTravel);
	DDX_Text(pDX, IDC_SHOW_COMPUTER_NAME, m_StrComputerName);
	DDX_Text(pDX, IDC_SHOW_COMPUTER_HWINFO, m_Computer_HWInfo);
	DDX_Text(pDX, IDC_TOTAL_MEMORY, m_TotalMemory);
}

BEGIN_MESSAGE_MAP(CBasicDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SUBMIT_BTN, &CBasicDlgDlg::OnBnClickedSubmitBtn)
	ON_BN_CLICKED(IDC_MOUNTION_CHECK, &CBasicDlgDlg::OnBnClickedMountionCheck)
	ON_BN_CLICKED(IDC_QUERY_COMPUTER_INFO, &CBasicDlgDlg::OnBnClickedQueryComputerInfo)
	ON_BN_CLICKED(IDC_CREATEDLG_BTN, &CBasicDlgDlg::OnBnClickedCreatedlgBtn)
	ON_BN_CLICKED(IDC_CHOOSECOLOR, &CBasicDlgDlg::OnBnClickedChoosecolor)
END_MESSAGE_MAP()


// CBasicDlgDlg 消息处理程序

BOOL CBasicDlgDlg::OnInitDialog()
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

void CBasicDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBasicDlgDlg::OnPaint()
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
HCURSOR CBasicDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBasicDlgDlg::OnBnClickedSubmitBtn()
{
	//将选择的控件的值传给变量
	int nID = GetCheckedRadioButton(IDC_DESTINATION_RADIO,IDC_RADIO4);
	CWnd* pBtn = GetDlgItem(nID);
	CString s;
	pBtn->GetWindowTextW(s);

	
	
	//UpdateData(true);
	///*
	//CString StrDest[] = 
	//{
	//	_T("北京"),
	//	_T("上海"),
	//	_T("郑州"),
	//	_T("深圳")
	//};
	//CString StrType[] = 
	//{
	//	_T("豪华"),
	//	_T("标准"),
	//	_T("经济")
	//};
	//CString s = _T("目的地：") + StrDest[m_nDest] +_T("\n酒店类型：")+ StrType[m_nType];
	//MessageBox(s,_T("选择结果"),MB_ICONINFORMATION);
	//*/

	////获得选定控件
	//CWnd* p1 = GetDlgItem(IDC_DESTINATION_RADIO + m_nDest);
	//CString temp;
	//p1->GetWindowText(temp);
	//CString Text = _T("目的地：") + temp;
	//CWnd* p2 = GetDlgItem(IDC_HOTLE_TYPE_RADIO + m_nType);
	//p2->GetWindowText(temp);
	//Text += _T("\n酒店类型：") + temp;
	//if(m_cbShopping.GetCheck())
	//{
	//	m_cbShopping.GetWindowText(temp);
	//	Text += _T("\n") + temp;
	//}
	//if(m_cbTravel.GetCheck())
	//{
	//	m_cbTravel.GetWindowText(temp);
	//	Text += _T("\n") + temp;
	//}
	//if(m_cbMountion.GetCheck())
	//{
	//	m_cbMountion.GetWindowText(temp);
	//	Text += _T("\n") + temp;
	//}
	//MessageBox(Text,_T("选择结果"),MB_ICONINFORMATION);
}


void CBasicDlgDlg::OnBnClickedMountionCheck()
{
	if(m_cbMountion.GetCheck())
		m_cbTravel.SetCheck(true);
}


void CBasicDlgDlg::OnBnClickedQueryComputerInfo()
{
	_TCHAR name[255];
	DWORD nLen = 255;
	::GetComputerName(name,&nLen);
	m_StrComputerName = name;

	
	HW_PROFILE_INFO info;
	::GetCurrentHwProfile(&info);
	m_Computer_HWInfo = info.szHwProfileGuid;

	MEMORYSTATUS pms;
	GlobalMemoryStatus(&pms);

	m_TotalMemory.Format(_T("%d"),pms.dwMemoryLoad);
	m_TotalMemory += _T("%");

	UpdateData(false);                                                                                                           
}


void CBasicDlgDlg::OnBnClickedCreatedlgBtn()
{
	//MessageBox(_T("hello world"),_T("提示"),MB_YESNOCANCEL|MB_DEFBUTTON2);
	
}


void CBasicDlgDlg::OnBnClickedChoosecolor()
{
	COLORREF color = RGB(255,255,255);
	CColorDialog dlgColor(color);
	if(dlgColor.DoModal() == IDOK)
	{
		color = dlgColor.GetColor();
		this->SetBackgroundColor(color);
	}
}
