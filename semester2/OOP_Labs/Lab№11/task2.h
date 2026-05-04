#pragma once
#include "Time.h"
#include <list>
using namespace std;

typedef list<Time> ListTime;

ListTime make_list_time(int n);
void print_list_time(ListTime l);
Time find_min_time(ListTime l);
Time find_max_time(ListTime l);
void task3_add_min_time(ListTime& l);
bool task4_delete_key_time(ListTime& l, Time key);
void task5_add_min_max_sum_time(ListTime& l);
void runTask2();