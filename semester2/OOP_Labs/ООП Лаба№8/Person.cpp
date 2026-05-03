#include "Person.h"

Person::Person() : name(""), age(0) {}
Person::Person(string n, int a) : name(n), age(a) {}
Person::Person(const Person& other) : name(other.name), age(other.age) {}
Person::~Person() {}


string Person::getName() { return name; }
int Person::getAge() {return age;}
void Person::setName(string n) {name = n;}
void Person::setAge(int a){age = a;}

Person& Person::operator =(const Person& other)
{
	if (&other != this)
	{
		name = other.name;
		age = other.age;
	}

	return *this;
}

void Person::Show()
{
	cout << "\nName: " << name << endl;
	cout << "Age: " << age << endl;
}
void Person::Input()
{
	cout << "\nenter name: "; cin >> name;
	cout << "enter age: "; cin >> age;
	cout << endl;
}

