
// ListControlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ListControl.h"
#include "ListControlDlg.h"
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


// CListControlDlg 对话框




CListControlDlg::CListControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListControlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CONTROL, m_ListControl);
	DDX_Control(pDX, IDC_VIEW_COMBOX, m_ViewCombo);
	DDX_Control(pDX, IDC_DRIVER_COMBO, m_DriveCombo);
}

BEGIN_MESSAGE_MAP(CListControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_VIEW_COMBOX, &CListControlDlg::OnCbnSelchangeViewCombox)
	ON_BN_CLICKED(IDC_SEL_OP_BTN, &CListControlDlg::OnBnClickedSelOpBtn)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CListControlDlg::OnHdnItemclickListControl)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CONTROL, &CListControlDlg::OnNMClickListControl)
	ON_BN_CLICKED(IDC_GETDRIVE_BTN, &CListControlDlg::OnBnClickedGetdriveBtn)
END_MESSAGE_MAP()


// CListControlDlg 消息处理程序

BOOL CListControlDlg::OnInitDialog()
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
	m_ViewCombo.SetCurSel(0);

	CImage image;//将png图片载入
	CString s;
	CBitmap* pBmap = NULL;
	COLORREF c = RGB(0,0,0);
	m_IList.Create(32,32,ILC_COLOR32,5,1);
	for(int i =1;i <=5;i++)
	{
		s.Format(_T("image\\%d.png"),i);
		image.Load(s);
		pBmap = CBitmap::FromHandle(image);
		m_IList.Add(pBmap,c);
		image.Destroy();
	}

	m_ListControl.SetImageList(&m_IList,TVSIL_NORMAL);
	
	m_ListControl.InsertColumn(0,_T("ID"),LVCFMT_CENTER,100);
	m_ListControl.InsertColumn(1,_T("Name"),LVCFMT_CENTER,100);
	m_ListControl.InsertColumn(2,_T("Sex"),LVCFMT_CENTER,100);
	m_ListControl.InsertColumn(3,_T("Age"),LVCFMT_CENTER,100);

	m_ListControl.InsertItem(0,_T("13517"));
	m_ListControl.InsertItem(1,_T("13518"));
	m_ListControl.InsertItem(2,_T("13519"));
	m_ListControl.InsertItem(3,_T("13520"));

	m_ListControl.SetItemText(0,1,_T("孙浩"));
	m_ListControl.SetItemText(0,2,_T("男"));
	m_ListControl.SetItemText(0,3,_T("23"));

	m_ListControl.SetItemText(1,1,_T("张红姐"));
	m_ListControl.SetItemText(1,2,_T("女"));
	m_ListControl.SetItemText(1,3,_T("24"));

	m_ListControl.SetItemText(2,1,_T("张卫卫"));
	m_ListControl.SetItemText(2,2,_T("男"));
	m_ListControl.SetItemText(2,3,_T("25"));

	m_ListControl.SetItemText(3,1,_T("张盼盼"));
	m_ListControl.SetItemText(3,2,_T("男"));
	m_ListControl.SetItemText(3,3,_T("22"));


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CListControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListControlDlg::OnPaint()
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
HCURSOR CListControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListControlDlg::OnCbnSelchangeViewCombox()
{
	int nSel = m_ViewCombo.GetCurSel();
	CString s;
	m_ViewCombo.GetLBText(nSel,s);
	if(s == _T("DETAILS"))
		m_ListControl.SetView(LV_VIEW_DETAILS);
	if(s == _T("ICON"))
		m_ListControl.SetView(LV_VIEW_ICON);
	if(s == _T("LIST"))
		m_ListControl.SetView(LV_VIEW_LIST);
	if(s == _T("SMALLICON"))
		m_ListControl.SetView(LV_VIEW_SMALLICON);
	if(s == _T("TILE"))
		m_ListControl.SetView(LV_VIEW_TILE);

}


void CListControlDlg::OnBnClickedSelOpBtn()
{
	/*//该方法可以进行遍历，若进行删除操作，会出现错误结果
	POSITION pos = m_ListControl.GetFirstSelectedItemPosition();
	while(pos)
	{
		int row = m_ListControl.GetNextSelectedItem(pos);
		m_ListControl.DeleteItem(row);
		CString s = m_ListControl.GetItemText(row,1);
		TRACE( CW2A(s));
		TRACE("\n");
	}*/

	//该方法可以进行遍历，若进行删除操作，不会得到错误结果
	int nItem = -1;
	CString res;
	while(true)
	{
		//删除每次都从-1 行开始查找
		nItem = m_ListControl.GetNextItem(-1,LVNI_SELECTED);
		//遍历从找到的行开始
		//nItem = m_ListControl.GetNextItem(nItem,LVNI_SELECTED);
		if(nItem <0)
			break;
		m_ListControl.DeleteItem(nItem);
		//res = m_ListControl.GetItemText(nItem,1);
		//TRACE( CW2A(res));
		//TRACE("\n");
	}
}


void CListControlDlg::OnHdnItemclickListControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);

	int row = m_ListControl.GetNextItem(-1,LVNI_SELECTED);
	CString res = m_ListControl.GetItemText(row,1);
	MessageBox(res);

	*pResult = 0;
}


void CListControlDlg::OnNMClickListControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	int row = m_ListControl.GetNextItem(-1,LVNI_SELECTED);
	if(row <0)
		return;


	m_ListControl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	CString res = m_ListControl.GetItemText(row,1);
	//MessageBox(res);

	*pResult = 0;
}


void CListControlDlg::OnBnClickedGetdriveBtn()
{
	_TCHAR buf[255];
	::GetLogicalDriveStrings(255,buf);
	_TCHAR* p = buf;
	while(true)
	{
		m_DriveCombo.AddString(p);
		p += _tcslen(p)+1;
		if( _tcscmp(p,_T("")) == 0 )
			break;
	}

}
