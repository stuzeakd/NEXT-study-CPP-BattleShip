#pragma once
#include "Ship.h"
class Destroyer :
	public Ship
{
public:
	Destroyer();
	~Destroyer();

	int GetLength(){ return 2; }
};

