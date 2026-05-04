#pragma once
#include <iostream>
#include <clocale>
#include <string>
using namespace std;

class Book
{
private:
	string name;
	string author;
	int date;
public:
	Book();
	Book(string, string, int);
	Book(const Book&);
	~Book();

	string getName();
	void setName(string);

	string getAuthor();
	void setAuthor(string);

	int getDate();
	void setDate(int);

	void Show();
};