#include "fraction.h"

void fraction::Init(int f, int s)
{
	first = f;
	second = s;
}
void fraction::Read()
{
	cout << "Введите номинал купюры: "; cin >> first;
	cout << "Введите кол-во купюр: "; cin >> second;
}
void fraction::Show()
{
	cout << "\nНоминал купюры = " << first;
	cout << "\nКол-во купюр = " << second;
	cout << "\n\n";
}
int fraction::summa()
{
	return first * second;
}