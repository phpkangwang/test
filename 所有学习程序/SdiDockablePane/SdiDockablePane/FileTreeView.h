#pragma once


// CFileTreeView

class CFileTreeView : public CDockablePane
{
	DECLARE_DYNAMIC(CFileTreeView)

public:
	CFileTreeView();
	virtual ~CFileTreeView();
public:
	CTreeCtrl m_tree;
	CMFCToolBar m_toolBar;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int& GetData(void);
};


