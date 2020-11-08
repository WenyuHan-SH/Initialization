#include <iostream>
#include <vector>
#include <map>
#include <string>

class VecNum
{
public:
	VecNum(const std::initializer_list<int>& vecNum)
	{
		for (auto num : vecNum)
		{
			m_vecNum.push_back(num);
		}
	}

	void PrintNum(void)
	{
		for (auto num : m_vecNum)
		{
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
private:
	std::vector<int> m_vecNum;
};

class Init
{
public:
	Init() : m_iInit0{ -1, -2, -3 } {}          // 构造函数成员列表初始化
private:
	std::vector<int> m_iInit0;
	std::vector<int> m_iInit1 = { 1,2,3 };      // 成员默认列表初始化
};

std::pair<int, std::string> DefineMap(const std::pair<int, std::string>& mapMap)
{
	return { mapMap.first, mapMap.second };		// return 语句中的列表初始化
}

int main()
{
	VecNum vecNum{ 0,1,2,3 };
	vecNum.PrintNum();

	int iNum0{};                                // 值列表初始化
	int iNum1{ 1 };                             // 直接列表初始化
	int iNum2 = { 1 };                          // 拷贝列表初始化
	std::string sStr0{ 's', 't', 'r', 'i' };    // initializer_list 构造函数调用

	std::map<int, std::string> mapMap0 =		// 嵌套列表初始化
	{
		{1, "s"},
		{2, {'s', 't', 'r'} },
		{3, sStr0}
	};

	std::pair<int, std::string> mapMap1
		= DefineMap({ 1, "str" });				// 函数调用中的列表初始化

	std::vector<std::string> sStr1("str");		//错误，不能使用字符串字面值构造vector对象
	std::vector<std::string> sStr2{ "str" };	//列表初始化，sStr1有一个元素"str"
	std::vector<std::string> sStr3(10);			//sStr3有10个默认初始化""元素
	std::vector<std::string> sStr4{ 10 };		//sStr3有10个默认初始化""元素
	std::vector<std::string> sStr5(10, "str");	//sStr5有10个值为"str"元素
	std::vector<std::string> sStr6{ 10,"str" };	//sStr6有10个值为"str"元素

	int bad{ 1.0 };								// 错误：窄化转换
	unsigned char uc2{ -1 };					// 错误：窄化转换

	Init initT0;

	return EXIT_SUCCESS;
}