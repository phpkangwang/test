
// MyCDCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyCDC.h"
#include "MyCDCDlg.h"
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


// CMyCDCDlg �Ի���




CMyCDCDlg::CMyCDCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyCDCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyCDCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyCDCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEST_BTN, &CMyCDCDlg::OnBnClickedTestBtn)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_SAVEIMAGE_BTN, &CMyCDCDlg::OnBnClickedSaveimageBtn)
	ON_BN_CLICKED(IDC_CUTSCREEN_BTN, &CMyCDCDlg::OnBnClickedCutscreenBtn)
	ON_BN_CLICKED(IDC_SAVEPOINT_BTN, &CMyCDCDlg::OnBnClickedSavepointBtn)
	ON_BN_CLICKED(IDC_READPOINT_BTN, &CMyCDCDlg::OnBnClickedReadpointBtn)
	ON_BN_CLICKED(IDC_DRAWIMAGE_BTN, &CMyCDCDlg::OnBnClickedDrawimageBtn)
END_MESSAGE_MAP()


// CMyCDCDlg ��Ϣ�������

BOOL CMyCDCDlg::OnInitDialog()
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

void CMyCDCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyCDCDlg::OnPaint()
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
		//�ػ�
		CDC* pDC = GetDC();

		pDC->Polyline(m_points.data(),m_points.size());
		int nBesizerCount = (m_points.size() -1)/3;
		//pDC->PolyBezier(m_points.data(),nBesizerCount*3 +1);

		pDC->TextOut(300,300,_T("��껮���Ŵ�"));
		this->ReleaseDC(pDC);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyCDCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyCDCDlg::OnBnClickedTestBtn()
{
	//���ÿͻ����ı���ɫ
	SetBackgroundColor(RGB(255,255,255),TRUE);
	//
	CDC* pDC = this->GetDC();
	//int nOldBKMode = pDC->SetBkMode(TRANSPARENT);
	//CRect rc;
	//GetClientRect(rc);
	//pDC->TextOut(200,200,_T("My name is���"));
	//pDC->DrawText(_T("�����"),&rc,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
	//pDC->SetBkMode(nOldBKMode);
	//pDC->MoveTo(200,600);
	//pDC->LineTo(400,400);
	//pDC->Ellipse(20,20,200,200);
	CImage img;
	img.Load(_T("2.png"));
	CBitmap* bMap = CBitmap::FromHandle(img);
	COLORREF c = RGB(255,0,0);

	//CBrush br(c);
	CBrush br(bMap);
	CBrush* OldBrush = pDC->SelectObject(&br);


	pDC->Rectangle(80,80,200,200);
	img.Destroy();

	pDC->SelectObject(OldBrush);


	this->ReleaseDC(pDC);
}

#include <fstream>
ostream& operator<<(ostream& os,CPoint& point)
{
	os<<point.x<<","<<point.y;
	return os;
}

//istream& operator>>(istream& is,CPoint& point)
//{
//	is>>point.x>>",">>point.y;
//	return is;
//}


void CMyCDCDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_points.push_back(point);
	this->Invalidate();//TRUE or FALSE

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMyCDCDlg::OnMouseMove(UINT nFlags, CPoint point)
{

	int n = 10;
	int nc = 30;
	CDC* pDC = GetDC();


	pDC->StretchBlt(60,60,nc+nc,nc+nc,pDC,point.x,point.y,n,n,SRCCOPY);

	ReleaseDC(pDC);

	vector<CPoint>::size_type nCount = m_points.size();
	if(nCount >0)
	{
		CRect rc;
		CPoint pLast = m_points[nCount-1];
		rc.SetRect(pLast,m_pTemp);
		rc.NormalizeRect();
		rc.InflateRect(1,1);
		InvalidateRect(rc);
		UpdateWindow();

		CDC* pDC = GetDC();

		//CPen pen(PS_DOT,10,RGB(255,0,0));
		//CPen* OldPen = pDC->SelectObject(&pen);
		
		pDC->MoveTo(pLast);
		pDC->LineTo(point);
		m_pTemp = point;

		//pDC->SelectObject(&OldPen);
		ReleaseDC(pDC);
	}

	CDialogEx::OnMouseMove(nFlags, point);
}

void CMyCDCDlg::OnBnClickedSaveimageBtn()
{
	CDC* pDC = GetDC();
	CRect rc;
	GetClientRect(&rc);
	int width = rc.Width();
	int height = rc.Height();
	//�����ڴ�DC
	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	//�����ڴ�CBitmap
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC,width,height);
	//mdc��bmp����
	CBitmap* OldBmp = mdc.SelectObject(&bmp);
	mdc.BitBlt(0,0,width,height,pDC,0,0,SRCCOPY);
	mdc.SelectObject(OldBmp);
	mdc.DeleteDC();
	CImage img;
	img.Attach(bmp); 

	CString ext = _T("jpg");
	CString name = _T("δ����");
	CString filter =_T("JPG�ļ�(.jpg)|*.jpg|")
		_T("PNG�ļ�(.png)|*.png|")
		_T("GIF�ļ�(.gif)|*.gif|")
		_T("�����ļ�(*.*)|*.*||");
	
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
	//
}

#include "CutDialog.h"
void CMyCDCDlg::OnBnClickedCutscreenBtn()
{
	CWnd* p = GetDesktopWindow();
	CDC* pDC = p->GetDC();
	CRect rc;
	p->GetWindowRect(&rc);
	int width = rc.Width();
	int height = rc.Height();
	//�����ڴ�DC
	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	//�����ڴ�CBitmap
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC,width,height);
	//mdc��bmp����
	CBitmap* OldBmp = mdc.SelectObject(&bmp);
	mdc.BitBlt(0,0,width,height,pDC,0,0,SRCCOPY);
	mdc.SelectObject(OldBmp);
	mdc.DeleteDC();

	CImage img;
	img.Attach(bmp);

	CutDialog cdlg;
	cdlg.GetImage(&img);
	cdlg.DoModal();
	/*if(cdlg.DoModal() == IDCANCEL)
		return;*/

	//img.Save(_T("C:\\cut.jpg"));
	img.Detach();
	bmp.DeleteObject();

	ReleaseDC(pDC);
}


void CMyCDCDlg::OnBnClickedSavepointBtn()
{
	ofstream ofs;
	ofs.open("C:\\CPoint.txt");
	vector<CPoint>::size_type nCount = m_points.size();
	CPoint outp;
	if(!ofs.bad())
	{
		for(unsigned int i=0; i <nCount;i++)
		{
			outp = m_points[i];
			ofs<<outp<<endl;
		}
		ofs.close();
	}
}


void CMyCDCDlg::OnBnClickedReadpointBtn()
{
	ifstream ifs;
	ifs.open("C:\\CPoint.txt",ios_base::in);
	char buf[255];
	if(!ifs.bad())
	{
		while(true)
		{
			ifs.getline(buf,255);
			int x;
			int y;
			int n = sscanf(buf,"%d,%d",&x,&y);
			if(n<2)
				break;
			m_points.push_back(CPoint(x,y));
		}
	}
	ifs.close();
}


void CMyCDCDlg::OnBnClickedDrawimageBtn()
{
	CImage img;
	img.Load(_T("C:\\1.jpg"));
	CDC* pDC = GetDC();

	CDC mdc;
	mdc.CreateCompatibleDC(pDC);

	img.BitBlt(mdc.m_hDC,0,0,300,300,0,0,SRCCOPY);
	
	CBitmap* bmap = CBitmap::FromHandle(img);

	CBitmap* oldBmap = pDC->SelectObject(bmap);
	pDC->BitBlt(0,0,300,300,&mdc,0,0,SRCCOPY);
	pDC->SelectObject(oldBmap);

	mdc.DeleteDC();

	ReleaseDC(pDC);


	img.Destroy();
}
