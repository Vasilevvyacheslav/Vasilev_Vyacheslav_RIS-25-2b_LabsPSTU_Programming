#include "Vector.h"
using namespace std;

Vector::Vector(int size, int k)
{
	this->size = size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}
Vector::Vector(const Vector& other)
{
	size = other.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
	beg = other.beg;
	end = other.end;
}
Vector::~Vector()
{
	delete[] data;
	data = nullptr;
}

Vector& Vector:: operator =(const Vector& other)
{
	if (this != &other)
	{
		size = other.size;
		if (data != 0)
			delete[]data;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
		beg = other.beg;
		end = other.end;
	}
	return *this;
}


int& Vector:: operator [](int index)
{
	if (index < size)
		return data[index];
	else
		cout << "\nError! Index > size";
	return data[0];
}


Vector Vector:: operator +(const Vector& other)
{
	if (size != other.size)
	{
		cout << "Error: vector sizes must be equal!" << endl;
	}
	Vector temp(size);
	for (int i = 0; i < size; i++)
	{
		temp.data[i] = data[i] + other.data[i];
	}
	return temp;

}

int Vector:: operator()()
{
	return size;
}

istream& operator >>(istream& in, Vector& other)
{
	for (int i = 0; i < other.size; ++i)
	{
		in >> other.data[i];
	}
	return in;
}
ostream& operator <<(ostream& out, const Vector& other)
{
	for (int i = 0; i < other.size; ++i)
	{
		out << other.data[i] << ' ';
	}
	return out;
}