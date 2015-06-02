
// GraphicsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Graphics.h"
#include "GraphicsDlg.h"
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


// CGraphicsDlg �Ի���




CGraphicsDlg::CGraphicsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGraphicsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	bFlag = TRUE;
}

void CGraphicsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGraphicsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_DRAWRECT_BTN, &CGraphicsDlg::OnBnClickedDrawrectBtn)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CGraphicsDlg ��Ϣ�������

BOOL CGraphicsDlg::OnInitDialog()
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
	GdiplusStartupInput gdiplusStartupInput;
	
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGraphicsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGraphicsDlg::OnPaint()
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

		int nBesizer = (m_pos.size()-1)/3;
		int nPoint = nBesizer *3 +1;

		CDC* pDC = GetDC();
		CDC mdc;
		mdc.CreateCompatibleDC(pDC);
		CBitmap bmap;
		CRect rc;
		GetClientRect(rc);
		CBrush br(RGB(255,255,255));
		bmap.CreateCompatibleBitmap(pDC,rc.Width(),rc.Height());
		CBitmap* oldBmap = mdc.SelectObject(&bmap);
		mdc.FillRect(rc,&br);
		Graphics g(mdc);
		Color c(255,0,255,0);
		Pen pen(c);
		/*
		Image img(_T("F:\\images\\face--qqͷ��\\1-1.png"));
		RectF rf(0,0,16,16);
		TextureBrush tb(&img,WrapModeTileFlipX,rf);
		Pen pen(&tb,16);
		*/
		Rect rect(0,0,rc.Width(),rc.Height());
		SolidBrush sBrush(Color(128,0,0,128));
		g.FillRectangle(&sBrush,rect);

		g.DrawLines(&pen,m_pos.data(),m_pos.size());
		g.DrawBeziers(&pen,m_pos.data(),nPoint);


		pDC->BitBlt(0,0,rc.Width(),rc.Height(),&mdc,0,0,SRCCOPY);
		mdc.SelectObject(oldBmap);
		bmap.DeleteObject();
		mdc.DeleteDC();
		ReleaseDC(pDC);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGraphicsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGraphicsDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(bFlag)
	{
		m_start.X = point.x;
		m_start.Y = point.y;
		m_end = m_start;
		bFlag = FALSE;
	}
	else
	{
		m_end.X = point.x;
		m_end.Y = point.y;
		bFlag = TRUE;
	}

	m_pos.push_back(Point(point.x,point.y));
	//Invalidate();
	int nCount = m_pos.size();
	if(nCount>1)
	{
		CRect rc(m_pos[nCount -1].X,m_pos[nCount -1].Y,m_pos[nCount -2].X,m_pos[nCount -2].Y);
		rc.NormalizeRect();
		InvalidateRect(rc,FALSE);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CGraphicsDlg::OnBnClickedDrawrectBtn()
{
		Graphics g(this->m_hWnd);
		Color c(255,255,0,0);
		Pen pen(c);
		RectF rf(20,20,160,160);		
		g.DrawRectangle(&pen,rf);
		SolidBrush sBrush(c);

		g.FillRectangle(&sBrush,rf);
}


void CGraphicsDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	//if(m_start.X == m_end.X && m_start.Y == m_end.Y)
	//	return;
	if(m_start.X != 0 || m_start.Y != 0 )//(bFlag == FALSE)
	{
		CRect rc(m_start.X,m_start.Y,m_end.X,m_end.Y);
		rc.NormalizeRect();
		InvalidateRect(rc,FALSE);
		UpdateWindow();

		int w = point.x - m_start.X;
		int h = point.y - m_start.Y;
		int width = w>0?w:-w;
		int height = h>0?h:-h;

		Pen pen(Color(255,255,255));
		Graphics g(this->m_hWnd);
		g.DrawRectangle(&pen,m_start.X,m_start.Y,width,height);

		/*CDC* pDC = GetDC();
		CBrush* Obj = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(rect);
		pDC->SelectObject(Obj);
		ReleaseDC(pDC);*/

		m_end.X = point.x;
		m_end.Y = point.y;
	}



	CDialogEx::OnMouseMove(nFlags, point);
}
