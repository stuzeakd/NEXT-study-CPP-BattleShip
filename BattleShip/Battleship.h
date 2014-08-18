#pragma once
#include "Ship.h"
class Battleship :
	public Ship
{
public:
	Battleship();
	~Battleship();

	int GetLength(){ return 4; }

};

