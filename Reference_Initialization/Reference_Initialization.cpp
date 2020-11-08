#include <utility>
#include <sstream>

void InitFun(int) {}

class Init0 {};

class Init1 : Init0
{
public:
	operator int& () { return m_iInit; };

	int m_iInit;
};

int main()
{
	int iNum0 = 1;
	int& iNum1 = iNum0;                     // ������ n ����ֵ����
	const int& iNum2(iNum0);                // ���ÿ�����const�޶�
	const int& iNum3{ iNum0 };              // ��ʹ���κγ�ʼ�����﷨

	int& iNum4 = iNum3;						// ����ȱ��const�޶�
	int& iNum5 = const_cast<int&>(iNum3);   // ��Ҫ const_cast

	void(&RFun)(int) = InitFun;             // ����������ֵ����
	int iArray[3]{ 0 };
	int(&iRArray)[3] = iArray;              // ���������ֵ����

	int& iNum6 = 1;                         // ���󣺲��ܰ���ֵ���õ���ֵ
	const int& iNum7 = 1;                   // �󶨵���ֵ

	int&& iNum8 = 1;                        // �󶨵���ֵ
	int&& iNum9 = iNum0;					// ���󣺲��ܰ���ֵ���õ���ֵ
	int&& iNum10 = static_cast<int&&>(iNum0); // ֱ�Ӱ󶨵�iNum0

	return EXIT_SUCCESS;
}