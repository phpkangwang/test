// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CALDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CALDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CALDLL_EXPORTS
#define CALDLL_API __declspec(dllexport)
#else
#define CALDLL_API __declspec(dllimport)
#endif

// �����Ǵ� CalDLL.dll ������
class CALDLL_API CCalDLL {
public:
	CCalDLL(void);
	// TODO: �ڴ�������ķ�����
};

extern CALDLL_API int nCalDLL;

CALDLL_API int fnCalDLL(void);
