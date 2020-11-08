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
	std::string sString0 = "string";				// 构造函数非 explicit
	std::string sString1 = std::move(sString0);		// 复制初始化进行移动

	//std::unique_ptr<int> piNum0 = new int(1);		// 错误：构造函数为 explicit
	std::unique_ptr<int> piNum1(new int(1));		// 直接初始化

	int iNum0 = 3.14;								// 浮点整型转换
	const int iNum1 = iNum0;						// 不受 const 与否

	Init0 init0T0;
	Init1 init1T0 = 1;								// 错误：构造函数为 explicit
	Init1 init1T1 = init1T0;						// 调用拷贝构造函数
	Init1 init1T2{ init0T0 };						// 调用 Init0::operator int(),调用Init1::Init1(int)
	Init1 init1T3 = { init0T0 };					// 错误：构造函数为 explicit
	Init1 init1T4 = Init1{ init0T0 };				// 调用 Init0::operator int(),调用Init1::Init1(int)
	return EXIT_SUCCESS;
}