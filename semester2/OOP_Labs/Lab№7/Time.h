#pragma once
#include <iostream>
#include <clocale>
using namespace std;

class Time {
private:
	int min;
	int sec;
public:
	Time(); 
	Time(int min, int sec);
	Time(const Time& t);
	~Time();
	void normalize_time();
	Time& operator =(const Time&);
	Time operator +(const Time&);
	Time operator -(const Time&);
	friend istream& operator >>(istream& in, Time&);
	friend ostream& operator <<(ostream& out, const Time&);
};