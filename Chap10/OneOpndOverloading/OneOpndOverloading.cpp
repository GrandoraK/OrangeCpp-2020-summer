//단항 연사자의 오버로딩
//증가 연산자를 멤버함수 기반으로, 감소 연산자를 전역함수 기반으로 연산자 오버로딩
//opnd == operand : 피연산자
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
		return *this;	//객체 자신을 반환인데 반환형이 참조형이기 때문에 객체 자신을 참조할 수 있는 참조 값이 반환된다. (이 때 객체 자신의 복사본 반환)
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

	++(++pos);	// == ++(pos.operator++()) == ++(pos의 참조값) == (pos의 참조값).operator++() //고로 2씩 증가한다 //이 연산을 가능케하기 위해 참조값을 반환한다
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();
	return 0;
}