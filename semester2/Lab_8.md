# Лабораторная работа №8

### Вариант 24

**Задание:** **Блоковый ввод-вывод**

  

**Статус:** ✅ Сдано

  

---

  

## Постановка задачи:
Структура "Студент":

-        фамилия, имя, отчество;

-        номер телефона;

-        группа;

-        оценки по 3 основным предметам.

Удалить все элементы из группы с указанным номером, у которых среднее арифметическое оценок меньше заданного, добавить элемент после элемента с заданной фамилией.
  

  

---

  

## Блок-схема:

1. [Функция main](lab8_scheme1.png)
2. [Функция удаления студентов, у которых средний балл оценок ниже заданного](lab8_scheme2.png)
3. [Функция добавления студента, после заданного другого](lab8_scheme3.png)
4. [Функция заполнения структуры данных "Студент"](lab8_scheme4.png)
  

---

  

## Исходный код:

  

```cpp
#include <iostream>
#include <clocale>
#include <string>
#include <windows.h> 
using namespace std;

struct student 
{
	string surname;
	string name;
	string patronymic;
	string number;
	string group;
	int grades[3]{};
	double Average()
	{
		return (grades[0] + grades[1] + grades[2]) / 3.0;
	}

};
void pop_students(student*& students, int& n, double b, string grp)
{
	bool found = false;
	int count_del = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (students[i].group == grp && students[i].Average() < b)
		{
			found = true;
			count_del++;
		}
	}
	if (!found)
	{
		cout << "Таких студентов нет!" << endl << endl;
		return;
	}
	int newN = n - count_del;
	student* newStudents = new student[newN];
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(students[i].group == grp && students[i].Average() < b))
		{
			newStudents[index] = students[i];
			index++;
		}	
	}
	delete[] students;
	students = newStudents;
	n = newN;
}
void push_student(student*& students, int &n, student newStudent, string &surn)
{
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (students[i].surname == surn)
		{
			found = true;
		}
	}
	if (!found)
	{
		cout << "Такого студента нет!" << endl << endl;
		return;
	}
	student* newStudents = new student[n+1];
	for (int i = 0; i < n; i++)
	{
		if (students[i].surname == surn)
		{
			found = true;
			for (int j = 0; j <= i; j++)
			{
				newStudents[j] = students[j];
			}
			newStudents[i+1] = newStudent;
			for (int j = i + 1; j < n; j++)
			{
				newStudents[j+1] = students[j];
			}
		}
	}
	n++;
	delete[] students;
	students = newStudents;
}
void FillStudents(student *&students, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << students[i].surname << ' '
			<< students[i].name << ' '
			<< students[i].patronymic << endl
			<< "Номер телефона: " << students[i].number << endl
			<< "Группа: " << students[i].group << endl
			<< "Средний балл: " << students[i].Average() << endl << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "ru");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 6;
	student* students = new student[n];

	students[0] = {"Васильев", "Вячеслав", "Николаевич", "79225042307", "РИС-25-2Б", {5,5,5} };
	students[1] = {"Морозов", "Михаил", "Дмитриевич", "79225399392", "РИС-25-3Б", {5,4,4}};
	students[2] = {"Жукова", "Маргарита", "Андреевна", "79225262109", "РИС-25-3Б", {5,3,3}};
	students[3] = {"Иванов", "Виктор", "Максимович", "79221290693", "РИС-25-2Б", {4,3,5}};
	students[4] = {"Федоров", "Егор", "Даниэльевич", "79229757358", "РИС-25-1Б", {4,3,3}};
	students[5] = {"Широкова", "Анна", "Александровна", "79048788415", "РИС-25-1Б", {4,4,3}};

	FillStudents(students, n);

	cout << "Введите группу, в которой будем просматривать студентов: "; 
	string grp;
	getline(cin, grp);
	cout << "\nВведите минимальный средний балл, по которому будем отнимать стипендию у студентов: ";
	double b;
	cin >> b;
	cout << endl;

	pop_students(students, n, b, grp);
	FillStudents(students, n);

	student newStudent;
	cout << "Введите данные нового студента:\n";
	cout << "Фамилия: ";
	cin.ignore();
	getline(cin, newStudent.surname);
	cout << "Имя: ";
	getline(cin, newStudent.name);
	cout << "Отчество: ";
	getline(cin, newStudent.patronymic);
	cout << "Номер телефона: ";
	getline(cin, newStudent.number);
	cout << "Группа: ";
	getline(cin, newStudent.group);
	cout << "Оценки по 3 основным предметам: ";
	cin >> newStudent.grades[0];
	cin >> newStudent.grades[1];
	cin >> newStudent.grades[2];

	cout << "\nНапишите фамилию студента, после которого вы хотите добавить нового: ";
	string surn;
	cin.ignore();
	getline(cin, surn);
	cout << endl;

	push_student(students, n, newStudent, surn);
	FillStudents(students, n);
	delete[] students;
	students = nullptr;
	return 0;
}
```
---
## Пример работы:

**Вывод 1:**
```
Васильев Вячеслав Николаевич
Номер телефона: 79225042307
Группа: РИС-25-2Б
Средний балл: 5

Морозов Михаил Дмитриевич
Номер телефона: 79225399392
Группа: РИС-25-3Б
Средний балл: 4.33333

Жукова Маргарита Андреевна
Номер телефона: 79225262109
Группа: РИС-25-3Б
Средний балл: 3.66667

Иванов Виктор Максимович
Номер телефона: 79221290693
Группа: РИС-25-2Б
Средний балл: 4

Федоров Егор Даниэльевич
Номер телефона: 79229757358
Группа: РИС-25-1Б
Средний балл: 3.33333

Широкова Анна Александровна
Номер телефона: 79048788415
Группа: РИС-25-1Б
Средний балл: 3.66667
```
**Ввод 1:**
```
Введите группу, в которой будем просматривать студентов: РИС-25-1Б

Введите минимальный средний балл, по которому будем отнимать стипендию у студентов: 4
```
**Вывод 2:**
```
Васильев Вячеслав Николаевич
Номер телефона: 79225042307
Группа: РИС-25-2Б
Средний балл: 5

Морозов Михаил Дмитриевич
Номер телефона: 79225399392
Группа: РИС-25-3Б
Средний балл: 4.33333

Жукова Маргарита Андреевна
Номер телефона: 79225262109
Группа: РИС-25-3Б
Средний балл: 3.66667

Иванов Виктор Максимович
Номер телефона: 79221290693
Группа: РИС-25-2Б
Средний балл: 4
```
**Ввод 2:**
```
Введите данные нового студента:
Фамилия: Степанов
Имя: Максим
Отчество: Юрьевич
Номер телефона: 79045205267
Группа: РИС-25-1Б
Оценки по 3 основным предметам: 4 4 5

Напишите фамилию студента, после которого вы хотите добавить нового: Иванов
```
**Вывод 3:**
```
Васильев Вячеслав Николаевич
Номер телефона: 79225042307
Группа: РИС-25-2Б
Средний балл: 5

Морозов Михаил Дмитриевич
Номер телефона: 79225399392
Группа: РИС-25-3Б
Средний балл: 4.33333

Жукова Маргарита Андреевна
Номер телефона: 79225262109
Группа: РИС-25-3Б
Средний балл: 3.66667

Иванов Виктор Максимович
Номер телефона: 79221290693
Группа: РИС-25-2Б
Средний балл: 4

Степанов Максим Юрьевич
Номер телефона: 79045205267
Группа: РИС-25-1Б
Средний балл: 4.33333
```

---
## Скриншот:
[Скриншот 1](lab8_run1.png)
[Скриншот 2](lab8_run2.png)
[Скриншот 3](lab8_run3.png)