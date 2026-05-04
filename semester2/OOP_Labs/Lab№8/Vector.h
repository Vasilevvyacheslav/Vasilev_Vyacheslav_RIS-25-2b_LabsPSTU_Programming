#pragma once
#include "Object.h"
class Vector
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	Vector();
	Vector(int);
	~Vector();
	void Add();
	void Del();
	void Show();
	void ShowElement(int k);
	int operator()();
	virtual void HandleEvent(const TEvent& e);
};

struct TEvent
{
	int what;
	union
	{
		MouseEventType mouse;
		KeyDownEvent keyDown;
		MessageEvent message;
	};
};
