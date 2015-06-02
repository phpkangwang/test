// Stu.h : CStu 类的实现



// CStu 实现

// 代码生成在 2013年7月23日, 16:35

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Int(pFX, _T("[age]"), m_age);
	RFX_Date(pFX, _T("[birth]"), m_birth);

}
/////////////////////////////////////////////////////////////////////////////
// CStu 诊断

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


