#include "Rectangle.h"

Rectangle::Rectangle() : Pair() {}

Rectangle::Rectangle(int length, int width) : Pair(length, width) {}

Rectangle::Rectangle(const Rectangle& other) : Pair(other) {}

Rectangle::~Rectangle() {}

int Rectangle::area()
{
	return first * second;
}
int Rectangle::perimetr()
{
	return 2 * (first + second);
}
istream& operator >>(istream& in, Rectangle& other)
{
	cout << "Введите длину: "; in >> other.first;
	cout << "Введите ширину: "; in >> other.second;
	return in;
}
ostream& operator <<(ostream& out, Rectangle& other)
{
	out << "Длина: " << other.first << endl;
	out << "Ширина: " << other.second << endl;
	out << "Площадь: " << other.area() << endl;
	out << "Периметр: " << other.perimetr() << endl;
	return out;
}
