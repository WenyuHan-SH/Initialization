#include <string>
#include <iostream>
#include <memory>

class Init
{
public:
    explicit Init(int iNum) : m_iInit(iNum)
    {}
public:
    int m_iInit;
};

int main()
{
    std::string sStr0("string");            // const char* 构造函数,初始化为"string"
    std::string sStr1(10,'s');              ////sStr1有10个值为's'元素

    Init initT0(1);                         // initT0 直接初始化
                                            // initT0.m_iInit 从形参n直接初始化
    Init initT1 = 1;                        // 错误：构造函数为 explicit
    return EXIT_SUCCESS;
}