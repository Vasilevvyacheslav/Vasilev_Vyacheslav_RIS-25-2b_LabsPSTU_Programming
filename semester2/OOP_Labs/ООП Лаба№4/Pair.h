#pragma once
#include <iostream>
#include <clocale>
using namespace std;

class Pair
{
public:

	Pair();
	Pair(int first, int second);
	Pair(const Pair& other);
	~Pair();

	int GetFirst();
	int GetSecond();
	void SetFirst(int first);
	void SetSecond(int second);

	Pair& operator =(const Pair&);
	friend istream& operator >>(istream& in, Pair&);
	friend ostream& operator <<(ostream& out, Pair&);

	int product();

protected:
	int first;
	int second;
};
