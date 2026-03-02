# Лабораторная работа №4

### Вариант 24

**Задание:** **Работа с одномерными массивами**

Статус: ✅Сдано

---
## Постановка задачи:

1.    Реализовать с использованием массива однонаправленное кольцо (просмотр возможен слева направо, от последнего элемента можно перейти к первому).

2.    Распечатать полученный массив, начиная с К-ого элемента и до К-1.

3.    Упорядочить элементы по возрастанию

4.    Удалить из кольца четные элементы.

5.    Распечатать полученный массив, начиная с К-ого элемента и до К-1.

---
## Блок-схема: 

1. [Функция main](screenshots/lab4_scheme1.png)
2. [Функции заполнения, вывода и сортировки массива](screenshots/lab4_scheme2.png)
3. [Функция удаления чётных чисел в массиве](screenshots/lab4_scheme3)

---
## Исходный код:

```cpp
#include <iostream>
#include <clocale>
using namespace std;

const int SIZE = 100;

void FillArray(int arr[], int n) {
	cout << "Введите массив: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void PrintArray(int arr[], int n, int k) {
	for (int i = 0; i < n; i++)
	{
		int sdv = (k - 1 + i) % n;
		cout << arr[sdv] << ' ';
	}
}
void Sort(int arr[], int n) {
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
	}
}
void DelEven(int arr[], int &n) {
	int temp[SIZE];
	int count_Odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			temp[count_Odd] = arr[i];
			count_Odd++;
		}
	}
	n = count_Odd;
	for (int i = 0; i < count_Odd; i++) {
		arr[i] = temp[i];
	}
}
int main() {
	setlocale(LC_ALL, "ru");

	int n, k;
	int arr[SIZE];

	cout << "Введите размер массива от 0 до 100: ";
	cin >> n; 
	while(SIZE<n){
		if (n > SIZE) {
			cout << "Введите размер поменьше!" << endl;
			cin >> n;
		}
	}
	FillArray(arr, n);
	do {
		cout << "Напишите с какого элемента вы хотите распечатать массив: ";
		cin >> k;
	} while (k<1 || k > n);
	cout << "Изначальный массив: ";
	PrintArray(arr, n, k);
	cout << endl;

	Sort(arr, n);
	DelEven(arr, n);
	
	do {
		cout << "Напишите с какого элемента вы хотите распечатать отсортированный массив без чётных чисел: ";
		cin >> k;
	} while (k<1 || k > n);
	cout << "Конечный массив: ";
	PrintArray(arr, n, k);

	return 0;
}
```
---
## Пример работы:

**Ввод:**
```
Введите размер массива от 0 до 100: 6
Введите массив: -3 6 9 1 0 7
Напишите с какого элемента вы хотите распечатать массив: 3 
Напишите с какого элемента вы хотите распечатать отсортированный массив без чётных чисел: 2
```
---
**Вывод: **
```
Изначальный массив: 9 1 0 7 -3 6 
Конечный массив: 1 7 9 -3
```
---
## Скриншот работы программы:

[Скриншот](screenshots/lab4_run.png)