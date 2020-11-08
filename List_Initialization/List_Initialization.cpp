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
	Init() : m_iInit0{ -1, -2, -3 } {}          // ���캯����Ա�б��ʼ��
private:
	std::vector<int> m_iInit0;
	std::vector<int> m_iInit1 = { 1,2,3 };      // ��ԱĬ���б��ʼ��
};

std::pair<int, std::string> DefineMap(const std::pair<int, std::string>& mapMap)
{
	return { mapMap.first, mapMap.second };		// return ����е��б��ʼ��
}

int main()
{
	VecNum vecNum{ 0,1,2,3 };
	vecNum.PrintNum();

	int iNum0{};                                // ֵ�б��ʼ��
	int iNum1{ 1 };                             // ֱ���б��ʼ��
	int iNum2 = { 1 };                          // �����б��ʼ��
	std::string sStr0{ 's', 't', 'r', 'i' };    // initializer_list ���캯������

	std::map<int, std::string> mapMap0 =		// Ƕ���б��ʼ��
	{
		{1, "s"},
		{2, {'s', 't', 'r'} },
		{3, sStr0}
	};

	std::pair<int, std::string> mapMap1
		= DefineMap({ 1, "str" });				// ���������е��б��ʼ��

	std::vector<std::string> sStr1("str");		//���󣬲���ʹ���ַ�������ֵ����vector����
	std::vector<std::string> sStr2{ "str" };	//�б��ʼ����sStr1��һ��Ԫ��"str"
	std::vector<std::string> sStr3(10);			//sStr3��10��Ĭ�ϳ�ʼ��""Ԫ��
	std::vector<std::string> sStr4{ 10 };		//sStr3��10��Ĭ�ϳ�ʼ��""Ԫ��
	std::vector<std::string> sStr5(10, "str");	//sStr5��10��ֵΪ"str"Ԫ��
	std::vector<std::string> sStr6{ 10,"str" };	//sStr6��10��ֵΪ"str"Ԫ��

	int bad{ 1.0 };								// ����խ��ת��
	unsigned char uc2{ -1 };					// ����խ��ת��

	Init initT0;

	return EXIT_SUCCESS;
}