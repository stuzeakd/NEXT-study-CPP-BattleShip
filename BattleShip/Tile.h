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

public:
	void Draw();
	void SetPoint(int x, int y);
private:
	EShip::Type shipType;
	ETile::State tileState; //none, miss, hit, destroy,
};



