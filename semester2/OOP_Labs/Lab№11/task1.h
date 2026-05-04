#pragma once
#include <list>
using namespace std;

typedef list<float> List;

List make_list(int n);
void print_list(List l);
float find_min(List l);
float find_max(List l);
void task3_add_min(List& l);
bool task4_delete_key(List& l, float key);
void task5_add_min_max_sum(List& l);
void runTask1();