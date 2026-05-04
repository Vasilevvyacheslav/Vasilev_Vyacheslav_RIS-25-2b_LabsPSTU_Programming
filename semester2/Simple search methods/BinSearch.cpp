//#include <iostream>
//#include <clocale>
//using namespace std;
//
//bool BinSearch(const int n, int arr[], int key, int& i)
//{
//	int left = 0;
//	int right = n - 1;
//	int middle = 0;
//	while (left <= right)
//	{
//		int middle = (left + right) / 2;
//		if (arr[middle] == key)
//		{
//			i = middle + 1;
//			return 1;
//		}
//		else
//		{
//			if (arr[middle] < key)
//			{
//				left = middle + 1;
//			}
//			else
//			{
//				right = middle - 1;
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	const int n = 10; 
//	int arr[n] = { 1, 4, 7 , 10, 13, 17, 20, 23, 27, 30 };
//	int i = 1;
//	cout << "Изначальный массив: ";
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	int key;
//	cout << "\nВведите число, которое вы ищите в массиве: ";
//	cin >> key;
//	if (BinSearch(n, arr, key, i))
//	{
//		cout << "Число " << key << " есть в массиве, его номер " << i << endl;
//	}
//	else
//	{
//		cout << "Числа " << key << " нет в массиве!" << endl;
//	}
//	return 0;
//}