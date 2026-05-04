#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class Person : public Object
{
protected:
	string name;
	int age;
public:
	virtual ~Person();
	Person();
	Person(string n, int a);
	Person(const Person&);

	void Show() override;
	void Input() override;

	string getName();
	int getAge();
	void setName(string n);
	void setAge(int a);

	Person& operator =(const Person&);
};

