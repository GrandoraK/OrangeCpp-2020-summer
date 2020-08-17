#include <iostream>

inline int SQUARE(int x)	//이것이 인라인 함수다
{
	return x * x;
}

int main(void)
{
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(12) << std::endl;
	return 0;
}