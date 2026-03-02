# Лабораторная работа №5

### Вариант 24

**Задание:** **Функции и массивы**

**Статус:** ✅ Сдано

  
---

  

## Постановка задачи:

Определить сколько элементов двумерного массива больше любого элемента

на главной диагонали.

  

---

  

## Блок-схема:

1. [Функция main](screenshots/lab5_scheme1.png)
2. [Функции заполнения массива и нахождения максимума на диагонали ](screenshots/lab5_scheme2.png)
3. [Функция счётчик чисел больших чем максимум на диагонали](screenshots/lab5_scheme3.png)



---

  

## Исходный код:

  

```cpp
#include <iostream>
#include <clocale>
using namespace std;

const int ROW = 50, COL = 50;

void FillArray(int arr[][COL], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}
int MaxInDiagonal(int arr[][COL], int n) {
	int max = arr[0][0];
		for (int i = 0; i < n; i++)
		{
			if (arr[i][i] >= max)
			{
				max = arr[i][i];
			}
		}
		return max;
}
int Count(int arr[][COL], int n, int max) {
	int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] > max) {
					count++;
				}
			}
		}
		return count;
}
int main() {
	setlocale(LC_ALL, "ru");
	int n;

	int arr[ROW][COL]{};
	cout << "Введите количество строк квадратной матрицы: ";
	cin >> n;

	cout << "Введите массив: " << endl;
	FillArray(arr, n);
	
	int maxDiagonal = MaxInDiagonal(arr, n);

	cout << "Количество элементов, которые больше любого элемента на главной диагонали: "
		<< Count(arr, n, maxDiagonal);
	return 0;
}
```
---
## Пример работы:

**Ввод:**
```
Введите количество строк квадратной матрицы: 3
Введите массив:
6 0 8
5 3 1
2 7 4
```
**Вывод:**
```
Количество элементов, которые больше любого элемента на главной диагонали: 2
```
---
## Скриншот:
[Скриншот](screenshots/lab5_run.png)