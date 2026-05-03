#include "task1.h"
#include <iostream>
#include <cstdlib>
#include <iterator>
using namespace std;

typedef list<float>List;

List make_list(int n)
{
	List l;
	for (int i = 0; i < n; i++)
	{
		float a = rand() % 100 - 50;
		l.push_back(a);
	}
	return l;
}

void print_list(List l)
{
	for (float val : l)
	{
		cout << val << ' ';
	}
	cout << endl;
}

float find_min(List l)
{
	if (l.empty())
		return 0;

	float min = *l.begin();

	for (float val : l)
	{
		if (val < min)
		{
			min = val;
		}
	}

	return min;
}
float find_max(List l)
{
	if (l.empty())
		return 0;

	float max = *l.begin();

	for (float val : l)
	{
		if (val > max)
		{
			max = val;
		}
	}
	return max;
}

void task3_add_min(List& l)
{
	float min = find_min(l);
	l.push_back(min);
	cout << "Добавлен минимальный элемент: " << min << endl;
}

bool task4_delete_key(List& l, float key)
{
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		if (*it == key)
		{
			l.erase(it);
			cout << "Элемент " << key << " удален\n";
			return true;
		}
	}
	cout << "Элемент " << key << " не найден\n";
	return false;
}

void task5_add_min_max_sum(List& l)
{
	float min = find_min(l);
	float max = find_max(l);
	float sum = min + max;

	cout << "Min: " << min << ", Max: " << max << ", Sum: " << sum << endl;

	for (auto& val : l)
	{
		val += sum;
	}
}

void runTask1() 
{
	try
	{
		int n;
		cout << "\n=== Задача 1: Список float ===\n";
		cout << "Введите размер списка: ";
		cin >> n;

		List l = make_list(n);
		cout << "Исходный список: ";
		print_list(l);

		cout << "\n--- Задание 3 ---\n";
		task3_add_min(l);
		cout << "После добавления минимума: ";
		print_list(l);

		cout << "\n--- Задание 4 ---\n";
		float key;
		cout << "Введите элемент для удаления: ";
		cin >> key;
		task4_delete_key(l, key);
		cout << "После удаления: ";
		print_list(l);

		cout << "\n--- Задание 5 ---\n";
		task5_add_min_max_sum(l);
		cout << "После добавления суммы min+max: ";
		print_list(l);

	}
	catch (...) {
		cout << "Ошибка!\n";
	}
}