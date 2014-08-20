#pragma once
#include "Player.h"
#include "UDLRRand.h"
class Human :
	public Player
{
public:
	Human();
	~Human();
public:
	void	Render();
	void	SetupShips();
	Point	MakeShipPos();
	Point	Attack();

	//void UpdateTileOnMyMap(Tile& tile);
	void UpdateTileOnEnemyMap(Tile& tile);
	void UpdateShipOnMyShips(Ship& ship);
	void UpdateShipOnEnemyShips(Ship& ship);

	void PrintMyMap();
	void PrintEnemyMap();

	Point MakeShipPosRand();

};

