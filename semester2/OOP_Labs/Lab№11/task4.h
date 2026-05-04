#pragma once
#include "Time.h"
#include <queue>
using namespace std;

typedef queue<Time> QueueTime;

QueueTime make_queue(int n);
void print_queue(QueueTime q);
Time find_min_queue(QueueTime q);
Time find_max_queue(QueueTime q);
QueueTime task3_add_min_queue(QueueTime q);
QueueTime task4_delete_key_queue(QueueTime q, Time key);
QueueTime task5_add_min_max_sum_queue(QueueTime q);
void runTask4();