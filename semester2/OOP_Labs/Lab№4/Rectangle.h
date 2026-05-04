#pragma once
#include "Pair.h"
class Rectangle : public Pair
{
public:
	Rectangle();
	Rectangle(int length, int width);
	Rectangle(const Rectangle& other);
	~Rectangle();

	int area();
	int perimetr();

	friend istream& operator >>(istream& in, Rectangle&);
	friend ostream& operator <<(ostream& out, Rectangle&);
};

