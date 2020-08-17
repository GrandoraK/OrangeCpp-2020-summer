//1번 코드를 C언어 스타일의 구조체와 전역함수를 이용하여 흉내
#include <iostream>
using namespace std;

//Data 클래스 흉내
typedef struct Data
{
	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);
} Data;


void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	return 0;
}