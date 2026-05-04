//#include <iostream>
//#include <clocale>
//#include <string>
//#include <fstream>
//using namespace std;
//
//
//struct Node
//{
//	string data;
//	Node* next = nullptr;
//	Node* prev = nullptr;
//};
//
//struct List
//{
//	Node* head_node = nullptr;
//	Node* tail_node = nullptr;
//	int size = 0;
//};
//void PrintToFile(List& list)
//{
//	ofstream output("fList.txt");
//	if (!output.is_open())
//	{
//		cout << "Файл f1.txt не открылся!" << endl;
//		return;
//	}
//	if (list.head_node == nullptr)
//	{
//		cout << "Список пустой!" << endl;
//		return;
//	}
//	Node* current_node = list.head_node;
//	while (current_node != nullptr)
//	{
//		output << current_node->data << ' ';
//		current_node = current_node->next;
//	}
//	output.close();
//}
//Node* FindKey(List &list, string key)
//{
//	Node* current_node = list.head_node;
//	for (int i = 0; i < list.size; i++)
//	{
//		if (current_node->data == key)
//		{
//			return current_node;
//		}
//		current_node = current_node->next;
//	}
//	return nullptr;
//}
//void PrintList(List& list)
//{
//	Node* current_node = list.head_node;
//	while (current_node != nullptr)
//	{
//		cout << current_node->data << ' ';
//		current_node = current_node->next;
//	}
//	cout << endl;
//}
//void pushFront(List& list, string data)
//{
//	Node* new_node = new Node;
//	new_node->data = data;
//	if (list.head_node == nullptr)
//	{
//		list.head_node = new_node;
//		list.tail_node = new_node;
//	}
//	else
//	{
//		list.head_node->prev = new_node;
//		new_node->next = list.head_node;
//		list.head_node = new_node;
//	}
//	list.size++;
//}
//void pushBack(List& list, string data)
//{
//	Node* new_node = new Node;
//	new_node->data = data;
//	if (list.head_node == nullptr)
//	{
//		list.head_node = new_node;
//		list.tail_node = new_node;
//	}
//	else
//	{
//		new_node->prev = list.tail_node;
//		list.tail_node->next = new_node;
//		list.tail_node = new_node;
//	}
//	list.size++;
//}
//void popFront(List& list)
//{
//	if (list.head_node == nullptr)
//	{
//		cout << "Список пустой, удалять нечего!" << endl;
//		return;
//	}
//	else
//	{
//		Node* remove_node = list.head_node;
//		list.head_node = list.head_node->next;
//		if (list.head_node != nullptr)
//		{
//			list.head_node->prev = nullptr;
//		}
//		if (remove_node == list.tail_node)
//		{
//			list.tail_node = nullptr;
//		}
//		delete remove_node;
//	}
//	list.size--;
//}
//void popBack(List& list)
//{
//	Node* current_node = list.head_node;
//	if (list.head_node == nullptr)
//	{
//		cout << "Список пустой, удалять нечего!" << endl;
//		return;
//	}
//	else if (list.head_node->next == nullptr)
//	{
//		delete list.head_node;
//		list.head_node = nullptr;
//		list.tail_node = nullptr;
//	}
//	else
//	{
//		Node* remove_node = list.tail_node;
//		list.tail_node = list.tail_node->prev;
//		list.tail_node->next = nullptr;
//		delete remove_node;
//	}
//	list.size--;
//}
//void InsertBefore(List& list, Node* key_node, string data)
//{
//	if (key_node == list.head_node)
//	{
//		pushFront(list, data);
//		return;
//	}
//	else
//	{
//		Node* new_node = new Node;
//		new_node->data = data;
//
//		new_node->next = key_node;
//		new_node->prev = key_node->prev;
//		key_node->prev->next = new_node;
//		key_node->prev = new_node;
//	}
//	list.size++;
//}
//void InsertAfter(List& list, Node* key_node, string data)
//{
//	if (key_node == list.tail_node)
//	{
//		pushBack(list, data);
//		return;
//	}
//	else
//	{
//		Node* new_node = new Node;
//		new_node->data = data;
//
//		new_node->next = key_node->next;
//		new_node->prev = key_node;
//		key_node->next->prev = new_node;
//		key_node->next = new_node;
//	}
//	list.size++;
//}
//void Remove(List& list, int pos)
//{
//	if (pos == 1)
//	{
//		popFront(list);
//		return;
//	}
//	else if (pos >= list.size)
//	{
//		if (pos > list.size)
//		{
//			cout << "Ошибка! В списке нет такой позиции!" << endl;
//			return;
//		}
//		popBack(list);
//		return;
//	}
//	else
//	{
//		Node* current_node = list.head_node;
//		for (int i = 0; i < pos - 1; i++)
//		{
//			current_node = current_node->next;
//		}
//		current_node->prev->next = current_node->next;
//		current_node->next->prev = current_node->prev;
//		delete current_node;
//	}
//	list.size--;
//}
//void FillList(List& list, string data, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cin >> data;
//		pushBack(list, data);
//	}
//	cout << endl;
//}
//void Clear(List& list)
//{
//	while (list.head_node != nullptr)
//	{
//		popFront(list);
//	}
//}
//void LoadFromFile(List& list)
//{
//	ifstream input("fList.txt");
//	if (!input.is_open())
//	{
//		cout << "Файл f1.txt не открылся!" << endl;
//		return;
//	}
//	string data;
//	while (getline(input, data))
//	{
//		pushBack(list, data);
//	}
//	input.close();
//}
// int main()
// {
//	 setlocale(LC_ALL, "ru");
//	 string data, key;
//	 List list;
//	 int n, pos, k;
//
//	 cout << "Введите кол-во элементов в списке: ";
//	 cin >> n;
//
//	 if (n != 0)
//	 {
//		 cout << "\nВведите список слов: ";
//	 }
//	 FillList(list, data, n);
//
//	 cout << "Список: ";
//	 PrintList(list);
//
//	 cout << "Введите номер элемента, который вы хотите удалить: ";
//	 cin >> pos;
//	 if (pos > 0)
//	 {
//		 Remove(list, pos);
//	 }
//	 else
//	 {
//		 cout << "Введите число больше нуля!" << endl;
//	 }
//	 cout << "Список: ";
//	 PrintList(list);
//
//	 cout << "\nВведите сколько элементов вы хотите добавить до и после какого-то элемента: ";
//	 cin >> k;
//	 if (k != 0)
//	 {
//		 cout << "\nВведите элемент списка перед и после которого вы хотите добавить другие элементы: ";
//		 cin >> key;
//		 Node* key_node = FindKey(list, key);
//		 if (key_node == nullptr)
//		 {
//			 cout << "Такого ключа нет!" << endl;
//		 }
//		 else
//		 {
//			 Node* insert_pos = key_node;
//			 cout << "Введите " << k << " элемент(a) перед заданным ключом: ";
//			 for (int i = 0; i < k; i++)
//			 {
//				 cin >> data;
//				 InsertBefore(list, insert_pos, data);
//			 }
//			 cout << "Введите " << k << " элемент(a) после заданного ключа: ";
//			 for (int i = 0; i < k; i++)
//			 {
//				 cin >> data;
//				 InsertAfter(list, insert_pos, data);
//				 insert_pos = key_node->next;
//			 }
//			 cout << "Список: ";
//			 PrintList(list);
//		 }
//	 }
//	 else
//	 {
//		 cout << "Список: ";
//		 PrintList(list);
//	 }
//	 PrintToFile(list);
//	 cout << "Список записан в файл" << endl;
//	 cout << "Содержимое файла: ";
//	 PrintList(list);
//	 Clear(list);
//	 cout << "\nСписок очищен" << endl;
//	 PrintList(list);
//	 LoadFromFile(list);
//	 cout << "Список восстановлен из файла" << endl;
//	 cout << "Список: ";
//	 PrintList(list);
//	 Clear(list);
//	 cout << "Список очищен" << endl;
//	 return 0;
// }