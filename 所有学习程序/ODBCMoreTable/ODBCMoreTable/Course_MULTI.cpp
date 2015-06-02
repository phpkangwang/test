// Course_MULTI.h : CCourse_MULTI 类的实现



// CCourse_MULTI 实现

// 代码生成在 2013年7月23日, 15:48

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
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
// CCourse_MULTI 诊断

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


