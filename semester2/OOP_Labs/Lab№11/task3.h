#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Vector 
{
private:
    T* data;
    int size;
public:
    Vector(int s = 0);
    ~Vector();

    void fill();
    void print();
    T find_min();
    T find_max();

    void task3_add_min();
    bool task4_delete_key(T key);
    void task5_add_min_max_sum();
};

inline void runTask3();


template <typename T>
Vector<T>::Vector(int s) : size(s)
{
    data = new T[size];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
void Vector<T>::fill()
{
    for (int i = 0; i < size; i++)
    {
        data[i] = static_cast<T>(rand() % 100 - 50);
    }
}

template <typename T>
void Vector<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

template <typename T>
T Vector<T>::find_min()
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
T Vector<T>::find_max()
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
void Vector<T>::task3_add_min()
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
bool Vector<T>::task4_delete_key(T key)
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

    if (index == -1)
    {
        cout << "Элемент " << key << " не найден\n";
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
    cout << "Элемент " << key << " удален\n";
    return true;
}

template <typename T>
void Vector<T>::task5_add_min_max_sum()
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

template class Vector<float>;

void runTask3()
{
    try {
        int n;
        cout << "\n=== Задача 3: Vector<float> ===\n";
        cout << "Введите размер вектора: ";
        cin >> n;

        Vector<float> v(n);
        v.fill();
        cout << "Исходный вектор: ";
        v.print();

        cout << "\n--- Задание 3 ---\n";
        v.task3_add_min();
        cout << "После добавления минимума: ";
        v.print();

        cout << "\n--- Задание 4 ---\n";
        float key;
        cout << "Введите элемент для удаления: ";
        cin >> key;
        v.task4_delete_key(key);
        cout << "После удаления: ";
        v.print();

        cout << "\n--- Задание 5 ---\n";
        v.task5_add_min_max_sum();
        cout << "После добавления суммы min+max: ";
        v.print();
    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}