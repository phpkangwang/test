// MyView.h : CMyView ���ʵ��



// CMyView ʵ��

// ���������� 2013��7��23��, 17:21

#include "stdafx.h"
#include "MyView.h"
IMPLEMENT_DYNAMIC(CMyView, CRecordset)

CMyView::CMyView(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_name = L"";
	m_age = 0;
	m_birth;
	m_ID = L"";
	m_Grade = 0.0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMyView::GetDefaultConnect()
{
	return _T("DSN=Stu;APP=Microsoft\x00ae Visual Studio\x00ae 2010;WSID=A14;DATABASE=MyDataBase;Trusted_Connection=Yes");
}

CString CMyView::GetDefaultSQL()
{
	return _T("[dbo].[MyView]");
}

void CMyView::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Int(pFX, _T("[age]"), m_age);
	RFX_Date(pFX, _T("[birth]"), m_birth);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Single(pFX, _T("[Grade]"), m_Grade);

}
/////////////////////////////////////////////////////////////////////////////
// CMyView ���

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


