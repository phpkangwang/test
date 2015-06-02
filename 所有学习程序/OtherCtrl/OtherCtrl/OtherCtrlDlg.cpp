
// OtherCtrlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OtherCtrl.h"
#include "OtherCtrlDlg.h"
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


// COtherCtrlDlg �Ի���




COtherCtrlDlg::COtherCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COtherCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COtherCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER, m_slider);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_RSLIDER, m_rSlider);
	DDX_Control(pDX, IDC_GSLIDER, m_gSlider);
	DDX_Control(pDX, IDC_BSLIDER, m_bSlider);
}

BEGIN_MESSAGE_MAP(COtherCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BTN, &COtherCtrlDlg::OnBnClickedStartBtn)
	ON_BN_CLICKED(IDC_END_BTN, &COtherCtrlDlg::OnBnClickedEndBtn)
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON3, &COtherCtrlDlg::OnBnClickedButton3)
	ON_NOTIFY(NM_THEMECHANGED, IDC_PROGRESS, &COtherCtrlDlg::OnNMThemeChangedProgress)
END_MESSAGE_MAP()


// COtherCtrlDlg ��Ϣ�������

BOOL COtherCtrlDlg::OnInitDialog()
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

	m_slider.SetRange(0,50,TRUE);
	m_progress.SetRange(0,50);


	m_rSlider.SetRange(0,255);
	m_gSlider.SetRange(0,255);
	m_bSlider.SetRange(0,255);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COtherCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COtherCtrlDlg::OnPaint()
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
HCURSOR COtherCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COtherCtrlDlg::OnBnClickedStartBtn()
{
	SetTimer(1,200,NULL);
}


void COtherCtrlDlg::OnBnClickedEndBtn()
{
	KillTimer(1);
}


void COtherCtrlDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == 1)
	{
		int nPos = m_slider.GetPos();
		m_slider.SetPos(nPos+1);
		m_progress.SetPos(nPos+1);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void COtherCtrlDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
	if(pSlider == &m_rSlider || pSlider == &m_gSlider || pSlider == &m_bSlider)
	{
		int r = m_rSlider.GetPos();
		int g = m_gSlider.GetPos();
		int b = m_bSlider.GetPos();
		c = RGB(r,g,b);
		this->SetBackgroundColor(c);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void COtherCtrlDlg::OnBnClickedButton3()
{
	int n = m_rSlider.GetPageSize();
	m_progress.SetBkColor(RGB(255,0,255));
	m_progress.SetBarColor(RGB(0,255,0));
}


void COtherCtrlDlg::OnNMThemeChangedProgress(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
