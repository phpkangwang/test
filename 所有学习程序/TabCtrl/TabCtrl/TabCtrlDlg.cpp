
// TabCtrlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TabCtrl.h"
#include "TabCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTabCtrlDlg �Ի���




CTabCtrlDlg::CTabCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_TabCtrl);
}

BEGIN_MESSAGE_MAP(CTabCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CTabCtrlDlg::OnTcnSelchangeTab)
	ON_BN_CLICKED(IDC_SHOW_BTN, &CTabCtrlDlg::OnBnClickedShowBtn)
	ON_BN_CLICKED(IDC_SHOW, &CTabCtrlDlg::OnBnClickedShow)
END_MESSAGE_MAP()


// CTabCtrlDlg ��Ϣ�������

BOOL CTabCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	//
	
	Imglst.Create(16,16,ILC_COLOR32,3,1);

	COLORREF c = RGB(255,255,255);
	CImage img;
	CBitmap* bmap;

	img.Load(_T("images\\1.png"));
	bmap =  CBitmap::FromHandle(img);
	Imglst.Add(bmap,c);
	img.Destroy();

	img.Load(_T("images\\2.png"));
	bmap =  CBitmap::FromHandle(img);
	Imglst.Add(bmap,c);
	img.Destroy();

	img.Load(_T("images\\3.png"));
	bmap =  CBitmap::FromHandle(img);
	Imglst.Add(bmap,c);
	img.Destroy();

	m_TabCtrl.SetImageList(&Imglst);

	m_TabCtrl.InsertItem(0,_T("��ǩ0"),0);
	m_TabCtrl.InsertItem(1,_T("��ǩ1"),1);
	m_TabCtrl.InsertItem(2,_T("��ǩ2"),2);
	m_TabCtrl.SetCurSel(0);
	m_nSel = 0;

	CRect rc;
	GetWindowRect(rc);

	m_dlg1.Create(CDlg1::IDD,&m_TabCtrl);
	m_dlg2.Create(CDlg2::IDD,&m_TabCtrl);
	m_dlg3.Create(CDlg3::IDD,&m_TabCtrl);

	m_dlg1.SetWindowPos(NULL,2,22,rc.Width()-4,rc.Height()-26,SWP_SHOWWINDOW);
	m_dlg2.SetWindowPos(NULL,2,22,rc.Width()-4,rc.Height()-26,SWP_SHOWWINDOW);
	m_dlg3.SetWindowPos(NULL,2,22,rc.Width()-4,rc.Height()-26,SWP_SHOWWINDOW);

	m_dlg1.ShowWindow(SW_SHOW);
	m_dlg2.ShowWindow(SW_HIDE);
	m_dlg3.ShowWindow(SW_HIDE);
	//
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTabCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTabCtrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTabCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTabCtrlDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	CDialog* dlg[]=
	{
		&m_dlg1,
		&m_dlg2,
		&m_dlg3
	};
	int n = m_TabCtrl.GetCurSel();
	//��ǰ��ʾ
	dlg[n]->ShowWindow(SW_SHOW);
	//��ǰ��ʾ������
	dlg[m_nSel]->ShowWindow(SW_HIDE);
	m_nSel = n;
	*pResult = 0;
}

#include "TestDlg.h"
void CTabCtrlDlg::OnBnClickedShowBtn()
{
	CTestDlg dlg;
	dlg.DoModal();
	//tab.Create(WS_CHILD|WS_VISIBLE,CRect(10,10,400,400),this,1218);
}


#include "PropSheet.h"
void CTabCtrlDlg::OnBnClickedShow()
{
	CPropSheet ps(_T("��������"));
	ps.DoModal();
}
