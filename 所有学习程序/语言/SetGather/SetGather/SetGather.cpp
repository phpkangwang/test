// SetGather.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "SetInt.h"
#include "TemplateSet.h"


//==========函数对象========

//删除时的判定条件
class FuncObject
{
public:
	FuncObject(bool even)
	{
		IsEven = even;
	}
public:
	bool operator()(int data)
	{
		if(IsEven)
			return data % 2 == 0;
		return data % 2 == 1;
	}
private:
	bool IsEven;//是否为偶数
};

//将大于某个数字的删除
class Greater
{
public:
	Greater(int data)
	{
		nGreater = data;
	}
public:
	bool operator()(int data)
	{
		return data >nGreater;
	}
private:
	int nGreater;
};

class DelStrBContain
{
public:
	DelStrBContain(string str)
	{
		request = str;
	}
public:
	bool operator()(string str)
	{
		return str.find(request) != string::npos;
	}
private:
	string request;
};

class DelName_Begin
{
public:
	DelName_Begin(string r)
	{
		request = r;
	}
public:
	bool operator()(Stu& stu)
	{
		string name = stu.GetName();
		string Name_begin = name.substr(0,request.length());
		return Name_begin == request;
	}
private:
	string request;
};

int _tmain(int argc, _TCHAR* argv[])
{

	/*TemplateSet<int,5> a;
	a.AddData(1);
	a.AddData(2);
	a.AddData(3);
	a.AddData(4);
	a.DeleteIfEx(Greater(2));
	a.DeleteIfEx(FuncObject(true));

	a.DeleteIfEx(DelEven);
	a.Print();*/

	//TemplateSet<Stu> st;
	//st.AddData(Stu("13517","孙浩",22));
	//st.AddData(Stu("13518","张宏杰",23));
	//st.AddData(Stu("13519","张卫卫",24));
	//st.AddData(Stu("13520","张盼盼",21));
	//st.DeleteIfEx(DelName_Begin("张"));
	////st.Delete(Stu("13518","张宏杰",23),DeleteByName);
	////st.DeleteIf(DelNameBegin);
	//st.Print();
	
	TemplateSet<string> ss;
	ss.AddData("123");
	ss.AddData("asd");
	ss.AddData("q23");
	ss.AddData("123456");
	ss.AddData("asdasd");
	ss.DeleteIfEx(DelStrBContain("23"));

	//ss.DeleteIf(DeleteStrSome);
	ss.Print();

	return 0;
}