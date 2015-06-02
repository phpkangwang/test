#pragma once

// CFuncPane

const UINT ID_BOOK_borrow = 1218;
const UINT ID_BOOK_borrow_return_search = ID_BOOK_borrow +1;
const UINT ID_BOOK_history_search = ID_BOOK_borrow +2;
const UINT ID_BOOK_new_book_search = ID_BOOK_borrow +3;
const UINT ID_BOOK_insert_new_book_info = ID_BOOK_borrow +4;
const UINT ID_BOOK_return = ID_BOOK_borrow +5;


class CFuncPane : public CDockablePane
{
	DECLARE_DYNAMIC(CFuncPane)

public:
	CMFCOutlookBar m_Outlook;

	CMFCOutlookBarPane m_paneBorrow;
	CMFCOutlookBarPane m_paneReturn;
	
	CImageList m_ImgList;
public:
	CFuncPane();
	virtual ~CFuncPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


