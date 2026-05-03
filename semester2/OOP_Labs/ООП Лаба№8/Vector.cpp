#include "Vector.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>
using namespace std;

Vector::Vector() : beg(nullptr), size(0), cur(0) {}

Vector::Vector(int size) : beg(new Object* [size]), cur(0), size(size) {}

Vector::~Vector()
{
	for (int i = 0; i < cur; i++)
	{
		delete beg[i];
	}
	delete[] beg;
	beg = 0;
}

void Vector::Add()
{
	if (cur >= size)
	{
		cout << "Vector is full! Cannot add more objects.\n";
		cout << "Current size: " << cur << " / " << size << endl;
		return;
	}

	cout << "1.Person" << endl;
	cout << "2.Employee" << endl;
	int y;
	cin >> y;

	Object* obj = nullptr;

	if (y == 1)
	{
		Person* p = new Person;
		p->Input();
		obj = p;
	}
	else if (y == 2)
	{
		Employee* em = new Employee;
		em->Input();
		obj = em;
	}
	else
	{
		cout << "Invalid choice!\n";
		return;
	}
	if (obj != nullptr)
	{
		beg[cur] = obj;
		cur++;
		cout << "Object added!\n";
		cout << "Current size: " << cur << " / " << size << endl;
	}
}
void Vector::Show()
{
	if (beg == nullptr)
	{
		cout << "Vector not created! Use 'mN' command.\n";
		return;
	}
	if (cur == 0)
	{
		cout << "Empty" << endl;
		return;
	}

	Object** ob = beg;
	for (int i = 0; i < cur; i++)
	{
		if (*ob != nullptr)
		{
			(*ob)->Show();
			cout << endl;
		}
		ob++;
	}
}

void Vector::ShowElement(int k)
{
	if (beg == nullptr)
	{
		cout << "Vector not created! Use 'm' command.\n";
		return;
	}

	if (k < 0 || k >= cur)
	{
		cout << "Invalid index! Valid range: 0 - " << (cur - 1) << endl;
		return;
	}

	if (beg[k] != nullptr)
	{
		cout << "Element [" << k << "]:\n";
		beg[k]->Show();
	}
	else
	{
		cout << "Element [" << k << "] is empty!\n";
	}
}
int Vector::operator()()
{
	return cur;
}
void Vector::Del()
{
	if (cur == 0)
	{
		cout << "Vector is empty!\n";
		return;
	}

	cur--;
	delete beg[cur];
	beg[cur] = nullptr;

	cout << "Object deleted. Current size : " << cur << " / " << size << endl;
}
void Vector::HandleEvent(const TEvent& e)
{
	
}