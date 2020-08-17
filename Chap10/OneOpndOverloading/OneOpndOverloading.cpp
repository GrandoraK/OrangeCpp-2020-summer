//���� �������� �����ε�
//���� �����ڸ� ����Լ� �������, ���� �����ڸ� �����Լ� ������� ������ �����ε�
//opnd == operand : �ǿ�����
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
	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;	//��ü �ڽ��� ��ȯ�ε� ��ȯ���� �������̱� ������ ��ü �ڽ��� ������ �� �ִ� ���� ���� ��ȯ�ȴ�. (�� �� ��ü �ڽ��� ���纻 ��ȯ)
	}
	friend Point& operator--(Point& ref);
};

Point& operator--(Point &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main(void)
{
	Point pos(1, 2);
	++pos; // == pos.operator++()
	pos.ShowPosition();
	--pos;	// == operator--(pos)
	pos.ShowPosition();

	++(++pos);	// == ++(pos.operator++()) == ++(pos�� ������) == (pos�� ������).operator++() //��� 2�� �����Ѵ� //�� ������ �������ϱ� ���� �������� ��ȯ�Ѵ�
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();
	return 0;
}