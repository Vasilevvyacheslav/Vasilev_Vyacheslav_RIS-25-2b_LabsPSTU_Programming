#include "task1.h"
#include <iostream>
#include <cstdlib>
using namespace std;

FloatSet make_set(int n) 
{
    FloatSet s;
    for (int i = 0; i < n; i++) 
    {
        float val = static_cast<float>(rand() % 100 - 50);
        s.insert(val); 
    }
    return s;
}

void print_set(FloatSet s) 
{
    cout << "{ ";
    for (float val : s) 
    {
        cout << val << ' ';
    }
    cout << "}" << endl;
}

float find_min(FloatSet s)
{
    if (s.empty()) return 0;
    return *s.begin();  
}

float find_max(FloatSet s) {
    if (s.empty()) return 0;
    return *s.rbegin();  
}

void task3_add_min(FloatSet& s) 
{
    if (s.empty()) 
    {
        cout << "Set пуст!\n";
        return;
    }
    float min_val = find_min(s);
    // В set нельзя добавить дубликат, поэтому удаляем и вставляем снова
    // Но для set это не имеет смысла, т.к. min уже есть
    cout << "Минимальный элемент уже в set: " << min_val << endl;
    cout << "Примечание: в set нельзя добавить дубликат\n";
}

bool task4_delete_key(FloatSet& s, float key) 
{
    auto it = s.find(key);
    if (it != s.end()) 
    {
        s.erase(it);
        cout << "Элемент " << key << " удален\n";
        return true;
    }
    cout << "Элемент " << key << " не найден\n";
    return false;
}


void task5_add_min_max_sum(set<float>& s) 
{
    if (s.empty()) 
    {
        cout << "Set пуст!\n";
        return;
    }

    float min_val = find_min(s);
    float max_val = find_max(s);
    float sum = min_val + max_val;

    cout << "Min: " << min_val << ", Max: " << max_val << ", Sum: " << sum << endl;

    // Создаём новый set с изменёнными значениями
    set<float> new_set;
    for (float val : s) 
    {
        new_set.insert(val + sum);
    }

    s = new_set;
}

void runTask1() 
{
    try
    {
        int n;
        cout << "\n=== Задача 1: set<float> ===\n";
        cout << "Введите количество элементов: ";
        cin >> n;

        FloatSet s = make_set(n);
        cout << "Исходный set: ";
        print_set(s);


        cout << "\n--- Задание 3 ---\n";
        task3_add_min(s);
        cout << "Set: ";
        print_set(s);


        cout << "\n--- Задание 4 ---\n";
        float key;
        cout << "Введите элемент для удаления: ";
        cin >> key;
        task4_delete_key(s, key);
        cout << "Set: ";
        print_set(s);


        cout << "\n--- Задание 5 ---\n";
        task5_add_min_max_sum(s);
        cout << "Set после добавления суммы min+max: ";
        print_set(s);

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}