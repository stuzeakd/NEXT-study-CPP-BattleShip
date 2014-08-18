#pragma once
#include "common.h"
#include "Ship.h"

#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"

//Singleton Class

class ShipFactory
{
public:
	static ShipFactory* Instance();
	~ShipFactory();

protected:
	ShipFactory();

public:
	Ship* GenerateShip(EShip::Type shipType, int id);
private:
	static ShipFactory* m_Instance;
};

