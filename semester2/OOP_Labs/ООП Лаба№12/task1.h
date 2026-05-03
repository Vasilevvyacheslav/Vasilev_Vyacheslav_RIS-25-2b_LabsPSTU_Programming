#pragma once
#include <set>
using namespace std;

typedef set<float> FloatSet;

FloatSet make_set(int n);
void print_set(FloatSet s);
float find_min(FloatSet s);
float find_max(FloatSet s);
void task3_add_min(FloatSet& s);
bool task4_delete_key(FloatSet& s, float key);
void task5_add_min_max_sum(set<float>& s);
void runTask1();