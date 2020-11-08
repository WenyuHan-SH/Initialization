#include <string>
#include <utility>
#include <memory>

class Init0
{
public:
	Init0() {};
	Init0(const Init0&) {};
	operator int() { return m_iInit; }
private:
	int m_iInit;
};

class Init1
{
public:
	Init1();
	explicit Init1(int) {};
	Init1(const Init1&) {};
private:
	int m_iInit;
};

int main()
{
	std::string sString0 = "string";				// ���캯���� explicit
	std::string sString1 = std::move(sString0);		// ���Ƴ�ʼ�������ƶ�

	//std::unique_ptr<int> piNum0 = new int(1);		// ���󣺹��캯��Ϊ explicit
	std::unique_ptr<int> piNum1(new int(1));		// ֱ�ӳ�ʼ��

	int iNum0 = 3.14;								// ��������ת��
	const int iNum1 = iNum0;						// ���� const ���

	Init0 init0T0;
	Init1 init1T0 = 1;								// ���󣺹��캯��Ϊ explicit
	Init1 init1T1 = init1T0;						// ���ÿ������캯��
	Init1 init1T2{ init0T0 };						// ���� Init0::operator int(),����Init1::Init1(int)
	Init1 init1T3 = { init0T0 };					// ���󣺹��캯��Ϊ explicit
	Init1 init1T4 = Init1{ init0T0 };				// ���� Init0::operator int(),����Init1::Init1(int)
	return EXIT_SUCCESS;
}