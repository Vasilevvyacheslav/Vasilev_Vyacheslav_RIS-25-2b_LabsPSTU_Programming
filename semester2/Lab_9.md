# Лабораторная работа №9

### Вариант 24

**Задание:** Строковый ввод-вывод

  

**Статус:** ✅ Сдано

  

---

  

## Постановка задачи:
1. Скопировать из файла F1 в файл F2 все строки, в которых содержится два одинаковых слова.

2. Определить номер слова, в котором больше всего букв «А».
  

  

---

  

## Блок-схема:

1. [Функция main 1](lab9_scheme1.png)
2. [Функция main 2](lab9_scheme2.png)

---

  

## Исходный код:

  

```cpp
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	ifstream input("f1.txt");
	ofstream output("f2.txt");

	if (!input.is_open())
	{
		cout << "Файл f1.txt не открылся!" << endl;
		return 1;
	}
	if (!output.is_open())
	{
		cout << "Файл f2.txt не открылся!" << endl;
		return 1;
	}

	string row;

	
	int cnt_word = 0, cnt_a = 0, num = 0, temp = 0;
	bool f = false;
	while (getline(input, row))
	{	
		string words[50];
		string word = "";
		int count = 0;
		row += " ";
		for (int i = 0; i < row.size(); i++)
		{
			if (i == 0 && !f)
			{
				row.erase(0, 3);
				f = true;
			}
			if (row[i] == 'a' || row[i] == 'A')
			{
				temp++;
			}
			if (row[i] == ' ')
			{
				words[count] = word;
				count++;
				word = "";
				cnt_word++;
				if (temp > cnt_a)
				{
					cnt_a = temp;
					num = cnt_word;
				}
				temp = 0;
			}
			else
			{
				word += row[i];
			}
		}
		if (word != "") {
			words[count] = word;
			count++;
		}
		bool duplicate = false;
		for (int i = 0; i < count; i++)
		{
			for (int j = i+1; j < count; j++)
			{
				if (words[i] == words[j])
				{
					duplicate = true;
				}
			}
		}
		if (duplicate)
		{
			output << row << endl;
		}
	}
	cout << "Номер слова в котором больше всего букв 'A': " << num << endl
		<< "Их кол-во: " << cnt_a << endl;

	input.close();
	output.close();
	return 0;
}

		

```
---
## Пример работы:

**Файл 1(Ввод):**
```
too I am fantastic too
hello hello
how are you
fantastica!
```
**Файл 2(Вывод):**
```
too I am fantastic too 
hello hello 
```
**Вывод(в консоль)**
```
Номер слова в котором больше всего букв 'A': 11
Их кол-во: 3
```

---
## Скриншот:
[Скриншот 1](lab9_run1.png)
[Скриншот 2](lab9_run2.png)
[Скриншот 3](lab9_run3.png)