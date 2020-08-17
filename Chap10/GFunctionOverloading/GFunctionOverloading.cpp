//+연산자의 전역함수 기반 오버로딩 (<->멤버함수 기반 : 앞의 예제)
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
	friend Point operator+(const Point& pos1, const Point& pos2); //해당 함수가 private에 접근할 수 있도록
	friend Point operator-(const Point& pos1, const Point& pos2);

	Point operator+=(const Point& ref)
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

Point operator+(const Point& pos1, const Point& pos2)	//전역함수 형태로 오버로딩 
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;	// == operator+(pos1, pos2)
	Point pos4 = pos2 - pos1;	// == operator-(pos2, pos1)

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}