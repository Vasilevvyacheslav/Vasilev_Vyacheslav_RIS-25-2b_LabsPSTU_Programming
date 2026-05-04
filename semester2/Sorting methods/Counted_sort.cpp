#include <iostream>
#include <clocale>
using namespace std;
int Max(int* arr, const int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
int Min(int* arr, const int size)
{
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
void Counted_sort(int* arr, const int size)
{
	int max = Max(arr, size);
	int min = Min(arr, size);
	int s = max - min + 1;
	int* count = new int[s] {};
	for (int i = 0; i < size; i++)
	{
		count[arr[i] - min]++;
	}
	int ind = 0;
	for (int i = 0; i < s; i++)
	{
		while (count[i] > 0)
		{
			arr[ind] = i + min;
			ind++;
			count[i]--;
		}
	}
	delete[] count;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	int* arr = new int[size];
	cout << "\nВведите массив чисел: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	Counted_sort(arr, size);
	cout << "\nОтсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	delete[] arr;
}