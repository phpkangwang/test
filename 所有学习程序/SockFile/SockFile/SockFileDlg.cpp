
// SockFileDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SockFile.h"
#include "SockFileDlg.h"
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


// CSockFileDlg �Ի���




CSockFileDlg::CSockFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSockFileDlg::IDD, pParent),m_sock(this)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_msg = _T("���");
	m_nToPort = 9000;
	m_sToIp = _T("192.168.0.16");
	m_nMyPort = 8000;
	m_sMyIp = _T("192.168.0.16");

}

void CSockFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MSG_EDIT, m_msg);
	DDX_Control(pDX, IDC_RECORD_LIST, m_RecordList);
	DDX_Text(pDX, IDC_TOPORT, m_nToPort);
	DDX_Text(pDX, IDC_TOIP, m_sToIp);
	DDX_Text(pDX, IDC_MYPORT, m_nMyPort);
	DDX_Text(pDX, IDC_MYIP, m_sMyIp);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
}

BEGIN_MESSAGE_MAP(CSockFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INIT, &CSockFileDlg::OnBnClickedInit)
	ON_BN_CLICKED(IDC_SEND, &CSockFileDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_SENDFILE, &CSockFileDlg::OnBnClickedSendfile)
	ON_BN_CLICKED(IDC_CANCEL_SENDFILE_BTN, &CSockFileDlg::OnBnClickedCancelSendfileBtn)
END_MESSAGE_MAP()


// CSockFileDlg ��Ϣ�������

BOOL CSockFileDlg::OnInitDialog()
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

void CSockFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSockFileDlg::OnPaint()
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
HCURSOR CSockFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSockFileDlg::OnBnClickedInit()
{
	UpdateData(TRUE);
	m_sock.Create(m_nMyPort, SOCK_DGRAM,FD_READ,m_sMyIp);
	CWnd* p = GetDlgItem(IDC_INIT);
	p->EnableWindow(FALSE);
}


void CSockFileDlg::OnBnClickedSend()
{
	UpdateData(TRUE);
	m_msg;
	CStringA sa = CW2A(m_msg);
	sa = "000" + sa;
	m_sock.SendTo(sa,sa.GetLength()+1,m_nToPort,m_sToIp);
}


void CSockFileDlg::OnBnClickedSendfile()
{
	UpdateData(TRUE);
//	if(m_sock.m_nCount>9)

	if(m_sock.m_fp == NULL)
	{
		//�����ļ�
		CFileDialog fd(TRUE);
		if(fd.DoModal() == IDCANCEL)//ȡ������
			return;
		CStringA Name = CW2A( fd.GetFileName() );
		m_sock.m_fp = fopen(Name,"rb");
		fseek(m_sock.m_fp,0,SEEK_END);
		long nSize = ftell(m_sock.m_fp);
		//���ý�����
		m_progress.SetRange32(0,nSize);
		m_progress.SetPos(0);

		CString size;
		size.Format(_T("%d"),nSize);
		fseek(m_sock.m_fp,0,SEEK_SET);

		CStringA sa = "111";
		sa += Name;
		sa += '#';
		sa += CW2A(size);
		m_sock.SendTo(sa,sa.GetLength()+1,m_nToPort,m_sToIp);
	}
	else
	{
		//MessageBox(_T("���ڷ���"));

	}
}


void CSockFileDlg::OnBnClickedCancelSendfileBtn()
{
	UpdateData();
	if(m_sock.m_fp == NULL)
	{
		//û�����ڷ����ļ�,����
		return;
	}
	else
	{
		m_sock.SendTo("555",4,m_nToPort,m_sToIp);
		fclose(m_sock.m_fp);
		m_sock.m_fp = NULL;
		m_progress.SetPos(0);
	}
}
