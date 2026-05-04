#pragma once
#include "Time.h"
#include <queue>
using namespace std;

typedef queue<Time> TimeQueue;

TimeQueue make_queue(int n);
void print_queue(TimeQueue q);
Time find_min_queue(TimeQueue q);
Time find_max_queue(TimeQueue q);

void task3_replace_queue(TimeQueue& q);
void task4_remove_queue(TimeQueue& q);
void task5_sort_queue(TimeQueue& q);
void task6_find_queue(TimeQueue q);
void task7_for_each_queue(TimeQueue& q);

void runTask2();