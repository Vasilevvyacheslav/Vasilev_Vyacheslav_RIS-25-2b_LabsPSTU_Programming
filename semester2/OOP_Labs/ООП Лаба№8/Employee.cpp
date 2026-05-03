#include "Employee.h"

Employee::Employee() : Person() { salary = 0; }
Employee::Employee(string n, int a, float s, string p) : Person(n, a) { salary = s; }
Employee::Employee(const Employee& other) : Person(other) { salary = other.salary; }
Employee::~Employee() {}


float Employee::getSalary() { return salary; }
void Employee::setSalary(float s) { salary = s; }

string Employee::getPosition() { return position; }
void Employee::setPosition(string p) { position = p; }

void Employee::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\nSalary: " << salary;
	cout << "\nPosition: " << position << endl;
}
void Employee::Input()
{
	cout << "\nenter name: "; cin >> name;
	cout << "enter age: "; cin >> age;
	cout << "enter salary: "; cin >> salary;
	cout << "enter position: "; cin >> position;
	cout << endl;
}