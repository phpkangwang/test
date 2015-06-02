// Stu.h : CStu ���ʵ��



// CStu ʵ��

// ���������� 2013��7��23��, 16:35

#include "stdafx.h"
#include "Stu.h"
IMPLEMENT_DYNAMIC(CStu, CRecordset)

CStu::CStu(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = L"";
	m_name = L"";
	m_age = 0;
	m_birth;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CStu::GetDefaultConnect()
{
	return _T("DSN=Stu;APP=Microsoft\x00ae Visual Studio\x00ae 2010;WSID=A14;DATABASE=MyDataBase;Trusted_Connection=Yes");
}

CString CStu::GetDefaultSQL()
{
	return _T("[dbo].[Stu]");
}

void CStu::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Int(pFX, _T("[age]"), m_age);
	RFX_Date(pFX, _T("[birth]"), m_birth);

}
/////////////////////////////////////////////////////////////////////////////
// CStu ���

#ifdef _DEBUG
void CStu::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStu::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


