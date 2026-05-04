#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int choice;

    do {
        cout << "========== МЕНЮ ==========\n";
        cout << "1. Задача 1 (set<float>)\n";
        cout << "2. Задача 2 (set<Time>)\n";
        cout << "3. Задача 3 (VectorSet<Time>)\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: runTask1(); break;
        case 2: runTask2(); break;
        case 3: runTask3<Time>(); break;
        case 0: break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}