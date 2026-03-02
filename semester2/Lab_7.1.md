# Лабораторная работа №7.1

### Вариант 24

**Задание:** **Перегрузка функций в Си++**

  

**Статус:** ✅ Сдано

  

---

  

## Постановка задачи:

Написать перегруженные функции и основную программу, которая их вызывает:

а) для массива целых чисел: удаляет все четные элементы из массива;

б) для строки: удаляет все четные слова.

  

---

  

## Блок-схема:

1. [Функция main](lab7.1_scheme1.png)
2. [Функции заполнения и вывода ](lab7.1_scheme2.png)
3. [Функция удаления чётных чисел](lab7.1_scheme3.png)
4. [Функция удаления чётных слов](lab7.1_scheme4.png)

  

---

  

## Исходный код:

  

```cpp
#include <iostream>
#include <clocale>
#include <string>
#include <windows.h> 
using namespace std;

void FillArray(int arr[], int n)
{
	cout << "Введите массив: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}
}
void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}
void DelEven(int arr[], int &n)
{
	int count_odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			arr[count_odd] = arr[i];
			count_odd++;
		}
	}
	n = count_odd;
}
void DelEven(string& str)
{
	int i = 0, count = 0;
	while (str[i] != '\0') {
		for (int j = i; str[j] != ' ' && str[j] != '\0'; j++)
		{
			count++;
		}
		if (count % 2 == 0)
		{
			str.erase(i, count+1);
			i--;
		}
		count = 0;
		for (int k = i; str[k] != ' ' && str[k] != '\0'; k++)
		{
			i++;
		}
		if (str[i] == ' ')
		{
			i++;
		}
	}
}
int main() 
{
	setlocale(LC_ALL, "ru");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int SIZE = 100;
	int arr[SIZE];
	int n;
	cout << "Введите размер массива: ";
	cin >> n;

	FillArray(arr, n);
	DelEven(arr, n);
	PrintArray(arr, n);

	cout << endl;

	cin.ignore();
	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	DelEven(str);
	cout << str << endl;
}
```
---
## Пример работы:

**Ввод:**
```
Введите размер массива: 6
Введите массив: 7 2 12 0 9 5
Введите строку: Казнить нельзя помиловать
```
**Вывод:**
```
7 9 5
Казнить
```
---
## Скриншот:

[Скриншот](lab7.1_run.png)