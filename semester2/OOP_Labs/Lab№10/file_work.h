#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Time t;
	cout << "Введите кол-во объектов: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stream << t << endl;
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t;
	int i = 0;
	while (stream >> t)
	{
		cout << t << endl;
		i++;
	}
	cout << endl;
	stream.close();
	return i;
}

int del_file(const char* f_name, Time t0)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream || !temp) return -1;
	Time t;
	int count = 0;
	while (stream >> t)
	{
		if (stream.eof()) break;
		if (t == t0)
		{
			temp << t << endl;
			count++;
		}
	}
	stream.close(); temp.close();
	if (remove(f_name) != 0)
	{
		cout << "Ошибка удаления файла!" << endl;
		return -1;
	}

	if (rename("temp", f_name) != 0)
	{
		cout << "Ошибка переименования файла!" << endl;
		return -1;
	}
	return count;
}

int add_file(const char* f_name, int k, Time tt)
{

	fstream stream(f_name, ios::in);
	if (!stream) return -1;

	Time arr[100];  
	int n = 0;

	while (stream >> arr[n])
	{
		if (stream.eof()) break;
		n++;
	}
	stream.close();

	
	stream.open(f_name, ios::out);
	if (!stream) return -1;


	cout << "Введите " << k << " новых объектов:\n";
	for (int i = 0; i < k; i++)
	{
		cout << "Запись " << (i + 1) << ": ";
		cin >> tt;

		tt.normalize_time();

		stream << tt << endl;
	}


	for (int i = 0; i < n; i++)
	{
		stream << arr[i] << endl;
	}

	stream.close();

	return k;
}

int decrease_file(const char* f_name, Time t0)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream || !temp) return -1;
	Time t;
	Time decrease(1, 30);
	int count = 0;
	while (stream >> t)
	{
		if (stream.eof()) break;

		if (t != t0)  
		{
			temp << t << endl;
		}
		else 
		{
			t = t - decrease;
			t.normalize_time();  

			if (t.getMin() < 0 || t.getSec() < 0)
			{
				t = Time(0, 0);
			}

			temp << t << endl;
			count++;
		}
	}
	stream.close(); temp.close();
	if (remove(f_name) != 0)
	{
		cout << "Ошибка удаления файла!" << endl;
		return -1;
	}

	if (rename("temp", f_name) != 0)
	{
		cout << "Ошибка переименования файла!" << endl;
		return -1;
	}
	return count;
}