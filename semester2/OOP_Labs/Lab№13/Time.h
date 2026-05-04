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
    void setMin(int m) { min = m; }
    void setSec(int s) { sec = s; }

    void normalize_time();

    Time& operator=(const Time& other);
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    Time operator-(const Time& other) const;
    Time operator+(const Time& other) const;

    friend istream& operator >>(istream& in, Time& t);
    friend ostream& operator <<(ostream& out, const Time& t);
};