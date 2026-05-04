//#pragma once
//#include <iostream>
//#include <clocale>
//#include <string>
//#include <fstream>
//#include "Randomizer.h"
//using namespace std;
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
//struct Node
//{
//	Human data;
//	Node* next = nullptr;
//};
//
//struct List
//{
//	Node* head_node = nullptr;
//	Node* tail_node = nullptr;
//	int size = 0;
//};
//void pushBack(List& list, Human data)
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
//		list.tail_node->next = new_node;
//		list.tail_node = new_node;
//	}
//	list.size++;
//}
//void ClearList(List& list)
//{
//	Node* current_node = list.head_node;
//	while (current_node != nullptr)
//	{
//		Node* next_node = current_node->next;
//		delete current_node;
//		current_node = next_node;
//	}
//	list.head_node = nullptr;
//	list.tail_node = nullptr;
//	list.size = 0;
//}
