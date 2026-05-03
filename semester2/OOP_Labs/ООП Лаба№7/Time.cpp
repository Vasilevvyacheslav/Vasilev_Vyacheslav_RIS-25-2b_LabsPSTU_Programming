#include "Time.h"
#include <iomanip> 

Time::Time() { min = sec = 0; }

Time::Time(int min, int sec)
{
	normalize_time();
}
Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
	normalize_time();
}
Time::~Time() {};

void Time::normalize_time()
{
	min += sec / 60;
	sec = sec % 60;
	min = min % 60;
}
Time& Time:: operator = (const Time& other)
{
	if (&other != this)
	{
		min = other.min;
		sec = other.sec;
		normalize_time();
	}
	return *this;
}

Time Time:: operator +(const Time& other)
{
	Time temp;
	temp.min = min + other.min;
	temp.sec = sec + other.sec;
	temp.normalize_time();
	return temp;
}

istream& operator >>(istream& in, Time& other)
{
	cout << "\nВведите минуты: "; in >> other.min;
	cout << "Введите секунды: "; in >> other.sec;
	cout << endl;
	other.normalize_time();
	return in;
}

ostream& operator <<(ostream& out, const Time& other)
{
	out << setw(2) << setfill('0') << other.min
		<< ":"
		<< setw(2) << setfill('0') << other.sec;
	return out;
}
