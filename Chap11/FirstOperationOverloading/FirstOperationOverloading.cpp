//����Ʈ ���� ������
//�� ���� Ŭ������ �����ϵ�, �� Ŭ������ ���� �����ڸ� �����ϰ�, �ٸ� Ŭ�������� ���� �����ڸ� �������� ����
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

	Second& operator=(const Second& ref)		//��� �� ����� ���簡 ����ǵ���, ���� �����ڸ� �����ε���.
	{
		cout << "Second& operator = ()" << endl;	//���� �������� ȣ���� Ȯ���ϱ� ����
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;		//��ȯ���� �������ӿ� �ָ�
	}
};

int main(void)
{
	First fsrc(111, 222);		//src�� source�̷���... ��
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;	//fcpy.oprator=(fsrc)�� �ؼ��ǰ� �̷� ���� ����Ʈ�� ���Ե� ���� �����ڰ� ȣ��ȴ�
	scpy = ssrc;	//scpy.operator=(ssrc)�� �ؼ��ǰ� �̷� ���� 25�࿡ ���ǵ� ���� �����ڰ� ȣ��ȴ�
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;		//���Կ����ڴ� �����ʿ��� �������� ����ȴ�. �� ������ ����ȴٴ� ��Ƿ� ����Ʈ ���� �������� ��ȯ���� ������ �� �ִ�.
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;

}