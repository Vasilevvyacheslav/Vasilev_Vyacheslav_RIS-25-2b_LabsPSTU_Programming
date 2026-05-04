#pragma once
#include <iostream>
#include <string>
using namespace std;


namespace Version2 {

	const int MAX_SIZE = 30;

	class Vector
	{
	private:
		int size;
		int* head;
	public:
		Vector();
		Vector(int s);
		Vector(int s, int* mas);
		Vector(const Vector& other);
		~Vector();
		Vector& operator =(const Vector& other);
		int& operator [](int index);
		int operator()();
		Vector operator +(int n);
		Vector operator -(int n);

		friend ostream& operator <<(ostream& out, const Vector& other);
		friend istream& operator >>(istream& in, Vector& other);
	};
}
