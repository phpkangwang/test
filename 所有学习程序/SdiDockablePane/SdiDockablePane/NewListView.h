#pragma once


// CNewListView 视图

class CNewListView : public CListView
{
	DECLARE_DYNCREATE(CNewListView)

public:
	CNewListView();           // 动态创建所使用的受保护的构造函数
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


