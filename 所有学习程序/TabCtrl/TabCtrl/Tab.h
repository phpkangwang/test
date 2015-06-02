#pragma once

// CTab

#include "Dlg1.h"
#include "Dlg2.h"
#include "Dlg3.h"

class CTab : public CTabCtrl
{
	DECLARE_DYNAMIC(CTab)
public:
	CDlg1 m_dlg1;
	CDlg2 m_dlg2;
	CDlg3 m_dlg3;
	int m_nSel;

public:
	CTab();
	virtual ~CTab();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
};


