
// My_CDialog1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "My_CDialog1.h"
#include "My_CDialog1Dlg.h"
#include "afxdialogex.h"
#include <sstream>
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


// CMy_CDialog1Dlg �Ի���




CMy_CDialog1Dlg::CMy_CDialog1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy_CDialog1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy_CDialog1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME_EDIT, m_name_edit);
}

BEGIN_MESSAGE_MAP(CMy_CDialog1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_MESBOX, &CMy_CDialog1Dlg::OnBnClickedBtnMesbox)
	ON_BN_CLICKED(IDC_BTN_SHOW_OR_HIDE, &CMy_CDialog1Dlg::OnBnClickedBtnShowOrHide)
	ON_BN_CLICKED(IDC_UPADATE_TITLE_BTN, &CMy_CDialog1Dlg::OnBnClickedUpadateTitleBtn)
	ON_BN_CLICKED(IDC_LOGIN_BTN, &CMy_CDialog1Dlg::OnBnClickedLoginBtn)
	ON_BN_CLICKED(IDC_LOGIN_CANCEL_BTN, &CMy_CDialog1Dlg::OnBnClickedLoginCancelBtn)
	ON_BN_CLICKED(IDC_ENABLE_BTN, &CMy_CDialog1Dlg::OnBnClickedEnableBtn)
	ON_BN_CLICKED(IDC_MSGBOX_BTN, &CMy_CDialog1Dlg::OnBnClickedMsgboxBtn)
END_MESSAGE_MAP()


// CMy_CDialog1Dlg ��Ϣ�������

BOOL CMy_CDialog1Dlg::OnInitDialog()
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

void CMy_CDialog1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy_CDialog1Dlg::OnPaint()
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
HCURSOR CMy_CDialog1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy_CDialog1Dlg::OnBnClickedBtnMesbox()
{
	CMy_CDialog1App* p = (CMy_CDialog1App*)::AfxGetApp();
	int n = p->m_nData;

	//STL
	wostringstream oss;
	oss<<n;
	wstring ss = oss.str();
	if( MessageBox(_T("�Ƿ���ʾ"),_T("��ʾ"),MB_YESNO |MB_ICONWARNING) == IDYES )
	{
		MessageBox(ss.c_str(),_T("����"));
	}
	/*CString s;
	s.Format(_T("m_nData = %d"),n);

	MessageBox(s,_T("����"),MB_OKCANCEL |MB_ICONWARNING);*/

	/*if(MessageBox(_T("�ҵ����ֽ����"),_T("��Ϣ��ʾ"),MB_OKCANCEL|MB_ICONWARNING) == IDOK)
	{
		MessageBox(_T("�ҵ����ֽ����"));
	}
	else
	{
		MessageBox(_T("I LOVE YOU"));
	}*/
	//::MessageBox();
	//::AfxMessageBox(_T("��Ϣ��ʾ"));
}


void CMy_CDialog1Dlg::OnBnClickedBtnShowOrHide()
{
	if(m_name_edit.IsWindowVisible())
		m_name_edit.ShowWindow(SW_HIDE);
	else
		m_name_edit.ShowWindow(SW_SHOW);
}


void CMy_CDialog1Dlg::OnBnClickedUpadateTitleBtn()
{
	CWnd* pEdit = GetDlgItem(IDC_TITLE_EDIT);
	CString s;
	pEdit->GetWindowText(s);
	pEdit->SetWindowText(_T(""));
	CWnd* pBtn = GetDlgItem(IDC_ISUPDATE_TITLE_BTN);
	pBtn->SetWindowText(s);
}


void CMy_CDialog1Dlg::OnBnClickedLoginBtn()
{
	//�õ�����
	CWnd* pEdit = GetDlgItem(IDC_LOGIN_NAME_EDIT);
	CString name;
	pEdit->GetWindowText(name);
	//�õ�����
	pEdit = GetDlgItem(IDC_LOGIN_PASSWORD_EDIT);
	CString password;
	pEdit->GetWindowText(password);
	if(name == "���" && password == "1218")
	{

	}
	else
		MessageBox(_T("�û������������"),_T("������ʾ"),MB_ICONHAND);

}


void CMy_CDialog1Dlg::OnBnClickedLoginCancelBtn()
{
	CWnd* pEdit = GetDlgItem(IDC_LOGIN_NAME_EDIT);
	pEdit->SetWindowText(_T(""));
	//�õ�����
	pEdit = GetDlgItem(IDC_LOGIN_PASSWORD_EDIT);
	pEdit->SetWindowText(_T(""));
}


void CMy_CDialog1Dlg::OnBnClickedEnableBtn()
{
	CWnd* pBtn = GetDlgItem(IDC_MSGBOX_BTN);
	pBtn->EnableWindow(!IsWindowEnabled());
	CString text = pBtn->IsWindowEnabled()?_T("����"):_T("����");
	GetDlgItem(IDC_ENABLE_BTN)->SetWindowText(text);
}


void CMy_CDialog1Dlg::OnBnClickedMsgboxBtn()
{
	MessageBox(_T("QWERTY"));
}
