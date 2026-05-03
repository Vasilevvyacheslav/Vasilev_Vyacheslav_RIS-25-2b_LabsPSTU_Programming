#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector
{
public:

	Vector(int size, T k = T());
	Vector(const Vector<T>& other);
	~Vector();

	Vector& operator =(const Vector<T>& other);
	T& operator [](int index);
	Vector operator +(const Vector<T>& other);
	int operator()();

	friend istream& operator >> <T>(istream& in, Vector<T>&);
	friend ostream& operator << <T>(ostream& out, const Vector<T>&);

private:
	int size;
	T* data;
};

template <typename T>
Vector<T>::Vector(int size, T k)
{
	this->size = size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	size = other.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] data;
	data = nullptr;
}

template <typename T>
Vector<T>& Vector<T>:: operator =(const Vector<T>& other)
{
	if (this != &other)
	{
		size = other.size;
		if (data != 0)
			delete[]data;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	return *this;
}

template <typename T>
T& Vector<T>:: operator [](int index)
{
	if (index < size)
		return data[index];
	else
		cout << "\nError! Index > size";
	return data[0];
}

template <typename T>
Vector<T> Vector<T>:: operator +(const Vector<T>& other)
{
	if (size != other.size)
	{
		cout << "Error: vector sizes must be equal!" << endl;
	}
	Vector<T> temp(size);
	for (int i = 0; i < size; i++)
	{
		temp.data[i] = data[i] + other.data[i];
	}
	return temp;

}

template <typename T>
int Vector<T>:: operator()()
{
	return size;
}

template <typename T>
istream& operator >> (istream& in, Vector<T>& other)
{
	for (int i = 0; i < other.size; ++i)
	{
		in >> other.data[i];
	}
	return in;
}

template <typename T>
ostream& operator << (ostream& out, const Vector<T>& other)
{
	for (int i = 0; i < other.size; ++i)
	{
		out << other.data[i] << ' ';
	}
	return out;
}
