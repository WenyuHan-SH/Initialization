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
    std::string sStr0("string");            // const char* ���캯��,��ʼ��Ϊ"string"
    std::string sStr1(10,'s');              ////sStr1��10��ֵΪ's'Ԫ��

    Init initT0(1);                         // initT0 ֱ�ӳ�ʼ��
                                            // initT0.m_iInit ���β�nֱ�ӳ�ʼ��
    Init initT1 = 1;                        // ���󣺹��캯��Ϊ explicit
    return EXIT_SUCCESS;
}