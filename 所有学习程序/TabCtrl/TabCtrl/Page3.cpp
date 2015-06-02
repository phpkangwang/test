// Page3.cpp : 实现文件
//

#include "stdafx.h"
#include "TabCtrl.h"
#include "Page3.h"
#include "afxdialogex.h"


// CPage3 对话框

IMPLEMENT_DYNAMIC(CPage3, CPropertyPage)

CPage3::CPage3()
	: CPropertyPage(CPage3::IDD)
{

}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage3, CPropertyPage)
END_MESSAGE_MAP()


// CPage3 消息处理程序
