#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
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
        cout << "\n1. Задача 1 (список float)";
        cout << "\n2. Задача 2 (список Time)";
        cout << "\n3. Задача 3 (Vector)";
        cout << "\n4. Задача 4 (очередь)";
        cout << "\n5. Задача 5 (параметризованная очередь)";
        cout << "\n0. Выход\n";
        cin >> choice;

        switch (choice)
        {
        case 1: runTask1(); break;
        case 2: runTask2(); break;
        case 3: runTask3(); break;
        case 4: runTask4(); break;
        case 5: runTask5(); break;
        }
    } while (choice != 0);

    return 0;
}