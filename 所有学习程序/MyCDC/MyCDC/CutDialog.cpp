// CutDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MyCDC.h"
#include "CutDialog.h"
#include "afxdialogex.h"


// CutDialog 对话框

IMPLEMENT_DYNAMIC(CutDialog, CDialogEx)

CutDialog::CutDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CutDialog::IDD, pParent)
{
	bFlag = TRUE;
}

CutDialog::~CutDialog()
{
}

void CutDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CutDialog, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
//	ON_WM_PAINT()
ON_WM_PAINT()
END_MESSAGE_MAP()


// CutDialog 消息处理程序


BOOL CutDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	//this->SetBackgroundImage(m_img);
	ShowWindow(SW_MAXIMIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CutDialog::GetImage(CImage* img)
{
	m_img = img;
}


void CutDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	//
	if(bFlag)
	{
		m_startp = point;
		m_endp = m_startp;
		bFlag = FALSE;
	}
	else
	{
		m_endp = point;
		bFlag = TRUE;
	}

	if(m_startp == m_endp)
		return;

	int w = m_endp.x - m_startp.x;
	int h = m_endp.y - m_startp.y;
	int width = w>0 ? w : -w;
	int height = h>0 ? h : -h;

	CDC* pDC = GetDC();

	CDC mdc;
	mdc.CreateCompatibleDC(pDC);

	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC,width,height);

	CBitmap* OldBmp = mdc.SelectObject(&bmp);
	mdc.BitBlt(0,0,width,height,pDC,m_startp.x,m_startp.y,SRCCOPY);
	mdc.SelectObject(OldBmp);
	mdc.DeleteDC();
	CImage img;
	img.Attach(bmp); 

	CString ext = _T("jpg");
	CString name = _T("未命名");
	CString filter =_T("JPG文件(.jpg)|*.jpg|")
		_T("PNG文件(.png)|*.png|")
		_T("GIF文件(.gif)|*.gif|")
		_T("所有文件(*.*)|*.*||");
	
	CFileDialog fd(
		FALSE,ext,name,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		filter
		);

	if(fd.DoModal() == IDCANCEL)
		return;
	CString PathName = fd.GetPathName();
	
	img.Save(PathName);
	img.Detach();
	bmp.DeleteObject();
	ReleaseDC(pDC);
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CutDialog::OnMouseMove(UINT nFlags, CPoint point)
{

	if(bFlag == FALSE)
	{
		CRect rc;
		rc.SetRect(m_startp,m_endp);
		rc.NormalizeRect();
		InvalidateRect(rc,FALSE);
		UpdateWindow();

		CRect rect(m_startp.x,m_startp.y,point.x,point.y);
		rect.NormalizeRect();

		CPen pen(PS_DASH,1,RGB(255,0,0));
		CDC* pDC = GetDC();
		CBrush* oldBr = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
		CPen* oldPen = pDC->SelectObject(&pen);
		pDC->Rectangle(rect);
		
		pDC->SelectObject(oldBr);
		pDC->SelectObject(oldPen);
		ReleaseDC(pDC);

		m_endp = point;
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CutDialog::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	CDialogEx::OnPaint();
	//重绘
	CDC* pDC = GetDC();
	
	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	//CBitmap bmp;
	//bmp.CreateCompatibleBitmap(pDC,1366,768);
	CBitmap* bmp = CBitmap::FromHandle(*m_img);

	CBitmap* pBmp = mdc.SelectObject(bmp);
	//m_img->AlphaBlend(mdc,0,0,80);
	//m_img->BitBlt(mdc,0,0);

	pDC->BitBlt(0,0,1366,768,&mdc,0,0,SRCCOPY);
	
	ReleaseDC(pDC);
	mdc.SelectObject(pBmp);
	//bmp.DeleteObject();
	mdc.DeleteDC();
}
