#include "fraction.h"

fraction make_fraction(int f, int s)
{
	fraction t;
	t.Init(f, s);
	return t;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "1.Инициализация через Init(500, 2): " << endl;
	fraction a;
	a.Init(500, 2);
	a.Show();
	cout << "a.summa(" << a.first << "," << a.second << ") = " << a.summa() << endl;
	cout << "--------------------------------------" << endl;

	cout << "2.Инициализация через Read(): " << endl;
	fraction b;
	b.Read();
	b.Show();
	cout << "b.summa(" << b.first << "," << b.second << ") = " << b.summa() << endl;
	cout << "--------------------------------------" << endl;

	cout << "3.Инициализация через указатели: " << endl;
	fraction* x = new fraction;
	x->Init(50, 6);
	x->Show();
	cout << "x.summa(" << x->first << "," << x->second << ") = " << x->summa() << endl;
	delete x;
	cout << "--------------------------------------" << endl;

	cout << "4.Инициализация через статический массив: " << endl;
	const int size = 2;
	fraction mas[size]{};
	for (int i = 0; i < size; i++)
	{
		mas[i].Read();
	}
	for (int i = 0; i < size; i++)
	{
		mas[i].Show();
	}
	for (int i = 0; i < size; i++)
	{
		cout << "mas[" << i << "].summa(" << mas[i].first << ", " << mas[i].second << ") = " << mas[i].summa() << endl;
	}
	cout << "--------------------------------------" << endl;

	cout << "5.Инициализация через динамический массив: " << endl;
	cout << "Введите кол-во операций подсчёта: ";
	int S;
	cin >> S;
	fraction* m = new fraction[S];
	for (int i = 0; i < S; i++)
	{
		m[i].Read();
	}
	for (int i = 0; i < S; i++)
	{
		m[i].Show();
	}
	for (int i = 0; i < S; i++)
	{
		cout << "m[" << i << "].summa(" << m[i].first << ", " << m[i].second << ") = " << m[i].summa() << endl;
	}
	delete[] m;
	cout << "--------------------------------------" << endl;

	cout << "6.Инициализация через функцию make_fraction: " << endl;
	int X, Y;
	cout << "Введите номинал купюры: "; cin >> X;
	cout << "Введите кол-во купюр: "; cin >> Y;
	fraction F = make_fraction(X, Y);
	F.Show();
	cout << "F.summa(" << F.first << ", " << F.second << ") = " << F.summa() << endl;
	cout << "--------------------------------------" << endl;
	return 0;
}