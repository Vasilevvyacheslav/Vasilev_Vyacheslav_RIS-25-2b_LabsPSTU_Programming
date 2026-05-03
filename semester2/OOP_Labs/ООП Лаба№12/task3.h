#pragma once
#include "Time.h" 
#include <set>
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class VectorSet 
{
private:
    set<T, less<T>> data;

public:
    void fill_random(int n);
    void print();
    T find_min();
    T find_max();

    void task3_add_min();
    bool task4_delete_key(T key);
    void task5_add_min_max_sum();
};

template <typename T>
void runTask3();


template <typename T>
void VectorSet<T>::fill_random(int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int m = rand() % 60;
        int sec = rand() % 60;
        data.insert(T(m, sec));
    }
}

template <typename T>
void VectorSet<T>::print() 
{
    cout << "{ ";
    for (T val : data) 
    {
        cout << val << ' ';
    }
    cout << "}" << endl;
}

template <typename T>
T VectorSet<T>::find_min() 
{
    if (data.empty()) return T();
    return *data.begin();
}

template <typename T>
T VectorSet<T>::find_max() 
{
    if (data.empty()) return T();
    return *data.rbegin();
}

template <typename T>
void VectorSet<T>::task3_add_min() 
{
    if (data.empty()) 
    {
        cout << "Set пуст!\n";
        return;
    }
    T min_val = find_min();
    cout << "Минимальный элемент уже в set: " << min_val << endl;
}

template <typename T>
bool VectorSet<T>::task4_delete_key(T key) 
{
    auto it = data.find(key);
    if (it != data.end())
    {
        cout << "Удален элемент: " << *it << endl;
        data.erase(it);
        return true;
    }
    cout << "Элемент не найден\n";
    return false;
}

template <typename T>
void VectorSet<T>::task5_add_min_max_sum() 
{
    if (data.empty()) {
        cout << "Set пуст!\n";
        return;
    }

    T min_val = find_min();
    T max_val = find_max();
    T sum = min_val + max_val;

    cout << "Min: " << min_val << ", Max: " << max_val << ", Sum: " << sum << endl;

    set<T> new_set;
    for (T val : data) 
    {
        new_set.insert(val + sum);
    }

    data = new_set;
}


template class VectorSet<Time>;

template <typename T>
void runTask3() {
    try {
        int n;
        cout << "\n=== Задача 3: VectorSet<Time> ===\n";
        cout << "Введите количество элементов: ";
        cin >> n;

        VectorSet<T> vs;
        vs.fill_random(n);
        cout << "Исходный set: ";
        vs.print();


        cout << "\n--- Задание 3 ---\n";
        vs.task3_add_min();
        cout << "Set: ";
        vs.print();


        cout << "\n--- Задание 4 ---\n";
        cout << "Введите время для удаления:\n";
        T key;
        cin >> key;
        vs.task4_delete_key(key);
        cout << "Set: ";
        vs.print();


        cout << "\n--- Задание 5 ---\n";
        vs.task5_add_min_max_sum();
        cout << "Set после добавления суммы min+max: ";
        vs.print();

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}

template void runTask3<Time>();