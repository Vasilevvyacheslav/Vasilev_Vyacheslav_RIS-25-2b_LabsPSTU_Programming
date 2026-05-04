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
//struct Stack
//{
//	Node* top_node = nullptr;	
//	int size = 0;
//};
//void Push(Stack& stack, string data)
//{
//	Node* new_node = new Node;
//	new_node->data = data;
//
//	new_node->next = stack.top_node;
//	stack.top_node = new_node;
//	stack.size++;
//}
//void Pop(Stack& stack)
//{
//	if (stack.top_node == nullptr)
//	{
//		cout << "Стек пустой, удалять нечего!" << endl;
//		return;
//	}
//	else
//	{
//		Node* temp = stack.top_node;
//		stack.top_node = stack.top_node->next;
//		delete temp;
//		stack.size--;
//	}
//}
//void FillStack(Stack& stack, string data, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cin >> data;
//		Push(stack, data);
//	}
//	cout << endl;
//}
//void PrintStack(Stack& stack)
//{
//	Node* current_node = stack.top_node;
//	while (current_node != nullptr)
//	{
//		cout << current_node->data << ' ';
//		current_node = current_node->next;
//	}
//	cout << endl;
//}
//void Clear(Stack& stack)
//{
//	while (stack.top_node != nullptr)
//	{
//		Pop(stack);
//	}
//}
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	string data;
//	Stack stack;
//	int n, k;
//
//	cout << "Введите кол-во элементов в стеке: ";
//	cin >> n;
//
//	if (n != 0)
//	{
//		cout << "\nВведите слова: ";
//	}
//	FillStack(stack, data, n);
//
//	cout << "Стек: ";
//	PrintStack(stack);
//
//	cout << "\nВведите сколько элементов вы хотите добавить в стек: ";
//	cin >> k;
//	if (k != 0)
//	{
//		cout << "\nВведите элементы, которые вы хотите добавить: ";
//		for (int i = 0; i < k; i++)
//		{
//			cin >> data;
//			Push(stack, data);
//		}
//		cout << "Стек: ";
//		PrintStack(stack);
//	}
//	else
//	{
//		cout << "Стек: ";
//		PrintStack(stack);
//	}
//	cout << "\nВведите сколько элементов вы хотите удалить из стека: ";
//	cin >> k;
//	if (k > stack.size)
//	{
//		cout << "Нелья удалить больше, чем размер стека!" << endl;
//	}
//	else if (k != 0)
//	{
//		for (int i = 0; i < k; i++)
//		{
//			Pop(stack);
//		}
//		cout << "Стек: ";
//		PrintStack(stack);
//	}
//	else
//	{
//		cout << "Стек: ";
//		PrintStack(stack);
//	}
//	Clear(stack);
//	return 0;
//}