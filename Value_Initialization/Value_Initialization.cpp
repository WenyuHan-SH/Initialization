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
	Init1(const Init1&) { }     // �������캯��
						        // ��Ĭ�Ϲ��캯��
private:
	int         m_iInit0;
	std::string m_sInit1;
};

struct Init2
{
public:
    Init2() { }                 // Ĭ�Ϲ��캯��
private:
    int         m_iInit0;
    std::string m_sInit1;
};

int main()
{
    int iNum0 = int();          // ֵ��ʼ����ֵΪ 0.0
    int iNum1 = int{};
    int* piNum2 = new int();
    int* piNum3 = new int{};
    Init0 init0T0{};            // ��ʽĬ�Ϲ��캯��
                                // init0T0.m_iInit0 Ĭ�ϳ�ʼ��Ϊ 0
                                // init0T0.m_sInit1 Ĭ�ϳ�ʼ��Ϊ ""
    Init1 init1T1{};            // ��������Ĭ�Ϲ��캯��
    Init2 init2T2{};            // �ṩĬ�Ϲ��캯��
                                // init2T2.m_iInit0 Ĭ�ϳ�ʼ��Ϊ��ȷ��ֵ
                                // init2T2.m_sInit1 Ĭ�ϳ�ʼ��Ϊ ""
    delete piNum2;
    delete piNum3;
    return EXIT_SUCCESS;
}