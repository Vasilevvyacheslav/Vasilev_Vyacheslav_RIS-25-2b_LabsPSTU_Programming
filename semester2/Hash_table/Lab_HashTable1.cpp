//#include "Randomizer.h"
//using namespace std;
//
//
//struct Human
//{
//	string Name;
//	string Surname;
//	string Patronymic;
//	int ID = 0;
//	string Date;
//
//	void CreateHuman()
//	{
//		Name = RandomName();
//		Surname = RandomSurname();
//		Patronymic = RandomPatronymic();
//		ID = RandomID();
//		Date = RandomDate();
//	}
//};
//
//struct HashTable
//{
//	Human* arr = nullptr;
//	int size = 0;
//	int count_collision = 0;
//
//	void CreateBlankTable(int s)
//	{
//		size = s;
//		arr = new Human[size]{};
//		for (int i = 0; i < size; i++)
//		{
//			arr[i].ID = 0;
//		}
//	}
//	int HashFunction(int ID)
//	{
//		return ID % size;
//	}
//
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
//		int first_hash = i;
//		if (arr[i].ID == 0 || arr[i].ID == -1)
//		{
//			arr[i] = h;
//		}
//		else
//		{
//			while (arr[i].ID != 0)
//			{
//				i = (i + 1) % size;
//				count_collision++;
//				if (arr[i].ID == 0 || arr[i].ID == -1)
//				{
//					arr[i] = h;
//					return;
//				}
//				if (i == first_hash)
//				{
//					cout << "Таблицы заполнена, элемент вставить нельзя!" << endl;
//					return;
//				}
//			}
//
//		}
//	}
//	void PrintTable()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << "Ячейка [" << i << "]" << endl;
//			if (arr[i].ID == 0 || arr[i].ID == -1)
//			{
//				cout << "Пусто\n\n";
//			}
//			else
//			{
//				cout << "ФИО: " << arr[i].Surname << " " << arr[i].Name << " " << arr[i].Patronymic << endl;
//				cout << "№ Паспорта: " << arr[i].ID << endl;
//				cout << "Дата рождения: " << arr[i].Date << endl << endl;
//			}
//		}
//	}
//	int FindIndex(int key_ID)
//	{
//		int i = HashFunction(key_ID);
//		for (int count = 0; count < size; count++)
//		{
//			if (arr[i].ID == key_ID)
//			{
//				return i;
//			}
//			i = (i + 1) % size;
//		}
//		cout << "Человека с таким номером паспорта нет!" << endl;
//		return -1;
//	}
//	void PopFromTable(int key_ID)
//	{
//		int index = FindIndex(key_ID);
//		if (index != -1)
//		{
//			arr[index].ID = -1;
//		}
//	}
//	void Clear()
//	{
//		delete[] arr;
//		arr = nullptr;
//		size = 0;
//	}
//};
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
//	table.PopFromTable(key_ID);
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
//	table.Clear();
//}
