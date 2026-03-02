# Лабораторная работа №7.2

### Вариант 24

**Задание:** **Функции с переменным числом параметров**
  

**Статус:** ✅ Сдано

  

---

  

## Постановка задачи:
1. На вход функции подаются координаты вершин многоугольника на плоскости в порядке обхода и количество вершин. Требуется найти длину самой длинной стороны многоугольника.

2. Написать функцию square, которая вычисляет площадь треугольника, заданного координатами вершин.

3. Написать функцию squaren c переменным числом параметров, которая определяет площадь выпуклого многоугольника, заданного координатами своих вершин.
  

  

---

  

## Блок-схема:

1. [Функция main](screenshots/lab7.2_scheme1.png)
2. [Функция нахождения наибольшей длины многоугольника ](screenshots/lab7.2_scheme2.png)
3. [Функция нахождения площади треугольника](screenshots/lab7.2_scheme3.png)
4. [Функция нахождения площади выпуклого многоугольника](screenshots/lab7.2_scheme4.png)

  

---

  

## Исходный код:

  

```cpp
#include <iostream>
#include <clocale>
#include <cstdarg>
#include <cmath>
using namespace std;

double max_length(int n, ...)
{
	va_list args;
	double arr[5][2];
	va_start(args, n);

	for (int i = 0; i < n; i++)
	{
		arr[i][0] = va_arg(args, double);
		arr[i][1] = va_arg(args, double);
	}
	va_end(args);

	double max_side = (sqrt(pow(arr[0][0] - arr[4][0], 2) + pow(arr[0][1] - arr[4][1], 2)));
	for (int i = 1; i < n - 1; i++)
	{
		double temp = (sqrt(pow(arr[i][0] - arr[i-1][0], 2) + pow(arr[i][1] - arr[i-1][1], 2)));
		if (temp > max_side)
		{
			max_side = temp;
		}
	}
	return max_side;
}
double square(int n, ...)
{	
	va_list args;
	double arr[3][2]{};
	va_start(args, n);

	for (int i = 0; i < n; i++)
	{
		arr[i][0] = va_arg(args, double);
		arr[i][1] = va_arg(args, double);
	}
	va_end(args);

	return 0.5 * abs((arr[0][0] - arr[2][0]) * (arr[1][1] - arr[2][1]) - (arr[1][0] - arr[2][0]) * (arr[0][1] - arr[2][1]));
}
double squaren(int n, ...)
{
	va_list args;
	double arr[5][2]{};
	va_start(args, n);

	for (int i = 0; i < n; i++)
	{
		arr[i][0] = va_arg(args, double);
		arr[i][1] = va_arg(args, double);
	}
	va_end(args);

	double sum = 0;
	for (int i = 1; i < n - 1; i++)
	{
		sum += square(3, arr[0][0], arr[0][1], arr[i][0], arr[i][1], arr[i+1][0], arr[i+1][1]);
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;
	cout << "Введите координаты треугольника: " << endl;
	cout << "\nТочка А: ";
	cin >> x1 >> y1;
	cout << "Точка B: ";
	cin >> x2 >> y2;
	cout << "Точка C: ";
	cin >> x3 >> y3;
	int sqr = square(3, x1, y1, x2, y2, x3, y3);
	if (sqr == 0)
	{
		cout << "\nТакого треугольника не существует!";
	}
	else
	{
		cout << "\nПлощадь треугольника ABC с данными координатами равна: " << sqr;
	}
	cout << endl;
	cout << "\n=============================================" << endl;
	cout << "\nВведите координаты пятиугольника: " << endl;
	cout << "\nТочка А: ";
	cin >> x1 >> y1;
	cout << "Точка B: ";
	cin >> x2 >> y2;
	cout << "Точка C: ";
	cin >> x3 >> y3;
	cout << "Точка D: ";
	cin >> x4 >> y4;
	cout << "Точка E: ";
	cin >> x5 >> y5;
	cout << "\nМаксимальная длина стороны пятиугольника ABCDE равна: " << max_length(5, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5) << endl;
	int sqrn = squaren(5, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
	cout << "\nПлощадь пятиугольника ABCDE с данными координатами равна: " << sqrn << endl;
	return 0;
}
```
---
## Пример работы:

**Ввод:**
```
Введите координаты треугольника:

Точка А: 1 2
Точка B: 5 1
Точка C: 6 2

Введите координаты пятиугольника:

Точка А: 4 0
Точка B: 5 8
Точка C: 11 9
Точка D: 9 6
Точка E: 7 0
```
**Вывод:**
```
Площадь треугольника ABC с данными координатами равна: 2

Максимальная длина стороны пятиугольника ABCDE равна: 8.06226

Площадь пятиугольника ABCDE с данными координатами равна: 34
```
---
## Скриншот:
[Скриншот](screenshots/lab7.2_run.png)