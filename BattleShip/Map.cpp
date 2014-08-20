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
	//for (int i = 0; i < MAP_ROW; i++){
	//	delete[] m_Tiles[i];
	//}
	//delete[] m_Tiles;
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
void Map::Draw()
{
	for (int i = 0; i < MAP_ROW; i++){
		for (int j = 0; j < MAP_COL; j++){
			m_Tiles[i][j].Draw();
		}
		printf_s("\n");
	}
}
Tile Map::GetTile(int row, int col)
{
	//if (m_Tiles == nullptr) return;
	return m_Tiles[row][col];
}
Tile Map::GetTile(Point pos)
{
	return GetTile(Utility::Instance().RowOfPoint(pos), Utility::Instance().ColOfPoint(pos));
}
void Map::SetTile(Tile tile)
{
	int row = Utility::Instance().RowOfPoint(tile);
	int col = Utility::Instance().ColOfPoint(tile);
	m_Tiles[row][col] = tile;
	//printf("(%d,%d)\n", Utility::Instance().RowOfPoint(tile), Utility::Instance().ColOfPoint(tile));
}
void Map::UpdateTile(Tile tile)
{
	int row = Utility::Instance().RowOfPoint(tile);
	int col = Utility::Instance().ColOfPoint(tile);
	m_Tiles[row][col].SetTileState(tile.GetTileState());
}
