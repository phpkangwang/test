
// QQDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QQ.h"
#include "QQDlg.h"
#include "afxdialogex.h"

#include <gdiplus.h>
using namespace Gdiplus;


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


// CQQDlg �Ի���




CQQDlg::CQQDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CQQDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nSelectIndex = 0;
	m_nHoverIndex = -1;
}

void CQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CQQDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CQQDlg ��Ϣ�������

BOOL CQQDlg::OnInitDialog()
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
	CRect rc;
	this->GetWindowRect(&rc);
	CRgn rgn;
	rgn.CreateRoundRectRgn(0,0,rc.right,rc.bottom,5,5);
	this->SetWindowRgn(rgn,1);

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CQQDlg::OnPaint()
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
		DoPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CQQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CQQDlg::DoPaint(void)
{
	//
	CDC* pDC = this->GetDC();
	//
	CDC mdc;
	CBitmap bmp;
	//���ڵĴ�С
	CRect rc;
	this->GetClientRect(&rc);
	int w = rc.Width();
	int h = rc.Height();
	//����ͼƬ��ͼƬ�Ĵ�С
	CImage img;
	img.Load(_T("image\\BK.bmp"));
	int iw = img.GetWidth();
	int ih = img.GetHeight();
	//
	CBrush br(RGB(255,255,255));
	mdc.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC,w,h);
	CBitmap* oldBmp = mdc.SelectObject(&bmp);
	//
	mdc.FillRect(rc,&br);
	int hTop = 105;//�ϱ߽�
	int hBottom = 26;//�±߽�
	int n = 5;//�߿�Ĵ�С
	COLORREF tc = RGB(255,0,255);//�ڱε���ɫ

	//============ draw background ======
	//left top region
	img.TransparentBlt(mdc,0,0,n,hTop,0,0,n,hTop,tc);
	//center top region
	img.StretchBlt(mdc,n,0,w-n-n,hTop,n,0,iw-n-n,hTop);
	//right top region
	img.TransparentBlt(mdc,w-n,0,n,hTop,iw-n,0,n,hTop,tc);
	//left center region
	img.TransparentBlt(mdc,0,hTop,n,h-hTop-hBottom,0,hTop,n,ih-hTop-hBottom,tc);
	//center center region
	img.StretchBlt(mdc,n,hTop,w-n-n,h-hTop-hBottom,w-n,hTop,iw-n-n,ih-hTop-hBottom);
	//right center region
	img.TransparentBlt(mdc,w-n,hTop,n,h-hTop-hBottom,iw-n,hTop,n,ih-hTop-hBottom,tc);
	//left bottom region
	img.TransparentBlt(mdc,0,h-hBottom,n,hBottom,0,ih-hBottom,n,hBottom,tc);
	//center bottom region
	img.StretchBlt(mdc,n,h-hBottom,w-n-n,hBottom,n,ih-hBottom,iw-n-n,hBottom);
	//right bottom region
	img.TransparentBlt(mdc,w-n,h-hBottom,n,hBottom,iw-n,ih-hBottom,n,hBottom,tc);
	//============= background end ==============
	//
	//============ draw image============
	CString funcImgName[] = 
	{
		_T("tab_icon_homepage.png"),
		_T("tab_icon_vul.png"),
		_T("tabMain_icon_trojan.png"),
		_T("tab_icon_system_optimize.png"),
		_T("tab_icon_software.png"),
		_T("tab-icon_hardware.png"),
		_T("tab_icon_protect.png"),
		_T("tab_icon_antiVirsu.png"),
		_T("tab_icon_feature.png")
	};
	CString strTitle[] = 
	{
		_T("��ҳ"),
		_T("�޸�©��"),
		_T("��ɱľ��"),
		_T("ϵͳ�Ż�"),
		_T("�������"),
		_T("Ӳ�����"),
		_T("ʵʱ����"),
		_T("ɱ��ר��"),
		_T("�߼�����")
	};
	int nCount = 9;
	int x = 10;//��һ��͸���������߽�ľ���
	int y = 28;//͸��ͼƬ�����ϱ߽�ľ���
	int xSpace = 0;
	int xTransBox = 84;
	Graphics g(mdc);

	//����ѡ��ʱ��͸����
	Image* pImg = nullptr;
	ImageAttributes ImgAttribute;
	Color c(0,255,0,255);
	ImgAttribute.SetColorKey(c,c);	
	pImg = Image::FromFile(_T("image\\ims_tab_button1_chosen.png"));
	int ImgWidth = pImg->GetWidth();
	int ImgHeight = pImg->GetHeight();
	int TransW = ImgWidth;//͸��ͼƬ�Ŀ�
	int TransH = ImgHeight;//͸��ͼƬ�ĸ�

	//ѡ���͸����
	g.DrawImage(
		pImg,
		Rect( (x +m_nSelectIndex *xTransBox +xSpace),y,ImgWidth,ImgHeight),
		0,0,ImgWidth,ImgHeight,
		UnitPixel,
		&ImgAttribute);

	//���ͣ��ʱ��͸����
	if(m_nHoverIndex>0)
	{
		if(m_nHoverIndex != m_nSelectIndex)
		g.DrawImage(
			pImg,
			Rect( (x +m_nHoverIndex *xTransBox +xSpace),y,ImgWidth,ImgHeight),
			0,0,ImgWidth,ImgHeight,
			UnitPixel,
			&ImgAttribute);
	}
	delete pImg;

	//������ͼ��
	CString NamePath;
	int ImgY = 38;
	int ImgX;
	CFont font;
	//font.CreateFont(
	//	12,                        // nHeight
	//	0,                         // nWidth
	//	0,                         // nEscapement
	//	0,                         // nOrientation
	//	FW_NORMAL,                 // nWeight
	//	FALSE,                     // bItalic
	//	FALSE,                     // bUnderline
	//	0,                         // cStrikeOut
	//	ANSI_CHARSET,              // nCharSet
	//	OUT_DEFAULT_PRECIS,        // nOutPrecision
	//	CLIP_DEFAULT_PRECIS,       // nClipPrecision
	//	DEFAULT_QUALITY,           // nQuality
	//	DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	//	_T("Arial"));
	font.CreatePointFont(90,_T("����"),pDC);
	int oldBKMode = mdc.SetBkMode(TRANSPARENT);
	CFont* oldFont = mdc.SelectObject(&font);
	mdc.SetTextColor(RGB(255,255,255));
	for(int i=0;i<nCount;i++)
	{
		//��ͼ��
		NamePath.Format(_T("image\\%s"),funcImgName[i]);
		pImg = Image::FromFile(NamePath);
		ImgWidth = pImg->GetWidth();
		ImgHeight = pImg->GetHeight();
		ImgX = x + (xTransBox-ImgWidth)/2;
		g.DrawImage(
			pImg,
			Rect( ImgX,ImgY,ImgWidth,ImgHeight),
			0,0,ImgWidth,ImgHeight,
			UnitPixel,
			&ImgAttribute);
		//������
		//g.DrawString(strTitle[i],strTitle[i].GetLength(),
		
		mdc.DrawText(strTitle[i],CRect(x,y,x+TransW,y+TransH-10),DT_SINGLELINE|DT_CENTER|DT_BOTTOM);
		
		x += xTransBox + xSpace;

		delete pImg;
	}
	mdc.SetBkMode(oldBKMode);
	mdc.SelectObject(oldFont);

	pDC->BitBlt(0,0,w,h,&mdc,0,0,SRCCOPY);
	mdc.SelectObject(oldBmp);
	mdc.DeleteDC();
	bmp.DeleteObject();
	//
	this->ReleaseDC(pDC);
}


void CQQDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	int x = 10;
	int TransTop = 28;
	int xTransBox = 84;
	int yTransBox = 78;
	int nDownIndex;
	CRect rc(x,TransTop,x+xTransBox*9,yTransBox+TransTop);
	nDownIndex = (point.x-x)/xTransBox;
	if(rc.PtInRect(point))
	{
		if(nDownIndex != m_nSelectIndex)
		{
			m_nSelectIndex = nDownIndex;
			InvalidateRect(rc,FALSE);
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CQQDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	int x = 10;
	int TransTop = 28;
	int xTransBox = 84;
	int yTransBox = 78;
	int nHoverIndex;
	CRect rc(x,TransTop,x+xTransBox*9,yTransBox+TransTop);
	nHoverIndex = (point.x-x)/xTransBox;
	if(rc.PtInRect(point))
	{
		if(m_nHoverIndex == nHoverIndex)
			;
		else
		{
			m_nHoverIndex = nHoverIndex;
			InvalidateRect(rc,FALSE);
		}
	}
	else
	{
		m_nHoverIndex = -1;
		InvalidateRect(rc,FALSE);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CQQDlg::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	int x = 10;
	int TransTop = 28;
	int xTransBox = 84;
	int yTransBox = 78;
	CRect rc(x,TransTop,x+xTransBox*9,yTransBox+TransTop);
	m_nHoverIndex = -1;
	InvalidateRect(rc,FALSE);


	CDialogEx::OnNcMouseMove(nHitTest, point);
}


LRESULT CQQDlg::OnNcHitTest(CPoint point)
{	
	CRect rw;
	GetClientRect(&rw);

	CRect rr(10,28,10+9*84,rw.bottom - 26);//

	CRgn FuncRgn;//����ѡ����
	FuncRgn.CreateRectRgnIndirect(rr);
	
	CRgn Rgn;
	//Rgn.CreateRectRgnIndirect(rw);
	Rgn.CreateRectRgn(rw.left+5,rw.top,rw.right -5,rw.bottom);
	
	CRgn MoveRgn;//��������ƶ����ڵ�����
	MoveRgn.CreateRectRgnIndirect(rr);
	MoveRgn.CombineRgn(&Rgn,&FuncRgn,RGN_DIFF);

	CRgn SizeRgn;
	SizeRgn.CreateRectRgn(rw.right -5,rw.top,rw.right,rw.bottom);

	ScreenToClient(&point);
	if(MoveRgn.PtInRegion(point))
		return HTCAPTION;
	else if(SizeRgn.PtInRegion(point))
		return HTBORDER;

	return CDialogEx::OnNcHitTest(point);
}
