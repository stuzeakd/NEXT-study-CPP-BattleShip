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
	void SetID(int id){ m_ShipId = id; }
	void SetPoint(int x, int y);
	void SetPoint(const Point& pos);
	void SetTileState(const ETile::State& state);
	void SetShipType(const EShip::Type& type);

	Point			GetPoint()		const;
	EShip::Type		GetShipType()	const { return m_ShipType; }
	ETile::State	GetTileState()	const { return m_TileState; }
	int				GetShipID()		const { return m_ShipId; }

private:
	int m_ShipId;
	EShip::Type m_ShipType;
	ETile::State m_TileState; //none, miss, hit, destroy,
};



