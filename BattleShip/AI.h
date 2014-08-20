#pragma once
#include "Player.h"
#include "UDLRRand.h"
class AI :
	public Player
{
public:
	AI();
	~AI();
	void Render();
	void SetupShips();
	Point MakeShipPos();
	Point Attack();
};

