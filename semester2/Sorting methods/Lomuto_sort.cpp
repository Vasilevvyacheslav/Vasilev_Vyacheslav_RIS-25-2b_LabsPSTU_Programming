//#include <iostream>
//#include <algorithm>
//#include <clocale>
//using namespace std;
//
//void ShowArr(int* arr, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//}
//void quickSortLomuto(int *arr,int low, int high)
//{
//	if (low >= high)
//		return;
//	int pivot = arr[high];
//	int i = low;
//
//	for (int j = low; j < high; j++)
//	{
//		if (arr[j] <= pivot)
//		{
//			swap(arr[i], arr[j]);
//			i++;
//		}
//	}
//	swap(arr[i], arr[high]);
//	quickSortLomuto(arr, low, i - 1);
//	
//	quickSortLomuto(arr, i + 1, high);
//}
//void Lomuto_sort(int* arr, int size)
//{
//	quickSortLomuto(arr, 0, size - 1);
//	return;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int size;
//	cout << "Введите размер массива: ";
//	cin >> size;
//	if (size < 1)
//	{
//		cout << "Размер массива должен быть больше 0!" << endl;
//		return 1;
//	}
//	int* arr = new int[size];
//	cout << "\nВведите массив чисел: ";
//	for (int i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//	Lomuto_sort(arr, size);
//	cout << "\nОтсортированный массив: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	delete[] arr;
//}