
// GDIGifDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GDIGif.h"
#include "GDIGifDlg.h"
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


// CGDIGifDlg 对话框




CGDIGifDlg::CGDIGifDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIGifDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGDIGifDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGDIGifDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGDIGifDlg 消息处理程序

BOOL CGDIGifDlg::OnInitDialog()
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

	//加载gdi
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	//信息从配置文件中读取
	_TCHAR ret[100];
	CString section = _T("Gif");
	CString keyName = _T("文件名");
	DWORD nRet = GetPrivateProfileString(
		section,
		keyName,
		_T(""),
		ret,100,
		_T("F:\\set.ini")
		);
	/*if(nRet == 0)
	{
		MessageBox(_T(""),_T(""),MB_OK);
		return FALSE;
	}*/
	//载入图片
	CString path;
	path.Format(_T("image\\%s"),ret);
	m_pImg = Image::FromFile(path);
	//得到尺寸数
	UINT nDimenCount = m_pImg->GetFrameDimensionsCount();
	m_pDimenGUID = new GUID[nDimenCount];
	//得到尺寸帧数
	m_pImg->GetFrameDimensionsList(m_pDimenGUID,nDimenCount);
	//根据尺寸关键字GUID
	m_nFrameCount = m_pImg->GetFrameCount(m_pDimenGUID);
	//设置当前的帧
	m_nIndex = 0;
	//启动时间器
	SetTimer(1,100,NULL);
	//


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGDIGifDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(1 == nIDEvent)
	{
		Invalidate();
	}

	CDialogEx::OnTimer(nIDEvent);
}




void CGDIGifDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGDIGifDlg::OnPaint()
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

		m_nIndex++;
		if((UINT)m_nIndex >= m_nFrameCount)
			m_nIndex = 0;
		m_pImg->SelectActiveFrame(m_pDimenGUID,m_nIndex);
		
		CClientDC dc(this);
		Graphics g(dc);

		PointF point(50,50);
		g.DrawImage(m_pImg,point);

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGDIGifDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}