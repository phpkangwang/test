
// ThreadSynDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ThreadSyn.h"
#include "ThreadSynDlg.h"
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


// CThreadSynDlg �Ի���




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


// CThreadSynDlg ��Ϣ�������

BOOL CThreadSynDlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CThreadSynDlg::OnPaint()
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
	//�ٽ���
	//cs.Lock();
	//
	//mu.Lock();
	//
	//sp.Lock();
	HWND hw = (HWND) pParam;
	//����ͼƬ
	Image* pImg;
	pImg = Image::FromFile(L"image\\loading.gif");
	//�õ�ͼƬ�ĳߴ�����
	UINT nDimenCount = pImg->GetFrameDimensionsCount();
	//����ռ�GUID
	GUID* pGuid = new GUID[nDimenCount];
	//�õ�GUID
	pImg->GetFrameDimensionsList(pGuid,nDimenCount);
	//�õ�����һ��GUID�õ��ãǣգɣĵ�ͼƬ֡��
	UINT nFrameCount = pImg->GetFrameCount(pGuid+0);
	//���û�����һ֡
	UINT nIndex = 0;
	//ÿ��ͼ������
	int xBox = 80;
	int yBox = 80;
	//�õ��ͻ���
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
