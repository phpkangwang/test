
// TheardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Theard.h"
#include "TheardDlg.h"
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


// CTheardDlg 对话框




CTheardDlg::CTheardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTheardDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTheardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTheardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CTheardDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_RESUME, &CTheardDlg::OnBnClickedResume)
	ON_BN_CLICKED(IDC_SUSPEND, &CTheardDlg::OnBnClickedSuspend)
	ON_BN_CLICKED(IDC_END, &CTheardDlg::OnBnClickedEnd)
	ON_MESSAGE(WM_Msg,&CTheardDlg::OnMsg)
	ON_BN_CLICKED(IDC_SIGANL, &CTheardDlg::OnBnClickedSiganl)
	ON_BN_CLICKED(IDC_SIGANLEXIT, &CTheardDlg::OnBnClickedSiganlexit)
END_MESSAGE_MAP()


// CTheardDlg 消息处理程序

BOOL CTheardDlg::OnInitDialog()
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

void CTheardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTheardDlg::OnPaint()
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
HCURSOR CTheardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CWinThread*  p = nullptr;
BOOL bContinue = TRUE;
CEvent eventDraw(TRUE);
CEvent eventExit;

UINT __cdecl MyThread( LPVOID pParam )
{
	HWND hw = (HWND) pParam;
	RECT rc;
	GetClientRect(hw,&rc);
	int w = rc.right - rc.left;
	int h = rc.bottom - 60;
	HANDLE hevent[] = { eventDraw,eventExit }; 
	while(bContinue)
	{
		//WaitForSingleObject(et,INFINITE);
	
		DWORD nResult = ::WaitForMultipleObjects(2,hevent,FALSE,INFINITE);
		int nIndex = nResult - WAIT_OBJECT_0;

		if(nIndex == 1)//退出事件被激活
			break;

		//得到DC，
		HDC hdc = GetDC(hw);
		//得到区域的四个点
		int left = rand()%w;
		int top = rand()%h;
		int right = rand()%w;
		int bottom = rand()%h;
		//TRACE("%d,%d,%d,%d\n",left,top,right,bottom);
		//得到随即颜色
		int r = rand()%256;
		int g = rand()%256;
		int b = rand()%256;
		
		HBRUSH br = CreateSolidBrush(RGB(r,g,b));
		HBRUSH oldBr = (HBRUSH)SelectObject(hdc,br);
		HPEN pen = CreatePen(PS_DOT,2,RGB(r,g,b));
		HPEN oldPen = (HPEN)SelectObject(hdc,pen);
		POINT p1 = {rand()%w,rand()%h};
		POINT p2 = {rand()%w,rand()%h};
		POINT p3 = {rand()%w,rand()%h};
		POINT p4 = {rand()%w,rand()%h};
		POINT point[]={	p1,p2,p3,p4	};
		//选择随即画图
		switch(rand()%4)
		{
		case 0:
			{
				Rectangle(hdc,left,top,right,bottom);
			}
			break;
		case 1:
			Ellipse(hdc,left,top,right,bottom);
			break;
		case 2:
			RoundRect(hdc,left,top,right,bottom,15,15);
			break;
		case 3:
			PolyBezier(hdc,point,4);
			break;
		}
		//恢复画刷，释放DC
		SelectObject(hdc,oldBr);
		SelectObject(hdc,oldPen);
		ReleaseDC(hw,hdc);
		//Sleep(400);
	}
	//MessageBox(NULL,_T("启动线程"),_T("线程测试"),MB_OK);
	PostMessage(hw,WM_Msg,0,0);
	return 0;
}
void CTheardDlg::OnBnClickedStart()
{
	//CDC* pDC = GetDC();
	//GetSafeHwnd();
	bContinue = TRUE;
	p = AfxBeginThread(MyThread,m_hWnd);
	//p = AfxBeginThread(MyThread,NULL,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
}

void CTheardDlg::OnBnClickedSiganl()
{
	eventDraw.SetEvent();
}


void CTheardDlg::OnBnClickedSiganlexit()
{
	eventExit.SetEvent();
}

void CTheardDlg::OnBnClickedResume()
{
	if(p)
		p->ResumeThread();

}


void CTheardDlg::OnBnClickedSuspend()
{
	if(p)
		p->SuspendThread();
	eventDraw.ResetEvent();
}


void CTheardDlg::OnBnClickedEnd()
{
	bContinue = FALSE;
	p = nullptr;
}

LRESULT CTheardDlg::OnMsg(WPARAM wParam,LPARAM lParam)
{
	MessageBox(_T("线程被结束啦"));
	return 1;
}