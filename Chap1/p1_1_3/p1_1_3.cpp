#include <iostream>

int main(void)
{
	int num;
	std::cout << "¸î ´Ü? ";
	std::cin >> num;

	for (int i = 1; i <= 9; i++)
		std::cout << num << " * " << i << " = " << num * i << std::endl;
	return 0;
}