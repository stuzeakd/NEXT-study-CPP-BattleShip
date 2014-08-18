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

void Tile::Draw()
{
	switch (m_ShipType)
	{
	case EShip::NONE:
		printf_s("N");
		break;
	case EShip::AIRCRAFT:
		printf_s("A");
		break;
	case EShip::BATTLESHIP:
		printf_s("B");
		break;
	case EShip::CRUISER:
		printf_s("C");
		break;
	case EShip::DESTROYER:
		printf_s("D");
		break;
	case EShip::SUBMARINE:
		printf_s("S");
		break;
	default:
		break;
	}
	switch (m_TileState)
	{
	case ETile::NONE:
		printf_s("N");
		break;
	case ETile::HIT:
		printf_s("H");
		break;
	case ETile::MISS:
		printf_s("M");
		break;
	case ETile::DESTROY:
		printf_s("D");
		break;
	default:
		break;
	}
	printf(" ");
}
void Tile::SetPoint(int x, int y){
	SetX(x);
	SetY(y);
}
void Tile::SetTileState(ETile::State state)
{
	m_TileState = state;
}
void Tile::SetShipType(EShip::Type type)
{
	m_ShipType = type;
}