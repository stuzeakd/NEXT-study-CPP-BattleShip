#pragma once
class Map
{
public:
	Map();
	~Map();

public:
	void mapInit();
	int getHP();

private:

	Aircraft aircraft;
	Battleship battleship;
	Cruiser cruiser;
	Destroyer destroyer1, destroyer2;
	Submarine submarine1, submarine2;
	
	void mapSet();

};