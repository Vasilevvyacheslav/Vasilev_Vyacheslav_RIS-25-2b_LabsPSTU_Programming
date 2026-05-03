#include <iostream>
#include "Pair.h"
#include "Rectangle.h"
using namespace std;


void f1(Pair& p)
{
	cout << "\nДо изменения " << endl << p << endl;
	p.SetFirst(100);
	p.SetSecond(200);
	cout << "После изменения  " << endl << p << endl;
	cout << "Произведение: " << p.product() << endl;
}
Pair f2()
{
	Rectangle r(52, 67);
	cout << "Создан Rectangle: " << endl << r << endl;
	return r;
}

int main()
{
	setlocale(LC_ALL, "ru");

	Pair p1;
	cin >> p1;
	cout << "Pair p1\n" << p1;
	cout << "Произведение: " << p1.product() << endl;
	cout << "--------------------------------------" << endl;
	cout << "Конструктор с параметрами" << endl;
	Pair p2(12, 17);
	cout << "Pair p2(12, 17)\n" << p2;
	cout << "Произведение: " << p2.product() << endl;
	cout << "--------------------------------------" << endl;
	cout << "Конструктор копирования" << endl;
	Pair p3 = p1;
	cout << "Pair p3\n" << p1;
	cout << "Произведение: " << p3.product() << endl;
	cout << "--------------------------------------" << endl;


	Rectangle a;
	cout << "Введите стороны прямоугольника: " << endl;
	cin >> a;
	cout << a;
	cout << "--------------------------------------" << endl;
	cout << "Принцип подстановки" << endl;
	cout << "\n1. Передаем Rectangle в функцию f1(Pair&):" << endl;
	f1(a);
	cout << "\n2. Функция f2() создает Rectangle, но возвращает Pair:" << endl;
	p1 = f2();
	cout << p1;

	return 0;
}