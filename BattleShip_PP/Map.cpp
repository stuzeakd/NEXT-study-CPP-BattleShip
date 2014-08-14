#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	Map::mapInit();
}


Map::~Map()
{
}

void Map::mapInit(){
	aircraft = Aircraft();
	battleship = Battleship();
	cruiser = Cruiser();
	destroyer1 = Destroyer();
	destroyer2 = Destroyer();
	submarine1 = Submarine();
	submarine2 = Submarine();
}

void Map::mapSet(){
	
}

int Map::getHP(){
	return aircraft.getHP() + battleship.getHP() + cruiser.getHP() + \
		destroyer1.getHP() + destroyer2.getHP() + submarine1.getHP() + submarine2.getHP();
}