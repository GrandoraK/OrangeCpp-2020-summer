//급여관리 시스템
//정규직(Permanent)만을 관리하는 형태의 시스템
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class PermanentWorker	//정규직 직원 클래스	//Data적 성격이 강함
{
private:
	char name[100];
	int salary;	//매달 지불해야 하는 급여액
public:
	PermanentWorker(char* name, int money)				// !! 여기서 에러가 난다
		: salary(money)		//초기화리스트(:) 이용
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

class EmployeeHandler	//앞에서 정의한 클래스의 객체를 저장 및 관리하기 위한 클래스	//기능적 성격이 강함
						//객제 저장을 목적으로 배열을 멤버로 지니고, 정보 출력을 위한 함수를 멤버로 지닌다.
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
	EmployeeHandler handler;	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성

	handler.AddEmployee(new PermanentWorker("KIM", 1000));		//직원 등록			// !! 여기서 에러가 난다
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();	//이번 달에 지불해야 할 급여의 정보

	handler.ShowTotalSalary();		//이번 달에 지불해야 할 급여의 총합
	return 0;
}