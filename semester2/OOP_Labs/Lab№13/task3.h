#pragma once
#include "Time.h"
#include <set>
using namespace std;

typedef multiset<Time> TimeMultiset;

TimeMultiset make_multiset(int n);
void print_multiset(TimeMultiset ms);
Time find_min_multiset(TimeMultiset ms);
Time find_max_multiset(TimeMultiset ms);

void task3_replace_multiset(TimeMultiset& ms);
void task4_remove_multiset(TimeMultiset& ms);
void task5_sort_multiset(TimeMultiset& ms);
void task6_find_multiset(TimeMultiset ms);
void task7_for_each_multiset(TimeMultiset& ms);

void runTask3();