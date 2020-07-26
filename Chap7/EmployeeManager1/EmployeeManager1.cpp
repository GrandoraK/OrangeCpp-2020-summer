//�޿����� �ý���
//������(Permanent)���� �����ϴ� ������ �ý���
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class PermanentWorker	//������ ���� Ŭ����	//Data�� ������ ����
{
private:
	char name[100];
	int salary;	//�Ŵ� �����ؾ� �ϴ� �޿���
public:
	PermanentWorker(char* name, int money)				// !! ���⼭ ������ ����
		: salary(money)		//�ʱ�ȭ����Ʈ(:) �̿�
	{
		strcpy(this->name, name);
	}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler	//�տ��� ������ Ŭ������ ��ü�� ���� �� �����ϱ� ���� Ŭ����	//����� ������ ����
						//���� ������ �������� �迭�� ����� ���ϰ�, ���� ����� ���� �Լ��� ����� ���Ѵ�.
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	EmployeeHandler handler;	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����

	handler.AddEmployee(new PermanentWorker("KIM", 1000));		//���� ���			// !! ���⼭ ������ ����
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();	//�̹� �޿� �����ؾ� �� �޿��� ����

	handler.ShowTotalSalary();		//�̹� �޿� �����ؾ� �� �޿��� ����
	return 0;
}