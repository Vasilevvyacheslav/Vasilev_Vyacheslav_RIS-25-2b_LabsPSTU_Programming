#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class Vector;
public:

	Iterator()
	{
		elem = 0;
	}
	Iterator(const Iterator& other)
	{
		elem = other.elem;
	}


	bool operator ==(const Iterator& other)
	{
		return elem == other.elem;
	}
	bool operator !=(const Iterator& other)
	{
		return !(elem == other.elem);
	}


	Iterator& operator++()
	{
		++elem;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator temp(*this);
		++elem;
		return temp;
	}
	Iterator& operator+=(int n)
	{
		elem += n;
		return *this;
	}
	Iterator operator+(int n) const
	{
		Iterator temp(*this);
		temp.elem += n;
		return temp;
	}

	int& operator *() const
	{
		return*elem;
	}

private:
	int* elem;
};

class Vector
{
public:

	Vector(int size, int k = 0);
	Vector(const Vector& other);
	~Vector();

	Vector& operator =(const Vector& other);
	int& operator [](int index);
	Vector operator +(const Vector& other);
	int operator()();

	friend istream& operator >>(istream& in, Vector&);
	friend ostream& operator <<(ostream& out, const Vector&);

	Iterator first()
	{
		return beg;
	}
	Iterator last()
	{
		return end;
	}

private:

	int size;
	int* data;
	Iterator beg;
	Iterator end;
};

