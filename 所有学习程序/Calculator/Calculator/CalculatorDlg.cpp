
// CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#include <string>
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


// CCalculatorDlg 对话框


CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
	, m_StrResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_StrResult = _T("0.");
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOW_EDIT, m_StrResult);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(IDC_BUTTON0,IDC_BUTTON9,&CCalculatorDlg::DoNum0_9)
	ON_COMMAND_RANGE(IDC_RIDE_BTN,IDC_DIVIDE_BTN,&CCalculatorDlg::DoOperator)
	
	ON_BN_CLICKED(IDC_CHANGE_BTN, &CCalculatorDlg::OnBnClickedChangeBtn)
	ON_BN_CLICKED(IDC_POINT_BTN, &CCalculatorDlg::OnBnClickedPointBtn)
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CCalculatorDlg::OnBnClickedClearBtn)
	ON_BN_CLICKED(IDC_RECIPROCAL_BTN, &CCalculatorDlg::OnBnClickedReciprocalBtn)
	ON_BN_CLICKED(IDC_EVOLUTION_BTN, &CCalculatorDlg::OnBnClickedEvolutionBtn)
	ON_BN_CLICKED(IDC_EQUAL_BTN, &CCalculatorDlg::OnBnClickedEqualBtn)
	ON_BN_CLICKED(IDC_BACK_BTN, &CCalculatorDlg::OnBnClickedBackBtn)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::DoNum0_9(UINT d)
{
	DoInput(d - IDC_BUTTON0);
}

void CCalculatorDlg::DoOperator(UINT d)
{
	CWnd* p = GetDlgItem(d);
	CString s;
	p->GetWindowText(s);
	DoCompute( s.GetAt(0) );
}

void CCalculatorDlg::DoInput(int data)
{
	double m_dRight = cal.DoInput(data);
	Show(m_dRight);
}

void CCalculatorDlg::OnBnClickedChangeBtn()
{
	double m_dRight = cal.QuFan();
	Show(m_dRight);
}


void CCalculatorDlg::Show(double d)
{
	CString s_Coff;
	double m_dCoff = cal.GetCoff();
	if( m_dCoff != 1.0)
	{
		s_Coff.Format(_T("%.30f"),m_dCoff);
		int ncoff = s_Coff.Find('1') - 2;
		CString s;
		s.Format(_T("%d"),ncoff);
		s = _T("%.") + s;
		s += _T("f");
		m_StrResult.Format(s,d);
	}
	else
	{
		m_StrResult.Format(_T("%f"),d);
		int nLen = m_StrResult.GetLength() - 1;
		while(true)
		{
			if( m_StrResult[nLen] == '0')
			{
				m_StrResult.Delete(nLen);
				nLen--;
			}
			else
				break;
		}
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedPointBtn()
{
	cal.ChangeCoff();
}

void CCalculatorDlg::DoCompute(char newOp)
{
	//显示
	double m_dLeft = cal.DoCalculate(newOp);
	Show(m_dLeft);
	
}


void CCalculatorDlg::OnBnClickedClearBtn()
{
	cal.Init();
	Show(0);
}

CString CCalculatorDlg::ChangeToCString(double d)
{
	CString s ;
	s.Format(_T("%f"),d);
	int nLen = s.GetLength() - 1;
	while(true)
	{
		if( s[nLen] == '0')
		{
			s.Delete(nLen);
			nLen--;
		}
		else
			break;
	}
	return s;
}


void CCalculatorDlg::OnBnClickedReciprocalBtn()
{
	//倒数
	double d = cal.Recip(m_StrResult);
	Show(d);
}


void CCalculatorDlg::OnBnClickedEvolutionBtn()
{
	//开方
	/*CString s = ChangeToCString(m_dLeft);
	if(m_StrResult == s)
	{
		m_dLeft = sqrt(m_dLeft);
		Show(m_dLeft);
	}
	else
	{
		m_dRight = sqrt(m_dRight);
		Show(m_dRight);
	}*/
	double d =cal.Evol( _wtof(m_StrResult) );
	Show(d);
}


void CCalculatorDlg::OnBnClickedEqualBtn()
{
	DoCompute('=');
}


BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_CHAR)
	{
		if(pMsg->wParam >='0'&&pMsg->wParam <='9')
		{
			DoInput(pMsg->wParam - '0');
			CWnd* p = GetDlgItem(IDC_BUTTON0 + pMsg->wParam - '0');
			p->SetFocus();
			return TRUE;
		}
	}
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_ADD)
		{
			DoCompute('+');
			return TRUE;
		}
		if(pMsg->wParam == VK_SUBTRACT)
		{
			if(GetKeyState(VK_SHIFT) & 8000)
			{
				OnBnClickedChangeBtn();
			}
			else
			{
				DoCompute('-');
				return TRUE;
			}
		}
		if(pMsg->wParam == VK_MULTIPLY)
		{
			DoCompute('*');
			return TRUE;
		}
		if(pMsg->wParam == VK_DIVIDE)
		{
			DoCompute('/');
			return TRUE;
		}
		if(pMsg->wParam == VK_RETURN)
		{
			DoCompute('=');
			CWnd* p = GetDlgItem(IDC_EQUAL_BTN);
			p->SetFocus();
			return TRUE;
		}
		if(pMsg->wParam == VK_DECIMAL)
		{
			OnBnClickedPointBtn();
			return TRUE;
		}
		/*if( (GetKeyState(VK_SHIFT) & 8000) && pMsg->wParam == VK_SUBTRACT)
		{
			OnBnClickedChangeBtn();
			return TRUE;
		}*/
		if(pMsg->wParam == VK_BACK)
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CCalculatorDlg::OnBnClickedBackBtn()
{
	
}