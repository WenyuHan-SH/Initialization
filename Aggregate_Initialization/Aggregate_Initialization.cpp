#include <string>
#include <array>
struct Init0
{
	int m_Init0;
	struct Init1 {
		int m_Init1;
		int m_Init2;
		int m_Init3[3];
	} str;
};

int main()
{
	Init0 init0T0 = { 1, { 2, 3, {4, 5, 6} } };     // 聚合初始化,使用拷贝列表初始化语法
	Init0 init0T1 = { 1, 2, 3, 4, 5, 6 };
	Init0 init0T2{ 1, {2, 3, {4, 5, 6} } };         // 聚合初始化,使用直接列表初始化语法
	Init0 init0T3{ 1, 2, 3, 4, 5, 6 };

	int iNum0[] = { 1,2,3 };                        // iNum0为int[3]
	char cChra0[3] = { 'a', 'b', 'c', 'd' };        // 错误：过多初始化器子句
	char cChra1[3] = { 'a' };                       // 数组初始化为{'a', '\0','\0'}

	int iNum1[2][2] = { {1, 2}, {3, 4} };           // 完全花括号的二维数组:{1, 2} {3, 4}  
	int iNum2[2][2] = { 1, 2, 3, 4 };               // 花括号消除:{1, 2}{3, 4}
	int iNum3[2][2] = { {1}, {2} };                 // 仅第一列:{1, 0}{2, 0}

	std::array<int, 3> ipNum4{ {1,2,3} };			// std::array 是聚合体
	std::array<int, 3> ipNum5 = { 1, 2, 3 };

	int ai[] = { 1, 2.0 };							// 错误：从 double 到 int 的窄化转换：

	std::string ars[] = { std::string("one"),		// 拷贝列表初始化
						 "two",
						 {'t', 'h', 'r', 'e', 'e'} };
	return EXIT_SUCCESS;
}