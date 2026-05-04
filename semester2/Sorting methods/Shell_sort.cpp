//#include <iostream>
//#include <clocale>
//#include <algorithm>
//using namespace std;
//
//void Shell_sort(int* arr, int size)
//{
//	for (int step = size / 2; step > 0; step /= 2)
//	{
//		for (int i = step; i < size; i++)
//		{
//			for (int j = i; j >= step && arr[j - step] > arr[j]; j -= step)
//			{
//				swap(arr[j], arr[j - step]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int size;
//	cout << "Введите размер массива: ";
//	cin >> size;
//	if (size <= 1)
//	{
//		cout << "Размер массива должен быть больше 1!" << endl;
//		return 1;
//	}
//	int* arr = new int[size];
//	cout << "\nВведите массив чисел: ";
//	for (int i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//	Shell_sort(arr, size);
//	cout << "\nОтсортированный массив: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	delete[] arr;
//}