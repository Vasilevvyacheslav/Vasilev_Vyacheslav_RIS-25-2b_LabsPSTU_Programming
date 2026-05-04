#pragma once
#include "Time.h"
#include <list>
#include <algorithm>
using namespace std;

typedef list<Time> TimeList;

TimeList make_list(int n);
void print_list(TimeList l);
Time find_min_list(TimeList l);
Time find_max_list(TimeList l);

void task3_replace(TimeList& l);
void task4_remove(TimeList& l);
void task5_sort(TimeList& l);
void task6_find(TimeList l);
void task7_for_each(TimeList& l);
void runTask1();