# Лабораторная работа №6

### Вариант 19

**Задание:** **Строки**

  

**Статус:** ✅ Сдано

  

---

  

## Постановка задачи: 
Все слова строки, которые начинаются с цифры отсортировать по убыванию.

  

  

---

  

## Блок-схема:

1. [Функция main 1](screenshots/lab6_scheme1.png)
2. [Функция main 2](screenshots/lab6_scheme2.png)  

---

  

## Исходный код:

  

```cpp
#include <iostream>
#include <clocale>
#include <string>
#include <windows.h> 
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	cout << "Введите строку: ";
	getline(cin, str);
	str += " ";
	char Nums[]{ '0', '1', '2', '3','4', '5', '6' ,'7', '8', '9' };

	int i = 0, count = 0;
	bool f = false;// Найдена цифра и она первая в слове

	while (str[i] != '\0')
	{
		for (int j = 0; j < size(Nums) && !f; j++)
		{
			if (str[i] == Nums[j])
			{
				f = true;
				for (int l = i; str[l] != ' '; l++)
				{
					count++;
				}
				for (int p = 0; p < count - 1; p++) {
					for (int k = i; str[k] != ' '; k++)
					{
						if (str[k + 1] > str[k])
						{
							int temp = str[k];
							str[k] = str[k + 1];
							str[k + 1] = temp;
						}
					}
				}
			}
		}
		count = 0;
		f = false;
		for (int k = i; str[k] != ' ' && str[k] != '\0'; k++)
		{
			i++;
		}
		if (str[i] == ' ')
		{
			i++;
		}
	}
	cout << str;
	return 0;
}

```
---
## Пример работы:

**Ввод:**
```
Введите строку: 9ptr s2tr 529 23int
```
**Вывод:**
```
trp9 s2tr 952 tni32
```
---
## Скриншот:
[Скриншот](screenshots/lab6_run.png)