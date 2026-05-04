//#include <iostream>
//#include <clocale>
//#include <string>
//using namespace std;
//
//struct Node
//{
//	char data;
//	Node* next = nullptr;
//};
//struct Stack
//{
//	Node* top_node = nullptr;
//	int size = 0;
//};
//void Push(Stack& stack, char data)
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
//void FillStack(Stack& stack, char data, int n)
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
//	Stack stack;
//	string row;
//	getline(cin, row);
//	bool f = false; // Строка состоит из одной закрывающей скобки
//	for (int i = 0; i < row.size(); i++)
//	{
//		if (row[i] == '(' || row[i] == '{' || row[i] == '[')
//		{
//			char data = row[i];
//			Push(stack, data);
//			PrintStack(stack);
//		}
//		if (row[i] == ')' || row[i] == '}' || row[i] == ']')
//		{
//			if (stack.top_node != nullptr)
//			{
//				if (row[i] == ')' && stack.top_node->data == '(')
//				{
//					Pop(stack);
//					PrintStack(stack);
//				}
//				if (row[i] == '}' && stack.top_node->data == '{')
//				{
//					Pop(stack);
//					PrintStack(stack);
//				}
//				if (row[i] == ']' && stack.top_node->data == '[')
//				{
//					Pop(stack);
//					PrintStack(stack);
//				}
//			}
//			else
//			{
//				f = true;
//			}
//		}
//	}
//	if (stack.top_node == nullptr && !f)
//	{
//		cout << "Скобки в строке расположены верно!" << endl;
//	}
//	else
//	{
//		cout << "Скобки в строке расположены неверно!" << endl;
//	}
//	Clear(stack);
//	return 0;
//}