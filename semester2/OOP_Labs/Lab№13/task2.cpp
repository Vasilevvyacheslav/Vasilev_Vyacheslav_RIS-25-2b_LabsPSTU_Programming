#include "task2.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

TimeQueue make_queue(int n) {
    TimeQueue q;
    for (int i = 0; i < n; i++) {
        int m = abs(rand()) % 60;
        int s = abs(rand()) % 60;
        q.push(Time(m, s));
    }
    return q;
}

void print_queue(TimeQueue q) {
    cout << "{ ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "}" << endl;
}

Time find_min_queue(TimeQueue q) {
    if (q.empty()) return Time(0, 0);
    Time min_val = q.front();
    while (!q.empty()) {
        if (q.front() < min_val) min_val = q.front();
        q.pop();
    }
    return min_val;
}

Time find_max_queue(TimeQueue q) {
    if (q.empty()) return Time(0, 0);
    Time max_val = q.front();
    while (!q.empty()) {
        if (q.front() > max_val) max_val = q.front();
        q.pop();
    }
    return max_val;
}

void task3_replace_queue(TimeQueue& q) {
    if (q.empty()) {
        cout << "Очередь пуста!\n";
        return;
    }

    vector<Time> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }

    Time min_val = *min_element(temp.begin(), temp.end());
    Time replacement = min_val + Time(1, 0);

    replace_if(temp.begin(), temp.end(),
        [min_val](const Time& t) { return t > min_val; },
        replacement
    );

    for (Time t : temp) {
        q.push(t);
    }

    cout << "После replace_if:\n";
    print_queue(q);
}

void task4_remove_queue(TimeQueue& q) {
    if (q.empty()) {
        cout << "Очередь пуста!\n";
        return;
    }

    vector<Time> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }

    Time min_val = *min_element(temp.begin(), temp.end());

    auto new_end = remove_if(temp.begin(), temp.end(),
        [min_val](const Time& t) { return t > min_val; }
    );
    temp.erase(new_end, temp.end());

    for (Time t : temp) {
        q.push(t);
    }

    cout << "После remove_if:\n";
    print_queue(q);
}

void task5_sort_queue(TimeQueue& q) {
    vector<Time> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }

    sort(temp.begin(), temp.end());
    cout << "По возрастанию: { ";
    for (Time t : temp) cout << t << " ";
    cout << "}\n";

    sort(temp.begin(), temp.end(), greater<Time>());
    cout << "По убыванию: { ";
    for (Time t : temp) cout << t << " ";
    cout << "}\n";

    sort(temp.begin(), temp.end());
    for (Time t : temp) q.push(t);
}

void task6_find_queue(TimeQueue q) {
    vector<Time> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }

    if (temp.empty()) {
        cout << "Очередь пуста!\n";
        return;
    }

    Time search_val = temp[0];

    auto it = find(temp.begin(), temp.end(), search_val);
    if (it != temp.end()) {
        cout << "find: найден " << *it << endl;
    }

    int cnt = count(temp.begin(), temp.end(), search_val);
    cout << "count(" << search_val << "): " << cnt << endl;
}

void task7_for_each_queue(TimeQueue& q) {
    vector<Time> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }

    if (temp.empty()) return;

    Time min_val = *min_element(temp.begin(), temp.end());
    Time max_val = *max_element(temp.begin(), temp.end());
    Time sum = min_val + max_val;

    for_each(temp.begin(), temp.end(),
        [sum](Time& t) { t = t + sum; }
    );

    for (Time t : temp) q.push(t);

    cout << "После for_each:\n";
    print_queue(q);
}

void runTask2() {
    try {
        int n;
        cout << "\n=== Задача 2: queue<Time> ===\n";
        cout << "Введите количество элементов: ";
        cin >> n;

        TimeQueue q = make_queue(n);
        cout << "Исходная очередь: ";
        print_queue(q);

        cout << "\n--- Задание 3 ---\n";
        task3_replace_queue(q);

        cout << "\n--- Задание 4 ---\n";
        task4_remove_queue(q);

        cout << "\n--- Задание 5 ---\n";
        task5_sort_queue(q);

        cout << "\n--- Задание 6 ---\n";
        task6_find_queue(q);

        cout << "\n--- Задание 7 ---\n";
        task7_for_each_queue(q);
        cout << "Итоговая очередь: ";
        print_queue(q);

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}