#include <iostream>
int Undefinedbehavior(bool bBool);

class Init0 
{ 
private:
	int m_iInit;
};

class Init1
{
public:
	Init1() { }					// m_iInit 不在初始化器列表中
private:
	int m_iInit;
};

int n; 

int main()
{
	int iNum0;						// 非类，值不确定
	std::string sString;			// 类，调用默认构造函数，值是""
	std::string pString[2];			// 数组，默认初始化其各元素，值是 {"", ""}
	int& iNum1;						// 错误：引用
	const int iNum2;				// 错误：const 的非类
	Init0 initT0;					// 类，调用隐式默认构造函数
									// initT0.m_iInit 默认初始化为不确定值
	const Init1 initT1;				// const 类，调用默认构造函数
									// initT1.m_iInit 被默认初始化为不确定值
	int* pNum3 = new int;			// 非类，值不确定
	Undefinedbehavior(true);
	return EXIT_SUCCESS;
}

int Undefinedbehavior(bool bBool)
{
	int iNum4;
	int iNum5 = iNum4;				// 错误：未定义行为
	return bBool ? iNum5 : 0;		// 错误：未定义行为，bBool为true
}