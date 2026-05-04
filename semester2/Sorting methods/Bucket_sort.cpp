	//#include <iostream>
	//#include <clocale>
	//#include <algorithm>
	//using namespace std;
	//
	//struct Node
	//{
	//	int data;
	//	Node* next;
	//};
	//struct List
	//{
	//	Node* head_node = nullptr;
	//	int size = 0;
	//};
	//void ShowArr(int* arr, int size)
	//{
	//	for (int i = 0; i < size; i++)
	//	{
	//		cout << "Корзина №" << i <<": " << arr[i] << ' ';
	//	}
	//	cout << endl;
	//}
	//void push_front(List& list, int value)
	//{
	//	Node* new_node = new Node;
	//	new_node->data = value;
	//	new_node->next = list.head_node;
	//	list.head_node = new_node;
	//	list.size++;
	//}
	//int GetBucketIndex(int value, int size, int min, int max)
	//{
	//	if (min == max)
	//		return 0;
	//	return (int)(((value - min) * size) / (max - min + 1));
	//}
	//void SortArr(int *arr, int size)
	//{
	//	for (int i = 1; i < size; i++)
	//	{
	//		for (int j = i; j > 0 && arr[j-1] > arr[j]; j--)
	//		{
	//			swap(arr[j], arr[j - 1]);
	//		}
	//	}
	//	ShowArr(arr, size);
	//}
	//void BucketSort(List* buckets, int numBuckets, int* arr)
	//{
	//	for (int i = 0; i < numBuckets; i++)
	//	{
	//		if (buckets[i].head_node == nullptr)
	//		{
	//			continue;
	//		}
	//		else
	//		{
	//			int* temp = new int[buckets[i].size];
	//			Node* current_node = buckets[i].head_node;
	//			int ind = 0;
	//
	//			while (current_node != nullptr)
	//			{
	//				temp[ind++] = current_node->data;
	//				current_node = current_node->next;
	//			}
	//
	//			SortArr(temp, buckets[i].size);
	//
	//			current_node = buckets[i].head_node;
	//			ind = 0;
	//			while (current_node != nullptr)
	//			{
	//				current_node->data = temp[ind++];
	//				current_node = current_node->next;
	//			}
	//			delete[] temp;
	//		}
	//	}
	//	int index = 0;
	//	for (int i = 0; i < numBuckets; i++)
	//	{
	//		Node* current_node = buckets[i].head_node;
	//		while (current_node != nullptr)
	//		{
	//			arr[index++] = current_node->data;
	//			current_node = current_node->next;
	//		}
	//	}
	//}
	//void ClearList(List* buckets, int numBuckets)
	//{
	//	for (int i = 0; i < numBuckets; i++)
	//	{
	//		Node* current_node = buckets[i].head_node;
	//		while (current_node != nullptr)
	//		{
	//			Node* next_node = current_node->next;
	//			delete current_node;
	//			current_node = next_node;
	//		}
	//	}
	//	delete[] buckets;
	//}
	//void CreateBuckets(int* arr, int size)
	//{
	//	int min = arr[0];
	//	int max = arr[0];
	//	for (int i = 1; i < size; i++)
	//	{
	//		if (arr[i] > max)
	//			max = arr[i];
	//		if (arr[i] < min)
	//			min = arr[i];
	//	}
	//	if (min == max)
	//		return;
	//	int numBuckets = size;
	//	List* buckets = new List[numBuckets]{};
	//	for (int i = 0; i < size; i++)
	//	{
	//		int ind = GetBucketIndex(arr[i], numBuckets, min, max);
	//		push_front(buckets[ind], arr[i]);
	//	}
	//	BucketSort(buckets, numBuckets, arr);
	//	ClearList(buckets, numBuckets);
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
	//	CreateBuckets(arr, size);
	//	cout << "\nОтсортированный массив: ";
	//	for (int i = 0; i < size; i++)
	//	{
	//		cout << arr[i] << ' ';
	//	}
	//
	//	delete[] arr;
	//}