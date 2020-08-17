//������ �����ε��� ���� ���� �ٸ� �ڷ����� �� ������ ���� ����
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator* (int times)	//���� �����ڸ� �����ε��Ͽ� ��ü�� �������� ������ ��������
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
};

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;	// == pos.operator*(3) //�̷��� �ؼ��Ϸ��� Point��ü�� ���� �������� ���� �;� �Ѵ�
	cpy.ShowPosition();

	cpy = pos * 3 * 2;	//3�� ������ �� ��ȯ�Ǵ� ��ü�� ������� �ٽ� 2�� ���ϴ� ����
	cpy.ShowPosition();
	return 0;
}