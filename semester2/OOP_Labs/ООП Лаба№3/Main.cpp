#include "Time.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Time a;
	Time b;
	Time c;
	cout << "Введите первое время "; cin >> a;
	cout << "\nВведите второе время "; cin >> b;
	cout << "\nПервое время: " << a << endl;
	cout << "Второе время: " << b << endl;

	bool result = a != b;
	if (result)
		cout << "Время не совпадает" << endl;
	else
		cout << "Время совпадает" << endl;

	c = a - b;
	cout << "\nРазница во времени составляет: " << c << endl;

	return 0;
}