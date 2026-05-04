//#include <iostream>
//#include <clocale>
//#include <string>
//using namespace std;
//
//struct Node
//{
//	string data;
//	Node* next = nullptr;
//};
//struct Queue
//{
//	Node* head_node = nullptr;
//	Node* tail_node = nullptr;
//	int size = 0;
//};
//
//void enqueue(Queue& queue, string data)
//{
//	Node* new_node = new Node;
//	new_node->data = data;
//	if (queue.head_node == nullptr)
//	{
//		queue.head_node = new_node;
//		queue.tail_node = new_node;
//	}
//	else
//	{
//		queue.tail_node->next = new_node;
//		queue.tail_node = new_node;
//	}
//	queue.size++;
//}
//
//void dequeue(Queue& queue)
//{
//	if (queue.head_node == nullptr)
//	{
//		cout << "Очередь пуста, удалять нечего!" << endl;
//		return;
//	}
//	else
//	{
//		Node* temp = queue.head_node;
//		queue.head_node = queue.head_node->next;
//		if (queue.head_node == nullptr)
//		{
//			queue.tail_node = nullptr;
//		}
//		delete temp;
//	}
//	queue.size--;
//}
//void FillQueue(Queue& queue, string data, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cin >> data;
//		enqueue(queue, data);
//	}
//	cout << endl;
//}
//void PrintQueue(Queue& queue)
//{
//	Node* current_node = queue.head_node;
//	while (current_node != nullptr)
//	{
//		cout << current_node->data << ' ';
//		current_node = current_node->next;
//	}
//	cout << endl;
//}
//void Clear(Queue& queue)
//{
//	while (queue.head_node != nullptr)
//	{
//		dequeue(queue);
//	}
//}
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string data;
//	Queue queue;
//	int n, k;
//
//	cout << "Введите кол-во элементов в очереди: ";
//	cin >> n;
//
//	if (n != 0)
//	{
//		cout << "\nВведите слова: ";
//	}
//	FillQueue(queue, data, n);
//
//	cout << "Очередь: ";
//	PrintQueue(queue);
//
//	cout << "\nВведите сколько элементов вы хотите добавить в очередь: ";
//	cin >> k;
//	if (k != 0)
//	{
//		cout << "\nВведите элементы, которые вы хотите добавить: ";
//		for (int i = 0; i < k; i++)
//		{
//			cin >> data;
//			enqueue(queue, data);
//		}
//		cout << "Очередь: ";
//		PrintQueue(queue);
//	}
//	else
//	{
//		cout << "Очередь: ";
//		PrintQueue(queue);
//	}
//	cout << "\nВведите сколько элементов вы хотите удалить из очереди: ";
//	cin >> k;
//	if (k > queue.size)
//	{
//		cout << "Нелья удалить больше, чем размер очереди!" << endl;
//	}
//	else if (k != 0)
//	{
//		for (int i = 0; i < k; i++)
//		{
//			dequeue(queue);
//		}
//		cout << "Очередь: ";
//		PrintQueue(queue);
//	}
//	else
//	{
//		cout << "Очередь: ";
//		PrintQueue(queue);
//	}
//	Clear(queue);
//	return 0;
//}