//1�� �ڵ带 C��� ��Ÿ���� ����ü�� �����Լ��� �̿��Ͽ� �䳻
#include <iostream>
using namespace std;

//Data Ŭ���� �䳻
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