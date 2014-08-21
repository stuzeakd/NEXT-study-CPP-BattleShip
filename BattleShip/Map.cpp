#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	m_Tiles = nullptr;
	Create();
	Init();
}

Map::~Map()
{
	for (int i = 0; i < MAP_ROW; i++){
		delete[] m_Tiles[i];
	}
	delete[] m_Tiles;
}
Map::Map(const Map& src)
{
	Create();
	for (int i = 0; i < MAP_ROW; i++){
		for (int j = 0; j < MAP_COL; j++){
			m_Tiles[i][j] = src.m_Tiles[i][j];
		}
	}
}
Map& Map::operator=(const Map& src)
{
	for (int i = 0; i < MAP_ROW; i++){
		delete[] m_Tiles[i];
	}
	delete[] m_Tiles;
	Create();
	for (int i = 0; i < MAP_ROW; i++){
		for (int j = 0; j < MAP_COL; j++){
			m_Tiles[i][j] = src.m_Tiles[i][j];
		}
	}
	return *this;
}

void Map::Create()
{
	m_Tiles = new Tile*[MAP_ROW];
	for (int i = 0; i < MAP_ROW; i++){
		m_Tiles[i] = new Tile[MAP_COL];
	}
}
void Map::Init()
{
	for (int i = 0; i < MAP_ROW; i++){
		for (int j = 0; j < MAP_COL; j++){
			m_Tiles[i][j].SetPoint(i, j);
		}
	}
}
Tile Map::GetTile(int row, int col) const
{
	//tile Range Check

	if (row < 0 || row >= MAP_ROW) return Tile();
	if (col < 0 || col >= MAP_COL) return Tile();

	return m_Tiles[row][col];
}
Tile Map::GetTile(const Point& pos) const
{
	return GetTile(Utility::Instance().RowOfPoint(pos), Utility::Instance().ColOfPoint(pos));
}
void Map::SetTile(const Tile& tile)
{
	//tile Range Check
	if (tile.GetX() < 0 || tile.GetX() >= MAP_ROW) return;
	if (tile.GetY() < 0 || tile.GetY() >= MAP_COL) return;

	int row = Utility::Instance().RowOfPoint(tile);
	int col = Utility::Instance().ColOfPoint(tile);
	m_Tiles[row][col] = tile;
	//printf("(%d,%d)\n", Utility::Instance().RowOfPoint(tile), Utility::Instance().ColOfPoint(tile));
}
void Map::UpdateTile(const Tile& tile)
{
	//tile Range Check
	if (tile.GetX() < 0 || tile.GetX() >= MAP_ROW) return;
	if (tile.GetY() < 0 || tile.GetY() >= MAP_COL) return;

	int row = Utility::Instance().RowOfPoint(tile);
	int col = Utility::Instance().ColOfPoint(tile);
	m_Tiles[row][col].SetTileState(tile.GetTileState());
}
