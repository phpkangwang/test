
// ThreadSynDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ThreadSyn.h"
#include "ThreadSynDlg.h"
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


// CThreadSynDlg 对话框




CThreadSynDlg::CThreadSynDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThreadSynDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadSynDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CThreadSynDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CThreadSynDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CThreadSynDlg 消息处理程序

BOOL CThreadSynDlg::OnInitDialog()
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

void CThreadSynDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThreadSynDlg::OnPaint()
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
HCURSOR CThreadSynDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CEvent eventGo;
CWinThread* p = nullptr;
int nTheard = 0;

CCriticalSection cs;
CMutex mu;
CSingleLock sl(&mu);

CSemaphore sp(2,5);


UINT _cdecl MyThreadSyn(LPVOID pParam)
{
	//临界区
	//cs.Lock();
	//
	//mu.Lock();
	//
	//sp.Lock();
	HWND hw = (HWND) pParam;
	//加载图片
	Image* pImg;
	pImg = Image::FromFile(L"image\\loading.gif");
	//得到图片的尺寸数量
	UINT nDimenCount = pImg->GetFrameDimensionsCount();
	//分配空间GUID
	GUID* pGuid = new GUID[nDimenCount];
	//得到GUID
	pImg->GetFrameDimensionsList(pGuid,nDimenCount);
	//得到根据一个GUID得到该ＧＵＩＤ的图片帧数
	UINT nFrameCount = pImg->GetFrameCount(pGuid+0);
	//设置画出哪一帧
	UINT nIndex = 0;
	//每个图的区域
	int xBox = 80;
	int yBox = 80;
	//得到客户区
	RECT rc;
	GetClientRect(hw,&rc);
	int w = rc.right;
	int h = rc.bottom;
	//
	int nRow = w /xBox;
	int x = (nTheard %nRow) *xBox;
	int y = nTheard /nRow *yBox;
	
	nTheard++;
	Graphics g(hw);
	int nLoop = 20;
	while(true)
	{
		//WaitForSingleObject(eventGo,100);
		if(nIndex == nFrameCount)
			nIndex = 0;
		pImg->SelectActiveFrame(pGuid,nIndex);
		g.DrawImage(pImg,x,y);
		nIndex++;
		nLoop--;
		if(nLoop<0)
			break;
		Sleep(200);
	}
	
	//cs.Unlock();
	//mu.Unlock();
	//sp.Unlock();

	return 1;
}


void CThreadSynDlg::OnBnClickedStart()
{
	p = AfxBeginThread(MyThreadSyn,m_hWnd);
	//
	eventGo.SetEvent();
}	
