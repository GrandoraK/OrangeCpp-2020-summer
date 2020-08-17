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
		cout << '[' << xpos << ", " << ypos << ']' << endl;	//����ǥ ����!!!
	}
	Point operator+(const Point& ref)	//operator+ ��� �̸��� �Լ�
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);	//pos1 ��ü�� ����Լ� operator+�� ȣ���ϸ� ���ڷ� pos2 ��ü�� �����ϰ� �ִ�.
										//���� �� �� ��ü�� ��� �� ��������� ���ο� Point��ü�� ��������� �̰��� ��ȯ�Ǿ� pos3�� �ʱ�ȭ (���� �����ڰ� ȣ���)

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}