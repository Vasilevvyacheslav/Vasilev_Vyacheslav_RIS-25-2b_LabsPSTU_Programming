#include "task5.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
VectorQueue<T>::VectorQueue(int s) : size(s) 
{
    data = new T[size];
}

template <typename T>
VectorQueue<T>::~VectorQueue() 
{
    delete[] data;
}

template <typename T>
void VectorQueue<T>::fill_random() 
{
    for (int i = 0; i < size; i++) 
    {
        int m = rand() % 60;
        int s = rand() % 60;
        data[i] = T(m, s);
    }
}

template <typename T>
void VectorQueue<T>::print() {
    for (int i = 0; i < size; i++) 
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

template <typename T>
T VectorQueue<T>::find_min() 
{
    if (size == 0) return T();
    T min_val = data[0];
    for (int i = 1; i < size; i++) 
    {
        if (data[i] < min_val) 
        {
            min_val = data[i];
        }
    }
    return min_val;
}

template <typename T>
T VectorQueue<T>::find_max() 
{
    if (size == 0) return T();
    T max_val = data[0];
    for (int i = 1; i < size; i++) 
    {
        if (data[i] > max_val) 
        {
            max_val = data[i];
        }
    }
    return max_val;
}

template <typename T>
void VectorQueue<T>::task3_add_min() 
{
    T min_val = find_min();
    T* new_data = new T[size + 1];
    for (int i = 0; i < size; i++) 
    {
        new_data[i] = data[i];
    }
    new_data[size] = min_val;
    delete[] data;
    data = new_data;
    size++;
    cout << "Добавлен минимальный элемент: " << min_val << endl;
}

template <typename T>
bool VectorQueue<T>::task4_delete_key(T key) 
{
    int index = -1;
    for (int i = 0; i < size; i++) 
    {
        if (data[i] == key) 
        {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Элемент не найден\n";
        return false;
    }

    T* new_data = new T[size - 1];
    for (int i = 0, j = 0; i < size; i++) 
    {
        if (i != index) 
        {
            new_data[j++] = data[i];
        }
    }
    delete[] data;
    data = new_data;
    size--;
    cout << "Элемент удален\n";
    return true;
}

template <typename T>
void VectorQueue<T>::task5_add_min_max_sum() 
{
    T min_val = find_min();
    T max_val = find_max();
    T sum = min_val + max_val;

    cout << "Min: " << min_val << ", Max: " << max_val << ", Sum: " << sum << endl;

    for (int i = 0; i < size; i++) 
    {
        data[i] = data[i] + sum;
    }
}

template class VectorQueue<Time>;

void runTask5() 
{
    try 
    {
        int n;
        cout << "\n=== Задача 5: Vector<Time> ===\n";
        cout << "Введите размер вектора: ";
        cin >> n;

        VectorQueue<Time> vec(n);
        vec.fill_random();
        cout << "Исходный вектор: ";
        vec.print();


        cout << "\n--- Задание 3 ---\n";
        vec.task3_add_min();
        cout << "После добавления минимума: ";
        vec.print();


        cout << "\n--- Задание 4 ---\n";
        cout << "Введите время для удаления:\n";
        Time key;
        cin >> key;
        vec.task4_delete_key(key);
        cout << "После удаления: ";
        vec.print();


        cout << "\n--- Задание 5 ---\n";
        vec.task5_add_min_max_sum();
        cout << "После добавления суммы min+max: ";
        vec.print();

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}