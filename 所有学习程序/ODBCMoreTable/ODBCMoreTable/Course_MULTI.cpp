// Course_MULTI.h : CCourse_MULTI ���ʵ��



// CCourse_MULTI ʵ��

// ���������� 2013��7��23��, 15:48

#include "stdafx.h"
#include "Course_MULTI.h"
IMPLEMENT_DYNAMIC(CCourse_MULTI, CRecordset)

CCourse_MULTI::CCourse_MULTI(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_dboCourseCourseID = L"";
	m_dboCourseCourseName = L"";
	m_dboCourseCredit = 0;
	m_dboStuID = L"";
	m_dboStuname = L"";
	m_dboStuage = 0;
	m_dboStubirth;
	m_dboStuCourseStuID = L"";
	m_dboStuCourseCourseID = L"";
	m_dboStuCourseGrade = 0.0;
	m_nFields = 10;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CCourse_MULTI::GetDefaultConnect()
{
	return _T("DSN=Stu;APP=Microsoft\x00ae Visual Studio\x00ae 2010;WSID=A14;DATABASE=MyDataBase;Trusted_Connection=Yes");
}

CString CCourse_MULTI::GetDefaultSQL()
{
	return _T("[dbo].[Course],[dbo].[Stu],[dbo].[StuCourse]");
}

void CCourse_MULTI::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[dbo].[Course].[CourseID]"), m_dboCourseCourseID);
	RFX_Text(pFX, _T("[dbo].[Course].[CourseName]"), m_dboCourseCourseName);
	RFX_Int(pFX, _T("[dbo].[Course].[Credit]"), m_dboCourseCredit);
	RFX_Text(pFX, _T("[dbo].[Stu].[ID]"), m_dboStuID);
	RFX_Text(pFX, _T("[dbo].[Stu].[name]"), m_dboStuname);
	RFX_Int(pFX, _T("[dbo].[Stu].[age]"), m_dboStuage);
	RFX_Date(pFX, _T("[dbo].[Stu].[birth]"), m_dboStubirth);
	RFX_Text(pFX, _T("[dbo].[StuCourse].[StuID]"), m_dboStuCourseStuID);
	RFX_Text(pFX, _T("[dbo].[StuCourse].[CourseID]"), m_dboStuCourseCourseID);
	RFX_Single(pFX, _T("[dbo].[StuCourse].[Grade]"), m_dboStuCourseGrade);

}
/////////////////////////////////////////////////////////////////////////////
// CCourse_MULTI ���

#ifdef _DEBUG
void CCourse_MULTI::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCourse_MULTI::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


