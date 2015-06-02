// FuncPane.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SdiDockablePane.h"
#include "FuncPane.h"


// CFuncPane

IMPLEMENT_DYNAMIC(CFuncPane, CDockablePane)

CFuncPane::CFuncPane()
{

}

CFuncPane::~CFuncPane()
{
}


BEGIN_MESSAGE_MAP(CFuncPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CFuncPane ��Ϣ�������


int CFuncPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rc;
	GetClientRect(rc);
	// TODO:  �ڴ������ר�õĴ�������
	if(!m_Outlook.Create(
		_T("ͼ�����"),
		this,
		rc,
		ID_OUTLOOK,
		WS_CHILD|WS_VISIBLE|CBRS_ALIGN_ANY)
	   )
	   return -1;

	CMFCOutlookBarTabCtrl* pTab = 
		(CMFCOutlookBarTabCtrl*)m_Outlook.GetUnderlyingWindow();

	if(!m_paneBorrow.Create(
		&m_Outlook,
		AFX_DEFAULT_TOOLBAR_STYLE,//WS_CHILD|WS_VISIBLE,//|AFX_CBRS_FLOAT,
		ID_PANAE_BORROW_1)
		)
		return -1;
	pTab->AddTab(&m_paneBorrow,_T("����Ա"),-1,FALSE);
	if(!m_paneReturn.Create(
		&m_Outlook,
		AFX_DEFAULT_TOOLBAR_STYLE,
		ID_PANAE_RETURN_1)
		)
		return -1;
	pTab->AddTab(&m_paneReturn,_T("�û�"),-1,FALSE);

	CString ImgNames[] = 
	{
		_T("¼��.png"),
		_T("�黹.png"),
		_T("����.png"),
		_T("���� �黹.png"),
		_T("���� �黹.png"),
		_T("���� �黹.png")
	};
	CString Lables[] = 
	{
		_T("¼��"),
		_T("�黹"),
		_T("����"),
		_T("¼��"),
		_T("�黹"),
		_T("¼��")
	};

	UINT ID[] = 
	{
		ID_BOOK_borrow,
		ID_BOOK_borrow_return_search,
		ID_BOOK_history_search,
		ID_BOOK_new_book_search,
		ID_BOOK_insert_new_book_info,
		ID_BOOK_return
	};

	m_ImgList.Create(85,43,ILC_COLOR24,6,1);
	CImage img;
	CBitmap* bmp;
	COLORREF color = RGB(255,0,255);
	CString s;
	for(int i =0;i <6;i++)
	{
		s.Format(_T("images\\%s"),ImgNames[i]);
		img.Load(s);
		bmp = CBitmap::FromHandle(img);
		m_ImgList.Add(bmp,color);
		img.Detach();
	}

	for(int i =0;i <3;i++)
	{
		m_paneBorrow.AddButton(
			m_ImgList.ExtractIcon(i),
			Lables[i],
			ID[i],
			-1,
			TRUE
			);
	}
	
	
	for(int i =3;i <6;i++)
	{
		m_paneReturn.AddButton(
			m_ImgList.ExtractIcon(i),
			Lables[i],
			ID[i],
			-1,
			TRUE
			);
	}

	return 0;
}


void CFuncPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	if(m_Outlook.GetSafeHwnd())
	{
		m_Outlook.MoveWindow(CRect(0,0,cx,cy));
	}
	// TODO: �ڴ˴������Ϣ����������
}
