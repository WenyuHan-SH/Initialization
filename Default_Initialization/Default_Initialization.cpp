#include <iostream>
int Undefinedbehavior(bool bBool);

class Init0 
{ 
private:
	int m_iInit;
};

class Init1
{
public:
	Init1() { }					// m_iInit ���ڳ�ʼ�����б���
private:
	int m_iInit;
};

int n; 

int main()
{
	int iNum0;						// ���ֵ࣬��ȷ��
	std::string sString;			// �࣬����Ĭ�Ϲ��캯����ֵ��""
	std::string pString[2];			// ���飬Ĭ�ϳ�ʼ�����Ԫ�أ�ֵ�� {"", ""}
	int& iNum1;						// ��������
	const int iNum2;				// ����const �ķ���
	Init0 initT0;					// �࣬������ʽĬ�Ϲ��캯��
									// initT0.m_iInit Ĭ�ϳ�ʼ��Ϊ��ȷ��ֵ
	const Init1 initT1;				// const �࣬����Ĭ�Ϲ��캯��
									// initT1.m_iInit ��Ĭ�ϳ�ʼ��Ϊ��ȷ��ֵ
	int* pNum3 = new int;			// ���ֵ࣬��ȷ��
	Undefinedbehavior(true);
	return EXIT_SUCCESS;
}

int Undefinedbehavior(bool bBool)
{
	int iNum4;
	int iNum5 = iNum4;				// ����δ������Ϊ
	return bBool ? iNum5 : 0;		// ����δ������Ϊ��bBoolΪtrue
}