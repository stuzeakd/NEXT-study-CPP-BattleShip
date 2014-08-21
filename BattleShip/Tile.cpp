#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	m_ShipType = EShip::NONE;
	m_TileState = ETile::NONE;
	m_ShipId = -1;
}


Tile::~Tile()
{
}
Tile::Tile(const Tile & src)
{
	m_ShipType = src.m_ShipType;
	m_ShipId = src.m_ShipId;
	m_TileState = src.m_TileState;
	SetX(src.GetX());
	SetY(src.GetY());
}
void Tile::SetPoint(int x, int y){
	SetX(x);
	SetY(y);
}
void Tile::SetPoint(const Point& pos)
{
	SetPoint(pos.GetX(), pos.GetY());
}
void Tile::SetTileState(const ETile::State& state)
{
	m_TileState = state;
}
void Tile::SetShipType(const EShip::Type& type)
{
	m_ShipType = type;
}
Point Tile::GetPoint() const
{
	return Point(GetX(), GetY());
}
