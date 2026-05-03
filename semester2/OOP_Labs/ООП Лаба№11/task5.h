#pragma once
#include "Time.h"
#include <iostream>
using namespace std;

template <typename T>
class VectorQueue 
{
private:
    T* data;
    int size;

public:
    VectorQueue(int s = 0);
    ~VectorQueue();

    void fill_random();
    void print();
    T find_min();
    T find_max();

    void task3_add_min();
    bool task4_delete_key(T key);
    void task5_add_min_max_sum();
};

void runTask5();