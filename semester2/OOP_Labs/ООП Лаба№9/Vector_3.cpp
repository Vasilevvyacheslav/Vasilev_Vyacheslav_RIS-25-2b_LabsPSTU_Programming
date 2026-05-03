#include "Vector_3.h"
#include "error_3.h"
using namespace std;

namespace Version3 {
    Vector::Vector() { size = 0; head = nullptr; }

    Vector::Vector(int s)
    {
        if (s > MAX_SIZE) throw MaxSizeError();
        size = s;
        head = new int[s];
        for (int i = 0; i < size; i++)
            head[i] = 0;
    }
    Vector::Vector(int s, int* mas)
    {
        if (s > MAX_SIZE) throw MaxSizeError();
        size = s;
        head = new int[s];
        for (int i = 0; i < size; i++)
            head[i] = mas[i];
    }
    Vector::Vector(const Vector& other)
    {
        size = other.size;
        head = new int[size];
        for (int i = 0; i < size; i++)
            head[i] = other.head[i];
    }
    Vector::~Vector()
    {
        if (head != 0) delete[] head;
    }
    Vector& Vector::operator=(const Vector& other)
    {
        if (this != &other)
        {
            if (head != 0)
                delete[]head;
            size = other.size;
            head = new int[size];
            for (int i = 0; i < size; i++)
            {
                head[i] = other.head[i];
            }
        }
        return *this;
    }
    int& Vector::operator[](int index)
    {
        if (index < 0) throw IndexError1();
        if (index >= size) throw IndexError2();
        return head[index];
    }
    int Vector::operator()()
    {
        return size;
    }
    Vector Vector::operator+(int n)
    {
        if (size + n == MAX_SIZE) throw MaxSizeError();
        Vector temp(size + n);
        for (int i = 0; i < size; i++)
        {
            temp.head[i] = head[i];
        }
        return temp;
    }

    Vector Vector::operator-(int n)
    {
        if (n < 0) throw InvalidArgumentError();
        if (n > size) throw SizeMismatchError();

        Vector temp(size - n);
        for (int i = 0; i < size - n; i++)
        {
            temp.head[i] = head[i];
        }
        return temp;
    }

    ostream& operator<<(ostream& out, const Vector& other)
    {
        for (int i = 0; i < other.size; i++)
        {
            out << other.head[i] << ' ';
        }
        return out;
    }

    istream& operator>>(istream& in, Vector& other)
    {
        for (int i = 0; i < other.size; i++)
        {
            in >> other.head[i];
        }
        return in;
    }
}