#pragma once


// CNewListView ��ͼ

class CNewListView : public CListView
{
	DECLARE_DYNCREATE(CNewListView)

public:
	CNewListView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CNewListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


