#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	shipType = EShip::NONE;
	tileState = ETile::NONE;
}


Tile::~Tile()
{
}

void Tile::Draw()
{
	switch (shipType)
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
	switch (tileState)
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