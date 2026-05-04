#include "Book.h"

Book::Book()
{
	name = "";
	author = "";
	date = 0;
	cout << "Вызвался конструктор без параметров " << this << endl;
}
Book::Book(string name, string author, int date)
{
	this->name = name;
	this->author = author;
	this->date = date;
	cout << "\nВызвался конструктор с параметрами " << this << endl;
}
Book::Book(const Book& other)
{
	name = other.name;
	author = other.author;
	date = other.date;
	cout << "\nВызвался конструктор копирования " << this << endl;
}
Book::~Book()
{
	cout << "\nВызвался деструктор " << this << endl;
}
string Book::getName()
{
	return name;
}
void Book::setName(string name)
{
	this->name = name;
}
string Book::getAuthor()
{
	return name;
}
void Book::setAuthor(string author)
{
	this->author = author;
}
int Book::getDate()
{
	return date;
}
void Book::setDate(int date)
{
	this->date = date;
}
void Book::Show()
{
	cout << "\nНазвание книги: " << name;
	cout << "\nАвтор книги: " << author;
	cout << "\nГод издания книги: " << date << endl;
}