#include "task2.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ListTime make_list_time(int n) 
{
    ListTime l;
    for (int i = 0; i < n; i++) 
    {
        int m = rand() % 60;
        int s = rand() % 60;
        l.push_back(Time(m, s));
    }
    return l;
}

void print_list_time(ListTime l) 
{
    for (Time t : l) 
    {
        cout << t << ' ';
    }
    cout << endl;
}

Time find_min_time(ListTime l) 
{
    if (l.empty()) return Time(0, 0);
    Time min_val = *l.begin();
    for (Time t : l) 
    {
        if (t < min_val) 
        {
            min_val = t;
        }
    }
    return min_val;
}

Time find_max_time(ListTime l) 
{
    if (l.empty()) return Time(0, 0);
    Time max_val = *l.begin();
    for (Time t : l) 
    {
        if (max_val < t) 
        {
            max_val = t;
        }
    }
    return max_val;
}

void task3_add_min_time(ListTime& l) 
{
    Time min_val = find_min_time(l);
    l.push_back(min_val);
    cout << "Добавлен минимальный элемент: " << min_val << endl;
}

bool task4_delete_key_time(ListTime& l, Time key) 
{
    for (auto it = l.begin(); it != l.end(); ++it) 
    {
        if (*it == key) 
        {
            cout << "Удален элемент: " << *it << endl;
            l.erase(it);
            return true;
        }
    }
    cout << "Элемент " << key << " не найден\n";
    return false;
}


void task5_add_min_max_sum_time(ListTime& l) 
{
    Time min_val = find_min_time(l);
    Time max_val = find_max_time(l);
    Time sum = min_val + max_val;

    cout << "Min: " << min_val << ", Max: " << max_val << ", Sum: " << sum << endl;

    for (auto& val : l) 
    {
        val = val + sum;
    }
}

void runTask2() 
{
    try 
    {
        int n;
        cout << "\n=== Задача 2: Список Time ===\n";
        cout << "Введите размер списка: ";
        cin >> n;

        ListTime l = make_list_time(n);
        cout << "Исходный список: ";
        print_list_time(l);

        cout << "\n--- Задание 3 ---\n";
        task3_add_min_time(l);
        cout << "После добавления минимума: ";
        print_list_time(l);


        cout << "\n--- Задание 4 ---\n";
        cout << "Введите время для удаления:\n";
        Time key;
        cin >> key;
        task4_delete_key_time(l, key);
        cout << "После удаления: ";
        print_list_time(l);

        cout << "\n--- Задание 5 ---\n";
        task5_add_min_max_sum_time(l);
        cout << "После добавления суммы min+max: ";
        print_list_time(l);

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}