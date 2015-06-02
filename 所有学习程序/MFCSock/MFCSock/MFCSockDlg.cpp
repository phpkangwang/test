
// MFCSockDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCSock.h"
#include "MFCSockDlg.h"
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


// CMFCSockDlg �Ի���




CMFCSockDlg::CMFCSockDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCSockDlg::IDD, pParent),m_sock(this)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_msg = _T("���");
	m_ToIp = _T("192.168.0.16");
	m_ToPort = 8000;
}

void CMFCSockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RECORD_LIST, m_RecordList);
	DDX_Text(pDX, IDC_MSG_RICH, m_msg);
	DDX_Text(pDX, IDC_TOIP_EDIT, m_ToIp);
	DDX_Text(pDX, IDC_TOPORT_EDIT, m_ToPort);
	DDX_Control(pDX, IDC_IP_COMBOX, m_IpCombox);
	DDX_Control(pDX, IDC_PORT_COMBOX, m_PortCombox);
}

BEGIN_MESSAGE_MAP(CMFCSockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND_BTN, &CMFCSockDlg::OnBnClickedSendBtn)
END_MESSAGE_MAP()


// CMFCSockDlg ��Ϣ�������

BOOL CMFCSockDlg::OnInitDialog()
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

	m_IpCombox.SetCurSel(0);
	m_PortCombox.SetCurSel(0);

	m_sock.Create(8000,SOCK_DGRAM,FD_READ,_T("192.168.0.16"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCSockDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCSockDlg::OnPaint()
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
HCURSOR CMFCSockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSockDlg::OnBnClickedSendBtn()
{
	UpdateData(TRUE);
	if(m_msg == "")
	{
		MessageBox(_T("�������ݲ���Ϊ��"),_T("��ʾ"),MB_OK|MB_ICONERROR);
		return;
	}
	CStringA sa = CW2A(m_msg);
	CString sIp;
	m_IpCombox.GetWindowText(sIp);
	UINT nPort;
	CString sPort;
	m_PortCombox.GetWindowText(sPort);
	nPort = atoi( CW2A(sPort) );
	
	int nRet = m_sock.SendTo(sa,sa.GetLength()+1,nPort,sIp);
	if(nRet == SOCKET_ERROR)
	{
		int nErrorCode = GetLastError();
		CString sError;
		sError.Format(_T("�������Ϊ:%d"),nErrorCode);
		MessageBox(sError,_T("��ʾ"),MB_OK|MB_ICONERROR);
		return ;
	}
	//m_sock.SendTo(sa,sa.GetLength()+1,m_ToPort,m_ToIp);
}
