#include <iostream>
#include "Vector.h"
#include "Time.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Создание вектора A (5 элементов)\n";
	Vector<int> A(5);
	cout << "Введите вектор: "; cin >> A;
	cout << "A = " << A << endl;

	cout << "\nСоздание вектора B (10 элементов, заполнено 0)\n";
	Vector<int> B(10 , 0);
	cout << "B = " << B << endl;

	cout << "\nКопирование: B = A\n";
	B = A;
	cout << "B = " << B << endl;

	cout << "\nДоступ по индексу: A[2]\n";
	cout << "A[2] = " << A[2] << endl;

	cout << "\nsize = " << A() << endl;

	cout << "\nСложение: B = A + B\n";
	B = A + B;
	cout << "B = " << B << endl;

	cout << "===============================" << endl;

	Time t;
	cout << "Введите время"; cin >> t;
	cout << "Время: " << t << endl;
	
	Vector<Time> a(3, t);
	cout << "\nВвод 3 элементов времени\n";
	cin >> a;

	cout << "\nВектор a\n";
	cout << "a = " << a << endl;

	cout << "\nСоздание вектора b (10 элементов, заполнено " << t << ")\n";
	Vector<Time> b(10, t);
	cout << "b = " << b << endl;

	cout << "\nКопирование: b = a\n";
	b = a;
	cout << "b = " << b << endl;

	cout << "\nЭлемент по индексу \n";
	cout << "a[2] = " << a[2] << endl;

	cout << "\nsize = " << a() << endl;

	cout << "\nСложение: b = a + b\n";
	b = a + b;
	cout << "b = " << b << endl;
}