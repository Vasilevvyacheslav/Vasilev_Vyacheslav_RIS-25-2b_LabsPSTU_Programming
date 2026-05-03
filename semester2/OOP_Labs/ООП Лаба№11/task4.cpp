#include "task4.h"
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

QueueTime make_queue(int n) 
{
    QueueTime q;
    for (int i = 0; i < n; i++) 
    {
        int m = rand() % 60;
        int s = rand() % 60;
        q.push(Time(m, s));
    }
    return q;
}

void print_queue(QueueTime q) 
{
    while (!q.empty()) 
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}

Time find_min_queue(QueueTime q) 
{
    if (q.empty()) return Time(0, 0);
    Time min_val = q.front();
    while (!q.empty()) 
    {
        if (q.front() < min_val) 
        {
            min_val = q.front();
        }
        q.pop();
    }
    return min_val;
}

Time find_max_queue(QueueTime q) 
{
    if (q.empty()) return Time(0, 0);
    Time max_val = q.front();
    while (!q.empty()) {
        if (max_val < q.front()) 
        {
            max_val = q.front();
        }
        q.pop();
    }
    return max_val;
}


QueueTime task3_add_min_queue(QueueTime q) 
{
    Time min_val = find_min_queue(q);
    q.push(min_val);
    cout << "Добавлен минимальный элемент: " << min_val << endl;
    return q;
}


QueueTime task4_delete_key_queue(QueueTime q, Time key) 
{
    QueueTime temp;
    bool found = false;

    while (!q.empty()) 
    {
        if (q.front() != key) 
        {
            temp.push(q.front());
        }
        else 
        {
            cout << "Удален элемент: " << q.front() << endl;
            found = true;
        }
        q.pop();
    }

    if (!found) {
        cout << "Элемент " << key << " не найден\n";
    }

    return temp;
}


QueueTime task5_add_min_max_sum_queue(QueueTime q)
{
    Time min_val = find_min_queue(q);
    Time max_val = find_max_queue(q);
    Time sum = min_val + max_val;

    cout << "Min: " << min_val << ", Max: " << max_val << ", Sum: " << sum << endl;

    QueueTime result;
    while (!q.empty()) 
    {
        Time t = q.front() + sum;
        result.push(t);
        q.pop();
    }

    return result;
}

void runTask4() 
{
    try {
        int n;
        cout << "\n=== Задача 4: Очередь Time ===\n";
        cout << "Введите размер очереди: ";
        cin >> n;

        QueueTime q = make_queue(n);
        cout << "Исходная очередь: ";
        print_queue(q);


        cout << "\n--- Задание 3 ---\n";
        q = task3_add_min_queue(q);
        cout << "После добавления минимума: ";
        print_queue(q);


        cout << "\n--- Задание 4 ---\n";
        cout << "Введите время для удаления:\n";
        Time key;
        cin >> key;
        q = task4_delete_key_queue(q, key);
        cout << "После удаления: ";
        print_queue(q);


        cout << "\n--- Задание 5 ---\n";
        q = task5_add_min_max_sum_queue(q);
        cout << "После добавления суммы min+max: ";
        print_queue(q);

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}