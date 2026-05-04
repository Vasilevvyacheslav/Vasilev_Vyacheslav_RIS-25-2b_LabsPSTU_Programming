//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void quickSortHoare(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//	int i = left;
//	int j = right;
//	int pivot = arr[(i+j)/2];
//
//	while (i <= j)
//	{
//		while (arr[i] < pivot)
//		{
//			i++;
//		}
//		while (arr[j] > pivot)
//		{
//			j--;
//		}
//		if (i <= j)
//		{
//			swap(arr[i], arr[j]);
//			i++;
//			j--;
//		}
//	}
//	if(left < j) quickSortHoare(arr, left, j);
//	if(right > i) quickSortHoare(arr, i, right);
//	return;
//}
//void Hoare_sort(int* arr, int size)
//{
//	quickSortHoare(arr, 0, size - 1);
//	return;
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
//	Hoare_sort(arr, size);
//	cout << "\nОтсортированный массив: ";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	delete[] arr;
//}