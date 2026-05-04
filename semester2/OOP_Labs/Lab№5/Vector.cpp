#include "Vector.h"

Vector::Vector() : head(nullptr), size(0), cur(0) {}
Vector::~Vector()
{
	if (head != nullptr)
	{
		delete[] head;
	}
	head = 0;
}
Vector::Vector(int size) : head(new Object* [size]), cur(0), size(size) {}
void Vector::Add(Object* p)
{
	if (cur < size)
	{
		head[cur] = p;
		cur++;
	}
}
ostream& operator <<(ostream& out, const Vector& v)
{
	if (v.size == 0)
	{
		out << "Empty" << endl;
		return out;
	}
	Object** p = v.head;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}
