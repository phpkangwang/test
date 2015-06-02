
// TheardDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Theard.h"
#include "TheardDlg.h"
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


// CTheardDlg �Ի���




CTheardDlg::CTheardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTheardDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTheardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTheardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CTheardDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_RESUME, &CTheardDlg::OnBnClickedResume)
	ON_BN_CLICKED(IDC_SUSPEND, &CTheardDlg::OnBnClickedSuspend)
	ON_BN_CLICKED(IDC_END, &CTheardDlg::OnBnClickedEnd)
	ON_MESSAGE(WM_Msg,&CTheardDlg::OnMsg)
	ON_BN_CLICKED(IDC_SIGANL, &CTheardDlg::OnBnClickedSiganl)
	ON_BN_CLICKED(IDC_SIGANLEXIT, &CTheardDlg::OnBnClickedSiganlexit)
END_MESSAGE_MAP()


// CTheardDlg ��Ϣ�������

BOOL CTheardDlg::OnInitDialog()
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

void CTheardDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTheardDlg::OnPaint()
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
HCURSOR CTheardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CWinThread*  p = nullptr;
BOOL bContinue = TRUE;
CEvent eventDraw(TRUE);
CEvent eventExit;

UINT __cdecl MyThread( LPVOID pParam )
{
	HWND hw = (HWND) pParam;
	RECT rc;
	GetClientRect(hw,&rc);
	int w = rc.right - rc.left;
	int h = rc.bottom - 60;
	HANDLE hevent[] = { eventDraw,eventExit }; 
	while(bContinue)
	{
		//WaitForSingleObject(et,INFINITE);
	
		DWORD nResult = ::WaitForMultipleObjects(2,hevent,FALSE,INFINITE);
		int nIndex = nResult - WAIT_OBJECT_0;

		if(nIndex == 1)//�˳��¼�������
			break;

		//�õ�DC��
		HDC hdc = GetDC(hw);
		//�õ�������ĸ���
		int left = rand()%w;
		int top = rand()%h;
		int right = rand()%w;
		int bottom = rand()%h;
		//TRACE("%d,%d,%d,%d\n",left,top,right,bottom);
		//�õ��漴��ɫ
		int r = rand()%256;
		int g = rand()%256;
		int b = rand()%256;
		
		HBRUSH br = CreateSolidBrush(RGB(r,g,b));
		HBRUSH oldBr = (HBRUSH)SelectObject(hdc,br);
		HPEN pen = CreatePen(PS_DOT,2,RGB(r,g,b));
		HPEN oldPen = (HPEN)SelectObject(hdc,pen);
		POINT p1 = {rand()%w,rand()%h};
		POINT p2 = {rand()%w,rand()%h};
		POINT p3 = {rand()%w,rand()%h};
		POINT p4 = {rand()%w,rand()%h};
		POINT point[]={	p1,p2,p3,p4	};
		//ѡ���漴��ͼ
		switch(rand()%4)
		{
		case 0:
			{
				Rectangle(hdc,left,top,right,bottom);
			}
			break;
		case 1:
			Ellipse(hdc,left,top,right,bottom);
			break;
		case 2:
			RoundRect(hdc,left,top,right,bottom,15,15);
			break;
		case 3:
			PolyBezier(hdc,point,4);
			break;
		}
		//�ָ���ˢ���ͷ�DC
		SelectObject(hdc,oldBr);
		SelectObject(hdc,oldPen);
		ReleaseDC(hw,hdc);
		//Sleep(400);
	}
	//MessageBox(NULL,_T("�����߳�"),_T("�̲߳���"),MB_OK);
	PostMessage(hw,WM_Msg,0,0);
	return 0;
}
void CTheardDlg::OnBnClickedStart()
{
	//CDC* pDC = GetDC();
	//GetSafeHwnd();
	bContinue = TRUE;
	p = AfxBeginThread(MyThread,m_hWnd);
	//p = AfxBeginThread(MyThread,NULL,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
}

void CTheardDlg::OnBnClickedSiganl()
{
	eventDraw.SetEvent();
}


void CTheardDlg::OnBnClickedSiganlexit()
{
	eventExit.SetEvent();
}

void CTheardDlg::OnBnClickedResume()
{
	if(p)
		p->ResumeThread();

}


void CTheardDlg::OnBnClickedSuspend()
{
	if(p)
		p->SuspendThread();
	eventDraw.ResetEvent();
}


void CTheardDlg::OnBnClickedEnd()
{
	bContinue = FALSE;
	p = nullptr;
}

LRESULT CTheardDlg::OnMsg(WPARAM wParam,LPARAM lParam)
{
	MessageBox(_T("�̱߳�������"));
	return 1;
}