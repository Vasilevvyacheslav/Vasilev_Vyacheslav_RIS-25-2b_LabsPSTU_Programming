#include "Time.h"

Time::Time() { min = 0, sec = 0; }
Time::Time(int min, int sec)
{
	this->min = min;
	this->sec = sec;
	normalize_time();
}
Time::Time(const Time& other)
{
	min = other.min, sec = other.sec;
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
bool Time:: operator ==(const Time& other) const
{
	return (min == other.min && sec == other.sec);
}
bool Time:: operator !=(const Time& other) const
{
	return !(min == other.min && sec == other.sec);
}
bool Time::operator<(const Time& other) const
{
	return (min * 60 + sec) < (other.min * 60 + other.sec);
}
bool Time::operator>(const Time& other) const
{
	return (min * 60 + sec) > (other.min * 60 + other.sec);
}
Time Time:: operator +(const Time& other) const
{
	Time temp;
	temp.min = min + other.min;
	temp.sec = sec + other.sec;
	temp.normalize_time();
	return temp;
}
Time Time:: operator -(const Time& other) const
{
	Time temp;
	temp.min = min - other.min;
	temp.sec = sec - other.sec;
	temp.normalize_time();
	return temp;
}
istream& operator >>(istream& in, Time& other)
{
	cout << "\nВведите минуты: "; in >> other.min;
	cout << "Введите секунды: "; in >> other.sec;
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
