#pragma once
#include <iostream>
#include <clocale>
using namespace std;

struct fraction
{
	int first;
	int second;
	void Init(int first, int second);
	void Read();
	void Show();
	int summa();
};