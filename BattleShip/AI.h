#pragma once
#include "Player.h"
class AI :
	public Player
{
public:
	AI();
	~AI();

	void SetupShips();
	Point MakeShipPos();
	Point Attack();
};

