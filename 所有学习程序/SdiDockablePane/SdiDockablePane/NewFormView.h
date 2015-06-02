#pragma once



// CNewFormView 窗体视图

class CNewFormView : public CFormView
{
	DECLARE_DYNCREATE(CNewFormView)

public:
	CNewFormView();           // 动态创建所使用的受保护的构造函数
	virtual ~CNewFormView();

public:
	enum { IDD = IDD_NEWFORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


