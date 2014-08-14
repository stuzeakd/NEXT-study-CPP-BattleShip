#pragma once
#include "Player.h"
class Human :
	public Player
{
public:
	Human();
	~Human();
public:

	void PrintMyMap();
	void PrintEnemyMap();
	void SetupShips();

};

