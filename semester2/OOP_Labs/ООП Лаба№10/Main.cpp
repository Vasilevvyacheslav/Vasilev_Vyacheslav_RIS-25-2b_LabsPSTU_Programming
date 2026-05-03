#include "Time.h"
#include "file_work.h"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	Time t, t1, t2, t0;
	int k, c;
	char file_name[30];
	do
	{
		cout << "1. Создать файл";
		cout << "\n2. Печать файла";
		cout << "\n3. Удалить записи, не равные заданному значению";
		cout << "\n4. Уменьшить записи, равные заданному, на 1:30";
		cout << "\n5. Добавить K записей в начало файла";
		cout << "\n0. Выйти\n\n";
		cin >> c;
		switch (c)
		{
		case 1: 
			cout << "Введите имя файла: "; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Ошибка. Файл не открылся!" << endl;
			break;
		case 2: 
			cout << "Введите имя файла: "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Файл пустой!" << endl;
			if (k < 0) cout << "Ошибка. Файл не открылся!" << endl;
			break;
		case 3:
			cout << "Введите имя файла: "; cin >> file_name;
			cout << "Введите значение (какие записи оставить): "; cin >> t0;
			k = del_file(file_name, t0);
			if (k < 0) cout << "Ошибка. Файл не открылся!" << endl;
			break;
		case 4:
			cout << "Введите имя файла: "; cin >> file_name;
			cout << "Введите значение (какие записи уменьшить): "; cin >> t0;
			k = decrease_file(file_name, t0);
			if (k < 0) cout << "Ошибка. Файл не открылся!" << endl;
			break;
		case 5:
			cout << "Введите имя файла: "; cin >> file_name;
			cout << "Сколько записей добавить: "; cin >> k;
			k = add_file(file_name, k, t1);
			if (k < 0) cout << "Ошибка. Файл не открылся!" << endl;
			break;
		case 0: 
			break;
		default:
			cout << "Invalid choise" << endl;
			break;
		}
	} while (c!=0);
	return 0;
}