#pragma once
#include "Point.h"

namespace EShip{
	enum Type {
		NONE = 0,
		SUBMARINE,
		DESTROYER,
		CRUISER,
		BATTLESHIP,
		AIRCRAFT,
	};
}
namespace EPlayer{
	enum Type {
		HUMAN,
		AI,
	};
}


#define MAP_ROW 8
#define MAP_COL 8
#define SHIP_NUM 5

const EShip::Type shipRule[] = { EShip::AIRCRAFT, EShip::BATTLESHIP , EShip::CRUISER, EShip::DESTROYER, EShip::DESTROYER };
