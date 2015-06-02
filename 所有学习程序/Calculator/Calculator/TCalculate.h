#pragma once

#ifdef CALDLL_EXPORTS
#define CALDLL_API __declspec(dllexport)
#else
#define CALDLL_API __declspec(dllimport)
#endif

namespace  TCalLib
{
	class CALDLL_API TCalculate
	{
	public:
		TCalculate(void);
		~TCalculate(void);
	private:
		double m_dLeft;
		double m_dRight;
		char m_CharOp;
		double m_dCoff;
	public:
		void Init(void);
		double DoInput(int data);
		double DoCalculate(char newOp);
		double QuFan(void);
		double GetCoff(void);
		void ChangeCoff(void);
		double Recip(CString cstr);
		double Evol(double d);
		CString DoubleToCString(double d);
		CString m_ShowRes;
	};
}