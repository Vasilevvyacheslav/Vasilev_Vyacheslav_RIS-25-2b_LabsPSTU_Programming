//#include <iostream>
//#include <clocale>
//using namespace std;
//
//bool InterPolSearch(const int n, int arr[], int key, int& i_key)
//{
//	int left = 0;
//	int right = n - 1;
//	int middle = 0;
//	while (left <= right)
//	{
//		int middle = left + (((key - arr[left]) * (right - left)) / (arr[right] - arr[left]));
//		if (arr[middle] == key)
//		{
//			i_key = middle + 1;
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
//		return 0;
//}
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	const int n = 10; 
//	int arr[n] = { 1, 4, 7 , 10, 13, 17, 20, 23, 27, 30 };
//	int i_key = 1;
//	cout << "Изначальный массив: ";
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	int key;
//	cout << "\nВведите число, которое вы ищите в массиве: ";
//	cin >> key;
//	if (InterPolSearch(n, arr, key, i_key))
//	{
//		cout << "Число " << key << " есть в массиве, его номер " << i_key << endl;
//	}
//	else
//	{
//		cout << "Числа " << key << " нет в массиве!" << endl;
//	}
//	return 0;
//}