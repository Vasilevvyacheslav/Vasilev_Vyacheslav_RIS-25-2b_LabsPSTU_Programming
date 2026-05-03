#pragma once
#include "Person.h"
class Employee: public Person
{
protected:
	float salary;
	string position;
public:
	~Employee();
	Employee();
	Employee(string n, int a, float s, string p);
	Employee(const Employee&);

	void Show() override;
	void Input() override;

	float getSalary();
	void setSalary(float s);

	string getPosition();
	void setPosition(string p);
};

