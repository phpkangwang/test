// NewFormView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SdiDockablePane.h"
#include "NewFormView.h"


// CNewFormView

IMPLEMENT_DYNCREATE(CNewFormView, CFormView)

CNewFormView::CNewFormView()
	: CFormView(CNewFormView::IDD)
{

}

CNewFormView::~CNewFormView()
{
}

void CNewFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNewFormView, CFormView)
END_MESSAGE_MAP()


// CNewFormView ���

#ifdef _DEBUG
void CNewFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CNewFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CNewFormView ��Ϣ�������
