#pragma once



// CNewFormView ������ͼ

class CNewFormView : public CFormView
{
	DECLARE_DYNCREATE(CNewFormView)

public:
	CNewFormView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


