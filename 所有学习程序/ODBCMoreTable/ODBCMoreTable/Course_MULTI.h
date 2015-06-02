// Course_MULTI.h : CCourse_MULTI ������

#pragma once

// ���������� 2013��7��23��, 15:48

class CCourse_MULTI : public CRecordset
{
public:
	CCourse_MULTI(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourse_MULTI)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	m_dboCourseCourseID;
	CStringW	m_dboCourseCourseName;
	int	m_dboCourseCredit;
	CStringW	m_dboStuID;
	CStringW	m_dboStuname;
	int	m_dboStuage;
	COleDateTime	m_dboStubirth;
	CStringW	m_dboStuCourseStuID;
	CStringW	m_dboStuCourseCourseID;
	float	m_dboStuCourseGrade;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


