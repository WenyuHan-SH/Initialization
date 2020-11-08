#include <string>
#include <vector>
#include <iostream>

class Init0
{
private:
    int         m_iInit0;
    std::string m_sInit1;
}; 

class Init1
{
public:
	Init1(const Init1&) { }     // 拷贝构造函数
						        // 无默认构造函数
private:
	int         m_iInit0;
	std::string m_sInit1;
};

struct Init2
{
public:
    Init2() { }                 // 默认构造函数
private:
    int         m_iInit0;
    std::string m_sInit1;
};

int main()
{
    int iNum0 = int();          // 值初始化，值为 0.0
    int iNum1 = int{};
    int* piNum2 = new int();
    int* piNum3 = new int{};
    Init0 init0T0{};            // 隐式默认构造函数
                                // init0T0.m_iInit0 默认初始化为 0
                                // init0T0.m_sInit1 默认初始化为 ""
    Init1 init1T1{};            // 错误：类无默认构造函数
    Init2 init2T2{};            // 提供默认构造函数
                                // init2T2.m_iInit0 默认初始化为不确定值
                                // init2T2.m_sInit1 默认初始化为 ""
    delete piNum2;
    delete piNum3;
    return EXIT_SUCCESS;
}