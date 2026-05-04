# Лабораторная работа №10

### Вариант 24

**Задание:** **Динамические массивы**

  

**Статус:** ✅ Сдано

  

---

  

## Постановка задачи:

1.    Сформировать массив строк. Удалить из него К первых строк.
  
---

  

## Блок-схема:

1. [Функция main](screenshots/lab10_scheme1.png)
2. [Функции заполнения, вывода и удаления k строк массива](screenshots/lab10_scheme2.png)

  

---

  

## Исходный код:

  

```cpp
#include <iostream>
#include <clocale>
#include <string>
using namespace std;

void FillArray(string arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}
void ShowArray(string arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void pop_start(string*& arr, int &size)
{
	size--;
	string* new_arr = new string[size];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i + 1];
	}
	delete[] arr;

	arr = new_arr;
}

int main() {
	setlocale(LC_ALL, "ru");

	system("chsp 1251");
	system("cls");

	int size, k, i = 0;
	cout << "Введите размер массива: ";
	cin >> size;
	string* arr = new string[size];
	cout << "Введите слова: ";
	FillArray(arr, size);
	cout << endl;
	cout << "Введите, сколько строк вы хотите удалить: ";
	cin >> k;
	while (k > size)
	{
		cout << "Введите число меньшее, чем кол-во строк: ";
		cin >> k;
	}
	while (i < k)
	{
		pop_start(arr, size);
		i++;
	}
	cout << "Итоговый массив: ";
	ShowArray(arr, size);
	delete[] arr;
	arr = nullptr;
	return 0;
}

```
---
## Пример работы:

**Ввод:**
```
Введите размер массива: 5
Введите слова: int array massiv pointer scope

Введите, сколько строк вы хотите удалить: 2
```
**Вывод:**
```
Итоговый массив: massiv pointer scope
```
---
## Скриншот:
[Скриншот](screenshots/lab10_run.png)