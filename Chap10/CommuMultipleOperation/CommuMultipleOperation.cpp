//곱셈 오버로딩 연산자에서 교환법칙이 성립하게 하는 법
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
	Point operator* (int times)	//곱셈 연산자를 오버로딩하여 객체와 정수간의 곱셈이 가능해짐
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)
{
	return ref * times;
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = 3 * pos;
	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();
	return 0;
}