#pragma once
#include "Event.h"
class Object
{
public:
	Object();
	void virtual Show() = 0;
	void virtual Input() = 0;
	virtual ~Object();
	
};
