#include <iostream>
#include "Pair.h"
#include "Rectangle.h"
#include "Object.h"
#include "Vector.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	Vector v(5);
	Pair p;
	cin >> p;
	Rectangle r;
	cin >> r;
	Object* ob = &p;
	v.Add(ob);
	ob = &r;
	v.Add(ob);
	cout << v;
	return 0;
}