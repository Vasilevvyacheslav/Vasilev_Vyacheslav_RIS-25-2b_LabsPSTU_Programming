//	#include <iostream>
//	#include <clocale>
//	using namespace std;
//void merge(int *arr, int *left, int lsize, int *right, int rsize)
//{
//	int i = 0;
//	int j = 0;
//	int i_arr = 0;
//	while (i < lsize && j < rsize)
//	{
//		if (left[i] <= right[j])
//		{
//			arr[i_arr++] = left[i++];
//		}
//		else
//		{
//			arr[i_arr++] = right[j++];
//		}
//	}
//	while (i < lsize)
//	{
//		arr[i_arr++] = left[i++];
//	}
//	while (j < rsize)
//	{
//		arr[i_arr++] = right[j++];
//	}
//}
//void merge_sort(int *arr, const int size)
//{
//	if (size <= 1)
//		return;
//	int mid = size / 2;
//	int* left = new int[mid];
//	int* right = new int[size - mid];
//	for (int i = 0; i < mid; i++)
//	{
//		left[i] = arr[i];
//	}
//	for (int i = 0; i < size - mid; i++)
//	{
//		right[i] = arr[i + mid];
//	}
//
//	merge_sort(left, mid);
//	merge_sort(right, size - mid);
//
//	merge(arr, left, mid, right, size - mid);
//
//	delete[] left;
//	delete[] right;
//}
//
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int size;
//	cout << "Введите размер массива: ";
//	cin >> size;
//	int* arr = new int[size];
//	cout << "\nВведите массив чисел: ";
//	for (int i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//	merge_sort(arr, size);
//	cout << "\nОтсортированный массив: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	delete[] arr;
//}