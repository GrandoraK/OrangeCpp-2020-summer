//급여관리 시스템
//임시직, 영업직 추가
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money) : Employee(name), salary(money)
	{ }
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWork : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWork(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];		//저장대상이 PermanentWorker객체에서 Employee객체로 변경되었다.
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		/*
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		*/
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
	EmployeeHandler handler;

	//정규직
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	//임시직
	TemporaryWork* alba = new TemporaryWork("JUNG", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	//영업직
	SalesWorker* seller = new SalesWorker("HONG", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
	return 0;
}