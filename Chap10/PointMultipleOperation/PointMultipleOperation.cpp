//연산자 오버로딩을 통한 서로 다른 자료형의 두 데이터 간의 연산
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
};

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;	// == pos.operator*(3) //이렇게 해석하려면 Point객체가 곱셈 연산자의 왼편에 와야 한다
	cpy.ShowPosition();

	cpy = pos * 3 * 2;	//3을 곱했을 때 반환되는 객체를 대상으로 다시 2를 곱하는 연산
	cpy.ShowPosition();
	return 0;
}