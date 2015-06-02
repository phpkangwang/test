
// GDIGifDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GDIGif.h"
#include "GDIGifDlg.h"
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


// CGDIGifDlg �Ի���




CGDIGifDlg::CGDIGifDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDIGifDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGDIGifDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGDIGifDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGDIGifDlg ��Ϣ�������

BOOL CGDIGifDlg::OnInitDialog()
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

	//����gdi
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	//��Ϣ�������ļ��ж�ȡ
	_TCHAR ret[100];
	CString section = _T("Gif");
	CString keyName = _T("�ļ���");
	DWORD nRet = GetPrivateProfileString(
		section,
		keyName,
		_T(""),
		ret,100,
		_T("F:\\set.ini")
		);
	/*if(nRet == 0)
	{
		MessageBox(_T(""),_T(""),MB_OK);
		return FALSE;
	}*/
	//����ͼƬ
	CString path;
	path.Format(_T("image\\%s"),ret);
	m_pImg = Image::FromFile(path);
	//�õ��ߴ���
	UINT nDimenCount = m_pImg->GetFrameDimensionsCount();
	m_pDimenGUID = new GUID[nDimenCount];
	//�õ��ߴ�֡��
	m_pImg->GetFrameDimensionsList(m_pDimenGUID,nDimenCount);
	//���ݳߴ�ؼ���GUID
	m_nFrameCount = m_pImg->GetFrameCount(m_pDimenGUID);
	//���õ�ǰ��֡
	m_nIndex = 0;
	//����ʱ����
	SetTimer(1,100,NULL);
	//


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGDIGifDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(1 == nIDEvent)
	{
		Invalidate();
	}

	CDialogEx::OnTimer(nIDEvent);
}




void CGDIGifDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGDIGifDlg::OnPaint()
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

		m_nIndex++;
		if((UINT)m_nIndex >= m_nFrameCount)
			m_nIndex = 0;
		m_pImg->SelectActiveFrame(m_pDimenGUID,m_nIndex);
		
		CClientDC dc(this);
		Graphics g(dc);

		PointF point(50,50);
		g.DrawImage(m_pImg,point);

	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGDIGifDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}