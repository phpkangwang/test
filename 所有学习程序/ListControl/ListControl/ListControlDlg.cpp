
// ListControlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListControl.h"
#include "ListControlDlg.h"
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


// CListControlDlg �Ի���




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


// CListControlDlg ��Ϣ�������

BOOL CListControlDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_ViewCombo.SetCurSel(0);

	CImage image;//��pngͼƬ����
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

	m_ListControl.SetItemText(0,1,_T("���"));
	m_ListControl.SetItemText(0,2,_T("��"));
	m_ListControl.SetItemText(0,3,_T("23"));

	m_ListControl.SetItemText(1,1,_T("�ź��"));
	m_ListControl.SetItemText(1,2,_T("Ů"));
	m_ListControl.SetItemText(1,3,_T("24"));

	m_ListControl.SetItemText(2,1,_T("������"));
	m_ListControl.SetItemText(2,2,_T("��"));
	m_ListControl.SetItemText(2,3,_T("25"));

	m_ListControl.SetItemText(3,1,_T("������"));
	m_ListControl.SetItemText(3,2,_T("��"));
	m_ListControl.SetItemText(3,3,_T("22"));


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CListControlDlg::OnPaint()
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
	/*//�÷������Խ��б�����������ɾ������������ִ�����
	POSITION pos = m_ListControl.GetFirstSelectedItemPosition();
	while(pos)
	{
		int row = m_ListControl.GetNextSelectedItem(pos);
		m_ListControl.DeleteItem(row);
		CString s = m_ListControl.GetItemText(row,1);
		TRACE( CW2A(s));
		TRACE("\n");
	}*/

	//�÷������Խ��б�����������ɾ������������õ�������
	int nItem = -1;
	CString res;
	while(true)
	{
		//ɾ��ÿ�ζ���-1 �п�ʼ����
		nItem = m_ListControl.GetNextItem(-1,LVNI_SELECTED);
		//�������ҵ����п�ʼ
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
