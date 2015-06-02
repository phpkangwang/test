
// MyOBDCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyOBDC.h"
#include "MyOBDCDlg.h"
#include "afxdialogex.h"

#include "Stu.h"
#include "DlgOp.h"

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
public:
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


// CMyOBDCDlg �Ի���


CMyOBDCDlg::CMyOBDCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyOBDCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nStyle = ID_DETAILINFO;
}

void CMyOBDCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOWDATA_LIST, m_DataList);
}

BEGIN_MESSAGE_MAP(CMyOBDCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUERYDATA_BTN, &CMyOBDCDlg::OnBnClickedQuerydataBtn)
	ON_BN_CLICKED(IDC_ADD_BTN, &CMyOBDCDlg::OnBnClickedAddBtn)
	ON_BN_CLICKED(IDC_DELETE_BTN, &CMyOBDCDlg::OnBnClickedDeleteBtn)
	ON_BN_CLICKED(IDC_UPDATE_BTN, &CMyOBDCDlg::OnBnClickedUpdateBtn)
	ON_WM_SIZE()
	ON_NOTIFY(NM_RCLICK, IDC_SHOWDATA_LIST, &CMyOBDCDlg::OnNMRClickShowdataList)
	ON_COMMAND(ID_REFLESH, &CMyOBDCDlg::OnReflesh)
	ON_BN_CLICKED(IDC_LIST_STYLE, &CMyOBDCDlg::OnBnClickedListStyle)
	ON_COMMAND(ID_DETAILINFO, &CMyOBDCDlg::OnDetailinfo)
	ON_COMMAND(ID_THUMBANAIL, &CMyOBDCDlg::OnThumbanail)
	ON_COMMAND(ID_TILE, &CMyOBDCDlg::OnTile)
	ON_COMMAND(ID_LISTING, &CMyOBDCDlg::OnListing)
	ON_COMMAND(ID_ICON, &CMyOBDCDlg::OnIcon)
//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_SHOWDATA_LIST, &CMyOBDCDlg::OnLvnItemchangedShowdataList)
ON_NOTIFY(NM_CLICK, IDC_SHOWDATA_LIST, &CMyOBDCDlg::OnNMClickShowdataList)
END_MESSAGE_MAP()


// CMyOBDCDlg ��Ϣ�������

BOOL CMyOBDCDlg::OnInitDialog()
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
	
	m_DataList.SetExtendedStyle(LVS_EX_FULLROWSELECT| 
		LVS_EX_GRIDLINES );//| LVS_EX_CHECKBOXES);

	CString s;
	CString cols[] = 
	{
		//_T("V"),
		_T("ѧ��"),
		_T("����"),
		_T("����"),
		_T("��������")
	};
	//m_DataList.InsertColumn(0,cols[0],LVCFMT_CENTER,25);
	for(int i=0;i<4;i++)
		m_DataList.InsertColumn(i,cols[i],LVCFMT_CENTER,100);

	//set size 
	DlgSizeChange(560,350);
	InitImageList();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyOBDCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyOBDCDlg::OnPaint()
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
HCURSOR CMyOBDCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyOBDCDlg::InitImageList(void)
{
	CString s;
	CImage img;
	CBitmap* bMap;
	COLORREF c = RGB(255,255,255);
	m_ImgList.Create(16,16,ILC_COLOR32,10,1);
	
	//����1��
	/*for(int i=1;i<=10;i++)
	{
		s.Format(_T("image\\%d.png"),i);
		img.Load(s);
		bMap = CBitmap::FromHandle(img);
		m_ImgList.Add(bMap,c);
		img.Destroy();
	}
	*/
	//����2��
	//WIN32_FIND_DATA fd;
	//HANDLE hFind = ::FindFirstFile(_T("image\\*.png"),&fd);
	//while( hFind != INVALID_HANDLE_VALUE)
	//{
	//	if(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
	//		;
	//	else
	//	{
	//		s = _T("image\\");
	//		s += fd.cFileName;
	//		//DWORD size = fd.nFileSizeHigh;
	//		//size = fd.nFileSizeLow;
	//		img.Load(s);
	//		bMap = CBitmap::FromHandle(img);
	//		m_ImgList.Add(bMap,c);
	//		img.Destroy();
	//	}
	//	BOOL b = ::FindNextFile(hFind,&fd);
	//	if(!b)
	//		break;
	//}
	//::FindClose(hFind);


	//����3��
	CFileFind ff;
	ff.FindFile(_T("image\\*.png"));
	while(true)
	{
		if(!ff.FindNextFile())
			break;
		if(ff.IsDirectory())
			;
		else
		{
			s = ff.GetFilePath();
			//����ʹ��ע�͵ķ���
			//s = ff.GetRoot();
			//s += ff.GetFileName();
			img.Load(s);
			bMap = CBitmap::FromHandle(img);
			m_ImgList.Add(bMap,c);
			img.Destroy();
		}
	}
	ff.Close();
	m_DataList.SetImageList(&m_ImgList,LVSIL_SMALL);

}


void CMyOBDCDlg::ShowData()
{
	m_DataList.DeleteAllItems();
	CStu st;
	if(! st.Open() )//�����ݿ�,�õ���¼����һ������
		return;
	int nRow = 0;
	CString s;
	int nCount = m_ImgList.GetImageCount();
	//���ݿ�Ĳ���
 	while( !st.IsEOF() )
	{
		//show current row data
		//m_DataList.InsertItem(nRow,_T(""));
		//m_DataList.SetItemText(nRow,0,st.m_ID);
		
		//_tzset();
		//srand( (unsigned)time(NULL) );
		int n = rand()%(nCount -1);

		m_DataList.InsertItem(nRow,st.m_ID,n);
		m_DataList.SetItemText(nRow,1,st.m_name);
		s.Format(_T("%d"),st.m_age);
		m_DataList.SetItemText(nRow,2,s);
		m_DataList.SetItemText(nRow,3,st.m_birth.Format(_T("%Y-%m-%d")));
		//move next row
		nRow++;
		st.MoveNext();
	}
	st.Close();//�ر����ݿ�
}

void CMyOBDCDlg::OnBnClickedQuerydataBtn()
{
	BeginWaitCursor();//������Ϊ�ȴ����
	ShowData();
	EndWaitCursor();
}


void CMyOBDCDlg::OnBnClickedAddBtn()
{
	DlgOp dlg;
	if(dlg.DoModal() == IDCANCEL)
		return;
	CStu st;
	CString res;
	res.Format(_T("id = '%s'"),dlg.m_id);
	st.m_strFilter.Format(res);
	st.Open();
	if( !st.IsEOF() )
	{
		MessageBox(_T("��ѧ���Ѵ���!"),_T("��ʾ"),MB_ICONERROR);
		st.Close();
		return;
	}
	st.AddNew();
	st.m_ID = dlg.m_id;  //_T("1000");
	st.m_name = dlg.m_name; //_T("������");
	st.m_age = dlg.m_age;//23;
	st.m_birth = dlg.m_birth;//CTime(1999,12,12,0,0,0);
	st.Update();
	st.Close();
	ShowData();
	/*
	//������ӵ�������list������ʾ
	int nRow = m_DataList.GetItemCount();
	m_DataList.InsertItem(nRow,dlg.m_id);
	m_DataList.SetItemText(nRow,1,dlg.m_name);
	CString s;
	s.Format(_T("%d"),dlg.m_age);
	m_DataList.SetItemText(nRow,2,s);
	m_DataList.SetItemText(nRow,3,dlg.m_birth.Format(_T("%Y-%m-%d")));
	*/
}


void CMyOBDCDlg::OnBnClickedDeleteBtn()
{
	int nSel = m_DataList.GetNextItem(-1,LVNI_SELECTED);
	if(nSel <0)//û��ѡ����
	{
		MessageBox(_T("û��ѡ����"),_T("��ʾ"));
		return;
	}
	if( MessageBox(_T("�Ƿ�ȷ��ɾ��ѡ����"),_T("��ʾ"),MB_ICONWARNING|MB_YESNO) == IDNO)
		return;
	CString s;
	s = m_DataList.GetItemText(nSel,0);
	/*
	CStu st;
	st.m_strFilter.Format(_T("ID='%s'"),s);
	st.Open();
	if(st.IsEOF())
		;//û���ҵ����������ļ�¼
	else
		st.Delete();
	st.Close();
	*/
	CDatabase db;
	db.Open(_T("Stu"));
	CString sql;
	sql.Format(_T("delete from stu where id = '%s'"),s);
	db.ExecuteSQL(sql);
	db.Close();

	m_DataList.DeleteItem(nSel);

	//ShowData();
}


void CMyOBDCDlg::OnBnClickedUpdateBtn()
{
	int nSel = m_DataList.GetNextItem(-1,LVNI_SELECTED);
	if(nSel <0)//û��ѡ����
	{
		MessageBox(_T("û��ѡ����"),_T("��ʾ"));
		return;
	}
	//��ѡ������Ϣ�ڶԻ�������ʾ
	DlgOp dlg;
	dlg.m_strCaption = _T("�޸�ѧ����Ϣ");
	dlg.m_id = m_DataList.GetItemText(nSel,1);
	dlg.m_name = m_DataList.GetItemText(nSel,2);
	CString temp = m_DataList.GetItemText(nSel,3);
	dlg.m_age = atoi(CW2A(temp));
	CString strTime = m_DataList.GetItemText(nSel,4);
	//dlg.m_birth = CStringToCtime(strTime);
	
	if(dlg.DoModal() == IDCANCEL)
		return;

	CStu st;
	st.m_strFilter.Format(_T("ID='%s'"),dlg.m_id);
	st.Open();
	st.Edit();
	st.m_name = dlg.m_name;
	st.m_age = dlg.m_age;
	st.m_birth = dlg.m_birth;
	st.Update();
	st.Close();
	//ShowData();

	m_DataList.SetItemText(nSel,2,dlg.m_name);
	CString s;
	s.Format(_T("%d"),dlg.m_age);
	m_DataList.SetItemText(nSel,3,s);
	m_DataList.SetItemText(nSel,4,dlg.m_birth.Format(_T("%Y-%m-%d")));
}

CTime CMyOBDCDlg::CStringToCtime(CString& s)
{
	int year;
	int month;
	int day;
	int nIndex,nIndex2;
	/*
	//����1��
	nIndex = s.Find('-');
	year = _wtof(s.Left(nIndex));
	nIndex2 = s.Find('-',nIndex+1);
	month = _wtof(s.Mid(nIndex+1,nIndex2 - nIndex -1));
	day = _wtof(s.Mid(nIndex2+1));
	*/
	//����2��
	CString temp;
	nIndex = s.Find('-');
	temp = s.Left(nIndex);
	year = atoi(CW2A(temp));
	nIndex2 = s.Find('-',nIndex+1);
	temp = s.Mid(nIndex+1,nIndex2 - nIndex -1);
	month = atoi(CW2A(temp));
	temp = s.Mid(nIndex2+1);
	day = atoi(CW2A(temp));
	//COleDateTime time(year,month,day,0,0,0);
	CTime time (year,month,day,0,0,0);
	return time;
}


COleDateTime CMyOBDCDlg::CStringToCOleDateTime(CString s)
{
	return COleDateTime();
}


void CMyOBDCDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if(!m_DataList.GetSafeHwnd())//m_DateList.hwnd
		return;
	DlgSizeChange(cx,cy);
	// TODO: �ڴ˴������Ϣ����������
}


void CMyOBDCDlg::DlgSizeChange(int width,int height)
{
	CWnd* p = GetDlgItem(IDC_QUERYDATA_BTN);
	CRect rc;
	int nDistance = 10;
	p->GetWindowRect(rc);
	this->ScreenToClient(rc);
	int x = nDistance;//������
	int y = rc.bottom + nDistance;//������
	//CRect rw;
	//this->GetClientRect(rw);
	//int w = rw.Width() - nDistance - nDistance;//��
	//int h = rw.Height() - nDistance - y;//��
	int w = width - nDistance - nDistance;
	int h = height - nDistance - y;
	m_DataList.MoveWindow(x,y,w,h);
	for(int i=1;i<5;i++)
		m_DataList.SetColumnWidth(i,w/5);

	//m_DataList.SetWindowPos(NULL,x,y,w,h,SWP_NOMOVE);
	//m_DataList.SetWindowPos(NULL,x,y,w,h,SWP_NOSIZE);
}


void CMyOBDCDlg::OnNMClickShowdataList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CMyOBDCDlg::OnNMRClickShowdataList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//
	CMenu menu;
	//����˵���Դ
	menu.LoadMenu(IDR_LISTPOP_MENU);
	CMenu* pMenu;
	int nSel = m_DataList.GetNextItem(-1,LVNI_SELECTED);
	//�õ��Ӳ˵�
	if(nSel<0)
		pMenu = menu.GetSubMenu(0);
	else
		pMenu = menu.GetSubMenu(1);
	//��ʾ�Ӳ˵�
	CPoint pos;
	GetCursorPos(&pos);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,pos.x,pos.y,this);

	*pResult = 0;
}


void CMyOBDCDlg::OnReflesh()
{
	OnBnClickedQuerydataBtn();
}


void CMyOBDCDlg::OnBnClickedListStyle()
{
	CMenu menu;
	menu.LoadMenu(IDR_LISTSTYLE_MENU);
	CMenu* pMenu;
	pMenu = menu.GetSubMenu(0);
	CWnd* pBtn = GetDlgItem(IDC_LIST_STYLE);
	CRect rc;
	pBtn->GetWindowRect(rc);
	int nID = m_nStyle;
	if( m_nStyle == LV_VIEW_SMALLICON)
		nID = ID_THUMBANAIL;
	else if( m_nStyle == LV_VIEW_TILE)
		nID = ID_TILE;
	else if( m_nStyle == LV_VIEW_ICON)
		nID = ID_ICON;
	else if( m_nStyle == LV_VIEW_LIST)
		nID = ID_LISTING;
	else
		nID = ID_DETAILINFO;
	pMenu->CheckMenuItem(nID,MF_CHECKED|MF_BYCOMMAND);

	pMenu->TrackPopupMenu(TPM_LEFTALIGN,rc.left,rc.bottom,this);
}


void CMyOBDCDlg::OnDetailinfo()
{
	//��ϸ��Ϣ
	//���÷�񣬷�Χ�ȽϹ�
	//m_DataList.ModifyStyle(m_nStyle,LVS_REPORT);
	//����View����
	m_DataList.SetView(LV_VIEW_DETAILS);
	//������Ϣ�ķ�ʽ
	//m_DataList.SendMessage(LVM_SETVIEW,LV_VIEW_DETAILS,0);
	m_nStyle = LV_VIEW_DETAILS;
}


void CMyOBDCDlg::OnThumbanail()
{
	m_DataList.SetImageList(&m_ImgList,LVSIL_SMALL);
	//����ͼ
	//m_DataList.ModifyStyle(m_nStyle,LVS_ICON);
	m_DataList.SetView(LV_VIEW_SMALLICON);
	m_nStyle = LV_VIEW_SMALLICON;
}


void CMyOBDCDlg::OnTile()
{
	m_DataList.SetImageList(&m_ImgList,LVSIL_NORMAL);
	//ƽ��
	//m_DataList.ModifyStyle(m_nStyle,LVS_SMALLICON);
	m_DataList.SetView(LV_VIEW_TILE);
	m_nStyle = LV_VIEW_TILE;
}


void CMyOBDCDlg::OnListing()
{
	m_DataList.SetImageList(&m_ImgList,LVSIL_SMALL);
	//�б�
	//m_DataList.ModifyStyle(m_nStyle,LVS_LIST);
	m_DataList.SetView(LV_VIEW_LIST);
	m_nStyle = LV_VIEW_LIST;
}


void CMyOBDCDlg::OnIcon()
{
	m_DataList.SetImageList(&m_ImgList,LVSIL_NORMAL);
	//ͼ��
	//m_DataList.ModifyStyle(m_nStyle,LVS_ICON);
	m_DataList.SetView(LV_VIEW_ICON);
	m_nStyle = LV_VIEW_ICON;
	
}
