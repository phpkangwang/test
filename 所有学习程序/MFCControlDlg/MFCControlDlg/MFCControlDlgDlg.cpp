
// MFCControlDlgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCControlDlg.h"
#include "MFCControlDlgDlg.h"
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


// CMFCControlDlgDlg 对话框




CMFCControlDlgDlg::CMFCControlDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCControlDlgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCControlDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_mfcBtn);
	DDX_Control(pDX, IDC_COMBO1, m_CBoxCtrl);
	DDX_Control(pDX, IDC_CITY_TREE, m_CityTree);
}

BEGIN_MESSAGE_MAP(CMFCControlDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCControlDlgDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CMFCControlDlgDlg::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_TREE_OP_BTN, &CMFCControlDlgDlg::OnBnClickedTreeOpBtn)
	ON_BN_CLICKED(IDC_TRAVERASAL_NODE_BTN, &CMFCControlDlgDlg::OnBnClickedTraverasalNodeBtn)
	ON_NOTIFY(TVN_SELCHANGED, IDC_CITY_TREE, &CMFCControlDlgDlg::OnTvnSelchangedCityTree)
	ON_NOTIFY(NM_CLICK, IDC_TREE_IMAGE, &CMFCControlDlgDlg::OnNMClickTreeImage)
//	ON_NOTIFY(NM_SETFOCUS, IDC_TREE_IMAGE, &CMFCControlDlgDlg::OnNMSetfocusTreeImage)
END_MESSAGE_MAP()


// CMFCControlDlgDlg 消息处理程序

BOOL CMFCControlDlgDlg::OnInitDialog()
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

	//设置tree控件的背景色
	m_TreeCtrl.SetBkColor(RGB(100,100,100));
	//CListImage对象的creat
	m_IList.Create(32,32,ILC_COLOR32,4,1);
	//m_IList.SetBkColor(RGB(123,123,123));
	//
	CImage image;//将png图片载入
	CBitmap* pBmap = NULL;
	COLORREF c = RGB(0,0,0);
	CString s;
	for(int i =1;i <=5;i++)
	{
		s.Format(_T("image\\%d.png"),i);
		image.Load(s);
		pBmap = CBitmap::FromHandle(image);
		m_IList.Add(pBmap,c);
		image.Destroy();
	}

	//tree imagelist 关联
	m_TreeCtrl.SetImageList(&m_IList,TVSIL_NORMAL);
	//向tree中插入Item
	HTREEITEM hRoot = m_TreeCtrl.InsertItem(_T("中国"),0,0);
	m_TreeCtrl.InsertItem(_T("河南"),1,1,hRoot);
	m_TreeCtrl.InsertItem(_T("广州"),2,2,hRoot);
	m_TreeCtrl.InsertItem(_T("河北"),3,4,hRoot);


	CBitmap bmap1,bmap2;
	bmap1.LoadBitmap(IDB_NORMAL);
	bmap2.LoadBitmap(IDB_HOT);
	m_mfcBtn.SetImage(IDB_NORMAL,IDB_HOT);
	//m_mfcBtn.SetImage(bmap1,TRUE,bmap2,TRUE);
	//m_mfcBtn.SetBitmap(bmap1);
	//m_mfcBtn.SizeToContent();

	/*
	CImage image1,image2;
	image1.Load(_T("image\\1.png"));
	image2.Load(_T("image\\2.png"));
	m_mfcBtn.SetImage(image1,TRUE,image2);
	m_mfcBtn.SizeToContent();
	*/


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCControlDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCControlDlgDlg::OnPaint()
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
HCURSOR CMFCControlDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCControlDlgDlg::OnBnClickedButton1()
{
	CString s;
	s = _T("孙浩");
	if( IsExist(s) )
		return;
	m_CBoxCtrl.AddString(s);
	s = _T("张红姐");
	if( IsExist(s) )
		return;
	m_CBoxCtrl.AddString(s);
	m_CBoxCtrl.SetCurSel(0);
}


void CMFCControlDlgDlg::OnBnClickedMfcbutton1()
{
	int nSel = m_CBoxCtrl.GetCurSel();
	if(nSel <0)
		return;
	CString s;
	m_CBoxCtrl.GetLBText(nSel,s);
	MessageBox(s);
}


void CMFCControlDlgDlg::OnBnClickedTreeOpBtn()
{
	m_CityTree.DeleteAllItems();
	HTREEITEM hCountry = m_CityTree.InsertItem(_T("中国"));
	HTREEITEM hProvince = m_CityTree.InsertItem(_T("河南省"),hCountry);
	m_CityTree.InsertItem(_T("河北省"),hCountry);
	m_CityTree.InsertItem(_T("北京市"),hCountry);
	m_CityTree.InsertItem(_T("上海市"),hCountry);
	m_CityTree.InsertItem(_T("郑州市"),hProvince);
	m_CityTree.InsertItem(_T("漯河市"),hProvince);
	m_CityTree.InsertItem(_T("新郑市"),hProvince);
	m_CityTree.InsertItem(_T("周口市"),hProvince);
	m_CityTree.InsertItem(_T("南阳市"),hProvince);
	m_CityTree.SetTextColor(RGB(255,0,0));
}


void CMFCControlDlgDlg::OnBnClickedTraverasalNodeBtn()
{
	HTREEITEM hSel = m_CityTree.GetSelectedItem();
	HTREEITEM hChild = m_CityTree.GetNextItem(hSel,TVGN_CHILD);
	CString s;
	while(hChild)
	{
		//get text
		s = m_CityTree.GetItemText(hChild);
		if( IsExist(s) == FALSE )
			m_CBoxCtrl.AddString(s);
		//get brother
		hChild = m_CityTree.GetNextItem(hChild,TVGN_NEXT);
	}
}


bool CMFCControlDlgDlg::IsExist(CString s)
{
	int nCount = m_CBoxCtrl.GetCount();
	CString str;
	for(int i =0;i< nCount;i++)
	{
		m_CBoxCtrl.GetLBText(i,str);
		if(str == s)
			return TRUE;
	}
	return FALSE;
}


void CMFCControlDlgDlg::OnTvnSelchangedCityTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCControlDlgDlg::OnNMClickTreeImage(NMHDR *pNMHDR, LRESULT *pResult)
{
	//HTREEITEM hSel = m_TreeCtrl.GetSelectedItem();
	CPoint pt;
	GetCursorPos(&pt);
	m_TreeCtrl.ScreenToClient(&pt);
	UINT nFlag = TVHT_ONITEMLABEL;

	HTREEITEM hItem = m_TreeCtrl.HitTest(pt,&nFlag);
	if(hItem == NULL)
		return;
	CString s = m_TreeCtrl.GetItemText(hItem);
	MessageBox(s);

	*pResult = 0;
}


//void CMFCControlDlgDlg::OnNMSetfocusTreeImage(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	HTREEITEM hSel = m_TreeCtrl.GetSelectedItem();
//	CString s = m_TreeCtrl.GetItemText(hSel);
//	MessageBox(s);
//	*pResult = 0;
//}
