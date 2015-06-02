// CutDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ScreenCut.h"
#include "CutDlg.h"
#include "afxdialogex.h"

#include<GdiPlus.h>
using namespace Gdiplus;

// CCutDlg �Ի���

IMPLEMENT_DYNAMIC(CCutDlg, CDialogEx)

CCutDlg::CCutDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCutDlg::IDD, pParent)
{
	bLClicked = FALSE;
}

CCutDlg::~CCutDlg()
{
}

void CCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCutDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CCutDlg ��Ϣ�������


BOOL CCutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//�õ������ָ��
	CWnd* pDesktop = CWnd::GetDesktopWindow();
	//�õ�����DC
	//pDesktop->GetDC();//���ַ�����Ҫ�ͷ�
	CClientDC dc(pDesktop);//����������DC����ݵ�DC
	m_mdc.CreateCompatibleDC(&dc);
	//�õ�����Ĵ�С
	CRect rc;
	pDesktop->GetWindowRect(&rc);
	m_width = rc.Width();
	m_height = rc.Height();

	//��������������ݵ�CBitmap
	m_mbmap.CreateCompatibleBitmap(&dc,m_width,m_height);
	m_oldBmap = m_mdc.SelectObject(&m_mbmap);
	m_mdc.BitBlt(0,0,m_width,m_height,&dc,0,0,SRCCOPY);

	this->ShowWindow(SW_SHOWMAXIMIZED);
	//����
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CCutDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ����
	CDialogEx::OnPaint();
	//dc.BitBlt(0,0,m_width,m_height,&m_mdc,0,0,SRCCOPY);

	CDC mdc;
	mdc.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,m_width,m_height);

	mdc.SelectObject(&bmp);
	mdc.BitBlt(0,0,m_width,m_height,&m_mdc,0,0,SRCCOPY);
	/*
	//���¾���
	CRect newRect(m_start,m_move);
	newRect.NormalizeRect();
	CBrush* oldBr = (CBrush*)mdc.SelectStockObject(NULL_BRUSH);
	mdc.Rectangle(newRect);
	mdc.SelectObject(oldBr);
	*/

	CRect newRect(m_start,m_move);
	newRect.NormalizeRect();
	m_end = m_move;

	//�õ�Ҫ���͸��ɫ������
	Rect BigRect(0,0,m_width,m_height);
	Region BigRegion(BigRect);
	Rect SmallRect(newRect.left,newRect.top,newRect.Width(),newRect.Height());
	BigRegion.Exclude(SmallRect);

	Graphics g(mdc);
	int rgb = 150;
	Color c(180,255,255,120);
	SolidBrush br(c);
	g.FillRegion(&br,&BigRegion);
	Color color(0,150,150);
	Pen pen(color,1);
	g.DrawRectangle(&pen,newRect.left,newRect.top,newRect.Width(),newRect.Height());

	dc.BitBlt(0,0,m_width,m_height,&mdc,0,0,SRCCOPY);

	mdc.DeleteDC();
	bmp.DeleteObject();
	ReleaseDC(&dc);
}


void CCutDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(bLClicked == FALSE)//��һ�ε���������
	{
		m_start = point;
		m_end = m_start;
		bLClicked = TRUE;
		//�ı������ʽ
		//����
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_WAIT);
			//IDC_CROSS ʮ��			IDC_ARROW ��ͷ
			//IDC_IBEAM �ı�����		IDC_WAIT �ȴ�	
		hOldCursor =::SetClassLong(this->m_hWnd,GCL_HCURSOR,(LONG)hCursor);
	}
	else
	{
		m_end = point;
		bLClicked = FALSE;
		SaveCutImage(point);
		//ͼ�񱣴洰�ڹرպ󣬹رս������ڣ����½���������
		OnOK();
		//EndDialog(IDD_CUT_DLG);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CCutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if(bLClicked)
	{
		m_move = point;
		Invalidate(FALSE);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CCutDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	//m_end = point;
	//bLClicked = FALSE;
	//SaveCutImage(point);
	////ͼ�񱣴洰�ڹرպ󣬹رս������ڣ����½���������
	//OnOK();
	////EndDialog(IDD_CUT_DLG);

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CCutDlg::SaveCutImage(CPoint point)
{
	::SetClassLong(this->m_hWnd,GCL_HCURSOR,hOldCursor);
	int w = m_end.x - m_start.x;
	int h = m_end.y - m_start.y;
	int width = w>0 ? w : -w;
	int height = h>0 ? h : -h;

	CDC* pDC = GetDC();
	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC,width,height);
	CBitmap* OldBmp = mdc.SelectObject(&bmp);
	mdc.BitBlt(0,0,width,height,pDC,m_start.x,m_start.y,SRCCOPY);
	mdc.SelectObject(OldBmp);
	mdc.DeleteDC();	
	ReleaseDC(pDC);
	CImage img;
	img.Attach(bmp); 
	CString ext = _T("jpg");
	CString name = _T("δ����");
	CString filter =_T("JPG�ļ�(.jpg)|*.jpg|")
		_T("PNG�ļ�(.png)|*.png|")
		_T("GIF�ļ�(.gif)|*.gif|")
		_T("ICO�ļ�(.ico)|*.ico|")
		_T("�����ļ�(*.*)|*.*||");
	CFileDialog fd(
		FALSE,ext,name,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		filter
		);
	if(fd.DoModal() == IDOK)
	{
		CString PathName = fd.GetPathName();
		img.Save(PathName);
		img.Detach();
		bmp.DeleteObject();
	}
}


void CCutDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	GdiplusShutdown(m_gdiplusToken);
	m_mdc.DeleteDC();
	m_mbmap.DeleteObject();
}
