#include "task1.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

TimeList make_list(int n) 
{
    TimeList l;
    for (int i = 0; i < n; i++) 
    {
        int m = abs(rand()) % 60;
        int s = abs(rand()) % 60;
        l.push_back(Time(m, s));
    }
    return l;
}

void print_list(TimeList l) 
{
    cout << "{ ";
    for (Time t : l) {
        cout << t << ' ';
    }
    cout << "}" << endl;
}

Time find_min_list(TimeList l) 
{
    if (l.empty()) return Time(0, 0);
    Time min_val = *l.begin();
    for (Time t : l) 
    {
        if (t < min_val) min_val = t;
    }
    return min_val;
}

Time find_max_list(TimeList l) 
{
    if (l.empty()) return Time(0, 0);
    Time max_val = *l.begin();
    for (Time t : l) 
    {
        if (t > max_val) max_val = t;
    }
    return max_val;
}

void task3_replace(TimeList& l) {
    if (l.empty()) {
        cout << "Список пуст!\n";
        return;
    }

    Time min_val = find_min_list(l);
    Time replacement = min_val + Time(1, 0);

    replace_if(l.begin(), l.end(),
        [min_val](const Time& t) { return t > min_val; },
        replacement
    );

    cout << "После replace_if:\n";
    print_list(l);
}

void task4_remove(TimeList& l) {
    if (l.empty()) {
        cout << "Список пуст!\n";
        return;
    }

    Time min_val = find_min_list(l);

    l.remove_if(
        [min_val](const Time& t) { return t > min_val; }
    );

    cout << "После remove_if:\n";
    print_list(l);
}


void task5_sort(TimeList& l) {
    // Сортировка по возрастанию
    l.sort();
    cout << "По возрастанию: ";
    print_list(l);

    // Сортировка по убыванию
    l.sort(greater<Time>());
    cout << "По убыванию: ";
    print_list(l);

    // Сортировка обратно по возрастанию
    l.sort();
}


void task6_find(TimeList l) {
    if (l.empty()) {
        cout << "Список пуст!\n";
        return;
    }

    Time search_val = *l.begin();

    auto it = find(l.begin(), l.end(), search_val);
    if (it != l.end()) {
        cout << "find: найден элемент " << *it << endl;
    }


    Time threshold(0, 30);
    it = find_if(l.begin(), l.end(),
        [threshold](const Time& t) { return t > threshold; }
    );
    if (it != l.end()) {
        cout << "find_if (первый > 0:30): " << *it << endl;
    }


    int cnt = count(l.begin(), l.end(), search_val);
    cout << "count(" << search_val << "): " << cnt << endl;


    Time limit(1, 0);
    cnt = count_if(l.begin(), l.end(),
        [limit](const Time& t) { return t < limit; }
    );
    cout << "count_if (элементов < 1:0): " << cnt << endl;
}

void task7_for_each(TimeList& l) {
    Time min_val = find_min_list(l);
    Time max_val = find_max_list(l);
    Time sum = min_val + max_val;

    for_each(l.begin(), l.end(),
        [sum](Time& t) { t = t + sum; }
    );

    cout << "После for_each (добавлена сумма min+max):\n";
    print_list(l);
}

void runTask1() {
    try {
        int n;
        cout << "\n=== Задача 1: list<Time> ===\n";
        cout << "Введите количество элементов: ";
        cin >> n;

        TimeList l = make_list(n);
        cout << "Исходный список: ";
        print_list(l);


        cout << "\n--- Задание 3 (replace_if) ---\n";
        task3_replace(l);


        cout << "\n--- Задание 4 (remove_if) ---\n";
        task4_remove(l);


        cout << "\n--- Задание 5 (sort) ---\n";
        task5_sort(l);

        cout << "\n--- Задание 6 (find, count) ---\n";
        task6_find(l);

        cout << "\n--- Задание 7 (for_each) ---\n";
        task7_for_each(l);
        cout << "Итоговый список: ";
        print_list(l);

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}