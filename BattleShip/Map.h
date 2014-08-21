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
	Map& operator=(const Map& src);
	Tile GetTile(int row, int col) const;
	Tile GetTile(const Point& pos) const;
	void SetTile(const Tile& tile);
	void UpdateTile(const Tile& tile);

private:
	void Create();
	void Init();
	Tile** m_Tiles;
};

