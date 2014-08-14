#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	Create();
	Init();
}

Map::~Map()
{
	for (int i = 0; i < MAP_ROW; i++){
		delete[] m_Map[i];
	}
	delete[] m_Map;
}

void Map::Create()
{
	m_Map = new Tile*[MAP_ROW];
	for (int i = 0; i < MAP_ROW; i++){
		m_Map[i] = new Tile[MAP_COL];
	}
}
void Map::Init()
{
	for (int i = 0; i < MAP_ROW; i++){
		for (int j = 0; j < MAP_COL; j++){
			m_Map[i][j].SetPoint(i, j);
		}
	}
}
void Map::Draw()
{
	for (int i = 0; i < MAP_ROW; i++){
		for (int j = 0; j < MAP_COL; j++){
			m_Map[i][j].Draw();
		}
		printf_s("\n");
	}
}