#include "task2.h"
#include <iostream>
#include <cstdlib>
using namespace std;

TimeSet make_time_set(int n) 
{
    TimeSet s;
    for (int i = 0; i < n; i++) 
    {
        int m = rand() % 60;
        int sec = rand() % 60;
        s.insert(Time(m, sec));
    }
    return s;
}

void print_time_set(TimeSet s) 
{
    cout << "{ ";
    for (Time t : s) 
    {
        cout << t << ' ';
    }
    cout << "}" << endl;
}

Time find_min_time(TimeSet s) 
{
    if (s.empty()) return Time(0, 0);
    return *s.begin();
}

Time find_max_time(TimeSet s) {
    if (s.empty()) return Time(0, 0);
    return *s.rbegin();
}

void task3_add_min_time(TimeSet& s) 
{
    if (s.empty()) 
    {
        cout << "Set пуст!\n";
        return;
    }
    Time min_val = find_min_time(s);
    cout << "Минимальный элемент уже в set: " << min_val << endl;
    cout << "Примечание: в set нельзя добавить дубликат\n";
}

bool task4_delete_key_time(TimeSet& s, Time key) 
{
    auto it = s.find(key);
    if (it != s.end()) 
    {
        cout << "Удален элемент: " << *it << endl;
        s.erase(it);
        return true;
    }
    cout << "Элемент " << key << " не найден\n";
    return false;
}

void task5_add_min_max_sum_time(set<Time>& s) 
{
    if (s.empty()) 
    {
        cout << "Set пуст!\n";
        return;
    }

    Time min_val = find_min_time(s);
    Time max_val = find_max_time(s);
    Time sum = min_val + max_val;

    cout << "Min: " << min_val << ", Max: " << max_val << ", Sum: " << sum << endl;

    set<Time> new_set;
    for (Time t : s) 
    {
        new_set.insert(t + sum);
    }

    s = new_set;
}

void runTask2() 
{
    try
    {
        int n;
        cout << "\n=== Задача 2: set<Time> ===\n";
        cout << "Введите количество элементов: ";
        cin >> n;

        TimeSet s = make_time_set(n);
        cout << "Исходный set: ";
        print_time_set(s);


        cout << "\n--- Задание 3 ---\n";
        task3_add_min_time(s);
        cout << "Set: ";
        print_time_set(s);


        cout << "\n--- Задание 4 ---\n";
        cout << "Введите время для удаления:\n";
        Time key;
        cin >> key;
        task4_delete_key_time(s, key);
        cout << "Set: ";
        print_time_set(s);


        cout << "\n--- Задание 5 ---\n";
        task5_add_min_max_sum_time(s);
        cout << "Set после добавления суммы min+max: ";
        print_time_set(s);

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}