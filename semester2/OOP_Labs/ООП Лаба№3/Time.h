#pragma once
#include <iostream>
#include <clocale>
using namespace std;

class Time {
	int min;
	int sec;
public:

	Time() { min = 0; sec = 0; }
	Time(int min, int sec) { normalize_time(); }
	Time(const Time& t) 
	{ 
		min = t.min; sec = t.sec;
		normalize_time();
	}
	~Time() {};

	int getMin() { return min; }
	void setMin(int min) 
	{ 
		this->min = min;
		normalize_time();
	}
	int getSec() { return sec; }
	void setSec(int sec) 
	{
		this->sec = sec;
		normalize_time();
	}

	void normalize_time();
	Time& operator = (const Time&);
	bool operator !=(const Time&);
	Time operator -(const Time&);
	friend istream& operator >>(istream& in, Time&);
	friend ostream& operator <<(ostream& out, const Time&);
};