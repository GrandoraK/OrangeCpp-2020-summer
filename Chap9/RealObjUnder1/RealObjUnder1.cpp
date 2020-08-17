//객체의 멤버함수와 멤버변수가 어떠한 형태인지 보여주는 예시
#include <iostream>
using namespace std;

class Data
{
private:
	int data;
public:
	Data(int num) : data(num)
	{ }
	void ShowData() { cout << "Data: " << data << endl; }
	void Add(int num) { data += num; }
};

int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	return 0;
}