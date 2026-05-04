#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	Vector a(5);
	cout << a << endl;

	cin >> a;
	cout << a << endl;

	a[2] = 100;
	cout << a << endl;

	Vector b(10);
	cout << b << endl;

	b = a;
	cout << b << endl;

	Vector c(10);
	c = a + b;
	cout << c << endl;

	cout << "\nthe lenght of a = " << a() << endl;

	cout << *(a.first()) << endl;

	Iterator i = a.first();
	i = i + 2;
	cout << *i << endl;
	i += 1;
	cout << *i << endl;
}