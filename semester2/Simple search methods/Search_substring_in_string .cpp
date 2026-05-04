//#include <iostream>
//#include <string>
//#include <clocale>
//#include <iomanip>
//using namespace std;
//
//int Substr_in_str(string str, string substr)
//{
//	int i = 0, j = 0, count = 0, index = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == substr[j])
//		{
//			count++;
//			j++;
//			if (count == 1)
//			{
//				index = i;
//			}
//			if (count == substr.size())
//			{
//				return index;
//			}
//		}
//		else
//		{
//			count = 0;
//			j = 0;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string str, substr;
//	cout << "Введите строку: ";
//	cin >> str;
//	cout << "Введите подстроку: ";
//	cin >> substr;
//	int index = Substr_in_str(str, substr);
//	bool f = false;
//	for (int i = 0; i < str.size() - substr.size() + 1 && !f; i++)
//	{
//		if (i == index)
//		{
//			f = true;
//		}
//		cout << "\nСтрока:    " << str;
//		cout << "\nПодстрока: " << setw(i + substr.size()) << substr << endl;
//	}
//	if (index >= 0)
//	{
//		cout << "Подстрока есть в строке" << endl;
//	}
//	else
//	{
//		cout << "Подстроки нет в строке" << endl;
//	}
//	return 0;
//}