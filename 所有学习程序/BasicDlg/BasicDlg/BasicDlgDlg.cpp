
// BasicDlgDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BasicDlg.h"
#include "BasicDlgDlg.h"
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


// CBasicDlgDlg �Ի���




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


// CBasicDlgDlg ��Ϣ�������

BOOL CBasicDlgDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBasicDlgDlg::OnPaint()
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
HCURSOR CBasicDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBasicDlgDlg::OnBnClickedSubmitBtn()
{
	//��ѡ��Ŀؼ���ֵ��������
	int nID = GetCheckedRadioButton(IDC_DESTINATION_RADIO,IDC_RADIO4);
	CWnd* pBtn = GetDlgItem(nID);
	CString s;
	pBtn->GetWindowTextW(s);

	
	
	//UpdateData(true);
	///*
	//CString StrDest[] = 
	//{
	//	_T("����"),
	//	_T("�Ϻ�"),
	//	_T("֣��"),
	//	_T("����")
	//};
	//CString StrType[] = 
	//{
	//	_T("����"),
	//	_T("��׼"),
	//	_T("����")
	//};
	//CString s = _T("Ŀ�ĵأ�") + StrDest[m_nDest] +_T("\n�Ƶ����ͣ�")+ StrType[m_nType];
	//MessageBox(s,_T("ѡ����"),MB_ICONINFORMATION);
	//*/

	////���ѡ���ؼ�
	//CWnd* p1 = GetDlgItem(IDC_DESTINATION_RADIO + m_nDest);
	//CString temp;
	//p1->GetWindowText(temp);
	//CString Text = _T("Ŀ�ĵأ�") + temp;
	//CWnd* p2 = GetDlgItem(IDC_HOTLE_TYPE_RADIO + m_nType);
	//p2->GetWindowText(temp);
	//Text += _T("\n�Ƶ����ͣ�") + temp;
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
	//MessageBox(Text,_T("ѡ����"),MB_ICONINFORMATION);
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
	//MessageBox(_T("hello world"),_T("��ʾ"),MB_YESNOCANCEL|MB_DEFBUTTON2);
	
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
