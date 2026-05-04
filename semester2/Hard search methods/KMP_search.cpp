//#include <iostream>
//#include <clocale>
//#include <string>
//#include <algorithm>	
//using namespace std;
//
//void lpsTable(int*& lps, int m, string pat, int n, string str)
//{
//	int len = 0;
//	for (int i = 1; i < m; i++)
//	{
//		if (pat[len] == pat[i])
//		{
//			len++;
//			lps[i] = len;
//		}
//		else if (pat[len] != pat[i] && len == 0)
//		{
//			lps[i] = 0;
//		}
//		else if (pat[len] != pat[i] && len > 0)
//		{
//			len = lps[len - 1];
//		}
//	}
//}
//void KMPsearch(const string& str, const string& pat)
//{
//	int n = str.size();
//	int m = pat.size();
//
//	int* lps = new int[m] {};
//
//	lpsTable(lps, m, pat, n, str);
//
//	int j = 0, i = 0;
//	cout << "Текст:     " << str << endl;
//	cout << "Паттерн:   " << pat << endl;
//	while (i < n)
//	{
//		if (str[i] == pat[j])
//		{
//			j++;
//			i++;
//			if (j == m)
//			{
//				cout << "Образ найден по индексу: " << i - m << endl;
//			}
//		}
//		else
//		{
//			if (j != 0)
//			{
//				j = lps[j - 1];
//			}
//			else
//			{
//				i++;
//			}
//		}
//
//	}
//	delete[] lps;
//}
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string row;
//	cout << "Введите строку: ";
//	getline(cin, row);
//	string pat;
//	cout << "Введите подстроку: ";
//	getline(cin, pat);
//	KMPsearch(row, pat);
//
//	return 0;
//}
