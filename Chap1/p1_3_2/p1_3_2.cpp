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
	std::cout << "SimpleFunc(int a = 10) 호출 : " << SimpleFunc(7) << std::endl;
	//std::cout << "SimpleFunc(void) 호출 : " << SimpleFunc() << std::endl;
	return 0;
}

//에러나는 코드!
//main함수에서 SimpleFunc()를 호출하면 SimpleFunc(int a = 10)과 SimpleFunc(void) 둘 다 불려 나온다.