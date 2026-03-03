# Лабораторная работа №7

### Вариант 24

**Задание:** **Методы нахождения приближённого корня**

  

**Статус:** ✅ Сдано

  

---

  

## Постановка задачи:

  Требуется найти приближённое значение корня нелинейного уравнения

на отрезке [0;1], используя следующие методы:

1. Метод половинного деления (метод дихотомии);

2. Метод Ньютона (метод касательных);

3. Метод итераций.

Известно, что данное уравнение имеет единственный корень на указанном отрезке, и его точное значение составляет x≈0,8814.

Цель работы - реализовать все три метода, сравнить их по количеству итераций, необходимых для достижения заданной точности ε = 1e-6, времени выполнения и оценить сходимость каждого метода к точному решению.

  

---
## Геометрическая интерпретация

1. [Метод половинного деления (метод дихотомии)](screenshots/lab7_interpretation1.png)
2. [Метод Ньютона (метод касательных)](screenshots/lab7_interpretation2.png)
3. [Метод итераций](screenshots/lab7_interpretation3.png)

---


## Блок-схема:

1. [Метод половинного деления (метод дихотомии)](screenshots/lab7_scheme1.png)
2. [Метод Ньютона (метод касательных)](screenshots/lab7_scheme2.png)
3. [Метод итераций](screenshots/lab7_scheme3.png)

  

---

  

## Исходный код:

  **Метод половинного деления (метод дихотомии)**

```cpp
#include <iostream>
#include <clocale>
#include <cmath>
#include <chrono>
using namespace std;
const double epsilon = 1e-6;

double f(double x)
{
	return exp(x) - exp(-x) - 2;
}

int main() {
	setlocale(LC_ALL, "ru");
	double a = 0, b = 1, c, i = 0;
	auto start = std::chrono::high_resolution_clock::now();
	while (b - a > epsilon)
	{
		c = (a + b) / 2.0;
		if (f(a) * f(c) < 0)
			b = c;
		else a = c;
		i++;
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	cout << "x = " << (a + b) / 2.0 << endl;
	cout << "Кол-во итераций: " << i << endl;
	cout << "Время выполнения: " << duration.count() << " нс" << endl;
	return 0;
}
```

Метод Ньютона (метод касательных)

```cpp
#include <iostream>
#include <clocale>
#include <chrono>
#include <cmath>
using namespace std;
const double epsilon = 1e-6;

double f(double x)
{
	return exp(x) - exp(-x) - 2;
}
double pf(double x)
{
	return exp(x) + exp(-x);
}
double ppf(double x)
{
	return exp(x) - exp(-x);
}

int main() {

	setlocale(LC_ALL, "ru");
	double a = 0, b = 1, x0, x, d, i = 0;

	if ((f(a) * ppf(a)) > 0)
		x0 = a;
	else if ((f(b) * ppf(b)) > 0)
		x0 = b;
	auto start = std::chrono::high_resolution_clock::now();
	do
	{
		double fx = f(x0);
		double fpx = pf(x0);
		x = x0 - (fx / fpx);
		d = abs(x - x0);
		x0 = x;
		i++;
	} while (d > epsilon);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	cout << "x = " << x << endl;
	cout << "Кол-во итераций: " << i << endl;
	cout << "Время выполнения: " << duration.count() << " нс" << endl;
	return 0;
}
```

Метод итераций

```cpp
#include <iostream>
#include <clocale>
#include <cmath>
#include <chrono>
using namespace std;
const double eps = 10e-6, lambda = 2/(2 + 3.08616);

double phi(double x)
{
	return x - lambda*(exp(x) - exp(-x) - 2);
}
int main() {

	setlocale(LC_ALL, "ru");
	double a = 0, b = 1;
	int i = 1;
	double x0 = (a + b) / 2;
	double x1 = phi(x0);
	auto start = std::chrono::high_resolution_clock::now();
	while (abs(x0 - x1) > eps)
	{
		x0 = x1;
		x1 = phi(x0);
		i++;
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	cout << x1 << endl;
	cout << "Кол-во итераций: " << i << endl;
	cout << "Время выполнения: " << duration.count() << " нс" << endl;
	return 0;
}
```
---
## Пример работы:

**Метод половинного деления (метод дихотомии)**

**Вывод:**
```
x = 0.881374
Кол-во итераций: 20
Время выполнения: 37164000 нс
```

**Метод Ньютона (метод касательных)**

**Вывод:**
```
x = 0.881374
Кол-во итераций: 4
Время выполнения: 2300 нс
```

**Метод итераций**

**Вывод:**
```
0.881373
Кол-во итераций: 5
Время выполнения: 2800 нс
```
---
## Скриншот:
1. [Метод половинного деления (метод дихотомии)](screenshots/lab7_run1.png)
2. [Метод Ньютона (метод касательных)](screenshots/lab7_run2.png)
3. [Метод итераций](screenshots/lab7_run3.png)
---
### Сравнение методов

| Метод                 | Количество итераций | Время выполнения(нс) |
| :-------------------- | :-----------------: | :------------------: |
| Половинного деления   |         20          |         4400         |
| Ньютона (касательных) |          4          |         200          |
| Итераций              |          5          |         100          |

Все три метода успешно находят приближённое значение корня уравнения ex−e−x−2 на отрезке [0;1]. Точное значение корня равно 0,8814.

1.    Метод итераций - самый быстрый. Он завершается за 5 итераций и требует всего 100 наносекунд. Полученный результат близок к точному значению.

2.    Метод Ньютона - второй по скорости. Завершается за 4 итерации, но занимает 200 нс - вдвое больше, чем метод итераций.

3.    Метод половинного деления - самый медленный. Выполняется за 20 итераций и занимает 4400 нс - это в 44 раза дольше, чем метод итераций.

Таким образом, по времени выполнения наиболее эффективен метод итераций, а по количеству итераций - метод Ньютона. Метод половинного деления, несмотря на большую длительность, обеспечивает надёжное и устойчивое решение, что делает его предпочтительным в задачах, где важна гарантия сходимости, а не скорость.
