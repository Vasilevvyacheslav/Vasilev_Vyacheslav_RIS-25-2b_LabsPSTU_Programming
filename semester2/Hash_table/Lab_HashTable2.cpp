//#include "Randomizer.h"
//#include "Linked_list.h"
//using namespace std;
//
//struct HashTable
//{
//	List* arr = nullptr;
//	int size = 0;
//	int count_collision = 0;
//
//	void CreateBlankTable(int s)
//	{
//		size = s;
//		arr = new List[size]{};
//	}
//	int HashFunction(int ID)
//	{
//		return ID % size;
//	}
//	void FillTable(int n)
//	{
//		Human h;
//		for (int i = 0; i < n; i++)
//		{
//			h.CreateHuman();
//			AddToTable(h);
//		}
//	}
//	void AddToTable(Human h)
//	{
//		int i = HashFunction(h.ID);
//		pushBack(arr[i], h);
//	}
//	void PrintTable()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << "Ячейка [" << i << "]" << endl;
//			if (arr[i].head_node == nullptr)
//			{
//				cout << "Пусто\n\n";
//			}
//			else
//			{
//				Node* current_node = arr[i].head_node;
//				while (current_node != nullptr)
//				{
//					cout << "ФИО: " << current_node->data.Surname << " "
//						<< current_node->data.Name
//						<< " " << current_node->data.Patronymic << endl;
//					cout << "№ Паспорта: " << current_node->data.ID << endl;
//					cout << "Дата рождения: " << current_node->data.Date << endl << endl;
//					current_node = current_node->next;
//				}
//			}
//		}
//	}
//
//	void DeleteFromTable(int key_ID)
//	{
//		int i = HashFunction(key_ID);
//		DeleteFromList(arr[i], key_ID);
//	}
//	void DeleteFromList(List& list, int key_ID)
//	{
//		Node* node_to_delete = FindID(list, key_ID);
//		if (node_to_delete == nullptr)
//		{
//			cout << "Человека с таким номером паспорта нет!" << endl;
//			return;
//		}
//		Node* prev_node = nullptr;
//		if (node_to_delete == list.head_node)
//		{
//			list.head_node = node_to_delete->next;
//			return;
//		}
//		else
//		{
//			prev_node = list.head_node;
//			while (prev_node->next != node_to_delete)
//			{
//				prev_node = prev_node->next;
//			}
//			prev_node->next = node_to_delete->next;
//		}
//		if (list.tail_node == node_to_delete)
//		{
//			list.tail_node = prev_node;
//		}
//		delete node_to_delete;
//		list.size--;
//	}
//	Node* FindID(List& list, int ID)
//	{
//		Node* current_node = list.head_node;
//		for (int i = 0; i < list.size; i++)
//		{
//			if (current_node->data.ID == ID)
//			{
//				return current_node;
//			}
//			current_node = current_node->next;
//		}
//		return nullptr;
//	}
//	void ClearHashTable()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			ClearList(arr[i]);
//		}
//		delete[] arr;
//	}
//};
//
//
//
//int main()
//{
//	srand(time(NULL));
//	setlocale(LC_ALL, "ru");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	int size;
//	cout << "Введите размер таблицы: ";
//	cin >> size;
//
//	HashTable table;
//	table.CreateBlankTable(size);
//	table.FillTable(size);
//	table.PrintTable();
//	cout << "Количество коллизий: " << table.count_collision << endl;
//	int key_ID;
//	cout << "Введите номер паспорта человека, которого вы хотите удалить: ";
//	cin >> key_ID;
//	table.DeleteFromTable(key_ID);
//	table.PrintTable();
//	table.count_collision = 0;
//
//	Human h;
//	cout << "Введите данные человека, которого хотите добавить " << endl;
//	cout << "Введите Фамилию: "; cin >> h.Surname;
//	cout << "Введите Имя: "; cin >> h.Name;
//	cout << "Введите Отчество: "; cin >> h.Patronymic;
//	cout << "Введите №Паспорта: "; cin >> h.ID;
//	cout << "Введите Дату рождения: "; cin >> h.Date;
//	cout << endl;
//	table.AddToTable(h);
//	table.PrintTable();
//	cout << "Количество коллизий: " << table.count_collision << endl << endl;
//
//	table.ClearHashTable();
//}
