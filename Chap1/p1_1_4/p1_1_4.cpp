#include <iostream>

int main(void)
{
	int sales;
	while (1)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> sales;
		if (sales == -1)
		{
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			return 0;
		}
		std::cout << "�̹� �� �޿�: " << 50 + sales * 0.12 << "����" << std::endl;
	}
}