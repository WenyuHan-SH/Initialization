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
	int& iNum1 = iNum0;                     // 到对象 n 的左值引用
	const int& iNum2(iNum0);                // 引用可以有const限定
	const int& iNum3{ iNum0 };              // 可使用任何初始化器语法

	int& iNum4 = iNum3;						// 错误：缺少const限定
	int& iNum5 = const_cast<int&>(iNum3);   // 需要 const_cast

	void(&RFun)(int) = InitFun;             // 到函数的左值引用
	int iArray[3]{ 0 };
	int(&iRArray)[3] = iArray;              // 到数组的左值引用

	int& iNum6 = 1;                         // 错误：不能绑定左值引用到右值
	const int& iNum7 = 1;                   // 绑定到右值

	int&& iNum8 = 1;                        // 绑定到右值
	int&& iNum9 = iNum0;					// 错误：不能绑定右值引用到左值
	int&& iNum10 = static_cast<int&&>(iNum0); // 直接绑定到iNum0

	return EXIT_SUCCESS;
}