#pragma once
#include "Player.h"
class Human :
	public Player
{
public:
	Human();
	~Human();
public:
	void	SetupShips();
	Point	MakeShipPos();
	Point	Attack();

	//void UpdateTileOnMyMap(Tile& tile);

	void PrintMyMap();
	void PrintEnemyMap();

};

