#include "task3.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

TimeMultiset make_multiset(int n) {
    TimeMultiset ms;
    for (int i = 0; i < n; i++) {
        int m = abs(rand()) % 60;
        int s = abs(rand()) % 60;
        ms.insert(Time(m, s));
    }
    return ms;
}

void print_multiset(TimeMultiset ms) {
    cout << "{ ";
    for (Time t : ms) {
        cout << t << " ";
    }
    cout << "}" << endl;
}

Time find_min_multiset(TimeMultiset ms) {
    if (ms.empty()) return Time(0, 0);
    return *ms.begin();
}

Time find_max_multiset(TimeMultiset ms) {
    if (ms.empty()) return Time(0, 0);
    return *ms.rbegin();
}

void task3_replace_multiset(TimeMultiset& ms) {
    if (ms.empty()) {
        cout << "Multiset пуст!\n";
        return;
    }

    vector<Time> temp(ms.begin(), ms.end());
    ms.clear();

    Time min_val = *min_element(temp.begin(), temp.end());
    Time replacement = min_val + Time(1, 0);

    replace_if(temp.begin(), temp.end(),
        [min_val](const Time& t) { return t > min_val; },
        replacement
    );

    for (Time t : temp) {
        ms.insert(t);
    }

    cout << "После replace_if:\n";
    print_multiset(ms);
}

void task4_remove_multiset(TimeMultiset& ms) {
    if (ms.empty()) {
        cout << "Multiset пуст!\n";
        return;
    }

    Time min_val = find_min_multiset(ms);


    for (auto it = ms.begin(); it != ms.end(); ) {
        if (*it > min_val) {
            it = ms.erase(it);
        }
        else {
            ++it;
        }
    }

    cout << "После удаления (оставлены только min):\n";
    print_multiset(ms);
}

void task5_sort_multiset(TimeMultiset& ms) {

    cout << "По возрастанию (по умолчанию): ";
    print_multiset(ms);


    vector<Time> temp(ms.begin(), ms.end());
    sort(temp.begin(), temp.end(), greater<Time>());

    cout << "По убыванию: { ";
    for (Time t : temp) cout << t << " ";
    cout << "}\n";
}

void task6_find_multiset(TimeMultiset ms) {
    if (ms.empty()) {
        cout << "Multiset пуст!\n";
        return;
    }

    Time search_val = *ms.begin();


    auto it = ms.find(search_val);
    if (it != ms.end()) {
        cout << "find: найден " << *it << endl;
    }


    int cnt = ms.count(search_val);
    cout << "count(" << search_val << "): " << cnt << endl;


    Time limit(0, 30);
    cnt = count_if(ms.begin(), ms.end(),
        [limit](const Time& t) { return t < limit; }
    );
    cout << "count_if (элементов < 0:30): " << cnt << endl;
}

void task7_for_each_multiset(TimeMultiset& ms) {
    if (ms.empty()) return;

    Time min_val = find_min_multiset(ms);
    Time max_val = find_max_multiset(ms);
    Time sum = min_val + max_val;


    vector<Time> temp(ms.begin(), ms.end());
    ms.clear();

    for_each(temp.begin(), temp.end(),
        [sum](Time& t) { t = t + sum; }
    );

    for (Time t : temp) {
        ms.insert(t);
    }

    cout << "После for_each (добавлена сумма min+max):\n";
    print_multiset(ms);
}

void runTask3() {
    try {
        int n;
        cout << "\n=== Задача 3: multiset<Time> ===\n";
        cout << "Введите количество элементов: ";
        cin >> n;

        TimeMultiset ms = make_multiset(n);
        cout << "Исходный multiset: ";
        print_multiset(ms);

        cout << "\n--- Задание 3 ---\n";
        task3_replace_multiset(ms);

        cout << "\n--- Задание 4 ---\n";
        task4_remove_multiset(ms);

        cout << "\n--- Задание 5 ---\n";
        task5_sort_multiset(ms);

        cout << "\n--- Задание 6 ---\n";
        task6_find_multiset(ms);

        cout << "\n--- Задание 7 ---\n";
        task7_for_each_multiset(ms);
        cout << "Итоговый multiset: ";
        print_multiset(ms);

    }
    catch (...) {
        cout << "Ошибка!\n";
    }
}