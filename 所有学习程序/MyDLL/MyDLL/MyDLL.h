// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MYDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MYDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

namespace mydll
{
	// �����Ǵ� MyDLL.dll ������
	class MYDLL_API CMyDLL {
	public:
		CMyDLL(void);
		// TODO: �ڴ�������ķ�����
	public:
		int Inc(int& nData);
	};

	extern MYDLL_API int nMyDLL;

	MYDLL_API int fnMyDLL(void);
}