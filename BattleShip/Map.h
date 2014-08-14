#pragma once
#include "common.h"
#include "Tile.h"


class Map
{
public:
	Map();
	~Map();
public:
	void Draw();

private:
	void Create();
	void Init();
	Tile** m_Map;
};

