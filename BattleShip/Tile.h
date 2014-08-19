#pragma once
#include "Point.h"
#include "common.h"

namespace ETile{
	enum State {
		NONE,
		MISS,
		HIT,
		DESTROY,
	};
}
class Tile :
	public Point
{
public:
	Tile();
	~Tile();
	Tile(const Tile & src);

public:
	void Draw();
	void SetID(int id){ m_ShipId = id; }
	void SetPoint(int x, int y);
	void SetTileState(ETile::State state);
	void SetShipType(EShip::Type type);
	Point			GetPoint();
	EShip::Type		GetShipType()	{ return m_ShipType; }
	ETile::State	GetTileState()	{ return m_TileState; }
	int				GetShipID()		{ return m_ShipId; }

private:
	int m_ShipId;
	EShip::Type m_ShipType;
	ETile::State m_TileState; //none, miss, hit, destroy,
};



