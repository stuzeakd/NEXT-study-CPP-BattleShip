#pragma once
#include "Ship.h"
#include "common.h"
#include "Utility.h"
#include "Map.h"
#include "ShipFactory.h"

class Player
{
public:
	Player();
	Player(EPlayer::Type type);
	~Player();

public:
	Point MakeShipPos();
	virtual void SetupShips() = 0;
	void PrintShips();
	int GetHP();

protected:
	void InitShip();

	EPlayer::Type m_PlayerType;
	Map m_MyMap;
	Map m_EnemyMap;
	std::vector<Ship*> m_Ships;
};

