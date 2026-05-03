#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int min;
    int sec;
public:
    Time();
    Time(int m, int s);
    Time(const Time& other);
    ~Time();

    int getMin() const { return min; }
    int getSec() const { return sec; }

    void normalize_time();

    Time& operator=(const Time& other);
    bool operator==(const Time& other);
    bool operator!=(const Time& other);
    bool operator<(const Time& other);
    bool operator>(const Time& other);
    Time operator-(const Time& other);
    Time operator+(const Time& other);

    friend istream& operator >>(istream& in, Time& t);
    friend ostream& operator <<(ostream& out, const Time& t);
};
