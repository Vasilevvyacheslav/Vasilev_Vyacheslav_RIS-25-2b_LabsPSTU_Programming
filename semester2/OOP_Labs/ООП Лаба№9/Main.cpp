#include "error_2.h"
#include "error_3.h"
#include "Vector_2.h"
#include "Vector_3.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "========== Вторая реализация ==========" << endl;
	try
	{
		Version2::Vector x(3);
		Version2::Vector y;
		cout << "Введите элементы вектора x(3): ";
		cin >> x;
		cout << x << endl;
		cout << "Размер вектора: " << x() << endl;


		cout << "Введите индекс элемента: ";
		int i;
		cin >> i;
		cout << x[i] << endl;


		int n;
		cout << "Введите сколько элементов вы хотите добавить: ";
		cin >> n;
		y = x + n;
		cout << y << endl;
		cout << "Размер вектора: " << y() << endl;



		cout << "Введите сколько элементов вы хотите удалить: ";
		cin >> n;
		y = y - n;
		cout << y << endl;
		cout << "Размер вектора: " << y() << endl;

	}
	catch (Version2::Error e)
	{
		e.what();
	}

	cout << "\n========== Третья реализация ==========" << endl;
	try
	{
		Version3::Vector x(3);
		Version3::Vector y;
		cout << "Введите элементы вектора x(3): ";
		cin >> x;
		cout << x << endl;
		cout << "Размер вектора: " << x() << endl;


		cout << "Введите индекс элемента: ";
		int i;
		cin >> i;
		cout << x[i] << endl;


		int n;
		cout << "Введите сколько элементов вы хотите добавить: ";
		cin >> n;
		y = x + n;
		cout << y << endl;
		cout << "Размер вектора: " << y() << endl;



		cout << "Введите сколько элементов вы хотите удалить: ";
		cin >> n;
		y = y - n;
		cout << y << endl;
		cout << "Размер вектора: " << y() << endl;

	}
	catch (Version3::Error& e)
	{
		e.what();
	}

	return 0;
}