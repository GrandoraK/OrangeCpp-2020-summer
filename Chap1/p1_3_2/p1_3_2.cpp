#include <iostream>

int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}

int main(void)
{
	std::cout << "SimpleFunc(int a = 10) ȣ�� : " << SimpleFunc(7) << std::endl;
	//std::cout << "SimpleFunc(void) ȣ�� : " << SimpleFunc() << std::endl;
	return 0;
}

//�������� �ڵ�!
//main�Լ����� SimpleFunc()�� ȣ���ϸ� SimpleFunc(int a = 10)�� SimpleFunc(void) �� �� �ҷ� ���´�.