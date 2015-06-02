
// CalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#include <string>
using namespace std;

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


// CCalculatorDlg �Ի���


CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
	, m_StrResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_StrResult = _T("0.");
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOW_EDIT, m_StrResult);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(IDC_BUTTON0,IDC_BUTTON9,&CCalculatorDlg::DoNum0_9)
	ON_COMMAND_RANGE(IDC_RIDE_BTN,IDC_DIVIDE_BTN,&CCalculatorDlg::DoOperator)
	
	ON_BN_CLICKED(IDC_CHANGE_BTN, &CCalculatorDlg::OnBnClickedChangeBtn)
	ON_BN_CLICKED(IDC_POINT_BTN, &CCalculatorDlg::OnBnClickedPointBtn)
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CCalculatorDlg::OnBnClickedClearBtn)
	ON_BN_CLICKED(IDC_RECIPROCAL_BTN, &CCalculatorDlg::OnBnClickedReciprocalBtn)
	ON_BN_CLICKED(IDC_EVOLUTION_BTN, &CCalculatorDlg::OnBnClickedEvolutionBtn)
	ON_BN_CLICKED(IDC_EQUAL_BTN, &CCalculatorDlg::OnBnClickedEqualBtn)
	ON_BN_CLICKED(IDC_BACK_BTN, &CCalculatorDlg::OnBnClickedBackBtn)
END_MESSAGE_MAP()


// CCalculatorDlg ��Ϣ�������

BOOL CCalculatorDlg::OnInitDialog()
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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::DoNum0_9(UINT d)
{
	DoInput(d - IDC_BUTTON0);
}

void CCalculatorDlg::DoOperator(UINT d)
{
	CWnd* p = GetDlgItem(d);
	CString s;
	p->GetWindowText(s);
	DoCompute( s.GetAt(0) );
}

void CCalculatorDlg::DoInput(int data)
{
	double m_dRight = cal.DoInput(data);
	Show(m_dRight);
}

void CCalculatorDlg::OnBnClickedChangeBtn()
{
	double m_dRight = cal.QuFan();
	Show(m_dRight);
}


void CCalculatorDlg::Show(double d)
{
	CString s_Coff;
	double m_dCoff = cal.GetCoff();
	if( m_dCoff != 1.0)
	{
		s_Coff.Format(_T("%.30f"),m_dCoff);
		int ncoff = s_Coff.Find('1') - 2;
		CString s;
		s.Format(_T("%d"),ncoff);
		s = _T("%.") + s;
		s += _T("f");
		m_StrResult.Format(s,d);
	}
	else
	{
		m_StrResult.Format(_T("%f"),d);
		int nLen = m_StrResult.GetLength() - 1;
		while(true)
		{
			if( m_StrResult[nLen] == '0')
			{
				m_StrResult.Delete(nLen);
				nLen--;
			}
			else
				break;
		}
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedPointBtn()
{
	cal.ChangeCoff();
}

void CCalculatorDlg::DoCompute(char newOp)
{
	//��ʾ
	double m_dLeft = cal.DoCalculate(newOp);
	Show(m_dLeft);
	
}


void CCalculatorDlg::OnBnClickedClearBtn()
{
	cal.Init();
	Show(0);
}

CString CCalculatorDlg::ChangeToCString(double d)
{
	CString s ;
	s.Format(_T("%f"),d);
	int nLen = s.GetLength() - 1;
	while(true)
	{
		if( s[nLen] == '0')
		{
			s.Delete(nLen);
			nLen--;
		}
		else
			break;
	}
	return s;
}


void CCalculatorDlg::OnBnClickedReciprocalBtn()
{
	//����
	double d = cal.Recip(m_StrResult);
	Show(d);
}


void CCalculatorDlg::OnBnClickedEvolutionBtn()
{
	//����
	/*CString s = ChangeToCString(m_dLeft);
	if(m_StrResult == s)
	{
		m_dLeft = sqrt(m_dLeft);
		Show(m_dLeft);
	}
	else
	{
		m_dRight = sqrt(m_dRight);
		Show(m_dRight);
	}*/
	double d =cal.Evol( _wtof(m_StrResult) );
	Show(d);
}


void CCalculatorDlg::OnBnClickedEqualBtn()
{
	DoCompute('=');
}


BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_CHAR)
	{
		if(pMsg->wParam >='0'&&pMsg->wParam <='9')
		{
			DoInput(pMsg->wParam - '0');
			CWnd* p = GetDlgItem(IDC_BUTTON0 + pMsg->wParam - '0');
			p->SetFocus();
			return TRUE;
		}
	}
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_ADD)
		{
			DoCompute('+');
			return TRUE;
		}
		if(pMsg->wParam == VK_SUBTRACT)
		{
			if(GetKeyState(VK_SHIFT) & 8000)
			{
				OnBnClickedChangeBtn();
			}
			else
			{
				DoCompute('-');
				return TRUE;
			}
		}
		if(pMsg->wParam == VK_MULTIPLY)
		{
			DoCompute('*');
			return TRUE;
		}
		if(pMsg->wParam == VK_DIVIDE)
		{
			DoCompute('/');
			return TRUE;
		}
		if(pMsg->wParam == VK_RETURN)
		{
			DoCompute('=');
			CWnd* p = GetDlgItem(IDC_EQUAL_BTN);
			p->SetFocus();
			return TRUE;
		}
		if(pMsg->wParam == VK_DECIMAL)
		{
			OnBnClickedPointBtn();
			return TRUE;
		}
		/*if( (GetKeyState(VK_SHIFT) & 8000) && pMsg->wParam == VK_SUBTRACT)
		{
			OnBnClickedChangeBtn();
			return TRUE;
		}*/
		if(pMsg->wParam == VK_BACK)
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CCalculatorDlg::OnBnClickedBackBtn()
{
	
}