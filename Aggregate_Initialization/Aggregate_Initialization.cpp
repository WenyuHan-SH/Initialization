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
	Init0 init0T0 = { 1, { 2, 3, {4, 5, 6} } };     // �ۺϳ�ʼ��,ʹ�ÿ����б��ʼ���﷨
	Init0 init0T1 = { 1, 2, 3, 4, 5, 6 };
	Init0 init0T2{ 1, {2, 3, {4, 5, 6} } };         // �ۺϳ�ʼ��,ʹ��ֱ���б��ʼ���﷨
	Init0 init0T3{ 1, 2, 3, 4, 5, 6 };

	int iNum0[] = { 1,2,3 };                        // iNum0Ϊint[3]
	char cChra0[3] = { 'a', 'b', 'c', 'd' };        // ���󣺹����ʼ�����Ӿ�
	char cChra1[3] = { 'a' };                       // �����ʼ��Ϊ{'a', '\0','\0'}

	int iNum1[2][2] = { {1, 2}, {3, 4} };           // ��ȫ�����ŵĶ�ά����:{1, 2} {3, 4}  
	int iNum2[2][2] = { 1, 2, 3, 4 };               // ����������:{1, 2}{3, 4}
	int iNum3[2][2] = { {1}, {2} };                 // ����һ��:{1, 0}{2, 0}

	std::array<int, 3> ipNum4{ {1,2,3} };			// std::array �Ǿۺ���
	std::array<int, 3> ipNum5 = { 1, 2, 3 };

	int ai[] = { 1, 2.0 };							// ���󣺴� double �� int ��խ��ת����

	std::string ars[] = { std::string("one"),		// �����б��ʼ��
						 "two",
						 {'t', 'h', 'r', 'e', 'e'} };
	return EXIT_SUCCESS;
}