#include <iostream>

int main(void)
{
	char name[100];
	char phoneNum[100];

	std::cout << "�̸��� �����Դϱ�? ";
	std::cin >> name;

	std::cout << "��ȭ��ȣ�� �����Դϱ�? ";
	std::cin >> phoneNum;

	std::cout << "�̸��� " << name << " �Դϴ�.\n";
	std::cout << "��ȭ��ȣ�� " << phoneNum << " �Դϴ�." << std::endl;
	return 0;
}