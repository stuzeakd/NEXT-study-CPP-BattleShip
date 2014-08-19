#pragma once
#include "common.h"
#include "Tile.h"
#include "Utility.h"

class Map
{
public:
	Map();
	~Map();
	Map(const Map& src);
public:
	void Draw();
	Tile GetTile(int row, int col);
	Tile GetTile(Point pos);
	void SetTile(Tile tile);

private:
	void Create();
	void Init();
	Tile** m_Tiles;
};

