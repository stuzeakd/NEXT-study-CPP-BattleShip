#include "stdafx.h"
#include "AI.h"


AI::AI()
{
	m_PlayerType = EPlayer::AI;
}


AI::~AI()
{
}
void AI::Render()
{
	GameUIIngame::Instance().DrawMyShipsP2(m_MyShips);
	GameUIIngame::Instance().DrawEnemyShipsP2(m_EnemyShips);
	GameUIIngame::Instance().DrawMyMapP2(m_MyMap);
	GameUIIngame::Instance().DrawEnemyMapP2(m_EnemyMap);
}
void AI::SetupShips()
{
	UDLRRand UDLR;
	Point head;
	Point tail;
	bool IsValidShipPos = true;
	bool IsValidMapPos = true;
	//	for (std::vector<Ship*>::iterator ship = m_MyShips.begin(); ship != m_MyShips.end(); ++ship)
	for (auto ship : m_MyShips)
	{
		while (true)
		{
			UDLR.Reset();
			head = MakeShipPos();
			while (!UDLR.IsEmpty())
			{
				switch (UDLR.GetRand())
				{
				case EUDLRRand::UP:
					tail.SetX(head.GetX());
					tail.SetY(head.GetY() + (ship->GetLength() - 1));
					break;
				case EUDLRRand::DOWN:
					tail.SetX(head.GetX());
					tail.SetY(head.GetY() - (ship->GetLength() - 1));
					break;
				case EUDLRRand::LEFT:
					tail.SetX(head.GetX() - (ship->GetLength() - 1));
					tail.SetY(head.GetY());
					break;
				case EUDLRRand::RIGHT:
					tail.SetX(head.GetX() + (ship->GetLength() - 1));
					tail.SetY(head.GetY());
					break;
				default:
					break;
				}
				if (IsValidMapPos = IsValidShipPositionOnMap(head, tail)) break;
			}
			if (IsValidMapPos) break;
		}
		ship->SetPosition(head, tail);
		SetShipOnMyMap(*ship);
	}
}
Point AI::Attack()
{
	Point pos = MakeShipPos();
	while (!IsValidAttackPos(pos))
	{
		pos = MakeShipPos();
	}
	return pos;
}
Point AI::MakeShipPos()
{
	srand(time(NULL));
	Point pos;
	pos.SetX(rand() % MAP_ROW);
	pos.SetY(rand() % MAP_COL);
	return pos;
}