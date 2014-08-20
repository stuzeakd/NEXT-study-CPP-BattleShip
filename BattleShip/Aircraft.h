#pragma once
#include "Ship.h"
class Aircraft :
	public Ship
{
public:
	Aircraft();
	~Aircraft();

	int GetLength() const { return 5; }
};

