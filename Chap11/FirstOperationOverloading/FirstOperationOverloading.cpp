//디폴트 대입 연산자
//두 개의 클래스를 정의하되, 한 클래스는 대입 연산자를 정의하고, 다른 클래스에는 대입 연산자를 정의하지 않음
#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{ }
	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{ }
	void ShowData() { cout << num3 << ", " << num4 << endl; }

	Second& operator=(const Second& ref)		//멤버 대 멤버의 복사가 진행되도록, 대입 연산자를 오버로딩함.
	{
		cout << "Second& operator = ()" << endl;	//대입 연산자의 호출을 확인하기 위함
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;		//반환형이 참조형임에 주목
	}
};

int main(void)
{
	First fsrc(111, 222);		//src는 source이려나... 흠
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;	//fcpy.oprator=(fsrc)로 해석되고 이로 인해 디폴트로 삽입된 대입 연산자가 호출된다
	scpy = ssrc;	//scpy.operator=(ssrc)로 해석되고 이로 인해 25행에 정의된 대입 연산자가 호출된다
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;		//대입연산자는 오른쪽에서 왼쪽으로 진행된다. 이 문장이 실행된다는 사실로 디폴트 대입 연산자의 반환형을 유추할 수 있다.
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;

}