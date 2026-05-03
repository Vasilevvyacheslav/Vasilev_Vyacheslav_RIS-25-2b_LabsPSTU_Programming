#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <iomanip>
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

	int getMin() { return min; }
	int getSec() { return sec; }

	Time& operator = (const Time&);
	bool operator ==(const Time&);
	bool operator !=(const Time&);
	Time operator -(const Time&);
	friend istream& operator >>(istream& in, Time&);
	friend ostream& operator <<(ostream& out, const Time&);

	friend fstream& operator >>(fstream& fin, Time&);
	friend fstream& operator <<(fstream& fout, const Time&);
}; 