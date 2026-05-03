#pragma once
#include "Time.h"
#include <set>
using namespace std;

typedef set<Time> TimeSet;

TimeSet make_time_set(int n);
void print_time_set(TimeSet s);
Time find_min_time(TimeSet s);
Time find_max_time(TimeSet s);
void task3_add_min_time(TimeSet& s);
bool task4_delete_key_time(TimeSet& s, Time key);
void task5_add_min_max_sum_time(set<Time>& s);
void runTask2();