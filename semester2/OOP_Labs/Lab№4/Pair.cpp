#include "Pair.h"


Pair::Pair() : first(0), second(0) {}
Pair::Pair(int f, int s) : first(f), second(s) {}
Pair::Pair(const Pair& other) : first(other.first), second(other.second) {}
Pair::~Pair() {}


int Pair::GetFirst()
{
	return first;
}
int Pair::GetSecond()
{
	return second;
}
void Pair::SetFirst(int first)
{
	this->first = first;
}
void Pair::SetSecond(int second)
{
	this->second = second;
}


Pair& Pair::operator =(const Pair& other)
{
	if (&other != this)
	{
		first = other.first;
		second = other.second;
	}

	return *this;
}
istream& operator >>(istream& in, Pair& other)
{
	cout << "Введите первое число: "; in >> other.first;
	cout << "\nВведите второе число: "; in >> other.second;
	return in;
}
ostream& operator <<(ostream& out, Pair& other)
{
	out << "Первое число: " << other.first << endl;
	out << "Второе число: " << other.second << endl;
	return out;
}
int Pair::product()
{
	return first * second;
}

