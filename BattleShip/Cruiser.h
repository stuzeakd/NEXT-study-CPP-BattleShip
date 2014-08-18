#pragma once
#include "Ship.h"
class Cruiser :
	public Ship
{
public:
	Cruiser();
	~Cruiser();

	int GetLength(){ return 3; }

};

