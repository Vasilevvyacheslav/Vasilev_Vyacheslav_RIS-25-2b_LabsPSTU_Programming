#include "Dialog.h"
#include <iostream>
#include <string>
using namespace std;

Dialog::Dialog() : Vector() { EndState = 0; }
Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event)
{

	string OpInt = "+-smqz";
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s; 
	code = s[0];

	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmShowK; break;
		case 'q': event.command = cmQuit; break;
		}
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else event.what = evNothing;
}

int Dialog::Execute()
{
	cout << "Commands:\n";
	cout << "  mN - create vector of size N\n";
	cout << "  +  - add object\n";
	cout << "  -  - delete object\n";
	cout << "  s  - show all objects\n";
	cout << "  zk - show element k\n";
	cout << "  q  - quit\n\n";

	TEvent event;
	do {
		EndState = 0;
		event.what = evNothing;
		event.command = 0;
		event.a = 0;

		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}
void Dialog::EndExec()
{
	EndState = 1;
}
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			if (beg != nullptr)
			{
				cout << "Vector already created!\n";
				break;
			}
			size = event.a;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del();
			ClearEvent(event);
			break;
		case cmShow:
			Show();	
			ClearEvent(event);
			break;
		case cmShowK:
			ShowElement(event.a);
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default: 
			break;
		};
	};
}