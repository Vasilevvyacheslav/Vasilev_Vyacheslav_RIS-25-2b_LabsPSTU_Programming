//#include <iostream>
//#include <clocale>
//#include <algorithm>	
//#include <string>
//#include <iomanip>
//using namespace std;
//
//void badCharTable(int CharTable[256], int size, string pattern)
//{
//	for (int i = 0; i < 256; i++)
//		CharTable[i] = -1;
//
//	for (int i = 0; i < size; i++)
//		CharTable[(int)pattern[i]] = i;
//}
//int boyerMooreSearch(const string& str, const string& pattern)
//{
//	int n = str.length();
//	int m = pattern.length();
//	if (m == 0)
//	{
//		cout << "Длина подстроки должна быть больше 0!" << endl;
//		return -1;
//	}
//	if (m > n)
//	{
//		cout << "подстрока должен быть меньше строки!" << endl;
//		return -1;
//	}
//	int CharTable[256];
//
//	badCharTable(CharTable, m, pattern);
//
//	int s = 0;
//	
//	while (s <= (n - m))
//	{
//		int j = m - 1;
//		cout << "Текст:     " << str << endl;
//		cout << "Паттерн:   " << setw(s + j + 1) << pattern << endl;
//		
//		while (j >= 0 && pattern[j] == str[s + j])
//			j--;
//		if (j < 0)
//		{
//			return s;
//		}
//		else
//		{
//			s += max(1, j - CharTable[str[s + j]]);
//		}
//	}
//
//	return -1;
//}
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string row;
//	cout << "Введите строку: ";
//	getline(cin, row);
//	string pattern;
//	cout << "Введите подстроку: ";
//	getline(cin, pattern);
//	cout << "Текст:     " << row << endl;
//	cout << "Паттерн:   " << pattern << endl;
//	int pos = boyerMooreSearch(row, pattern);
//	if (pos >= 0)
//	{
//		cout << "Подстрока есть в строке, она начинается с индекса " << pos << endl;
//	}
//	else
//	{
//		cout << "Подстроки нет в строке" << endl;
//	}
//	return 0;
//}
